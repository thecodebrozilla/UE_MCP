// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MCPClientToolset/MCPToolsetSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeMCPToolsetSettings() {}

// ********** Begin Cross Module References ********************************************************
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
MCPCLIENTTOOLSET_API UClass* Z_Construct_UClass_UMCPToolsetSettings();
MCPCLIENTTOOLSET_API UClass* Z_Construct_UClass_UMCPToolsetSettings_NoRegister();
MCPCLIENTTOOLSET_API UEnum* Z_Construct_UEnum_MCPClientToolset_EMCPAuth();
MCPCLIENTTOOLSET_API UEnum* Z_Construct_UEnum_MCPClientToolset_EMCPTransport();
MCPCLIENTTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FMCPServerConfig();
UPackage* Z_Construct_UPackage__Script_MCPClientToolset();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EMCPTransport *************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EMCPTransport;
static UEnum* EMCPTransport_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EMCPTransport.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EMCPTransport.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_MCPClientToolset_EMCPTransport, (UObject*)Z_Construct_UPackage__Script_MCPClientToolset(), TEXT("EMCPTransport"));
	}
	return Z_Registration_Info_UEnum_EMCPTransport.OuterSingleton;
}
template<> MCPCLIENTTOOLSET_NON_ATTRIBUTED_API UEnum* StaticEnum<EMCPTransport>()
{
	return EMCPTransport_StaticEnum();
}
struct Z_Construct_UEnum_MCPClientToolset_EMCPTransport_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Transport protocol for an MCP server connection. */" },
#endif
		{ "ModuleRelativePath", "Public/MCPClientToolset/MCPToolsetSettings.h" },
		{ "SSE.DisplayName", "Legacy SSE (HTTP+SSE)" },
		{ "SSE.Name", "EMCPTransport::SSE" },
		{ "StreamableHTTP.DisplayName", "Streamable HTTP" },
		{ "StreamableHTTP.Name", "EMCPTransport::StreamableHTTP" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Transport protocol for an MCP server connection." },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMCPTransport::SSE", (int64)EMCPTransport::SSE },
		{ "EMCPTransport::StreamableHTTP", (int64)EMCPTransport::StreamableHTTP },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_MCPClientToolset_EMCPTransport_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_MCPClientToolset_EMCPTransport_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_MCPClientToolset,
	nullptr,
	"EMCPTransport",
	"EMCPTransport",
	Z_Construct_UEnum_MCPClientToolset_EMCPTransport_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_MCPClientToolset_EMCPTransport_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_MCPClientToolset_EMCPTransport_Statics::Enum_MetaDataParams), Z_Construct_UEnum_MCPClientToolset_EMCPTransport_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_MCPClientToolset_EMCPTransport()
{
	if (!Z_Registration_Info_UEnum_EMCPTransport.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EMCPTransport.InnerSingleton, Z_Construct_UEnum_MCPClientToolset_EMCPTransport_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EMCPTransport.InnerSingleton;
}
// ********** End Enum EMCPTransport ***************************************************************

// ********** Begin Enum EMCPAuth ******************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EMCPAuth;
static UEnum* EMCPAuth_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EMCPAuth.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EMCPAuth.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_MCPClientToolset_EMCPAuth, (UObject*)Z_Construct_UPackage__Script_MCPClientToolset(), TEXT("EMCPAuth"));
	}
	return Z_Registration_Info_UEnum_EMCPAuth.OuterSingleton;
}
template<> MCPCLIENTTOOLSET_NON_ATTRIBUTED_API UEnum* StaticEnum<EMCPAuth>()
{
	return EMCPAuth_StaticEnum();
}
struct Z_Construct_UEnum_MCPClientToolset_EMCPAuth_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BearerToken.DisplayName", "Bearer Token (API Key)" },
		{ "BearerToken.Name", "EMCPAuth::BearerToken" },
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Authentication method for an MCP server connection. */" },
#endif
		{ "ModuleRelativePath", "Public/MCPClientToolset/MCPToolsetSettings.h" },
		{ "None.DisplayName", "None" },
		{ "None.Name", "EMCPAuth::None" },
		{ "OAuth2.DisplayName", "OAuth 2.0 (Authorization Code + PKCE)" },
		{ "OAuth2.Name", "EMCPAuth::OAuth2" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Authentication method for an MCP server connection." },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMCPAuth::None", (int64)EMCPAuth::None },
		{ "EMCPAuth::BearerToken", (int64)EMCPAuth::BearerToken },
		{ "EMCPAuth::OAuth2", (int64)EMCPAuth::OAuth2 },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_MCPClientToolset_EMCPAuth_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_MCPClientToolset_EMCPAuth_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_MCPClientToolset,
	nullptr,
	"EMCPAuth",
	"EMCPAuth",
	Z_Construct_UEnum_MCPClientToolset_EMCPAuth_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_MCPClientToolset_EMCPAuth_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_MCPClientToolset_EMCPAuth_Statics::Enum_MetaDataParams), Z_Construct_UEnum_MCPClientToolset_EMCPAuth_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_MCPClientToolset_EMCPAuth()
{
	if (!Z_Registration_Info_UEnum_EMCPAuth.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EMCPAuth.InnerSingleton, Z_Construct_UEnum_MCPClientToolset_EMCPAuth_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EMCPAuth.InnerSingleton;
}
// ********** End Enum EMCPAuth ********************************************************************

// ********** Begin ScriptStruct FMCPServerConfig **************************************************
struct Z_Construct_UScriptStruct_FMCPServerConfig_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FMCPServerConfig); }
	static inline consteval int16 GetStructAlignment() { return alignof(FMCPServerConfig); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Configuration for a single MCP server connection. */" },
#endif
		{ "ModuleRelativePath", "Public/MCPClientToolset/MCPToolsetSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Configuration for a single MCP server connection." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "MCP Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Display name for this MCP server (used as the toolset name). */" },
#endif
		{ "ModuleRelativePath", "Public/MCPClientToolset/MCPToolsetSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Display name for this MCP server (used as the toolset name)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "Category", "MCP Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Human-readable description of this toolset, surfaced to the AI as context.\n\x09 *  If empty, the name is used instead. */" },
#endif
		{ "ModuleRelativePath", "Public/MCPClientToolset/MCPToolsetSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Human-readable description of this toolset, surfaced to the AI as context.\nIf empty, the name is used instead." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ServerUrl_MetaData[] = {
		{ "Category", "MCP Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Base URL of the MCP server (e.g., http://localhost:3000). */" },
#endif
		{ "ModuleRelativePath", "Public/MCPClientToolset/MCPToolsetSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Base URL of the MCP server (e.g., http://localhost:3000)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ApiKey_MetaData[] = {
		{ "Category", "MCP Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional API key sent as \"Authorization: Bearer <ApiKey>\". */" },
#endif
		{ "ModuleRelativePath", "Public/MCPClientToolset/MCPToolsetSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional API key sent as \"Authorization: Bearer <ApiKey>\"." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnabled_MetaData[] = {
		{ "Category", "MCP Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether this server config is active. Disabled configs are skipped on startup. */" },
#endif
		{ "ModuleRelativePath", "Public/MCPClientToolset/MCPToolsetSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether this server config is active. Disabled configs are skipped on startup." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Transport_MetaData[] = {
		{ "Category", "Connection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Transport protocol to use when connecting to this server. */" },
#endif
		{ "ModuleRelativePath", "Public/MCPClientToolset/MCPToolsetSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Transport protocol to use when connecting to this server." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Auth_MetaData[] = {
		{ "Category", "Authentication" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Authentication method to use when connecting to this server. */" },
#endif
		{ "ModuleRelativePath", "Public/MCPClientToolset/MCPToolsetSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Authentication method to use when connecting to this server." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OAuthClientId_MetaData[] = {
		{ "Category", "Authentication" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** OAuth 2.0 client ID. Leave empty to use RFC 7591 dynamic client registration\n\x09 *  (the server assigns a client ID automatically \xe2\x80\x94 no app registration required). */" },
#endif
		{ "ModuleRelativePath", "Public/MCPClientToolset/MCPToolsetSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "OAuth 2.0 client ID. Leave empty to use RFC 7591 dynamic client registration\n(the server assigns a client ID automatically \xe2\x80\x94 no app registration required)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OAuthScope_MetaData[] = {
		{ "Category", "Authentication" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** OAuth 2.0 scope string, e.g. \"read:me offline_access\" (required when Auth = OAuth2). */" },
#endif
		{ "ModuleRelativePath", "Public/MCPClientToolset/MCPToolsetSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "OAuth 2.0 scope string, e.g. \"read:me offline_access\" (required when Auth = OAuth2)." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FMCPServerConfig constinit property declarations ******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Description;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ServerUrl;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ApiKey;
	static void NewProp_bEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Transport_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Transport;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Auth_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Auth;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OAuthClientId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OAuthScope;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FMCPServerConfig constinit property declarations ********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMCPServerConfig>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FMCPServerConfig_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FMCPServerConfig;
class UScriptStruct* FMCPServerConfig::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FMCPServerConfig.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FMCPServerConfig.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMCPServerConfig, (UObject*)Z_Construct_UPackage__Script_MCPClientToolset(), TEXT("MCPServerConfig"));
	}
	return Z_Registration_Info_UScriptStruct_FMCPServerConfig.OuterSingleton;
	}

// ********** Begin ScriptStruct FMCPServerConfig Property Definitions *****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMCPServerConfig_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMCPServerConfig, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMCPServerConfig_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMCPServerConfig, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMCPServerConfig_Statics::NewProp_ServerUrl = { "ServerUrl", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMCPServerConfig, ServerUrl), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ServerUrl_MetaData), NewProp_ServerUrl_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMCPServerConfig_Statics::NewProp_ApiKey = { "ApiKey", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMCPServerConfig, ApiKey), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ApiKey_MetaData), NewProp_ApiKey_MetaData) };
void Z_Construct_UScriptStruct_FMCPServerConfig_Statics::NewProp_bEnabled_SetBit(void* Obj)
{
	((FMCPServerConfig*)Obj)->bEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FMCPServerConfig_Statics::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FMCPServerConfig), &Z_Construct_UScriptStruct_FMCPServerConfig_Statics::NewProp_bEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnabled_MetaData), NewProp_bEnabled_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FMCPServerConfig_Statics::NewProp_Transport_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FMCPServerConfig_Statics::NewProp_Transport = { "Transport", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMCPServerConfig, Transport), Z_Construct_UEnum_MCPClientToolset_EMCPTransport, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Transport_MetaData), NewProp_Transport_MetaData) }; // 2765916987
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FMCPServerConfig_Statics::NewProp_Auth_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FMCPServerConfig_Statics::NewProp_Auth = { "Auth", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMCPServerConfig, Auth), Z_Construct_UEnum_MCPClientToolset_EMCPAuth, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Auth_MetaData), NewProp_Auth_MetaData) }; // 336429233
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMCPServerConfig_Statics::NewProp_OAuthClientId = { "OAuthClientId", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMCPServerConfig, OAuthClientId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OAuthClientId_MetaData), NewProp_OAuthClientId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMCPServerConfig_Statics::NewProp_OAuthScope = { "OAuthScope", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMCPServerConfig, OAuthScope), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OAuthScope_MetaData), NewProp_OAuthScope_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMCPServerConfig_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMCPServerConfig_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMCPServerConfig_Statics::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMCPServerConfig_Statics::NewProp_ServerUrl,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMCPServerConfig_Statics::NewProp_ApiKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMCPServerConfig_Statics::NewProp_bEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMCPServerConfig_Statics::NewProp_Transport_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMCPServerConfig_Statics::NewProp_Transport,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMCPServerConfig_Statics::NewProp_Auth_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMCPServerConfig_Statics::NewProp_Auth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMCPServerConfig_Statics::NewProp_OAuthClientId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMCPServerConfig_Statics::NewProp_OAuthScope,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMCPServerConfig_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FMCPServerConfig Property Definitions *******************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMCPServerConfig_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_MCPClientToolset,
	nullptr,
	&NewStructOps,
	"MCPServerConfig",
	Z_Construct_UScriptStruct_FMCPServerConfig_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMCPServerConfig_Statics::PropPointers),
	sizeof(FMCPServerConfig),
	alignof(FMCPServerConfig),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMCPServerConfig_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMCPServerConfig_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FMCPServerConfig()
{
	if (!Z_Registration_Info_UScriptStruct_FMCPServerConfig.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FMCPServerConfig.InnerSingleton, Z_Construct_UScriptStruct_FMCPServerConfig_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FMCPServerConfig.InnerSingleton);
}
// ********** End ScriptStruct FMCPServerConfig ****************************************************

// ********** Begin Class UMCPToolsetSettings ******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UMCPToolsetSettings;
UClass* UMCPToolsetSettings::GetPrivateStaticClass()
{
	using TClass = UMCPToolsetSettings;
	if (!Z_Registration_Info_UClass_UMCPToolsetSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("MCPToolsetSettings"),
			Z_Registration_Info_UClass_UMCPToolsetSettings.InnerSingleton,
			StaticRegisterNativesUMCPToolsetSettings,
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
	return Z_Registration_Info_UClass_UMCPToolsetSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UMCPToolsetSettings_NoRegister()
{
	return UMCPToolsetSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UMCPToolsetSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Editor settings for MCP (Model Context Protocol) server connections.\n *  Configure servers under Editor Preferences > Plugins > MCP Toolset Servers. */" },
#endif
		{ "DisplayName", "MCP Toolset Servers" },
		{ "IncludePath", "MCPClientToolset/MCPToolsetSettings.h" },
		{ "ModuleRelativePath", "Public/MCPClientToolset/MCPToolsetSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Editor settings for MCP (Model Context Protocol) server connections.\nConfigure servers under Editor Preferences > Plugins > MCP Toolset Servers." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MCPServers_MetaData[] = {
		{ "Category", "MCP Servers" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** List of MCP servers to connect to on editor startup. */" },
#endif
		{ "ModuleRelativePath", "Public/MCPClientToolset/MCPToolsetSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "List of MCP servers to connect to on editor startup." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UMCPToolsetSettings constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_MCPServers_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_MCPServers;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UMCPToolsetSettings constinit property declarations ************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMCPToolsetSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UMCPToolsetSettings_Statics

// ********** Begin Class UMCPToolsetSettings Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UMCPToolsetSettings_Statics::NewProp_MCPServers_Inner = { "MCPServers", nullptr, (EPropertyFlags)0x0000000000004000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FMCPServerConfig, METADATA_PARAMS(0, nullptr) }; // 3495991264
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UMCPToolsetSettings_Statics::NewProp_MCPServers = { "MCPServers", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMCPToolsetSettings, MCPServers), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MCPServers_MetaData), NewProp_MCPServers_MetaData) }; // 3495991264
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMCPToolsetSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMCPToolsetSettings_Statics::NewProp_MCPServers_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMCPToolsetSettings_Statics::NewProp_MCPServers,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMCPToolsetSettings_Statics::PropPointers) < 2048);
// ********** End Class UMCPToolsetSettings Property Definitions ***********************************
UObject* (*const Z_Construct_UClass_UMCPToolsetSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_MCPClientToolset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMCPToolsetSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMCPToolsetSettings_Statics::ClassParams = {
	&UMCPToolsetSettings::StaticClass,
	"EditorPerProjectUserSettings",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UMCPToolsetSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UMCPToolsetSettings_Statics::PropPointers),
	0,
	0x000800A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMCPToolsetSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UMCPToolsetSettings_Statics::Class_MetaDataParams)
};
void UMCPToolsetSettings::StaticRegisterNativesUMCPToolsetSettings()
{
}
UClass* Z_Construct_UClass_UMCPToolsetSettings()
{
	if (!Z_Registration_Info_UClass_UMCPToolsetSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMCPToolsetSettings.OuterSingleton, Z_Construct_UClass_UMCPToolsetSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMCPToolsetSettings.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UMCPToolsetSettings);
UMCPToolsetSettings::~UMCPToolsetSettings() {}
// ********** End Class UMCPToolsetSettings ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_MCPClientToolset_Source_MCPClientToolset_Public_MCPClientToolset_MCPToolsetSettings_h__Script_MCPClientToolset_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EMCPTransport_StaticEnum, TEXT("EMCPTransport"), &Z_Registration_Info_UEnum_EMCPTransport, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2765916987U) },
		{ EMCPAuth_StaticEnum, TEXT("EMCPAuth"), &Z_Registration_Info_UEnum_EMCPAuth, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 336429233U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FMCPServerConfig::StaticStruct, Z_Construct_UScriptStruct_FMCPServerConfig_Statics::NewStructOps, TEXT("MCPServerConfig"),&Z_Registration_Info_UScriptStruct_FMCPServerConfig, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMCPServerConfig), 3495991264U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMCPToolsetSettings, UMCPToolsetSettings::StaticClass, TEXT("UMCPToolsetSettings"), &Z_Registration_Info_UClass_UMCPToolsetSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMCPToolsetSettings), 3535195127U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_MCPClientToolset_Source_MCPClientToolset_Public_MCPClientToolset_MCPToolsetSettings_h__Script_MCPClientToolset_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_MCPClientToolset_Source_MCPClientToolset_Public_MCPClientToolset_MCPToolsetSettings_h__Script_MCPClientToolset_1174362497{
	TEXT("/Script/MCPClientToolset"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_MCPClientToolset_Source_MCPClientToolset_Public_MCPClientToolset_MCPToolsetSettings_h__Script_MCPClientToolset_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_MCPClientToolset_Source_MCPClientToolset_Public_MCPClientToolset_MCPToolsetSettings_h__Script_MCPClientToolset_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_MCPClientToolset_Source_MCPClientToolset_Public_MCPClientToolset_MCPToolsetSettings_h__Script_MCPClientToolset_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_MCPClientToolset_Source_MCPClientToolset_Public_MCPClientToolset_MCPToolsetSettings_h__Script_MCPClientToolset_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_MCPClientToolset_Source_MCPClientToolset_Public_MCPClientToolset_MCPToolsetSettings_h__Script_MCPClientToolset_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_MCPClientToolset_Source_MCPClientToolset_Public_MCPClientToolset_MCPToolsetSettings_h__Script_MCPClientToolset_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
