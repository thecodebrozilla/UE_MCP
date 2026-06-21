# Copyright Epic Games, Inc. All Rights Reserved.

import unreal

import toolset_registry


@unreal.uclass()
class SequencerCustomBindingTools(unreal.ToolsetDefinition):
    """Tools for converting and managing custom binding types in Sequencer. Use
    when converting between possessable, spawnable, and custom/replaceable
    bindings, querying what custom binding type a binding uses, accessing
    custom binding objects for property inspection, or changing the actor
    template class on spawnables/replaceables."""

    @toolset_registry.tool_call
    @staticmethod
    def convert_to_spawnable(
        binding: unreal.SequencerBindingProxy,
    ) -> list[unreal.SequencerBindingProxy]:
        """Convert a possessable binding to a spawnable.

        Args:
            binding: The possessable binding to convert.

        Returns:
            List of new spawnable SequencerBindingProxy objects.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        return list(subsystem.convert_to_spawnable(binding))

    @toolset_registry.tool_call
    @staticmethod
    def convert_to_possessable(
        binding: unreal.SequencerBindingProxy,
    ) -> unreal.SequencerBindingProxy:
        """Convert a spawnable binding to a possessable.

        Args:
            binding: The spawnable binding to convert.

        Returns:
            The new possessable SequencerBindingProxy.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        return subsystem.convert_to_possessable(binding)

    @toolset_registry.tool_call
    @staticmethod
    def convert_to_custom_binding(
        binding: unreal.SequencerBindingProxy,
        binding_type_class: str,
    ) -> unreal.SequencerBindingProxy:
        """Convert a binding to a custom binding type.

        Args:
            binding: The binding to convert.
            binding_type_class: Full class path of the custom binding type.

        Returns:
            The converted SequencerBindingProxy.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        cls = unreal.load_class(None, binding_type_class)
        if cls is None:
            raise ValueError(
                f"Could not load binding type class '{binding_type_class}'."
            )
        return subsystem.convert_to_custom_binding(binding, cls)

    @toolset_registry.tool_call
    @staticmethod
    def get_custom_binding_type(
        binding: unreal.SequencerBindingProxy,
    ) -> str:
        """Get the custom binding class for a binding.

        Returns the class path of the custom binding type, or an empty
        string for standard possessable bindings.

        Args:
            binding: The binding to query.

        Returns:
            Class path string, or empty string.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        cls = subsystem.get_custom_binding_type(binding)
        if cls is None:
            return ""
        return cls.get_path_name()

    @toolset_registry.tool_call
    @staticmethod
    def get_custom_binding_objects(
        binding: unreal.SequencerBindingProxy,
    ) -> list[unreal.MovieSceneCustomBinding]:
        """Get the custom binding instances for a binding.

        Args:
            binding: The binding to query.

        Returns:
            List of UMovieSceneCustomBinding objects.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        return list(subsystem.get_custom_binding_objects(binding))

    @toolset_registry.tool_call
    @staticmethod
    def get_custom_bindings_of_type(
        binding_type_class: str,
    ) -> list[unreal.SequencerBindingProxy]:
        """Find all bindings of a given custom type in the current sequence.

        Args:
            binding_type_class: Full class path of the custom binding type.

        Returns:
            List of matching SequencerBindingProxy objects.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        cls = unreal.load_class(None, binding_type_class)
        if cls is None:
            raise ValueError(
                f"Could not load binding type class '{binding_type_class}'."
            )
        return list(subsystem.get_custom_bindings_of_type(cls))

    @toolset_registry.tool_call
    @staticmethod
    def change_actor_template_class(
        binding: unreal.SequencerBindingProxy,
        actor_class: str,
    ) -> bool:
        """Set the actor class for a spawnable or replaceable template.

        Args:
            binding: The spawnable/replaceable binding to modify.
            actor_class: Full class path of the new actor class.

        Returns:
            True if the class was changed successfully.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        cls = unreal.load_class(None, actor_class)
        if cls is None:
            raise ValueError(f"Could not load actor class '{actor_class}'.")
        return subsystem.change_actor_template_class(binding, cls)

    @toolset_registry.tool_call
    @staticmethod
    def save_default_spawnable_state(
        binding: unreal.SequencerBindingProxy,
    ) -> bool:
        """Save the current state of a spawnable as its default.

        Args:
            binding: The spawnable binding to save defaults for.
        """
        subsystem = unreal.get_editor_subsystem(unreal.LevelSequenceEditorSubsystem)
        subsystem.save_default_spawnable_state(binding)
        return True

    # ========================================================================
