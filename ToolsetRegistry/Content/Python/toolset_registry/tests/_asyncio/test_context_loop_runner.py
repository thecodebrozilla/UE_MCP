"""Test ContextLoopRunner."""

from __future__ import annotations
from asyncio import AbstractEventLoop
from collections.abc import Callable
from contextvars import copy_context, Context, ContextVar
from functools import wraps
from typing import Any
from unittest import mock
import unittest

from toolset_registry._asyncio.context_loop_runner import (
    ContextLoopRunner, ReturnT
)
from toolset_registry._asyncio.pollable_event_loop import PollableEventLoop
from . import run_test_on_thread


def run_in_new_context(
    func: Callable[[Any], None]
) -> Callable[[Any], None]:
    """Decorator that runs a function in a new contextvars context."""
    @wraps(func)
    def _wrapper(self: Any) -> None:
        """Wraps func()."""
        context = copy_context()
        context.run(func, self)

    return run_test_on_thread(_wrapper)


# pylint: disable-next=too-many-public-methods
class TestContextLoopRunner(unittest.TestCase):
    """Test context loop runner."""

    def setUp(self):
        """Setup a mock that is called from run_sync_on_loop."""
        self._run_sync_on_loop_mock = mock.Mock(
            spec=self._run_sync_on_loop,
            side_effect=lambda unused_loop, func, unused_context: func()
        )

    def _run_sync_on_loop(
            self, loop: AbstractEventLoop, func: Callable[[], ReturnT],
            context: Context | 'ContextLoopRunner' | None = None
        ) -> ReturnT:
        """Call self._run_sync_on_loop_mock with the provided args."""
        return self._run_sync_on_loop_mock(loop, func, context)

    def _create_context_loop_runner(self) -> (
        tuple[Context, PollableEventLoop, ContextLoopRunner]
    ):
        """Create a context loop runner."""
        context = copy_context()
        loop = PollableEventLoop()
        runner = ContextLoopRunner(context, loop, self._run_sync_on_loop)
        return (context, loop, runner)

    @run_test_on_thread
    def test_init(self):
        """Test initializing a loop runner."""
        context, loop, runner = self._create_context_loop_runner()
        self.assertIs(runner.context, context)
        self.assertIs(runner.loop, loop)

    @run_test_on_thread
    def test_run(self):
        """Test running a callable on a loop with a context."""
        context, loop, runner = self._create_context_loop_runner()
        call_args = (1, 2)
        call_kwargs = {'three': 'four'}
        expected_return_value = 42
        mock_callable = mock.Mock(return_value=expected_return_value)

        result = runner.run(mock_callable, *call_args, **call_kwargs)
        self.assertEqual(result, expected_return_value)
        mock_callable.assert_called_once_with(*call_args, **call_kwargs)
        self._run_sync_on_loop_mock.assert_called_once_with(
            loop, mock.ANY, context
        )

    @run_test_on_thread
    def test_copy(self):
        """Test copying a loop runner."""
        _, _, runner = self._create_context_loop_runner()
        copy_of_runner = runner.copy()
        self.assertIsNot(runner, copy_of_runner)
        self.assertIs(copy_of_runner.context, runner.context)
        self.assertIs(copy_of_runner.loop, runner.loop)

    @staticmethod
    def create_context_var() -> ContextVar[int]:
        """Test a test context variable."""
        test_var: ContextVar[int] = ContextVar('test_var')
        test_var.set(42)
        return test_var

    def create_runner_and_var_out_of_context(self) -> (
        tuple[ContextLoopRunner, ContextVar[int]]
    ):
        """Create a runner and test variable outside of the context."""
        _, _, runner = self._create_context_loop_runner()
        test_var = self.create_context_var()
        return (runner, test_var)

    def create_runner_and_var_in_context(self) -> (
        tuple[ContextLoopRunner, ContextVar[int]]
    ):
        """Create a runner and test variable inside the context."""
        test_var = self.create_context_var()
        _, _, runner = self._create_context_loop_runner()
        return (runner, test_var)

    @run_in_new_context
    def test_contains_var_out_of_context(self):
        """Test contains with a variable out of the context"""
        runner, test_var = self.create_runner_and_var_out_of_context()
        self.assertNotIn(test_var, runner)

    @run_in_new_context
    def test_contains_var_in_context(self):
        """Test contains with a variable in context"""
        runner, test_var = self.create_runner_and_var_in_context()
        self.assertIn(test_var, runner)

    @run_in_new_context
    def test_getitem_var_out_of_context(self):
        """Ensure getitem does not return a variable out of the context"""
        runner, test_var = self.create_runner_and_var_out_of_context()
        with self.assertRaises(KeyError):
            _ = runner[test_var]

    @run_in_new_context
    def test_getitem_var_in_context(self):
        """Ensure getitem returns a variable in context"""
        runner, test_var = self.create_runner_and_var_in_context()
        self.assertEqual(runner[test_var], test_var.get())

    @run_in_new_context
    def test_get_var_out_of_context(self):
        """Ensure get does not return a variable out of the context"""
        runner, test_var = self.create_runner_and_var_out_of_context()
        self.assertIsNone(runner.get(test_var))

    @run_in_new_context
    def test_get_var_in_context(self):
        """Ensure get returns a variable in the context"""
        runner, test_var = self.create_runner_and_var_in_context()
        self.assertEqual(runner.get(test_var), test_var.get())

    @run_in_new_context
    def test_iter_var_out_of_context(self):
        """Ensure iter returns nothing with a variable out of the context"""
        runner, _ = self.create_runner_and_var_out_of_context()
        self.assertSequenceEqual(list(runner), [])

    @run_in_new_context
    def test_iter_var_in_context(self):
        """Ensure iter returns a variable in context"""
        runner, test_var = self.create_runner_and_var_in_context()
        self.assertSequenceEqual(list(runner), [test_var])

    @run_in_new_context
    def test_len_var_out_of_context(self):
        """Ensure len returns 0 with a variable out of context."""
        runner, _ = self.create_runner_and_var_out_of_context()
        self.assertEqual(len(runner), 0)

    @run_in_new_context
    def test_len_var_in_context(self):
        """Ensure len returns 1 with a variable in context."""
        runner, _ = self.create_runner_and_var_in_context()
        self.assertEqual(len(runner), 1)

    @run_in_new_context
    def test_items_var_out_of_context(self):
        """Ensure items is empty with a variable out of the context"""
        runner, _ = self.create_runner_and_var_out_of_context()
        self.assertSequenceEqual(list(runner.items()), [])

    @run_in_new_context
    def test_items_var_in_context(self):
        """Test items is with a variable in context"""
        runner, test_var = self.create_runner_and_var_in_context()
        self.assertSequenceEqual(
            list(runner.items()), [(test_var, test_var.get())]
        )

    @run_in_new_context
    def test_keys_var_out_of_context(self):
        """Ensure keys is empty with a variable out of the context"""
        runner, _ = self.create_runner_and_var_out_of_context()
        self.assertSequenceEqual(list(runner.keys()), [])

    @run_in_new_context
    def test_keys_var_in_context(self):
        """Test keys with a variable in context"""
        runner, test_var = self.create_runner_and_var_in_context()
        self.assertSequenceEqual(list(runner.keys()), [test_var])

    @run_in_new_context
    def test_values_var_out_of_context(self):
        """Ensure values is empty with a variable out of the context"""
        runner, _ = self.create_runner_and_var_out_of_context()
        self.assertSequenceEqual(list(runner.values()), [])

    @run_in_new_context
    def test_values_var_in_context(self):
        """Test values with a variable in context"""
        runner, test_var = self.create_runner_and_var_in_context()
        self.assertSequenceEqual(list(runner.values()), [test_var.get()])

    @run_in_new_context
    def test_get_context_with_none(self):
        """Ensure get_context() returns None when provided no context."""
        self.assertIsNone(ContextLoopRunner.get_context(None))

    @run_in_new_context
    def test_get_context_with_context(self):
        """Ensure get_context() returns the provided context."""
        context = copy_context()
        self.assertIs(ContextLoopRunner.get_context(context), context)

    @run_in_new_context
    def test_get_context_with_context_loop_runner(self):
        """Ensure get_context() returns the wrapped context."""
        _, _, runner = self._create_context_loop_runner()
        self.assertIs(ContextLoopRunner.get_context(runner), runner.context)


if __name__ == '__main__':  # pragma: no cover
    unittest.main()
