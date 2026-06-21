# Copyright Epic Games, Inc. All Rights Reserved.
"""Test _registry_interface."""

from contextlib import contextmanager, ExitStack
from typing import Any, Generator, FrozenSet
from unittest import mock
import unittest


from toolset_registry import _registry_interface
from toolset_registry._registry_interface import (
    execute_tool,
    find_toolset_classes,
    register_toolset_classes,
    unregister_toolset_classes,
    ToolCallAsyncResultProtocol,
    ToolsetRegistryProtocol,
    ToolsetToolInvocationNoOutput,
    ToolsetIsNotRegistered,
    ToolsetToolInvocationError
)
from toolset_registry.tests import demo_toolset


class FakeToolCallAsyncResult:
    """Fake async result."""

    def __init__(self):
        """Initialize a pending result."""
        self._complete = False
        self._value: str = ''
        self._error: str = ''

    @property
    def is_complete(self) -> bool:  # pyright: ignore
        """Whether the result is complete."""
        return self._complete

    @property
    def value(self) -> Any:
        """Value of the result when complete."""
        return self._value

    @property
    def error(self) -> Any:
        """Error message if complete and the call failed."""
        return self._error

    def set_result(self, value: str) -> None:
        """Complete the result with a value.

        Args:
            value: Value to assign.
        """
        assert not self.is_complete
        self._value = value
        self._complete = True

    def set_error(self, error: str) -> None:
        """Complete the result with an error.

        Args:
            error: Error to assign.
        """
        assert not self.is_complete
        self._error = error
        self._complete = True


class FakeToolsetRegistry:
    """Fake toolset registry."""

    _toolset_classes_by_name: dict[str, type] = {}
    available = True

    @classmethod
    def is_available(cls) -> bool:
        """Whether the registry is available."""
        return cls.available

    @classmethod
    def is_toolset_registered(cls, toolset_name: str) -> bool:
        """Whether a toolset is registered."""
        return cls.find_toolset_class(toolset_name) is not None

    @classmethod
    def is_toolset_class_registered(cls, toolset_class: type) -> bool: # pyright: ignore
        """Whether a toolset class is registered."""
        return toolset_class in cls._toolset_classes_by_name.values()

    @classmethod
    def register_toolset_class(cls, toolset_class: type) -> None:
        """Register a toolset."""
        cls._toolset_classes_by_name[toolset_class.__name__] = toolset_class

    @classmethod
    def unregister_toolset_class(cls, toolset_class: type) -> None:
        """Unregister a toolset."""
        del cls._toolset_classes_by_name[toolset_class.__name__]

    @classmethod
    def execute_tool(
        cls, toolset_name: str, tool_name: str, json_input: str
    ) -> ToolCallAsyncResultProtocol:  # pyright: ignore
        """Execute a tool."""
        toolset = cls.find_toolset_class(toolset_name)
        if not toolset:
            result = FakeToolCallAsyncResult()
            result.set_error(f'{toolset_name}.{tool_name} not registered ')
            return result

        tool = getattr(toolset, tool_name, None)
        if not callable(tool):
            result = FakeToolCallAsyncResult()
            result.set_error(f'{toolset_name}.{tool_name} not found: {tool}')
            return result

        return tool(json_input)  # type: ignore

    @classmethod
    def reset(cls) -> None:
        """Reset the fake to its initial state."""
        cls.available = True
        cls._toolset_classes_by_name.clear()

    @classmethod
    def get_registered_toolset_classes(cls) -> FrozenSet[type]:
        """Get registered toolset clasess.

        Returns:
            Toolset classes registered with the fake.
        """
        return frozenset(cls._toolset_classes_by_name.values())

    @classmethod
    @contextmanager
    def install(cls) -> Generator[ToolsetRegistryProtocol, None, None]:
        """Install the fake toolset registry.

        Yields:
            This class.
        """
        cls.reset()
        with mock.patch.object(
            _registry_interface, 'get_toolset_registry', cls
        ):
            try:
                yield cls
            finally:
                cls.reset()

    @classmethod
    @contextmanager
    def spy_on_unregister_toolset_class(cls) -> (
        Generator[mock.Mock, None, None]
    ):
        """Hook unregister toolset class with a mock.

        Yields:
            Mock that reports calls to unregister_toolset_class.
        """
        with mock.patch.object(
            cls, 'unregister_toolset_class',
            side_effect=cls.unregister_toolset_class
        ) as mock_unregister_toolset_class:
            yield mock_unregister_toolset_class

    @classmethod
    def find_toolset_class(cls, toolset_name: str) -> type | None:
        """Find a toolset class by name.

        Args:
            toolset_name: Toolset name to find.

        Returns:
            Toolset class if found None otherwise.
        """
        return cls._toolset_classes_by_name.get(toolset_name)


class RegistryInterfaceTestCase(unittest.TestCase):
    """Base test case for the _registry_interface module."""

    _TOOLSET_CLASSES: list[type] = [
        demo_toolset.DemoPythonToolset,
        demo_toolset.ErrorProneToolset,
    ]

    def setUp(self):
        """Install the fake toolset registry."""
        self._exit_stack = ExitStack()
        _ = self._exit_stack.enter_context(FakeToolsetRegistry.install())

    def tearDown(self):
        """Uninstall fakes."""
        self._exit_stack.close()


class TestFindToolsetClasses(RegistryInterfaceTestCase):
    """Test find_toolset_classes."""

    def test_find_toolset_classes(self):
        """Test finding toolset classes in a module.."""
        self.assertCountEqual(
            find_toolset_classes([demo_toolset]), self._TOOLSET_CLASSES
        )


