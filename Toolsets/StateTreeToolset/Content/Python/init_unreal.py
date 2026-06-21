# Copyright Epic Games, Inc. All Rights Reserved.

import unreal

from state_tree_toolset import toolsets
from state_tree_toolset import tests

toolsets._registration.register()

tests._test_runner = unreal.PythonTestRunner.create(
    'AI.Toolsets.StateTreeToolset',
    unreal.PythonTestRunnerSearchOptions(root_module=tests.__name__))
