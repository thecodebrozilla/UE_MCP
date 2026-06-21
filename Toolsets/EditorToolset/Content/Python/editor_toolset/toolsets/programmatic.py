# Copyright Epic Games, Inc. All Rights Reserved.
"""Toolset that supports programmatic execution of tools."""

import ast
import atexit
from asyncio import AbstractEventLoop
import builtins
from concurrent.futures import Future, ThreadPoolExecutor
from contextlib import contextmanager, ExitStack
from enum import Enum
import json
import os
import re
import traceback
from threading import Lock
from types import CodeType, TracebackType
from typing import cast, Any, Generator, IO

import unreal

from toolset_registry import tool_call
from toolset_registry._registry_interface import (
    execute_tool, ToolsetToolInvocationError
)
from toolset_registry._asyncio.callable_runner import CallableRunner
from toolset_registry._asyncio.editor_event_loop_manager import (
    EditorEventLoopManager
)
from toolset_registry._asyncio.run_on_loop import run_async_on_loop


@unreal.ustruct()
class ProgrammaticApiSupportedModule(unreal.StructBase): # pylint: disable=too-few-public-methods
    """Module that can be imported in the programmatic execution environment.

    Attributes:
        name: Fully qualified name of the module.
        description: Optional description of the module with links to documentation.
    """
    name = unreal.uproperty(str)
    description = unreal.uproperty(str)


def _make_supported_module(name: str, description: str) -> ProgrammaticApiSupportedModule:
    """Create a ProgrammaticApiSupportedModule with the given values."""
    module = ProgrammaticApiSupportedModule()
    module.name = name
    module.description = description
    return module


# Modules that are safe to import within execute_tool_script scripts.
_SUPPORTED_MODULES = [
    _make_supported_module(
        "json",
        "Standard library JSON encoding and decoding.",
    ),
    _make_supported_module(
        "math",
        "Standard library mathematical functions.",
    ),
    _make_supported_module(
        "datetime",
        "Standard library date and time types.",
    ),
    _make_supported_module(
        "copy",
        "Standard library shallow and deep copy operations.",
    ),
    _make_supported_module(
        "re",
        "Standard library regular expression operations.",
    ),
    _make_supported_module(
        "time",
        "Standard library for time.",
    ),
]


_ALLOWED_MODULE_NAMES = frozenset(m.name for m in _SUPPORTED_MODULES)


class _FileOpener(CallableRunner[IO[Any]]):  # pylint: disable=too-few-public-methods
    """Restricted replacement for open()."""

    _ALLOWED_READ_MODES = frozenset({"r", "rb", "rt"})
    _ALLOWED_OPEN_KWARGS = frozenset({"encoding"})

    def __init__(self, loop: AbstractEventLoop):
        """Initialize the opener.

        Args:
            loop: Asyncio event loop used to execute __open().
        """
        super().__init__(loop, self.__open)

    def __open(
        self, file: int | str | bytes | os.PathLike[str] | os.PathLike[bytes],
        mode: str, **kwargs: Any
    ) -> IO[Any]:
        """Open a file.

        Args:
            file: Path to the file to open.
            mode: File mode.
            **kwargs: Subset of built-in open() keyword arguments.

        Returns:
            A file object.

        Raises:
            ValueError: If preconditions for arguments are not met.
        """
        if not isinstance(file, (str, os.PathLike)):
            raise ValueError(f"File '{str(file)}' is not a path.")
        if mode not in self._ALLOWED_READ_MODES:
            raise ValueError(
                f"Mode '{mode}' is not permitted. "
                f"Allowed modes: {sorted(self._ALLOWED_READ_MODES)}"
            )
        resolved_path = self._resolve_project_path(str(file))
        safe_kwargs = {
            k: kwargs[k]
            for k in self._ALLOWED_OPEN_KWARGS if k in kwargs
        }
        # pylint: disable-next=unspecified-encoding
        return builtins.open(resolved_path, mode, **safe_kwargs)

    @staticmethod
    def _real_path(ue_path: str) -> str:
        """Return the realpath of a UE path string."""
        return os.path.realpath(unreal.Paths.convert_relative_path_to_full(ue_path))

    @staticmethod
    def _is_under(root: str, path: str) -> bool:
        """Return True if *path* is contained within *root* (both realpath'd)."""
        try:
            return os.path.commonpath([root, path]) == root
        except ValueError:
            # commonpath raises ValueError on Windows when paths are on different drives.
            return False

    @classmethod
    def _resolve_project_path(cls, path: str) -> str:
        """Resolve a path and validate it is contained within an allowed root.

        Relative paths are anchored to the project directory. Absolute paths are
        used as-is. Both forms are then checked against the allowed roots:

        - The project directory (`unreal.Paths.project_dir()`).
        - The project saved directory (`unreal.Paths.project_saved_dir()`).

        Args:
            path: Path to resolve.

        Returns:
            The resolved absolute path.

        Raises:
            ValueError: If the resolved path escapes all allowed directories.
        """
        real_project_root = cls._real_path(unreal.Paths.project_dir())
        if os.path.isabs(path):
            resolved_path = os.path.realpath(path)
        else:
            resolved_path = os.path.realpath(os.path.join(real_project_root, path))

        allowed_roots = [
            real_project_root,
            cls._real_path(unreal.Paths.project_saved_dir()),
        ]

        # POSIX os.path.isabs doesn't recognize Windows drive prefixes, so reject
        # them explicitly to keep cross-drive paths rejected on every host.
        is_cross_drive_path = (
            not os.path.isabs(path) and re.match(r'^[A-Za-z]:[\\/]', path)
        )
        is_not_under_allowed_roots = (
            not any(cls._is_under(root, resolved_path) for root in allowed_roots)
        )
        if is_cross_drive_path or is_not_under_allowed_roots:
            raise ValueError(
                f"Path '{path}' resolves to '{resolved_path}', which is outside all "
                f"allowed directories ({', '.join(repr(r) for r in allowed_roots)})."
            )

        return resolved_path


