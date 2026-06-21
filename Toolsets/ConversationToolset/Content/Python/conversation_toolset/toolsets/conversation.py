# Copyright Epic Games, Inc. All Rights Reserved.

import unreal

import toolset_registry


@unreal.uclass()
class ConversationTools(unreal.ToolsetDefinition):
    """Inspect Conversation Graph (UConversationDatabase) dialogue assets."""

    @toolset_registry.tool_call
    @staticmethod
    def list_entry_points(conversation: unreal.ConversationDatabase) -> list[unreal.ConversationEntryList]:
        """Returns entry points (FConversationEntryList structs).

        Args:
            conversation: The ConversationDatabase asset.
        Returns:
            A list of FConversationEntryList structs.
        """
        return list(conversation.entry_tags)

    @toolset_registry.tool_call
    @staticmethod
    def list_speakers(conversation: unreal.ConversationDatabase) -> list[unreal.CommonDialogueBankParticipant]:
        """Returns speaker/participant information.

        Args:
            conversation: The ConversationDatabase asset.
        Returns:
            A list of FCommonDialogueBankParticipant structs.
        """
        return list(conversation.speakers)

    @toolset_registry.tool_call
    @staticmethod
    def get_all_nodes(conversation: unreal.ConversationDatabase) -> list[unreal.ConversationNode]:
        """Returns all reachable nodes in the conversation.

        Use ObjectTools.get_class and get_properties on each node
        to inspect type and properties. Each node's GUID is
        available via its compiled_node_guid attribute.

        Args:
            conversation: The ConversationDatabase asset.
        Returns:
            A list of UConversationNode UObjects.
        """
        return [n for n in conversation.reachable_node_map.values() if n is not None]

    @toolset_registry.tool_call
    @staticmethod
    def get_node_guids(conversation: unreal.ConversationDatabase) -> list[unreal.Guid]:
        """Returns GUIDs of all reachable nodes, in map iteration order.

        Use with get_node_by_guid to look up specific nodes.

        Args:
            conversation: The ConversationDatabase asset.
        Returns:
            A list of FGuid structs.
        """
        return [g for g, n in conversation.reachable_node_map.items() if n is not None]

    @toolset_registry.tool_call
    @staticmethod
    def get_node_by_guid(conversation: unreal.ConversationDatabase, guid: unreal.Guid) -> unreal.ConversationNode:
        """Returns a conversation node by its GUID.

        Args:
            conversation: The ConversationDatabase asset.
            guid: The GUID (from get_node_guids or entry_points).
        Returns:
            The UConversationNode.
        """
        guid_str = guid.to_string()
        for g, node in conversation.reachable_node_map.items():
            if g.to_string() == guid_str and node is not None:
                return node
        raise RuntimeError(f'Node with GUID {guid_str} not found.')

    @toolset_registry.tool_call
    @staticmethod
    def get_node_connections(node: unreal.ConversationNodeWithLinks) -> list[unreal.Guid]:
        """Returns output connection GUIDs for a conversation node.

        Args:
            node: The conversation node to query.
        Returns:
            A list of FGuid output connections.
        """
        return list(node.output_connections)

    @toolset_registry.tool_call
    @staticmethod
    def get_sub_nodes(node: unreal.ConversationTaskNode) -> list[unreal.ConversationSubNode]:
        """Returns sub-nodes (requirements, choices) attached to a task node.

        Args:
            node: The conversation task node to query.
        Returns:
            A list of UConversationSubNode UObjects.
        """
        return list(node.sub_nodes)
