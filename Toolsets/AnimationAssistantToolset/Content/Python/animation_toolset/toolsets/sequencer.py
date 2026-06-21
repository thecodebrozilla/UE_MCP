# Copyright Epic Games, Inc. All Rights Reserved.

import json

import unreal

import toolset_registry


@unreal.uclass()
class SequencerTools(unreal.ToolsetDefinition):
    """Core tools for creating and editing Level Sequences in Sequencer. Use
    whenever working with Sequencer - covers sequence lifecycle (create, open,
    close), playback control (play, pause, scrub, speed, loop), sequence
    properties (display rate, frame ranges, marked frames, tick resolution),
    actor bindings (add actors, spawnables, cameras, find and manage bindings),
    tracks (add, find, remove any track type), sections (range, easing, blend
    type, completion mode), selection state, folder organization, sub-sequence
    navigation, event tracks, track filters, and sequence locking. For
    keyframing use SequencerKeyframingTools. For Control Rig use
    SequencerControlRigTools. For outliner inspection use
    SequencerOutlinerTools."""


    @toolset_registry.tool_call
    @staticmethod
    def create_level_sequence(package_path: str, asset_name: str) -> unreal.LevelSequence:
        """Create a new Level Sequence asset.

        If an asset already exists at the given path, it will be deleted
        first to avoid triggering a modal overwrite dialog.

        Args:
            package_path: The content browser folder path (e.g. '/Game/Cinematics').
            asset_name: The name for the new sequence asset.

        Returns:
            The newly created LevelSequence asset.
        """
        if not package_path:
            raise ValueError("Package path is empty.")
        if not asset_name:
            raise ValueError("Asset name is empty.")
        full_path = f"{package_path}/{asset_name}"
        if unreal.EditorAssetLibrary.does_asset_exist(full_path):
            unreal.EditorAssetLibrary.delete_asset(full_path)
        factory = unreal.LevelSequenceFactoryNew()
        asset_tools = unreal.AssetToolsHelpers.get_asset_tools()
        sequence = asset_tools.create_asset(asset_name, package_path, unreal.LevelSequence, factory)
        if not sequence:
            raise ValueError(
                f"Failed to create Level Sequence '{asset_name}' at '{package_path}'."
            )
        return sequence

    @toolset_registry.tool_call
    @staticmethod
    def get_current_sequence() -> unreal.LevelSequence:
        """Get the root level sequence currently open in the Sequencer editor.

        Returns:
            The root LevelSequence asset, or None if no sequence is open.
        """
        return unreal.LevelSequenceEditorBlueprintLibrary.get_current_level_sequence()

    @toolset_registry.tool_call
    @staticmethod
    def get_focused_sequence() -> unreal.LevelSequence:
        """Get the currently focused level sequence in the hierarchy.

        When navigated into a sub-sequence, this returns the sub-sequence
        rather than the root sequence.

        Returns:
            The focused LevelSequence asset, or None if no sequence is open.
        """
        return unreal.LevelSequenceEditorBlueprintLibrary.get_focused_level_sequence()

    @toolset_registry.tool_call
    @staticmethod
    def open_sequence(sequence: unreal.LevelSequence) -> bool:
        """Open a level sequence asset in the Sequencer editor.

        Args:
            sequence: The LevelSequence asset to open.
        """
        if not sequence:
            raise ValueError("Cannot open a None sequence.")
        unreal.LevelSequenceEditorBlueprintLibrary.open_level_sequence(sequence)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def close_sequence() -> bool:
        """Close the currently open level sequence editor."""
        unreal.LevelSequenceEditorBlueprintLibrary.close_level_sequence()
        return True

    @toolset_registry.tool_call
    @staticmethod
    def refresh_sequence() -> bool:
        """Force refresh the Sequencer editor UI on the next tick."""
        unreal.LevelSequenceEditorBlueprintLibrary.refresh_current_level_sequence()
        return True

    # ========================================================================

    @toolset_registry.tool_call
    @staticmethod
    def play() -> bool:
        """Start playback of the current sequence."""
        unreal.LevelSequenceEditorBlueprintLibrary.play()
        return True

    @toolset_registry.tool_call
    @staticmethod
    def pause() -> bool:
        """Pause playback of the current sequence."""
        unreal.LevelSequenceEditorBlueprintLibrary.pause()
        return True

    @toolset_registry.tool_call
    @staticmethod
    def is_playing() -> bool:
        """Check whether the sequence is currently playing.

        Returns:
            True if the sequence is playing, False otherwise.
        """
        return unreal.LevelSequenceEditorBlueprintLibrary.is_playing()

    @toolset_registry.tool_call
    @staticmethod
    def set_playhead_frame(frame: int) -> bool:
        """Set the playhead position in display rate frames.

        Args:
            frame: The frame number to move the playhead to.
        """
        params = unreal.MovieSceneSequencePlaybackParams()
        params.frame = unreal.FrameTime(
            frame_number=unreal.FrameNumber(value=frame)
        )
        unreal.LevelSequenceEditorBlueprintLibrary.set_global_position(params)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_playhead_frame() -> int:
        """Get the current playhead position in display rate frames.

        Returns:
            The current playhead frame number.
        """
        params = unreal.LevelSequenceEditorBlueprintLibrary.get_global_position()
        return params.frame.frame_number.value

    @toolset_registry.tool_call
    @staticmethod
    def set_playback_speed(speed: float) -> bool:
        """Set the playback speed multiplier.

        Args:
            speed: The speed multiplier (e.g. 1.0 for normal, 2.0 for double).
        """
        if speed <= 0.0:
            raise ValueError(f"Playback speed must be positive, got {speed}.")
        unreal.LevelSequenceEditorBlueprintLibrary.set_playback_speed(speed)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_playback_speed() -> float:
        """Get the current playback speed multiplier.

        Returns:
            The current speed multiplier.
        """
        return unreal.LevelSequenceEditorBlueprintLibrary.get_playback_speed()

    @toolset_registry.tool_call
    @staticmethod
    def set_loop_mode(loop: bool) -> bool:
        """Enable or disable loop playback.

        Args:
            loop: True to enable looping, False to disable.
        """
        mode = unreal.SequencerLoopMode.SLM_LOOP if loop else unreal.SequencerLoopMode.SLM_NO_LOOP
        unreal.LevelSequenceEditorBlueprintLibrary.set_loop_mode(mode)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_loop_mode() -> bool:
        """Get the current loop playback mode.

        Returns:
            True if looping is enabled, False otherwise.
        """
        mode = unreal.LevelSequenceEditorBlueprintLibrary.get_loop_mode()
        return mode != unreal.SequencerLoopMode.SLM_NO_LOOP

    # ========================================================================

    @toolset_registry.tool_call
    @staticmethod
    def get_display_rate(sequence: unreal.LevelSequence) -> unreal.FrameRate:
        """Get the display frame rate of a sequence.

        Args:
            sequence: The LevelSequence to query.

        Returns:
            The display FrameRate.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        return sequence.get_display_rate()

    @toolset_registry.tool_call
    @staticmethod
    def set_display_rate(
        sequence: unreal.LevelSequence,
        numerator: int,
        denominator: int = 1
    ) -> bool:
        """Set the display frame rate of a sequence.

        Args:
            sequence: The LevelSequence to modify.
            numerator: Frame rate numerator (e.g. 30 for 30fps).
            denominator: Frame rate denominator (default 1).
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        if numerator <= 0 or denominator <= 0:
            raise ValueError(
                f"Frame rate must be positive, got {numerator}/{denominator}."
            )
        rate = unreal.FrameRate(numerator=numerator, denominator=denominator)
        sequence.set_display_rate(rate)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_playback_range(sequence: unreal.LevelSequence) -> str:
        """Get the playback start and end frames of a sequence.

        Args:
            sequence: The LevelSequence to query.

        Returns:
            JSON string with 'start' and 'end' integer frame numbers.
        """

        if not sequence:
            raise ValueError("Sequence is None.")
        start = sequence.get_playback_start()
        end = sequence.get_playback_end()
        return json.dumps({"start": start, "end": end})

    @toolset_registry.tool_call
    @staticmethod
    def set_playback_range(
        sequence: unreal.LevelSequence,
        start_frame: int,
        end_frame: int
    ) -> bool:
        """Set the playback start and end frames of a sequence.

        Args:
            sequence: The LevelSequence to modify.
            start_frame: The start frame.
            end_frame: The end frame.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        if start_frame >= end_frame:
            raise ValueError(
                f"Start frame ({start_frame}) must be less than end frame "
                f"({end_frame})."
            )
        sequence.set_playback_start(start_frame)
        sequence.set_playback_end(end_frame)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def set_view_range(
        sequence: unreal.LevelSequence,
        start_seconds: float,
        end_seconds: float
    ) -> bool:
        """Set the visible time range in the Sequencer timeline.

        Args:
            sequence: The LevelSequence to modify.
            start_seconds: The visible range start in seconds.
            end_seconds: The visible range end in seconds.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        sequence.set_view_range_start(start_seconds)
        sequence.set_view_range_end(end_seconds)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_view_range(sequence: unreal.LevelSequence) -> str:
        """Get the visible time range in the Sequencer timeline.

        Args:
            sequence: The LevelSequence to query.

        Returns:
            JSON string with 'start' and 'end' in seconds.
        """

        if not sequence:
            raise ValueError("Sequence is None.")
        return json.dumps({
            "start": sequence.get_view_range_start(),
            "end": sequence.get_view_range_end(),
        })

    @toolset_registry.tool_call
    @staticmethod
    def set_work_range(
        sequence: unreal.LevelSequence,
        start_seconds: float,
        end_seconds: float
    ) -> bool:
        """Set the work range of the sequence.

        Args:
            sequence: The LevelSequence to modify.
            start_seconds: The work range start in seconds.
            end_seconds: The work range end in seconds.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        sequence.set_work_range_start(start_seconds)
        sequence.set_work_range_end(end_seconds)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_work_range(sequence: unreal.LevelSequence) -> str:
        """Get the work range of the sequence.

        Args:
            sequence: The LevelSequence to query.

        Returns:
            JSON string with 'start' and 'end' in seconds.
        """

        if not sequence:
            raise ValueError("Sequence is None.")
        return json.dumps({
            "start": sequence.get_work_range_start(),
            "end": sequence.get_work_range_end(),
        })

    @toolset_registry.tool_call
    @staticmethod
    def add_marked_frame(
        sequence: unreal.LevelSequence,
        frame: int
    ) -> int:
        """Add a marked frame (bookmark) to the sequence.

        Args:
            sequence: The LevelSequence to modify.
            frame: The frame number to mark.

        Returns:
            The index of the newly added marked frame.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        marked_frame = unreal.MovieSceneMarkedFrame()
        marked_frame.frame_number = unreal.FrameNumber(value=frame)
        return sequence.add_marked_frame(marked_frame)

    @toolset_registry.tool_call
    @staticmethod
    def get_marked_frames(
        sequence: unreal.LevelSequence
    ) -> list[unreal.MovieSceneMarkedFrame]:
        """Get all marked frames (bookmarks) in the sequence.

        Args:
            sequence: The LevelSequence to query.

        Returns:
            List of MovieSceneMarkedFrame objects.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        return list(sequence.get_marked_frames())

    @toolset_registry.tool_call
    @staticmethod
    def delete_marked_frame(
        sequence: unreal.LevelSequence,
        index: int
    ) -> bool:
        """Delete a marked frame by index.

        Args:
            sequence: The LevelSequence to modify.
            index: Index of the marked frame to delete.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        sequence.delete_marked_frame(index)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def delete_all_marked_frames(sequence: unreal.LevelSequence) -> bool:
        """Delete all marked frames from the sequence.

        Args:
            sequence: The LevelSequence to modify.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        sequence.delete_marked_frames()
        return True

    @toolset_registry.tool_call
    @staticmethod
    def find_marked_frame_by_label(
        sequence: unreal.LevelSequence,
        label: str
    ) -> int:
        """Find a marked frame by label.

        Args:
            sequence: The LevelSequence to search.
            label: The label to find.

        Returns:
            Index of the marked frame, or -1 if not found.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        return sequence.find_marked_frame_by_label(label)

    # -- Add 11: Sequence properties --

    @toolset_registry.tool_call
    @staticmethod
    def get_tick_resolution(sequence: unreal.LevelSequence) -> unreal.FrameRate:
        """Get the internal tick resolution of a sequence.

        Args:
            sequence: The LevelSequence to query.

        Returns:
            The tick FrameRate.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        return sequence.get_tick_resolution()

    @toolset_registry.tool_call
    @staticmethod
    def set_tick_resolution(
        sequence: unreal.LevelSequence,
        numerator: int,
        denominator: int = 1
    ) -> bool:
        """Set the internal tick resolution of a sequence.

        Args:
            sequence: The LevelSequence to modify.
            numerator: Numerator of the frame rate.
            denominator: Denominator of the frame rate.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        rate = unreal.FrameRate(numerator=numerator, denominator=denominator)
        sequence.set_tick_resolution(rate)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_evaluation_type(sequence: unreal.LevelSequence) -> str:
        """Get the evaluation type of a sequence.

        Args:
            sequence: The LevelSequence to query.

        Returns:
            String representation of the evaluation type.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        return str(sequence.get_evaluation_type())

    @toolset_registry.tool_call
    @staticmethod
    def set_evaluation_type(
        sequence: unreal.LevelSequence,
        eval_type: str
    ) -> bool:
        """Set the evaluation type of a sequence.

        Args:
            sequence: The LevelSequence to modify.
            eval_type: Evaluation type string (e.g. 'WITH_SUB_FRAMES', 'FRAME_LOCKED').
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        et = unreal.MovieSceneEvaluationType.cast(
            {'WITH_SUB_FRAMES': 0, 'FRAME_LOCKED': 1}.get(eval_type.upper(), 0)
        )
        sequence.set_evaluation_type(et)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_clock_source(sequence: unreal.LevelSequence) -> str:
        """Get the clock source for the sequence.

        Args:
            sequence: The LevelSequence to query.

        Returns:
            String representation of the clock source.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        return str(sequence.get_clock_source())

    @toolset_registry.tool_call
    @staticmethod
    def set_clock_source(
        sequence: unreal.LevelSequence,
        clock_source: str
    ) -> bool:
        """Set the clock source for the sequence.

        Args:
            sequence: The LevelSequence to modify.
            clock_source: Clock source string (e.g. 'TICK', 'PLATFORM', 'AUDIO', 'TIMECODE', 'CUSTOM').
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        cs_map = {
            'TICK': 0, 'PLATFORM': 1, 'AUDIO': 2,
            'TIMECODE': 3, 'CUSTOM': 4,
        }
        cs = unreal.UpdateClockSource.cast(cs_map.get(clock_source.upper(), 0))
        sequence.set_clock_source(cs)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def is_playback_range_locked(sequence: unreal.LevelSequence) -> bool:
        """Check if the playback range is locked.

        Args:
            sequence: The LevelSequence to query.

        Returns:
            True if the playback range is locked.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        return sequence.is_playback_range_locked()

    @toolset_registry.tool_call
    @staticmethod
    def set_playback_range_locked(
        sequence: unreal.LevelSequence,
        locked: bool
    ) -> bool:
        """Lock or unlock the playback range.

        Args:
            sequence: The LevelSequence to modify.
            locked: True to lock, False to unlock.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        sequence.set_playback_range_locked(locked)
        return True

    # ========================================================================

    @toolset_registry.tool_call
    @staticmethod
    def add_actors(actors: list[unreal.Actor]) -> list[unreal.SequencerBindingProxy]:
        """Add actors from the level to the currently open sequence.

        Args:
            actors: List of Actors to bind into the sequence.

        Returns:
            List of SequencerBindingProxy objects for the new bindings.
        """
        if not actors:
            raise ValueError("Actor list is empty.")
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        return list(subsystem.add_actors(actors))

    @toolset_registry.tool_call
    @staticmethod
    def add_spawnable_from_instance(
        sequence: unreal.LevelSequence,
        obj: unreal.Object
    ) -> unreal.SequencerBindingProxy:
        """Create a spawnable binding from an existing object instance.

        Args:
            sequence: The LevelSequence to add the spawnable to.
            obj: The object to create a spawnable from.

        Returns:
            The SequencerBindingProxy for the new spawnable.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        if not obj:
            raise ValueError("Object is None.")
        return sequence.add_spawnable_from_instance(obj)

    @toolset_registry.tool_call
    @staticmethod
    def add_spawnable_from_class(
        sequence: unreal.LevelSequence,
        actor_class_path: str
    ) -> unreal.SequencerBindingProxy:
        """Create a spawnable binding from an actor class.

        Args:
            sequence: The LevelSequence to add the spawnable to.
            actor_class_path: Full class path, e.g. '/Script/Engine.CameraActor'
                or '/Script/CinematicCamera.CineCameraActor'.

        Returns:
            The SequencerBindingProxy for the new spawnable.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        if not actor_class_path:
            raise ValueError("Actor class path is empty.")
        actor_class = unreal.load_object(None, actor_class_path)
        if not actor_class:
            raise ValueError(f"Could not load class '{actor_class_path}'.")
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        return subsystem.add_spawnable_from_class(sequence, actor_class)

    @toolset_registry.tool_call
    @staticmethod
    def create_camera(spawnable: bool = True) -> unreal.SequencerBindingProxy:
        """Create a new cine camera actor in the sequence.

        Args:
            spawnable: If True, creates as a spawnable. If False, creates
                as a possessable placed in the level.

        Returns:
            The SequencerBindingProxy for the new camera.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        binding, camera_actor = subsystem.create_camera(spawnable)
        return binding

    @toolset_registry.tool_call
    @staticmethod
    def get_bindings(
        sequence: unreal.LevelSequence
    ) -> list[unreal.SequencerBindingProxy]:
        """Get all bindings in the sequence.

        Args:
            sequence: The LevelSequence to query.

        Returns:
            List of SequencerBindingProxy objects.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        return list(sequence.get_bindings())

    @toolset_registry.tool_call
    @staticmethod
    def find_binding_by_name(
        sequence: unreal.LevelSequence,
        name: str
    ) -> unreal.SequencerBindingProxy:
        """Find a binding by its display name.

        Args:
            sequence: The LevelSequence to search.
            name: The display name to match.

        Returns:
            The matching SequencerBindingProxy.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        if not name:
            raise ValueError("Name is empty.")
        return sequence.find_binding_by_name(name)

    @toolset_registry.tool_call
    @staticmethod
    def get_binding_name(binding: unreal.SequencerBindingProxy) -> str:
        """Get the display name of a binding.

        Args:
            binding: The binding to query.

        Returns:
            The binding's display name.
        """
        return str(binding.get_display_name())

    @toolset_registry.tool_call
    @staticmethod
    def set_binding_name(binding: unreal.SequencerBindingProxy, name: str) -> bool:
        """Set the display name of a binding.

        Args:
            binding: The binding to rename.
            name: The new display name.
        """
        if not name:
            raise ValueError("Name is empty.")
        binding.set_display_name(name)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def remove_binding(binding: unreal.SequencerBindingProxy) -> bool:
        """Remove a binding from the sequence.

        Args:
            binding: The binding to remove.
        """
        binding.remove()
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_bound_objects(
        binding: unreal.SequencerBindingProxy
    ) -> list[unreal.Object]:
        """Get the objects currently resolved by a binding.

        Args:
            binding: The binding to resolve.

        Returns:
            List of resolved UObject instances.
        """
        binding_id = unreal.MovieSceneObjectBindingID()
        binding_id.set_editor_property("Guid", binding.get_id())
        results = unreal.LevelSequenceEditorBlueprintLibrary.get_bound_objects(
            binding_id
        )
        return list(results)

    # ========================================================================

    @toolset_registry.tool_call
    @staticmethod
    def add_track_to_binding(
        binding: unreal.SequencerBindingProxy,
        track_type: unreal.Class
    ) -> unreal.MovieSceneTrack:
        """Add a track of the given type to a binding.

        Args:
            binding: The binding to add the track to.
            track_type: The track class (e.g. unreal.MovieSceneSkeletalAnimationTrack).

        Returns:
            The newly created MovieSceneTrack.
        """
        if not track_type:
            raise ValueError("Track type is None.")
        track = binding.add_track(track_type)
        if not track:
            raise ValueError(
                f"Failed to add track of type '{track_type}' to binding."
            )
        return track

    @toolset_registry.tool_call
    @staticmethod
    def add_track_to_sequence(
        sequence: unreal.LevelSequence,
        track_type: unreal.Class
    ) -> unreal.MovieSceneTrack:
        """Add a sequence-level (master) track.

        Args:
            sequence: The LevelSequence to add the track to.
            track_type: The track class (e.g. unreal.MovieSceneCameraCutTrack).

        Returns:
            The newly created MovieSceneTrack.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        if not track_type:
            raise ValueError("Track type is None.")
        track = sequence.add_track(track_type)
        if not track:
            raise ValueError(
                f"Failed to add track of type '{track_type}' to sequence."
            )
        return track

    @toolset_registry.tool_call
    @staticmethod
    def get_tracks_on_binding(
        binding: unreal.SequencerBindingProxy
    ) -> list[unreal.MovieSceneTrack]:
        """Get all tracks on a binding.

        Args:
            binding: The binding to query.

        Returns:
            List of MovieSceneTrack objects.
        """
        return list(binding.get_tracks())

    @toolset_registry.tool_call
    @staticmethod
    def get_tracks_on_sequence(
        sequence: unreal.LevelSequence
    ) -> list[unreal.MovieSceneTrack]:
        """Get all sequence-level (master) tracks.

        Args:
            sequence: The LevelSequence to query.

        Returns:
            List of MovieSceneTrack objects.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        return list(sequence.get_tracks())

    @toolset_registry.tool_call
    @staticmethod
    def find_tracks_by_type(
        binding: unreal.SequencerBindingProxy,
        track_type: unreal.Class
    ) -> list[unreal.MovieSceneTrack]:
        """Find all tracks of a specific type on a binding.

        Args:
            binding: The binding to search.
            track_type: The track class to filter by.

        Returns:
            List of matching MovieSceneTrack objects.
        """
        if not track_type:
            raise ValueError("Track type is None.")
        return list(binding.find_tracks_by_type(track_type))

    @toolset_registry.tool_call
    @staticmethod
    def remove_track(
        binding: unreal.SequencerBindingProxy,
        track: unreal.MovieSceneTrack
    ) -> bool:
        """Remove a track from a binding.

        Args:
            binding: The binding that owns the track.
            track: The track to remove.
        """
        if not track:
            raise ValueError("Track is None.")
        binding.remove_track(track)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def remove_track_from_sequence(
        sequence: unreal.LevelSequence,
        track: unreal.MovieSceneTrack
    ) -> bool:
        """Remove a sequence-level (master) track.

        Args:
            sequence: The LevelSequence to modify.
            track: The track to remove.

        Returns:
            True if the track was removed.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        if not track:
            raise ValueError("Track is None.")
        return sequence.remove_track(track)

    @toolset_registry.tool_call
    @staticmethod
    def get_track_display_name(track: unreal.MovieSceneTrack) -> str:
        """Get the display name of a track.

        Args:
            track: The track to query.

        Returns:
            The track's display name.
        """
        if not track:
            raise ValueError("Track is None.")
        return str(track.get_display_name())

    @toolset_registry.tool_call
    @staticmethod
    def set_track_display_name(track: unreal.MovieSceneTrack, name: str) -> bool:
        """Set the display name of a track.

        Args:
            track: The track to rename.
            name: The new display name.
        """
        if not track:
            raise ValueError("Track is None.")
        if not name:
            raise ValueError("Name is empty.")
        track.set_display_name(name)
        return True

    # ========================================================================

    @toolset_registry.tool_call
    @staticmethod
    def add_section(track: unreal.MovieSceneTrack) -> unreal.MovieSceneSection:
        """Add a new section to a track.

        Args:
            track: The track to add a section to.

        Returns:
            The newly created MovieSceneSection.
        """
        if not track:
            raise ValueError("Track is None.")
        section = track.add_section()
        if not section:
            raise ValueError("Failed to add section to track.")
        return section

    @toolset_registry.tool_call
    @staticmethod
    def get_sections(track: unreal.MovieSceneTrack) -> list[unreal.MovieSceneSection]:
        """Get all sections on a track.

        Args:
            track: The track to query.

        Returns:
            List of MovieSceneSection objects.
        """
        if not track:
            raise ValueError("Track is None.")
        return list(track.get_sections())

    @toolset_registry.tool_call
    @staticmethod
    def remove_section(
        track: unreal.MovieSceneTrack,
        section: unreal.MovieSceneSection
    ) -> bool:
        """Remove a section from a track.

        Args:
            track: The track that owns the section.
            section: The section to remove.
        """
        if not track:
            raise ValueError("Track is None.")
        if not section:
            raise ValueError("Section is None.")
        track.remove_section(section)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def set_section_range(
        section: unreal.MovieSceneSection,
        start_frame: int,
        end_frame: int
    ) -> bool:
        """Set the frame range of a section.

        Args:
            section: The section to modify.
            start_frame: The start frame.
            end_frame: The end frame.
        """
        if not section:
            raise ValueError("Section is None.")
        if start_frame >= end_frame:
            raise ValueError(
                f"Start frame ({start_frame}) must be less than end frame "
                f"({end_frame})."
            )
        section.set_range(start_frame, end_frame)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_section_range(section: unreal.MovieSceneSection) -> str:
        """Get the frame range of a section.

        Args:
            section: The section to query.

        Returns:
            JSON string with 'start' and 'end' integer frame numbers.
        """

        if not section:
            raise ValueError("Section is None.")
        start = section.get_start_frame()
        end = section.get_end_frame()
        return json.dumps({"start": start, "end": end})

    @toolset_registry.tool_call
    @staticmethod
    def has_section_start_frame(section: unreal.MovieSceneSection) -> bool:
        """Check if a section has a bounded start frame (vs infinite).

        Args:
            section: The section to query.

        Returns:
            True if the start frame is bounded.
        """
        if not section:
            raise ValueError("Section is None.")
        return section.has_start_frame()

    @toolset_registry.tool_call
    @staticmethod
    def has_section_end_frame(section: unreal.MovieSceneSection) -> bool:
        """Check if a section has a bounded end frame (vs infinite).

        Args:
            section: The section to query.

        Returns:
            True if the end frame is bounded.
        """
        if not section:
            raise ValueError("Section is None.")
        return section.has_end_frame()

    @toolset_registry.tool_call
    @staticmethod
    def set_section_start_bounded(
        section: unreal.MovieSceneSection,
        bounded: bool
    ) -> bool:
        """Set whether the section start frame is bounded or infinite.

        Args:
            section: The section to modify.
            bounded: True for bounded, False for infinite.
        """
        if not section:
            raise ValueError("Section is None.")
        section.set_start_frame_bounded(bounded)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def set_section_end_bounded(
        section: unreal.MovieSceneSection,
        bounded: bool
    ) -> bool:
        """Set whether the section end frame is bounded or infinite.

        Args:
            section: The section to modify.
            bounded: True for bounded, False for infinite.
        """
        if not section:
            raise ValueError("Section is None.")
        section.set_end_frame_bounded(bounded)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def set_camera_cut_binding(
        section: unreal.MovieSceneCameraCutSection,
        camera_binding_id: str
    ) -> bool:
        """Set which camera a camera cut section uses.

        Args:
            section: The camera cut section.
            camera_binding_id: The binding ID of the camera (from get_bindings).
        """
        if not section:
            raise ValueError("Section is None.")
        binding_id = unreal.MovieSceneObjectBindingID()
        binding_id.set_editor_property("Guid", unreal.Guid(camera_binding_id))
        section.set_camera_binding_id(binding_id)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def set_section_ease_in(section: unreal.MovieSceneSection, duration: int) -> bool:
        """Set the ease-in duration of a section in frames.

        Enables manual ease override if not already active.

        Args:
            section: The section to modify.
            duration: The ease-in duration in frames.
        """
        if not section:
            raise ValueError("Section is None.")
        if duration < 0:
            raise ValueError(f"Ease-in duration must be non-negative, got {duration}.")
        section.set_ease_in_duration(duration)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def set_section_ease_out(section: unreal.MovieSceneSection, duration: int) -> bool:
        """Set the ease-out duration of a section in frames.

        Enables manual ease override if not already active.

        Args:
            section: The section to modify.
            duration: The ease-out duration in frames.
        """
        if not section:
            raise ValueError("Section is None.")
        if duration < 0:
            raise ValueError(
                f"Ease-out duration must be non-negative, got {duration}."
            )
        section.set_ease_out_duration(duration)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_section_ease_in(section: unreal.MovieSceneSection) -> int:
        """Get the effective ease-in duration of a section in frames.

        Args:
            section: The section to query.

        Returns:
            The ease-in duration in frames.
        """
        if not section:
            raise ValueError("Section is None.")
        return section.get_ease_in_duration()

    @toolset_registry.tool_call
    @staticmethod
    def get_section_ease_out(section: unreal.MovieSceneSection) -> int:
        """Get the effective ease-out duration of a section in frames.

        Args:
            section: The section to query.

        Returns:
            The ease-out duration in frames.
        """
        if not section:
            raise ValueError("Section is None.")
        return section.get_ease_out_duration()

    @toolset_registry.tool_call
    @staticmethod
    def set_section_blend_type(
        section: unreal.MovieSceneSection,
        blend_type: str
    ) -> bool:
        """Set the blend type of a section.

        Valid values: 'Absolute', 'Additive', 'Relative', 'Override'.

        Args:
            section: The section to modify.
            blend_type: The blend type name string.
        """
        if not section:
            raise ValueError("Section is None.")
        type_map = {
            "absolute": unreal.MovieSceneBlendType.ABSOLUTE,
            "additive": unreal.MovieSceneBlendType.ADDITIVE,
            "relative": unreal.MovieSceneBlendType.RELATIVE,
            "override": unreal.MovieSceneBlendType.OVERRIDE,
        }
        key = blend_type.lower()
        if key not in type_map:
            raise ValueError(
                f"Unknown blend type '{blend_type}'. "
                f"Valid values: {list(type_map.keys())}"
            )
        section.set_blend_type(type_map[key])
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_section_blend_type(
        section: unreal.MovieSceneSection
    ) -> str:
        """Get the blend type of a section.

        Args:
            section: The section to query.

        Returns:
            The blend type name string (e.g. 'Absolute', 'Additive').
        """
        if not section:
            raise ValueError("Section is None.")
        opt = section.get_blend_type()
        return str(opt.blend_type) if opt.is_valid else "None"

    @toolset_registry.tool_call
    @staticmethod
    def set_section_completion_mode(
        section: unreal.MovieSceneSection,
        completion_mode: str
    ) -> bool:
        """Set the completion mode of a section.

        Valid values: 'KeepState', 'RestoreState', 'ProjectDefault'.

        Args:
            section: The section to modify.
            completion_mode: The completion mode name string.
        """
        if not section:
            raise ValueError("Section is None.")
        mode_map = {
            "keepstate": unreal.MovieSceneCompletionMode.KEEP_STATE,
            "restorestate": unreal.MovieSceneCompletionMode.RESTORE_STATE,
            "projectdefault": unreal.MovieSceneCompletionMode.PROJECT_DEFAULT,
        }
        key = completion_mode.lower().replace("_", "")
        if key not in mode_map:
            raise ValueError(
                f"Unknown completion mode '{completion_mode}'. "
                f"Valid values: KeepState, RestoreState, ProjectDefault"
            )
        section.set_completion_mode(mode_map[key])
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_section_completion_mode(
        section: unreal.MovieSceneSection
    ) -> str:
        """Get the completion mode of a section.

        Args:
            section: The section to query.

        Returns:
            The completion mode name string.
        """
        if not section:
            raise ValueError("Section is None.")
        return str(section.get_completion_mode())

    @toolset_registry.tool_call
    @staticmethod
    def get_section_properties(section: unreal.MovieSceneSection) -> str:
        """Get all common properties of a section in a single call.

        Useful for testing and verification. Returns range, easing, blend
        type, and completion mode.

        Args:
            section: The section to query.

        Returns:
            JSON string with keys: 'start', 'end', 'ease_in', 'ease_out',
            'blend_type', 'completion_mode'.
        """

        if not section:
            raise ValueError("Section is None.")
        return json.dumps({
            "start": section.get_start_frame(),
            "end": section.get_end_frame(),
            "ease_in": section.get_ease_in_duration(),
            "ease_out": section.get_ease_out_duration(),
            "blend_type": str(section.get_blend_type().blend_type) if section.get_blend_type().is_valid else "None",
            "completion_mode": str(section.get_completion_mode()),
        })

    # ========================================================================

    @toolset_registry.tool_call
    @staticmethod
    def get_selected_tracks() -> list[unreal.MovieSceneTrack]:
        """Get the currently selected tracks in the Sequencer editor.

        Returns:
            List of selected MovieSceneTrack objects.
        """
        return list(
            unreal.LevelSequenceEditorBlueprintLibrary.get_selected_tracks()
        )

    @toolset_registry.tool_call
    @staticmethod
    def get_selected_sections() -> list[unreal.MovieSceneSection]:
        """Get the currently selected sections in the Sequencer editor.

        Returns:
            List of selected MovieSceneSection objects.
        """
        return list(
            unreal.LevelSequenceEditorBlueprintLibrary.get_selected_sections()
        )

    @toolset_registry.tool_call
    @staticmethod
    def get_selected_bindings() -> list[unreal.SequencerBindingProxy]:
        """Get the currently selected bindings in the Sequencer editor.

        Returns:
            List of selected SequencerBindingProxy objects.
        """
        return list(
            unreal.LevelSequenceEditorBlueprintLibrary.get_selected_bindings()
        )

    @toolset_registry.tool_call
    @staticmethod
    def get_selected_folders() -> list[unreal.MovieSceneFolder]:
        """Get the currently selected folders in the Sequencer editor.

        Returns:
            List of selected MovieSceneFolder objects.
        """
        return list(
            unreal.LevelSequenceEditorBlueprintLibrary.get_selected_folders()
        )

    @toolset_registry.tool_call
    @staticmethod
    def select_tracks(tracks: list[unreal.MovieSceneTrack]) -> bool:
        """Set the track selection in the Sequencer editor.

        Args:
            tracks: The tracks to select.
        """
        unreal.LevelSequenceEditorBlueprintLibrary.select_tracks(tracks)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def select_sections(sections: list[unreal.MovieSceneSection]) -> bool:
        """Set the section selection in the Sequencer editor.

        Args:
            sections: The sections to select.
        """
        unreal.LevelSequenceEditorBlueprintLibrary.select_sections(sections)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def select_bindings(bindings: list[unreal.SequencerBindingProxy]) -> bool:
        """Set the binding selection in the Sequencer editor.

        Args:
            bindings: The bindings to select.
        """
        unreal.LevelSequenceEditorBlueprintLibrary.select_bindings(bindings)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def empty_selection() -> bool:
        """Clear all selection in the Sequencer editor."""
        unreal.LevelSequenceEditorBlueprintLibrary.empty_selection()
        return True

    @toolset_registry.tool_call
    @staticmethod
    def force_evaluate() -> bool:
        """Force the Sequencer to evaluate and update the viewport."""
        unreal.LevelSequenceEditorBlueprintLibrary.force_update()
        return True

    @toolset_registry.tool_call
    @staticmethod
    def set_camera_lock(lock: bool) -> bool:
        """Lock or unlock the camera cut to the viewport.

        Args:
            lock: True to lock the camera to the viewport, False to unlock.
        """
        unreal.LevelSequenceEditorBlueprintLibrary.set_lock_camera_cut_to_viewport(
            lock
        )
        return True

    @toolset_registry.tool_call
    @staticmethod
    def select_folders(folders: list[unreal.MovieSceneFolder]) -> bool:
        """Set the folder selection in the Sequencer editor.

        Args:
            folders: The folders to select.
        """
        unreal.LevelSequenceEditorBlueprintLibrary.select_folders(folders)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def is_camera_cut_locked() -> bool:
        """Check if the camera cut is locked to the viewport.

        Returns:
            True if the camera is locked to the viewport.
        """
        return unreal.LevelSequenceEditorBlueprintLibrary.is_camera_cut_locked_to_viewport()

    @toolset_registry.tool_call
    @staticmethod
    def play_to(frame: int) -> bool:
        """Play from the current position to a specific frame, then stop.

        Args:
            frame: The target frame number in display rate.
        """
        params = unreal.MovieSceneSequencePlaybackParams()
        params.frame = unreal.FrameTime(
            frame_number=unreal.FrameNumber(value=frame)
        )
        unreal.LevelSequenceEditorBlueprintLibrary.play_to(params)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_selection_range() -> str:
        """Get the selection range (green bar) start and end frames.

        Returns:
            JSON string with 'start' and 'end' frame numbers.
        """

        start = unreal.LevelSequenceEditorBlueprintLibrary.get_selection_range_start()
        end = unreal.LevelSequenceEditorBlueprintLibrary.get_selection_range_end()
        return json.dumps({"start": start, "end": end})

    @toolset_registry.tool_call
    @staticmethod
    def set_selection_range(start_frame: int, end_frame: int) -> bool:
        """Set the selection range (green bar) start and end frames.

        Args:
            start_frame: The start frame number.
            end_frame: The end frame number.
        """
        unreal.LevelSequenceEditorBlueprintLibrary.set_selection_range_start(
            start_frame
        )
        unreal.LevelSequenceEditorBlueprintLibrary.set_selection_range_end(
            end_frame
        )
        return True

    @toolset_registry.tool_call
    @staticmethod
    def add_actors_by_name(actor_names: list[str]) -> list[unreal.SequencerBindingProxy]:
        """Add actors to the sequence by their names in the level.

        Finds actors by label in the current level and adds them to the
        currently open sequence as possessable bindings.

        Args:
            actor_names: List of actor label strings to find and add.

        Returns:
            List of SequencerBindingProxy for the added actors.
        """
        if not actor_names:
            raise ValueError("Actor names list is empty.")
        all_actors = unreal.EditorLevelLibrary.get_all_level_actors()
        matched = [
            a for a in all_actors
            if a.get_actor_label() in actor_names
        ]
        if not matched:
            raise ValueError(
                f"No actors found with names: {actor_names}"
            )
        subsystem = unreal.get_editor_subsystem(
            unreal.LevelSequenceEditorSubsystem
        )
        return list(subsystem.add_actors(matched))

    # ========================================================================

    @toolset_registry.tool_call
    @staticmethod
    def add_root_folder(
        sequence: unreal.LevelSequence,
        name: str
    ) -> unreal.MovieSceneFolder:
        """Create a new root-level folder in the sequence.

        Args:
            sequence: The LevelSequence to add the folder to.
            name: The folder name.

        Returns:
            The newly created MovieSceneFolder.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        if not name:
            raise ValueError("Folder name is empty.")
        return sequence.add_root_folder_to_sequence(name)

    @toolset_registry.tool_call
    @staticmethod
    def get_root_folders(
        sequence: unreal.LevelSequence
    ) -> list[unreal.MovieSceneFolder]:
        """Get all root-level folders in the sequence.

        Args:
            sequence: The LevelSequence to query.

        Returns:
            List of root MovieSceneFolder objects.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        return list(sequence.get_root_folders_in_sequence())

    @toolset_registry.tool_call
    @staticmethod
    def remove_root_folder(
        sequence: unreal.LevelSequence,
        folder: unreal.MovieSceneFolder
    ) -> bool:
        """Remove a root-level folder from the sequence.

        Args:
            sequence: The LevelSequence to modify.
            folder: The folder to remove.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        if not folder:
            raise ValueError("Folder is None.")
        sequence.remove_root_folder_from_sequence(folder)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def add_track_to_folder(
        folder: unreal.MovieSceneFolder,
        track: unreal.MovieSceneTrack
    ) -> bool:
        """Add a track into a folder for organization.

        Args:
            folder: The folder to add the track to.
            track: The track to organize.
        """
        if not folder:
            raise ValueError("Folder is None.")
        if not track:
            raise ValueError("Track is None.")
        folder.add_child_track(track)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def add_binding_to_folder(
        folder: unreal.MovieSceneFolder,
        binding: unreal.SequencerBindingProxy
    ) -> bool:
        """Add a binding into a folder for organization.

        Args:
            folder: The folder to add the binding to.
            binding: The binding to organize.
        """
        if not folder:
            raise ValueError("Folder is None.")
        folder.add_child_object_binding(binding)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_folder_contents(folder: unreal.MovieSceneFolder) -> str:
        """Get the tracks and bindings inside a folder.

        Args:
            folder: The folder to inspect.

        Returns:
            JSON string with 'track_count' and 'binding_count', plus
            'track_names' and 'binding_names' lists.
        """

        if not folder:
            raise ValueError("Folder is None.")
        tracks = list(folder.get_child_tracks())
        bindings = list(folder.get_child_object_bindings())
        return json.dumps({
            "track_count": len(tracks),
            "binding_count": len(bindings),
            "track_names": [str(t.get_display_name()) for t in tracks],
            "binding_names": [str(b.get_display_name()) for b in bindings],
        })

    # ========================================================================

    @toolset_registry.tool_call
    @staticmethod
    def focus_sub_sequence(sub_section: unreal.MovieSceneSubSection) -> bool:
        """Navigate into a sub-sequence via its sub-section.

        Use get_sections() on a sub-track to find the sub-section, then pass
        it here to focus the sub-sequence it references.

        Args:
            sub_section: The sub-section referencing the sub-sequence to focus.
        """
        if not sub_section:
            raise ValueError("Sub-section is None.")
        unreal.LevelSequenceEditorBlueprintLibrary.focus_level_sequence(sub_section)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def focus_parent_sequence() -> bool:
        """Navigate up one level in the sub-sequence hierarchy."""
        unreal.LevelSequenceEditorBlueprintLibrary.focus_parent_sequence()
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_sub_sequence_hierarchy() -> list[unreal.MovieSceneSubSection]:
        """Get the current sub-sequence hierarchy path.

        Returns a list of sub-sections from the root down to the currently
        focused sub-sequence.

        Returns:
            List of sub-section objects in the hierarchy path.
        """
        return list(
            unreal.LevelSequenceEditorBlueprintLibrary.get_sub_sequence_hierarchy()
        )

    @toolset_registry.tool_call
    @staticmethod
    def get_sequence_lock_state() -> bool:
        """Check whether the current level sequence is locked.

        Returns:
            True if the sequence is locked, False otherwise.
        """
        return unreal.LevelSequenceEditorBlueprintLibrary.is_level_sequence_locked()

    # ========================================================================

    @toolset_registry.tool_call
    @staticmethod
    def add_event_trigger_section(
        track: unreal.MovieSceneEventTrack
    ) -> unreal.MovieSceneEventTriggerSection:
        """Add an event trigger section to an event track.

        Args:
            track: The event track.

        Returns:
            The new trigger section.
        """
        if not track:
            raise ValueError("Track is None.")
        return track.add_event_trigger_section()

    @toolset_registry.tool_call
    @staticmethod
    def add_event_repeater_section(
        track: unreal.MovieSceneEventTrack
    ) -> unreal.MovieSceneEventRepeaterSection:
        """Add an event repeater section to an event track.

        Args:
            track: The event track.

        Returns:
            The new repeater section.
        """
        if not track:
            raise ValueError("Track is None.")
        return track.add_event_repeater_section()

    # ========================================================================

    @toolset_registry.tool_call
    @staticmethod
    def add_actors_to_binding(
        actors: list[unreal.Actor],
        binding: unreal.SequencerBindingProxy,
    ) -> bool:
        """Add actors to an existing binding.

        Args:
            actors: List of Actor objects to add.
            binding: The binding to add actors to.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        subsystem.add_actors_to_binding(actors, binding)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def replace_binding_with_actors(
        actors: list[unreal.Actor],
        binding: unreal.SequencerBindingProxy,
    ) -> bool:
        """Replace all bound actors on a binding with new ones.

        Args:
            actors: List of Actor objects to bind.
            binding: The binding to replace actors on.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        subsystem.replace_binding_with_actors(actors, binding)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def remove_actors_from_binding(
        actors: list[unreal.Actor],
        binding: unreal.SequencerBindingProxy,
    ) -> bool:
        """Remove specific actors from a binding.

        Args:
            actors: List of Actor objects to remove.
            binding: The binding to remove actors from.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        subsystem.remove_actors_from_binding(actors, binding)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def remove_all_bindings(binding: unreal.SequencerBindingProxy) -> bool:
        """Remove all bound actors from a binding.

        Args:
            binding: The binding to clear.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        subsystem.remove_all_bindings(binding)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def remove_invalid_bindings(binding: unreal.SequencerBindingProxy) -> bool:
        """Remove missing or broken actor references from a binding.

        Args:
            binding: The binding to clean up.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        subsystem.remove_invalid_bindings(binding)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def rebind_component(
        component_bindings: list[unreal.SequencerBindingProxy],
        component_name: str,
    ) -> bool:
        """Rebind component bindings to a named component.

        Args:
            component_bindings: List of SequencerBindingProxy for the
                component bindings to rebind.
            component_name: Name of the target component.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        subsystem.rebind_component(component_bindings, component_name)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def fix_actor_references() -> bool:
        """Attempt to auto-fix broken actor references in the current sequence."""
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        subsystem.fix_actor_references()
        return True

    # ========================================================================

    @toolset_registry.tool_call
    @staticmethod
    def get_track_filter_names() -> list[str]:
        """Get all available track filter names.

        Returns:
            List of track filter name strings.
        """
        return [
            str(n) for n in
            unreal.LevelSequenceEditorBlueprintLibrary.get_track_filter_names()
        ]

    @toolset_registry.tool_call
    @staticmethod
    def is_track_filter_active(name: str) -> bool:
        """Check whether a track filter is currently active.

        Args:
            name: The track filter name.

        Returns:
            True if the filter is active.
        """
        return unreal.LevelSequenceEditorBlueprintLibrary.is_track_filter_enabled(unreal.Text(name))

    @toolset_registry.tool_call
    @staticmethod
    def set_track_filter_active(name: str, active: bool) -> bool:
        """Enable or disable a track filter.

        Args:
            name: The track filter name.
            active: True to enable, False to disable.
        """
        unreal.LevelSequenceEditorBlueprintLibrary.set_track_filter_enabled(unreal.Text(name), active)
        return True

    # ========================================================================

    @toolset_registry.tool_call
    @staticmethod
    def is_sequence_locked() -> bool:
        """Check if the current sequence and its descendants are locked.

        Returns:
            True if the sequence is locked.
        """
        return unreal.LevelSequenceEditorBlueprintLibrary.is_level_sequence_locked()

    @toolset_registry.tool_call
    @staticmethod
    def set_sequence_locked(lock: bool) -> bool:
        """Lock or unlock the current sequence and its descendants.

        Args:
            lock: True to lock, False to unlock.
        """
        unreal.LevelSequenceEditorBlueprintLibrary.set_lock_level_sequence(lock)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def bake_transform(bindings: list[unreal.SequencerBindingProxy]) -> bool:
        """Bake transforms for the given bindings at every frame.

        Args:
            bindings: List of SequencerBindingProxy objects to bake.

        Returns:
            True if the bake succeeded.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        settings = unreal.BakingAnimationKeySettings()
        return subsystem.bake_transform_with_settings(bindings, settings)

    # ========================================================================

    @toolset_registry.tool_call
    @staticmethod
    def get_child_possessables(
        binding: unreal.SequencerBindingProxy,
    ) -> list[unreal.SequencerBindingProxy]:
        """Get component bindings under an actor binding.

        Actor bindings can own child possessable bindings for their
        components (e.g. SkeletalMeshComponent, CameraComponent).
        Use this to find the component binding when you need to add
        tracks to a specific component rather than the actor.

        Args:
            binding: The actor-level binding to query.

        Returns:
            List of child component SequencerBindingProxy objects.
        """
        return list(binding.get_child_possessables())

    @toolset_registry.tool_call
    @staticmethod
    def get_binding_id(
        sequence: unreal.LevelSequence,
        binding: unreal.SequencerBindingProxy,
    ) -> unreal.MovieSceneObjectBindingID:
        """Get the binding ID for a binding proxy.

        The binding ID can be used with get_bound_objects to resolve
        what actor or component the binding references at runtime.

        Args:
            sequence: The LevelSequence containing the binding.
            binding: The binding to get the ID for.

        Returns:
            The MovieSceneObjectBindingID.
        """
        return sequence.get_binding_id(binding)

    @toolset_registry.tool_call
    @staticmethod
    def get_section_to_key(
        track: unreal.MovieSceneTrack,
    ) -> unreal.MovieSceneSection:
        """Get the active section that receives new keys on a track.

        When keying properties, Sequencer writes to a specific section.
        This returns that section, which is usually the first section
        or the one the user has designated.

        Args:
            track: The track to query.

        Returns:
            The section that receives new keyframes.
        """
        return track.get_section_to_key()

    @toolset_registry.tool_call
    @staticmethod
    def set_property_name_and_path(
        track: unreal.MovieScenePropertyTrack,
        display_name: str,
        property_path: str,
    ) -> bool:
        """Configure a property track to animate a specific UProperty.

        This binds a generic property track (Float, Bool, Byte, etc.)
        to a specific property on the bound object. For nested properties
        use dot notation in the path.

        Examples:
            display_name="Intensity", property_path="Intensity"
            display_name="Focus Distance", property_path="FocusSettings.ManualFocusDistance"
            display_name="Animation Mode", property_path="AnimationMode"

        Args:
            track: The property track to configure.
            display_name: Human-readable name shown in Sequencer UI.
            property_path: The UProperty path on the bound object.
        """
        track.set_property_name_and_path(display_name, property_path)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def set_byte_track_enum(
        track: unreal.MovieSceneByteTrack,
        enum_class_path: str,
    ) -> bool:
        """Configure a byte track to use a specific enum type.

        Byte tracks can animate enum properties. Call this after
        adding the track and before setting property_name_and_path.

        Args:
            track: The byte track to configure.
            enum_class_path: Path to the enum (e.g. the result of
                unreal.AnimationMode.static_enum()).
        """
        enum_obj = unreal.load_object(name=enum_class_path)
        if not enum_obj:
            raise ValueError(
                f"Could not load enum object '{enum_class_path}'."
            )
        track.set_byte_track_enum(enum_obj)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def set_section_animation(
        section: unreal.MovieSceneSkeletalAnimationSection,
        anim_sequence_path: str,
    ) -> bool:
        """Set the animation asset on a skeletal animation section.

        After adding a MovieSceneSkeletalAnimationTrack and section,
        call this to assign which AnimSequence plays in that section.

        Args:
            section: The skeletal animation section.
            anim_sequence_path: Content path to the AnimSequence asset.
        """
        anim = unreal.load_asset(anim_sequence_path)
        if not anim:
            raise ValueError(f"Animation not found: {anim_sequence_path}")
        section.params.animation = anim
        return True

    @toolset_registry.tool_call
    @staticmethod
    def set_section_pre_roll_frames(
        section: unreal.MovieSceneSection,
        frames: int,
    ) -> bool:
        """Set the number of frames to pre-roll this section before it starts.

        Pre-roll evaluates the section before its real start so physics,
        cloth, or simulation state can warm up. The pre-roll frames do not
        affect the rendered output of the section.

        Args:
            section: The section to configure.
            frames: Number of frames to pre-roll (must be >= 0).

        Returns:
            True when set successfully.
        """
        if not section:
            raise ValueError("Section is None.")
        if frames < 0:
            raise ValueError(f"Pre-roll frames must be >= 0, got {frames}.")
        section.set_pre_roll_frames(int(frames))
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_section_pre_roll_frames(
        section: unreal.MovieSceneSection,
    ) -> int:
        """Get the number of pre-roll frames configured on a section.

        Args:
            section: The section to query.

        Returns:
            The pre-roll frame count.
        """
        if not section:
            raise ValueError("Section is None.")
        return section.get_pre_roll_frames()

    @toolset_registry.tool_call
    @staticmethod
    def set_section_post_roll_frames(
        section: unreal.MovieSceneSection,
        frames: int,
    ) -> bool:
        """Set the number of frames to post-roll this section after it ends.

        Post-roll continues evaluation after the section's real end, useful
        for simulations that need to settle.

        Args:
            section: The section to configure.
            frames: Number of frames to post-roll (must be >= 0).

        Returns:
            True when set successfully.
        """
        if not section:
            raise ValueError("Section is None.")
        if frames < 0:
            raise ValueError(f"Post-roll frames must be >= 0, got {frames}.")
        section.set_post_roll_frames(int(frames))
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_section_post_roll_frames(
        section: unreal.MovieSceneSection,
    ) -> int:
        """Get the number of post-roll frames configured on a section.

        Args:
            section: The section to query.

        Returns:
            The post-roll frame count.
        """
        if not section:
            raise ValueError("Section is None.")
        return section.get_post_roll_frames()

    @toolset_registry.tool_call
    @staticmethod
    def find_binding_by_tag(
        sequence: unreal.LevelSequence,
        tag_name: str,
    ) -> unreal.MovieSceneObjectBindingID:
        """Find the first binding with the given tag in the sequence.

        Tags are authored via tag_binding() in this toolset, or via
        RMB -> Expose on a binding in the Sequencer editor.

        Args:
            sequence: The LevelSequence to search.
            tag_name: The tag name to look up.

        Returns:
            The first matching FMovieSceneObjectBindingID. When no
            binding carries the tag, a default-constructed (invalid)
            ID is returned - check `.is_valid()` on the result, or call
            find_bindings_by_tag() and test the list length instead.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        if not tag_name:
            raise ValueError("Tag name is empty.")
        return sequence.find_binding_by_tag(tag_name)

    @toolset_registry.tool_call
    @staticmethod
    def find_bindings_by_tag(
        sequence: unreal.LevelSequence,
        tag_name: str,
    ) -> list[unreal.MovieSceneObjectBindingID]:
        """Find all bindings with the given tag in the sequence.

        Args:
            sequence: The LevelSequence to search.
            tag_name: The tag name to look up.

        Returns:
            List of matching FMovieSceneObjectBindingID objects.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        if not tag_name:
            raise ValueError("Tag name is empty.")
        return list(sequence.find_bindings_by_tag(tag_name))

    @toolset_registry.tool_call
    @staticmethod
    def get_all_binding_tags(
        sequence: unreal.LevelSequence,
    ) -> list[str]:
        """Get every tag name registered in the sequence.

        Uses the MovieSceneBindingTagExtensions C++ library.

        Args:
            sequence: The LevelSequence to query.

        Returns:
            List of tag name strings.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        return [str(n) for n in sequence.get_all_binding_tags()]

    @toolset_registry.tool_call
    @staticmethod
    def get_binding_tags(
        binding: unreal.SequencerBindingProxy,
    ) -> list[str]:
        """Get the tags currently attached to a specific binding.

        Args:
            binding: The binding to query.

        Returns:
            List of tag name strings.
        """
        if not binding:
            raise ValueError("Binding is None.")
        return [str(n) for n in binding.get_binding_tags()]

    @toolset_registry.tool_call
    @staticmethod
    def tag_binding(
        binding: unreal.SequencerBindingProxy,
        tag_name: str,
    ) -> bool:
        """Attach a tag to a binding.

        If the tag has not been seen in the sequence before, it is
        automatically registered.

        Args:
            binding: The binding to tag.
            tag_name: The tag name.

        Returns:
            True on success.
        """
        if not tag_name:
            raise ValueError("Tag name is empty.")
        binding.tag_binding(tag_name)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def untag_binding(
        binding: unreal.SequencerBindingProxy,
        tag_name: str,
    ) -> bool:
        """Remove a tag from a binding.

        Args:
            binding: The binding to untag.
            tag_name: The tag name to remove.

        Returns:
            True on success. No-op if the binding did not have the tag.
        """
        if not tag_name:
            raise ValueError("Tag name is empty.")
        binding.untag_binding(tag_name)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def remove_binding_tag(
        sequence: unreal.LevelSequence,
        tag_name: str,
    ) -> bool:
        """Remove a tag from the sequence entirely.

        Clears the tag from every binding that had it and unregisters the
        tag name from the sequence.

        Args:
            sequence: The LevelSequence.
            tag_name: The tag name to remove.

        Returns:
            True on success.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        if not tag_name:
            raise ValueError("Tag name is empty.")
        sequence.remove_binding_tag(tag_name)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def copy_bindings(
        bindings: list[unreal.SequencerBindingProxy],
    ) -> str:
        """Copy one or more bindings to the Sequencer clipboard.

        Returns a paste token that can be passed to paste_bindings, or an
        empty string to consume from the clipboard. The token also lands
        in the editor clipboard for interactive use.

        Args:
            bindings: The bindings to copy.

        Returns:
            The paste token string.
        """
        subsystem = unreal.get_editor_subsystem(
            unreal.LevelSequenceEditorSubsystem
        )
        return subsystem.copy_bindings(bindings)

    @toolset_registry.tool_call
    @staticmethod
    def paste_bindings(
        paste_token: str,
        sequence: unreal.LevelSequence,
        parent_folder: unreal.MovieSceneFolder | None = None,
    ) -> list[unreal.SequencerBindingProxy]:
        """Paste bindings from the clipboard (or a token returned by copy_bindings).

        Args:
            paste_token: Token from copy_bindings, or empty string to use the
                editor clipboard.
            sequence: Destination sequence (informational; the subsystem
                pastes into the active sequence).
            parent_folder: Optional folder to paste into.

        Returns:
            List of newly-created bindings.
        """
        subsystem = unreal.get_editor_subsystem(
            unreal.LevelSequenceEditorSubsystem
        )
        paste_params = unreal.MovieScenePasteBindingsParams()
        paste_params.bindings = []
        paste_params.folders = []
        paste_params.parent_folder = parent_folder
        return list(subsystem.paste_bindings(paste_token, paste_params))

    @toolset_registry.tool_call
    @staticmethod
    def copy_tracks(
        tracks: list[unreal.MovieSceneTrack],
    ) -> str:
        """Copy one or more tracks to the Sequencer clipboard.

        Args:
            tracks: The tracks to copy.

        Returns:
            The paste token string.
        """
        subsystem = unreal.get_editor_subsystem(
            unreal.LevelSequenceEditorSubsystem
        )
        return subsystem.copy_tracks(tracks)

    @toolset_registry.tool_call
    @staticmethod
    def paste_tracks(
        paste_token: str,
        sequence: unreal.LevelSequence,
        target_bindings: list[unreal.SequencerBindingProxy],
        parent_folder: unreal.MovieSceneFolder = None,
    ) -> list[unreal.MovieSceneTrack]:
        """Paste tracks from the clipboard onto the given bindings.

        Args:
            paste_token: Token from copy_tracks, or empty string.
            sequence: Destination sequence.
            target_bindings: Bindings to paste the tracks onto. Pass an empty
                list to paste as sequence-level tracks.
            parent_folder: Optional folder to place the pasted tracks under.

        Returns:
            List of newly-created tracks.
        """
        subsystem = unreal.get_editor_subsystem(
            unreal.LevelSequenceEditorSubsystem
        )
        paste_params = unreal.MovieScenePasteTracksParams()
        paste_params.sequence = sequence
        paste_params.bindings = target_bindings or []
        paste_params.folders = []
        paste_params.parent_folder = parent_folder
        return list(subsystem.paste_tracks(paste_token, paste_params))

    @toolset_registry.tool_call
    @staticmethod
    def copy_sections(
        sections: list[unreal.MovieSceneSection],
    ) -> str:
        """Copy one or more sections to the Sequencer clipboard.

        Args:
            sections: The sections to copy.

        Returns:
            The paste token string.
        """
        subsystem = unreal.get_editor_subsystem(
            unreal.LevelSequenceEditorSubsystem
        )
        return subsystem.copy_sections(sections)

    @toolset_registry.tool_call
    @staticmethod
    def paste_sections(
        paste_token: str,
        target_tracks: list[unreal.MovieSceneTrack],
        paste_frame: int = 0,
    ) -> list[unreal.MovieSceneSection]:
        """Paste sections from the clipboard onto the given tracks.

        Args:
            paste_token: Token from copy_sections, or empty string.
            target_tracks: Tracks to paste the sections onto.
            paste_frame: Frame at which to start the pasted sections.

        Returns:
            List of newly-created sections.
        """
        subsystem = unreal.get_editor_subsystem(
            unreal.LevelSequenceEditorSubsystem
        )
        paste_params = unreal.MovieScenePasteSectionsParams()
        paste_params.tracks = target_tracks
        paste_params.time = unreal.FrameTime(
            frame_number=unreal.FrameNumber(value=int(paste_frame))
        )
        paste_params.track_row_indices = []
        return list(subsystem.paste_sections(paste_token, paste_params))

    @toolset_registry.tool_call
    @staticmethod
    def copy_folders(
        folders: list[unreal.MovieSceneFolder],
    ) -> str:
        """Copy one or more folders to the Sequencer clipboard.

        Args:
            folders: The folders to copy.

        Returns:
            The paste token string.
        """
        subsystem = unreal.get_editor_subsystem(
            unreal.LevelSequenceEditorSubsystem
        )
        # copy_folders returns a 3-tuple: (folders_text, objects_text, tracks_text).
        # Only the folders_text is the paste token needed for paste_folders.
        result = subsystem.copy_folders(folders)
        if isinstance(result, tuple):
            return result[0]
        return result

    @toolset_registry.tool_call
    @staticmethod
    def paste_folders(
        paste_token: str,
        sequence: unreal.LevelSequence,
        parent_folder: unreal.MovieSceneFolder | None = None,
    ) -> list[unreal.MovieSceneFolder]:
        """Paste folders from the clipboard into the sequence.

        Args:
            paste_token: Token from copy_folders, or empty string.
            sequence: Destination sequence.
            parent_folder: Optional folder to paste into (for nesting).

        Returns:
            List of newly-created folders.
        """
        subsystem = unreal.get_editor_subsystem(
            unreal.LevelSequenceEditorSubsystem
        )
        paste_params = unreal.MovieScenePasteFoldersParams()
        paste_params.sequence = sequence
        paste_params.parent_folder = parent_folder
        return list(subsystem.paste_folders(paste_token, paste_params))
