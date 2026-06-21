// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PCGToolsetSettings.h"

#ifdef PCGTOOLSET_PCGToolsetSettings_generated_h
#error "PCGToolsetSettings.generated.h already included, missing '#pragma once' in PCGToolsetSettings.h"
#endif
#define PCGTOOLSET_PCGToolsetSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UPCGToolsetSettings ******************************************************
struct Z_Construct_UClass_UPCGToolsetSettings_Statics;
PCGTOOLSET_API UClass* Z_Construct_UClass_UPCGToolsetSettings_NoRegister();

#define FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolsetSettings_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPCGToolsetSettings(); \
	friend struct ::Z_Construct_UClass_UPCGToolsetSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PCGTOOLSET_API UClass* ::Z_Construct_UClass_UPCGToolsetSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UPCGToolsetSettings, UDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/PCGToolset"), Z_Construct_UClass_UPCGToolsetSettings_NoRegister) \
	DECLARE_SERIALIZER(UPCGToolsetSettings) \
	static constexpr const TCHAR* StaticConfigName() {return TEXT("Editor");} \



#define FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolsetSettings_h_15_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPCGToolsetSettings(UPCGToolsetSettings&&) = delete; \
	UPCGToolsetSettings(const UPCGToolsetSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPCGToolsetSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPCGToolsetSettings); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UPCGToolsetSettings) \
	NO_API virtual ~UPCGToolsetSettings();


#define FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolsetSettings_h_12_PROLOG
#define FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolsetSettings_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolsetSettings_h_15_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolsetSettings_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPCGToolsetSettings;

// ********** End Class UPCGToolsetSettings ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolsetSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
