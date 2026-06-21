# Copyright Epic Games, Inc. All Rights Reserved.

import unreal

import toolset_registry
from editor_toolset.toolsets.asset import import_asset


@unreal.uclass()
class StaticMeshTools(unreal.ToolsetDefinition):
    """Provides tools for inspecting and modifying static mesh assets."""

    @toolset_registry.tool_call
    @staticmethod
    def import_file(
            folder_path: str, asset_name: str, source_file: str,
            import_materials: bool = False,
            import_textures: bool = False,
            combine_meshes: bool = True) -> list[unreal.Object]:
        """Imports a mesh file from disk as a StaticMesh asset.

        Args:
            folder_path: The content-browser folder to create the asset in.
            asset_name: The name of the new asset.
            source_file: The absolute path to the source mesh file on disk.
            import_materials: When True, create Material assets for any materials
                referenced in the file. When False, the imported meshes have no
                materials assigned.
            import_textures: When True, create Texture2D assets for any textures
                referenced by the imported materials. Only effective when
                import_materials is True.
            combine_meshes: When True, all meshes in the file are merged into a
                single StaticMesh. When False, each mesh in the file produces
                its own StaticMesh asset.

        Returns:
            The assets produced by the import. The first entry is the primary
            StaticMesh; additional entries may include extra StaticMeshes (when
            combine_meshes is False) and Material/Texture assets (when the
            corresponding import flags are True).
        """
        options = unreal.FbxImportUI()
        options.automated_import_should_detect_type = False
        options.import_mesh = True
        options.import_as_skeletal = False
        options.mesh_type_to_import = unreal.FBXImportType.FBXIT_STATIC_MESH
        options.original_import_type = unreal.FBXImportType.FBXIT_STATIC_MESH
        options.import_materials = import_materials
        options.import_textures = import_textures
        options.import_animations = False
        options.static_mesh_import_data.combine_meshes = combine_meshes
        return import_asset(
            folder_path, asset_name, source_file,
            options=options, factory=unreal.FbxFactory())

    @toolset_registry.tool_call
    @staticmethod
    def get_lod_count(mesh: unreal.StaticMesh) -> int:
        """Returns the number of LODs in a static mesh asset.

        Args:
            mesh: The static mesh asset to query.

        Returns:
            The number of LODs.
        """
        return StaticMeshTools._smes().get_lod_count(mesh)

    @toolset_registry.tool_call
    @staticmethod
    def get_triangle_count(mesh: unreal.StaticMesh, lod_index: int = 0) -> int:
        """Returns the number of triangles in a specific LOD of a static mesh.

        Args:
            mesh: The static mesh asset to query.
            lod_index: The LOD index to query. Defaults to 0 (highest quality).

        Returns:
            The number of triangles in the specified LOD.
        """
        StaticMeshTools._validate_lod_index(mesh, lod_index)
        return mesh.get_num_triangles(lod_index)

    @toolset_registry.tool_call
    @staticmethod
    def get_vertex_count(mesh: unreal.StaticMesh, lod_index: int = 0) -> int:
        """Returns the number of vertices in a specific LOD of a static mesh.

        Args:
            mesh: The static mesh asset to query.
            lod_index: The LOD index to query. Defaults to 0 (highest quality).

        Returns:
            The number of vertices in the specified LOD.
        """
        StaticMeshTools._validate_lod_index(mesh, lod_index)
        return StaticMeshTools._smes().get_number_verts(mesh, lod_index)

    @toolset_registry.tool_call
    @staticmethod
    def get_bounds(mesh: unreal.StaticMesh) -> unreal.Box:
        """Returns the local-space bounding box of a static mesh.

        Args:
            mesh: The static mesh asset to query.

        Returns:
            The local-space axis-aligned bounding box.
        """
        return mesh.get_bounding_box()

    @toolset_registry.tool_call
    @staticmethod
    def get_material_slots(mesh: unreal.StaticMesh) -> list[str]:
        """Returns the names of all material slots in a static mesh.

        Material slot names are used when assigning materials to specific parts of
        the mesh. Use these names with get_material and set_material.

        Args:
            mesh: The static mesh asset to query.

        Returns:
            A list of material slot names.
        """
        return [str(mat.material_slot_name) for mat in mesh.static_materials]

    @toolset_registry.tool_call
    @staticmethod
    def get_material(mesh: unreal.StaticMesh, slot_name: str) -> unreal.MaterialInterface:
        """Returns the material assigned to a named slot on a static mesh.

        Args:
            mesh: The static mesh asset to query.
            slot_name: The name of the material slot to query.

        Returns:
            The material assigned to the slot.
        """
        slot_index = StaticMeshTools._get_material_slot_index(mesh, slot_name)
        material = mesh.get_material(slot_index)
        assert material, f'No material assigned to slot "{slot_name}" on {mesh.get_name()}.'
        return material

    @toolset_registry.tool_call
    @staticmethod
    def set_material(
            mesh: unreal.StaticMesh, slot_name: str,
            material: unreal.MaterialInterface) -> bool:
        """Assigns a material to a named slot on a static mesh asset.

        This affects all instances of the mesh that do not override the slot material.
        Use set_component_material_override to change materials on a single instance.

        Args:
            mesh: The static mesh asset to modify.
            slot_name: The name of the material slot to assign to.
            material: The material to assign.

        Returns:
            True if the material was assigned successfully.
        """
        slot_index = StaticMeshTools._get_material_slot_index(mesh, slot_name)
        mesh.modify()
        mesh.set_material(slot_index, material)
        return mesh.get_material(slot_index) == material

    @toolset_registry.tool_call
    @staticmethod
    def get_lod_thresholds(mesh: unreal.StaticMesh) -> list[float]:
        """Returns the screen-size thresholds at which each LOD becomes active.

        Screen size is a ratio of the mesh's screen height to the viewport height. A value
        of 1.0 means the mesh fills the full viewport height; values above 1.0 are valid and
        mean the mesh must appear larger than the viewport before the next LOD activates.
        Each LOD activates when the mesh appears smaller than its threshold.

        Args:
            mesh: The static mesh asset to query.

        Returns:
            A list of screen-size threshold values, one per LOD.
        """
        return list(StaticMeshTools._smes().get_lod_screen_sizes(mesh))

    @toolset_registry.tool_call
    @staticmethod
    def set_lod_thresholds(mesh: unreal.StaticMesh, thresholds: list[float]) -> bool:
        """Sets the screen-size thresholds at which each LOD becomes active.

        Screen size is a ratio of the mesh's screen height to the viewport height. A value
        of 1.0 means the mesh fills the full viewport height; values above 1.0 are valid and
        mean the mesh must appear larger than the viewport before the next LOD activates.
        Thresholds must be in strictly descending order (LOD 0 has the largest threshold),
        and there must be exactly one threshold per LOD.

        Args:
            mesh: The static mesh asset to modify.
            thresholds: Screen-size threshold values, one per LOD, in descending order.

        Returns:
            True if the thresholds were applied successfully.
        """
        smes = StaticMeshTools._smes()
        lod_count = smes.get_lod_count(mesh)
        if len(thresholds) != lod_count:
            raise ValueError(
                f'Expected {lod_count} threshold(s) (one per LOD), got {len(thresholds)}.')
        for i, t in enumerate(thresholds):
            if t <= 0.0:
                raise ValueError(
                    f'Threshold at index {i} must be greater than 0.0, got {t}.')
        for i in range(1, len(thresholds)):
            if thresholds[i] >= thresholds[i - 1]:
                raise ValueError(
                    f'Thresholds must be in strictly descending order. '
                    f'threshold[{i}]={thresholds[i]} is not less than '
                    f'threshold[{i - 1}]={thresholds[i - 1]}.')
        return smes.set_lod_screen_sizes(mesh, thresholds)

    @toolset_registry.tool_call
    @staticmethod
    def generate_lods(mesh: unreal.StaticMesh, triangle_percents: list[float]) -> int:
        """Auto-generates LODs for a static mesh using triangle reduction.

        Each entry in triangle_percents creates one additional LOD. The value is the
        fraction of triangles to keep relative to LOD 0, from just above 0.0 (nearly
        empty) to 1.0 (full detail). For example, [0.5, 0.25] creates LOD1 with 50%
        of the original triangles and LOD2 with 25%.

        Args:
            mesh: The static mesh asset to modify.
            triangle_percents: Triangle retention fraction for each generated LOD.

        Returns:
            The total number of LODs after the operation, including LOD 0.
        """
        StaticMeshTools._validate_triangle_percents(triangle_percents)
        # The reduction_settings array is 1-indexed: the first entry specifies LOD0
        # (base mesh, no reduction), and subsequent entries create LOD1, LOD2, etc.
        reduction_settings = unreal.Array(unreal.StaticMeshReductionSettings)
        for pct in [1.0, *triangle_percents]:
            setting = unreal.StaticMeshReductionSettings()
            setting.percent_triangles = pct
            reduction_settings.append(setting)
        options = unreal.StaticMeshReductionOptions()
        options.auto_compute_lod_screen_size = True
        options.reduction_settings = reduction_settings
        return StaticMeshTools._smes().set_lods(mesh, options)

    @toolset_registry.tool_call
    @staticmethod
    def remove_lods(mesh: unreal.StaticMesh) -> bool:
        """Removes all auto-generated LODs from a static mesh, keeping only LOD 0.

        Args:
            mesh: The static mesh asset to modify.

        Returns:
            True if LODs were removed successfully.
        """
        return StaticMeshTools._smes().remove_lods(mesh)

    @toolset_registry.tool_call
    @staticmethod
    def generate_convex_collisions(
            mesh: unreal.StaticMesh, hull_count: int = 4,
            max_hull_verts: int = 16, hull_precision: int = 100000) -> bool:
        """Generates convex hull collision shapes for a static mesh.

        Convex hulls provide accurate collision for physics simulation. More hulls
        improve accuracy but increase runtime cost. Replaces any existing collision.

        Args:
            mesh: The static mesh asset to modify.
            hull_count: The number of convex hulls to generate.
            max_hull_verts: The maximum number of vertices per hull.
            hull_precision: Controls the voxel precision of the decomposition.

        Returns:
            True if convex collision was generated successfully.
        """
        return StaticMeshTools._smes().set_convex_decomposition_collisions(
            mesh, hull_count, max_hull_verts, hull_precision)

    @toolset_registry.tool_call
    @staticmethod
    def remove_collisions(mesh: unreal.StaticMesh) -> bool:
        """Removes all collision shapes from a static mesh.

        Args:
            mesh: The static mesh asset to modify.

        Returns:
            True if all collision shapes were removed.
        """
        return StaticMeshTools._smes().remove_collisions(mesh)

    @toolset_registry.tool_call
    @staticmethod
    def is_nanite_enabled(mesh: unreal.StaticMesh) -> bool:
        """Returns whether Nanite is enabled for a static mesh.

        Nanite is Unreal's virtualized geometry system that renders highly detailed
        meshes efficiently. It is most beneficial for meshes with many triangles.

        Args:
            mesh: The static mesh asset to query.

        Returns:
            True if Nanite is enabled for this mesh.
        """
        return StaticMeshTools._smes().get_nanite_settings(mesh).enabled

    @toolset_registry.tool_call
    @staticmethod
    def set_nanite_enabled(mesh: unreal.StaticMesh, enabled: bool) -> None:
        """Enables or disables Nanite for a static mesh.

        Changing this setting triggers a mesh rebuild. Nanite is most beneficial for
        high-polygon meshes. Low-polygon meshes may not benefit from Nanite.

        Args:
            mesh: The static mesh asset to modify.
            enabled: True to enable Nanite, False to disable it.
        """
        smes = StaticMeshTools._smes()
        settings = smes.get_nanite_settings(mesh)
        settings.enabled = enabled
        smes.set_nanite_settings(mesh, settings)

    @staticmethod
    def _validate_triangle_percents(triangle_percents: list[float]) -> None:
        """Validates triangle reduction percentages for LOD generation.

        Args:
            triangle_percents: Triangle retention fractions to validate.
        """
        if len(triangle_percents) == 0:
            raise ValueError('triangle_percents must not be empty.')
        for pct in triangle_percents:
            if not 0.0 < pct <= 1.0:
                raise ValueError(
                    f'Triangle percent {pct} must be between 0.0 (exclusive) and 1.0 (inclusive).')

    @staticmethod
    def _get_material_slot_index(mesh: unreal.StaticMesh, slot_name: str) -> int:
        """Returns the index of a named material slot, raising an error if not found.

        Args:
            mesh: The static mesh to query.
            slot_name: The name of the material slot.

        Returns:
            The index of the material slot.
        """
        slot_index = mesh.get_material_index(slot_name)
        if slot_index < 0:
            raise ValueError(
                f'Material slot "{slot_name}" not found on {mesh.get_name()}.')
        return slot_index

    @staticmethod
    def _validate_lod_index(mesh: unreal.StaticMesh, lod_index: int) -> None:
        """Ensures that lod_index is valid for the given mesh.

        Args:
            mesh: The static mesh to validate against.
            lod_index: The LOD index to check.
        """
        lod_count = StaticMeshTools._smes().get_lod_count(mesh)
        if not 0 <= lod_index < lod_count:
            raise ValueError(
                f'LOD index {lod_index} is out of range. Mesh has {lod_count} LODs.')

    @staticmethod
    def _smes() -> unreal.StaticMeshEditorSubsystem:
        smes = unreal.get_editor_subsystem(unreal.StaticMeshEditorSubsystem)
        assert smes
        return smes
