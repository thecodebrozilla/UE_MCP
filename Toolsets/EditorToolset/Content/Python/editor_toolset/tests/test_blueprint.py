# Copyright Epic Games, Inc. All Rights Reserved.

from contextlib import ExitStack
import json
from typing import Any, Iterable
import unittest

import unreal

from toolset_registry.tests.toolset_testcase import ToolCallTestCase
from toolset_registry.tests.automation import create_temp_folder
from editor_toolset.toolsets.asset import AssetTools
from editor_toolset.toolsets.blueprint import BlueprintTools, ContainerType, _BlueprintCache
from editor_toolset.toolsets.blueprint_layout import GraphFormatter
from editor_toolset.toolsets.object import ObjectTools
from editor_toolset.toolsets.actor import ActorTools

class BlueprintToolsTestCase(ToolCallTestCase):
    """Test BlueprintTools toolset."""

    def assertIn(self, item: Any, container: Iterable[Any]):
        """unreal.Array.__repr__ does not display contents so use __str__.

        Args:
            item: Item to search for within the container.
            container: Container to search.
        """
        super().assertIn(item, container, msg=f'{item} not in {container}')

    def setUp(self):
        super().setUp()
        # We need to enter the temp_folder context in test setup because these tests create
        # Python objects that reference Blueprint UObjects and those Python objects need
        # to be out of scope before we delete the Blueprint asset.
        self._stack = ExitStack()
        self.test_folder = self._stack.enter_context(create_temp_folder())
        self.blueprint = BlueprintTools.create(
            folder_path=self.test_folder, asset_name='TestBlueprint',
            asset_type=unreal.Actor.static_class())

    def tearDown(self) -> None:
        self.sibling_blueprint = None
        self.blueprint = None
        self._stack.close()
        super().tearDown()

    def test_create(self):
        """Ensures that we can create a blueprint asset."""
        self.assertIsInstance(self.blueprint, unreal.Blueprint)
        self.assertIsInstance(
            unreal.get_default_object(self.blueprint.generated_class()), unreal.Actor)

    @unittest.skipIf(unreal.SystemLibrary.is_unattended(), "Skipping test as running in headless mode")
    def test_create_bad_asset_type_fails(self):
        """Ensures that creating blueprint asset with invalid type fails."""
        with self.assertToolRaisesRuntimeError():
            # Note: The blueprint factory puts up a modal error dialog.
            bad_blueprint = BlueprintTools.create(
                folder_path=self.test_folder, asset_name='TestBadBlueprint',
                asset_type=unreal.StaticMesh.static_class())
            self.assertIsNone(bad_blueprint)

    def test_create_bad_asset_type_none_fails(self):
        """Ensures that creating blueprint asset with invalid type fails."""
        with self.assertToolRaisesRuntimeError():
            bad_blueprint = BlueprintTools.create(
                folder_path=self.test_folder, asset_name='TestBadBlueprint',
                asset_type=None)
            self.assertIsNone(bad_blueprint)

    def test_create_dupe_fails(self):
        """Ensures that creating blueprint asset that already exists fails."""
        with self.assertToolRaisesRuntimeError():
            bad_blueprint = BlueprintTools.create(
                folder_path=self.test_folder, asset_name='TestBlueprint',
                asset_type=unreal.Actor.static_class())
            self.assertIsNone(bad_blueprint)

    def test_get_default_object(self):
        """Ensures get_default_object returns the CDO of the Blueprint's generated class."""
        cdo = BlueprintTools.get_default_object(self.blueprint)
        self.assertIsInstance(cdo, unreal.Actor)
        self.assertEqual(cdo, unreal.get_default_object(self.blueprint.generated_class()))

    def test_get_graph(self):
        """Ensures that we can get the event graph from a blueprint"""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        bp_editor = unreal.BlueprintGraphEditor.get_graph_editor_by_name(self.blueprint, unreal.Name('EventGraph'))
        self.assertIsInstance(graph, unreal.EdGraph)
        self.assertEqual(graph, bp_editor.get_graph())

    def test_add_get_node(self):
        """Ensures that we can add and get nodes from the event graph"""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        added_node = BlueprintTools.create_node(graph, 'Development|PrintString', unreal.IntPoint(1, 2))
        self.assertIsNotNone(added_node)
        nodes = BlueprintTools.find_nodes(graph)
        self.assertIn(added_node, nodes)
        node_info = BlueprintTools._get_node_info(added_node)
        self.assertEqual(node_info.node, added_node)
        self.assertEqual(node_info.position, unreal.IntPoint(1, 2))
        self.assertEqual(node_info.type_id, 'Development|PrintString')

    def test_delete_node(self):
        "Ensures that we can remove nodes from Blueprint graphs"
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        added_node = BlueprintTools.create_node(graph, 'Development|PrintString', unreal.IntPoint(1, 2))
        BlueprintTools.delete_node(added_node)
        self.assertNotIn(added_node, BlueprintTools.find_nodes(graph))

    def test_find_node_types_name(self):
        """Ensures that we can find nodes using their name and that results are cached."""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        graph_key = graph.get_path_name()
        _BlueprintCache._graph_node_types.pop(graph_key, None)
        node_types = BlueprintTools.find_node_types(graph, 'Development|PrintString')
        self.assertIn('Development|PrintString', node_types)
        self.assertIn(graph_key, _BlueprintCache._graph_node_types)
        node_types = BlueprintTools.find_node_types(graph, 'Devel')
        self.assertIn('Development|PrintString', node_types)

    def test_find_node_types_stale_fingerprint(self):
        """Ensures that a stale fingerprint on one graph invalidates all sibling graphs too."""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        graph_key = graph.get_path_name()
        # Populate the cache for a second graph in the same blueprint.
        func_graph = BlueprintTools.add_function_graph(self.blueprint, 'MyFunction')
        func_graph_key = func_graph.get_path_name()
        BlueprintTools.find_node_types(graph, '')
        BlueprintTools.find_node_types(func_graph, '')
        cached_fingerprint = _BlueprintCache._graph_node_types[graph_key].fingerprint
        self.assertIn(func_graph_key, _BlueprintCache._graph_node_types)
        # Simulate a UI-side variable addition bypassing the toolset's invalidation call.
        unreal.BlueprintEditorLibrary.add_member_variable(
            self.blueprint, 'UIVar', unreal.BlueprintEditorLibrary.get_basic_type_by_name('int'))
        # Both entries are still present but their fingerprints are now stale.
        self.assertIn(graph_key, _BlueprintCache._graph_node_types)
        self.assertIn(func_graph_key, _BlueprintCache._graph_node_types)
        self.assertEqual(_BlueprintCache._graph_node_types[graph_key].fingerprint, cached_fingerprint)
        # A find_node_types call on one graph should detect the mismatch, invalidate
        # all graphs in the blueprint, and rebuild only the queried graph.
        BlueprintTools.find_node_types(graph, '')
        new_fingerprint = _BlueprintCache._graph_node_types[graph_key].fingerprint
        self.assertNotEqual(new_fingerprint, cached_fingerprint)
        self.assertNotIn(func_graph_key, _BlueprintCache._graph_node_types)

    def test_find_node_types_macro(self):
        """Ensures that find_node_types includes engine macros in Category|Title format"""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        node_types = BlueprintTools.find_node_types(graph, 'Utilities|FlowControl|ForLoop')
        self.assertIn('Utilities|FlowControl|ForLoop', node_types)
        node_types = BlueprintTools.find_node_types(graph, 'Utilities|FlowControl')
        self.assertIn('Utilities|FlowControl|ForLoop', node_types)

    def test_find_node_categories_macro(self):
        """Ensures that find_node_categories includes macro categories"""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        categories = BlueprintTools.find_node_categories(graph, 'Utilities|FlowControl')
        self.assertIn('Utilities|FlowControl', categories)

    def test_create_macro_node(self):
        """Ensures that we can create a macro node using its Category|Title type_id"""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        node = BlueprintTools.create_node(graph, 'Utilities|FlowControl|ForLoop', unreal.IntPoint(100, 100))
        self.assertIsInstance(node, unreal.EdGraphNode)
        self.assertIn(node, BlueprintTools.find_nodes(graph))
        self.assertEqual(BlueprintTools._get_node_info(node).type_id, 'Utilities|FlowControl|ForLoop')

    def test_find_node_types_pin(self):
        """Ensures that we can find nodes by using context pins"""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        added_node = BlueprintTools.create_node(graph, 'Utilities|String|ToLower', unreal.IntPoint(1, 2))
        node_info = BlueprintTools._get_node_info(added_node)
        node_types = BlueprintTools.find_node_types(graph, '', [node_info.output_pins[0].pin_id])
        self.assertIn('Development|PrintString', node_types)

    def test_find_node_categories_name(self):
        """Ensures that we can find node categories using their name"""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        categories = BlueprintTools.find_node_categories(graph, 'Utilities')
        self.assertGreater(len(categories), 0)
        self.assertIn('Utilities|Operators', categories)

    def test_find_node_categories_pin(self):
        """Ensures that we can find node categories by using context pins"""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        added_node = BlueprintTools.create_node(graph, 'Utilities|String|ToLower', unreal.IntPoint(1, 2))
        node_info = BlueprintTools._get_node_info(added_node)
        categories = BlueprintTools.find_node_categories(graph, '', [node_info.output_pins[0].pin_id])
        self.assertGreater(len(categories), 0)
        self.assertIn('Development', categories)

    def test_get_set_pin_value(self):
        """Ensures that we can get and set a pin's value"""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        added_node = BlueprintTools.create_node(graph, 'Development|PrintString', unreal.IntPoint(1, 2))
        node_info = BlueprintTools._get_node_info(added_node)
        pin = node_info.input_pins[1].pin_id
        BlueprintTools.set_pin_value(pin, 'Hi there!')
        self.assertEqual(BlueprintTools.get_pin_value(pin), 'Hi there!')

    def test_set_node_position(self):
        """Ensures that we can set the position of a node"""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        added_node = BlueprintTools.create_node(graph, 'Development|PrintString', unreal.IntPoint(1, 2))
        BlueprintTools.set_node_position(added_node, unreal.IntPoint(100, 200))
        node_info = BlueprintTools._get_node_info(added_node)
        self.assertEqual(node_info.position, unreal.IntPoint(100, 200))

    def test_connect_break_pins(self):
        """Ensures we can connect two pins and then break two pins' connections"""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        print_string_node = BlueprintTools.create_node(graph, 'Development|PrintString', unreal.IntPoint(200, 200))
        to_lower_node = BlueprintTools.create_node(graph, 'Utilities|String|ToLower', unreal.IntPoint(100, 200))
        print_string_pin = BlueprintTools._get_node_info(print_string_node).input_pins[1].pin_id
        to_lower_pin = BlueprintTools._get_node_info(to_lower_node).output_pins[0].pin_id
        BlueprintTools.connect_pins(to_lower_pin, print_string_pin)
        to_lower_node_info = BlueprintTools._get_node_info(to_lower_node)
        self.assertGreater(len(to_lower_node_info.output_pins[0].connected_pins), 0)
        BlueprintTools.break_pins(to_lower_pin, print_string_pin)
        to_lower_node_info = BlueprintTools._get_node_info(to_lower_node)
        self.assertEqual(len(to_lower_node_info.output_pins[0].connected_pins), 0)

    def test_connect_pins_incompatible_raises(self):
        """Ensures that connecting incompatible pins raises."""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        print_string_node = BlueprintTools.create_node(
            graph, 'Development|PrintString', unreal.IntPoint(200, 200))
        to_lower_node = BlueprintTools.create_node(
            graph, 'Utilities|String|ToLower', unreal.IntPoint(100, 200))
        # exec output -> string input: incompatible types
        exec_out_pin = BlueprintTools._get_node_info(print_string_node).output_pins[0].pin_id
        string_in_pin = BlueprintTools._get_node_info(to_lower_node).input_pins[0].pin_id
        with self.assertToolRaisesRuntimeError():
            BlueprintTools.connect_pins(exec_out_pin, string_in_pin)

    def test_break_pins_not_connected_raises(self):
        """Ensures that breaking a non-existent connection raises."""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        print_string_node = BlueprintTools.create_node(
            graph, 'Development|PrintString', unreal.IntPoint(200, 200))
        to_lower_node = BlueprintTools.create_node(
            graph, 'Utilities|String|ToLower', unreal.IntPoint(100, 200))
        print_string_pin = BlueprintTools._get_node_info(print_string_node).input_pins[1].pin_id
        to_lower_pin = BlueprintTools._get_node_info(to_lower_node).output_pins[0].pin_id
        with self.assertToolRaisesRuntimeError():
            BlueprintTools.break_pins(to_lower_pin, print_string_pin)

    def test_set_pin_value_exec_pin_raises(self):
        """Ensures that setting a value on an exec pin raises."""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        print_string_node = BlueprintTools.create_node(
            graph, 'Development|PrintString', unreal.IntPoint(1, 2))
        exec_pin = BlueprintTools._get_node_info(print_string_node).input_pins[0].pin_id
        with self.assertToolRaisesRuntimeError():
            BlueprintTools.set_pin_value(exec_pin, 'invalid')

    def test_get_node_infos(self):
        """Ensures get_node_infos returns NodeInfo for each supplied node"""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        nodes = BlueprintTools.find_nodes(graph)
        infos = BlueprintTools.get_node_infos(nodes)
        self.assertEqual(len(infos), len(nodes))
        for node_info in infos:
            self.assertIn(node_info.node, nodes)

    def test_compile_blueprint(self):
        "Ensures that we can compile a Blueprint."
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        print_string_node = BlueprintTools.create_node(graph, 'Development|PrintString', unreal.IntPoint(200, 200))
        event_tick_node = BlueprintTools.find_nodes(graph)[2]
        event_tick_exec_pin = BlueprintTools._get_node_info(event_tick_node).output_pins[1].pin_id
        print_string_node_pin = BlueprintTools._get_node_info(print_string_node).input_pins[0].pin_id
        BlueprintTools.connect_pins(event_tick_exec_pin, print_string_node_pin)
        self.assertEqual(self.blueprint.status, unreal.BlueprintStatus.BS_DIRTY)
        BlueprintTools.compile_blueprint(self.blueprint)
        self.assertEqual(self.blueprint.status, unreal.BlueprintStatus.BS_UP_TO_DATE)

    def test_fail_compile_blueprint(self):
        """Ensures we can receive the compiler errors when compiling a blueprint."""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        srv_node = BlueprintTools.create_node(graph, 'Camera|SetRotatorVariable', unreal.IntPoint(200, 200))
        event_tick_node = BlueprintTools.find_nodes(graph)[2]
        event_tick_exec_pin = BlueprintTools._get_node_info(event_tick_node).output_pins[1].pin_id
        srv_node_pin = BlueprintTools._get_node_info(srv_node).input_pins[0].pin_id
        BlueprintTools.connect_pins(event_tick_exec_pin, srv_node_pin)
        unreal.AutomationLibrary.add_expected_plain_log_error(
            '[Compiler] The current value', 2, False)
        with self.assertToolRaisesRuntimeError() as cm:
            BlueprintTools.compile_blueprint(self.blueprint)
        self.assertIn('Compile Errors: ', str(cm.exception))

    def test_add_member_variable_types(self):
        """Ensures that we can add member variables of various types."""
        cases = [
            ('MyBool', 'bool', bool),
            ('MyInt', 'int', int),
            ('MyFloat', 'float', float),
            ('MyString', 'string', str),
            ('MyVector', 'Vector', unreal.Vector),
        ]
        for name, type_name, expected_type in cases:
            self.assertIsInstance(self._add_variable_and_get_property(name, type_name), expected_type)

    def test_add_struct_member_variable(self):
        """Ensures that we can add a struct member variable of an arbitrary UStruct type."""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        graph_key = graph.get_path_name()
        BlueprintTools.find_node_types(graph, '')  # populate cache
        self.assertIn(graph_key, _BlueprintCache._graph_node_types)
        BlueprintTools.add_struct_variable(
            self.blueprint, 'MyHitResult', unreal.HitResult.static_struct())
        self.assertNotIn(graph_key, _BlueprintCache._graph_node_types)
        BlueprintTools.compile_blueprint(self.blueprint)
        cdo = unreal.get_default_object(self.blueprint.generated_class())
        self.assertIsInstance(cdo.get_editor_property('MyHitResult'), unreal.HitResult)

    def test_add_struct_local_variable(self):
        """Ensures that we can add a struct local variable to a function graph."""
        graph = BlueprintTools.add_function_graph(self.blueprint, 'MyFunction')
        BlueprintTools.add_struct_variable(
            self.blueprint, 'LocalHitResult', unreal.HitResult.static_struct(), graph=graph)
        self.assertIn('LocalHitResult', BlueprintTools.list_variables(self.blueprint, graph=graph))

    def test_add_struct_function_params(self):
        """Ensures that we can add struct input and output params to a function graph."""
        graph = BlueprintTools.add_function_graph(self.blueprint, 'MyFunction')
        in_pin = BlueprintTools.add_struct_function_param(
            graph, 'MyHitInput', unreal.HitResult.static_struct(), True)
        self.assertIsNotNone(in_pin)
        nodes = BlueprintTools.find_nodes(graph)
        node_info = BlueprintTools._get_node_info(nodes[0])
        self.assertIn('MyHitInput', [p.name for p in node_info.output_pins])
        out_pin = BlueprintTools.add_struct_function_param(
            graph, 'MyHitOutput', unreal.HitResult.static_struct(), False)
        self.assertIsNotNone(out_pin)
        nodes = BlueprintTools.find_nodes(graph)
        node_info = BlueprintTools._get_node_info(nodes[1])
        self.assertIn('MyHitOutput', [p.name for p in node_info.input_pins])

    def test_add_struct_member_variable_duplicate_raises(self):
        """Ensures that adding a struct member variable with a duplicate name raises."""
        BlueprintTools.add_struct_variable(
            self.blueprint, 'MyHitResult', unreal.HitResult.static_struct())
        with self.assertToolRaisesRuntimeError():
            BlueprintTools.add_struct_variable(
                self.blueprint, 'MyHitResult', unreal.HitResult.static_struct())

    def test_add_struct_local_variable_duplicate_raises(self):
        """Ensures that adding a duplicate struct local variable raises."""
        graph = BlueprintTools.add_function_graph(self.blueprint, 'MyFunction')
        BlueprintTools.add_struct_variable(
            self.blueprint, 'LocalHit', unreal.HitResult.static_struct(), graph=graph)
        with self.assertToolRaisesRuntimeError():
            BlueprintTools.add_struct_variable(
                self.blueprint, 'LocalHit', unreal.HitResult.static_struct(), graph=graph)

    def test_add_duplicate_struct_function_params(self):
        """Ensures that adding duplicate struct function params raises."""
        graph = BlueprintTools.add_function_graph(self.blueprint, 'MyFunction')
        BlueprintTools.add_struct_function_param(
            graph, 'MyHitInput', unreal.HitResult.static_struct(), True)
        with self.assertToolRaisesRuntimeError():
            BlueprintTools.add_struct_function_param(
                graph, 'MyHitInput', unreal.HitResult.static_struct(), True)
        BlueprintTools.add_struct_function_param(
            graph, 'MyHitOutput', unreal.HitResult.static_struct(), False)
        with self.assertToolRaisesRuntimeError():
            BlueprintTools.add_struct_function_param(
                graph, 'MyHitOutput', unreal.HitResult.static_struct(), False)

    def test_add_member_object_variable(self):
        """Ensures that we can add an object reference member variable and that it invalidates the cache."""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        graph_key = graph.get_path_name()
        BlueprintTools.find_node_types(graph, '')  # populate cache
        self.assertIn(graph_key, _BlueprintCache._graph_node_types)
        BlueprintTools.add_object_variable(self.blueprint, 'MyActor', unreal.Actor.static_class())
        self.assertNotIn(graph_key, _BlueprintCache._graph_node_types)
        BlueprintTools.compile_blueprint(self.blueprint)
        cdo = unreal.get_default_object(self.blueprint.generated_class())
        self.assertIsNone(cdo.get_editor_property('MyActor'))

    def test_set_variable_instance_editable(self):
        """Ensures that instance editable can be toggled on a member variable."""
        BlueprintTools.add_variable(self.blueprint, 'MyInt', 'int')
        BlueprintTools.set_variable_instance_editable(self.blueprint, 'MyInt', True)
        BlueprintTools.set_variable_instance_editable(self.blueprint, 'MyInt', False)

    def test_set_variable_replication(self):
        """Ensures that replication mode can be set and read back on a member variable."""
        BlueprintTools.add_variable(self.blueprint, 'MyInt', 'int')
        self.assertEqual(
            BlueprintTools.get_variable_replication(self.blueprint, 'MyInt'),
            unreal.BlueprintVariableReplication.NONE)

        BlueprintTools.set_variable_replication(
            self.blueprint, 'MyInt', unreal.BlueprintVariableReplication.REPLICATED)
        self.assertEqual(
            BlueprintTools.get_variable_replication(self.blueprint, 'MyInt'),
            unreal.BlueprintVariableReplication.REPLICATED)

        BlueprintTools.set_variable_replication(
            self.blueprint, 'MyInt', unreal.BlueprintVariableReplication.NONE)
        self.assertEqual(
            BlueprintTools.get_variable_replication(self.blueprint, 'MyInt'),
            unreal.BlueprintVariableReplication.NONE)

    def test_set_variable_replication_rep_notify(self):
        """Ensures that RepNotify creates an OnRep_ function and reads back correctly."""
        BlueprintTools.add_variable(self.blueprint, 'MyInt', 'int')
        BlueprintTools.set_variable_replication(
            self.blueprint, 'MyInt', unreal.BlueprintVariableReplication.REP_NOTIFY)
        self.assertEqual(
            BlueprintTools.get_variable_replication(self.blueprint, 'MyInt'),
            unreal.BlueprintVariableReplication.REP_NOTIFY)
        graph_names = [g.get_name() for g in BlueprintTools.list_graphs(self.blueprint)]
        self.assertIn('OnRep_MyInt', graph_names)

    def test_set_variable_replication_missing(self):
        """Ensures that get/set replication on a missing variable raises."""
        with self.assertToolRaisesRuntimeError():
            BlueprintTools.set_variable_replication(
                self.blueprint, 'DoesNotExist', unreal.BlueprintVariableReplication.REPLICATED)
        with self.assertToolRaisesRuntimeError():
            BlueprintTools.get_variable_replication(self.blueprint, 'DoesNotExist')

    def test_remove_member_variable(self):
        """Ensures that add_variable and remove_variable each invalidate the cache."""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        graph_key = graph.get_path_name()
        BlueprintTools.find_node_types(graph, '')  # populate cache
        self.assertIn(graph_key, _BlueprintCache._graph_node_types)
        BlueprintTools.add_variable(self.blueprint, 'ToRemove', 'int')
        self.assertNotIn(graph_key, _BlueprintCache._graph_node_types)
        BlueprintTools.find_node_types(graph, '')  # repopulate cache
        self.assertIn(graph_key, _BlueprintCache._graph_node_types)
        BlueprintTools.remove_variable(self.blueprint, 'ToRemove')
        self.assertNotIn(graph_key, _BlueprintCache._graph_node_types)

    def test_remove_member_variable_missing(self):
        """Ensures that removing a non-existent member variable raises."""
        with self.assertToolRaisesRuntimeError():
            BlueprintTools.remove_variable(self.blueprint, 'DoesNotExist')

    def test_add_local_variable_types(self):
        """Ensures that we can add local variables of various types."""
        graph = BlueprintTools.add_function_graph(self.blueprint, 'MyFunction')
        for var_name, type_name in [
            ('LocalBool', 'bool'),
            ('LocalInt', 'int'),
            ('LocalFloat', 'float'),
            ('LocalString', 'string'),
            ('LocalVector', 'Vector'),
        ]:
            BlueprintTools.add_variable(self.blueprint, var_name, type_name, graph=graph)
        local_names = BlueprintTools.list_variables(self.blueprint, graph=graph)
        self.assertIn('LocalBool', local_names)
        self.assertIn('LocalInt', local_names)
        self.assertIn('LocalFloat', local_names)
        self.assertIn('LocalString', local_names)
        self.assertIn('LocalVector', local_names)

    def test_add_local_object_variable(self):
        """Ensures that we can add a local object reference variable to a function graph."""
        graph = BlueprintTools.add_function_graph(self.blueprint, 'MyFunction')
        BlueprintTools.add_object_variable(
            self.blueprint, 'LocalActor', unreal.Actor.static_class(), graph=graph)
        self.assertIn('LocalActor', BlueprintTools.list_variables(self.blueprint, graph=graph))

    def test_remove_local_variable(self):
        """Ensures that a local variable can be successfully removed from a function graph."""
        graph = BlueprintTools.add_function_graph(self.blueprint, 'MyFunction')
        BlueprintTools.add_variable(self.blueprint, 'ToRemove', 'int', graph=graph)
        BlueprintTools.remove_variable(self.blueprint, 'ToRemove', graph=graph)
        self.assertNotIn('ToRemove', BlueprintTools.list_variables(self.blueprint, graph=graph))

    def test_remove_local_variable_missing(self):
        """Ensures that removing a non-existent local variable raises."""
        graph = BlueprintTools.add_function_graph(self.blueprint, 'MyFunction')
        with self.assertToolRaisesRuntimeError():
            BlueprintTools.remove_variable(self.blueprint, 'DoesNotExist', graph)

    def test_list_member_variables(self):
        """Ensures that list_variables returns member variables defined on the Blueprint."""
        BlueprintTools.add_variable(self.blueprint, 'MyInt', 'int')
        BlueprintTools.add_variable(self.blueprint, 'MyFloat', 'float')
        names = BlueprintTools.list_variables(self.blueprint)
        self.assertIn('MyInt', names)
        self.assertIn('MyFloat', names)
        self.assertEqual(len(names), 2)

    def test_list_local_variables(self):
        """Ensures that list_variables returns local variables when a graph is provided."""
        graph = BlueprintTools.add_function_graph(self.blueprint, 'MyFunction')
        BlueprintTools.add_variable(self.blueprint, 'LocalInt', 'int', graph=graph)
        BlueprintTools.add_variable(self.blueprint, 'LocalFloat', 'float', graph=graph)
        names = BlueprintTools.list_variables(self.blueprint, graph=graph)
        self.assertIn('LocalInt', names)
        self.assertIn('LocalFloat', names)
        self.assertEqual(len(names), 2)

    def test_get_class_blueprint(self):
        """Ensures get_class returns the generated class for a Blueprint, not the Blueprint class."""
        cls = ObjectTools.get_class(self.blueprint)
        self.assertIsInstance(cls, unreal.Class)
        self.assertEqual(cls, self.blueprint.generated_class())
        # Blueprint's own class is unreal.Blueprint; generated_class() is the Actor subclass
        self.assertNotEqual(cls, self.blueprint.get_class())

    def test_list_properties_blueprint(self):
        """Ensures list_properties returns properties of the generated class for a Blueprint."""
        # The generated class is an Actor subclass, so it should have Actor's properties
        properties_json = ObjectTools.list_properties(self.blueprint)
        properties = json.loads(properties_json)
        self.assertIsInstance(properties, dict)
        self.assertGreater(len(properties), 0)

    def test_get_properties_blueprint(self):
        """Ensures get_properties reads from the Blueprint CDO, not the Blueprint asset itself."""
        BlueprintTools.add_variable(self.blueprint, 'TestFloat', 'float')
        BlueprintTools.compile_blueprint(self.blueprint)
        result = ObjectTools.get_properties(self.blueprint, ['TestFloat'])
        props = json.loads(result)
        self.assertIn('TestFloat', props)

    def test_set_properties_blueprint(self):
        """Ensures set_properties writes to the Blueprint CDO, not the Blueprint asset itself."""
        BlueprintTools.add_variable(self.blueprint, 'TestFloat', 'float')
        BlueprintTools.compile_blueprint(self.blueprint)
        self.assertTrue(ObjectTools.set_properties(self.blueprint, json.dumps({'TestFloat': 42.0})))
        result = ObjectTools.get_properties(self.blueprint, ['TestFloat'])
        props = json.loads(result)
        self.assertEqual(props['TestFloat'], 42.0)

    def _add_variable_and_get_property(self, name: str, type_name: str) -> Any:
        """Helper that adds a member variable and then ensure it appears in properties."""
        assert self.blueprint
        BlueprintTools.add_variable(self.blueprint, name, type_name)
        BlueprintTools.compile_blueprint(self.blueprint)
        return unreal.get_default_object(self.blueprint.generated_class()).get_editor_property(name)

    def test_add_function_graph(self):
        """Ensures that we can add a function graph to a blueprint and that it invalidates the cache."""
        event_graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        event_graph_key = event_graph.get_path_name()
        BlueprintTools.find_node_types(event_graph, '')  # populate cache
        self.assertIn(event_graph_key, _BlueprintCache._graph_node_types)
        graph = BlueprintTools.add_function_graph(self.blueprint, 'MyFunction')
        self.assertNotIn(event_graph_key, _BlueprintCache._graph_node_types)
        self.assertIsNotNone(graph)
        graph = BlueprintTools.get_graph(self.blueprint, 'MyFunction')
        self.assertIsNotNone(graph)
        graphs = BlueprintTools.list_graphs(self.blueprint)
        self.assertIn(graph, graphs)

    def test_remove_function_graph(self):
        """Ensures that we can remove a function graph from a blueprint and that it invalidates the cache."""
        BlueprintTools.add_function_graph(self.blueprint, 'MyFunction')
        event_graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        event_graph_key = event_graph.get_path_name()
        BlueprintTools.find_node_types(event_graph, '')  # populate cache
        self.assertIn(event_graph_key, _BlueprintCache._graph_node_types)
        BlueprintTools.remove_function_graph(self.blueprint, 'MyFunction')
        self.assertNotIn(event_graph_key, _BlueprintCache._graph_node_types)
        graphs = BlueprintTools.list_graphs(self.blueprint)
        graph_names = [g.get_name() for g in graphs]
        self.assertNotIn('MyFunction', graph_names)

    def test_list_graphs(self):
        """Ensures that we can list all graphs in a blueprint."""
        graphs = BlueprintTools.list_graphs(self.blueprint)
        self.assertGreater(len(graphs), 0)
        graph_names = [g.get_name() for g in graphs]
        self.assertIn('EventGraph', graph_names)
        BlueprintTools.add_function_graph(self.blueprint, 'MyFunction')
        graphs = BlueprintTools.list_graphs(self.blueprint)
        graph_names = [g.get_name() for g in graphs]
        self.assertIn('MyFunction', graph_names)

    def test_add_function_param(self):
        """Ensures that we can add an input and output params to a function graph."""
        graph = BlueprintTools.add_function_graph(self.blueprint, 'MyFunction')
        pin = BlueprintTools.add_function_param(graph, 'MyInput', 'float', True)
        self.assertIsNotNone(pin)
        BlueprintTools.set_pin_value(pin, '1.0')
        nodes = BlueprintTools.find_nodes(graph)
        node_info = BlueprintTools._get_node_info(nodes[0])
        self.assertIn('MyInput', [pin_info.name for pin_info in node_info.output_pins])
        self.assertIn('1.0', [pin_info.value for pin_info in node_info.output_pins])
        result_pin = BlueprintTools.add_function_param(graph, 'MyOutput', 'float', False)
        self.assertIsNotNone(result_pin)
        nodes = BlueprintTools.find_nodes(graph)
        node_info = BlueprintTools._get_node_info(nodes[1])
        self.assertIn('MyOutput', [pin_info.name for pin_info in node_info.input_pins])

    def test_remove_function_param(self):
        """Ensures that we can remove an param from a function graph."""
        graph = BlueprintTools.add_function_graph(self.blueprint, 'MyFunction')
        BlueprintTools.add_function_param(graph, 'MyInput', 'float', True)
        BlueprintTools.remove_function_param(graph, 'MyInput', True)
        nodes = BlueprintTools.find_nodes(graph)
        node_info = BlueprintTools._get_node_info(nodes[0])
        self.assertNotIn('MyInput', [pin_info.name for pin_info in node_info.output_pins])
        self.assertNotIn('1.0', [pin_info.value for pin_info in node_info.output_pins])
        BlueprintTools.add_function_param(graph, 'MyOutput', 'float', False)
        BlueprintTools.remove_function_param(graph, 'MyOutput', False)
        nodes = BlueprintTools.find_nodes(graph)
        node_info = BlueprintTools._get_node_info(nodes[1])
        self.assertNotIn('MyOutput', [pin_info.name for pin_info in node_info.input_pins])
        self.assertNotIn('1.0', [pin_info.value for pin_info in node_info.input_pins])

    def test_remove_function_param_missing_raises(self):
        """Ensures that removing a non-existent function param raises."""
        graph = BlueprintTools.add_function_graph(self.blueprint, 'MyFunction')
        with self.assertToolRaisesRuntimeError():
            BlueprintTools.remove_function_param(graph, 'DoesNotExist', True)

    def test_add_object_function_params(self):
        """Ensures that we can add an object reference params to a function graph."""
        graph = BlueprintTools.add_function_graph(self.blueprint, 'MyFunction')
        pin = BlueprintTools.add_object_function_param(graph, 'MyActorInput', unreal.Actor.static_class(), True)
        self.assertIsNotNone(pin)
        nodes = BlueprintTools.find_nodes(graph)
        node_info = BlueprintTools._get_node_info(nodes[0])
        self.assertIn('MyActorInput', [pin_info.name for pin_info in node_info.output_pins])
        self.assertIn('Actor Object Reference', [pin_info.type_id for pin_info in node_info.output_pins])
        pin = BlueprintTools.add_object_function_param(graph, 'MyActorOutput', unreal.Actor.static_class(), False)
        self.assertIsNotNone(pin)
        nodes = BlueprintTools.find_nodes(graph)
        node_info = BlueprintTools._get_node_info(nodes[1])
        self.assertIn('MyActorOutput', [pin_info.name for pin_info in node_info.input_pins])
        self.assertIn('Actor Object Reference', [pin_info.type_id for pin_info in node_info.input_pins])

    def test_add_duplicate_params(self):
        """Ensures that adding duplicate function params raises."""
        graph = BlueprintTools.add_function_graph(self.blueprint, 'MyFunction')
        BlueprintTools.add_function_param(graph, 'MyInput', 'float', True)
        with self.assertToolRaisesRuntimeError():
            BlueprintTools.add_function_param(graph, 'MyInput', 'float', True)
        BlueprintTools.add_function_param(graph, 'MyOutput', 'float', False)
        with self.assertToolRaisesRuntimeError():
            BlueprintTools.add_function_param(graph, 'MyOutput', 'float', False)

    def test_add_duplicate_object_params(self):
        """Ensures that adding duplicate object function params raises."""
        graph = BlueprintTools.add_function_graph(self.blueprint, 'MyFunction')
        BlueprintTools.add_object_function_param(graph, 'MyActorInput', unreal.Actor.static_class(), True)
        with self.assertToolRaisesRuntimeError():
            BlueprintTools.add_object_function_param(graph, 'MyActorInput', unreal.Actor.static_class(), True)
        BlueprintTools.add_object_function_param(graph, 'MyActorOutput', unreal.Actor.static_class(), False)
        with self.assertToolRaisesRuntimeError():
            BlueprintTools.add_object_function_param(graph, 'MyActorOutput', unreal.Actor.static_class(), False)

    def test_add_duplicate_function_graphs(self):
        """Adding a function graph by an existing name returns that graph."""
        first = BlueprintTools.add_function_graph(self.blueprint, 'MyFunction')
        second = BlueprintTools.add_function_graph(self.blueprint, 'MyFunction')
        self.assertEqual(first, second)

    def test_list_events_surfaces_inherited(self):
        """Ensures list_events surfaces inherited BlueprintEvents on the parent class."""
        events = BlueprintTools.list_events(self.blueprint)
        receive_damage = next(
            (e for e in events if str(e.name) == 'ReceiveAnyDamage'), None)
        self.assertIsNotNone(receive_damage)
        self.assertFalse(receive_damage.is_implemented)

    def test_list_functions_returns_info_entries(self):
        """Ensures list_functions returns entries shaped like BlueprintFunctionInfo."""
        functions = BlueprintTools.list_functions(self.blueprint)
        for info in functions:
            self.assertIsInstance(info, unreal.BlueprintFunctionInfo)
            self.assertIsInstance(info.name, unreal.Name)
            self.assertIsInstance(info.is_implemented, bool)

    def test_add_function_graph_event_raises(self):
        """add_function_graph rejects event-shape inherited names with a clear error."""
        events = BlueprintTools.list_events(self.blueprint)
        self.assertIn('ReceiveAnyDamage', {str(e.name) for e in events if not e.is_implemented})
        with self.assertToolRaisesRuntimeError():
            BlueprintTools.add_function_graph(self.blueprint, 'ReceiveAnyDamage')

    def test_add_function_graph_override(self):
        """Ensures a name matching an inherited overridable function produces a function-graph override."""
        functions = BlueprintTools.list_functions(self.blueprint)
        overridable = [f for f in functions if not f.is_implemented]
        if not overridable:
            self.skipTest('No non-event overridable functions on Actor parent class')
        target = str(overridable[0].name)
        graph = BlueprintTools.add_function_graph(self.blueprint, target)
        self.assertIsNotNone(graph)
        self.assertEqual(graph.get_name(), target)
        remaining = BlueprintTools.list_functions(self.blueprint)
        match = next((f for f in remaining if str(f.name) == target), None)
        self.assertIsNotNone(match)
        self.assertTrue(match.is_implemented)

    def test_add_function_graph_override_idempotent(self):
        """Ensures repeated add_function_graph calls on the same overridable return the existing graph."""
        functions = BlueprintTools.list_functions(self.blueprint)
        overridable = [f for f in functions if not f.is_implemented]
        if not overridable:
            self.skipTest('No non-event overridable functions on Actor parent class')
        target = str(overridable[0].name)
        first = BlueprintTools.add_function_graph(self.blueprint, target)
        second = BlueprintTools.add_function_graph(self.blueprint, target)
        self.assertEqual(first, second)

    def test_add_event_inherited_override(self):
        """add_event creates a K2Node_Event override for an inherited event name."""
        node = BlueprintTools.add_event(self.blueprint, 'ReceiveAnyDamage')
        self.assertIsInstance(node, unreal.K2Node_Event)
        self.assertNotIsInstance(node, unreal.K2Node_CustomEvent)
        events = BlueprintTools.list_events(self.blueprint)
        match = next((e for e in events if str(e.name) == 'ReceiveAnyDamage'), None)
        self.assertIsNotNone(match)
        self.assertTrue(match.is_implemented)

    def test_add_event_inherited_override_idempotent(self):
        """Repeated add_event for the same inherited event returns the existing node."""
        first = BlueprintTools.add_event(self.blueprint, 'ReceiveAnyDamage')
        second = BlueprintTools.add_event(self.blueprint, 'ReceiveAnyDamage')
        self.assertEqual(first, second)

    def test_add_event_custom(self):
        """add_event creates a K2Node_CustomEvent when the name is not inherited."""
        node = BlueprintTools.add_event(self.blueprint, 'OnMyCustomEvent')
        self.assertIsInstance(node, unreal.K2Node_CustomEvent)
        self.assertIn('OnMyCustomEvent', node.get_node_title())

    def test_add_event_function_shape_raises(self):
        """add_event refuses inherited function-shape names with a clear error."""
        functions = BlueprintTools.list_functions(self.blueprint)
        overridable = [f for f in functions if not f.is_implemented]
        if not overridable:
            self.skipTest('No non-event overridable functions on Actor parent class')
        target = str(overridable[0].name)
        with self.assertToolRaisesRuntimeError():
            BlueprintTools.add_event(self.blueprint, target)

    def _add_sphere_component(self):
        """Helper that adds a SphereComponent to the test blueprint and returns it."""
        ActorTools.add_component(self.blueprint, unreal.SphereComponent.static_class(), 'TestSphere')
        cdo = BlueprintTools.get_default_object(self.blueprint)
        components = ActorTools.get_components(cdo, unreal.SphereComponent.static_class())
        self.assertEqual(len(components), 1)
        return components[0]

    def test_list_component_events(self):
        """Ensures list_component_events returns delegate events for a component."""
        sphere = self._add_sphere_component()
        events = BlueprintTools.list_component_events(sphere)
        self.assertGreater(len(events), 0)
        self.assertIn(unreal.Name('OnComponentBeginOverlap'), events)
        self.assertIn(unreal.Name('OnComponentEndOverlap'), events)
        self.assertIn(unreal.Name('OnComponentHit'), events)

    def test_add_component_bound_event(self):
        """Ensures add_component_bound_event creates a node in the event graph."""
        sphere = self._add_sphere_component()
        event_graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        node = BlueprintTools.add_component_bound_event(sphere, 'OnComponentBeginOverlap', event_graph)
        self.assertIsNotNone(node)
        nodes = BlueprintTools.find_nodes(event_graph)
        self.assertIn(node, nodes)

    def test_get_parent(self):
        """Ensures get_parent returns the parent class of a Blueprint."""
        parent = BlueprintTools.get_parent(self.blueprint)
        self.assertIsInstance(parent, unreal.Class)
        self.assertEqual(parent, unreal.Actor.static_class())

    def test_set_parent(self):
        """Ensures set_parent reparents the Blueprint to the new class."""
        BlueprintTools.set_parent(self.blueprint, unreal.Pawn.static_class())
        self.assertEqual(BlueprintTools.get_parent(self.blueprint), unreal.Pawn.static_class())

    def test_set_parent_invalid_class_raises(self):
        """Ensures set_parent with an invalid class raises."""
        with self.assertToolRaisesRuntimeError():
            BlueprintTools.set_parent(self.blueprint, None)

    def test_add_component_bound_event_no_duplicate(self):
        """Ensures calling add_component_bound_event twice returns the same node."""
        sphere = self._add_sphere_component()
        event_graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        node1 = BlueprintTools.add_component_bound_event(sphere, 'OnComponentBeginOverlap', event_graph)
        node2 = BlueprintTools.add_component_bound_event(sphere, 'OnComponentBeginOverlap', event_graph)
        self.assertEqual(node1, node2)
        nodes = BlueprintTools.find_nodes(event_graph)
        self.assertEqual(sum(1 for n in nodes if n == node1), 1)

    def test_event_dispatchers(self):
        """Ensures event dispatchers can be added, listed, removed, and that remove_function_graph works."""
        self.assertEqual(BlueprintTools.list_event_dispatchers(self.blueprint), [])
        sig_graph = BlueprintTools.add_event_dispatcher(self.blueprint, 'OnDamaged')
        self.assertIsInstance(sig_graph, unreal.EdGraph)
        self.assertEqual(sig_graph.get_name(), 'OnDamaged')
        BlueprintTools.add_event_dispatcher(self.blueprint, 'OnHealed')
        dispatcher_graphs = BlueprintTools.list_event_dispatchers(self.blueprint)
        dispatcher_names = [g.get_name() for g in dispatcher_graphs]
        self.assertIn('OnDamaged', dispatcher_names)
        self.assertIn('OnHealed', dispatcher_names)
        with self.assertToolRaisesRuntimeError():
            BlueprintTools.add_event_dispatcher(self.blueprint, 'OnDamaged')
        BlueprintTools.remove_function_graph(self.blueprint, 'OnDamaged')
        self.assertNotIn('OnDamaged', [g.get_name() for g in BlueprintTools.list_event_dispatchers(self.blueprint)])
        with self.assertToolRaisesRuntimeError():
            BlueprintTools.remove_function_graph(self.blueprint, 'OnDamaged')
        BlueprintTools.compile_blueprint(self.blueprint)

    def test_dispatcher_parameters(self):
        """Ensures parameters can be added/removed on a dispatcher via the graph API."""
        def param_names(graph):
            info = BlueprintTools.get_node_infos(BlueprintTools.find_nodes(graph))
            return [p.name for p in info[0].output_pins if p.name != 'then']

        sig_graph = BlueprintTools.add_event_dispatcher(self.blueprint, 'OnDamaged')
        self.assertEqual(param_names(sig_graph), [])
        BlueprintTools.add_function_param(sig_graph, 'Amount', 'int', True)
        BlueprintTools.add_function_param(sig_graph, 'Location', 'Vector', True)
        BlueprintTools.add_struct_function_param(sig_graph, 'Hit', unreal.HitResult.static_struct(), True)
        BlueprintTools.add_object_function_param(sig_graph, 'Target', unreal.Actor.static_class(), True)
        params = param_names(sig_graph)
        self.assertIn('Amount', params)
        self.assertIn('Location', params)
        self.assertIn('Hit', params)
        self.assertIn('Target', params)
        with self.assertToolRaisesRuntimeError():
            BlueprintTools.add_function_param(sig_graph, 'Amount', 'int', True)
        with self.assertToolRaisesRuntimeError():
            BlueprintTools.add_function_param(sig_graph, 'Out', 'int', False)
        BlueprintTools.remove_function_param(sig_graph, 'Amount', True)
        self.assertNotIn('Amount', param_names(sig_graph))
        with self.assertToolRaisesRuntimeError():
            BlueprintTools.remove_function_param(sig_graph, 'Amount', True)
        BlueprintTools.compile_blueprint(self.blueprint)

    def test_dispatcher_event_node(self):
        """Ensures a dispatcher event node can be created via create_node and the BP compiles."""
        sig_graph = BlueprintTools.add_event_dispatcher(self.blueprint, 'OnDamaged')
        BlueprintTools.add_function_param(sig_graph, 'Amount', 'int', True)
        BlueprintTools.compile_blueprint(self.blueprint)
        event_graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        node = BlueprintTools.create_node(event_graph, 'Default|EventDispatcherOnDamaged', unreal.IntPoint(0, 0))
        self.assertIsInstance(node, unreal.EdGraphNode)
        BlueprintTools.compile_blueprint(self.blueprint)
        with self.assertToolRaisesRuntimeError():
            BlueprintTools.create_node(event_graph, 'Default|EventDispatcherNoSuch', unreal.IntPoint(0, 0))
        # Dispatcher appears in find_node_types
        node_types = BlueprintTools.find_node_types(event_graph, 'EventDispatcher')
        self.assertIn('Default|EventDispatcherOnDamaged', node_types)

    def test_create_node_named_custom_event(self):
        """Ensures 'AddEvent|Custom|<name>' creates a custom event with that name."""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        node = BlueprintTools.create_node(graph, 'AddEvent|Custom|OnMyCustomEvent', unreal.IntPoint(100, 100))
        self.assertIsInstance(node, unreal.K2Node_CustomEvent)
        self.assertIn('OnMyCustomEvent', node.get_node_title())
        self.assertEqual(BlueprintTools._get_node_info(node).type_id, 'AddEvent|Custom|OnMyCustomEvent')
        BlueprintTools.compile_blueprint(self.blueprint)

    def test_create_node_default_custom_event(self):
        """Ensures the action database's 'Add Custom Event...' spawner creates a default-named custom event."""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        node = BlueprintTools.create_node(graph, 'AddEvent|AddCustomEvent...', unreal.IntPoint(100, 100))
        self.assertIsInstance(node, unreal.K2Node_CustomEvent)
        BlueprintTools.compile_blueprint(self.blueprint)

    def test_create_node_inherited_event_override(self):
        """Ensures an inherited event installs as an override event node, not a custom event."""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        node = BlueprintTools.create_node(graph, 'AddEvent|EventBeginPlay', unreal.IntPoint(100, 100))
        self.assertIsInstance(node, unreal.K2Node_Event)
        self.assertNotIsInstance(node, unreal.K2Node_CustomEvent)
        self.assertIn('BeginPlay', node.get_node_title())
        self.assertEqual(BlueprintTools._get_node_info(node).type_id, 'AddEvent|EventBeginPlay')

    def test_create_node_declaring_class_function(self):
        """declaring_class picks the correct Blueprint function when siblings share the same name."""
        self.sibling_blueprint = BlueprintTools.create(self.test_folder, 'SiblingBP', unreal.Actor.static_class())
        BlueprintTools.add_function_graph(self.blueprint, 'SharedFunc')
        BlueprintTools.compile_blueprint(self.blueprint)
        BlueprintTools.add_function_graph(self.sibling_blueprint, 'SharedFunc')
        BlueprintTools.compile_blueprint(self.sibling_blueprint)
        event_graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        # Discover the actual type_id - the category prefix varies by blueprint structure
        matching = BlueprintTools.find_node_types(event_graph, 'SharedFunc')
        self.assertGreater(len(matching), 0, f'No type_id found for SharedFunc; available: {matching}')
        type_id = matching[0]
        node = BlueprintTools.create_node(
            event_graph, type_id, unreal.IntPoint(0, 0),
            declaring_class=self.blueprint.generated_class())
        self.assertIsInstance(node, unreal.EdGraphNode)
        BlueprintTools.compile_blueprint(self.blueprint)

    def test_create_node_declaring_class_wrong_class_raises(self):
        """declaring_class filters out functions not owned by that class, causing a RuntimeError."""
        self.sibling_blueprint = BlueprintTools.create(self.test_folder, 'SiblingBP', unreal.Actor.static_class())
        BlueprintTools.add_function_graph(self.sibling_blueprint, 'BOnlyFunc')
        BlueprintTools.compile_blueprint(self.sibling_blueprint)
        event_graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        # Discover the type_id for BOnlyFunc visible from self.blueprint's context
        matching = BlueprintTools.find_node_types(event_graph, 'BOnlyFunc')
        self.assertGreater(len(matching), 0, 'BOnlyFunc not visible in event graph context')
        type_id = matching[0]
        # self.blueprint has no BOnlyFunc - the declaring_class filter excludes bp_b's version
        with self.assertToolRaisesRuntimeError():
            BlueprintTools.create_node(
                event_graph, type_id, unreal.IntPoint(0, 0),
                declaring_class=self.blueprint.generated_class())

    def test_create_node_declaring_class_delegate(self):
        """declaring_class picks the correct delegate Call node when siblings share the same dispatcher."""
        self.sibling_blueprint = BlueprintTools.create(self.test_folder, 'SiblingBP', unreal.Actor.static_class())
        BlueprintTools.add_event_dispatcher(self.blueprint, 'SharedDelegate')
        BlueprintTools.compile_blueprint(self.blueprint)
        BlueprintTools.add_event_dispatcher(self.sibling_blueprint, 'SharedDelegate')
        BlueprintTools.compile_blueprint(self.sibling_blueprint)
        event_graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        node = BlueprintTools.create_node(
            event_graph, 'Default|CallSharedDelegate', unreal.IntPoint(0, 0),
            declaring_class=self.blueprint.generated_class())
        self.assertIsInstance(node, unreal.EdGraphNode)
        BlueprintTools.compile_blueprint(self.blueprint)

    def test_retarget_node_class(self):
        """retarget_node_class updates a supported node's class reference in place."""
        event_graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        cast_types = BlueprintTools.find_node_types(event_graph, 'CastToActor')
        self.assertGreater(len(cast_types), 0, 'No CastToActor node type found')
        cast_node = BlueprintTools.create_node(
            event_graph, cast_types[0], unreal.IntPoint(0, 0))
        BlueprintTools.retarget_node_class(
            cast_node, unreal.Actor.static_class(), unreal.Pawn.static_class())
        self.assertIn('Pawn', BlueprintTools._get_node_info(cast_node).type_id)

    def test_retarget_node_class_unsupported_raises(self):
        """retarget_node_class raises for node types that don't carry a class reference."""
        event_graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        macro_node = BlueprintTools.create_node(
            event_graph, 'Utilities|FlowControl|ForLoop', unreal.IntPoint(0, 0))
        with self.assertToolRaisesRuntimeError():
            BlueprintTools.retarget_node_class(
                macro_node, unreal.Actor.static_class(), unreal.Pawn.static_class())

    def test_retarget_node_class_wrong_old_class_raises(self):
        """retarget_node_class raises when old_class doesn't match the node's current class."""
        event_graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        cast_types = BlueprintTools.find_node_types(event_graph, 'CastToActor')
        self.assertGreater(len(cast_types), 0, 'No CastToActor node type found')
        cast_node = BlueprintTools.create_node(
            event_graph, cast_types[0], unreal.IntPoint(0, 0))
        with self.assertToolRaisesRuntimeError():
            BlueprintTools.retarget_node_class(
                cast_node, unreal.Pawn.static_class(), unreal.Character.static_class())

    def _make_connected_create_event_node(self, event_graph):
        """Helper: returns (create_event_node, set_timer_node) with OutputDelegate connected."""
        create_event_node = BlueprintTools.create_node(
            event_graph, 'EventDispatchers|CreateEvent', unreal.IntPoint(0, 0))
        set_timer_node = BlueprintTools.create_node(
            event_graph, 'Utilities|Time|SetTimerbyEvent', unreal.IntPoint(300, 0))
        output_delegate_pin = next(
            p for p in BlueprintTools._get_node_info(create_event_node).output_pins
            if p.name == 'OutputDelegate')
        delegate_input_pin = next(
            p for p in BlueprintTools._get_node_info(set_timer_node).input_pins
            if p.name == 'Delegate')
        BlueprintTools.connect_pins(output_delegate_pin.pin_id, delegate_input_pin.pin_id)
        return create_event_node, set_timer_node

    def test_create_event_node(self):
        """Ensures Create Event nodes can be connected, listed, bound, and compiled."""
        BlueprintTools.compile_blueprint(self.blueprint)
        event_graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        create_event_node, _ = self._make_connected_create_event_node(event_graph)

        compatible = BlueprintTools.list_compatible_event_functions(create_event_node)
        self.assertIn('TearOff', compatible)

        self.assertEqual(BlueprintTools.get_create_event_function(create_event_node), '')
        BlueprintTools.set_create_event_function(create_event_node, 'TearOff')
        self.assertEqual(BlueprintTools.get_create_event_function(create_event_node), 'TearOff')

        BlueprintTools.compile_blueprint(self.blueprint)

    def test_create_event_node_list_and_set_raise_when_unconnected(self):
        """Ensures Create Event tools raise when OutputDelegate is not connected."""
        BlueprintTools.compile_blueprint(self.blueprint)
        event_graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        create_event_node = BlueprintTools.create_node(
            event_graph, 'EventDispatchers|CreateEvent', unreal.IntPoint(0, 0))

        with self.assertToolRaisesRuntimeError():
            BlueprintTools.list_compatible_event_functions(create_event_node)

    def test_create_event_node_invalid_raises(self):
        """Ensures set_create_event_function raises for an incompatible function name."""
        BlueprintTools.compile_blueprint(self.blueprint)
        event_graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        create_event_node, _ = self._make_connected_create_event_node(event_graph)

        with self.assertToolRaisesRuntimeError():
            BlueprintTools.set_create_event_function(create_event_node, 'NotAFunction')

    def test_find_nodes_by_title(self):
        """Ensures find_nodes returns nodes whose title contains the given substring."""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        BlueprintTools.create_node(graph, 'Development|PrintString', unreal.IntPoint(0, 0))
        results = BlueprintTools.find_nodes(graph, title='print')
        titles = [n.get_node_title().lower() for n in results]
        self.assertTrue(all('print' in t for t in titles))
        self.assertGreater(len(results), 0)

    def test_find_nodes_by_class(self):
        """Ensures find_nodes returns only nodes of the given class and its subclasses."""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        BlueprintTools.create_node(graph, 'Development|PrintString', unreal.IntPoint(0, 0))
        results = BlueprintTools.find_nodes(graph, node_class=unreal.K2Node_Event.static_class())
        self.assertGreater(len(results), 0)
        for node in results:
            self.assertIsInstance(node, unreal.K2Node_Event)
        # PrintString is not an event node and must be absent
        non_event_titles = [
            n.get_node_title() for n in BlueprintTools.find_nodes(graph)
            if not isinstance(n, unreal.K2Node_Event)
        ]
        result_titles = [n.get_node_title() for n in results]
        for title in non_event_titles:
            self.assertNotIn(title, result_titles)

    def test_find_nodes_combined_filters(self):
        """Ensures find_nodes ANDs the title and class filters."""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        event_nodes = BlueprintTools.find_nodes(graph, node_class=unreal.K2Node_Event.static_class())
        self.assertGreater(len(event_nodes), 1)
        first_title = event_nodes[0].get_node_title()
        results = BlueprintTools.find_nodes(
            graph, title=first_title, node_class=unreal.K2Node_Event.static_class())
        self.assertEqual(len(results), 1)
        self.assertEqual(results[0].get_node_title(), first_title)

    def test_find_nodes_no_match(self):
        """Ensures find_nodes returns an empty list when nothing matches."""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        results = BlueprintTools.find_nodes(graph, title='zzznomatch')
        self.assertEqual(results, [])

    def test_find_nodes_entry_points_event_graph(self):
        """Ensures find_nodes with entry_points_only returns only event nodes in the event graph."""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        BlueprintTools.create_node(graph, 'Development|PrintString', unreal.IntPoint(0, 0))
        results = BlueprintTools.find_nodes(graph, entry_points_only=True)
        self.assertGreater(len(results), 0)
        for node in results:
            self.assertIsInstance(node, unreal.K2Node_Event)

    def test_find_nodes_entry_points_function_graph(self):
        """Ensures find_nodes with entry_points_only returns the single function entry node."""
        func_graph = BlueprintTools.add_function_graph(self.blueprint, 'MyFunction')
        results = BlueprintTools.find_nodes(func_graph, entry_points_only=True)
        self.assertEqual(len(results), 1)
        self.assertIsInstance(results[0], unreal.K2Node_FunctionEntry)

    def test_get_connected_subgraph(self):
        """Ensures get_connected_subgraph returns only nodes reachable from the given node."""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        event_nodes = BlueprintTools.find_nodes(graph, node_class=unreal.K2Node_Event.static_class())
        self.assertGreaterEqual(len(event_nodes), 2)
        first_event = event_nodes[0]
        second_event = event_nodes[1]
        # Connect a PrintString to the first event only.
        print_node = BlueprintTools.create_node(graph, 'Development|PrintString', unreal.IntPoint(300, 0))
        exec_out = BlueprintTools._get_node_info(first_event).output_pins[1].pin_id
        exec_in = BlueprintTools._get_node_info(print_node).input_pins[0].pin_id
        BlueprintTools.connect_pins(exec_out, exec_in)
        # First event's component should contain both nodes.
        first_subgraph = BlueprintTools.get_connected_subgraph(first_event)
        first_nodes = [info.node for info in first_subgraph]
        self.assertIn(first_event, first_nodes)
        self.assertIn(print_node, first_nodes)
        # Second event is isolated â€” print_node must not appear.
        second_subgraph = BlueprintTools.get_connected_subgraph(second_event)
        second_nodes = [info.node for info in second_subgraph]
        self.assertIn(second_event, second_nodes)
        self.assertNotIn(print_node, second_nodes)

    def test_get_connected_subgraph_isolated_node(self):
        """Ensures get_connected_subgraph on an unconnected node returns only that node."""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        node = BlueprintTools.create_node(graph, 'Development|PrintString', unreal.IntPoint(0, 0))
        result = BlueprintTools.get_connected_subgraph(node)
        self.assertEqual(len(result), 1)
        self.assertEqual(result[0].node, node)

    def test_add_array_member_variable(self):
        """Ensures add_variable with container_type=ARRAY creates an array-typed member variable."""
        BlueprintTools.add_variable(self.blueprint, 'MyIntArray', 'int', container_type=ContainerType.ARRAY)
        BlueprintTools.compile_blueprint(self.blueprint)
        cdo = unreal.get_default_object(self.blueprint.generated_class())
        self.assertIsInstance(cdo.get_editor_property('MyIntArray'), unreal.Array)

    def test_add_array_struct_member_variable(self):
        """Ensures add_struct_variable with container_type=ARRAY creates an array of struct."""
        BlueprintTools.add_struct_variable(
            self.blueprint, 'MyHitArray', unreal.HitResult.static_struct(), container_type=ContainerType.ARRAY)
        BlueprintTools.compile_blueprint(self.blueprint)
        cdo = unreal.get_default_object(self.blueprint.generated_class())
        self.assertIsInstance(cdo.get_editor_property('MyHitArray'), unreal.Array)

    def test_add_array_object_member_variable(self):
        """Ensures add_object_variable with container_type=ARRAY creates an array of object references."""
        BlueprintTools.add_object_variable(
            self.blueprint, 'MyActorArray', unreal.Actor.static_class(), container_type=ContainerType.ARRAY)
        BlueprintTools.compile_blueprint(self.blueprint)
        cdo = unreal.get_default_object(self.blueprint.generated_class())
        self.assertIsInstance(cdo.get_editor_property('MyActorArray'), unreal.Array)

    def test_add_array_function_param(self):
        """Ensures add_function_param with container_type=ARRAY creates an array input parameter."""
        graph = BlueprintTools.add_function_graph(self.blueprint, 'MyFunction')
        pin = BlueprintTools.add_function_param(graph, 'MyIntArray', 'int', True, container_type=ContainerType.ARRAY)
        self.assertIsNotNone(pin)
        node_info = BlueprintTools._get_node_info(BlueprintTools.find_nodes(graph)[0])
        pin_names = [p.name for p in node_info.output_pins]
        self.assertIn('MyIntArray', pin_names)
        type_id = next(p.type_id for p in node_info.output_pins if p.name == 'MyIntArray')
        self.assertIn('Array', type_id)

    def test_add_array_struct_function_param(self):
        """Ensures add_struct_function_param with container_type=ARRAY creates an array of struct params."""
        graph = BlueprintTools.add_function_graph(self.blueprint, 'MyFunction')
        pin = BlueprintTools.add_struct_function_param(
            graph, 'MyHitArray', unreal.HitResult.static_struct(), True, container_type=ContainerType.ARRAY)
        self.assertIsNotNone(pin)
        node_info = BlueprintTools._get_node_info(BlueprintTools.find_nodes(graph)[0])
        pin_names = [p.name for p in node_info.output_pins]
        self.assertIn('MyHitArray', pin_names)
        type_id = next(p.type_id for p in node_info.output_pins if p.name == 'MyHitArray')
        self.assertIn('Array', type_id)

    def test_add_array_object_function_param(self):
        """Ensures add_object_function_param with container_type=ARRAY creates an array of object ref params."""
        graph = BlueprintTools.add_function_graph(self.blueprint, 'MyFunction')
        pin = BlueprintTools.add_object_function_param(
            graph, 'MyActorArray', unreal.Actor.static_class(), True, container_type=ContainerType.ARRAY)
        self.assertIsNotNone(pin)
        node_info = BlueprintTools._get_node_info(BlueprintTools.find_nodes(graph)[0])
        pin_names = [p.name for p in node_info.output_pins]
        self.assertIn('MyActorArray', pin_names)
        type_id = next(p.type_id for p in node_info.output_pins if p.name == 'MyActorArray')
        self.assertIn('Array', type_id)

    def test_add_set_member_variable(self):
        """Ensures add_variable with container_type=SET creates a set-typed member variable."""
        BlueprintTools.add_variable(self.blueprint, 'MyIntSet', 'int', container_type=ContainerType.SET)
        BlueprintTools.compile_blueprint(self.blueprint)
        cdo = unreal.get_default_object(self.blueprint.generated_class())
        self.assertIsInstance(cdo.get_editor_property('MyIntSet'), unreal.Set)

    def test_add_map_member_variable(self):
        """Ensures add_variable with container_type=MAP creates a string-keyed map variable."""
        BlueprintTools.add_variable(self.blueprint, 'MyIntMap', 'int', container_type=ContainerType.MAP)
        BlueprintTools.compile_blueprint(self.blueprint)
        cdo = unreal.get_default_object(self.blueprint.generated_class())
        self.assertIsInstance(cdo.get_editor_property('MyIntMap'), unreal.Map)

    def test_add_set_function_param(self):
        """Ensures add_function_param with container_type=SET creates a set input parameter."""
        graph = BlueprintTools.add_function_graph(self.blueprint, 'MyFunction')
        pin = BlueprintTools.add_function_param(graph, 'MyIntSet', 'int', True, container_type=ContainerType.SET)
        self.assertIsNotNone(pin)
        node_info = BlueprintTools._get_node_info(BlueprintTools.find_nodes(graph)[0])
        type_id = next(p.type_id for p in node_info.output_pins if p.name == 'MyIntSet')
        self.assertIn('Set', type_id)

    def test_add_map_function_param(self):
        """Ensures add_function_param with container_type=MAP creates a map input parameter."""
        graph = BlueprintTools.add_function_graph(self.blueprint, 'MyFunction')
        pin = BlueprintTools.add_function_param(graph, 'MyIntMap', 'int', True, container_type=ContainerType.MAP)
        self.assertIsNotNone(pin)
        node_info = BlueprintTools._get_node_info(BlueprintTools.find_nodes(graph)[0])
        type_id = next(p.type_id for p in node_info.output_pins if p.name == 'MyIntMap')
        self.assertIn('Map', type_id)

    def test_find_assets_blueprint_class_filter(self):
        """Ensures find_assets returns Blueprint assets when filtering by the generated class.

        asset_data.get_class() returns UBlueprint for all Blueprint assets rather than
        the Blueprint's generated class, so find_assets must use ObjectTools.get_class()
        to resolve the generated class before applying the type filter.
        """
        blueprint_path = f'{self.test_folder}TestBlueprint'
        results = AssetTools.find_assets(self.test_folder, asset_type=unreal.Actor.static_class())
        self.assertIn(blueprint_path, results)

    def test_arrange_nodes(self):
        """Ensures arrange_nodes separates overlapping nodes by at least ROW_PADDING vertically
        and COL_PADDING horizontally when connected."""
        event_graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        origin = unreal.IntPoint(0, 0)
        node_a = BlueprintTools.create_node(event_graph, 'Development|PrintString', origin)
        node_b = BlueprintTools.create_node(event_graph, 'Development|PrintString', origin)
        node_c = BlueprintTools.create_node(event_graph, 'Development|PrintString', origin)
        BlueprintTools.connect_pins(
            BlueprintTools._get_node_info(node_a).output_pins[0].pin_id,
            BlueprintTools._get_node_info(node_b).input_pins[0].pin_id,
        )
        all_nodes = BlueprintTools.find_nodes(event_graph)
        for node in all_nodes:
            BlueprintTools.set_node_position(node, origin)
        BlueprintTools.arrange_nodes(all_nodes)
        for i, node_i in enumerate(all_nodes):
            for node_j in all_nodes[i + 1:]:
                pos_i = BlueprintTools._get_node_info(node_i).position
                pos_j = BlueprintTools._get_node_info(node_j).position
                self.assertTrue(
                    abs(pos_i.x - pos_j.x) >= GraphFormatter.COL_PADDING or
                    abs(pos_i.y - pos_j.y) >= GraphFormatter.ROW_PADDING
                )

    def test_get_node_type_pins_valid(self):
        """get_node_type_pins returns pin info for a known node type."""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        info = BlueprintTools.get_node_type_pins(graph, 'Development|PrintString')
        input_names = [p.name for p in info.input_pins]
        output_names = [p.name for p in info.output_pins]
        self.assertIn('InString', input_names)
        self.assertIn('then', output_names)

    def test_get_node_type_pins_invalid_raises(self):
        """get_node_type_pins raises for an unknown node type."""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        with self.assertToolRaisesRuntimeError():
            BlueprintTools.get_node_type_pins(graph, 'NoSuchNode|Invalid')

    def test_add_and_remove_node_pin(self):
        """add_node_pin returns the new pin's PinID; remove_node_pin removes it."""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        node = BlueprintTools.create_node(
            graph, 'Utilities|FlowControl|Sequence', unreal.IntPoint(0, 0))
        pins_before = BlueprintTools._get_node_info(node).output_pins
        new_pin_id = BlueprintTools.add_node_pin(node)
        pins_after = BlueprintTools._get_node_info(node).output_pins
        self.assertEqual(len(pins_after), len(pins_before) + 1)
        new_pin_name = next(p.name for p in pins_after if p.name not in {p.name for p in pins_before})
        self.assertEqual(new_pin_id.index_id, next(i for i, p in enumerate(pins_after) if p.name == new_pin_name))
        BlueprintTools.remove_node_pin(node, new_pin_id)
        pins_final = BlueprintTools._get_node_info(node).output_pins
        self.assertEqual(len(pins_final), len(pins_before))
        self.assertNotIn(new_pin_name, {p.name for p in pins_final})

    def test_write_graph_dsl_creates_nodes(self):
        """write_graph_dsl adds nodes to the event graph from DSL code."""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        BlueprintTools.write_graph_dsl(graph, '(event Custom|MyEvent\n  (Development|PrintString "Hello"))')
        type_ids = [BlueprintTools._get_node_info(n).type_id for n in BlueprintTools.find_nodes(graph)]
        self.assertIn('AddEvent|Custom|MyEvent', type_ids)
        self.assertIn('Development|PrintString', type_ids)

    def test_write_graph_dsl_replaces_stale_nodes(self):
        """write_graph_dsl removes old nodes when an event is rewritten."""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        BlueprintTools.write_graph_dsl(graph, '(event Custom|MyEvent\n  (Development|PrintString "Hello"))')
        BlueprintTools.write_graph_dsl(graph, '(event Custom|MyEvent\n  (Utilities|FlowControl|ForLoop 0 1))')
        type_ids = [BlueprintTools._get_node_info(n).type_id for n in BlueprintTools.find_nodes(graph)]
        self.assertNotIn('Development|PrintString', type_ids)
        self.assertIn('Utilities|FlowControl|ForLoop', type_ids)

    def test_write_graph_dsl_invalid_code_raises_and_restores(self):
        """write_graph_dsl raises on invalid code and leaves the graph unchanged."""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        BlueprintTools.write_graph_dsl(graph, '(event Custom|MyEvent\n  (Development|PrintString "Hello"))')
        nodes_before = {n.get_path_name() for n in BlueprintTools.find_nodes(graph)}
        with self.assertToolRaisesRuntimeError():
            BlueprintTools.write_graph_dsl(graph, '(event Custom|MyEvent\n  (NoSuchNode|Invalid))')
        nodes_after = {n.get_path_name() for n in BlueprintTools.find_nodes(graph)}
        self.assertEqual(nodes_before, nodes_after)

    def test_write_graph_dsl_orphaned_nodes_raise(self):
        """write_graph_dsl silently removes pre-existing orphaned nodes."""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        orphan = BlueprintTools.create_node(graph, 'Development|PrintString', unreal.IntPoint(0, 0))
        orphan_path = orphan.get_path_name()
        BlueprintTools.write_graph_dsl(graph, '(event Custom|MyEvent\n  (Development|PrintString "Hello"))')
        remaining = {n.get_path_name() for n in BlueprintTools.find_nodes(graph)}
        self.assertNotIn(orphan_path, remaining)

    def test_read_graph_dsl_returns_code(self):
        """read_graph_dsl returns DSL code representing the written events and nodes."""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        BlueprintTools.write_graph_dsl(graph, '(event Custom|MyEvent\n  (Development|PrintString "Hello"))')
        code = BlueprintTools.read_graph_dsl(graph)
        self.assertIn('Custom|MyEvent', code)
        self.assertIn('Development|PrintString', code)

    def test_write_graph_dsl_regular_event_creates_override(self):
        """write_graph_dsl with a built-in event name creates a K2Node_Event override."""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        BlueprintTools.write_graph_dsl(graph, '(event EventBeginPlay\n  (Development|PrintString "Init"))')
        nodes = BlueprintTools.find_nodes(graph)
        event_nodes = [n for n in nodes if isinstance(n, unreal.K2Node_Event)]
        self.assertTrue(any('BeginPlay' in n.get_node_title() for n in event_nodes))

    def test_read_graph_dsl_round_trips_regular_event(self):
        """read_graph_dsl preserves the event name for a built-in event override."""
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')
        BlueprintTools.write_graph_dsl(graph, '(event EventBeginPlay\n  (Development|PrintString "Init"))')
        code = BlueprintTools.read_graph_dsl(graph)
        self.assertIn('EventBeginPlay', code)
        self.assertNotIn('Custom|', code)

    def test_write_read_dsl_comprehensive(self):
        """write_graph_dsl + read_graph_dsl exercises the major DSL features:
        if (then-only), for range, and bind+exec-cont (cast).

        Uses bind+exec-cont form on the cast to exercise the new feature.
        The decompiler emits a canonical form (without the explicit bind name),
        which is verified by exact structural assertions and an idempotency
        check: re-writing the decompiled output must produce identical output.
        """
        graph = BlueprintTools.get_graph(self.blueprint, 'EventGraph')

        cast_types = BlueprintTools.find_node_types(graph, 'CastToActor')
        self.assertGreater(len(cast_types), 0, 'No CastToActor node type found')
        cast_type = cast_types[0]

        # Use bind+exec-cont form with 'actor' referenced in the :then body,
        # which exercises the data wire from bind_name to the continuation.
        # The if condition uses (== 1 1) to exercise expression evaluation.
        dsl = (
            '(event Custom|TestDSL\n'
            '  (if (== 1 1)\n'
            '    (for _ (range 3)\n'
            '      (Development|PrintString "loop")))\n'
            f'  (bind actor ({cast_type} self)\n'
            '    (:then\n'
            '      (Development|PrintString actor))\n'
            '    (:CastFailed\n'
            '      (Development|PrintString "cast failed"))))'
        )

        BlueprintTools.write_graph_dsl(graph, dsl)
        code = BlueprintTools.read_graph_dsl(graph)

        # read_graph_dsl returns all events; isolate the one we wrote.
        test_block = next(
            (b.strip() for b in code.split('\n\n') if 'Custom|TestDSL' in b), None)
        self.assertIsNotNone(test_block, 'Custom|TestDSL event not found in decompiled output')

        # Assert the exact canonical form the decompiler must produce:
        # - (== 1 1) maps to the engine integer-equal node type
        # - bind+exec-cont round-trips as (bind _asactor (...)) since the data
        #   output is used; _asactor is "As Actor" sanitized (spaces stripped)
        # - (range 3) is canonical when FirstIndex == 0
        expected = (
            '(event Custom|TestDSL\n'
            '  (if (== 1 1)\n'
            '    (for _ (range 3)\n'
            '      (Development|PrintString "loop")))\n'
            f'  (bind _asactor ({cast_type} self)\n'
            '    (:then\n'
            '      (Development|PrintString (Utilities|GetDisplayName _asactor)))\n'
            '    (:CastFailed\n'
            '      (Development|PrintString "cast failed"))))'
        )
        self.assertEqual(test_block, expected)

        # Idempotency: re-writing the canonical form must produce identical output.
        BlueprintTools.write_graph_dsl(graph, test_block)
        code2 = BlueprintTools.read_graph_dsl(graph)
        test_block2 = next(
            (b.strip() for b in code2.split('\n\n') if 'Custom|TestDSL' in b), None)
        self.assertEqual(test_block, test_block2)

