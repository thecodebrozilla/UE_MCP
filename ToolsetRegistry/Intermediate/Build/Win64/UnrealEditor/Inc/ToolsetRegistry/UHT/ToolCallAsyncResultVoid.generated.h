// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ToolsetRegistry/ToolCallAsyncResultVoid.h"

#ifdef TOOLSETREGISTRY_ToolCallAsyncResultVoid_generated_h
#error "ToolCallAsyncResultVoid.generated.h already included, missing '#pragma once' in ToolCallAsyncResultVoid.h"
#endif
#define TOOLSETREGISTRY_ToolCallAsyncResultVoid_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UToolCallAsyncResultVoid *************************************************
#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultVoid_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetCompleted);


struct Z_Construct_UClass_UToolCallAsyncResultVoid_Statics;
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolCallAsyncResultVoid_NoRegister();

#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultVoid_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUToolCallAsyncResultVoid(); \
	friend struct ::Z_Construct_UClass_UToolCallAsyncResultVoid_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend TOOLSETREGISTRY_API UClass* ::Z_Construct_UClass_UToolCallAsyncResultVoid_NoRegister(); \
public: \
	DECLARE_CLASS2(UToolCallAsyncResultVoid, UToolCallAsyncResult, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ToolsetRegistry"), Z_Construct_UClass_UToolCallAsyncResultVoid_NoRegister) \
	DECLARE_SERIALIZER(UToolCallAsyncResultVoid)


#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultVoid_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UToolCallAsyncResultVoid(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UToolCallAsyncResultVoid(UToolCallAsyncResultVoid&&) = delete; \
	UToolCallAsyncResultVoid(const UToolCallAsyncResultVoid&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UToolCallAsyncResultVoid); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UToolCallAsyncResultVoid); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UToolCallAsyncResultVoid) \
	NO_API virtual ~UToolCallAsyncResultVoid();


#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultVoid_h_17_PROLOG
#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultVoid_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultVoid_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultVoid_h_20_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultVoid_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UToolCallAsyncResultVoid;

// ********** End Class UToolCallAsyncResultVoid ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultVoid_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
