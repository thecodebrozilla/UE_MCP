# Copyright Epic Games, Inc. All Rights Reserved.
"""Test the programmatic toolset."""

from asyncio import get_event_loop, wrap_future
import builtins
from collections.abc import Callable
from concurrent.futures import Future, ThreadPoolExecutor
from contextlib import contextmanager, ExitStack
import inspect
import json
import os
import tempfile
from time import perf_counter
from typing import Any, Generator, IO
import unittest
from unittest import mock

import unreal

# Because tool calls are wrapped in a decorator that consumes exceptions, we
# need to call the underlying execution function directly to verify that
# exceptions propagate as expected.
from editor_toolset.toolsets.programmatic import (
    ProgrammaticApiLanguage,
    ProgrammaticToolset,
    _MAX_SCRIPT_FRAMES,
    _StrictDict,
    _ScriptRunner,
    _FileOpener,
    _TransactionScope,
)

from toolset_registry.tests.demo_toolset import ErrorProneToolset
from toolset_registry.tests.toolset_testcase import ErrorProneToolsetTestCase
from toolset_registry._registry_interface import (
    execute_tool as execute_tool_via_registry,
    ToolsetToolInvocationError
)
from toolset_registry.tests.test_execute_tool import (
    FAKE_ERROR_PRONE_TOOLSET_NAME,
    BUGGY_TOOL_NAME,
    BUGGY_TOOL_ERROR_MESSAGE
)


class TestCaseWithAssertRaisesWithCause(unittest.IsolatedAsyncioTestCase):
    """TestCase that adds assert_raises_runtime_error_with_cause()."""

    @contextmanager
    def assert_raises_runtime_error_with_cause(
        self, cause_type: type
    ) -> Generator[Any, None, None]:
        """Test that a RuntimeError is raised with the specified exception as
        its cause.  Can be used as a context manager just like assertRaises.

        Exceptions raised inside tool calls are wrapped in RuntimeError with
        line info by _sandboxed_exec; the original exception is chained as
        __cause__.
        """
        with self.assertRaises(RuntimeError) as ctx:
            yield ctx
        self.assertIsInstance(ctx.exception.__cause__, cause_type)


class TestStrictDict(unittest.TestCase):
    """Test _StrictDict."""

    def test_getitem_existing_key_returns_value(self):
        """Ensure getitem returns the value of an existing key."""
        d = _StrictDict({"a": 1, "b": 2})
        self.assertEqual(d["a"], 1)

    def test_getitem_missing_key_raises_key_error(self):
        """Ensure getitem raises when getting a missing key."""
        d = _StrictDict({"min": 0, "max": 10})
        with self.assertRaises(KeyError) as ctx:
            _ = d["origin"]
        self.assertIn("origin", str(ctx.exception))
        self.assertIn("min", str(ctx.exception))
        self.assertIn("max", str(ctx.exception))

    def test_get_existing_key_returns_value(self):
        """Ensure get return the value of an existing key."""
        d = _StrictDict({"a": 1})
        self.assertEqual(d.get("a"), 1)

    def test_get_missing_key_raises_key_error(self):
        """Ensure get raises when getting a missing key."""
        d = _StrictDict({"min": 0, "max": 10})
        with self.assertRaises(KeyError) as ctx:
            d.get("origin")
        self.assertIn("origin", str(ctx.exception))
        self.assertIn("min", str(ctx.exception))
        self.assertIn("max", str(ctx.exception))
        nested = _StrictDict({"returnValue": _StrictDict({"min": 0, "max": 10})})
        with self.assertRaises(KeyError) as ctx:
            nested["returnValue"].get("origin")
        self.assertIn("origin", str(ctx.exception))
        self.assertIn("min", str(ctx.exception))
        self.assertIn("max", str(ctx.exception))
        nested = _StrictDict({"returnValue": _StrictDict({"min": 0, "max": 10})})
        with self.assertRaises(KeyError) as ctx:
            nested["returnValue"].get("origin")
        self.assertIn("origin", str(ctx.exception))
        self.assertIn("min", str(ctx.exception))
        self.assertIn("max", str(ctx.exception))

    def test_get_raises_type_error_when_default_is_set(self):
        """Ensure get raises when a default value is provided."""
        d = _StrictDict({"a": 1})
        with self.assertRaises(TypeError):
            d.get("a", "default")



class TestGetProgrammaticApiExecutionEnvironmentInfo(unittest.TestCase):
    """Test the programmatic API's environment informaiton."""

    def setUp(self):
        """Get the execution environment info."""
        self.info = ProgrammaticToolset.get_execution_environment()

    def test_language_is_python(self):
        """Ensure the language is Python"""
        self.assertEqual(ProgrammaticApiLanguage.PYTHON.value, "python")
        self.assertEqual(
            self.info.language, ProgrammaticApiLanguage.PYTHON.value
        )

    def test_has_supported_modules(self):
        """Ensure some modules can be imported."""
        self.assertGreater(len(self.info.supported_modules), 0)

    def test_has_instructions(self):
        """Ensure instructions are present."""
        self.assertNotEqual(self.info.instructions, '')

    def test_supported_modules_have_name_and_description(self):
        """Ensure each module has a name and description."""
        for module in self.info.supported_modules:
            self.assertIsInstance(module.name, str)
            self.assertIsInstance(module.description, str)


# pylint: disable-next=protected-access
_resolve_project_path = _FileOpener._resolve_project_path


