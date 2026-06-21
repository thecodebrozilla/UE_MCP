// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DataRegistryTools.h"

#ifdef DATAREGISTRYTOOLSET_DataRegistryTools_generated_h
#error "DataRegistryTools.generated.h already included, missing '#pragma once' in DataRegistryTools.h"
#endif
#define DATAREGISTRYTOOLSET_DataRegistryTools_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UScriptStruct;
struct FDataRegistryInfo;
struct FDataRegistrySourceSummary;
struct FInstancedStruct;

// ********** Begin ScriptStruct FDataRegistryInfo *************************************************
struct Z_Construct_UScriptStruct_FDataRegistryInfo_Statics;
#define FID_UE_MCP_Plugins_Toolsets_DataRegistryToolset_Source_DataRegistryToolset_Private_DataRegistryTools_h_20_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FDataRegistryInfo_Statics; \
	DATAREGISTRYTOOLSET_API static class UScriptStruct* StaticStruct();


struct FDataRegistryInfo;
// ********** End ScriptStruct FDataRegistryInfo ***************************************************

// ********** Begin ScriptStruct FDataRegistrySourceSummary ****************************************
struct Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics;
#define FID_UE_MCP_Plugins_Toolsets_DataRegistryToolset_Source_DataRegistryToolset_Private_DataRegistryTools_h_52_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics; \
	DATAREGISTRYTOOLSET_API static class UScriptStruct* StaticStruct();


struct FDataRegistrySourceSummary;
// ********** End ScriptStruct FDataRegistrySourceSummary ******************************************

// ********** Begin Class UDataRegistryTools *******************************************************
#define FID_UE_MCP_Plugins_Toolsets_DataRegistryToolset_Source_DataRegistryToolset_Private_DataRegistryTools_h_87_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetItems); \
	DECLARE_FUNCTION(execListRuntimeSources); \
	DECLARE_FUNCTION(execListDataSources); \
	DECLARE_FUNCTION(execListItems); \
	DECLARE_FUNCTION(execGetSchema); \
	DECLARE_FUNCTION(execGetRegistryInfo); \
	DECLARE_FUNCTION(execListRegistries);


struct Z_Construct_UClass_UDataRegistryTools_Statics;
DATAREGISTRYTOOLSET_API UClass* Z_Construct_UClass_UDataRegistryTools_NoRegister();

#define FID_UE_MCP_Plugins_Toolsets_DataRegistryToolset_Source_DataRegistryToolset_Private_DataRegistryTools_h_87_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDataRegistryTools(); \
	friend struct ::Z_Construct_UClass_UDataRegistryTools_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend DATAREGISTRYTOOLSET_API UClass* ::Z_Construct_UClass_UDataRegistryTools_NoRegister(); \
public: \
	DECLARE_CLASS2(UDataRegistryTools, UToolsetDefinition, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DataRegistryToolset"), Z_Construct_UClass_UDataRegistryTools_NoRegister) \
	DECLARE_SERIALIZER(UDataRegistryTools)


#define FID_UE_MCP_Plugins_Toolsets_DataRegistryToolset_Source_DataRegistryToolset_Private_DataRegistryTools_h_87_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDataRegistryTools(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDataRegistryTools(UDataRegistryTools&&) = delete; \
	UDataRegistryTools(const UDataRegistryTools&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDataRegistryTools); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDataRegistryTools); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDataRegistryTools) \
	NO_API virtual ~UDataRegistryTools();


#define FID_UE_MCP_Plugins_Toolsets_DataRegistryToolset_Source_DataRegistryToolset_Private_DataRegistryTools_h_84_PROLOG
#define FID_UE_MCP_Plugins_Toolsets_DataRegistryToolset_Source_DataRegistryToolset_Private_DataRegistryTools_h_87_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_Toolsets_DataRegistryToolset_Source_DataRegistryToolset_Private_DataRegistryTools_h_87_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_DataRegistryToolset_Source_DataRegistryToolset_Private_DataRegistryTools_h_87_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_DataRegistryToolset_Source_DataRegistryToolset_Private_DataRegistryTools_h_87_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDataRegistryTools;

// ********** End Class UDataRegistryTools *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_Toolsets_DataRegistryToolset_Source_DataRegistryToolset_Private_DataRegistryTools_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
