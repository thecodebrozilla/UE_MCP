# Copyright Epic Games, Inc. All Rights Reserved.

from contextlib import ExitStack
import os
import tempfile
import unittest

import unreal

from toolset_registry.tests.automation import create_temp_folder
from animation_toolset.tests._sequencer_test_base import (
    MANNEQUIN_MESH_CANDIDATES,
    resolve_mannequin_mesh_path,
)
from animation_toolset.toolsets.sequencer import SequencerTools
from animation_toolset.toolsets.import_export import SequencerImportExportTools


class SequencerImportExportTestCase(unittest.TestCase):
    """Test SequencerImportExportTools FBX and AnimSequence I/O."""

    def setUp(self):
        super().setUp()
        # Initialize attrs first so tearDown is safe even if we skip below.
        self._stack = None
        self._test_folder = None
        self._tempdir = None
        self._mesh_path = None
        self.sequence = None
        self.actor = None
        self.binding = None
        self.world = None

        # Resolve the mannequin mesh lazily so tests work regardless of
        # asset-registry scan timing. S7: the per-test _make_anim_sequence
        # helper also needs this path, so stash it on the instance.
        self._mesh_path = resolve_mannequin_mesh_path()
        if self._mesh_path is None:
            self.skipTest(
                'No skeletal mesh available from candidates: '
                + ', '.join(MANNEQUIN_MESH_CANDIDATES)
            )
        mesh = unreal.load_asset(self._mesh_path)
        if mesh is None:
            self.skipTest(f'Mannequin mesh failed to load at {self._mesh_path}')

        self._stack = ExitStack()
        self._test_folder = self._stack.enter_context(create_temp_folder())
        self._tempdir = self._stack.enter_context(
            tempfile.TemporaryDirectory(prefix='seq_imp_exp_')
        )

        self.sequence = SequencerTools.create_level_sequence(
            self._test_folder, 'ImportExportTest'
        )
        unreal.LevelSequenceEditorBlueprintLibrary.open_level_sequence(
            self.sequence
        )
        SequencerTools.set_playback_range(self.sequence, 0, 30)

        self.actor = unreal.EditorLevelLibrary.spawn_actor_from_class(
            unreal.SkeletalMeshActor,
            unreal.Vector(0, 0, 0),
            unreal.Rotator(0, 0, 0),
        )
        skel_comp = self.actor.get_editor_property('skeletal_mesh_component')
        skel_comp.set_skeletal_mesh_asset(mesh)

        subsystem = unreal.get_editor_subsystem(
            unreal.LevelSequenceEditorSubsystem
        )
        bindings = subsystem.add_actors([self.actor])
        self.binding = bindings[0]

        self.world = unreal.EditorLevelLibrary.get_editor_world()

    def tearDown(self) -> None:
        try:
            unreal.LevelSequenceEditorBlueprintLibrary.empty_selection()
        except Exception:
            pass
        try:
            unreal.LevelSequenceEditorBlueprintLibrary.close_level_sequence()
        except Exception:
            pass
        if self.actor:
            self.actor.destroy_actor()
        self.sequence = None
        self.binding = None
        self.actor = None
        if self._stack is not None:
            self._stack.close()
        super().tearDown()

    def test_export_fbx_writes_file(self):
        """export_fbx should write an FBX file to disk."""
        fbx_path = os.path.join(self._tempdir, 'export.fbx')
        result = SequencerImportExportTools.export_fbx(
            self.world, self.sequence, [self.binding], fbx_path
        )
        self.assertTrue(result, "export_fbx reported failure")
        self.assertTrue(os.path.exists(fbx_path), "FBX file not created")
        self.assertGreater(
            os.path.getsize(fbx_path), 0, "FBX file is empty"
        )

    def test_import_fbx_roundtrip(self):
        """Exporting and reimporting FBX should succeed."""
        fbx_path = os.path.join(self._tempdir, 'roundtrip.fbx')
        self.assertTrue(
            SequencerImportExportTools.export_fbx(
                self.world, self.sequence, [self.binding], fbx_path
            )
        )
        self.assertTrue(os.path.exists(fbx_path))

        import_settings = unreal.MovieSceneUserImportFBXSettings()
        result = SequencerImportExportTools.import_fbx(
            self.world, self.sequence, [self.binding],
            import_settings, fbx_path
        )
        self.assertTrue(result, "import_fbx reported failure")

    def _make_anim_sequence(self, name):
        """Create an AnimSequence asset with the mannequin skeleton set up-front."""
        # self._mesh_path was already resolved in setUp; load_asset can't
        # return None here unless the asset was unloaded mid-test.
        mesh = unreal.load_asset(self._mesh_path)
        skeleton = mesh.skeleton
        self.assertIsNotNone(skeleton, 'Mannequin mesh has no skeleton')
        factory = unreal.AnimSequenceFactory()
        factory.set_editor_property('target_skeleton', skeleton)
        anim_seq = unreal.AssetToolsHelpers.get_asset_tools().create_asset(
            asset_name=name,
            package_path=self._test_folder.rstrip('/'),
            asset_class=unreal.AnimSequence,
            factory=factory,
        )
        return anim_seq

    def test_export_anim_sequence_populates_asset(self):
        """export_anim_sequence should bake animation to an AnimSequence asset."""
        anim_seq = self._make_anim_sequence('TestExportedAnim')
        self.assertIsNotNone(anim_seq)

        result = SequencerImportExportTools.export_anim_sequence(
            self.world, self.sequence, anim_seq, self.binding,
            create_link=False
        )
        self.assertTrue(result, "export_anim_sequence reported failure")

    def test_link_anim_sequence(self):
        """link_anim_sequence should complete without error."""
        anim_seq = self._make_anim_sequence('TestLinkedAnim')
        self.assertIsNotNone(anim_seq)

        # First do an export so the asset has bake settings.
        SequencerImportExportTools.export_anim_sequence(
            self.world, self.sequence, anim_seq, self.binding,
            create_link=False
        )
        # Now link it - should not raise.
        SequencerImportExportTools.link_anim_sequence(
            self.sequence, anim_seq, self.binding
        )

    def test_export_fbx_returns_bool(self):
        """export_fbx should return a truthy result after writing the file."""
        fbx_path = os.path.join(self._tempdir, 'returntype.fbx')
        result = SequencerImportExportTools.export_fbx(
            self.world, self.sequence, [self.binding], fbx_path
        )
        self.assertIsInstance(result, bool)
        self.assertTrue(result)

    def test_export_fbx_rejects_empty_path(self):
        """Empty path should produce a failure result (decorator catches ValueError)."""
        result = SequencerImportExportTools.export_fbx(
            self.world, self.sequence, [self.binding], ""
        )
        self.assertFalse(result, "export_fbx should fail on empty path")

    def test_export_fbx_rejects_none_sequence(self):
        """None sequence should produce a failure result (decorator catches ValueError)."""
        fbx_path = os.path.join(self._tempdir, 'none.fbx')
        result = SequencerImportExportTools.export_fbx(
            self.world, None, [self.binding], fbx_path
        )
        self.assertFalse(result, "export_fbx should fail on None sequence")

    def test_link_anim_sequence_rejects_none(self):
        """link_anim_sequence should return False for None inputs."""
        anim_seq = self._make_anim_sequence('TestLinkNoneBool')
        self.assertIsNotNone(anim_seq)
        result = SequencerImportExportTools.link_anim_sequence(
            self.sequence, None, self.binding
        )
        self.assertFalse(result, "link_anim_sequence should fail with None anim")

    def test_get_linked_anim_sequences_empty(self):
        """Fresh sequence has no linked AnimSequences."""
        result = SequencerImportExportTools.get_linked_anim_sequences(
            self.sequence
        )
        self.assertTrue(hasattr(result, '__len__'))
        self.assertEqual(len(result), 0)

    def test_get_linked_anim_sequences_after_link(self):
        """After export with create_link=True, the sequence reports the link."""
        anim_seq = self._make_anim_sequence('TestLinkedList')
        self.assertIsNotNone(anim_seq)
        SequencerImportExportTools.export_anim_sequence(
            self.world, self.sequence, anim_seq, self.binding,
            create_link=True
        )
        result = SequencerImportExportTools.get_linked_anim_sequences(
            self.sequence
        )
        self.assertTrue(hasattr(result, '__len__'))
        self.assertGreaterEqual(len(result), 1)

    def test_get_linked_level_sequence_empty(self):
        """AnimSequence without a link returns empty string."""
        anim_seq = self._make_anim_sequence('TestUnlinked')
        result = SequencerImportExportTools.get_linked_level_sequence(anim_seq)
        self.assertIsInstance(result, str)
        self.assertEqual(result, "")

