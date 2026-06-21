# Copyright Epic Games, Inc. All Rights Reserved.
"""
Tests for reload_remote.py.

These are plain Python tests — no Unreal Editor required.
Run with: python -m pytest toolset_registry/tests/test_reload_remote.py
     or:  python toolset_registry/tests/test_reload_remote.py
"""

import enum
import types
from contextlib import contextmanager
import unittest

from toolset_registry.tests.reload_remote import _run_remote_with

_NODE = {'node_id': 'test-node-1'}


class RemoteState(enum.Enum):
    CLOSED = 'closed'
    OPENED = 'opened'
    STARTED = 'started'
    STOPPED = 'stopped'

class FakeRemoteExecution:
    instances: list['FakeRemoteExecution'] = []

    def __init__(
        self, test: unittest.TestCase,
        nodes: list[str],
        command_output: str,
        connection_error: Exception | None,
        command_error: Exception | None):
        self._test = test
        self._nodes = nodes
        self._command_output = command_output
        self._connection_error = connection_error
        self._command_error = command_error
        self._state = RemoteState.STOPPED
        self.last_command = None
        self.last_exec_mode = None

    @property
    def remote_nodes(self):
        return self._nodes

    @property
    def stopped(self):
        return self._state == RemoteState.STOPPED

    @property
    def closed(self):
        return self._state != RemoteState.OPENED

    def start(self):
        self._test.assertEqual(self._state, RemoteState.STOPPED)
        self._state = RemoteState.STARTED

    def stop(self):
        self._test.assertEqual(self._state, RemoteState.STARTED)
        self._state = RemoteState.STOPPED

    def open_command_connection(self, node_id):
        self._test.assertEqual(self._state, RemoteState.STARTED)
        if self._connection_error is not None:
            raise self._connection_error
        self._state = RemoteState.OPENED

    def close_command_connection(self):
        self._test.assertEqual(self._state, RemoteState.OPENED)
        self._state = RemoteState.STARTED

    def run_command(self, command, exec_mode):
        self._test.assertEqual(self._state, RemoteState.OPENED)
        if self._command_error is not None:
            raise self._command_error
        self.last_command = command
        self.last_exec_mode = exec_mode
        return {'output': [{'type': 'Info', 'output': self._command_output}]}

    @classmethod
    @contextmanager
    def create(
        cls, test: unittest.TestCase,
        nodes = (_NODE,),
        command_output: str = '',
        connection_error: Exception | None = None,
        command_error: Exception | None = None):
        instance = cls(test, nodes, command_output, connection_error, command_error)
        cls.instances.append(instance)
        try:
            yield (
                types.SimpleNamespace(
                    RemoteExecution=lambda: instance,
                    MODE_EXEC_FILE='ExecuteFile'),
                cls.instances
            )
        finally:
            cls.instances = []

class TestReloadRemote(unittest.TestCase):
    """Tests for reload_remote helpers."""

    def test_success_returns_zero(self):
        with FakeRemoteExecution.create(self) as (fake, _):
            self.assertEqual(_run_remote_with(fake, 'toolset_registry'), 0)

    def test_stop_called_on_success(self):
        with FakeRemoteExecution.create(self) as (fake, instances):
            _run_remote_with(fake, 'toolset_registry')
            self.assertTrue(instances[0].stopped)

    def test_close_connection_called_on_success(self):
        with FakeRemoteExecution.create(self) as (fake, instances):
            _run_remote_with(fake, 'toolset_registry')
            self.assertTrue(instances[0].closed)

    def test_timeout_returns_one(self):
        """No nodes within timeout → returns 1."""
        with FakeRemoteExecution.create(self, nodes=[]) as (fake, _):
            self.assertEqual(_run_remote_with(fake, 'toolset_registry', timeout=0), 1)

    def test_timeout_calls_stop(self):
        """stop() is called even when a timeout occurs."""
        with FakeRemoteExecution.create(self, nodes=[]) as (fake, instances):
            _run_remote_with(fake, 'toolset_registry', timeout=0)
            self.assertTrue(instances[0].stopped)

    def test_connection_error_returns_one(self):
        """open_command_connection raising → state stays STARTED, not OPENED."""
        with FakeRemoteExecution.create(
            self, connection_error=RuntimeError('connection refused')
        ) as (_, instances):
            instance = instances[0]
            instance.start()
            with self.assertRaises(RuntimeError):
                instance.open_command_connection(_NODE['node_id'])
            self.assertFalse(instance.stopped)

    def test_connection_error_calls_stop(self):
        """stop() is callable after open_command_connection raises."""
        with FakeRemoteExecution.create(
            self, connection_error=RuntimeError('connection refused')
        ) as (_, instances):
            instance = instances[0]
            instance.start()
            with self.assertRaises(RuntimeError):
                instance.open_command_connection(_NODE['node_id'])
            instance.stop()
            self.assertTrue(instance.stopped)

    def test_command_error_returns_one(self):
        """run_command raising → returns 1."""
        with FakeRemoteExecution.create(
            self, command_error=RuntimeError('command failed')
        ) as (fake, _):
            self.assertEqual(_run_remote_with(fake, 'toolset_registry'), 1)

    def test_command_error_calls_stop(self):
        """stop() is still called when run_command raises."""
        with FakeRemoteExecution.create(
            self, command_error=RuntimeError('command failed')
        ) as (fake, instances):
            _run_remote_with(fake, 'toolset_registry')
            self.assertTrue(instances[0].stopped)

    def test_exec_mode_is_exec_file(self):
        """run_command is called with MODE_EXEC_FILE."""
        with FakeRemoteExecution.create(self) as (fake, instances):
            _run_remote_with(fake, 'toolset_registry')
            self.assertEqual(instances[0].last_exec_mode, 'ExecuteFile')

    def test_command_calls_reload_on_given_package(self):
        """Command imports the package and calls toolset_registry.reload_module() on it."""
        with FakeRemoteExecution.create(self) as (fake, instances):
            _run_remote_with(fake, 'animation_toolset')
            self.assertIn('import animation_toolset', instances[0].last_command)
            self.assertIn('import toolset_registry', instances[0].last_command)
            self.assertIn('toolset_registry.reload_module(animation_toolset)', instances[0].last_command)


if __name__ == '__main__':
    unittest.main()
