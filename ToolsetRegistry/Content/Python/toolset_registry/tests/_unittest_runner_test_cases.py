# Copyright Epic Games, Inc. All Rights Reserved.
"""Test cases used by test_unittest_runner."""

from asyncio import sleep
import unittest

class TestSuccess(unittest.TestCase):
    """A test that succeeds"""

    _class_is_set_up = False

    @classmethod
    def setUpClass(cls):
        cls._class_is_set_up = True

    @classmethod
    def tearDownClass(cls):
        cls._class_is_set_up = False

    def setUp(self):
        self._is_set_up = True

    def tearDown(self):
        self._is_set_up = False

    def test_succeed(self):
        """Ensures the test case is set up."""
        self.assertTrue(self._is_set_up)
        self.assertTrue(self._class_is_set_up)


class TestFailure(unittest.TestCase):
    """A test that fails"""

    def test_fail(self):
        """Fails"""
        self.assertTrue(False)  # pylint: disable=redundant-unittest-assert

    def test_error(self):
        """Causes error"""
        eval('1 = 2')  # pylint: disable=eval-used


class TestAsyncio(unittest.IsolatedAsyncioTestCase):
    """Asyncio test."""

    async def asyncSetUp(self):
        self._is_set_up = True

    async def asyncTearDown(self):
        self._is_set_up = False

    async def test_async(self):
        """Ensure the test case is set up."""
        await sleep(0.0)
        self.assertTrue(self._is_set_up)
