# Copyright Epic Games, Inc. All Rights Reserved.

from contextlib import ExitStack
import json
import unittest

import unreal

from toolset_registry.tests.automation import create_temp_folder
from animation_toolset.toolsets.sequencer import SequencerTools
from sequencer_animmixer_toolset.toolsets.mixer import SequencerAnimMixerTools

# Path to the UEFN Mannequin skeletal mesh used for spawning test actors.
_MANNEQUIN_MESH_PATH = (
    '/Game/Characters/UEFN_Mannequin/Meshes/SKM_UEFN_Mannequin'
)

_ANIM_PATH = (
    '/Game/Characters/UEFN_Mannequin/Animations/Idle/'
    'M_Neutral_Stand_Idle_Loop'
)


class SequencerAnimMixerTestCase(unittest.TestCase):
    """Tests for the SequencerAnimMixerTools toolset."""

    def setUp(self):
        super().setUp()
        self._stack = ExitStack()
        self._test_folder = self._stack.enter_context(create_temp_folder())

        self.sequence = SequencerTools.create_level_sequence(
            self._test_folder, 'MixerTestSequence'
        )
        unreal.LevelSequenceEditorBlueprintLibrary.open_level_sequence(
            self.sequence
        )
        SequencerTools.set_playback_range(self.sequence, 0, 120)

        mesh = unreal.load_asset(_MANNEQUIN_MESH_PATH)
        if not mesh:
            self.skipTest(f'Mannequin mesh not found at {_MANNEQUIN_MESH_PATH}')
        self.actor = unreal.EditorLevelLibrary.spawn_actor_from_class(
            unreal.SkeletalMeshActor,
            unreal.Vector(0, 0, 0),
            unreal.Rotator(0, 0, 0),
        )
        if not self.actor:
            self.skipTest('Failed to spawn SkeletalMeshActor')
        skel_comp = self.actor.get_editor_property('skeletal_mesh_component')
        skel_comp.set_skeletal_mesh_asset(mesh)

        subsystem = unreal.get_editor_subsystem(
            unreal.LevelSequenceEditorSubsystem
        )
        bindings = subsystem.add_actors([self.actor])
        self.binding = bindings[0]

        # Add a mixer track for tests to use.
        self.mixer_track = SequencerTools.add_track_to_binding(
            self.binding,
            unreal.MovieSceneAnimationMixerTrack.static_class()
        )

    def tearDown(self) -> None:
        try:
            unreal.LevelSequenceEditorBlueprintLibrary.empty_selection()
        except Exception:
            pass
        try:
            editor_actor_sub = unreal.get_editor_subsystem(
                unreal.EditorActorSubsystem
            )
            editor_actor_sub.clear_actor_selection_set()
        except Exception:
            pass
        unreal.LevelSequenceEditorBlueprintLibrary.close_level_sequence()
        if self.actor:
            self.actor.destroy_actor()
        self.sequence = None
        self.binding = None
        self.actor = None
        self.mixer_track = None
        self._stack.close()
        super().tearDown()

    # ====================================================================
    # Layers
    # ====================================================================

    def test_add_and_count_layers(self):
        """Add layers and verify the count increases."""
        initial = SequencerAnimMixerTools.get_mixer_layer_count(self.mixer_track)
        SequencerAnimMixerTools.add_mixer_layer(self.mixer_track)
        SequencerAnimMixerTools.add_mixer_layer(self.mixer_track)
        self.assertEqual(
            SequencerAnimMixerTools.get_mixer_layer_count(self.mixer_track),
            initial + 2
        )

    def test_get_mixer_layers(self):
        """get_mixer_layers returns layer objects matching the count."""
        initial_count = SequencerAnimMixerTools.get_mixer_layer_count(self.mixer_track)
        SequencerAnimMixerTools.add_mixer_layer(self.mixer_track)
        SequencerAnimMixerTools.add_mixer_layer(self.mixer_track)
        layers = SequencerAnimMixerTools.get_mixer_layers(self.mixer_track)
        self.assertEqual(len(layers), initial_count + 2)

    def test_insert_mixer_layer(self):
        """Insert a layer at index 0 and verify count increases."""
        SequencerAnimMixerTools.add_mixer_layer(self.mixer_track)
        SequencerAnimMixerTools.add_mixer_layer(self.mixer_track)
        count_before = SequencerAnimMixerTools.get_mixer_layer_count(self.mixer_track)
        layer = SequencerAnimMixerTools.insert_mixer_layer(self.mixer_track, 0)
        self.assertIsNotNone(layer)
        count_after = SequencerAnimMixerTools.get_mixer_layer_count(self.mixer_track)
        self.assertEqual(count_after, count_before + 1)

    def test_layer_name_roundtrip(self):
        """Set and get a layer name."""
        layer = SequencerAnimMixerTools.add_mixer_layer(self.mixer_track)
        SequencerAnimMixerTools.set_layer_name(layer, 'TestLayer')
        result = SequencerAnimMixerTools.get_layer_name(layer)
        self.assertEqual(result, 'TestLayer')

    def test_is_layer_empty(self):
        """A newly created layer should be empty."""
        layer = SequencerAnimMixerTools.add_mixer_layer(self.mixer_track)
        self.assertTrue(SequencerAnimMixerTools.is_layer_empty(layer))

    def test_get_layer_sections_empty(self):
        """An empty layer should have no sections."""
        layer = SequencerAnimMixerTools.add_mixer_layer(self.mixer_track)
        sections = SequencerAnimMixerTools.get_layer_sections(layer)
        self.assertEqual(len(sections), 0)

    def test_get_layer_index(self):
        """Layer index should match insertion order."""
        layer_a = SequencerAnimMixerTools.add_mixer_layer(self.mixer_track)
        layer_b = SequencerAnimMixerTools.add_mixer_layer(self.mixer_track)
        idx_a = SequencerAnimMixerTools.get_layer_index(layer_a)
        idx_b = SequencerAnimMixerTools.get_layer_index(layer_b)
        self.assertLess(idx_a, idx_b)

    # ====================================================================
    # Animation content
    # ====================================================================

    def test_add_animation_to_mixer(self):
        """Add an animation to a layer and verify the layer is no longer empty."""
        anim = unreal.load_asset(_ANIM_PATH)
        if not anim:
            self.skipTest(f'Animation asset not found at {_ANIM_PATH}')
        layer = SequencerAnimMixerTools.add_mixer_layer(self.mixer_track)
        layers = SequencerAnimMixerTools.get_mixer_layers(self.mixer_track)
        layer_index = SequencerAnimMixerTools.get_layer_index(layer)
        section = SequencerAnimMixerTools.add_animation_to_mixer(
            self.mixer_track, layer_index, 0, anim
        )
        self.assertIsNotNone(section)
        self.assertFalse(SequencerAnimMixerTools.is_layer_empty(layer))
        sections = SequencerAnimMixerTools.get_layer_sections(layer)
        self.assertEqual(len(sections), 1)

    def test_add_child_track_to_layer(self):
        """Add a child track to a mixer layer and verify the layer has content."""
        layer = SequencerAnimMixerTools.add_mixer_layer(self.mixer_track)
        layer_index = SequencerAnimMixerTools.get_layer_index(layer)
        self.assertTrue(SequencerAnimMixerTools.is_layer_empty(layer))
        child = SequencerAnimMixerTools.add_child_track_to_layer(
            self.mixer_track, self.binding,
            unreal.MovieSceneControlRigParameterTrack.static_class(),
            layer_index
        )
        self.assertIsNotNone(child)
        # Layer should no longer be empty after adding a child track.
        self.assertFalse(SequencerAnimMixerTools.is_layer_empty(layer))

    # ====================================================================
    # Transitions
    # ====================================================================

    def test_get_transitions_for_section_with_overlap(self):
        """Overlapping sections should produce at least one transition."""
        anim = unreal.load_asset(_ANIM_PATH)
        if not anim:
            self.skipTest(f'Animation asset not found at {_ANIM_PATH}')
        layer = SequencerAnimMixerTools.add_mixer_layer(self.mixer_track)
        layer_index = SequencerAnimMixerTools.get_layer_index(layer)
        sec_a = SequencerAnimMixerTools.add_animation_to_mixer(
            self.mixer_track, layer_index, 0, anim
        )
        sec_b = SequencerAnimMixerTools.add_animation_to_mixer(
            self.mixer_track, layer_index, 30, anim
        )
        transitions = SequencerAnimMixerTools.get_transitions_for_section(
            self.mixer_track, sec_a
        )
        self.assertGreaterEqual(len(transitions), 1)
        # Each transition should be a valid object.
        for t in transitions:
            self.assertTrue(
                SequencerAnimMixerTools.get_transition_info(t) is not None
            )

    def test_get_transition_between_overlapping(self):
        """get_transition_between returns a transition for overlapping sections."""
        anim = unreal.load_asset(_ANIM_PATH)
        if not anim:
            self.skipTest(f'Animation asset not found at {_ANIM_PATH}')
        layer = SequencerAnimMixerTools.add_mixer_layer(self.mixer_track)
        layer_index = SequencerAnimMixerTools.get_layer_index(layer)
        sec_a = SequencerAnimMixerTools.add_animation_to_mixer(
            self.mixer_track, layer_index, 0, anim
        )
        sec_b = SequencerAnimMixerTools.add_animation_to_mixer(
            self.mixer_track, layer_index, 30, anim
        )
        transition = SequencerAnimMixerTools.get_transition_between(
            self.mixer_track, sec_a, sec_b
        )
        self.assertIsNotNone(transition)
        name = SequencerAnimMixerTools.get_transition_name(transition)
        self.assertIsInstance(name, str)
        self.assertGreater(len(name), 0)

    def test_transition_info_and_name(self):
        """Verify transition info and name on overlapping sections."""
        anim = unreal.load_asset(_ANIM_PATH)
        if not anim:
            self.skipTest(f'Animation asset not found at {_ANIM_PATH}')
        layer = SequencerAnimMixerTools.add_mixer_layer(self.mixer_track)
        layer_index = SequencerAnimMixerTools.get_layer_index(layer)
        sec_a = SequencerAnimMixerTools.add_animation_to_mixer(
            self.mixer_track, layer_index, 0, anim
        )
        sec_b = SequencerAnimMixerTools.add_animation_to_mixer(
            self.mixer_track, layer_index, 30, anim
        )
        transition = SequencerAnimMixerTools.get_transition_between(
            self.mixer_track, sec_a, sec_b
        )
        if not transition:
            transitions = SequencerAnimMixerTools.get_transitions_for_section(
                self.mixer_track, sec_a
            )
            if transitions:
                transition = transitions[0]
        if transition:
            info_str = SequencerAnimMixerTools.get_transition_info(transition)
            info = json.loads(info_str)
            self.assertIn('name', info)
            self.assertIn('is_valid', info)
            name = SequencerAnimMixerTools.get_transition_name(transition)
            self.assertIsInstance(name, str)
            self.assertGreater(len(name), 0)

    def test_change_transition_type(self):
        """Change a transition's type and verify it returns a new object."""
        anim = unreal.load_asset(_ANIM_PATH)
        if not anim:
            self.skipTest(f'Animation asset not found at {_ANIM_PATH}')
        layer = SequencerAnimMixerTools.add_mixer_layer(self.mixer_track)
        layer_index = SequencerAnimMixerTools.get_layer_index(layer)
        sec_a = SequencerAnimMixerTools.add_animation_to_mixer(
            self.mixer_track, layer_index, 0, anim
        )
        sec_b = SequencerAnimMixerTools.add_animation_to_mixer(
            self.mixer_track, layer_index, 30, anim
        )
        transitions = SequencerAnimMixerTools.get_transitions_for_section(
            self.mixer_track, sec_a
        )
        if not transitions:
            transitions = SequencerAnimMixerTools.get_transitions_for_section(
                self.mixer_track, sec_b
            )
        if transitions:
            transition = transitions[0]
            original_name = SequencerAnimMixerTools.get_transition_name(transition)
            self.assertGreater(len(original_name), 0)
            # Change to same type as a safe roundtrip.
            new_t = SequencerAnimMixerTools.change_transition_type(
                transition, transition.get_class()
            )
            self.assertIsNotNone(new_t)

    # ====================================================================
    # Decorations
    # ====================================================================

    def test_get_compatible_decorations(self):
        """Compatible decorations should return a non-empty list of classes."""
        layer = SequencerAnimMixerTools.add_mixer_layer(self.mixer_track)
        compat = SequencerAnimMixerTools.get_compatible_decorations(layer)
        self.assertGreaterEqual(len(compat), 1)
        # Each entry should be a UClass.
        for cls in compat:
            self.assertTrue(hasattr(cls, 'get_name'))

    def test_add_get_remove_decoration(self):
        """Add, find, and remove a decoration on a mixer layer."""
        layer = SequencerAnimMixerTools.add_mixer_layer(self.mixer_track)
        try:
            compat = SequencerAnimMixerTools.get_compatible_decorations(layer)
        except Exception:
            self.skipTest('Layer does not support decorations')
        if not compat:
            self.skipTest('No compatible decoration types available')
        deco_class = compat[0]
        decoration = SequencerAnimMixerTools.add_decoration(layer, deco_class)
        self.assertIsNotNone(decoration)
        found = SequencerAnimMixerTools.find_decoration(layer, deco_class)
        self.assertIsNotNone(found)
        all_decos = SequencerAnimMixerTools.get_decorations(layer)
        self.assertGreaterEqual(len(all_decos), 1)
        SequencerAnimMixerTools.remove_decoration(layer, deco_class)
        found_after = SequencerAnimMixerTools.find_decoration(layer, deco_class)
        self.assertIsNone(found_after)
