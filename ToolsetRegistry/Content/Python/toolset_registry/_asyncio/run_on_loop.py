# Copyright Epic Games, Inc. All Rights Reserved.
"""Functionality to run on an asyncio loop while handling ContextLoopRunner."""

from __future__ import annotations
from asyncio import iscoroutine, AbstractEventLoop, CancelledError, Task
from collections.abc import Awaitable, Callable
from concurrent.futures import Future
from contextvars import Context
from functools import wraps
from typing import Any

from .context_loop_runner import ContextLoopRunner, ReturnT
from .utilities import get_event_loop_or_none


def run_async_on_loop(
    loop: AbstractEventLoop,
    awaitable: Awaitable[ReturnT],
    context: Context | ContextLoopRunner | None = None
) -> Future[ReturnT]:
    """Run a coroutine or awaitable on the specified loop.

    Args:
        loop: Loop to run the coroutine on.
        awaitable: Awaitable to run.
        context: Context to use when running coro.

    Returns:
        Future that resolves to the result of coro.

    Raises:
        ValueError: If the loop is set on the current thread.
    """
    if get_event_loop_or_none() is loop:
        raise ValueError(
            f'Cannot run and wait for {awaitable} on asyncio loop '
            f'{loop} as the loop is running on the current thread which cause '
            'deadlock.'
        )

    if iscoroutine(awaitable):
        coro = awaitable
    else:
        async def _awaitable_wrapper() -> ReturnT:
            """Wraps an awaitable with a coroutine."""
            return await awaitable

        coro = _awaitable_wrapper()

    future: Future[ReturnT] = Future()

    def _complete_future(task: Task[Any]) -> None:
        """Complete the captured future with the task's result.

        Args:
            task: Task to read the future's result from.
        """
        try:
            future.set_result(task.result())
        except CancelledError:
            future.cancel()
        # pylint: disable-next=broad-exception-caught
        except Exception as exception:
            future.set_exception(exception)

    def _schedule_task():
        """Schedule the coroutine on the loop."""
        task: Task[ReturnT] = loop.create_task(
            coro, context=ContextLoopRunner.get_context(context)
        )
        task.add_done_callback(_complete_future)

    # NOTE: This doesn't use run_coroutine_threadsafe() as it's not possible to
    # provide a context.
    _ = loop.call_soon_threadsafe(
        _schedule_task,
        context=ContextLoopRunner.get_context(context)
    )
    return future


def run_sync_on_loop(
    loop: AbstractEventLoop,
    func: Callable[[], ReturnT],
    context: Context | ContextLoopRunner | None = None
) -> ReturnT:
    """Run a callable on an asyncio loop.

    Args:
        loop: Loop to run the coroutine on.
        func: Callable to call.
        context: Context to use when running the callable.

    Returns:
        Result of the callable.
    """
    # If the event loop is on the current thread, run the callable now.
    if get_event_loop_or_none() is loop:
        return func()

    @wraps(func)
    async def _call_func_async() -> ReturnT:
        """Async wrapper around func."""
        return func()

    # Assume we're on a different thread to the asyncio loop and therefore
    # call the method using the asyncio loop and wait for the result.
    return run_async_on_loop(
        loop, _call_func_async(), context=context
    ).result()
