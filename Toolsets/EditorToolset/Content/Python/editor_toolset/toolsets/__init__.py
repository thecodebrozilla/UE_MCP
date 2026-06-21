# Copyright Epic Games, Inc. All Rights Reserved.

from toolset_registry.registration import Registration
from editor_toolset.toolsets import asset
from editor_toolset.toolsets import actor
from editor_toolset.toolsets import blueprint
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
    blueprint.BlueprintTools,
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

