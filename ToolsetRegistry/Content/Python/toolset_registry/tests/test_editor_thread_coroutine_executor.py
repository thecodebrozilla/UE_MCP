# Copyright Epic Games, Inc. All Rights Reserved.
"""Test editor_thread_coroutine_executor."""

from contextlib import closing, contextmanager, ExitStack
from datetime import timedelta
from threading import current_thread, Lock
from typing import cast, Generator
from unittest import mock
import unittest

from toolset_registry._asyncio.editor_event_loop_manager import (
    _ReferenceCountedEditorEventLoopManager,
    EditorEventLoopManager
)
from .editor_thread_coroutine_executor import EditorThreadCoroutineExecutor
from ._asyncio import run_test_on_thread
from ._asyncio.test_timeout_poller import (
    FakePerfCounter, TimeoutPollerUsingFakePerfCounter
)
from ._asyncio.test_editor_thread_ticker import (
    configure_editor_thread_ticker,
    FakeTickableUnrealModule
)


class CustomThreadCoroutineExecutor(EditorThreadCoroutineExecutor):
    """Coroutine executor that runs on any thread.

    This should be created after using configure_editor_thread_ticker() to
    configure the editor thread ticker's main thread.
    """

    def __init__(self):
        """Override perf counter and event loop manager for testing."""
        super().__init__()
        self._timeout_poller = (
            TimeoutPollerUsingFakePerfCounter.from_timeout_poller(
                self._timeout_poller
            )
        )
        # Replace the global manager for the test.
        assert isinstance(self._event_loop_manager, EditorEventLoopManager)
        self._event_loop_manager = cast(
            EditorEventLoopManager,
            _ReferenceCountedEditorEventLoopManager()
        )

    @property
    def fake_perf_counter(self) -> FakePerfCounter:
        """Fake perf counter."""
        assert isinstance(
            self._timeout_poller, TimeoutPollerUsingFakePerfCounter
        )
        return self._timeout_poller.fake_perf_counter

    def _on_tick(self, delta_time: float) -> None:
        """Execute a batch of commands and advance time."""
        super()._on_tick(delta_time)
        self.fake_perf_counter.advance_time(timedelta(seconds=delta_time))

    @classmethod
    @contextmanager
    def create(cls, main_thread_ident: int | None = None) -> (
        Generator[
            tuple[
                'CustomThreadCoroutineExecutor',
                FakeTickableUnrealModule,
                mock.Mock,
                mock.Mock
            ],
            None, None
        ]
    ):
        """Create a custom thread coroutine executor.

        Args:
            main_thread_ident: ID of the thread to treat as the main thread.
                If this isn't specified the current thread is used.

        Yield:
            (executor, unreal, get_main_thread_ident_mock,
            get_current_thread_ident_mock) where executor is the coroutine
            executor that has entered its context, unreal is the fake unreal
            module that can be used to tick the executor, get_main_thread_ident
            and get_current_thread_ident are mocks that return the main and
            current thread IDs.
        """
        with (
            configure_editor_thread_ticker(
                main_thread_ident=main_thread_ident
            ) as (
                fake_unreal, get_main_thread_ident_mock,
                get_current_thread_ident_mock
            ),
            cls() as executor
        ):
            yield (
                executor, fake_unreal, get_main_thread_ident_mock,
                get_current_thread_ident_mock
            )


