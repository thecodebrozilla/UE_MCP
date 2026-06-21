# Copyright Epic Games, Inc. All Rights Reserved.
"""Utilities for running unittest tests from Unreal."""

from asyncio import sleep, AbstractEventLoop
from collections import defaultdict
from collections.abc import Callable
from concurrent.futures import Future, ThreadPoolExecutor
from dataclasses import dataclass, field, replace
from fnmatch import fnmatch
from inspect import getmodule
from os.path import realpath
import sys
from threading import local
from types import MethodType, TracebackType
from typing import cast, Protocol, Sequence, TextIO
import unittest

from .._asyncio.callable_runner import CallableRunner
from .._asyncio.context_loop_runner import ContextLoopRunner
from .._asyncio.preconfigured_loop_runner import PreconfiguredLoopRunner
from .._asyncio.run_on_loop import run_sync_on_loop
from .editor_thread_coroutine_executor import EditorThreadCoroutineExecutor


# Default glob used to find test modules.
_DEFAULT_TEST_MODULE_GLOB = 'test_*'
_DEFAULT_VERBOSITY = 2
_DEFAULT_ROOT_MODULE = __package__ or ''


class _ThreadLocalStorage(local):  # pylint: disable=too-few-public-methods
    """This module's thread-local storage.

    This is thread-local storage so that this module can be tested in
    background threads using fakes while this module is in use on other
    threads.
    """

    get_or_create_executor: Callable[[], EditorThreadCoroutineExecutor]

    def __init__(self):
        """Initialize defaults."""
        self.__dict__.setdefault(
            'get_or_create_executor', EditorThreadCoroutineExecutor.get_or_create
        )


_thread_local_storage = _ThreadLocalStorage()


def _get_or_create_executor() -> EditorThreadCoroutineExecutor:
    """Get or create the coroutine executor for this thread.

    Returns:
        Potentially thread local, editor thread coroutine executor.
    """
    return _thread_local_storage.get_or_create_executor()


class OnTestCompletion(Protocol):  # pylint: disable=too-few-public-methods
    """Called when a test completes."""

    def __call__(
            self, test_cases: Sequence[unittest.TestCase],
            successful: bool
        ) -> None:
        """Called when a test completes.

        Args:
            test_cases: Completed test case(s).
            successful: Whether the test case(s) completed sucessfully.
        """


def _unhandled_test_completion(
        test_cases: Sequence[unittest.TestCase], successful: bool
    ) -> None:
    """Test completion that does nothing."""
    _ = (test_cases, successful)  # Silence pylint


def _get_test_cases_from_suite(
        suite: unittest.TestSuite
    ) -> Sequence[unittest.TestCase]:
    """Get test cases from a test suite.

    Args:
        suite: Suite to search.
    """
    test_cases: list[unittest.TestCase] = []
    for maybe_test in suite:
        if isinstance(maybe_test, unittest.TestSuite):
            test_cases.extend(_get_test_cases_from_suite(maybe_test))
        else:
            test_cases.append(maybe_test)
    return test_cases


def _filter_test_cases(
        test_cases: Sequence[unittest.TestCase],
        test_name_globs: set[str],
    ) -> Sequence[unittest.TestCase]:
    """Filter test cases by a set of globs.

    Args:
        test_cases: Test cases for filter.
        test_name_globs: Globs used to filter test cases. If this empty, test
            cases are not filtered.
    """
    if not test_name_globs:
        return test_cases
    filtered_test_cases: list[unittest.TestCase] = []
    for test_case in test_cases:
        for test_name_glob in test_name_globs:
            if fnmatch(test_case.id(), test_name_glob):
                filtered_test_cases.append(test_case)
                break
    return filtered_test_cases


@dataclass(frozen=True)
class TestSearchOptions:
    """Test search / discovery options.

    Class Attributes:
        root_module: Module to search under for tests.
        test_module_glob: A glob that matches test modules to discover or an
            empty string to discover all tests.
        test_name_globs: A set of globs that match test names to execute or an
            empty set or None to run all tests.
    """
    root_module: str = _DEFAULT_ROOT_MODULE
    test_module_glob: str = _DEFAULT_TEST_MODULE_GLOB
    test_name_globs: set[str] = field(default_factory=set)  # pyright: ignore

    @property
    def test_module_filename_glob(self) -> str:
        """Glob that matches a test module filename."""
        return f'{self.test_module_glob}.py'


