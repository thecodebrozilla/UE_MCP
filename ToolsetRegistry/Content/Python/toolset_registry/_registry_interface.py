# Copyright Epic Games, Inc. All Rights Reserved.
"""Toolset registry interface that can be used in tests outside of Unreal."""

from asyncio import sleep
import json
from types import ModuleType
from typing import runtime_checkable, Any, Mapping, Protocol

from ._unreal import get_unreal_module


@runtime_checkable
class ToolCallAsyncResultProtocol(Protocol):
    """Protocol for an async result."""

    @property
    def is_complete(self) -> bool:  # pyright: ignore
        """Whether the result is complete."""

    @property
    def value(self) -> Any:
        """JSON value of the result when complete."""

    @property
    def error(self) -> Any:
        """Error message if complete and the call failed."""


class ToolsetRegistryProtocol(Protocol):
    """Protocol for the toolset registry.

    This is provided for type checking outside of Unreal.
    """

    @classmethod
    def is_available(cls) -> bool: # pyright: ignore
        """Whether the registry is available."""

    @classmethod
    def is_toolset_registered(cls, toolset_name: str) -> bool: # pyright: ignore
        """Whether a toolset is reigstered."""

    @classmethod
    def is_toolset_class_registered(cls, toolset_class: type) -> bool: # pyright: ignore
        """Whether a toolset class is registered."""

    @classmethod
    def register_toolset_class(cls, toolset_class: type) -> None:
        """Register a toolset."""

    @classmethod
    def unregister_toolset_class(cls, toolset_class: type) -> None:
        """Unregister a toolset."""

    @classmethod
    def execute_tool(
        cls, toolset_name: str, tool_name: str, json_input: str
    ) -> ToolCallAsyncResultProtocol:  # pyright: ignore
        """Execute a tool."""


def get_toolset_registry() -> ToolsetRegistryProtocol:
    """Get the toolset registry class.

    Returns:
        ToolsetRegistry class.
    """
    return get_unreal_module().ToolsetRegistry


def find_toolset_classes(modules_to_search: list[ModuleType]) -> list[type]:
    """Find toolset classes in a set of modules.

    Args:
        modules_to_search: Modules to search for toolset classes.

    Returns:
        List toolset classes found in the specified modules.
    """
    unreal = get_unreal_module()  # type: ignore
    toolset_classes: list[type] = []
    for module in modules_to_search:
        for attr_name in dir(module):
            obj = getattr(module, attr_name, None)
            if (
                isinstance(obj, type) and
                issubclass(obj, unreal.ToolsetDefinition) and  # type: ignore
                getattr(obj, '__module__', '') == module.__name__
            ):
                toolset_classes.append(obj)
    return toolset_classes


def register_toolset_classes(toolset_classes: list[type]) -> list[str]:
    """Find and register toolset classes.

    Args:
        toolset_classes: Toolset classes to register. If the class is already
            registered it is re-registered.

    Returns:
        List of errors that occurred while registering toolset classes.
    """
    registry = get_toolset_registry()
    errors: list[str] = []
    if registry.is_available():
        for toolset_class in toolset_classes:
            if registry.is_toolset_class_registered(toolset_class):
                registry.unregister_toolset_class(toolset_class)
            try:
                registry.register_toolset_class(toolset_class)
            except Exception as e:  # pylint: disable=broad-exception-caught
                errors.append(f'Failed to register {toolset_class}: {str(e)}')
    return errors


def unregister_toolset_classes(toolset_classes: list[type]) -> list[type]:
    """Unregister registered toolset classes in modules.

    Args:
        toolset_classes: References toolset classes to unregister.

    Returns:
        List of unregistered toolset classes.
    """
    registry = get_toolset_registry()
    unregistered_toolset_classes: list[type] = []
    if registry.is_available():
        for toolset_class in toolset_classes:
            if registry.is_toolset_class_registered(toolset_class):
                registry.unregister_toolset_class(toolset_class)
                unregistered_toolset_classes.append(toolset_class)
    return unregistered_toolset_classes


class ToolsetToolInvocationNoOutput(Exception):
    """Exception raised when Toolset.invoke_tool returns None.

    This should never happen and would indicate a serious problem inside
    InvokeTool.
    """

class ToolsetToolInvocationError(Exception):
    """Exception raised when Toolset.invoke_tool returns an error message.

    This indicates an error occurred while trying to invoke the tool and it was
    handled appropriately.
    """

class ToolsetIsNotRegistered(Exception):
    """Exception raised when a toolset is called but not registered."""


async def execute_tool(
    toolset_name: str, tool_name: str, tool_input: Mapping[str, Any]
) -> Mapping[str, Any]:
    """Execute a tool via the registry.

    Args:
        toolset_name: The name of the toolset being executed.
        tool_name: The name of the tool to execute.
        tool_input: The request object providing parameters to the tool.

    Raises:
        ToolsetToolInvocationNoOutput: Raised when execute_tool returns a
            unexpected return value.
        ToolsetToolInvocationError: Raised when execute_tool returns an error
            message.
        ToolsetIsNotRegistered: Raised when the executing toolset is not
            registered.

    Returns:
        Mapping: The response data from the tool.
    """
    registry = get_toolset_registry()
    dumped_input = json.dumps(tool_input)
    async_result = registry.execute_tool(toolset_name, tool_name, dumped_input)
    # We're explicitly checking the return object's shape as the C++ layer
    # could - if buggy - return any UObject derived type. It's still possible
    # for the C++ layer to return an object that matches the shape but not the
    # expected types, this is fine.
    if not isinstance(async_result, ToolCallAsyncResultProtocol):  # type: ignore
        raise ToolsetToolInvocationNoOutput()

    # Wait for execution to complete.
    # The toolset registry should ensure this never polls indefinitely.
    while not async_result.is_complete:
        # Yielding to the next event loop update is fine as the editor event
        # loop is executed for one iteration roughly every 16ms.
        await sleep(0.0)

    error = async_result.error
    if error:
        if registry.is_toolset_registered(toolset_name):
            raise ToolsetToolInvocationError(error)
        raise ToolsetIsNotRegistered(f'{toolset_name} is not registered')

    value = async_result.value
    try:
        return json.loads(value)
    except (TypeError, json.JSONDecodeError) as json_load_error:
        raise ToolsetToolInvocationError(
            f'{toolset_name}.{tool_name} produced invalid JSON output'
        ) from json_load_error