class TestResolveProjectPath(unittest.TestCase):
    """Tests for _resolve_project_path path-containment validation."""

    def _project_root(self) -> str:
        return os.path.realpath(
            unreal.Paths.convert_relative_path_to_full(
                unreal.Paths.project_dir()))

    def test_relative_path_resolves_under_project_root(self):
        """Ensure the current directory resolves to the project root."""
        resolved = _resolve_project_path(".")
        self.assertEqual(resolved, self._project_root())

    def test_paths_outside_project_are_rejected(self):
        """Resolving paths outside of the project should raise."""
        outside_paths = [
            "../../../etc/passwd",
            os.path.join(os.path.dirname(self._project_root()), "other_project"),
        ]
        for path in outside_paths:
            with self.subTest(path=path):
                with self.assertRaises(ValueError) as ctx:
                    _resolve_project_path(path)
                self.assertIn("outside all allowed directories", str(ctx.exception))

    def test_cross_drive_path_is_rejected_with_structured_message(self):
        """Ensure resolving paths outside of the project's drive raise."""
        # On Windows, os.path.commonpath raises ValueError for paths on
        # different drives. _resolve_project_path must convert that into the
        # standard 'outside the project directory' message rather than letting
        # an unrelated ValueError propagate.
        project_root = self._project_root()
        drive = os.path.splitdrive(project_root)[0]
        # Pick whichever drive letter is not the project drive. If the project
        # is on C: try D:, otherwise try C:. Skip the test if no alternative
        # drive letter can be determined (non-Windows or single-drive layout).
        alt_drive = "D:" if drive.upper() != "D:" else "C:"
        cross_drive_path = alt_drive + "\\evil\\path"
        with self.assertRaises(ValueError) as ctx:
            _resolve_project_path(cross_drive_path)
        self.assertIn("outside all allowed directories", str(ctx.exception))

    def test_nested_path_within_project_is_accepted(self):
        """Test resolving a path within a project."""
        resolved = _resolve_project_path("Config")
        self.assertTrue(resolved.startswith(self._project_root()))


class TestResolveProjectPathWithSeparateSavedDir(unittest.TestCase):
    """Tests for _resolve_project_path when project_saved_dir is outside project_dir.

    Simulates a CI layout where the two directories are siblings rather than
    parent/child.  unreal.Paths is a C++ extension type whose attributes are
    immutable, so we patch _real_path in the production module instead, routing
    the actual UE path strings to controlled temp directories.
    """

    def setUp(self):
        self._exit_stack = ExitStack()

        self._project_dir = os.path.realpath(
            self._exit_stack.enter_context(tempfile.TemporaryDirectory()))
        self._saved_dir = os.path.realpath(
            self._exit_stack.enter_context(tempfile.TemporaryDirectory()))

        # Build a mapping from the real UE path strings to our fake dirs so
        # that _real_path returns the fake root when called from _resolve_project_path.
        real_project_ue_path = unreal.Paths.project_dir()
        real_saved_ue_path = unreal.Paths.project_saved_dir()

        def _fake_real_path(ue_path: str) -> str:
            if ue_path == real_project_ue_path:
                return self._project_dir
            if ue_path == real_saved_ue_path:
                return self._saved_dir
            return os.path.realpath(ue_path)

        _ = self._exit_stack.enter_context(
            mock.patch.object(
                _FileOpener, '_real_path', side_effect=_fake_real_path
            )
        )

    def tearDown(self):
        self._exit_stack.close()

    def test_relative_path_resolves_under_project_dir(self):
        """Test resolving a path within a project."""
        resolved = _resolve_project_path("Config")
        self.assertTrue(resolved.startswith(self._project_dir))

    def test_absolute_path_under_project_dir_is_accepted(self):
        """Test resolving an absolute path within a project."""
        abs_path = os.path.join(self._project_dir, "Config", "file.ini")
        resolved = _resolve_project_path(abs_path)
        self.assertEqual(resolved, abs_path)

    def test_absolute_path_under_saved_dir_is_accepted(self):
        """Test resolving an absolute path within the saved directory."""
        abs_path = os.path.join(self._saved_dir, "Logs", "output.log")
        resolved = _resolve_project_path(abs_path)
        self.assertEqual(resolved, abs_path)

    def test_path_outside_both_roots_is_rejected(self):
        """Ensure resolving paths outside of saved or project dirs raises."""
        # Parent of both temp dirs (they share a common tmp prefix).
        outside_path = os.path.join(
            os.path.dirname(self._project_dir), "evil.txt")
        with self.assertRaises(ValueError) as ctx:
            _resolve_project_path(outside_path)
        self.assertIn("outside all allowed directories", str(ctx.exception))


