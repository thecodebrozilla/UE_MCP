# Copyright Epic Games, Inc. All Rights Reserved.
"""Test automation fixtures shared across toolsets."""

from contextlib import contextmanager
from typing import Iterator
import unreal
import uuid

AUTOMATION_MOUNT_POINT = '/Automation/'
_mount_point_active = False


@contextmanager
def create_temp_folder() -> Iterator[str]:
    """Yields a unique automation folder; tears it down on exit.

    Mounts the automation point on first entry and unmounts on exit. Reentrant
    use is rejected; share one folder across nested setup instead.
    """
    global _mount_point_active
    assert not _mount_point_active, (
        'create_temp_folder() called while already active — '
        'use a single shared folder instead of nesting.')
    eas = unreal.get_editor_subsystem(unreal.EditorAssetSubsystem)
    assert eas
    test_folder = f'{AUTOMATION_MOUNT_POINT}{str(uuid.uuid4())}/'
    _mount_point_active = True
    unreal.AutomationUtilsBlueprintLibrary.add_automation_mount_point(AUTOMATION_MOUNT_POINT)
    try:
        eas.make_directory(test_folder)
        yield test_folder
    finally:
        if eas.does_directory_exist(test_folder):
            eas.delete_directory(test_folder)
        unreal.AutomationUtilsBlueprintLibrary.remove_automation_mount_point(AUTOMATION_MOUNT_POINT)
        _mount_point_active = False
