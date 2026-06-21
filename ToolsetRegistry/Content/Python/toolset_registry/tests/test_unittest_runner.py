# Copyright Epic Games, Inc. All Rights Reserved.
"""Test unittest_runner."""

from asyncio import AbstractEventLoop
from datetime import datetime, timedelta
from io import StringIO
from concurrent.futures import Future
from contextlib import contextmanager
from time import perf_counter
from typing import Any, Callable, Generator, Sequence
from unittest import mock
import unittest

from . import unittest_runner
from . import _unittest_runner_test_cases
from ._asyncio import run_test_on_thread
from ._asyncio.test_editor_thread_ticker import FakeTickableUnrealModule
from .test_editor_thread_coroutine_executor import (
    CustomThreadCoroutineExecutor
)
from .unittest_runner import (
    SingleTestRunOptions, TestRunOptions, TestSearchOptions,
    clear_last_test_results, discover_tests, discover_and_run_tests,
    get_last_test_result, run_tests, run_test,
    _get_test_loader_by_root_package  # type: ignore
)


class UnittestRunnerTestCase(unittest.TestCase):
    """Test case for unittest_runner tests."""

    # Module that contains test cases to discover.
    TEST_MODULE = _unittest_runner_test_cases.__name__.rsplit('.', maxsplit=1)[-1]

    # Search options to find test cases.
    SEARCH_OPTIONS = TestSearchOptions(test_module_glob=TEST_MODULE)

    # Test IDs to use.
    TEST_SUCCEED_ID = (
        _unittest_runner_test_cases.TestSuccess.test_succeed.__qualname__
    )
    TEST_ERROR_ID = (
        _unittest_runner_test_cases.TestFailure.test_error.__qualname__
    )
    TEST_FAIL_ID = (
        _unittest_runner_test_cases.TestFailure.test_fail.__qualname__
    )
    TEST_ASYNC_ID = (
        _unittest_runner_test_cases.TestAsyncio.test_async.__qualname__
    )

    _fake_unreal: FakeTickableUnrealModule

    _TEST_TIMEOUT = timedelta(seconds=30)

    @staticmethod
    @contextmanager
    def _patch_unittest_runner() -> (
        Generator[FakeTickableUnrealModule, None, None]
    ):
        """Patch unittest runner with thread local fakes."""
        with CustomThreadCoroutineExecutor.create() as (
            executor, fake_unreal_module, _, _
        ):
            # Patch _run_suite_on_asyncio_loop() so that the fake unreal module
            # is available on the thread.
            real_run_suite_on_asyncio_loop = (
                # pylint: disable-next=protected-access
                unittest_runner._run_suite_on_asyncio_loop
            )

            def _run_suite_on_asyncio_loop(
                test_suite: unittest.TestSuite,
                run_options: SingleTestRunOptions,
                loop: AbstractEventLoop
            ) -> Any:
                with FakeTickableUnrealModule.install(
                    fake_unreal=fake_unreal_module
                ) as _:
                    return real_run_suite_on_asyncio_loop(
                        test_suite, run_options, loop
                    )

            with (
                mock.patch.object(
                    # pylint: disable=protected-access
                    unittest_runner._thread_local_storage,
                    'get_or_create_executor',
                    return_value=executor
                ) as _,
                mock.patch.object(
                    unittest_runner, '_run_suite_on_asyncio_loop',
                    _run_suite_on_asyncio_loop
                ) as _,
            ):
                yield fake_unreal_module

    @staticmethod
    @contextmanager
    def capture_output() -> (
        Generator[tuple[StringIO, StringIO, Callable[[], str]], None, None]
    ):
        """Capture stdout and stderr for this context.

        Yields:
            (output_stream, error_stream, get_output) where
            output_stream is a fake stdout stream, error_stream is a fake
            stderr stream and get_output is a callable that returns the
            contents of output_stream and error_stream.
        """
        with StringIO() as output_stream, StringIO() as error_stream:
            yield (
                output_stream,
                error_stream,
                lambda: '\n'.join((output_stream.getvalue(), error_stream.getvalue()))
            )

    @contextmanager
    def _setup(self) -> Generator[None, None, None]:
        """Patch in a fake unreal module."""
        with self._patch_unittest_runner() as self._fake_unreal:
            try:
                yield
            finally:
                clear_last_test_results()

    def discover_test(self, name: str) -> unittest.TestCase:
        """Discover a test in TEST_MODULE

        Args:
            name: Name of the test to find.

        Returns:
            Test case.
        """
        tests = discover_tests(
            TestSearchOptions(
                test_module_glob=self.TEST_MODULE,
                test_name_globs=set((f'*.{name}',))
            )
        )
        self.assertEqual(len(tests), 1, msg=str(tests))
        assert len(tests) == 1
        return tests[0]

    def get_short_test_case_ids(
        self, test_cases: Sequence[unittest.TestCase]
    ) -> Sequence[str]:
        """Get short IDs of test cases.

        Args:
            test_cases: Test cases to query.

        Returns:
            List of test case IDs with the package name removed.
        """
        fully_qualified_module_name = (
            f'{TestSearchOptions().root_module}.{self.TEST_MODULE}.'
        )
        short_test_case_ids: list[str] = []
        for test_case in test_cases:
            test_case_id = test_case.id()
            self.assertTrue(
                test_case_id.startswith(fully_qualified_module_name),
                msg=(
                    f'{test_case_id} does not start with '
                    f'{fully_qualified_module_name}'
                )
            )
            short_test_case_ids.append(
                test_case_id[len(fully_qualified_module_name):])
        return tuple(sorted(short_test_case_ids))

    def wait_for_test_completion(
            self, result_future: Future[bool]
        ) -> bool:
        """Wait for test(s) to complete.

        Args:
            result_future: Future to poll for completion.

        Returns:
            Value of result.
        """
        deadline = datetime.now() + self._TEST_TIMEOUT
        while True:
            if datetime.now() > deadline:
                raise TimeoutError()
            start_time = perf_counter()
            self._fake_unreal.tick()
            # Simulate tick period in the Unreal Editor.
            elapsed = perf_counter() - start_time
            try:
                result_future.result(
                    timeout=max(self._fake_unreal.DELTA_TIME - elapsed, 0.01)
                )
                break
            except TimeoutError:
                continue
        return result_future.result()


