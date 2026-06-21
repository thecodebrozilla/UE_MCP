# Copyright Epic Games, Inc. All Rights Reserved.
"""Safely runs a callable on an asyncio loop."""

from asyncio import AbstractEventLoop
from collections.abc import Callable
from functools import wraps
from typing import Any, Generic, Sequence

from .run_on_loop import run_sync_on_loop, ReturnT


class CallableRunner(Generic[ReturnT]):
    """Wraps a callable in a coroutine that is run on an asyncio loop."""

    def __init__(self, loop: AbstractEventLoop, func: Callable[..., ReturnT]):
        """Initialize the runner.

        Args:
            loop: Asyncio loop to execute func on.
            func: Callable or coroutine that should be executed on the asyncio
                loop.
        """
        self._loop = loop
        self._func = func

    def __call__(self, *args: Any, **kwargs: Any) -> ReturnT:
        """Run the associated function on an asyncio loop."""

        @wraps(self._func)
        def _run_func() -> ReturnT:
            """Run the associated function synchronously."""
            return self._func(*args, **kwargs)

        return run_sync_on_loop(self._loop, _run_func)

    @classmethod
    def wrap_functions(
            cls, loop: AbstractEventLoop, instance: object,
            functions: Sequence[Callable[..., Any]]
        ):
        """Wrap functions of an object instance in CallableRunner.

        Args:
            loop: Asyncio loop to run wrapped functions on.
            instance: Instance with functions to wrap.
            functions: Functions on instance to wrap.

        Raises:
            AttributeError: If any functions are not on the instance.
        """
        for function_name in (func.__name__ for func in functions):
            setattr(
                instance, function_name,
                cls(loop, getattr(instance, function_name))
            )
