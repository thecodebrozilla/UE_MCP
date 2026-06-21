# Copyright Epic Games, Inc. All Rights Reserved.

from __future__ import annotations

from toolset_registry.registration import Registration
from editor_toolset.toolsets import asset
from editor_toolset.toolsets import actor
# [5.7 port] blueprint.py depends on unreal.BlueprintGraphEditor (a 5.8-only engine class in
# BlueprintEditorLibrary). It is provided on 5.7 by the bundled BlueprintGraphEditorPort plugin;
# if that isn't present, degrade gracefully so the rest of EditorToolset still registers.
try:
    from editor_toolset.toolsets import blueprint
    _HAVE_BLUEPRINT = True
except Exception as _e:  # noqa: BLE001
    import unreal as _unreal
    _unreal.log_warning(f"[5.7 port] EditorToolset 'blueprint' toolset unavailable: {_e}")
    _HAVE_BLUEPRINT = False
from editor_toolset.toolsets import curve_table
from editor_toolset.toolsets import data_asset
from editor_toolset.toolsets import data_table
from editor_toolset.toolsets import material
from editor_toolset.toolsets import material_instance
from editor_toolset.toolsets import object
from editor_toolset.toolsets import primitive
from editor_toolset.toolsets import programmatic
from editor_toolset.toolsets import scene
from editor_toolset.toolsets import skeletal_mesh
from editor_toolset.toolsets import static_mesh
from editor_toolset.toolsets import string_table
from editor_toolset.toolsets import texture

_registration = Registration([
    actor.ActorTools,
    asset.AssetTools,
    *( [blueprint.BlueprintTools] if _HAVE_BLUEPRINT else [] ),
    curve_table.CurveTableTools,
    data_asset.DataAssetTools,
    data_table.DataTableTools,
    material.MaterialTools,
    material_instance.MaterialInstanceTools,
    object.ObjectTools,
    primitive.PrimitiveTools,
    scene.SceneTools,
    skeletal_mesh.SkeletalMeshTools,
    static_mesh.StaticMeshTools,
    string_table.StringTableTools,
    programmatic.ProgrammaticToolset,
    texture.TextureTools,
])

