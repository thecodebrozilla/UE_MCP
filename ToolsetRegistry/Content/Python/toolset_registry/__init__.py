# Copyright Epic Games, Inc. All Rights Reserved.
"""Toolset registry utilities."""

from collections.abc import Callable
from contextlib import contextmanager
from types import ModuleType
from typing import Any, Generator


@contextmanager
def tool_raising_exceptions() -> Generator[None, None, None]:
    """Context manager to temporarily enable exception raising in tool calls.

    When used, exceptions in tool calls will be raised normally instead of being
    converted to script errors. This is useful for testing and debugging.

    Example:
        with tool_raising_exceptions():
            # Exceptions will be raised here
            some_toolset.some_tool()

    Note: the ufunction decorator wraps all raised exceptions in RuntimeError,
    so tests must do something like this:

        def tool_that_raises_ValueError():
            ...

        with tool_raising_exceptions():
            with self.assertRaisesRegex(RuntimeError, 'ValueError'):
                tool_that_raises_ValueError()

    or
        with tool_raising_exceptions():
            with self.assertRaises(RuntimeError) as context:
                tool_that_raises_ValueError()
            self.assertIn('ValueError: ', str(context.exception))
    """
    # pylint: disable-next=import-outside-toplevel
    from .tool_call_impl import (
        tool_raising_exceptions as tool_raising_exceptions_func
    )
    with tool_raising_exceptions_func():
        yield


def tool_call(func: Callable[..., Any]):
    """Decorator to wrap and declare a toolset method as a tool.

    Used to mark a method as a tool (UFunction) suitable for calling from an AI
    agent.  Tool method params and return types must be annotated.

    Note: Toolsets are just Blueprint Function Libraries, so tool calls must be
    static methods too.

    Note: Python exceptions in the tool method are caught and raised as script
    errors so the toolset registry can treat them as errors from the tool.
    Script error events however are not broadcast outside of the game thread, so
    tools *must* be called from the game thread in order to properly get errors
    detected.

    Args:
        func: Method to mark as a tool.

    Returns:
        The generated UFunction.

    Raises:
        ToolCallMissingAnnotation: if any params or return type are missing
    annotations that would cause the unreal.ufunction decorator to fail.
    """
    # pylint: disable-next=import-outside-toplevel
    from .tool_call_impl import tool_call as tool_call_func
    return tool_call_func(func)


def reload_module(top_module: ModuleType) -> None:
    """Reload a module and all its submodules, managing toolset registration.

    For any toolset classes found in the modules being reloaded that are
    currently registered, they are unregistered before reload and re-registered
    after.

    Args:
        top_module: The top-level module to reload. All submodules are also reloaded.
    """
    # pylint: disable-next=import-outside-toplevel
    from ._reload import reload_module as reload_module_func
    reload_module_func(top_module)
