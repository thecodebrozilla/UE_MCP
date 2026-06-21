// Copyright Epic Games, Inc. All Rights Reserved.

#include "BlueprintEditorLibrary/BGEPortCompat.h"

#include "EdGraphSchema_K2.h"
#include "K2Node.h"
#include "K2Node_EditablePinBase.h"
#include "K2Node_CallFunction.h"
#include "K2Node_Event.h"
#include "KismetCompiler.h"
#include "KismetCompilerMisc.h"
#include "Editor/EditorEngine.h"
#include "Engine/Font.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonSerializer.h"
#include "Serialization/JsonWriter.h"
#include "JsonSchema/JsonSchemaGenerator.h"

namespace BGEPortCompat
{
	// Local mirror of UE::Private::ForEach*Pin helpers from 5.8 BlueprintEditorLibrary.cpp.
	static void ForEachVisiblePin(const UK2Node* Node, TFunctionRef<bool(UEdGraphPin*)> Ftor)
	{
		for (UEdGraphPin* Pin : Node->Pins)
		{
			if (Pin->bHidden)
			{
				continue;
			}

			if (!Ftor(Pin))
			{
				return;
			}
		}
	}

	static void ForEachVisibleOutputPin(const UK2Node* Node, TFunctionRef<bool(UEdGraphPin*)> Ftor)
	{
		ForEachVisiblePin(Node, [&Ftor](UEdGraphPin* Pin)
		{
			if (Pin->Direction == EGPD_Output)
			{
				return Ftor(Pin);
			}
			return true;
		});
	}

	FBlueprintGraphPin FindThenPin(const UK2Node* Node)
	{
		if (!::IsValid(Node))
		{
			return FBlueprintGraphPin{};
		}

		FBlueprintGraphPin Result;
		ForEachVisibleOutputPin(Node, [&Result](UEdGraphPin* Pin)
		{
			if (UEdGraphSchema_K2::IsExecPin(*Pin) && Pin->PinName == UEdGraphSchema_K2::PN_Then)
			{
				Result = UBlueprintGraphPinLibrary::FromNativePin(Pin);
				return false;
			}
			return true;
		});
		if (!::IsValid(Result.Node))
		{
			UE_LOG(LogTemp, Warning, TEXT("No then pin found on node %s"), *Node->GetPathName());
		}
		return Result;
	}

	FString PinTypeToJsonSchema(const FEdGraphPinType& PinType, const UClass* SelfContext)
	{
		if (PinType.PinCategory == UEdGraphSchema_K2::PC_Exec)
		{
			return TEXT("{\n    \"type\": \"exec\"\n}");
		}

		FCompilerResultsLog Discard;
		// We reuse FPropertyToJsonSchemaObject rather than maintain a direct pin-type -> schema mapping.
		UStruct* Scope = NewObject<UScriptStruct>();
		const FProperty* Property = FKismetCompilerUtilities::CreatePropertyOnScope(
			Scope,
			TEXT("TestProperty"),
			PinType,
			const_cast<UClass*>(SelfContext),
			CPF_BlueprintVisible | CPF_BlueprintReadOnly,
			GetDefault<UEdGraphSchema_K2>(),
			Discard);
		if (!Property)
		{
			return TEXT("");
		}

		TSharedPtr<FJsonObject> PinSchema = FJsonSchemaGenerator::FPropertyToJsonSchemaObject(Property);
		FString OutString;
		if (PinSchema)
		{
			TSharedRef<TJsonWriter<>> JsonWriter = TJsonWriterFactory<>::Create(&OutString);
			FJsonSerializer::Serialize(PinSchema, JsonWriter);
			JsonWriter->Close();
		}
		return OutString;
	}

	float EstimateNodeHeight(const UEdGraphNode* Node)
	{
		float HeightEstimate = 0.0f;

		if (Node != nullptr)
		{
			float BaseNodeHeight = 48.0f;
			bool bConsiderNodePins = false;
			float HeightPerPin = 18.0f;

			if (Node->IsA(UK2Node_CallFunction::StaticClass()))
			{
				BaseNodeHeight = 80.0f;
				bConsiderNodePins = true;
				HeightPerPin = 18.0f;
			}
			else if (Node->IsA(UK2Node_Event::StaticClass()))
			{
				BaseNodeHeight = 48.0f;
				bConsiderNodePins = true;
				HeightPerPin = 16.0f;
			}

			HeightEstimate = BaseNodeHeight;

			if (bConsiderNodePins)
			{
				int32 NumInputPins = 0;
				int32 NumOutputPins = 0;

				for (int32 PinIndex = 0; PinIndex < Node->Pins.Num(); PinIndex++)
				{
					UEdGraphPin* CurrentPin = Node->Pins[PinIndex];
					if (CurrentPin != nullptr && !CurrentPin->bHidden)
					{
						switch (CurrentPin->Direction)
						{
							case EGPD_Input:
							{
								NumInputPins++;
							}
							break;
							case EGPD_Output:
							{
								NumOutputPins++;
							}
							break;
						}
					}
				}

				float MaxNumPins = float(FMath::Max<int32>(NumInputPins, NumOutputPins));

				HeightEstimate += MaxNumPins * HeightPerPin;
			}
		}

		return HeightEstimate;
	}

	float EstimateNodeWidth(const UEdGraphNode* Node)
	{
		float WidthEstimate = 0.0f;

		if (Node != nullptr)
		{
			const float BaseNodeWidth = Node->IsA(UK2Node_CallFunction::StaticClass()) ? 250.0f : 200.0f;

			FString NodeTitle = Node->GetNodeTitle(ENodeTitleType::FullTitle).ToString();

			if (const UFont* Font = GetDefault<UEditorEngine>()->EditorFont)
			{
				WidthEstimate = FMath::Max(BaseNodeWidth, (float)Font->GetStringSize(*NodeTitle));
			}
			else
			{
				static const float EstimatedCharWidth = 6.0f;
				WidthEstimate = FMath::Max(BaseNodeWidth, NodeTitle.Len() * EstimatedCharWidth);
			}
		}

		return WidthEstimate;
	}
}

// [5.7 port] UK2Node_EditablePinBase::UserDefinedPinExists is declared in 5.7 but not BLUEPRINTGRAPH_API-
// exported (5.8 exported it), so external modules cannot link it. Provide a local definition (the engine's
// own internal copy is unaffected; the symbol is not exported so there is no duplicate at link time).
bool UK2Node_EditablePinBase::UserDefinedPinExists(const FName PinName) const
{
	return UserDefinedPins.ContainsByPredicate([&PinName](const TSharedPtr<FUserPinInfo>& UDPin)
	{
		return UDPin.IsValid() && (UDPin->PinName == PinName);
	});
}
