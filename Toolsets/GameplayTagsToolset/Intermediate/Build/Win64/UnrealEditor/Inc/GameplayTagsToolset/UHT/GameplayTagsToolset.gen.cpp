// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameplayTagsToolset/GameplayTagsToolset.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeGameplayTagsToolset() {}

// ********** Begin Cross Module References ********************************************************
GAMEPLAYTAGSTOOLSET_API UClass* Z_Construct_UClass_UGameplayTagsToolset();
GAMEPLAYTAGSTOOLSET_API UClass* Z_Construct_UClass_UGameplayTagsToolset_NoRegister();
GAMEPLAYTAGSTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagInfo();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition();
UPackage* Z_Construct_UPackage__Script_GameplayTagsToolset();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FGameplayTagInfo **************************************************
struct Z_Construct_UScriptStruct_FGameplayTagInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FGameplayTagInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FGameplayTagInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Describes the properties of a gameplay tag.\n" },
#endif
		{ "ModuleRelativePath", "Private/GameplayTagsToolset/GameplayTagsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Describes the properties of a gameplay tag." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Comment_MetaData[] = {
		{ "Category", "GameplayTag" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The developer comment describing the tag's purpose.\n" },
#endif
		{ "ModuleRelativePath", "Private/GameplayTagsToolset/GameplayTagsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The developer comment describing the tag's purpose." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Source_MetaData[] = {
		{ "Category", "GameplayTag" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The name of the INI source file that defines this tag (e.g. \"DefaultGameplayTags.ini\").\n" },
#endif
		{ "ModuleRelativePath", "Private/GameplayTagsToolset/GameplayTagsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The name of the INI source file that defines this tag (e.g. \"DefaultGameplayTags.ini\")." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Children_MetaData[] = {
		{ "Category", "GameplayTag" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The fully-qualified names of this tag's immediate children.\n" },
#endif
		{ "ModuleRelativePath", "Private/GameplayTagsToolset/GameplayTagsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The fully-qualified names of this tag's immediate children." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FGameplayTagInfo constinit property declarations ******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Comment;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Source;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Children_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Children;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FGameplayTagInfo constinit property declarations ********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGameplayTagInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FGameplayTagInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FGameplayTagInfo;
class UScriptStruct* FGameplayTagInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FGameplayTagInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FGameplayTagInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FGameplayTagInfo, (UObject*)Z_Construct_UPackage__Script_GameplayTagsToolset(), TEXT("GameplayTagInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FGameplayTagInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FGameplayTagInfo Property Definitions *****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FGameplayTagInfo_Statics::NewProp_Comment = { "Comment", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGameplayTagInfo, Comment), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Comment_MetaData), NewProp_Comment_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FGameplayTagInfo_Statics::NewProp_Source = { "Source", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGameplayTagInfo, Source), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Source_MetaData), NewProp_Source_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FGameplayTagInfo_Statics::NewProp_Children_Inner = { "Children", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FGameplayTagInfo_Statics::NewProp_Children = { "Children", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGameplayTagInfo, Children), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Children_MetaData), NewProp_Children_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGameplayTagInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameplayTagInfo_Statics::NewProp_Comment,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameplayTagInfo_Statics::NewProp_Source,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameplayTagInfo_Statics::NewProp_Children_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameplayTagInfo_Statics::NewProp_Children,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameplayTagInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FGameplayTagInfo Property Definitions *******************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGameplayTagInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GameplayTagsToolset,
	nullptr,
	&NewStructOps,
	"GameplayTagInfo",
	Z_Construct_UScriptStruct_FGameplayTagInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameplayTagInfo_Statics::PropPointers),
	sizeof(FGameplayTagInfo),
	alignof(FGameplayTagInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameplayTagInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FGameplayTagInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FGameplayTagInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FGameplayTagInfo.InnerSingleton, Z_Construct_UScriptStruct_FGameplayTagInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FGameplayTagInfo.InnerSingleton);
}
// ********** End ScriptStruct FGameplayTagInfo ****************************************************

// ********** Begin Class UGameplayTagsToolset Function AddTag *************************************
struct Z_Construct_UFunction_UGameplayTagsToolset_AddTag_Statics
{
	struct GameplayTagsToolset_eventAddTag_Parms
	{
		FString TagName;
		FString Comment;
		FString TagSource;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "GameplayTags" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Adds a new gameplay tag to the project.\n\x09 * This should ONLY be called after getting explicit direction or permission from the user.\n\x09 * @param TagName The fully-qualified name of the tag to add, e.g. \"Character.State.Dead\".\n\x09 * @param Comment An optional developer comment describing the tag's purpose.\n\x09 * @param TagSource The INI source to add the tag to. Uses the default source if empty.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/GameplayTagsToolset/GameplayTagsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds a new gameplay tag to the project.\nThis should ONLY be called after getting explicit direction or permission from the user.\n@param TagName The fully-qualified name of the tag to add, e.g. \"Character.State.Dead\".\n@param Comment An optional developer comment describing the tag's purpose.\n@param TagSource The INI source to add the tag to. Uses the default source if empty." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TagName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Comment_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TagSource_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddTag constinit property declarations ********************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_TagName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Comment;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TagSource;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddTag constinit property declarations **********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddTag Property Definitions *******************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameplayTagsToolset_AddTag_Statics::NewProp_TagName = { "TagName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayTagsToolset_eventAddTag_Parms, TagName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TagName_MetaData), NewProp_TagName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameplayTagsToolset_AddTag_Statics::NewProp_Comment = { "Comment", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayTagsToolset_eventAddTag_Parms, Comment), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Comment_MetaData), NewProp_Comment_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameplayTagsToolset_AddTag_Statics::NewProp_TagSource = { "TagSource", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayTagsToolset_eventAddTag_Parms, TagSource), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TagSource_MetaData), NewProp_TagSource_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameplayTagsToolset_AddTag_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayTagsToolset_AddTag_Statics::NewProp_TagName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayTagsToolset_AddTag_Statics::NewProp_Comment,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayTagsToolset_AddTag_Statics::NewProp_TagSource,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayTagsToolset_AddTag_Statics::PropPointers) < 2048);
// ********** End Function AddTag Property Definitions *********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameplayTagsToolset_AddTag_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGameplayTagsToolset, nullptr, "AddTag", 	Z_Construct_UFunction_UGameplayTagsToolset_AddTag_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayTagsToolset_AddTag_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGameplayTagsToolset_AddTag_Statics::GameplayTagsToolset_eventAddTag_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayTagsToolset_AddTag_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameplayTagsToolset_AddTag_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGameplayTagsToolset_AddTag_Statics::GameplayTagsToolset_eventAddTag_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGameplayTagsToolset_AddTag()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameplayTagsToolset_AddTag_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGameplayTagsToolset::execAddTag)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_TagName);
	P_GET_PROPERTY(FStrProperty,Z_Param_Comment);
	P_GET_PROPERTY(FStrProperty,Z_Param_TagSource);
	P_FINISH;
	P_NATIVE_BEGIN;
	UGameplayTagsToolset::AddTag(Z_Param_TagName,Z_Param_Comment,Z_Param_TagSource);
	P_NATIVE_END;
}
// ********** End Class UGameplayTagsToolset Function AddTag ***************************************

// ********** Begin Class UGameplayTagsToolset Function FindReferencersByTag ***********************
struct Z_Construct_UFunction_UGameplayTagsToolset_FindReferencersByTag_Statics
{
	struct GameplayTagsToolset_eventFindReferencersByTag_Parms
	{
		FString TagName;
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "GameplayTags" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns assets that reference a gameplay tag.\n\x09 * @param TagName The fully-qualified gameplay tag to search for, e.g. \"Character.State.Dead\".\n\x09 * @return A list of package paths that reference the tag.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/GameplayTagsToolset/GameplayTagsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns assets that reference a gameplay tag.\n@param TagName The fully-qualified gameplay tag to search for, e.g. \"Character.State.Dead\".\n@return A list of package paths that reference the tag." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TagName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function FindReferencersByTag constinit property declarations ******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_TagName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FindReferencersByTag constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FindReferencersByTag Property Definitions *****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameplayTagsToolset_FindReferencersByTag_Statics::NewProp_TagName = { "TagName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayTagsToolset_eventFindReferencersByTag_Parms, TagName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TagName_MetaData), NewProp_TagName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameplayTagsToolset_FindReferencersByTag_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UGameplayTagsToolset_FindReferencersByTag_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayTagsToolset_eventFindReferencersByTag_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameplayTagsToolset_FindReferencersByTag_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayTagsToolset_FindReferencersByTag_Statics::NewProp_TagName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayTagsToolset_FindReferencersByTag_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayTagsToolset_FindReferencersByTag_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayTagsToolset_FindReferencersByTag_Statics::PropPointers) < 2048);
// ********** End Function FindReferencersByTag Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameplayTagsToolset_FindReferencersByTag_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGameplayTagsToolset, nullptr, "FindReferencersByTag", 	Z_Construct_UFunction_UGameplayTagsToolset_FindReferencersByTag_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayTagsToolset_FindReferencersByTag_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGameplayTagsToolset_FindReferencersByTag_Statics::GameplayTagsToolset_eventFindReferencersByTag_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayTagsToolset_FindReferencersByTag_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameplayTagsToolset_FindReferencersByTag_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGameplayTagsToolset_FindReferencersByTag_Statics::GameplayTagsToolset_eventFindReferencersByTag_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGameplayTagsToolset_FindReferencersByTag()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameplayTagsToolset_FindReferencersByTag_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGameplayTagsToolset::execFindReferencersByTag)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_TagName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=UGameplayTagsToolset::FindReferencersByTag(Z_Param_TagName);
	P_NATIVE_END;
}
// ********** End Class UGameplayTagsToolset Function FindReferencersByTag *************************

// ********** Begin Class UGameplayTagsToolset Function GetTagInfo *********************************
struct Z_Construct_UFunction_UGameplayTagsToolset_GetTagInfo_Statics
{
	struct GameplayTagsToolset_eventGetTagInfo_Parms
	{
		FString TagName;
		FGameplayTagInfo ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "GameplayTags" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns detailed information about a specific gameplay tag.\n\x09 * @param TagName The fully-qualified name of the tag, e.g. \"Character.State.Dead\".\n\x09 * @return The tag's developer comment, source INI file, and immediate children.\n\x09 *   Raises a script error if the tag does not exist.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/GameplayTagsToolset/GameplayTagsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns detailed information about a specific gameplay tag.\n@param TagName The fully-qualified name of the tag, e.g. \"Character.State.Dead\".\n@return The tag's developer comment, source INI file, and immediate children.\n  Raises a script error if the tag does not exist." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TagName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetTagInfo constinit property declarations ****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_TagName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetTagInfo constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetTagInfo Property Definitions ***************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameplayTagsToolset_GetTagInfo_Statics::NewProp_TagName = { "TagName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayTagsToolset_eventGetTagInfo_Parms, TagName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TagName_MetaData), NewProp_TagName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGameplayTagsToolset_GetTagInfo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayTagsToolset_eventGetTagInfo_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayTagInfo, METADATA_PARAMS(0, nullptr) }; // 3546409351
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameplayTagsToolset_GetTagInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayTagsToolset_GetTagInfo_Statics::NewProp_TagName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayTagsToolset_GetTagInfo_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayTagsToolset_GetTagInfo_Statics::PropPointers) < 2048);
// ********** End Function GetTagInfo Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameplayTagsToolset_GetTagInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGameplayTagsToolset, nullptr, "GetTagInfo", 	Z_Construct_UFunction_UGameplayTagsToolset_GetTagInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayTagsToolset_GetTagInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGameplayTagsToolset_GetTagInfo_Statics::GameplayTagsToolset_eventGetTagInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayTagsToolset_GetTagInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameplayTagsToolset_GetTagInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGameplayTagsToolset_GetTagInfo_Statics::GameplayTagsToolset_eventGetTagInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGameplayTagsToolset_GetTagInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameplayTagsToolset_GetTagInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGameplayTagsToolset::execGetTagInfo)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_TagName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGameplayTagInfo*)Z_Param__Result=UGameplayTagsToolset::GetTagInfo(Z_Param_TagName);
	P_NATIVE_END;
}
// ********** End Class UGameplayTagsToolset Function GetTagInfo ***********************************

// ********** Begin Class UGameplayTagsToolset Function ListTags ***********************************
struct Z_Construct_UFunction_UGameplayTagsToolset_ListTags_Statics
{
	struct GameplayTagsToolset_eventListTags_Parms
	{
		FString ParentTag;
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "GameplayTags" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns gameplay tags registered in the project.\n\x09 * @param ParentTag If non-empty, only tags that are descendants of this tag are returned.\n\x09 *   For example, passing \"Character.State\" returns \"Character.State.Dead\",\n\x09 *   \"Character.State.Stunned\", etc. Pass an empty string to return all tags.\n\x09 * @return A sorted list of fully-qualified tag names.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/GameplayTagsToolset/GameplayTagsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns gameplay tags registered in the project.\n@param ParentTag If non-empty, only tags that are descendants of this tag are returned.\n  For example, passing \"Character.State\" returns \"Character.State.Dead\",\n  \"Character.State.Stunned\", etc. Pass an empty string to return all tags.\n@return A sorted list of fully-qualified tag names." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ParentTag_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ListTags constinit property declarations ******************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ParentTag;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListTags constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListTags Property Definitions *****************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameplayTagsToolset_ListTags_Statics::NewProp_ParentTag = { "ParentTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayTagsToolset_eventListTags_Parms, ParentTag), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ParentTag_MetaData), NewProp_ParentTag_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameplayTagsToolset_ListTags_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UGameplayTagsToolset_ListTags_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayTagsToolset_eventListTags_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameplayTagsToolset_ListTags_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayTagsToolset_ListTags_Statics::NewProp_ParentTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayTagsToolset_ListTags_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayTagsToolset_ListTags_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayTagsToolset_ListTags_Statics::PropPointers) < 2048);
// ********** End Function ListTags Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameplayTagsToolset_ListTags_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGameplayTagsToolset, nullptr, "ListTags", 	Z_Construct_UFunction_UGameplayTagsToolset_ListTags_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayTagsToolset_ListTags_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGameplayTagsToolset_ListTags_Statics::GameplayTagsToolset_eventListTags_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayTagsToolset_ListTags_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameplayTagsToolset_ListTags_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGameplayTagsToolset_ListTags_Statics::GameplayTagsToolset_eventListTags_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGameplayTagsToolset_ListTags()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameplayTagsToolset_ListTags_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGameplayTagsToolset::execListTags)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ParentTag);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=UGameplayTagsToolset::ListTags(Z_Param_ParentTag);
	P_NATIVE_END;
}
// ********** End Class UGameplayTagsToolset Function ListTags *************************************

// ********** Begin Class UGameplayTagsToolset Function RemoveTag **********************************
struct Z_Construct_UFunction_UGameplayTagsToolset_RemoveTag_Statics
{
	struct GameplayTagsToolset_eventRemoveTag_Parms
	{
		FString TagName;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "GameplayTags" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Removes a gameplay tag from the project.\n\x09 * This should ONLY be called after getting explicit direction or permission from the user.\n\x09 * @param TagName The fully-qualified name of the tag to remove, e.g. \"Character.State.Dead\".\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/GameplayTagsToolset/GameplayTagsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Removes a gameplay tag from the project.\nThis should ONLY be called after getting explicit direction or permission from the user.\n@param TagName The fully-qualified name of the tag to remove, e.g. \"Character.State.Dead\"." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TagName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RemoveTag constinit property declarations *****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_TagName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RemoveTag constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RemoveTag Property Definitions ****************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameplayTagsToolset_RemoveTag_Statics::NewProp_TagName = { "TagName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayTagsToolset_eventRemoveTag_Parms, TagName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TagName_MetaData), NewProp_TagName_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameplayTagsToolset_RemoveTag_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayTagsToolset_RemoveTag_Statics::NewProp_TagName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayTagsToolset_RemoveTag_Statics::PropPointers) < 2048);
// ********** End Function RemoveTag Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameplayTagsToolset_RemoveTag_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGameplayTagsToolset, nullptr, "RemoveTag", 	Z_Construct_UFunction_UGameplayTagsToolset_RemoveTag_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayTagsToolset_RemoveTag_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGameplayTagsToolset_RemoveTag_Statics::GameplayTagsToolset_eventRemoveTag_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayTagsToolset_RemoveTag_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameplayTagsToolset_RemoveTag_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGameplayTagsToolset_RemoveTag_Statics::GameplayTagsToolset_eventRemoveTag_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGameplayTagsToolset_RemoveTag()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameplayTagsToolset_RemoveTag_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGameplayTagsToolset::execRemoveTag)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_TagName);
	P_FINISH;
	P_NATIVE_BEGIN;
	UGameplayTagsToolset::RemoveTag(Z_Param_TagName);
	P_NATIVE_END;
}
// ********** End Class UGameplayTagsToolset Function RemoveTag ************************************

// ********** Begin Class UGameplayTagsToolset Function RenameTag **********************************
struct Z_Construct_UFunction_UGameplayTagsToolset_RenameTag_Statics
{
	struct GameplayTagsToolset_eventRenameTag_Parms
	{
		FString OldTagName;
		FString NewTagName;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "GameplayTags" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Renames a gameplay tag, updating all references in the project.\n\x09 * This should ONLY be called after getting explicit direction or permission from the user.\n\x09 * @param OldTagName The fully-qualified name of the tag to rename.\n\x09 * @param NewTagName The new fully-qualified name for the tag.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/GameplayTagsToolset/GameplayTagsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Renames a gameplay tag, updating all references in the project.\nThis should ONLY be called after getting explicit direction or permission from the user.\n@param OldTagName The fully-qualified name of the tag to rename.\n@param NewTagName The new fully-qualified name for the tag." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OldTagName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewTagName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RenameTag constinit property declarations *****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_OldTagName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_NewTagName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RenameTag constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RenameTag Property Definitions ****************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameplayTagsToolset_RenameTag_Statics::NewProp_OldTagName = { "OldTagName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayTagsToolset_eventRenameTag_Parms, OldTagName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OldTagName_MetaData), NewProp_OldTagName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameplayTagsToolset_RenameTag_Statics::NewProp_NewTagName = { "NewTagName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayTagsToolset_eventRenameTag_Parms, NewTagName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewTagName_MetaData), NewProp_NewTagName_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameplayTagsToolset_RenameTag_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayTagsToolset_RenameTag_Statics::NewProp_OldTagName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayTagsToolset_RenameTag_Statics::NewProp_NewTagName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayTagsToolset_RenameTag_Statics::PropPointers) < 2048);
// ********** End Function RenameTag Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameplayTagsToolset_RenameTag_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGameplayTagsToolset, nullptr, "RenameTag", 	Z_Construct_UFunction_UGameplayTagsToolset_RenameTag_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayTagsToolset_RenameTag_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGameplayTagsToolset_RenameTag_Statics::GameplayTagsToolset_eventRenameTag_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayTagsToolset_RenameTag_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameplayTagsToolset_RenameTag_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGameplayTagsToolset_RenameTag_Statics::GameplayTagsToolset_eventRenameTag_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGameplayTagsToolset_RenameTag()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameplayTagsToolset_RenameTag_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGameplayTagsToolset::execRenameTag)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_OldTagName);
	P_GET_PROPERTY(FStrProperty,Z_Param_NewTagName);
	P_FINISH;
	P_NATIVE_BEGIN;
	UGameplayTagsToolset::RenameTag(Z_Param_OldTagName,Z_Param_NewTagName);
	P_NATIVE_END;
}
// ********** End Class UGameplayTagsToolset Function RenameTag ************************************

// ********** Begin Class UGameplayTagsToolset *****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UGameplayTagsToolset;
UClass* UGameplayTagsToolset::GetPrivateStaticClass()
{
	using TClass = UGameplayTagsToolset;
	if (!Z_Registration_Info_UClass_UGameplayTagsToolset.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("GameplayTagsToolset"),
			Z_Registration_Info_UClass_UGameplayTagsToolset.InnerSingleton,
			StaticRegisterNativesUGameplayTagsToolset,
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
	return Z_Registration_Info_UClass_UGameplayTagsToolset.InnerSingleton;
}
UClass* Z_Construct_UClass_UGameplayTagsToolset_NoRegister()
{
	return UGameplayTagsToolset::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UGameplayTagsToolset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Provides tools for reading and managing gameplay tags in the project's GameplayTagsManager.\n" },
#endif
		{ "IncludePath", "GameplayTagsToolset/GameplayTagsToolset.h" },
		{ "ModuleRelativePath", "Private/GameplayTagsToolset/GameplayTagsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Provides tools for reading and managing gameplay tags in the project's GameplayTagsManager." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UGameplayTagsToolset constinit property declarations *********************
// ********** End Class UGameplayTagsToolset constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AddTag"), .Pointer = &UGameplayTagsToolset::execAddTag },
		{ .NameUTF8 = UTF8TEXT("FindReferencersByTag"), .Pointer = &UGameplayTagsToolset::execFindReferencersByTag },
		{ .NameUTF8 = UTF8TEXT("GetTagInfo"), .Pointer = &UGameplayTagsToolset::execGetTagInfo },
		{ .NameUTF8 = UTF8TEXT("ListTags"), .Pointer = &UGameplayTagsToolset::execListTags },
		{ .NameUTF8 = UTF8TEXT("RemoveTag"), .Pointer = &UGameplayTagsToolset::execRemoveTag },
		{ .NameUTF8 = UTF8TEXT("RenameTag"), .Pointer = &UGameplayTagsToolset::execRenameTag },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UGameplayTagsToolset_AddTag, "AddTag" }, // 1673505818
		{ &Z_Construct_UFunction_UGameplayTagsToolset_FindReferencersByTag, "FindReferencersByTag" }, // 2476185153
		{ &Z_Construct_UFunction_UGameplayTagsToolset_GetTagInfo, "GetTagInfo" }, // 3949679771
		{ &Z_Construct_UFunction_UGameplayTagsToolset_ListTags, "ListTags" }, // 3569149317
		{ &Z_Construct_UFunction_UGameplayTagsToolset_RemoveTag, "RemoveTag" }, // 506238770
		{ &Z_Construct_UFunction_UGameplayTagsToolset_RenameTag, "RenameTag" }, // 1793250553
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameplayTagsToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UGameplayTagsToolset_Statics
UObject* (*const Z_Construct_UClass_UGameplayTagsToolset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UToolsetDefinition,
	(UObject* (*)())Z_Construct_UPackage__Script_GameplayTagsToolset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGameplayTagsToolset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGameplayTagsToolset_Statics::ClassParams = {
	&UGameplayTagsToolset::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGameplayTagsToolset_Statics::Class_MetaDataParams), Z_Construct_UClass_UGameplayTagsToolset_Statics::Class_MetaDataParams)
};
void UGameplayTagsToolset::StaticRegisterNativesUGameplayTagsToolset()
{
	UClass* Class = UGameplayTagsToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UGameplayTagsToolset_Statics::Funcs));
}
UClass* Z_Construct_UClass_UGameplayTagsToolset()
{
	if (!Z_Registration_Info_UClass_UGameplayTagsToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGameplayTagsToolset.OuterSingleton, Z_Construct_UClass_UGameplayTagsToolset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGameplayTagsToolset.OuterSingleton;
}
UGameplayTagsToolset::UGameplayTagsToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UGameplayTagsToolset);
UGameplayTagsToolset::~UGameplayTagsToolset() {}
// ********** End Class UGameplayTagsToolset *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GameplayTagsToolset_Source_GameplayTagsToolset_Private_GameplayTagsToolset_GameplayTagsToolset_h__Script_GameplayTagsToolset_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FGameplayTagInfo::StaticStruct, Z_Construct_UScriptStruct_FGameplayTagInfo_Statics::NewStructOps, TEXT("GameplayTagInfo"),&Z_Registration_Info_UScriptStruct_FGameplayTagInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGameplayTagInfo), 3546409351U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGameplayTagsToolset, UGameplayTagsToolset::StaticClass, TEXT("UGameplayTagsToolset"), &Z_Registration_Info_UClass_UGameplayTagsToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGameplayTagsToolset), 3659864546U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GameplayTagsToolset_Source_GameplayTagsToolset_Private_GameplayTagsToolset_GameplayTagsToolset_h__Script_GameplayTagsToolset_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GameplayTagsToolset_Source_GameplayTagsToolset_Private_GameplayTagsToolset_GameplayTagsToolset_h__Script_GameplayTagsToolset_1388366359{
	TEXT("/Script/GameplayTagsToolset"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GameplayTagsToolset_Source_GameplayTagsToolset_Private_GameplayTagsToolset_GameplayTagsToolset_h__Script_GameplayTagsToolset_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GameplayTagsToolset_Source_GameplayTagsToolset_Private_GameplayTagsToolset_GameplayTagsToolset_h__Script_GameplayTagsToolset_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GameplayTagsToolset_Source_GameplayTagsToolset_Private_GameplayTagsToolset_GameplayTagsToolset_h__Script_GameplayTagsToolset_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GameplayTagsToolset_Source_GameplayTagsToolset_Private_GameplayTagsToolset_GameplayTagsToolset_h__Script_GameplayTagsToolset_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
