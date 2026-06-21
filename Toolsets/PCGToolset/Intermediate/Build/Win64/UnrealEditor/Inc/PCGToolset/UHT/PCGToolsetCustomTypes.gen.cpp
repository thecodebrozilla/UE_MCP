// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PCGToolsetCustomTypes.h"
#include "StructUtils/PropertyBag.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodePCGToolsetCustomTypes() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UEnum* Z_Construct_UEnum_CoreUObject_EPropertyBagContainerType();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FInstancedPropertyBag();
PCG_API UClass* Z_Construct_UClass_APCGVolume_NoRegister();
PCG_API UClass* Z_Construct_UClass_UPCGGraph_NoRegister();
PCG_API UEnum* Z_Construct_UEnum_PCG_EPCGMetadataTypes();
PCGTOOLSET_API UClass* Z_Construct_UClass_UPCGExecuteGraphInstanceAsyncResult();
PCGTOOLSET_API UClass* Z_Construct_UClass_UPCGExecuteGraphInstanceAsyncResult_NoRegister();
PCGTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FPCGEdgeInfo();
PCGTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FPCGGraphInstanceInfo();
PCGTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FPCGGraphSchema();
PCGTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FPCGGraphStructure();
PCGTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FPCGNativeNodeSchema();
PCGTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FPCGNodeExecutionMessage();
PCGTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FPCGNodeInfo();
PCGTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FPCGParamDefinition();
PCGTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FPCGPinInfo();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolCallAsyncResult();
UPackage* Z_Construct_UPackage__Script_PCGToolset();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FPCGGraphInstanceInfo *********************************************
struct Z_Construct_UScriptStruct_FPCGGraphInstanceInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FPCGGraphInstanceInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FPCGGraphInstanceInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Actor_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Graph_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FPCGGraphInstanceInfo constinit property declarations *************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Graph;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FPCGGraphInstanceInfo constinit property declarations ***************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPCGGraphInstanceInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FPCGGraphInstanceInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FPCGGraphInstanceInfo;
class UScriptStruct* FPCGGraphInstanceInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FPCGGraphInstanceInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FPCGGraphInstanceInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPCGGraphInstanceInfo, (UObject*)Z_Construct_UPackage__Script_PCGToolset(), TEXT("PCGGraphInstanceInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FPCGGraphInstanceInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FPCGGraphInstanceInfo Property Definitions ************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FPCGGraphInstanceInfo_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0114000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGGraphInstanceInfo, Actor), Z_Construct_UClass_APCGVolume_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Actor_MetaData), NewProp_Actor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FPCGGraphInstanceInfo_Statics::NewProp_Graph = { "Graph", nullptr, (EPropertyFlags)0x0114000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGGraphInstanceInfo, Graph), Z_Construct_UClass_UPCGGraph_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Graph_MetaData), NewProp_Graph_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPCGGraphInstanceInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGGraphInstanceInfo_Statics::NewProp_Actor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGGraphInstanceInfo_Statics::NewProp_Graph,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCGGraphInstanceInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FPCGGraphInstanceInfo Property Definitions **************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPCGGraphInstanceInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_PCGToolset,
	nullptr,
	&NewStructOps,
	"PCGGraphInstanceInfo",
	Z_Construct_UScriptStruct_FPCGGraphInstanceInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCGGraphInstanceInfo_Statics::PropPointers),
	sizeof(FPCGGraphInstanceInfo),
	alignof(FPCGGraphInstanceInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCGGraphInstanceInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPCGGraphInstanceInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FPCGGraphInstanceInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FPCGGraphInstanceInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FPCGGraphInstanceInfo.InnerSingleton, Z_Construct_UScriptStruct_FPCGGraphInstanceInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FPCGGraphInstanceInfo.InnerSingleton);
}
// ********** End ScriptStruct FPCGGraphInstanceInfo ***********************************************

// ********** Begin ScriptStruct FPCGParamDefinition ***********************************************
struct Z_Construct_UScriptStruct_FPCGParamDefinition_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FPCGParamDefinition); }
	static inline consteval int16 GetStructAlignment() { return alignof(FPCGParamDefinition); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContainerType_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultValueJson_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FPCGParamDefinition constinit property declarations ***************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Name;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Type_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Type;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Description;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ContainerType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ContainerType;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DefaultValueJson;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FPCGParamDefinition constinit property declarations *****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPCGParamDefinition>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FPCGParamDefinition_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FPCGParamDefinition;
class UScriptStruct* FPCGParamDefinition::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FPCGParamDefinition.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FPCGParamDefinition.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPCGParamDefinition, (UObject*)Z_Construct_UPackage__Script_PCGToolset(), TEXT("PCGParamDefinition"));
	}
	return Z_Registration_Info_UScriptStruct_FPCGParamDefinition.OuterSingleton;
	}

