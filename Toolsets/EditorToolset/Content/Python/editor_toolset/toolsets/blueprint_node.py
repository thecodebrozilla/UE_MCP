# Copyright Epic Games, Inc. All Rights Reserved.
"""Core Blueprint graph data types shared across blueprint modules."""

from __future__ import annotations

import unreal


@unreal.ustruct()
class PinID(unreal.StructBase):
    """Uniquely identifies a pin on a Blueprint graph node."""
    node = unreal.uproperty(unreal.EdGraphNode)
    index_id = unreal.uproperty(int)
    direction = unreal.uproperty(unreal.EdGraphPinDirection)
    # [5.7 port] Cache the FName pin name so _resolve_pin can reconstruct an
    # FBlueprintGraphPin without calling list_all_pins() (5.8-only).
    pin_name = unreal.uproperty(str)


@unreal.ustruct()
class PinInfo(unreal.StructBase):
    """Summarizes information about a pin on a Blueprint node."""
    name = unreal.uproperty(str)
    type_id = unreal.uproperty(str)
    pin_id = unreal.uproperty(PinID)
    connected_pins = unreal.uproperty(unreal.Array(PinID))
    value = unreal.uproperty(str)


@unreal.ustruct()
class NodeInfo(unreal.StructBase):
    """
    Summarizes information about a node in a Blueprint graph.
    When referring to a node in messages to the user use Title from the type_id.
    """
    type_id = unreal.uproperty(str, meta={'ToolTip': 'type_id is in the format Category|Title'})
    node = unreal.uproperty(unreal.EdGraphNode)
    position = unreal.uproperty(unreal.IntPoint)
    input_pins = unreal.uproperty(unreal.Array(PinInfo))
    output_pins = unreal.uproperty(unreal.Array(PinInfo))