class TestUnrealOpen(unittest.IsolatedAsyncioTestCase):
    """Tests for the restricted open() replacement injected into the sandbox."""

    @staticmethod
    async def _open_file(
        file: int | str | bytes | os.PathLike[str] | os.PathLike[bytes],
        mode: str, **kwargs: Any
    ) -> IO[Any]:
        """Open a file using the file opener from another thread.

        Args:
            file: File to open.
            mode: File open mode.

        Returns:
            File handle.
        """
        file_opener = _FileOpener(get_event_loop())
        with ThreadPoolExecutor() as executor:
            result: IO[Any] = await wrap_future(
                executor.submit(file_opener, file, mode, **kwargs)
            )
        return result

    async def test_disallowed_modes_are_rejected(self):
        """Ensure unsafe file open modes raises."""
        for mode in ("w", "a", "x", "r+", "wb", "ab", "w+", "rb+"):
            with self.subTest(mode=mode):
                with self.assertRaises(ValueError) as ctx:
                    await self._open_file("some_file.txt", mode)
                self.assertIn("is not permitted", str(ctx.exception))

    async def test_path_traversal_is_rejected(self):
        """Ensure opening files outside of allowed directories raises."""
        with self.assertRaises(ValueError) as ctx:
            await self._open_file("../../../etc/passwd", "r")
        self.assertIn("outside all allowed directories", str(ctx.exception))

    async def _assert_file_has_contents(
        self, expected_contents: str | bytes, filename: str,
        **kwargs: Any
    ):
        """Read a file from a thread, validating its contents.

        Args:
            expected_contents: Expected contents of the file.
            filename: Filename to read and delete after reading.
            mode: File open mode.
            **kwargs: Arguments passed to the file opener.
        """
        try:
            with await self._open_file(filename, **kwargs) as f:
                content = f.read()
            self.assertEqual(content, expected_contents)
        finally:
            os.unlink(filename)

    async def test_read_file_within_project_dir(self):
        """Test reading a file within the project directory."""
        saved_dir = unreal.Paths.convert_relative_path_to_full(
            unreal.Paths.project_saved_dir())
        tmp_path = os.path.join(saved_dir, "test_unreal_open_read.txt")
        contents = "hello"
        with builtins.open(tmp_path, "w", encoding="utf-8") as f:
            f.write(contents)
        await self._assert_file_has_contents(
            contents, tmp_path, mode="r", encoding="utf-8"
        )

    async def test_binary_read_is_permitted(self):
        """Test reading a binary file."""
        saved_dir = unreal.Paths.convert_relative_path_to_full(
            unreal.Paths.project_saved_dir())
        tmp_path = os.path.join(saved_dir, "test_unreal_open_binary.txt")
        contents = b"bytes"
        with builtins.open(tmp_path, "wb") as f:
            f.write(contents)
        await self._assert_file_has_contents(contents, tmp_path, mode="rb")


async def _run_script(script: str) -> dict[str, Any]:
    """Run a script using_ _ScriptRunner().

    Args:
        script: Script to run.

    Returns:
        Result of the script.
    """
    with _ScriptRunner(script) as runner:
        result_future = runner()
        result = await wrap_future(result_future)
        return result


class TestExecuteProgrammaticApis(TestCaseWithAssertRaisesWithCause):
    """Test execution with the programmatic toolset."""

    async def test_returns_dict_from_run(self):
        """Ensure a dict is returned from a valid script."""
        result = await _run_script(
            "def run():\n"
            "    return {'key': 'value'}"
        )
        self.assertEqual(result["key"], "value")

    async def test_empty_dict_return(self):
        """Test running a script that returns an empty dict"""
        result = await _run_script(
            "def run():\n"
            "    return {}"
        )
        self.assertEqual(result, {})

    async def test_run_with_computation(self):
        """Test running a simple script with a computed result."""
        result = await _run_script(
            "def run():\n"
            "    x = 1 + 1\n"
            "    return {'result': x}\n"
        )
        self.assertEqual(result["result"], 2)

    async def test_missing_run_raises_value_error(self):
        """Ensure running a script without a run method raises."""
        with self.assertRaises(ValueError) as ctx:
            await _run_script("x = 1 + 1")
        self.assertIn("run()", str(ctx.exception))

    async def test_non_dict_return_raises_type_error(self):
        """Ensure running a script that does not return a dict raises."""
        with self.assertRaises(TypeError):
            await _run_script(
                "def run():\n"
                "    return 'not a dict'"
            )

    async def test_none_return_raises_type_error(self):
        """Ensure running a script that doesreturns None raises."""
        with self.assertRaises(TypeError):
            await _run_script(
                "def run():\n"
                "    pass"
            )

    async def test_syntax_error_raises(self):
        """Ensure a script with a syntax error raises."""
        with self.assertRaises(SyntaxError):
            await _run_script("def !!!")

    async def test_runtime_error_raises(self):
        """Ensure a script with a runtime error raises."""
        with self.assert_raises_runtime_error_with_cause(ZeroDivisionError):
            await _run_script(
                "def run():\n"
                "    return 1/0"
            )

    async def test_unhandled_exception_propagates(self):
        """Ensure unhandled exceptions are raised by the script executor."""
        with self.assertRaises(RuntimeError):
            await _run_script(
                "def run():\n"
                "    raise RuntimeError('fail')"
            )

    async def test_can_import_json(self):
        """Test importing the json module."""
        script = (
            "import json\n"
            "def run():\n"
            "    return json.loads('{\"key\": \"value\"}')\n"
        )
        result = await _run_script(script)
        self.assertEqual(result["key"], "value")

    async def test_can_import_math(self):
        """Test importing the math module."""
        script = (
            "import math\n"
            "def run():\n"
            "    return {'pi': str(math.pi)}\n"
        )
        result = await _run_script(script)
        self.assertIn("3.14159", result["pi"])

    async def test_can_import_datetime(self):
        """Test importing the datetime module."""
        result = await _run_script(
            "import datetime\n"
            "def run():\n"
            "    return {'date': str(datetime.date(2024, 1, 1))}\n"
        )
        self.assertEqual(result["date"], "2024-01-01")

    async def test_can_import_time(self):
        """Test importing the time module."""
        result = await _run_script(
            "import time\n"
            "def run():\n"
            "    counter = time.perf_counter()\n"
            "    return {'counter': counter}\n"
        )
        self.assertGreaterEqual(perf_counter(), result['counter'])

    async def test_can_import_copy(self):
        """Test importing the copy module."""
        result = await _run_script(
            "import copy\n"
            "def run():\n"
            "    x = [1, 2]\n"
            "    y = copy.deepcopy(x)\n"
            "    return {'copied': y}\n"
        )
        self.assertEqual(result["copied"], [1, 2])

    async def test_can_import_re(self):
        """Test importing the re module."""
        result = await _run_script(
            "import re\n"
            "def run():\n"
            "    m = re.match(r'(\\w+)', 'hello world')\n"
            "    return {'match': m.group(1)}\n"
        )
        self.assertEqual(result["match"], "hello")

    async def test_execute_tool_builtin_is_callable(self):
        """Ensure execute_tool is callable."""
        result = await _run_script(
            "def run():\n"
            "    return {'is_callable': callable(execute_tool)}\n"
        )
        self.assertTrue(result["is_callable"])

    async def test_can_use_loop_to_batch_operations(self):
        """Test loop execution."""
        result = await _run_script(
            "def run():\n"
            "    results = []\n"
            "    for i in range(5):\n"
            "        results.append(i * 2)\n"
            "    return {'results': results}\n"
        )
        self.assertEqual(result["results"], [0, 2, 4, 6, 8])

    async def test_helper_functions_alongside_run(self):
        """Test helper function execution."""
        result = await _run_script(
            "def double(x):\n"
            "    return x * 2\n"
            "\n"
            "def run():\n"
            "    return {'value': double(21)}\n"
        )
        self.assertEqual(result["value"], 42)


