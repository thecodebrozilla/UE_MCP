# Copyright Epic Games, Inc. All Rights Reserved.

import unreal

import toolset_registry


@unreal.uclass()
class StateTreeTools(unreal.ToolsetDefinition):
    """Inspect StateTree (ST) assets."""

    @toolset_registry.tool_call
    @staticmethod
    def get_editor_data(
        state_tree: unreal.StateTree,
    ) -> unreal.StateTreeEditorData:
        """Returns the editor data for a StateTree asset.

        Args:
            state_tree: The StateTree asset.

        Returns:
            The editor data object.
        """
        ed = unreal.StateTreeEditorData.get_editor_data(state_tree)
        if ed is None:
            raise ValueError('StateTree has no editor data.')
        return ed

    @toolset_registry.tool_call
    @staticmethod
    def get_root_states(
        state_tree: unreal.StateTree,
    ) -> list[unreal.StateTreeState]:
        """Returns top-level states of a StateTree.

        Args:
            state_tree: The StateTree asset.

        Returns:
            Root-level states.
        """
        ed = StateTreeTools._get_ed(state_tree)
        return list(ed.sub_trees)

    @toolset_registry.tool_call
    @staticmethod
    def get_children(
        state: unreal.StateTreeState,
    ) -> list[unreal.StateTreeState]:
        """Returns child states of a state.

        Args:
            state: The state to query.

        Returns:
            Child states.
        """
        return list(state.children)

    @toolset_registry.tool_call
    @staticmethod
    def get_tasks(
        state: unreal.StateTreeState,
    ) -> list[unreal.StateTreeEditorNode]:
        """Returns tasks on a state.

        Args:
            state: The state to query.

        Returns:
            Task editor nodes.
        """
        return list(state.tasks)

    @toolset_registry.tool_call
    @staticmethod
    def get_enter_conditions(
        state: unreal.StateTreeState,
    ) -> list[unreal.StateTreeEditorNode]:
        """Returns enter conditions on a state.

        Args:
            state: The state to query.

        Returns:
            Condition editor nodes.
        """
        return list(state.enter_conditions)

    @toolset_registry.tool_call
    @staticmethod
    def get_transitions(
        state: unreal.StateTreeState,
    ) -> list[unreal.StateTreeTransition]:
        """Returns transitions on a state.

        Args:
            state: The state to query.

        Returns:
            Transitions.
        """
        return list(state.transitions)

    @toolset_registry.tool_call
    @staticmethod
    def get_global_tasks(
        state_tree: unreal.StateTree,
    ) -> list[unreal.StateTreeEditorNode]:
        """Returns global tasks that run across all states.

        Args:
            state_tree: The StateTree asset.

        Returns:
            Global task editor nodes.
        """
        ed = StateTreeTools._get_ed(state_tree)
        return list(ed.global_tasks)

    @toolset_registry.tool_call
    @staticmethod
    def get_evaluators(
        state_tree: unreal.StateTree,
    ) -> list[unreal.StateTreeEditorNode]:
        """Returns global evaluators.

        Args:
            state_tree: The StateTree asset.

        Returns:
            Evaluator editor nodes.
        """
        ed = StateTreeTools._get_ed(state_tree)
        return list(ed.evaluators)

    @toolset_registry.tool_call
    @staticmethod
    def get_node_description(
        state_tree: unreal.StateTree,
        node: unreal.StateTreeEditorNode,
    ) -> str:
        """Returns a human-readable description for a node.

        Args:
            state_tree: The StateTree asset.
            node: The editor node to describe.

        Returns:
            Formatted description string.
        """
        ed = StateTreeTools._get_ed(state_tree)
        return str(ed.get_node_description(node))

    @staticmethod
    def _get_ed(
        state_tree: unreal.StateTree,
    ) -> unreal.StateTreeEditorData:
        """Returns editor data, raising if unavailable."""
        ed = unreal.StateTreeEditorData.get_editor_data(
            state_tree)
        if ed is None:
            raise ValueError('StateTree has no editor data.')
        return ed
