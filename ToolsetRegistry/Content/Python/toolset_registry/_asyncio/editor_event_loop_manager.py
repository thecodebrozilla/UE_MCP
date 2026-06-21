# Copyright Epic Games, Inc. All Rights Reserved.
"""Manages an asyncio event loop on the editor's main thread."""

import asyncio
from contextlib import ExitStack
from datetime import timedelta
from threading import Event, Lock, RLock
from types import TracebackType

from .editor_thread_ticker import EditorThreadTicker
from .pollable_event_loop import PollableEventLoop
from .timeout_poller import TimeoutPoller
from .utilities import get_event_loop_or_none


class _StopPolling(Exception):
    """Raised when polling should stop including retries."""


class _EditorEventLoopManager(EditorThreadTicker):  # pylint: disable=too-few-public-methods
    """Manages an asyncio event loop on the editor's main thread."""

    # Maximum command execution time per tick.
    # Continue executing coroutines until this amount of time has elapsed or
    # no more coroutines are scheduled.
    _MAXIMUM_TICK_TIME = timedelta(milliseconds=16)
    # Time to wait before retrying polling, this allows another thread some
    # slack to schedule more tasks that could be executed on this thread.
    _RETRY_DELAY = timedelta(milliseconds=1)

    def __init__(self, timeout_poller: TimeoutPoller | None = None):
        """Initialize the event loop manager.

        Args:
            timeout_poller: Optional timeout poller with parameters to use in
                tests.
        """
        super().__init__()
        self._loop: PollableEventLoop | None = None
        self._tick_subscription_lock = RLock()
        self._task_notification_lock = Lock()
        self._task_notification_count = 0
        self._task_notification = Event()
        self._timeout_poller = timeout_poller or TimeoutPoller(
            self._MAXIMUM_TICK_TIME, poll_retry_delay=self._RETRY_DELAY
        )
        self._timeout_poller.set_wait(self._wait_for_task_notification)
        self._initializing = False

    @property
    def loop(self) -> PollableEventLoop:
        """Pollable event loop to schedule tasks on the editor's main thread.

        Raises:
            RuntimeError: If the event loop hasn't been created yet.
        """
        if not self._loop:
            raise RuntimeError('Event loop not created')
        return self._loop

    def _on_scheduled_task(self) -> None:
        """Handle a scheduled task event."""
        with self._tick_subscription_lock:
            self._subscribe_to_tick()
        self._add_task_notification()

    def _add_task_notification(self) -> None:
        """Track a task notification."""
        with self._task_notification_lock:
            self._task_notification_count += 1
            self._task_notification.set()

    def _reset_task_notification(self) -> None:
        """Reset the task notification count and clear the event."""
        with self._task_notification_lock:
            self._task_notification_count = 0
            if not self._initializing:
                self._task_notification.clear()
            else:
                self._initializing = False

    def _wait_for_task_notification(self, timeout_in_seconds: float) -> None:
        """Wait for a task notification or until the timeout elapses.

        Args:
            timeout_in_seconds: Maximum time to wait in seconds.
        """
        self._task_notification.wait(timeout=timeout_in_seconds)

    def _poll(self) -> bool:
        """Poll the loop, unsubscribing if no tasks are running or pending.

        Returns:
            True if tasks were scheduled during the last event loop poll,
            False otherwise.
        """
        self._reset_task_notification()
        self.loop.poll()
        task_notification_count = self._task_notification_count
        with self._tick_subscription_lock:
            if (
                not self.loop.is_running_or_pending() and
                task_notification_count == 0
            ):
                self._unsubscribe_from_tick()
                raise _StopPolling()
        return task_notification_count > 0

    def _on_tick(self, delta_time: float) -> None:
        """Poll the asyncio event loop."""
        _ = delta_time
        try:
            self._timeout_poller.poll(self._poll)
        except _StopPolling:
            pass

    def _on_register(self) -> None:
        """Set the event loop of the current thread.

        Raises:
            RuntimeError: If a different event loop is already set on the
                thread.
        """
        loop = self._get_or_create_event_loop()

        # Assign the event loop to the current thread's asyncio loop.
        existing_event_loop = get_event_loop_or_none()
        existing_event_loop_is_not_this_loop = existing_event_loop is not loop
        if existing_event_loop_is_not_this_loop:
            if existing_event_loop:
                self._close_event_loop(existing_event_loop)
            asyncio.set_event_loop(loop)

    def _on_unregister(self) -> None:
        """Clear the event loop of the current thread."""
        event_loop = get_event_loop_or_none()
        if event_loop and event_loop is self.loop and self._loop:
            self._close_event_loop(self._loop)
            self._loop = None

    @staticmethod
    def _close_event_loop(
        loop: asyncio.AbstractEventLoop | PollableEventLoop) -> None:
        """Try to close and clear specified event loop."""
        try:
            # Cancel tasks.
            assert (
                asyncio.current_task(loop=loop) is None
            ), 'asyncio Loop cannot be closed from a task'
        except RuntimeError:
            pass  # Ignore runtime error if the loop isn't running.
        tasks = asyncio.all_tasks(loop=loop)
        for task in tasks:
            task.cancel()
        # Wait for cancellation.
        cancellation = asyncio.gather(*tasks)

        if isinstance(loop, PollableEventLoop):
            while loop.is_running_or_pending():
                loop.poll()
        else:
            # Flush the loop.
            asyncio.run(asyncio.sleep(0.0))

        try:
            _ = cancellation.exception()
        except Exception:  # pylint: disable=broad-exception-caught
            pass  #  Ignore any exceptions on cancellation.

        # Close and clear the loop.
        loop.close()
        asyncio.set_event_loop(None)

    def _get_or_create_event_loop(self) -> PollableEventLoop:
        """Create a pollable event loop.

        Returns:
            PollableEventLoop instance tied to this object.
        """
        # Create the loop on the tick thread if it doesn't exist.
        if self._loop is None:
            # Don't wait on the initial poll when the loop is created.
            self._add_task_notification()
            self._initializing = True
            self._loop = PollableEventLoop(
                use_polling=True, on_scheduled_task=self._on_scheduled_task
            )
        return self.loop


