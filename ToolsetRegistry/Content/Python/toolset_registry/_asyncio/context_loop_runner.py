"""contextvars.Context proxy that runs callables on an asyncio loop."""

from __future__ import annotations
from asyncio import AbstractEventLoop
from collections.abc import Callable
from contextvars import Context, ContextVar
from typing import (
    Any, ItemsView, Iterator, KeysView, Protocol, TypeVar, ValuesView
)


ReturnT = TypeVar('ReturnT')


class RunSyncOnLoopProtocol(Protocol):  # pylint: disable=too-few-public-methods
    """Protocol for running a callable on an asyncio loop."""

    def __call__(
        self, loop: AbstractEventLoop, func: Callable[[], ReturnT],
        context: Context | 'ContextLoopRunner' | None = None
    ) -> ReturnT:
        """Run a callable on an asyncio loop.

        Args:
            loop: Loop to run the coroutine on.
            func: Callable to call.
            context: Context to use when running the callable.

        Returns:
            Result of the callable.
        """


class ContextLoopRunner:
    """contextvars.Context compatible object with a custom run method."""

    def __init__(
            self, context: Context, loop: AbstractEventLoop,
            run_on_loop: RunSyncOnLoopProtocol
        ):
        """Initialize the instance.

        Args:
            context: Context to use.
            loop: Loop to run callables on.
            run_on_loop: Used to run a callable on an asyncio loop.
        """
        self._context = context
        self._loop = loop
        self._run_on_loop = run_on_loop

    def run(self, func: Callable[..., ReturnT], *args, **kwargs) -> ReturnT:
        """Run a callable with this context on an asyncio loop.

        Args:
            func: Function to call.
            *args: Positional arguments for func.
            **kwargs: Keyword arguments for func.

        Returns:
            Return value of func.
        """
        return self._run_on_loop(
            self.loop, lambda: func(*args, **kwargs), context=self.context
        )

    @property
    def context(self) -> Context:
        """Underlying context object."""
        return self._context

    @property
    def loop(self) -> AbstractEventLoop:
        """Loop callables with be run on."""
        return self._loop

    def copy(self) -> ContextLoopRunner:
        """Shallow copy this instance."""
        return ContextLoopRunner(self.context, self.loop, self._run_on_loop)

    def __contains__(self, item: Any) -> bool:
        """Whether the context contains the specified context var."""
        return item in self.context

    def __getitem__(self, item: Any) -> Any:
        """Get the value of the specified context var."""
        return self.context[item]

    def get(self, item: ContextVar) -> Any:
        """Get the value of the specified context var."""
        return self.context.get(item)

    def __iter__(self) -> Iterator[ContextVar]:
        """Iterator over the variables stored in the context object."""
        return self.context.__iter__()

    def __len__(self) -> int:
        """Number of variables set in the context object."""
        return len(self.context)

    def items(self) -> ItemsView[ContextVar, Any]:
        """All variables and their values in the context object."""
        return self.context.items()

    def keys(self) -> KeysView[ContextVar]:
        """All variables' keys in the context object."""
        return self.context.keys()

    def values(self) -> ValuesView[Any]:
        """All variables' values in the context object."""
        return self.context.values()

    @staticmethod
    def get_context(
        context: Context | 'ContextLoopRunner' | None
    ) -> Context | None:
        """Get the contextvars.Context.

        Args:
            context: Object to query.

        Returns:
            Underlying contextvars.Context if context isn't None.
        """
        return (
            context.context if isinstance(context, ContextLoopRunner) else context
        )
