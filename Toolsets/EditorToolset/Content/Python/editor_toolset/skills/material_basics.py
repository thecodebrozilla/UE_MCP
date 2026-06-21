# Copyright Epic Games, Inc. All Rights Reserved.

import unreal

from toolset_registry.agent_skill import agent_skill

_INSTRUCTIONS = (
    'Decision order when asked for a material:\n'
    '1. Search for an existing Material or MaterialInstance that already covers the need.\n'
    '2. If a suitable parent exists, create a MaterialInstance from it.\n'
    '3. Create a new Material only when nothing close enough exists.\n'
    '\n'
    'When creating a new Material:\n'
    '- Search for existing MaterialFunctions before writing graph logic by hand. '
    'Reuse what you find. Only create a new MaterialFunction when nothing suitable '
    'exists and the logic is worth sharing across materials.\n'
    '- Expose parameters for anything a user would want to vary per-instance. '
    'Group related parameters under a shared name so they appear organised in the '
    'Material Instance editor.\n'
    '\n'
    'Common gotchas:\n'
    '- Neutral normal is (0, 0, 1) — pure blue, not zero.\n'
    '- Static switch parameters multiply permutations: 2 switches = 4 shaders, '
    '4 switches = 16. Keep them minimal on parent materials.\n'
)

@agent_skill
class MaterialBasicsSkill(unreal.AgentSkill):
    """Provides guidance on working with Materials and MaterialInstances in Unreal Engine.
    Apply this skill whenever creating, modifying, or choosing between Material assets."""

    instructions = _INSTRUCTIONS
