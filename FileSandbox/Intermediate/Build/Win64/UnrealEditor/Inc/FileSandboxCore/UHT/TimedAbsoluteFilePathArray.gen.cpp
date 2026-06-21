// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Data/TimedAbsoluteFilePathArray.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeTimedAbsoluteFilePathArray() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
FILESANDBOXCORE_API UScriptStruct* Z_Construct_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray();
UPackage* Z_Construct_UPackage__Script_FileSandboxCore();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FFileSandboxCore_TimedAbsoluteFilePathArray ***********************
struct Z_Construct_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FFileSandboxCore_TimedAbsoluteFilePathArray); }
	static inline consteval int16 GetStructAlignment() { return alignof(FFileSandboxCore_TimedAbsoluteFilePathArray); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Keeps an array of absolute file paths and their respective timestamps. Each path is unique. */" },
#endif
		{ "ModuleRelativePath", "Private/Data/TimedAbsoluteFilePathArray.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Keeps an array of absolute file paths and their respective timestamps. Each path is unique." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Files_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Absolute file paths. */" },
#endif
		{ "ModuleRelativePath", "Private/Data/TimedAbsoluteFilePathArray.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Absolute file paths." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Timestamps_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * The times that the files were changed in local time. \n\x09 * \n\x09 * Under normal circumstances, this is equal length to Files.\n\x09 * Keep in mind that the user may have edited the file in the manifest, in which case the values in this array are useless.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/Data/TimedAbsoluteFilePathArray.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The times that the files were changed in local time.\n\nUnder normal circumstances, this is equal length to Files.\nKeep in mind that the user may have edited the file in the manifest, in which case the values in this array are useless." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FFileSandboxCore_TimedAbsoluteFilePathArray constinit property declarations 
	static const UECodeGen_Private::FStrPropertyParams NewProp_Files_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Files;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Timestamps_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Timestamps;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FFileSandboxCore_TimedAbsoluteFilePathArray constinit property declarations 
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFileSandboxCore_TimedAbsoluteFilePathArray>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray;
class UScriptStruct* FFileSandboxCore_TimedAbsoluteFilePathArray::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray, (UObject*)Z_Construct_UPackage__Script_FileSandboxCore(), TEXT("FileSandboxCore_TimedAbsoluteFilePathArray"));
	}
	return Z_Registration_Info_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray.OuterSingleton;
	}

// ********** Begin ScriptStruct FFileSandboxCore_TimedAbsoluteFilePathArray Property Definitions **
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray_Statics::NewProp_Files_Inner = { "Files", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray_Statics::NewProp_Files = { "Files", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFileSandboxCore_TimedAbsoluteFilePathArray, Files), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Files_MetaData), NewProp_Files_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray_Statics::NewProp_Timestamps_Inner = { "Timestamps", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray_Statics::NewProp_Timestamps = { "Timestamps", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFileSandboxCore_TimedAbsoluteFilePathArray, Timestamps), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Timestamps_MetaData), NewProp_Timestamps_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray_Statics::NewProp_Files_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray_Statics::NewProp_Files,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray_Statics::NewProp_Timestamps_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray_Statics::NewProp_Timestamps,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FFileSandboxCore_TimedAbsoluteFilePathArray Property Definitions ****
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_FileSandboxCore,
	nullptr,
	&NewStructOps,
	"FileSandboxCore_TimedAbsoluteFilePathArray",
	Z_Construct_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray_Statics::PropPointers),
	sizeof(FFileSandboxCore_TimedAbsoluteFilePathArray),
	alignof(FFileSandboxCore_TimedAbsoluteFilePathArray),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray()
{
	if (!Z_Registration_Info_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray.InnerSingleton, Z_Construct_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray.InnerSingleton);
}
// ********** End ScriptStruct FFileSandboxCore_TimedAbsoluteFilePathArray *************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Private_Data_TimedAbsoluteFilePathArray_h__Script_FileSandboxCore_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FFileSandboxCore_TimedAbsoluteFilePathArray::StaticStruct, Z_Construct_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray_Statics::NewStructOps, TEXT("FileSandboxCore_TimedAbsoluteFilePathArray"),&Z_Registration_Info_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FFileSandboxCore_TimedAbsoluteFilePathArray), 3450424683U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Private_Data_TimedAbsoluteFilePathArray_h__Script_FileSandboxCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Private_Data_TimedAbsoluteFilePathArray_h__Script_FileSandboxCore_3926776840{
	TEXT("/Script/FileSandboxCore"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Private_Data_TimedAbsoluteFilePathArray_h__Script_FileSandboxCore_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Private_Data_TimedAbsoluteFilePathArray_h__Script_FileSandboxCore_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
