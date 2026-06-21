# Copyright Epic Games, Inc. All Rights Reserved.
"""Test editor thread ticker."""

from __future__ import annotations
from contextlib import contextmanager
from time import sleep
from threading import current_thread, RLock
from unittest import mock
import unittest
from typing import Callable, Generator, Mapping

from toolset_registry._asyncio import editor_thread_ticker
from toolset_registry._asyncio.editor_thread_ticker import EditorThreadTicker


class FakeTickableUnrealModule:
    """Fake for components of unreal module that handle tick events."""

    DELTA_TIME = 1 / 60 # Fake time between each tick.

    def __init__(self):
        """Initialize the fake."""
        self._tick_lock = RLock()
        self._tick_callbacks: dict[int, Callable[[float], bool]] = {}
        self._tick_callback_id = 0

    def register_ticker_callback(
            self, callback: Callable[[float], bool]
        ) -> int:
        """Register a tick callback.

        Args:
            callback: Callback to call on tick().

        Returns:
            Handle to the callback.
        """
        with self._tick_lock:
            tick_callback_id = self._tick_callback_id
            self._tick_callback_id += 1
            self._tick_callbacks[tick_callback_id] = callback
        return tick_callback_id

    def unregister_ticker_callback(self, callback_handle: int) -> None:
        """Unregister a tick callback.

        Args:
            callback_handle: Handle to the callback to unregister
        """
        with self._tick_lock:
            del self._tick_callbacks[callback_handle]

    def tick(self) -> None:
        """Notify tick callbacks."""
        for handle, callback in self.tick_callbacks.items():
            if not callback(self.DELTA_TIME):
                self.unregister_ticker_callback(handle)

    def tick_until(self, maximum_number_of_ticks: int = 1000) -> None:
        """Tick while callbacks are scheduled or until the specified limit.

        Args:
            maximum_number_of_ticks: Maximum number of ticks to execute.
        """
        number_of_ticks = 0
        while (
            len(self._tick_callbacks) > 0 and
            number_of_ticks < maximum_number_of_ticks
        ):
            self.tick()
            sleep(0.001)  # Ensure the GIL is released between each tick.
            number_of_ticks += 1

    @property
    def tick_callbacks(self) -> Mapping[int, Callable[[float], bool]]:
        """Registered tick callbacks."""
        with self._tick_lock:
            return dict(self._tick_callbacks)

    @classmethod
    @contextmanager
    def install(
        cls, fake_unreal: 'FakeTickableUnrealModule | None' = None
    ) -> Generator['FakeTickableUnrealModule', None, None]:
        """Install a fake unreal module.

        Args:
            fake_unreal: Fake unreal module to install or None to create a
                new instance.

        Yields:
            Fake unreal module.
        """
        fake = fake_unreal or cls()
        with mock.patch.object(
            # pylint: disable=protected-access
            editor_thread_ticker._thread_local_storage,
            'get_unreal_module', return_value=fake
        ):
            yield fake


