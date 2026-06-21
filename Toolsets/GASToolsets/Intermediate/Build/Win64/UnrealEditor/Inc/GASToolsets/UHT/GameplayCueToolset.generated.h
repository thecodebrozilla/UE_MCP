// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GameplayCueToolset.h"

#ifdef GASTOOLSETS_GameplayCueToolset_generated_h
#error "GameplayCueToolset.generated.h already included, missing '#pragma once' in GameplayCueToolset.h"
#endif
#define GASTOOLSETS_GameplayCueToolset_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FGameplayCueInfo;
struct FGameplayCueNotifyInfo;

// ********** Begin ScriptStruct FGameplayCueInfo **************************************************
struct Z_Construct_UScriptStruct_FGameplayCueInfo_Statics;
#define FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_GameplayCueToolset_h_14_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FGameplayCueInfo_Statics; \
	GASTOOLSETS_API static class UScriptStruct* StaticStruct();


struct FGameplayCueInfo;
// ********** End ScriptStruct FGameplayCueInfo ****************************************************

// ********** Begin ScriptStruct FGameplayCueNotifyInfo ********************************************
struct Z_Construct_UScriptStruct_FGameplayCueNotifyInfo_Statics;
#define FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_GameplayCueToolset_h_34_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FGameplayCueNotifyInfo_Statics; \
	GASTOOLSETS_API static class UScriptStruct* StaticStruct();


struct FGameplayCueNotifyInfo;
// ********** End ScriptStruct FGameplayCueNotifyInfo **********************************************

// ********** Begin Class UGameplayCueToolset ******************************************************
#define FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_GameplayCueToolset_h_57_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execFindCueTagsWithoutNotifies); \
	DECLARE_FUNCTION(execRemoveCueTag); \
	DECLARE_FUNCTION(execAddCueTag); \
	DECLARE_FUNCTION(execCreateCueNotifyAsset); \
	DECLARE_FUNCTION(execFindCueNotifyAssets); \
	DECLARE_FUNCTION(execExecuteCueOnSelectedActor); \
	DECLARE_FUNCTION(execGetCueInfo); \
	DECLARE_FUNCTION(execListCues);


struct Z_Construct_UClass_UGameplayCueToolset_Statics;
GASTOOLSETS_API UClass* Z_Construct_UClass_UGameplayCueToolset_NoRegister();

#define FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_GameplayCueToolset_h_57_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGameplayCueToolset(); \
	friend struct ::Z_Construct_UClass_UGameplayCueToolset_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GASTOOLSETS_API UClass* ::Z_Construct_UClass_UGameplayCueToolset_NoRegister(); \
public: \
	DECLARE_CLASS2(UGameplayCueToolset, UToolsetDefinition, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GASToolsets"), Z_Construct_UClass_UGameplayCueToolset_NoRegister) \
	DECLARE_SERIALIZER(UGameplayCueToolset)


#define FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_GameplayCueToolset_h_57_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGameplayCueToolset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UGameplayCueToolset(UGameplayCueToolset&&) = delete; \
	UGameplayCueToolset(const UGameplayCueToolset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGameplayCueToolset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameplayCueToolset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGameplayCueToolset) \
	NO_API virtual ~UGameplayCueToolset();


#define FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_GameplayCueToolset_h_54_PROLOG
#define FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_GameplayCueToolset_h_57_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_GameplayCueToolset_h_57_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_GameplayCueToolset_h_57_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_GameplayCueToolset_h_57_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UGameplayCueToolset;

// ********** End Class UGameplayCueToolset ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_GameplayCueToolset_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
