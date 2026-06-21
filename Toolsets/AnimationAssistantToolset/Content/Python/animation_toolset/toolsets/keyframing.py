# Copyright Epic Games, Inc. All Rights Reserved.

import json

import unreal

import toolset_registry


def _json_safe_value(value):
    """Return value if it serializes natively via json.dumps, else str(value).

    Channel get_value() returns native Python types for the common channel
    kinds (float, bool, int, str) which JSON can handle directly. Exotic
    types (unreal structs, enums, etc.) fall back to repr-via-str so the
    payload stays serializable.
    """
    try:
        json.dumps(value)
        return value
    except (TypeError, ValueError):
        return str(value)


@unreal.uclass()
class SequencerKeyframingTools(unreal.ToolsetDefinition):
    """Tools for keyframing and animating properties on the Sequencer
    timeline. Use when adding, querying, or removing keyframes on channels,
    setting default values, evaluating channels at specific times, working
    with the Curve Editor, or managing channel selection. Covers float, bool,
    integer, and string key types with configurable interpolation."""


    # Internal helper to look up a channel by name on a section.
    # Not a tool call - used by the tools below.
    @staticmethod
    def _find_channel(section, channel_name):
        for ch in section.get_all_channels():
            if ch.channel_name == channel_name:
                return ch
        raise ValueError(
            f"Channel '{channel_name}' not found on section."
        )

    @toolset_registry.tool_call
    @staticmethod
    def get_channel_names(
        section: unreal.MovieSceneSection
    ) -> list[str]:
        """Get the names of all channels on a section.

        For example, a 3D Transform section has channels named
        'Location.X', 'Location.Y', 'Location.Z', 'Rotation.X', etc.

        Args:
            section: The section to query.

        Returns:
            List of channel name strings.
        """
        if not section:
            raise ValueError("Section is None.")
        return [ch.channel_name for ch in section.get_all_channels()]

    @toolset_registry.tool_call
    @staticmethod
    def add_key_float(
        section: unreal.MovieSceneSection,
        channel_name: str,
        frame: int,
        value: float,
        interpolation: str = "",
    ) -> bool:
        """Add a float key to a channel on a section.

        Args:
            section: The section containing the channel.
            channel_name: Name of the channel (e.g. 'Location.X').
            frame: The frame number for the key.
            value: The float value.
            interpolation: Key interpolation mode as a string:
                "cubic", "linear", "constant", "break", or "" for default (smart auto).

        Returns:
            True when the key was added successfully.
        """
        if not section:
            raise ValueError("Section is None.")
        channel = SequencerKeyframingTools._find_channel(section, channel_name)
        time = unreal.FrameNumber(value=int(frame))
        interp_map = {
            "auto": unreal.MovieSceneKeyInterpolation.AUTO,
            "user": unreal.MovieSceneKeyInterpolation.USER,
            "linear": unreal.MovieSceneKeyInterpolation.LINEAR,
            "constant": unreal.MovieSceneKeyInterpolation.CONSTANT,
            "break": unreal.MovieSceneKeyInterpolation.BREAK,
            "cubic": unreal.MovieSceneKeyInterpolation.AUTO,  # legacy alias
        }
        interp = interp_map.get(interpolation.lower(), unreal.MovieSceneKeyInterpolation.SMART_AUTO) if interpolation else unreal.MovieSceneKeyInterpolation.SMART_AUTO
        channel.add_key(time=time, new_value=float(value), interpolation=interp)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def add_key_bool(
        section: unreal.MovieSceneSection,
        channel_name: str,
        frame: int,
        value: bool
    ) -> bool:
        """Add a bool key to a channel on a section.

        Args:
            section: The section containing the channel.
            channel_name: Name of the channel.
            frame: The frame number for the key.
            value: The bool value.

        Returns:
            True when the key was added successfully.
        """
        if not section:
            raise ValueError("Section is None.")
        channel = SequencerKeyframingTools._find_channel(section, channel_name)
        time = unreal.FrameNumber(value=int(frame))
        channel.add_key(time=time, new_value=bool(value))
        return True

    @toolset_registry.tool_call
    @staticmethod
    def add_key_integer(
        section: unreal.MovieSceneSection,
        channel_name: str,
        frame: int,
        value: int
    ) -> bool:
        """Add an integer key to a channel on a section.

        Args:
            section: The section containing the channel.
            channel_name: Name of the channel.
            frame: The frame number for the key.
            value: The integer value.

        Returns:
            True when the key was added successfully.
        """
        if not section:
            raise ValueError("Section is None.")
        channel = SequencerKeyframingTools._find_channel(section, channel_name)
        time = unreal.FrameNumber(value=int(frame))
        channel.add_key(time=time, new_value=int(value))
        return True

    @toolset_registry.tool_call
    @staticmethod
    def add_key_string(
        section: unreal.MovieSceneSection,
        channel_name: str,
        frame: int,
        value: str
    ) -> bool:
        """Add a string key to a channel on a section.

        Args:
            section: The section containing the channel.
            channel_name: Name of the channel.
            frame: The frame number for the key.
            value: The string value.

        Returns:
            True when the key was added successfully.
        """
        if not section:
            raise ValueError("Section is None.")
        channel = SequencerKeyframingTools._find_channel(section, channel_name)
        time = unreal.FrameNumber(value=int(frame))
        channel.add_key(time=time, new_value=str(value))
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_keys(
        section: unreal.MovieSceneSection,
        channel_name: str
    ) -> str:
        """Get all keys on a channel, returned as a JSON array.

        Each key entry includes its frame number and value.

        Args:
            section: The section containing the channel.
            channel_name: Name of the channel.

        Returns:
            JSON string with a list of key objects, each with 'frame'
            and 'value' fields. For numeric channels the value is a
            native JSON number; for exotic channel types that don't
            round-trip through JSON natively, the value is stringified.
        """

        if not section:
            raise ValueError("Section is None.")
        channel = SequencerKeyframingTools._find_channel(section, channel_name)
        keys = list(channel.get_keys())
        result = [
            {
                "frame": key.get_time(
                    time_unit=unreal.MovieSceneTimeUnit.DISPLAY_RATE
                ).frame_number.value,
                "value": _json_safe_value(key.get_value()),
            }
            for key in keys
        ]
        return json.dumps(result)

    @toolset_registry.tool_call
    @staticmethod
    def remove_key_at_frame(
        section: unreal.MovieSceneSection,
        channel_name: str,
        frame: int
    ) -> bool:
        """Remove a key at a specific frame from a channel.

        Args:
            section: The section containing the channel.
            channel_name: Name of the channel.
            frame: The frame number of the key to remove.

        Returns:
            True if a key was found and removed, False if no key at that frame.
        """
        if not section:
            raise ValueError("Section is None.")
        channel = SequencerKeyframingTools._find_channel(section, channel_name)
        for key in channel.get_keys():
            time = key.get_time(time_unit=unreal.MovieSceneTimeUnit.DISPLAY_RATE)
            if time.frame_number.value == frame:
                channel.remove_key(key)
                return True
        return False

    @toolset_registry.tool_call
    @staticmethod
    def set_default_value(
        section: unreal.MovieSceneSection,
        channel_name: str,
        value: float
    ) -> bool:
        """Set the default value of a channel.

        Args:
            section: The section containing the channel.
            channel_name: Name of the channel.
            value: The default value.
        """
        if not section:
            raise ValueError("Section is None.")
        channel = SequencerKeyframingTools._find_channel(section, channel_name)
        channel.set_default(value)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_default_value(
        section: unreal.MovieSceneSection,
        channel_name: str
    ) -> float:
        """Get the default value of a float channel.

        Args:
            section: The section containing the channel.
            channel_name: Name of the channel.

        Returns:
            The default value of the channel.
        """
        if not section:
            raise ValueError("Section is None.")
        channel = SequencerKeyframingTools._find_channel(section, channel_name)
        return channel.get_default()

    # ========================================================================

    @toolset_registry.tool_call
    @staticmethod
    def get_selected_channels() -> list[unreal.SequencerChannelProxy]:
        """Get the currently selected channels in the Sequencer editor.

        Returns:
            List of selected SequencerChannelProxy objects.
        """
        return list(
            unreal.LevelSequenceEditorBlueprintLibrary.get_selected_channels()
        )

    @toolset_registry.tool_call
    @staticmethod
    def select_channels(channels: list[unreal.SequencerChannelProxy]) -> bool:
        """Set the channel selection in the Sequencer editor.

        Args:
            channels: List of SequencerChannelProxy objects to select.
        """
        unreal.LevelSequenceEditorBlueprintLibrary.select_channels(channels)
        return True

    # ========================================================================

    @toolset_registry.tool_call
    @staticmethod
    def open_curve_editor() -> bool:
        """Open the Sequencer Curve Editor panel."""
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        subsystem.get_curve_editor().open_curve_editor()
        return True

    @toolset_registry.tool_call
    @staticmethod
    def close_curve_editor() -> bool:
        """Close the Sequencer Curve Editor panel."""
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        subsystem.get_curve_editor().close_curve_editor()
        return True

    @toolset_registry.tool_call
    @staticmethod
    def is_curve_editor_open() -> bool:
        """Check whether the Curve Editor panel is currently open.

        Returns:
            True if the Curve Editor is open.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        return subsystem.get_curve_editor().is_curve_editor_open()

    @toolset_registry.tool_call
    @staticmethod
    def get_selected_key_channels() -> list[unreal.SequencerChannelProxy]:
        """Get channels that have selected keys in the Curve Editor.

        Returns:
            List of SequencerChannelProxy objects with selected keys.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        return list(subsystem.get_curve_editor().get_channels_with_selected_keys())

    @toolset_registry.tool_call
    @staticmethod
    def get_curve_editor_selected_keys(channel: unreal.SequencerChannelProxy) -> list[int]:
        """Get selected key indices for a channel in the Curve Editor.

        Args:
            channel: The channel proxy to query.

        Returns:
            List of integer key indices that are selected.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        return list(subsystem.get_curve_editor().get_selected_keys(channel))

    @toolset_registry.tool_call
    @staticmethod
    def curve_editor_select_keys(channel: unreal.SequencerChannelProxy, indices: list[int]) -> bool:
        """Select keys by index in the Curve Editor.

        Args:
            channel: The channel proxy containing the keys.
            indices: List of integer key indices to select.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        subsystem.get_curve_editor().select_keys(channel, indices)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def curve_editor_empty_selection() -> bool:
        """Clear all key selection in the Curve Editor."""
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        subsystem.get_curve_editor().empty_selection()
        return True

    @toolset_registry.tool_call
    @staticmethod
    def show_curve(channel: unreal.SequencerChannelProxy, show: bool) -> bool:
        """Show or hide a curve in the Curve Editor.

        Args:
            channel: The channel proxy for the curve.
            show: True to show, False to hide.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        subsystem.get_curve_editor().show_curve(channel, show)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def is_curve_shown(channel: unreal.SequencerChannelProxy) -> bool:
        """Check if a curve is visible in the Curve Editor.

        Args:
            channel: The channel proxy to check.

        Returns:
            True if the curve is displayed.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        return subsystem.get_curve_editor().is_curve_shown(channel)

    @toolset_registry.tool_call
    @staticmethod
    def bake_channel_keys(
        section: unreal.MovieSceneSection,
        channel_name: str,
        start_frame: int,
        end_frame: int,
    ) -> list[float]:
        """Bake a channel's values over a frame range.

        Evaluates the channel curve at every frame in the range and
        returns the computed values. Useful for extracting animation
        data or verifying interpolation results.

        Args:
            section: The section containing the channel.
            channel_name: Name of the channel (e.g. 'Location.X').
            start_frame: Start of the evaluation range.
            end_frame: End of the evaluation range.

        Returns:
            List of float values, one per frame in the range.
        """
        if not section:
            raise ValueError("Section is None.")
        channel = SequencerKeyframingTools._find_channel(section, channel_name)
        sequence = unreal.LevelSequenceEditorBlueprintLibrary.get_current_level_sequence()
        frame_rate = sequence.get_display_rate()
        script_range = unreal.SequencerScriptingRange()
        script_range.set_start_frame(start_frame)
        script_range.set_end_frame(end_frame)
        return list(channel.evaluate_keys(script_range, frame_rate))

    @toolset_registry.tool_call
    @staticmethod
    def get_keys_by_index(
        section: unreal.MovieSceneSection,
        channel_name: str,
        indices: list[int],
    ) -> str:
        """Get specific keys on a channel by their indices, returned as JSON.

        Useful for resolving the keys behind a Curve Editor selection,
        which provides indices rather than key objects.

        Args:
            section: The section containing the channel.
            channel_name: Name of the channel.
            indices: Key indices to look up (0-based).

        Returns:
            JSON string with a list of key objects, each with 'frame',
            'value', and 'index' fields. An entry is emitted for EVERY
            requested index in the input order; out-of-range indices are
            reported with 'frame': None and 'value': None so callers can
            correlate results with the request. Value uses a native JSON
            number for numeric channels and a string for exotic types.
        """
        if not section:
            raise ValueError("Section is None.")
        channel = SequencerKeyframingTools._find_channel(section, channel_name)
        request_indices = [int(i) for i in indices]
        keys = list(channel.get_keys_by_index(request_indices))
        result = []
        for i, key in zip(request_indices, keys):
            if key is None:
                result.append({"index": i, "frame": None, "value": None})
                continue
            time = key.get_time(time_unit=unreal.MovieSceneTimeUnit.DISPLAY_RATE)
            result.append({
                "index": i,
                "frame": time.frame_number.value,
                "value": _json_safe_value(key.get_value()),
            })
        return json.dumps(result)
