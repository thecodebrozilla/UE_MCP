# Copyright Epic Games, Inc. All Rights Reserved.

import unreal

# Only register toolset if MetaHuman subsystem is available
metahuman_subsystem = unreal.get_editor_subsystem(unreal.MetaHumanCharacterEditorSubsystem)
if metahuman_subsystem:
    from metahuman_toolset.session import clear_session_cache
    from metahuman_toolset.metahuman import MetaHumanToolset

    # Clear any stale sessions from previous Python session
    clear_session_cache()

    unreal.ToolsetRegistry.register_toolset_class(MetaHumanToolset)
    unreal.log("[MetaHumanGenerator] Toolset registered successfully")
else:
    unreal.log_warning("[MetaHumanGenerator] MetaHumanCharacterEditorSubsystem not available, toolset not registered")
