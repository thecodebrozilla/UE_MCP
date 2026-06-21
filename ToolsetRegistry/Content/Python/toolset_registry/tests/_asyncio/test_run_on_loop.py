# Copyright Epic Games, Inc. All Rights Reserved.
"""Test run_on_loop"""

from asyncio import set_event_loop, CancelledError
from collections.abc import Callable
from contextvars import copy_context, ContextVar
from concurrent.futures import (
    CancelledError as ConcurrentFuturesCancelledError,
    Future, ThreadPoolExecutor
)
from contextlib import closing, contextmanager
from datetime import timedelta
from typing import Any, Generator, TypeVar
from unittest import mock
import unittest

from toolset_registry._asyncio.pollable_event_loop import (
    PollableEventLoop
)
from toolset_registry._asyncio.timeout_poller import TimeoutPoller
from toolset_registry._asyncio.run_on_loop import (
    run_async_on_loop,
    run_sync_on_loop
)
from . import run_test_on_thread


@contextmanager
def create_loop() -> Generator[PollableEventLoop, None, None]:
    """Context manager yielding a pollable asyncio loop."""
    with closing(PollableEventLoop(use_polling=True)) as loop:
        yield loop


def poll_loop_until_future_is_complete(
    loop: PollableEventLoop, future: Future[Any]
) -> None:
    """Poll a pollable loop and future until the future is complete.

    Args:
        loop: Loop to poll.
        future: Future to poll for completion.
    """
    poller = TimeoutPoller(
        timedelta(seconds=10),
        poll_interval=timedelta(milliseconds=1),
        poll_retry_delay=timedelta(milliseconds=1),
    )

    def _poll_until_complete() -> bool:
        loop.poll()
        return not future.done()

    poller.poll(_poll_until_complete)


ResultT = TypeVar('ResultT')

def run_on_thread_and_wait_for_completion(
    func: Callable[[], ResultT], loop: PollableEventLoop
) -> ResultT:
    """Run a callable on a thread and poll a loop for completion.

    Args:
        func: Callable to run on a thread that will schedule an execution on
            an asyncio loop.
        loop: Loop to poll.

    Returns:
        Result of the callable.
    """
    executor = ThreadPoolExecutor(max_workers=1)
    try:
        result_future = executor.submit(func)
        poll_loop_until_future_is_complete(loop, result_future)
        return result_future.result()
    finally:
        executor.shutdown(wait=False)


class TestRunAsyncOnLoop(unittest.TestCase):
    """Test running a task on an asyncio loop that completes a future."""

    @run_test_on_thread
    def test_run_coroutine(self):
        """"Test running a coroutine."""
        with create_loop() as loop:
            expected_result = 42
            async_mock = mock.AsyncMock(return_value=expected_result)
            result_future = run_async_on_loop(loop, async_mock())
            poll_loop_until_future_is_complete(loop, result_future)
            self.assertEqual(result_future.result(), expected_result)

    @run_test_on_thread
    def test_run_coroutine_that_is_cancelled(self):
        """"Test running a coroutine that is cancelled."""
        with create_loop() as loop:
            async_mock = mock.AsyncMock(side_effect=CancelledError)
            result_future = run_async_on_loop(loop, async_mock())
            poll_loop_until_future_is_complete(loop, result_future)
            with self.assertRaises(ConcurrentFuturesCancelledError):
                _ = result_future.result()

    @run_test_on_thread
    def test_run_awaitable(self):
        """"Test running an awaitable."""
        with create_loop() as loop:
            expected_result = 42
            awaitable = loop.create_future()
            result_future = run_async_on_loop(loop, awaitable)
            awaitable.set_result(expected_result)
            poll_loop_until_future_is_complete(loop, result_future)
            self.assertEqual(result_future.result(), expected_result)

    @run_test_on_thread
    def test_run_with_contextvars(self):
        """Test running with contextvars"""
        with create_loop() as loop:
            context_val: ContextVar[int] = ContextVar('val')
            context_val.set(1)

            async def modify_context() -> int:
                context_val.set(context_val.get() + 1)
                return context_val.get()

            result_future = run_async_on_loop(
                loop, modify_context(), context=copy_context()
            )
            poll_loop_until_future_is_complete(loop, result_future)
            self.assertEqual(result_future.result(), 2)
            # Context var should be unmodified outside of the execution
            # context.
            self.assertEqual(context_val.get(), 1)


class TestRunSyncOnLoop(unittest.TestCase):
    """Test running a synchronous function on an asyncio loop."""

    @run_test_on_thread
    def test_run_from_current_thread(self):
        """Test running a function on the thread with the loop."""
        with create_loop() as loop:
            set_event_loop(loop)
            expected_result = 24
            mock_func = mock.Mock(return_value=expected_result)
            # Shouldn't need to execute the loop.
            result = run_sync_on_loop(loop, mock_func)
            self.assertEqual(result, expected_result)

    @run_test_on_thread
    def test_run_from_another_thread(self):
        """Test running a function on the loop from another thread."""
        with create_loop() as loop:
            set_event_loop(loop)
            expected_result = 12
            mock_func = mock.Mock(return_value=expected_result)
            result = run_on_thread_and_wait_for_completion(
                lambda: run_sync_on_loop(loop, mock_func), loop
            )
            self.assertEqual(result, expected_result)


if __name__ == '__main__':  # pragma: no cover
    unittest.main()
