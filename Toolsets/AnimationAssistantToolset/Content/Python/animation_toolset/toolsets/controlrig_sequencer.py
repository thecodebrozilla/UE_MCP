# Copyright Epic Games, Inc. All Rights Reserved.

import json

import unreal

import toolset_registry


@unreal.uclass()
class SequencerControlRigTools(unreal.ToolsetDefinition):
    """Tools for animating with Control Rig inside Sequencer. Use when adding
    Control Rig tracks to bindings, getting or setting control values (bool,
    float, int, position, rotator, scale, euler transform, transform), keying
    controls, baking animation to Control Rig, managing layered rigs and
    priority, masking controls per section, space switching (world, parent,
    control, bone), tweening and blending between keys, snapping controls to
    actors, mirroring poses, zeroing transforms, or managing animation layers
    (add, delete, duplicate, reorder, merge, collapse)."""


    # -- Internal helpers (not exposed as tools) --

    @staticmethod
    def _get_control_type(rig, control_name):
        """Get the ERigControlType for a control on the rig."""
        hierarchy = rig.get_hierarchy()
        key = unreal.RigElementKey(
            type=unreal.RigElementType.CONTROL, name=control_name
        )
        element = hierarchy.find_control(key)
        if element:
            return element.settings.control_type
        return None

    @staticmethod
    def _find_rig(sequence, control_rig_asset_path):
        """Resolve a UControlRig from the sequence by matching asset path.

        Returns the UControlRig instance or raises ValueError.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        proxies = unreal.ControlRigSequencerLibrary.get_control_rigs(sequence)
        for p in proxies:
            if control_rig_asset_path in str(p.control_rig.get_class().get_path_name()):
                return p.control_rig
        raise ValueError(
            f"Control Rig matching '{control_rig_asset_path}' not found in sequence."
        )

    @staticmethod
    def _find_rig_and_track(sequence, control_rig_asset_path):
        """Resolve both UControlRig and its track from the sequence.

        Returns a tuple of (UControlRig, UMovieSceneControlRigParameterTrack)
        or raises ValueError.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        proxies = unreal.ControlRigSequencerLibrary.get_control_rigs(sequence)
        for p in proxies:
            if control_rig_asset_path in str(p.control_rig.get_class().get_path_name()):
                return p.control_rig, p.track
        raise ValueError(
            f"Control Rig matching '{control_rig_asset_path}' not found in sequence."
        )

    # -- Group 1: Control Value Get/Set --

    @toolset_registry.tool_call
    @staticmethod
    def get_float(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        control_name: str,
        frame: int
    ) -> float:
        """Get a float control value at a specific frame.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.
            control_name: Name of the float control.
            frame: The frame number.

        Returns:
            The float value at the given frame.
        """
        rig = SequencerControlRigTools._find_rig(sequence, control_rig_asset_path)
        return unreal.ControlRigSequencerLibrary.get_local_control_rig_float(
            sequence, rig, control_name, unreal.FrameNumber(value=frame)
        )

    @toolset_registry.tool_call
    @staticmethod
    def set_float(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        control_name: str,
        frame: int,
        value: float,
        set_key: bool = True
    ) -> bool:
        """Set a float control value at a specific frame.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.
            control_name: Name of the float control.
            frame: The frame number.
            value: The float value to set.
            set_key: If True, set a keyframe at this frame.
        """
        rig = SequencerControlRigTools._find_rig(sequence, control_rig_asset_path)
        unreal.ControlRigSequencerLibrary.set_local_control_rig_float(
            sequence, rig, control_name, unreal.FrameNumber(value=frame),
            value, set_key=set_key
        )
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_bool(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        control_name: str,
        frame: int
    ) -> bool:
        """Get a bool control value at a specific frame.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.
            control_name: Name of the bool control.
            frame: The frame number.

        Returns:
            The bool value at the given frame.
        """
        rig = SequencerControlRigTools._find_rig(sequence, control_rig_asset_path)
        return unreal.ControlRigSequencerLibrary.get_local_control_rig_bool(
            sequence, rig, control_name, unreal.FrameNumber(value=frame)
        )

    @toolset_registry.tool_call
    @staticmethod
    def set_bool(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        control_name: str,
        frame: int,
        value: bool,
        set_key: bool = True
    ) -> bool:
        """Set a bool control value at a specific frame.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.
            control_name: Name of the bool control.
            frame: The frame number.
            value: The bool value to set.
            set_key: If True, set a keyframe at this frame.
        """
        rig = SequencerControlRigTools._find_rig(sequence, control_rig_asset_path)
        unreal.ControlRigSequencerLibrary.set_local_control_rig_bool(
            sequence, rig, control_name, unreal.FrameNumber(value=frame),
            value, set_key=set_key
        )
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_int(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        control_name: str,
        frame: int
    ) -> int:
        """Get an integer control value at a specific frame.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.
            control_name: Name of the integer control.
            frame: The frame number.

        Returns:
            The integer value at the given frame.
        """
        rig = SequencerControlRigTools._find_rig(sequence, control_rig_asset_path)
        return unreal.ControlRigSequencerLibrary.get_local_control_rig_int(
            sequence, rig, control_name, unreal.FrameNumber(value=frame)
        )

    @toolset_registry.tool_call
    @staticmethod
    def set_int(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        control_name: str,
        frame: int,
        value: int,
        set_key: bool = True
    ) -> bool:
        """Set an integer control value at a specific frame.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.
            control_name: Name of the integer control.
            frame: The frame number.
            value: The integer value to set.
            set_key: If True, set a keyframe at this frame.
        """
        rig = SequencerControlRigTools._find_rig(sequence, control_rig_asset_path)
        unreal.ControlRigSequencerLibrary.set_local_control_rig_int(
            sequence, rig, control_name, unreal.FrameNumber(value=frame),
            value, set_key=set_key
        )
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_vector2d(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        control_name: str,
        frame: int
    ) -> str:
        """Get a Vector2D control value at a specific frame.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.
            control_name: Name of the Vector2D control.
            frame: The frame number.

        Returns:
            JSON string with 'x' and 'y' fields.
        """

        rig = SequencerControlRigTools._find_rig(sequence, control_rig_asset_path)
        v = unreal.ControlRigSequencerLibrary.get_local_control_rig_vector2d(
            sequence, rig, control_name, unreal.FrameNumber(value=frame)
        )
        return json.dumps({"x": v.x, "y": v.y})

    @toolset_registry.tool_call
    @staticmethod
    def set_vector2d(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        control_name: str,
        frame: int,
        x: float = 0.0,
        y: float = 0.0,
        set_key: bool = True
    ) -> bool:
        """Set a Vector2D control value at a specific frame.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.
            control_name: Name of the Vector2D control.
            frame: The frame number.
            x: X component.
            y: Y component.
            set_key: If True, set a keyframe at this frame.
        """
        rig = SequencerControlRigTools._find_rig(sequence, control_rig_asset_path)
        unreal.ControlRigSequencerLibrary.set_local_control_rig_vector2d(
            sequence, rig, control_name, unreal.FrameNumber(value=frame),
            unreal.Vector2D(x, y), set_key=set_key
        )
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_position(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        control_name: str,
        frame: int
    ) -> str:
        """Get a position control value at a specific frame.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.
            control_name: Name of the position control.
            frame: The frame number.

        Returns:
            JSON string with 'x', 'y', 'z' fields.
        """

        rig = SequencerControlRigTools._find_rig(sequence, control_rig_asset_path)
        v = unreal.ControlRigSequencerLibrary.get_local_control_rig_position(
            sequence, rig, control_name, unreal.FrameNumber(value=frame)
        )
        return json.dumps({"x": v.x, "y": v.y, "z": v.z})

    @toolset_registry.tool_call
    @staticmethod
    def set_position(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        control_name: str,
        frame: int,
        x: float = 0.0,
        y: float = 0.0,
        z: float = 0.0,
        set_key: bool = True
    ) -> bool:
        """Set a position control value at a specific frame.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.
            control_name: Name of the position control.
            frame: The frame number.
            x: X component.
            y: Y component.
            z: Z component.
            set_key: If True, set a keyframe at this frame.
        """
        rig = SequencerControlRigTools._find_rig(sequence, control_rig_asset_path)
        unreal.ControlRigSequencerLibrary.set_local_control_rig_position(
            sequence, rig, control_name, unreal.FrameNumber(value=frame),
            unreal.Vector(x, y, z), set_key=set_key
        )
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_rotator(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        control_name: str,
        frame: int
    ) -> str:
        """Get a rotator control value at a specific frame.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.
            control_name: Name of the rotator control.
            frame: The frame number.

        Returns:
            JSON string with 'pitch', 'yaw', 'roll' fields.
        """

        rig = SequencerControlRigTools._find_rig(sequence, control_rig_asset_path)
        r = unreal.ControlRigSequencerLibrary.get_local_control_rig_rotator(
            sequence, rig, control_name, unreal.FrameNumber(value=frame)
        )
        return json.dumps({"pitch": r.pitch, "yaw": r.yaw, "roll": r.roll})

    @toolset_registry.tool_call
    @staticmethod
    def set_rotator(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        control_name: str,
        frame: int,
        pitch: float = 0.0,
        yaw: float = 0.0,
        roll: float = 0.0,
        set_key: bool = True
    ) -> bool:
        """Set a rotator control value at a specific frame.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.
            control_name: Name of the rotator control.
            frame: The frame number.
            pitch: Pitch in degrees.
            yaw: Yaw in degrees.
            roll: Roll in degrees.
            set_key: If True, set a keyframe at this frame.
        """
        rig = SequencerControlRigTools._find_rig(sequence, control_rig_asset_path)
        unreal.ControlRigSequencerLibrary.set_local_control_rig_rotator(
            sequence, rig, control_name, unreal.FrameNumber(value=frame),
            unreal.Rotator(pitch=pitch, yaw=yaw, roll=roll), set_key=set_key
        )
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_scale(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        control_name: str,
        frame: int
    ) -> str:
        """Get a scale control value at a specific frame.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.
            control_name: Name of the scale control.
            frame: The frame number.

        Returns:
            JSON string with 'x', 'y', 'z' fields.
        """

        rig = SequencerControlRigTools._find_rig(sequence, control_rig_asset_path)
        v = unreal.ControlRigSequencerLibrary.get_local_control_rig_scale(
            sequence, rig, control_name, unreal.FrameNumber(value=frame)
        )
        return json.dumps({"x": v.x, "y": v.y, "z": v.z})

    @toolset_registry.tool_call
    @staticmethod
    def set_scale(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        control_name: str,
        frame: int,
        x: float = 1.0,
        y: float = 1.0,
        z: float = 1.0,
        set_key: bool = True
    ) -> bool:
        """Set a scale control value at a specific frame.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.
            control_name: Name of the scale control.
            frame: The frame number.
            x: X scale.
            y: Y scale.
            z: Z scale.
            set_key: If True, set a keyframe at this frame.
        """
        rig = SequencerControlRigTools._find_rig(sequence, control_rig_asset_path)
        unreal.ControlRigSequencerLibrary.set_local_control_rig_scale(
            sequence, rig, control_name, unreal.FrameNumber(value=frame),
            unreal.Vector(x, y, z), set_key=set_key
        )
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_euler_transform(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        control_name: str,
        frame: int
    ) -> str:
        """Get an EulerTransform control value at a specific frame.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.
            control_name: Name of the EulerTransform control.
            frame: The frame number.

        Returns:
            JSON string with 'location' (x,y,z), 'rotation' (pitch,yaw,roll),
            and 'scale' (x,y,z) dicts.
        """

        rig = SequencerControlRigTools._find_rig(sequence, control_rig_asset_path)
        et = unreal.ControlRigSequencerLibrary.get_local_control_rig_euler_transform(
            sequence, rig, control_name, unreal.FrameNumber(value=frame)
        )
        loc = et.location
        rot = et.rotation
        scl = et.scale
        return json.dumps({
            "location": {"x": loc.x, "y": loc.y, "z": loc.z},
            "rotation": {"pitch": rot.pitch, "yaw": rot.yaw, "roll": rot.roll},
            "scale": {"x": scl.x, "y": scl.y, "z": scl.z},
        })

    @toolset_registry.tool_call
    @staticmethod
    def set_euler_transform(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        control_name: str,
        frame: int,
        location_x: float = 0.0, location_y: float = 0.0, location_z: float = 0.0,
        rotation_pitch: float = 0.0, rotation_yaw: float = 0.0, rotation_roll: float = 0.0,
        scale_x: float = 1.0, scale_y: float = 1.0, scale_z: float = 1.0,
        set_key: bool = True
    ) -> bool:
        """Set an EulerTransform control value at a specific frame.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.
            control_name: Name of the EulerTransform control.
            frame: The frame number.
            location_x: X location.
            location_y: Y location.
            location_z: Z location.
            rotation_pitch: Pitch in degrees.
            rotation_yaw: Yaw in degrees.
            rotation_roll: Roll in degrees.
            scale_x: X scale.
            scale_y: Y scale.
            scale_z: Z scale.
            set_key: If True, set a keyframe at this frame.
        """
        rig = SequencerControlRigTools._find_rig(sequence, control_rig_asset_path)
        et = unreal.EulerTransform()
        et.location = unreal.Vector(location_x, location_y, location_z)
        et.rotation = unreal.Rotator(pitch=rotation_pitch, yaw=rotation_yaw, roll=rotation_roll)
        et.scale = unreal.Vector(scale_x, scale_y, scale_z)
        unreal.ControlRigSequencerLibrary.set_local_control_rig_euler_transform(
            sequence, rig, control_name, unreal.FrameNumber(value=frame),
            et, set_key=set_key
        )
        return True

    # -- Group 2: World Transforms --

    @toolset_registry.tool_call
    @staticmethod
    def get_world_transform(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        control_name: str,
        frame: int
    ) -> str:
        """Get a control's world-space transform at a specific frame.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.
            control_name: Name of the control.
            frame: The frame number.

        Returns:
            JSON string with 'location' (x,y,z) and 'rotation' (pitch,yaw,roll).
        """

        rig = SequencerControlRigTools._find_rig(sequence, control_rig_asset_path)
        t = unreal.ControlRigSequencerLibrary.get_control_rig_world_transform(
            sequence, rig, control_name, unreal.FrameNumber(value=frame)
        )
        rot = t.rotation.rotator()
        return json.dumps({
            "location": {"x": t.translation.x, "y": t.translation.y, "z": t.translation.z},
            "rotation": {"pitch": rot.pitch, "yaw": rot.yaw, "roll": rot.roll},
        })

    @toolset_registry.tool_call
    @staticmethod
    def set_world_transform(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        control_name: str,
        frame: int,
        location_x: float = 0.0, location_y: float = 0.0, location_z: float = 0.0,
        rotation_pitch: float = 0.0, rotation_yaw: float = 0.0, rotation_roll: float = 0.0,
        set_key: bool = True
    ) -> bool:
        """Set a control's world-space transform at a specific frame.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.
            control_name: Name of the control.
            frame: The frame number.
            location_x: World X location.
            location_y: World Y location.
            location_z: World Z location.
            rotation_pitch: Pitch in degrees.
            rotation_yaw: Yaw in degrees.
            rotation_roll: Roll in degrees.
            set_key: If True, set a keyframe at this frame.
        """
        rig = SequencerControlRigTools._find_rig(sequence, control_rig_asset_path)
        transform = unreal.Transform(
            location=[location_x, location_y, location_z],
            rotation=[rotation_pitch, rotation_yaw, rotation_roll],
            scale=[1.0, 1.0, 1.0]
        )
        unreal.ControlRigSequencerLibrary.set_control_rig_world_transform(
            sequence, rig, control_name, unreal.FrameNumber(value=frame),
            transform, set_key=set_key
        )
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_actor_transform_at_frame(
        sequence: unreal.LevelSequence,
        actor_name: str,
        frame: int
    ) -> str:
        """Get an actor's world transform at a specific frame.

        Finds the actor by name in the current editor world.

        Args:
            sequence: The LevelSequence.
            actor_name: The name or label of the actor in the level.
            frame: The frame number.

        Returns:
            JSON string with 'location' (x,y,z) and 'rotation' (pitch,yaw,roll).
        """

        if not sequence:
            raise ValueError("Sequence is None.")
        editor_system = unreal.get_editor_subsystem(unreal.UnrealEditorSubsystem)
        world = editor_system.get_editor_world()
        actors = unreal.GameplayStatics.get_all_actors_of_class(world, unreal.Actor)
        actor = None
        for a in actors:
            if actor_name in a.get_actor_label() or actor_name in a.get_name():
                actor = a
                break
        if not actor:
            raise ValueError(f"Actor '{actor_name}' not found in level.")
        t = unreal.ControlRigSequencerLibrary.get_actor_world_transform(
            sequence, actor, unreal.FrameNumber(value=frame)
        )
        rot = t.rotation.rotator()
        return json.dumps({
            "location": {"x": t.translation.x, "y": t.translation.y, "z": t.translation.z},
            "rotation": {"pitch": rot.pitch, "yaw": rot.yaw, "roll": rot.roll},
        })

    # -- Group 3: Keying --

    @toolset_registry.tool_call
    @staticmethod
    def key_controls(
        section: unreal.MovieSceneSection,
        control_names: list[str]
    ) -> bool:
        """Key the specified controls on the section at the current Sequencer time.

        Args:
            section: The Control Rig parameter section.
            control_names: List of control names to key.
        """
        if not section:
            raise ValueError("Section is None.")
        if not control_names:
            raise ValueError("control_names is empty.")
        unreal.ControlRigSequencerLibrary.key_controls(
            section, control_names
        )
        return True

    @toolset_registry.tool_call
    @staticmethod
    def key_controls_at_frames(
        section: unreal.MovieSceneSection,
        control_names: list[str],
        frames: list[int]
    ) -> bool:
        """Key the specified controls at specific frame numbers.

        Args:
            section: The Control Rig parameter section.
            control_names: List of control names to key.
            frames: List of frame numbers at which to set keys.
        """
        if not section:
            raise ValueError("Section is None.")
        if not control_names:
            raise ValueError("control_names is empty.")
        if not frames:
            raise ValueError("frames is empty.")
        frame_nums = [unreal.FrameNumber(value=f) for f in frames]
        unreal.ControlRigSequencerLibrary.key_controls_at_frames(
            section, control_names, frame_nums
        )
        return True

    # -- Group 4: Baking --

    @toolset_registry.tool_call
    @staticmethod
    def bake_to_control_rig(
        sequence: unreal.LevelSequence,
        binding: unreal.SequencerBindingProxy,
        control_rig_asset_path: str,
        reduce_keys: bool = False,
        tolerance: float = 0.001,
        reset_controls: bool = True
    ) -> bool:
        """Bake existing animation on a binding into a Control Rig track.

        Args:
            sequence: The LevelSequence.
            binding: The skeletal mesh binding to bake from.
            control_rig_asset_path: Path to the CR asset to bake into.
            reduce_keys: If True, perform key reduction after baking.
            tolerance: Key reduction tolerance. Smaller values keep more keys.
            reset_controls: If True, reset all controls to initial value per frame.

        Returns:
            True if baking succeeded.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        rig_asset = unreal.load_asset(control_rig_asset_path)
        if not rig_asset:
            raise ValueError(f"Could not load CR asset '{control_rig_asset_path}'.")
        rig_class = rig_asset.get_control_rig_class()
        if not rig_class:
            raise ValueError(f"Asset '{control_rig_asset_path}' has no CR class.")
        editor_system = unreal.get_editor_subsystem(unreal.UnrealEditorSubsystem)
        world = editor_system.get_editor_world()
        export_options = unreal.AnimSeqExportOption()
        return unreal.ControlRigSequencerLibrary.bake_to_control_rig(
            world, sequence, rig_class, export_options,
            reduce_keys, tolerance, binding,
            reset_controls=reset_controls
        )

    @toolset_registry.tool_call
    @staticmethod
    def load_anim_into_rig(
        cr_section: unreal.MovieSceneSection,
        anim_sequence_path: str,
        start_frame: int = 0,
        reset_controls: bool = True,
        key_reduce: bool = False,
        tolerance: float = 0.001
    ) -> bool:
        """Load an animation sequence into a Control Rig section.

        Finds the skeletal mesh component from the binding associated with
        the section's track.

        Args:
            cr_section: The Control Rig parameter section to load into.
            anim_sequence_path: Content path to the AnimSequence asset.
            start_frame: Frame at which to insert the animation.
            reset_controls: If True, reset controls to initial value per frame.
            key_reduce: If True, perform key reduction.
            tolerance: Key reduction tolerance.

        Returns:
            True if the load succeeded.
        """
        if not cr_section:
            raise ValueError("cr_section is None.")
        anim_seq = unreal.load_asset(anim_sequence_path)
        if not anim_seq:
            raise ValueError(f"Could not load AnimSequence '{anim_sequence_path}'.")
        editor_system = unreal.get_editor_subsystem(unreal.UnrealEditorSubsystem)
        world = editor_system.get_editor_world()
        # Find the skel mesh component from the binding that owns this CR track.
        track = cr_section.get_outer()
        sequence = track.get_outer().get_outer()
        # Resolve the owning binding by matching the track against each binding's tracks.
        owner_binding = None
        for b in sequence.get_bindings():
            if track in b.get_tracks():
                owner_binding = b
                break
        if not owner_binding:
            raise ValueError("Could not find the binding that owns this Control Rig track.")
        skel_comp = None
        bound_objects = unreal.SequencerTools.get_bound_objects(
            world, sequence, [owner_binding], sequence.get_playback_range()
        )
        for bo in bound_objects:
            for obj in bo.bound_objects:
                if isinstance(obj, unreal.SkeletalMeshComponent):
                    skel_comp = obj
                    break
                if isinstance(obj, unreal.Actor):
                    comp = obj.get_component_by_class(unreal.SkeletalMeshComponent)
                    if comp:
                        skel_comp = comp
                        break
            if skel_comp:
                break
        if not skel_comp:
            raise ValueError("Could not find a SkeletalMeshComponent on the CR track's binding.")
        return unreal.ControlRigSequencerLibrary.load_anim_sequence_into_control_rig_section_with_range(
            cr_section, anim_seq, skel_comp,
            unreal.FrameNumber(value=start_frame),
            False, unreal.FrameNumber(value=0), unreal.FrameNumber(value=0),
            key_reduce=key_reduce, tolerance=tolerance,
            reset_controls=reset_controls
        )

    @toolset_registry.tool_call
    @staticmethod
    def collapse_anim_layers(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        reduce_keys: bool = False,
        tolerance: float = 0.001
    ) -> bool:
        """Collapse all sections and layers on a Control Rig track into one section.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.
            reduce_keys: If True, perform key reduction after collapsing.
            tolerance: Key reduction tolerance.

        Returns:
            True if collapsing succeeded.
        """
        _, track = SequencerControlRigTools._find_rig_and_track(sequence, control_rig_asset_path)
        return unreal.ControlRigSequencerLibrary.collapse_control_rig_anim_layers(
            sequence, track, key_reduce=reduce_keys, tolerance=tolerance
        )

    # -- Group 5: Masking --

    @toolset_registry.tool_call
    @staticmethod
    def get_controls_mask(
        section: unreal.MovieSceneSection,
        control_name: str
    ) -> bool:
        """Check if a control is visible (unmasked) on a section.

        Args:
            section: The Control Rig parameter section.
            control_name: The control name to check.

        Returns:
            True if the control is visible, False if masked.
        """
        if not section:
            raise ValueError("Section is None.")
        return unreal.ControlRigSequencerLibrary.get_controls_mask(
            section, control_name
        )

    @toolset_registry.tool_call
    @staticmethod
    def set_controls_mask(
        section: unreal.MovieSceneSection,
        control_names: list[str],
        visible: bool
    ) -> bool:
        """Set the visibility mask for the specified controls on a section.

        Args:
            section: The Control Rig parameter section.
            control_names: List of control names to affect.
            visible: True to show, False to hide.
        """
        if not section:
            raise ValueError("Section is None.")
        if not control_names:
            raise ValueError("control_names is empty.")
        unreal.ControlRigSequencerLibrary.set_controls_mask(
            section, control_names, visible
        )
        return True

    @toolset_registry.tool_call
    @staticmethod
    def show_all_controls(section: unreal.MovieSceneSection) -> bool:
        """Show all controls on a Control Rig section (unmask everything).

        Args:
            section: The Control Rig parameter section.
        """
        if not section:
            raise ValueError("Section is None.")
        unreal.ControlRigSequencerLibrary.show_all_controls(section)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def hide_all_controls(section: unreal.MovieSceneSection) -> bool:
        """Hide all controls on a Control Rig section (mask everything).

        Args:
            section: The Control Rig parameter section.
        """
        if not section:
            raise ValueError("Section is None.")
        unreal.ControlRigSequencerLibrary.hide_all_controls(section)
        return True

    # -- Group 6: Layering & FK --

    @toolset_registry.tool_call
    @staticmethod
    def is_layered_control_rig(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str
    ) -> bool:
        """Check if a Control Rig in the sequence is in layered mode.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.

        Returns:
            True if the rig is in layered mode.
        """
        rig = SequencerControlRigTools._find_rig(sequence, control_rig_asset_path)
        return unreal.ControlRigSequencerLibrary.is_layered_control_rig(rig)

    @toolset_registry.tool_call
    @staticmethod
    def set_layered_mode(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        is_layered: bool
    ) -> bool:
        """Set a Control Rig track to layered or absolute mode.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.
            is_layered: True for layered, False for absolute.

        Returns:
            True if the mode was set successfully.
        """
        _, track = SequencerControlRigTools._find_rig_and_track(sequence, control_rig_asset_path)
        return unreal.ControlRigSequencerLibrary.set_control_rig_layered_mode(
            track, is_layered
        )

    @toolset_registry.tool_call
    @staticmethod
    def get_priority_order(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str
    ) -> int:
        """Get the evaluation priority order of a Control Rig track.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.

        Returns:
            The priority order integer.
        """
        _, track = SequencerControlRigTools._find_rig_and_track(sequence, control_rig_asset_path)
        return unreal.ControlRigSequencerLibrary.get_control_rig_priority_order(track)

    @toolset_registry.tool_call
    @staticmethod
    def set_priority_order(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        order: int
    ) -> bool:
        """Set the evaluation priority order of a Control Rig track.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.
            order: The priority order value to set.
        """
        _, track = SequencerControlRigTools._find_rig_and_track(sequence, control_rig_asset_path)
        unreal.ControlRigSequencerLibrary.set_control_rig_priority_order(track, order)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def is_fk_control_rig(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str
    ) -> bool:
        """Check if a Control Rig is an FK Control Rig.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.

        Returns:
            True if the rig is an FK Control Rig.
        """
        rig = SequencerControlRigTools._find_rig(sequence, control_rig_asset_path)
        return unreal.ControlRigSequencerLibrary.is_fk_control_rig(rig)

    # -- Group 7: Space Switching --

    @toolset_registry.tool_call
    @staticmethod
    def set_space(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        control_name: str,
        space_type: str,
        frame: int,
        space_target: str = ""
    ) -> bool:
        """Set the space for a Control Rig control at a given frame.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.
            control_name: Name of the control.
            space_type: One of 'world', 'default_parent', 'control', or 'bone'.
                For 'control' or 'bone', space_target must name the element.
            frame: Frame at which to set the space switch key.
            space_target: For 'control' or 'bone' types, the name of the
                target element. Ignored for 'world' and 'default_parent'.

        Returns:
            True if the space key was set successfully.
        """
        rig = SequencerControlRigTools._find_rig(sequence, control_rig_asset_path)
        st = space_type.lower()
        if st == "world":
            space_key = unreal.ControlRigSequencerLibrary.get_world_space_reference_key()
        elif st == "default_parent":
            space_key = unreal.ControlRigSequencerLibrary.get_default_parent_key()
        elif st == "control":
            if not space_target:
                raise ValueError("space_target is required for space_type 'control'.")
            space_key = unreal.RigElementKey(name=space_target, type=unreal.RigElementType.CONTROL)
        elif st == "bone":
            if not space_target:
                raise ValueError("space_target is required for space_type 'bone'.")
            space_key = unreal.RigElementKey(name=space_target, type=unreal.RigElementType.BONE)
        else:
            raise ValueError(
                f"Invalid space_type '{space_type}'. "
                "Must be 'world', 'default_parent', 'control', or 'bone'."
            )
        return unreal.ControlRigSequencerLibrary.set_control_rig_space(
            sequence, rig, control_name, space_key,
            unreal.FrameNumber(value=frame)
        )

    @toolset_registry.tool_call
    @staticmethod
    def move_space(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        control_name: str,
        old_frame: int,
        new_frame: int
    ) -> bool:
        """Move a space-switch key from one frame to another.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.
            control_name: Name of the control.
            old_frame: The current frame of the space key.
            new_frame: The new frame to move the space key to.

        Returns:
            True if the move succeeded.
        """
        rig = SequencerControlRigTools._find_rig(sequence, control_rig_asset_path)
        return unreal.ControlRigSequencerLibrary.move_control_rig_space(
            sequence, rig, control_name,
            unreal.FrameNumber(value=old_frame),
            unreal.FrameNumber(value=new_frame)
        )

    @toolset_registry.tool_call
    @staticmethod
    def delete_space(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        control_name: str,
        frame: int
    ) -> bool:
        """Delete a space-switch key at a specific frame.

        Performs compensation to the new space automatically.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.
            control_name: Name of the control.
            frame: Frame of the space key to delete.

        Returns:
            True if the deletion succeeded.
        """
        rig = SequencerControlRigTools._find_rig(sequence, control_rig_asset_path)
        return unreal.ControlRigSequencerLibrary.delete_control_rig_space(
            sequence, rig, control_name, unreal.FrameNumber(value=frame)
        )

    @toolset_registry.tool_call
    @staticmethod
    def bake_space(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        control_names: list[str],
        start_frame: int,
        end_frame: int,
        reduce_keys: bool = False,
        tolerance: float = 0.001
    ) -> bool:
        """Bake Control Rig controls' space over a frame range.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.
            control_names: Names of controls to bake.
            start_frame: Start of the bake range.
            end_frame: End of the bake range.
            reduce_keys: If True, perform key reduction after baking.
            tolerance: Key reduction tolerance.

        Returns:
            True if the bake succeeded.
        """
        rig = SequencerControlRigTools._find_rig(sequence, control_rig_asset_path)
        settings = unreal.RigSpacePickerBakeSettings()
        settings.start_frame = unreal.FrameNumber(value=start_frame)
        settings.end_frame = unreal.FrameNumber(value=end_frame)
        settings.reduce_keys = reduce_keys
        settings.tolerance = tolerance
        return unreal.ControlRigSequencerLibrary.bake_control_rig_space(
            sequence, rig, control_names, settings
        )

    # -- Group 8: Tween & Blend --

    @toolset_registry.tool_call
    @staticmethod
    def tween_control_rig(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        tween_value: float
    ) -> bool:
        """Perform a tween operation on a Control Rig at the current Sequencer time.

        The tween blends between the previous and next keyframe values.

        Args:
            sequence: The LevelSequence (must be open in Sequencer).
            control_rig_asset_path: Path to identify which Control Rig.
            tween_value: Blend value from -1.0 (previous key) to 1.0 (next key).

        Returns:
            True if tween succeeded.
        """
        rig = SequencerControlRigTools._find_rig(sequence, control_rig_asset_path)
        return unreal.ControlRigSequencerLibrary.tween_control_rig(
            sequence, rig, tween_value
        )

    @toolset_registry.tool_call
    @staticmethod
    def blend_values_on_selected(
        sequence: unreal.LevelSequence,
        operation: str,
        blend_value: float
    ) -> bool:
        """Perform a blend operation on selected keys or controls.

        Args:
            sequence: The LevelSequence (must be open in Sequencer).
            operation: The blend operation. One of: 'tween',
                'blend_to_neighbor', 'push_pull', 'blend_relative',
                'blend_to_ease', 'smooth_rough'.
            blend_value: Blend value, typically -1.0 to 1.0.

        Returns:
            True if the blend succeeded.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        op_map = {
            "tween": unreal.AnimToolBlendOperation.TWEEN,
            "blend_to_neighbor": unreal.AnimToolBlendOperation.BLEND_TO_NEIGHBOR,
            "push_pull": unreal.AnimToolBlendOperation.PUSH_PULL,
            "blend_relative": unreal.AnimToolBlendOperation.BLEND_RELATIVE,
            "blend_to_ease": unreal.AnimToolBlendOperation.BLEND_TO_EASE,
            "smooth_rough": unreal.AnimToolBlendOperation.SMOOTH_ROUGH,
        }
        op_lower = operation.lower()
        if op_lower not in op_map:
            raise ValueError(
                f"Invalid operation '{operation}'. Must be one of: "
                f"{', '.join(op_map.keys())}"
            )
        return unreal.ControlRigSequencerLibrary.blend_values_on_selected(
            sequence, op_map[op_lower], blend_value
        )

    # -- Group 9: Snapping --

    @toolset_registry.tool_call
    @staticmethod
    def snap_control_rig(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        control_names: list[str],
        target_actor_name: str,
        start_frame: int,
        end_frame: int,
        keep_offset: bool = False,
        snap_position: bool = True,
        snap_rotation: bool = True,
        snap_scale: bool = False
    ) -> bool:
        """Snap Control Rig controls to a target actor over a frame range.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.
            control_names: Names of controls to snap.
            target_actor_name: Name or label of the target actor in the level.
            start_frame: Start frame of the snap range.
            end_frame: End frame of the snap range.
            keep_offset: If True, maintain the initial offset.
            snap_position: If True, snap position.
            snap_rotation: If True, snap rotation.
            snap_scale: If True, snap scale.

        Returns:
            True if the snap succeeded.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        rig = SequencerControlRigTools._find_rig(sequence, control_rig_asset_path)
        editor_system = unreal.get_editor_subsystem(unreal.UnrealEditorSubsystem)
        world = editor_system.get_editor_world()
        actors = unreal.GameplayStatics.get_all_actors_of_class(world, unreal.Actor)
        target_actor = None
        for a in actors:
            if target_actor_name in a.get_actor_label() or target_actor_name in a.get_name():
                target_actor = a
                break
        if not target_actor:
            raise ValueError(f"Target actor '{target_actor_name}' not found in level.")
        snap_settings = unreal.ControlRigSnapSettings()
        snap_settings.keep_offset = keep_offset
        snap_settings.snap_position = snap_position
        snap_settings.snap_rotation = snap_rotation
        snap_settings.snap_scale = snap_scale
        child_selection = unreal.ControlRigSnapperSelection()
        child_selection.control_rig = rig
        child_selection.control_names = control_names
        parent_selection = unreal.ControlRigSnapperSelection()
        parent_selection.actors = [target_actor]
        return unreal.ControlRigSequencerLibrary.snap_control_rig(
            sequence,
            unreal.FrameNumber(value=start_frame),
            unreal.FrameNumber(value=end_frame),
            child_selection, parent_selection, snap_settings
        )

    # -- Group 10: Animation Layers --

    @toolset_registry.tool_call
    @staticmethod
    def get_anim_layers() -> str:
        """Get all animation layers from the active Sequencer.

        Returns:
            JSON string with a list of layer objects, each containing
            'index' and 'name'.
        """

        layers = unreal.ControlRigSequencerLibrary.get_anim_layers(True)
        result = []
        for i, layer in enumerate(layers):
            result.append({
                "index": i,
                "name": str(layer.get_name()),
            })
        return json.dumps(result)

    @toolset_registry.tool_call
    @staticmethod
    def add_layer_from_selection() -> int:
        """Add an animation layer from the currently selected objects in Sequencer.

        Returns:
            The index of the newly created animation layer.
        """
        return unreal.ControlRigSequencerLibrary.add_anim_layer_from_selection()

    @toolset_registry.tool_call
    @staticmethod
    def delete_anim_layer(index: int) -> bool:
        """Delete an animation layer at the specified index.

        Args:
            index: The index of the layer to delete.

        Returns:
            True if the layer was deleted successfully.
        """
        return unreal.ControlRigSequencerLibrary.delete_anim_layer(index)

    @toolset_registry.tool_call
    @staticmethod
    def duplicate_anim_layer(index: int) -> int:
        """Duplicate an animation layer at the specified index.

        Args:
            index: The index of the layer to duplicate.

        Returns:
            The index of the newly created duplicate layer, or -1 on failure.
        """
        return unreal.ControlRigSequencerLibrary.duplicate_anim_layer(index)

    @toolset_registry.tool_call
    @staticmethod
    def reorder_anim_layers(old_index: int, new_index: int) -> bool:
        """Move an animation layer from one index to another.

        Cannot move the base layer (index 0).

        Args:
            old_index: Current index of the layer to move.
            new_index: Target index to move the layer to.

        Returns:
            True if the reorder succeeded.
        """
        return unreal.ControlRigSequencerLibrary.reorder_anim_layers(
            old_index, new_index
        )

    @toolset_registry.tool_call
    @staticmethod
    def merge_anim_layers(indices: list[int]) -> bool:
        """Merge specified animation layers into one.

        Merges onto the layer with the lowest index.

        Args:
            indices: List of layer indices to merge.

        Returns:
            True if the merge succeeded.
        """
        if not indices:
            raise ValueError("indices is empty.")
        settings = unreal.MergeAnimLayerSettings()
        return unreal.ControlRigSequencerLibrary.merge_anim_layers_with_settings(
            indices, settings
        )

    # -- Group 11: Mirroring --

    @toolset_registry.tool_call
    @staticmethod
    def select_mirrored_controls() -> bool:
        """Select the mirrored counterparts of the currently selected controls.

        Replaces the current selection with mirrored controls.
        """
        unreal.ControlRigSequencerLibrary.select_mirrored_controls()
        return True

    @toolset_registry.tool_call
    @staticmethod
    def mirror_selected_controls() -> bool:
        """Apply a mirrored pose to the currently selected controls."""
        unreal.ControlRigSequencerLibrary.mirror_selected_controls()
        return True

    # -- Group 12: Misc --

    @toolset_registry.tool_call
    @staticmethod
    def zero_transforms(
        selection_only: bool = True,
        include_channels: bool = True
    ) -> bool:
        """Reset Control Rig transforms to their default (usually zero) values.

        Args:
            selection_only: If True, only reset controls on rigs with
                selected controls. If False, reset all.
            include_channels: If True, include channels in addition to
                parent controls.
        """
        unreal.ControlRigSequencerLibrary.zero_transforms(
            selection_only, include_channels
        )
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_selected_controls(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str
    ) -> list[str]:
        """Get the currently selected controls on a Control Rig.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.

        Returns:
            List of selected control names.
        """
        rig = SequencerControlRigTools._find_rig(sequence, control_rig_asset_path)
        return [str(n) for n in rig.current_control_selection()]

    @toolset_registry.tool_call
    @staticmethod
    def select_control(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        control_name: str,
        selected: bool = True
    ) -> bool:
        """Select or deselect a control on a Control Rig.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.
            control_name: Name of the control.
            selected: True to select, False to deselect.
        """
        rig = SequencerControlRigTools._find_rig(sequence, control_rig_asset_path)
        rig.select_control(control_name, selected)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def clear_selection() -> bool:
        """Clear the current Control Rig control selection."""
        unreal.ControlRigSequencerLibrary.clear_selection()
        return True

    @toolset_registry.tool_call
    @staticmethod
    def frame_selection() -> bool:
        """Frame the viewport to the current Control Rig control selection."""
        unreal.ControlRigSequencerLibrary.frame_selection()
        return True

    # -- Group 13: FBX --

    @toolset_registry.tool_call
    @staticmethod
    def export_fbx_from_rig(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        export_file_path: str,
        ascii: bool = False
    ) -> bool:
        """Export an FBX file from a Control Rig section.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.
            export_file_path: File system path for the output FBX file.
            ascii: If True, export in ASCII format instead of binary.

        Returns:
            True if the export succeeded.
        """
        _, track = SequencerControlRigTools._find_rig_and_track(sequence, control_rig_asset_path)
        sections = track.get_sections()
        if not sections:
            raise ValueError("No sections found on the Control Rig track.")
        section = sections[0]
        settings = unreal.MovieSceneUserExportFBXControlRigSettings()
        settings.export_file_path = export_file_path
        settings.ascii = ascii
        return unreal.ControlRigSequencerLibrary.export_fbx_from_control_rig_section(
            sequence, section, settings
        )

    @toolset_registry.tool_call
    @staticmethod
    def import_fbx_to_rig(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        import_file_path: str,
        selected_controls: list[str]
    ) -> bool:
        """Import an FBX file onto a Control Rig track.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.
            import_file_path: File system path to the FBX file to import.
            selected_controls: Optional list of control names to import onto.
                If provided, only these controls will be affected.

        Returns:
            True if the import succeeded.
        """
        _, track = SequencerControlRigTools._find_rig_and_track(sequence, control_rig_asset_path)
        sections = track.get_sections()
        section = sections[0] if sections else None
        editor_system = unreal.get_editor_subsystem(unreal.UnrealEditorSubsystem)
        world = editor_system.get_editor_world()
        control_list = selected_controls if selected_controls else []
        settings = unreal.MovieSceneUserImportFBXControlRigSettings()
        if selected_controls:
            settings.import_onto_selected_controls = True
        return unreal.ControlRigSequencerLibrary.import_fbx_to_control_rig_track(
            world, sequence, track, section,
            control_list, settings, import_file_path
        )

    # ========================================================================
    @toolset_registry.tool_call
    @staticmethod
    def find_or_create_track(
        sequence: unreal.LevelSequence,
        binding: unreal.SequencerBindingProxy,
        control_rig_asset_path: str,
        is_layered: bool = False
    ) -> str:
        """Add a Control Rig track to a binding using a Control Rig asset.

        This is the standard way to add a Control Rig to Sequencer.
        Uses ControlRigSequencerLibrary.find_or_create_control_rig_track.

        Args:
            sequence: The LevelSequence.
            binding: The binding to add the CR track to.
            control_rig_asset_path: Path to the CR asset (e.g.
                '/Game/Rigs/CR_Mannequin_Body').
            is_layered: If True, create as a layered Control Rig.

        Returns:
            JSON string with 'track' refPath and 'control_rig' info.
        """

        if not sequence:
            raise ValueError("Sequence is None.")
        rig_asset = unreal.load_asset(control_rig_asset_path)
        if not rig_asset:
            raise ValueError(
                f"Could not load Control Rig asset '{control_rig_asset_path}'."
            )
        rig_class = rig_asset.get_control_rig_class()
        if not rig_class:
            raise ValueError(
                f"Asset '{control_rig_asset_path}' has no Control Rig class."
            )
        editor_system = unreal.get_editor_subsystem(
            unreal.UnrealEditorSubsystem
        )
        world = editor_system.get_editor_world()
        track = unreal.ControlRigSequencerLibrary.find_or_create_control_rig_track(
            world, sequence, rig_class, binding,
            is_layered_control_rig=is_layered
        )
        if not track:
            raise ValueError(
                f"Failed to create Control Rig track for '{control_rig_asset_path}'."
            )
        # The return is a UMovieSceneTrack, get CR info via get_control_rigs
        rigs = unreal.ControlRigSequencerLibrary.get_control_rigs(sequence)
        cr_name = None
        for p in rigs:
            if p.track == track:
                cr_name = str(p.control_rig.get_name())
                break
        return json.dumps({
            "track": str(track.get_path_name()),
            "control_rig": cr_name,
        })

    @toolset_registry.tool_call
    @staticmethod
    def get_control_rigs(
        sequence: unreal.LevelSequence
    ) -> str:
        """Get all Control Rigs currently in the sequence.

        Returns proxy objects with track and rig references.

        Args:
            sequence: The LevelSequence to query.

        Returns:
            JSON string with list of CR info objects containing
            'track', 'control_rig_name', and 'is_layered'.
        """

        if not sequence:
            raise ValueError("Sequence is None.")
        proxies = unreal.ControlRigSequencerLibrary.get_control_rigs(sequence)
        result = []
        for p in proxies:
            result.append({
                "track": str(p.track.get_path_name()),
                "control_rig_name": str(p.control_rig.get_name()),
                "is_layered": unreal.ControlRigSequencerLibrary.is_layered_control_rig(
                    p.control_rig
                ),
            })
        return json.dumps(result)

    @toolset_registry.tool_call
    @staticmethod
    def get_controls_info(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str
    ) -> str:
        """Get all controls on a Control Rig with their names and types.

        Returns a list of controls with name and type so the caller can
        find controls of a specific type (e.g. find a Float control to
        use with set_float).

        Possible types: Bool, Float, Integer, Vector2D, Position,
        Rotator, Scale, Transform, TransformNoScale, EulerTransform.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which Control Rig.

        Returns:
            JSON string with a list of objects, each with 'name' and 'type'.
        """

        if not sequence:
            raise ValueError("Sequence is None.")
        rig = SequencerControlRigTools._find_rig(sequence, control_rig_asset_path)
        hierarchy = rig.get_hierarchy()
        controls = rig.get_sorted_controls()
        result = []
        for ctrl_name in controls:
            name = str(ctrl_name)
            key = unreal.RigElementKey(
                type=unreal.RigElementType.CONTROL, name=name
            )
            elem = hierarchy.find_control(key)
            if elem:
                try:
                    ct = str(elem.settings.control_type)
                    # Extract the enum name from e.g. "<RigControlType.FLOAT: 1>"
                    if '.' in ct and ':' in ct:
                        ct = ct.split('.')[1].split(':')[0]
                except Exception:
                    ct = "Unknown"
                result.append({"name": name, "type": ct})
        return json.dumps(result)

    @toolset_registry.tool_call
    @staticmethod
    def set_transform(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        control_name: str,
        frame: int,
        location_x: float = 0.0, location_y: float = 0.0, location_z: float = 0.0,
        rotation_pitch: float = 0.0, rotation_yaw: float = 0.0, rotation_roll: float = 0.0,
        set_key: bool = True
    ) -> bool:
        """Set a transform value on a Control Rig control and optionally key it.

        Uses ControlRigSequencerLibrary.set_local_control_rig_transform.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which CR (used to find the rig).
            control_name: The control name (e.g. 'body_ctrl').
            frame: The frame number.
            location_x: X location.
            location_y: Y location.
            location_z: Z location.
            rotation_pitch: Pitch rotation in degrees.
            rotation_yaw: Yaw rotation in degrees.
            rotation_roll: Roll rotation in degrees.
            set_key: If True, set a keyframe at this frame.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        rig = SequencerControlRigTools._find_rig(sequence, control_rig_asset_path)
        frame_num = unreal.FrameNumber(value=frame)
        ctrl_type = SequencerControlRigTools._get_control_type(rig, control_name)
        if ctrl_type == unreal.RigControlType.EULER_TRANSFORM:
            euler = unreal.EulerTransform()
            euler.location = unreal.Vector(location_x, location_y, location_z)
            euler.rotation = unreal.Rotator(
                pitch=rotation_pitch, yaw=rotation_yaw, roll=rotation_roll
            )
            euler.scale = unreal.Vector(1.0, 1.0, 1.0)
            unreal.ControlRigSequencerLibrary.set_local_control_rig_euler_transform(
                sequence, rig, control_name, frame_num, euler,
                set_key=set_key
            )
        else:
            transform = unreal.Transform(
                location=[location_x, location_y, location_z],
                rotation=[rotation_pitch, rotation_yaw, rotation_roll],
                scale=[1.0, 1.0, 1.0]
            )
            unreal.ControlRigSequencerLibrary.set_local_control_rig_transform(
                sequence, rig, control_name, frame_num, transform,
                set_key=set_key
            )
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_transform(
        sequence: unreal.LevelSequence,
        control_rig_asset_path: str,
        control_name: str,
        frame: int
    ) -> str:
        """Get the transform value of a Control Rig control at a frame.

        Automatically detects whether the control is a Transform or
        EulerTransform type and uses the appropriate API.

        Args:
            sequence: The LevelSequence.
            control_rig_asset_path: Path to identify which CR.
            control_name: The control name (e.g. 'body_ctrl').
            frame: The frame number.

        Returns:
            JSON string with 'location' and 'rotation' dicts.
        """

        if not sequence:
            raise ValueError("Sequence is None.")
        rig = SequencerControlRigTools._find_rig(sequence, control_rig_asset_path)
        frame_num = unreal.FrameNumber(value=frame)
        ctrl_type = SequencerControlRigTools._get_control_type(rig, control_name)
        if ctrl_type == unreal.RigControlType.EULER_TRANSFORM:
            t = unreal.ControlRigSequencerLibrary.get_local_control_rig_euler_transform(
                sequence, rig, control_name, frame_num
            )
            return json.dumps({
                "location": {"x": t.location.x, "y": t.location.y, "z": t.location.z},
                "rotation": {"pitch": t.rotation.pitch, "yaw": t.rotation.yaw, "roll": t.rotation.roll},
            })
        else:
            t = unreal.ControlRigSequencerLibrary.get_local_control_rig_transform(
                sequence, rig, control_name, frame_num
            )
            return json.dumps({
                "location": {"x": t.translation.x, "y": t.translation.y, "z": t.translation.z},
                "rotation": {"pitch": t.rotation.rotator().pitch, "yaw": t.rotation.rotator().yaw, "roll": t.rotation.rotator().roll},
            })

    # -- Animation Mode settings --

    @staticmethod
    def _get_animation_mode_settings():
        """Internal: load ControlRigEditModeSettings CDO."""
        settings_class = unreal.load_class(
            None, '/Script/ControlRigEditor.ControlRigEditModeSettings'
        )
        if settings_class is None:
            raise ValueError(
                "Could not load ControlRigEditModeSettings. ControlRigEditor "
                "module may not be available."
            )
        return unreal.get_default_object(settings_class)

    @staticmethod
    def _get_transform_gizmo_settings():
        """Internal: load UTransformGizmoEditorSettings CDO.

        The CR-specific GizmoScale UPROPERTY on UControlRigEditModeSettings
        was removed in UE 5.8 ('the ControlRigEditMode-specific gizmo scale
        feature has been removed'). The editor-wide gizmo size now lives in
        UTransformGizmoEditorSettings::TransformGizmoSize.
        """
        settings_class = unreal.load_class(
            None,
            '/Script/EditorInteractiveToolsFramework.TransformGizmoEditorSettings'
        )
        if settings_class is None:
            raise ValueError(
                "Could not load TransformGizmoEditorSettings. "
                "EditorInteractiveToolsFramework module may not be available."
            )
        return unreal.get_default_object(settings_class)

    @toolset_registry.tool_call
    @staticmethod
    def get_anim_mode_gizmo_scale() -> float:
        """Get the editor's transform gizmo size.

        Reads UTransformGizmoEditorSettings::TransformGizmoSize. The CR-specific
        gizmo scale was removed in UE 5.8 in favor of this editor-wide setting,
        so this affects every transform gizmo (level, sequencer, CR, etc.).

        Returns:
            The transform gizmo size offset. Default 0.0; range -10..150.
        """
        settings = SequencerControlRigTools._get_transform_gizmo_settings()
        return float(settings.get_editor_property('TransformGizmoSize'))

    @toolset_registry.tool_call
    @staticmethod
    def set_anim_mode_gizmo_scale(scale: float) -> bool:
        """Set the editor's transform gizmo size.

        Writes UTransformGizmoEditorSettings::TransformGizmoSize. The CR-specific
        gizmo scale was removed in UE 5.8 in favor of this editor-wide setting.

        Args:
            scale: Gizmo size offset, clamped to [-10.0, 150.0]. 0.0 is default.

        Returns:
            True on success.
        """
        settings = SequencerControlRigTools._get_transform_gizmo_settings()
        settings.set_editor_property('TransformGizmoSize', float(scale))
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_anim_mode_hierarchy() -> bool:
        """Get whether the Animation Mode draws hierarchy lines/dots.

        Returns:
            True if hierarchy display is on.
        """
        settings = SequencerControlRigTools._get_animation_mode_settings()
        return bool(settings.get_editor_property('bDisplayHierarchy'))

    @toolset_registry.tool_call
    @staticmethod
    def set_anim_mode_hierarchy(enabled: bool) -> bool:
        """Toggle the Animation Mode hierarchy lines/dots display.

        Args:
            enabled: True to show, False to hide.

        Returns:
            True on success.
        """
        settings = SequencerControlRigTools._get_animation_mode_settings()
        settings.set_editor_property('bDisplayHierarchy', bool(enabled))
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_anim_mode_nulls() -> bool:
        """Get whether the Animation Mode draws nulls.

        Returns:
            True if null display is on.
        """
        settings = SequencerControlRigTools._get_animation_mode_settings()
        return bool(settings.get_editor_property('bDisplayNulls'))

    @toolset_registry.tool_call
    @staticmethod
    def set_anim_mode_nulls(enabled: bool) -> bool:
        """Toggle the Animation Mode nulls display.

        Args:
            enabled: True to show, False to hide.

        Returns:
            True on success.
        """
        settings = SequencerControlRigTools._get_animation_mode_settings()
        settings.set_editor_property('bDisplayNulls', bool(enabled))
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_anim_mode_hide_manips() -> bool:
        """Get whether Animation Mode hides all manipulators.

        Returns:
            True if manipulators are hidden.
        """
        settings = SequencerControlRigTools._get_animation_mode_settings()
        return bool(settings.get_editor_property('bHideControlShapes'))

    @toolset_registry.tool_call
    @staticmethod
    def set_anim_mode_hide_manips(hide: bool) -> bool:
        """Toggle whether Animation Mode hides all manipulators.

        Args:
            hide: True to hide all controls and gizmos.

        Returns:
            True on success.
        """
        settings = SequencerControlRigTools._get_animation_mode_settings()
        settings.set_editor_property('bHideControlShapes', bool(hide))
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_anim_mode_only_rig_sel() -> bool:
        """Get whether Animation Mode restricts viewport selection to rig controls.

        Returns:
            True if only rig controls are selectable.
        """
        settings = SequencerControlRigTools._get_animation_mode_settings()
        return bool(settings.get_editor_property('bOnlySelectRigControls'))

    @toolset_registry.tool_call
    @staticmethod
    def set_anim_mode_only_rig_sel(only_rig: bool) -> bool:
        """Toggle Animation Mode restricting viewport selection to rig controls.

        Args:
            only_rig: True to only allow selecting rig controls in viewport.

        Returns:
            True on success.
        """
        settings = SequencerControlRigTools._get_animation_mode_settings()
        settings.set_editor_property('bOnlySelectRigControls', bool(only_rig))
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_anim_mode_local_spaces() -> bool:
        """Get whether multi-select transforms act in each control's own space.

        Returns:
            True if each selected control transforms in its own local space.
        """
        settings = SequencerControlRigTools._get_animation_mode_settings()
        return bool(settings.get_editor_property('bLocalTransformsInEachLocalSpace'))

    @toolset_registry.tool_call
    @staticmethod
    def set_anim_mode_local_spaces(enabled: bool) -> bool:
        """Toggle multi-select transforms acting in each control's own space.

        When True, transforming multiple selected controls respects each
        control's own local space. When False, all use a shared reference.

        Args:
            enabled: True to enable per-control local space.

        Returns:
            True on success.
        """
        settings = SequencerControlRigTools._get_animation_mode_settings()
        settings.set_editor_property(
            'bLocalTransformsInEachLocalSpace', bool(enabled)
        )
        return True

    # ========================================================================