class _StrictDict(dict[Any, Any]):
    """A dict that raises on missing keys instead of returning None.

    Used to wrap tool results so that accessing a wrong key — whether via []
    or .get() — raises immediately with a helpful message listing the keys
    that are actually present.
    """

    def __getitem__(self, key: Any):
        try:
            return super().__getitem__(key)
        except KeyError:
            available = sorted(self.keys())
            raise KeyError(
                f"{key!r} not found. Available keys: {available}"
            ) from None

    def get(self, key: Any, default: Any = None):  # noqa: D102
        if default is not None:
            raise TypeError(
                "_StrictDict.get() does not support a default value. "
                "Use direct key access [] instead."
            )
        if key not in self:
            available = sorted(self.keys())
            raise KeyError(
                f"{key!r} not found. Available keys: {available}"
            )
        return super().get(key, default)


class _ToolExecutor:  # pylint: disable=too-few-public-methods
    """Executes tools on an asyncio loop."""

    def __init__(self, loop: AbstractEventLoop):
        """Initialize a tool executor.

        Args:
            loop: Asyncio event loop used to run tools. The provided loop must
                not be on the same thread that calls this executor.
        """
        self._loop = loop

    @staticmethod
    def _split_full_tool_name(full_tool_name: str) -> tuple[str, str]:
        """Split a dotted full tool name into (toolset_name, tool_name).

        Toolset names themselves contain dots (e.g. 'EditorToolset.AssetTools')
        and tool names do not, so the split is on the LAST dot.

        Args:
            full_tool_name: Dotted full name from the agent's tool list, e.g.
                'EditorToolset.AssetTools.find_assets'.

        Returns:
            Tuple of (toolset_name, tool_name).

        Raises:
            ValueError: If the name does not contain a dot or either side of
                the split is empty.
        """
        if '.' not in full_tool_name:
            raise ValueError(
                f"Invalid tool name '{full_tool_name}'. Specify the tool "
                "name exactly as it appears in your tool list."
            )
        toolset_name, tool_name = full_tool_name.rsplit('.', maxsplit=1)
        if not toolset_name or not tool_name:
            raise ValueError(
                f"Invalid tool name '{full_tool_name}'. Specify the tool "
                "name exactly as it appears in your tool list."
            )
        return toolset_name, tool_name

    async def _execute_tool(
        self, toolset_name: str, tool_name: str, json_input: str
    ) -> _StrictDict:
        """Execute a tool asynchronously.

        Args:
            toolset_name: Fully qualified toolset class name.
            tool_name: Name of the tool method to call.
            json_input: JSON string matching the tool's input schema.

        Returns:
            The parsed tool result.

        Raises:
            RuntimeError: If tool execution fails.
        """
        try:
            result = await execute_tool(
                toolset_name, tool_name, json.loads(json_input)
            )
        except ToolsetToolInvocationError as error:
            # pylint: disable-next=raise-missing-from
            raise RuntimeError(
                f'Script error in {toolset_name}.{tool_name}:\n'
                f'{error}'
            )
        # Wrap returned dict and nested dicts in a _StrictDict to only allow
        # the agent access to fields that exist.
        return json.loads(json.dumps(result), object_hook=_StrictDict)

    def __call__(self, full_tool_name: str, json_input: str) -> _StrictDict:
        """Execute a registered tool by dotted full name.

        This function is injected into the script sandbox as a builtin,
        providing access to registered toolset operations without exposing the
        full unreal module.

        Args:
            full_tool_name: Dotted full name from the agent's tool list
                (e.g. ``'EditorToolset.AssetTools.find_assets'``).
            json_input: JSON string matching the tool's input schema.

        Returns:
            The parsed tool result.

        Raises:
            ValueError: If ``full_tool_name`` has no dot or has empty segments.
            RuntimeError: If the tool raises an error during execution.
        """
        toolset_name, tool_name = self._split_full_tool_name(full_tool_name)
        # A lot of UE functionality is not thread safe so run the tool on the
        # editor thread.
        return run_async_on_loop(
            self._loop,
            self._execute_tool(toolset_name, tool_name, json_input)
        ).result()


