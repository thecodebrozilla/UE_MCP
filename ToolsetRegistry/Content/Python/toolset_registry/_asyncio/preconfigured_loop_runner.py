# Copyright Epic Games, Inc. All Rights Reserved.
"""asyncio.Runner that uses a pre-configured asyncio loop."""

from asyncio import AbstractEventLoop, Runner
from collections.abc import Awaitable, Coroutine
from contextvars import Context
from typing import Self, TypeVar
from types import TracebackType

from .context_loop_runner import ContextLoopRunner
from .run_on_loop import run_async_on_loop

ReturnT = TypeVar('ReturnT')


class PreconfiguredLoopRunner:
    """Implements asyncio.Runner using a pre-configured asyncio loop."""

    def __init__(self, loop: AbstractEventLoop):
        """Initialize with a loop that is already configured and running."""
        self._loop = loop

    def __enter__(self) -> Self:
        """Do nothing as the loop is already configured."""
        return self

    def __exit__(
            self, exc_type: type[BaseException] | None,
            exc_val: BaseException | None,
            exc_tb: TracebackType
        ):
        """Do nothing as the loop is already configured."""

    def close(self) -> None:
        """Do nothing as the loop is already configured."""

    def get_loop(self) -> AbstractEventLoop:
        """Return the referenced event loop."""
        return self._loop

    def run(
        self, coro: Coroutine[None, None, ReturnT] | Awaitable[ReturnT], *,
        context: Context | ContextLoopRunner | None = None
    ) -> ReturnT:
        """Run a coroutine or awaitable on this object's loop.

        Args:
            coro: Coroutine or awaitable.
            context: Context to use when running coro.

        Returns:
            Result of coro.

        Raises:
            ValueError if this object's loop is set on the current thread.
        """
        return run_async_on_loop(self._loop, coro, context=context).result()

    @classmethod
    def _check_implements_runner_protocol(cls):
        """Ensure this class implements the asyncio.Runner protocol."""
        for expected_attribute_name in dir(Runner):
            if (
                expected_attribute_name.startswith('_') and
                expected_attribute_name not in ('__enter__', '__exit__')
            ):
                continue
            attribute = getattr(cls, expected_attribute_name, None)
            assert attribute is not None, (
                f'{expected_attribute_name} not found in {cls}'
            )
            assert callable(attribute), (
                f'{attribute} ({expected_attribute_name}) is not callable'
            )


# asyncio.Runner is final and doesn't have a protocol so check conformance
# on import.
# pylint: disable-next=protected-access
PreconfiguredLoopRunner._check_implements_runner_protocol()
