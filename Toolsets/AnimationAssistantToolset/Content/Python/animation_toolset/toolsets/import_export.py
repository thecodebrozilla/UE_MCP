# Copyright Epic Games, Inc. All Rights Reserved.

import unreal

import toolset_registry


@unreal.uclass()
class SequencerImportExportTools(unreal.ToolsetDefinition):
    """Tools for importing and exporting animation data to and from Sequencer.
    Use when exporting bindings or Control Rig animation to FBX files,
    importing FBX animation onto bindings or Control Rig tracks, exporting
    animation to AnimSequence assets, or linking AnimSequences for
    auto-updates."""

    @toolset_registry.tool_call
    @staticmethod
    def export_fbx(
        world: unreal.World,
        sequence: unreal.LevelSequence,
        bindings: list[unreal.SequencerBindingProxy],
        fbx_file_path: str,
        override_options: unreal.FbxExportOption | None = None
    ) -> bool:
        """Export a level sequence to FBX.

        Args:
            world: The world context.
            sequence: The LevelSequence to export.
            bindings: The bindings to include in the export.
            fbx_file_path: The output FBX file path.
            override_options: Optional FBX export options.

        Returns:
            True if the export succeeded, False otherwise.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        if not fbx_file_path:
            raise ValueError("FBX file path is empty.")

        export_params = unreal.SequencerExportFBXParams()
        export_params.world = world
        export_params.sequence = sequence
        export_params.bindings = bindings
        export_params.fbx_file_name = fbx_file_path
        if override_options:
            export_params.override_options = override_options

        return unreal.SequencerTools.export_level_sequence_fbx(export_params)

    @toolset_registry.tool_call
    @staticmethod
    def import_fbx(
        world: unreal.World,
        sequence: unreal.LevelSequence,
        bindings: list[unreal.SequencerBindingProxy],
        import_settings: unreal.MovieSceneUserImportFBXSettings,
        fbx_file_path: str
    ) -> bool:
        """Import FBX data into a level sequence.

        Args:
            world: The world context.
            sequence: The LevelSequence to import into.
            bindings: The bindings to apply the import to.
            import_settings: The FBX import settings.
            fbx_file_path: The input FBX file path.

        Returns:
            True if the import succeeded, False otherwise.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        if not fbx_file_path:
            raise ValueError("FBX file path is empty.")

        return unreal.SequencerTools.import_level_sequence_fbx(
            world,
            sequence,
            bindings,
            import_settings,
            fbx_file_path
        )

    @toolset_registry.tool_call
    @staticmethod
    def export_anim_sequence(
        world: unreal.World,
        sequence: unreal.LevelSequence,
        anim_sequence: unreal.AnimSequence,
        binding: unreal.SequencerBindingProxy,
        create_link: bool = False
    ) -> bool:
        """Export animation from a sequence binding to an AnimSequence asset.

        Args:
            world: The world context.
            sequence: The source LevelSequence.
            anim_sequence: The destination AnimSequence asset.
            binding: The binding whose animation to export.
            create_link: Whether to create a link between the sequence and
                the exported AnimSequence.

        Returns:
            True if the export succeeded, False otherwise.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        if not anim_sequence:
            raise ValueError("AnimSequence is None.")

        export_option = unreal.AnimSeqExportOption()
        return unreal.SequencerTools.export_anim_sequence(
            world,
            sequence,
            anim_sequence,
            export_option,
            binding,
            create_link
        )

    @toolset_registry.tool_call
    @staticmethod
    def link_anim_sequence(
        sequence: unreal.LevelSequence,
        anim_sequence: unreal.AnimSequence,
        binding: unreal.SequencerBindingProxy
    ) -> bool:
        """Link an AnimSequence asset to a level sequence binding.

        When the sequence is modified, the linked AnimSequence can be
        automatically updated.

        Args:
            sequence: The LevelSequence to link from.
            anim_sequence: The AnimSequence to link to.
            binding: The binding to associate the link with.

        Returns:
            True on success. Returns False (via the tool_call decorator) if
            sequence or anim_sequence is None.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        if not anim_sequence:
            raise ValueError("AnimSequence is None.")

        unreal.SequencerTools.link_anim_sequence(
            sequence,
            anim_sequence,
            binding
        )
        return True

    @toolset_registry.tool_call
    @staticmethod
    def get_linked_anim_sequences(
        sequence: unreal.LevelSequence,
    ) -> list[str]:
        """Get content paths of all AnimSequences linked to a LevelSequence.

        Linked AnimSequences auto-update when the LevelSequence changes.
        They are created via export_anim_sequence with create_link=True.

        Args:
            sequence: The LevelSequence to query.

        Returns:
            List of content paths (e.g. '/Game/Anim/Test_Anim') for each
            linked AnimSequence. Empty list if no links exist.
        """
        if not sequence:
            raise ValueError("Sequence is None.")
        link = unreal.SequencerTools.get_anim_sequence_link_from_level_sequence(
            sequence
        )
        if not link:
            return []
        paths = []
        for entry in link.anim_sequence_links:
            soft_path = entry.path_to_anim_sequence
            paths.append(str(soft_path))
        return paths

    @toolset_registry.tool_call
    @staticmethod
    def get_linked_level_sequence(
        anim_sequence: unreal.AnimSequence,
    ) -> str:
        """Get the content path of the LevelSequence linked to an AnimSequence.

        Args:
            anim_sequence: The AnimSequence to query.

        Returns:
            Content path of the linked LevelSequence, or empty string if
            no link exists.
        """
        if not anim_sequence:
            raise ValueError("AnimSequence is None.")
        link = unreal.SequencerTools.get_level_sequence_link_from_anim_sequence(
            anim_sequence
        )
        if not link:
            return ""
        return str(link.path_to_level_sequence)

    # ========================================================================
