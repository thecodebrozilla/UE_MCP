# Copyright Epic Games, Inc. All Rights Reserved.
"""Test timeout poller."""

from __future__ import annotations
from collections.abc import Callable
from datetime import timedelta
from unittest import mock
import unittest

from toolset_registry._asyncio.timeout_poller import TimeoutPoller


class FakePerfCounter:  # pylint: disable=too-few-public-methods
    """Fake performance counter."""
    def __init__(self):
        self.timestamp = 0.0

    def advance_time(self, elapsed: timedelta) -> None:
        """Advance time.

        Args:
            elapsed: Time to advance.
        """
        self.timestamp += elapsed.total_seconds()


class TimeoutPollerUsingFakePerfCounter(TimeoutPoller):
    """Timeout poller that uses a fake performance counter."""

    def __init__(
            self, timeout: timedelta, poll_interval: timedelta = timedelta(),
            poll_retry_delay: timedelta = timedelta(),
            wait: Callable[[float], None] | None = None
    ):
        super().__init__(
            timeout, poll_interval=poll_interval,
            poll_retry_delay=poll_retry_delay, wait=wait
        )
        self._fake_perf_counter = FakePerfCounter()
        self._perf_counter = lambda: self._fake_perf_counter.timestamp

    @property
    def fake_perf_counter(self) -> FakePerfCounter:
        """Fake perf counter."""
        return self._fake_perf_counter

    @classmethod
    def from_timeout_poller(cls, timeout_poller: TimeoutPoller) -> (
        'TimeoutPollerUsingFakePerfCounter'
    ):
        """Construct an instance of this class from an existing poller.

        Args:
            timeout_poller: Poller to construct from.
        """
        return cls(
            timeout_poller.timeout,
            poll_interval=timeout_poller.poll_interval,
            poll_retry_delay=timeout_poller.poll_retry_delay,
            wait=timeout_poller._wait  # pylint: disable=protected-access
        )


class TestTimeoutPoller(unittest.TestCase):
    """Test timeout poller."""

    _TIMEOUT = timedelta(milliseconds=16)
    _POLL_INTERVAL = timedelta(microseconds=500)

    @classmethod
    def create_timeout_poller(
        cls, retry_delay: timedelta = timedelta()
    ) -> TimeoutPoller:
        """Create a test timeout poller.

        Args:
            retry_delay: Delay before trying to poll again.
        """
        return TimeoutPoller(
            cls._TIMEOUT, poll_interval=cls._POLL_INTERVAL,
            poll_retry_delay=retry_delay
        )

    def test_init(self):
        """Test initialization."""
        poller = self.create_timeout_poller()
        self.assertEqual(poller.timeout, self._TIMEOUT)
        self.assertEqual(poller.poll_interval, self._POLL_INTERVAL)
        # Make sure the default perf counter is configured as other tests
        # override it.
        # pylint: disable-next=protected-access
        self.assertIsInstance(poller._perf_counter(), float)

    def test_poll_until_complete(self):
        """Test polling until a callable is complete."""
        poller = self.create_timeout_poller()
        mock_pollable = mock.Mock(side_effect=[True, False])
        poller.poll(mock_pollable)
        mock_pollable.assert_has_calls([mock.call()] * 2)

    def test_poll_until_timeout(self):
        """Test polling until a timeout is reached."""
        poller = TimeoutPollerUsingFakePerfCounter.from_timeout_poller(
            self.create_timeout_poller()
        )

        number_of_times_to_poll = 4

        def _pollable_that_advances_time() -> bool:
            poller.fake_perf_counter.advance_time(
                self._TIMEOUT / number_of_times_to_poll
            )
            return True

        mock_pollable = mock.Mock(side_effect=_pollable_that_advances_time)
        poller.poll(mock_pollable)
        mock_pollable.assert_has_calls(
            [mock.call()] * number_of_times_to_poll
        )

    def test_poll_waits(self):
        """Ensure each poll attempt waits"""
        poller = self.create_timeout_poller()
        with mock.patch.object(
            # pylint: disable-next=protected-access
            poller, '_wait', side_effect=poller._wait
        ) as mock_sleep:
            mock_pollable = mock.Mock(side_effect=[True, False])
            poller.poll(mock_pollable)
            mock_sleep.assert_called_once_with(
                self._POLL_INTERVAL.total_seconds()
            )

    def test_poll_retries(self):
        """Ensure polling retries once after the pollable returns False."""
        poller = self.create_timeout_poller(
            retry_delay=timedelta(milliseconds=1)
        )
        with mock.patch.object(
            # pylint: disable-next=protected-access
            poller, '_wait', side_effect=poller._wait
        ) as mock_sleep:
            poll_attempt_results = [
                True,
                False,  # Should retry
                True,
                False,  # Should retry
                False,  # Should stop retrying.
            ]
            mock_pollable = mock.Mock(side_effect=poll_attempt_results)
            poller.poll(mock_pollable)
            mock_pollable.assert_has_calls(
                [mock.call()] * len(poll_attempt_results)
            )
            mock_sleep.assert_has_calls(
                [
                    mock.call(sleep_time.total_seconds())
                    for sleep_time in (
                        poller.poll_interval,
                        poller.poll_retry_delay,
                        poller.poll_interval,
                        poller.poll_retry_delay,
                    )
                ]
            )

    def test_set_wait(self):
        """Test setting the wait method after initialization."""
        poller = self.create_timeout_poller()
        mock_wait = mock.Mock()
        poller.set_wait(wait=mock_wait)
        mock_wait.assert_not_called()

        poller.poll(mock.Mock())
        mock_wait.assert_called()


if __name__ == '__main__':  # pragma: no cover
    unittest.main()
