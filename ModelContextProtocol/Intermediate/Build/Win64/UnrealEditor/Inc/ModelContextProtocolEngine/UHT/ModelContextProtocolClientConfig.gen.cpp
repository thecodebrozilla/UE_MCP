// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ModelContextProtocolClientConfig.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeModelContextProtocolClientConfig() {}

// ********** Begin Cross Module References ********************************************************
MODELCONTEXTPROTOCOLENGINE_API UEnum* Z_Construct_UEnum_ModelContextProtocolEngine_EModelContextProtocolClient();
UPackage* Z_Construct_UPackage__Script_ModelContextProtocolEngine();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EModelContextProtocolClient ***********************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EModelContextProtocolClient;
static UEnum* EModelContextProtocolClient_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EModelContextProtocolClient.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EModelContextProtocolClient.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ModelContextProtocolEngine_EModelContextProtocolClient, (UObject*)Z_Construct_UPackage__Script_ModelContextProtocolEngine(), TEXT("EModelContextProtocolClient"));
	}
	return Z_Registration_Info_UEnum_EModelContextProtocolClient.OuterSingleton;
}
template<> MODELCONTEXTPROTOCOLENGINE_NON_ATTRIBUTED_API UEnum* StaticEnum<EModelContextProtocolClient>()
{
	return EModelContextProtocolClient_StaticEnum();
}
struct Z_Construct_UEnum_ModelContextProtocolEngine_EModelContextProtocolClient_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "ClaudeCode.Comment", "/** Claude Code: `.mcp.json` in project root */" },
		{ "ClaudeCode.Name", "EModelContextProtocolClient::ClaudeCode" },
		{ "ClaudeCode.ToolTip", "Claude Code: `.mcp.json` in project root" },
		{ "Codex.Comment", "/** Codex CLI: `.codex/config.toml` in project root (TOML, write-once) */" },
		{ "Codex.Name", "EModelContextProtocolClient::Codex" },
		{ "Codex.ToolTip", "Codex CLI: `.codex/config.toml` in project root (TOML, write-once)" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Supported AI coding clients for MCP configuration file generation. */" },
#endif
		{ "Cursor.Comment", "/** Cursor: `.cursor/mcp.json` in project root */" },
		{ "Cursor.Name", "EModelContextProtocolClient::Cursor" },
		{ "Cursor.ToolTip", "Cursor: `.cursor/mcp.json` in project root" },
		{ "Gemini.Comment", "/** Gemini CLI: `.gemini/settings.json` in project root */" },
		{ "Gemini.Name", "EModelContextProtocolClient::Gemini" },
		{ "Gemini.ToolTip", "Gemini CLI: `.gemini/settings.json` in project root" },
		{ "ModuleRelativePath", "Public/ModelContextProtocolClientConfig.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Supported AI coding clients for MCP configuration file generation." },
#endif
		{ "VSCode.Comment", "/** VS Code / Copilot: `.vscode/mcp.json` in project root */" },
		{ "VSCode.Name", "EModelContextProtocolClient::VSCode" },
		{ "VSCode.ToolTip", "VS Code / Copilot: `.vscode/mcp.json` in project root" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EModelContextProtocolClient::ClaudeCode", (int64)EModelContextProtocolClient::ClaudeCode },
		{ "EModelContextProtocolClient::Cursor", (int64)EModelContextProtocolClient::Cursor },
		{ "EModelContextProtocolClient::VSCode", (int64)EModelContextProtocolClient::VSCode },
		{ "EModelContextProtocolClient::Gemini", (int64)EModelContextProtocolClient::Gemini },
		{ "EModelContextProtocolClient::Codex", (int64)EModelContextProtocolClient::Codex },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_ModelContextProtocolEngine_EModelContextProtocolClient_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ModelContextProtocolEngine_EModelContextProtocolClient_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ModelContextProtocolEngine,
	nullptr,
	"EModelContextProtocolClient",
	"EModelContextProtocolClient",
	Z_Construct_UEnum_ModelContextProtocolEngine_EModelContextProtocolClient_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ModelContextProtocolEngine_EModelContextProtocolClient_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ModelContextProtocolEngine_EModelContextProtocolClient_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ModelContextProtocolEngine_EModelContextProtocolClient_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ModelContextProtocolEngine_EModelContextProtocolClient()
{
	if (!Z_Registration_Info_UEnum_EModelContextProtocolClient.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EModelContextProtocolClient.InnerSingleton, Z_Construct_UEnum_ModelContextProtocolEngine_EModelContextProtocolClient_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EModelContextProtocolClient.InnerSingleton;
}
// ********** End Enum EModelContextProtocolClient *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolClientConfig_h__Script_ModelContextProtocolEngine_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EModelContextProtocolClient_StaticEnum, TEXT("EModelContextProtocolClient"), &Z_Registration_Info_UEnum_EModelContextProtocolClient, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 686879264U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolClientConfig_h__Script_ModelContextProtocolEngine_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolClientConfig_h__Script_ModelContextProtocolEngine_1769856218{
	TEXT("/Script/ModelContextProtocolEngine"),
	nullptr, 0,
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolClientConfig_h__Script_ModelContextProtocolEngine_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolClientConfig_h__Script_ModelContextProtocolEngine_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
