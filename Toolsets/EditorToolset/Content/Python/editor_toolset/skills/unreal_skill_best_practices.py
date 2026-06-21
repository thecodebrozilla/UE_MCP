# Copyright Epic Games, Inc. All Rights Reserved.

import unreal

from toolset_registry.agent_skill import agent_skill

_INSTRUCTIONS = (
    'A good skill is:\n'
    '- Novel: content should be things the agent doesn\'t already know or can\'t learn by using tools.\n'
    '- Collegial: write like you\'re briefing a knowledgeable colleague, not authoring documentation.\n'
    '- Flexible: use conceptual explanations, step-by-step instructions, or a mix — whichever is clearest.\n'
    '- Durable: avoid embedding property names, tool names, or other details that change over time.\n'
    '- Agnostic: avoid referencing orchestration systems, role names, model names, or infrastructure specifics.\n'
    '- Parsimonious: every token costs context. Cut anything that isn\'t essential or evergreen.\n'
)

@agent_skill
class UnrealSkillBestPracticesSkill(unreal.AgentSkill):
    """Provides best practices for creating, updating, and reviewing skills in Unreal.
    Apply this skill whenever creating, updating, or reviewing skills in Unreal."""

    instructions = _INSTRUCTIONS
