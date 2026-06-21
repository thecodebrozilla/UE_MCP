// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ToolsetRegistry/UToolsetRegistry.h"

#ifdef TOOLSETREGISTRY_UToolsetRegistry_generated_h
#error "UToolsetRegistry.generated.h already included, missing '#pragma once' in UToolsetRegistry.h"
#endif
#define TOOLSETREGISTRY_UToolsetRegistry_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UClass;
class UToolCallAsyncResultString;
class UToolsetDefinition;

// ********** Begin Class UToolsetRegistry *********************************************************
#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_UToolsetRegistry_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetAllToolsetJsonSchemas); \
	DECLARE_FUNCTION(execGetToolsetJsonSchema); \
	DECLARE_FUNCTION(execExecuteTool); \
	DECLARE_FUNCTION(execIsToolsetRegistered); \
	DECLARE_FUNCTION(execIsToolsetClassRegistered); \
	DECLARE_FUNCTION(execUnregisterToolsetClass); \
	DECLARE_FUNCTION(execRegisterToolsetClass); \
	DECLARE_FUNCTION(execIsAvailable);


struct Z_Construct_UClass_UToolsetRegistry_Statics;
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetRegistry_NoRegister();

#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_UToolsetRegistry_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUToolsetRegistry(); \
	friend struct ::Z_Construct_UClass_UToolsetRegistry_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend TOOLSETREGISTRY_API UClass* ::Z_Construct_UClass_UToolsetRegistry_NoRegister(); \
public: \
	DECLARE_CLASS2(UToolsetRegistry, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ToolsetRegistry"), Z_Construct_UClass_UToolsetRegistry_NoRegister) \
	DECLARE_SERIALIZER(UToolsetRegistry)


#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_UToolsetRegistry_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	TOOLSETREGISTRY_API UToolsetRegistry(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UToolsetRegistry(UToolsetRegistry&&) = delete; \
	UToolsetRegistry(const UToolsetRegistry&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(TOOLSETREGISTRY_API, UToolsetRegistry); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UToolsetRegistry); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UToolsetRegistry) \
	TOOLSETREGISTRY_API virtual ~UToolsetRegistry();


#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_UToolsetRegistry_h_15_PROLOG
#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_UToolsetRegistry_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_UToolsetRegistry_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_UToolsetRegistry_h_18_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_UToolsetRegistry_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UToolsetRegistry;

// ********** End Class UToolsetRegistry ***********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_UToolsetRegistry_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