class TestExecuteProgrammaticApisSecurity(TestCaseWithAssertRaisesWithCause):
    """Test basic security of the programmatic environment."""

    _MINIMAL_RUN = (
        "def run():\n"
        "    return {}"
    )

    async def test_disallowed_import_is_blocked(self):
        """Ensure importing disallowed imports raises."""
        with self.assertRaises(ValueError) as ctx:
            await _run_script("import os\n" + self._MINIMAL_RUN)
        self.assertIn("'os' is not permitted", str(ctx.exception))

    async def test_disallowed_from_import_is_blocked(self):
        """Ensure importing a module from a blocked package raises."""
        with self.assertRaises(ValueError) as ctx:
            await _run_script("from os import path\n" + self._MINIMAL_RUN)
        self.assertIn("'os' is not permitted", str(ctx.exception))

    async def test_disallowed_submodule_import_is_blocked(self):
        """Ensure importing a module from a blocked package raises."""
        # Top-level module name determines allowance; 'os' is blocked even via
        # a submodule path like 'os.path'.
        with self.assertRaises(ValueError) as ctx:
            await _run_script("import os.path\n" + self._MINIMAL_RUN)
        self.assertIn("'os.path' is not permitted", str(ctx.exception))

    async def test_relative_import_is_blocked(self):
        """Ensure a blocked relative import raises."""
        with self.assertRaises(ValueError) as ctx:
            await _run_script(
                "from . import something\n" + self._MINIMAL_RUN
            )
        self.assertIn("Relative imports are not permitted", str(ctx.exception))

    async def test_allowed_from_import_works(self):
        """Test importing an allowed import."""
        result = await _run_script(
            "from json import dumps\n"
            "def run():\n"
            "    return {'data': dumps([1, 2, 3])}\n"
        )
        self.assertIn("[1, 2, 3]", result["data"])

    async def test_allowed_submodule_from_import_works(self):
        """Test importing a module from a package."""
        # A 'from' import of a submodule of an allowed package is permitted.
        result = await _run_script(
            "from json.decoder import JSONDecoder\n"
            "def run():\n"
            "    return {'data': JSONDecoder().decode('[1]')}\n"
        )
        self.assertEqual(result["data"], [1])

    async def test_disallowed_import_does_not_execute_preceding_code(self):
        """Ensure code can not be executed before imports."""
        # Validation runs before exec, so no script code runs on a bad import.
        # The ValueError (from AST validation) rather than a runtime error
        # proves the script never executed.
        with self.assertRaises(ValueError) as ctx:
            await _run_script(
                "x = 1 / 0  # would raise ZeroDivisionError if executed\n"
                "import os\n"
                f"{self._MINIMAL_RUN}"
            )
        self.assertIn("'os' is not permitted", str(ctx.exception))

    async def test_exec_builtin_is_not_available(self):
        """Ensure using exec() raises."""
        with self.assert_raises_runtime_error_with_cause(NameError):
            await _run_script(
                "def run():\n"
                "    exec('x = 1')\n"
                "    return {}"
            )

    async def test_eval_builtin_is_not_available(self):
        """Ensure using eval() raises."""
        with self.assert_raises_runtime_error_with_cause(NameError):
            await _run_script(
                "def run():\n"
                "    eval('1 + 1')\n"
                "    return {}"
            )

    async def test_open_disallowed_mode_is_rejected(self):
        """Ensure using open with a blocked mode raises."""
        script = (
            "def run():\n"
            "    open('somefile.txt', 'w')\n"
            "    return {}\n"
        )
        with self.assert_raises_runtime_error_with_cause(ValueError):
            await _run_script(script)

    async def test_open_path_traversal_is_rejected(self):
        """Ensure using open using an invalid path raises."""
        with self.assert_raises_runtime_error_with_cause(ValueError):
            await _run_script(
                "def run():\n"
                "    open('../../../etc/passwd', 'r')\n"
                "    return {}\n"
            )

    async def test_compile_builtin_is_not_available(self):
        """Ensure using compile() raises."""
        with self.assert_raises_runtime_error_with_cause(NameError):
            await _run_script(
                "def run():\n"
                "    compile('1+1', '<string>', 'eval')\n"
                "    return {}\n"
            )

    async def test_input_builtin_is_not_available(self):
        """Ensure using input() raises."""
        with self.assert_raises_runtime_error_with_cause(NameError):
            await _run_script(
                "def run():\n"
                "    input('prompt: ')\n"
                "    return {}"
            )

    async def test_breakpoint_builtin_is_not_available(self):
        """Ensure using breakpoint() raises."""
        with self.assert_raises_runtime_error_with_cause(NameError):
            await _run_script(
                "def run():\n"
                "    breakpoint()\n"
                "    return {}"
            )

    async def test_builtins_mutation_does_not_persist_across_executions(self):
        """Ensure each execution environment starts with new builtins."""
        # A script that injects a new key into __builtins__ must not affect
        # subsequent executions. This verifies _SAFE_BUILTINS is copied, not
        # shared, across calls.
        await _run_script(
            "__builtins__['injected_fn'] = lambda: 42\n"
            f"{self._MINIMAL_RUN}"
        )
        with self.assert_raises_runtime_error_with_cause(NameError):
            await _run_script(
                "def run():\n"
                "    injected_fn()\n"
                "    return {}"
            )