class TestRegisterToolsetClasses(RegistryInterfaceTestCase):
    """Test register_toolset_classes."""

    def test_not_available(self):
        """Test registration when the registry is not available."""
        FakeToolsetRegistry.available = False
        self.assertSequenceEqual(
            register_toolset_classes(self._TOOLSET_CLASSES), []
        )
        self.assertCountEqual(
            FakeToolsetRegistry.get_registered_toolset_classes(), []
        )

    def test_not_registered(self):
        """Test registration when toolsets are not registered."""
        self.assertSequenceEqual(
            register_toolset_classes(self._TOOLSET_CLASSES), []
        )
        self.assertCountEqual(
            FakeToolsetRegistry.get_registered_toolset_classes(),
            self._TOOLSET_CLASSES
        )

    def test_registered(self):
        """Test registering toolsets when they're already registered."""
        with FakeToolsetRegistry.spy_on_unregister_toolset_class() as (
            mock_unregister_toolset_class
        ):
            self.assertSequenceEqual(
                register_toolset_classes(self._TOOLSET_CLASSES), []
            )
            self.assertSequenceEqual(
                register_toolset_classes(self._TOOLSET_CLASSES), []
            )
            mock_unregister_toolset_class.assert_has_calls(
                [
                    mock.call(toolset_class)
                    for toolset_class in self._TOOLSET_CLASSES
                ],
                any_order=True
            )
            self.assertCountEqual(
               FakeToolsetRegistry.get_registered_toolset_classes(),
                self._TOOLSET_CLASSES
            )


class TestUnregisterToolsetClasses(RegistryInterfaceTestCase):
    """Test toolset class unregistration."""

    def test_not_available(self):
        """Test unregistration when the registry is not available."""
        FakeToolsetRegistry.available = False
        with FakeToolsetRegistry.spy_on_unregister_toolset_class() as (
            mock_unregister_toolset_class
        ):
            self.assertSequenceEqual(
                unregister_toolset_classes(self._TOOLSET_CLASSES), []
            )
            mock_unregister_toolset_class.assert_not_called()

    def test_registered(self):
        """Test unregistration when toolsets are registered."""
        register_toolset_classes(self._TOOLSET_CLASSES)
        self.assertCountEqual(
            unregister_toolset_classes(self._TOOLSET_CLASSES),
            self._TOOLSET_CLASSES
        )
        self.assertCountEqual(
            FakeToolsetRegistry.get_registered_toolset_classes(), []
        )

    def test_registered_not_registered(self):
        """Test unregistration when toolsets are registered."""
        with FakeToolsetRegistry.spy_on_unregister_toolset_class() as (
            mock_unregister_toolset_class
        ):
            self.assertSequenceEqual(
                unregister_toolset_classes(self._TOOLSET_CLASSES), []
            )
            mock_unregister_toolset_class.assert_not_called()


class FakeTool:
    """Fake tool."""

    @classmethod
    def success(cls, json_input: str) -> ToolCallAsyncResultProtocol:
        """Succesful tool that returns the provided input.

        Args:
            json_input: What to return.

        Returns:
            Result with the provided input.
        """
        result = FakeToolCallAsyncResult()
        result.set_result(json_input)
        return result

    @classmethod
    def failure(cls, json_input: str) -> ToolCallAsyncResultProtocol:
        """Tool that fails.

        Args:
            json_input: Ignored.

        Returns:
            An error.
        """
        _ = json_input
        result = FakeToolCallAsyncResult()
        result.set_error('failed')
        return result

    @classmethod
    def invalid_result(cls, json_input: str) -> ToolCallAsyncResultProtocol:
        """Tool that doesn't return a valid result type.

        Args:
            json_input: Ignored.

        Returns:
            Invalid object.
        """
        _ = json_input
        result = FakeToolCallAsyncResult()
        result.set_result('invalid_json_output')
        return result

    @classmethod
    def invalid_result_type(cls, json_input: str) -> ToolCallAsyncResultProtocol:
        """Tool that doesn't return a valid result type.

        Args:
            json_input: Ignored.

        Returns:
            Invalid object.
        """
        _ = json_input
        return {}  # type: ignore


class TestExecuteTool(RegistryInterfaceTestCase):
    """Test executing a tool via the registry."""

    def setUp(self):
        """Register the fake tool with the registry."""
        super().setUp()
        FakeToolsetRegistry.register_toolset_class(FakeTool)

    async def test_success(self):
        """Test successfully executing a tool."""
        tool_input = {'hay': 'barn'}
        result = await execute_tool(
            FakeTool.__name__, FakeTool.success.__name__, tool_input
        )
        self.assertDictEqual(result, tool_input)

    async def test_failure(self):
        """Test executing a failing tool."""
        with self.assertRaises(ToolsetToolInvocationError):
            _ = await execute_tool(
                FakeTool.__name__, FakeTool.failure.__name__, {}
            )

    async def test_invalid_result(self):
        """Test executing a tool that completes with invalid output."""
        with self.assertRaises(ToolsetToolInvocationError):
            _ = await execute_tool(
                FakeTool.__name__, FakeTool.invalid_result.__name__, {}
            )

    async def test_invalid_result_type(self):
        """Test executing a tool that returns an invalid result."""
        with self.assertRaises(ToolsetToolInvocationNoOutput):
            _ = await execute_tool(
                FakeTool.__name__, FakeTool.invalid_result_type.__name__, {}
            )

    async def test_missing_toolset(self):
        """Test executing a toolset that is missing."""
        with self.assertRaises(ToolsetIsNotRegistered):
            _ = await execute_tool(
                'FakeyTool', FakeTool.success.__name__, {}
            )

    async def test_missing_tool(self):
        """Test executing a missing tool."""
        with self.assertRaises(ToolsetIsNotRegistered):
            _ = await execute_tool(FakeTool.__name__, 'wibble', {})
