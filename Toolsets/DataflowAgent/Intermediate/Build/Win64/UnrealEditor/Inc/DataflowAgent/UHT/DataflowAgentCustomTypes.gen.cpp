// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DataflowAgentCustomTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeDataflowAgentCustomTypes() {}

// ********** Begin Cross Module References ********************************************************
DATAFLOWAGENT_API UScriptStruct* Z_Construct_UScriptStruct_FDataflowConnectionInfo();
DATAFLOWAGENT_API UScriptStruct* Z_Construct_UScriptStruct_FDataflowNodeInfo();
UPackage* Z_Construct_UPackage__Script_DataflowAgent();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FDataflowNodeInfo *************************************************
struct Z_Construct_UScriptStruct_FDataflowNodeInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FDataflowNodeInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDataflowNodeInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Basic info about a Dataflow node returned by GetNodeInfo */" },
#endif
		{ "ModuleRelativePath", "Public/DataflowAgentCustomTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Basic info about a Dataflow node returned by GetNodeInfo" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "Dataflow" },
		{ "ModuleRelativePath", "Public/DataflowAgentCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TypeName_MetaData[] = {
		{ "Category", "Dataflow" },
		{ "ModuleRelativePath", "Public/DataflowAgentCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PosX_MetaData[] = {
		{ "Category", "Dataflow" },
		{ "ModuleRelativePath", "Public/DataflowAgentCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PosY_MetaData[] = {
		{ "Category", "Dataflow" },
		{ "ModuleRelativePath", "Public/DataflowAgentCustomTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDataflowNodeInfo constinit property declarations *****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TypeName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_PosX;
	static const UECodeGen_Private::FIntPropertyParams NewProp_PosY;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDataflowNodeInfo constinit property declarations *******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDataflowNodeInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FDataflowNodeInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDataflowNodeInfo;
class UScriptStruct* FDataflowNodeInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDataflowNodeInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDataflowNodeInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDataflowNodeInfo, (UObject*)Z_Construct_UPackage__Script_DataflowAgent(), TEXT("DataflowNodeInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FDataflowNodeInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FDataflowNodeInfo Property Definitions ****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDataflowNodeInfo_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDataflowNodeInfo, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDataflowNodeInfo_Statics::NewProp_TypeName = { "TypeName", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDataflowNodeInfo, TypeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TypeName_MetaData), NewProp_TypeName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDataflowNodeInfo_Statics::NewProp_PosX = { "PosX", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDataflowNodeInfo, PosX), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PosX_MetaData), NewProp_PosX_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDataflowNodeInfo_Statics::NewProp_PosY = { "PosY", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDataflowNodeInfo, PosY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PosY_MetaData), NewProp_PosY_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDataflowNodeInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDataflowNodeInfo_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDataflowNodeInfo_Statics::NewProp_TypeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDataflowNodeInfo_Statics::NewProp_PosX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDataflowNodeInfo_Statics::NewProp_PosY,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDataflowNodeInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FDataflowNodeInfo Property Definitions ******************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDataflowNodeInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_DataflowAgent,
	nullptr,
	&NewStructOps,
	"DataflowNodeInfo",
	Z_Construct_UScriptStruct_FDataflowNodeInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDataflowNodeInfo_Statics::PropPointers),
	sizeof(FDataflowNodeInfo),
	alignof(FDataflowNodeInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDataflowNodeInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDataflowNodeInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDataflowNodeInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FDataflowNodeInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDataflowNodeInfo.InnerSingleton, Z_Construct_UScriptStruct_FDataflowNodeInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDataflowNodeInfo.InnerSingleton);
}
// ********** End ScriptStruct FDataflowNodeInfo ***************************************************

// ********** Begin ScriptStruct FDataflowConnectionInfo *******************************************
struct Z_Construct_UScriptStruct_FDataflowConnectionInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FDataflowConnectionInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDataflowConnectionInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Describes one end of a connection in a Dataflow graph */" },
#endif
		{ "ModuleRelativePath", "Public/DataflowAgentCustomTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Describes one end of a connection in a Dataflow graph" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NodeName_MetaData[] = {
		{ "Category", "Dataflow" },
		{ "ModuleRelativePath", "Public/DataflowAgentCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PinName_MetaData[] = {
		{ "Category", "Dataflow" },
		{ "ModuleRelativePath", "Public/DataflowAgentCustomTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDataflowConnectionInfo constinit property declarations ***********
	static const UECodeGen_Private::FStrPropertyParams NewProp_NodeName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_PinName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDataflowConnectionInfo constinit property declarations *************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDataflowConnectionInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FDataflowConnectionInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDataflowConnectionInfo;
class UScriptStruct* FDataflowConnectionInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDataflowConnectionInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDataflowConnectionInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDataflowConnectionInfo, (UObject*)Z_Construct_UPackage__Script_DataflowAgent(), TEXT("DataflowConnectionInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FDataflowConnectionInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FDataflowConnectionInfo Property Definitions **********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDataflowConnectionInfo_Statics::NewProp_NodeName = { "NodeName", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDataflowConnectionInfo, NodeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NodeName_MetaData), NewProp_NodeName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDataflowConnectionInfo_Statics::NewProp_PinName = { "PinName", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDataflowConnectionInfo, PinName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PinName_MetaData), NewProp_PinName_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDataflowConnectionInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDataflowConnectionInfo_Statics::NewProp_NodeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDataflowConnectionInfo_Statics::NewProp_PinName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDataflowConnectionInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FDataflowConnectionInfo Property Definitions ************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDataflowConnectionInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_DataflowAgent,
	nullptr,
	&NewStructOps,
	"DataflowConnectionInfo",
	Z_Construct_UScriptStruct_FDataflowConnectionInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDataflowConnectionInfo_Statics::PropPointers),
	sizeof(FDataflowConnectionInfo),
	alignof(FDataflowConnectionInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDataflowConnectionInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDataflowConnectionInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDataflowConnectionInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FDataflowConnectionInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDataflowConnectionInfo.InnerSingleton, Z_Construct_UScriptStruct_FDataflowConnectionInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDataflowConnectionInfo.InnerSingleton);
}
// ********** End ScriptStruct FDataflowConnectionInfo *********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_DataflowAgent_Source_DataflowAgent_Public_DataflowAgentCustomTypes_h__Script_DataflowAgent_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FDataflowNodeInfo::StaticStruct, Z_Construct_UScriptStruct_FDataflowNodeInfo_Statics::NewStructOps, TEXT("DataflowNodeInfo"),&Z_Registration_Info_UScriptStruct_FDataflowNodeInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDataflowNodeInfo), 429722934U) },
		{ FDataflowConnectionInfo::StaticStruct, Z_Construct_UScriptStruct_FDataflowConnectionInfo_Statics::NewStructOps, TEXT("DataflowConnectionInfo"),&Z_Registration_Info_UScriptStruct_FDataflowConnectionInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDataflowConnectionInfo), 269773907U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_DataflowAgent_Source_DataflowAgent_Public_DataflowAgentCustomTypes_h__Script_DataflowAgent_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_DataflowAgent_Source_DataflowAgent_Public_DataflowAgentCustomTypes_h__Script_DataflowAgent_3584072919{
	TEXT("/Script/DataflowAgent"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_DataflowAgent_Source_DataflowAgent_Public_DataflowAgentCustomTypes_h__Script_DataflowAgent_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_DataflowAgent_Source_DataflowAgent_Public_DataflowAgentCustomTypes_h__Script_DataflowAgent_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
