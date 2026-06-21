// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Data/AbsoluteFilePathArray.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeAbsoluteFilePathArray() {}

// ********** Begin Cross Module References ********************************************************
FILESANDBOXCORE_API UScriptStruct* Z_Construct_UScriptStruct_FFileSandboxCore_AbsoluteFilePathArray();
UPackage* Z_Construct_UPackage__Script_FileSandboxCore();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FFileSandboxCore_AbsoluteFilePathArray ****************************
struct Z_Construct_UScriptStruct_FFileSandboxCore_AbsoluteFilePathArray_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FFileSandboxCore_AbsoluteFilePathArray); }
	static inline consteval int16 GetStructAlignment() { return alignof(FFileSandboxCore_AbsoluteFilePathArray); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Keeps an array of absolute file paths. Each path is unique. */" },
#endif
		{ "ModuleRelativePath", "Private/Data/AbsoluteFilePathArray.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Keeps an array of absolute file paths. Each path is unique." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Files_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Absolute file paths. */" },
#endif
		{ "ModuleRelativePath", "Private/Data/AbsoluteFilePathArray.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Absolute file paths." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FFileSandboxCore_AbsoluteFilePathArray constinit property declarations 
	static const UECodeGen_Private::FStrPropertyParams NewProp_Files_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Files;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FFileSandboxCore_AbsoluteFilePathArray constinit property declarations 
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFileSandboxCore_AbsoluteFilePathArray>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FFileSandboxCore_AbsoluteFilePathArray_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FFileSandboxCore_AbsoluteFilePathArray;
class UScriptStruct* FFileSandboxCore_AbsoluteFilePathArray::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FFileSandboxCore_AbsoluteFilePathArray.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FFileSandboxCore_AbsoluteFilePathArray.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FFileSandboxCore_AbsoluteFilePathArray, (UObject*)Z_Construct_UPackage__Script_FileSandboxCore(), TEXT("FileSandboxCore_AbsoluteFilePathArray"));
	}
	return Z_Registration_Info_UScriptStruct_FFileSandboxCore_AbsoluteFilePathArray.OuterSingleton;
	}

// ********** Begin ScriptStruct FFileSandboxCore_AbsoluteFilePathArray Property Definitions *******
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_AbsoluteFilePathArray_Statics::NewProp_Files_Inner = { "Files", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_AbsoluteFilePathArray_Statics::NewProp_Files = { "Files", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFileSandboxCore_AbsoluteFilePathArray, Files), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Files_MetaData), NewProp_Files_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FFileSandboxCore_AbsoluteFilePathArray_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_AbsoluteFilePathArray_Statics::NewProp_Files_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_AbsoluteFilePathArray_Statics::NewProp_Files,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_AbsoluteFilePathArray_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FFileSandboxCore_AbsoluteFilePathArray Property Definitions *********
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFileSandboxCore_AbsoluteFilePathArray_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_FileSandboxCore,
	nullptr,
	&NewStructOps,
	"FileSandboxCore_AbsoluteFilePathArray",
	Z_Construct_UScriptStruct_FFileSandboxCore_AbsoluteFilePathArray_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_AbsoluteFilePathArray_Statics::PropPointers),
	sizeof(FFileSandboxCore_AbsoluteFilePathArray),
	alignof(FFileSandboxCore_AbsoluteFilePathArray),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_AbsoluteFilePathArray_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FFileSandboxCore_AbsoluteFilePathArray_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FFileSandboxCore_AbsoluteFilePathArray()
{
	if (!Z_Registration_Info_UScriptStruct_FFileSandboxCore_AbsoluteFilePathArray.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FFileSandboxCore_AbsoluteFilePathArray.InnerSingleton, Z_Construct_UScriptStruct_FFileSandboxCore_AbsoluteFilePathArray_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FFileSandboxCore_AbsoluteFilePathArray.InnerSingleton);
}
// ********** End ScriptStruct FFileSandboxCore_AbsoluteFilePathArray ******************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Private_Data_AbsoluteFilePathArray_h__Script_FileSandboxCore_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FFileSandboxCore_AbsoluteFilePathArray::StaticStruct, Z_Construct_UScriptStruct_FFileSandboxCore_AbsoluteFilePathArray_Statics::NewStructOps, TEXT("FileSandboxCore_AbsoluteFilePathArray"),&Z_Registration_Info_UScriptStruct_FFileSandboxCore_AbsoluteFilePathArray, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FFileSandboxCore_AbsoluteFilePathArray), 1892007055U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Private_Data_AbsoluteFilePathArray_h__Script_FileSandboxCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Private_Data_AbsoluteFilePathArray_h__Script_FileSandboxCore_3036912481{
	TEXT("/Script/FileSandboxCore"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Private_Data_AbsoluteFilePathArray_h__Script_FileSandboxCore_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Private_Data_AbsoluteFilePathArray_h__Script_FileSandboxCore_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