class TestTestSearchOptions(unittest.TestCase):
    """Test TestSearchOptions"""

    def test_all_fields_have_defaults(self):
        """Ensure all fields have default values."""
        search_options = TestSearchOptions()
        self.assertNotEqual(search_options.root_module, '')
        self.assertNotEqual(search_options.test_module_glob, '')
        self.assertSetEqual(search_options.test_name_globs, set())
        self.assertNotEqual(search_options.test_module_filename_glob, '')
        self.assertTrue(
            search_options.test_module_filename_glob.endswith('.py'),
            msg=search_options.test_module_filename_glob)


class TestDiscoverTests(UnittestRunnerTestCase):
    """Test discover_tests()."""

    def test_creates_new_loader_for_each_root_package(self):
        """Ensure a loader is created for different root packages."""
        loader1 = _get_test_loader_by_root_package('bish.bash')
        loader2 = _get_test_loader_by_root_package('foo.bar')
        self.assertIsNot(loader1, loader2)

    def test_filter_by_package(self):
        """Test filtering tests by package."""
        tests = discover_tests(
            TestSearchOptions(
                root_module=(
                    f'{_unittest_runner_test_cases.__name__}'
                ),
                test_module_glob=self.TEST_MODULE,
            )
        )
        self.assertSequenceEqual(
            self.get_short_test_case_ids(tests),
            (
                self.TEST_ASYNC_ID, self.TEST_ERROR_ID, self.TEST_FAIL_ID,
                self.TEST_SUCCEED_ID,
            )
        )

    def test_filter_by_module(self):
        """Test filtering tests by module"""
        tests = discover_tests(self.SEARCH_OPTIONS)
        self.assertSequenceEqual(
            self.get_short_test_case_ids(tests),
            (
                self.TEST_ASYNC_ID, self.TEST_ERROR_ID, self.TEST_FAIL_ID,
                self.TEST_SUCCEED_ID,
            )
        )

    def test_filter_by_name(self):
        """Test filtering tests by name"""
        tests = discover_tests(
            TestSearchOptions(
                test_module_glob=self.TEST_MODULE,
                test_name_globs=set(('*.test_er*', '*succeed'))
            )
        )
        self.assertSequenceEqual(
            self.get_short_test_case_ids(tests),
            (self.TEST_ERROR_ID, self.TEST_SUCCEED_ID)
        )


