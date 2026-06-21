# Copyright Epic Games, Inc. All Rights Reserved.

import unreal

from conversation_toolset import toolsets
from conversation_toolset import tests

toolsets._registration.register()

tests._test_runner =  unreal.PythonTestRunner.create(
    'AI.Toolsets.ConversationToolset',
    unreal.PythonTestRunnerSearchOptions(root_module=tests.__name__))