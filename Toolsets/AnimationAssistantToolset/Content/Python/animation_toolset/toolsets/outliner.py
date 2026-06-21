# Copyright Epic Games, Inc. All Rights Reserved.

import json

import unreal

import toolset_registry


@unreal.uclass()
class SequencerOutlinerTools(unreal.ToolsetDefinition):
    """Tools for inspecting and managing the Sequencer outliner tree. Use when
    getting a snapshot of the outliner hierarchy, querying node children,
    managing outliner selection, expanding or collapsing nodes, or toggling
    node states like mute, solo, deactivate, lock, and pin. Also useful for
    test verification of Sequencer UI state."""


    @toolset_registry.tool_call
    @staticmethod
    def get_outliner_tree() -> str:
        """Get a full snapshot of the Sequencer outliner tree.

        Builds a recursive tree structure from the outliner root nodes.
        Useful for testing and UI verification.

        Returns:
            JSON string encoding a list of objects, each with 'label',
            'type', and 'children' (a recursive list of the same structure).
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        scripting_layer = subsystem.get_scripting_layer()
        outliner = scripting_layer.get_outliner()

        root_node = outliner.get_root_node()
        root_nodes = [root_node] if root_node else []

        def _build_tree(nodes):
            result = []
            for node in nodes:
                children = list(outliner.get_children(node))
                entry = {
                    "label": node.get_label(),
                    "type": str(node.type),
                    "children": _build_tree(children),
                }
                result.append(entry)
            return result


        return json.dumps(_build_tree(root_nodes))

    @toolset_registry.tool_call
    @staticmethod
    def get_outliner_children(
        node: unreal.SequencerViewModelScriptingStruct,
        type_filter: str | None = None
    ) -> list[unreal.SequencerViewModelScriptingStruct]:
        """Get child nodes of an outliner node.

        Args:
            node: The parent outliner node.
            type_filter: Optional node type name to filter by (e.g. "Track").

        Returns:
            List of child SequencerViewModelScriptingStruct objects.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        scripting_layer = subsystem.get_scripting_layer()
        outliner = scripting_layer.get_outliner()

        children = list(outliner.get_children(node))
        if type_filter:
            children = [c for c in children if str(c.type) == type_filter]
        return children

    @toolset_registry.tool_call
    @staticmethod
    def get_outliner_selection() -> list[unreal.SequencerViewModelScriptingStruct]:
        """Get the currently selected nodes in the outliner.

        Returns:
            List of selected SequencerViewModelScriptingStruct objects.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        scripting_layer = subsystem.get_scripting_layer()
        outliner = scripting_layer.get_outliner()
        return list(outliner.get_selection())

    @toolset_registry.tool_call
    @staticmethod
    def set_outliner_selection(
        nodes: list[unreal.SequencerViewModelScriptingStruct]
    ) -> bool:
        """Set the outliner selection.

        Args:
            nodes: The nodes to select.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        scripting_layer = subsystem.get_scripting_layer()
        outliner = scripting_layer.get_outliner()
        outliner.set_selection(nodes)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_node_label(
        node: unreal.SequencerViewModelScriptingStruct
    ) -> str:
        """Get the display label of an outliner node.

        Args:
            node: The outliner node to query.

        Returns:
            The node's display label text.
        """
        return node.get_label()

    @toolset_registry.tool_call
    @staticmethod
    def set_node_expanded(
        nodes: list[unreal.SequencerViewModelScriptingStruct],
        expanded: bool
    ) -> bool:
        """Expand or collapse outliner nodes.

        Args:
            nodes: The nodes to expand or collapse.
            expanded: True to expand, False to collapse.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        scripting_layer = subsystem.get_scripting_layer()
        outliner = scripting_layer.get_outliner()
        outliner.set_expansion(nodes, expanded)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def is_node_expanded(
        node: unreal.SequencerViewModelScriptingStruct
    ) -> bool:
        """Check whether an outliner node is expanded.

        Args:
            node: The outliner node to query.

        Returns:
            True if expanded, False if collapsed.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        scripting_layer = subsystem.get_scripting_layer()
        outliner = scripting_layer.get_outliner()
        return outliner.is_expanded(node)

    @toolset_registry.tool_call
    @staticmethod
    def set_node_muted(
        nodes: list[unreal.SequencerViewModelScriptingStruct],
        muted: bool
    ) -> bool:
        """Mute or unmute outliner nodes.

        Args:
            nodes: The nodes to mute or unmute.
            muted: True to mute, False to unmute.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        scripting_layer = subsystem.get_scripting_layer()
        outliner = scripting_layer.get_outliner()
        outliner.set_mute_nodes(nodes, muted)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def set_node_solo(
        nodes: list[unreal.SequencerViewModelScriptingStruct],
        soloed: bool
    ) -> bool:
        """Solo or unsolo outliner nodes.

        Args:
            nodes: The nodes to solo or unsolo.
            soloed: True to solo, False to unsolo.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        scripting_layer = subsystem.get_scripting_layer()
        outliner = scripting_layer.get_outliner()
        outliner.set_solo_nodes(nodes, soloed)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_muted_nodes() -> list[unreal.SequencerViewModelScriptingStruct]:
        """Get the currently muted outliner nodes.

        Returns:
            List of muted nodes.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        scripting_layer = subsystem.get_scripting_layer()
        outliner = scripting_layer.get_outliner()
        return list(outliner.get_mute_nodes())

    @toolset_registry.tool_call
    @staticmethod
    def get_soloed_nodes() -> list[unreal.SequencerViewModelScriptingStruct]:
        """Get the currently soloed outliner nodes.

        Returns:
            List of soloed nodes.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        scripting_layer = subsystem.get_scripting_layer()
        outliner = scripting_layer.get_outliner()
        return list(outliner.get_solo_nodes())

    @toolset_registry.tool_call
    @staticmethod
    def set_node_deactivated(
        nodes: list[unreal.SequencerViewModelScriptingStruct],
        deactivated: bool
    ) -> bool:
        """Deactivate or reactivate outliner nodes.

        Args:
            nodes: List of outliner nodes to modify.
            deactivated: True to deactivate, False to reactivate.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        outliner = subsystem.get_scripting_layer().get_outliner()
        outliner.set_deactivated_nodes(nodes, deactivated)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_deactivated_nodes() -> list[unreal.SequencerViewModelScriptingStruct]:
        """Get the currently deactivated outliner nodes.

        Returns:
            List of deactivated nodes.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        outliner = subsystem.get_scripting_layer().get_outliner()
        return list(outliner.get_deactivated_nodes())

    @toolset_registry.tool_call
    @staticmethod
    def set_node_locked(
        nodes: list[unreal.SequencerViewModelScriptingStruct],
        locked: bool
    ) -> bool:
        """Lock or unlock outliner nodes for editing.

        Args:
            nodes: List of outliner nodes to modify.
            locked: True to lock, False to unlock.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        outliner = subsystem.get_scripting_layer().get_outliner()
        outliner.set_locked_nodes(nodes, locked)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_locked_nodes() -> list[unreal.SequencerViewModelScriptingStruct]:
        """Get the currently locked outliner nodes.

        Returns:
            List of locked nodes.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        outliner = subsystem.get_scripting_layer().get_outliner()
        return list(outliner.get_locked_nodes())

    @toolset_registry.tool_call
    @staticmethod
    def set_node_pinned(
        nodes: list[unreal.SequencerViewModelScriptingStruct],
        pinned: bool
    ) -> bool:
        """Pin or unpin outliner nodes.

        Args:
            nodes: List of outliner nodes to modify.
            pinned: True to pin, False to unpin.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        outliner = subsystem.get_scripting_layer().get_outliner()
        outliner.set_pinned_nodes(nodes, pinned)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_pinned_nodes() -> list[unreal.SequencerViewModelScriptingStruct]:
        """Get the currently pinned outliner nodes.

        Returns:
            List of pinned nodes.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        outliner = subsystem.get_scripting_layer().get_outliner()
        return list(outliner.get_pinned_nodes())

    @toolset_registry.tool_call
    @staticmethod
    def get_sections_for_nodes(
        nodes: list[unreal.SequencerViewModelScriptingStruct]
    ) -> list[unreal.MovieSceneSection]:
        """Get sections associated with the given outliner nodes.

        Args:
            nodes: The outliner nodes to query.

        Returns:
            List of MovieSceneSection objects associated with the nodes.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        outliner = subsystem.get_scripting_layer().get_outliner()
        # Use the outliner selection approach: select nodes, get selected sections.
        old_selection = list(outliner.get_selection())
        try:
            outliner.set_selection(nodes)
            sections = list(
                unreal.LevelSequenceEditorBlueprintLibrary.get_selected_sections()
            )
        finally:
            outliner.set_selection(old_selection)
        return sections

