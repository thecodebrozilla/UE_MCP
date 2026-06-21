# Copyright Epic Games, Inc. All Rights Reserved.

from __future__ import annotations

import fnmatch

import unreal

import toolset_registry
from toolset_registry.helpers import create_asset

@unreal.uclass()
class DataAssetTools(unreal.ToolsetDefinition):
    """Provides tools for working with Data Assets."""

    @toolset_registry.tool_call
    @staticmethod
    def create(folder_path: str, asset_name: str, asset_type: unreal.Class) -> unreal.DataAsset:
        """Creates a new DataAsset asset in the project.

        Args:
            folder_path: The path to the folder that will contain the asset.
            asset_name: The name of the asset in the folder.
            asset_type: The specific kind of DataClass to make.

        Returns:
            The DataAsset that was created.
        """
        assert unreal.MathLibrary.class_is_child_of(asset_type, unreal.DataAsset.static_class()), (
            f'{asset_type} cannot be stored in a DataAsset.')
        data_asset = create_asset(
            folder_path, asset_name, asset_type, unreal.DataAssetFactory())
        assert isinstance(data_asset, unreal.DataAsset)
        return data_asset
