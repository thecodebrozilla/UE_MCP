# Copyright Epic Games, Inc. All Rights Reserved.
"""Test tool execution via the registry."""

from typing import Any
import unittest

import unreal

from toolset_registry._registry_interface import (
    ToolsetToolInvocationError, ToolsetIsNotRegistered, execute_tool
)
from toolset_registry.tests.demo_toolset import (
    DemoPythonToolset, ErrorProneToolset, ToolsetTestObject, ToolsetTestActor
)
from toolset_registry.tests.toolset_testcase import (
    DemoToolsetTestCase, ErrorProneToolsetTestCase
)


DEMO_TOOLSET_NAME = f'{DemoPythonToolset.__module__}.{DemoPythonToolset.__name__}'
ERROR_PRONE_TOOLSET_NAME = f'{ErrorProneToolset.__module__}.{ErrorProneToolset.__name__}'


class TestExecuteTool(DemoToolsetTestCase, unittest.IsolatedAsyncioTestCase):
    """Tests for executing tools through toolset registry."""

    async def test_execute_valid_tool(self):
        """Test that executing a toolset thru registry ExecuteTool works properly."""
        our_msg = 'Hi'
        request = {'msg': our_msg}
        result = await execute_tool(
            DEMO_TOOLSET_NAME, DemoPythonToolset.hello_world.__name__, request)
        expected_result = f'Hello, world! {our_msg} from demo toolset'
        self.assertEqual(result['returnValue'], expected_result)

    async def test_execute_invalid_tool(self):
        """Test that executing an invalid tool thru registry ExecuteTool errors out properly."""
        request = {'msg': 'Hi'}
        tool_name = 'nonexistent_tool'
        expected_error_msg = f'Unknown tool {tool_name}'
        with self.assertRaises(ToolsetToolInvocationError) as context:
            _ = await execute_tool(
                DEMO_TOOLSET_NAME, tool_name, request)
        self.assertEqual(str(context.exception), expected_error_msg)

    async def test_execute_invalid_toolset(self):
        """Test that executing an invalid toolset thru registry ExecuteTool errors out properly."""
        request = {'msg': 'Hi'}
        invalid_toolset_name = DEMO_TOOLSET_NAME + 'Invalid'

        unreal.AutomationLibrary.add_expected_plain_log_error(
            f'Toolset \'{invalid_toolset_name}\' not found', 1)

        with self.assertRaises(ToolsetIsNotRegistered):
            _ = await execute_tool(
                invalid_toolset_name, 'nonexistent_tool', request)

    async def test_execute_tool_no_output(self):
        """Test that executing a tool that returns no output behaves as expected."""
        request: dict[str, Any] = {}
        tool_name = DemoPythonToolset.hello_void.__name__

        result = await execute_tool(DEMO_TOOLSET_NAME, tool_name, request)
        expected_result = None
        self.assertEqual(result['returnValue'], expected_result)

    async def test_execute_tool_simple_params(self):
        """Test that invoking tool method works as expected with basic param types."""
        our_msg = 'Hi'
        request = {'msg': our_msg}
        result = await execute_tool(DEMO_TOOLSET_NAME, 'hello_world', request)
        expected_result = f'Hello, world! {our_msg} from demo toolset'
        self.assertEqual(result['returnValue'], expected_result)

    async def test_execute_tool_optional_params(self):
        """Test that invoking tool method works as expected with optional params."""
        # Invoke with no value for input
        request: dict[str, Any] = {}
        result = await execute_tool(DEMO_TOOLSET_NAME, 'hello_optional', request)
        expected_result = None
        self.assertEqual(result['returnValue'], expected_result)
        # Invoke with None value for input
        request = {'input': None}
        result = await execute_tool(DEMO_TOOLSET_NAME, 'hello_optional', request)
        expected_result = None
        self.assertEqual(result['returnValue'], expected_result)
        # Invoke with float value for input
        request = {'input': 14}
        result = await execute_tool(DEMO_TOOLSET_NAME, 'hello_optional', request)
        expected_result = 14
        self.assertEqual(result['returnValue'], expected_result)

    async def test_execute_tool_struct_params(self):
        """Test that invoking tool method works as expected with struct param types."""
        request: dict[str, Any] = {'test_input': {'value_1': 'foo', 'value_2': 42}}
        result = await execute_tool(DEMO_TOOLSET_NAME, 'hello_struct', request)
        expected_result = {'success': True, 'a_number': 42.0,
                           'many_results': ['a', 'b', 'c']}
        self.assertDictEqual(result['returnValue'], expected_result)

    async def test_execute_tool_object_params(self):
        """Test that invoking tool method works as expected with object param types."""
        test_object = ToolsetTestObject()
        request: dict[str, Any] = {'input': { 'refPath' : test_object.get_path_name() } }
        result = await execute_tool(DEMO_TOOLSET_NAME, 'hello_object', request)
        expected_result = { 'refPath' : test_object.get_path_name() }
        self.assertDictEqual(result['returnValue'], expected_result)

    async def test_execute_tool_list_params(self):
        """Test that invoking tool method works as expected with list param types."""
        request = {'input': ['foo', 'bar']}
        result = await execute_tool(DEMO_TOOLSET_NAME, 'hello_list', request)
        expected_result = ['foo', 'bar']
        self.assertEqual(result['returnValue'], expected_result)

    async def test_execute_tool_dict_params(self):
        """Test that invoking tool method works as expected with dict param types."""
        contents = {'foo': 3.0, 'bar': 42.0}
        request = {'input': contents}
        result = await execute_tool(DEMO_TOOLSET_NAME, 'hello_dict', request)
        expected_result = contents
        self.assertDictEqual(result['returnValue'], expected_result)

    async def test_execute_tool_set_params(self):
        """Test that invoking tool method works as expected with set param types."""
        contents = [1.0, 9.0]
        request = {'input': contents}
        result = await execute_tool(DEMO_TOOLSET_NAME, 'hello_set', request)
        expected_result = contents
        self.assertEqual(result['returnValue'], expected_result)

    async def test_execute_tool_handle_call_that_returns_failure(self):
        """Test that invoking a tool method that returns a failed result is handled properly."""
        request: dict[str, Any] = {
            'test_input': {'value_1': 'fail', 'value_2': 0.0}
        }
        result = await execute_tool(DEMO_TOOLSET_NAME, 'hello_struct', request)
        expected_result = {'success': False, 'a_number': -1.0, 'many_results': []}
        self.assertDictEqual(result['returnValue'], expected_result)

    async def test_execute_tool_handle_error(self):
        """Test that invoking a tool method that generates an error on call is handled properly."""
        request: dict[str, Any] = {
            'test_input': {'value_1': 'fail', 'value_2': 0.0}
        }
        tool_name = 'hello_struct_nonexistent'
        expected_error_msg = f'Unknown tool {tool_name}'
        with self.assertRaises(ToolsetToolInvocationError) as context:
            _ = await execute_tool(DEMO_TOOLSET_NAME, tool_name, request)
        self.assertEqual(str(context.exception), expected_error_msg)

    async def test_execute_tool_default_params_provided(self):
        """Test that invoking tool with default param types works when provided."""
        world_count = 3
        request: dict[str, Any] = {
            'msg': 'Guten Tag', "world_count": world_count
        }
        result = await execute_tool(DEMO_TOOLSET_NAME, 'hello_many_worlds', request)
        expected_result = world_count
        self.assertEqual(result['returnValue'], expected_result)


