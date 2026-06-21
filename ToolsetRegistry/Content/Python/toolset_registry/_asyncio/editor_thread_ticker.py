# Copyright Epic Games, Inc. All Rights Reserved.
"""Handles tick events on the editor's main thread."""

from abc import abstractmethod, ABC
from enum import Enum
from threading import current_thread, local, main_thread, RLock
from typing import Any, Callable, Self
from types import ModuleType, TracebackType

from .._unreal import get_unreal_module as real_get_unreal_module


class _ThreadLocalStorage(local):  # pylint: disable=too-few-public-methods
    """This module's thread-local storage.

    This is thread-local storage so that this module can be tested in
    background threads using fakes while this module is in use on other
    threads.
    """

    get_unreal_module: Callable[[], ModuleType]
    get_main_thread_ident: Callable[[], int]
    get_current_thread_ident: Callable[[], int]

    def __init__(self):
        """Initialize defaults."""
        self.__dict__.setdefault('get_unreal_module', real_get_unreal_module)
        self.__dict__.setdefault('get_main_thread_ident',
                                 lambda: main_thread().ident)
        self.__dict__.setdefault('get_current_thread_ident',
                                 lambda: current_thread().ident)


_thread_local_storage = _ThreadLocalStorage()


class _TickEvent(Enum):
    """Event to perform on the next tick.

    Class Attributes:
        REGISTER: Register the event loop with the ticking thread.
        UNREGISTER: Unregister the event loop from the ticking thread.
        POLL: Poll the event loop.
        STOP: Stop polling from the ticking thread.
    """
    REGISTER = 'register'
    UNREGISTER = 'unregister'
    POLL = 'poll'
    STOP = 'stop'


class EditorThreadTicker(ABC):
    """Handles tick events on the editor's main thread."""

    def __init__(self):
        """Initialize ticker."""
        # Unreal initializes Python on the main thread which will ultimately
        # poll this object.
        self.__tick_thread_id = _thread_local_storage.get_main_thread_ident()
        self.__tick_callback_handle: Any = None
        # Guards operations that happen within a tick
        self.__tick_lock = RLock()
        # Writes of _tick_event are guarded by _tick_lock.
        #
        # All inter-thread communication happens via this property.
        # Caller threads only indirectly set this property which is acted
        # upon within __tick_handler().
        self.___tick_event = _TickEvent.STOP

    def __enter__(self) -> Self:
        """Create and install a ticker on the main thread.

        Returns:
            This instance.
        """
        self.__tick_event = _TickEvent.REGISTER
        return self

    def __exit__(
            self, exc_type: type[BaseException] | None,
            exc_value: BaseException | None,
            traceback: TracebackType | None
        ) -> None:
        """Remove the ticker from the main thread if it's registered."""
        _ = (exc_type, exc_value, traceback)
        self.__tick_event = _TickEvent.UNREGISTER

    @abstractmethod
    def _on_tick(self, delta_time: float) -> None:
        """Called on a tick event.

        Subclasses should implement this method to do work on the main thread.

        Args:
            delta_time: Time elapsed, in seconds, since the last tick.
        """

    @abstractmethod
    def _on_register(self) -> None:
        """Called on the first tick event."""

    @abstractmethod
    def _on_unregister(self) -> None:
        """Called before this class is unregistered from tick events."""

    @property
    def __tick_event(self) -> _TickEvent:
        """Scheduled tick event."""
        return self.___tick_event

    @__tick_event.setter
    def __tick_event(self, value: _TickEvent) -> None:
        """Set the scheduled tick event."""
        with self.__tick_lock:
            if self.__tick_event != value:
                self.___tick_event = value
                match self.__tick_event:
                    case _TickEvent.REGISTER:
                        self._subscribe_to_and_maybe_fire_tick()
                    case (
                        _TickEvent.POLL |
                        _TickEvent.UNREGISTER |
                        _TickEvent.STOP
                    ):
                        self.tick_if_on_tick_thread()

    def __tick_handler(self, delta_time: float) -> bool:
        """Called when a tick event fires.

        Args:
            delta_time: Time elapsed, in seconds, since the last tick.

        Returns:
            True to continue ticking, False otherwise.
        """
        continue_ticking = True
        tick_event: _TickEvent
        with self.__tick_lock:
            tick_event = self.__tick_event

        match tick_event:
            case _TickEvent.POLL:
                self._on_tick(delta_time)
            case _TickEvent.REGISTER:
                self._on_register()
                self.__tick_event = _TickEvent.POLL
            case _TickEvent.UNREGISTER:
                self._on_unregister()
                self.__tick_event = _TickEvent.STOP
            case _TickEvent.STOP:
                self._unsubscribe_from_tick()
                continue_ticking = False
        return continue_ticking

    def tick_if_on_tick_thread(self):
        """Tick if the current thread is the ticker thread."""
        if self._on_tick_thread:
            self.__tick_handler(0.0)

    @property
    def _on_tick_thread(self) -> bool:
        """Whether the caller thread is the tick thread."""
        return (
            # pylint: disable=no-member
            _thread_local_storage.get_current_thread_ident() ==
            self.__tick_thread_id
        )

    def _subscribe_to_tick(self) -> bool:
        """Subscribe to tick events.

        Returns:
            True if subscribed to the tick event, False if already subscribed.
        """
        with self.__tick_lock:
            if self.__tick_callback_handle is None:
                self.__tick_callback_handle = (
                    _thread_local_storage.get_unreal_module()
                    .register_ticker_callback(self.__tick_handler)
                )
                return True
        return False

    def _subscribe_to_and_maybe_fire_tick(self) -> None:
        """Subscribe to tick events and fire a tick now if possible."""
        self._subscribe_to_tick()
        self.tick_if_on_tick_thread()

    def _unsubscribe_from_tick(self) -> None:
        """Unsubscribe from tick events."""
        with self.__tick_lock:
            if self.__tick_callback_handle is not None:
                unreal = _thread_local_storage.get_unreal_module()
                unreal.unregister_ticker_callback(self.__tick_callback_handle)
                self.__tick_callback_handle = None
