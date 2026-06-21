# Copyright Epic Games, Inc. All Rights Reserved.

import unreal
from toolset_registry.agent_skill import agent_skill

_INSTRUCTIONS = """
Never remove or modify anything without confirmation. Present findings; let the user decide.

## What to look for
The non-obvious orphan classes -- the ones a generic "unused asset" sweep will miss:

- **Modules that run but do nothing.** A spawn-rate module hardcoded to zero on a non-looping emitter; collision disabled by default with no role for the effect; a force module reading a system variable that no module writes anymore.
- **Dynamic Input chains reading dead attributes.** When a writer module is removed, downstream Dynamic Inputs reading the attribute it produced still resolve -- to defaults or stale values -- without erroring.
- **Data Interface initializers for removed consumers.** Set-parameter modules that initialize a mesh reader, skeletal reader, or similar Data Interface for a module no longer in the stack.
- **User Parameters whose driving modules are gone.** Exposed but unreferenced; they survive because nothing flags them.

The common thread: removal of one module silently strands its readers and initializers. Walk the stack with that lens.

## Before judging
Understand the effect's intended use case. Something that looks unused in isolation may be intentional context (a collision module disabled by default but flipped on by a consumer-side override; a parameter exposed for designers).

## Presenting findings
Give the user a per-item table with location, what it is, and why you flagged it. State which you'd remove and why -- but wait for confirmation before touching anything. If the system is clean, say so and stop.

## On removal
For an orphaned Dynamic Input chain, the input needs a replacement -- a direct value or a Dynamic Input that matches the original intent. Ask if the intent isn't obvious from context.
"""


@agent_skill
class NiagaraCleanupSkill(unreal.AgentSkill):
    """Covers inspecting a Niagara System for cleanup candidates -- orphaned modules, unused User Parameters, and leftover state after modifications -- and presenting them to the user before removal."""

    instructions = _INSTRUCTIONS
    toolsets = [unreal.NiagaraToolset_Info, unreal.NiagaraToolset_System, unreal.NiagaraToolset_Component]
