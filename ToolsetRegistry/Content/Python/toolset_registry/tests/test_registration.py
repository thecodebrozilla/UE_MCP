# Copyright Epic Games, Inc. All Rights Reserved.
"""Test Registration."""

from contextlib import ExitStack
from unittest import mock
import unittest

import unreal

from ..registration import Registration

from .test_registry_interface import FakeToolsetRegistry

class MockToolset1:  # pylint: disable=too-few-public-methods
    """Mock toolset"""

class MockToolset2:  # pylint: disable=too-few-public-methods
    """Mock toolset"""


class TestRegistration(unittest.TestCase):
    """Test Registration."""

    def setUp(self):
        exit_stack = ExitStack()
        self.addCleanup(exit_stack.close)

        self._mock_toolsets: list[type] = [MockToolset1, MockToolset2]
        _ = exit_stack.enter_context(FakeToolsetRegistry.install())
        _ = exit_stack.enter_context(
            mock.patch.object(
                Registration, '_registry',
                new_callable=lambda *unused_args: FakeToolsetRegistry
            )
        )

    def create_registration(self) -> Registration:
        """Create registration instance with mock toolsets."""
        return Registration(self._mock_toolsets)

    def test_register_not_available(self):
        """Test registration when the toolset registry isn't available."""
        FakeToolsetRegistry.available = False
        registration = self.create_registration()
        self.assertFalse(registration.register())
        self.assertCountEqual(
            FakeToolsetRegistry.get_registered_toolset_classes(), []
        )

    def test_unregister_not_available(self):
        """Test unregistration when the toolset registry isn't available."""
        FakeToolsetRegistry.available = False
        registration = self.create_registration()
        registration.unregister()
        self.assertCountEqual(
            FakeToolsetRegistry.get_registered_toolset_classes(), []
        )

    def test_register_available(self):
        """Test registration when the toolset registry is available."""
        registration = self.create_registration()
        self.assertTrue(registration.register())
        self.assertCountEqual(
            FakeToolsetRegistry.get_registered_toolset_classes(),
            self._mock_toolsets
        )

    def test_unregister_available(self):
        """Test unregistration when the toolset registry is available."""
        registration = self.create_registration()
        registration.register()
        registration.unregister()
        self.assertCountEqual(
            FakeToolsetRegistry.get_registered_toolset_classes(), []
        )