def execute_tool(
    toolset_name: str, tool_name: str, json_input: str
) -> _StrictDict:
    """Provides a _ToolExecutor() for test scripts."""
    _ = toolset_name, tool_name, json_input
    raise ValueError('Should not be executed outside of the script')


def _get_function_body_source(func: Callable[..., Any]) -> str:
    """Get a function body's source code.

    NOTE: This can't handle functions with type annotated arguments.

    Args:
        func: Function to query.

    Returns:
        Source code of the function.
    """
    assert func.__doc__, 'Supplied function must have a doc string.'
    source = inspect.getsource(func)
    body = source[source.index(':\n'):]
    doc_lines = len(func.__doc__.splitlines())
    lines = body.splitlines()[doc_lines + 1:]
    indent = len(lines[0]) - len(lines[0].lstrip())
    lines = [line[indent:] for line in lines]
    return '\n'.join(lines)


BAD_TOOLSET_NAME = (
    f'{ErrorProneToolset.__module__}.{ErrorProneToolset.__name__}'
)

class TestExecuteProgrammaticToolCall(
    ErrorProneToolsetTestCase, unittest.IsolatedAsyncioTestCase
):
    """Test tool call for executing script."""

    _TOOLSET_NAME = (
        f'{ProgrammaticToolset.__module__}.{ProgrammaticToolset.__name__}'
    )

    @staticmethod
    def successful_script():
        """Successful script."""
        def run():  # pylint: disable=unused-variable
            return {'foo': 'bar'}

    @staticmethod
    def bad_script():
        """Bad script"""
        # pylint: disable-next=import-outside-toplevel,redefined-outer-name,reimported
        import json

        def run_bad_method():
            execute_tool(
                f'{BAD_TOOLSET_NAME}.bad_tool', json.dumps({'msg': 'hi'})
            )

        def run_bad_typed_method():
            execute_tool(
                f'{BAD_TOOLSET_NAME}.bad_typed_tool', json.dumps({'msg': 'hi'})
            )

        def run_multiple_bad_methods():
            run_bad_method()
            run_bad_typed_method()

        def run():  # pylint: disable=unused-variable
            run_multiple_bad_methods()
            raise RuntimeError('should never get here')

    async def test_succesful_tool(self):
        """Testing calling a successful tool via the registry."""
        result = await execute_tool_via_registry(
            self._TOOLSET_NAME,
            ProgrammaticToolset.execute_tool_script.__name__,
            {'script': _get_function_body_source(self.successful_script)}
        )
        self.assertDictEqual(
            result,
            {'returnValue': json.dumps({'foo': 'bar'})}
        )

    async def test_call_other_tools_with_error(self):
        """Exception raised in tool calls from script should raise immediately
        before executing remainder of script.
        """
        with self.assertRaises(ToolsetToolInvocationError) as context:
            script = (
                _get_function_body_source(self.bad_script)
                .replace('BAD_TOOLSET_NAME', f'"{BAD_TOOLSET_NAME}"')
            )
            _ = await execute_tool_via_registry(
                self._TOOLSET_NAME,
                ProgrammaticToolset.execute_tool_script.__name__,
                {'script': script}
            )
        self.assertIn('Bad tool bad', str(context.exception))
        self.assertIn('Script error in ', str(context.exception))
        self.assertNotIn('is not valid', str(context.exception))
        self.assertNotIn('should never get here', str(context.exception))


class TestExecuteToolMalformedName(TestCaseWithAssertRaisesWithCause):
    """Sandbox-side validation of malformed tool names."""

    async def test_execute_tool_rejects_malformed_names(self):
        """Names that don't conform to ``<toolset>.<tool>`` are rejected at
        the sandbox boundary so the agent sees a clear shape error that
        points at the canonical source (the tool list) rather than a
        registry lookup failure."""
        for name in ('no_dot', 'ToolsetNameWithoutTool.', '.ToolnameWithoutToolset'):
            with self.subTest(name=name):
                script = (
                    'def run():\n'
                    f'    return execute_tool({name!r}, "{{}}")'
                )
                with self.assert_raises_runtime_error_with_cause(ValueError) as ctx:
                    await _run_script(script)
                self.assertIn('tool list', str(ctx.exception.__cause__))


