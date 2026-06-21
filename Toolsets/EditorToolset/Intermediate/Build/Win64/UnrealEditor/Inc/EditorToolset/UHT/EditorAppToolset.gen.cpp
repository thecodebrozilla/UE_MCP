// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EditorAppToolset.h"
#include "ToolsetRegistry/ToolsetImage.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeEditorAppToolset() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
EDITORTOOLSET_API UClass* Z_Construct_UClass_UEditorAppToolset();
EDITORTOOLSET_API UClass* Z_Construct_UClass_UEditorAppToolset_NoRegister();
EDITORTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FPIESessionOptions();
EDITORTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FViewportAnnotationConfig();
EDITORTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FViewportCapture();
EDITORTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FViewportGrid();
EDITORTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FViewportLabel();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolCallAsyncResultImage_NoRegister();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolCallAsyncResultVoid_NoRegister();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition();
TOOLSETREGISTRY_API UScriptStruct* Z_Construct_UScriptStruct_FToolsetImage();
UNREALED_API UEnum* Z_Construct_UEnum_UnrealEd_EPlayModeType();
UPackage* Z_Construct_UPackage__Script_EditorToolset();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FPIESessionOptions ************************************************
struct Z_Construct_UScriptStruct_FPIESessionOptions_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FPIESessionOptions); }
	static inline consteval int16 GetStructAlignment() { return alignof(FPIESessionOptions); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n * Options bag for StartPIE. All fields are optional; defaults run a standard\n * Play-In-Editor session inside the active level viewport, with a 2-second\n * warmup after PostPIEStarted to let project initialization settle.\n */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Options bag for StartPIE. All fields are optional; defaults run a standard\n* Play-In-Editor session inside the active level viewport, with a 2-second\n* warmup after PostPIEStarted to let project initialization settle." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSimulate_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * If true, starts Simulate-In-Editor: the world ticks and AI / physics /\n\x09 * subsystems run, but no player pawn is spawned or possessed. Useful for\n\x09 * observing initialization, autonomous agents, and physics state\n\x09 * independently of player input.\n\x09 * If false (default), starts standard PIE with the player pawn possessed.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* If true, starts Simulate-In-Editor: the world ticks and AI / physics /\n* subsystems run, but no player pawn is spawned or possessed. Useful for\n* observing initialization, autonomous agents, and physics state\n* independently of player input.\n* If false (default), starts standard PIE with the player pawn possessed." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayMode_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Editor play mode (in-viewport, floating window, etc.). Out-of-process\n\x09 * modes (NewProcess, MobilePreview, VR, QuickLaunch) are downgraded to\n\x09 * PlayMode_InViewPort with a log warning since this tool requires\n\x09 * in-process PIE for delegate-based completion tracking.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Editor play mode (in-viewport, floating window, etc.). Out-of-process\n* modes (NewProcess, MobilePreview, VR, QuickLaunch) are downgraded to\n* PlayMode_InViewPort with a log warning since this tool requires\n* in-process PIE for delegate-based completion tracking." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartTransform_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Optional spawn override. When set, the player pawn (PIE) or simulation\n\x09 * reference (Simulate) spawns at this transform instead of the level's\n\x09 * PlayerStart / GameMode default. To spawn at the editor viewport camera,\n\x09 * retrieve the current editor camera properties and use the result here.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Optional spawn override. When set, the player pawn (PIE) or simulation\n* reference (Simulate) spawns at this transform instead of the level's\n* PlayerStart / GameMode default. To spawn at the editor viewport camera,\n* retrieve the current editor camera properties and use the result here." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WarmupSeconds_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Seconds to wait after the engine fires PostPIEStarted (BeginPlay called)\n\x09 * before this call completes. Heuristic for project-specific initialization\n\x09 * (services, authentication, plugin warmup) to settle before the agent\n\x09 * inspects state or logs. Pass 0 to complete as soon as PIE is up.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Seconds to wait after the engine fires PostPIEStarted (BeginPlay called)\n* before this call completes. Heuristic for project-specific initialization\n* (services, authentication, plugin warmup) to settle before the agent\n* inspects state or logs. Pass 0 to complete as soon as PIE is up." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FPIESessionOptions constinit property declarations ****************
	static void NewProp_bSimulate_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSimulate;
	static const UECodeGen_Private::FBytePropertyParams NewProp_PlayMode;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StartTransform_Inner;
	static const UECodeGen_Private::FGenericPropertyParams NewProp_StartTransform;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WarmupSeconds;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FPIESessionOptions constinit property declarations ******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPIESessionOptions>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FPIESessionOptions_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FPIESessionOptions;
class UScriptStruct* FPIESessionOptions::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FPIESessionOptions.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FPIESessionOptions.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPIESessionOptions, (UObject*)Z_Construct_UPackage__Script_EditorToolset(), TEXT("PIESessionOptions"));
	}
	return Z_Registration_Info_UScriptStruct_FPIESessionOptions.OuterSingleton;
	}

// ********** Begin ScriptStruct FPIESessionOptions Property Definitions ***************************
void Z_Construct_UScriptStruct_FPIESessionOptions_Statics::NewProp_bSimulate_SetBit(void* Obj)
{
	((FPIESessionOptions*)Obj)->bSimulate = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPIESessionOptions_Statics::NewProp_bSimulate = { "bSimulate", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FPIESessionOptions), &Z_Construct_UScriptStruct_FPIESessionOptions_Statics::NewProp_bSimulate_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSimulate_MetaData), NewProp_bSimulate_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FPIESessionOptions_Statics::NewProp_PlayMode = { "PlayMode", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPIESessionOptions, PlayMode), Z_Construct_UEnum_UnrealEd_EPlayModeType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayMode_MetaData), NewProp_PlayMode_MetaData) }; // 776899543
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPIESessionOptions_Statics::NewProp_StartTransform_Inner = { "StartTransform", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FGenericPropertyParams Z_Construct_UScriptStruct_FPIESessionOptions_Statics::NewProp_StartTransform = { "StartTransform", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Optional, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPIESessionOptions, StartTransform), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartTransform_MetaData), NewProp_StartTransform_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPIESessionOptions_Statics::NewProp_WarmupSeconds = { "WarmupSeconds", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPIESessionOptions, WarmupSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WarmupSeconds_MetaData), NewProp_WarmupSeconds_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPIESessionOptions_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPIESessionOptions_Statics::NewProp_bSimulate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPIESessionOptions_Statics::NewProp_PlayMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPIESessionOptions_Statics::NewProp_StartTransform_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPIESessionOptions_Statics::NewProp_StartTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPIESessionOptions_Statics::NewProp_WarmupSeconds,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPIESessionOptions_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FPIESessionOptions Property Definitions *****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPIESessionOptions_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EditorToolset,
	nullptr,
	&NewStructOps,
	"PIESessionOptions",
	Z_Construct_UScriptStruct_FPIESessionOptions_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPIESessionOptions_Statics::PropPointers),
	sizeof(FPIESessionOptions),
	alignof(FPIESessionOptions),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPIESessionOptions_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPIESessionOptions_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FPIESessionOptions()
{
	if (!Z_Registration_Info_UScriptStruct_FPIESessionOptions.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FPIESessionOptions.InnerSingleton, Z_Construct_UScriptStruct_FPIESessionOptions_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FPIESessionOptions.InnerSingleton);
}
// ********** End ScriptStruct FPIESessionOptions **************************************************

