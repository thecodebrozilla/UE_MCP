// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MCPClientToolset/MCPToolsetSettings.h"

#ifdef MCPCLIENTTOOLSET_MCPToolsetSettings_generated_h
#error "MCPToolsetSettings.generated.h already included, missing '#pragma once' in MCPToolsetSettings.h"
#endif
#define MCPCLIENTTOOLSET_MCPToolsetSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FMCPServerConfig **************************************************
struct Z_Construct_UScriptStruct_FMCPServerConfig_Statics;
#define FID_UE_MCP_Plugins_Toolsets_MCPClientToolset_Source_MCPClientToolset_Public_MCPClientToolset_MCPToolsetSettings_h_30_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FMCPServerConfig_Statics; \
	MCPCLIENTTOOLSET_API static class UScriptStruct* StaticStruct();


struct FMCPServerConfig;
// ********** End ScriptStruct FMCPServerConfig ****************************************************

// ********** Begin Class UMCPToolsetSettings ******************************************************
struct Z_Construct_UClass_UMCPToolsetSettings_Statics;
MCPCLIENTTOOLSET_API UClass* Z_Construct_UClass_UMCPToolsetSettings_NoRegister();

#define FID_UE_MCP_Plugins_Toolsets_MCPClientToolset_Source_MCPClientToolset_Public_MCPClientToolset_MCPToolsetSettings_h_76_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMCPToolsetSettings(); \
	friend struct ::Z_Construct_UClass_UMCPToolsetSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend MCPCLIENTTOOLSET_API UClass* ::Z_Construct_UClass_UMCPToolsetSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UMCPToolsetSettings, UDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MCPClientToolset"), Z_Construct_UClass_UMCPToolsetSettings_NoRegister) \
	DECLARE_SERIALIZER(UMCPToolsetSettings) \
	static constexpr const TCHAR* StaticConfigName() {return TEXT("EditorPerProjectUserSettings");} \



#define FID_UE_MCP_Plugins_Toolsets_MCPClientToolset_Source_MCPClientToolset_Public_MCPClientToolset_MCPToolsetSettings_h_76_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UMCPToolsetSettings(UMCPToolsetSettings&&) = delete; \
	UMCPToolsetSettings(const UMCPToolsetSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(MCPCLIENTTOOLSET_API, UMCPToolsetSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMCPToolsetSettings); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UMCPToolsetSettings) \
	MCPCLIENTTOOLSET_API virtual ~UMCPToolsetSettings();


#define FID_UE_MCP_Plugins_Toolsets_MCPClientToolset_Source_MCPClientToolset_Public_MCPClientToolset_MCPToolsetSettings_h_73_PROLOG
#define FID_UE_MCP_Plugins_Toolsets_MCPClientToolset_Source_MCPClientToolset_Public_MCPClientToolset_MCPToolsetSettings_h_76_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_Toolsets_MCPClientToolset_Source_MCPClientToolset_Public_MCPClientToolset_MCPToolsetSettings_h_76_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_MCPClientToolset_Source_MCPClientToolset_Public_MCPClientToolset_MCPToolsetSettings_h_76_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UMCPToolsetSettings;

// ********** End Class UMCPToolsetSettings ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_Toolsets_MCPClientToolset_Source_MCPClientToolset_Public_MCPClientToolset_MCPToolsetSettings_h

// ********** Begin Enum EMCPTransport *************************************************************
#define FOREACH_ENUM_EMCPTRANSPORT(op) \
	op(EMCPTransport::SSE) \
	op(EMCPTransport::StreamableHTTP) 

enum class EMCPTransport : uint8;
template<> struct TIsUEnumClass<EMCPTransport> { enum { Value = true }; };
template<> MCPCLIENTTOOLSET_NON_ATTRIBUTED_API UEnum* StaticEnum<EMCPTransport>();
// ********** End Enum EMCPTransport ***************************************************************

// ********** Begin Enum EMCPAuth ******************************************************************
#define FOREACH_ENUM_EMCPAUTH(op) \
	op(EMCPAuth::None) \
	op(EMCPAuth::BearerToken) \
	op(EMCPAuth::OAuth2) 

enum class EMCPAuth : uint8;
template<> struct TIsUEnumClass<EMCPAuth> { enum { Value = true }; };
template<> MCPCLIENTTOOLSET_NON_ATTRIBUTED_API UEnum* StaticEnum<EMCPAuth>();
// ********** End Enum EMCPAuth ********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
