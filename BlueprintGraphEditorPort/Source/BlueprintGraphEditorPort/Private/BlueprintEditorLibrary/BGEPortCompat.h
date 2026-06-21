// Copyright Epic Games, Inc. All Rights Reserved.
//
// BGEPortCompat: local backports of helper functions that UE 5.8 added to engine
// classes but that UE 5.7 lacks. These mirror the 5.8 implementations as free
// functions so the bundled BlueprintGraphEditorPort plugin compiles against 5.7.
//
//   - UBlueprintEditorLibrary::FindThenPin           (5.8 BlueprintEditorLibrary.cpp ~2539)
//   - UBlueprintEditorLibrary::PinTypeToJsonSchema   (5.8 BlueprintEditorLibrary.cpp ~2237)
//   - UEdGraphSchema_K2::EstimateNodeWidth           (5.8 EdGraphSchema_K2.cpp ~7051)
//   - UEdGraphSchema_K2::EstimateNodeHeight          (5.8 EdGraphSchema_K2.cpp ~6984)
//
#pragma once

#include "CoreMinimal.h"
#include "BlueprintEditorLibrary/BlueprintGraphPin.h"

class UK2Node;
class UClass;
class UEdGraphNode;
struct FEdGraphPinType;

namespace BGEPortCompat
{
	/** Returns the (visible) exec "then" output pin of the given node, wrapped as an FBlueprintGraphPin. */
	FBlueprintGraphPin FindThenPin(const UK2Node* Node);

	/** Produces a JSON schema string describing the supplied pin type. */
	FString PinTypeToJsonSchema(const FEdGraphPinType& PinType, const UClass* SelfContext);

	/** Best-guess width of the node prior to Slate laying it out. */
	float EstimateNodeWidth(const UEdGraphNode* Node);

	/** Best-guess height of the node prior to Slate laying it out. */
	float EstimateNodeHeight(const UEdGraphNode* Node);
}
