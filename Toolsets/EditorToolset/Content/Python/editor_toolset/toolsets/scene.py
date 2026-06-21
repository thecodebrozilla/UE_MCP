# Copyright Epic Games, Inc. All Rights Reserved.

from __future__ import annotations

import unreal

import toolset_registry
from editor_toolset.toolsets.actor import ActorTools
from editor_toolset.toolsets.asset import AssetTools
from toolset_registry.helpers import require_editable

# All available collision channels. OBJECT_TYPE_QUERY* entries are deprecated aliases for
# the ECC_* names (e.g. OBJECT_TYPE_QUERY1 == ECC_WORLD_STATIC) and are excluded to avoid
# duplicates and deprecation warnings.
ALL_COLLISION_CHANNELS: list[unreal.ObjectTypeQuery] = [
    getattr(unreal.ObjectTypeQuery, name)
    for name in dir(unreal.ObjectTypeQuery)
    if (not name.startswith('OBJECT_TYPE_')
        and isinstance(getattr(unreal.ObjectTypeQuery, name, None), unreal.ObjectTypeQuery))
]

@unreal.uclass()
class SceneTools(unreal.ToolsetDefinition):
    """Provides tools for working with the currently loaded level, including
    loading levels, placing and removing actors, controlling the level camera,
    and organizing actors in the outliner."""

    @toolset_registry.tool_call
    @staticmethod
    def load_level(level_path: str) -> None:
        """Loads a level in the editor.

        Args:
            level_path: The path to the level asset.
        """
        if not AssetTools.exists(level_path):
            raise RuntimeError(
                f'Cannot load {level_path!r}: level does not exist.')
        if AssetTools.is_dirty(level_path):
            raise RuntimeError(
                f'Cannot load {level_path!r}: the level has unsaved changes. '
                'Save the level before loading it.')
        SceneTools._les().load_level(level_path)

    @toolset_registry.tool_call
    @staticmethod
    def get_current_level() -> str:
        """Returns the path to the current level asset.

        Returns:
            The name of the loaded level, if any.
        """
        current_level = SceneTools._les().get_current_level()
        return current_level.get_outermost().get_name() if current_level else ''

    @toolset_registry.tool_call
    @staticmethod
    def get_collision_channels() -> list[unreal.ObjectTypeQuery]:
        """Returns all available collision channels for use with find_actors.

        Returns:
            A list of all collision channels.
        """
        return ALL_COLLISION_CHANNELS

    @toolset_registry.tool_call
    @staticmethod
    def find_actors(
        root: unreal.Actor | None = None, name: str = '',
        actor_type: unreal.Class | None = None,
        tag: str = '',
        bounds: unreal.Box | None = None,
        collision_channels: list[unreal.ObjectTypeQuery] = []) -> list[unreal.Actor]:
        """Searches the scene for actors that match specific criteria.

        Args:
            root: If set, will only search this actor and its children.
            name: If set, will only return actors whose label contains this string
                (case-insensitive).
            actor_type: If set, will only return actors that are of this type.
            tag: If set, will only return actors that have this tag.
            bounds: If set, only returns actors whose bounds overlap this world-space AABB.
            collision_channels: If set, bounds checks will uses a native physics overlap query
                restricted to these channels. Non-collision actors will be ignored.

        Returns:
            A list of actors that match the criteria.
        """
        root_candidates = list(root.get_attached_actors()) + [root] if root else None
        candidates = SceneTools._actors_in_bounds(
            bounds, actor_type, collision_channels, root_candidates)
        filtered_actors: list[unreal.Actor] = []
        name_lower = name.lower()
        tag_name = unreal.Name(tag) if tag else None
        for actor in candidates:
            assert isinstance(actor, unreal.Actor)
            if (name_lower in actor.get_actor_label().lower() and
                (not tag or actor.actor_has_tag(tag_name))):
                filtered_actors.append(actor)
        return filtered_actors

    @toolset_registry.tool_call
    @staticmethod
    def add_to_scene_from_class(
        actor_type: unreal.Class, name: str, xform: unreal.Transform,
        parent: unreal.Actor | None = None, snap_to_ground: bool = False) -> unreal.Actor:
        """Creates a new instance of the specified object at the specified transform.

        Args:
            actor_type: The Actor class to instantiate.
            name: The name of the actor instance.
            xform: The transform for the new actor. Parent-local when `parent` is set;
                world-space otherwise.
            parent: If set, the new actor will be a child of this actor. If unset the Actor will
                be a child of the world.
            snap_to_ground: If set to true, will attempt to adjust the actors Z position so that
                the bottom of its bounding box is on the ground.

        Returns:
            The created actor or nothing if creation was unsuccessful.
        """
        new_actor = SceneTools._add_actor(name, actor_type, xform, parent)
        if snap_to_ground:
            SceneTools._snap_to_ground(new_actor)
        return new_actor

    @toolset_registry.tool_call
    @staticmethod
    def add_to_scene_from_asset(
        asset_path: str, name: str, xform: unreal.Transform,
        parent: unreal.Actor | None = None, snap_to_ground: bool = False) -> unreal.Actor:
        """Creates a new actor in the scene from an asset.

        Args:
            asset_path: The path to the asset to spawn (e.g. '/Game/Blueprints/MyActor').
            name: The name of the actor instance.
            xform: The transform for the new actor. Parent-local when `parent` is set;
                world-space otherwise.
            parent: If set, the new actor will be a child of this actor. If unset the Actor will
                be a child of the world.
            snap_to_ground: If set to true, will attempt to adjust the actors Z position so that
                the bottom of its bounding box is on the ground.

        Returns:
            The created actor or nothing if creation was unsuccessful.
        """
        obj = unreal.load_asset(asset_path)
        assert obj, f'Could not load asset at path: {asset_path}'
        new_actor = SceneTools._add_actor(name, obj, xform, parent)
        if snap_to_ground:
            SceneTools._snap_to_ground(new_actor)
        return new_actor

    @toolset_registry.tool_call
    @staticmethod
    def remove_from_scene(actor: unreal.Actor) -> bool:
        """Deletes an actor from the scene.

        Args:
            actor: The actor to remove.

        Returns:
            True if the actor was removed.
        """
        if SceneTools._is_pie():
            raise RuntimeError('Cannot remove actors while PIE is active.')
        require_editable(actor)
        return SceneTools._eas().destroy_actor(actor)

    @toolset_registry.tool_call
    @staticmethod
    def get_folders() -> list[str]:
        """Returns all folder paths currently in use in the outliner.

        Includes all intermediate parent paths. For example, if an actor is assigned to
        'Lighting/Spotlights', both 'Lighting' and 'Lighting/Spotlights' are returned.

        Returns:
            A sorted list of unique folder path strings.
        """
        folders: set[str] = set()
        for actor in SceneTools._eas().get_all_level_actors():
            path = SceneTools._get_actor_folder(actor)
            if path:
                parts = path.split('/')
                for i in range(len(parts)):
                    folders.add('/'.join(parts[:i + 1]))
        return sorted(folders)

    @toolset_registry.tool_call
    @staticmethod
    def get_actors_in_folder(folder_path: str, recursive: bool = False) -> list[unreal.Actor]:
        """Returns the actors in the specified outliner folder.

        Args:
            folder_path: The folder path to query (e.g. 'Lighting/Spotlights').
            recursive: If True, also includes actors in sub-folders.

        Returns:
            A list of actors in the specified folder.
        """
        SceneTools._require_folder(folder_path)
        result: list[unreal.Actor] = []
        for actor in SceneTools._eas().get_all_level_actors():
            path = SceneTools._get_actor_folder(actor)
            if recursive:
                if path == folder_path or path.startswith(folder_path + '/'):
                    result.append(actor)
            else:
                if path == folder_path:
                    result.append(actor)
        return result

    @toolset_registry.tool_call
    @staticmethod
    def set_actor_folder(actor: unreal.Actor, folder_path: str) -> None:
        """Assigns an actor to the specified folder in the outliner.

        Creates the folder implicitly if it does not already exist. Pass an empty string
        to move the actor to the root of the outliner.

        Args:
            actor: The actor to move.
            folder_path: The folder path to assign (e.g. 'Lighting/Spotlights').
                         Pass an empty string to move the actor to the root.
        """
        actor.set_folder_path(unreal.Name(folder_path))

    @toolset_registry.tool_call
    @staticmethod
    def rename_folder(old_path: str, new_path: str) -> int:
        """Renames a folder in the outliner.

        Updates the folder path for all actors in the folder and any sub-folders.
        For example, renaming 'Lighting' to 'Lights' also updates actors in
        'Lighting/Spotlights' to 'Lights/Spotlights'. If the new path already
        exists then the affected actors will be merged into it.

        Args:
            old_path: The current folder path (e.g. 'Lighting').
            new_path: The new folder path (e.g. 'Lights').

        Returns:
            The number of actors whose folder path was updated.
        """
        SceneTools._require_folder(old_path)
        if not new_path:
            raise ValueError('new_path must not be empty.')
        old_folders = sorted(
            [f for f in SceneTools.get_folders() if f == old_path or f.startswith(old_path + '/')],
            reverse=True)
        count = 0
        for actor in SceneTools._eas().get_all_level_actors():
            path = SceneTools._get_actor_folder(actor)
            if path == old_path or path.startswith(old_path + '/'):
                updated = new_path + path[len(old_path):]
                actor.set_folder_path(unreal.Name(updated))
                count += 1
        for old_folder in old_folders:
            SceneTools._les().delete_actor_folder(unreal.Name(old_folder))
        return count

    @toolset_registry.tool_call
    @staticmethod
    def delete_folder(folder_path: str) -> int:
        """Deletes a folder from the outliner.

        Actors directly in the folder are moved to the parent folder. Sub-folders and
        their actors are preserved by re-rooting them under the parent. For example,
        deleting 'Lighting' with a sub-folder 'Lighting/Spotlights' leaves 'Spotlights'
        intact under the parent.

        Args:
            folder_path: The folder path to delete (e.g. 'Lighting/Spotlights').

        Returns:
            The number of actors that were moved.
        """
        SceneTools._require_folder(folder_path)
        parent = folder_path.rsplit('/', 1)[0] if '/' in folder_path else ''
        count = 0
        for actor in SceneTools._eas().get_all_level_actors():
            path = SceneTools._get_actor_folder(actor)
            if path == folder_path:
                actor.set_folder_path(unreal.Name(parent))
                count += 1
            elif path.startswith(folder_path + '/'):
                sub_path = path[len(folder_path) + 1:]
                new_path = f'{parent}/{sub_path}' if parent else sub_path
                actor.set_folder_path(unreal.Name(new_path))
                count += 1
        SceneTools._les().delete_actor_folder(unreal.Name(folder_path))
        return count

    @toolset_registry.tool_call
    @staticmethod
    def trace_world(start: unreal.Vector, end: unreal.Vector) -> float | None:
        """Traces a line through the world and returns the distance to the first hit.

        Args:
            start: The start point of the trace in world space.
            end: The end point of the trace in world space.

        Returns:
            The distance from start to the hit point, or None if nothing was hit.
        """
        hit_location = SceneTools._trace_world(SceneTools._get_world(), start, end)
        if hit_location is None:
            return None
        return start.distance(hit_location)

    @toolset_registry.tool_call
    @staticmethod
    def merge_actors(
            actors: list[unreal.StaticMeshActor], output_path: str,
            name: str = '', destroy_source_actors: bool = False) -> unreal.StaticMeshActor:
        """Merges multiple StaticMesh actors into a single mesh asset and actor.

        Args:
            actors: The StaticMeshActors to merge. All must be in the same level.
            output_path: Content path for the merged mesh asset (e.g. '/Game/Meshes/Merged').
            name: Label for the new merged actor. Defaults to the last segment of output_path.
            destroy_source_actors: If True, removes the source actors after merging.

        Returns:
            The merged StaticMeshActor.
        """
        if SceneTools._is_pie():
            raise RuntimeError('Cannot merge actors while PIE is active.')
        options = unreal.MergeStaticMeshActorsOptions()
        options.base_package_name = output_path
        options.new_actor_label = name or output_path.rsplit('/', 1)[-1]
        options.destroy_source_actors = destroy_source_actors
        options.spawn_merged_actor = True
        smes = unreal.get_editor_subsystem(unreal.StaticMeshEditorSubsystem)
        assert smes
        merged = smes.merge_static_mesh_actors(actors, options)
        if merged is None:
            raise RuntimeError('merge_actors failed to produce a merged actor.')
        return merged

    @toolset_registry.tool_call
    @staticmethod
    def create_level_instance(
            level_path: str, name: str, xform: unreal.Transform,
            parent: unreal.Actor | None = None) -> unreal.LevelInstance:
        """Creates a Level Instance actor in the scene referencing an existing level asset.

        Args:
            level_path: The content path to the level asset (e.g. '/Game/Maps/MyLevel').
            name: The label for the new Level Instance actor.
            xform: The transform for the new actor.
            parent: If set, the new actor will be a child of this actor.

        Returns:
            The created LevelInstance actor.
        """
        if not AssetTools.exists(level_path):
            raise RuntimeError(
                f'Cannot create level instance: {level_path!r} does not exist.')
        world_asset = unreal.load_asset(level_path)
        actor = SceneTools._add_actor(name, unreal.LevelInstance.static_class(), xform, parent)
        assert isinstance(actor, unreal.LevelInstance)
        if not actor.set_world_asset(world_asset):
            SceneTools._eas().destroy_actor(actor)
            raise RuntimeError(
                f'Failed to assign level {level_path!r} to the level instance.')
        return actor

    @toolset_registry.tool_call
    @staticmethod
    def edit_level_instance(level_instance: unreal.LevelInstance) -> None:
        """Opens a level instance for editing.

        While in edit mode, scene tools such as add_to_scene_from_class and
        remove_from_scene operate within the level instance's sub-level. Only one
        level instance can be in edit mode at a time. Call commit_level_instance
        when done to save or discard changes.

        Args:
            level_instance: The level instance actor to open for editing.
        """
        success = unreal.InterchangeEditorScriptLibrary.level_instance_enter_edit_mode(level_instance)
        if not success:
            raise RuntimeError(f"Failed to enter edit mode for level instance '{level_instance.get_name()}'. "
                               "Another level instance may already be in edit mode.")

    @toolset_registry.tool_call
    @staticmethod
    def commit_level_instance(
            level_instance: unreal.LevelInstance, discard: bool = False) -> None:
        """Saves or discards edits to a level instance and exits edit mode.

        Args:
            level_instance: The level instance actor to commit.
            discard: If True, discards all changes without saving. Defaults to False.
        """
        lib = unreal.InterchangeEditorScriptLibrary
        if not discard:
            # Pre-save so the commit's save dialog isn't silently declined in
            # unattended environments, leaving edit mode active.
            unreal.EditorLoadingAndSavingUtils.save_dirty_packages(True, True)
        if not lib.level_instance_commit(level_instance, discard):
            raise RuntimeError(
                f'Failed to commit {level_instance.get_actor_label()!r}. '
                'The level instance may not be in edit mode.')
        # A save commit (discard=False) does not always exit edit mode synchronously.
        # If the level instance is still in edit mode after saving, force-exit by
        # discarding — safe because all changes were already written to disk above.
        if not discard and lib.level_instance_get_editable_actors(level_instance):
            if not lib.level_instance_commit(level_instance, True):
                raise RuntimeError(
                    f'Failed to exit edit mode for {level_instance.get_actor_label()!r} '
                    'after saving.')

    @toolset_registry.tool_call
    @staticmethod
    def can_edit(actor: unreal.Actor) -> bool:
        """Checks whether an actor can be edited.

        Args:
            actor: The actor to check.

        Returns:
            True if the actor can be edited, False if it is checked out
            or locked by another user in source control.
        """
        state = SceneTools._sc_state(actor)
        return True if state is None else not state.is_checked_out_other

    @toolset_registry.tool_call
    @staticmethod
    def is_checked_out(actor: unreal.Actor) -> bool:
        """Checks whether an actor is checked out by the current user.

        Args:
            actor: The actor to check.

        Returns:
            True if the actor is currently checked out by the current user.
        """
        state = SceneTools._sc_state(actor)
        return False if state is None else state.is_checked_out

    @toolset_registry.tool_call
    @staticmethod
    def save_actor(actor: unreal.Actor) -> None:
        """Saves the actor to disk.

        Args:
            actor: The actor to save.
        """
        if not SceneTools._is_external_actor(actor):
            raise RuntimeError(
                f'{actor.get_actor_label()!r} is not an external actor asset and cannot '
                'be saved individually. Save the level instead.')
        actor_package = actor.get_package()
        if not AssetTools.save_assets([actor_package.get_path_name()]):
            raise RuntimeError(f'Failed to save {actor.get_actor_label()!r}.')

    @staticmethod
    def _is_external_actor(actor: unreal.Actor) -> bool:
        """Returns True if the actor has its own package (i.e. is a World Partition external actor)."""
        return actor.get_package() != actor.get_outer().get_outermost()

    @staticmethod
    def _sc_state(actor: unreal.Actor) -> unreal.SourceControlState | None:
        """Returns the source control state for the actor's package, or None if SC is not enabled."""
        if not unreal.SourceControl.is_enabled():
            return None
        return unreal.SourceControl.query_file_state(actor.get_package().get_path_name(), True)

    @staticmethod
    def _is_pie() -> bool:
        """Returns True if PIE (Play In Editor) is currently active."""
        return SceneTools._ues().get_game_world() is not None

    @staticmethod
    def _get_world() -> unreal.World:
        """Returns the active world: PIE world if PIE is running, otherwise the editor world."""
        ues = SceneTools._ues()
        return ues.get_game_world() if SceneTools._is_pie() else ues.get_editor_world()

    @staticmethod
    def _eas() -> unreal.EditorActorSubsystem:
        eas = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
        assert eas
        return eas

    @staticmethod
    def _ues() -> unreal.UnrealEditorSubsystem:
        ues = unreal.get_editor_subsystem(unreal.UnrealEditorSubsystem)
        assert ues
        return ues

    @staticmethod
    def _les() -> unreal.LevelEditorSubsystem:
        les = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
        assert les
        return les

    @staticmethod
    def _add_actor(
        name: str, actor_type: unreal.Class | unreal.Object, transform: unreal.Transform,
        parent: unreal.Actor | None) -> unreal.Actor:

        if SceneTools._is_pie():
            raise RuntimeError('Cannot create actors while PIE is active.')

        # Spawn functions take a world-space position. When a parent is provided,
        # transform is relative so we convert its translation to world space.
        if parent:
            actor_position = parent.get_actor_transform().transform_location(transform.translation)
        else:
            actor_position = transform.translation

        # Attempt to spawn the actor. If we are not able to spawn the actor for any reason,
        # then we raise an exception/error with information about why.
        new_actor: unreal.Actor
        if isinstance(actor_type, unreal.Class):
            new_actor = SceneTools._eas().spawn_actor_from_class(actor_type, actor_position)
            assert new_actor, f'Cannot create Actor from class {actor_type.get_class_path_name()}'
        elif isinstance(actor_type, unreal.Object):
            new_actor = SceneTools._eas().spawn_actor_from_object(actor_type, actor_position)
            assert new_actor, f'Cannot create Actor from object {actor_type.get_path_name()}'
        else:
            assert False, f'Unable to create an Actor from {str(actor_type)}'

        # When a parent is provided, attach first then set the transform as relative so
        # xform is interpreted in the parent's local space. Without a parent, set world space.
        if parent:
            new_actor.attach_to_actor(
                parent, unreal.Name(), unreal.AttachmentRule.KEEP_WORLD,
                unreal.AttachmentRule.KEEP_WORLD, unreal.AttachmentRule.KEEP_WORLD)
            ActorTools.set_actor_transform(new_actor, transform, False)
        else:
            ActorTools.set_actor_transform(new_actor, transform, True)

        # Sets the human facing name.
        new_actor.set_actor_label(name)

        return new_actor

    @staticmethod
    def _trace_world(
        world: unreal.World, start: unreal.Vector, end: unreal.Vector,
        actors_to_ignore: list[unreal.Actor] | None = None) -> unreal.Vector | None:
        ue_to_ignore = unreal.Array(unreal.Actor)
        ue_to_ignore.extend(actors_to_ignore or [])
        hit_result = unreal.SystemLibrary.line_trace_single(
            world,
            start, end,
            unreal.TraceTypeQuery.ECC_VISIBILITY,
            True,
            ue_to_ignore,
            unreal.DrawDebugTrace.NONE,
            True
        )
        return hit_result.to_dict()['location'] if hit_result else None

    @staticmethod
    def _require_folder(folder_path: str) -> None:
        """Raises ValueError if folder_path does not exist in the outliner."""
        if folder_path not in SceneTools.get_folders():
            raise ValueError(f'Folder does not exist: {folder_path!r}')

    @staticmethod
    def _get_actor_folder(actor: unreal.Actor) -> str:
        """Returns the actor's folder path as a normalized string.

        Returns an empty string for actors at the root of the outliner.
        """
        folder = str(actor.get_folder_path())
        return '' if folder == 'None' else folder

    @staticmethod
    def _actors_in_bounds(
        bounds: unreal.Box | None,
        actor_class: unreal.Class | None,
        collision_channels: list[unreal.ObjectTypeQuery],
        candidates: list[unreal.Actor] | None) -> list[unreal.Actor]:
        """Returns actors matching the given criteria.

        Args:
            bounds: If set, only returns actors whose bounds overlap this box.
            actor_class: If set, only returns actors of this class.
            collision_channels: If non-empty (requires bounds), uses a physics overlap query
                restricted to these channels instead of checking all actor bounds.
            candidates: If provided, only these actors are considered. When None, all world
                actors matching actor_class are queried.
        """
        def _matches_class(a: unreal.Actor) -> bool:
            return not actor_class or unreal.MathLibrary.class_is_child_of(
                a.get_class(), actor_class)

        if bounds is not None and collision_channels:
            center = bounds.min.add(bounds.max).multiply_float(0.5)
            extent = bounds.max.subtract(bounds.min).multiply_float(0.5)
            result = unreal.SystemLibrary.box_overlap_actors(
                SceneTools._get_world(), center, extent,
                collision_channels,
                actor_class or unreal.Actor.static_class(),
                unreal.Array(unreal.Actor))
            physics_result = set(result) if result else set()
            if candidates is not None:
                return [a for a in candidates if _matches_class(a) and a in physics_result]
            return list(physics_result)

        actors: list[unreal.Actor]
        if candidates is not None:
            actors = [a for a in candidates if _matches_class(a)]
        else:
            query_class = actor_class or unreal.Actor.static_class()
            actors = list(unreal.GameplayStatics.get_all_actors_of_class(
                SceneTools._get_world(), query_class) or [])

        if bounds is None:
            return actors

        result = []
        for a in actors:
            origin, box_extent = a.get_actor_bounds(False)
            actor_box = unreal.Box(
                min=origin.subtract(box_extent), max=origin.add(box_extent))
            if actor_box.test_box_box_intersection(bounds):
                result.append(a)
        return result

    @staticmethod
    def _snap_to_ground(actor: unreal.Actor) -> bool:
        origin, extent = actor.get_actor_bounds(False)
        assert isinstance(extent.z, float)
        vertical_extent = unreal.Vector(0, 0, extent.z)
        trace_start = origin.add(vertical_extent.multiply_float(2))
        trace_end = trace_start.subtract(vertical_extent.multiply_float(10))
        hit_location = SceneTools._trace_world(
            SceneTools._get_world(), trace_start, trace_end, [actor])
        if hit_location:
            root = actor.root_component
            if root:
                root.modify()
            position = actor.get_actor_location()
            bounds_offset = position.subtract(origin)
            actor.set_actor_location(
                hit_location.add(vertical_extent).add(bounds_offset), False, True)
            return True
        return False
