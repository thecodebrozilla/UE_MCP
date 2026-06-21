# Copyright Epic Games, Inc. All Rights Reserved.

import unreal

import toolset_registry
from editor_toolset.toolsets.asset import import_asset, require_factory_supports


@unreal.uclass()
class TextureTools(unreal.ToolsetDefinition):
    """Provides tools for working with Texture assets."""

    @toolset_registry.tool_call
    @staticmethod
    def import_file(
            folder_path: str, asset_name: str,
            source_file: str) -> list[unreal.Object]:
        """Imports an image file from disk as a Texture2D asset.

        Args:
            folder_path: The content-browser folder to create the asset in.
            asset_name: The name of the new asset.
            source_file: The absolute path to the source image file on disk.

        Returns:
            The assets produced by the import (typically a single Texture2D).
        """
        # Validate via TextureFactory without pinning task.factory; pinning
        # bypasses the Interchange path, which legacy UTextureFactory mishandles.
        require_factory_supports(source_file, unreal.TextureFactory())
        return import_asset(folder_path, asset_name, source_file)

    @toolset_registry.tool_call
    @staticmethod
    def get_size(texture: unreal.Texture2D) -> unreal.IntPoint:
        """Returns the dimensions of a Texture2D in pixels.

        Args:
            texture: The Texture2D to query.

        Returns:
            A vector x is the width and y is the height, both in pixels.
        """
        return unreal.IntPoint(texture.blueprint_get_size_x(), texture.blueprint_get_size_y())
