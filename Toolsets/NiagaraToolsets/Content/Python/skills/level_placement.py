# Copyright Epic Games, Inc. All Rights Reserved.

import unreal
from toolset_registry.agent_skill import agent_skill

_INSTRUCTIONS = """
Generic template systems can be found in the Niagara and NiagaraToolsets plugins.

Search the project for candidate VFX assets matching the user's request. Present the matches with location and a brief description, then stop and wait for the user to pick one. Do not place the first match. If nothing matches, say so -- do not author a new system unless the user explicitly asks.
"""


@agent_skill
class NiagaraLevelPlacementSkill(unreal.AgentSkill):
    """Triggers when the user asks to place or spawn a gameplay VFX -- smoke, plume, fire, explosion, spark, trail, beam, muzzle flash, impact, burst, dust, cloud, ember, projectile, hit, ability, status effect. Enforces the search-present-confirm gate before placing an existing asset."""

    instructions = _INSTRUCTIONS
    toolsets = [unreal.NiagaraToolset_Info, unreal.NiagaraToolset_System, unreal.NiagaraToolset_Component]