def _assert_module_allowed(module_name: str) -> None:
    """Verify that a module name is in the allowlist.

    Checks the top-level package name against _ALLOWED_MODULE_NAMES. For
    dotted names like 'json.decoder', only the top-level name 'json' is
    checked.

    Args:
        module_name: Fully qualified module name to check.

    Raises:
        ValueError: If the top-level module is not in the allowlist.
    """
    top_level = module_name.split(".")[0]
    if top_level not in _ALLOWED_MODULE_NAMES:
        raise ValueError(
            f"Import of '{module_name}' is not permitted. "
            f"Allowed modules: {_ALLOWED_MODULE_NAMES}"
        )


def _safe_import(name: str, *args: Any, **kwargs: Any):
    """Replacement for __import__ that enforces the module allowlist.

    Used as the __import__ builtin in the sandbox so that import statements
    are checked at runtime as a second layer of defense after the AST check.

    Args:
        name: Module name to import.
        *args: Forwarded to builtins.__import__.
        **kwargs: Forwarded to builtins.__import__.

    Returns:
        The imported module.

    Raises:
        ValueError: If the module is not in the allowlist.
    """
    _assert_module_allowed(name)
    return builtins.__import__(name, *args, **kwargs)


# Builtins available to executed scripts. Starts from the full set and removes
# anything that could escape the sandbox: dynamic code execution, file access,
# and interactive functions that would block or confuse the editor.
# __import__ is replaced with _safe_import rather than removed — CPython's
# IMPORT_NAME opcode requires it to be present for any import statement to work.
# _safe_import enforces the module allowlist at runtime as a second layer of
# defense after the AST check.
_SAFE_BUILTINS = {
    k: v for k, v in builtins.__dict__.items()
    if k not in {
        # dynamic code execution
        "exec", "eval", "compile",
        # blocks waiting for stdin
        "input",
        # drops into an interactive debugger
        "breakpoint",
        # opens an interactive pager
        "help",
    }
}
_SAFE_BUILTINS["__import__"] = _safe_import


def _validate_and_compile(script: str, script_path: str) -> CodeType:
    """Parse, validate imports, and compile a script.

    The script is compiled with the given file path so that tracebacks
    reference a real file with readable source lines.

    Args:
        script: Python source to validate and compile.
        script_path: File path to associate with the compiled code for
            traceback display.

    Returns:
        A compiled code object ready for exec().

    Raises:
        SyntaxError: If the script cannot be parsed.
        ValueError: If the script imports a disallowed or relative module.
    """
    tree = ast.parse(script)

    for node in ast.walk(tree):
        if isinstance(node, ast.Import):
            for alias in node.names:
                _assert_module_allowed(alias.name)
        elif isinstance(node, ast.ImportFrom):
            if node.level > 0:
                raise ValueError("Relative imports are not permitted.")
            if node.module is not None:
                _assert_module_allowed(node.module)

    return compile(tree, script_path, "exec")


_MAX_SCRIPT_FRAMES = 30
_HEAD_FRAMES = 5


