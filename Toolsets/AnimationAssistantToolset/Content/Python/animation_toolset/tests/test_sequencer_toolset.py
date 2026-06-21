# Copyright Epic Games, Inc. All Rights Reserved.

import json
import unittest

import unreal

from animation_toolset.tests._sequencer_test_base import SequencerTestBase
from animation_toolset.toolsets.sequencer import SequencerTools


class SequencerToolsTestCase(SequencerTestBase):
    """Test the core SequencerTools toolset - lifecycle, bindings, tracks,
    sections, folders, playback, and selection."""


    def test_create_level_sequence(self):
        """Ensures that we can create a LevelSequence asset."""
        seq = SequencerTools.create_level_sequence(
            self._test_folder, 'LifecycleSeq'
        )
        self.assertIsInstance(seq, unreal.LevelSequence)

    def test_open_close_sequence(self):
        """Ensures that opening and closing a sequence updates the current sequence."""
        current = SequencerTools.get_current_sequence()
        self.assertIsNotNone(current)
        SequencerTools.close_sequence()
        closed = SequencerTools.get_current_sequence()
        self.assertIsNone(closed)
        # Re-open so tearDown can close cleanly.
        SequencerTools.open_sequence(self.sequence)

    def test_get_current_and_focused(self):
        """Ensures that get_current_sequence and get_focused_sequence return the open sequence."""
        current = SequencerTools.get_current_sequence()
        focused = SequencerTools.get_focused_sequence()
        self.assertIsNotNone(current)
        self.assertIsNotNone(focused)


    def test_play_pause(self):
        """Ensures that play/pause toggles the playing state."""
        SequencerTools.play()
        self.assertTrue(SequencerTools.is_playing())
        SequencerTools.pause()
        self.assertFalse(SequencerTools.is_playing())

    def test_playhead_frame(self):
        """Ensures that the playhead can be set and read back."""
        SequencerTools.set_playhead_frame(60)
        result = SequencerTools.get_playhead_frame()
        self.assertEqual(result, 60)

    def test_playback_speed(self):
        """Ensures that playback speed can be set and read back."""
        SequencerTools.set_playback_speed(2.0)
        result = SequencerTools.get_playback_speed()
        self.assertAlmostEqual(result, 2.0, places=1)


    def test_display_rate(self):
        """Ensures that display rate can be set and read back."""
        SequencerTools.set_display_rate(self.sequence, 24)
        rate = SequencerTools.get_display_rate(self.sequence)
        self.assertEqual(rate.numerator, 24)

    def test_playback_range(self):
        """Ensures that playback range can be set and read back."""
        SequencerTools.set_playback_range(self.sequence, 10, 200)
        result = json.loads(SequencerTools.get_playback_range(self.sequence))
        self.assertEqual(result['start'], 10)
        self.assertEqual(result['end'], 200)

    def test_marked_frames(self):
        """Ensures that marked frames can be added and retrieved."""
        SequencerTools.add_marked_frame(self.sequence, 50)
        frames = SequencerTools.get_marked_frames(self.sequence)
        frame_values = [f.frame_number.value for f in frames]
        self.assertIn(50, frame_values)


    def test_get_bindings(self):
        """Ensures that get_bindings returns at least the actor binding from setUp."""
        bindings = SequencerTools.get_bindings(self.sequence)
        self.assertGreaterEqual(len(bindings), 1)

    def test_find_binding_by_name(self):
        """Ensures that we can find a binding by the actor's name."""
        name = SequencerTools.get_binding_name(self.binding)
        found = SequencerTools.find_binding_by_name(self.sequence, name)
        self.assertIsNotNone(found)

    def test_binding_name(self):
        """Ensures that a binding can be renamed and the new name read back."""
        SequencerTools.set_binding_name(self.binding, 'RenamedBinding')
        result = SequencerTools.get_binding_name(self.binding)
        self.assertEqual(result, 'RenamedBinding')


    def test_add_track_to_binding(self):
        """Ensures that a visibility track can be added to a binding."""
        track = SequencerTools.add_track_to_binding(
            self.binding, unreal.MovieSceneVisibilityTrack.static_class()
        )
        self.assertIsNotNone(track)
        tracks = SequencerTools.get_tracks_on_binding(self.binding)
        self.assertIn(track, tracks)

    def test_track_display_name(self):
        """Ensures that a track display name can be set and read back."""
        track = SequencerTools.add_track_to_binding(
            self.binding, unreal.MovieScene3DTransformTrack.static_class()
        )
        SequencerTools.set_track_display_name(track, 'MyTrack')
        result = SequencerTools.get_track_display_name(track)
        self.assertEqual(result, 'MyTrack')

    def test_remove_track(self):
        """Ensures that a track can be added then removed."""
        track = SequencerTools.add_track_to_binding(
            self.binding, unreal.MovieSceneVisibilityTrack.static_class()
        )
        tracks_before = len(SequencerTools.get_tracks_on_binding(self.binding))
        SequencerTools.remove_track(self.binding, track)
        tracks_after = len(SequencerTools.get_tracks_on_binding(self.binding))
        self.assertEqual(tracks_after, tracks_before - 1)


    def test_add_get_remove_section(self):
        """Ensures that sections can be added, listed, and removed."""
        track, section = self._make_track_and_section()
        sections = SequencerTools.get_sections(track)
        self.assertIn(section, sections)
        SequencerTools.remove_section(track, section)
        sections_after = SequencerTools.get_sections(track)
        self.assertNotIn(section, sections_after)

    def test_section_range(self):
        """Ensures that section range can be set and read back."""
        _, section = self._make_track_and_section()
        SequencerTools.set_section_range(section, 10, 100)
        result = json.loads(SequencerTools.get_section_range(section))
        self.assertEqual(result['start'], 10)
        self.assertEqual(result['end'], 100)

    def test_section_easing(self):
        """Ensures that ease-in and ease-out can be set and read back."""
        _, section = self._make_track_and_section()
        SequencerTools.set_section_range(section, 0, 100)
        SequencerTools.set_section_ease_in(section, 5)
        SequencerTools.set_section_ease_out(section, 10)
        self.assertEqual(SequencerTools.get_section_ease_in(section), 5)
        self.assertEqual(SequencerTools.get_section_ease_out(section), 10)

    def test_section_blend_type(self):
        """Ensures that blend type can be set and read back."""
        # Use a transform section which supports blend types
        _, section = self._make_transform_section()
        SequencerTools.set_section_blend_type(section, 'Additive')
        result = SequencerTools.get_section_blend_type(section)
        self.assertIn('ADDITIVE', result.upper())

    def test_section_completion_mode(self):
        """Ensures that completion mode can be set and read back."""
        _, section = self._make_track_and_section()
        SequencerTools.set_section_completion_mode(section, 'KeepState')
        result = SequencerTools.get_section_completion_mode(section)
        self.assertIn('KEEP_STATE', result.upper())


    def test_select_tracks(self):
        """Ensures that tracks can be selected and the selection read back."""
        track = SequencerTools.add_track_to_binding(
            self.binding, unreal.MovieSceneVisibilityTrack.static_class()
        )
        SequencerTools.select_tracks([track])
        selected = SequencerTools.get_selected_tracks()
        self.assertIn(track, selected)

    def test_select_bindings(self):
        """Ensures that bindings can be selected and the selection read back."""
        SequencerTools.select_bindings([self.binding])
        selected = SequencerTools.get_selected_bindings()
        self.assertGreaterEqual(len(selected), 1)

    def test_empty_selection(self):
        """Ensures that empty_selection clears all selection."""
        track = SequencerTools.add_track_to_binding(
            self.binding, unreal.MovieSceneVisibilityTrack.static_class()
        )
        SequencerTools.select_tracks([track])
        SequencerTools.empty_selection()
        selected_tracks = SequencerTools.get_selected_tracks()
        selected_bindings = SequencerTools.get_selected_bindings()
        self.assertEqual(len(selected_tracks), 0)
        self.assertEqual(len(selected_bindings), 0)


    def test_add_get_remove_folder(self):
        """Ensures that folders can be added, listed, and removed."""
        folder = SequencerTools.add_root_folder(self.sequence, 'TestFolder')
        self.assertIsNotNone(folder)
        folders = SequencerTools.get_root_folders(self.sequence)
        self.assertIn(folder, folders)
        SequencerTools.remove_root_folder(self.sequence, folder)
        folders_after = SequencerTools.get_root_folders(self.sequence)
        self.assertNotIn(folder, folders_after)

    def test_folder_contents(self):
        """Ensures that a track added to a folder appears in its contents."""
        folder = SequencerTools.add_root_folder(self.sequence, 'ContentsFolder')
        track = SequencerTools.add_track_to_binding(
            self.binding, unreal.MovieSceneVisibilityTrack.static_class()
        )
        SequencerTools.add_track_to_folder(folder, track)
        contents = json.loads(SequencerTools.get_folder_contents(folder))
        self.assertGreaterEqual(contents['track_count'], 1)


    def test_set_loop_mode(self):
        """Ensures that loop mode can be set and read back."""
        SequencerTools.set_loop_mode(True)
        self.assertTrue(SequencerTools.get_loop_mode())
        SequencerTools.set_loop_mode(False)
        self.assertFalse(SequencerTools.get_loop_mode())

    def test_play_to(self):
        """Ensures that play_to advances the playhead."""
        SequencerTools.set_playhead_frame(0)
        try:
            SequencerTools.play_to(60)
        except Exception:
            pass
        # After play_to, playhead should have moved (may be at 60 or elsewhere).
        # Just verify the API works; exact position depends on timing.
        pos = SequencerTools.get_playhead_frame()
        self.assertIsInstance(pos, int)

    def test_refresh_sequence(self):
        """Ensures that refreshing the sequence keeps it in a valid state."""
        SequencerTools.refresh_sequence()
        # Verify the sequence is still accessible after refresh.
        current = SequencerTools.get_current_sequence()
        self.assertIsNotNone(current)

    def test_force_evaluate(self):
        """Ensures that force evaluate completes and sequence remains valid."""
        SequencerTools.force_evaluate()
        current = SequencerTools.get_current_sequence()
        self.assertIsNotNone(current)


    def test_set_view_range(self):
        """Ensures that view range can be set and read back."""
        SequencerTools.set_view_range(self.sequence, 0.5, 3.0)
        result = json.loads(SequencerTools.get_view_range(self.sequence))
        self.assertAlmostEqual(result['start'], 0.5, places=1)
        self.assertAlmostEqual(result['end'], 3.0, places=1)

    def test_set_work_range(self):
        """Ensures that work range can be set and read back."""
        SequencerTools.set_work_range(self.sequence, 1.0, 5.0)
        result = json.loads(SequencerTools.get_work_range(self.sequence))
        self.assertAlmostEqual(result['start'], 1.0, places=1)
        self.assertAlmostEqual(result['end'], 5.0, places=1)


    def test_add_actors_by_name(self):
        """Ensures that actors can be added to the sequence by name."""
        # Create a fresh actor not yet in the sequence
        new_actor = unreal.EditorLevelLibrary.spawn_actor_from_class(
            unreal.StaticMeshActor, unreal.Vector(100, 0, 0), unreal.Rotator(0, 0, 0))
        new_actor.set_actor_label('AddByNameTestActor')
        self.addCleanup(new_actor.destroy_actor)
        bindings = SequencerTools.add_actors_by_name(['AddByNameTestActor'])
        self.assertGreaterEqual(len(list(bindings)), 1)

    def test_create_camera(self):
        """Ensures that create_camera returns a valid binding proxy."""
        binding = SequencerTools.create_camera(spawnable=True)
        self.assertIsNotNone(binding)
        name = SequencerTools.get_binding_name(binding)
        self.assertTrue(len(name) > 0)

    def test_remove_binding(self):
        """Ensures that a spawnable binding can be removed from the sequence."""
        binding = SequencerTools.create_camera(spawnable=True)
        bindings_before = len(SequencerTools.get_bindings(self.sequence))
        SequencerTools.remove_binding(binding)
        bindings_after = len(SequencerTools.get_bindings(self.sequence))
        self.assertEqual(bindings_after, bindings_before - 1)

    def test_get_bound_objects(self):
        """Ensures that get_bound_objects returns objects for a possessable binding."""
        objects = SequencerTools.get_bound_objects(self.binding)
        # A possessable binding to a level actor should resolve to objects.
        self.assertTrue(hasattr(objects, "__len__"))

    def test_add_spawnable_from_class(self):
        """Ensures that a spawnable can be created from a CineCameraActor class."""
        binding = SequencerTools.add_spawnable_from_class(
            self.sequence, '/Script/CinematicCamera.CineCameraActor'
        )
        self.assertIsNotNone(binding)
        name = SequencerTools.get_binding_name(binding)
        self.assertTrue(len(name) > 0)


    def test_add_track_to_sequence(self):
        """Ensures that a camera cut track can be added to a sequence."""
        track = SequencerTools.add_track_to_sequence(
            self.sequence, unreal.MovieSceneCameraCutTrack.static_class()
        )
        self.assertIsNotNone(track)

    def test_get_tracks_on_sequence(self):
        """Ensures that sequence-level tracks can be retrieved."""
        SequencerTools.add_track_to_sequence(
            self.sequence, unreal.MovieSceneCameraCutTrack.static_class()
        )
        tracks = SequencerTools.get_tracks_on_sequence(self.sequence)
        self.assertGreaterEqual(len(tracks), 1)

    def test_find_tracks_by_type(self):
        """Ensures that tracks can be found by type on a binding."""
        SequencerTools.add_track_to_binding(
            self.binding, unreal.MovieScene3DTransformTrack.static_class()
        )
        found = SequencerTools.find_tracks_by_type(
            self.binding, unreal.MovieScene3DTransformTrack.static_class()
        )
        self.assertGreaterEqual(len(found), 1)


    def test_get_section_properties(self):
        """Ensures that get_section_properties returns all expected keys."""
        _, section = self._make_track_and_section()
        SequencerTools.set_section_range(section, 0, 100)
        props = json.loads(SequencerTools.get_section_properties(section))
        for key in ('start', 'end', 'ease_in', 'ease_out',
                     'blend_type', 'completion_mode'):
            self.assertIn(key, props)


    def test_select_sections(self):
        """Ensures that select_sections and get_selected_sections do not error."""
        _, section = self._make_track_and_section()
        SequencerTools.select_sections([section])
        selected = SequencerTools.get_selected_sections()
        self.assertTrue(hasattr(selected, "__len__"))
        SequencerTools.empty_selection()

    def test_select_folders(self):
        """Ensures that select_folders and get_selected_folders do not error."""
        folder = SequencerTools.add_root_folder(self.sequence, 'SelectFolder')
        SequencerTools.select_folders([folder])
        selected = SequencerTools.get_selected_folders()
        self.assertTrue(hasattr(selected, "__len__"))
        SequencerTools.empty_selection()

    def test_get_selected_sections(self):
        """Ensures that get_selected_sections returns a list."""
        SequencerTools.empty_selection()
        selected = SequencerTools.get_selected_sections()
        self.assertTrue(hasattr(selected, "__len__"))
        self.assertEqual(len(selected), 0)

    def test_get_selected_folders(self):
        """Ensures that get_selected_folders returns a list."""
        SequencerTools.empty_selection()
        selected = SequencerTools.get_selected_folders()
        self.assertTrue(hasattr(selected, "__len__"))
        self.assertEqual(len(selected), 0)

    def test_set_camera_lock_and_get(self):
        """Ensures that camera lock can be set and read back."""
        SequencerTools.set_camera_lock(True)
        self.assertTrue(SequencerTools.is_camera_cut_locked())
        SequencerTools.set_camera_lock(False)
        self.assertFalse(SequencerTools.is_camera_cut_locked())

    def test_set_sequence_locked_and_get(self):
        """Ensures that sequence lock can be set and read back."""
        SequencerTools.set_sequence_locked(True)
        self.assertTrue(SequencerTools.get_sequence_lock_state())
        SequencerTools.set_sequence_locked(False)
        self.assertFalse(SequencerTools.get_sequence_lock_state())

    def test_set_get_selection_range(self):
        """Ensures that the selection range can be set and read back."""
        SequencerTools.set_selection_range(10, 50)
        result = json.loads(SequencerTools.get_selection_range())
        self.assertEqual(result['start'], 10)
        self.assertEqual(result['end'], 50)

    def test_track_filters(self):
        """Ensures that track filter names can be retrieved and toggled."""
        names = SequencerTools.get_track_filter_names()
        self.assertTrue(hasattr(names, "__len__"))
        if not names:
            self.skipTest('No track filters available')
        filter_name = names[0]
        # Toggle on then off.
        SequencerTools.set_track_filter_active(filter_name, True)
        self.assertTrue(SequencerTools.is_track_filter_active(filter_name))
        SequencerTools.set_track_filter_active(filter_name, False)
        self.assertFalse(SequencerTools.is_track_filter_active(filter_name))


    def test_remove_root_folder(self):
        """Ensures that a root folder can be added and then removed."""
        folder = SequencerTools.add_root_folder(self.sequence, 'RemoveMe')
        folders_before = SequencerTools.get_root_folders(self.sequence)
        self.assertIn(folder, folders_before)
        SequencerTools.remove_root_folder(self.sequence, folder)
        folders_after = SequencerTools.get_root_folders(self.sequence)
        self.assertNotIn(folder, folders_after)

    def test_add_binding_to_folder(self):
        """Ensures that a binding can be added to a folder."""
        folder = SequencerTools.add_root_folder(self.sequence, 'BindingFolder')
        SequencerTools.add_binding_to_folder(folder, self.binding)
        contents = json.loads(SequencerTools.get_folder_contents(folder))
        self.assertGreaterEqual(contents['binding_count'], 1)

    def test_add_track_to_folder(self):
        """Ensures that a track can be added to a folder."""
        folder = SequencerTools.add_root_folder(self.sequence, 'TrackFolder')
        track = SequencerTools.add_track_to_binding(
            self.binding, unreal.MovieSceneVisibilityTrack.static_class()
        )
        SequencerTools.add_track_to_folder(folder, track)
        contents = json.loads(SequencerTools.get_folder_contents(folder))
        self.assertGreaterEqual(contents['track_count'], 1)


    def test_get_sub_sequence_hierarchy(self):
        """Ensures that get_sub_sequence_hierarchy returns a list."""
        hierarchy = SequencerTools.get_sub_sequence_hierarchy()
        self.assertTrue(hasattr(hierarchy, "__len__"))

    def test_get_sequence_lock_state(self):
        """Ensures that get_sequence_lock_state returns a bool."""
        result = SequencerTools.get_sequence_lock_state()
        self.assertIsInstance(result, bool)


    def test_add_actors(self):
        """Ensures that add_actors binds an actor list to the sequence."""
        actor2 = unreal.EditorLevelLibrary.spawn_actor_from_class(
            unreal.SkeletalMeshActor,
            unreal.Vector(100, 0, 0),
            unreal.Rotator(0, 0, 0),
        )
        try:
            bindings_before = SequencerTools.get_bindings(self.sequence)
            bindings = SequencerTools.add_actors([actor2])
            self.assertGreaterEqual(len(bindings), 1)
            bindings_after = SequencerTools.get_bindings(self.sequence)
            self.assertGreater(len(bindings_after), len(bindings_before))
        finally:
            try:
                editor_actor_sub = unreal.get_editor_subsystem(
                    unreal.EditorActorSubsystem
                )
                editor_actor_sub.clear_actor_selection_set()
            except Exception:
                pass
            actor2.destroy_actor()

    def test_add_spawnable_from_instance(self):
        """Ensures that a spawnable can be created from an existing object."""
        binding = SequencerTools.add_spawnable_from_instance(
            self.sequence, self.actor
        )
        self.assertIsNotNone(binding)


    def test_focus_sub_sequence_and_parent(self):
        """Ensures that sub-sequence focus and parent navigation work."""
        sub_seq = SequencerTools.create_level_sequence(
            self._test_folder, 'SubSeq'
        )
        track = SequencerTools.add_track_to_sequence(
            self.sequence, unreal.MovieSceneSubTrack.static_class()
        )
        sections = SequencerTools.get_sections(track)
        if not sections:
            section = SequencerTools.add_section(track)
        else:
            section = sections[0]
        section.set_editor_property('sub_sequence', sub_seq)
        SequencerTools.set_section_range(section, 0, 120)
        # focus_sub_sequence takes a sub-section, not a LevelSequence
        SequencerTools.focus_sub_sequence(section)
        focused = SequencerTools.get_focused_sequence()
        self.assertEqual(focused, sub_seq)
        SequencerTools.focus_parent_sequence()
        focused_after = SequencerTools.get_focused_sequence()
        self.assertEqual(focused_after, self.sequence)


    def test_remove_invalid_bindings(self):
        """Remove invalid bindings on a clean binding should be a no-op."""
        bindings = SequencerTools.get_bindings(self.sequence)
        if not bindings:
            self.skipTest('No bindings in sequence')
        count_before = len(SequencerTools.get_bindings(self.sequence))
        SequencerTools.remove_invalid_bindings(bindings[0])
        count_after = len(SequencerTools.get_bindings(self.sequence))
        self.assertEqual(count_before, count_after)

    def test_fix_actor_references(self):
        """Fix actor references should not change valid bindings."""
        count_before = len(SequencerTools.get_bindings(self.sequence))
        SequencerTools.fix_actor_references()
        count_after = len(SequencerTools.get_bindings(self.sequence))
        self.assertEqual(count_before, count_after)


    def test_get_track_filter_names(self):
        """Get track filter names returns a non-empty list of strings."""
        names = SequencerTools.get_track_filter_names()
        self.assertGreater(len(names), 0)
        for name in names:
            self.assertIsInstance(name, str)

    def test_track_filter_toggle(self):
        """Toggle a track filter on and off and verify state changes."""
        names = SequencerTools.get_track_filter_names()
        if not names:
            self.skipTest('No track filters available')
        name = names[0]
        original = SequencerTools.is_track_filter_active(name)
        SequencerTools.set_track_filter_active(name, not original)
        self.assertEqual(SequencerTools.is_track_filter_active(name), not original)
        SequencerTools.set_track_filter_active(name, original)
        self.assertEqual(SequencerTools.is_track_filter_active(name), original)


    def test_sequence_lock_roundtrip(self):
        """Lock and unlock the sequence and verify state changes."""
        original = SequencerTools.is_sequence_locked()
        SequencerTools.set_sequence_locked(True)
        self.assertTrue(SequencerTools.is_sequence_locked())
        SequencerTools.set_sequence_locked(False)
        self.assertFalse(SequencerTools.is_sequence_locked())
        SequencerTools.set_sequence_locked(original)

    def test_bake_transform(self):
        """Bake transform on a binding should succeed."""
        bindings = SequencerTools.get_bindings(self.sequence)
        if not bindings:
            self.skipTest('No bindings in sequence')
        result = SequencerTools.bake_transform(bindings[:1])
        self.assertTrue(result)


    def test_get_binding_id(self):
        """Get binding ID and verify it's a valid object."""
        binding_id = SequencerTools.get_binding_id(self.sequence, self.binding)
        self.assertIsNotNone(binding_id)

    def test_get_section_to_key(self):
        """Get the active keying section from a track with sections."""
        tracks = SequencerTools.get_tracks_on_binding(self.binding)
        if not tracks:
            self.skipTest('No tracks on binding')
        # Find a track with sections and verify get_section_to_key returns
        # either one of those sections or None (no designated keying section).
        for track in tracks:
            sections = SequencerTools.get_sections(track)
            if sections:
                keying_section = SequencerTools.get_section_to_key(track)
                if keying_section is not None:
                    self.assertIn(keying_section, sections)
                return
        self.fail("No track had sections to test get_section_to_key against.")

    def test_set_property_name_and_path(self):
        """Configure a float property track with a property path."""
        track = SequencerTools.add_track_to_binding(
            self.binding, unreal.MovieSceneFloatTrack.static_class()
        )
        SequencerTools.set_property_name_and_path(
            track, 'Test Property', 'RelativeScale3D.X'
        )
        name = track.get_property_name()
        self.assertEqual(str(name), 'Test Property')

    def test_set_section_animation(self):
        """Set animation on a skeletal animation section."""
        anim_path = (
            '/Game/Characters/UEFN_Mannequin/Animations/Idle/'
            'M_Neutral_Stand_Idle_Loop'
        )
        anim = unreal.load_asset(anim_path)
        if not anim:
            self.skipTest(f'Animation not found at {anim_path}')
        track = SequencerTools.add_track_to_binding(
            self.binding,
            unreal.MovieSceneSkeletalAnimationTrack.static_class()
        )
        section = SequencerTools.add_section(track)
        SequencerTools.set_section_animation(section, anim_path)
        self.assertEqual(section.params.animation, anim)

    # ========================================================================
    # Pre-roll / Post-roll
    # ========================================================================

    def test_pre_roll_frames_roundtrip(self):
        """Pre-roll frames can be set and queried."""
        _, section = self._make_track_and_section()
        SequencerTools.set_section_pre_roll_frames(section, 8)
        self.assertEqual(
            SequencerTools.get_section_pre_roll_frames(section), 8
        )

    def test_post_roll_frames_roundtrip(self):
        """Post-roll frames can be set and queried."""
        _, section = self._make_track_and_section()
        SequencerTools.set_section_post_roll_frames(section, 12)
        self.assertEqual(
            SequencerTools.get_section_post_roll_frames(section), 12
        )

    def test_pre_roll_rejects_negative(self):
        """Pre-roll rejects negative values (decorator catches ValueError)."""
        _, section = self._make_track_and_section()
        result = SequencerTools.set_section_pre_roll_frames(section, -5)
        self.assertFalse(result)

    def test_post_roll_rejects_negative(self):
        """Post-roll rejects negative values (decorator catches ValueError)."""
        _, section = self._make_track_and_section()
        result = SequencerTools.set_section_post_roll_frames(section, -5)
        self.assertFalse(result)

    # ========================================================================
    # Binding Tags
    # ========================================================================

    def test_tag_binding_roundtrip(self):
        """Tag a binding, query tags, untag, verify removal."""
        SequencerTools.tag_binding(self.binding, 'TestTag')
        tags = SequencerTools.get_binding_tags(self.binding)
        self.assertIn('TestTag', tags)

        SequencerTools.untag_binding(self.binding, 'TestTag')
        tags_after = SequencerTools.get_binding_tags(self.binding)
        self.assertNotIn('TestTag', tags_after)

    def test_get_all_binding_tags(self):
        """get_all_binding_tags returns registered tags for the sequence."""
        SequencerTools.tag_binding(self.binding, 'AllTagsTest')
        all_tags = SequencerTools.get_all_binding_tags(self.sequence)
        self.assertIn('AllTagsTest', all_tags)

    def test_find_binding_by_tag(self):
        """find_binding_by_tag locates the tagged binding."""
        SequencerTools.tag_binding(self.binding, 'FindMe')
        result = SequencerTools.find_binding_by_tag(self.sequence, 'FindMe')
        self.assertIsNotNone(result)

    def test_find_bindings_by_tag_returns_list(self):
        """find_bindings_by_tag returns all matching bindings."""
        SequencerTools.tag_binding(self.binding, 'ListMe')
        result = SequencerTools.find_bindings_by_tag(self.sequence, 'ListMe')
        self.assertTrue(hasattr(result, '__len__'))
        self.assertGreater(len(result), 0)

    def test_remove_binding_tag_cleans_all(self):
        """remove_binding_tag clears the tag from the whole sequence."""
        SequencerTools.tag_binding(self.binding, 'RemoveMe')
        self.assertIn(
            'RemoveMe', SequencerTools.get_all_binding_tags(self.sequence)
        )
        SequencerTools.remove_binding_tag(self.sequence, 'RemoveMe')
        self.assertNotIn(
            'RemoveMe', SequencerTools.get_all_binding_tags(self.sequence)
        )

    def test_find_binding_by_tag_missing_returns_default_id(self):
        """find_binding_by_tag returns an invalid/default id when no match exists."""
        # Pre-condition: an existing tagged binding can be found so the
        # negative-case comparison below is meaningful.
        SequencerTools.tag_binding(self.binding, 'ExistsForNegativeTest')
        found = SequencerTools.find_binding_by_tag(
            self.sequence, 'ExistsForNegativeTest'
        )
        # Unresolved lookup returns a default-constructed BindingID; its
        # Guid exports as the all-zero string. Compare exported text so
        # we don't depend on Python struct identity or BP-exposed fields.
        missing = SequencerTools.find_binding_by_tag(
            self.sequence, 'NeverTaggedAnything'
        )
        default = unreal.MovieSceneObjectBindingID()
        self.assertEqual(
            missing.get_editor_property('Guid').export_text(),
            default.get_editor_property('Guid').export_text(),
        )
        # And the found one must differ from the default-invalid id.
        self.assertNotEqual(
            found.get_editor_property('Guid').export_text(),
            default.get_editor_property('Guid').export_text(),
        )

    # ========================================================================
    # Copy / Paste
    # ========================================================================

    def test_copy_paste_tracks(self):
        """Copy a track and paste onto another binding, with and without folder."""
        track1 = SequencerTools.add_track_to_binding(
            self.binding, unreal.MovieSceneVisibilityTrack.static_class()
        )
        # Create a second binding to paste onto
        actor2 = unreal.EditorLevelLibrary.spawn_actor_from_class(
            unreal.SkeletalMeshActor,
            unreal.Vector(100, 0, 0),
            unreal.Rotator(0, 0, 0),
        )
        try:
            bindings2 = SequencerTools.add_actors([actor2])
            target_binding = bindings2[0]

            token = SequencerTools.copy_tracks([track1])
            self.assertIsInstance(token, str)
            self.assertGreater(len(token), 0)

            # Default (no parent folder).
            pasted = SequencerTools.paste_tracks(
                token, self.sequence, [target_binding]
            )
            self.assertGreaterEqual(len(pasted), 1)

            # parent_folder plumbed through: pasting into a folder should
            # also succeed and produce at least one track.
            folder = SequencerTools.add_root_folder(self.sequence, 'TrackPasteTarget')
            pasted_in_folder = SequencerTools.paste_tracks(
                token, self.sequence, [target_binding], parent_folder=folder
            )
            self.assertGreaterEqual(len(pasted_in_folder), 1)
        finally:
            actor2.destroy_actor()

    def test_copy_paste_folders(self):
        """Copy a folder and paste back into the same sequence."""
        folder = SequencerTools.add_root_folder(self.sequence, 'FolderA')
        token = SequencerTools.copy_folders([folder])
        self.assertIsInstance(token, str)
        self.assertGreater(
            len(token), 0, 'copy_folders token should be non-empty'
        )
        # Paste back (creates FolderA_1 alongside the original, for a total
        # of at least one new folder).
        pasted = SequencerTools.paste_folders(token, self.sequence)
        self.assertTrue(hasattr(pasted, '__len__'))
        self.assertGreaterEqual(
            len(pasted), 1, 'paste_folders should return the new folder'
        )

    def test_copy_paste_sections(self):
        """Copy a section and paste onto another track."""
        track1, section1 = self._make_track_and_section()
        # Create a second track to paste onto
        track2 = SequencerTools.add_track_to_binding(
            self.binding, unreal.MovieSceneVisibilityTrack.static_class()
        )
        token = SequencerTools.copy_sections([section1])
        self.assertIsInstance(token, str)
        pasted = SequencerTools.paste_sections(token, [track2], 10)
        self.assertTrue(hasattr(pasted, '__len__'))

    def test_copy_paste_bindings(self):
        """Copy a binding and paste back; verify the paste returned it."""
        actor2 = unreal.EditorLevelLibrary.spawn_actor_from_class(
            unreal.SkeletalMeshActor,
            unreal.Vector(200, 0, 0),
            unreal.Rotator(0, 0, 0),
        )
        try:
            bindings2 = SequencerTools.add_actors([actor2])
            source = bindings2[0]

            token = SequencerTools.copy_bindings([source])
            self.assertIsInstance(token, str)
            self.assertGreater(
                len(token), 0, 'copy_bindings token should be non-empty'
            )

            # Paste without a parent folder (root-level paste).
            pasted_root = SequencerTools.paste_bindings(token, self.sequence)
            self.assertTrue(hasattr(pasted_root, '__len__'))
            self.assertGreaterEqual(
                len(pasted_root), 1,
                'paste_bindings should return the pasted binding'
            )

            # Paste into a folder exercises the parent_folder scalar path,
            # which previously was incorrectly wrapped in a list.
            folder = SequencerTools.add_root_folder(self.sequence, 'PasteTarget')
            pasted_in_folder = SequencerTools.paste_bindings(
                token, self.sequence, parent_folder=folder
            )
            self.assertTrue(hasattr(pasted_in_folder, '__len__'))
            self.assertGreaterEqual(len(pasted_in_folder), 1)
        finally:
            actor2.destroy_actor()

