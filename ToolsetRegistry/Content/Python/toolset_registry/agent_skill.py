# Copyright Epic Games, Inc. All Rights Reserved.

import inspect
import unreal


def agent_skill(cls):
    """Decorator that registers a Python-defined AgentSkill.

    Applies @unreal.uclass() and populates the CDO from class attributes:
    - description: taken from the class docstring
    - instructions: taken from the instructions class attribute (str)
    """
    doc = cls.__doc__
    instructions = getattr(cls, 'instructions', '')

    cls = unreal.uclass()(cls)
    cdo = cls.get_default_object()
    cdo.set_editor_property('description', inspect.cleandoc(doc or ''))
    cdo.set_editor_property('instructions', instructions)
    return cls