def _format_script_traceback(frames: list[traceback.FrameSummary]) -> str:
    """Format script frames, truncating the middle when too many.

    Deep recursion can produce hundreds of redundant frames. Keeping the head
    and tail with an explicit `[... N frames omitted ...]` marker bounds the
    output without losing the entry point or the failure site.
    """
    if len(frames) <= _MAX_SCRIPT_FRAMES:
        return "".join(traceback.format_list(frames)).rstrip()
    head = frames[:_HEAD_FRAMES]
    tail = frames[-(_MAX_SCRIPT_FRAMES - _HEAD_FRAMES):]
    omitted = len(frames) - _MAX_SCRIPT_FRAMES
    return (
        "".join(traceback.format_list(head))
        + f"  [... {omitted} frames omitted ...]\n"
        + "".join(traceback.format_list(tail))
    ).rstrip()


def _format_script_exception(exc: BaseException, script_path: str) -> str | None:
    """Format an exception raised by a script for the model.

    Always includes the exception class name (even when `str(exc)` is empty)
    followed by a Python-style traceback restricted to script frames, so
    nested helper calls and the failing source line remain visible. The
    script's temporary path is normalized to `<script>` so paths stay
    stable across executions. Returns ``None`` when no script frames are
    present, signalling the caller to re-raise the original exception
    unchanged.
    """
    script_frames = [f for f in traceback.extract_tb(exc.__traceback__)
                     if f.filename == script_path]
    if not script_frames:
        return None
    last_frame = script_frames[-1]
    exc_class = type(exc).__name__
    exc_message = str(exc)
    qualified = f"{exc_class}: {exc_message}" if exc_message else exc_class
    formatted_traceback = _format_script_traceback(script_frames).replace(
        script_path, "<script>",
    )
    return (
        f"line {last_frame.lineno}: {qualified}\n"
        f"Traceback (script frames only):\n"
        f"{formatted_traceback}"
    )


_TOOLSET_ENVIRONMENT_INSTRUCTIONS = f"""
Use the function execute_tool(tool_name, json_input) to call any registered
tool. ``tool_name`` is the tool name exactly as it appears in your tool list.
It returns the result directly as a dict-like object. It raises RuntimeError
on failure - no error checking is needed.

The script must define a `run()` function that returns a `Dict[str, Any]`.
Unhandled exceptions will be returned when the tool is executed.

STOP. Before composing the script: the schemas in your tool list describe
each tool's INPUTS only, not what it returns. To parse return values in the
script, look up the output schema (if available) for each tool the script
will call, unless you have already received that tool's return value in
this conversation.

IMPORTANT: At the top of the script, define short helper functions that wrap
each execute_tool call you plan to use. This keeps the rest of the script
readable and avoids repeating the verbose execute_tool invocation. For example:

    import json

    def get_selected_actors():
        return execute_tool(
            "EditorToolset.EditorAppToolset.GetSelectedActors",
            "{{}}")["returnValue"]

    def set_actor_transform(actor, xform, worldspace=True):
        return execute_tool(
            "editor_toolset.toolsets.actor.ActorTools.set_actor_transform",
            json.dumps({{"actor": actor, "xform": xform,
                         "worldspace": worldspace}}))

    def run():
        for actor in get_selected_actors():
            set_actor_transform(actor, new_xform)
        return {{"moved": len(get_selected_actors())}}

The scripting environment allows importing a limited set of safe modules:
{_ALLOWED_MODULE_NAMES}. The function execute_tool() is available to call
registered tools directly.
"""

class ProgrammaticApiLanguage(Enum):
    """Programming language supported by the execution environment.
    """
    PYTHON = 'python'

@unreal.ustruct()
class ProgrammaticApiExecutionEnvironmentInfo(
    unreal.StructBase
): # pylint: disable=too-few-public-methods
    """Describes a programmatic API execution environment.

    Attributes:
        language: Programming language supported by the environment.
        supported_modules: Modules that can be imported in the execution
            environment.
        instructions: Instructions to the agent on how to write scripts so that
            ensure the script has the proper entrypoint and uses the available
            tools and allowed modules correctly.
    """
    language = unreal.uproperty(str)
    supported_modules = unreal.uproperty(unreal.Array(ProgrammaticApiSupportedModule))
    instructions = unreal.uproperty(str)


