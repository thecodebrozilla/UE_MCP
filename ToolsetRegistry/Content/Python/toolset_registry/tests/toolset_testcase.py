# Copyright Epic Games, Inc. All Rights Reserved.

import contextlib
import unittest
import unreal

from toolset_registry.tests.demo_toolset import DemoPythonToolset, ErrorProneToolset
from toolset_registry.tool_call_impl import tool_raising_exceptions


class ToolCallTestCase(unittest.TestCase):
    """Test case base class with helpers for testing tool calls."""

    @contextlib.contextmanager
    def assertToolRaisesRuntimeError(self):
        with tool_raising_exceptions(), self.assertRaises(RuntimeError) as cm:
            yield cm


class DemoToolsetTestCase(unittest.TestCase):
    """Test case that provides a DemoPythonToolset for testing."""

    @classmethod
    def setUpClass(cls):
        unreal.ToolsetRegistry.register_toolset_class(DemoPythonToolset)

    @classmethod
    def tearDownClass(cls):
        unreal.ToolsetRegistry.unregister_toolset_class(DemoPythonToolset)

class ErrorProneToolsetTestCase(unittest.TestCase):
    """Test case that provides a ErrorProneToolset for testing."""

    @classmethod
    def setUpClass(cls):
        unreal.ToolsetRegistry.register_toolset_class(ErrorProneToolset)

    @classmethod
    def tearDownClass(cls):
        unreal.ToolsetRegistry.unregister_toolset_class(ErrorProneToolset)
