# Copyright Epic Games, Inc. All Rights Reserved.

import unreal

import toolset_registry


@unreal.uclass()
class SequencerConditionTools(unreal.ToolsetDefinition):
    """Tools for managing runtime conditions on Sequencer tracks, sections, and
    track rows. Use when setting up dynamic conditions that control whether
    tracks or sections evaluate at runtime based on platform, gameplay state,
    or custom logic. Supports MovieScenePlatformCondition,
    MovieSceneDirectorBlueprintCondition, and MovieSceneGroupCondition types."""

    @toolset_registry.tool_call
    @staticmethod
    def get_section_condition(section: unreal.MovieSceneSection) -> str:
        """Get the condition on a section.

        Returns the class path of the condition, or an empty string if
        no condition is set.

        Args:
            section: The section to query.

        Returns:
            Class path of the condition, or empty string.
        """
        condition = section.get_section_condition()
        if condition is None:
            return ""
        return condition.get_class().get_path_name()

    @toolset_registry.tool_call
    @staticmethod
    def set_section_condition(
        section: unreal.MovieSceneSection,
        condition_class: str,
    ) -> bool:
        """Set a condition on a section.

        Common condition classes:
        - /Script/MovieSceneTracks.MovieScenePlatformCondition
        - /Script/MovieSceneTracks.MovieSceneDirectorBlueprintCondition
        - /Script/MovieScene.MovieSceneGroupCondition

        Args:
            section: The section to modify.
            condition_class: Full class path of the condition type.
        """
        cls = unreal.load_class(None, condition_class)
        if not cls:
            raise ValueError(f"Could not load condition class '{condition_class}'.")
        section.set_section_condition(cls)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def clear_section_condition(section: unreal.MovieSceneSection) -> bool:
        """Remove the condition from a section.

        Args:
            section: The section to clear the condition from.
        """
        section.clear_section_condition()
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_track_condition(track: unreal.MovieSceneTrack) -> str:
        """Get the track-level condition.

        Args:
            track: The track to query.

        Returns:
            Class path of the condition, or empty string.
        """
        condition = track.get_track_condition()
        if condition is None:
            return ""
        return condition.get_class().get_path_name()

    @toolset_registry.tool_call
    @staticmethod
    def set_track_condition(
        track: unreal.MovieSceneTrack,
        condition_class: str,
    ) -> bool:
        """Set a condition on a track.

        Args:
            track: The track to modify.
            condition_class: Full class path of the condition type.
        """
        cls = unreal.load_class(None, condition_class)
        if not cls:
            raise ValueError(f"Could not load condition class '{condition_class}'.")
        track.set_track_condition(cls)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def clear_track_condition(track: unreal.MovieSceneTrack) -> bool:
        """Remove the condition from a track.

        Args:
            track: The track to clear the condition from.
        """
        track.clear_track_condition()
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_track_row_condition(track: unreal.MovieSceneTrack, row_index: int) -> str:
        """Get the condition on a specific track row.

        Args:
            track: The track to query.
            row_index: The row index (0-based).

        Returns:
            Class path of the condition, or empty string.
        """
        # Track row metadata is not exposed to Python properties.
        # Uses the C++ extension MovieSceneConditionExtensions.
        condition = track.get_track_row_condition(row_index)
        if condition is None:
            return ""
        return condition.get_class().get_path_name()

    @toolset_registry.tool_call
    @staticmethod
    def set_track_row_condition(
        track: unreal.MovieSceneTrack,
        row_index: int,
        condition_class: str,
    ) -> bool:
        """Set a condition on a specific track row.

        Args:
            track: The track to modify.
            row_index: The row index (0-based).
            condition_class: Full class path of the condition type.
        """
        cls = unreal.load_class(None, condition_class)
        if not cls:
            raise ValueError(f"Could not load condition class '{condition_class}'.")
        track.set_track_row_condition(row_index, cls)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def clear_track_row_condition(track: unreal.MovieSceneTrack, row_index: int) -> bool:
        """Remove the condition from a specific track row.

        Args:
            track: The track to modify.
            row_index: The row index (0-based).
        """
        track.clear_track_row_condition(row_index)
        return True

    # ========================================================================
