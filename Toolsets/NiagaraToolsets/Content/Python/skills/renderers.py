# Copyright Epic Games, Inc. All Rights Reserved.

import unreal
from toolset_registry.agent_skill import agent_skill

_INSTRUCTIONS = """
## Renderer choice
Sprite is the default for camera-facing cards (smoke, sparks, dust). Mesh for chunky 3D (debris, shrapnel, hero cores). Ribbon for trails / beams / connecting threads anchored to ordered particles.

Three are CPU-only and force the whole emitter to CPU when present:

- **Light** -- hero accents only. One particle, low count, very short lifetime; never on a high-count emitter. Disable on low-tier platforms; particles don't cast shadows so the renderer is the only cost.
- **Decal** -- projects a deferred decal onto world geometry. Static once spawned -- decals don't move, so forces and velocity solves don't apply. Position is set at spawn.
- **Component** -- per-particle Blueprint or Actor. Very expensive; reserve for set pieces.

Picking any of these usually justifies the emitter staying on CPU.

## Light renderer specifics
No material -- it parameterizes a runtime point light directly. Author values via the light-attributes module. Material-based dynamic parameters don't reach it.

## Decal renderer specifics
Author values via the decal-attributes module. Material-based dynamic parameters don't reach decal materials either.

## Source mode -- per-particle vs per-emitter rendering
Sprite and Mesh expose a Source Mode toggle: Particles (default) draws one card or mesh per particle and reads particle-scope bindings; Emitter draws one at the emitter position, reads emitter-scope bindings, and ignores per-particle data. Useful for single flash sprites, emitter-bounds markers, or any one-per-emitter visual driven by emitter-scope state. Affects rendering only -- not simulation or particle count.

## Visibility tag
When one emitter mixes renderer types (Sprite vs Mesh vs Light vs Decal), the visibility-tag attribute routes each particle to exactly one renderer. Ribbons don't participate -- split a ribbon stream into separate emitters or use ribbon-ID disambiguation.

For mesh variation only (same renderer, different meshes), the Meshes array is cheaper than visibility tags -- one renderer holds N meshes, particles pick by index. No per-index material override; materials are uniform across the array. For per-particle material differentiation, bake onto the mesh assets or fall back to visibility tags.

## Sprite alignment and facing
Both properties default to Automatic, which reads particle-scope hints if a module writes them and falls back otherwise. Leave them automatic in most cases. The most common reason to override is velocity-aligned sprites combined with speed-driven scaling.

## Mesh renderer
The mesh asset carries the look -- geometry, surface, UVs, baked material assignments. Niagara mostly sets transforms and drives a few attributes (color, scale) the material reads. First step when changing a Mesh renderer's look is to swap the mesh asset, not override materials. Reach for Override Materials only when the baked material is genuinely wrong (lit vs unlit), the same mesh needs different materials across systems and re-baking isn't viable, or a per-particle attribute is needed and the baked material doesn't wire it through. Override Materials is gated by an enable toggle; empty entries fall through to the baked material.

## Material dependencies that fail silently
These are the gotchas an LLM can't see in the asset:

- **Dynamic Material Parameters** writes per-particle values to material `Dynamic Parameter` slots. If the material doesn't declare matching nodes (correct index and channel layout), writes are silently dropped -- no error, no warning. Verify the material first.
- **SubUV / flipbook** requires three things lined up: the renderer's sub-image grid matches the texture, a SubUV-animation module runs in particle update, and that module's renderer-info input points at the consuming renderer.
- **Renderer Info Data Interfaces** appear as inputs on multiple module types; they have to be set to the intended renderer or the module is wired to nothing.

## Sort mode
Defaults to None. Keep it there when blending allows -- any other mode adds GPU overhead and index-buffer memory. The performance skill covers culling, distance fade, and other per-renderer optimization knobs.
"""


@agent_skill
class NiagaraRenderersSkill(unreal.AgentSkill):
    """Covers choosing and configuring Niagara renderers -- per-type rules (Sprite, Mesh, Ribbon, Light, Decal, Component), source mode, sprite alignment, visibility-tag and mesh-variant differentiation, sort mode, and silent-failure material dependencies."""

    instructions = _INSTRUCTIONS
    toolsets = [unreal.NiagaraToolset_Info, unreal.NiagaraToolset_System, unreal.NiagaraToolset_Component]