_test_loader_by_root_package: dict[str, unittest.TestLoader] = (
    defaultdict(unittest.TestLoader)
)


def _get_test_loader_by_root_package(module_or_package_name: str) -> (
        unittest.TestLoader):
    """Get or create a test loader for a root package.

    Args:
        module_or_package_name: Fully qualified module or package name.

    Returns:
        TestLoader instance.
    """
    root_package_name = module_or_package_name.split('.', maxsplit=1)[0]
    return _test_loader_by_root_package[root_package_name]


def discover_tests(
        search_options: TestSearchOptions | None = None
    ) -> Sequence[unittest.TestCase]:
    """Discover tests.

    Args:
        search_options: Options used to search for tests.

    Returns:
        Discovered test cases.
    """
    search_options = search_options or TestSearchOptions()
    return _filter_test_cases(
        _get_test_cases_from_suite(
            _get_test_loader_by_root_package(
                search_options.root_module).discover(
                    search_options.root_module,
                    search_options.test_module_filename_glob)),
        search_options.test_name_globs)


class _TestCompletionAggregator:
    """Aggregates test completions."""

    _test_results_by_id: dict[str, bool] = {}

    def __init__(
            self, test_cases: Sequence[unittest.TestCase],
            on_complete: OnTestCompletion,
            on_all_complete: OnTestCompletion):
        """Initialize the instance.

        Args:
            test_cases: Test cases that will be aggregated in a single
                completion.
            on_complete: Called when some test cases complete.
            on_all_complete: Called when all test cases are complete.
        """
        self._successful = True
        self._test_cases = tuple(test_cases)
        self._pending_test_case_ids = (
            set(test_case.id() for test_case in test_cases))
        self._on_complete = on_complete
        self._on_all_complete = on_all_complete
        self._on_all_complete_future: Future[bool] = Future()

        for test_case_id in self._pending_test_case_ids:
            try:
                _ = self._test_results_by_id.pop(test_case_id)
            except KeyError:
                pass

    @property
    def on_all_complete_future(self) -> Future[bool]:
        """Resolves when all tests are complete."""
        return self._on_all_complete_future

    def on_complete(
            self, test_cases: Sequence[unittest.TestCase],
            successful: bool
        ) -> None:
        """Handle completion calling on_completed if all tests have finished.

        Args:
            test_cases: Completed test cases.
            successful: Whether the specified test cases completed
                successfully.
        """
        self._on_complete(test_cases, successful)
        self._successful = self._successful and successful
        for test_case in test_cases:
            test_case_id = test_case.id()
            self._pending_test_case_ids.remove(test_case_id)
            self._test_results_by_id[test_case_id] = successful
        if not self._pending_test_case_ids:
            try:
                self._on_all_complete(self._test_cases, self._successful)
            finally:
                self._on_all_complete_future.set_result(self._successful)

    @classmethod
    def get_last_test_result(cls, test_id: str) -> bool | None:
        """Get the last result of the specified test.

        Args:
            test_id: Fully qualified name of the test.

        Returns:
            True if successful, False if it failed, None if it hasn't been
            executed or is executing.
        """
        return cls._test_results_by_id.get(test_id)

    @classmethod
    def clear_last_test_results(cls) -> None:
        """Clear all stored test results."""
        cls._test_results_by_id.clear()


@dataclass(frozen=True)
class SingleTestRunOptions:
    """Test run / execution options for a single test.

    Attributes:
        verbosity: Test runner verbosity level, 0 = off, 1 = minimal,
            2 = verbose.
        on_complete: Called as requested tests complete.
        output_stream: Where to log test output.
        error_stream: Where to log test errors.
    """
    verbosity: int = _DEFAULT_VERBOSITY
    on_complete: OnTestCompletion = _unhandled_test_completion
    output_stream: TextIO = field(default_factory=lambda: sys.stdout)
    error_stream: TextIO = field(default_factory=lambda: sys.stderr)


