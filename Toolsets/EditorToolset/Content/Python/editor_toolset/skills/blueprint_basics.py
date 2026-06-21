# Copyright Epic Games, Inc. All Rights Reserved.

import unreal

from toolset_registry.agent_skill import agent_skill

_INSTRUCTIONS = """\
READING GRAPHS
- Use the DSL to read a graph as text; this is the natural way to understand
  logic before modifying it with the DSL.
- Use node inspection tools when you need to navigate or examine specific nodes
  rather than read the whole graph. For example, filtering to entry-point nodes
  then reading the connected subgraph isolates one event chain from a large Event Graph.

WRITING GRAPHS
- Use the DSL to populate event and function graphs.
- Never guess node type IDs or pin names. Always look up node types and confirm
  exact pin names before writing DSL or connecting nodes via the API.
- Use function graphs for logic that returns values or needs to be reused;
  keep the Event Graph for event-driven and async logic.
- Only compile once all graph modifications for a logical unit are complete.

BATCH OPERATIONS
- For work that spans multiple assets (creating many Blueprints, adding variables
  in bulk, reparenting), use programmatic tool calling instead of many individual tool calls.

COMMON GOTCHAS
- Pure node outputs are not cached: each wire connected to a pure node output
  reruns the calculation. Store the result in a variable if used more than once.
- Casting to a Blueprint creates a hard load dependency: all assets that Blueprint
  references load into memory even if the cast fails. Prefer interfaces for loose coupling.
- The Blueprint must be compiled before structural changes take effect. Added or
  removed components, new variables, and function signature changes won't appear
  on the CDO or on newly spawned instances until the next compile.
- Runtime physics operations require Movable component mobility. Components inherit
  a default mobility that is often Static; set mobility to Movable before enabling
  simulation or applying impulses, or the call is rejected at runtime.
"""

@agent_skill
class BlueprintBasicsSkill(unreal.AgentSkill):
    """Provides guidance on creating and editing Blueprints in Unreal Engine.
    Apply this skill whenever creating, modifying, or reviewing Blueprint assets."""

    instructions = _INSTRUCTIONS