class TestRunTest(UnittestRunnerTestCase):
    """Test run_test."""

    def run_test_capture_output(
            self, name: str,
            verbosity: int = SingleTestRunOptions().verbosity
        ) -> tuple[bool, str, str]:
        """Run a test and capture its output.

        Args:
            name: Name of the test to run.
            verbosity: Verbosity of the test's output.

        Returns:
            (successful, output, error_output) tuple.
        """
        test = self.discover_test(name)
        with self.capture_output() as (
            output_stream, error_stream, get_output
        ):
            result = self.wait_for_test_completion(
                run_test(
                    test,
                    run_options=SingleTestRunOptions(
                        verbosity=verbosity,
                        output_stream=output_stream,
                        error_stream=error_stream
                    )
                )
            )
            return (result, get_output(), error_stream.getvalue())

    @run_test_on_thread
    def test_run_successful_test(self):
        """Test running a successful test."""
        successful, output, error_output = (
            self.run_test_capture_output(self.TEST_SUCCEED_ID)
        )
        self.assertIn(self.TEST_SUCCEED_ID, output)
        self.assertTrue(successful, msg=output)
        self.assertEqual(error_output, '')

    @run_test_on_thread
    def test_run_test_low_verbosity(self):
        """Test running a test with low verbosity."""
        successful, output, error_output = self.run_test_capture_output(
            self.TEST_SUCCEED_ID,
            verbosity=1
        )
        self.assertNotIn(self.TEST_SUCCEED_ID, output)
        self.assertTrue(successful, msg=output)
        self.assertEqual(error_output, '')

    @run_test_on_thread
    def test_run_failing_test(self):
        """Test running a failing test."""
        for name, expected_error in (
            (
                self.TEST_FAIL_ID,
                'self.assertTrue(False)'
            ),
            (
                self.TEST_ERROR_ID,
                'SyntaxError'
            )
        ):
            with self.subTest(name):
                successful, output, error_output = (
                    self.run_test_capture_output(name)
                )
                self.assertIn(name, output)
                self.assertFalse(successful, msg=output)
                self.assertIn(expected_error, error_output)

    @run_test_on_thread
    def test_run_async_test(self):
        """Test running an async test."""
        successful, output, error_output = self.run_test_capture_output(
            self.TEST_ASYNC_ID
        )
        self.assertIn(self.TEST_ASYNC_ID, output)
        self.assertTrue(successful, msg=output)
        self.assertEqual(error_output, '')


class OnTestCompletionHandler:  # pylint: disable=too-few-public-methods
    """Handles test completion storing the result."""

    def __init__(self):
        """Initialize an empty handler."""
        self.completed: list[unittest.TestCase] = []
        self.successful = True

    def __call__(
            self, test_cases: Sequence[unittest.TestCase], successful: bool
        ) -> None:
        """Called when a test completes.

        Args:
            test_cases: Completed test case(s).
            successful: Whether the test case(s) completed sucessfully.
        """
        self.completed.extend(test_cases)
        self.successful = self.successful and successful