@dataclass(frozen=True)
class TestRunOptions(SingleTestRunOptions):
    """Test run / execution options for a suite of tests.

    Attributes:
        on_all_complete: Called when all requested tests are complete.
    """
    on_all_complete: OnTestCompletion = _unhandled_test_completion


def discover_and_run_tests(
        search_options: TestSearchOptions | None = None,
        run_options: TestRunOptions | None = None
    ) -> tuple[Sequence[unittest.TestCase], Future[bool]]:
    """Discover and run tests.

    Args:
        search_options: Options used to search for tests.
        run_options: Options used to run tests.

    Returns:
        (tests, result_future) tuple where tests is the sequence of tests that
        either have been executed or scheduled to be executed and result
        resolves to whether test execution has completed successfully.
    """
    tests = discover_tests(search_options=search_options)
    result_future = run_tests(tests, run_options=run_options)
    return (tests, result_future)


def run_tests(
        test_cases: Sequence[unittest.TestCase],
        run_options: TestRunOptions | None = None
    ) -> Future[bool]:
    """Run tests.

    Args:
        test_cases: Test cases to run.
        run_options: Options used to run tests.

    Returns:
        Resolves to True if all tests complete successful, False otherwise.
    """
    run_options = run_options or TestRunOptions()
    completion_aggregator = (
        _TestCompletionAggregator(
            test_cases, run_options.on_complete,
            run_options.on_all_complete
        )
    )
    run_options_using_completion_aggregator = replace(
        run_options,
        on_complete=completion_aggregator.on_complete,
    )
    if test_cases:
        executor = _get_or_create_executor()
        for test in test_cases:
            executor.schedule(
                _run_test_async(
                    test, run_options=run_options_using_completion_aggregator
                )
            )
        # Force an update in an attempt to dispatch any pending test executions.
        executor.tick_if_on_tick_thread()
    else:
        completion_aggregator.on_complete([], False)
    return completion_aggregator.on_all_complete_future


def clear_last_test_results() -> None:
    """Clear all stored test results."""
    _TestCompletionAggregator.clear_last_test_results()


def get_last_test_result(test_id: str) -> bool | None:
    """Get the last result of the specified test.

    Args:
        test_id: Fully qualified name of the test.

    Returns:
        True if successful, False if it failed, None if it hasn't been
        executed or is executing.
    """
    return _TestCompletionAggregator.get_last_test_result(test_id)


