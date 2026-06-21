# Copyright Epic Games, Inc. All Rights Reserved.

import json
import unittest

import unreal

from animation_toolset.tests._sequencer_test_base import SequencerTestBase
from animation_toolset.toolsets.sequencer import SequencerTools
from animation_toolset.toolsets.custom_bindings import SequencerCustomBindingTools

class SequencerCustomBindingsTestCase(SequencerTestBase):
    """Test SequencerCustomBindingTools - binding type conversions."""

    def test_convert_to_spawnable_and_back(self):
        """Convert a possessable to spawnable and back to possessable."""
        bindings = SequencerTools.get_bindings(self.sequence)
        if not bindings:
            self.skipTest('No bindings in sequence')
        spawnable_list = SequencerCustomBindingTools.convert_to_spawnable(bindings[0])
        self.assertGreater(len(spawnable_list), 0)
        possessable = SequencerCustomBindingTools.convert_to_possessable(spawnable_list[0])
        self.assertIsNotNone(possessable)

    def test_get_custom_binding_type_on_possessable(self):
        """Possessable binding should return empty custom binding type."""
        bindings = SequencerTools.get_bindings(self.sequence)
        if not bindings:
            self.skipTest('No bindings in sequence')
        result = SequencerCustomBindingTools.get_custom_binding_type(bindings[0])
        self.assertEqual(result, "")

    def test_get_custom_binding_objects_on_possessable(self):
        """Possessable binding should return empty custom binding objects list."""
        bindings = SequencerTools.get_bindings(self.sequence)
        if not bindings:
            self.skipTest('No bindings in sequence')
        result = SequencerCustomBindingTools.get_custom_binding_objects(bindings[0])
        self.assertEqual(len(result), 0)

    def test_save_default_spawnable_state(self):
        """Save default spawnable state on a spawnable binding."""
        bindings = SequencerTools.get_bindings(self.sequence)
        if not bindings:
            self.skipTest('No bindings in sequence')
        spawnable_list = SequencerCustomBindingTools.convert_to_spawnable(bindings[0])
        if not spawnable_list:
            self.skipTest('Could not create spawnable')
        SequencerCustomBindingTools.save_default_spawnable_state(spawnable_list[0])
        # Restore to possessable so tearDown doesn't fail.
        SequencerCustomBindingTools.convert_to_possessable(spawnable_list[0])

    # ====================================================================
    # Conditions (requires C++ MovieSceneConditionExtensions)
    # ====================================================================

    def test_get_child_possessables(self):
        """Get component bindings under a spawnable actor binding."""
        # Convert to spawnable so component children are available.
        spawnable_list = SequencerCustomBindingTools.convert_to_spawnable(self.binding)
        if not spawnable_list:
            self.skipTest('Could not create spawnable')
        children = SequencerTools.get_child_possessables(spawnable_list[0])
        self.assertTrue(hasattr(children, '__len__'))
        # Restore to possessable.
        SequencerCustomBindingTools.convert_to_possessable(spawnable_list[0])
