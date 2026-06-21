# Copyright Epic Games, Inc. All Rights Reserved.

from contextlib import ExitStack
import unittest

import unreal

from toolset_registry.tests.automation import create_temp_folder
from animation_toolset.toolsets.controlrig import ControlRigTools, EventType


class ControlRigToolsTestCase(unittest.TestCase):
    """Test ControlRigTools toolset."""

    def setUp(self):
        super().setUp()
        self._stack = ExitStack()
        test_folder = self._stack.enter_context(create_temp_folder())
        self.control_rig = ControlRigTools.create(f'{test_folder}TestControlRig')

    def tearDown(self) -> None:
        self.control_rig = None
        self._stack.close()
        super().tearDown()

    def test_create(self):
        """Ensures that we can create a Control Rig asset."""
        self.assertIsInstance(self.control_rig, unreal.ControlRigBlueprint)

    def test_get_forward_solve_graph(self):
        """Ensures that we can get the forward solve graph."""
        graph = ControlRigTools.get_forward_solve_graph(self.control_rig)
        self.assertIsInstance(graph, unreal.RigVMGraph)

    def test_list_graphs(self):
        """Ensures that we can list all graphs in a Control Rig."""
        graphs = ControlRigTools.list_graphs(self.control_rig)
        self.assertGreaterEqual(len(graphs), 1)

    def test_add_graph(self):
        """Ensures that we can add a new graph."""
        graph = ControlRigTools.add_graph(self.control_rig, 'TestGraph')
        self.assertIsInstance(graph, unreal.RigVMGraph)

    def test_get_graph(self):
        """Ensures that we can get a graph by name."""
        graph = ControlRigTools.get_graph(self.control_rig, 'RigVMModel')
        self.assertIsInstance(graph, unreal.RigVMGraph)

    def test_get_graph_not_found(self):
        """Ensures that getting a non-existent graph returns None."""
        result = ControlRigTools.get_graph(self.control_rig, 'NonExistentGraph')
        self.assertIsNone(result)

    def test_add_backward_solve_graph(self):
        """Ensures that we can add a backward solve graph with InverseExecution event."""
        graph = ControlRigTools.add_backward_solve_graph(self.control_rig)
        self.assertIsInstance(graph, unreal.RigVMGraph)
        self.assertTrue(self._graph_has_event_node(graph, 'RigUnit_InverseExecution'))

    def test_add_interaction_graph(self):
        """Ensures that we can add an interaction graph with InteractionExecution event."""
        graph = ControlRigTools.add_interaction_graph(self.control_rig)
        self.assertIsInstance(graph, unreal.RigVMGraph)
        self.assertTrue(self._graph_has_event_node(graph, 'RigUnit_InteractionExecution'))

    def test_add_event_graph_rejects_forward_solve(self):
        """Ensures that add_event_graph rejects FORWARD_SOLVE event type."""
        # The @tool_call decorator converts exceptions to script errors and returns None
        result = ControlRigTools.add_event_graph(self.control_rig, EventType.FORWARD_SOLVE)
        self.assertIsNone(result)

    def test_create_node(self):
        """Ensures that we can create a node in a graph."""
        graph = ControlRigTools.get_forward_solve_graph(self.control_rig)
        node = ControlRigTools.create_node(self.control_rig, graph, 'RigUnit_GetTransform')
        self.assertIsInstance(node, unreal.RigVMNode)

    def test_create_node_with_full_path(self):
        """Ensures that we can create a node using full struct path."""
        graph = ControlRigTools.get_forward_solve_graph(self.control_rig)
        node = ControlRigTools.create_node(
            self.control_rig, graph, '/Script/ControlRig.RigUnit_SetTransform')
        self.assertIsInstance(node, unreal.RigVMNode)

    def test_create_node_invalid_type(self):
        """Ensures that creating a node with invalid type returns None."""
        graph = ControlRigTools.get_forward_solve_graph(self.control_rig)
        result = ControlRigTools.create_node(self.control_rig, graph, 'NonExistentRigUnit')
        self.assertIsNone(result)

    def test_list_nodes(self):
        """Ensures that we can list all nodes in a graph."""
        graph = ControlRigTools.get_forward_solve_graph(self.control_rig)
        nodes = ControlRigTools.list_nodes(self.control_rig, graph)
        self.assertGreaterEqual(len(nodes), 0)

    def test_delete_node(self):
        """Ensures that we can delete a node from a graph."""
        graph = ControlRigTools.get_forward_solve_graph(self.control_rig)
        node = ControlRigTools.create_node(self.control_rig, graph, 'RigUnit_GetTransform')
        nodes_before = len(ControlRigTools.list_nodes(self.control_rig, graph))
        ControlRigTools.delete_node(self.control_rig, graph, node)
        nodes_after = len(ControlRigTools.list_nodes(self.control_rig, graph))
        self.assertEqual(nodes_after, nodes_before - 1)

    def test_get_set_node_position(self):
        """Ensures that we can get and set a node's position."""
        graph = ControlRigTools.get_forward_solve_graph(self.control_rig)
        node = ControlRigTools.create_node(
            self.control_rig, graph, 'RigUnit_GetTransform',
            position=unreal.Vector2D(100, 200))
        pos = ControlRigTools.get_node_position(self.control_rig, node)
        self.assertAlmostEqual(pos.x, 100, places=1)
        self.assertAlmostEqual(pos.y, 200, places=1)
        ControlRigTools.set_node_position(
            self.control_rig, graph, node, unreal.Vector2D(300, 400))
        new_pos = ControlRigTools.get_node_position(self.control_rig, node)
        self.assertAlmostEqual(new_pos.x, 300, places=1)
        self.assertAlmostEqual(new_pos.y, 400, places=1)

    def test_list_pins(self):
        """Ensures that we can list all pins on a node."""
        graph = ControlRigTools.get_forward_solve_graph(self.control_rig)
        node = ControlRigTools.create_node(self.control_rig, graph, 'RigUnit_GetTransform')
        pins = ControlRigTools.list_pins(self.control_rig, node)
        self.assertGreater(len(pins), 0)

    def test_add_bone(self):
        """Ensures that we can add a bone to the hierarchy."""
        bone_key = ControlRigTools.add_bone(self.control_rig, 'TestBone')
        self.assertEqual(bone_key.type, unreal.RigElementType.BONE)
        self.assertEqual(bone_key.name, 'TestBone')

    def test_add_null(self):
        """Ensures that we can add a null to the hierarchy."""
        null_key = ControlRigTools.add_null(self.control_rig, 'TestNull')
        self.assertEqual(null_key.type, unreal.RigElementType.NULL)
        self.assertEqual(null_key.name, 'TestNull')

    def test_add_control(self):
        """Ensures that we can add a control to the hierarchy."""
        control_key = ControlRigTools.add_control(self.control_rig, 'TestControl')
        self.assertEqual(control_key.type, unreal.RigElementType.CONTROL)
        self.assertEqual(control_key.name, 'TestControl')

    def test_add_element_bone(self):
        """Ensures that we can add a bone using add_element."""
        bone_key = ControlRigTools.add_element(self.control_rig, 'TestElementBone', 'bone')
        self.assertEqual(bone_key.type, unreal.RigElementType.BONE)

    def test_add_element_null(self):
        """Ensures that we can add a null using add_element."""
        null_key = ControlRigTools.add_element(self.control_rig, 'TestElementNull', 'null')
        self.assertEqual(null_key.type, unreal.RigElementType.NULL)

    def test_add_element_invalid_type(self):
        """Ensures that add_element rejects 'control' type."""
        result = ControlRigTools.add_element(self.control_rig, 'Test', 'control')
        self.assertEqual(result.name, '')

    def test_get_elements_all(self):
        """Ensures that we can get all hierarchy elements."""
        ControlRigTools.add_bone(self.control_rig, 'Bone1')
        ControlRigTools.add_null(self.control_rig, 'Null1')
        elements = ControlRigTools.get_elements(self.control_rig)
        self.assertGreaterEqual(len(elements), 2)

    def test_get_elements_by_type(self):
        """Ensures that we can filter elements by type."""
        ControlRigTools.add_bone(self.control_rig, 'FilterBone')
        ControlRigTools.add_null(self.control_rig, 'FilterNull')
        bones = ControlRigTools.get_elements(self.control_rig, unreal.RigElementType.BONE)
        for elem in bones:
            self.assertEqual(elem.type, unreal.RigElementType.BONE)

    def test_get_all_bones(self):
        """Ensures that get_all_bones returns only bones."""
        ControlRigTools.add_bone(self.control_rig, 'AllBone')
        bones = ControlRigTools.get_all_bones(self.control_rig)
        elements = ControlRigTools.get_elements(self.control_rig, unreal.RigElementType.BONE)
        self.assertEqual(len(bones), len(elements))

    def test_get_all_nulls(self):
        """Ensures that get_all_nulls returns only nulls."""
        ControlRigTools.add_null(self.control_rig, 'AllNull')
        nulls = ControlRigTools.get_all_nulls(self.control_rig)
        elements = ControlRigTools.get_elements(self.control_rig, unreal.RigElementType.NULL)
        self.assertEqual(len(nulls), len(elements))

    def test_get_all_controls(self):
        """Ensures that get_all_controls returns only controls."""
        ControlRigTools.add_control(self.control_rig, 'AllControl')
        controls = ControlRigTools.get_all_controls(self.control_rig)
        elements = ControlRigTools.get_elements(self.control_rig, unreal.RigElementType.CONTROL)
        self.assertEqual(len(controls), len(elements))

    def test_add_bone_with_parent(self):
        """Ensures that we can add a bone with a parent."""
        parent_key = ControlRigTools.add_bone(self.control_rig, 'ParentBone')
        child_key = ControlRigTools.add_bone(self.control_rig, 'ChildBone', parent=parent_key)
        found_parent = ControlRigTools.get_parent(self.control_rig, child_key)
        self.assertEqual(found_parent.name, parent_key.name)

    def test_get_children(self):
        """Ensures that we can get children of an element."""
        parent_key = ControlRigTools.add_bone(self.control_rig, 'ParentForChildren')
        ControlRigTools.add_bone(self.control_rig, 'Child1', parent=parent_key)
        ControlRigTools.add_bone(self.control_rig, 'Child2', parent=parent_key)
        children = ControlRigTools.get_children(self.control_rig, parent_key)
        child_names = [c.name for c in children]
        self.assertIn('Child1', child_names)
        self.assertIn('Child2', child_names)

    def test_get_set_global_transform(self):
        """Ensures that we can get and set global transforms."""
        bone_key = ControlRigTools.add_bone(self.control_rig, 'TransformBone')
        initial_transform = ControlRigTools.get_global_transform(self.control_rig, bone_key)
        self.assertIsInstance(initial_transform, unreal.Transform)
        # Create transform and set properties (ustruct doesn't support constructor kwargs)
        new_transform = unreal.Transform(unreal.Vector(100, 200, 300))
        ControlRigTools.set_global_transform(
            self.control_rig, bone_key, new_transform, initial=True)
        result_transform = ControlRigTools.get_global_transform(
            self.control_rig, bone_key, initial=True)
        self.assertAlmostEqual(result_transform.translation.x, 100, places=1)
        self.assertAlmostEqual(result_transform.translation.y, 200, places=1)
        self.assertAlmostEqual(result_transform.translation.z, 300, places=1)

    def test_get_set_local_transform(self):
        """Ensures that we can get and set local transforms."""
        bone_key = ControlRigTools.add_bone(self.control_rig, 'LocalTransformBone')
        local_transform = ControlRigTools.get_local_transform(self.control_rig, bone_key)
        self.assertIsInstance(local_transform, unreal.Transform)
        # Create transform and set properties (ustruct doesn't support constructor kwargs)
        new_transform = unreal.Transform(scale=unreal.Vector(2, 2, 2))
        ControlRigTools.set_local_transform(
            self.control_rig, bone_key, new_transform, initial=True)
        result_transform = ControlRigTools.get_local_transform(
            self.control_rig, bone_key, initial=True)
        self.assertAlmostEqual(result_transform.scale3d.x, 2, places=1)

    def test_add_variable(self):
        """Ensures that we can add a member variable."""
        ControlRigTools.add_variable(self.control_rig, 'TestFloat', 'float')
        variables = ControlRigTools.list_variables(self.control_rig)
        var_names = [v.get_editor_property('name') for v in variables]
        self.assertIn('TestFloat', var_names)

    def test_list_variables(self):
        """Ensures that we can list all member variables."""
        variables = ControlRigTools.list_variables(self.control_rig)
        self.assertGreaterEqual(len(variables), 0)

    def test_get_variable(self):
        """Ensures that we can get a variable by name."""
        ControlRigTools.add_variable(self.control_rig, 'TestVector', '/Script/CoreUObject.Vector')
        var = ControlRigTools.get_variable(self.control_rig, 'TestVector')
        self.assertEqual(var.get_editor_property('name'), 'TestVector')

    def test_get_variable_not_found(self):
        """Ensures that getting a non-existent variable returns empty struct."""
        result = ControlRigTools.get_variable(self.control_rig, 'NonExistentVar')
        self.assertEqual(result.name, '')

    def test_remove_variable(self):
        """Ensures that we can remove a member variable."""
        ControlRigTools.add_variable(self.control_rig, 'ToBeRemoved', 'float')
        variables = ControlRigTools.list_variables(self.control_rig)
        var_names = [v.get_editor_property('name') for v in variables]
        self.assertIn('ToBeRemoved', var_names)
        ControlRigTools.remove_variable(self.control_rig, 'ToBeRemoved')
        variables = ControlRigTools.list_variables(self.control_rig)
        var_names = [v.get_editor_property('name') for v in variables]
        self.assertNotIn('ToBeRemoved', var_names)

    def _graph_has_event_node(self, graph: unreal.RigVMGraph, event_struct_name: str) -> bool:
        """Helper that checks if a graph contains a specific event node."""
        nodes = ControlRigTools.list_nodes(self.control_rig, graph)
        for node in nodes:
            struct = node.get_script_struct()
            if struct and struct.get_name() == event_struct_name:
                return True
        return False


class EventTypeTestCase(unittest.TestCase):
    """Test EventType enum."""

    def test_event_type_values(self):
        """Ensures that EventType has correct integer values."""
        self.assertEqual(EventType.FORWARD_SOLVE.value, 0)
        self.assertEqual(EventType.BACKWARD_SOLVE.value, 1)
        self.assertEqual(EventType.INTERACTION.value, 2)

    def test_event_type_members(self):
        """Ensures that EventType has all expected members."""
        self.assertTrue(hasattr(EventType, 'FORWARD_SOLVE'))
        self.assertTrue(hasattr(EventType, 'BACKWARD_SOLVE'))
        self.assertTrue(hasattr(EventType, 'INTERACTION'))


class ControlRigToolsHelpersTestCase(unittest.TestCase):
    """Test ControlRigTools internal helpers."""

    def test_get_hierarchy_with_none(self):
        """Ensures that _get_hierarchy raises ValueError for None input."""
        with self.assertRaises(ValueError):
            ControlRigTools._get_hierarchy(None)