class _ScriptRunner:
    """Write a script to a file and runs it on a background thread."""

    _RUN_RETURN_MESSAGE = "run() must return a dict[str, Any]"

    _editor_event_loop_manager_lock = Lock()
    _editor_event_loop_manager: EditorEventLoopManager | None = None
    _editor_event_loop_manager_exit_stack = ExitStack()

    def __init__(self, script: str):
        """Initialize the runner.

        Args:
            script: Script to run.
        """
        self._exit_stack = ExitStack()
        self._script = script
        self._script_path = ''
        self._loop: AbstractEventLoop | None = None
        self._tool_executor: _ToolExecutor | None = None
        self._file_opener: _FileOpener | None = None
        self._thread_executor: ThreadPoolExecutor | None = None

    def __enter__(self) -> '_ScriptRunner':
        """Setup the script runner."""
        assert not self._script_path
        self._script_path = self._exit_stack.enter_context(
            self._script_temp_file(self._script)
        )
        self._loop = self._get_or_create_event_loop()
        self._tool_executor = _ToolExecutor(self.loop)
        self._file_opener = _FileOpener(self.loop)
        self._thread_executor = ThreadPoolExecutor(max_workers=1)
        self._exit_stack.callback(self._shutdown_thread_executor)
        return self

    def __exit__(
        self, exc_type: type[BaseException] | None,
        exc_value: BaseException | None,
        tb: TracebackType | None
    ) -> None:
        """Clean up the script runner."""
        _ = (exc_type, exc_value, tb)
        self._exit_stack.close()
        self._script_path = ''
        self._tool_executor = None
        self._file_opener = None

    @property
    def loop(self) -> AbstractEventLoop:
        """Asyncio loop used to execute tasks for the script."""
        assert self._loop
        return self._loop

    def __call__(self) -> Future[dict[str, Any]]:
        """Write the script to a file and run it on a background thread.

        Returns:
            Result of the script.

        Raises:
            TypeError: If the result was not a dict.
        """
        assert self._thread_executor
        return self._thread_executor.submit(self.__run)

    def chain_async_result(
        self, result_future: Future[dict[str, Any]],
        async_result: unreal.ToolCallAsyncResultString
    ) -> unreal.ToolCallAsyncResultString:
        """Chain the completion of a future to an async result.

        Args:
            result_future: Future to copy the result or exception from.
            async_result: Async result to complete when the future
                completes.

        Returns:
            Provided async result instance.
        """
        # This is required to set the async_result on the loop's thread.
        # Even though ToolCallAsyncResult is thread safe, Unreal's Python
        # bindings block all function calls from background threads.
        result_future.add_done_callback(
            lambda future: (
                self.loop.call_soon_threadsafe(
                    self._complete_on_loop, future, async_result
                )
            )
        )
        return async_result

    def _complete_on_loop(
        self, result_future: Future[dict[str, Any]],
        async_result: unreal.ToolCallAsyncResultString
    ) -> None:
        """Complete an async result from the specified future.

        Args:
            result_future: Future to copy the result or exception from.
            async_result: Async result to complete when the future
                completes.
        """
        if result_future.cancelled():
            async_result.set_error("Tool call cancelled")
        elif (exception := result_future.exception()) is not None:
            async_result.set_error(str(exception))
        else:
            async_result.set_value(json.dumps(result_future.result()))
        self.__exit__(None, None, None)

    def _shutdown_thread_executor(self) -> None:
        """Shutdown the thread pool."""
        if self._thread_executor:
            self._thread_executor.shutdown(wait=False)
            self._thread_executor = None

    def __run(self) -> dict[str, Any]:
        """Write the script to a file and run it.

        Returns:
            Result of the script.

        Raises:
            TypeError: If the result was not a dict.
        """
        result = self.__sandboxed_exec()
        if not isinstance(result, dict):
            raise TypeError(
                f"{self._RUN_RETURN_MESSAGE}, "
                f"returned {type(result).__name__}"
            )
        result_dict: dict[Any, Any] = cast(dict[Any, Any], result)
        if (result_dict and
            not all(isinstance(key, str) for key in result_dict.keys())):
            raise TypeError(
                f'{self._RUN_RETURN_MESSAGE}, '
                'returned dict with non-string keys.')
        return result_dict

    def __sandboxed_exec(self) -> Any:
        """Validate, compile, and execute a script inside the sandbox.

        The script must define a `run()` function. After compiling and executing
        the module-level code (which defines `run`), the function is called and its
        return value is returned.

        Returns:
            The return value of the script's `run()` function.

        Raises:
            SyntaxError: If the script cannot be parsed.
            ValueError: If the script imports a disallowed module, uses a
                relative import, or does not define a `run()` function.
            Exception: Any exception raised by the script itself.
        """
        assert self._tool_executor
        assert self._file_opener

        globals_dict: dict[str, Any] = {
            "__builtins__": {
                **_SAFE_BUILTINS,
                "execute_tool": self._tool_executor,
                # Replace built-in open with a restricted version that only allows
                # reading files under the project directory.
                "open": self._file_opener,
            }
        }
        # pylint: disable-next=exec-used
        exec(_validate_and_compile(self._script, self._script_path), globals_dict)
        if "run" not in globals_dict or not callable(globals_dict["run"]):
            raise ValueError("Script must define a callable run() function.")
        try:
            return globals_dict["run"]()
        except Exception as e:
            formatted = _format_script_exception(e, self._script_path)
            if formatted:
                raise RuntimeError(formatted) from e
            raise

    @staticmethod
    @contextmanager
    def _script_temp_file(script: str) -> Generator[str, None, None]:
        """Write a script to a temporary file and yield its path.

        The temporary file is kept alive for the duration of the context so that
        tracebacks can reference source lines for easier debugging.

        Args:
            script: Python source to write.

        Yields:
            Path to the temporary file containing the script.
        """
        script_path: str = unreal.Paths.create_temp_filename(
            unreal.Paths.project_saved_dir(),
            prefix="agent_script_", extension=".py"
        )
        try:
            with open(script_path, "w", encoding="utf-8") as f:
                f.write(script)
            yield script_path
        finally:
            os.unlink(script_path)

    @classmethod
    def _get_or_create_event_loop(cls) -> AbstractEventLoop:
        """Get or create an event loop on the editor thread.

        Returns:
            Event loop on the editor thread.
        """
        with cls._editor_event_loop_manager_lock:
            if cls._editor_event_loop_manager is None:
                cls._editor_event_loop_manager = (
                    cls._editor_event_loop_manager_exit_stack.enter_context(
                        EditorEventLoopManager()
                    )
                )
                atexit.register(
                    cls._editor_event_loop_manager_exit_stack.close
                )
            return cls._editor_event_loop_manager.loop


