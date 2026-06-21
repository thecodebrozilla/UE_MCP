// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Data/SandboxMetaData.h"
#include "Data/InstancedStructMap.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSandboxMetaData() {}

// ********** Begin Cross Module References ********************************************************
FILESANDBOXCORE_API UScriptStruct* Z_Construct_UScriptStruct_FFileSandboxCore_InstancedStructMap();
FILESANDBOXCORE_API UScriptStruct* Z_Construct_UScriptStruct_FFileSandboxCore_SandboxMetaData();
UPackage* Z_Construct_UPackage__Script_FileSandboxCore();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FFileSandboxCore_SandboxMetaData **********************************
struct Z_Construct_UScriptStruct_FFileSandboxCore_SandboxMetaData_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FFileSandboxCore_SandboxMetaData); }
	static inline consteval int16 GetStructAlignment() { return alignof(FFileSandboxCore_SandboxMetaData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Metadata about a sandbox. This data is not needed for operations of the sandbox itself and is intended to be useful for external systems. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/SandboxMetaData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Metadata about a sandbox. This data is not needed for operations of the sandbox itself and is intended to be useful for external systems." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Name of this sandbox, usually provided by the user. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/SandboxMetaData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Name of this sandbox, usually provided by the user." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Description of this sandbox, usually provided by the user. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/SandboxMetaData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Description of this sandbox, usually provided by the user." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Tags_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Custom tags that may have been added to this sandbox. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/SandboxMetaData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Custom tags that may have been added to this sandbox." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CustomData_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Custom advanced data that may have been added to this sandbox. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/SandboxMetaData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Custom advanced data that may have been added to this sandbox." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FFileSandboxCore_SandboxMetaData constinit property declarations **
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Description;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Tags_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Tags;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CustomData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FFileSandboxCore_SandboxMetaData constinit property declarations ****
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFileSandboxCore_SandboxMetaData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FFileSandboxCore_SandboxMetaData_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FFileSandboxCore_SandboxMetaData;
class UScriptStruct* FFileSandboxCore_SandboxMetaData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FFileSandboxCore_SandboxMetaData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FFileSandboxCore_SandboxMetaData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FFileSandboxCore_SandboxMetaData, (UObject*)Z_Construct_UPackage__Script_FileSandboxCore(), TEXT("FileSandboxCore_SandboxMetaData"));
	}
	return Z_Registration_Info_UScriptStruct_FFileSandboxCore_SandboxMetaData.OuterSingleton;
	}

// ********** Begin ScriptStruct FFileSandboxCore_SandboxMetaData Property Definitions *************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_SandboxMetaData_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFileSandboxCore_SandboxMetaData, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_SandboxMetaData_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFileSandboxCore_SandboxMetaData, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_SandboxMetaData_Statics::NewProp_Tags_Inner = { "Tags", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_SandboxMetaData_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFileSandboxCore_SandboxMetaData, Tags), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Tags_MetaData), NewProp_Tags_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_SandboxMetaData_Statics::NewProp_CustomData = { "CustomData", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFileSandboxCore_SandboxMetaData, CustomData), Z_Construct_UScriptStruct_FFileSandboxCore_InstancedStructMap, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CustomData_MetaData), NewProp_CustomData_MetaData) }; // 3882689963
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FFileSandboxCore_SandboxMetaData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_SandboxMetaData_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_SandboxMetaData_Statics::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_SandboxMetaData_Statics::NewProp_Tags_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_SandboxMetaData_Statics::NewProp_Tags,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_SandboxMetaData_Statics::NewProp_CustomData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_SandboxMetaData_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FFileSandboxCore_SandboxMetaData Property Definitions ***************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFileSandboxCore_SandboxMetaData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_FileSandboxCore,
	nullptr,
	&NewStructOps,
	"FileSandboxCore_SandboxMetaData",
	Z_Construct_UScriptStruct_FFileSandboxCore_SandboxMetaData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_SandboxMetaData_Statics::PropPointers),
	sizeof(FFileSandboxCore_SandboxMetaData),
	alignof(FFileSandboxCore_SandboxMetaData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_SandboxMetaData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FFileSandboxCore_SandboxMetaData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FFileSandboxCore_SandboxMetaData()
{
	if (!Z_Registration_Info_UScriptStruct_FFileSandboxCore_SandboxMetaData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FFileSandboxCore_SandboxMetaData.InnerSingleton, Z_Construct_UScriptStruct_FFileSandboxCore_SandboxMetaData_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FFileSandboxCore_SandboxMetaData.InnerSingleton);
}
// ********** End ScriptStruct FFileSandboxCore_SandboxMetaData ************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Public_Data_SandboxMetaData_h__Script_FileSandboxCore_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FFileSandboxCore_SandboxMetaData::StaticStruct, Z_Construct_UScriptStruct_FFileSandboxCore_SandboxMetaData_Statics::NewStructOps, TEXT("FileSandboxCore_SandboxMetaData"),&Z_Registration_Info_UScriptStruct_FFileSandboxCore_SandboxMetaData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FFileSandboxCore_SandboxMetaData), 3176896455U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Public_Data_SandboxMetaData_h__Script_FileSandboxCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Public_Data_SandboxMetaData_h__Script_FileSandboxCore_2684269264{
	TEXT("/Script/FileSandboxCore"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Public_Data_SandboxMetaData_h__Script_FileSandboxCore_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Public_Data_SandboxMetaData_h__Script_FileSandboxCore_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
