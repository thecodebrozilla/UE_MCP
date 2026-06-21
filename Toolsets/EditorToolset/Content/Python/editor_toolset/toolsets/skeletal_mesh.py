# Copyright Epic Games, Inc. All Rights Reserved.

import unreal

import toolset_registry
from editor_toolset.toolsets.asset import import_asset


@unreal.uclass()
class SkeletalMeshTools(unreal.ToolsetDefinition):
    """Provides tools for inspecting and modifying skeletal mesh assets, including
    the mesh/materials, bone hierarchies, and sockets."""

    @toolset_registry.tool_call
    @staticmethod
    def import_file(
            folder_path: str, asset_name: str, source_file: str,
            skeleton: unreal.Skeleton | None = None,
            import_materials: bool = False,
            import_textures: bool = False,
            import_animations: bool = False,
            create_physics_asset: bool = False) -> list[unreal.Object]:
        """Imports a mesh file from disk as a SkeletalMesh asset.

        The source file must contain a skeleton hierarchy and skinned mesh data.

        Args:
            folder_path: The content-browser folder to create the asset in.
            asset_name: The name of the new asset.
            source_file: The absolute path to the source mesh file on disk.
            skeleton: An existing skeleton to bind the imported mesh to. When
                None, a new Skeleton asset is created alongside the mesh.
            import_materials: When True, create Material assets for any materials
                referenced in the file. When False, the imported mesh has no
                materials assigned.
            import_textures: When True, create Texture2D assets for any textures
                referenced by the imported materials. Only effective when
                import_materials is True.
            import_animations: When True, create AnimSequence assets for any
                animations contained in the file.
            create_physics_asset: When True, create a PhysicsAsset bound to the
                imported mesh's skeleton.

        Returns:
            The assets produced by the import. The first entry is the imported
            SkeletalMesh; additional entries may include a newly created
            Skeleton (when none was supplied), a PhysicsAsset, AnimSequences,
            Materials, and Texture2Ds, depending on which options are enabled.
        """
        options = unreal.FbxImportUI()
        options.automated_import_should_detect_type = False
        options.import_mesh = True
        options.import_as_skeletal = True
        options.mesh_type_to_import = unreal.FBXImportType.FBXIT_SKELETAL_MESH
        options.original_import_type = unreal.FBXImportType.FBXIT_SKELETAL_MESH
        options.import_materials = import_materials
        options.import_textures = import_textures
        options.import_animations = import_animations
        options.create_physics_asset = create_physics_asset
        if skeleton is not None:
            options.skeleton = skeleton
        return import_asset(
            folder_path, asset_name, source_file,
            options=options, factory=unreal.FbxFactory())

    @toolset_registry.tool_call
    @staticmethod
    def get_lod_count(mesh: unreal.SkeletalMesh) -> int:
        """Returns the number of LODs in a skeletal mesh asset.

        Args:
            mesh: The skeletal mesh asset to query.

        Returns:
            The number of LODs.
        """
        return SkeletalMeshTools._smes().get_lod_count(mesh)

    @toolset_registry.tool_call
    @staticmethod
    def get_vertex_count(mesh: unreal.SkeletalMesh, lod_index: int = 0) -> int:
        """Returns the number of vertices in a specific LOD of a skeletal mesh.

        Args:
            mesh: The skeletal mesh asset to query.
            lod_index: The LOD index to query. Defaults to 0 (highest quality).

        Returns:
            The number of vertices in the specified LOD.
        """
        SkeletalMeshTools._validate_lod_index(mesh, lod_index)
        return SkeletalMeshTools._smes().get_num_verts(mesh, lod_index)

    @toolset_registry.tool_call
    @staticmethod
    def get_section_count(mesh: unreal.SkeletalMesh, lod_index: int = 0) -> int:
        """Returns the number of sections in a specific LOD of a skeletal mesh.

        Sections correspond to individual material slots rendered by a single draw call.
        A mesh may have more sections than material slots if multiple sections share
        the same material.

        Args:
            mesh: The skeletal mesh asset to query.
            lod_index: The LOD index to query. Defaults to 0 (highest quality).

        Returns:
            The number of sections in the specified LOD.
        """
        SkeletalMeshTools._validate_lod_index(mesh, lod_index)
        return SkeletalMeshTools._smes().get_num_sections(mesh, lod_index)

    @toolset_registry.tool_call
    @staticmethod
    def get_bounds(mesh: unreal.SkeletalMesh) -> unreal.BoxSphereBounds:
        """Returns the local-space bounding volume of a skeletal mesh.

        The bounds represent the reference pose and do not account for animation.

        Args:
            mesh: The skeletal mesh asset to query.

        Returns:
            The local-space bounding volume as a combined box and sphere.
        """
        return mesh.get_bounds()

    @toolset_registry.tool_call
    @staticmethod
    def get_skeleton(mesh: unreal.SkeletalMesh) -> unreal.Skeleton:
        """Returns the skeleton asset associated with a skeletal mesh.

        The skeleton defines the bone hierarchy shared across all meshes and
        animations that use it.

        Args:
            mesh: The skeletal mesh asset to query.

        Returns:
            The skeleton asset bound to this mesh.
        """
        skeleton = mesh.skeleton
        assert skeleton, f'{mesh.get_name()} has no skeleton assigned.'
        return skeleton

    @toolset_registry.tool_call
    @staticmethod
    def get_bone_names(mesh: unreal.SkeletalMesh) -> list[str]:
        """Returns the names of all bones in a skeletal mesh in hierarchy order.

        Bone names are used to target specific bones for socket attachment, physics
        constraints, and animation retargeting.

        Args:
            mesh: The skeletal mesh asset to query.

        Returns:
            A list of bone names in skeleton order (root first).
        """
        skeleton = mesh.skeleton
        assert skeleton, f'{mesh.get_name()} has no skeleton assigned.'
        return [str(n) for n in skeleton.get_reference_pose().get_bone_names()]

    @toolset_registry.tool_call
    @staticmethod
    def get_bone_parent(mesh: unreal.SkeletalMesh, bone_name: str) -> str:
        """Returns the name of a bone's parent, or an empty string for the root bone.

        Args:
            mesh: The skeletal mesh asset to query.
            bone_name: The name of the bone to query.

        Returns:
            The parent bone name, or '' if the bone is the root.
        """
        SkeletalMeshTools._validate_bone_name(mesh, bone_name)
        parent = SkeletalMeshTools._smes().get_bone_parent(mesh, bone_name)
        return str(parent) if str(parent) != 'None' else ''

    @toolset_registry.tool_call
    @staticmethod
    def get_bone_children(mesh: unreal.SkeletalMesh, bone_name: str) -> list[str]:
        """Returns the direct children of a bone.

        Args:
            mesh: The skeletal mesh asset to query.
            bone_name: The name of the bone to query.

        Returns:
            A list of direct child bone names, or an empty list for leaf bones.
        """
        SkeletalMeshTools._validate_bone_name(mesh, bone_name)
        return [str(n) for n in SkeletalMeshTools._smes().get_bone_children(mesh, bone_name)]

    @toolset_registry.tool_call
    @staticmethod
    def get_material_slots(mesh: unreal.SkeletalMesh) -> list[str]:
        """Returns the names of all material slots in a skeletal mesh.

        Material slot names are used when assigning materials to specific parts of
        the mesh. Use these names with get_material and set_material.

        Args:
            mesh: The skeletal mesh asset to query.

        Returns:
            A list of material slot names.
        """
        return [str(mat.material_slot_name) for mat in mesh.materials]

    @toolset_registry.tool_call
    @staticmethod
    def get_material(
            mesh: unreal.SkeletalMesh, slot_name: str) -> unreal.MaterialInterface:
        """Returns the material assigned to a named slot on a skeletal mesh.

        Args:
            mesh: The skeletal mesh asset to query.
            slot_name: The name of the material slot to query.

        Returns:
            The material assigned to the slot.
        """
        slot_index = SkeletalMeshTools._get_material_slot_index(mesh, slot_name)
        material = mesh.materials[slot_index].material_interface
        assert material, f'No material assigned to slot "{slot_name}" on {mesh.get_name()}.'
        return material

    @toolset_registry.tool_call
    @staticmethod
    def set_material(
            mesh: unreal.SkeletalMesh, slot_name: str,
            material: unreal.MaterialInterface) -> bool:
        """Assigns a material to a named slot on a skeletal mesh asset.

        This affects all instances of the mesh that do not override the slot material.

        Args:
            mesh: The skeletal mesh asset to modify.
            slot_name: The name of the material slot to assign to.
            material: The material to assign.

        Returns:
            True if the material was assigned successfully.
        """
        slot_index = SkeletalMeshTools._get_material_slot_index(mesh, slot_name)
        mesh.modify()
        old = mesh.materials[slot_index]
        new_slot = unreal.SkeletalMaterial(
            material_interface=material,
            material_slot_name=old.material_slot_name,
            uv_channel_data=old.uv_channel_data)
        materials = list(mesh.materials)
        materials[slot_index] = new_slot
        mesh.materials = materials
        return mesh.materials[slot_index].material_interface == material

    @toolset_registry.tool_call
    @staticmethod
    def get_physics_asset(mesh: unreal.SkeletalMesh) -> unreal.PhysicsAsset:
        """Returns the physics asset assigned to a skeletal mesh.

        The physics asset defines the collision bodies and constraints used for
        ragdoll simulation and per-bone physics.

        Args:
            mesh: The skeletal mesh asset to query.

        Returns:
            The physics asset assigned to this mesh.
        """
        physics_asset = mesh.physics_asset
        if not physics_asset:
            raise RuntimeError(f'{mesh} has no physics asset assigned.')
        return physics_asset

    @toolset_registry.tool_call
    @staticmethod
    def assign_physics_asset(
            mesh: unreal.SkeletalMesh,
            physics_asset: unreal.PhysicsAsset) -> bool:
        """Assigns a physics asset to a skeletal mesh.

        The physics asset must be compatible with the mesh's skeleton. Use this
        to swap physics assets or assign one to a mesh that has none.

        Args:
            mesh: The skeletal mesh asset to modify.
            physics_asset: The physics asset to assign.

        Returns:
            True if the physics asset was assigned successfully.
        """
        return SkeletalMeshTools._smes().assign_physics_asset(mesh, physics_asset)

    @toolset_registry.tool_call
    @staticmethod
    def get_morph_target_names(mesh: unreal.SkeletalMesh) -> list[str]:
        """Returns the names of all morph targets on a skeletal mesh.

        Morph targets (blend shapes) are per-vertex offsets used to deform the mesh,
        commonly used for facial expressions and cloth simulation.

        Args:
            mesh: The skeletal mesh asset to query.

        Returns:
            A list of morph target names, or an empty list if none exist.
        """
        return list(mesh.get_all_morph_target_names())

    @toolset_registry.tool_call
    @staticmethod
    def add_socket(
            mesh: unreal.SkeletalMesh, socket_name: str,
            bone_name: str) -> unreal.SkeletalMeshSocket:
        """Adds a named socket to a skeletal mesh attached to a bone.

        Sockets are named attachment points used to attach weapons, accessories,
        or effects at a consistent position relative to a bone.

        Args:
            mesh: The skeletal mesh asset to modify.
            socket_name: The name to give the new socket.
            bone_name: The name of the bone to attach the socket to.

        Returns:
            The newly created socket.
        """
        SkeletalMeshTools._validate_bone_name(mesh, bone_name)
        # socket_name and bone_name are read-only from Python. We work around this by:
        # 1. Creating with outer=mesh so add_socket accepts the object.
        # 2. Using set_socket_parent to set the bone (C++ API that bypasses read-only).
        # 3. Adding to the mesh (socket has no name yet; UE leaves SocketName as NAME_None).
        # 4. Using rename_socket to assign the desired name (FName("None") == NAME_None).
        new_socket = unreal.new_object(unreal.SkeletalMeshSocket, outer=mesh)
        new_socket.set_socket_parent(mesh, bone_name)
        mesh.modify()
        prev_socket_names = set(SkeletalMeshTools.get_socket_names(mesh))
        mesh.add_socket(new_socket, False)
        new_socket_names = set(SkeletalMeshTools.get_socket_names(mesh))
        assert len(new_socket_names) == len(prev_socket_names) + 1, (
            f'Failed to add socket "{socket_name}" to {mesh}.')
        added_names = new_socket_names.difference(prev_socket_names)
        added_name = list(added_names)[0]
        if not SkeletalMeshTools._smes().rename_socket(mesh, added_name, socket_name):
            raise RuntimeError(f'Unable to rename {added_name} to {socket_name}')
        result = mesh.find_socket(socket_name)
        assert result, f'Socket "{socket_name}" not found after adding to {mesh.get_name()}.'
        return result

    @toolset_registry.tool_call
    @staticmethod
    def get_socket_names(mesh: unreal.SkeletalMesh) -> list[str]:
        """Returns the names of all sockets on a skeletal mesh.

        Sockets are named attachment points parented to bones. They are used to
        attach weapons, accessories, or effects at a consistent location.

        Args:
            mesh: The skeletal mesh asset to query.

        Returns:
            A list of socket names, or an empty list if none exist.
        """
        return [str(mesh.get_socket_by_index(i).socket_name)
                for i in range(mesh.num_sockets())]

    @toolset_registry.tool_call
    @staticmethod
    def get_socket_bone(mesh: unreal.SkeletalMesh, socket_name: str) -> str:
        """Returns the name of the bone that a socket is attached to.

        Args:
            mesh: The skeletal mesh asset to query.
            socket_name: The name of the socket to query.

        Returns:
            The name of the parent bone.
        """
        socket = SkeletalMeshTools._find_socket(mesh, socket_name)
        return str(socket.bone_name)

    @toolset_registry.tool_call
    @staticmethod
    def get_socket_transform(
            mesh: unreal.SkeletalMesh, socket_name: str) -> unreal.Transform:
        """Returns the local transform of a socket relative to its parent bone.

        Args:
            mesh: The skeletal mesh asset to query.
            socket_name: The name of the socket to query.

        Returns:
            The socket's local transform (translation, rotation, scale).
        """
        socket = SkeletalMeshTools._find_socket(mesh, socket_name)
        transform = unreal.Transform()
        transform.translation = socket.relative_location
        transform.rotation = socket.relative_rotation.quaternion()
        transform.scale3d = socket.relative_scale
        return transform

    @toolset_registry.tool_call
    @staticmethod
    def set_socket_transform(
            mesh: unreal.SkeletalMesh, socket_name: str,
            transform: unreal.Transform) -> None:
        """Sets the local transform of a socket relative to its parent bone.

        Args:
            mesh: The skeletal mesh asset to modify.
            socket_name: The name of the socket to modify.
            transform: The new local transform for the socket.
        """
        socket = SkeletalMeshTools._find_socket(mesh, socket_name)
        socket.set_socket_local_transform(transform)

    @toolset_registry.tool_call
    @staticmethod
    def remove_socket(mesh: unreal.SkeletalMesh, socket_name: str) -> bool:
        """Removes a named socket from a skeletal mesh.

        Args:
            mesh: The skeletal mesh asset to modify.
            socket_name: The name of the socket to remove.

        Returns:
            True if the socket was removed successfully.
        """
        SkeletalMeshTools._find_socket(mesh, socket_name)
        return SkeletalMeshTools._smes().remove_socket(mesh, socket_name)

    @toolset_registry.tool_call
    @staticmethod
    def rename_socket(
            mesh: unreal.SkeletalMesh, old_name: str, new_name: str) -> bool:
        """Renames a socket on a skeletal mesh.

        Args:
            mesh: The skeletal mesh asset to modify.
            old_name: The current name of the socket.
            new_name: The new name to give the socket.

        Returns:
            True if the socket was renamed successfully.
        """
        SkeletalMeshTools._find_socket(mesh, old_name)
        return SkeletalMeshTools._smes().rename_socket(mesh, old_name, new_name)

    @staticmethod
    def _smes() -> unreal.SkeletalMeshEditorSubsystem:
        smes = unreal.get_editor_subsystem(unreal.SkeletalMeshEditorSubsystem)
        assert smes
        return smes

    @staticmethod
    def _validate_lod_index(mesh: unreal.SkeletalMesh, lod_index: int) -> None:
        """Ensures that lod_index is valid for the given mesh.

        Args:
            mesh: The skeletal mesh to validate against.
            lod_index: The LOD index to check.
        """
        lod_count = SkeletalMeshTools._smes().get_lod_count(mesh)
        if not 0 <= lod_index < lod_count:
            raise ValueError(
                f'LOD index {lod_index} is out of range. Mesh has {lod_count} LODs.')

    @staticmethod
    def _get_material_slot_index(mesh: unreal.SkeletalMesh, slot_name: str) -> int:
        """Returns the index of a named material slot, raising an error if not found.

        Args:
            mesh: The skeletal mesh to query.
            slot_name: The name of the material slot.

        Returns:
            The index of the material slot.
        """
        for i, mat in enumerate(mesh.materials):
            if str(mat.material_slot_name) == slot_name:
                return i
        raise ValueError(
            f'Material slot "{slot_name}" not found on {mesh.get_name()}.')

    @staticmethod
    def _validate_bone_name(mesh: unreal.SkeletalMesh, bone_name: str) -> None:
        """Raises ValueError if bone_name does not exist in the mesh's skeleton.

        Args:
            mesh: The skeletal mesh to validate against.
            bone_name: The bone name to check.
        """
        if bone_name not in SkeletalMeshTools.get_bone_names(mesh):
            raise ValueError(f'Bone "{bone_name}" not found on {mesh.get_name()}.')

    @staticmethod
    def _find_socket(
            mesh: unreal.SkeletalMesh, socket_name: str) -> unreal.SkeletalMeshSocket:
        """Returns the socket with the given name, raising an error if not found.

        Args:
            mesh: The skeletal mesh to query.
            socket_name: The name of the socket.

        Returns:
            The socket object.
        """
        socket = mesh.find_socket(socket_name)
        if not socket:
            raise ValueError(f'Socket "{socket_name}" not found on {mesh.get_name()}.')
        return socket