class TestErrorTool(
    ErrorProneToolsetTestCase, unittest.IsolatedAsyncioTestCase
):
    """Tests for executing tools that error out."""

    async def test_execute_tool_raises_error(self):
        """Test that invoking tool that raises error propagates error properly."""

        # Tool exceptions are propagated via ToolsetToolInvocationError.
        with self.assertRaises(ToolsetToolInvocationError) as context:
            await execute_tool(
                ERROR_PRONE_TOOLSET_NAME, 'bad_tool', {"msg": "Guten Tag"})

        # The exception message should match the original error, because it is
        # raised by the tool_call decorator .
        self.assertEqual('Bad tool bad', str(context.exception))

    async def test_execute_tool_catches_scripting_exceptions(self):
        """Test that scripting layer exceptions are captured as errors properly."""

        # bad_typed_tool returns None for an int return. Nativization fails via
        # FFrame::KismetExecutionMessage, which PSP's InvokeFunctionCall handler
        # catches and translates to RuntimeError directly - async_result.error
        # is never reached.
        with self.assertRaises(RuntimeError) as context:
            await execute_tool(
                ERROR_PRONE_TOOLSET_NAME, 'bad_typed_tool', {"msg": "hello"})

        # We don't control the scripting layer's exception formatting, but the
        # message must carry the underlying NativizeProperty type mismatch.
        self.assertIn(
            'NativizeProperty: Cannot nativize \'NoneType\' as \'ReturnValue\'',
            str(context.exception))

    async def test_null_object_param(self):
        """Ensure passing null object param raises error."""
        tool_name = 'takes_uobject'
        with self.assertRaises(ToolsetToolInvocationError) as context:
            await execute_tool(
                ERROR_PRONE_TOOLSET_NAME, tool_name, {'obj': {'refPath': ''}})
        self.assertIn('None is not valid', str(context.exception))

    async def test_null_class_param(self):
        """Ensure passing null class param raises error."""
        tool_name = 'takes_uclass'
        with self.assertRaises(ToolsetToolInvocationError) as context:
            await execute_tool(
                ERROR_PRONE_TOOLSET_NAME, tool_name, {'obj': {'refPath': ''}})
        self.assertIn('None is not valid', str(context.exception))

    async def test_convert_optional_object_param(self):
        """Test passing None to optional object param does not raise error."""
        tool_name = 'takes_optional_uobject'
        result = await execute_tool(
            ERROR_PRONE_TOOLSET_NAME, tool_name, {'obj': {'refPath': ''}})
        self.assertEqual(result['returnValue'], None)

    async def test_param_actor_as_uobject(self):
        """Ensure passing actor as uobject param does not error."""
        tool_name = 'takes_uobject'
        test_actor = ToolsetTestActor()
        result = await execute_tool(
            ERROR_PRONE_TOOLSET_NAME, tool_name,
            {'obj': {'refPath': test_actor.get_path_name()}})
        self.assertEqual(result['returnValue'], None)

    async def test_param_actor_as_class(self):
        """Ensure passing actor as uclass param raises error."""
        tool_name = 'takes_uclass'
        test_actor = ToolsetTestActor()
        with self.assertRaises(ToolsetToolInvocationError) as context:
            await execute_tool(
                ERROR_PRONE_TOOLSET_NAME, tool_name,
                {'obj': {'refPath': test_actor.get_path_name()}})
        self.assertIn('is not valid', str(context.exception))

    async def test_param_object_as_class(self):
        """Ensure passing uobject as uclass param raises error."""
        tool_name = 'takes_uclass'
        test_object = ToolsetTestObject()
        with self.assertRaises(ToolsetToolInvocationError) as context:
            await execute_tool(
                ERROR_PRONE_TOOLSET_NAME, tool_name,
                {'obj': {'refPath': test_object.get_path_name()}})
        self.assertIn('is not valid', str(context.exception))

    async def test_param_actor_as_actor(self):
        """Ensure passing actor as actor param does not error."""
        tool_name = 'takes_actor'
        test_actor = ToolsetTestActor()
        result = await execute_tool(
            ERROR_PRONE_TOOLSET_NAME, tool_name,
            {'obj': {'refPath': test_actor.get_path_name()}})
        self.assertEqual(result['returnValue'], None)

    async def test_param_object_as_actor(self):
        """Ensure passing uobject as actor param raises error."""
        tool_name = 'takes_actor'
        test_object = ToolsetTestObject()
        with self.assertRaises(ToolsetToolInvocationError) as context:
            await execute_tool(
                ERROR_PRONE_TOOLSET_NAME, tool_name,
                {'obj': {'refPath': test_object.get_path_name()}})
        self.assertIn('is not valid', str(context.exception))


FAKE_ERROR_PRONE_TOOLSET_NAME = 'ToolsetRegistry.FakeErrorProneToolset'
BUGGY_TOOL_NAME = 'BuggyTool'
BUGGY_TOOL_ERROR_MESSAGE = 'Bug in this tool'


class TestFailingCppToolFromPython(unittest.TestCase):
    """A C++ tool's RaiseScriptError must reach Python as a catchable exception."""

    @classmethod
    def setUpClass(cls):
        unreal.ToolsetRegistry.register_toolset_class(unreal.FakeErrorProneToolset)

    @classmethod
    def tearDownClass(cls):
        unreal.ToolsetRegistry.unregister_toolset_class(unreal.FakeErrorProneToolset)

    async def test_failure_is_catchable_from_execute_tool_sync(self):
        """execute_tool surfaces the C++ failure as ToolsetToolInvocationError."""
        with self.assertRaises(ToolsetToolInvocationError) as context:
            await execute_tool(FAKE_ERROR_PRONE_TOOLSET_NAME, BUGGY_TOOL_NAME, {})
        self.assertIn(BUGGY_TOOL_ERROR_MESSAGE, str(context.exception))
