# Copyright Epic Games, Inc. All Rights Reserved.
"""Helpers for testing _asyncio"""

from functools import wraps
from contextlib import ExitStack
from collections.abc import Callable
from concurrent.futures import ThreadPoolExecutor
from typing import Any, TypeVar
import unittest

TestCaseT_co = TypeVar('TestCaseT_co', bound=unittest.TestCase, covariant=True)

def run_test_on_thread(
    func: Callable[[TestCaseT_co], Any]
) -> Callable[[TestCaseT_co], Any]:
    """Wraps a test case function so that it's run on a background thread.

    This is required to ensure the test is run in a context without an
    asyncio event loop.

    Args:
        func: TestCase member function to wrap. If the TestCase implements a
          _setup() function it's treated as a context manager and entered for
          the duration of func().
    """
    @wraps(func)
    def _wrapper(self: unittest.TestCase) -> None:
        """Wraps func()."""

        def _run_on_thread() -> None:
            """Called from a thread."""
            with ExitStack() as exit_stack:
                setup = getattr(self, '_setup', None)
                if callable(setup):
                    _ = exit_stack.enter_context(setup())
                func(self)  # type: ignore

        with ThreadPoolExecutor(max_workers=1) as executor:
            _ = executor.submit(_run_on_thread).result()

    return _wrapper
