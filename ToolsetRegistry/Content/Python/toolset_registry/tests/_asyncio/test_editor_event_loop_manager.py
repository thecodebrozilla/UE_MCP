# Copyright Epic Games, Inc. All Rights Reserved.
"""Test editor_event_loop_manager."""
from asyncio import (
    get_event_loop, run, set_event_loop, sleep, AbstractEventLoop, Task
)
from contextlib import contextmanager
from datetime import timedelta
from time import perf_counter
from typing import Any, Generator
from unittest import mock
import unittest

from toolset_registry._asyncio.editor_event_loop_manager import (
    EditorEventLoopManager,
    _EditorEventLoopManager,
    _ReferenceCountedEditorEventLoopManager
)
from toolset_registry._asyncio.pollable_event_loop import (
    PollableEventLoop,
    _BaseEventLoop
)
from toolset_registry._asyncio.timeout_poller import TimeoutPoller
from . import run_test_on_thread
from .test_editor_thread_ticker import (
    configure_editor_thread_ticker,
    FakeTickableUnrealModule
)
from .test_timeout_poller import TimeoutPollerUsingFakePerfCounter


class TestEditorEventLoopManager(unittest.TestCase):
    """Test editor event loop."""

    _get_main_thread_ident: mock.Mock
    _fake_unreal_module: FakeTickableUnrealModule
    _ref_counted_event_loop_manager: _ReferenceCountedEditorEventLoopManager
    _timeout_poller: TimeoutPollerUsingFakePerfCounter

    def _create_ref_counted_editor_event_loop_manager(
        self, timeout_poller: TimeoutPoller
    ) -> None:
        """Create / recreate the ref counted editor event loop manager.

        Args:
            timeout_poller: Timeout poller to use.
        """
        self._timeout_poller = (
            TimeoutPollerUsingFakePerfCounter.from_timeout_poller(
                timeout_poller
            )
        )
        # Create a reference counted event loop manager for this test.
        self._ref_counted_event_loop_manager = (
            _ReferenceCountedEditorEventLoopManager(self._timeout_poller)
        )

    @contextmanager
    def _setup(self) -> Generator[None, None, None]:
        """Set up the test case for a test.

        This is not implemented in setUp() as some tests require the setup to
        be executed on a background thread.
        """
        with (
            configure_editor_thread_ticker() as (
                fake_unreal_module, get_main_thread_ident, _
            )
        ):
            self._get_main_thread_ident = get_main_thread_ident
            self._fake_unreal_module = fake_unreal_module
            self._create_ref_counted_editor_event_loop_manager(
                # pylint: disable=protected-access
                _EditorEventLoopManager()._timeout_poller
            )
            yield
            # Tick to allow the event loop manager to clean itself up.
            self._fake_unreal_module.tick()

    def create_editor_event_loop_manager(self) -> EditorEventLoopManager:
        """Create an editor event loop manager for this test.

        Returns:
            EditorEventLoopManager that doesn't reference global state.
        """
        manager = EditorEventLoopManager()
        # pylint: disable=protected-access
        manager._ref_counted_event_loop_manager = self._ref_counted_event_loop_manager
        return manager

    @run_test_on_thread
    def test_registers_event_loop(self):
        """Ensure the manager installs an event loop."""
        with self.create_editor_event_loop_manager() as manager:
            self.assertIsInstance(get_event_loop(), PollableEventLoop)
            self.assertIs(get_event_loop(), manager.loop)

    @run_test_on_thread
    def test_registers_event_loop_from_non_main_thread(self):
        """Ensure the manager installs an event loop from a non-main thread."""
        self._get_main_thread_ident.return_value = (
            self._get_main_thread_ident.return_value + 1
        )
        with self.create_editor_event_loop_manager() as manager:
            with self.assertRaises(RuntimeError):
                get_event_loop()
            with self.assertRaises(RuntimeError):
                _ = manager.loop

            self._fake_unreal_module.tick()
            self.assertIsInstance(get_event_loop(), PollableEventLoop)
            self.assertIs(get_event_loop(), manager.loop)

    @run_test_on_thread
    def test_unregisters_event_loop(self):
        """Ensure the manager uninstalls an event loop."""
        with self.create_editor_event_loop_manager() as _:
            pass
        with self.assertRaises(RuntimeError):
            get_event_loop()

    @run_test_on_thread
    def test_can_nest_event_loop_registration(self):
        """Event loop registration should be reference counted."""
        with self.create_editor_event_loop_manager() as manager:
            with manager:  # Nesting again shouldn't do anything.
                with self.create_editor_event_loop_manager() as _:
                    self.assertIsInstance(get_event_loop(), PollableEventLoop)
            self.assertIsInstance(get_event_loop(), PollableEventLoop)

        with self.assertRaises(RuntimeError):
            _ = get_event_loop()

    @run_test_on_thread
    def test_unsubscribes_from_tick_event_on_close(self):
        """Ensure unsubscription from the tick event on close."""
        with self.create_editor_event_loop_manager() as _:
            pass
        self.assertDictEqual(self._fake_unreal_module.tick_callbacks, {})

    @run_test_on_thread
    def test_runs_tasks(self):
        """Ensure the event loop can run tasks."""
        with self.create_editor_event_loop_manager() as manager:
            tasks_and_expected_result: list[tuple[Task[Any], int]] = []
            for result in [42, 24, 12]:
                async_mock = mock.AsyncMock(return_value=result)
                tasks_and_expected_result.append(
                    (manager.loop.create_task(async_mock()), result))

            self._fake_unreal_module.tick()
            for task, expected_result in tasks_and_expected_result:
                self.assertTrue(task.done())
                self.assertEqual(task.result(), expected_result)


    def _schedule_chained_task(
            self, manager: EditorEventLoopManager,
            main_task_yields: bool = True
        ) -> list[Task[Any]]:
        """Schedule a task that yields and then creates another task.

        Args:
            manager: Event loop manager to schedule task with.
            main_task_yields: Whether the main task should yield before
                starting the final task.

        Returns:
            List that is updated with scheduled tasks.
        """
        tasks: list[Task[Any]] = []

        internal_event_loop_manager = (
            manager._ref_counted_event_loop_manager
            ._event_loop_manager
        )
        assert internal_event_loop_manager

        loop = manager.loop

        def advance_time():
            """Advance time a fraction of a tick"""
            self._timeout_poller.fake_perf_counter.advance_time(
                # pylint: disable=protected-access
                internal_event_loop_manager._timeout_poller.timeout / 4
            )

        async def last():
            """Do nothing."""
            advance_time()

        async def yield_then_schedule_last():
            """Schedule last() after yielding control."""
            if main_task_yields:
                await sleep(0)
            advance_time()
            tasks.append(loop.create_task(last()))
            advance_time()

        tasks.append(loop.create_task(yield_then_schedule_last()))
        return tasks

    @run_test_on_thread
    def test_runs_batches_of_tasks(self):
        """Ensure the event loop can run a batch of tasks."""
        with self.create_editor_event_loop_manager() as manager:
            tasks = self._schedule_chained_task(
                manager, main_task_yields=True
            )

            self._fake_unreal_module.tick()
            # All tasks should be complete.
            self.assertSequenceEqual(
                [task.done() for task in tasks],
                [True] * len(tasks),
                msg=str(tasks)
            )
            self.assertEqual(len(tasks), 2, msg=str(tasks))

    @run_test_on_thread
    def test_does_not_wait_on_retry(self):
        """Ensure no waiting on retry when new tasks are scheduled."""
        poll_retry_delay = timedelta(seconds=10)
        self._create_ref_counted_editor_event_loop_manager(
            TimeoutPoller(
                timedelta(seconds=30),
                poll_retry_delay=poll_retry_delay
            )
        )
        start_time = perf_counter()
        with self.create_editor_event_loop_manager() as manager:
            # Should not wait on initialization.
            elapsed = perf_counter() - start_time
            self.assertLess(elapsed, poll_retry_delay.total_seconds())

            start_time = perf_counter()
            tasks = self._schedule_chained_task(
                manager, main_task_yields=False
            )
            self._fake_unreal_module.tick()
            # Should not wait while tasks are enqueued.
            elapsed = perf_counter() - start_time
            self.assertLess(elapsed, poll_retry_delay.total_seconds())
            # All tasks should be complete.
            self.assertEqual(len(tasks), 2, msg=str(tasks))

    @run_test_on_thread
    def test_stops_tasks_on_close(self):
        """Ensure the event loop stops pending tasks on close."""
        with self.create_editor_event_loop_manager() as manager:
            async def _delayed_task():
                await sleep(0.0)

            task = manager.loop.create_task(_delayed_task())
        self.assertTrue(task.cancelled())

    @run_test_on_thread
    def test_unsubscribes_from_tick_event_on_no_tasks(self):
        """Test unsubscription from the tick event on task completion."""
        with self.create_editor_event_loop_manager() as manager:
            func = mock.AsyncMock(return_value=42)
            task = manager.loop.create_task(func())
            self._fake_unreal_module.tick()
            self.assertTrue(task.done())

            # As no tasks are scheduled the manager should unsubscribe the
            # tick event.
            self.assertDictEqual(self._fake_unreal_module.tick_callbacks, {})

    @run_test_on_thread
    def test_closes_existing_event_loop(self):
        """Ensure creation of an event loop closes an existing event loop.

        An asyncio event loop is installed on the main thread by default so
        this ensures it can be replaced with a pollable loop.
        """
        existing_loop: AbstractEventLoop = _BaseEventLoop()
        set_event_loop(existing_loop)
        with self.create_editor_event_loop_manager() as manager:
            loop = get_event_loop()
            self.assertIs(loop, manager.loop)
            self.assertIsNot(loop, existing_loop)
            self.assertTrue(existing_loop.is_closed())

        with self.assertRaises(RuntimeError):
            _ = get_event_loop()


if __name__ == '__main__':  # pragma: no cover
    async def run_unittest():
        """Run tests with an asyncio loop set."""
        unittest.main()

    run(run_unittest())