class _TransactionScope:
    """Editor transaction context manager that undoes by default on exit.

    Begins an editor transaction on __enter__ and ends it on __exit__.
    If commit() is not called before __exit__, the transaction is rolled
    back via UndoTransaction (when we are the outermost begin_transaction
    caller -- nested begin/end pairs share a single transaction record,
    so undoing at the global level would revert state owned by the
    enclosing caller).

    All calls must run on the editor thread; the class does not enforce
    threading on its own.
    """

    def __init__(self, context: str, description: str):
        self._context = context
        self._description = description
        self._prior_active_count: int | None = None
        self._active_undo_count_on_enter: int = 0
        self._committed = False

    def commit(self) -> None:
        """Suppress the undo that would otherwise fire on __exit__."""
        self._committed = True

    @property
    def _is_outermost_transaction(self) -> bool:
        """True when this scope's begin_transaction was the outermost call
        (no enclosing transaction was already open). Only meaningful after
        __enter__ has run.
        """
        return self._prior_active_count == 0

    def _has_new_undo_entries(self) -> bool:
        """True if end_transaction committed a record since __enter__.

        UTransBuffer::End silently drops a transaction with no UObject
        modifications, leaving the active undo count unchanged; without
        this check a blind undo_transaction() would pop whatever unrelated
        entry was previously on top of the stack.
        """
        return (unreal.ToolsetLibrary.get_active_undo_count() >
                self._active_undo_count_on_enter)

    def __enter__(self) -> '_TransactionScope':
        # Snapshot before begin so we can tell on exit whether the
        # begin/end pair actually committed a record.
        self._active_undo_count_on_enter = (
            unreal.ToolsetLibrary.get_active_undo_count())
        self._prior_active_count = unreal.SystemLibrary.begin_transaction(
            self._context, self._description, None)
        return self

    def __exit__(
        self, exc_type: type[BaseException] | None,
        exc_value: BaseException | None,
        tb: TracebackType | None,
    ) -> None:
        _ = (exc_type, exc_value, tb)
        if self._prior_active_count is None:
            return
        # End so the begin/end action counter balances.
        unreal.SystemLibrary.end_transaction()
        if (not self._committed
            and self._is_outermost_transaction
            and self._has_new_undo_entries()):
            unreal.ToolsetLibrary.undo_transaction()
        self._prior_active_count = None


