# Copyright Epic Games, Inc. All Rights Reserved.
"""Cross-toolset helpers for common editor operations.

Shared utilities for toolsets that need to create assets, check for their
existence, compile blueprints, or guard mutations on actors — without taking
a dependency on another toolset module.
"""

import unreal


def asset_exists(path: str) -> bool:
    """True if an asset OR a folder exists at path."""
    eas = unreal.get_editor_subsystem(unreal.EditorAssetSubsystem)
    return eas.does_directory_exist(path) or eas.does_asset_exist(path)


def create_asset(
        folder_path: str, asset_name: str, asset_type: unreal.Class,
        factory: unreal.Factory) -> unreal.Object:
    """Creates an asset at folder_path/asset_name. Raises if one already exists."""
    if asset_exists(f'{folder_path}/{asset_name}'):
        raise RuntimeError(f'create_asset: {asset_name} at {folder_path} already exists')
    new_asset = unreal.AssetToolsHelpers.get_asset_tools().create_asset(
        asset_name, folder_path, asset_type, factory)
    assert new_asset, f'Unable to create asset {asset_name} at {folder_path}'
    return new_asset


def compile_blueprint(blueprint: unreal.Blueprint, warnings_as_errors: bool = False) -> None:
    """Compiles a Blueprint and raises with collected error messages on failure."""
    unreal.BlueprintEditorLibrary.compile_blueprint(blueprint)
    status = blueprint.get_editor_property('Status')
    if status == unreal.BlueprintStatus.BS_UP_TO_DATE:
        return
    if status == unreal.BlueprintStatus.BS_UP_TO_DATE_WITH_WARNINGS and not warnings_as_errors:
        return
    all_graphs = unreal.BlueprintEditorLibrary.list_graphs(blueprint)
    error_nodes = []
    for graph in all_graphs:
        bp_editor = unreal.BlueprintGraphEditor.get_graph_editor(graph)
        error_nodes += bp_editor.list_nodes_with_errors()
    error_msgs = [node.get_editor_property('ErrorMsg') for node in error_nodes]
    assert False, f'Blueprint {blueprint} failed to compile. Compile Errors: {error_msgs}'


def require_editable(obj: unreal.Object) -> None:
    """Raises RuntimeError if obj (or its owning actor) is in a non-editing level instance."""
    actor: unreal.Actor | None = None
    if isinstance(obj, unreal.Actor):
        actor = obj
    elif isinstance(obj, unreal.ActorComponent):
        outer = obj.get_outer()
        if isinstance(outer, unreal.Actor):
            actor = outer
    if not actor:
        return
    actor_level = actor.get_outer()
    les = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
    assert les
    if actor_level == les.get_current_level():
        return
    world = actor.get_world()
    if not world:
        return
    lib = unreal.InterchangeEditorScriptLibrary
    for li in unreal.GameplayStatics.get_all_actors_of_class(
            world, unreal.LevelInstance.static_class()):
        if li.get_loaded_level() != actor_level:
            continue
        if actor not in lib.level_instance_get_editable_actors(li):
            raise RuntimeError(
                f'{actor.get_actor_label()!r} is inside level instance '
                f'{li.get_actor_label()!r} which is not in edit mode. '
                'Call edit_level_instance to edit it.')
        return
