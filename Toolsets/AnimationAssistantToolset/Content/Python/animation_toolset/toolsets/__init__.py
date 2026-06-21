# Copyright Epic Games, Inc. All Rights Reserved.

from animation_toolset.toolsets.controlrig import ControlRigTools
from animation_toolset.toolsets.sequencer import SequencerTools
from animation_toolset.toolsets.keyframing import SequencerKeyframingTools
from animation_toolset.toolsets.controlrig_sequencer import SequencerControlRigTools
from animation_toolset.toolsets.outliner import SequencerOutlinerTools
from animation_toolset.toolsets.conditions import SequencerConditionTools
from animation_toolset.toolsets.custom_bindings import SequencerCustomBindingTools
from animation_toolset.toolsets.import_export import SequencerImportExportTools
from toolset_registry.registration import Registration

_registration = Registration([
    ControlRigTools,
    SequencerTools,
    SequencerKeyframingTools,
    SequencerControlRigTools,
    SequencerOutlinerTools,
    SequencerConditionTools,
    SequencerCustomBindingTools,
    SequencerImportExportTools,
])
