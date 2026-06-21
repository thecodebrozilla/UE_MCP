// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Data/InstancedStructMap.h"
#include "StructUtils/InstancedStruct.h"
#include "UObject/SoftObjectPath.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeInstancedStructMap() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FInstancedStruct();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FSoftObjectPath();
FILESANDBOXCORE_API UScriptStruct* Z_Construct_UScriptStruct_FFileSandboxCore_InstancedStructMap();
UPackage* Z_Construct_UPackage__Script_FileSandboxCore();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FFileSandboxCore_InstancedStructMap *******************************
struct Z_Construct_UScriptStruct_FFileSandboxCore_InstancedStructMap_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FFileSandboxCore_InstancedStructMap); }
	static inline consteval int16 GetStructAlignment() { return alignof(FFileSandboxCore_InstancedStructMap); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Advanced tagging structure. Each USTRUCT() can be added at most once. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/InstancedStructMap.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Advanced tagging structure. Each USTRUCT() can be added at most once." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Data_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/InstancedStructMap.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FFileSandboxCore_InstancedStructMap constinit property declarations 
	static const UECodeGen_Private::FStructPropertyParams NewProp_Data_ValueProp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Data_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_Data;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FFileSandboxCore_InstancedStructMap constinit property declarations *
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFileSandboxCore_InstancedStructMap>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FFileSandboxCore_InstancedStructMap_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FFileSandboxCore_InstancedStructMap;
class UScriptStruct* FFileSandboxCore_InstancedStructMap::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FFileSandboxCore_InstancedStructMap.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FFileSandboxCore_InstancedStructMap.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FFileSandboxCore_InstancedStructMap, (UObject*)Z_Construct_UPackage__Script_FileSandboxCore(), TEXT("FileSandboxCore_InstancedStructMap"));
	}
	return Z_Registration_Info_UScriptStruct_FFileSandboxCore_InstancedStructMap.OuterSingleton;
	}

// ********** Begin ScriptStruct FFileSandboxCore_InstancedStructMap Property Definitions **********
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_InstancedStructMap_Statics::NewProp_Data_ValueProp = { "Data", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FInstancedStruct, METADATA_PARAMS(0, nullptr) }; // 3949785911
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_InstancedStructMap_Statics::NewProp_Data_Key_KeyProp = { "Data_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FSoftObjectPath, METADATA_PARAMS(0, nullptr) }; // 2425717601
const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_InstancedStructMap_Statics::NewProp_Data = { "Data", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFileSandboxCore_InstancedStructMap, Data), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Data_MetaData), NewProp_Data_MetaData) }; // 2425717601 3949785911
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FFileSandboxCore_InstancedStructMap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_InstancedStructMap_Statics::NewProp_Data_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_InstancedStructMap_Statics::NewProp_Data_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_InstancedStructMap_Statics::NewProp_Data,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_InstancedStructMap_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FFileSandboxCore_InstancedStructMap Property Definitions ************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFileSandboxCore_InstancedStructMap_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_FileSandboxCore,
	nullptr,
	&NewStructOps,
	"FileSandboxCore_InstancedStructMap",
	Z_Construct_UScriptStruct_FFileSandboxCore_InstancedStructMap_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_InstancedStructMap_Statics::PropPointers),
	sizeof(FFileSandboxCore_InstancedStructMap),
	alignof(FFileSandboxCore_InstancedStructMap),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_InstancedStructMap_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FFileSandboxCore_InstancedStructMap_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FFileSandboxCore_InstancedStructMap()
{
	if (!Z_Registration_Info_UScriptStruct_FFileSandboxCore_InstancedStructMap.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FFileSandboxCore_InstancedStructMap.InnerSingleton, Z_Construct_UScriptStruct_FFileSandboxCore_InstancedStructMap_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FFileSandboxCore_InstancedStructMap.InnerSingleton);
}
// ********** End ScriptStruct FFileSandboxCore_InstancedStructMap *********************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Public_Data_InstancedStructMap_h__Script_FileSandboxCore_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FFileSandboxCore_InstancedStructMap::StaticStruct, Z_Construct_UScriptStruct_FFileSandboxCore_InstancedStructMap_Statics::NewStructOps, TEXT("FileSandboxCore_InstancedStructMap"),&Z_Registration_Info_UScriptStruct_FFileSandboxCore_InstancedStructMap, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FFileSandboxCore_InstancedStructMap), 3882689963U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Public_Data_InstancedStructMap_h__Script_FileSandboxCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Public_Data_InstancedStructMap_h__Script_FileSandboxCore_661233826{
	TEXT("/Script/FileSandboxCore"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Public_Data_InstancedStructMap_h__Script_FileSandboxCore_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Public_Data_InstancedStructMap_h__Script_FileSandboxCore_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
