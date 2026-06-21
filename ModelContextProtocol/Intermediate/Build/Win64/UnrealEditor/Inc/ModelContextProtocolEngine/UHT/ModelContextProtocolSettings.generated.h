// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ModelContextProtocolSettings.h"

#ifdef MODELCONTEXTPROTOCOLENGINE_ModelContextProtocolSettings_generated_h
#error "ModelContextProtocolSettings.generated.h already included, missing '#pragma once' in ModelContextProtocolSettings.h"
#endif
#define MODELCONTEXTPROTOCOLENGINE_ModelContextProtocolSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UModelContextProtocolSettings ********************************************
struct Z_Construct_UClass_UModelContextProtocolSettings_Statics;
MODELCONTEXTPROTOCOLENGINE_API UClass* Z_Construct_UClass_UModelContextProtocolSettings_NoRegister();

#define FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolSettings_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUModelContextProtocolSettings(); \
	friend struct ::Z_Construct_UClass_UModelContextProtocolSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend MODELCONTEXTPROTOCOLENGINE_API UClass* ::Z_Construct_UClass_UModelContextProtocolSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UModelContextProtocolSettings, UDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ModelContextProtocolEngine"), Z_Construct_UClass_UModelContextProtocolSettings_NoRegister) \
	DECLARE_SERIALIZER(UModelContextProtocolSettings) \
	static constexpr const TCHAR* StaticConfigName() {return TEXT("EditorPerProjectUserSettings");} \



#define FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolSettings_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	MODELCONTEXTPROTOCOLENGINE_API UModelContextProtocolSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UModelContextProtocolSettings(UModelContextProtocolSettings&&) = delete; \
	UModelContextProtocolSettings(const UModelContextProtocolSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(MODELCONTEXTPROTOCOLENGINE_API, UModelContextProtocolSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UModelContextProtocolSettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UModelContextProtocolSettings) \
	MODELCONTEXTPROTOCOLENGINE_API virtual ~UModelContextProtocolSettings();


#define FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolSettings_h_17_PROLOG
#define FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolSettings_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolSettings_h_20_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolSettings_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UModelContextProtocolSettings;

// ********** End Class UModelContextProtocolSettings **********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
