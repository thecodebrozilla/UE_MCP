# Copyright Epic Games, Inc. All Rights Reserved.
"""Polls a callable until a timeout is reached."""

from collections.abc import Callable
from datetime import timedelta
from time import perf_counter, sleep


class TimeoutPoller:
    """Timeout poller."""

    def __init__(
            self, timeout: timedelta,
            poll_interval: timedelta = timedelta(),
            poll_retry_delay: timedelta = timedelta(),
            wait: Callable[[float], None] | None = None):
        """Initialize the poller.

        Args:
            timeout: Maximum time to poll.
            poll_interval: Time to wait between each poll.
            poll_retry_delay: Time to wait before retrying polling once.
                If this is non-zero, poll() will attempt to call the
                pollable one more time after it returns False.
            wait: Used to wait for poll_interval or poll_retry_delay.
        """
        self._perf_counter = perf_counter
        self.set_wait(wait=wait)
        self._timeout_in_seconds = timeout.total_seconds()
        self._poll_interval_in_seconds = poll_interval.total_seconds()
        self._poll_retry_delay_in_seconds = poll_retry_delay.total_seconds()

    def set_wait(self, wait: Callable[[float], None] | None = None):
        """Set the wait callable (exposed for tests).

        Args:
            wait: Callable used to wait for poll_interval or poll_retry_delay.
        """
        self._wait = wait or sleep

    @property
    def timeout(self) -> timedelta:
        """Maximum time to poll."""
        return timedelta(seconds=self._timeout_in_seconds)

    @property
    def poll_interval(self) -> timedelta:
        """Poll interval."""
        return timedelta(seconds=self._poll_interval_in_seconds)

    @property
    def poll_retry_delay(self) -> timedelta:
        """Delay before trying to poll again."""
        return timedelta(seconds=self._poll_retry_delay_in_seconds)

    def _create_countdown_timer(self) -> Callable[[], float]:
        """Start a countdown timer.

        Returns:
            Callable that returns the remaining time.
        """
        start_timestamp = self._perf_counter()
        return lambda: (
            max(
                self._timeout_in_seconds -
                (self._perf_counter() - start_timestamp),
                0.0
            )
        )

    def poll(self, pollable: Callable[[], bool]) -> None:
        """Poll a callable until it returns False or timeout elapses.

        Args:
            pollable: Callable to poll.
        """
        get_remaining_time = self._create_countdown_timer()
        while True:
            continue_polling = False

            for retry in (bool(self._poll_retry_delay_in_seconds), False):
                continue_polling = pollable()
                if not continue_polling and retry:
                    self._wait(self._poll_retry_delay_in_seconds)
                    continue
                break

            if not continue_polling or get_remaining_time() <= 0.0:
                break

            self._wait(self._poll_interval_in_seconds)
