// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ToolsetRegistry/ReferenceConverter.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeReferenceConverter() {}

// ********** Begin Cross Module References ********************************************************
TOOLSETREGISTRY_API UScriptStruct* Z_Construct_UScriptStruct_FToolsetReference();
UPackage* Z_Construct_UPackage__Script_ToolsetRegistry();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FToolsetReference *************************************************
struct Z_Construct_UScriptStruct_FToolsetReference_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FToolsetReference); }
	static inline consteval int16 GetStructAlignment() { return alignof(FToolsetReference); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Represents a reference to a UObject or UClass.\n" },
#endif
		{ "ModuleRelativePath", "Private/ToolsetRegistry/ReferenceConverter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Represents a reference to a UObject or UClass." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RefPath_MetaData[] = {
		{ "Category", "Toolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The reference stored as a soft path string.\n" },
#endif
		{ "ModuleRelativePath", "Private/ToolsetRegistry/ReferenceConverter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The reference stored as a soft path string." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FToolsetReference constinit property declarations *****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_RefPath;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FToolsetReference constinit property declarations *******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FToolsetReference>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FToolsetReference_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FToolsetReference;
class UScriptStruct* FToolsetReference::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FToolsetReference.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FToolsetReference.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FToolsetReference, (UObject*)Z_Construct_UPackage__Script_ToolsetRegistry(), TEXT("ToolsetReference"));
	}
	return Z_Registration_Info_UScriptStruct_FToolsetReference.OuterSingleton;
	}

// ********** Begin ScriptStruct FToolsetReference Property Definitions ****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FToolsetReference_Statics::NewProp_RefPath = { "RefPath", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FToolsetReference, RefPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RefPath_MetaData), NewProp_RefPath_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FToolsetReference_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FToolsetReference_Statics::NewProp_RefPath,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FToolsetReference_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FToolsetReference Property Definitions ******************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FToolsetReference_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ToolsetRegistry,
	nullptr,
	&NewStructOps,
	"ToolsetReference",
	Z_Construct_UScriptStruct_FToolsetReference_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FToolsetReference_Statics::PropPointers),
	sizeof(FToolsetReference),
	alignof(FToolsetReference),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FToolsetReference_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FToolsetReference_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FToolsetReference()
{
	if (!Z_Registration_Info_UScriptStruct_FToolsetReference.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FToolsetReference.InnerSingleton, Z_Construct_UScriptStruct_FToolsetReference_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FToolsetReference.InnerSingleton);
}
// ********** End ScriptStruct FToolsetReference ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Private_ToolsetRegistry_ReferenceConverter_h__Script_ToolsetRegistry_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FToolsetReference::StaticStruct, Z_Construct_UScriptStruct_FToolsetReference_Statics::NewStructOps, TEXT("ToolsetReference"),&Z_Registration_Info_UScriptStruct_FToolsetReference, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FToolsetReference), 1318453915U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Private_ToolsetRegistry_ReferenceConverter_h__Script_ToolsetRegistry_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Private_ToolsetRegistry_ReferenceConverter_h__Script_ToolsetRegistry_224211867{
	TEXT("/Script/ToolsetRegistry"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Private_ToolsetRegistry_ReferenceConverter_h__Script_ToolsetRegistry_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Private_ToolsetRegistry_ReferenceConverter_h__Script_ToolsetRegistry_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