class _ReferenceCountedEditorEventLoopManager:
    """Creates an asyncio event loop on the editor's main thread."""

    def __init__(self, timeout_poller: TimeoutPoller | None = None):
        """Initialize the instance with no event loop manager.

        Args:
            timeout_poller: Optional timeout poller to use in tests.
        """
        self._timeout_poller = timeout_poller
        self._reference_count = 0
        self._exit_stack = ExitStack()
        self._event_loop_manager: _EditorEventLoopManager | None = None
        self._lock = Lock()

    def __enter__(self) -> '_ReferenceCountedEditorEventLoopManager':
        """Create or reference the editor main thread asyncio event loop."""
        with self._lock:
            if not self._event_loop_manager:
                self._event_loop_manager = self._exit_stack.enter_context(
                    _EditorEventLoopManager(self._timeout_poller)
                )
            self._reference_count += 1
        return self

    def __exit__(
            self, exc_type: type[BaseException] | None,
            exc_value: BaseException | None,
            traceback: TracebackType | None
        ) -> None:
        """Destroy or dereference the editor main thread asyncio event loop."""
        _ = (exc_type, exc_value, traceback)
        with self._lock:
            assert self._reference_count, '__exit__ called without __enter__'
            self._reference_count -= 1
            if not self._reference_count:
                self._event_loop_manager = None
                self._exit_stack.close()

    @property
    def loop(self) -> PollableEventLoop:
        """Pollable event loop to schedule tasks on the editor's main thread.

        Raises:
            RuntimeError: If the event loop hasn't been created yet.
        """
        assert self._event_loop_manager
        return self._event_loop_manager.loop


class EditorEventLoopManager:  # pragma: no cover
    """Creates an asyncio event loop on the editor's main thread."""

    _ref_counted_event_loop_manager = _ReferenceCountedEditorEventLoopManager()

    def __enter__(self) -> 'EditorEventLoopManager':
        """Create or reference the editor main thread asyncio event loop."""
        self._ref_counted_event_loop_manager.__enter__()
        return self

    def __exit__(
            self,
            exc_type: type[BaseException] | None,
            exc_value: BaseException | None,
            traceback: TracebackType | None
        ) -> None:
        """Destroy or dereference the editor main thread asyncio event loop."""
        self._ref_counted_event_loop_manager.__exit__(
            exc_type, exc_value, traceback
        )

    @property
    def loop(self) -> PollableEventLoop:
        """Pollable event loop to schedule tasks on the editor's main thread.

        Raises:
            RuntimeError: If the event loop hasn't been created yet.
        """
        return self._ref_counted_event_loop_manager.loop