class TestExecuteToolErrorMessaging(
    ErrorProneToolsetTestCase,
    TestCaseWithAssertRaisesWithCause
):
    """Test execute_tool error messages in scripts."""

    @staticmethod
    def bad_script() -> None:
        """Contains code for a bad script."""
        # pylint: disable-next=import-outside-toplevel,redefined-outer-name,reimported
        import json

        def call_bad_tool():
            execute_tool(f'{BAD_TOOLSET_NAME}.bad_tool', json.dumps({'msg': 'hi'}))

        # pylint: disable=unused-variable
        def run():  # type: ignore
            call_bad_tool()
            return {}  # type: ignore

    async def test_execute_tool_error_includes_line_number_and_source_line(self):
        """Ensure execute_tool script error messages include line number and source."""
        with self.assertRaises(RuntimeError) as ctx:
            await _run_script(
                _get_function_body_source(self.bad_script)
                .replace('BAD_TOOLSET_NAME', f'"{BAD_TOOLSET_NAME}"')
            )
        self.assertIn("line 5", str(ctx.exception))
        self.assertIn("execute_tool(", str(ctx.exception))


class TestFailingCppToolFromSandbox(unittest.IsolatedAsyncioTestCase):
    """A sandboxed script's try/except catches a C++ RaiseScriptError.

    RaiseScriptError broadcasts OnScriptException; our handler captures into
    async_result.error; _execute_tool raises RuntimeError; the script catches.
    """

    @classmethod
    def setUpClass(cls):
        unreal.ToolsetRegistry.register_toolset_class(
            unreal.FakeErrorProneToolset
        )

    @classmethod
    def tearDownClass(cls):
        unreal.ToolsetRegistry.unregister_toolset_class(
            unreal.FakeErrorProneToolset
        )

    @staticmethod
    def catch_exception_script() -> None:
        """Reports whether an exception was caught and its message."""
        # pylint: disable=unused-variable
        def run():  # type: ignore
            # pylint: disable-next=import-outside-toplevel,redefined-outer-name,reimported
            import json

            caught = False
            message = ''
            try:
                execute_tool(
                    f'{FAKE_ERROR_PRONE_TOOLSET_NAME}.{BUGGY_TOOL_NAME}',
                    json.dumps({})
                )
            except Exception as e:  # pylint: disable=broad-exception-caught
                caught = True
                message = str(e)
            result: dict[str, Any] = {
                'caught': caught, 'message': message
            }
            return result

    async def test_try_except_catches_native_failure(self):
        """The script's try/except must catch the C++ RaiseScriptError."""
        self.assertDictEqual(
            await _run_script(
                _get_function_body_source(self.catch_exception_script)
                .replace(
                    'FAKE_ERROR_PRONE_TOOLSET_NAME',
                    f'"{FAKE_ERROR_PRONE_TOOLSET_NAME}"'
                )
                .replace('BUGGY_TOOL_NAME', f'"{BUGGY_TOOL_NAME}"')
            ),
            {
                'caught': True,
                'message': (
                    'Script error in '
                    f'{FAKE_ERROR_PRONE_TOOLSET_NAME}.{BUGGY_TOOL_NAME}:\n'
                    f'{BUGGY_TOOL_ERROR_MESSAGE}'
                )
            })


