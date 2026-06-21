# Copyright Epic Games, Inc. All Rights Reserved.

import os
import tempfile
from contextlib import ExitStack

import unreal

from toolset_registry.tests.toolset_testcase import ToolCallTestCase
from editor_toolset.toolsets.skeletal_mesh import SkeletalMeshTools
from toolset_registry.tests.automation import create_temp_folder

_ENGINE_MATERIAL_PATH = '/Engine/BasicShapes/BasicShapeMaterial'
_ENGINE_MESH_PATH = '/Engine/EditorMeshes/SkeletalMesh/DefaultSkeletalMesh'


def _add_test_socket(mesh: unreal.SkeletalMesh, socket_name: str = 'TestSocket') -> str:
    """Adds a named socket to mesh attached to its first bone. Returns the socket name."""
    bone_names = SkeletalMeshTools.get_bone_names(mesh)
    SkeletalMeshTools.add_socket(mesh, socket_name, bone_names[0])
    return socket_name


def _add_test_physics_asset(mesh: unreal.SkeletalMesh) -> unreal.PhysicsAsset:
    """Creates and assigns a physics asset to mesh. Returns the created physics asset."""
    smes = unreal.get_editor_subsystem(unreal.SkeletalMeshEditorSubsystem)
    assert smes
    physics_asset = smes.create_physics_asset(mesh, set_to_mesh=True)
    assert physics_asset
    return physics_asset


