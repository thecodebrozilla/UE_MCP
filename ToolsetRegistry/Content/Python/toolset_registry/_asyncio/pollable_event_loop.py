# Copyright Epic Games, Inc. All Rights Reserved.
"""asyncio event loop that must be polled to make progress."""
from __future__ import annotations

import asyncio
from asyncio import Handle, Future, Task, TimerHandle
from collections.abc import Callable, Coroutine
from concurrent.futures import Executor
from contextlib import contextmanager
from contextvars import Context
from threading import current_thread, RLock
from typing import Any, Generator, Sequence, TypeVar


ReturnT = TypeVar('ReturnT')


class PollableEventLoopError(RuntimeError):
    """Raised if a precondition of a pollable asyncio event loop fails."""


# asyncio.EventLoop is the public alias for the platform's default loop class,
# available from Python 3.12 onwards. For 3.11, fall back to the equivalent
# _loop_factory attribute on the default policy, which has been stable since 3.5.
_BaseEventLoop = getattr(
    asyncio, 'EventLoop',
    asyncio.DefaultEventLoopPolicy._loop_factory  # type: ignore[attr-defined]  # pylint: disable=protected-access
)


class _ScheduledTaskTracker:
    """Tracks scheduled tasks running in an asyncio loop."""

    def __init__(self):
        """Initialize tracking data."""
        self._on_scheduled_task_lock = RLock()
        self._internal_callables: set[Callable[..., None]] = set()
        self._running_callables: set[Callable[..., None]] = set()
        self._running_tasks: set[Task[Any]] = set()

    def track_internal_callable(self, callback: Callable[..., None]) -> None:
        """Track a callable that is executed when the loop is idle.

        Args:
            callback: Callable to track.
        """
        with self._on_scheduled_task_lock:
            self._internal_callables.add(callback)

    @contextmanager
    def track_running_handles(
            self, ready_handles: Sequence[Handle]
        ) -> Generator[None, None, None]:
        """Track currently running callables and their associated tasks.

        Tracks currently running callables and their associated tasks so they
        can be ignored if they're rescheduled while running an iteration of the
        pollable loop.

        Args:
            ready_handles: Handles to tasks that are ready to execute on the
                next loop iteration.
        """
        with self._on_scheduled_task_lock:
            self._clear_running_handles()
            self._track_running_handles(ready_handles)
        try:
            yield
        finally:
            with self._on_scheduled_task_lock:
                self._clear_running_handles()

    def should_notify_on_callable(
            self, callback: Callable[[], None],
            is_running_or_pending: bool
        ) -> bool:
        """Whether scheduling a callable should result in a task notification.

        Args:
            callback: Callable to query.
            is_running_or_pending: Whether the loop has tasks ready to execute
                or any scheduled tasks.

        Returns:
            True to send a notification for the callable, False otherwise.
        """
        with self._on_scheduled_task_lock:
            if callback in self._internal_callables:
                return False
            if not is_running_or_pending:
                return True
            if callback in self._running_callables:
                return False
            maybe_task = self._get_task_from_callback(callback)
            if maybe_task and maybe_task in self._running_tasks:
                return False
            return True

    def _clear_running_handles(self) -> None:
        """Clear all tracked running callables and their tasks."""
        self._running_callables.clear()
        self._running_tasks.clear()

    def _track_running_handles(self, ready_handles: Sequence[Handle]) -> None:
        """Track currently running callables and their associated tasks.

        Tracks currently running callables and their associated tasks so they
        can be ignored if they're rescheduled while running an iteration of the
        pollable loop.

        Args:
            ready_handles: Handles to tasks that are ready to execute on the
                next loop iteration.
        """
        for handle in ready_handles:
            self._track_running_callable(
                # pylint: disable=protected-access
                handle._callback  # type: ignore[attr-defined]
            )

    def _track_running_callable(self, callback: Callable[..., None]) -> None:
        """Track a callable.

        Args:
            callback: Callable to track.
        """
        self._running_callables.add(callback)
        maybe_task = self._get_task_from_callback(callback)
        if maybe_task:
            self._running_tasks.add(maybe_task)

    @staticmethod
    def _get_task_from_callback(
        callback: Callable[..., Any]
    ) -> Task[Any] | None:
        """Get the task associated with a callback, if any.

        Args:
            callback: Callable to query.

        Returns:
            Task if one is associated, None otherwise.
        """
        maybe_task: Task[Any] | None = None
        if (
            hasattr(callback, '__self__') and
            isinstance(callback.__self__, Task)  # type: ignore
        ):
            maybe_task = callback.__self__  # type: ignore
        return maybe_task