class TestRunTests(UnittestRunnerTestCase):
    """Test test execution"""

    SUCCESS_SEARCH_OPTIONS = TestSearchOptions(
        test_module_glob=UnittestRunnerTestCase.TEST_MODULE,
        test_name_globs=set((f'*.{UnittestRunnerTestCase.TEST_SUCCEED_ID}',))
    )

    FAIL_SEARCH_OPTIONS = TestSearchOptions(
        test_module_glob=UnittestRunnerTestCase.TEST_MODULE,
        test_name_globs=set((f'*.{UnittestRunnerTestCase.TEST_FAIL_ID}',))
    )

    TEST_CASES = (
        (
            SUCCESS_SEARCH_OPTIONS,
            True,
            (UnittestRunnerTestCase.TEST_SUCCEED_ID,)
        ),
        (
            FAIL_SEARCH_OPTIONS,
            False,
            (UnittestRunnerTestCase.TEST_FAIL_ID,)
        ),
    )

    def _assert_last_test_result(
            self,
            tests: Sequence[unittest.TestCase],
            expected_result: bool | None
        ):
        """Ensure the last result of all specified tests matches.

        Args:
            tests: Tests to query the last result of.
            expected_result: Expected result of all tests.
        """
        self.assertDictEqual(
            {test.id(): get_last_test_result(test.id()) for test in tests},
            {test.id(): expected_result for test in tests},
        )

    @run_test_on_thread
    def test_no_tests(self):
        """Test running with no tests."""
        handler = OnTestCompletionHandler()
        all_handler = OnTestCompletionHandler()
        result = self.wait_for_test_completion(
            run_tests(
                (),
                TestRunOptions(
                    on_complete=handler,
                    on_all_complete=all_handler)
            )
        )
        self.assertSequenceEqual(handler.completed, [])
        self.assertFalse(handler.successful)
        self.assertEqual(handler.successful, result)
        self.assertSequenceEqual(handler.completed, all_handler.completed)
        self.assertEqual(handler.successful, all_handler.successful)

    @run_test_on_thread
    def test_run_one_test(self):
        """Test running one test at a time."""
        for search_options, expected_success, expected_test_case_ids in (
            self.TEST_CASES
        ):
            with self.subTest(search_options=search_options):
                clear_last_test_results()
                handler = OnTestCompletionHandler()
                all_handler = OnTestCompletionHandler()
                tests = discover_tests(search_options=search_options)
                self._assert_last_test_result(tests, None)
                with self.capture_output() as (
                    output_stream, error_stream, get_output
                ):
                    result = self.wait_for_test_completion(
                        run_tests(
                            tests,
                            run_options=TestRunOptions(
                                on_complete=handler,
                                on_all_complete=all_handler,
                                output_stream=output_stream,
                                error_stream=error_stream
                            )
                        )
                    )
                    self.assertEqual(
                        handler.successful, expected_success, msg=get_output()
                    )
                    self.assertEqual(
                        result, expected_success, msg=get_output()
                    )
                    self.assertSequenceEqual(
                        self.get_short_test_case_ids(handler.completed),
                        expected_test_case_ids,
                        msg=get_output()
                    )
                    self.assertEqual(
                        all_handler.successful, handler.successful,
                        msg=get_output()
                    )
                    self.assertEqual(
                        all_handler.completed, handler.completed,
                        msg=get_output()
                    )
                    self._assert_last_test_result(tests, expected_success)

    @run_test_on_thread
    def test_run_multiple(self):
        """Test running multiple tests."""
        handler = OnTestCompletionHandler()
        with self.capture_output() as (
            output_stream, error_stream, get_output
        ):
            result = self.wait_for_test_completion(
                run_tests(
                    discover_tests(
                        TestSearchOptions(test_module_glob=self.TEST_MODULE)
                    ),
                    run_options=TestRunOptions(
                        on_complete=handler,
                        output_stream=output_stream,
                        error_stream=error_stream
                    )
                )
            )
            self.assertFalse(handler.successful, msg=get_output())
            self.assertEqual(result, handler.successful, msg=get_output())
            self.assertSequenceEqual(
                self.get_short_test_case_ids(handler.completed),
                (
                    self.TEST_ASYNC_ID, self.TEST_ERROR_ID, self.TEST_FAIL_ID,
                    self.TEST_SUCCEED_ID
                ),
                msg=get_output()
            )

    @run_test_on_thread
    def test_discover_and_run_tests(self):
        """Test discovering and running tests."""
        handler = OnTestCompletionHandler()
        all_handler = OnTestCompletionHandler()
        with self.capture_output() as (
            output_stream, error_stream, get_output
        ):
            tests, result_future = discover_and_run_tests(
                self.SUCCESS_SEARCH_OPTIONS,
                run_options=TestRunOptions(
                    on_complete=handler,
                    on_all_complete=all_handler,
                    output_stream=output_stream,
                    error_stream=error_stream
                )
            )
            result = self.wait_for_test_completion(result_future)
            self.assertSequenceEqual(
                self.get_short_test_case_ids(tests),
                (UnittestRunnerTestCase.TEST_SUCCEED_ID,),
                msg=get_output()
            )
            self.assertTrue(handler.successful, msg=get_output())
            self.assertEqual(handler.successful, result, msg=get_output())
            self.assertSequenceEqual(
                self.get_short_test_case_ids(handler.completed),
                (UnittestRunnerTestCase.TEST_SUCCEED_ID,),
                msg=get_output()
            )
            self.assertEqual(
                all_handler.successful, handler.successful,
                msg=get_output()
            )
            self.assertEqual(
                all_handler.completed, handler.completed,
                msg=get_output()
            )


if __name__ == '__main__':  # pragma: no cover
    unittest.main()
