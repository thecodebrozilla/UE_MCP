# Copyright Epic Games, Inc. All Rights Reserved.

import gc
import unittest

import toolset_registry
from toolset_registry.tests.demo_toolset import DemoPythonToolset
import unreal

class TestToolsetRegistry(unittest.TestCase):
    """Tests for the Toolset Registry Blueprint wrapper library."""

    def setUp(self):
        """Ensure that demo toolset is unregistered."""
        registry = unreal.ToolsetRegistry
        if registry.is_toolset_class_registered(DemoPythonToolset):
           registry.unregister_toolset_class(DemoPythonToolset)

    def tearDown(self):
        """Clean up."""
        registry = unreal.ToolsetRegistry
        registry.unregister_toolset_class(DemoPythonToolset)

    def test_is_available(self):
        """"Ensure the toolset registry is available in the editor."""
        self.assertTrue(unreal.ToolsetRegistry.is_available())

    def test_register_unregister_toolset(self):
        """Test that we can register and unregister toolset."""
        registry = unreal.ToolsetRegistry
        self.assertFalse(registry.is_toolset_class_registered(DemoPythonToolset))
        registry.register_toolset_class(DemoPythonToolset)
        self.assertTrue(registry.is_toolset_class_registered(DemoPythonToolset))
        registry.unregister_toolset_class(DemoPythonToolset)
        self.assertFalse(registry.is_toolset_class_registered(DemoPythonToolset))

