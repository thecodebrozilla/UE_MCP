// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GameplayTagsToolset/GameplayTagsToolset.h"

#ifdef GAMEPLAYTAGSTOOLSET_GameplayTagsToolset_generated_h
#error "GameplayTagsToolset.generated.h already included, missing '#pragma once' in GameplayTagsToolset.h"
#endif
#define GAMEPLAYTAGSTOOLSET_GameplayTagsToolset_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FGameplayTagInfo;

// ********** Begin ScriptStruct FGameplayTagInfo **************************************************
struct Z_Construct_UScriptStruct_FGameplayTagInfo_Statics;
#define FID_UE_MCP_Plugins_Toolsets_GameplayTagsToolset_Source_GameplayTagsToolset_Private_GameplayTagsToolset_GameplayTagsToolset_h_15_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FGameplayTagInfo_Statics; \
	GAMEPLAYTAGSTOOLSET_API static class UScriptStruct* StaticStruct();


struct FGameplayTagInfo;
// ********** End ScriptStruct FGameplayTagInfo ****************************************************

// ********** Begin Class UGameplayTagsToolset *****************************************************
#define FID_UE_MCP_Plugins_Toolsets_GameplayTagsToolset_Source_GameplayTagsToolset_Private_GameplayTagsToolset_GameplayTagsToolset_h_34_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execFindReferencersByTag); \
	DECLARE_FUNCTION(execRenameTag); \
	DECLARE_FUNCTION(execRemoveTag); \
	DECLARE_FUNCTION(execAddTag); \
	DECLARE_FUNCTION(execGetTagInfo); \
	DECLARE_FUNCTION(execListTags);


struct Z_Construct_UClass_UGameplayTagsToolset_Statics;
GAMEPLAYTAGSTOOLSET_API UClass* Z_Construct_UClass_UGameplayTagsToolset_NoRegister();

#define FID_UE_MCP_Plugins_Toolsets_GameplayTagsToolset_Source_GameplayTagsToolset_Private_GameplayTagsToolset_GameplayTagsToolset_h_34_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGameplayTagsToolset(); \
	friend struct ::Z_Construct_UClass_UGameplayTagsToolset_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GAMEPLAYTAGSTOOLSET_API UClass* ::Z_Construct_UClass_UGameplayTagsToolset_NoRegister(); \
public: \
	DECLARE_CLASS2(UGameplayTagsToolset, UToolsetDefinition, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameplayTagsToolset"), Z_Construct_UClass_UGameplayTagsToolset_NoRegister) \
	DECLARE_SERIALIZER(UGameplayTagsToolset)


#define FID_UE_MCP_Plugins_Toolsets_GameplayTagsToolset_Source_GameplayTagsToolset_Private_GameplayTagsToolset_GameplayTagsToolset_h_34_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGameplayTagsToolset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UGameplayTagsToolset(UGameplayTagsToolset&&) = delete; \
	UGameplayTagsToolset(const UGameplayTagsToolset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGameplayTagsToolset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameplayTagsToolset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGameplayTagsToolset) \
	NO_API virtual ~UGameplayTagsToolset();


#define FID_UE_MCP_Plugins_Toolsets_GameplayTagsToolset_Source_GameplayTagsToolset_Private_GameplayTagsToolset_GameplayTagsToolset_h_31_PROLOG
#define FID_UE_MCP_Plugins_Toolsets_GameplayTagsToolset_Source_GameplayTagsToolset_Private_GameplayTagsToolset_GameplayTagsToolset_h_34_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_Toolsets_GameplayTagsToolset_Source_GameplayTagsToolset_Private_GameplayTagsToolset_GameplayTagsToolset_h_34_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_GameplayTagsToolset_Source_GameplayTagsToolset_Private_GameplayTagsToolset_GameplayTagsToolset_h_34_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_GameplayTagsToolset_Source_GameplayTagsToolset_Private_GameplayTagsToolset_GameplayTagsToolset_h_34_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UGameplayTagsToolset;

// ********** End Class UGameplayTagsToolset *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_Toolsets_GameplayTagsToolset_Source_GameplayTagsToolset_Private_GameplayTagsToolset_GameplayTagsToolset_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
