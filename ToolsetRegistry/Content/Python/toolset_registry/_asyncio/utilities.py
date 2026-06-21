# Copyright Epic Games, Inc. All Rights Reserved.
"""Very simple asyncio utilities."""

from asyncio import get_event_loop, AbstractEventLoop


def get_event_loop_or_none() -> AbstractEventLoop | None:
    """Get the asyncio event loop on the current thread.

    Returns:
        Event loop on the current thread or None if no event loop is set.
    """
    try:
        return get_event_loop()
    except RuntimeError:
        return None
