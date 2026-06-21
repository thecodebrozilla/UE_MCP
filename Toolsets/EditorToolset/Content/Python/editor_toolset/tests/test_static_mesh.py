# Copyright Epic Games, Inc. All Rights Reserved.

import os
import tempfile
from contextlib import contextmanager
from typing import Iterator
import unreal

from toolset_registry.tests.toolset_testcase import ToolCallTestCase
from toolset_registry.tests.automation import create_temp_folder
from editor_toolset.toolsets.static_mesh import StaticMeshTools

_CUBE_PATH = '/Engine/BasicShapes/Cube'


_TRIANGLE_OBJ = (
    'v 0.0 0.0 0.0\n'
    'v 1.0 0.0 0.0\n'
    'v 0.0 1.0 0.0\n'
    'f 1 2 3\n'
)


def _write_obj(tmp_dir: str, content: str = _TRIANGLE_OBJ) -> str:
    """Writes a Wavefront OBJ to tmp_dir and returns its absolute path."""
    path = os.path.join(tmp_dir, 'triangle.obj')
    with open(path, 'w') as f:
        f.write(content)
    return path


@contextmanager
def create_mesh_copy() -> Iterator[unreal.StaticMesh]:
    """Creates a writable copy of the engine Cube mesh in a temporary folder."""
    eas = unreal.get_editor_subsystem(unreal.EditorAssetSubsystem)
    assert eas
    with create_temp_folder() as test_folder:
        copy_path = f'{test_folder}Cube'
        eas.duplicate_asset(_CUBE_PATH, copy_path)
        mesh = unreal.load_asset(copy_path)
        assert isinstance(mesh, unreal.StaticMesh)
        yield mesh



