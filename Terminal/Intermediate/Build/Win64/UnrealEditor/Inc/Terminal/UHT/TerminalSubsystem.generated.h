// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "TerminalSubsystem.h"

#ifdef TERMINAL_TerminalSubsystem_generated_h
#error "TerminalSubsystem.generated.h already included, missing '#pragma once' in TerminalSubsystem.h"
#endif
#define TERMINAL_TerminalSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UTerminalSubsystem *******************************************************
struct Z_Construct_UClass_UTerminalSubsystem_Statics;
TERMINAL_API UClass* Z_Construct_UClass_UTerminalSubsystem_NoRegister();

#define FID_UE_MCP_Plugins_Terminal_Source_Terminal_Public_TerminalSubsystem_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUTerminalSubsystem(); \
	friend struct ::Z_Construct_UClass_UTerminalSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend TERMINAL_API UClass* ::Z_Construct_UClass_UTerminalSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UTerminalSubsystem, UEditorSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Terminal"), Z_Construct_UClass_UTerminalSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UTerminalSubsystem)


#define FID_UE_MCP_Plugins_Terminal_Source_Terminal_Public_TerminalSubsystem_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	TERMINAL_API UTerminalSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UTerminalSubsystem(UTerminalSubsystem&&) = delete; \
	UTerminalSubsystem(const UTerminalSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(TERMINAL_API, UTerminalSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTerminalSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UTerminalSubsystem) \
	TERMINAL_API virtual ~UTerminalSubsystem();


#define FID_UE_MCP_Plugins_Terminal_Source_Terminal_Public_TerminalSubsystem_h_13_PROLOG
#define FID_UE_MCP_Plugins_Terminal_Source_Terminal_Public_TerminalSubsystem_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_Terminal_Source_Terminal_Public_TerminalSubsystem_h_16_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Terminal_Source_Terminal_Public_TerminalSubsystem_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UTerminalSubsystem;

// ********** End Class UTerminalSubsystem *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_Terminal_Source_Terminal_Public_TerminalSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