class PollableEventLoop(_BaseEventLoop):  # type: ignore[valid-type, misc]
    """asyncio event loop that must be polled to make progress."""

    def __init__(
            self, use_polling: bool = False,
            on_scheduled_task: Callable[[], None] | None = None):
        """Initialize an event loop.

        Args:
            use_polling: Whether to configure the event loop as pollable.
                If this is True, all blocking operations raise an exception and
                the loop must be polled using poll() to make progress.
                If this is False, the class prevents polling (via poll) and
                works in the same way as the default event loop.
            on_scheduled_task: Called whenever a task is scheduled.
        """
        self._notify_on_scheduled_task: (
            Callable[[Callable[..., Any]], None]
        ) = self.__notify_on_scheduled_task
        self._on_scheduled_task = on_scheduled_task
        self._task_tracker = _ScheduledTaskTracker()
        # NOTE: This has to happen after setting requirements for
        # _notify_on_scheduled_task() as some implementations can fire tasks
        # in __init__().
        super().__init__()  # type: ignore

        self._number_of_internal_tasks = 0
        self._poller_thread_id = (
            self._get_current_thread_id() if use_polling else None)

        # BaseProactorEventLoop always maintains a task to read from sockets
        # in the ready queue, so run a loop and ignore that task (along with
        # any others) that are added when considering whether tasks are
        # pending.
        running_tasks = len(self._ready)
        self._notify_on_scheduled_task = (
            self._task_tracker.track_internal_callable
        )
        self._poll()
        self._number_of_internal_tasks = len(self._ready) - running_tasks
        self._notify_on_scheduled_task = self.__notify_on_scheduled_task

    def call_soon(
        self, callback: Callable[..., None], *args: Any,
        context: Context | None = None
    ) -> Handle:
        """Call a callback on the next event loop update.

        Args:
            callback: Callable to run on the loop.
            *args: Arguments for callback.
            context: Context to use.

        Return:
            Handle that can be used to cancel the scheduled execution.
        """
        result = super().call_soon(  # type: ignore
            callback, *args, context=context
        )
        assert isinstance(result, Handle)
        self._notify_on_scheduled_task(callback)
        return result

    def call_later(
        self, delay: float, callback: Callable[..., None], *args: Any,
        context: Context | None = None
    ) -> TimerHandle:
        """Call a callback at the specified time.

        Args:
            delay: Delay in seconds until running the callback.
            callback: Callable to run on the loop.
            *args: Arguments for callback.
            context: Context to use.

        Return:
            Handle that can be used to cancel the scheduled execution.
        """
        result = super().call_later(  # type: ignore
            delay, callback, *args, context=context
        )
        assert isinstance(result, TimerHandle)
        self._notify_on_scheduled_task(callback)
        return result

    def call_at(
        self, when: float, callback: Callable[..., None], *args: Any,
        context: Context | None = None
    ) -> TimerHandle:
        """Call a callback at the specified time.

        Args:
            when: When to run the callback.
            callback: Callable to run on the loop.
            *args: Arguments for callback.
            context: Context to use.

        Return:
            Handle that can be used to cancel the scheduled execution.
        """
        result = super().call_at(  # type: ignore
            when, callback, *args, context=context
        )
        assert isinstance(result, TimerHandle)
        self._notify_on_scheduled_task(callback)
        return result

    def call_soon_threadsafe(
        self, callback: Callable[..., None], *args: Any,
        context: Context | None = None
    ) -> Handle:
        """Thread safely call a callback on the next event loop update.

        Args:
            callback: Callable to run on the loop.
            *args: Arguments for callback.
            context: Context to use.

        Return:
            Handle that can be used to cancel the scheduled execution.
        """
        result = super().call_soon_threadsafe(  # type: ignore
            callback, *args, context=context
        )
        assert isinstance(result, Handle)
        self._notify_on_scheduled_task(callback)
        return result

    def run_in_executor(
        self, executor: Executor | None, func: Callable[..., ReturnT],
        *args: Any
    ) -> Future[ReturnT]:
        """Run a callable in specified executor.

        Args:
            executor: Executor to run func on, or None to use the loop's
                default executor.
            func: Callable to run.
            *args: Arguments for func.

        Returns:
            Future that resolves to the result of func.
        """
        future_result = super().run_in_executor(  # type: ignore
            executor, func, *args
        )
        self._notify_on_scheduled_task(func)
        return future_result  # type: ignore

    @property
    def poller_thread_id(self) -> int | None:
        """Thread ID that the event loop can be polled on, if any."""
        return self._poller_thread_id

    def run_forever(self) -> None:
        """Raise PollableEventLoopError if called from the poller thread."""
        self._assert_not_poller_thread(self.run_forever.__name__)
        super().run_forever()  # type: ignore

    def run_until_complete(
            self, future: Future[ReturnT] | Coroutine[Any, Any, ReturnT]
        ) -> Future[ReturnT]:
        """Raise PollableEventLoopError if called from the poller thread."""
        self._assert_not_poller_thread(self.run_until_complete.__name__)
        return super().run_until_complete(future)  # type: ignore

    def poll(self) -> None:
        """Execute one iteration of the event loop."""
        self._assert_on_poller_thread(self.poll.__name__)
        self._poll()

    def _poll(self) -> None:
        """Unconditionally execute one iteration of the event loop."""
        # Schedule stop to run only one iteration.
        with self._task_tracker.track_running_handles(self._ready):
            super().call_soon(self.stop)  # type: ignore
            super().run_forever()  # type: ignore

    def is_running_or_pending(self) -> bool:
        """Whether the loop is running or any tasks are pending."""
        return self.is_running() or self._tasks_pending

    @property
    def _tasks_pending(self) -> bool:
        """Whether any tasks are pending."""
        has_ready_tasks = len(self._ready) > self._number_of_internal_tasks
        return bool(has_ready_tasks or self._scheduled)

    def _assert_not_poller_thread(self, method: str) -> None:
        """Ensure the current thread is not the polling thread.

        Args:
            method: Method name to add to a raised exception.

        Raises:
            PollableEventLoopError: If the current thread is the polling
                thread.
        """
        if (
            self.poller_thread_id is not None
            and self._get_current_thread_id() == self.poller_thread_id
        ):
            raise PollableEventLoopError(
                f'{type(self)}.{method}() was called from the poller thread '
                f'(id={self.poller_thread_id}), which must not be blocked.  '
                'Use poll() instead.'
            )

    def _assert_on_poller_thread(self, method: str) -> None:
        """Ensure the event loop has a poller thread and is on the thread.

        Args:
            method: Method name to add to a raised exception.

        Raises:
            PollableEventLoopError: If event loop doesn't have a configured
            poller thread.
        """
        if self.poller_thread_id is None:
            raise PollableEventLoopError(
                f'{type(self)}.{method}() was called without a poller thread '
                'specified. This is not supported, use run_forever() or '
                'run_until_complete() instead.'
            )
        if not self._is_poller_thread:
            raise PollableEventLoopError(
                f'{type(self)}.{method}() was called on a different thread to '
                'the configured poller thread.'
            )

    @property
    def _is_poller_thread(self) -> bool:
        """Whether the current thread is the poller thread."""
        return self.poller_thread_id == self._get_current_thread_id()

    def __notify_on_scheduled_task(self, callback: Callable[[], None]) -> None:
        """Notify the _on_scheduled_task callable.

        Args:
            callback: Callable being scheduled.
        """
        on_scheduled_task: Callable[[], None] | None = self._on_scheduled_task
        if (
            on_scheduled_task and
            self._task_tracker.should_notify_on_callable(
                callback, self.is_running_or_pending()
            )
        ):
            on_scheduled_task()

    @staticmethod
    def _get_current_thread_id() -> int:
        """Get the current thread ID.

        Returns:
            Current thread ID.
        """
        ident = current_thread().ident
        assert isinstance(ident, int)
        return ident
