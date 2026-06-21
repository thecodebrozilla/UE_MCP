# Copyright Epic Games, Inc. All Rights Reserved.
"""Tests for PollableEventLoop."""

from asyncio import sleep as asyncio_sleep
from collections.abc import Generator
from concurrent.futures import ThreadPoolExecutor
from contextlib import closing, contextmanager
from time import sleep as time_sleep
from threading import current_thread
from typing import Callable
from unittest import mock
import unittest

from toolset_registry._asyncio.pollable_event_loop import (
    PollableEventLoop,
    PollableEventLoopError,
)
from . import run_test_on_thread

class TestPollableEventLoop(unittest.TestCase):
    """Tests for PollableEventLoop."""

    @staticmethod
    @contextmanager
    def _pollable_loop(
        on_scheduled_task: Callable[[], None] | None = None
    ) -> Generator[PollableEventLoop, None, None]:
        """Context manager yielding a PollableEventLoop configured for polling."""
        with closing(PollableEventLoop(
            use_polling=True, on_scheduled_task=on_scheduled_task
        )) as loop:
            yield loop

    @run_test_on_thread
    def test_poll_makes_forward_progress(self) -> None:
        """poll() must advance the task by exactly one step per call."""
        steps: list[int] = []

        async def multi_step() -> None:
            steps.append(1)
            await asyncio_sleep(0)
            steps.append(2)
            await asyncio_sleep(0)
            steps.append(3)

        with self._pollable_loop() as loop:
            task = loop.create_task(multi_step())

            loop.poll()
            self.assertEqual(steps, [1])

            loop.poll()
            self.assertEqual(steps, [1, 2])

            loop.poll()
            self.assertEqual(steps, [1, 2, 3])
            self.assertTrue(task.done())

    @run_test_on_thread
    def test_pollable_thread_id(self):
        """pollable_thread_id is the creator thread"""
        with self._pollable_loop() as loop:
            self.assertEqual(loop.poller_thread_id, current_thread().ident)

    @run_test_on_thread
    def test_is_running_or_pending_with_immediate_task(self):
        """Test is_running_or_pending() with an immediately executed task."""
        with (
            self._pollable_loop() as loop,
            self._create_callback_and_args() as (callback, callback_args)
        ):
            self.assertFalse(loop.is_running_or_pending())

            _ = loop.call_soon(callback, *callback_args)
            self.assertTrue(loop.is_running_or_pending())

            loop.poll()
            self.assertFalse(loop.is_running_or_pending())

    @run_test_on_thread
    def test_is_running_or_pending_with_delayed_task(self):
        """Test is_running_or_pending() with a delayed task."""
        with self._pollable_loop() as loop:
            self.assertFalse(loop.is_running_or_pending())

            future = loop.create_future()
            delay = 0.1
            _ = loop.call_later(delay, lambda: future.set_result(None))
            self.assertTrue(loop.is_running_or_pending())

            while not future.done():
                loop.poll()
                time_sleep(delay)
            self.assertFalse(loop.is_running_or_pending())

    @run_test_on_thread
    def test_pollable_run_forever_raises(self) -> None:
        """run_forever() must raise from the poller thread."""
        with self._pollable_loop() as loop:
            with self.assertRaises(PollableEventLoopError):
                loop.run_forever()

    @run_test_on_thread
    def test_pollable_run_until_complete_raises(self) -> None:
        """run_until_complete() must raise from the poller thread."""
        async def noop() -> None:
            pass

        with self._pollable_loop() as loop:
            coro = noop()
            with self.assertRaises(PollableEventLoopError):
                loop.run_until_complete(coro)
            coro.close()

    @classmethod
    @contextmanager
    def _pollable_notifying_loop(cls) -> (
        Generator[tuple[PollableEventLoop, mock.Mock], None, None]
    ):
        """Yields a loop and task notification handler."""
        notification_handler = mock.Mock()
        with cls._pollable_loop(on_scheduled_task=notification_handler) as (
                loop):
            yield (loop, notification_handler)

    @staticmethod
    @contextmanager
    def _create_callback_and_args() -> (
        Generator[tuple[mock.Mock, tuple[int, int]], None, None]
    ):
        """Callback and arguments that must be called before generator exit."""
        callback, callback_args = (mock.Mock(), (42, 24))
        try:
            yield (callback, callback_args)
        finally:
            callback.assert_called_once_with(*callback_args)

    @run_test_on_thread
    def test_notification_with_no_tasks(self) -> None:
        """Test task notifications with no tasks."""
        with self._pollable_notifying_loop() as (loop, notification_handler):
            notification_handler.assert_not_called()

            loop.poll()
            notification_handler.assert_not_called()

            # Implementations like ProactorEventLoop leave some internal tasks
            # in the ready queue, make sure they don't result in notifications
            # on the next loop execution.
            loop.poll()
            notification_handler.assert_not_called()

    @run_test_on_thread
    def test_notification_on_new_tasks(self) -> None:
        """Ensure task notifications only fire for new tasks."""
        with self._pollable_notifying_loop() as (loop, notification_handler):
            steps: list[int] = []  # Used to track progress from this function.

            async def sub_task() -> None:
                steps.append(3)
                await asyncio_sleep(0)
                steps.append(4)

            async def multi_step_task() -> None:
                steps.append(0)
                await asyncio_sleep(0)
                steps.append(1)
                await asyncio_sleep(0)
                steps.append(2)
                await loop.create_task(sub_task())

            task = loop.create_task(multi_step_task())
            notification_handler.assert_called_once_with()

            # Should stop on the first sleep.
            notification_handler.reset_mock()
            loop.poll()
            self.assertSequenceEqual(steps, [0])
            notification_handler.assert_not_called()

            # Should stop on the second sleep.
            notification_handler.reset_mock()
            loop.poll()
            self.assertSequenceEqual(steps, [0, 1])
            notification_handler.assert_not_called()

            # Should schedule the subtask.
            notification_handler.reset_mock()
            loop.poll()
            self.assertSequenceEqual(steps, [0, 1, 2])
            self.assertFalse(task.done())
            notification_handler.assert_called_once_with()

            while not task.done():
                loop.poll()
                time_sleep(0.01)

            self.assertSequenceEqual(steps, [0, 1, 2, 3, 4])

    @run_test_on_thread
    def test_notification_on_call_later(self) -> None:
        """Ensure call_later() notifies."""
        with (
            self._pollable_notifying_loop() as (loop, notification_handler),
            self._create_callback_and_args() as (callback, callback_args)
        ):
            loop.call_later(0, callback, *callback_args)
            # call_later() can result in multiple notifications.
            notification_handler.assert_called()
            loop.poll()

    @run_test_on_thread
    def test_notification_on_call_soon(self) -> None:
        """Ensure call_soon() notifies."""
        with (
            self._pollable_notifying_loop() as (loop, notification_handler),
            self._create_callback_and_args() as (callback, callback_args)
        ):
            loop.call_soon(callback, *callback_args)
            notification_handler.assert_called_once()
            loop.poll()

    @run_test_on_thread
    def test_notification_on_call_at(self) -> None:
        """Ensure call_at() notifies."""
        with (
            self._pollable_notifying_loop() as (loop, notification_handler),
            self._create_callback_and_args() as (callback, callback_args)
        ):
            loop.call_at(loop.time(), callback, *callback_args)
            notification_handler.assert_called_once()
            loop.poll()

    @run_test_on_thread
    def test_notification_on_create_task(self) -> None:
        """Ensure create_task() notifies."""
        with self._pollable_notifying_loop() as (loop, notification_handler):
            mock_coroutine = mock.AsyncMock()
            task = loop.create_task(mock_coroutine())
            notification_handler.assert_called_once()
            loop.poll()
            self.assertTrue(task.done())

    @run_test_on_thread
    def test_notification_on_call_soon_threadsafe(self) -> None:
        """Ensure call_soon_threadsafe() notifies."""
        with (
            self._pollable_notifying_loop() as (loop, notification_handler),
            self._create_callback_and_args() as (callback, callback_args)
        ):
            _ = loop.call_soon_threadsafe(callback, *callback_args)
            notification_handler.assert_called_once()
            loop.poll()
            callback.assert_called_once_with(*callback_args)

    @run_test_on_thread
    def test_notification_on_run_in_executor(self) -> None:
        """Ensure run_in_executor() notifies."""
        with (
            self._pollable_notifying_loop() as (loop, notification_handler),
            self._create_callback_and_args() as (callback, callback_args)
        ):
            with ThreadPoolExecutor(max_workers=1) as executor:
                result_future = loop.run_in_executor(
                    executor, callback, *callback_args
                )
                loop.poll()
                notification_handler.assert_called()
                self.assertTrue(result_future.done())
                callback.assert_called_once_with(*callback_args)

    @run_test_on_thread
    def test_polling_from_another_thread_raises(self) -> None:
        """Ensure polling from another thread raises."""
        with self._pollable_loop() as loop:
            with ThreadPoolExecutor(max_workers=1) as executor:
                result_future = executor.submit(loop.poll)

            with self.assertRaises(PollableEventLoopError):
                _ = result_future.result()

    @staticmethod
    @contextmanager
    def _regular_loop() -> Generator[PollableEventLoop, None, None]:
        """Context manager yielding a PollableEventLoop configured as a regular event loop."""
        with closing(PollableEventLoop(use_polling=False)) as loop:
            yield loop

    @run_test_on_thread
    def test_regular_run_forever_does_not_raise(self) -> None:
        """run_forever() must work normally on a non-pollable loop."""
        with self._regular_loop() as loop:
            loop.call_soon(loop.stop)
            loop.run_forever()  # must not raise

    @run_test_on_thread
    def test_regular_run_until_complete_does_not_raise(self) -> None:
        """run_until_complete() must work normally on a non-pollable loop."""
        async def answer() -> int:
            return 42

        with self._regular_loop() as loop:
            self.assertEqual(loop.run_until_complete(answer()), 42)

    @run_test_on_thread
    def test_regular_pollable_thread_id(self):
        """non-pollable loop has no creator thread set."""
        with self._regular_loop() as loop:
            self.assertIsNone(loop.poller_thread_id)

    @run_test_on_thread
    def test_regular_is_running_or_pending(self):
        """is_running_or_pending() returns False when complete."""
        with (
            self._regular_loop() as loop,
            self._create_callback_and_args() as (callback, callback_args)
        ):
            self.assertFalse(loop.is_running_or_pending())

            _ = loop.call_soon(callback, *callback_args)
            loop.call_soon(loop.stop)
            loop.run_forever()

            self.assertFalse(loop.is_running_or_pending())

    @run_test_on_thread
    def test_regular_poll_raises(self) -> None:
        """poll() must raise on a non-pollable loop."""
        with self._regular_loop() as loop:
            with self.assertRaises(PollableEventLoopError):
                loop.poll()


if __name__ == '__main__':  # pragma: no cover
    unittest.main()