// ********** Begin ScriptStruct FPCGParamDefinition Property Definitions **************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FPCGParamDefinition_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGParamDefinition, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FPCGParamDefinition_Statics::NewProp_Type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FPCGParamDefinition_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGParamDefinition, Type), Z_Construct_UEnum_PCG_EPCGMetadataTypes, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Type_MetaData), NewProp_Type_MetaData) }; // 77595749
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPCGParamDefinition_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGParamDefinition, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FPCGParamDefinition_Statics::NewProp_ContainerType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FPCGParamDefinition_Statics::NewProp_ContainerType = { "ContainerType", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGParamDefinition, ContainerType), Z_Construct_UEnum_CoreUObject_EPropertyBagContainerType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContainerType_MetaData), NewProp_ContainerType_MetaData) }; // 2448123157
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPCGParamDefinition_Statics::NewProp_DefaultValueJson = { "DefaultValueJson", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGParamDefinition, DefaultValueJson), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultValueJson_MetaData), NewProp_DefaultValueJson_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPCGParamDefinition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGParamDefinition_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGParamDefinition_Statics::NewProp_Type_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGParamDefinition_Statics::NewProp_Type,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGParamDefinition_Statics::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGParamDefinition_Statics::NewProp_ContainerType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGParamDefinition_Statics::NewProp_ContainerType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGParamDefinition_Statics::NewProp_DefaultValueJson,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCGParamDefinition_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FPCGParamDefinition Property Definitions ****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPCGParamDefinition_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_PCGToolset,
	nullptr,
	&NewStructOps,
	"PCGParamDefinition",
	Z_Construct_UScriptStruct_FPCGParamDefinition_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCGParamDefinition_Statics::PropPointers),
	sizeof(FPCGParamDefinition),
	alignof(FPCGParamDefinition),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCGParamDefinition_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPCGParamDefinition_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FPCGParamDefinition()
{
	if (!Z_Registration_Info_UScriptStruct_FPCGParamDefinition.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FPCGParamDefinition.InnerSingleton, Z_Construct_UScriptStruct_FPCGParamDefinition_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FPCGParamDefinition.InnerSingleton);
}
// ********** End ScriptStruct FPCGParamDefinition *************************************************

// ********** Begin ScriptStruct FPCGPinInfo *******************************************************
struct Z_Construct_UScriptStruct_FPCGPinInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FPCGPinInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FPCGPinInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FPCGPinInfo constinit property declarations ***********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Type;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Description;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FPCGPinInfo constinit property declarations *************************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPCGPinInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FPCGPinInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FPCGPinInfo;
class UScriptStruct* FPCGPinInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FPCGPinInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FPCGPinInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPCGPinInfo, (UObject*)Z_Construct_UPackage__Script_PCGToolset(), TEXT("PCGPinInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FPCGPinInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FPCGPinInfo Property Definitions **********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPCGPinInfo_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGPinInfo, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPCGPinInfo_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGPinInfo, Type), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Type_MetaData), NewProp_Type_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPCGPinInfo_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGPinInfo, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPCGPinInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGPinInfo_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGPinInfo_Statics::NewProp_Type,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGPinInfo_Statics::NewProp_Description,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCGPinInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FPCGPinInfo Property Definitions ************************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPCGPinInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_PCGToolset,
	nullptr,
	&NewStructOps,
	"PCGPinInfo",
	Z_Construct_UScriptStruct_FPCGPinInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCGPinInfo_Statics::PropPointers),
	sizeof(FPCGPinInfo),
	alignof(FPCGPinInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCGPinInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPCGPinInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FPCGPinInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FPCGPinInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FPCGPinInfo.InnerSingleton, Z_Construct_UScriptStruct_FPCGPinInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FPCGPinInfo.InnerSingleton);
}
// ********** End ScriptStruct FPCGPinInfo *********************************************************

