// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ToolsetRegistry/ToolCallAsyncResult.h"

#ifdef TOOLSETREGISTRY_ToolCallAsyncResult_generated_h
#error "ToolCallAsyncResult.generated.h already included, missing '#pragma once' in ToolCallAsyncResult.h"
#endif
#define TOOLSETREGISTRY_ToolCallAsyncResult_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UToolCallAsyncResult;

// ********** Begin Delegate FToolCallAsyncResultCompleted *****************************************
#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResult_h_25_DELEGATE \
TOOLSETREGISTRY_API void FToolCallAsyncResultCompleted_DelegateWrapper(const FMulticastScriptDelegate& ToolCallAsyncResultCompleted, UToolCallAsyncResult* Result);


// ********** End Delegate FToolCallAsyncResultCompleted *******************************************

// ********** Begin Class UToolCallAsyncResult *****************************************************
#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResult_h_44_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execBroadcastOnCompletedIfComplete); \
	DECLARE_FUNCTION(execSetError); \
	DECLARE_FUNCTION(execGetValueAsJsonString);


struct Z_Construct_UClass_UToolCallAsyncResult_Statics;
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolCallAsyncResult_NoRegister();

#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResult_h_44_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUToolCallAsyncResult(); \
	friend struct ::Z_Construct_UClass_UToolCallAsyncResult_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend TOOLSETREGISTRY_API UClass* ::Z_Construct_UClass_UToolCallAsyncResult_NoRegister(); \
public: \
	DECLARE_CLASS2(UToolCallAsyncResult, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ToolsetRegistry"), Z_Construct_UClass_UToolCallAsyncResult_NoRegister) \
	DECLARE_SERIALIZER(UToolCallAsyncResult)


#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResult_h_44_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	TOOLSETREGISTRY_API UToolCallAsyncResult(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UToolCallAsyncResult(UToolCallAsyncResult&&) = delete; \
	UToolCallAsyncResult(const UToolCallAsyncResult&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(TOOLSETREGISTRY_API, UToolCallAsyncResult); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UToolCallAsyncResult); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UToolCallAsyncResult) \
	TOOLSETREGISTRY_API virtual ~UToolCallAsyncResult();


#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResult_h_41_PROLOG
#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResult_h_44_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResult_h_44_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResult_h_44_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResult_h_44_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UToolCallAsyncResult;

// ********** End Class UToolCallAsyncResult *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResult_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