// ********** Begin ScriptStruct FViewportLabel ****************************************************
struct Z_Construct_UScriptStruct_FViewportLabel_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FViewportLabel); }
	static inline consteval int16 GetStructAlignment() { return alignof(FViewportLabel); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * One labeled actor in a viewport capture's annotation overlay.\n *\n * Name is the canonical object name (unique within the level and stable across captures);\n * Label is the human-readable text drawn on the image (actor label + position).\n * Use Name when referring back to a specific actor, Label for display.\n */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "One labeled actor in a viewport capture's annotation overlay.\n\nName is the canonical object name (unique within the level and stable across captures);\nLabel is the human-readable text drawn on the image (actor label + position).\nUse Name when referring back to a specific actor, Label for display." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "EditorAppToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Canonical, level-unique name of the actor (AActor::GetName). Use this to reference the actor later. */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Canonical, level-unique name of the actor (AActor::GetName). Use this to reference the actor later." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Label_MetaData[] = {
		{ "Category", "EditorAppToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Display label that was drawn on the image (actor label + position in meters). Not guaranteed unique. */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Display label that was drawn on the image (actor label + position in meters). Not guaranteed unique." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Class_MetaData[] = {
		{ "Category", "EditorAppToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Class of the actor. */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Class of the actor." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScreenPosition_MetaData[] = {
		{ "Category", "EditorAppToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Screen-space pixel position of the actor origin in the returned image. */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Screen-space pixel position of the actor origin in the returned image." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldLocation_MetaData[] = {
		{ "Category", "EditorAppToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** World-space location of the actor origin (cm). */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "World-space location of the actor origin (cm)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistanceCm_MetaData[] = {
		{ "Category", "EditorAppToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Distance from the camera to the actor origin (cm). */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Distance from the camera to the actor origin (cm)." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FViewportLabel constinit property declarations ********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Label;
	static const UECodeGen_Private::FClassPropertyParams NewProp_Class;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ScreenPosition;
	static const UECodeGen_Private::FStructPropertyParams NewProp_WorldLocation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DistanceCm;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FViewportLabel constinit property declarations **********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FViewportLabel>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FViewportLabel_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FViewportLabel;
class UScriptStruct* FViewportLabel::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FViewportLabel.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FViewportLabel.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FViewportLabel, (UObject*)Z_Construct_UPackage__Script_EditorToolset(), TEXT("ViewportLabel"));
	}
	return Z_Registration_Info_UScriptStruct_FViewportLabel.OuterSingleton;
	}

// ********** Begin ScriptStruct FViewportLabel Property Definitions *******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FViewportLabel_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FViewportLabel, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FViewportLabel_Statics::NewProp_Label = { "Label", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FViewportLabel, Label), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Label_MetaData), NewProp_Label_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FViewportLabel_Statics::NewProp_Class = { "Class", nullptr, (EPropertyFlags)0x0014000000000014, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FViewportLabel, Class), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Class_MetaData), NewProp_Class_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FViewportLabel_Statics::NewProp_ScreenPosition = { "ScreenPosition", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FViewportLabel, ScreenPosition), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScreenPosition_MetaData), NewProp_ScreenPosition_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FViewportLabel_Statics::NewProp_WorldLocation = { "WorldLocation", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FViewportLabel, WorldLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldLocation_MetaData), NewProp_WorldLocation_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FViewportLabel_Statics::NewProp_DistanceCm = { "DistanceCm", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FViewportLabel, DistanceCm), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistanceCm_MetaData), NewProp_DistanceCm_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FViewportLabel_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FViewportLabel_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FViewportLabel_Statics::NewProp_Label,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FViewportLabel_Statics::NewProp_Class,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FViewportLabel_Statics::NewProp_ScreenPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FViewportLabel_Statics::NewProp_WorldLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FViewportLabel_Statics::NewProp_DistanceCm,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FViewportLabel_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FViewportLabel Property Definitions *********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FViewportLabel_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EditorToolset,
	nullptr,
	&NewStructOps,
	"ViewportLabel",
	Z_Construct_UScriptStruct_FViewportLabel_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FViewportLabel_Statics::PropPointers),
	sizeof(FViewportLabel),
	alignof(FViewportLabel),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FViewportLabel_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FViewportLabel_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FViewportLabel()
{
	if (!Z_Registration_Info_UScriptStruct_FViewportLabel.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FViewportLabel.InnerSingleton, Z_Construct_UScriptStruct_FViewportLabel_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FViewportLabel.InnerSingleton);
}
// ********** End ScriptStruct FViewportLabel ******************************************************

// ********** Begin ScriptStruct FViewportGrid *****************************************************
struct Z_Construct_UScriptStruct_FViewportGrid_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FViewportGrid); }
	static inline consteval int16 GetStructAlignment() { return alignof(FViewportGrid); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Grid parameters echoed back from an annotated viewport capture for round-tripping / reporting. */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Grid parameters echoed back from an annotated viewport capture for round-tripping / reporting." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpacingCm_MetaData[] = {
		{ "Category", "EditorAppToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** World-space distance between grid lines (cm). Zero if the grid was disabled. */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "World-space distance between grid lines (cm). Zero if the grid was disabled." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExtentCm_MetaData[] = {
		{ "Category", "EditorAppToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** How far the grid extends from the origin in each axis (cm). */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "How far the grid extends from the origin in each axis (cm)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Height_MetaData[] = {
		{ "Category", "EditorAppToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Height of the ground-plane grid in world space. */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Height of the ground-plane grid in world space." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FViewportGrid constinit property declarations *********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SpacingCm;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ExtentCm;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Height;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FViewportGrid constinit property declarations ***********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FViewportGrid>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FViewportGrid_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FViewportGrid;
class UScriptStruct* FViewportGrid::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FViewportGrid.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FViewportGrid.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FViewportGrid, (UObject*)Z_Construct_UPackage__Script_EditorToolset(), TEXT("ViewportGrid"));
	}
	return Z_Registration_Info_UScriptStruct_FViewportGrid.OuterSingleton;
	}

// ********** Begin ScriptStruct FViewportGrid Property Definitions ********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FViewportGrid_Statics::NewProp_SpacingCm = { "SpacingCm", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FViewportGrid, SpacingCm), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpacingCm_MetaData), NewProp_SpacingCm_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FViewportGrid_Statics::NewProp_ExtentCm = { "ExtentCm", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FViewportGrid, ExtentCm), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExtentCm_MetaData), NewProp_ExtentCm_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FViewportGrid_Statics::NewProp_Height = { "Height", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FViewportGrid, Height), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Height_MetaData), NewProp_Height_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FViewportGrid_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FViewportGrid_Statics::NewProp_SpacingCm,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FViewportGrid_Statics::NewProp_ExtentCm,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FViewportGrid_Statics::NewProp_Height,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FViewportGrid_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FViewportGrid Property Definitions **********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FViewportGrid_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EditorToolset,
	nullptr,
	&NewStructOps,
	"ViewportGrid",
	Z_Construct_UScriptStruct_FViewportGrid_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FViewportGrid_Statics::PropPointers),
	sizeof(FViewportGrid),
	alignof(FViewportGrid),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FViewportGrid_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FViewportGrid_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FViewportGrid()
{
	if (!Z_Registration_Info_UScriptStruct_FViewportGrid.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FViewportGrid.InnerSingleton, Z_Construct_UScriptStruct_FViewportGrid_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FViewportGrid.InnerSingleton);
}
// ********** End ScriptStruct FViewportGrid *******************************************************

// ********** Begin ScriptStruct FViewportAnnotationConfig *****************************************
struct Z_Construct_UScriptStruct_FViewportAnnotationConfig_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FViewportAnnotationConfig); }
	static inline consteval int16 GetStructAlignment() { return alignof(FViewportAnnotationConfig); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Annotation overlay configuration for CaptureViewport.\n */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Annotation overlay configuration for CaptureViewport." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridSpacing_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** World-space distance between grid lines (cm). Pass 0 to disable the grid overlay while still drawing actor labels. */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "World-space distance between grid lines (cm). Pass 0 to disable the grid overlay while still drawing actor labels." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridExtent_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** How far the grid extends from the origin in each axis (cm). */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "How far the grid extends from the origin in each axis (cm)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridHeight_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Height of the ground-plane grid in world space. */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Height of the ground-plane grid in world space." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxLabelDistance_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum distance (cm) for labeling actors and grid coordinates. Pass 0 to disable actor labels while still drawing the grid. */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum distance (cm) for labeling actors and grid coordinates. Pass 0 to disable actor labels while still drawing the grid." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClassFilter_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If non-null, only actors of this class (or a subclass) are labeled. */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If non-null, only actors of this class (or a subclass) are labeled." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxLabels_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum number of actor labels to draw. Nearest-to-camera wins. Don't draw too many or the image becomes incoherent. */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum number of actor labels to draw. Nearest-to-camera wins. Don't draw too many or the image becomes incoherent." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FViewportAnnotationConfig constinit property declarations *********
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GridSpacing;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GridExtent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GridHeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxLabelDistance;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ClassFilter;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxLabels;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FViewportAnnotationConfig constinit property declarations ***********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FViewportAnnotationConfig>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FViewportAnnotationConfig_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FViewportAnnotationConfig;
class UScriptStruct* FViewportAnnotationConfig::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FViewportAnnotationConfig.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FViewportAnnotationConfig.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FViewportAnnotationConfig, (UObject*)Z_Construct_UPackage__Script_EditorToolset(), TEXT("ViewportAnnotationConfig"));
	}
	return Z_Registration_Info_UScriptStruct_FViewportAnnotationConfig.OuterSingleton;
	}

// ********** Begin ScriptStruct FViewportAnnotationConfig Property Definitions ********************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FViewportAnnotationConfig_Statics::NewProp_GridSpacing = { "GridSpacing", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FViewportAnnotationConfig, GridSpacing), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridSpacing_MetaData), NewProp_GridSpacing_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FViewportAnnotationConfig_Statics::NewProp_GridExtent = { "GridExtent", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FViewportAnnotationConfig, GridExtent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridExtent_MetaData), NewProp_GridExtent_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FViewportAnnotationConfig_Statics::NewProp_GridHeight = { "GridHeight", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FViewportAnnotationConfig, GridHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridHeight_MetaData), NewProp_GridHeight_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FViewportAnnotationConfig_Statics::NewProp_MaxLabelDistance = { "MaxLabelDistance", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FViewportAnnotationConfig, MaxLabelDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxLabelDistance_MetaData), NewProp_MaxLabelDistance_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FViewportAnnotationConfig_Statics::NewProp_ClassFilter = { "ClassFilter", nullptr, (EPropertyFlags)0x0014000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FViewportAnnotationConfig, ClassFilter), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClassFilter_MetaData), NewProp_ClassFilter_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FViewportAnnotationConfig_Statics::NewProp_MaxLabels = { "MaxLabels", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FViewportAnnotationConfig, MaxLabels), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxLabels_MetaData), NewProp_MaxLabels_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FViewportAnnotationConfig_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FViewportAnnotationConfig_Statics::NewProp_GridSpacing,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FViewportAnnotationConfig_Statics::NewProp_GridExtent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FViewportAnnotationConfig_Statics::NewProp_GridHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FViewportAnnotationConfig_Statics::NewProp_MaxLabelDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FViewportAnnotationConfig_Statics::NewProp_ClassFilter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FViewportAnnotationConfig_Statics::NewProp_MaxLabels,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FViewportAnnotationConfig_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FViewportAnnotationConfig Property Definitions **********************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FViewportAnnotationConfig_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EditorToolset,
	nullptr,
	&NewStructOps,
	"ViewportAnnotationConfig",
	Z_Construct_UScriptStruct_FViewportAnnotationConfig_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FViewportAnnotationConfig_Statics::PropPointers),
	sizeof(FViewportAnnotationConfig),
	alignof(FViewportAnnotationConfig),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FViewportAnnotationConfig_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FViewportAnnotationConfig_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FViewportAnnotationConfig()
{
	if (!Z_Registration_Info_UScriptStruct_FViewportAnnotationConfig.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FViewportAnnotationConfig.InnerSingleton, Z_Construct_UScriptStruct_FViewportAnnotationConfig_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FViewportAnnotationConfig.InnerSingleton);
}
// ********** End ScriptStruct FViewportAnnotationConfig *******************************************