// ********** Begin ScriptStruct FPCGEdgeInfo ******************************************************
struct Z_Construct_UScriptStruct_FPCGEdgeInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FPCGEdgeInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FPCGEdgeInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SrcNode_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SrcPin_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DestNode_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DestPin_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FPCGEdgeInfo constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_SrcNode;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SrcPin;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DestNode;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DestPin;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FPCGEdgeInfo constinit property declarations ************************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPCGEdgeInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FPCGEdgeInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FPCGEdgeInfo;
class UScriptStruct* FPCGEdgeInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FPCGEdgeInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FPCGEdgeInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPCGEdgeInfo, (UObject*)Z_Construct_UPackage__Script_PCGToolset(), TEXT("PCGEdgeInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FPCGEdgeInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FPCGEdgeInfo Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPCGEdgeInfo_Statics::NewProp_SrcNode = { "SrcNode", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGEdgeInfo, SrcNode), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SrcNode_MetaData), NewProp_SrcNode_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPCGEdgeInfo_Statics::NewProp_SrcPin = { "SrcPin", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGEdgeInfo, SrcPin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SrcPin_MetaData), NewProp_SrcPin_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPCGEdgeInfo_Statics::NewProp_DestNode = { "DestNode", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGEdgeInfo, DestNode), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DestNode_MetaData), NewProp_DestNode_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPCGEdgeInfo_Statics::NewProp_DestPin = { "DestPin", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGEdgeInfo, DestPin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DestPin_MetaData), NewProp_DestPin_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPCGEdgeInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGEdgeInfo_Statics::NewProp_SrcNode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGEdgeInfo_Statics::NewProp_SrcPin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGEdgeInfo_Statics::NewProp_DestNode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGEdgeInfo_Statics::NewProp_DestPin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCGEdgeInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FPCGEdgeInfo Property Definitions ***********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPCGEdgeInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_PCGToolset,
	nullptr,
	&NewStructOps,
	"PCGEdgeInfo",
	Z_Construct_UScriptStruct_FPCGEdgeInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCGEdgeInfo_Statics::PropPointers),
	sizeof(FPCGEdgeInfo),
	alignof(FPCGEdgeInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCGEdgeInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPCGEdgeInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FPCGEdgeInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FPCGEdgeInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FPCGEdgeInfo.InnerSingleton, Z_Construct_UScriptStruct_FPCGEdgeInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FPCGEdgeInfo.InnerSingleton);
}
// ********** End ScriptStruct FPCGEdgeInfo ********************************************************

// ********** Begin ScriptStruct FPCGNodeInfo ******************************************************
struct Z_Construct_UScriptStruct_FPCGNodeInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FPCGNodeInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FPCGNodeInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Path_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Position_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Title_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnabled_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Comment_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NodeType_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ParamOverrides_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FPCGNodeInfo constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Path;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Position;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Title;
	static void NewProp_bEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Comment;
	static const UECodeGen_Private::FStrPropertyParams NewProp_NodeType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ParamOverrides;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FPCGNodeInfo constinit property declarations ************************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPCGNodeInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FPCGNodeInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FPCGNodeInfo;
class UScriptStruct* FPCGNodeInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FPCGNodeInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FPCGNodeInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPCGNodeInfo, (UObject*)Z_Construct_UPackage__Script_PCGToolset(), TEXT("PCGNodeInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FPCGNodeInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FPCGNodeInfo Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPCGNodeInfo_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGNodeInfo, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPCGNodeInfo_Statics::NewProp_Path = { "Path", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGNodeInfo, Path), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Path_MetaData), NewProp_Path_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPCGNodeInfo_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGNodeInfo, Position), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Position_MetaData), NewProp_Position_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPCGNodeInfo_Statics::NewProp_Title = { "Title", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGNodeInfo, Title), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Title_MetaData), NewProp_Title_MetaData) };
void Z_Construct_UScriptStruct_FPCGNodeInfo_Statics::NewProp_bEnabled_SetBit(void* Obj)
{
	((FPCGNodeInfo*)Obj)->bEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPCGNodeInfo_Statics::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FPCGNodeInfo), &Z_Construct_UScriptStruct_FPCGNodeInfo_Statics::NewProp_bEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnabled_MetaData), NewProp_bEnabled_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPCGNodeInfo_Statics::NewProp_Comment = { "Comment", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGNodeInfo, Comment), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Comment_MetaData), NewProp_Comment_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPCGNodeInfo_Statics::NewProp_NodeType = { "NodeType", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGNodeInfo, NodeType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NodeType_MetaData), NewProp_NodeType_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPCGNodeInfo_Statics::NewProp_ParamOverrides = { "ParamOverrides", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGNodeInfo, ParamOverrides), Z_Construct_UScriptStruct_FInstancedPropertyBag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ParamOverrides_MetaData), NewProp_ParamOverrides_MetaData) }; // 1261298821
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPCGNodeInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGNodeInfo_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGNodeInfo_Statics::NewProp_Path,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGNodeInfo_Statics::NewProp_Position,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGNodeInfo_Statics::NewProp_Title,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGNodeInfo_Statics::NewProp_bEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGNodeInfo_Statics::NewProp_Comment,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGNodeInfo_Statics::NewProp_NodeType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGNodeInfo_Statics::NewProp_ParamOverrides,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCGNodeInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FPCGNodeInfo Property Definitions ***********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPCGNodeInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_PCGToolset,
	nullptr,
	&NewStructOps,
	"PCGNodeInfo",
	Z_Construct_UScriptStruct_FPCGNodeInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCGNodeInfo_Statics::PropPointers),
	sizeof(FPCGNodeInfo),
	alignof(FPCGNodeInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCGNodeInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPCGNodeInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FPCGNodeInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FPCGNodeInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FPCGNodeInfo.InnerSingleton, Z_Construct_UScriptStruct_FPCGNodeInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FPCGNodeInfo.InnerSingleton);
}
// ********** End ScriptStruct FPCGNodeInfo ********************************************************

