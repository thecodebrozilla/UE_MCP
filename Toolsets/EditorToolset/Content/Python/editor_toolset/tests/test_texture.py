# Copyright Epic Games, Inc. All Rights Reserved.

import json
import os
import struct
import tempfile
from typing import Iterator
from contextlib import contextmanager

import unreal

from toolset_registry.tests.toolset_testcase import ToolCallTestCase
from toolset_registry.tests.automation import create_temp_folder
from editor_toolset.toolsets.object import ObjectTools
from editor_toolset.toolsets.texture import TextureTools


def _write_tga(tmp_dir: str, width: int, height: int) -> str:
    """Writes a minimal 24-bit uncompressed TGA to tmp_dir and returns its path.

    Unreal can import this format without any external dependencies.
    """
    path = os.path.join(tmp_dir, 'texture.tga')
    # 18-byte TGA header: id_len, colormap_type, image_type,
    # colormap_first(H), colormap_len(H), colormap_entry_size,
    # x_origin(H), y_origin(H), width(H), height(H), bpp, image_desc
    header = struct.pack(
        '<BBBHHBHHHHBB',
        0, 0, 2,
        0, 0, 0,
        0, 0,
        width, height,
        24,
        0,
    )
    with open(path, 'wb') as f:
        f.write(header)
        # BGR pixel data (magenta: B=255, G=0, R=255)
        f.write(b'\xff\x00\xff' * (width * height))
    return path


@contextmanager
def create_temp_texture(
    asset_name: str = 'Tex', width: int = 4, height: int = 8) -> Iterator[unreal.Texture2D]:
    """Creates a minimal TGA file, imports it as a Texture2D, and cleans up on exit.

    Args:
        asset_name: The name to give the imported asset.
        width: Image width in pixels. Should be a power-of-two.
        height: Image height in pixels. Should be a power-of-two.

    Yields:
        The imported Texture2D asset.
    """
    with create_temp_folder() as folder, tempfile.TemporaryDirectory() as tmp_dir:
        path = _write_tga(tmp_dir, width, height)
        imported = TextureTools.import_file(folder, asset_name, path)
        texture = imported[0]
        assert isinstance(texture, unreal.Texture2D), (
            f'Imported asset is not a Texture2D: {type(texture).__name__}')
        yield texture


class TextureToolsTestCase(ToolCallTestCase):
    """Test TextureTools toolset."""

    def test_get_size(self):
        """Ensures that get_size returns the correct dimensions for an imported texture."""
        with create_temp_texture(width=4, height=8) as texture:
            size = TextureTools.get_size(texture)
            self.assertIsInstance(size, unreal.IntPoint)
            self.assertEqual(size.x, 4)
            self.assertEqual(size.y, 8)

    def test_set_and_get_compression(self):
        """Ensures that compressionSettings can be written and read back via ObjectTools."""
        with create_temp_texture() as texture:
            ObjectTools.set_properties(texture, json.dumps({'compressionSettings': 'TC_Normalmap'}))
            result = json.loads(ObjectTools.get_properties(texture, ['compressionSettings']))
            self.assertEqual(result['compressionSettings'], 'TC_Normalmap')

    def test_set_and_get_srgb(self):
        """Ensures that sRGB can be written and read back via ObjectTools."""
        with create_temp_texture() as texture:
            ObjectTools.set_properties(texture, json.dumps({'sRGB': False}))
            result = json.loads(ObjectTools.get_properties(texture, ['sRGB']))
            self.assertFalse(result['sRGB'])

    def test_set_and_get_filter(self):
        """Ensures that filter can be written and read back via ObjectTools."""
        with create_temp_texture() as texture:
            ObjectTools.set_properties(texture, json.dumps({'filter': 'TF_Nearest'}))
            result = json.loads(ObjectTools.get_properties(texture, ['filter']))
            self.assertEqual(result['filter'], 'TF_Nearest')

    def test_set_and_get_lod_group(self):
        """Ensures that lODGroup can be written and read back via ObjectTools."""
        with create_temp_texture() as texture:
            ObjectTools.set_properties(texture, json.dumps({'lODGroup': 'TEXTUREGROUP_UI'}))
            result = json.loads(ObjectTools.get_properties(texture, ['lODGroup']))
            self.assertEqual(result['lODGroup'], 'TEXTUREGROUP_UI')

    def test_set_and_get_mip_gen_settings(self):
        """Ensures that mipGenSettings can be written and read back via ObjectTools."""
        with create_temp_texture() as texture:
            ObjectTools.set_properties(texture, json.dumps({'mipGenSettings': 'TMGS_NoMipmaps'}))
            result = json.loads(ObjectTools.get_properties(texture, ['mipGenSettings']))
            self.assertEqual(result['mipGenSettings'], 'TMGS_NoMipmaps')

    def test_set_and_get_address_mode(self):
        """Ensures that addressX and addressY can be written and read back via ObjectTools."""
        with create_temp_texture() as texture:
            ObjectTools.set_properties(
                texture, json.dumps({'addressX': 'TA_Clamp', 'addressY': 'TA_Mirror'}))
            result = json.loads(ObjectTools.get_properties(texture, ['addressX', 'addressY']))
            self.assertEqual(result['addressX'], 'TA_Clamp')
            self.assertEqual(result['addressY'], 'TA_Mirror')

    def test_import_file(self):
        """Ensures import_file produces a Texture2D with the source image's dimensions."""
        with create_temp_folder() as folder, tempfile.TemporaryDirectory() as tmp_dir:
            path = _write_tga(tmp_dir, width=4, height=8)
            result = TextureTools.import_file(folder, 'ImportedTex', path)
            self.assertEqual(len(result), 1)
            texture = result[0]
            self.assertIsInstance(texture, unreal.Texture2D)
            size = TextureTools.get_size(texture)
            self.assertEqual(size.x, 4)
            self.assertEqual(size.y, 8)

    def test_import_file_unsupported_extension(self):
        """Ensures import_file rejects file extensions TextureFactory does not declare."""
        with create_temp_folder() as folder, tempfile.TemporaryDirectory() as tmp_dir:
            path = os.path.join(tmp_dir, 'not_an_image.txt')
            with open(path, 'w') as f:
                f.write('hello')
            with self.assertToolRaisesRuntimeError():
                TextureTools.import_file(folder, 'NotATexture', path)