@contextmanager
def configure_editor_thread_ticker(
    main_thread_ident: int | None = None,
    fake_unreal_module_class: type[FakeTickableUnrealModule] | None = None
) -> (
    Generator[
        tuple[FakeTickableUnrealModule, mock.Mock, mock.Mock],
        None, None
    ]
):
    """Configure editor_thread_ticker for testing.

    Args:
        main_thread_ident: ID of the thread to treat as the main thread.
            If this isn't specified the current thread is used.
        fake_unreal_module_class: Unreal module class to install on the current
            thread.

    Yields:
        (fake_unreal, get_main_thread_ident_mock,
         get_current_thread_ident_mock) where fake_unreal is a fake
        unreal module that can be ticked to simulate the slate tick event,
        get_main_thread_ident and get_current_thread_ident are mocks that
        return the main and current thread IDs.
    """
    fake_unreal_module_class = fake_unreal_module_class or FakeTickableUnrealModule
    # Override the main thread ID so that the test can be called
    # from any thread and this also enables testing of immediate
    # vs. deferred creation on entering the
    # EditorEventLoopManager() context.
    get_main_thread_ident_mock = mock.Mock(
        return_value=(
            main_thread_ident
            if main_thread_ident is not None else
            current_thread().ident
        )
    )
    get_current_thread_ident_mock = mock.Mock(
        return_value=current_thread().ident
    )
    with (
            fake_unreal_module_class.install() as fake_unreal_module,
            mock.patch.object(
                # pylint: disable=protected-access
                editor_thread_ticker._thread_local_storage,
                'get_main_thread_ident',
                side_effect=get_main_thread_ident_mock
            ),
            mock.patch.object(
                # pylint: disable=protected-access
                editor_thread_ticker._thread_local_storage,
                'get_current_thread_ident',
                side_effect=get_current_thread_ident_mock
            )
        ):
        yield (
            fake_unreal_module,
            get_main_thread_ident_mock,
            get_current_thread_ident_mock
        )


class _EditorThreadTickTracker(EditorThreadTicker):  # pylint: disable=too-few-public-methods
    """Tracks EditorThreadTicker events

    Attributes:
        on_tick_delta_times: List of delta times received by the _on_tick()
            handler.
        on_register_count: Number of times _on_register() is called.
        on_unregister_count: Number of time _on_unregister() is called.
    """

    def __init__(self):
        """Initialize the tracker."""
        super().__init__()
        self.on_tick_delta_times: list[float] = []
        self.on_register_count = 0
        self.on_unregister_count = 0

    def _on_tick(self, delta_time: float) -> None:
        """Log a delta time.

        Args:
            delta_time: Time elapsed, in seconds, since the last tick.
        """
        self.on_tick_delta_times.append(delta_time)

    def _on_register(self) -> None:
        """Log register event."""
        self.on_register_count += 1

    def _on_unregister(self) -> None:
        """Log unregister event."""
        self.on_unregister_count += 1


