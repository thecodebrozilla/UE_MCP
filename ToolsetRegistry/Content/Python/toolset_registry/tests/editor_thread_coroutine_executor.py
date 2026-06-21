# Copyright Epic Games, Inc. All Rights Reserved.
"""Executes a queue of coroutines on the editor thread."""

from __future__ import annotations
from asyncio import AbstractEventLoop, Task
import atexit
from collections import deque
from collections.abc import Coroutine
from contextlib import ExitStack
from datetime import timedelta
from threading import Lock
from typing import Any

from .._asyncio.timeout_poller import TimeoutPoller
from .._asyncio.editor_thread_ticker import EditorThreadTicker
from .._asyncio.editor_event_loop_manager import EditorEventLoopManager


class EditorThreadCoroutineExecutor(EditorThreadTicker):
    """Executes a queue of coroutines on the editor thread.

    Each coroutine is executed in a context with an asyncio event loop that
    runs coroutines on the editor thread. To schedule coroutines on the main
    thread from another thread use the loop property of this instance.
    """
    _instance_exit_stack = ExitStack()
    _instance_lock = Lock()
    _instance: 'EditorThreadCoroutineExecutor | None' = None

    # Maximum command execution time per tick.
    # Continue executing coroutines until this amount of time has elapsed or
    # no more coroutines are scheduled.
    _MAXIMUM_TICK_TIME = timedelta(milliseconds=16)
    # Time to wait before retrying polling, this allows another thread some
    # slack to schedule more tasks that could be executed on this thread.
    _RETRY_DELAY = timedelta(microseconds=500)

    def __init__(self):
        """Initialize the instance."""
        super().__init__()
        self._timeout_poller = TimeoutPoller(
            self._MAXIMUM_TICK_TIME, poll_retry_delay=self._RETRY_DELAY
        )
        self._event_loop_manager_exit_stack = ExitStack()
        self._scheduled: deque[Coroutine[None, None, None]] = deque()
        self._pending_task: Task[Any] | None = None
        self._event_loop_manager = EditorEventLoopManager()

    def schedule(self, coroutine: Coroutine[None, None, None]) -> None:
        """Schedule a coroutine to be executed.

        When calling from the editor thread the coroutine may be executed
        immediately.

        Args:
            coroutine: Coroutine to execute.
        """
        self._scheduled.append(coroutine)
        self._subscribe_to_and_maybe_fire_tick()

    @property
    def loop(self) -> AbstractEventLoop:
        """Event loop that run asyncio tasks on the editor thread."""
        return self._event_loop_manager.loop

    def _on_register(self) -> None:
        """Register the asyncio event loop manager."""
        self._event_loop_manager_exit_stack.close()
        self._event_loop_manager_exit_stack.enter_context(
            self._event_loop_manager)

    def _on_unregister(self) -> None:
        """Clean up the asyncio event loop manager."""
        self._event_loop_manager_exit_stack.close()

    def _on_tick(self, delta_time: float) -> None:
        """Execute a batch of commands until _MAXIMUM_TICK_TIME."""
        _ = delta_time
        self._timeout_poller.poll(self._execute_next_or_poll)

    def _execute_next_or_poll(self) -> bool:
        """Execute the next scheduled coroutine or poll for completion.

        Returns:
            True if a coroutine was scheduled or completed, False otherwise.
        """
        if self._pending_task:
            self._event_loop_manager.loop.poll()
            if not self._pending_task.done():
                return False
            self._pending_task = None

        try:
            coroutine = self._scheduled.popleft()
        except IndexError:
            self._unsubscribe_from_tick()
            return False
        self._pending_task = self.loop.create_task(coroutine)
        self._event_loop_manager.loop.poll()
        return True

    @classmethod
    def get_or_create(cls) -> 'EditorThreadCoroutineExecutor':
        """Get or create a global instance of this executor."""
        with cls._instance_lock:
            instance = cls._instance
            if instance is None:
                instance = cls._instance_exit_stack.enter_context(cls())
                atexit.register(cls._instance_exit_stack.close)
                cls._instance = instance
            return instance

    @classmethod
    def close(cls) -> None:
        """Destroy the global instance."""
        with cls._instance_lock:
            atexit.unregister(cls._instance_exit_stack.close)
            cls._instance_exit_stack.close()
            cls._instance = None
