# Copyright Epic Games, Inc. All Rights Reserved.

import unreal

from toolset_registry import tests

tests._toolset_registry_test_runner = unreal.PythonTestRunner.create(
    'AI.ToolsetRegistry.PythonTests',
    unreal.PythonTestRunnerSearchOptions(
        root_module=tests.__name__,
        test_name_globs=['toolset_registry.tests.test_*',
                         'toolset_registry.tests._asyncio.*']))
