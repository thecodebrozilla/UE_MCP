# Copyright Epic Games, Inc. All Rights Reserved.
"""Lazy import of the Unreal module."""

from types import ModuleType

def get_unreal_module() -> ModuleType:
    """Lazily import the unreal module.

    Returns:
        unreal Module.
    """
    # pylint: disable-next=import-outside-toplevel
    import unreal  # type: ignore
    return unreal
