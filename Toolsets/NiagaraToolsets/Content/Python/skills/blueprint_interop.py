# Copyright Epic Games, Inc. All Rights Reserved.

import unreal
from toolset_registry.agent_skill import agent_skill

_INSTRUCTIONS = """
## Spawn mechanism
Match the mechanism to the effect's lifetime, ownership, and trigger source. Don't stack mechanisms.

- **Component on the actor BP** -- the effect is part of the actor's identity (projectile trail, weapon idle, carried-item glow). Construction amortizes across the actor's lifetime. If the BP triggers the start manually (e.g. fuse delay), turn off auto-activate.
- **Spawn at location** -- one-shot world FX with no owning actor. Capture the return value if parameters need setting post-spawn or for early deactivate.
- **Spawn attached** -- one-shot following a moving target the spawner doesn't own. Pays per-frame transform parenting; only use when the FX must follow a target you don't own.
- **Gameplay Cue Notify** -- whenever a Gameplay Tag association exists. Data-driven and decouples gameplay from the BP that defines the FX. Requires the Gameplay Abilities plugin.
- **Anim notify (one-shot or timed)** -- start, duration, and end are dictated by an animation clip.
- **Niagara Data Channel** -- a high-frequency repeating event class (footsteps, bullet impacts, projectile trails at scale) that an existing channel already covers. Publish to the channel; don't author a per-event spawn call competing with it.

## Parameter binding
Drive User Parameters from BP via the typed Set Niagara Variable nodes on a component reference (component on the BP, spawn return value, or Get Spawned Effect on an anim notify).

- Pass the bare parameter name -- no `User.` prefix.
- No enum setter exists. Set the underlying int and let Niagara reinterpret.
- Type must match exactly. A wrong-type set is a silent no-op, not an error. World-space anchors are Position (LWC-aware), not Vector3; directions, normals, velocities, and offsets are Vector3.

## Pooling and lifetime
Pooling is set by the spawner, not on the asset.

- Repeating one-shots must use auto-release pooling. The default leaks component allocations one per spawn.
- Auto-destroy lives on the spawn node (not on the component) and only applies to fire-and-forget spawns. Set it true unless the BP itself calls deactivate. Components placed on a BP class don't have this pin -- they persist with the actor.

The performance skill covers pooling cost trade-offs and when pooling pays off.
"""


@agent_skill
class NiagaraBlueprintInteropSkill(unreal.AgentSkill):
    """Covers driving Niagara Systems from Blueprint at runtime -- spawn-mechanism choice, parameter binding, and pooling and lifetime."""

    instructions = _INSTRUCTIONS
    toolsets = [unreal.NiagaraToolset_Info, unreal.NiagaraToolset_System, unreal.NiagaraToolset_Blueprint, unreal.NiagaraToolset_Component]
