// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "LogsToolset.h"

#ifdef EDITORTOOLSET_LogsToolset_generated_h
#error "LogsToolset.generated.h already included, missing '#pragma once' in LogsToolset.h"
#endif
#define EDITORTOOLSET_LogsToolset_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class ULogsToolset *************************************************************
#define FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_LogsToolset_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetVerbosity); \
	DECLARE_FUNCTION(execGetVerbosity); \
	DECLARE_FUNCTION(execGetLogCategories); \
	DECLARE_FUNCTION(execGetLogEntries);


struct Z_Construct_UClass_ULogsToolset_Statics;
EDITORTOOLSET_API UClass* Z_Construct_UClass_ULogsToolset_NoRegister();

#define FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_LogsToolset_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULogsToolset(); \
	friend struct ::Z_Construct_UClass_ULogsToolset_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend EDITORTOOLSET_API UClass* ::Z_Construct_UClass_ULogsToolset_NoRegister(); \
public: \
	DECLARE_CLASS2(ULogsToolset, UToolsetDefinition, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/EditorToolset"), Z_Construct_UClass_ULogsToolset_NoRegister) \
	DECLARE_SERIALIZER(ULogsToolset)


#define FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_LogsToolset_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	EDITORTOOLSET_API ULogsToolset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	ULogsToolset(ULogsToolset&&) = delete; \
	ULogsToolset(const ULogsToolset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(EDITORTOOLSET_API, ULogsToolset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULogsToolset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULogsToolset) \
	EDITORTOOLSET_API virtual ~ULogsToolset();


#define FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_LogsToolset_h_13_PROLOG
#define FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_LogsToolset_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_LogsToolset_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_LogsToolset_h_16_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_LogsToolset_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ULogsToolset;

// ********** End Class ULogsToolset ***************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_LogsToolset_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
