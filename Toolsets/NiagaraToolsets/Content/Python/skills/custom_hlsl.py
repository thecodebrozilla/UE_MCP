# Copyright Epic Games, Inc. All Rights Reserved.

import unreal
from toolset_registry.agent_skill import agent_skill

_INSTRUCTIONS = """
## Usage Rules
- Single rvalue of the correct type. No variable declarations, no `return`.
- Must compile on both the CPU VM and GPU. Stick to basic math/trig (`sin`, `cos`, `rcp`, `abs`, `min`, `max`); intrinsics like `smoothstep` aren't implemented on the CPU VM and will silently diverge.
- Scope rules: a Particle expression can read Emitter and System; an Emitter expression cannot read Particles.
"""


@agent_skill
class NiagaraCustomHLSLSkill(unreal.AgentSkill):
    """Covers writing inline HLSL expressions in Niagara dynamic inputs -- single-rvalue syntax, CPU VM and GPU intrinsic compatibility, and Particle/Emitter/System scope rules."""

    instructions = _INSTRUCTIONS
    toolsets = [unreal.NiagaraToolset_Info, unreal.NiagaraToolset_System, unreal.NiagaraToolset_Component]