// ********** Begin ScriptStruct FPCGGraphStructure ************************************************
struct Z_Construct_UScriptStruct_FPCGGraphStructure_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FPCGGraphStructure); }
	static inline consteval int16 GetStructAlignment() { return alignof(FPCGGraphStructure); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Nodes_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Edges_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FPCGGraphStructure constinit property declarations ****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Description;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Nodes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Nodes;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Edges_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Edges;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FPCGGraphStructure constinit property declarations ******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPCGGraphStructure>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FPCGGraphStructure_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FPCGGraphStructure;
class UScriptStruct* FPCGGraphStructure::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FPCGGraphStructure.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FPCGGraphStructure.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPCGGraphStructure, (UObject*)Z_Construct_UPackage__Script_PCGToolset(), TEXT("PCGGraphStructure"));
	}
	return Z_Registration_Info_UScriptStruct_FPCGGraphStructure.OuterSingleton;
	}

// ********** Begin ScriptStruct FPCGGraphStructure Property Definitions ***************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPCGGraphStructure_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGGraphStructure, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPCGGraphStructure_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGGraphStructure, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPCGGraphStructure_Statics::NewProp_Nodes_Inner = { "Nodes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FPCGNodeInfo, METADATA_PARAMS(0, nullptr) }; // 1617287642
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FPCGGraphStructure_Statics::NewProp_Nodes = { "Nodes", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGGraphStructure, Nodes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Nodes_MetaData), NewProp_Nodes_MetaData) }; // 1617287642
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPCGGraphStructure_Statics::NewProp_Edges_Inner = { "Edges", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FPCGEdgeInfo, METADATA_PARAMS(0, nullptr) }; // 3167419441
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FPCGGraphStructure_Statics::NewProp_Edges = { "Edges", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGGraphStructure, Edges), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Edges_MetaData), NewProp_Edges_MetaData) }; // 3167419441
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPCGGraphStructure_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGGraphStructure_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGGraphStructure_Statics::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGGraphStructure_Statics::NewProp_Nodes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGGraphStructure_Statics::NewProp_Nodes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGGraphStructure_Statics::NewProp_Edges_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGGraphStructure_Statics::NewProp_Edges,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCGGraphStructure_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FPCGGraphStructure Property Definitions *****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPCGGraphStructure_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_PCGToolset,
	nullptr,
	&NewStructOps,
	"PCGGraphStructure",
	Z_Construct_UScriptStruct_FPCGGraphStructure_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCGGraphStructure_Statics::PropPointers),
	sizeof(FPCGGraphStructure),
	alignof(FPCGGraphStructure),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCGGraphStructure_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPCGGraphStructure_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FPCGGraphStructure()
{
	if (!Z_Registration_Info_UScriptStruct_FPCGGraphStructure.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FPCGGraphStructure.InnerSingleton, Z_Construct_UScriptStruct_FPCGGraphStructure_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FPCGGraphStructure.InnerSingleton);
}
// ********** End ScriptStruct FPCGGraphStructure **************************************************

