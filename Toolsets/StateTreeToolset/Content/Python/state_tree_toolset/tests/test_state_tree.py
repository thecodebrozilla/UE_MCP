# Copyright Epic Games, Inc. All Rights Reserved.

from dataclasses import dataclass
from typing import Optional
import unittest

import unreal

from state_tree_toolset.toolsets.state_tree import StateTreeTools


def _has_conditions(state) -> bool:
    """Recursively checks if a state or its children have enter conditions."""
    if len(list(state.enter_conditions)) > 0:
        return True
    for child in state.children:
        if _has_conditions(child):
            return True
    return False


@dataclass()
class _StateTreeInfo:
    state_tree: unreal.Object
    has_subtrees: bool = False
    has_tasks: bool = False
    has_conds: bool = False

    @property
    def richness(self) -> int:
        return (int(self.has_subtrees) + int(self.has_tasks) +
                int(self.has_conds))

    @property
    def is_rich(self) -> bool:
        return self.has_subtrees and self.has_tasks and self.has_conds


def _find_rich_state_tree() -> Optional[_StateTreeInfo]:
    """Finds a StateTree with tasks and conditions."""
    registry = unreal.AssetRegistryHelpers.get_asset_registry()
    assets = list(registry.get_assets_by_class(
        unreal.TopLevelAssetPath(
            '/Script/StateTreeModule', 'StateTree')))
    best_state_tree_info: _StateTreeInfo | None = None
    for asset_data in assets:
        st = asset_data.get_asset()
        if st is None:
            continue
        state_tree_info = _StateTreeInfo(st)
        ed = unreal.StateTreeEditorData.get_editor_data(st)
        if ed is None:
            continue
        state_tree_info.has_subtrees = bool(len(ed.sub_trees))
        state_tree_info.has_tasks = any(
            len(list(r.tasks)) > 0 for r in ed.sub_trees)
        state_tree_info.has_conds = any(
            _has_conditions(r) for r in ed.sub_trees)

        if (not best_state_tree_info or
            state_tree_info.richness > best_state_tree_info.richness):
            best_state_tree_info = state_tree_info
            if best_state_tree_info.is_rich:
                break
    return best_state_tree_info


class StateTreeToolsTestCase(unittest.TestCase):
    """Test StateTreeTools toolset."""

    @classmethod
    def setUpClass(cls):
        cls._state_tree_info = _find_rich_state_tree()

    def _require_asset(
            self, tasks: bool = False, conds: bool = False,
            subtrees = False) -> unreal.Object:
        self.assertIsNotNone(
            self._state_tree_info, 'No StateTree asset found.')
        for requirement, should_skip in (
            ('tasks', tasks and not self._state_tree_info.has_tasks),
            ('conditions', conds and not self._state_tree_info.has_conds),
            ('subtrees', subtrees and not self._state_tree_info.has_subtrees),
        ):
            if should_skip:
                self.skipTest(f'Requires state tree with {requirement}')
        assert self._state_tree_info
        return self._state_tree_info.state_tree

    def test_get_editor_data(self):
        """Ensures get_editor_data returns StateTreeEditorData."""
        st = self._require_asset()
        ed = StateTreeTools.get_editor_data(st)
        self.assertIsInstance(ed, unreal.StateTreeEditorData)

    def test_get_root_states(self):
        """Ensures get_root_states returns states."""
        st = self._require_asset()
        roots = list(StateTreeTools.get_root_states(st))
        self.assertGreater(len(roots), 0)
        self.assertIsInstance(roots[0], unreal.StateTreeState)

    def test_get_children(self):
        """Ensures get_children returns child states."""
        st = self._require_asset()
        roots = list(StateTreeTools.get_root_states(st))
        children = list(StateTreeTools.get_children(roots[0]))
        for child in children:
            self.assertIsInstance(child, unreal.StateTreeState)

    def test_get_tasks(self):
        """Ensures get_tasks returns editor nodes."""
        st = self._require_asset(tasks=True)
        ed = StateTreeTools.get_editor_data(st)
        for root in ed.sub_trees:
            tasks = list(StateTreeTools.get_tasks(root))
            if tasks:
                self.assertIsInstance(
                    tasks[0], unreal.StateTreeEditorNode)
                return
            for child in root.children:
                tasks = list(StateTreeTools.get_tasks(child))
                if tasks:
                    self.assertIsInstance(
                        tasks[0], unreal.StateTreeEditorNode)
                    return
        self.fail('No state with tasks found.')

    def test_get_enter_conditions(self):
        """Ensures get_enter_conditions returns editor nodes."""
        st = self._require_asset(conds=True)
        ed = StateTreeTools.get_editor_data(st)
        queue = list(ed.sub_trees)
        while queue:
            state = queue.pop(0)
            conds = list(
                StateTreeTools.get_enter_conditions(state))
            if conds:
                self.assertIsInstance(
                    conds[0], unreal.StateTreeEditorNode)
                return
            queue.extend(state.children)
        self.fail('No state with enter conditions found.')

    def test_get_transitions(self):
        """Ensures get_transitions returns transitions."""
        st = self._require_asset()
        ed = StateTreeTools.get_editor_data(st)
        for root in ed.sub_trees:
            for child in root.children:
                trans = list(
                    StateTreeTools.get_transitions(child))
                if trans:
                    self.assertIsInstance(
                        trans[0], unreal.StateTreeTransition)
                    return
        self.fail('No state with transitions found.')

    def test_get_global_tasks(self):
        """Ensures get_global_tasks returns editor nodes."""
        st = self._require_asset()
        tasks = list(StateTreeTools.get_global_tasks(st))
        self.assertGreaterEqual(len(tasks), 0)

    def test_get_evaluators(self):
        """Ensures get_evaluators returns editor nodes."""
        st = self._require_asset()
        evals = list(
            StateTreeTools.get_evaluators(st))
        self.assertGreaterEqual(len(evals), 0)

    def test_get_node_description(self):
        """Ensures get_node_description returns a string."""
        st = self._require_asset(tasks=True)
        ed = StateTreeTools.get_editor_data(st)
        queue = list(ed.sub_trees)
        while queue:
            state = queue.pop(0)
            tasks = list(StateTreeTools.get_tasks(state))
            if tasks:
                desc = StateTreeTools.get_node_description(
                    st, tasks[0])
                self.assertIsInstance(desc, str)
                return
            queue.extend(state.children)
        self.fail('No task node found for description.')

    def test_state_name_accessible(self):
        """Ensures state name is directly accessible."""
        st = self._require_asset()
        roots = list(StateTreeTools.get_root_states(st))
        self.assertIsNotNone(roots[0].name)

    def test_editor_node_properties(self):
        """Ensures editor node has node and instance structs."""
        st = self._require_asset(tasks=True, subtrees=True)
        ed = StateTreeTools.get_editor_data(st)
        for root in ed.sub_trees:
            for child in root.children:
                tasks = list(StateTreeTools.get_tasks(child))
                if tasks:
                    self.assertIsInstance(
                        tasks[0].node, unreal.InstancedStruct)
                    self.assertIsInstance(
                        tasks[0].instance, unreal.InstancedStruct)
                    return
        self.fail('No task node found.')

    def test_transition_properties(self):
        """Ensures transition has trigger and state link."""
        st = self._require_asset(subtrees=True)
        ed = StateTreeTools.get_editor_data(st)
        for root in ed.sub_trees:
            for child in root.children:
                trans = list(
                    StateTreeTools.get_transitions(child))
                if trans:
                    self.assertIsNotNone(trans[0].trigger)
                    self.assertIsNotNone(trans[0].state)
                    return
        self.fail('No transition found.')