class SkeletalMeshToolsTestCase(ToolCallTestCase):
    """Test SkeletalMeshTools toolset.
    Copies the engine mesh into a temp folder and builds a three-bone chain
    (joint1 -> joint2 -> joint3) on it. SkeletonModifier writes through to the
    engine's shared Skeleton asset (the skeleton property on SkeletalMesh is
    read-only, so the copy cannot be retargeted). _cleanup_skeleton removes the
    added bones and clears the dirty flag so subsequent tests see a clean state.
    """

    def setUp(self):
        super().setUp()
        # We need to enter the temp_folder context in test setup because these tests create
        # Python objects that reference SkeletalMesh UObjects and those Python objects need
        # to be out of scope before we delete the mesh asset.
        self._stack = ExitStack()
        test_folder = self._stack.enter_context(create_temp_folder())
        eas = unreal.get_editor_subsystem(unreal.EditorAssetSubsystem)
        assert eas
        copy_path = f'{test_folder}DefaultSkeletalMesh_Test'
        eas.duplicate_asset(_ENGINE_MESH_PATH, copy_path)
        self.mesh = unreal.load_asset(copy_path)
        assert isinstance(self.mesh, unreal.SkeletalMesh)

        modifier = unreal.SkeletonModifier()
        modifier.set_skeletal_mesh(self.mesh)
        modifier.add_bone('joint2', 'joint1', unreal.Transform())
        modifier.add_bone('joint3', 'joint2', unreal.Transform())
        modifier.commit_skeleton_to_skeletal_mesh()

        mesh_ref = self.mesh
        self._stack.callback(SkeletalMeshToolsTestCase._cleanup_skeleton, mesh_ref)

    def tearDown(self) -> None:
        self.mesh = None
        self._stack.close()
        super().tearDown()

    @staticmethod
    def _cleanup_skeleton(mesh: unreal.SkeletalMesh) -> None:
        """Removes the test bones and clears the dirty flag on the engine skeleton."""
        modifier = unreal.SkeletonModifier()
        modifier.set_skeletal_mesh(mesh)
        modifier.remove_bone('joint2', True)
        modifier.commit_skeleton_to_skeletal_mesh()
        eas = unreal.get_editor_subsystem(unreal.EditorAssetSubsystem)
        if eas:
            eas.set_dirty_flag(mesh.skeleton, False)

    # --- LOD & Mesh Info ---

    def test_get_lod_count(self):
        """Ensures we can get the LOD count from a skeletal mesh."""
        lod_count = SkeletalMeshTools.get_lod_count(self.mesh)
        self.assertGreaterEqual(lod_count, 1)

    def test_get_vertex_count(self):
        """Ensures we can get the vertex count for LOD 0."""
        vert_count = SkeletalMeshTools.get_vertex_count(self.mesh, lod_index=0)
        self.assertGreater(vert_count, 0)

    def test_get_section_count(self):
        """Ensures we can get the section count for LOD 0."""
        section_count = SkeletalMeshTools.get_section_count(self.mesh, lod_index=0)
        self.assertGreater(section_count, 0)

    def test_invalid_lod_index(self):
        """Ensures _validate_lod_index raises ValueError for an out-of-range LOD index."""
        with self.assertRaises(ValueError):
            SkeletalMeshTools._validate_lod_index(self.mesh, 999)

    def test_get_bounds(self):
        """Ensures we can get a valid bounding volume for a skeletal mesh."""
        bounds = SkeletalMeshTools.get_bounds(self.mesh)
        self.assertIsInstance(bounds, unreal.BoxSphereBounds)
        self.assertGreater(bounds.sphere_radius, 0)

    # --- Skeleton & Bones ---

    def test_get_skeleton(self):
        """Ensures we can retrieve the skeleton from a skeletal mesh."""
        skeleton = SkeletalMeshTools.get_skeleton(self.mesh)
        self.assertIsInstance(skeleton, unreal.Skeleton)

    def test_get_bone_names(self):
        """Ensures get_bone_names returns a non-empty list containing all bones."""
        bone_names = SkeletalMeshTools.get_bone_names(self.mesh)
        self.assertGreater(len(bone_names), 0)
        self.assertIn('joint1', bone_names)

    def test_get_bone_names_root_first(self):
        """Ensures the root bone is the first entry in the bone list."""
        bone_names = SkeletalMeshTools.get_bone_names(self.mesh)
        self.assertEqual(bone_names[0], 'joint1')

    def test_get_bone_parent(self):
        """Ensures get_bone_parent returns the correct parent for non-root bones."""
        self.assertEqual(SkeletalMeshTools.get_bone_parent(self.mesh, 'joint2'), 'joint1')
        self.assertEqual(SkeletalMeshTools.get_bone_parent(self.mesh, 'joint3'), 'joint2')

    def test_get_bone_parent_root(self):
        """Ensures get_bone_parent returns an empty string for the root bone."""
        self.assertEqual(SkeletalMeshTools.get_bone_parent(self.mesh, 'joint1'), '')

    def test_get_bone_children(self):
        """Ensures get_bone_children returns direct children only."""
        self.assertIn('joint2', SkeletalMeshTools.get_bone_children(self.mesh, 'joint1'))
        self.assertIn('joint3', SkeletalMeshTools.get_bone_children(self.mesh, 'joint2'))

    def test_get_bone_children_leaf(self):
        """Ensures get_bone_children returns an empty list for a leaf bone."""
        self.assertEqual(SkeletalMeshTools.get_bone_children(self.mesh, 'joint3'), [])

    def test_validate_bone_name_invalid(self):
        """Ensures _validate_bone_name raises ValueError for an unknown bone name."""
        with self.assertRaises(ValueError):
            SkeletalMeshTools._validate_bone_name(self.mesh, 'nonexistent_bone')

    # --- Materials ---

    def test_get_set_material(self):
        """Ensures set_material assigns a material and get_material retrieves it."""
        slots = SkeletalMeshTools.get_material_slots(self.mesh)
        self.assertGreater(len(slots), 0)
        new_material = unreal.load_asset(_ENGINE_MATERIAL_PATH)
        self.assertIsInstance(new_material, unreal.MaterialInterface)
        result = SkeletalMeshTools.set_material(self.mesh, slots[0], new_material)
        self.assertTrue(result)
        self.assertEqual(SkeletalMeshTools.get_material(self.mesh, slots[0]), new_material)

    def test_invalid_material_slot_name(self):
        """Ensures _get_material_slot_index raises ValueError for an unknown slot name."""
        with self.assertRaises(ValueError):
            SkeletalMeshTools._get_material_slot_index(self.mesh, 'nonexistent_slot')

    # --- Physics ---

    def test_get_physics_asset_none(self):
        """Ensures get_physics_asset raises an error when no physics asset is assigned."""
        with self.assertToolRaisesRuntimeError():
            SkeletalMeshTools.get_physics_asset(self.mesh)

    def test_set_get_physics_asset(self):
        """Ensures get_physics_asset retrieves and assign_physics_asset reassigns it."""
        physics_asset = _add_test_physics_asset(self.mesh)
        retrieved = SkeletalMeshTools.get_physics_asset(self.mesh)
        self.assertEqual(retrieved, physics_asset)
        result = SkeletalMeshTools.assign_physics_asset(self.mesh, physics_asset)
        self.assertTrue(result)
        self.assertEqual(SkeletalMeshTools.get_physics_asset(self.mesh), physics_asset)

    # --- Morph Targets ---

    def test_get_morph_target_names(self):
        """Ensures the default skeletal mesh has no morph targets."""
        names = SkeletalMeshTools.get_morph_target_names(self.mesh)
        self.assertEqual(len(names), 0)

    # --- Sockets ---

    def test_get_socket_names(self):
        """Ensures get_socket_names reflects sockets added to the mesh."""
        bone_names = SkeletalMeshTools.get_bone_names(self.mesh)
        SkeletalMeshTools.add_socket(self.mesh, 'TestSocket', bone_names[0])
        self.assertIn('TestSocket', SkeletalMeshTools.get_socket_names(self.mesh))

    def test_add_socket(self):
        """Ensures add_socket creates a socket with the correct name and bone attachment."""
        bone_names = SkeletalMeshTools.get_bone_names(self.mesh)
        socket = SkeletalMeshTools.add_socket(self.mesh, 'TestSocket', bone_names[0])
        self.assertEqual(str(socket.socket_name), 'TestSocket')
        self.assertEqual(str(socket.bone_name), bone_names[0])

    def test_get_socket_bone(self):
        """Ensures get_socket_bone returns the bone the socket was attached to."""
        bone_names = SkeletalMeshTools.get_bone_names(self.mesh)
        SkeletalMeshTools.add_socket(self.mesh, 'TestSocket', bone_names[0])
        self.assertEqual(SkeletalMeshTools.get_socket_bone(self.mesh, 'TestSocket'), bone_names[0])

    def test_set_get_socket_transform(self):
        """Ensures set_socket_transform modifies the socket's local transform."""
        socket_name = _add_test_socket(self.mesh)
        new_transform = unreal.Transform()
        new_transform.translation = unreal.Vector(10.0, 20.0, 30.0)
        new_transform.rotation = unreal.Quat(0.0, 0.0, 0.0, 1.0)
        new_transform.scale3d = unreal.Vector(1.0, 1.0, 1.0)

        SkeletalMeshTools.set_socket_transform(self.mesh, socket_name, new_transform)

        updated = SkeletalMeshTools.get_socket_transform(self.mesh, socket_name)
        self.assertAlmostEqual(updated.translation.x, 10.0, places=3)
        self.assertAlmostEqual(updated.translation.y, 20.0, places=3)
        self.assertAlmostEqual(updated.translation.z, 30.0, places=3)

    def test_rename_socket(self):
        """Ensures rename_socket changes the socket name on the mesh."""
        original_name = _add_test_socket(self.mesh)
        new_name = original_name + '_Renamed'

        result = SkeletalMeshTools.rename_socket(self.mesh, original_name, new_name)
        self.assertTrue(result)
        updated_names = SkeletalMeshTools.get_socket_names(self.mesh)
        self.assertIn(new_name, updated_names)
        self.assertNotIn(original_name, updated_names)

    def test_remove_socket(self):
        """Ensures remove_socket deletes the socket from the mesh."""
        socket_name = _add_test_socket(self.mesh)
        result = SkeletalMeshTools.remove_socket(self.mesh, socket_name)
        self.assertTrue(result)
        self.assertNotIn(socket_name, SkeletalMeshTools.get_socket_names(self.mesh))

    def test_find_socket_not_found(self):
        """Ensures _find_socket raises ValueError for a nonexistent socket name."""
        with self.assertRaises(ValueError):
            SkeletalMeshTools._find_socket(self.mesh, 'nonexistent_socket')

    def test_import_file_unsupported_extension(self):
        """Ensures import_file rejects file extensions FbxFactory does not declare."""
        # setUp() already entered create_temp_folder, so derive the folder from
        # self.mesh rather than nesting another temp folder.
        folder = os.path.dirname(self.mesh.get_path_name())
        with tempfile.TemporaryDirectory() as tmp_dir:
            path = os.path.join(tmp_dir, 'not_a_skeletal_mesh.obj')
            with open(path, 'w') as f:
                f.write('v 0 0 0\n')
            with self.assertToolRaisesRuntimeError():
                SkeletalMeshTools.import_file(folder, 'NotAMesh', path)
