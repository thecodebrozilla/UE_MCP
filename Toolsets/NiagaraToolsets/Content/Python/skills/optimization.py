# Copyright Epic Games, Inc. All Rights Reserved.

import unreal
from toolset_registry.agent_skill import agent_skill

_INSTRUCTIONS = """
## Sim target -- the headline cost
System and Emitter scripts always run on CPU through the Niagara VM. Only Particle scripts move to GPU when SimTarget is GPU. Switching an emitter to GPU does not eliminate its per-emitter CPU cost -- it just moves the particle work.

GPU dispatches in fixed-size waves: an emitter under one wave's worth of particles wastes the same hardware as a full one. Rule of thumb: comfortably above ~100 simultaneous particles, not gating gameplay or silhouette, is a viable GPU candidate.

Platform context matters more than raw particle count. Mobile and Switch are typically GPU-bound -- keep simple sims on CPU to preserve GPU headroom. CPU-bound PC projects benefit from offloading moderate-count sims to GPU. Some platforms have no compute support at all; those emitters are CPU-only regardless.

## Emitter consolidation -- the primary lever
Reducing emitter count beats almost any other optimization. Three patterns:

- **One emitter, multiple renderers.** A single particle stream feeds Sprite + Light + Mesh simultaneously. The sim cost is paid once.
- **Multi-source spawning in one emitter.** Replace N near-identical emitters (e.g. one per bone) with one emitter and N spawn modules tagged by spawn group. Particles inherit the group ID; downstream modules branch on it. Cuts VM overhead linearly with N.
- **Cross-emitter reads via Attribute Reader, not Event Handlers.** Event Handlers are valid for genuinely event-triggered logic but pay higher per-crossing cost.

## Bounds
The choice gates CPU recalc cost and GPU compatibility:

- **Fixed** -- no per-frame recalc, works on CPU and GPU. Cheapest. Don't oversize on small fast-moving effects -- they stay relevant off-screen and waste cycles.
- **Dynamic** -- per-frame recalc from particle positions. CPU emitters only. Use only when scale varies wildly between instances.
- **Programmable** -- driven by an emitter-bounds module. Works on GPU. The choice for GPU emitters needing per-instance scaled or moving bounds.

Declare initial streaming bounds on the system so the renderer registers the system immediately on activation.

## Scalability and Effect Types
Effect Types apply project-wide significance handling -- distance culling, instance limits, visibility culling, cull-proxy mode -- to every system that references them. They're shared assets; never create a new one without confirming first. If no existing one matches, ask. Pick along two axes: gameplay vs environment (gameplay culls tighter, higher priority) and burst vs looping (burst tolerates instant culling; looping needs a delay to avoid pop).

Per-emitter and per-renderer scalability gates flag pieces to run only on specific quality tiers; gated-off pieces incur no sim or render cost. Use these to land the low-spec degradation path -- including CPU-only platforms where compute-shader emitters must be gated off entirely.

Budget Scaling on the asset reacts to the project's global FX budget at runtime. Inspect the asset for current properties.

## Pooling cost
Pooling pays off for frequently spawned, moderate-volume effects -- impacts, hit reactions, footsteps. Below a threshold, the bookkeeping costs more than it saves. Auto-release for fire-and-forget; manual release when gameplay code owns the lifetime (status auras, channeled abilities). The blueprint interop skill covers the spawn-side wiring.

## System-level cheap wins
- **Require Current Frame Data** -- disable for non-moving / statically attached systems. Lets ticks start earlier and spreads CPU load. Trade-off: visible lag between effect and source -- keep enabled on high-speed gameplay tracking moving sockets (projectiles, muzzle flashes).
- **Owner-velocity inheritance** -- disable when not attached to a moving object. Removes a game-thread dependency.
- **Trim Attributes** -- keep on. Strips unused particle attributes at compile.

## Particle-only meshes
When a static mesh is only ever a particle, strip what the renderer will never use: collisions, cast-shadow on the LOD (especially translucent), distance-field resolution (set to zero), and unused UV channels.

## Burst spawning
Large single-frame spawns hitch the CPU. Spread big counts across frames.

## Renderer-level optimization
Covered in the renderers skill alongside per-renderer rules.
"""


@agent_skill
class NiagaraOptimizationSkill(unreal.AgentSkill):
    """Covers reducing the CPU and GPU cost of Niagara effects -- sim target, emitter consolidation, bounds, scalability and Effect Types, pooling, system-level cheap wins, particle-only mesh stripping, and burst spawning."""

    instructions = _INSTRUCTIONS
    toolsets = [unreal.NiagaraToolset_Info, unreal.NiagaraToolset_System, unreal.NiagaraToolset_Component]