// ********** Begin ScriptStruct FPCGGraphSchema ***************************************************
struct Z_Construct_UScriptStruct_FPCGGraphSchema_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FPCGGraphSchema); }
	static inline consteval int16 GetStructAlignment() { return alignof(FPCGGraphSchema); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GraphParamsSchema_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InputPins_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutputPins_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FPCGGraphSchema constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_GraphParamsSchema;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InputPins_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_InputPins;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutputPins_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutputPins;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FPCGGraphSchema constinit property declarations *********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPCGGraphSchema>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FPCGGraphSchema_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FPCGGraphSchema;
class UScriptStruct* FPCGGraphSchema::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FPCGGraphSchema.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FPCGGraphSchema.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPCGGraphSchema, (UObject*)Z_Construct_UPackage__Script_PCGToolset(), TEXT("PCGGraphSchema"));
	}
	return Z_Registration_Info_UScriptStruct_FPCGGraphSchema.OuterSingleton;
	}

// ********** Begin ScriptStruct FPCGGraphSchema Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPCGGraphSchema_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGGraphSchema, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPCGGraphSchema_Statics::NewProp_GraphParamsSchema = { "GraphParamsSchema", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGGraphSchema, GraphParamsSchema), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GraphParamsSchema_MetaData), NewProp_GraphParamsSchema_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPCGGraphSchema_Statics::NewProp_InputPins_Inner = { "InputPins", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FPCGPinInfo, METADATA_PARAMS(0, nullptr) }; // 1703332394
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FPCGGraphSchema_Statics::NewProp_InputPins = { "InputPins", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGGraphSchema, InputPins), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InputPins_MetaData), NewProp_InputPins_MetaData) }; // 1703332394
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPCGGraphSchema_Statics::NewProp_OutputPins_Inner = { "OutputPins", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FPCGPinInfo, METADATA_PARAMS(0, nullptr) }; // 1703332394
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FPCGGraphSchema_Statics::NewProp_OutputPins = { "OutputPins", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGGraphSchema, OutputPins), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutputPins_MetaData), NewProp_OutputPins_MetaData) }; // 1703332394
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPCGGraphSchema_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGGraphSchema_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGGraphSchema_Statics::NewProp_GraphParamsSchema,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGGraphSchema_Statics::NewProp_InputPins_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGGraphSchema_Statics::NewProp_InputPins,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGGraphSchema_Statics::NewProp_OutputPins_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGGraphSchema_Statics::NewProp_OutputPins,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCGGraphSchema_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FPCGGraphSchema Property Definitions ********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPCGGraphSchema_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_PCGToolset,
	nullptr,
	&NewStructOps,
	"PCGGraphSchema",
	Z_Construct_UScriptStruct_FPCGGraphSchema_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCGGraphSchema_Statics::PropPointers),
	sizeof(FPCGGraphSchema),
	alignof(FPCGGraphSchema),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCGGraphSchema_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPCGGraphSchema_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FPCGGraphSchema()
{
	if (!Z_Registration_Info_UScriptStruct_FPCGGraphSchema.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FPCGGraphSchema.InnerSingleton, Z_Construct_UScriptStruct_FPCGGraphSchema_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FPCGGraphSchema.InnerSingleton);
}
// ********** End ScriptStruct FPCGGraphSchema *****************************************************

// ********** Begin ScriptStruct FPCGNativeNodeSchema **********************************************
struct Z_Construct_UScriptStruct_FPCGNativeNodeSchema_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FPCGNativeNodeSchema); }
	static inline consteval int16 GetStructAlignment() { return alignof(FPCGNativeNodeSchema); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropertiesSchema_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InputPins_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutputPins_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FPCGNativeNodeSchema constinit property declarations **************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Description;
	static const UECodeGen_Private::FStrPropertyParams NewProp_PropertiesSchema;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InputPins_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_InputPins;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutputPins_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutputPins;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FPCGNativeNodeSchema constinit property declarations ****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPCGNativeNodeSchema>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FPCGNativeNodeSchema_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FPCGNativeNodeSchema;
class UScriptStruct* FPCGNativeNodeSchema::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FPCGNativeNodeSchema.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FPCGNativeNodeSchema.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPCGNativeNodeSchema, (UObject*)Z_Construct_UPackage__Script_PCGToolset(), TEXT("PCGNativeNodeSchema"));
	}
	return Z_Registration_Info_UScriptStruct_FPCGNativeNodeSchema.OuterSingleton;
	}

