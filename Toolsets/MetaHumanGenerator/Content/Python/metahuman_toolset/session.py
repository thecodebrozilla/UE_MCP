# Copyright Epic Games, Inc. All Rights Reserved.

import atexit
import unreal

_METAHUMAN_SUBSYSTEM = unreal.get_editor_subsystem(unreal.MetaHumanCharacterEditorSubsystem)
if not _METAHUMAN_SUBSYSTEM:
    raise RuntimeError("MetaHumanCharacterEditorSubsystem not available")

@unreal.uclass()
class MetaHumanEditSession(unreal.Object):
    """Manages edit mode lifecycle for a MetaHuman character."""

    object_path = unreal.uproperty(str)
    character = unreal.uproperty(unreal.MetaHumanCharacter)
    is_in_edit_mode = unreal.uproperty(bool)

    def initialize(self):
        """Enter edit mode for the character."""
        if not _METAHUMAN_SUBSYSTEM.is_object_added_for_editing(self.character):
            unreal.log(f"[MetaHumanGenerator] Entering edit mode for {self.object_path}")
            if not _METAHUMAN_SUBSYSTEM.try_add_object_to_edit(character=self.character):
                raise ValueError("Failed to add character to edit mode")
            self.is_in_edit_mode = True
        else:
            unreal.log(f"[MetaHumanGenerator] Character {self.object_path} already in edit mode")

    def finalize(self):
        """Exit edit mode and remove from cache."""
        if self.is_in_edit_mode:
            unreal.log(f"[MetaHumanGenerator] Exiting edit mode for {self.object_path}")
            if _METAHUMAN_SUBSYSTEM.is_object_added_for_editing(self.character):
                _METAHUMAN_SUBSYSTEM.remove_object_to_edit(self.character)
            self.is_in_edit_mode = False
        if self.object_path in _session_cache:
            del _session_cache[self.object_path]


_session_cache: dict[str, MetaHumanEditSession] = {}

def get_or_create_session(object_path: str, cache: bool = True) -> MetaHumanEditSession:
    """Get cached edit session or create new one.

    Args:
        object_path: Path to MetaHuman character asset
        cache: If True, cache the session for reuse (default: True)

    Returns:
        MetaHumanEditSession for the character.
    """
    if object_path in _session_cache:
        unreal.log(f"[MetaHumanGenerator] Cache HIT for {object_path}, reusing session")
        return _session_cache[object_path]

    unreal.log(f"[MetaHumanGenerator] Cache MISS for {object_path}, creating new session")
    character = unreal.load_object(None, object_path)
    if not character:
        raise ValueError(f"Failed to load MetaHuman asset at {object_path}")

    session = unreal.new_object(MetaHumanEditSession)
    if not session:
        raise RuntimeError("Failed to create MetaHumanEditSession object")

    session.object_path = object_path
    session.character = character
    session.is_in_edit_mode = False
    session.initialize()

    if cache:
        _session_cache[object_path] = session
    return session


def clear_session_cache() -> None:
    """Clear all cached edit sessions and exit their edit modes.

    Useful for testing and cleanup. Exits edit mode for all cached sessions.
    """
    for session in list(_session_cache.values()):
        session.finalize()
    _session_cache.clear()
    unreal.log("[MetaHumanGenerator] Session cache cleared")


def _cleanup_on_shutdown() -> None:
    """Cleanup function called on plugin shutdown."""
    try:
        if _METAHUMAN_SUBSYSTEM:
            clear_session_cache()
    except:
        pass


atexit.register(_cleanup_on_shutdown)