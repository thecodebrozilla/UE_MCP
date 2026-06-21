# Copyright Epic Games, Inc. All Rights Reserved.

import json
import unittest
import unreal

from editor_toolset.toolsets.object import ObjectTools
from toolset_registry.tests.demo_toolset import ToolsetTestObject


class ObjectToolsTestCase(unittest.TestCase):
    """Test ObjectTools toolset."""

    def test_get_class_from_object(self):
        """Ensures we can get a UClass from a UObject"""
        test_class = ObjectTools.get_class(ToolsetTestObject())
        self.assertEqual(test_class, ToolsetTestObject.static_class())

    def test_get_class_from_class(self):
        """Ensures we can get a UClass from a UClass"""
        test_class = ObjectTools.get_class(ToolsetTestObject.static_class())
        self.assertEqual(test_class, ToolsetTestObject.static_class())

    def test_list_object_properties(self):
        """Ensures that we can list the properties for a UObject"""
        test_object = ToolsetTestObject()
        properties = {
            "a_number": {"type": "number"},
            "a_string": {"type": "string"},
        }
        self.assertEqual(json.loads(ObjectTools.list_properties(test_object)), properties)

    def test_list_class_properties(self):
        """Ensures that we can list the properties for a UClass"""
        properties = {
            "a_number": {"type": "number"},
            "a_string": {"type": "string"},
        }
        self.assertEqual(json.loads(ObjectTools.list_properties(
            ToolsetTestObject.static_class())), properties)

    def test_get_properties(self):
        """Ensures that we can retrieve the values of properties"""
        test_object = ToolsetTestObject()
        test_object.a_number = 10
        properties = {
            "a_number": 10
        }
        self.assertEqual(json.loads(ObjectTools.get_properties(test_object, ['a_number'])), properties)

    def test_set_properties(self):
        """Ensures that we can set the values of properties"""
        test_object = ToolsetTestObject()
        properties = {
            "a_number": 10
        }
        self.assertEqual(test_object.a_number, 0)
        self.assertTrue(ObjectTools.set_properties(test_object, json.dumps(properties)))
        self.assertEqual(test_object.a_number, 10)

    def test_get_properties_invalid(self):
        """Ensures that requesting a non-existent property returns an error."""
        # Must use execute_tool because RaiseScriptError in C++ does not raise
        # a Python exception, so tool_raising_exceptions() cannot catch it.
        test_object = ToolsetTestObject()
        result = unreal.ToolsetRegistry.execute_tool(
            'editor_toolset.toolsets.object.ObjectTools',
            'get_properties',
            json.dumps({
                'instance': {'refPath': test_object.get_path_name()},
                'properties': ['does_not_exist']
            }))
        self.assertIn(
            'the following properties could not be read: does_not_exist', result.error)

    def test_set_properties_invalid(self):
        """Ensures that setting a non-existent property returns an error."""
        # Must use execute_tool because RaiseScriptError in C++ does not raise
        # a Python exception, so tool_raising_exceptions() cannot catch it.
        test_object = ToolsetTestObject()
        result = unreal.ToolsetRegistry.execute_tool(
            'editor_toolset.toolsets.object.ObjectTools',
            'set_properties',
            json.dumps({
                'instance': {'refPath': test_object.get_path_name()},
                'values': json.dumps({'does_not_exist': 10})
            }))
        self.assertIn(
            'the following properties could not be set: does_not_exist', result.error)

    def test_search_subclasses(self):
        """Ensures that we can search subclasses by class"""
        subclasses = ObjectTools.search_subclasses(
            base_class=unreal.PrimaryDataAsset.static_class())
        expected = unreal.SoftClassPath(
            unreal.PrimaryAssetLabel.static_class().get_path_name())
        self.assertIn(expected, subclasses)

    def test_search_subclasses_name(self):
        """Ensures that we can search subclasses by name substring"""
        subclasses = ObjectTools.search_subclasses(
            class_name='Mat', base_class=unreal.DataAsset.static_class())
        expected = unreal.SoftClassPath(
            unreal.MaterialAggregate.static_class().get_path_name())
        self.assertIn(expected, subclasses)

    def test_search_subclasses_no_matches(self):
        """Ensures search_subclasses returns an empty list when nothing matches."""
        subclasses = ObjectTools.search_subclasses(class_name='ZZZNoSuchClass', base_class=unreal.DataAsset.static_class())
        self.assertEqual(subclasses, [])

    def test_reset_properties(self):
        """Ensures that we can reset properties back to their default values."""
        test_object = ToolsetTestObject()
        test_object.a_number = 42.0
        test_object.a_string = 'modified'
        self.assertTrue(ObjectTools.reset_properties(test_object, ['a_number', 'a_string']))
        self.assertEqual(test_object.a_number, 0.0)
        self.assertEqual(test_object.a_string, '')

    def test_reset_properties_partial(self):
        """Ensures that resetting only some properties leaves others unchanged."""
        test_object = ToolsetTestObject()
        test_object.a_number = 42.0
        test_object.a_string = 'modified'
        self.assertTrue(ObjectTools.reset_properties(test_object, ['a_number']))
        self.assertEqual(test_object.a_number, 0.0)
        self.assertEqual(test_object.a_string, 'modified')

    def test_reset_properties_invalid(self):
        """Ensures that resetting a non-existent property returns an error."""
        test_object = ToolsetTestObject()
        result = unreal.ToolsetRegistry.execute_tool(
            'editor_toolset.toolsets.object.ObjectTools',
            'reset_properties',
            json.dumps({
                'instance': {'refPath': test_object.get_path_name()},
                'properties': ['does_not_exist']
            }))
        self.assertIn(
            'the following properties could not be read: does_not_exist', result.error)