// ********** Begin ScriptStruct FPCGNativeNodeSchema Property Definitions *************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPCGNativeNodeSchema_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGNativeNodeSchema, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPCGNativeNodeSchema_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGNativeNodeSchema, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPCGNativeNodeSchema_Statics::NewProp_PropertiesSchema = { "PropertiesSchema", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGNativeNodeSchema, PropertiesSchema), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropertiesSchema_MetaData), NewProp_PropertiesSchema_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPCGNativeNodeSchema_Statics::NewProp_InputPins_Inner = { "InputPins", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FPCGPinInfo, METADATA_PARAMS(0, nullptr) }; // 1703332394
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FPCGNativeNodeSchema_Statics::NewProp_InputPins = { "InputPins", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGNativeNodeSchema, InputPins), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InputPins_MetaData), NewProp_InputPins_MetaData) }; // 1703332394
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPCGNativeNodeSchema_Statics::NewProp_OutputPins_Inner = { "OutputPins", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FPCGPinInfo, METADATA_PARAMS(0, nullptr) }; // 1703332394
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FPCGNativeNodeSchema_Statics::NewProp_OutputPins = { "OutputPins", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGNativeNodeSchema, OutputPins), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutputPins_MetaData), NewProp_OutputPins_MetaData) }; // 1703332394
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPCGNativeNodeSchema_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGNativeNodeSchema_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGNativeNodeSchema_Statics::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGNativeNodeSchema_Statics::NewProp_PropertiesSchema,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGNativeNodeSchema_Statics::NewProp_InputPins_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGNativeNodeSchema_Statics::NewProp_InputPins,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGNativeNodeSchema_Statics::NewProp_OutputPins_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGNativeNodeSchema_Statics::NewProp_OutputPins,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCGNativeNodeSchema_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FPCGNativeNodeSchema Property Definitions ***************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPCGNativeNodeSchema_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_PCGToolset,
	nullptr,
	&NewStructOps,
	"PCGNativeNodeSchema",
	Z_Construct_UScriptStruct_FPCGNativeNodeSchema_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCGNativeNodeSchema_Statics::PropPointers),
	sizeof(FPCGNativeNodeSchema),
	alignof(FPCGNativeNodeSchema),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCGNativeNodeSchema_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPCGNativeNodeSchema_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FPCGNativeNodeSchema()
{
	if (!Z_Registration_Info_UScriptStruct_FPCGNativeNodeSchema.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FPCGNativeNodeSchema.InnerSingleton, Z_Construct_UScriptStruct_FPCGNativeNodeSchema_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FPCGNativeNodeSchema.InnerSingleton);
}
// ********** End ScriptStruct FPCGNativeNodeSchema ************************************************

// ********** Begin ScriptStruct FPCGNodeExecutionMessage ******************************************
struct Z_Construct_UScriptStruct_FPCGNodeExecutionMessage_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FPCGNodeExecutionMessage); }
	static inline consteval int16 GetStructAlignment() { return alignof(FPCGNodeExecutionMessage); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Severity_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReporterNode_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FPCGNodeExecutionMessage constinit property declarations **********
	static const UECodeGen_Private::FStrPropertyParams NewProp_Message;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Severity;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReporterNode;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FPCGNodeExecutionMessage constinit property declarations ************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPCGNodeExecutionMessage>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FPCGNodeExecutionMessage_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FPCGNodeExecutionMessage;
class UScriptStruct* FPCGNodeExecutionMessage::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FPCGNodeExecutionMessage.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FPCGNodeExecutionMessage.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPCGNodeExecutionMessage, (UObject*)Z_Construct_UPackage__Script_PCGToolset(), TEXT("PCGNodeExecutionMessage"));
	}
	return Z_Registration_Info_UScriptStruct_FPCGNodeExecutionMessage.OuterSingleton;
	}

