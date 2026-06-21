# Copyright Epic Games, Inc. All Rights Reserved.

import unreal

import toolset_registry
from editor_toolset.toolsets.blueprint import BlueprintTools
from toolset_registry.helpers import require_editable


@unreal.uclass()
class ActorTools(unreal.ToolsetDefinition):
    """Provides tools for inspecting and modifying actors, including
    their transforms, labels, parent-child relationships, and components."""

    @toolset_registry.tool_call
    @staticmethod
    def get_label(actor: unreal.Actor) -> str:
        """Returns the actor's human friendly name as it appears in the editor.

        Args:
            actor: The actor to query.

        Returns:
            The label for the actor.
        """
        return actor.get_actor_label()

    @toolset_registry.tool_call
    @staticmethod
    def set_label(actor: unreal.Actor, label: str) -> bool:
        """Sets the human-friendly name of the actor.

        Args:
            actor: The actor to modify.
            label: The new name for the actor.

        Returns:
            True if the label was updated correctly.
        """
        require_editable(actor)
        actor.set_actor_label(label)
        return actor.get_actor_label() == label

    @toolset_registry.tool_call
    @staticmethod
    def get_tags(actor: unreal.Actor) -> list[str]:
        """Returns the list of tags on an actor.

        Args:
            actor: The actor to query.

        Returns:
            The tags on the actor as strings.
        """
        return [str(tag) for tag in actor.tags]

    @toolset_registry.tool_call
    @staticmethod
    def has_tag(actor: unreal.Actor, tag: str) -> bool:
        """Returns whether an actor has a specific tag.

        Args:
            actor: The actor to query.
            tag: The tag to check for.

        Returns:
            True if the actor has the tag, False otherwise.
        """
        return actor.actor_has_tag(unreal.Name(tag))

    @toolset_registry.tool_call
    @staticmethod
    def add_tag(actor: unreal.Actor, tag: str) -> None:
        """Adds a tag to an actor.

        Args:
            actor: The actor to modify.
            tag: The tag to add.
        """
        require_editable(actor)
        if actor.actor_has_tag(unreal.Name(tag)):
            raise ValueError(f'Actor "{actor.get_actor_label()}" already has tag "{tag}".')
        actor.modify()
        tags = list(actor.tags)
        tags.append(unreal.Name(tag))
        actor.tags = tags

    @toolset_registry.tool_call
    @staticmethod
    def remove_tag(actor: unreal.Actor, tag: str) -> None:
        """Removes a tag from an actor.

        Args:
            actor: The actor to modify.
            tag: The tag to remove.
        """
        require_editable(actor)
        if not actor.actor_has_tag(unreal.Name(tag)):
            raise ValueError(f'Actor "{actor.get_actor_label()}" does not have tag "{tag}".')
        actor.modify()
        tag_name = unreal.Name(tag)
        actor.tags = [t for t in actor.tags if t != tag_name]

    @toolset_registry.tool_call
    @staticmethod
    def get_actor_transform(actor: unreal.Actor) -> unreal.Transform:
        """Returns the position, rotation, and scale of an actor.

        Args:
            actor: The actor to query.

        Returns:
            The world space actor transform.
        """
        if unreal.BlueprintEditorLibrary.get_blueprint_asset(actor.get_outer()):
            root = ActorTools.get_root_component(actor)
            return root.get_relative_transform() if root else unreal.Transform()
        return actor.get_actor_transform()

    @toolset_registry.tool_call
    @staticmethod
    def set_actor_transform(
        actor: unreal.Actor, xform: unreal.Transform, worldspace: bool = True) -> bool:
        """Updates the position, rotation, and/or scale of an actor.

        Args:
            actor: The actor to modify.
            xform: The new transform to apply to this actor.
            worldspace: True means xform is in worldpace. False means relative to parent.
                Has no effect on actors in blueprints, which only have a default
                relative transform.

        Returns:
            True if an id matching the actor was found and it's position was set.
        """
        require_editable(actor)
        blueprint = unreal.BlueprintEditorLibrary.get_blueprint_asset(actor.get_outer())
        if blueprint:
            root = ActorTools.get_root_component(actor)
            if root:
                root.modify()
                root.set_relative_transform(xform, False, True)
                BlueprintTools.compile_blueprint(blueprint)
            return True
        root = actor.root_component
        if root:
            root.modify()
        if worldspace:
            actor.set_actor_transform(xform, False, True)
        else:
            actor.set_actor_relative_transform(xform, False, True)
        return True

    @toolset_registry.tool_call
    @staticmethod
    def look_at(actor: unreal.Actor, target: unreal.Vector) -> None:
        """Rotates an actor so its forward vector points at a world-space position.

        Args:
            actor: The actor to rotate.
            target: The world-space position to face.
        """
        require_editable(actor)
        blueprint = unreal.BlueprintEditorLibrary.get_blueprint_asset(actor.get_outer())
        if blueprint:
            root = ActorTools.get_root_component(actor)
            if not root:
                return
            rotation = unreal.MathLibrary.find_look_at_rotation(
                root.relative_location, target)
            root.modify()
            root.set_relative_rotation(rotation, False, True)
            BlueprintTools.compile_blueprint(blueprint)
            return
        rotation = unreal.MathLibrary.find_look_at_rotation(
            actor.get_actor_location(), target)
        root = actor.root_component
        if root:
            root.modify()
        actor.set_actor_rotation(rotation, True)

    @toolset_registry.tool_call
    @staticmethod
    def get_root_component(actor: unreal.Actor) -> unreal.SceneComponent | None:
        """Returns the root component of an actor, if any.

        Args:
            actor: The actor to query.

        Returns:
            The actor's root SceneComponent, or None if it has no root component.
        """
        root = actor.root_component
        if root:
            return root
        # For blueprint CDOs, root_component may return None; fall back to SDS.
        blueprint = unreal.BlueprintEditorLibrary.get_blueprint_asset(actor.get_outer())
        if not blueprint:
            return None
        sds = ActorTools._sds()
        for so_handle in ActorTools._get_subobject_handles(sds, actor, blueprint):
            so_data = unreal.SubobjectDataBlueprintFunctionLibrary.get_data(so_handle)
            if unreal.SubobjectDataBlueprintFunctionLibrary.is_root_component(so_data):
                obj = unreal.SubobjectDataBlueprintFunctionLibrary.get_associated_object(so_data)
                return obj if isinstance(obj, unreal.SceneComponent) else None
        return None

    @toolset_registry.tool_call
    @staticmethod
    def get_component_actor(component: unreal.ActorComponent) -> unreal.Actor:
        """Returns the actor that owns the specified component.

        Args:
            component: The component to query.

        Returns:
            The actor that owns this component.
        """
        _, actor = ActorTools._blueprint_and_actor_for_component(component)
        if not actor:
            raise RuntimeError(f'Could not determine owning actor for {component}.')
        return actor

    @toolset_registry.tool_call
    @staticmethod
    def get_parent_component(component: unreal.SceneComponent) -> unreal.SceneComponent | None:
        """Returns the parent component that this component is attached to, if any.

        Args:
            component: The scene component to query.

        Returns:
            The parent SceneComponent if attached to one, otherwise None.
        """
        blueprint, actor = ActorTools._blueprint_and_actor_for_component(component)
        if not blueprint:
            return component.get_attach_parent()
        sds = ActorTools._sds()
        for so_handle in ActorTools._get_subobject_handles(sds, actor, blueprint):
            so_data = unreal.SubobjectDataBlueprintFunctionLibrary.get_data(so_handle)
            obj = unreal.SubobjectDataBlueprintFunctionLibrary.get_associated_object(so_data)
            if obj != component:
                continue
            parent_handle = unreal.SubobjectDataBlueprintFunctionLibrary.get_parent_handle(so_data)
            if not unreal.SubobjectDataBlueprintFunctionLibrary.is_handle_valid(parent_handle):
                return None
            parent_data = unreal.SubobjectDataBlueprintFunctionLibrary.get_data(parent_handle)
            if unreal.SubobjectDataBlueprintFunctionLibrary.is_actor(parent_data):
                return None
            parent_obj = unreal.SubobjectDataBlueprintFunctionLibrary.get_associated_object(
                parent_data)
            return parent_obj if isinstance(parent_obj, unreal.SceneComponent) else None
        return None

    @toolset_registry.tool_call
    @staticmethod
    def set_parent_component(
        component: unreal.SceneComponent, parent: unreal.SceneComponent | None = None) -> bool:
        """Sets the parent for the specified scene component.

        For blueprint actors, passing a component as the parent of the root promotes it
        to the scene root, making the current root a child of it. If the current root is a
        DefaultSceneRoot, Unreal will automatically remove it.

        Args:
            component: The scene component to modify.
            parent: The new parent component. None will detach the component from its current parent.

        Returns:
            True if the reparent succeeded.
        """
        require_editable(component)
        blueprint, actor = ActorTools._blueprint_and_actor_for_component(component)
        if not blueprint:
            # Attaching our root to another actor's component is valid (actor attachment).
            # Reparenting root to a component within the same actor is not supported.
            if (parent and actor and actor.root_component == component
                    and parent.get_outer() == actor):
                raise RuntimeError(
                    'Cannot reparent the root component of a scene instance actor. '
                    'To change the root component, use a blueprint actor.')
            component.modify()
            if not parent:
                component.detach_from_component(
                    unreal.DetachmentRule.KEEP_WORLD, unreal.DetachmentRule.KEEP_WORLD,
                    unreal.DetachmentRule.KEEP_WORLD)
                return True
            return component.attach_to_component(
                parent, unreal.Name(), unreal.AttachmentRule.KEEP_WORLD,
                unreal.AttachmentRule.KEEP_WORLD, unreal.AttachmentRule.KEEP_WORLD)
        # Component is in a blueprint
        if not parent:
            raise ValueError(f'{component} is in a blueprint and cannot be parented to the world.')
        if component == parent:
            raise ValueError(f'Cannot parent {component} to itself.')
        sds = ActorTools._sds()
        actor_handle = None
        component_handle = None
        component_is_root = False
        parent_handle = None
        for so_handle in ActorTools._get_subobject_handles(sds, actor, blueprint):
            so_data = unreal.SubobjectDataBlueprintFunctionLibrary.get_data(so_handle)
            if unreal.SubobjectDataBlueprintFunctionLibrary.is_actor(so_data):
                actor_handle = so_handle
                continue
            obj = unreal.SubobjectDataBlueprintFunctionLibrary.get_associated_object(so_data)
            if obj == component:
                component_handle = so_handle
                component_is_root = (
                    unreal.SubobjectDataBlueprintFunctionLibrary.is_root_component(so_data))
            elif obj == parent:
                parent_handle = so_handle
        if not actor_handle:
            raise RuntimeError(f'Could not find actor handle for {actor}.')
        if not component_handle:
            raise RuntimeError(f'Could not find subobject handle for {component}.')
        if not parent_handle:
            raise RuntimeError(
                f'{parent} is not a component of the same blueprint. '
                f'Blueprint components can only be parented within the same blueprint.')
        # MakeNewSceneRoot only promotes a component to be the new scene root; it
        # cannot reparent arbitrary components. Dispatch by which side is moving.
        if component_is_root:
            return sds.make_new_scene_root(actor_handle, parent_handle, blueprint)
        params = unreal.ReparentSubobjectParams()
        params.new_parent_handle = parent_handle
        params.blueprint_context = blueprint
        params.actor_preview_context = actor
        return sds.reparent_subobject(params, component_handle)

    @toolset_registry.tool_call
    @staticmethod
    def get_actor_bounds(actor: unreal.Actor) -> unreal.Box:
        """Returns the bounding box of an actor.

        Args:
            actor: The actor to query.

        Returns:
            The world space bounding box for the actor.
        """
        origin, extent = actor.get_actor_bounds(False)
        assert isinstance(origin, unreal.Vector) and isinstance(extent, unreal.Vector)
        return unreal.Box(origin.subtract(extent), origin.add(extent))

    @toolset_registry.tool_call
    @staticmethod
    def get_components(actor: unreal.Actor, component_type: unreal.Class | None = None) -> (
        list[unreal.ActorComponent]):
        """Returns the components that an actor contains.

        Args:
            actor: The actor to query.
            component_type: If set, will only return components of this type.

        Returns:
            The components in the actor.
        """
        blueprint = unreal.BlueprintEditorLibrary.get_blueprint_asset(actor.get_outer())
        if not blueprint:
            component_class = component_type if component_type else unreal.ActorComponent
            return actor.get_components_by_class(component_class)

        # For blueprint actors, get_components_by_class returns nothing, so we must
        # enumerate subobjects via the SubobjectDataSubsystem instead.
        filter_class = component_type if component_type else unreal.ActorComponent.static_class()
        sds = ActorTools._sds()
        seen = set()
        components = []
        for so_handle in ActorTools._get_subobject_handles(sds, actor, blueprint):
            so_data = unreal.SubobjectDataBlueprintFunctionLibrary.get_data(so_handle)
            if unreal.SubobjectDataBlueprintFunctionLibrary.is_actor(so_data):
                continue
            obj = unreal.SubobjectDataBlueprintFunctionLibrary.get_associated_object(so_data)
            if (isinstance(obj, unreal.ActorComponent) and
                    unreal.MathLibrary.class_is_child_of(obj.get_class(), filter_class) and
                    id(obj) not in seen):
                seen.add(id(obj))
                components.append(obj)
        return components

    @toolset_registry.tool_call
    @staticmethod
    def add_component(
        owner: unreal.Object, component_type: unreal.Class, name: str) -> unreal.ActorComponent:
        """Adds a component to an actor instance or blueprint.

        Args:
            owner: The actor blueprint, instance, or SceneComponent to add to.
            component_type: The type of component to add.
            name: The name of the new component.

        Returns:
            The newly added actor component.
        """
        require_editable(owner)
        assert unreal.MathLibrary.class_is_child_of(
            component_type, unreal.ActorComponent.static_class()), (
                f'{component_type} is not an ActorComponent.')

        # Extract the actor, blueprint, and component objects from
        # the passed in owner, which could be an Actor, Blueprint, or SceneComponent.
        # If Blueprint is null it means we are dealing with a scene instance.
        actor: unreal.Actor
        blueprint: unreal.Blueprint | None = None
        parent_component: unreal.SceneComponent | None = None
        if isinstance(owner, unreal.SceneComponent):
            blueprint = unreal.BlueprintEditorLibrary.get_blueprint_asset(owner.get_outer())
            actor = owner.get_outer()
            if not blueprint:
                assert isinstance(actor, unreal.Actor), f'{owner} is not an Actor instance.'
            parent_component = owner
        elif isinstance(owner, unreal.Actor):
            blueprint = unreal.BlueprintEditorLibrary.get_blueprint_asset(owner.get_outer())
            actor = owner
        elif isinstance(owner, unreal.Blueprint):
            blueprint = owner
            actor = BlueprintTools.get_default_object(blueprint)
            if not isinstance(actor, unreal.Actor):
                raise RuntimeError(f'{owner} is not an Actor Blueprint.')
        else:
            raise RuntimeError(f'{owner} is not an Actor, Blueprint, or SceneComponent.')

        # Get SubobjectDataHandles to the actor and the component we will attach to.
        actor_handle: unreal.SubobjectDataHandle | None = None
        parent_handle: unreal.SubobjectDataHandle | None = None
        sds = ActorTools._sds()
        for so_handle in ActorTools._get_subobject_handles(sds, actor, blueprint):
            so_data = unreal.SubobjectDataBlueprintFunctionLibrary.get_data(so_handle)
            if (parent_component and
                unreal.SubobjectDataBlueprintFunctionLibrary.get_associated_object(so_data) == parent_component):
                parent_handle = so_handle
            elif (not parent_component and
                  unreal.SubobjectDataBlueprintFunctionLibrary.is_root_component(so_data)):
                parent_handle = so_handle
            elif unreal.SubobjectDataBlueprintFunctionLibrary.is_actor(so_data):
                actor_handle = so_handle
            if parent_handle and actor_handle:
                break

        # Determine if we are attaching to an actor or a component.
        base_handle: unreal.SubobjectDataHandle | None = None
        if unreal.MathLibrary.class_is_child_of(
            component_type, unreal.SceneComponent.static_class()):
            # If adding a SceneComponent, we have to attach to a pre-existing SceneComponent,
            # so we add a root component if need be.
            if not parent_handle:
                parent_handle, error_text = sds.add_new_subobject(unreal.AddNewSubobjectParams(
                    parent_handle=actor_handle,
                    new_class=unreal.SceneComponent.static_class(),
                    blueprint_context=blueprint
                ))
                assert not error_text, error_text
                sds.rename_subobject(handle=parent_handle, new_name=unreal.Text('DefaultSceneRoot'))
            base_handle = parent_handle
        else:
            base_handle = actor_handle
        assert base_handle

        # Now, create the new component sub-object, which will be attached either to
        # the actor or a component in the actor, and will either modify the scene
        # instance or the blueprint.
        new_component_handle, failure_reason = sds.add_new_subobject(
            unreal.AddNewSubobjectParams(base_handle, component_type, blueprint))
        assert failure_reason.is_empty(), failure_reason
        sds.rename_subobject(handle=new_component_handle, new_name=unreal.Text(name))

        if blueprint:
            BlueprintTools.compile_blueprint(blueprint)

        new_component_data = unreal.SubobjectDataBlueprintFunctionLibrary.get_data(
            new_component_handle)
        return unreal.SubobjectDataBlueprintFunctionLibrary.get_associated_object(
            new_component_data)

    @toolset_registry.tool_call
    @staticmethod
    def remove_component(component: unreal.ActorComponent) -> bool:
        """Removes a component from an actor instance or blueprint.

        Args:
            component: The component to remove.

        Returns:
            True if the component was successfully removed.
        """
        require_editable(component)
        outer = component.get_outer()
        blueprint: unreal.Blueprint | None = None
        actor: unreal.Actor
        if isinstance(outer, unreal.Actor):
            actor = outer
            blueprint = unreal.BlueprintEditorLibrary.get_blueprint_asset(actor.get_outer())
        else:
            blueprint = unreal.BlueprintEditorLibrary.get_blueprint_asset(outer)
            assert blueprint, f'{component} is not owned by an Actor or Blueprint.'
            actor = BlueprintTools.get_default_object(blueprint)
            if not isinstance(actor, unreal.Actor):
                raise RuntimeError(f'{component} is not owned by an Actor Blueprint.')

        actor_handle: unreal.SubobjectDataHandle | None = None
        component_handle: unreal.SubobjectDataHandle | None = None
        sds = ActorTools._sds()
        for so_handle in ActorTools._get_subobject_handles(sds, actor, blueprint):
            so_data = unreal.SubobjectDataBlueprintFunctionLibrary.get_data(so_handle)
            if unreal.SubobjectDataBlueprintFunctionLibrary.is_actor(so_data):
                actor_handle = so_handle
            elif unreal.SubobjectDataBlueprintFunctionLibrary.get_associated_object(
                    so_data) == component:
                component_handle = so_handle
            if actor_handle and component_handle:
                break

        if not actor_handle:
            raise RuntimeError(f'Could not find actor handle for {actor}')
        if not component_handle:
            raise RuntimeError(f'Could not find subobject handle for {component}')

        if blueprint:
            deleted = sds.delete_subobject(actor_handle, component_handle, blueprint)
        else:
            deleted = sds.k2_delete_subobject_from_instance(actor_handle, component_handle)
        assert deleted > 0, f'Failed to remove component {component}'

        if blueprint:
            BlueprintTools.compile_blueprint(blueprint)

        return True

    @staticmethod
    def _blueprint_and_actor_for_component(
        component: unreal.ActorComponent,
    ) -> tuple[unreal.Blueprint | None, unreal.Actor | None]:
        """Returns the blueprint and actor for a component, handling both scene instances and blueprints.

        For scene instance components, the blueprint is None and the actor is the owning actor.
        For blueprint components, both the blueprint and a CDO actor are returned.
        """
        outer = component.get_outer()
        if isinstance(outer, unreal.Actor):
            blueprint = unreal.BlueprintEditorLibrary.get_blueprint_asset(outer.get_outer())
            return blueprint, outer
        blueprint = unreal.BlueprintEditorLibrary.get_blueprint_asset(outer)
        if blueprint:
            actor = BlueprintTools.get_default_object(blueprint)
            if isinstance(actor, unreal.Actor):
                # Verify the component actually belongs to this blueprint via SDS
                # to avoid false positives from get_blueprint_asset returning stale results.
                sds = ActorTools._sds()
                for so_handle in ActorTools._get_subobject_handles(sds, actor, blueprint):
                    so_data = unreal.SubobjectDataBlueprintFunctionLibrary.get_data(so_handle)
                    if (unreal.SubobjectDataBlueprintFunctionLibrary.get_associated_object(so_data)
                            == component):
                        return blueprint, actor
        return None, None

    @staticmethod
    def _sds() -> unreal.SubobjectDataSubsystem:
        sds = unreal.get_engine_subsystem(unreal.SubobjectDataSubsystem)
        assert sds
        return sds

    @staticmethod
    def _get_subobject_handles(
        sds: unreal.SubobjectDataSubsystem,
        actor: unreal.Actor,
        blueprint: unreal.Blueprint | None,
    ) -> list[unreal.SubobjectDataHandle]:
        """Returns subobject handles for an actor instance or blueprint.

        Args:
            sds: The SubobjectDataSubsystem to query.
            actor: The actor instance to gather handles from when blueprint is None.
            blueprint: The blueprint to gather handles from, or None for a scene instance.

        Returns:
            The list of SubobjectDataHandles.
        """
        return (
            sds.k2_gather_subobject_data_for_blueprint(blueprint) if blueprint else
            sds.k2_gather_subobject_data_for_instance(actor))  # type: ignore

