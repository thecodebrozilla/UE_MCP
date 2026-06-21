// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameplayCueToolset.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeGameplayCueToolset() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
GASTOOLSETS_API UClass* Z_Construct_UClass_UGameplayCueToolset();
GASTOOLSETS_API UClass* Z_Construct_UClass_UGameplayCueToolset_NoRegister();
GASTOOLSETS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayCueInfo();
GASTOOLSETS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayCueNotifyInfo();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition();
UPackage* Z_Construct_UPackage__Script_GASToolsets();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FGameplayCueInfo **************************************************
struct Z_Construct_UScriptStruct_FGameplayCueInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FGameplayCueInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FGameplayCueInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Describes a registered gameplay cue and its associated notify asset.\n" },
#endif
		{ "ModuleRelativePath", "Private/GameplayCueToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Describes a registered gameplay cue and its associated notify asset." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Tag_MetaData[] = {
		{ "Category", "GameplayCue" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The fully-qualified gameplay cue tag (e.g. \"GameplayCue.Character.Death\").\n" },
#endif
		{ "ModuleRelativePath", "Private/GameplayCueToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The fully-qualified gameplay cue tag (e.g. \"GameplayCue.Character.Death\")." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NotifyAssetPath_MetaData[] = {
		{ "Category", "GameplayCue" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The object path to the associated GameplayCueNotify asset.\n/// Empty if no notify has been found for this tag in the asset registry.\n" },
#endif
		{ "ModuleRelativePath", "Private/GameplayCueToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The object path to the associated GameplayCueNotify asset.\nEmpty if no notify has been found for this tag in the asset registry." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NotifyType_MetaData[] = {
		{ "Category", "GameplayCue" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The notify base class: \"Static\", \"Actor\", or \"None\" if no notify is found.\n" },
#endif
		{ "ModuleRelativePath", "Private/GameplayCueToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The notify base class: \"Static\", \"Actor\", or \"None\" if no notify is found." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FGameplayCueInfo constinit property declarations ******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Tag;
	static const UECodeGen_Private::FStrPropertyParams NewProp_NotifyAssetPath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_NotifyType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FGameplayCueInfo constinit property declarations ********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGameplayCueInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FGameplayCueInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FGameplayCueInfo;
class UScriptStruct* FGameplayCueInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FGameplayCueInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FGameplayCueInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FGameplayCueInfo, (UObject*)Z_Construct_UPackage__Script_GASToolsets(), TEXT("GameplayCueInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FGameplayCueInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FGameplayCueInfo Property Definitions *****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FGameplayCueInfo_Statics::NewProp_Tag = { "Tag", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGameplayCueInfo, Tag), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Tag_MetaData), NewProp_Tag_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FGameplayCueInfo_Statics::NewProp_NotifyAssetPath = { "NotifyAssetPath", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGameplayCueInfo, NotifyAssetPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NotifyAssetPath_MetaData), NewProp_NotifyAssetPath_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FGameplayCueInfo_Statics::NewProp_NotifyType = { "NotifyType", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGameplayCueInfo, NotifyType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NotifyType_MetaData), NewProp_NotifyType_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGameplayCueInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameplayCueInfo_Statics::NewProp_Tag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameplayCueInfo_Statics::NewProp_NotifyAssetPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameplayCueInfo_Statics::NewProp_NotifyType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameplayCueInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FGameplayCueInfo Property Definitions *******************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGameplayCueInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GASToolsets,
	nullptr,
	&NewStructOps,
	"GameplayCueInfo",
	Z_Construct_UScriptStruct_FGameplayCueInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameplayCueInfo_Statics::PropPointers),
	sizeof(FGameplayCueInfo),
	alignof(FGameplayCueInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameplayCueInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FGameplayCueInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FGameplayCueInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FGameplayCueInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FGameplayCueInfo.InnerSingleton, Z_Construct_UScriptStruct_FGameplayCueInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FGameplayCueInfo.InnerSingleton);
}
// ********** End ScriptStruct FGameplayCueInfo ****************************************************

// ********** Begin ScriptStruct FGameplayCueNotifyInfo ********************************************
struct Z_Construct_UScriptStruct_FGameplayCueNotifyInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FGameplayCueNotifyInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FGameplayCueNotifyInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Describes a GameplayCueNotify asset found in the project.\n" },
#endif
		{ "ModuleRelativePath", "Private/GameplayCueToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Describes a GameplayCueNotify asset found in the project." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CueTag_MetaData[] = {
		{ "Category", "GameplayCue" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The gameplay cue tag this notify responds to.\n" },
#endif
		{ "ModuleRelativePath", "Private/GameplayCueToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The gameplay cue tag this notify responds to." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AssetPath_MetaData[] = {
		{ "Category", "GameplayCue" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The full object path to the asset (e.g. \"/Game/Effects/GCN_Death.GCN_Death\").\n" },
#endif
		{ "ModuleRelativePath", "Private/GameplayCueToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The full object path to the asset (e.g. \"/Game/Effects/GCN_Death.GCN_Death\")." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AssetName_MetaData[] = {
		{ "Category", "GameplayCue" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The asset name without the package path (e.g. \"GCN_Death\").\n" },
#endif
		{ "ModuleRelativePath", "Private/GameplayCueToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The asset name without the package path (e.g. \"GCN_Death\")." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NotifyType_MetaData[] = {
		{ "Category", "GameplayCue" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// \"Static\" for UGameplayCueNotify_Static subclasses, \"Actor\" for AGameplayCueNotify_Actor subclasses.\n" },
#endif
		{ "ModuleRelativePath", "Private/GameplayCueToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\"Static\" for UGameplayCueNotify_Static subclasses, \"Actor\" for AGameplayCueNotify_Actor subclasses." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FGameplayCueNotifyInfo constinit property declarations ************
	static const UECodeGen_Private::FStrPropertyParams NewProp_CueTag;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AssetPath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AssetName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_NotifyType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FGameplayCueNotifyInfo constinit property declarations **************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGameplayCueNotifyInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FGameplayCueNotifyInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FGameplayCueNotifyInfo;
class UScriptStruct* FGameplayCueNotifyInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FGameplayCueNotifyInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FGameplayCueNotifyInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FGameplayCueNotifyInfo, (UObject*)Z_Construct_UPackage__Script_GASToolsets(), TEXT("GameplayCueNotifyInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FGameplayCueNotifyInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FGameplayCueNotifyInfo Property Definitions ***********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FGameplayCueNotifyInfo_Statics::NewProp_CueTag = { "CueTag", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGameplayCueNotifyInfo, CueTag), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CueTag_MetaData), NewProp_CueTag_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FGameplayCueNotifyInfo_Statics::NewProp_AssetPath = { "AssetPath", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGameplayCueNotifyInfo, AssetPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AssetPath_MetaData), NewProp_AssetPath_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FGameplayCueNotifyInfo_Statics::NewProp_AssetName = { "AssetName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGameplayCueNotifyInfo, AssetName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AssetName_MetaData), NewProp_AssetName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FGameplayCueNotifyInfo_Statics::NewProp_NotifyType = { "NotifyType", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGameplayCueNotifyInfo, NotifyType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NotifyType_MetaData), NewProp_NotifyType_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGameplayCueNotifyInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameplayCueNotifyInfo_Statics::NewProp_CueTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameplayCueNotifyInfo_Statics::NewProp_AssetPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameplayCueNotifyInfo_Statics::NewProp_AssetName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameplayCueNotifyInfo_Statics::NewProp_NotifyType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameplayCueNotifyInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FGameplayCueNotifyInfo Property Definitions *************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGameplayCueNotifyInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GASToolsets,
	nullptr,
	&NewStructOps,
	"GameplayCueNotifyInfo",
	Z_Construct_UScriptStruct_FGameplayCueNotifyInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameplayCueNotifyInfo_Statics::PropPointers),
	sizeof(FGameplayCueNotifyInfo),
	alignof(FGameplayCueNotifyInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameplayCueNotifyInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FGameplayCueNotifyInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FGameplayCueNotifyInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FGameplayCueNotifyInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FGameplayCueNotifyInfo.InnerSingleton, Z_Construct_UScriptStruct_FGameplayCueNotifyInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FGameplayCueNotifyInfo.InnerSingleton);
}
// ********** End ScriptStruct FGameplayCueNotifyInfo **********************************************

// ********** Begin Class UGameplayCueToolset Function AddCueTag ***********************************
struct Z_Construct_UFunction_UGameplayCueToolset_AddCueTag_Statics
{
	struct GameplayCueToolset_eventAddCueTag_Parms
	{
		FString CueTag;
		FString Comment;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "GameplayCues" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Adds a new gameplay cue tag to the project.\n\x09 * This should ONLY be called after getting explicit direction or permission from the user.\n\x09 * @param CueTag The fully-qualified tag to add. Must begin with \"GameplayCue.\"\n\x09 *   (e.g. \"GameplayCue.Character.Death\").\n\x09 * @param Comment An optional developer comment describing the cue's purpose.\n\x09 * @return True if the tag was added successfully.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/GameplayCueToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds a new gameplay cue tag to the project.\nThis should ONLY be called after getting explicit direction or permission from the user.\n@param CueTag The fully-qualified tag to add. Must begin with \"GameplayCue.\"\n  (e.g. \"GameplayCue.Character.Death\").\n@param Comment An optional developer comment describing the cue's purpose.\n@return True if the tag was added successfully." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CueTag_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Comment_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddCueTag constinit property declarations *****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_CueTag;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Comment;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddCueTag constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddCueTag Property Definitions ****************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameplayCueToolset_AddCueTag_Statics::NewProp_CueTag = { "CueTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayCueToolset_eventAddCueTag_Parms, CueTag), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CueTag_MetaData), NewProp_CueTag_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameplayCueToolset_AddCueTag_Statics::NewProp_Comment = { "Comment", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayCueToolset_eventAddCueTag_Parms, Comment), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Comment_MetaData), NewProp_Comment_MetaData) };
void Z_Construct_UFunction_UGameplayCueToolset_AddCueTag_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((GameplayCueToolset_eventAddCueTag_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGameplayCueToolset_AddCueTag_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GameplayCueToolset_eventAddCueTag_Parms), &Z_Construct_UFunction_UGameplayCueToolset_AddCueTag_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameplayCueToolset_AddCueTag_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayCueToolset_AddCueTag_Statics::NewProp_CueTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayCueToolset_AddCueTag_Statics::NewProp_Comment,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayCueToolset_AddCueTag_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayCueToolset_AddCueTag_Statics::PropPointers) < 2048);
// ********** End Function AddCueTag Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameplayCueToolset_AddCueTag_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGameplayCueToolset, nullptr, "AddCueTag", 	Z_Construct_UFunction_UGameplayCueToolset_AddCueTag_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayCueToolset_AddCueTag_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGameplayCueToolset_AddCueTag_Statics::GameplayCueToolset_eventAddCueTag_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayCueToolset_AddCueTag_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameplayCueToolset_AddCueTag_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGameplayCueToolset_AddCueTag_Statics::GameplayCueToolset_eventAddCueTag_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGameplayCueToolset_AddCueTag()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameplayCueToolset_AddCueTag_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGameplayCueToolset::execAddCueTag)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_CueTag);
	P_GET_PROPERTY(FStrProperty,Z_Param_Comment);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UGameplayCueToolset::AddCueTag(Z_Param_CueTag,Z_Param_Comment);
	P_NATIVE_END;
}
// ********** End Class UGameplayCueToolset Function AddCueTag *************************************

// ********** Begin Class UGameplayCueToolset Function CreateCueNotifyAsset ************************
struct Z_Construct_UFunction_UGameplayCueToolset_CreateCueNotifyAsset_Statics
{
	struct GameplayCueToolset_eventCreateCueNotifyAsset_Parms
	{
		FString CueTag;
		FString PackagePath;
		FString AssetName;
		bool bIsActor;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "GameplayCues" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Creates a new GameplayCueNotify Blueprint asset at the specified content browser location.\n\x09 * This should ONLY be called after getting explicit direction or permission from the user.\n\x09 * @param CueTag The gameplay cue tag the notify should respond to.\n\x09 *   The tag must already exist; create it first with AddCueTag if needed.\n\x09 * @param PackagePath The content browser folder for the asset, e.g. \"/Game/Effects/Cues\".\n\x09 * @param AssetName The file name for the new asset, e.g. \"GCN_CharacterDeath\".\n\x09 * @param bIsActor If true, creates a GameplayCueNotify_Actor (spawned actor in the world).\n\x09 *   If false, creates a GameplayCueNotify_Static (instant effect, no spawned actor).\n\x09 * @return The object path of the created asset, or an empty string on failure.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/GameplayCueToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Creates a new GameplayCueNotify Blueprint asset at the specified content browser location.\nThis should ONLY be called after getting explicit direction or permission from the user.\n@param CueTag The gameplay cue tag the notify should respond to.\n  The tag must already exist; create it first with AddCueTag if needed.\n@param PackagePath The content browser folder for the asset, e.g. \"/Game/Effects/Cues\".\n@param AssetName The file name for the new asset, e.g. \"GCN_CharacterDeath\".\n@param bIsActor If true, creates a GameplayCueNotify_Actor (spawned actor in the world).\n  If false, creates a GameplayCueNotify_Static (instant effect, no spawned actor).\n@return The object path of the created asset, or an empty string on failure." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CueTag_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PackagePath_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AssetName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CreateCueNotifyAsset constinit property declarations ******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_CueTag;
	static const UECodeGen_Private::FStrPropertyParams NewProp_PackagePath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AssetName;
	static void NewProp_bIsActor_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsActor;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CreateCueNotifyAsset constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CreateCueNotifyAsset Property Definitions *****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameplayCueToolset_CreateCueNotifyAsset_Statics::NewProp_CueTag = { "CueTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayCueToolset_eventCreateCueNotifyAsset_Parms, CueTag), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CueTag_MetaData), NewProp_CueTag_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameplayCueToolset_CreateCueNotifyAsset_Statics::NewProp_PackagePath = { "PackagePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayCueToolset_eventCreateCueNotifyAsset_Parms, PackagePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PackagePath_MetaData), NewProp_PackagePath_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameplayCueToolset_CreateCueNotifyAsset_Statics::NewProp_AssetName = { "AssetName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayCueToolset_eventCreateCueNotifyAsset_Parms, AssetName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AssetName_MetaData), NewProp_AssetName_MetaData) };
void Z_Construct_UFunction_UGameplayCueToolset_CreateCueNotifyAsset_Statics::NewProp_bIsActor_SetBit(void* Obj)
{
	((GameplayCueToolset_eventCreateCueNotifyAsset_Parms*)Obj)->bIsActor = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGameplayCueToolset_CreateCueNotifyAsset_Statics::NewProp_bIsActor = { "bIsActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GameplayCueToolset_eventCreateCueNotifyAsset_Parms), &Z_Construct_UFunction_UGameplayCueToolset_CreateCueNotifyAsset_Statics::NewProp_bIsActor_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameplayCueToolset_CreateCueNotifyAsset_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayCueToolset_eventCreateCueNotifyAsset_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameplayCueToolset_CreateCueNotifyAsset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayCueToolset_CreateCueNotifyAsset_Statics::NewProp_CueTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayCueToolset_CreateCueNotifyAsset_Statics::NewProp_PackagePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayCueToolset_CreateCueNotifyAsset_Statics::NewProp_AssetName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayCueToolset_CreateCueNotifyAsset_Statics::NewProp_bIsActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayCueToolset_CreateCueNotifyAsset_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayCueToolset_CreateCueNotifyAsset_Statics::PropPointers) < 2048);
// ********** End Function CreateCueNotifyAsset Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameplayCueToolset_CreateCueNotifyAsset_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGameplayCueToolset, nullptr, "CreateCueNotifyAsset", 	Z_Construct_UFunction_UGameplayCueToolset_CreateCueNotifyAsset_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayCueToolset_CreateCueNotifyAsset_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGameplayCueToolset_CreateCueNotifyAsset_Statics::GameplayCueToolset_eventCreateCueNotifyAsset_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayCueToolset_CreateCueNotifyAsset_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameplayCueToolset_CreateCueNotifyAsset_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGameplayCueToolset_CreateCueNotifyAsset_Statics::GameplayCueToolset_eventCreateCueNotifyAsset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGameplayCueToolset_CreateCueNotifyAsset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameplayCueToolset_CreateCueNotifyAsset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGameplayCueToolset::execCreateCueNotifyAsset)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_CueTag);
	P_GET_PROPERTY(FStrProperty,Z_Param_PackagePath);
	P_GET_PROPERTY(FStrProperty,Z_Param_AssetName);
	P_GET_UBOOL(Z_Param_bIsActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UGameplayCueToolset::CreateCueNotifyAsset(Z_Param_CueTag,Z_Param_PackagePath,Z_Param_AssetName,Z_Param_bIsActor);
	P_NATIVE_END;
}
// ********** End Class UGameplayCueToolset Function CreateCueNotifyAsset **************************

// ********** Begin Class UGameplayCueToolset Function ExecuteCueOnSelectedActor *******************
struct Z_Construct_UFunction_UGameplayCueToolset_ExecuteCueOnSelectedActor_Statics
{
	struct GameplayCueToolset_eventExecuteCueOnSelectedActor_Parms
	{
		FString CueTag;
		float NormalizedMagnitude;
		FVector Location;
		FVector Normal;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "GameplayCues" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Executes a gameplay cue non-replicated on the currently selected actor in the editor.\n\x09 * Useful for previewing cue effects without network replication.\n\x09 * Requires a PIE session or a configured GameplayCueManager to produce visible results.\n\x09 * @param CueTag The fully-qualified tag of the cue to execute, e.g. \"GameplayCue.Character.Death\".\n\x09 * @param NormalizedMagnitude A normalized (0.0-1.0) magnitude value passed to the cue.\n\x09 * @param Location World-space location parameter passed to the cue.\n\x09 * @param Normal World-space direction parameter passed to the cue.\n\x09 * @return True if the cue was dispatched. Raises a script error if no actor is selected\n\x09 *   or the tag does not exist.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/GameplayCueToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Executes a gameplay cue non-replicated on the currently selected actor in the editor.\nUseful for previewing cue effects without network replication.\nRequires a PIE session or a configured GameplayCueManager to produce visible results.\n@param CueTag The fully-qualified tag of the cue to execute, e.g. \"GameplayCue.Character.Death\".\n@param NormalizedMagnitude A normalized (0.0-1.0) magnitude value passed to the cue.\n@param Location World-space location parameter passed to the cue.\n@param Normal World-space direction parameter passed to the cue.\n@return True if the cue was dispatched. Raises a script error if no actor is selected\n  or the tag does not exist." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CueTag_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ExecuteCueOnSelectedActor constinit property declarations *************
	static const UECodeGen_Private::FStrPropertyParams NewProp_CueTag;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NormalizedMagnitude;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Normal;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ExecuteCueOnSelectedActor constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ExecuteCueOnSelectedActor Property Definitions ************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameplayCueToolset_ExecuteCueOnSelectedActor_Statics::NewProp_CueTag = { "CueTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayCueToolset_eventExecuteCueOnSelectedActor_Parms, CueTag), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CueTag_MetaData), NewProp_CueTag_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UGameplayCueToolset_ExecuteCueOnSelectedActor_Statics::NewProp_NormalizedMagnitude = { "NormalizedMagnitude", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayCueToolset_eventExecuteCueOnSelectedActor_Parms, NormalizedMagnitude), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGameplayCueToolset_ExecuteCueOnSelectedActor_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayCueToolset_eventExecuteCueOnSelectedActor_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGameplayCueToolset_ExecuteCueOnSelectedActor_Statics::NewProp_Normal = { "Normal", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayCueToolset_eventExecuteCueOnSelectedActor_Parms, Normal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UGameplayCueToolset_ExecuteCueOnSelectedActor_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((GameplayCueToolset_eventExecuteCueOnSelectedActor_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGameplayCueToolset_ExecuteCueOnSelectedActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GameplayCueToolset_eventExecuteCueOnSelectedActor_Parms), &Z_Construct_UFunction_UGameplayCueToolset_ExecuteCueOnSelectedActor_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameplayCueToolset_ExecuteCueOnSelectedActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayCueToolset_ExecuteCueOnSelectedActor_Statics::NewProp_CueTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayCueToolset_ExecuteCueOnSelectedActor_Statics::NewProp_NormalizedMagnitude,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayCueToolset_ExecuteCueOnSelectedActor_Statics::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayCueToolset_ExecuteCueOnSelectedActor_Statics::NewProp_Normal,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayCueToolset_ExecuteCueOnSelectedActor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayCueToolset_ExecuteCueOnSelectedActor_Statics::PropPointers) < 2048);
// ********** End Function ExecuteCueOnSelectedActor Property Definitions **************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameplayCueToolset_ExecuteCueOnSelectedActor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGameplayCueToolset, nullptr, "ExecuteCueOnSelectedActor", 	Z_Construct_UFunction_UGameplayCueToolset_ExecuteCueOnSelectedActor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayCueToolset_ExecuteCueOnSelectedActor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGameplayCueToolset_ExecuteCueOnSelectedActor_Statics::GameplayCueToolset_eventExecuteCueOnSelectedActor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayCueToolset_ExecuteCueOnSelectedActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameplayCueToolset_ExecuteCueOnSelectedActor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGameplayCueToolset_ExecuteCueOnSelectedActor_Statics::GameplayCueToolset_eventExecuteCueOnSelectedActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGameplayCueToolset_ExecuteCueOnSelectedActor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameplayCueToolset_ExecuteCueOnSelectedActor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGameplayCueToolset::execExecuteCueOnSelectedActor)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_CueTag);
	P_GET_PROPERTY(FFloatProperty,Z_Param_NormalizedMagnitude);
	P_GET_STRUCT(FVector,Z_Param_Location);
	P_GET_STRUCT(FVector,Z_Param_Normal);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UGameplayCueToolset::ExecuteCueOnSelectedActor(Z_Param_CueTag,Z_Param_NormalizedMagnitude,Z_Param_Location,Z_Param_Normal);
	P_NATIVE_END;
}
// ********** End Class UGameplayCueToolset Function ExecuteCueOnSelectedActor *********************

// ********** Begin Class UGameplayCueToolset Function FindCueNotifyAssets *************************
struct Z_Construct_UFunction_UGameplayCueToolset_FindCueNotifyAssets_Statics
{
	struct GameplayCueToolset_eventFindCueNotifyAssets_Parms
	{
		FString ParentTag;
		TArray<FGameplayCueNotifyInfo> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "GameplayCues" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns all GameplayCueNotify assets found in the project via the asset registry.\n\x09 * @param ParentTag If non-empty, only notifies whose cue tag descends from this tag are returned.\n\x09 *   Pass an empty string to return all notify assets in the project.\n\x09 * @return A list of notify descriptors, sorted by cue tag.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/GameplayCueToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns all GameplayCueNotify assets found in the project via the asset registry.\n@param ParentTag If non-empty, only notifies whose cue tag descends from this tag are returned.\n  Pass an empty string to return all notify assets in the project.\n@return A list of notify descriptors, sorted by cue tag." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ParentTag_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function FindCueNotifyAssets constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ParentTag;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FindCueNotifyAssets constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FindCueNotifyAssets Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameplayCueToolset_FindCueNotifyAssets_Statics::NewProp_ParentTag = { "ParentTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayCueToolset_eventFindCueNotifyAssets_Parms, ParentTag), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ParentTag_MetaData), NewProp_ParentTag_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGameplayCueToolset_FindCueNotifyAssets_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGameplayCueNotifyInfo, METADATA_PARAMS(0, nullptr) }; // 3281200071
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UGameplayCueToolset_FindCueNotifyAssets_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayCueToolset_eventFindCueNotifyAssets_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 3281200071
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameplayCueToolset_FindCueNotifyAssets_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayCueToolset_FindCueNotifyAssets_Statics::NewProp_ParentTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayCueToolset_FindCueNotifyAssets_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayCueToolset_FindCueNotifyAssets_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayCueToolset_FindCueNotifyAssets_Statics::PropPointers) < 2048);
// ********** End Function FindCueNotifyAssets Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameplayCueToolset_FindCueNotifyAssets_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGameplayCueToolset, nullptr, "FindCueNotifyAssets", 	Z_Construct_UFunction_UGameplayCueToolset_FindCueNotifyAssets_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayCueToolset_FindCueNotifyAssets_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGameplayCueToolset_FindCueNotifyAssets_Statics::GameplayCueToolset_eventFindCueNotifyAssets_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayCueToolset_FindCueNotifyAssets_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameplayCueToolset_FindCueNotifyAssets_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGameplayCueToolset_FindCueNotifyAssets_Statics::GameplayCueToolset_eventFindCueNotifyAssets_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGameplayCueToolset_FindCueNotifyAssets()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameplayCueToolset_FindCueNotifyAssets_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGameplayCueToolset::execFindCueNotifyAssets)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ParentTag);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FGameplayCueNotifyInfo>*)Z_Param__Result=UGameplayCueToolset::FindCueNotifyAssets(Z_Param_ParentTag);
	P_NATIVE_END;
}
// ********** End Class UGameplayCueToolset Function FindCueNotifyAssets ***************************

// ********** Begin Class UGameplayCueToolset Function FindCueTagsWithoutNotifies ******************
struct Z_Construct_UFunction_UGameplayCueToolset_FindCueTagsWithoutNotifies_Statics
{
	struct GameplayCueToolset_eventFindCueTagsWithoutNotifies_Parms
	{
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "GameplayCues" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns gameplay cue tags that have no corresponding GameplayCueNotify asset in the project.\n\x09 * Tags without notifies produce no visible effect when triggered at runtime.\n\x09 * @return A sorted list of gameplay cue tag names with no associated notify assets.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/GameplayCueToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns gameplay cue tags that have no corresponding GameplayCueNotify asset in the project.\nTags without notifies produce no visible effect when triggered at runtime.\n@return A sorted list of gameplay cue tag names with no associated notify assets." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function FindCueTagsWithoutNotifies constinit property declarations ************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FindCueTagsWithoutNotifies constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FindCueTagsWithoutNotifies Property Definitions ***********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameplayCueToolset_FindCueTagsWithoutNotifies_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UGameplayCueToolset_FindCueTagsWithoutNotifies_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayCueToolset_eventFindCueTagsWithoutNotifies_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameplayCueToolset_FindCueTagsWithoutNotifies_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayCueToolset_FindCueTagsWithoutNotifies_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayCueToolset_FindCueTagsWithoutNotifies_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayCueToolset_FindCueTagsWithoutNotifies_Statics::PropPointers) < 2048);
// ********** End Function FindCueTagsWithoutNotifies Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameplayCueToolset_FindCueTagsWithoutNotifies_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGameplayCueToolset, nullptr, "FindCueTagsWithoutNotifies", 	Z_Construct_UFunction_UGameplayCueToolset_FindCueTagsWithoutNotifies_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayCueToolset_FindCueTagsWithoutNotifies_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGameplayCueToolset_FindCueTagsWithoutNotifies_Statics::GameplayCueToolset_eventFindCueTagsWithoutNotifies_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayCueToolset_FindCueTagsWithoutNotifies_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameplayCueToolset_FindCueTagsWithoutNotifies_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGameplayCueToolset_FindCueTagsWithoutNotifies_Statics::GameplayCueToolset_eventFindCueTagsWithoutNotifies_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGameplayCueToolset_FindCueTagsWithoutNotifies()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameplayCueToolset_FindCueTagsWithoutNotifies_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGameplayCueToolset::execFindCueTagsWithoutNotifies)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=UGameplayCueToolset::FindCueTagsWithoutNotifies();
	P_NATIVE_END;
}
// ********** End Class UGameplayCueToolset Function FindCueTagsWithoutNotifies ********************

// ********** Begin Class UGameplayCueToolset Function GetCueInfo **********************************
struct Z_Construct_UFunction_UGameplayCueToolset_GetCueInfo_Statics
{
	struct GameplayCueToolset_eventGetCueInfo_Parms
	{
		FString CueTag;
		FGameplayCueInfo ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "GameplayCues" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns information about a specific gameplay cue, including its notify asset.\n\x09 * @param CueTag The fully-qualified gameplay cue tag, e.g. \"GameplayCue.Character.Death\".\n\x09 * @return The cue's notify asset path and type (\"Static\", \"Actor\", or \"None\").\n\x09 *   Raises a script error if the tag does not exist.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/GameplayCueToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns information about a specific gameplay cue, including its notify asset.\n@param CueTag The fully-qualified gameplay cue tag, e.g. \"GameplayCue.Character.Death\".\n@return The cue's notify asset path and type (\"Static\", \"Actor\", or \"None\").\n  Raises a script error if the tag does not exist." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CueTag_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCueInfo constinit property declarations ****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_CueTag;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCueInfo constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCueInfo Property Definitions ***************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameplayCueToolset_GetCueInfo_Statics::NewProp_CueTag = { "CueTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayCueToolset_eventGetCueInfo_Parms, CueTag), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CueTag_MetaData), NewProp_CueTag_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGameplayCueToolset_GetCueInfo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayCueToolset_eventGetCueInfo_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayCueInfo, METADATA_PARAMS(0, nullptr) }; // 3554732059
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameplayCueToolset_GetCueInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayCueToolset_GetCueInfo_Statics::NewProp_CueTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayCueToolset_GetCueInfo_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayCueToolset_GetCueInfo_Statics::PropPointers) < 2048);
// ********** End Function GetCueInfo Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameplayCueToolset_GetCueInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGameplayCueToolset, nullptr, "GetCueInfo", 	Z_Construct_UFunction_UGameplayCueToolset_GetCueInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayCueToolset_GetCueInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGameplayCueToolset_GetCueInfo_Statics::GameplayCueToolset_eventGetCueInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayCueToolset_GetCueInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameplayCueToolset_GetCueInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGameplayCueToolset_GetCueInfo_Statics::GameplayCueToolset_eventGetCueInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGameplayCueToolset_GetCueInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameplayCueToolset_GetCueInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGameplayCueToolset::execGetCueInfo)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_CueTag);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGameplayCueInfo*)Z_Param__Result=UGameplayCueToolset::GetCueInfo(Z_Param_CueTag);
	P_NATIVE_END;
}
// ********** End Class UGameplayCueToolset Function GetCueInfo ************************************

// ********** Begin Class UGameplayCueToolset Function ListCues ************************************
struct Z_Construct_UFunction_UGameplayCueToolset_ListCues_Statics
{
	struct GameplayCueToolset_eventListCues_Parms
	{
		FString ParentTag;
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "GameplayCues" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns gameplay cue tags registered in the project.\n\x09 * @param ParentTag If non-empty, only cues descending from this tag are returned.\n\x09 *   For example, passing \"GameplayCue.Character\" returns all cues under that namespace.\n\x09 *   Pass an empty string to return all tags under the \"GameplayCue\" root.\n\x09 * @return A sorted list of fully-qualified gameplay cue tag names.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/GameplayCueToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns gameplay cue tags registered in the project.\n@param ParentTag If non-empty, only cues descending from this tag are returned.\n  For example, passing \"GameplayCue.Character\" returns all cues under that namespace.\n  Pass an empty string to return all tags under the \"GameplayCue\" root.\n@return A sorted list of fully-qualified gameplay cue tag names." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ParentTag_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ListCues constinit property declarations ******************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ParentTag;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListCues constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListCues Property Definitions *****************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameplayCueToolset_ListCues_Statics::NewProp_ParentTag = { "ParentTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayCueToolset_eventListCues_Parms, ParentTag), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ParentTag_MetaData), NewProp_ParentTag_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameplayCueToolset_ListCues_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UGameplayCueToolset_ListCues_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayCueToolset_eventListCues_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameplayCueToolset_ListCues_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayCueToolset_ListCues_Statics::NewProp_ParentTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayCueToolset_ListCues_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayCueToolset_ListCues_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayCueToolset_ListCues_Statics::PropPointers) < 2048);
// ********** End Function ListCues Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameplayCueToolset_ListCues_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGameplayCueToolset, nullptr, "ListCues", 	Z_Construct_UFunction_UGameplayCueToolset_ListCues_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayCueToolset_ListCues_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGameplayCueToolset_ListCues_Statics::GameplayCueToolset_eventListCues_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayCueToolset_ListCues_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameplayCueToolset_ListCues_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGameplayCueToolset_ListCues_Statics::GameplayCueToolset_eventListCues_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGameplayCueToolset_ListCues()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameplayCueToolset_ListCues_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGameplayCueToolset::execListCues)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ParentTag);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=UGameplayCueToolset::ListCues(Z_Param_ParentTag);
	P_NATIVE_END;
}
// ********** End Class UGameplayCueToolset Function ListCues **************************************

// ********** Begin Class UGameplayCueToolset Function RemoveCueTag ********************************
struct Z_Construct_UFunction_UGameplayCueToolset_RemoveCueTag_Statics
{
	struct GameplayCueToolset_eventRemoveCueTag_Parms
	{
		FString CueTag;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "GameplayCues" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Removes a gameplay cue tag from the project.\n\x09 * This should ONLY be called after getting explicit direction or permission from the user.\n\x09 * @param CueTag The fully-qualified cue tag to remove (e.g. \"GameplayCue.Character.Death\").\n\x09 * @return True if the tag was removed successfully.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/GameplayCueToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Removes a gameplay cue tag from the project.\nThis should ONLY be called after getting explicit direction or permission from the user.\n@param CueTag The fully-qualified cue tag to remove (e.g. \"GameplayCue.Character.Death\").\n@return True if the tag was removed successfully." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CueTag_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RemoveCueTag constinit property declarations **************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_CueTag;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RemoveCueTag constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RemoveCueTag Property Definitions *************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameplayCueToolset_RemoveCueTag_Statics::NewProp_CueTag = { "CueTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayCueToolset_eventRemoveCueTag_Parms, CueTag), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CueTag_MetaData), NewProp_CueTag_MetaData) };
void Z_Construct_UFunction_UGameplayCueToolset_RemoveCueTag_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((GameplayCueToolset_eventRemoveCueTag_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGameplayCueToolset_RemoveCueTag_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GameplayCueToolset_eventRemoveCueTag_Parms), &Z_Construct_UFunction_UGameplayCueToolset_RemoveCueTag_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameplayCueToolset_RemoveCueTag_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayCueToolset_RemoveCueTag_Statics::NewProp_CueTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayCueToolset_RemoveCueTag_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayCueToolset_RemoveCueTag_Statics::PropPointers) < 2048);
// ********** End Function RemoveCueTag Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameplayCueToolset_RemoveCueTag_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGameplayCueToolset, nullptr, "RemoveCueTag", 	Z_Construct_UFunction_UGameplayCueToolset_RemoveCueTag_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayCueToolset_RemoveCueTag_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGameplayCueToolset_RemoveCueTag_Statics::GameplayCueToolset_eventRemoveCueTag_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayCueToolset_RemoveCueTag_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameplayCueToolset_RemoveCueTag_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGameplayCueToolset_RemoveCueTag_Statics::GameplayCueToolset_eventRemoveCueTag_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGameplayCueToolset_RemoveCueTag()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameplayCueToolset_RemoveCueTag_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGameplayCueToolset::execRemoveCueTag)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_CueTag);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UGameplayCueToolset::RemoveCueTag(Z_Param_CueTag);
	P_NATIVE_END;
}
// ********** End Class UGameplayCueToolset Function RemoveCueTag **********************************

// ********** Begin Class UGameplayCueToolset ******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UGameplayCueToolset;
UClass* UGameplayCueToolset::GetPrivateStaticClass()
{
	using TClass = UGameplayCueToolset;
	if (!Z_Registration_Info_UClass_UGameplayCueToolset.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("GameplayCueToolset"),
			Z_Registration_Info_UClass_UGameplayCueToolset.InnerSingleton,
			StaticRegisterNativesUGameplayCueToolset,
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
	return Z_Registration_Info_UClass_UGameplayCueToolset.InnerSingleton;
}
UClass* Z_Construct_UClass_UGameplayCueToolset_NoRegister()
{
	return UGameplayCueToolset::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UGameplayCueToolset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Provides tools for inspecting, executing, and managing gameplay cues and their notify assets.\n" },
#endif
		{ "IncludePath", "GameplayCueToolset.h" },
		{ "ModuleRelativePath", "Private/GameplayCueToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Provides tools for inspecting, executing, and managing gameplay cues and their notify assets." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UGameplayCueToolset constinit property declarations **********************
// ********** End Class UGameplayCueToolset constinit property declarations ************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AddCueTag"), .Pointer = &UGameplayCueToolset::execAddCueTag },
		{ .NameUTF8 = UTF8TEXT("CreateCueNotifyAsset"), .Pointer = &UGameplayCueToolset::execCreateCueNotifyAsset },
		{ .NameUTF8 = UTF8TEXT("ExecuteCueOnSelectedActor"), .Pointer = &UGameplayCueToolset::execExecuteCueOnSelectedActor },
		{ .NameUTF8 = UTF8TEXT("FindCueNotifyAssets"), .Pointer = &UGameplayCueToolset::execFindCueNotifyAssets },
		{ .NameUTF8 = UTF8TEXT("FindCueTagsWithoutNotifies"), .Pointer = &UGameplayCueToolset::execFindCueTagsWithoutNotifies },
		{ .NameUTF8 = UTF8TEXT("GetCueInfo"), .Pointer = &UGameplayCueToolset::execGetCueInfo },
		{ .NameUTF8 = UTF8TEXT("ListCues"), .Pointer = &UGameplayCueToolset::execListCues },
		{ .NameUTF8 = UTF8TEXT("RemoveCueTag"), .Pointer = &UGameplayCueToolset::execRemoveCueTag },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UGameplayCueToolset_AddCueTag, "AddCueTag" }, // 752237971
		{ &Z_Construct_UFunction_UGameplayCueToolset_CreateCueNotifyAsset, "CreateCueNotifyAsset" }, // 168740956
		{ &Z_Construct_UFunction_UGameplayCueToolset_ExecuteCueOnSelectedActor, "ExecuteCueOnSelectedActor" }, // 2895363827
		{ &Z_Construct_UFunction_UGameplayCueToolset_FindCueNotifyAssets, "FindCueNotifyAssets" }, // 4204044717
		{ &Z_Construct_UFunction_UGameplayCueToolset_FindCueTagsWithoutNotifies, "FindCueTagsWithoutNotifies" }, // 645382015
		{ &Z_Construct_UFunction_UGameplayCueToolset_GetCueInfo, "GetCueInfo" }, // 299015711
		{ &Z_Construct_UFunction_UGameplayCueToolset_ListCues, "ListCues" }, // 3418763010
		{ &Z_Construct_UFunction_UGameplayCueToolset_RemoveCueTag, "RemoveCueTag" }, // 2193946869
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameplayCueToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UGameplayCueToolset_Statics
UObject* (*const Z_Construct_UClass_UGameplayCueToolset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UToolsetDefinition,
	(UObject* (*)())Z_Construct_UPackage__Script_GASToolsets,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGameplayCueToolset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGameplayCueToolset_Statics::ClassParams = {
	&UGameplayCueToolset::StaticClass,
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
	0x010000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGameplayCueToolset_Statics::Class_MetaDataParams), Z_Construct_UClass_UGameplayCueToolset_Statics::Class_MetaDataParams)
};
void UGameplayCueToolset::StaticRegisterNativesUGameplayCueToolset()
{
	UClass* Class = UGameplayCueToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UGameplayCueToolset_Statics::Funcs));
}
UClass* Z_Construct_UClass_UGameplayCueToolset()
{
	if (!Z_Registration_Info_UClass_UGameplayCueToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGameplayCueToolset.OuterSingleton, Z_Construct_UClass_UGameplayCueToolset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGameplayCueToolset.OuterSingleton;
}
UGameplayCueToolset::UGameplayCueToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UGameplayCueToolset);
UGameplayCueToolset::~UGameplayCueToolset() {}
// ********** End Class UGameplayCueToolset ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_GameplayCueToolset_h__Script_GASToolsets_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FGameplayCueInfo::StaticStruct, Z_Construct_UScriptStruct_FGameplayCueInfo_Statics::NewStructOps, TEXT("GameplayCueInfo"),&Z_Registration_Info_UScriptStruct_FGameplayCueInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGameplayCueInfo), 3554732059U) },
		{ FGameplayCueNotifyInfo::StaticStruct, Z_Construct_UScriptStruct_FGameplayCueNotifyInfo_Statics::NewStructOps, TEXT("GameplayCueNotifyInfo"),&Z_Registration_Info_UScriptStruct_FGameplayCueNotifyInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGameplayCueNotifyInfo), 3281200071U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGameplayCueToolset, UGameplayCueToolset::StaticClass, TEXT("UGameplayCueToolset"), &Z_Registration_Info_UClass_UGameplayCueToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGameplayCueToolset), 2479781569U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_GameplayCueToolset_h__Script_GASToolsets_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_GameplayCueToolset_h__Script_GASToolsets_1209704771{
	TEXT("/Script/GASToolsets"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_GameplayCueToolset_h__Script_GASToolsets_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_GameplayCueToolset_h__Script_GASToolsets_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_GameplayCueToolset_h__Script_GASToolsets_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_GameplayCueToolset_h__Script_GASToolsets_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
