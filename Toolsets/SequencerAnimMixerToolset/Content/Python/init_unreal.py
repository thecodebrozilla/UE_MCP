# Copyright Epic Games, Inc. All Rights Reserved.

import unreal

from sequencer_animmixer_toolset import toolsets
from sequencer_animmixer_toolset import tests

toolsets._registration.register()

tests._test_runner = unreal.PythonTestRunner.create(
    'AI.Toolsets.SequencerAnimMixerToolset',
    unreal.PythonTestRunnerSearchOptions(root_module=tests.__name__))