// ********** Begin ScriptStruct FViewportCapture **************************************************
struct Z_Construct_UScriptStruct_FViewportCapture_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FViewportCapture); }
	static inline consteval int16 GetStructAlignment() { return alignof(FViewportCapture); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Describes the results of a viewport capture. Includes a screenshot of the level viewport plus structured metadata describing the\n * camera. When annotations are enabled, the associated metadata will be populated and the image will include a projected world-space\n * grid and per-actor labels.\n */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Describes the results of a viewport capture. Includes a screenshot of the level viewport plus structured metadata describing the\ncamera. When annotations are enabled, the associated metadata will be populated and the image will include a projected world-space\ngrid and per-actor labels." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Image_MetaData[] = {
		{ "Category", "EditorAppToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The captured screenshot (PNG encoded as base64). Empty on failure. Pixel dimensions are available via FToolsetImage. */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The captured screenshot (PNG encoded as base64). Empty on failure. Pixel dimensions are available via FToolsetImage." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraLocation_MetaData[] = {
		{ "Category", "EditorAppToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Level viewport camera location (world space, cm). */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Level viewport camera location (world space, cm)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraRotation_MetaData[] = {
		{ "Category", "EditorAppToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Level viewport camera rotation (world space). */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Level viewport camera rotation (world space)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraFOV_MetaData[] = {
		{ "Category", "EditorAppToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Level viewport camera field of view, in degrees. */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Level viewport camera field of view, in degrees." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Grid_MetaData[] = {
		{ "Category", "EditorAppToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Grid parameters used for the annotation. SpacingCm is zero when the grid was disabled. */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Grid parameters used for the annotation. SpacingCm is zero when the grid was disabled." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LabeledActors_MetaData[] = {
		{ "Category", "EditorAppToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** One entry per labeled actor in the image. */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "One entry per labeled actor in the image." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FViewportCapture constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Image;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CameraLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CameraRotation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CameraFOV;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Grid;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LabeledActors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_LabeledActors;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FViewportCapture constinit property declarations ********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FViewportCapture>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FViewportCapture_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FViewportCapture;
class UScriptStruct* FViewportCapture::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FViewportCapture.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FViewportCapture.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FViewportCapture, (UObject*)Z_Construct_UPackage__Script_EditorToolset(), TEXT("ViewportCapture"));
	}
	return Z_Registration_Info_UScriptStruct_FViewportCapture.OuterSingleton;
	}

// ********** Begin ScriptStruct FViewportCapture Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FViewportCapture_Statics::NewProp_Image = { "Image", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FViewportCapture, Image), Z_Construct_UScriptStruct_FToolsetImage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Image_MetaData), NewProp_Image_MetaData) }; // 1290813077
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FViewportCapture_Statics::NewProp_CameraLocation = { "CameraLocation", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FViewportCapture, CameraLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraLocation_MetaData), NewProp_CameraLocation_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FViewportCapture_Statics::NewProp_CameraRotation = { "CameraRotation", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FViewportCapture, CameraRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraRotation_MetaData), NewProp_CameraRotation_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FViewportCapture_Statics::NewProp_CameraFOV = { "CameraFOV", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FViewportCapture, CameraFOV), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraFOV_MetaData), NewProp_CameraFOV_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FViewportCapture_Statics::NewProp_Grid = { "Grid", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FViewportCapture, Grid), Z_Construct_UScriptStruct_FViewportGrid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Grid_MetaData), NewProp_Grid_MetaData) }; // 1910091040
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FViewportCapture_Statics::NewProp_LabeledActors_Inner = { "LabeledActors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FViewportLabel, METADATA_PARAMS(0, nullptr) }; // 1685283340
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FViewportCapture_Statics::NewProp_LabeledActors = { "LabeledActors", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FViewportCapture, LabeledActors), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LabeledActors_MetaData), NewProp_LabeledActors_MetaData) }; // 1685283340
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FViewportCapture_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FViewportCapture_Statics::NewProp_Image,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FViewportCapture_Statics::NewProp_CameraLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FViewportCapture_Statics::NewProp_CameraRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FViewportCapture_Statics::NewProp_CameraFOV,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FViewportCapture_Statics::NewProp_Grid,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FViewportCapture_Statics::NewProp_LabeledActors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FViewportCapture_Statics::NewProp_LabeledActors,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FViewportCapture_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FViewportCapture Property Definitions *******************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FViewportCapture_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EditorToolset,
	nullptr,
	&NewStructOps,
	"ViewportCapture",
	Z_Construct_UScriptStruct_FViewportCapture_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FViewportCapture_Statics::PropPointers),
	sizeof(FViewportCapture),
	alignof(FViewportCapture),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FViewportCapture_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FViewportCapture_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FViewportCapture()
{
	if (!Z_Registration_Info_UScriptStruct_FViewportCapture.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FViewportCapture.InnerSingleton, Z_Construct_UScriptStruct_FViewportCapture_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FViewportCapture.InnerSingleton);
}
// ********** End ScriptStruct FViewportCapture ****************************************************

// ********** Begin Class UEditorAppToolset Function CaptureAssetImage *****************************
struct Z_Construct_UFunction_UEditorAppToolset_CaptureAssetImage_Statics
{
	struct EditorAppToolset_eventCaptureAssetImage_Parms
	{
		FString AssetPath;
		UToolCallAsyncResultImage* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Renders a thumbnail for the specified asset (e.g. static meshes, skeletal meshes,\n\x09 * skeletons, animations, montages, materials, textures).\n\x09 * @param AssetPath The path to the asset, e.g. '/Game/Meshes/SM_Cube'.\n\x09 * @return An image of the asset.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Renders a thumbnail for the specified asset (e.g. static meshes, skeletal meshes,\n* skeletons, animations, montages, materials, textures).\n* @param AssetPath The path to the asset, e.g. '/Game/Meshes/SM_Cube'.\n* @return An image of the asset." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AssetPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CaptureAssetImage constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AssetPath;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CaptureAssetImage constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CaptureAssetImage Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEditorAppToolset_CaptureAssetImage_Statics::NewProp_AssetPath = { "AssetPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EditorAppToolset_eventCaptureAssetImage_Parms, AssetPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AssetPath_MetaData), NewProp_AssetPath_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEditorAppToolset_CaptureAssetImage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EditorAppToolset_eventCaptureAssetImage_Parms, ReturnValue), Z_Construct_UClass_UToolCallAsyncResultImage_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEditorAppToolset_CaptureAssetImage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_CaptureAssetImage_Statics::NewProp_AssetPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_CaptureAssetImage_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_CaptureAssetImage_Statics::PropPointers) < 2048);
// ********** End Function CaptureAssetImage Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEditorAppToolset_CaptureAssetImage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEditorAppToolset, nullptr, "CaptureAssetImage", 	Z_Construct_UFunction_UEditorAppToolset_CaptureAssetImage_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_CaptureAssetImage_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UEditorAppToolset_CaptureAssetImage_Statics::EditorAppToolset_eventCaptureAssetImage_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_CaptureAssetImage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEditorAppToolset_CaptureAssetImage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEditorAppToolset_CaptureAssetImage_Statics::EditorAppToolset_eventCaptureAssetImage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEditorAppToolset_CaptureAssetImage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEditorAppToolset_CaptureAssetImage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEditorAppToolset::execCaptureAssetImage)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AssetPath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UToolCallAsyncResultImage**)Z_Param__Result=UEditorAppToolset::CaptureAssetImage(Z_Param_AssetPath);
	P_NATIVE_END;
}
// ********** End Class UEditorAppToolset Function CaptureAssetImage *******************************

// ********** Begin Class UEditorAppToolset Function CaptureEditorImage ****************************
struct Z_Construct_UFunction_UEditorAppToolset_CaptureEditorImage_Statics
{
	struct EditorAppToolset_eventCaptureEditorImage_Parms
	{
		FToolsetImage ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Captures an image of the entire editor application as the user sees it.\n\x09 * @return An image of editor windows as they appear on the users' desktop.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Captures an image of the entire editor application as the user sees it.\n* @return An image of editor windows as they appear on the users' desktop." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function CaptureEditorImage constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CaptureEditorImage constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CaptureEditorImage Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEditorAppToolset_CaptureEditorImage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EditorAppToolset_eventCaptureEditorImage_Parms, ReturnValue), Z_Construct_UScriptStruct_FToolsetImage, METADATA_PARAMS(0, nullptr) }; // 1290813077
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEditorAppToolset_CaptureEditorImage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_CaptureEditorImage_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_CaptureEditorImage_Statics::PropPointers) < 2048);
// ********** End Function CaptureEditorImage Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEditorAppToolset_CaptureEditorImage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEditorAppToolset, nullptr, "CaptureEditorImage", 	Z_Construct_UFunction_UEditorAppToolset_CaptureEditorImage_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_CaptureEditorImage_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UEditorAppToolset_CaptureEditorImage_Statics::EditorAppToolset_eventCaptureEditorImage_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_CaptureEditorImage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEditorAppToolset_CaptureEditorImage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEditorAppToolset_CaptureEditorImage_Statics::EditorAppToolset_eventCaptureEditorImage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEditorAppToolset_CaptureEditorImage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEditorAppToolset_CaptureEditorImage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEditorAppToolset::execCaptureEditorImage)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FToolsetImage*)Z_Param__Result=UEditorAppToolset::CaptureEditorImage();
	P_NATIVE_END;
}
// ********** End Class UEditorAppToolset Function CaptureEditorImage ******************************

