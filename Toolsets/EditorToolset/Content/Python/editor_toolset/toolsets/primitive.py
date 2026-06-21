# Copyright Epic Games, Inc. All Rights Reserved.

from __future__ import annotations

import unreal

import toolset_registry
from editor_toolset.toolsets.actor import ActorTools


# Asset paths for UE's built-in primitive shapes.
_CUBE_ASSET = '/Engine/BasicShapes/Cube'
_SPHERE_ASSET = '/Engine/BasicShapes/Sphere'
_CYLINDER_ASSET = '/Engine/BasicShapes/Cylinder'
_CONE_ASSET = '/Engine/BasicShapes/Cone'


@unreal.uclass()
class PrimitiveTools(unreal.ToolsetDefinition):
    """Provides tools for adding primitive geometry components to actors."""

    @toolset_registry.tool_call
    @staticmethod
    def add_cube(
        actor: unreal.Actor, name: str,
        dimensions: unreal.Vector = unreal.Vector(100, 100, 100),
        local_transform: unreal.Transform | None = None) -> unreal.StaticMeshComponent:
        """Adds a cube-shaped StaticMeshComponent to an actor.

        Args:
            actor: The actor to add the component to.
            name: The name of the new component.
            dimensions: The x, y, and z size of the cube.
            local_transform: The transform of the component relative to the actor.

        Returns:
            The new StaticMeshComponent.
        """
        PrimitiveTools._validate_positive(
            **{'dimensions.x': dimensions.x, 'dimensions.y': dimensions.y,
               'dimensions.z': dimensions.z})
        mesh = PrimitiveTools._load_mesh(_CUBE_ASSET)
        box = mesh.get_bounding_box()
        default_size = unreal.Vector(
            box.max.x - box.min.x,
            box.max.y - box.min.y,
            box.max.z - box.min.z)
        scale = unreal.Vector(
            dimensions.x / default_size.x,
            dimensions.y / default_size.y,
            dimensions.z / default_size.z)
        return PrimitiveTools._add_static_mesh_component(actor, name, mesh, scale, local_transform)

    @toolset_registry.tool_call
    @staticmethod
    def add_sphere(
        actor: unreal.Actor, name: str, radius: float = 50,
        local_transform: unreal.Transform | None = None) -> unreal.StaticMeshComponent:
        """Adds a sphere-shaped StaticMeshComponent to an actor.

        Args:
            actor: The actor to add the component to.
            name: The name of the new component.
            radius: The radius of the sphere.
            local_transform: The transform of the component relative to the actor.

        Returns:
            The new StaticMeshComponent.
        """
        PrimitiveTools._validate_positive(radius=radius)
        mesh = PrimitiveTools._load_mesh(_SPHERE_ASSET)
        box = mesh.get_bounding_box()
        default_radius = (box.max.x - box.min.x) / 2
        s = radius / default_radius
        return PrimitiveTools._add_static_mesh_component(
            actor, name, mesh, unreal.Vector(s, s, s), local_transform)

    @toolset_registry.tool_call
    @staticmethod
    def add_cylinder(
        actor: unreal.Actor, name: str, radius: float = 50, height: float = 100,
        local_transform: unreal.Transform | None = None) -> unreal.StaticMeshComponent:
        """Adds a cylinder-shaped StaticMeshComponent to an actor.

        Args:
            actor: The actor to add the component to.
            name: The name of the new component.
            radius: The radius of the cylinder.
            height: The height of the cylinder.
            local_transform: The transform of the component relative to the actor.

        Returns:
            The new StaticMeshComponent.
        """
        PrimitiveTools._validate_positive(radius=radius, height=height)
        mesh = PrimitiveTools._load_mesh(_CYLINDER_ASSET)
        box = mesh.get_bounding_box()
        default_radius = (box.max.x - box.min.x) / 2
        default_height = box.max.z - box.min.z
        scale = unreal.Vector(
            radius / default_radius,
            radius / default_radius,
            height / default_height)
        return PrimitiveTools._add_static_mesh_component(actor, name, mesh, scale, local_transform)

    @toolset_registry.tool_call
    @staticmethod
    def add_cone(
        actor: unreal.Actor, name: str, radius: float = 50, height: float = 100,
        local_transform: unreal.Transform | None = None) -> unreal.StaticMeshComponent:
        """Adds a cone-shaped StaticMeshComponent to an actor.

        Args:
            actor: The actor to add the component to.
            name: The name of the new component.
            radius: The radius of the cone base.
            height: The height of the cone.
            local_transform: The transform of the component relative to the actor.

        Returns:
            The new StaticMeshComponent.
        """
        PrimitiveTools._validate_positive(radius=radius, height=height)
        mesh = PrimitiveTools._load_mesh(_CONE_ASSET)
        box = mesh.get_bounding_box()
        default_radius = (box.max.x - box.min.x) / 2
        default_height = box.max.z - box.min.z
        scale = unreal.Vector(
            radius / default_radius,
            radius / default_radius,
            height / default_height)
        return PrimitiveTools._add_static_mesh_component(actor, name, mesh, scale, local_transform)

    @staticmethod
    def _validate_positive(**kwargs: float) -> None:
        for param, value in kwargs.items():
            if value <= 0:
                raise ValueError(f'{param} must be positive, got {value}.')

    @staticmethod
    def _load_mesh(mesh_path: str) -> unreal.StaticMesh:
        mesh = unreal.load_asset(mesh_path)
        assert isinstance(mesh, unreal.StaticMesh), f'Failed to load {mesh_path}'
        return mesh

    @staticmethod
    def _add_static_mesh_component(
        actor: unreal.Actor, name: str, mesh: unreal.StaticMesh,
        param_scale: unreal.Vector,
        local_transform: unreal.Transform | None) -> unreal.StaticMeshComponent:
        if local_transform:
            ts = local_transform.scale3d
            PrimitiveTools._validate_positive(**{'scale.x': ts.x, 'scale.y': ts.y, 'scale.z': ts.z})
        smc = ActorTools.add_component(actor, unreal.StaticMeshComponent.static_class(), name)
        if not isinstance(smc, unreal.StaticMeshComponent):
            raise RuntimeError(f'Failed to add StaticMeshComponent to {actor}')
        smc.modify()
        smc.set_static_mesh(mesh)
        if local_transform:
            smc.set_relative_transform(local_transform, False, True)
        ts = local_transform.scale3d if local_transform else unreal.Vector(1, 1, 1)
        smc.set_relative_scale3d(unreal.Vector(
            param_scale.x * ts.x,
            param_scale.y * ts.y,
            param_scale.z * ts.z))
        return smc
