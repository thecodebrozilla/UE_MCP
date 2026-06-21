// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ToolsetRegistry/AgentSkill.h"

#ifdef TOOLSETREGISTRY_AgentSkill_generated_h
#error "AgentSkill.generated.h already included, missing '#pragma once' in AgentSkill.h"
#endif
#define TOOLSETREGISTRY_AgentSkill_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FAgentSkillDetails;

// ********** Begin ScriptStruct FAgentSkillDetails ************************************************
struct Z_Construct_UScriptStruct_FAgentSkillDetails_Statics;
#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_AgentSkill_h_20_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FAgentSkillDetails_Statics; \
	TOOLSETREGISTRY_API static class UScriptStruct* StaticStruct();


struct FAgentSkillDetails;
// ********** End ScriptStruct FAgentSkillDetails **************************************************

// ********** Begin Class UAgentSkill **************************************************************
#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_AgentSkill_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGeneratePrompt);


#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_AgentSkill_h_31_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UAgentSkill_Statics;
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UAgentSkill_NoRegister();

#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_AgentSkill_h_31_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAgentSkill(); \
	friend struct ::Z_Construct_UClass_UAgentSkill_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend TOOLSETREGISTRY_API UClass* ::Z_Construct_UClass_UAgentSkill_NoRegister(); \
public: \
	DECLARE_CLASS2(UAgentSkill, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ToolsetRegistry"), Z_Construct_UClass_UAgentSkill_NoRegister) \
	DECLARE_SERIALIZER(UAgentSkill)


#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_AgentSkill_h_31_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	TOOLSETREGISTRY_API UAgentSkill(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UAgentSkill(UAgentSkill&&) = delete; \
	UAgentSkill(const UAgentSkill&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(TOOLSETREGISTRY_API, UAgentSkill); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAgentSkill); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAgentSkill) \
	TOOLSETREGISTRY_API virtual ~UAgentSkill();


#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_AgentSkill_h_28_PROLOG
#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_AgentSkill_h_31_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_AgentSkill_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_AgentSkill_h_31_CALLBACK_WRAPPERS \
	FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_AgentSkill_h_31_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_AgentSkill_h_31_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UAgentSkill;

// ********** End Class UAgentSkill ****************************************************************

// ********** Begin Class UAgentSkillToolset *******************************************************
#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_AgentSkill_h_62_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execUpdateSkill); \
	DECLARE_FUNCTION(execCreateSkill); \
	DECLARE_FUNCTION(execGetSkills); \
	DECLARE_FUNCTION(execListSkills);


struct Z_Construct_UClass_UAgentSkillToolset_Statics;
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UAgentSkillToolset_NoRegister();

#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_AgentSkill_h_62_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAgentSkillToolset(); \
	friend struct ::Z_Construct_UClass_UAgentSkillToolset_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend TOOLSETREGISTRY_API UClass* ::Z_Construct_UClass_UAgentSkillToolset_NoRegister(); \
public: \
	DECLARE_CLASS2(UAgentSkillToolset, UToolsetDefinition, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ToolsetRegistry"), Z_Construct_UClass_UAgentSkillToolset_NoRegister) \
	DECLARE_SERIALIZER(UAgentSkillToolset)


#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_AgentSkill_h_62_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAgentSkillToolset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UAgentSkillToolset(UAgentSkillToolset&&) = delete; \
	UAgentSkillToolset(const UAgentSkillToolset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAgentSkillToolset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAgentSkillToolset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAgentSkillToolset) \
	NO_API virtual ~UAgentSkillToolset();


#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_AgentSkill_h_59_PROLOG
#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_AgentSkill_h_62_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_AgentSkill_h_62_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_AgentSkill_h_62_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_AgentSkill_h_62_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UAgentSkillToolset;

// ********** End Class UAgentSkillToolset *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_AgentSkill_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