// ********** Begin Class UEditorAppToolset Function CaptureViewport *******************************
struct Z_Construct_UFunction_UEditorAppToolset_CaptureViewport_Statics
{
	struct EditorAppToolset_eventCaptureViewport_Parms
	{
		TOptional<FTransform> CaptureTransform;
		TOptional<FViewportAnnotationConfig> Annotations;
		bool bShowUI;
		FViewportCapture ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "EditorAppToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Captures the level viewport with optional annotations.\n\x09 * \n\x09 * Annotations rendering overlays a projected 3D world-space grid plus\n\x09 * name + position labels on visible actors. The grid is drawn at a configurable\n\x09 * ground-plane Z and projected through the camera, with coordinate numbers at\n\x09 * intersections (shown in meters). Each labeled actor gets a crosshair at its\n\x09 * projected screen position with a leader-line callout placed to avoid overlap. This\n\x09 * gives a vision-capable agent spatial awareness: it can reference grid\n\x09 * coordinates to direct placement and identify scene contents by label.\n\x09 *\n\x09 * @param CaptureTransform Optional pose to capture from. If unset, uses the viewport's\n\x09 *   current camera.\n\x09 * @param Annotations Optional annotation overlay configuration. Only use this when\n\x09 *   you need the information in order to perform spatial actions.\n\x09 * @param bShowUI If false (default), editor UI overlays such as transform gizmos and\n\x09 *   selection outlines are hidden in the captured image. Set true to capture exactly\n\x09 *   what's on screen, gizmos and all.\n\x09 * @return The captured image and associated metadata.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Captures the level viewport with optional annotations.\n*\n* Annotations rendering overlays a projected 3D world-space grid plus\n* name + position labels on visible actors. The grid is drawn at a configurable\n* ground-plane Z and projected through the camera, with coordinate numbers at\n* intersections (shown in meters). Each labeled actor gets a crosshair at its\n* projected screen position with a leader-line callout placed to avoid overlap. This\n* gives a vision-capable agent spatial awareness: it can reference grid\n* coordinates to direct placement and identify scene contents by label.\n*\n* @param CaptureTransform Optional pose to capture from. If unset, uses the viewport's\n*   current camera.\n* @param Annotations Optional annotation overlay configuration. Only use this when\n*   you need the information in order to perform spatial actions.\n* @param bShowUI If false (default), editor UI overlays such as transform gizmos and\n*   selection outlines are hidden in the captured image. Set true to capture exactly\n*   what's on screen, gizmos and all.\n* @return The captured image and associated metadata." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function CaptureViewport constinit property declarations ***********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_CaptureTransform_Inner;
	static const UECodeGen_Private::FGenericPropertyParams NewProp_CaptureTransform;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Annotations_Inner;
	static const UECodeGen_Private::FGenericPropertyParams NewProp_Annotations;
	static void NewProp_bShowUI_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowUI;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CaptureViewport constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CaptureViewport Property Definitions **********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEditorAppToolset_CaptureViewport_Statics::NewProp_CaptureTransform_Inner = { "CaptureTransform", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FGenericPropertyParams Z_Construct_UFunction_UEditorAppToolset_CaptureViewport_Statics::NewProp_CaptureTransform = { "CaptureTransform", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Optional, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EditorAppToolset_eventCaptureViewport_Parms, CaptureTransform), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEditorAppToolset_CaptureViewport_Statics::NewProp_Annotations_Inner = { "Annotations", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FViewportAnnotationConfig, METADATA_PARAMS(0, nullptr) }; // 1695222172
const UECodeGen_Private::FGenericPropertyParams Z_Construct_UFunction_UEditorAppToolset_CaptureViewport_Statics::NewProp_Annotations = { "Annotations", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Optional, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EditorAppToolset_eventCaptureViewport_Parms, Annotations), METADATA_PARAMS(0, nullptr) }; // 1695222172
void Z_Construct_UFunction_UEditorAppToolset_CaptureViewport_Statics::NewProp_bShowUI_SetBit(void* Obj)
{
	((EditorAppToolset_eventCaptureViewport_Parms*)Obj)->bShowUI = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEditorAppToolset_CaptureViewport_Statics::NewProp_bShowUI = { "bShowUI", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EditorAppToolset_eventCaptureViewport_Parms), &Z_Construct_UFunction_UEditorAppToolset_CaptureViewport_Statics::NewProp_bShowUI_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEditorAppToolset_CaptureViewport_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EditorAppToolset_eventCaptureViewport_Parms, ReturnValue), Z_Construct_UScriptStruct_FViewportCapture, METADATA_PARAMS(0, nullptr) }; // 4285175330
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEditorAppToolset_CaptureViewport_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_CaptureViewport_Statics::NewProp_CaptureTransform_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_CaptureViewport_Statics::NewProp_CaptureTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_CaptureViewport_Statics::NewProp_Annotations_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_CaptureViewport_Statics::NewProp_Annotations,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_CaptureViewport_Statics::NewProp_bShowUI,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_CaptureViewport_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_CaptureViewport_Statics::PropPointers) < 2048);
// ********** End Function CaptureViewport Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEditorAppToolset_CaptureViewport_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEditorAppToolset, nullptr, "CaptureViewport", 	Z_Construct_UFunction_UEditorAppToolset_CaptureViewport_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_CaptureViewport_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UEditorAppToolset_CaptureViewport_Statics::EditorAppToolset_eventCaptureViewport_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_CaptureViewport_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEditorAppToolset_CaptureViewport_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEditorAppToolset_CaptureViewport_Statics::EditorAppToolset_eventCaptureViewport_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEditorAppToolset_CaptureViewport()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEditorAppToolset_CaptureViewport_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEditorAppToolset::execCaptureViewport)
{
	P_GET_TOPTIONAL(FTransform,Z_Param_CaptureTransform);
	P_GET_TOPTIONAL(FViewportAnnotationConfig,Z_Param_Annotations);
	P_GET_UBOOL(Z_Param_bShowUI);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FViewportCapture*)Z_Param__Result=UEditorAppToolset::CaptureViewport(Z_Param_CaptureTransform,Z_Param_Annotations,Z_Param_bShowUI);
	P_NATIVE_END;
}
// ********** End Class UEditorAppToolset Function CaptureViewport *********************************

// ********** Begin Class UEditorAppToolset Function FocusOnActors *********************************
struct Z_Construct_UFunction_UEditorAppToolset_FocusOnActors_Statics
{
	struct EditorAppToolset_eventFocusOnActors_Parms
	{
		TArray<AActor*> Actors;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Repositions the level editor camera to focus on the specified actors.\n\x09 * Cannot be called while PIE is active.\n\x09 * @param Actors The actors to focus the level camera on.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Repositions the level editor camera to focus on the specified actors.\n* Cannot be called while PIE is active.\n* @param Actors The actors to focus the level camera on." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Actors_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function FocusOnActors constinit property declarations *************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Actors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Actors;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FocusOnActors constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FocusOnActors Property Definitions ************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEditorAppToolset_FocusOnActors_Statics::NewProp_Actors_Inner = { "Actors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UEditorAppToolset_FocusOnActors_Statics::NewProp_Actors = { "Actors", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EditorAppToolset_eventFocusOnActors_Parms, Actors), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Actors_MetaData), NewProp_Actors_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEditorAppToolset_FocusOnActors_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_FocusOnActors_Statics::NewProp_Actors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_FocusOnActors_Statics::NewProp_Actors,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_FocusOnActors_Statics::PropPointers) < 2048);
// ********** End Function FocusOnActors Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEditorAppToolset_FocusOnActors_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEditorAppToolset, nullptr, "FocusOnActors", 	Z_Construct_UFunction_UEditorAppToolset_FocusOnActors_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_FocusOnActors_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UEditorAppToolset_FocusOnActors_Statics::EditorAppToolset_eventFocusOnActors_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_FocusOnActors_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEditorAppToolset_FocusOnActors_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEditorAppToolset_FocusOnActors_Statics::EditorAppToolset_eventFocusOnActors_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEditorAppToolset_FocusOnActors()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEditorAppToolset_FocusOnActors_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEditorAppToolset::execFocusOnActors)
{
	P_GET_TARRAY_REF(AActor*,Z_Param_Out_Actors);
	P_FINISH;
	P_NATIVE_BEGIN;
	UEditorAppToolset::FocusOnActors(Z_Param_Out_Actors);
	P_NATIVE_END;
}
// ********** End Class UEditorAppToolset Function FocusOnActors ***********************************

