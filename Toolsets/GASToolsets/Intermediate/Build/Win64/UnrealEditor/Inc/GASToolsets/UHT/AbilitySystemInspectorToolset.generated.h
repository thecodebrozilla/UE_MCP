// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AbilitySystemInspectorToolset.h"

#ifdef GASTOOLSETS_AbilitySystemInspectorToolset_generated_h
#error "AbilitySystemInspectorToolset.generated.h already included, missing '#pragma once' in AbilitySystemInspectorToolset.h"
#endif
#define GASTOOLSETS_AbilitySystemInspectorToolset_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
struct FActiveEffectInfo;
struct FGrantedAbilityInfo;
struct FRuntimeAttributeValue;

// ********** Begin ScriptStruct FRuntimeAttributeValue ********************************************
struct Z_Construct_UScriptStruct_FRuntimeAttributeValue_Statics;
#define FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AbilitySystemInspectorToolset_h_14_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FRuntimeAttributeValue_Statics; \
	GASTOOLSETS_API static class UScriptStruct* StaticStruct();


struct FRuntimeAttributeValue;
// ********** End ScriptStruct FRuntimeAttributeValue **********************************************

// ********** Begin ScriptStruct FActiveEffectInfo *************************************************
struct Z_Construct_UScriptStruct_FActiveEffectInfo_Statics;
#define FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AbilitySystemInspectorToolset_h_41_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FActiveEffectInfo_Statics; \
	GASTOOLSETS_API static class UScriptStruct* StaticStruct();


struct FActiveEffectInfo;
// ********** End ScriptStruct FActiveEffectInfo ***************************************************

// ********** Begin ScriptStruct FGrantedAbilityInfo ***********************************************
struct Z_Construct_UScriptStruct_FGrantedAbilityInfo_Statics;
#define FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AbilitySystemInspectorToolset_h_68_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FGrantedAbilityInfo_Statics; \
	GASTOOLSETS_API static class UScriptStruct* StaticStruct();


struct FGrantedAbilityInfo;
// ********** End ScriptStruct FGrantedAbilityInfo *************************************************

// ********** Begin Class UAbilitySystemInspectorToolset *******************************************
#define FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AbilitySystemInspectorToolset_h_91_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetActiveTags); \
	DECLARE_FUNCTION(execGetGrantedAbilities); \
	DECLARE_FUNCTION(execGetActiveEffects); \
	DECLARE_FUNCTION(execGetAttributeValues);


struct Z_Construct_UClass_UAbilitySystemInspectorToolset_Statics;
GASTOOLSETS_API UClass* Z_Construct_UClass_UAbilitySystemInspectorToolset_NoRegister();

#define FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AbilitySystemInspectorToolset_h_91_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAbilitySystemInspectorToolset(); \
	friend struct ::Z_Construct_UClass_UAbilitySystemInspectorToolset_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GASTOOLSETS_API UClass* ::Z_Construct_UClass_UAbilitySystemInspectorToolset_NoRegister(); \
public: \
	DECLARE_CLASS2(UAbilitySystemInspectorToolset, UToolsetDefinition, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GASToolsets"), Z_Construct_UClass_UAbilitySystemInspectorToolset_NoRegister) \
	DECLARE_SERIALIZER(UAbilitySystemInspectorToolset)


#define FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AbilitySystemInspectorToolset_h_91_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAbilitySystemInspectorToolset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UAbilitySystemInspectorToolset(UAbilitySystemInspectorToolset&&) = delete; \
	UAbilitySystemInspectorToolset(const UAbilitySystemInspectorToolset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAbilitySystemInspectorToolset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAbilitySystemInspectorToolset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAbilitySystemInspectorToolset) \
	NO_API virtual ~UAbilitySystemInspectorToolset();


#define FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AbilitySystemInspectorToolset_h_88_PROLOG
#define FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AbilitySystemInspectorToolset_h_91_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AbilitySystemInspectorToolset_h_91_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AbilitySystemInspectorToolset_h_91_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AbilitySystemInspectorToolset_h_91_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UAbilitySystemInspectorToolset;

// ********** End Class UAbilitySystemInspectorToolset *********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AbilitySystemInspectorToolset_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