class _TestOnAsyncioLoopFactory:
    """Creates test cases and suites to run tests on an asyncio loop.

    TestSuite and TestCase block the caller thread, this moves execution of
    setUp, tearDown and test methods to the asyncio loop provided on
    initialization of this instance.
    """

    _TEST_SUITE_FUNCTIONS_TO_WRAP: Sequence[MethodType] = cast(
        Sequence[MethodType],
        (
            # pylint: disable=protected-access
            unittest.TestSuite._handleClassSetUp,       # type: ignore
            unittest.TestSuite._handleModuleFixture,    # type: ignore
            unittest.TestSuite._handleModuleTearDown,   # type: ignore
            unittest.TestSuite._tearDownPreviousClass,  # type: ignore
        )
    )

    _SYNCHRONOUS_TEST_FUNCTIONS_TO_WRAP: Sequence[MethodType] = cast(
        Sequence[MethodType],
        (
            # pylint: disable=protected-access
            unittest.TestCase._callSetUp,       # type: ignore
            unittest.TestCase._callTearDown,    # type: ignore
            unittest.TestCase._callCleanup,     # type: ignore
            unittest.TestCase._callTestMethod,  # type: ignore
        )
    )

    def __init__(self, loop: AbstractEventLoop):
        """Initialize the instance.

        Args:
            loop: Loop to run tests on.
        """
        self._loop = loop

    def create_test_suite(self, suite: unittest.TestSuite) -> unittest.TestSuite:
        """Create a suite that runs test setup/teardown on an asyncio loop.

        Args:
            suite: Test suite to copy and modify.

        Returns:
            Test suite that runs setup/teardown on an asyncio loop.

        Raises:
            ValueError: If suite is not an instance of TestSuite. Subclasses of
                TestSuite are not supported.
        """
        # pylint: disable-next=unidiomatic-typecheck
        if type(suite) is not unittest.TestSuite:
            raise ValueError(
                f'{suite} is a subclass of TestSuite which is not supported'
            )

        new_suite = unittest.TestSuite(
            [self.create_test(test) for test in _get_test_cases_from_suite(suite)]
        )
        CallableRunner.wrap_functions(
            self._loop, new_suite, self._TEST_SUITE_FUNCTIONS_TO_WRAP
        )
        return new_suite

    def create_test(
            self, test: unittest.TestCase | unittest.IsolatedAsyncioTestCase
        ) -> unittest.TestCase:
        """Create a test that runs setup/teardown and tests on an asyncio loop.

        Args:
            test: Test to copy and modify.

        Returns:
            Test case that runs setup/teardown and tests on an asyncio loop.
        """
        # NOTE: This is safe as it follows exactly the same approach used by
        # TestLoader.loadTestsFromTestCase().
        test_class = type(test)
        new_test = test_class(methodName=test.id().rsplit('.', maxsplit=1)[-1])
        return (
            self._patch_async_test(new_test)
            if isinstance(new_test, unittest.IsolatedAsyncioTestCase) else
            self._patch_sync_test(new_test)
        )

    def _patch_sync_test(self, test: unittest.TestCase) -> unittest.TestCase:
        """Patch a synchronous test to run on the associated asyncio loop.

        Args:
            test: Test to patch.

        Returns:
            Patched test.
        """
        CallableRunner.wrap_functions(
            self._loop, test, self._SYNCHRONOUS_TEST_FUNCTIONS_TO_WRAP
        )
        return test

    def _patch_async_test(
            self, test: unittest.IsolatedAsyncioTestCase
        ) -> unittest.TestCase:
        """Patch an asynchronous test to run on the associated asyncio loop.

        Args:
            test: Test to patch.

        Returns:
            Patched test.
        """
        # NOTE: This patches the test case's asyncio.Runner to run async
        # functions on the loop associated with this object.
        # IsolatedAsyncioTestCase runs all synchronous test methods
        # (test_* / setup / teardown / cleanup) using contextvars.Context.run()
        # so the following code replaces that with ContextLoopRunner which
        # also runs functions on the loop associated with this object.

        def _setup_asyncio_runner(
                _self: unittest.IsolatedAsyncioTestCase
        ) -> None:
            """Use a different asyncio loop to run coroutines."""
            # pylint: disable=protected-access
            _self._asyncioRunner = (  # type: ignore[attr-defined]
                PreconfiguredLoopRunner(self._loop)
            )

        setattr(
            test,
            # pylint: disable=protected-access
            unittest.IsolatedAsyncioTestCase
            ._setupAsyncioRunner.__name__,  # type: ignore
            MethodType(_setup_asyncio_runner, test)
        )

        # pylint: disable-next=protected-access
        test._asyncioTestContext = ContextLoopRunner(  # type: ignore[attr-defined]
            # pylint: disable-next=protected-access
            test._asyncioTestContext,  # type: ignore[attr-defined]
            self._loop, run_sync_on_loop
        )
        return test