// ********** Begin Class UEditorAppToolset Function GetCameraTransform ****************************
struct Z_Construct_UFunction_UEditorAppToolset_GetCameraTransform_Statics
{
	struct EditorAppToolset_eventGetCameraTransform_Parms
	{
		FTransform ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Returns the position and rotation of the level viewport camera.\n\x09 * @return The transform for the level viewport camera.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Returns the position and rotation of the level viewport camera.\n* @return The transform for the level viewport camera." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetCameraTransform constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCameraTransform constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCameraTransform Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEditorAppToolset_GetCameraTransform_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EditorAppToolset_eventGetCameraTransform_Parms, ReturnValue), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEditorAppToolset_GetCameraTransform_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_GetCameraTransform_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_GetCameraTransform_Statics::PropPointers) < 2048);
// ********** End Function GetCameraTransform Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEditorAppToolset_GetCameraTransform_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEditorAppToolset, nullptr, "GetCameraTransform", 	Z_Construct_UFunction_UEditorAppToolset_GetCameraTransform_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_GetCameraTransform_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UEditorAppToolset_GetCameraTransform_Statics::EditorAppToolset_eventGetCameraTransform_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_GetCameraTransform_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEditorAppToolset_GetCameraTransform_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEditorAppToolset_GetCameraTransform_Statics::EditorAppToolset_eventGetCameraTransform_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEditorAppToolset_GetCameraTransform()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEditorAppToolset_GetCameraTransform_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEditorAppToolset::execGetCameraTransform)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FTransform*)Z_Param__Result=UEditorAppToolset::GetCameraTransform();
	P_NATIVE_END;
}
// ********** End Class UEditorAppToolset Function GetCameraTransform ******************************

// ********** Begin Class UEditorAppToolset Function GetContentBrowserPath *************************
struct Z_Construct_UFunction_UEditorAppToolset_GetContentBrowserPath_Statics
{
	struct EditorAppToolset_eventGetContentBrowserPath_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Gets the current path of the active content browser.\n\x09 * @return The path to the folder currently shown in the content browser.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Gets the current path of the active content browser.\n* @return The path to the folder currently shown in the content browser." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetContentBrowserPath constinit property declarations *****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetContentBrowserPath constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetContentBrowserPath Property Definitions ****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEditorAppToolset_GetContentBrowserPath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EditorAppToolset_eventGetContentBrowserPath_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEditorAppToolset_GetContentBrowserPath_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_GetContentBrowserPath_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_GetContentBrowserPath_Statics::PropPointers) < 2048);
// ********** End Function GetContentBrowserPath Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEditorAppToolset_GetContentBrowserPath_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEditorAppToolset, nullptr, "GetContentBrowserPath", 	Z_Construct_UFunction_UEditorAppToolset_GetContentBrowserPath_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_GetContentBrowserPath_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UEditorAppToolset_GetContentBrowserPath_Statics::EditorAppToolset_eventGetContentBrowserPath_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_GetContentBrowserPath_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEditorAppToolset_GetContentBrowserPath_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEditorAppToolset_GetContentBrowserPath_Statics::EditorAppToolset_eventGetContentBrowserPath_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEditorAppToolset_GetContentBrowserPath()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEditorAppToolset_GetContentBrowserPath_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEditorAppToolset::execGetContentBrowserPath)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UEditorAppToolset::GetContentBrowserPath();
	P_NATIVE_END;
}
// ********** End Class UEditorAppToolset Function GetContentBrowserPath ***************************

// ********** Begin Class UEditorAppToolset Function GetOpenAssets *********************************
struct Z_Construct_UFunction_UEditorAppToolset_GetOpenAssets_Statics
{
	struct EditorAppToolset_eventGetOpenAssets_Parms
	{
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Gets the list of assets currently open in asset editors.\n\x09 * @return A list of package paths to the assets open in asset editors.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Gets the list of assets currently open in asset editors.\n* @return A list of package paths to the assets open in asset editors." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetOpenAssets constinit property declarations *************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetOpenAssets constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetOpenAssets Property Definitions ************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEditorAppToolset_GetOpenAssets_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UEditorAppToolset_GetOpenAssets_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EditorAppToolset_eventGetOpenAssets_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEditorAppToolset_GetOpenAssets_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_GetOpenAssets_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_GetOpenAssets_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_GetOpenAssets_Statics::PropPointers) < 2048);
// ********** End Function GetOpenAssets Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEditorAppToolset_GetOpenAssets_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEditorAppToolset, nullptr, "GetOpenAssets", 	Z_Construct_UFunction_UEditorAppToolset_GetOpenAssets_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_GetOpenAssets_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UEditorAppToolset_GetOpenAssets_Statics::EditorAppToolset_eventGetOpenAssets_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_GetOpenAssets_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEditorAppToolset_GetOpenAssets_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEditorAppToolset_GetOpenAssets_Statics::EditorAppToolset_eventGetOpenAssets_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEditorAppToolset_GetOpenAssets()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEditorAppToolset_GetOpenAssets_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEditorAppToolset::execGetOpenAssets)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=UEditorAppToolset::GetOpenAssets();
	P_NATIVE_END;
}
// ********** End Class UEditorAppToolset Function GetOpenAssets ***********************************

// ********** Begin Class UEditorAppToolset Function GetSelectedActors *****************************
struct Z_Construct_UFunction_UEditorAppToolset_GetSelectedActors_Statics
{
	struct EditorAppToolset_eventGetSelectedActors_Parms
	{
		TArray<AActor*> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Gets the currently selected actors in the level editor.\n\x09 * @return A list of the currently selected actors.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Gets the currently selected actors in the level editor.\n* @return A list of the currently selected actors." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetSelectedActors constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSelectedActors constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSelectedActors Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEditorAppToolset_GetSelectedActors_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UEditorAppToolset_GetSelectedActors_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EditorAppToolset_eventGetSelectedActors_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEditorAppToolset_GetSelectedActors_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_GetSelectedActors_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_GetSelectedActors_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_GetSelectedActors_Statics::PropPointers) < 2048);
// ********** End Function GetSelectedActors Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEditorAppToolset_GetSelectedActors_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEditorAppToolset, nullptr, "GetSelectedActors", 	Z_Construct_UFunction_UEditorAppToolset_GetSelectedActors_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_GetSelectedActors_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UEditorAppToolset_GetSelectedActors_Statics::EditorAppToolset_eventGetSelectedActors_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_GetSelectedActors_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEditorAppToolset_GetSelectedActors_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEditorAppToolset_GetSelectedActors_Statics::EditorAppToolset_eventGetSelectedActors_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEditorAppToolset_GetSelectedActors()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEditorAppToolset_GetSelectedActors_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEditorAppToolset::execGetSelectedActors)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<AActor*>*)Z_Param__Result=UEditorAppToolset::GetSelectedActors();
	P_NATIVE_END;
}
// ********** End Class UEditorAppToolset Function GetSelectedActors *******************************

// ********** Begin Class UEditorAppToolset Function GetSelectedAssets *****************************
struct Z_Construct_UFunction_UEditorAppToolset_GetSelectedAssets_Statics
{
	struct EditorAppToolset_eventGetSelectedAssets_Parms
	{
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Gets the list of assets selected in the content browser.\n\x09 * @return A list of package paths to the assets selected in the content browser.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Gets the list of assets selected in the content browser.\n* @return A list of package paths to the assets selected in the content browser." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetSelectedAssets constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSelectedAssets constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSelectedAssets Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEditorAppToolset_GetSelectedAssets_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UEditorAppToolset_GetSelectedAssets_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EditorAppToolset_eventGetSelectedAssets_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEditorAppToolset_GetSelectedAssets_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_GetSelectedAssets_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_GetSelectedAssets_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_GetSelectedAssets_Statics::PropPointers) < 2048);
// ********** End Function GetSelectedAssets Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEditorAppToolset_GetSelectedAssets_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEditorAppToolset, nullptr, "GetSelectedAssets", 	Z_Construct_UFunction_UEditorAppToolset_GetSelectedAssets_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_GetSelectedAssets_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UEditorAppToolset_GetSelectedAssets_Statics::EditorAppToolset_eventGetSelectedAssets_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_GetSelectedAssets_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEditorAppToolset_GetSelectedAssets_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEditorAppToolset_GetSelectedAssets_Statics::EditorAppToolset_eventGetSelectedAssets_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEditorAppToolset_GetSelectedAssets()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEditorAppToolset_GetSelectedAssets_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEditorAppToolset::execGetSelectedAssets)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=UEditorAppToolset::GetSelectedAssets();
	P_NATIVE_END;
}
// ********** End Class UEditorAppToolset Function GetSelectedAssets *******************************

// ********** Begin Class UEditorAppToolset Function GetVisibleActors ******************************
struct Z_Construct_UFunction_UEditorAppToolset_GetVisibleActors_Statics
{
	struct EditorAppToolset_eventGetVisibleActors_Parms
	{
		TArray<AActor*> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Returns all actors in the current level whose bounds intersect the viewport frustum.\n\x09 * @return The actors that are at least partially in view.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Returns all actors in the current level whose bounds intersect the viewport frustum.\n* @return The actors that are at least partially in view." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetVisibleActors constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetVisibleActors constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetVisibleActors Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEditorAppToolset_GetVisibleActors_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UEditorAppToolset_GetVisibleActors_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EditorAppToolset_eventGetVisibleActors_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEditorAppToolset_GetVisibleActors_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_GetVisibleActors_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_GetVisibleActors_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_GetVisibleActors_Statics::PropPointers) < 2048);
// ********** End Function GetVisibleActors Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEditorAppToolset_GetVisibleActors_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEditorAppToolset, nullptr, "GetVisibleActors", 	Z_Construct_UFunction_UEditorAppToolset_GetVisibleActors_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_GetVisibleActors_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UEditorAppToolset_GetVisibleActors_Statics::EditorAppToolset_eventGetVisibleActors_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_GetVisibleActors_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEditorAppToolset_GetVisibleActors_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEditorAppToolset_GetVisibleActors_Statics::EditorAppToolset_eventGetVisibleActors_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEditorAppToolset_GetVisibleActors()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEditorAppToolset_GetVisibleActors_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEditorAppToolset::execGetVisibleActors)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<AActor*>*)Z_Param__Result=UEditorAppToolset::GetVisibleActors();
	P_NATIVE_END;
}
// ********** End Class UEditorAppToolset Function GetVisibleActors ********************************

// ********** Begin Class UEditorAppToolset Function IsPIERunning **********************************
struct Z_Construct_UFunction_UEditorAppToolset_IsPIERunning_Statics
{
	struct EditorAppToolset_eventIsPIERunning_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Returns whether a Play In Editor session is currently running.\n\x09 * @return True if PIE is active, false otherwise.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Returns whether a Play In Editor session is currently running.\n* @return True if PIE is active, false otherwise." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsPIERunning constinit property declarations **************************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsPIERunning constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsPIERunning Property Definitions *************************************
void Z_Construct_UFunction_UEditorAppToolset_IsPIERunning_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EditorAppToolset_eventIsPIERunning_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEditorAppToolset_IsPIERunning_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EditorAppToolset_eventIsPIERunning_Parms), &Z_Construct_UFunction_UEditorAppToolset_IsPIERunning_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEditorAppToolset_IsPIERunning_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_IsPIERunning_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_IsPIERunning_Statics::PropPointers) < 2048);
// ********** End Function IsPIERunning Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEditorAppToolset_IsPIERunning_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEditorAppToolset, nullptr, "IsPIERunning", 	Z_Construct_UFunction_UEditorAppToolset_IsPIERunning_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_IsPIERunning_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UEditorAppToolset_IsPIERunning_Statics::EditorAppToolset_eventIsPIERunning_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_IsPIERunning_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEditorAppToolset_IsPIERunning_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEditorAppToolset_IsPIERunning_Statics::EditorAppToolset_eventIsPIERunning_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEditorAppToolset_IsPIERunning()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEditorAppToolset_IsPIERunning_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEditorAppToolset::execIsPIERunning)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UEditorAppToolset::IsPIERunning();
	P_NATIVE_END;
}
// ********** End Class UEditorAppToolset Function IsPIERunning ************************************

// ********** Begin Class UEditorAppToolset Function OpenEditorForAsset ****************************
struct Z_Construct_UFunction_UEditorAppToolset_OpenEditorForAsset_Statics
{
	struct EditorAppToolset_eventOpenEditorForAsset_Parms
	{
		FString AssetPath;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Opens an asset editor for the specified asset.\n\x09 * @param AssetPath The path to the asset to open, e.g. '/Game/Meshes/SM_Cube'.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Opens an asset editor for the specified asset.\n* @param AssetPath The path to the asset to open, e.g. '/Game/Meshes/SM_Cube'." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AssetPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OpenEditorForAsset constinit property declarations ********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AssetPath;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OpenEditorForAsset constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OpenEditorForAsset Property Definitions *******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEditorAppToolset_OpenEditorForAsset_Statics::NewProp_AssetPath = { "AssetPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EditorAppToolset_eventOpenEditorForAsset_Parms, AssetPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AssetPath_MetaData), NewProp_AssetPath_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEditorAppToolset_OpenEditorForAsset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_OpenEditorForAsset_Statics::NewProp_AssetPath,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_OpenEditorForAsset_Statics::PropPointers) < 2048);
// ********** End Function OpenEditorForAsset Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEditorAppToolset_OpenEditorForAsset_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEditorAppToolset, nullptr, "OpenEditorForAsset", 	Z_Construct_UFunction_UEditorAppToolset_OpenEditorForAsset_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_OpenEditorForAsset_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UEditorAppToolset_OpenEditorForAsset_Statics::EditorAppToolset_eventOpenEditorForAsset_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_OpenEditorForAsset_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEditorAppToolset_OpenEditorForAsset_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEditorAppToolset_OpenEditorForAsset_Statics::EditorAppToolset_eventOpenEditorForAsset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEditorAppToolset_OpenEditorForAsset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEditorAppToolset_OpenEditorForAsset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEditorAppToolset::execOpenEditorForAsset)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AssetPath);
	P_FINISH;
	P_NATIVE_BEGIN;
	UEditorAppToolset::OpenEditorForAsset(Z_Param_AssetPath);
	P_NATIVE_END;
}
// ********** End Class UEditorAppToolset Function OpenEditorForAsset ******************************

