# Copyright Epic Games, Inc. All Rights Reserved.

import unittest
import unreal

from metahuman_toolset.metahuman import MetaHumanToolset, BodyShape, SkinTone, EyeColor
from metahuman_toolset.session import clear_session_cache


class MetaHumanToolsetTestCase(unittest.TestCase):
    """Test MetaHumanToolset."""

    def setUp(self):
        """Create test MetaHuman character."""
        self.test_path = "/Game/TestMetaHuman"

        if unreal.EditorAssetLibrary.does_asset_exist(self.test_path):
            unreal.EditorAssetLibrary.delete_asset(self.test_path)

        asset_tools = unreal.AssetToolsHelpers.get_asset_tools()
        factory = unreal.new_object(type=unreal.MetaHumanCharacterFactoryNew)
        self.test_character = asset_tools.create_asset(
            asset_name="TestMetaHuman",
            package_path="/Game",
            asset_class=unreal.MetaHumanCharacter,
            factory=factory
        )
        self.assertIsNotNone(self.test_character, "Failed to create test character")
        self.session = MetaHumanToolset.begin_edit(self.test_path)

    def tearDown(self):
        """Clean up test character."""
        if hasattr(self, 'session') and self.session:
            MetaHumanToolset.end_edit(self.session)
        clear_session_cache()
        if self.test_character and unreal.EditorAssetLibrary.does_asset_exist(self.test_path):
            unreal.EditorAssetLibrary.delete_asset(self.test_path)
        unreal.SystemLibrary.collect_garbage()

    def test_get_skin_tone(self):
        """Test getting skin tone from MetaHuman character."""
        skin_tone = MetaHumanToolset.get_skin_tone(self.session)
        self.assertIsInstance(skin_tone, SkinTone)
        self.assertGreaterEqual(skin_tone.lightness, 0.0)
        self.assertLessEqual(skin_tone.lightness, 1.0)
        self.assertGreaterEqual(skin_tone.redness, 0.0)
        self.assertLessEqual(skin_tone.redness, 1.0)

    def test_set_get_skin_tone(self):
        """Test setting and getting skin tone."""
        new_tone = SkinTone()
        new_tone.lightness = 0.5
        new_tone.redness = 0.7
        MetaHumanToolset.set_skin_tone(self.session, new_tone)
        retrieved_tone = MetaHumanToolset.get_skin_tone(self.session)
        self.assertAlmostEqual(retrieved_tone.lightness, 0.5, places=2)
        self.assertAlmostEqual(retrieved_tone.redness, 0.7, places=2)

    def test_get_body_shape(self):
        """Test getting body shape from MetaHuman character."""
        body_shape = MetaHumanToolset.get_body_shape(self.session)
        self.assertIsInstance(body_shape, BodyShape)
        if body_shape.masculine_feminine is not None:
            self.assertGreaterEqual(body_shape.masculine_feminine, 0.0)
            self.assertLessEqual(body_shape.masculine_feminine, 1.0)
        if body_shape.fat is not None:
            self.assertGreaterEqual(body_shape.fat, 0.0)
            self.assertLessEqual(body_shape.fat, 1.0)
        if body_shape.muscularity is not None:
            self.assertGreaterEqual(body_shape.muscularity, 0.0)
            self.assertLessEqual(body_shape.muscularity, 1.0)
        if body_shape.height_cm is not None:
            self.assertGreaterEqual(body_shape.height_cm, 135.0)
            self.assertLessEqual(body_shape.height_cm, 220.0)

    def test_set_get_body_shape(self):
        """Test setting and getting body shape."""
        new_shape = BodyShape()
        new_shape.masculine_feminine = 0.3
        new_shape.fat = 0.4
        new_shape.muscularity = 0.6
        new_shape.height_cm = 175.0
        MetaHumanToolset.set_body_shape(self.session, new_shape)
        retrieved_shape = MetaHumanToolset.get_body_shape(self.session)
        self.assertAlmostEqual(retrieved_shape.masculine_feminine, 0.3, places=1)
        self.assertAlmostEqual(retrieved_shape.fat, 0.4, places=1)
        self.assertAlmostEqual(retrieved_shape.muscularity, 0.6, places=1)
        self.assertAlmostEqual(retrieved_shape.height_cm, 175.0, places=0)

    def test_get_eye_color(self):
        """Test getting eye color from MetaHuman character."""
        eye_color = MetaHumanToolset.get_eye_color(self.session)
        self.assertIsInstance(eye_color, EyeColor)
        self.assertGreaterEqual(eye_color.temperature, 0.0)
        self.assertLessEqual(eye_color.temperature, 1.0)
        self.assertGreaterEqual(eye_color.brightness, 0.0)
        self.assertLessEqual(eye_color.brightness, 1.0)

    def test_set_get_eye_color(self):
        """Test setting and getting eye color."""
        new_color = EyeColor()
        new_color.temperature = 0.8
        new_color.brightness = 0.6
        MetaHumanToolset.set_eye_color(self.session, new_color)
        retrieved_color = MetaHumanToolset.get_eye_color(self.session)
        self.assertAlmostEqual(retrieved_color.temperature, 0.8, places=2)
        self.assertAlmostEqual(retrieved_color.brightness, 0.6, places=2)

    def test_instantiate_metahuman_asset(self):
        """Test creating a new MetaHuman asset."""
        test_asset_path = "/Game/TestMetaHumanInstantiate"
        try:
            asset = MetaHumanToolset.create(test_asset_path)
            self.assertIsNotNone(asset)
            self.assertEqual(asset.get_class().get_name(), "MetaHumanCharacter")
            self.assertTrue(unreal.EditorAssetLibrary.does_asset_exist(test_asset_path))
        finally:
            if unreal.EditorAssetLibrary.does_asset_exist(test_asset_path):
                unreal.EditorAssetLibrary.delete_asset(test_asset_path)
            unreal.SystemLibrary.collect_garbage()