class _TestResult(unittest.TextTestResult):
    """Test result that filters the CallableRunner from tracebacks."""

    _CALLABLE_RUNNER_FILENAME = realpath(
        getmodule(CallableRunner).__file__ or '' # type: ignore
    )

    _TESTCASE_FILENAME = realpath(
        getmodule(unittest.TestCase).__file__ or '' # type: ignore
    )

    def _clean_tracebacks(
        self, exctype: type[Exception] | None, value: Exception | None,
        tb: TracebackType | None, test: unittest.TestCase
    ) -> TracebackType:
        """Ignore stack frames associated with the CallableRunner.

        Args:
            exctype: Type of exception (ignored).
            value: Exception (ignored).
            tb: Traceback that is modified.
            test: Test case that threw the exception (ignored).

        Return:
            Modified traceback
        """
        # Filter out all stack frames between the CallableRunner and the TestCase.
        filtered_tbs: list[TracebackType] = []
        in_callable_runner = False
        while tb:
            module_filename = realpath(tb.tb_frame.f_code.co_filename)
            if (
                not in_callable_runner and
                module_filename == self._CALLABLE_RUNNER_FILENAME
            ):
                in_callable_runner = True
            elif module_filename == self._TESTCASE_FILENAME:
                in_callable_runner = False

            if not in_callable_runner:
                filtered_tbs.append(tb)
            tb = tb.tb_next

        previous_tb: TracebackType | None = None
        for filtered_tb in reversed(filtered_tbs):
            filtered_tb.tb_next = previous_tb
            previous_tb = filtered_tb
        tb = filtered_tbs[0] if filtered_tbs else None
        return super()._clean_tracebacks(exctype, value, tb, test)  # type: ignore[misc]


def _run_suite_on_asyncio_loop(
    test_suite: unittest.TestSuite,
    run_options: SingleTestRunOptions,
    loop: AbstractEventLoop
) -> bool:
    """Run a test suite on an asyncio loop.

    Args:
        test_suite: Suite to run on an asyncio loop.
        run_options: Options used to run the test suite.
        loop: Loop to run suite on.

    Returns:
        True if the test(s) passed, False otherwise.
    """
    test_cases = _get_test_cases_from_suite(test_suite)
    test_suite_that_runs_cases_on_asyncio_loop = (
        _TestOnAsyncioLoopFactory(loop).create_test_suite(
            test_suite
        )
    )
    test_runner = unittest.TextTestRunner(
        verbosity=run_options.verbosity, stream=run_options.output_stream,
        buffer=True,
        # pylint: disable-next=unnecessary-lambda
        resultclass=lambda *args: _TestResult(*args)  # type: ignore
    )
    test_result = test_runner.run(test_suite_that_runs_cases_on_asyncio_loop)

    # On test failure, resend error messages to stderr so that automated tests
    # in editor can see that the test failed.
    successful = test_result.wasSuccessful()
    if not successful:
        run_options.error_stream.write(
            ''.join([
                *[
                    f'{error_testcase}: {error_exc}\n'
                    for error_testcase, error_exc in test_result.errors
                ],
                *[
                    f'{failure_testcase}: {failure_exc}\n'
                    for failure_testcase, failure_exc in test_result.failures
                ]
            ])
        )
    run_options.on_complete(test_cases, successful)
    return successful


def run_test(
    test: unittest.TestSuite | unittest.TestCase,
    run_options: SingleTestRunOptions | None = None,
) -> Future[bool]:
    """Run a test with output that plays nicely with Unreal Automated tests.

    Args:
        test: Test case or suite to execute.
        run_options: Options used to run the test.

    Returns:
        Resolves to True if the test(s) passed, False otherwise.
    """
    run_options = run_options or SingleTestRunOptions()
    # We need to wrap the test in a TestSuite so that
    # setUpClass / tearDownClass and other hooks get called.
    test_suite = (
        test
        if isinstance(test, unittest.TestSuite) else
        unittest.TestSuite([test])
    )
    loop = _get_or_create_executor().loop
    thread_pool = ThreadPoolExecutor(max_workers=1)

    def _run() -> bool:
        """Runs a suite on a thread pool and shut down the pool."""
        try:
            return _run_suite_on_asyncio_loop(test_suite, run_options, loop)
        finally:
            thread_pool.shutdown(wait=False)

    return thread_pool.submit(_run)


async def _run_test_async(
    test: unittest.TestSuite | unittest.TestCase,
    run_options: SingleTestRunOptions | None = None,
) -> None:
    """Run a test with output that plays nicely with Unreal Automated tests.

    Args:
        test: Test case or suite to execute.
        run_options: Options used to run the test.
    """
    # NOTE: This cannot use asyncio.wrap_future as the completion executes on a
    # different thread.
    future_result = run_test(test, run_options=run_options)
    while not future_result.done():
        await sleep(0.0)
