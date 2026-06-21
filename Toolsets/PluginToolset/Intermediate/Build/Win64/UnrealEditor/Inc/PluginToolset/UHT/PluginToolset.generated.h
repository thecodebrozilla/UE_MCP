// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PluginToolset.h"

#ifdef PLUGINTOOLSET_PluginToolset_generated_h
#error "PluginToolset.generated.h already included, missing '#pragma once' in PluginToolset.h"
#endif
#define PLUGINTOOLSET_PluginToolset_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FPluginDependencyToolsetInfo;
struct FPluginDescriptorToolsetInfo;
struct FPluginTemplateDescriptionToolsetInfo;
struct FPluginToolsetInfo;

// ********** Begin ScriptStruct FPluginDescriptorToolsetInfo **************************************
struct Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics;
#define FID_UE_MCP_Plugins_Toolsets_PluginToolset_Source_PluginToolset_Private_PluginToolset_h_16_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics; \
	PLUGINTOOLSET_API static class UScriptStruct* StaticStruct();


struct FPluginDescriptorToolsetInfo;
// ********** End ScriptStruct FPluginDescriptorToolsetInfo ****************************************

// ********** Begin ScriptStruct FPluginToolsetInfo ************************************************
struct Z_Construct_UScriptStruct_FPluginToolsetInfo_Statics;
#define FID_UE_MCP_Plugins_Toolsets_PluginToolset_Source_PluginToolset_Private_PluginToolset_h_86_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FPluginToolsetInfo_Statics; \
	PLUGINTOOLSET_API static class UScriptStruct* StaticStruct();


struct FPluginToolsetInfo;
// ********** End ScriptStruct FPluginToolsetInfo **************************************************

// ********** Begin ScriptStruct FPluginDependencyToolsetInfo **************************************
struct Z_Construct_UScriptStruct_FPluginDependencyToolsetInfo_Statics;
#define FID_UE_MCP_Plugins_Toolsets_PluginToolset_Source_PluginToolset_Private_PluginToolset_h_114_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FPluginDependencyToolsetInfo_Statics; \
	PLUGINTOOLSET_API static class UScriptStruct* StaticStruct();


struct FPluginDependencyToolsetInfo;
// ********** End ScriptStruct FPluginDependencyToolsetInfo ****************************************

// ********** Begin ScriptStruct FPluginTemplateDescriptionToolsetInfo *****************************
struct Z_Construct_UScriptStruct_FPluginTemplateDescriptionToolsetInfo_Statics;
#define FID_UE_MCP_Plugins_Toolsets_PluginToolset_Source_PluginToolset_Private_PluginToolset_h_133_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FPluginTemplateDescriptionToolsetInfo_Statics; \
	PLUGINTOOLSET_API static class UScriptStruct* StaticStruct();


struct FPluginTemplateDescriptionToolsetInfo;
// ********** End ScriptStruct FPluginTemplateDescriptionToolsetInfo *******************************

// ********** Begin Class UPluginToolset ***********************************************************
#define FID_UE_MCP_Plugins_Toolsets_PluginToolset_Source_PluginToolset_Private_PluginToolset_h_160_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execRemovePluginDependency); \
	DECLARE_FUNCTION(execAddPluginDependency); \
	DECLARE_FUNCTION(execUpdatePluginDescriptor); \
	DECLARE_FUNCTION(execGetPluginDescriptor); \
	DECLARE_FUNCTION(execSetPluginEnabled); \
	DECLARE_FUNCTION(execIsPluginModificationAllowed); \
	DECLARE_FUNCTION(execCreatePlugin); \
	DECLARE_FUNCTION(execValidateNewPluginNameAndLocation); \
	DECLARE_FUNCTION(execIsPluginCreationAllowed); \
	DECLARE_FUNCTION(execGetPluginTemplateDescriptions); \
	DECLARE_FUNCTION(execGetPluginForAsset); \
	DECLARE_FUNCTION(execGetPluginDependents); \
	DECLARE_FUNCTION(execGetPluginDependencies); \
	DECLARE_FUNCTION(execIsEnabled); \
	DECLARE_FUNCTION(execGetPluginInfo); \
	DECLARE_FUNCTION(execListDiscoveredPlugins); \
	DECLARE_FUNCTION(execListEnabledPlugins);


struct Z_Construct_UClass_UPluginToolset_Statics;
PLUGINTOOLSET_API UClass* Z_Construct_UClass_UPluginToolset_NoRegister();

#define FID_UE_MCP_Plugins_Toolsets_PluginToolset_Source_PluginToolset_Private_PluginToolset_h_160_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPluginToolset(); \
	friend struct ::Z_Construct_UClass_UPluginToolset_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PLUGINTOOLSET_API UClass* ::Z_Construct_UClass_UPluginToolset_NoRegister(); \
public: \
	DECLARE_CLASS2(UPluginToolset, UToolsetDefinition, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PluginToolset"), Z_Construct_UClass_UPluginToolset_NoRegister) \
	DECLARE_SERIALIZER(UPluginToolset)


#define FID_UE_MCP_Plugins_Toolsets_PluginToolset_Source_PluginToolset_Private_PluginToolset_h_160_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	PLUGINTOOLSET_API UPluginToolset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPluginToolset(UPluginToolset&&) = delete; \
	UPluginToolset(const UPluginToolset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(PLUGINTOOLSET_API, UPluginToolset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPluginToolset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPluginToolset) \
	PLUGINTOOLSET_API virtual ~UPluginToolset();


#define FID_UE_MCP_Plugins_Toolsets_PluginToolset_Source_PluginToolset_Private_PluginToolset_h_157_PROLOG
#define FID_UE_MCP_Plugins_Toolsets_PluginToolset_Source_PluginToolset_Private_PluginToolset_h_160_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_Toolsets_PluginToolset_Source_PluginToolset_Private_PluginToolset_h_160_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_PluginToolset_Source_PluginToolset_Private_PluginToolset_h_160_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_PluginToolset_Source_PluginToolset_Private_PluginToolset_h_160_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPluginToolset;

// ********** End Class UPluginToolset *************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_Toolsets_PluginToolset_Source_PluginToolset_Private_PluginToolset_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
