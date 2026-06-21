// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ModelContextProtocolToolResults.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeModelContextProtocolToolResults() {}

// ********** Begin Cross Module References ********************************************************
JSONUTILITIES_API UScriptStruct* Z_Construct_UScriptStruct_FJsonObjectWrapper();
MODELCONTEXTPROTOCOL_API UEnum* Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolAudience();
MODELCONTEXTPROTOCOL_API UEnum* Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolToolResultType();
MODELCONTEXTPROTOCOL_API UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolToolResult();
UPackage* Z_Construct_UPackage__Script_ModelContextProtocol();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EModelContextProtocolToolResultType ***************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EModelContextProtocolToolResultType;
static UEnum* EModelContextProtocolToolResultType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EModelContextProtocolToolResultType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EModelContextProtocolToolResultType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolToolResultType, (UObject*)Z_Construct_UPackage__Script_ModelContextProtocol(), TEXT("EModelContextProtocolToolResultType"));
	}
	return Z_Registration_Info_UEnum_EModelContextProtocolToolResultType.OuterSingleton;
}
template<> MODELCONTEXTPROTOCOL_NON_ATTRIBUTED_API UEnum* StaticEnum<EModelContextProtocolToolResultType>()
{
	return EModelContextProtocolToolResultType_StaticEnum();
}
struct Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolToolResultType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Audio.Name", "EModelContextProtocolToolResultType::Audio" },
		{ "Bitflags", "" },
		{ "EmbeddedResource.Hidden", "" },
		{ "EmbeddedResource.Name", "EModelContextProtocolToolResultType::EmbeddedResource" },
		{ "Image.Name", "EModelContextProtocolToolResultType::Image" },
		{ "ModuleRelativePath", "Public/ModelContextProtocolToolResults.h" },
		{ "None.Name", "EModelContextProtocolToolResultType::None" },
		{ "ResourceLink.Hidden", "" },
		{ "ResourceLink.Name", "EModelContextProtocolToolResultType::ResourceLink" },
		{ "StructuredContent.Name", "EModelContextProtocolToolResultType::StructuredContent" },
		{ "Text.Name", "EModelContextProtocolToolResultType::Text" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EModelContextProtocolToolResultType::None", (int64)EModelContextProtocolToolResultType::None },
		{ "EModelContextProtocolToolResultType::Text", (int64)EModelContextProtocolToolResultType::Text },
		{ "EModelContextProtocolToolResultType::Image", (int64)EModelContextProtocolToolResultType::Image },
		{ "EModelContextProtocolToolResultType::Audio", (int64)EModelContextProtocolToolResultType::Audio },
		{ "EModelContextProtocolToolResultType::ResourceLink", (int64)EModelContextProtocolToolResultType::ResourceLink },
		{ "EModelContextProtocolToolResultType::EmbeddedResource", (int64)EModelContextProtocolToolResultType::EmbeddedResource },
		{ "EModelContextProtocolToolResultType::StructuredContent", (int64)EModelContextProtocolToolResultType::StructuredContent },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolToolResultType_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolToolResultType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ModelContextProtocol,
	nullptr,
	"EModelContextProtocolToolResultType",
	"EModelContextProtocolToolResultType",
	Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolToolResultType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolToolResultType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolToolResultType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolToolResultType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolToolResultType()
{
	if (!Z_Registration_Info_UEnum_EModelContextProtocolToolResultType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EModelContextProtocolToolResultType.InnerSingleton, Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolToolResultType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EModelContextProtocolToolResultType.InnerSingleton;
}
// ********** End Enum EModelContextProtocolToolResultType *****************************************

// ********** Begin Enum EModelContextProtocolAudience *********************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EModelContextProtocolAudience;
static UEnum* EModelContextProtocolAudience_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EModelContextProtocolAudience.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EModelContextProtocolAudience.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolAudience, (UObject*)Z_Construct_UPackage__Script_ModelContextProtocol(), TEXT("EModelContextProtocolAudience"));
	}
	return Z_Registration_Info_UEnum_EModelContextProtocolAudience.OuterSingleton;
}
template<> MODELCONTEXTPROTOCOL_NON_ATTRIBUTED_API UEnum* StaticEnum<EModelContextProtocolAudience>()
{
	return EModelContextProtocolAudience_StaticEnum();
}
struct Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolAudience_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "All.Name", "EModelContextProtocolAudience::All" },
		{ "Assistant.Name", "EModelContextProtocolAudience::Assistant" },
		{ "Bitflags", "" },
		{ "ModuleRelativePath", "Public/ModelContextProtocolToolResults.h" },
		{ "None.Name", "EModelContextProtocolAudience::None" },
		{ "User.Name", "EModelContextProtocolAudience::User" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EModelContextProtocolAudience::None", (int64)EModelContextProtocolAudience::None },
		{ "EModelContextProtocolAudience::User", (int64)EModelContextProtocolAudience::User },
		{ "EModelContextProtocolAudience::Assistant", (int64)EModelContextProtocolAudience::Assistant },
		{ "EModelContextProtocolAudience::All", (int64)EModelContextProtocolAudience::All },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolAudience_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolAudience_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ModelContextProtocol,
	nullptr,
	"EModelContextProtocolAudience",
	"EModelContextProtocolAudience",
	Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolAudience_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolAudience_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolAudience_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolAudience_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolAudience()
{
	if (!Z_Registration_Info_UEnum_EModelContextProtocolAudience.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EModelContextProtocolAudience.InnerSingleton, Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolAudience_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EModelContextProtocolAudience.InnerSingleton;
}
// ********** End Enum EModelContextProtocolAudience ***********************************************

// ********** Begin ScriptStruct FModelContextProtocolToolResult ***********************************
struct Z_Construct_UScriptStruct_FModelContextProtocolToolResult_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FModelContextProtocolToolResult); }
	static inline consteval int16 GetStructAlignment() { return alignof(FModelContextProtocolToolResult); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * IModelContextProtocolTool execution result.\n * \n * Wraps a JSON object adhering to https://modelcontextprotocol.io/specification/2025-06-18/server/tools#tool-result spec.\n * \n * Use MakeTextResult, MakeStructuredContentResult, MakeImageResult & MakeAudioResult for creating the appropriate tool result structures.\n */" },
#endif
		{ "ModuleRelativePath", "Public/ModelContextProtocolToolResults.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "IModelContextProtocolTool execution result.\n\nWraps a JSON object adhering to https://modelcontextprotocol.io/specification/2025-06-18/server/tools#tool-result spec.\n\nUse MakeTextResult, MakeStructuredContentResult, MakeImageResult & MakeAudioResult for creating the appropriate tool result structures." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FModelContextProtocolToolResult constinit property declarations ***
// ********** End ScriptStruct FModelContextProtocolToolResult constinit property declarations *****
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FModelContextProtocolToolResult>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FModelContextProtocolToolResult_Statics
static_assert(std::is_polymorphic<FModelContextProtocolToolResult>() == std::is_polymorphic<FJsonObjectWrapper>(), "USTRUCT FModelContextProtocolToolResult cannot be polymorphic unless super FJsonObjectWrapper is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FModelContextProtocolToolResult;
class UScriptStruct* FModelContextProtocolToolResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolToolResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FModelContextProtocolToolResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FModelContextProtocolToolResult, (UObject*)Z_Construct_UPackage__Script_ModelContextProtocol(), TEXT("ModelContextProtocolToolResult"));
	}
	return Z_Registration_Info_UScriptStruct_FModelContextProtocolToolResult.OuterSingleton;
	}
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FModelContextProtocolToolResult_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ModelContextProtocol,
	Z_Construct_UScriptStruct_FJsonObjectWrapper,
	&NewStructOps,
	"ModelContextProtocolToolResult",
	nullptr,
	0,
	sizeof(FModelContextProtocolToolResult),
	alignof(FModelContextProtocolToolResult),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolToolResult_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FModelContextProtocolToolResult_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolToolResult()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolToolResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FModelContextProtocolToolResult.InnerSingleton, Z_Construct_UScriptStruct_FModelContextProtocolToolResult_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FModelContextProtocolToolResult.InnerSingleton);
}
// ********** End ScriptStruct FModelContextProtocolToolResult *************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolToolResults_h__Script_ModelContextProtocol_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EModelContextProtocolToolResultType_StaticEnum, TEXT("EModelContextProtocolToolResultType"), &Z_Registration_Info_UEnum_EModelContextProtocolToolResultType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1771457716U) },
		{ EModelContextProtocolAudience_StaticEnum, TEXT("EModelContextProtocolAudience"), &Z_Registration_Info_UEnum_EModelContextProtocolAudience, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2531148173U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FModelContextProtocolToolResult::StaticStruct, Z_Construct_UScriptStruct_FModelContextProtocolToolResult_Statics::NewStructOps, TEXT("ModelContextProtocolToolResult"),&Z_Registration_Info_UScriptStruct_FModelContextProtocolToolResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FModelContextProtocolToolResult), 609480732U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolToolResults_h__Script_ModelContextProtocol_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolToolResults_h__Script_ModelContextProtocol_2402003387{
	TEXT("/Script/ModelContextProtocol"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolToolResults_h__Script_ModelContextProtocol_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolToolResults_h__Script_ModelContextProtocol_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolToolResults_h__Script_ModelContextProtocol_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolToolResults_h__Script_ModelContextProtocol_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