class TestEditorThreadTicker(unittest.TestCase):
    """Test EditorThreadTicker."""

    def test_init(self):
        """Test initialization."""
        with configure_editor_thread_ticker() as _:
            tracker = _EditorThreadTickTracker()
            self.assertSequenceEqual(tracker.on_tick_delta_times, [])
            self.assertEqual(tracker.on_register_count, 0)
            self.assertEqual(tracker.on_unregister_count, 0)

    def test_on_tick_thread(self):
        """Test _on_tick_thread."""
        with (
            configure_editor_thread_ticker() as (
                _, get_main_thread_ident_mock, get_current_thread_ident_mock
            )
        ):
            with _EditorThreadTickTracker() as tracker:
                # pylint: disable=protected-access
                self.assertTrue(tracker._on_tick_thread)

                # Switch to a different thread.
                get_current_thread_ident_mock.return_value = (
                    get_main_thread_ident_mock.return_value + 1
                )
                self.assertFalse(tracker._on_tick_thread)

    def test_register_and_unregister(self):
        """Test registration on context enter / exit."""
        with configure_editor_thread_ticker() as (fake_unreal, _, _):
            tracker = _EditorThreadTickTracker()
            with tracker:
                self.assertEqual(tracker.on_register_count, 1)
                # Should tick once after registration.
                self.assertSequenceEqual(tracker.on_tick_delta_times, [0.0])
                self.assertEqual(tracker.on_unregister_count, 0)
                self.assertNotEqual(
                    list(fake_unreal.tick_callbacks.keys()), []
                )
            self.assertEqual(tracker.on_register_count, 1)
            self.assertSequenceEqual(tracker.on_tick_delta_times, [0.0])
            self.assertEqual(tracker.on_unregister_count, 1)
            self.assertEqual(
                list(fake_unreal.tick_callbacks.keys()), []
            )

    def test_tick(self):
        """Ensure tick events are handled by the ticker."""
        with configure_editor_thread_ticker() as (fake_unreal, _, _):
            tracker = _EditorThreadTickTracker()
            fake_unreal.tick()
            self.assertSequenceEqual(tracker.on_tick_delta_times, [])

            with tracker:
                expected_ticks = [0.0]
                self.assertSequenceEqual(
                    tracker.on_tick_delta_times, expected_ticks
                )

                fake_unreal.tick()
                expected_ticks.append(FakeTickableUnrealModule.DELTA_TIME)
                self.assertSequenceEqual(
                    tracker.on_tick_delta_times, expected_ticks
                )

                fake_unreal.tick()
                expected_ticks.append(FakeTickableUnrealModule.DELTA_TIME)
                self.assertSequenceEqual(
                    tracker.on_tick_delta_times, expected_ticks
                )
            self.assertSequenceEqual(
                tracker.on_tick_delta_times, expected_ticks
            )

    def test_tick_if_on_tick_thread(self):
        """Test forcing a tick."""
        with (
            configure_editor_thread_ticker() as (
                _, get_main_thread_ident_mock, get_current_thread_ident_mock
            )
        ):
            with _EditorThreadTickTracker() as tracker:
                expected_ticks = [0.0]
                self.assertSequenceEqual(tracker.on_tick_delta_times, expected_ticks)

                tracker.tick_if_on_tick_thread()
                expected_ticks.append(0.0)
                self.assertSequenceEqual(tracker.on_tick_delta_times, expected_ticks)

                # Switch to a different thread.
                get_current_thread_ident_mock.return_value = (
                    get_main_thread_ident_mock.return_value + 1
                )

                tracker.tick_if_on_tick_thread()
                self.assertSequenceEqual(tracker.on_tick_delta_times, expected_ticks)

    def test_lifecycle_from_another_thread(self):
        """Test registration / tick and unregistration from another thread."""
        current_thread_id = current_thread().ident or 0
        fake_main_thread_id = current_thread_id + 1
        with configure_editor_thread_ticker(
            main_thread_ident=fake_main_thread_id
        ) as (fake_unreal, _, get_current_thread_ident):
            tracker = _EditorThreadTickTracker()
            expected_ticks: list[float] = []
            self.assertEqual(tracker.on_register_count, 0)
            self.assertSequenceEqual(
                tracker.on_tick_delta_times, expected_ticks
            )
            self.assertEqual(tracker.on_unregister_count, 0)

            with tracker:
                self.assertEqual(tracker.on_register_count, 0)
                self.assertSequenceEqual(
                    tracker.on_tick_delta_times, expected_ticks
                )

                # Simulate ticks from the main thread.
                get_current_thread_ident.return_value = fake_main_thread_id
                fake_unreal.tick()
                self.assertEqual(tracker.on_register_count, 1)
                # First tick happens immediately after register
                expected_ticks.append(0.0)
                self.assertSequenceEqual(
                    tracker.on_tick_delta_times, expected_ticks
                )

                fake_unreal.tick()
                self.assertEqual(tracker.on_register_count, 1)
                expected_ticks.append(FakeTickableUnrealModule.DELTA_TIME)
                self.assertSequenceEqual(
                    tracker.on_tick_delta_times, expected_ticks
                )

                # Unregister from the current thread.
                get_current_thread_ident.return_value = current_thread_id

            self.assertEqual(tracker.on_unregister_count, 0)

            get_current_thread_ident.return_value = fake_main_thread_id
            fake_unreal.tick()
            self.assertEqual(tracker.on_unregister_count, 1)
            self.assertEqual(tracker.on_register_count, 1)
            self.assertSequenceEqual(
                tracker.on_tick_delta_times, expected_ticks
            )
            self.assertEqual(
                list(fake_unreal.tick_callbacks.keys()), []
            )


if __name__ == '__main__':  # pragma:  no cover
    unittest.main()
