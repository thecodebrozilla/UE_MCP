# Copyright Epic Games, Inc. All Rights Reserved.

import importlib

import unreal

from animation_toolset import toolsets

toolsets._registration.register()

for _module_path, _runner_name in [
    ('animation_toolset.tests.test_control_rig_toolset',       'AI.Toolsets.AnimationToolset.ControlRig'),
    ('animation_toolset.tests.test_sequencer_toolset',          'AI.Toolsets.AnimationToolset.Sequencer'),
    ('animation_toolset.tests.test_sequencer_keyframing',       'AI.Toolsets.AnimationToolset.SequencerKeyframing'),
    ('animation_toolset.tests.test_sequencer_control_rig',      'AI.Toolsets.AnimationToolset.SequencerControlRig'),
    ('animation_toolset.tests.test_sequencer_outliner',         'AI.Toolsets.AnimationToolset.SequencerOutliner'),
    ('animation_toolset.tests.test_sequencer_conditions',       'AI.Toolsets.AnimationToolset.SequencerConditions'),
    ('animation_toolset.tests.test_sequencer_custom_bindings',  'AI.Toolsets.AnimationToolset.SequencerCustomBindings'),
    ('animation_toolset.tests.test_sequencer_import_export',    'AI.Toolsets.AnimationToolset.SequencerImportExport'),
]:
    _module = importlib.import_module(_module_path)
    _module._test_runner = unreal.PythonTestRunner.create(
        _runner_name,
        unreal.PythonTestRunnerSearchOptions(
            root_module=_module.__package__,
            test_name_globs=[f'{_module.__name__}*']))
