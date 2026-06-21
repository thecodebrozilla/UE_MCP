# Copyright Epic Games, Inc. All Rights Reserved.

from contextlib import ExitStack
from typing import Optional
import unittest

import unreal

from toolset_registry.tests.automation import create_temp_folder
from aimodule_toolset.toolsets.behavior_tree import BehaviorTreeTools


def _create_behavior_tree(folder: str, name: str) -> unreal.BehaviorTree:
    """Creates a BehaviorTree asset using UBehaviorTreeFactory."""
    factory = unreal.BehaviorTreeFactory()
    asset = unreal.AssetToolsHelpers.get_asset_tools().create_asset(
        name, folder, unreal.BehaviorTree.static_class(), factory)
    assert isinstance(asset, unreal.BehaviorTree), f'Could not create BehaviorTree {name}'
    return asset


def _find_populated_behavior_tree() -> Optional[unreal.BehaviorTree]:
    """Finds a BehaviorTree with a root node via asset registry."""
    registry = unreal.AssetRegistryHelpers.get_asset_registry()
    assets = list(registry.get_assets_by_class(
        unreal.TopLevelAssetPath('/Script/AIModule', 'BehaviorTree')))
    for asset_data in assets:
        bt = asset_data.get_asset()
        if isinstance(bt, unreal.BehaviorTree) and bt.root_node is not None:
            return bt
    return None


class BehaviorTreeToolsEmptyTestCase(unittest.TestCase):
    """Test BehaviorTreeTools against a factory-created empty BT."""

    def setUp(self):
        super().setUp()
        self._stack = ExitStack()
        folder = self._stack.enter_context(create_temp_folder())
        self._bt = _create_behavior_tree(folder, 'TestBT')

    def tearDown(self):
        self._bt = None
        self._stack.close()
        super().tearDown()

    def test_list_nodes_empty(self):
        """Empty BT has no nodes."""
        self.assertEqual(len(BehaviorTreeTools.list_nodes(self._bt)), 0)

    def test_get_node_depths_empty(self):
        """Empty BT has no depths."""
        self.assertEqual(len(BehaviorTreeTools.get_node_depths(self._bt)), 0)

    def test_get_blackboard_empty(self):
        """Empty BT has no blackboard."""
        self.assertIsNone(BehaviorTreeTools.get_blackboard(self._bt))

    def test_get_root_decorators_empty(self):
        """Empty BT has no root decorators."""
        self.assertEqual(len(BehaviorTreeTools.get_root_decorators(self._bt)), 0)


class BehaviorTreeToolsPopulatedTestCase(unittest.TestCase):
    """Test BehaviorTreeTools against a real BT asset from the registry."""

    @classmethod
    def setUpClass(cls):
        cls._bt = _find_populated_behavior_tree()

    def _require_asset(self):
        if self._bt is None:
            self.fail('No populated BehaviorTree asset found in the asset registry.')

    def test_list_nodes_has_root(self):
        """Root composite is the first non-decorator node in the list."""
        self._require_asset()
        nodes = BehaviorTreeTools.list_nodes(self._bt)
        self.assertGreater(len(nodes), 0)
        root_decorators = BehaviorTreeTools.get_root_decorators(self._bt)
        first_composite_index = len(root_decorators)
        self.assertEqual(nodes[first_composite_index], self._bt.root_node)

    def test_get_node_depths_root_at_zero(self):
        """Root composite is at depth 0 and all depths are non-negative."""
        self._require_asset()
        nodes = BehaviorTreeTools.list_nodes(self._bt)
        depths = BehaviorTreeTools.get_node_depths(self._bt)
        self.assertEqual(len(nodes), len(depths))
        root_decorators = BehaviorTreeTools.get_root_decorators(self._bt)
        self.assertEqual(depths[len(root_decorators)], 0)
        for depth in depths:
            self.assertGreaterEqual(depth, 0)

    def test_get_node_depth_matches_depths(self):
        """get_node_depth returns same value as get_node_depths at each index."""
        self._require_asset()
        depths = BehaviorTreeTools.get_node_depths(self._bt)
        for index in range(min(len(depths), 5)):
            self.assertEqual(
                BehaviorTreeTools.get_node_depth(self._bt, index),
                depths[index])

    def test_get_blackboard_populated(self):
        """Populated BT returns a BlackboardData if one is assigned."""
        self._require_asset()
        bb = BehaviorTreeTools.get_blackboard(self._bt)
        if bb is not None:
            self.assertIsInstance(bb, unreal.BlackboardData)

    def test_get_children_matches_composite_children(self):
        """get_children returns the same nodes as the composite's children struct."""
        self._require_asset()
        root = self._bt.root_node
        children = BehaviorTreeTools.get_children(root)
        expected = []
        for child_struct in root.children:
            node = child_struct.child_composite or child_struct.child_task
            if node is not None:
                expected.append(node)
        self.assertEqual(children, expected)

    def test_get_subtree_on_run_behavior(self):
        """get_subtree returns a BehaviorTree for RunBehavior tasks."""
        self._require_asset()
        registry = unreal.AssetRegistryHelpers.get_asset_registry()
        bt_assets = list(registry.get_assets_by_class(
            unreal.TopLevelAssetPath('/Script/AIModule', 'BehaviorTree')))
        for asset_data in bt_assets:
            bt = asset_data.get_asset()
            for node in BehaviorTreeTools.list_nodes(bt):
                if not hasattr(node, 'behavior_asset') and not hasattr(node, 'default_behavior_asset'):
                    continue
                subtree = BehaviorTreeTools.get_subtree(node)
                self.assertIsInstance(subtree, unreal.BehaviorTree)
                return
        self.fail('No RunBehavior task with exposed behavior_asset found in any BT.')

    def test_direct_property_access(self):
        """BT root_node is accessible and has children."""
        self._require_asset()
        root = self._bt.root_node
        self.assertIsNotNone(root)
        self.assertIsInstance(root, unreal.BTCompositeNode)
        self.assertGreater(len(list(root.children)), 0)
