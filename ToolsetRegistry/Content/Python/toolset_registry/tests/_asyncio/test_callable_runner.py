# Copyright Epic Games, Inc. All Rights Reserved.
"""Test asyncio CallableRunner."""

from unittest import mock
import unittest

from toolset_registry._asyncio.callable_runner import CallableRunner
from toolset_registry._asyncio.utilities import get_event_loop_or_none
from .test_run_on_loop import (
    create_loop, run_on_thread_and_wait_for_completion
)
from . import run_test_on_thread


class _Accumulator:
    """Accumulates changes to a value."""

    def __init__(self):
        """Initialize the value."""
        self.value = 0

    def add(self, value: int) -> int:
        """Add the specified value to this object's value.

        Args:
            value: Value to add to this object's value.

        Returns:
            New value of this object.
        """
        self.value += value
        return self.value

    def subtract(self, value: int) -> int:
        """Subtract the specified value from this object's value.

        Args:
            value: Value to subtract from this object's value.

        Returns:
            New value of this object.
        """
        self.value -= value
        return self.value


class TestCallableRunner(unittest.TestCase):
    """Test asyncio CallableRunner."""

    @run_test_on_thread
    def test_call_on_loop(self):
        """Test running a function on an asyncio loop."""
        with create_loop() as loop:
            call_args = ('foo', 'bar')
            call_kwargs = {'bish': 'bosh'}
            expected_result = 42

            mock_callable = mock.Mock(return_value=expected_result)
            runner = CallableRunner(loop, mock_callable)
            result = run_on_thread_and_wait_for_completion(
                lambda: runner(*call_args, **call_kwargs), loop
            )
            mock_callable.assert_called_once_with(
                *call_args, **call_kwargs
            )
            self.assertEqual(result, expected_result)

    @run_test_on_thread
    def test_wrap_functions(self):
        """Test wrapping a synchronous method with a callable runner."""
        with create_loop() as loop:
            test = self

            class _AccumulatorChecksAddCalledFromloop(_Accumulator):
                """Checks add is called from the event loop."""

                def add(self, value: int) -> int:
                    test.assertIs(get_event_loop_or_none(), loop)
                    return super().add(value)

            accumulator = _AccumulatorChecksAddCalledFromloop()

            CallableRunner.wrap_functions(
                loop, accumulator, (accumulator.add,)
            )
            self.assertIsInstance(accumulator.add, CallableRunner)
            result = run_on_thread_and_wait_for_completion(
                lambda: accumulator.add(4), loop
            )
            self.assertEqual(result, 4)

    @run_test_on_thread
    def test_wrap_functions_missing_method_raises(self):
        """Test wrapping a missing method raises."""
        with create_loop() as loop:
            accumulator = _Accumulator()
            with self.assertRaises(AttributeError):
                CallableRunner.wrap_functions(
                    loop, accumulator, (lambda: None,)
                )

    @run_test_on_thread
    def test_wrap_functions_does_not_wrap_unspecified_functions(self):
        """Ensure function wrapping is not applied to callables that are not specified."""
        with create_loop() as loop:
            test = self

            class _AccumulatorSubtractNotCalledFromEventLoop(_Accumulator):
                """Checks subtract is not called from the event loop."""

                def subtract(self, value: int) -> int:
                    test.assertIsNone(get_event_loop_or_none(), None)
                    return super().subtract(value)

            accumulator = _AccumulatorSubtractNotCalledFromEventLoop()

            CallableRunner.wrap_functions(
                loop, accumulator, (accumulator.add,)
            )
            self.assertFalse(
                isinstance(accumulator.subtract, CallableRunner),
                msg=type(accumulator.subtract)
            )
            result = run_on_thread_and_wait_for_completion(
                lambda: accumulator.subtract(1), loop
            )
            self.assertEqual(result, -1)


if __name__ == '__main__':  # pragma: no cover
    unittest.main()
