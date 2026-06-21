// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ToolsetRegistry/ToolCallAsyncResultImage.h"

#ifdef TOOLSETREGISTRY_ToolCallAsyncResultImage_generated_h
#error "ToolCallAsyncResultImage.generated.h already included, missing '#pragma once' in ToolCallAsyncResultImage.h"
#endif
#define TOOLSETREGISTRY_ToolCallAsyncResultImage_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FToolsetImage;

// ********** Begin Class UToolCallAsyncResultImage ************************************************
#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultImage_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetValue);


struct Z_Construct_UClass_UToolCallAsyncResultImage_Statics;
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolCallAsyncResultImage_NoRegister();

#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultImage_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUToolCallAsyncResultImage(); \
	friend struct ::Z_Construct_UClass_UToolCallAsyncResultImage_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend TOOLSETREGISTRY_API UClass* ::Z_Construct_UClass_UToolCallAsyncResultImage_NoRegister(); \
public: \
	DECLARE_CLASS2(UToolCallAsyncResultImage, UToolCallAsyncResult, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ToolsetRegistry"), Z_Construct_UClass_UToolCallAsyncResultImage_NoRegister) \
	DECLARE_SERIALIZER(UToolCallAsyncResultImage)


#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultImage_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UToolCallAsyncResultImage(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UToolCallAsyncResultImage(UToolCallAsyncResultImage&&) = delete; \
	UToolCallAsyncResultImage(const UToolCallAsyncResultImage&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UToolCallAsyncResultImage); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UToolCallAsyncResultImage); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UToolCallAsyncResultImage) \
	NO_API virtual ~UToolCallAsyncResultImage();


#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultImage_h_11_PROLOG
#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultImage_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultImage_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultImage_h_14_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultImage_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UToolCallAsyncResultImage;

// ********** End Class UToolCallAsyncResultImage **************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultImage_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