// ********** Begin ScriptStruct FPCGNodeExecutionMessage Property Definitions *********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPCGNodeExecutionMessage_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGNodeExecutionMessage, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPCGNodeExecutionMessage_Statics::NewProp_Severity = { "Severity", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGNodeExecutionMessage, Severity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Severity_MetaData), NewProp_Severity_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPCGNodeExecutionMessage_Statics::NewProp_ReporterNode = { "ReporterNode", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPCGNodeExecutionMessage, ReporterNode), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReporterNode_MetaData), NewProp_ReporterNode_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPCGNodeExecutionMessage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGNodeExecutionMessage_Statics::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGNodeExecutionMessage_Statics::NewProp_Severity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCGNodeExecutionMessage_Statics::NewProp_ReporterNode,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCGNodeExecutionMessage_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FPCGNodeExecutionMessage Property Definitions ***********************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPCGNodeExecutionMessage_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_PCGToolset,
	nullptr,
	&NewStructOps,
	"PCGNodeExecutionMessage",
	Z_Construct_UScriptStruct_FPCGNodeExecutionMessage_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCGNodeExecutionMessage_Statics::PropPointers),
	sizeof(FPCGNodeExecutionMessage),
	alignof(FPCGNodeExecutionMessage),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCGNodeExecutionMessage_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPCGNodeExecutionMessage_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FPCGNodeExecutionMessage()
{
	if (!Z_Registration_Info_UScriptStruct_FPCGNodeExecutionMessage.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FPCGNodeExecutionMessage.InnerSingleton, Z_Construct_UScriptStruct_FPCGNodeExecutionMessage_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FPCGNodeExecutionMessage.InnerSingleton);
}
// ********** End ScriptStruct FPCGNodeExecutionMessage ********************************************

