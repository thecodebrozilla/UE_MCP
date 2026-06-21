// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "TerminalSettings.h"

#ifdef TERMINAL_TerminalSettings_generated_h
#error "TerminalSettings.generated.h already included, missing '#pragma once' in TerminalSettings.h"
#endif
#define TERMINAL_TerminalSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UTerminalSettings ********************************************************
struct Z_Construct_UClass_UTerminalSettings_Statics;
TERMINAL_API UClass* Z_Construct_UClass_UTerminalSettings_NoRegister();

#define FID_UE_MCP_Plugins_Terminal_Source_Terminal_Public_TerminalSettings_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUTerminalSettings(); \
	friend struct ::Z_Construct_UClass_UTerminalSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend TERMINAL_API UClass* ::Z_Construct_UClass_UTerminalSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UTerminalSettings, UDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Terminal"), Z_Construct_UClass_UTerminalSettings_NoRegister) \
	DECLARE_SERIALIZER(UTerminalSettings) \
	static constexpr const TCHAR* StaticConfigName() {return TEXT("EditorPerProjectUserSettings");} \



#define FID_UE_MCP_Plugins_Terminal_Source_Terminal_Public_TerminalSettings_h_12_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	TERMINAL_API UTerminalSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UTerminalSettings(UTerminalSettings&&) = delete; \
	UTerminalSettings(const UTerminalSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(TERMINAL_API, UTerminalSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTerminalSettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UTerminalSettings) \
	TERMINAL_API virtual ~UTerminalSettings();


#define FID_UE_MCP_Plugins_Terminal_Source_Terminal_Public_TerminalSettings_h_9_PROLOG
#define FID_UE_MCP_Plugins_Terminal_Source_Terminal_Public_TerminalSettings_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_Terminal_Source_Terminal_Public_TerminalSettings_h_12_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Terminal_Source_Terminal_Public_TerminalSettings_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UTerminalSettings;

// ********** End Class UTerminalSettings **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_Terminal_Source_Terminal_Public_TerminalSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
