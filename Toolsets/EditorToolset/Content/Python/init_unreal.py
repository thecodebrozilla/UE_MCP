# Copyright Epic Games, Inc. All Rights Reserved.

import unreal

from editor_toolset import skills  # noqa: F401 — imports register @agent_skill modules
from editor_toolset import toolsets
from editor_toolset import tests

toolsets._registration.register()

tests._test_runner = unreal.PythonTestRunner.create(
    'AI.Toolsets.EditorToolset',
    unreal.PythonTestRunnerSearchOptions(root_module=tests.__name__))