// ********** Begin Class UPCGExecuteGraphInstanceAsyncResult **************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UPCGExecuteGraphInstanceAsyncResult;
UClass* UPCGExecuteGraphInstanceAsyncResult::GetPrivateStaticClass()
{
	using TClass = UPCGExecuteGraphInstanceAsyncResult;
	if (!Z_Registration_Info_UClass_UPCGExecuteGraphInstanceAsyncResult.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("PCGExecuteGraphInstanceAsyncResult"),
			Z_Registration_Info_UClass_UPCGExecuteGraphInstanceAsyncResult.InnerSingleton,
			StaticRegisterNativesUPCGExecuteGraphInstanceAsyncResult,
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
	return Z_Registration_Info_UClass_UPCGExecuteGraphInstanceAsyncResult.InnerSingleton;
}
UClass* Z_Construct_UClass_UPCGExecuteGraphInstanceAsyncResult_NoRegister()
{
	return UPCGExecuteGraphInstanceAsyncResult::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPCGExecuteGraphInstanceAsyncResult_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "PCGToolsetCustomTypes.h" },
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "ModuleRelativePath", "Public/PCGToolsetCustomTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UPCGExecuteGraphInstanceAsyncResult constinit property declarations ******
	static const UECodeGen_Private::FStructPropertyParams NewProp_Value_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UPCGExecuteGraphInstanceAsyncResult constinit property declarations ********
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPCGExecuteGraphInstanceAsyncResult>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UPCGExecuteGraphInstanceAsyncResult_Statics

// ********** Begin Class UPCGExecuteGraphInstanceAsyncResult Property Definitions *****************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPCGExecuteGraphInstanceAsyncResult_Statics::NewProp_Value_Inner = { "Value", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FPCGNodeExecutionMessage, METADATA_PARAMS(0, nullptr) }; // 4067192777
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPCGExecuteGraphInstanceAsyncResult_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPCGExecuteGraphInstanceAsyncResult, Value), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) }; // 4067192777
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPCGExecuteGraphInstanceAsyncResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPCGExecuteGraphInstanceAsyncResult_Statics::NewProp_Value_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPCGExecuteGraphInstanceAsyncResult_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPCGExecuteGraphInstanceAsyncResult_Statics::PropPointers) < 2048);
// ********** End Class UPCGExecuteGraphInstanceAsyncResult Property Definitions *******************
UObject* (*const Z_Construct_UClass_UPCGExecuteGraphInstanceAsyncResult_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UToolCallAsyncResult,
	(UObject* (*)())Z_Construct_UPackage__Script_PCGToolset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPCGExecuteGraphInstanceAsyncResult_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPCGExecuteGraphInstanceAsyncResult_Statics::ClassParams = {
	&UPCGExecuteGraphInstanceAsyncResult::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UPCGExecuteGraphInstanceAsyncResult_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UPCGExecuteGraphInstanceAsyncResult_Statics::PropPointers),
	0,
	0x008000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPCGExecuteGraphInstanceAsyncResult_Statics::Class_MetaDataParams), Z_Construct_UClass_UPCGExecuteGraphInstanceAsyncResult_Statics::Class_MetaDataParams)
};
void UPCGExecuteGraphInstanceAsyncResult::StaticRegisterNativesUPCGExecuteGraphInstanceAsyncResult()
{
}
UClass* Z_Construct_UClass_UPCGExecuteGraphInstanceAsyncResult()
{
	if (!Z_Registration_Info_UClass_UPCGExecuteGraphInstanceAsyncResult.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPCGExecuteGraphInstanceAsyncResult.OuterSingleton, Z_Construct_UClass_UPCGExecuteGraphInstanceAsyncResult_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPCGExecuteGraphInstanceAsyncResult.OuterSingleton;
}
UPCGExecuteGraphInstanceAsyncResult::UPCGExecuteGraphInstanceAsyncResult(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UPCGExecuteGraphInstanceAsyncResult);
UPCGExecuteGraphInstanceAsyncResult::~UPCGExecuteGraphInstanceAsyncResult() {}
// ********** End Class UPCGExecuteGraphInstanceAsyncResult ****************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolsetCustomTypes_h__Script_PCGToolset_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FPCGGraphInstanceInfo::StaticStruct, Z_Construct_UScriptStruct_FPCGGraphInstanceInfo_Statics::NewStructOps, TEXT("PCGGraphInstanceInfo"),&Z_Registration_Info_UScriptStruct_FPCGGraphInstanceInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPCGGraphInstanceInfo), 313673020U) },
		{ FPCGParamDefinition::StaticStruct, Z_Construct_UScriptStruct_FPCGParamDefinition_Statics::NewStructOps, TEXT("PCGParamDefinition"),&Z_Registration_Info_UScriptStruct_FPCGParamDefinition, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPCGParamDefinition), 2235050558U) },
		{ FPCGPinInfo::StaticStruct, Z_Construct_UScriptStruct_FPCGPinInfo_Statics::NewStructOps, TEXT("PCGPinInfo"),&Z_Registration_Info_UScriptStruct_FPCGPinInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPCGPinInfo), 1703332394U) },
		{ FPCGEdgeInfo::StaticStruct, Z_Construct_UScriptStruct_FPCGEdgeInfo_Statics::NewStructOps, TEXT("PCGEdgeInfo"),&Z_Registration_Info_UScriptStruct_FPCGEdgeInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPCGEdgeInfo), 3167419441U) },
		{ FPCGNodeInfo::StaticStruct, Z_Construct_UScriptStruct_FPCGNodeInfo_Statics::NewStructOps, TEXT("PCGNodeInfo"),&Z_Registration_Info_UScriptStruct_FPCGNodeInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPCGNodeInfo), 1617287642U) },
		{ FPCGGraphStructure::StaticStruct, Z_Construct_UScriptStruct_FPCGGraphStructure_Statics::NewStructOps, TEXT("PCGGraphStructure"),&Z_Registration_Info_UScriptStruct_FPCGGraphStructure, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPCGGraphStructure), 403529749U) },
		{ FPCGGraphSchema::StaticStruct, Z_Construct_UScriptStruct_FPCGGraphSchema_Statics::NewStructOps, TEXT("PCGGraphSchema"),&Z_Registration_Info_UScriptStruct_FPCGGraphSchema, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPCGGraphSchema), 1829918540U) },
		{ FPCGNativeNodeSchema::StaticStruct, Z_Construct_UScriptStruct_FPCGNativeNodeSchema_Statics::NewStructOps, TEXT("PCGNativeNodeSchema"),&Z_Registration_Info_UScriptStruct_FPCGNativeNodeSchema, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPCGNativeNodeSchema), 3790087811U) },
		{ FPCGNodeExecutionMessage::StaticStruct, Z_Construct_UScriptStruct_FPCGNodeExecutionMessage_Statics::NewStructOps, TEXT("PCGNodeExecutionMessage"),&Z_Registration_Info_UScriptStruct_FPCGNodeExecutionMessage, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPCGNodeExecutionMessage), 4067192777U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPCGExecuteGraphInstanceAsyncResult, UPCGExecuteGraphInstanceAsyncResult::StaticClass, TEXT("UPCGExecuteGraphInstanceAsyncResult"), &Z_Registration_Info_UClass_UPCGExecuteGraphInstanceAsyncResult, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPCGExecuteGraphInstanceAsyncResult), 2721933059U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolsetCustomTypes_h__Script_PCGToolset_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolsetCustomTypes_h__Script_PCGToolset_2010006124{
	TEXT("/Script/PCGToolset"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolsetCustomTypes_h__Script_PCGToolset_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolsetCustomTypes_h__Script_PCGToolset_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolsetCustomTypes_h__Script_PCGToolset_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolsetCustomTypes_h__Script_PCGToolset_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
