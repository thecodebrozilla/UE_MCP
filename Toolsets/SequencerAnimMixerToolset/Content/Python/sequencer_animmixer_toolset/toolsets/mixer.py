# Copyright Epic Games, Inc. All Rights Reserved.

"""Sequencer Animation Mixer toolset for the EDA ToolsetRegistry.

Provides tools for working with the Animation Mixer track in Sequencer,
including layer management, transitions, and decorations.

This is a separate plugin from AnimationAssistantToolset because the
MovieSceneAnimMixer plugin is not enabled by default in all targets.
"""

import json

import unreal
import toolset_registry


@unreal.uclass()
class SequencerAnimMixerTools(unreal.ToolsetDefinition):
    """Tools for working with the Animation Mixer in Sequencer."""

    # ========================================================================
    # Layers & Content
    # ========================================================================

    @toolset_registry.tool_call
    @staticmethod
    def get_mixer_layers(
        track: unreal.MovieSceneAnimationMixerTrack
    ) -> list[unreal.MovieSceneAnimationMixerLayer]:
        """Get all layers in an Anim Mixer track.

        Args:
            track: The Anim Mixer track to query.

        Returns:
            List of MovieSceneAnimationMixerLayer objects.
        """
        if not track:
            raise ValueError("Track is None.")
        return list(track.get_layers())

    @toolset_registry.tool_call
    @staticmethod
    def get_mixer_layer_count(
        track: unreal.MovieSceneAnimationMixerTrack
    ) -> int:
        """Get the number of layers in an Anim Mixer track.

        Args:
            track: The Anim Mixer track to query.

        Returns:
            The layer count.
        """
        if not track:
            raise ValueError("Track is None.")
        return track.get_layer_count()

    @toolset_registry.tool_call
    @staticmethod
    def add_mixer_layer(
        track: unreal.MovieSceneAnimationMixerTrack
    ) -> unreal.MovieSceneAnimationMixerLayer:
        """Add a new empty layer at the end of the Anim Mixer track.

        Args:
            track: The Anim Mixer track to add a layer to.

        Returns:
            The newly created MovieSceneAnimationMixerLayer.
        """
        if not track:
            raise ValueError("Track is None.")
        layer = track.add_layer()
        if not layer:
            raise ValueError("Failed to add layer to Anim Mixer track.")
        return layer

    @toolset_registry.tool_call
    @staticmethod
    def insert_mixer_layer(
        track: unreal.MovieSceneAnimationMixerTrack,
        index: int
    ) -> unreal.MovieSceneAnimationMixerLayer:
        """Insert a new layer at a specific index in the Anim Mixer track.

        Args:
            track: The Anim Mixer track to insert a layer into.
            index: The zero-based index at which to insert the layer.

        Returns:
            The newly created MovieSceneAnimationMixerLayer.
        """
        if not track:
            raise ValueError("Track is None.")
        if index < 0:
            raise ValueError(f"Layer index must be non-negative, got {index}.")
        layer = track.insert_layer(index)
        if not layer:
            raise ValueError(
                f"Failed to insert layer at index {index} in Anim Mixer track."
            )
        return layer

    @toolset_registry.tool_call
    @staticmethod
    def add_animation_to_mixer(
        track: unreal.MovieSceneAnimationMixerTrack,
        layer_index: int,
        start_frame: int,
        anim_sequence: unreal.AnimSequenceBase
    ) -> unreal.MovieSceneSection:
        """Add a skeletal animation to a specific layer in the Anim Mixer.

        Args:
            track: The Anim Mixer track.
            layer_index: The zero-based index of the target layer.
            start_frame: The frame at which the animation starts.
            anim_sequence: The AnimSequence asset to add.

        Returns:
            The newly created MovieSceneSection for the animation.
        """
        if not track:
            raise ValueError("Track is None.")
        if not anim_sequence:
            raise ValueError("Anim sequence is None.")
        if layer_index < 0:
            raise ValueError(
                f"Layer index must be non-negative, got {layer_index}."
            )
        frame = unreal.FrameNumber(value=start_frame)
        section = track.add_animation(layer_index, frame, anim_sequence)
        if not section:
            raise ValueError(
                f"Failed to add animation to layer {layer_index}."
            )
        return section

    @toolset_registry.tool_call
    @staticmethod
    def add_child_track_to_layer(
        track: unreal.MovieSceneAnimationMixerTrack,
        binding: unreal.SequencerBindingProxy,
        track_class: unreal.Class,
        layer_index: int
    ) -> unreal.MovieSceneTrack:
        """Add a child track (e.g. Control Rig) to a mixer layer.

        The child track occupies the entire layer. Layers support either
        animation sections or a single child track, not both. This is the
        UI operation of adding a track type to an empty mixer layer.

        Args:
            track: The Anim Mixer track.
            binding: The binding that owns this mixer track.
            track_class: The track class to add (e.g. MovieSceneControlRigParameterTrack).
            layer_index: The zero-based layer index to add the track to.

        Returns:
            The newly created child track.
        """
        if not track:
            raise ValueError("Track is None.")
        if not binding:
            raise ValueError("Binding is None.")
        child = track.add_child_track_to_layer(
            binding.get_id(), track_class, layer_index
        )
        if not child:
            raise ValueError(
                f"Failed to add child track to layer {layer_index}."
            )
        return child

    @toolset_registry.tool_call
    @staticmethod
    def get_layer_name(
        layer: unreal.MovieSceneAnimationMixerLayer
    ) -> str:
        """Get the display name of an Anim Mixer layer.

        Args:
            layer: The layer to query.

        Returns:
            The layer's display name.
        """
        if not layer:
            raise ValueError("Layer is None.")
        return str(layer.get_display_name())

    @toolset_registry.tool_call
    @staticmethod
    def set_layer_name(
        layer: unreal.MovieSceneAnimationMixerLayer,
        name: str
    ) -> bool:
        """Set the display name of an Anim Mixer layer.

        Args:
            layer: The layer to rename.
            name: The new display name.
        """
        if not layer:
            raise ValueError("Layer is None.")
        if not name:
            raise ValueError("Name is empty.")
        layer.set_display_name(unreal.Text(name))
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_layer_sections(
        layer: unreal.MovieSceneAnimationMixerLayer
    ) -> list[unreal.MovieSceneSection]:
        """Get all animation sections on an Anim Mixer layer.

        Args:
            layer: The layer to query.

        Returns:
            List of MovieSceneSection objects on the layer.
        """
        if not layer:
            raise ValueError("Layer is None.")
        return list(layer.get_sections())

    @toolset_registry.tool_call
    @staticmethod
    def get_layer_index(layer: unreal.MovieSceneAnimationMixerLayer) -> int:
        """Get the index of a mixer layer within its parent track.

        Args:
            layer: The mixer layer to query.

        Returns:
            The layer index.
        """
        if not layer:
            raise ValueError("Layer is None.")
        return layer.get_layer_index()

    @toolset_registry.tool_call
    @staticmethod
    def is_layer_empty(
        layer: unreal.MovieSceneAnimationMixerLayer
    ) -> bool:
        """Check whether an Anim Mixer layer has any content.

        Args:
            layer: The layer to check.

        Returns:
            True if the layer is empty, False if it has sections.
        """
        if not layer:
            raise ValueError("Layer is None.")
        return layer.is_empty()

    # ========================================================================
    # Transitions
    # ========================================================================

    @toolset_registry.tool_call
    @staticmethod
    def get_transitions_for_section(
        track: unreal.MovieSceneAnimationMixerTrack,
        section: unreal.MovieSceneSection
    ) -> list[unreal.MovieSceneAnimTransitionSectionBase]:
        """Get all transitions associated with a section.

        Transitions are created automatically when sections overlap.

        Args:
            track: The Anim Mixer track containing the section.
            section: The section to query transitions for.

        Returns:
            List of transition objects touching this section.
        """
        if not track:
            raise ValueError("Track is None.")
        if not section:
            raise ValueError("Section is None.")
        return list(track.get_transitions_for_section(section))

    @toolset_registry.tool_call
    @staticmethod
    def get_transition_between(
        track: unreal.MovieSceneAnimationMixerTrack,
        from_section: unreal.MovieSceneSection,
        to_section: unreal.MovieSceneSection
    ) -> unreal.MovieSceneAnimTransitionSectionBase:
        """Get the transition between two specific sections.

        Args:
            track: The Anim Mixer track.
            from_section: The earlier section.
            to_section: The later section.

        Returns:
            The transition object, or None if no transition exists.
        """
        if not track:
            raise ValueError("Track is None.")
        if not from_section:
            raise ValueError("From section is None.")
        if not to_section:
            raise ValueError("To section is None.")
        return track.get_transition_between(from_section, to_section)

    @toolset_registry.tool_call
    @staticmethod
    def get_transition_info(
        transition: unreal.MovieSceneAnimTransitionSectionBase
    ) -> str:
        """Get detailed information about a transition.

        Args:
            transition: The transition to inspect.

        Returns:
            JSON string with 'name', 'is_valid', 'from_section_name',
            and 'to_section_name'.
        """
        if not transition:
            raise ValueError("Transition is None.")
        from_sec = transition.get_from_section()
        to_sec = transition.get_to_section()
        return json.dumps({
            "name": str(transition.get_transition_display_name()),
            "is_valid": transition.is_transition_valid(),
            "from_section": str(from_sec.get_name()) if from_sec else None,
            "to_section": str(to_sec.get_name()) if to_sec else None,
        })

    @toolset_registry.tool_call
    @staticmethod
    def change_transition_type(
        transition: unreal.MovieSceneAnimTransitionSectionBase,
        new_transition_class: unreal.Class
    ) -> unreal.MovieSceneAnimTransitionSectionBase:
        """Change the type of a transition, preserving blend data where possible.

        Args:
            transition: The transition to change.
            new_transition_class: The new transition class to switch to.

        Returns:
            The new transition object (the old one becomes invalid).
        """
        if not transition:
            raise ValueError("Transition is None.")
        if not new_transition_class:
            raise ValueError("New transition class is None.")
        new_transition = transition.change_transition_type(new_transition_class)
        if not new_transition:
            raise ValueError(
                f"Failed to change transition to type '{new_transition_class}'."
            )
        return new_transition

    @toolset_registry.tool_call
    @staticmethod
    def get_transition_name(
        transition: unreal.MovieSceneAnimTransitionSectionBase
    ) -> str:
        """Get the display name of a transition.

        Args:
            transition: The transition to query.

        Returns:
            The transition's display name.
        """
        if not transition:
            raise ValueError("Transition is None.")
        return str(transition.get_transition_display_name())

    # ========================================================================
    # Decorations
    # ========================================================================

    @toolset_registry.tool_call
    @staticmethod
    def get_compatible_decorations(
        container: unreal.MovieSceneDecorationContainerObject
    ) -> list[unreal.Class]:
        """Get all decoration classes that can be added to a container.

        Works on any decoration container, including Anim Mixer layers.

        Args:
            container: The decoration container to query.

        Returns:
            List of UClass objects representing compatible decoration types.
        """
        if not container:
            raise ValueError("Container is None.")
        return list(container.get_compatible_decorations())

    @toolset_registry.tool_call
    @staticmethod
    def get_decorations(
        container: unreal.MovieSceneDecorationContainerObject
    ) -> list[unreal.Object]:
        """Get all decorations currently on a container.

        Args:
            container: The decoration container to query.

        Returns:
            List of decoration objects.
        """
        if not container:
            raise ValueError("Container is None.")
        return list(container.get_decorations())

    @toolset_registry.tool_call
    @staticmethod
    def find_decoration(
        container: unreal.MovieSceneDecorationContainerObject,
        decoration_class: unreal.Class
    ) -> unreal.Object:
        """Find a specific decoration by class on a container.

        Args:
            container: The decoration container to search.
            decoration_class: The decoration class to find.

        Returns:
            The decoration object, or None if not present.
        """
        if not container:
            raise ValueError("Container is None.")
        if not decoration_class:
            raise ValueError("Decoration class is None.")
        return container.find_decoration(decoration_class)

    @toolset_registry.tool_call
    @staticmethod
    def add_decoration(
        container: unreal.MovieSceneDecorationContainerObject,
        decoration_class: unreal.Class
    ) -> unreal.Object:
        """Add a decoration by class to a container.

        If the decoration already exists, returns the existing one.

        Args:
            container: The decoration container to add the decoration to.
            decoration_class: The decoration class to add.

        Returns:
            The decoration object (existing or newly created).
        """
        if not container:
            raise ValueError("Container is None.")
        if not decoration_class:
            raise ValueError("Decoration class is None.")
        decoration = container.add_decoration(decoration_class)
        if not decoration:
            raise ValueError(
                f"Failed to add decoration of type '{decoration_class}'."
            )
        return decoration

    @toolset_registry.tool_call
    @staticmethod
    def remove_decoration(
        container: unreal.MovieSceneDecorationContainerObject,
        decoration_class: unreal.Class
    ) -> bool:
        """Remove a decoration by class from a container.

        Args:
            container: The decoration container to modify.
            decoration_class: The decoration class to remove.
        """
        if not container:
            raise ValueError("Container is None.")
        if not decoration_class:
            raise ValueError("Decoration class is None.")
        container.remove_decoration(decoration_class)
        return True
