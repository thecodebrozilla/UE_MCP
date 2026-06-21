# Copyright Epic Games, Inc. All Rights Reserved.

import json
import unittest

import unreal

from animation_toolset.tests._sequencer_test_base import SequencerTestBase
from animation_toolset.toolsets.sequencer import SequencerTools
from animation_toolset.toolsets.conditions import SequencerConditionTools

class SequencerConditionsTestCase(SequencerTestBase):
    """Test SequencerConditionTools - section/track/row runtime conditions."""

    def test_section_condition_roundtrip(self):
        """Set, get, and clear a condition on a section."""
        bindings = SequencerTools.get_bindings(self.sequence)
        if not bindings:
            self.skipTest('No bindings in sequence')
        tracks = SequencerTools.get_tracks_on_binding(bindings[0])
        if not tracks:
            self.skipTest('No tracks on binding')
        sections = tracks[0].get_sections()
        if not sections:
            self.skipTest('No sections on track')
        section = sections[0]
        self.assertEqual(SequencerConditionTools.get_section_condition(section), "")
        SequencerConditionTools.set_section_condition(
            section, '/Script/MovieSceneTracks.MovieScenePlatformCondition'
        )
        cond = SequencerConditionTools.get_section_condition(section)
        self.assertIn('PlatformCondition', cond)
        SequencerConditionTools.clear_section_condition(section)
        self.assertEqual(SequencerConditionTools.get_section_condition(section), "")

    def test_track_condition_roundtrip(self):
        """Set, get, and clear a condition on a track."""
        bindings = SequencerTools.get_bindings(self.sequence)
        if not bindings:
            self.skipTest('No bindings in sequence')
        tracks = SequencerTools.get_tracks_on_binding(bindings[0])
        if not tracks:
            self.skipTest('No tracks on binding')
        track = tracks[0]
        self.assertEqual(SequencerConditionTools.get_track_condition(track), "")
        SequencerConditionTools.set_track_condition(
            track, '/Script/MovieSceneTracks.MovieScenePlatformCondition'
        )
        cond = SequencerConditionTools.get_track_condition(track)
        self.assertIn('PlatformCondition', cond)
        SequencerConditionTools.clear_track_condition(track)
        self.assertEqual(SequencerConditionTools.get_track_condition(track), "")

    def test_track_row_condition_roundtrip(self):
        """Set, get, and clear a condition on a track row."""
        bindings = SequencerTools.get_bindings(self.sequence)
        if not bindings:
            self.skipTest('No bindings in sequence')
        tracks = SequencerTools.get_tracks_on_binding(bindings[0])
        if not tracks:
            self.skipTest('No tracks on binding')
        track = tracks[0]
        self.assertEqual(SequencerConditionTools.get_track_row_condition(track, 0), "")
        SequencerConditionTools.set_track_row_condition(
            track, 0, '/Script/MovieSceneTracks.MovieScenePlatformCondition'
        )
        cond = SequencerConditionTools.get_track_row_condition(track, 0)
        self.assertIn('PlatformCondition', cond)
        SequencerConditionTools.clear_track_row_condition(track, 0)
        self.assertEqual(SequencerConditionTools.get_track_row_condition(track, 0), "")

    # ====================================================================
    # Binding Management
    # ====================================================================
