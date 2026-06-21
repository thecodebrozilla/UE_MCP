# Copyright Epic Games, Inc. All Rights Reserved.

import unreal
from toolset_registry.agent_skill import agent_skill

_INSTRUCTIONS = """
## Templates for new assets
- When searching for any asset type relevant to a Niagara system — including emitters, materials, textures, and modules — always search across all relevant content folders starting with /Niagara/, and /NiagaraToolsets/. Do not restrict searches to a single folder. Do not stop at the first search result. 

## Sim Target -- CPU vs GPU
- A System can mix CPU and GPU emitters freely.
- CPU is required to fire Niagara Events and to ship to platforms without compute-shader support. Default to CPU when compute support is uncertain.
- GPU is required for GPU-only Data Interfaces, Simulation Stages, and sustaining hundreds+ of particles.

## Editing
- Read module descriptions and input tooltips before using them -- functionality and naming conventions drift. Module functionality is rarely fully captured by its name.
- When finding scripts, the default visibility filter restricts results to library-exposed scripts. Only widen to hidden / unexposed when the user has explicitly asked for one.

## Script Stack Ordering
The stack runs in fixed scope/phase order: System -> Emitter -> Particle, each with Spawn (once at creation) and Update (every tick). Place modules by what they do:
- One-shot constants and one-time computed values: Spawn phase of the relevant scope.
- Per-tick recomputed values driven by inputs that change at runtime: System or Emitter Update.
- Per-particle initialization: Particle Spawn, set via the initialize particles module before any later Set/override modules.
- Forces, then collision, then the velocity solve, in that order, in Particle Update. The solve runs exactly once per tick.

## System/Emitter State
- Loop Behavior: Once, Infinite, or Multiple with Loop Count. Always verify the loop behavior matches intent.
- Per-emitter scalability requires the emitter to evaluate its own state rather than inherit from the system.
- Setting Life Cycle Mode to Self only makes the emitter manage its own lifecycle, but doesn't change how it loops.

## Particle Initialization
- Configure initial values on the initialize particles module first; only add a separate Set/Initialize module when the value isn't exposed there.
- Hue shift has no effect on a neutral (white) base color. Set the base color to RED (1, 0, 0) for hue shift to work.

## Collision
- Collision works on both CPU and GPU; mode options switch with sim target. Inspect the module schema for current options.
- GPU depth-buffer collision against opaque materials reads the particles' own pixels and self-collides. Enable Partial Depth to exclude particle pixels from the depth read.

## Random Values
For range requests ("10 to 20", "1-3 seconds"), configure randomness -- don't pick a single value. Prefer the module's own min/max mode; fall back to a Random dynamic input when min/max isn't exposed.

## Parameter Namespaces
- User       -- externally set; read anywhere.
- Engine     -- engine-provided (DeltaTime, Owner xform, ExecutionState); read-only.
- System     -- system-scope; written by System scripts; visible to Emitter/Particle.
- Emitter    -- emitter-scope; written by Emitter scripts; visible to Particle.
- Particles  -- per-particle; written by Particle scripts.

## Linked Parameters
- Namespace Format: `<Namespace>.<ModuleInstanceName>.<AttributeName>` -- Use the module's actual instance name (renaming a module changes the linked path); never the literal `MODULE` placeholder.
- Global controls are often defined as user, system or emitter parameters. Follow linked parameters to get the full picture.

## Dynamic Inputs
- Follow the dynamic input chains in full before deciding on a course of action.

## User Parameters
- Evaluated every frame -- keep them targeted; avoid expensive data interfaces.
- They are the external interface into the system. The Blueprint interop skill covers binding them at runtime.

## Coordinate Spaces
- The most common mistake is choosing Local Space because the system is attached to the actor — attachment controls spawn origin, space setting controls post-spawn behavior. These are independent concerns.
- Default to World Space unless particles must rigidly follow the actor; Local Space is the exception, not the starting point.
- Individual modules can declare a space independent of the emitter; check the module's space input.
- LWC: keep `Position`-typed data as `Position`. Do not convert to `Vector` unless no other option exists.

## HLSL Expressions
- Last resort. Prefer dynamic inputs or module configuration.

## Sprite Rotations
- Sprites can be tumbled in 3D -- Use the mesh rotation modules (including aerodynamic drag when appropriate) and utilize the Align Sprite To Mesh Orientation module.

## Scale
- Unreal Engine operates at 1 unit = 1 cm, so parameter values map directly to real-world scales. Verify size, velocity, and lifetime against the real-world scale of the subject the effect represents.

## Verify Intent
- After building or modifying a system, trace the full input chain of every velocity-affecting module and every appearance-affecting module.
- Every module present is executing — Verify the resolved behavior matches the **stated intent**, not just the authored intent.

## Verify State
- Edits can put a system into a bad state. You must verify the system is valid after modifications. Open the Niagara editor and check for stack errors and warnings. Opening the editor is necessary for the errors to surface.

## Materials
- Prefer material instances over materials.
- Materials access per particle canonical data via `Particle*` nodes; custom per-particle dynamic data flows through the dynamic-parameter material node, populated from the matching particle module.
- If a particle will be seen from both sides make sure the material supports it by activating the Two Sided option.
- Materials require the correct usage flags per renderer type -- Used with Niagara Sprites/Ribbons/Mesh Particles. Each usage flag comes with a cost. Apply the minimal set.
- Prefer Masked over Translucent materials. Only use Translucent when the effect genuinely requires partial transparency or soft blending.
- Translucent materials do not support Metallic, Specular, Roughness, Normal by default. Translucency Lighting Mode must be set to one of the Directional options to activate these inputs.
- The renderers skill covers per-renderer material requirements.

## Out of scope
The toolset doesn't support Lightweight Emitters or Niagara Data Channels. If a task requires either, surface the limit rather than working around it. Avoid listing assets which reference Lightweight or Data Channels when asked.
"""


@agent_skill
class NiagaraFundamentalsSkill(unreal.AgentSkill):
    """Covers the foundational rules for authoring Niagara systems -- templates, sim target, script stack ordering, lifecycle and initialization, parameter namespaces, randomness, coordinate spaces, HLSL expressions, User Parameters, and materials."""

    instructions = _INSTRUCTIONS
    toolsets = [unreal.NiagaraToolset_Info, unreal.NiagaraToolset_System, unreal.NiagaraToolset_Blueprint, unreal.NiagaraToolset_Component]