class TestScriptExceptionFormatting(TestCaseWithAssertRaisesWithCause):
    """Tests for the exception formatter that wraps script-level errors.

    The model can only act on script failures when the wrapped error
    preserves enough detail to identify what went wrong. Without the
    exception class and a script-frame traceback the model receives an
    unactionable header and either retries blindly or gives up. These
    tests pin down the round-trip guarantees called out in UE-377456.
    """

    async def test_value_error_round_trips_class_and_message(self):
        """A ValueError raised inside run() must surface its class and message.

        Acceptance criterion from UE-377456: a script raising
        ValueError("x") inside execute_tool must return an error containing
        both 'ValueError' and 'x' to the caller.
        """
        with self.assert_raises_runtime_error_with_cause(ValueError) as ctx:
            await _run_script(
                "def run():\n"
                "    raise ValueError('boom-payload')"
            )
        message = str(ctx.exception)
        self.assertIn("ValueError", message)
        self.assertIn("boom-payload", message)

    async def test_empty_message_still_includes_exception_class(self):
        """An exception with empty str(exc) must still carry its class name.

        Reproduces the production failure pattern where the inner error
        body collapsed to nothing and the wrap layer surfaced only
        'line N: <empty>' to the model. The class name is the floor of
        actionable signal we always preserve.
        """
        with self.assertRaises(RuntimeError) as ctx:
            await _run_script(
                "def run():\n"
                "    raise ValueError()\n"
            )
        message = str(ctx.exception)
        self.assertIn("ValueError", message)
        self.assertIn("line 2", message)

    async def test_traceback_includes_nested_helper_frames(self):
        """Nested helper calls inside the script must appear in the traceback.

        Without a script-only traceback the call site reported is only the
        outermost line in run(), hiding which helper actually raised. The
        model needs every script frame to localize the failure.
        """
        script = (
            "def inner():\n"
            "    raise ValueError('deep')\n"
            "\n"
            "def middle():\n"
            "    inner()\n"
            "\n"
            "def run():\n"
            "    middle()\n"
            "    return {}\n"
        )
        with self.assertRaises(RuntimeError) as ctx:
            await _run_script(script)
        message = str(ctx.exception)
        self.assertIn("Traceback (script frames only):", message)
        self.assertIn("in inner", message)
        self.assertIn("in middle", message)
        self.assertIn("in run", message)

    async def test_traceback_uses_script_placeholder(self):
        """The temporary script path must be normalized to '<script>'.

        The on-disk script is a per-execution hashed temp file under
        Saved/. Paths like `agent_script_5D7EE7BC...py` are noise to the
        model and break cross-trace matching. Pin the stable label so it
        cannot drift back.
        """
        script = (
            "def run():\n"
            "    raise ValueError('x')\n"
        )
        with self.assertRaises(RuntimeError) as ctx:
            await _run_script(script)
        message = str(ctx.exception)
        self.assertIn('File "<script>"', message)
        self.assertNotIn("agent_script_", message)

    async def test_extreme_recursion_truncates_middle_frames(self):
        """Deep recursion must produce a bounded traceback with an omitted marker.

        Without truncation a recursion-depth failure produces ~1000 frames of
        repetition that drown out the actual signal and balloon the message
        size. Both ends of the call chain are kept; the redundant middle is
        dropped with a marker so the omission is explicit.
        """
        script = (
            "def recurse(n):\n"
            "    recurse(n + 1)\n"
            "\n"
            "def run():\n"
            "    recurse(0)\n"
            "    return {}\n"
        )
        with self.assertRaises(RuntimeError) as ctx:
            await _run_script(script)
        message = str(ctx.exception)
        self.assertIn("RecursionError", message)
        self.assertIn("frames omitted", message)
        self.assertIn("in run", message)
        self.assertIn("in recurse", message)
        traceback_section = message.split(
            "Traceback (script frames only):\n", 1)[1]
        formatted_frame_count = sum(
            1 for line in traceback_section.splitlines()
            if line.lstrip().startswith("File ")
        )
        self.assertLessEqual(formatted_frame_count, _MAX_SCRIPT_FRAMES)


class _FakeTransactionRecorder:
    """Stand-in for unreal.SystemLibrary + unreal.ToolsetLibrary.

    Records every begin/end/undo call so tests can assert the sequence
    without nesting MagicMock attributes. The same instance is installed
    for both library surfaces so calls accumulate in a single ordered list.
    """

    BEGIN = 'begin_transaction'
    END = 'end_transaction'
    UNDO = 'undo_transaction'
    GET_ACTIVE_UNDO_COUNT = 'get_active_undo_count'

    def __init__(
        self, *,
        initial_active_count: int = 0,
        initial_undo_count: int = 0,
    ):
        # Outstanding begin_transaction nesting depth. Set to model
        # "this scope is opened inside a caller's transaction".
        self._active_count = initial_active_count
        # Number of committed undoable transactions on top of the stack.
        # Set to model prior user/session work that must survive a
        # failed programmatic-toolset call.
        self._active_undo_count = initial_undo_count
        # Tracks whether the currently-open outermost transaction has been
        # marked dirty. None when no outermost transaction is open.
        self._pending_dirty: bool | None = (
            False if initial_active_count > 0 else None)
        self.calls: list[tuple[str, tuple[Any, ...]]] = []

    @property
    def call_names(self) -> list[str]:
        """Names of recorded calls in order, e.g. ['begin_transaction', ...]."""
        return [name for name, _ in self.calls]

    @property
    def active_undo_count(self) -> int:
        """Snapshot of the committed undo-stack depth, for assertions."""
        return self._active_undo_count

    # unreal.SystemLibrary surface ------------------------------------------

    def begin_transaction(self, context: str, description: str,
                          primary_object: Any) -> int:
        self.calls.append((self.BEGIN, (context, description, primary_object)))
        prior = self._active_count
        if self._active_count == 0:
            self._pending_dirty = False
        self._active_count += 1
        return prior

    def end_transaction(self) -> None:
        self.calls.append((self.END, ()))
        if self._active_count <= 0:
            return
        self._active_count -= 1
        if self._active_count == 0:
            if self._pending_dirty:
                # UE commits the record to the undo buffer.
                self._active_undo_count += 1
            # If not dirty, the transaction is transient and UE silently
            # drops it from the buffer -- the active undo count stays put.
            self._pending_dirty = None

    # unreal.ToolsetLibrary surface -----------------------------------------

    def undo_transaction(self) -> None:
        self.calls.append((self.UNDO, ()))
        if self._active_undo_count > 0:
            self._active_undo_count -= 1

    def get_active_undo_count(self) -> int:
        """Mirrors UToolsetLibrary::GetActiveUndoCount."""
        self.calls.append((self.GET_ACTIVE_UNDO_COUNT, ()))
        return self._active_undo_count

    # Test helper -----------------------------------------------------------

    def mark_modified(self) -> None:
        """Simulate a UObject->Modify() during the open outermost transaction.

        Without this call a begin/end pair is treated as transient, matching
        UTransBuffer::End's behavior of dropping a transaction whose records
        contain no changes.
        """
        assert self._pending_dirty is not None, (
            "No outermost transaction is open")
        self._pending_dirty = True


