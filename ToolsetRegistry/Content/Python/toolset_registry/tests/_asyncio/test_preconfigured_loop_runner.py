# Copyright Epic Games, Inc. All Rights Reserved.
"""Tests for an asyncio.Runner that uses a pre-configured asyncio loop."""

from contextvars import copy_context, ContextVar
from unittest import mock
import unittest

from toolset_registry._asyncio.preconfigured_loop_runner import (
    PreconfiguredLoopRunner
)
from . import run_test_on_thread
from .test_run_on_loop import (
    create_loop, run_on_thread_and_wait_for_completion
)


class TestPreconfiguredLoopRunner(unittest.TestCase):
    """Test PreconfiguredLoopRunner."""

    @run_test_on_thread
    def test_get_loop(self):
        """Test getting the loop from the runner."""
        with create_loop() as loop:
            runner = PreconfiguredLoopRunner(loop)
            self.assertIs(runner.get_loop(), loop)

    @run_test_on_thread
    def test_context_does_nothing(self):
        """Ensure the context manager behavior does nothing."""
        with (
            create_loop() as loop,
            PreconfiguredLoopRunner(loop) as runner
        ):
            self.assertIs(runner.get_loop(), loop)

    @run_test_on_thread
    def test_close_does_nothing(self):
        """Ensure calling close on the runner does nothing."""
        with (
            create_loop() as loop,
            mock.patch.object(
                loop, 'close', side_effect=loop.close
            ) as mock_close,
            PreconfiguredLoopRunner(loop) as runner
        ):
            runner.close()
            mock_close.assert_not_called()

    @run_test_on_thread
    def test_run(self):
        """Test running a coroutine."""
        with (
            create_loop() as loop,
            PreconfiguredLoopRunner(loop) as runner
        ):
            expected_result = 42
            async_mock = mock.AsyncMock(return_value=expected_result)
            result = run_on_thread_and_wait_for_completion(
                lambda: runner.run(async_mock()), loop
            )
            self.assertEqual(result, expected_result)

    @run_test_on_thread
    def test_run_with_context(self):
        """Test running a coroutine with custom contextvars"""
        with (
            create_loop() as loop,
            PreconfiguredLoopRunner(loop) as runner
        ):
            magic_contextvar_initial_value = 42
            magic_contextvar: ContextVar[int] = ContextVar('magic')
            magic_contextvar.set(magic_contextvar_initial_value)
            context = copy_context()

            self.assertIn(magic_contextvar, context)
            self.assertEqual(
                magic_contextvar.get(), magic_contextvar_initial_value
            )

            async def _modify_context() -> int:
                next_value = magic_contextvar.get() + 1
                magic_contextvar.set(next_value)
                return next_value

            result = run_on_thread_and_wait_for_completion(
                lambda: runner.run(_modify_context(), context=context), loop
            )
            self.assertEqual(result, magic_contextvar_initial_value + 1)
            # The current context should not be modified.
            self.assertEqual(
                magic_contextvar.get(), magic_contextvar_initial_value
            )


if __name__ == '__main__':  # pragma: no cover
    unittest.main()
