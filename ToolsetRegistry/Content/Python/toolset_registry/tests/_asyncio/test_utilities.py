# Copyright Epic Games, Inc. All Rights Reserved.
"""Test very simple asyncio utilities."""

from asyncio import run
import unittest

from toolset_registry._asyncio.utilities import (
    get_event_loop_or_none
)
from . import run_test_on_thread


class TestGetEventLoopOrNone(unittest.TestCase):
    """Test very simple asyncio utilities."""

    @run_test_on_thread
    def test_with_no_loop(self):
        """Test getting the event loop from a thread with none."""
        self.assertIsNone(get_event_loop_or_none())

    @run_test_on_thread
    def test_with_a_loop(self):
        """Test getting the event loop from a thread with one set."""

        async def has_event_loop():
            self.assertIsNotNone(get_event_loop_or_none())

        run(has_event_loop())



if __name__ == '__main__':  # pragma: no cover
    unittest.main()