class _TransactionalScriptRunner(_ScriptRunner):
    """_ScriptRunner that brackets script execution in an editor transaction.

    The transaction is opened alongside the runner on __enter__ and
    committed when the script's future resolves cleanly. An exception, a
    cancellation, or a setup failure that unwinds via __exit__ without
    a commit() leaves the transaction in its rollback state, which
    _TransactionScope handles on exit.

    All transaction calls run on the editor thread: __enter__ runs there
    because execute_tool_script is called on the editor thread, and the
    overridden _complete_on_loop is dispatched via call_soon_threadsafe.
    """

    _CONTEXT = "ProgrammaticToolset"
    _DESCRIPTION = "Execute tool script"

    def __init__(self, script: str):
        super().__init__(script)
        self._transaction = _TransactionScope(self._CONTEXT, self._DESCRIPTION)

    def __enter__(self) -> '_TransactionalScriptRunner':
        super().__enter__()
        self._transaction.__enter__()
        return self

    def __exit__(
        self, exc_type: type[BaseException] | None,
        exc_value: BaseException | None,
        tb: TracebackType | None,
    ) -> None:
        # Release in reverse order of acquisition.
        self._transaction.__exit__(exc_type, exc_value, tb)
        super().__exit__(exc_type, exc_value, tb)

    def _complete_on_loop(
        self, result_future: Future[dict[str, Any]],
        async_result: unreal.ToolCallAsyncResultString
    ) -> None:
        """Mark the transaction committed on clean success, then unwind."""
        if (not result_future.cancelled() and result_future.exception() is None):
            self._transaction.commit()
        super()._complete_on_loop(result_future, async_result)


@unreal.uclass()
class ProgrammaticToolset(unreal.ToolsetDefinition):
    """Batches calls to other registered tools through a small sandboxed Python
    script that glues them together with custom logic. The script's purpose is
    tool orchestration, not general Python execution."""

    @tool_call
    @staticmethod
    def get_execution_environment() -> (
        ProgrammaticApiExecutionEnvironmentInfo):
        """Get details about execution environment.

        This includes instructions on how to write scripts, and constraints,
        such as what modules may be imported and the script entrypoint and
        function signature.

        Returns:
            Returns the current execution environment.
        """
        info = ProgrammaticApiExecutionEnvironmentInfo()
        info.language = ProgrammaticApiLanguage.PYTHON.value
        info.supported_modules = _SUPPORTED_MODULES
        info.instructions = _TOOLSET_ENVIRONMENT_INSTRUCTIONS
        return info

    @tool_call
    @staticmethod
    def execute_tool_script(script: str) -> unreal.ToolCallAsyncResultString:
        """Execute a Python script against the toolset APIs.

        Use this to batch multiple tool calls into a single script execution,
        reducing round-trips and context usage.

        IMPORTANT: Available modules and usage instructions are described by the
        value returned by `get_execution_environment`. You MUST call
        `get_execution_environment` once in the conversation before using this
        tool. Read the value in the `instructions` field in the returned
        environment info prior to calling this function, so that you understand
        what APIs are available and how to use them.

        Before writing a script that calls multiple tools, look up the output
        schemas (if available) for any tools you plan to use. This returns the
        JSON schema describing each tool's return value, so you know how to
        parse results and pass data between calls.

        Args:
            script: Python script to execute. Must define a `run()` function
                that returns a `Dict[str, Any]`.

        Returns:
            JSON-encoded dict returned by the script's `run()` function.

        Raises:
            SyntaxError: If the script has invalid syntax.
            ValueError: If the script imports a disallowed module or does not
                define a `run()` function.
            TypeError: If `run()` does not return a dict.
            Exception: Any unhandled exception raised by the script.
        """
        async_result = unreal.ToolCallAsyncResultString()
        exit_stack = ExitStack()
        try:
            script_runner = exit_stack.enter_context(
                _TransactionalScriptRunner(script))
            result_future = script_runner()
        except Exception as error:  # pylint: disable=broad-except
            exit_stack.close()
            async_result.set_error(str(error))
            return async_result

        # NOTE: This is intentional, chain_async_result() unconditionally
        # exits the script_runner context when result_future completes.
        _ = exit_stack.pop_all()

        return script_runner.chain_async_result(result_future, async_result)