// ********** Begin Class UEditorAppToolset Function ScreenCoordsToWorld ***************************
struct Z_Construct_UFunction_UEditorAppToolset_ScreenCoordsToWorld_Statics
{
	struct EditorAppToolset_eventScreenCoordsToWorld_Parms
	{
		FVector2D Coords;
		float TraceDistance;
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Finds the world position of the nearest solid object at a given set of normalized view space coords.\n\x09 * @param Coords The normalized screen-space coordinates to trace from.\n\x09 * @param TraceDistance The maximum distance to trace within the scene.\n\x09 * @return The world-space coordinates of the intersection point.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Finds the world position of the nearest solid object at a given set of normalized view space coords.\n* @param Coords The normalized screen-space coordinates to trace from.\n* @param TraceDistance The maximum distance to trace within the scene.\n* @return The world-space coordinates of the intersection point." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ScreenCoordsToWorld constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Coords;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TraceDistance;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ScreenCoordsToWorld constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ScreenCoordsToWorld Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEditorAppToolset_ScreenCoordsToWorld_Statics::NewProp_Coords = { "Coords", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EditorAppToolset_eventScreenCoordsToWorld_Parms, Coords), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEditorAppToolset_ScreenCoordsToWorld_Statics::NewProp_TraceDistance = { "TraceDistance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EditorAppToolset_eventScreenCoordsToWorld_Parms, TraceDistance), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEditorAppToolset_ScreenCoordsToWorld_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EditorAppToolset_eventScreenCoordsToWorld_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEditorAppToolset_ScreenCoordsToWorld_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_ScreenCoordsToWorld_Statics::NewProp_Coords,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_ScreenCoordsToWorld_Statics::NewProp_TraceDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_ScreenCoordsToWorld_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_ScreenCoordsToWorld_Statics::PropPointers) < 2048);
// ********** End Function ScreenCoordsToWorld Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEditorAppToolset_ScreenCoordsToWorld_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEditorAppToolset, nullptr, "ScreenCoordsToWorld", 	Z_Construct_UFunction_UEditorAppToolset_ScreenCoordsToWorld_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_ScreenCoordsToWorld_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UEditorAppToolset_ScreenCoordsToWorld_Statics::EditorAppToolset_eventScreenCoordsToWorld_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_ScreenCoordsToWorld_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEditorAppToolset_ScreenCoordsToWorld_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEditorAppToolset_ScreenCoordsToWorld_Statics::EditorAppToolset_eventScreenCoordsToWorld_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEditorAppToolset_ScreenCoordsToWorld()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEditorAppToolset_ScreenCoordsToWorld_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEditorAppToolset::execScreenCoordsToWorld)
{
	P_GET_STRUCT(FVector2D,Z_Param_Coords);
	P_GET_PROPERTY(FFloatProperty,Z_Param_TraceDistance);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=UEditorAppToolset::ScreenCoordsToWorld(Z_Param_Coords,Z_Param_TraceDistance);
	P_NATIVE_END;
}
// ********** End Class UEditorAppToolset Function ScreenCoordsToWorld *****************************

// ********** Begin Class UEditorAppToolset Function SearchCVars ***********************************
struct Z_Construct_UFunction_UEditorAppToolset_SearchCVars_Statics
{
	struct EditorAppToolset_eventSearchCVars_Parms
	{
		FString Name;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Finds all console variables that contain a given name.\n\x09 * @param Name The partial or full name to search for.\n\x09 * @return A JSON dict with info about matching cvars.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Finds all console variables that contain a given name.\n* @param Name The partial or full name to search for.\n* @return A JSON dict with info about matching cvars." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SearchCVars constinit property declarations ***************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SearchCVars constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SearchCVars Property Definitions **************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEditorAppToolset_SearchCVars_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EditorAppToolset_eventSearchCVars_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEditorAppToolset_SearchCVars_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EditorAppToolset_eventSearchCVars_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEditorAppToolset_SearchCVars_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_SearchCVars_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_SearchCVars_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_SearchCVars_Statics::PropPointers) < 2048);
// ********** End Function SearchCVars Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEditorAppToolset_SearchCVars_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEditorAppToolset, nullptr, "SearchCVars", 	Z_Construct_UFunction_UEditorAppToolset_SearchCVars_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_SearchCVars_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UEditorAppToolset_SearchCVars_Statics::EditorAppToolset_eventSearchCVars_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_SearchCVars_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEditorAppToolset_SearchCVars_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEditorAppToolset_SearchCVars_Statics::EditorAppToolset_eventSearchCVars_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEditorAppToolset_SearchCVars()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEditorAppToolset_SearchCVars_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEditorAppToolset::execSearchCVars)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UEditorAppToolset::SearchCVars(Z_Param_Name);
	P_NATIVE_END;
}
// ********** End Class UEditorAppToolset Function SearchCVars *************************************

// ********** Begin Class UEditorAppToolset Function SelectActors **********************************
struct Z_Construct_UFunction_UEditorAppToolset_SelectActors_Statics
{
	struct EditorAppToolset_eventSelectActors_Parms
	{
		TArray<AActor*> Actors;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Selects the specified actors in the current scene.\n\x09 * @param Actors The actors to select.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Selects the specified actors in the current scene.\n* @param Actors The actors to select." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Actors_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SelectActors constinit property declarations **************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Actors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Actors;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SelectActors constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SelectActors Property Definitions *************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEditorAppToolset_SelectActors_Statics::NewProp_Actors_Inner = { "Actors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UEditorAppToolset_SelectActors_Statics::NewProp_Actors = { "Actors", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EditorAppToolset_eventSelectActors_Parms, Actors), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Actors_MetaData), NewProp_Actors_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEditorAppToolset_SelectActors_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_SelectActors_Statics::NewProp_Actors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_SelectActors_Statics::NewProp_Actors,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_SelectActors_Statics::PropPointers) < 2048);
// ********** End Function SelectActors Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEditorAppToolset_SelectActors_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEditorAppToolset, nullptr, "SelectActors", 	Z_Construct_UFunction_UEditorAppToolset_SelectActors_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_SelectActors_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UEditorAppToolset_SelectActors_Statics::EditorAppToolset_eventSelectActors_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_SelectActors_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEditorAppToolset_SelectActors_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEditorAppToolset_SelectActors_Statics::EditorAppToolset_eventSelectActors_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEditorAppToolset_SelectActors()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEditorAppToolset_SelectActors_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEditorAppToolset::execSelectActors)
{
	P_GET_TARRAY_REF(AActor*,Z_Param_Out_Actors);
	P_FINISH;
	P_NATIVE_BEGIN;
	UEditorAppToolset::SelectActors(Z_Param_Out_Actors);
	P_NATIVE_END;
}
// ********** End Class UEditorAppToolset Function SelectActors ************************************

