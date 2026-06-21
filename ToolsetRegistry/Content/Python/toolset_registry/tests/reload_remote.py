# Copyright Epic Games, Inc. All Rights Reserved.
"""
Reload a toolset package in a running Unreal Editor via Remote Execution.

Requires Remote Execution to be enabled in the running editor:
  Edit -> Project Settings -> Plugins -> Python -> Enable Remote Execution

Usage:
    python reload_remote.py toolset_registry
    python reload_remote.py animation_toolset
    python reload_remote.py conversation_toolset
"""

import argparse
from pathlib import Path
import sys
import time
import types


def _build_command(package_name: str) -> str:
    return '\n'.join([
        f'import {package_name}',
        'import toolset_registry',
        f'toolset_registry.reload_module({package_name})',
    ])


def _run_remote_with(ue_remote: types.ModuleType, package_name: str, timeout: int = 30) -> int:
    """Run reload using the provided remote execution module.

    Separated from run_remote() to allow testing with a fake ue_remote.
    Returns 0 on success, 1 on failure.
    """
    command = _build_command(package_name)

    remote = ue_remote.RemoteExecution()
    remote.start()

    print('Waiting for Unreal Editor', end='', flush=True)
    deadline = time.monotonic() + timeout
    while not remote.remote_nodes:
        if time.monotonic() > deadline:
            print()
            print('Error: Timed out waiting for a remote node.', file=sys.stderr)
            print(
                'Make sure Remote Execution is enabled: '
                'Edit -> Project Settings -> Plugins -> Python -> Enable Remote Execution',
                file=sys.stderr,
            )
            remote.stop()
            return 1
        time.sleep(1)
        print('.', end='', flush=True)
    print(' connected.')

    print(f'Reloading {package_name}...', flush=True)
    try:
        remote.open_command_connection(remote.remote_nodes[0]['node_id'])
        result = remote.run_command(command, exec_mode=ue_remote.MODE_EXEC_FILE)
        output = ''.join(
            item.get('output', '') for item in result.get('output', [])
        )
        print(output, end='')
    except Exception as e:
        print(f'Error: {e}', file=sys.stderr)
        return 1
    finally:
        remote.close_command_connection()
        remote.stop()

    print('Done.')
    return 0


def run_remote(package_name: str, timeout: int = 30) -> int:
    """Connect to the running Unreal Editor and reload the given package.

    Returns 0 on success, 1 on failure.
    """
    repo_root = next(
        (p for p in Path(__file__).resolve().parents if (p / 'Engine').is_dir()),
        None,
    )
    if repo_root is None:
        print(
            f'Error: Could not locate repo root (directory containing Engine) '
            f'searching upward from {Path(__file__).resolve()}',
            file=sys.stderr,
        )
        return 1

    remote_exec_path = (
        repo_root / 'Engine/Plugins/Experimental/PythonScriptPlugin/Content/Python'
    )
    sys.path.insert(0, str(remote_exec_path))
    try:
        import remote_execution as ue_remote  # type: ignore
    except ImportError:
        print(
            f'Error: Could not import remote_execution from:\n  {remote_exec_path}',
            file=sys.stderr,
        )
        return 1
    finally:
        sys.path.remove(str(remote_exec_path))

    return _run_remote_with(ue_remote, package_name, timeout)


def main():
    parser = argparse.ArgumentParser(
        description='Reload a toolset package in a running Unreal Editor via Remote Execution.',
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog=__doc__,
    )
    parser.add_argument(
        'package',
        metavar='PACKAGE',
        help='Python package to reload (e.g. toolset_registry, animation_toolset).',
    )
    parser.add_argument(
        '--timeout',
        type=int,
        default=30,
        metavar='SECONDS',
        help='How long to wait for the Unreal Editor to respond (default: 30).',
    )
    args = parser.parse_args()
    sys.exit(run_remote(args.package, args.timeout))


if __name__ == '__main__':
    main()
