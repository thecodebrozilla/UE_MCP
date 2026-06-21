// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ModelContextProtocolMetaData.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeModelContextProtocolMetaData() {}

// ********** Begin Cross Module References ********************************************************
MODELCONTEXTPROTOCOL_API UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolFunctionMetaData();
MODELCONTEXTPROTOCOL_API UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData();
UPackage* Z_Construct_UPackage__Script_ModelContextProtocol();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FModelContextProtocolPropertyMetaData *****************************
struct Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FModelContextProtocolPropertyMetaData); }
	static inline consteval int16 GetStructAlignment() { return alignof(FModelContextProtocolPropertyMetaData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cached editor-only property meta-data in a cookable form */" },
#endif
		{ "ModuleRelativePath", "Public/ModelContextProtocolMetaData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached editor-only property meta-data in a cookable form" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Property description derived from its tooltip / native code comment */" },
#endif
		{ "ModuleRelativePath", "Public/ModelContextProtocolMetaData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Property description derived from its tooltip / native code comment" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClampMin_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Property's Meta ClampMin e.g: UPROPERTY(Meta = (ClampMin = \"1\")) */" },
#endif
		{ "ModuleRelativePath", "Public/ModelContextProtocolMetaData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Property's Meta ClampMin e.g: UPROPERTY(Meta = (ClampMin = \"1\"))" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClampMax_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Property's Meta ClampMax e.g: UPROPERTY(Meta = (ClampMax = \"1000\")) */" },
#endif
		{ "ModuleRelativePath", "Public/ModelContextProtocolMetaData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Property's Meta ClampMax e.g: UPROPERTY(Meta = (ClampMax = \"1000\"))" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultValue_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** For function parameters, stores the default parameter value */" },
#endif
		{ "ModuleRelativePath", "Public/ModelContextProtocolMetaData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "For function parameters, stores the default parameter value" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultValueJsonType_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Original JSON type (EJson cast to uint8) of DefaultValue, used for lossless round-trip */" },
#endif
		{ "ModuleRelativePath", "Public/ModelContextProtocolMetaData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Original JSON type (EJson cast to uint8) of DefaultValue, used for lossless round-trip" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FModelContextProtocolPropertyMetaData constinit property declarations 
	static const UECodeGen_Private::FTextPropertyParams NewProp_Description_Inner;
	static const UECodeGen_Private::FGenericPropertyParams NewProp_Description;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_ClampMin_Inner;
	static const UECodeGen_Private::FGenericPropertyParams NewProp_ClampMin;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_ClampMax_Inner;
	static const UECodeGen_Private::FGenericPropertyParams NewProp_ClampMax;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DefaultValue_Inner;
	static const UECodeGen_Private::FGenericPropertyParams NewProp_DefaultValue;
	static const UECodeGen_Private::FBytePropertyParams NewProp_DefaultValueJsonType_Inner;
	static const UECodeGen_Private::FGenericPropertyParams NewProp_DefaultValueJsonType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FModelContextProtocolPropertyMetaData constinit property declarations 
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FModelContextProtocolPropertyMetaData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FModelContextProtocolPropertyMetaData;
class UScriptStruct* FModelContextProtocolPropertyMetaData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolPropertyMetaData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FModelContextProtocolPropertyMetaData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData, (UObject*)Z_Construct_UPackage__Script_ModelContextProtocol(), TEXT("ModelContextProtocolPropertyMetaData"));
	}
	return Z_Registration_Info_UScriptStruct_FModelContextProtocolPropertyMetaData.OuterSingleton;
	}

// ********** Begin ScriptStruct FModelContextProtocolPropertyMetaData Property Definitions ********
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData_Statics::NewProp_Description_Inner = { "Description", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FGenericPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Optional, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolPropertyMetaData, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData_Statics::NewProp_ClampMin_Inner = { "ClampMin", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FGenericPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData_Statics::NewProp_ClampMin = { "ClampMin", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Optional, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolPropertyMetaData, ClampMin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClampMin_MetaData), NewProp_ClampMin_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData_Statics::NewProp_ClampMax_Inner = { "ClampMax", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FGenericPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData_Statics::NewProp_ClampMax = { "ClampMax", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Optional, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolPropertyMetaData, ClampMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClampMax_MetaData), NewProp_ClampMax_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData_Statics::NewProp_DefaultValue_Inner = { "DefaultValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FGenericPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData_Statics::NewProp_DefaultValue = { "DefaultValue", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Optional, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolPropertyMetaData, DefaultValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultValue_MetaData), NewProp_DefaultValue_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData_Statics::NewProp_DefaultValueJsonType_Inner = { "DefaultValueJsonType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FGenericPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData_Statics::NewProp_DefaultValueJsonType = { "DefaultValueJsonType", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Optional, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolPropertyMetaData, DefaultValueJsonType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultValueJsonType_MetaData), NewProp_DefaultValueJsonType_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData_Statics::NewProp_Description_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData_Statics::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData_Statics::NewProp_ClampMin_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData_Statics::NewProp_ClampMin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData_Statics::NewProp_ClampMax_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData_Statics::NewProp_ClampMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData_Statics::NewProp_DefaultValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData_Statics::NewProp_DefaultValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData_Statics::NewProp_DefaultValueJsonType_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData_Statics::NewProp_DefaultValueJsonType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FModelContextProtocolPropertyMetaData Property Definitions **********
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ModelContextProtocol,
	nullptr,
	&NewStructOps,
	"ModelContextProtocolPropertyMetaData",
	Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData_Statics::PropPointers),
	sizeof(FModelContextProtocolPropertyMetaData),
	alignof(FModelContextProtocolPropertyMetaData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolPropertyMetaData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FModelContextProtocolPropertyMetaData.InnerSingleton, Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FModelContextProtocolPropertyMetaData.InnerSingleton);
}
// ********** End ScriptStruct FModelContextProtocolPropertyMetaData *******************************

// ********** Begin ScriptStruct FModelContextProtocolFunctionMetaData *****************************
struct Z_Construct_UScriptStruct_FModelContextProtocolFunctionMetaData_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FModelContextProtocolFunctionMetaData); }
	static inline consteval int16 GetStructAlignment() { return alignof(FModelContextProtocolFunctionMetaData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cached editor-only function meta-data in a cookable form */" },
#endif
		{ "ModuleRelativePath", "Public/ModelContextProtocolMetaData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached editor-only function meta-data in a cookable form" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Function description derived from its tooltip / native code comment */" },
#endif
		{ "ModuleRelativePath", "Public/ModelContextProtocolMetaData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Function description derived from its tooltip / native code comment" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropertyMetaData_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Per-property meta data, including inner properties e.g: Person, Person.Name, Person.Age */" },
#endif
		{ "ModuleRelativePath", "Public/ModelContextProtocolMetaData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Per-property meta data, including inner properties e.g: Person, Person.Name, Person.Age" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContext_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The function's WorldContext meta-data value, if any */" },
#endif
		{ "ModuleRelativePath", "Public/ModelContextProtocolMetaData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The function's WorldContext meta-data value, if any" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FModelContextProtocolFunctionMetaData constinit property declarations 
	static const UECodeGen_Private::FTextPropertyParams NewProp_Description_Inner;
	static const UECodeGen_Private::FGenericPropertyParams NewProp_Description;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PropertyMetaData_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_PropertyMetaData_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_PropertyMetaData;
	static const UECodeGen_Private::FStrPropertyParams NewProp_WorldContext;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FModelContextProtocolFunctionMetaData constinit property declarations 
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FModelContextProtocolFunctionMetaData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FModelContextProtocolFunctionMetaData_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FModelContextProtocolFunctionMetaData;
class UScriptStruct* FModelContextProtocolFunctionMetaData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolFunctionMetaData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FModelContextProtocolFunctionMetaData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FModelContextProtocolFunctionMetaData, (UObject*)Z_Construct_UPackage__Script_ModelContextProtocol(), TEXT("ModelContextProtocolFunctionMetaData"));
	}
	return Z_Registration_Info_UScriptStruct_FModelContextProtocolFunctionMetaData.OuterSingleton;
	}

// ********** Begin ScriptStruct FModelContextProtocolFunctionMetaData Property Definitions ********
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolFunctionMetaData_Statics::NewProp_Description_Inner = { "Description", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FGenericPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolFunctionMetaData_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Optional, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolFunctionMetaData, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolFunctionMetaData_Statics::NewProp_PropertyMetaData_ValueProp = { "PropertyMetaData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData, METADATA_PARAMS(0, nullptr) }; // 3694238115
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolFunctionMetaData_Statics::NewProp_PropertyMetaData_Key_KeyProp = { "PropertyMetaData_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolFunctionMetaData_Statics::NewProp_PropertyMetaData = { "PropertyMetaData", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolFunctionMetaData, PropertyMetaData), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropertyMetaData_MetaData), NewProp_PropertyMetaData_MetaData) }; // 3694238115
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolFunctionMetaData_Statics::NewProp_WorldContext = { "WorldContext", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolFunctionMetaData, WorldContext), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContext_MetaData), NewProp_WorldContext_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FModelContextProtocolFunctionMetaData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolFunctionMetaData_Statics::NewProp_Description_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolFunctionMetaData_Statics::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolFunctionMetaData_Statics::NewProp_PropertyMetaData_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolFunctionMetaData_Statics::NewProp_PropertyMetaData_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolFunctionMetaData_Statics::NewProp_PropertyMetaData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolFunctionMetaData_Statics::NewProp_WorldContext,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolFunctionMetaData_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FModelContextProtocolFunctionMetaData Property Definitions **********
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FModelContextProtocolFunctionMetaData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ModelContextProtocol,
	nullptr,
	&NewStructOps,
	"ModelContextProtocolFunctionMetaData",
	Z_Construct_UScriptStruct_FModelContextProtocolFunctionMetaData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolFunctionMetaData_Statics::PropPointers),
	sizeof(FModelContextProtocolFunctionMetaData),
	alignof(FModelContextProtocolFunctionMetaData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolFunctionMetaData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FModelContextProtocolFunctionMetaData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolFunctionMetaData()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolFunctionMetaData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FModelContextProtocolFunctionMetaData.InnerSingleton, Z_Construct_UScriptStruct_FModelContextProtocolFunctionMetaData_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FModelContextProtocolFunctionMetaData.InnerSingleton);
}
// ********** End ScriptStruct FModelContextProtocolFunctionMetaData *******************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolMetaData_h__Script_ModelContextProtocol_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FModelContextProtocolPropertyMetaData::StaticStruct, Z_Construct_UScriptStruct_FModelContextProtocolPropertyMetaData_Statics::NewStructOps, TEXT("ModelContextProtocolPropertyMetaData"),&Z_Registration_Info_UScriptStruct_FModelContextProtocolPropertyMetaData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FModelContextProtocolPropertyMetaData), 3694238115U) },
		{ FModelContextProtocolFunctionMetaData::StaticStruct, Z_Construct_UScriptStruct_FModelContextProtocolFunctionMetaData_Statics::NewStructOps, TEXT("ModelContextProtocolFunctionMetaData"),&Z_Registration_Info_UScriptStruct_FModelContextProtocolFunctionMetaData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FModelContextProtocolFunctionMetaData), 4184287625U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolMetaData_h__Script_ModelContextProtocol_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolMetaData_h__Script_ModelContextProtocol_4143717466{
	TEXT("/Script/ModelContextProtocol"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolMetaData_h__Script_ModelContextProtocol_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolMetaData_h__Script_ModelContextProtocol_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
