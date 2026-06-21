# Copyright Epic Games, Inc. All Rights Reserved.

import unreal

from aimodule_toolset import toolsets
from aimodule_toolset import tests

toolsets._registration.register()

tests._test_runner = unreal.PythonTestRunner.create(
    'AI.Toolsets.AIModuleToolset',
    unreal.PythonTestRunnerSearchOptions(root_module=tests.__name__))