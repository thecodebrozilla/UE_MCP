// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DataflowAgentToolset.h"

#ifdef DATAFLOWAGENT_DataflowAgentToolset_generated_h
#error "DataflowAgentToolset.generated.h already included, missing '#pragma once' in DataflowAgentToolset.h"
#endif
#define DATAFLOWAGENT_DataflowAgentToolset_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UDataflow;
class UDataflowEdNode;
class UObject;
struct FLinearColor;

// ********** Begin Class UDataflowAgentToolset ****************************************************
#define FID_UE_MCP_Plugins_Toolsets_DataflowAgent_Source_DataflowAgent_Private_DataflowAgentToolset_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execAssignDataflowTemplate); \
	DECLARE_FUNCTION(execListDataflowTemplatesForAssetClass); \
	DECLARE_FUNCTION(execCreateDataflowCompatibleAssetFromTemplate); \
	DECLARE_FUNCTION(execCreateDataflowCompatibleAsset); \
	DECLARE_FUNCTION(execListDataflowCompatibleAssetTypes); \
	DECLARE_FUNCTION(execRemoveCommentBox); \
	DECLARE_FUNCTION(execAddCommentBox); \
	DECLARE_FUNCTION(execSetVariable); \
	DECLARE_FUNCTION(execRemoveVariable); \
	DECLARE_FUNCTION(execAddVariable); \
	DECLARE_FUNCTION(execListVariables); \
	DECLARE_FUNCTION(execDisconnectNodePins); \
	DECLARE_FUNCTION(execConnectNodePins); \
	DECLARE_FUNCTION(execRemoveNode); \
	DECLARE_FUNCTION(execRepositionNode); \
	DECLARE_FUNCTION(execGetNodeInfo); \
	DECLARE_FUNCTION(execUpdateNode); \
	DECLARE_FUNCTION(execAddNode); \
	DECLARE_FUNCTION(execGetNodeTypeSchema); \
	DECLARE_FUNCTION(execListNodeTypes); \
	DECLARE_FUNCTION(execGetGraphStructure); \
	DECLARE_FUNCTION(execCreateGraph);


struct Z_Construct_UClass_UDataflowAgentToolset_Statics;
DATAFLOWAGENT_API UClass* Z_Construct_UClass_UDataflowAgentToolset_NoRegister();

#define FID_UE_MCP_Plugins_Toolsets_DataflowAgent_Source_DataflowAgent_Private_DataflowAgentToolset_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDataflowAgentToolset(); \
	friend struct ::Z_Construct_UClass_UDataflowAgentToolset_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend DATAFLOWAGENT_API UClass* ::Z_Construct_UClass_UDataflowAgentToolset_NoRegister(); \
public: \
	DECLARE_CLASS2(UDataflowAgentToolset, UToolsetDefinition, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DataflowAgent"), Z_Construct_UClass_UDataflowAgentToolset_NoRegister) \
	DECLARE_SERIALIZER(UDataflowAgentToolset)


#define FID_UE_MCP_Plugins_Toolsets_DataflowAgent_Source_DataflowAgent_Private_DataflowAgentToolset_h_19_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDataflowAgentToolset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDataflowAgentToolset(UDataflowAgentToolset&&) = delete; \
	UDataflowAgentToolset(const UDataflowAgentToolset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDataflowAgentToolset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDataflowAgentToolset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDataflowAgentToolset) \
	NO_API virtual ~UDataflowAgentToolset();


#define FID_UE_MCP_Plugins_Toolsets_DataflowAgent_Source_DataflowAgent_Private_DataflowAgentToolset_h_16_PROLOG
#define FID_UE_MCP_Plugins_Toolsets_DataflowAgent_Source_DataflowAgent_Private_DataflowAgentToolset_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_Toolsets_DataflowAgent_Source_DataflowAgent_Private_DataflowAgentToolset_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_DataflowAgent_Source_DataflowAgent_Private_DataflowAgentToolset_h_19_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_DataflowAgent_Source_DataflowAgent_Private_DataflowAgentToolset_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDataflowAgentToolset;

// ********** End Class UDataflowAgentToolset ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_Toolsets_DataflowAgent_Source_DataflowAgent_Private_DataflowAgentToolset_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