class TestEditorThreadCoroutineExecutor(unittest.TestCase):
    """Test EditorThreadCoroutineExecutor."""

    @staticmethod
    def _get_current_thread_ident() -> int:
        """Return the current thread's identifier"""
        thread = current_thread()
        assert thread.ident is not None
        return thread.ident

    @classmethod
    def _get_fake_thread_ident(cls) -> int:
        """Return a fake thread identifier."""
        return cls._get_current_thread_ident() + 1

    @run_test_on_thread
    def test_schedule_from_editor_thread(self):
        """Test scheduling from the editor thread."""
        with CustomThreadCoroutineExecutor.create() as (executor, _, _, _):
            callable_mock1 = mock.AsyncMock()
            executor.schedule(callable_mock1())
            callable_mock1.assert_awaited_once_with()

            callable_mock2 = mock.AsyncMock()
            executor.schedule(callable_mock2())
            callable_mock2.assert_awaited_once_with()
        callable_mock1.assert_awaited_once_with()
        callable_mock2.assert_awaited_once_with()

    @run_test_on_thread
    def test_can_run_asyncio_tasks(self):
        """Ensure asyncio tasks can be executed using the executor's loop"""
        with CustomThreadCoroutineExecutor.create() as (
            executor, fake_unreal, _, get_current_thread_ident_mock
        ):
            # Schedule from another thread.
            get_current_thread_ident_mock.return_value = (
                self._get_fake_thread_ident()
            )
            callable_mock = mock.Mock()
            executor.loop.call_soon(callable_mock)

            # Tick from the creation thread.
            get_current_thread_ident_mock.return_value = (
                self._get_current_thread_ident()
            )
            fake_unreal.tick()
            callable_mock.assert_called_once_with()

    @run_test_on_thread
    def test_schedule_from_background_thread(self):
        """Test scheduling from a background thread."""
        with (
            CustomThreadCoroutineExecutor.create(
                main_thread_ident=self._get_fake_thread_ident()
            ) as (executor, fake_unreal, _, get_current_thread_ident_mock),
        ):
            # Only allow one execution per tick.
            # pylint: disable=protected-access
            executor._timeout_poller._timeout_in_seconds = 0
            # Schedule tasks from the background thread.
            callable_mock1 = mock.AsyncMock()
            callable_mock2 = mock.AsyncMock()
            executor.schedule(callable_mock1())
            executor.schedule(callable_mock2())
            callable_mock1.assert_not_awaited()
            callable_mock2.assert_not_awaited()

            # Tick from the main thread.
            get_current_thread_ident_mock.return_value = (
                self._get_fake_thread_ident()
            )
            fake_unreal.tick()
            callable_mock1.assert_awaited_once_with()
            callable_mock2.assert_not_awaited()

            fake_unreal.tick()
            callable_mock1.assert_awaited_once_with()
            callable_mock2.assert_awaited_once_with()
        callable_mock1.assert_awaited_once_with()
        callable_mock2.assert_awaited_once_with()

    def _create_one_second_coroutine(
            self, fake_perf_counter: FakePerfCounter
        ) -> mock.AsyncMock:
        """Create an async mock that advances the performance counter 1 second.

        Args:
            fake_perf_counter: Fake performance counter to advance.
        """
        return mock.AsyncMock(
            side_effect=(
                lambda: fake_perf_counter.advance_time(timedelta(seconds=1.0))
            )
        )

    @run_test_on_thread
    def test_schedule_within_deadline(self):
        """Test execution of scheduled commands within a deadline."""
        with CustomThreadCoroutineExecutor.create(
            main_thread_ident=self._get_fake_thread_ident()
        ) as (executor, fake_unreal, _, get_current_thread_ident_mock):
            # pylint: disable=protected-access
            executor._timeout_poller._timeout_in_seconds = 1.5
            callable_mock1 = self._create_one_second_coroutine(
                executor.fake_perf_counter
            )
            callable_mock2 = self._create_one_second_coroutine(
                executor.fake_perf_counter
            )
            callable_mock3 = self._create_one_second_coroutine(
                executor.fake_perf_counter
            )
            executor.schedule(callable_mock1())
            executor.schedule(callable_mock2())
            executor.schedule(callable_mock3())

            # Tick from the main thread.
            get_current_thread_ident_mock.return_value = (
                self._get_fake_thread_ident()
            )
            fake_unreal.tick()
            callable_mock1.assert_awaited_once_with()
            callable_mock2.assert_awaited_once_with()
            # Deadline was 1.5 seconds so this callable should not be called.
            callable_mock3.assert_not_awaited()

    @run_test_on_thread
    def test_create_singleton(self):
        """Test creating and cleaning up the singleton."""
        # Hold the class lock to prevent any other threads from using it.
        # pylint: disable-next=protected-access
        with CustomThreadCoroutineExecutor._instance_lock:
            with (
                configure_editor_thread_ticker(
                    main_thread_ident=self._get_current_thread_ident(),
                ) as _,
                mock.patch.object(
                    CustomThreadCoroutineExecutor, '_instance_lock',
                    Lock()
                ),
                mock.patch.object(
                    CustomThreadCoroutineExecutor, '_instance_exit_stack',
                    ExitStack()
                ) as _,
                mock.patch.object(
                    CustomThreadCoroutineExecutor, '_instance', None
                ) as _,
                ExitStack() as wrapper_exit_stack,
            ):
                with wrapper_exit_stack:
                    with closing(CustomThreadCoroutineExecutor):
                        executor = (
                            CustomThreadCoroutineExecutor.get_or_create()
                        )
                        executor_on_unregister_wrapper = (
                            wrapper_exit_stack.enter_context(
                                mock.patch.object(
                                    executor, '_on_unregister',
                                    # pylint: disable=protected-access
                                    side_effect=executor._on_unregister)
                            )
                        )
                        callable_mock = mock.AsyncMock()
                        executor.schedule(callable_mock())
                        callable_mock.assert_awaited_once_with()
                        executor_on_unregister_wrapper.assert_not_called()
                    executor_on_unregister_wrapper.assert_called_once()


if __name__ == '__main__':  # pragma: no cover
    unittest.main()
