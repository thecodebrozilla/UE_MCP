# Copyright Epic Games, Inc. All Rights Reserved.

import json
import unittest

import unreal

from animation_toolset.tests._sequencer_test_base import SequencerTestBase
from animation_toolset.toolsets.sequencer import SequencerTools
from animation_toolset.toolsets.outliner import SequencerOutlinerTools

class SequencerOutlinerTestCase(SequencerTestBase):
    """Test SequencerOutlinerTools - tree, mute/solo, expansion, node state."""

    def test_outliner_tree(self):
        """Ensures that the outliner tree contains the actor binding label."""
        tree_json = SequencerOutlinerTools.get_outliner_tree()
        actor_label = self.actor.get_actor_label()
        self.assertIn(actor_label, tree_json)

    # ====================================================================
    # Playback extras
    # ====================================================================

    def test_get_outliner_selection_and_set(self):
        """Ensures that outliner selection can be set and read back."""
        root, children, outliner = self._get_outliner_root_and_children()
        if not children:
            self.skipTest('No outliner children available')
        SequencerOutlinerTools.set_outliner_selection([children[0]])
        selected = SequencerOutlinerTools.get_outliner_selection()
        self.assertGreaterEqual(len(selected), 1)
        # Clear selection to avoid state leakage.
        SequencerOutlinerTools.set_outliner_selection([])

    def test_get_node_label(self):
        """Ensures that an outliner node has a non-empty label."""
        root, children, _ = self._get_outliner_root_and_children()
        if not children:
            self.skipTest('No outliner children available')
        label = SequencerOutlinerTools.get_node_label(children[0])
        self.assertIsInstance(label, str)
        self.assertTrue(len(label) > 0)

    def test_set_node_expanded_and_is_expanded(self):
        """Ensures that outliner nodes can be expanded and collapsed."""
        root, children, _ = self._get_outliner_root_and_children()
        if not children:
            self.skipTest('No outliner children available')
        node = children[0]
        SequencerOutlinerTools.set_node_expanded([node], True)
        self.assertTrue(SequencerOutlinerTools.is_node_expanded(node))
        SequencerOutlinerTools.set_node_expanded([node], False)
        self.assertFalse(SequencerOutlinerTools.is_node_expanded(node))

    def test_set_node_muted(self):
        """Ensures that muting a node changes the mute state."""
        root, children, outliner = self._get_outliner_root_and_children()
        if not children:
            self.skipTest('No outliner children available')
        node = children[0]
        SequencerOutlinerTools.set_node_muted([node], True)
        muted = SequencerOutlinerTools.get_muted_nodes()
        self.assertGreaterEqual(len(muted), 1)
        # Unmute to clean up.
        SequencerOutlinerTools.set_node_muted([node], False)

    def test_set_node_solo(self):
        """Ensures that soloing a node changes the solo state."""
        root, children, outliner = self._get_outliner_root_and_children()
        if not children:
            self.skipTest('No outliner children available')
        node = children[0]
        SequencerOutlinerTools.set_node_solo([node], True)
        soloed = SequencerOutlinerTools.get_soloed_nodes()
        self.assertGreaterEqual(len(soloed), 1)
        # Unsolo to clean up.
        SequencerOutlinerTools.set_node_solo([node], False)

    def test_get_sections_for_nodes(self):
        """Ensures that get_sections_for_nodes returns a list."""
        root, children, _ = self._get_outliner_root_and_children()
        if not children:
            self.skipTest('No outliner children available')
        sections = SequencerOutlinerTools.get_sections_for_nodes(children)
        self.assertTrue(hasattr(sections, "__len__"))

    # ====================================================================
    # Binding extras
    # ====================================================================

    def test_get_outliner_children(self):
        """Ensures that outliner children can be retrieved for the root node."""
        root, children, _ = self._get_outliner_root_and_children()
        # The root should have at least one child (the actor binding).
        self.assertGreaterEqual(len(children), 1)