// ********** Begin Class UEditorAppToolset Function SelectAssets **********************************
struct Z_Construct_UFunction_UEditorAppToolset_SelectAssets_Statics
{
	struct EditorAppToolset_eventSelectAssets_Parms
	{
		TArray<FString> AssetPaths;
		UToolCallAsyncResultVoid* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Selects the specified assets in the content browser.\n\x09 * Completes once the content browser has applied the selection.\n\x09 * @param AssetPaths The package paths of the assets to select.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Selects the specified assets in the content browser.\n* Completes once the content browser has applied the selection.\n* @param AssetPaths The package paths of the assets to select." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AssetPaths_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SelectAssets constinit property declarations **************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AssetPaths_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_AssetPaths;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SelectAssets constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SelectAssets Property Definitions *************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEditorAppToolset_SelectAssets_Statics::NewProp_AssetPaths_Inner = { "AssetPaths", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UEditorAppToolset_SelectAssets_Statics::NewProp_AssetPaths = { "AssetPaths", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EditorAppToolset_eventSelectAssets_Parms, AssetPaths), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AssetPaths_MetaData), NewProp_AssetPaths_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEditorAppToolset_SelectAssets_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EditorAppToolset_eventSelectAssets_Parms, ReturnValue), Z_Construct_UClass_UToolCallAsyncResultVoid_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEditorAppToolset_SelectAssets_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_SelectAssets_Statics::NewProp_AssetPaths_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_SelectAssets_Statics::NewProp_AssetPaths,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_SelectAssets_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_SelectAssets_Statics::PropPointers) < 2048);
// ********** End Function SelectAssets Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEditorAppToolset_SelectAssets_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEditorAppToolset, nullptr, "SelectAssets", 	Z_Construct_UFunction_UEditorAppToolset_SelectAssets_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_SelectAssets_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UEditorAppToolset_SelectAssets_Statics::EditorAppToolset_eventSelectAssets_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_SelectAssets_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEditorAppToolset_SelectAssets_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEditorAppToolset_SelectAssets_Statics::EditorAppToolset_eventSelectAssets_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEditorAppToolset_SelectAssets()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEditorAppToolset_SelectAssets_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEditorAppToolset::execSelectAssets)
{
	P_GET_TARRAY_REF(FString,Z_Param_Out_AssetPaths);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UToolCallAsyncResultVoid**)Z_Param__Result=UEditorAppToolset::SelectAssets(Z_Param_Out_AssetPaths);
	P_NATIVE_END;
}
// ********** End Class UEditorAppToolset Function SelectAssets ************************************

// ********** Begin Class UEditorAppToolset Function SetCameraTransform ****************************
struct Z_Construct_UFunction_UEditorAppToolset_SetCameraTransform_Statics
{
	struct EditorAppToolset_eventSetCameraTransform_Parms
	{
		FTransform Transform;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Sets the position and rotation of the level viewport camera.\n\x09 * @param Transform The transform to apply to the viewport camera.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Sets the position and rotation of the level viewport camera.\n* @param Transform The transform to apply to the viewport camera." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Transform_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetCameraTransform constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Transform;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetCameraTransform constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetCameraTransform Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEditorAppToolset_SetCameraTransform_Statics::NewProp_Transform = { "Transform", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EditorAppToolset_eventSetCameraTransform_Parms, Transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Transform_MetaData), NewProp_Transform_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEditorAppToolset_SetCameraTransform_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_SetCameraTransform_Statics::NewProp_Transform,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_SetCameraTransform_Statics::PropPointers) < 2048);
// ********** End Function SetCameraTransform Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEditorAppToolset_SetCameraTransform_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEditorAppToolset, nullptr, "SetCameraTransform", 	Z_Construct_UFunction_UEditorAppToolset_SetCameraTransform_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_SetCameraTransform_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UEditorAppToolset_SetCameraTransform_Statics::EditorAppToolset_eventSetCameraTransform_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_SetCameraTransform_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEditorAppToolset_SetCameraTransform_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEditorAppToolset_SetCameraTransform_Statics::EditorAppToolset_eventSetCameraTransform_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEditorAppToolset_SetCameraTransform()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEditorAppToolset_SetCameraTransform_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEditorAppToolset::execSetCameraTransform)
{
	P_GET_STRUCT_REF(FTransform,Z_Param_Out_Transform);
	P_FINISH;
	P_NATIVE_BEGIN;
	UEditorAppToolset::SetCameraTransform(Z_Param_Out_Transform);
	P_NATIVE_END;
}
// ********** End Class UEditorAppToolset Function SetCameraTransform ******************************

// ********** Begin Class UEditorAppToolset Function SetContentBrowserPath *************************
struct Z_Construct_UFunction_UEditorAppToolset_SetContentBrowserPath_Statics
{
	struct EditorAppToolset_eventSetContentBrowserPath_Parms
	{
		FString Path;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Navigates the active content browser to the specified folder path.\n\x09 * @param Path The internal path to navigate to, e.g. '/Game/Meshes'.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Navigates the active content browser to the specified folder path.\n* @param Path The internal path to navigate to, e.g. '/Game/Meshes'." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Path_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetContentBrowserPath constinit property declarations *****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Path;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetContentBrowserPath constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetContentBrowserPath Property Definitions ****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEditorAppToolset_SetContentBrowserPath_Statics::NewProp_Path = { "Path", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EditorAppToolset_eventSetContentBrowserPath_Parms, Path), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Path_MetaData), NewProp_Path_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEditorAppToolset_SetContentBrowserPath_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_SetContentBrowserPath_Statics::NewProp_Path,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_SetContentBrowserPath_Statics::PropPointers) < 2048);
// ********** End Function SetContentBrowserPath Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEditorAppToolset_SetContentBrowserPath_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEditorAppToolset, nullptr, "SetContentBrowserPath", 	Z_Construct_UFunction_UEditorAppToolset_SetContentBrowserPath_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_SetContentBrowserPath_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UEditorAppToolset_SetContentBrowserPath_Statics::EditorAppToolset_eventSetContentBrowserPath_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_SetContentBrowserPath_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEditorAppToolset_SetContentBrowserPath_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEditorAppToolset_SetContentBrowserPath_Statics::EditorAppToolset_eventSetContentBrowserPath_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEditorAppToolset_SetContentBrowserPath()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEditorAppToolset_SetContentBrowserPath_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEditorAppToolset::execSetContentBrowserPath)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Path);
	P_FINISH;
	P_NATIVE_BEGIN;
	UEditorAppToolset::SetContentBrowserPath(Z_Param_Path);
	P_NATIVE_END;
}
// ********** End Class UEditorAppToolset Function SetContentBrowserPath ***************************

// ********** Begin Class UEditorAppToolset Function StartPIE **************************************
struct Z_Construct_UFunction_UEditorAppToolset_StartPIE_Statics
{
	struct EditorAppToolset_eventStartPIE_Parms
	{
		FPIESessionOptions Options;
		UToolCallAsyncResultVoid* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Starts a Play-In-Editor or Simulate-In-Editor session using the current level.\n\x09 * Completes after the engine fires PostPIEStarted (session fully started,\n\x09 * BeginPlay called) and Options.WarmupSeconds have elapsed, giving project-\n\x09 * specific initialization (services, authentication, plugin warmup) time to\n\x09 * settle before the agent inspects state or logs.\n\x09 * Raises an error if a play session is already running.\n\x09 * @param Options Session configuration: PIE vs Simulate, play mode, optional\n\x09 *   spawn transform override, warmup duration. See FPIESessionOptions.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Starts a Play-In-Editor or Simulate-In-Editor session using the current level.\n* Completes after the engine fires PostPIEStarted (session fully started,\n* BeginPlay called) and Options.WarmupSeconds have elapsed, giving project-\n* specific initialization (services, authentication, plugin warmup) time to\n* settle before the agent inspects state or logs.\n* Raises an error if a play session is already running.\n* @param Options Session configuration: PIE vs Simulate, play mode, optional\n*   spawn transform override, warmup duration. See FPIESessionOptions." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Options_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function StartPIE constinit property declarations ******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Options;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function StartPIE constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function StartPIE Property Definitions *****************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEditorAppToolset_StartPIE_Statics::NewProp_Options = { "Options", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EditorAppToolset_eventStartPIE_Parms, Options), Z_Construct_UScriptStruct_FPIESessionOptions, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Options_MetaData), NewProp_Options_MetaData) }; // 1259254835
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEditorAppToolset_StartPIE_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EditorAppToolset_eventStartPIE_Parms, ReturnValue), Z_Construct_UClass_UToolCallAsyncResultVoid_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEditorAppToolset_StartPIE_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_StartPIE_Statics::NewProp_Options,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_StartPIE_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_StartPIE_Statics::PropPointers) < 2048);
// ********** End Function StartPIE Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEditorAppToolset_StartPIE_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEditorAppToolset, nullptr, "StartPIE", 	Z_Construct_UFunction_UEditorAppToolset_StartPIE_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_StartPIE_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UEditorAppToolset_StartPIE_Statics::EditorAppToolset_eventStartPIE_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_StartPIE_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEditorAppToolset_StartPIE_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEditorAppToolset_StartPIE_Statics::EditorAppToolset_eventStartPIE_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEditorAppToolset_StartPIE()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEditorAppToolset_StartPIE_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEditorAppToolset::execStartPIE)
{
	P_GET_STRUCT_REF(FPIESessionOptions,Z_Param_Out_Options);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UToolCallAsyncResultVoid**)Z_Param__Result=UEditorAppToolset::StartPIE(Z_Param_Out_Options);
	P_NATIVE_END;
}
// ********** End Class UEditorAppToolset Function StartPIE ****************************************

// ********** Begin Class UEditorAppToolset Function StopPIE ***************************************
struct Z_Construct_UFunction_UEditorAppToolset_StopPIE_Statics
{
	struct EditorAppToolset_eventStopPIE_Parms
	{
		UToolCallAsyncResultVoid* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Stops the currently running play session (PIE or Simulate).\n\x09 * Raises an error if no play session is running.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Stops the currently running play session (PIE or Simulate).\n* Raises an error if no play session is running." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function StopPIE constinit property declarations *******************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function StopPIE constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function StopPIE Property Definitions ******************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEditorAppToolset_StopPIE_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EditorAppToolset_eventStopPIE_Parms, ReturnValue), Z_Construct_UClass_UToolCallAsyncResultVoid_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEditorAppToolset_StopPIE_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_StopPIE_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_StopPIE_Statics::PropPointers) < 2048);
// ********** End Function StopPIE Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEditorAppToolset_StopPIE_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEditorAppToolset, nullptr, "StopPIE", 	Z_Construct_UFunction_UEditorAppToolset_StopPIE_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_StopPIE_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UEditorAppToolset_StopPIE_Statics::EditorAppToolset_eventStopPIE_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_StopPIE_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEditorAppToolset_StopPIE_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEditorAppToolset_StopPIE_Statics::EditorAppToolset_eventStopPIE_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEditorAppToolset_StopPIE()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEditorAppToolset_StopPIE_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEditorAppToolset::execStopPIE)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UToolCallAsyncResultVoid**)Z_Param__Result=UEditorAppToolset::StopPIE();
	P_NATIVE_END;
}
// ********** End Class UEditorAppToolset Function StopPIE *****************************************

// ********** Begin Class UEditorAppToolset Function WorldPosToScreenCoords ************************
struct Z_Construct_UFunction_UEditorAppToolset_WorldPosToScreenCoords_Statics
{
	struct EditorAppToolset_eventWorldPosToScreenCoords_Parms
	{
		FVector Position;
		FVector2D ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Converts a world-space position into normalized screen space based on the editor viewport camera.\n\x09 * @param Position The world space position to convert.\n\x09 * @return The normalized screen-space coordinates for the position if it is in view.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Converts a world-space position into normalized screen space based on the editor viewport camera.\n* @param Position The world space position to convert.\n* @return The normalized screen-space coordinates for the position if it is in view." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function WorldPosToScreenCoords constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function WorldPosToScreenCoords constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function WorldPosToScreenCoords Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEditorAppToolset_WorldPosToScreenCoords_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EditorAppToolset_eventWorldPosToScreenCoords_Parms, Position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEditorAppToolset_WorldPosToScreenCoords_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EditorAppToolset_eventWorldPosToScreenCoords_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEditorAppToolset_WorldPosToScreenCoords_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_WorldPosToScreenCoords_Statics::NewProp_Position,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEditorAppToolset_WorldPosToScreenCoords_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_WorldPosToScreenCoords_Statics::PropPointers) < 2048);
// ********** End Function WorldPosToScreenCoords Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEditorAppToolset_WorldPosToScreenCoords_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEditorAppToolset, nullptr, "WorldPosToScreenCoords", 	Z_Construct_UFunction_UEditorAppToolset_WorldPosToScreenCoords_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_WorldPosToScreenCoords_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UEditorAppToolset_WorldPosToScreenCoords_Statics::EditorAppToolset_eventWorldPosToScreenCoords_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEditorAppToolset_WorldPosToScreenCoords_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEditorAppToolset_WorldPosToScreenCoords_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEditorAppToolset_WorldPosToScreenCoords_Statics::EditorAppToolset_eventWorldPosToScreenCoords_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEditorAppToolset_WorldPosToScreenCoords()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEditorAppToolset_WorldPosToScreenCoords_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEditorAppToolset::execWorldPosToScreenCoords)
{
	P_GET_STRUCT(FVector,Z_Param_Position);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector2D*)Z_Param__Result=UEditorAppToolset::WorldPosToScreenCoords(Z_Param_Position);
	P_NATIVE_END;
}
// ********** End Class UEditorAppToolset Function WorldPosToScreenCoords **************************

// ********** Begin Class UEditorAppToolset ********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UEditorAppToolset;
UClass* UEditorAppToolset::GetPrivateStaticClass()
{
	using TClass = UEditorAppToolset;
	if (!Z_Registration_Info_UClass_UEditorAppToolset.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("EditorAppToolset"),
			Z_Registration_Info_UClass_UEditorAppToolset.InnerSingleton,
			StaticRegisterNativesUEditorAppToolset,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UEditorAppToolset.InnerSingleton;
}
UClass* Z_Construct_UClass_UEditorAppToolset_NoRegister()
{
	return UEditorAppToolset::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEditorAppToolset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Tools for querying and modifying Unreal Editor state: console variables, asset imaging,\n/// actor and asset selection, viewport camera, content browser navigation, and Play-In-Editor\n/// session control.\n" },
#endif
		{ "IncludePath", "EditorAppToolset.h" },
		{ "ModuleRelativePath", "Private/EditorAppToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Tools for querying and modifying Unreal Editor state: console variables, asset imaging,\nactor and asset selection, viewport camera, content browser navigation, and Play-In-Editor\nsession control." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UEditorAppToolset constinit property declarations ************************
// ********** End Class UEditorAppToolset constinit property declarations **************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CaptureAssetImage"), .Pointer = &UEditorAppToolset::execCaptureAssetImage },
		{ .NameUTF8 = UTF8TEXT("CaptureEditorImage"), .Pointer = &UEditorAppToolset::execCaptureEditorImage },
		{ .NameUTF8 = UTF8TEXT("CaptureViewport"), .Pointer = &UEditorAppToolset::execCaptureViewport },
		{ .NameUTF8 = UTF8TEXT("FocusOnActors"), .Pointer = &UEditorAppToolset::execFocusOnActors },
		{ .NameUTF8 = UTF8TEXT("GetCameraTransform"), .Pointer = &UEditorAppToolset::execGetCameraTransform },
		{ .NameUTF8 = UTF8TEXT("GetContentBrowserPath"), .Pointer = &UEditorAppToolset::execGetContentBrowserPath },
		{ .NameUTF8 = UTF8TEXT("GetOpenAssets"), .Pointer = &UEditorAppToolset::execGetOpenAssets },
		{ .NameUTF8 = UTF8TEXT("GetSelectedActors"), .Pointer = &UEditorAppToolset::execGetSelectedActors },
		{ .NameUTF8 = UTF8TEXT("GetSelectedAssets"), .Pointer = &UEditorAppToolset::execGetSelectedAssets },
		{ .NameUTF8 = UTF8TEXT("GetVisibleActors"), .Pointer = &UEditorAppToolset::execGetVisibleActors },
		{ .NameUTF8 = UTF8TEXT("IsPIERunning"), .Pointer = &UEditorAppToolset::execIsPIERunning },
		{ .NameUTF8 = UTF8TEXT("OpenEditorForAsset"), .Pointer = &UEditorAppToolset::execOpenEditorForAsset },
		{ .NameUTF8 = UTF8TEXT("ScreenCoordsToWorld"), .Pointer = &UEditorAppToolset::execScreenCoordsToWorld },
		{ .NameUTF8 = UTF8TEXT("SearchCVars"), .Pointer = &UEditorAppToolset::execSearchCVars },
		{ .NameUTF8 = UTF8TEXT("SelectActors"), .Pointer = &UEditorAppToolset::execSelectActors },
		{ .NameUTF8 = UTF8TEXT("SelectAssets"), .Pointer = &UEditorAppToolset::execSelectAssets },
		{ .NameUTF8 = UTF8TEXT("SetCameraTransform"), .Pointer = &UEditorAppToolset::execSetCameraTransform },
		{ .NameUTF8 = UTF8TEXT("SetContentBrowserPath"), .Pointer = &UEditorAppToolset::execSetContentBrowserPath },
		{ .NameUTF8 = UTF8TEXT("StartPIE"), .Pointer = &UEditorAppToolset::execStartPIE },
		{ .NameUTF8 = UTF8TEXT("StopPIE"), .Pointer = &UEditorAppToolset::execStopPIE },
		{ .NameUTF8 = UTF8TEXT("WorldPosToScreenCoords"), .Pointer = &UEditorAppToolset::execWorldPosToScreenCoords },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEditorAppToolset_CaptureAssetImage, "CaptureAssetImage" }, // 1854748733
		{ &Z_Construct_UFunction_UEditorAppToolset_CaptureEditorImage, "CaptureEditorImage" }, // 834701168
		{ &Z_Construct_UFunction_UEditorAppToolset_CaptureViewport, "CaptureViewport" }, // 1400344183
		{ &Z_Construct_UFunction_UEditorAppToolset_FocusOnActors, "FocusOnActors" }, // 350535001
		{ &Z_Construct_UFunction_UEditorAppToolset_GetCameraTransform, "GetCameraTransform" }, // 3891877136
		{ &Z_Construct_UFunction_UEditorAppToolset_GetContentBrowserPath, "GetContentBrowserPath" }, // 4193083226
		{ &Z_Construct_UFunction_UEditorAppToolset_GetOpenAssets, "GetOpenAssets" }, // 1716417188
		{ &Z_Construct_UFunction_UEditorAppToolset_GetSelectedActors, "GetSelectedActors" }, // 3340356333
		{ &Z_Construct_UFunction_UEditorAppToolset_GetSelectedAssets, "GetSelectedAssets" }, // 2361191067
		{ &Z_Construct_UFunction_UEditorAppToolset_GetVisibleActors, "GetVisibleActors" }, // 3593276319
		{ &Z_Construct_UFunction_UEditorAppToolset_IsPIERunning, "IsPIERunning" }, // 908534398
		{ &Z_Construct_UFunction_UEditorAppToolset_OpenEditorForAsset, "OpenEditorForAsset" }, // 2078209255
		{ &Z_Construct_UFunction_UEditorAppToolset_ScreenCoordsToWorld, "ScreenCoordsToWorld" }, // 3510731960
		{ &Z_Construct_UFunction_UEditorAppToolset_SearchCVars, "SearchCVars" }, // 2375171290
		{ &Z_Construct_UFunction_UEditorAppToolset_SelectActors, "SelectActors" }, // 295001252
		{ &Z_Construct_UFunction_UEditorAppToolset_SelectAssets, "SelectAssets" }, // 4263575879
		{ &Z_Construct_UFunction_UEditorAppToolset_SetCameraTransform, "SetCameraTransform" }, // 1912511473
		{ &Z_Construct_UFunction_UEditorAppToolset_SetContentBrowserPath, "SetContentBrowserPath" }, // 321777428
		{ &Z_Construct_UFunction_UEditorAppToolset_StartPIE, "StartPIE" }, // 460903433
		{ &Z_Construct_UFunction_UEditorAppToolset_StopPIE, "StopPIE" }, // 3296791711
		{ &Z_Construct_UFunction_UEditorAppToolset_WorldPosToScreenCoords, "WorldPosToScreenCoords" }, // 2333223465
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEditorAppToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UEditorAppToolset_Statics
UObject* (*const Z_Construct_UClass_UEditorAppToolset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UToolsetDefinition,
	(UObject* (*)())Z_Construct_UPackage__Script_EditorToolset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEditorAppToolset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEditorAppToolset_Statics::ClassParams = {
	&UEditorAppToolset::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x000800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEditorAppToolset_Statics::Class_MetaDataParams), Z_Construct_UClass_UEditorAppToolset_Statics::Class_MetaDataParams)
};
void UEditorAppToolset::StaticRegisterNativesUEditorAppToolset()
{
	UClass* Class = UEditorAppToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UEditorAppToolset_Statics::Funcs));
}
UClass* Z_Construct_UClass_UEditorAppToolset()
{
	if (!Z_Registration_Info_UClass_UEditorAppToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEditorAppToolset.OuterSingleton, Z_Construct_UClass_UEditorAppToolset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEditorAppToolset.OuterSingleton;
}
UEditorAppToolset::UEditorAppToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UEditorAppToolset);
UEditorAppToolset::~UEditorAppToolset() {}
// ********** End Class UEditorAppToolset **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_EditorAppToolset_h__Script_EditorToolset_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FPIESessionOptions::StaticStruct, Z_Construct_UScriptStruct_FPIESessionOptions_Statics::NewStructOps, TEXT("PIESessionOptions"),&Z_Registration_Info_UScriptStruct_FPIESessionOptions, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPIESessionOptions), 1259254835U) },
		{ FViewportLabel::StaticStruct, Z_Construct_UScriptStruct_FViewportLabel_Statics::NewStructOps, TEXT("ViewportLabel"),&Z_Registration_Info_UScriptStruct_FViewportLabel, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FViewportLabel), 1685283340U) },
		{ FViewportGrid::StaticStruct, Z_Construct_UScriptStruct_FViewportGrid_Statics::NewStructOps, TEXT("ViewportGrid"),&Z_Registration_Info_UScriptStruct_FViewportGrid, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FViewportGrid), 1910091040U) },
		{ FViewportAnnotationConfig::StaticStruct, Z_Construct_UScriptStruct_FViewportAnnotationConfig_Statics::NewStructOps, TEXT("ViewportAnnotationConfig"),&Z_Registration_Info_UScriptStruct_FViewportAnnotationConfig, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FViewportAnnotationConfig), 1695222172U) },
		{ FViewportCapture::StaticStruct, Z_Construct_UScriptStruct_FViewportCapture_Statics::NewStructOps, TEXT("ViewportCapture"),&Z_Registration_Info_UScriptStruct_FViewportCapture, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FViewportCapture), 4285175330U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEditorAppToolset, UEditorAppToolset::StaticClass, TEXT("UEditorAppToolset"), &Z_Registration_Info_UClass_UEditorAppToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEditorAppToolset), 901136801U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_EditorAppToolset_h__Script_EditorToolset_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_EditorAppToolset_h__Script_EditorToolset_2280201025{
	TEXT("/Script/EditorToolset"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_EditorAppToolset_h__Script_EditorToolset_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_EditorAppToolset_h__Script_EditorToolset_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_EditorAppToolset_h__Script_EditorToolset_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_EditorAppToolset_h__Script_EditorToolset_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