class TestTransactionScope(unittest.TestCase):
    """Tests for the _TransactionScope context manager.

    Verifies the begin/end/undo sequence for the transaction wrap around
    execute_tool_script. The actual undo behavior on UObjects is covered
    by the C++ spec AI.ToolsetRegistry.ToolsetLibrary.UndoTransaction;
    here we only care about which calls fire and in what order based on
    whether commit() was called, the active count nesting at entry, and
    whether anything actually modified state during the transaction.
    """

    @contextmanager
    def _patched(
        self, *,
        initial_active_count: int = 0,
        initial_undo_count: int = 0,
    ) -> Generator[_FakeTransactionRecorder, None, None]:
        """Install the fake recorder for SystemLibrary + ToolsetLibrary."""
        fake = _FakeTransactionRecorder(
            initial_active_count=initial_active_count,
            initial_undo_count=initial_undo_count,
        )
        with mock.patch.object(unreal, 'SystemLibrary', fake), \
                mock.patch.object(unreal, 'ToolsetLibrary', fake):
            yield fake

    def test_no_commit_dirty_undoes_only_own_record(self):
        """Without commit() at outermost level and a dirty transaction:
        end_transaction commits the record, then undo_transaction rolls
        it back. The pre-existing entries on the undo stack must remain
        untouched (active_undo_count returns to its starting value).
        """
        with self._patched(initial_undo_count=2) as fake:
            with _TransactionScope("Ctx", "Desc"):
                fake.mark_modified()

        self.assertEqual(fake.active_undo_count, 2)
        self.assertIn(_FakeTransactionRecorder.UNDO, fake.call_names)

    def test_no_commit_empty_does_not_undo_prior_unrelated_work(self):
        """An empty (transient) _TransactionScope must not pop the prior
        unrelated transaction off the undo stack.

        Reproduces the field bug: after a fresh EDA session's
        execute_tool_script failed before any tool reached a Modify(),
        the slate "Undo Execute tool script" notification fired but the
        entry actually rolled back came from the user's earlier work
        (or a prior EDA session). UE's UTransBuffer::End drops a
        begin/end pair whose records contain no changes, so a blind
        undo_transaction() after End targets whatever was previously on
        top of the buffer.
        """
        with self._patched(initial_undo_count=1) as fake:
            with _TransactionScope("ProgrammaticToolset", "Execute tool script"):
                pass  # Script failed before any Modify() ran.

        self.assertEqual(
            fake.active_undo_count, 1,
            "Empty transaction must not pop the unrelated prior entry")
        self.assertNotIn(
            _FakeTransactionRecorder.UNDO, fake.call_names,
            "undo_transaction must not fire when nothing was recorded")

    def test_commit_skips_undo(self):
        """commit() before exit suppresses the undo even when dirty."""
        with self._patched() as fake:
            with _TransactionScope("Ctx", "Desc") as scope:
                fake.mark_modified()
                scope.commit()

        self.assertNotIn(_FakeTransactionRecorder.UNDO, fake.call_names)
        # The transaction stays on the undo stack as a committed record.
        self.assertEqual(fake.active_undo_count, 1)

    def test_no_commit_skips_undo_when_nested(self):
        """Without commit() when nested: skip undo to avoid reverting
        the enclosing caller's work.

        A nonzero prior_active_count means the caller opened the
        transaction first. UE's nested begin/end share a single
        transaction record, so undoing here would revert state belonging
        to the caller.
        """
        with self._patched(initial_active_count=1) as fake:
            with _TransactionScope("Ctx", "Desc"):
                pass

        self.assertNotIn(_FakeTransactionRecorder.UNDO, fake.call_names)

    def test_begin_transaction_arguments(self):
        """Context and description are forwarded verbatim to begin_transaction.

        Pinning these matters for users scanning the Edit > Undo history:
        a script-driven change should be self-identifying rather than
        showing up as an anonymous transaction.
        """
        with self._patched() as fake:
            with _TransactionScope("MyContext", "My description"):
                pass

        begin_calls = [
            args for name, args in fake.calls
            if name == _FakeTransactionRecorder.BEGIN
        ]
        self.assertEqual(
            begin_calls,
            [("MyContext", "My description", None)])

    def test_double_exit_does_not_double_end_or_double_undo(self):
        """Calling __exit__ twice must not unbalance begin/end or undo twice.

        UE's transaction system counts begin/end pairs; an extra
        end_transaction would leak a level of nesting that no caller
        opened. A second undo_transaction would pop an unrelated entry
        off the stack. Calling __exit__ twice is treated as a no-op the
        second time around (e.g. if an ExitStack and a higher-level
        caller both try to clean up).
        """
        scope = _TransactionScope("Ctx", "Desc")
        with self._patched() as fake:
            scope.__enter__()
            fake.mark_modified()
            scope.__exit__(None, None, None)
            scope.__exit__(None, None, None)

        self.assertEqual(
            fake.call_names.count(_FakeTransactionRecorder.BEGIN), 1)
        self.assertEqual(
            fake.call_names.count(_FakeTransactionRecorder.END), 1)
        self.assertEqual(
            fake.call_names.count(_FakeTransactionRecorder.UNDO), 1)

    def test_exit_without_enter_is_a_noop(self):
        """__exit__ without a prior __enter__ must not call end_transaction.

        Protects against a half-constructed scope (e.g. exception in
        owner's setup that runs __exit__ during cleanup before the
        transaction was opened) leaking an unmatched end_transaction.
        """
        scope = _TransactionScope("Ctx", "Desc")
        with self._patched() as fake:
            scope.__exit__(None, None, None)

        self.assertEqual(fake.call_names, [])
