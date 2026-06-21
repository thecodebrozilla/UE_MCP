# Copyright Epic Games, Inc. All Rights Reserved.

import unittest

import unreal

from toolset_registry.tests.toolset_testcase import ToolCallTestCase
from toolset_registry.tests.automation import create_temp_folder
from editor_toolset.toolsets.data_asset import DataAssetTools

class DataAssetToolsTestCase(ToolCallTestCase):
    """Test DataAssetTools toolset."""

    def test_create(self):
        """Ensures that we can create a data asset."""
        with create_temp_folder() as test_folder:
            data_asset = DataAssetTools.create(
                test_folder, 'test', unreal.InputAction.static_class())
            self.assertIsInstance(data_asset, unreal.InputAction)

    def test_create_invalid_type(self):
        """Ensures create raises an error when asset_type is not a DataAsset subclass."""
        with create_temp_folder() as test_folder:
            with self.assertToolRaisesRuntimeError():
                DataAssetTools.create(test_folder, 'test', unreal.Actor.static_class())
