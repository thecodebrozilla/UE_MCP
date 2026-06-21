# Copyright Epic Games, Inc. All Rights Reserved.

import unittest

import unreal

from conversation_toolset.toolsets.conversation import ConversationTools

_NULL_GUID = unreal.Guid()


class ConversationToolsTestCase(unittest.TestCase):
    """Test ConversationTools toolset."""

    @classmethod
    def setUpClass(cls):
        registry = unreal.AssetRegistryHelpers.get_asset_registry()
        assets = list(registry.get_assets_by_class(
            unreal.TopLevelAssetPath(
                '/Script/CommonConversationRuntime',
                'ConversationDatabase')))
        cls._class_conv = assets[0].get_asset() if len(assets) else None

    @property
    def _conv(self) -> unreal.Object:
        """Get a conversation asset or skip the test"""
        if not self._class_conv:
            self.skipTest('No ConversationDatabase found in asset registry')
        return self._class_conv

    def test_list_entry_points(self):
        """Entry points have valid tags and destination GUIDs."""
        entries = ConversationTools.list_entry_points(self._conv)
        self.assertGreater(len(entries), 0)
        for entry in entries:
            self.assertIsInstance(entry, unreal.ConversationEntryList)
            tag_text = entry.entry_tag.export_text()
            self.assertIn('TagName=', tag_text)
            self.assertGreater(len(entry.destination_list), 0)

    def test_list_speakers(self):
        """Ensures list_speakers returns participant structs."""
        speakers = ConversationTools.list_speakers(self._conv)
        for speaker in speakers:
            self.assertIsInstance(
                speaker, unreal.CommonDialogueBankParticipant)

    def test_get_all_nodes(self):
        """All nodes are reachable and have valid GUIDs."""
        nodes = ConversationTools.get_all_nodes(self._conv)
        guids = ConversationTools.get_node_guids(self._conv)
        self.assertEqual(len(nodes), len(guids))
        self.assertGreater(len(nodes), 0)
        for node in nodes:
            self.assertIsInstance(node, unreal.ConversationNode)
            self.assertNotEqual(
                node.compiled_node_guid.to_string(),
                _NULL_GUID.to_string())

    def test_get_node_guids(self):
        """GUIDs are valid and non-empty."""
        guids = ConversationTools.get_node_guids(self._conv)
        self.assertGreater(len(guids), 0)
        for guid in guids:
            self.assertIsInstance(guid, unreal.Guid)
            self.assertNotEqual(guid.to_string(), _NULL_GUID.to_string())

    def test_get_node_by_guid(self):
        """Lookup by GUID returns the correct node."""
        guids = ConversationTools.get_node_guids(self._conv)
        node = ConversationTools.get_node_by_guid(
            self._conv, guids[0])
        self.assertIsInstance(node, unreal.ConversationNode)
        self.assertEqual(
            node.compiled_node_guid.to_string(),
            guids[0].to_string())

    def test_get_node_connections(self):
        """Entry point node has valid outgoing connections."""
        entries = ConversationTools.list_entry_points(self._conv)
        entry_guid = entries[0].destination_list[0]
        node = ConversationTools.get_node_by_guid(
            self._conv, entry_guid)
        self.assertIsInstance(node, unreal.ConversationNodeWithLinks)
        connections = ConversationTools.get_node_connections(node)
        self.assertGreater(len(connections), 0)
        for connection in connections:
            self.assertIsInstance(connection, unreal.Guid)
            self.assertNotEqual(
                    connection.to_string(), _NULL_GUID.to_string())

    def test_get_sub_nodes(self):
        """Task nodes with sub-nodes return valid UObjects."""
        found = False
        for node in ConversationTools.get_all_nodes(self._conv):
            if not isinstance(node, unreal.ConversationTaskNode):
                continue
            sub_nodes = ConversationTools.get_sub_nodes(node)
            if not sub_nodes:
                continue
            found = True
            for sub_node in sub_nodes:
                self.assertIsInstance(
                    sub_node, unreal.ConversationSubNode)
                self.assertTrue(sub_node.get_name())
            break
        self.assertTrue(found, 'No task node with sub-nodes found.')

    def test_direct_property_access(self):
        """BlueprintReadOnly properties are directly accessible."""
        self.assertGreater(len(list(self._conv.entry_tags)), 0)
        self.assertIsNotNone(self._conv.reachable_node_map)