class StaticMeshToolsTestCase(ToolCallTestCase):
    """Test StaticMeshTools toolset."""

    def test_get_lod_count(self):
        """Ensures we can get the LOD count from a static mesh."""
        mesh = unreal.load_asset(_CUBE_PATH)
        lod_count = StaticMeshTools.get_lod_count(mesh)
        self.assertGreaterEqual(lod_count, 1)

    def test_get_triangle_count(self):
        """Ensures we can get the triangle count for LOD 0."""
        mesh = unreal.load_asset(_CUBE_PATH)
        tri_count = StaticMeshTools.get_triangle_count(mesh, lod_index=0)
        self.assertGreater(tri_count, 0)

    def test_get_vertex_count(self):
        """Ensures we can get the vertex count for LOD 0."""
        mesh = unreal.load_asset(_CUBE_PATH)
        vert_count = StaticMeshTools.get_vertex_count(mesh, lod_index=0)
        self.assertGreater(vert_count, 0)

    def test_invalid_lod_index(self):
        """Ensures get_triangle_count raises an error for an out-of-range LOD index."""
        mesh = unreal.load_asset(_CUBE_PATH)
        with self.assertToolRaisesRuntimeError():
            StaticMeshTools.get_triangle_count(mesh, lod_index=999)

    def test_invalid_material_slot_name(self):
        """Ensures get_material raises an error for an unknown slot name."""
        mesh = unreal.load_asset(_CUBE_PATH)
        with self.assertToolRaisesRuntimeError():
            StaticMeshTools.get_material(mesh, 'nonexistent_slot')

    def test_get_bounds(self):
        """Ensures we can get a valid local-space bounding box for a mesh."""
        mesh = unreal.load_asset(_CUBE_PATH)
        bounds = StaticMeshTools.get_bounds(mesh)
        self.assertIsInstance(bounds, unreal.Box)
        extent = bounds.max.subtract(bounds.min)
        self.assertGreater(extent.x, 0)
        self.assertGreater(extent.y, 0)
        self.assertGreater(extent.z, 0)

    def test_get_material_slots(self):
        """Ensures we can retrieve the list of material slot names."""
        mesh = unreal.load_asset(_CUBE_PATH)
        slots = StaticMeshTools.get_material_slots(mesh)
        self.assertGreater(len(slots), 0)
        for slot in slots:
            self.assertIsInstance(slot, str)

    def test_get_material(self):
        """Ensures we can get the material assigned to a named slot."""
        mesh = unreal.load_asset(_CUBE_PATH)
        slots = StaticMeshTools.get_material_slots(mesh)
        self.assertGreater(len(slots), 0)
        material = StaticMeshTools.get_material(mesh, slots[0])
        self.assertIsInstance(material, unreal.MaterialInterface)

    def test_set_material(self):
        """Ensures set_material can clear and restore a material slot."""
        with create_mesh_copy() as mesh:
            slots = StaticMeshTools.get_material_slots(mesh)
            original_material = StaticMeshTools.get_material(mesh, slots[0])

            # Clear the slot using the raw API and confirm it's gone.
            slot_index = mesh.get_material_index(slots[0])
            mesh.modify()
            mesh.set_material(slot_index, None)
            self.assertIsNone(mesh.get_material(slot_index))

            # Reset via the toolset and confirm it's back.
            result = StaticMeshTools.set_material(mesh, slots[0], original_material)
            self.assertTrue(result)
            self.assertEqual(StaticMeshTools.get_material(mesh, slots[0]), original_material)

    def test_get_set_lod_thresholds(self):
        """Ensures we can set LOD screen-size thresholds and read them back."""
        with create_mesh_copy() as mesh:
            StaticMeshTools.generate_lods(mesh, [0.5, 0.25])
            lod_count = StaticMeshTools.get_lod_count(mesh)
            screen_sizes = StaticMeshTools.get_lod_thresholds(mesh)
            self.assertEqual(len(screen_sizes), lod_count)
            new_thresholds = [1.5, 0.5, 0.25]
            result = StaticMeshTools.set_lod_thresholds(mesh, new_thresholds)
            self.assertTrue(result)
            actual = StaticMeshTools.get_lod_thresholds(mesh)
            for expected, got in zip(new_thresholds, actual):
                self.assertAlmostEqual(expected, got, places=4)

    def test_set_lod_thresholds_wrong_count(self):
        """Ensures set_lod_thresholds raises an error when threshold count mismatches LODs."""
        with create_mesh_copy() as mesh:
            StaticMeshTools.generate_lods(mesh, [0.5])
            with self.assertToolRaisesRuntimeError():
                StaticMeshTools.set_lod_thresholds(mesh, [1.0])  # 2 LODs, 1 threshold

    def test_set_lod_thresholds_non_positive(self):
        """Ensures set_lod_thresholds raises an error for non-positive threshold values."""
        with create_mesh_copy() as mesh:
            StaticMeshTools.generate_lods(mesh, [0.5])
            with self.assertToolRaisesRuntimeError():
                StaticMeshTools.set_lod_thresholds(mesh, [1.0, 0.0])

    def test_set_lod_thresholds_non_descending(self):
        """Ensures set_lod_thresholds raises an error when thresholds are not strictly descending."""
        with create_mesh_copy() as mesh:
            StaticMeshTools.generate_lods(mesh, [0.5])
            with self.assertToolRaisesRuntimeError():
                StaticMeshTools.set_lod_thresholds(mesh, [0.5, 1.0])  # ascending
            with self.assertToolRaisesRuntimeError():
                StaticMeshTools.set_lod_thresholds(mesh, [1.0, 1.0])  # equal

    def test_generate_lods(self):
        """Ensures we can auto-generate LODs with triangle reduction."""
        with create_mesh_copy() as mesh:
            total_lods = StaticMeshTools.generate_lods(mesh, [0.5, 0.25])
            self.assertEqual(total_lods, 3)
            self.assertEqual(StaticMeshTools.get_lod_count(mesh), 3)
            thresholds = StaticMeshTools.get_lod_thresholds(mesh)
            self.assertAlmostEqual(thresholds[0], 2.0, places=4)
            self.assertAlmostEqual(thresholds[1], 0.75, places=4)
            self.assertAlmostEqual(thresholds[2], 0.5625, places=4)

    def test_generate_lods_invalid_percents(self):
        """Ensures generate_lods raises an error for out-of-range triangle percentages."""
        mesh = unreal.load_asset(_CUBE_PATH)
        with self.assertToolRaisesRuntimeError():
            StaticMeshTools.generate_lods(mesh, [])
        with self.assertToolRaisesRuntimeError():
            StaticMeshTools.generate_lods(mesh, [0.0])
        with self.assertToolRaisesRuntimeError():
            StaticMeshTools.generate_lods(mesh, [1.5])

    def test_remove_lods(self):
        """Ensures that removing LODs returns the mesh to a single LOD."""
        with create_mesh_copy() as mesh:
            StaticMeshTools.generate_lods(mesh, [0.5])
            self.assertEqual(StaticMeshTools.get_lod_count(mesh), 2)
            result = StaticMeshTools.remove_lods(mesh)
            self.assertTrue(result)
            self.assertEqual(StaticMeshTools.get_lod_count(mesh), 1)

    def test_generate_and_remove_convex_collisions(self):
        """Ensures convex collision can be generated and then fully removed."""
        with create_mesh_copy() as mesh:
            smes = unreal.get_editor_subsystem(unreal.StaticMeshEditorSubsystem)
            assert smes

            result = StaticMeshTools.generate_convex_collisions(mesh, hull_count=2)
            self.assertTrue(result)
            self.assertGreater(smes.get_convex_collision_count(mesh), 0)

            result = StaticMeshTools.remove_collisions(mesh)
            self.assertTrue(result)
            self.assertEqual(smes.get_convex_collision_count(mesh), 0)
            self.assertEqual(smes.get_simple_collision_count(mesh), 0)

    def test_get_set_nanite_enabled(self):
        """Ensures we can toggle the Nanite enabled state on a mesh copy."""
        with create_mesh_copy() as mesh:
            original = StaticMeshTools.is_nanite_enabled(mesh)
            StaticMeshTools.set_nanite_enabled(mesh, not original)
            self.assertEqual(StaticMeshTools.is_nanite_enabled(mesh), not original)
            StaticMeshTools.set_nanite_enabled(mesh, original)
            self.assertEqual(StaticMeshTools.is_nanite_enabled(mesh), original)

    def test_import_file_obj(self):
        """Ensures import_file produces a StaticMesh with the OBJ's triangle."""
        with create_temp_folder() as folder, tempfile.TemporaryDirectory() as tmp_dir:
            path = _write_obj(tmp_dir)
            result = StaticMeshTools.import_file(folder, 'ImportedMesh', path)
            self.assertEqual(len(result), 1)
            mesh = result[0]
            self.assertIsInstance(mesh, unreal.StaticMesh)
            self.assertEqual(StaticMeshTools.get_triangle_count(mesh, lod_index=0), 1)

    def test_import_file_unsupported_extension(self):
        """Ensures import_file rejects file extensions FbxFactory does not declare."""
        with create_temp_folder() as folder, tempfile.TemporaryDirectory() as tmp_dir:
            path = os.path.join(tmp_dir, 'not_a_mesh.txt')
            with open(path, 'w') as f:
                f.write('hello')
            with self.assertToolRaisesRuntimeError():
                StaticMeshTools.import_file(folder, 'NotAMesh', path)

