// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PCGToolset.h"

#ifdef PCGTOOLSET_PCGToolset_generated_h
#error "PCGToolset.generated.h already included, missing '#pragma once' in PCGToolset.h"
#endif
#define PCGTOOLSET_PCGToolset_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APCGVolume;
class UPCGExecuteGraphInstanceAsyncResult;
class UPCGGraph;
class UPCGNode;
class UToolCallAsyncResultVoid;
struct FInstancedPropertyBag;
struct FLinearColor;
struct FPCGGraphInstanceInfo;
struct FPCGGraphSchema;
struct FPCGGraphStructure;
struct FPCGNativeNodeSchema;
struct FPCGNodeInfo;
struct FPCGParamDefinition;

// ********** Begin Class UPCGToolset **************************************************************
#define FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolset_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execDrawSpline); \
	DECLARE_FUNCTION(execRemoveCommentBox); \
	DECLARE_FUNCTION(execUpdateCommentBox); \
	DECLARE_FUNCTION(execAddCommentBox); \
	DECLARE_FUNCTION(execGetNodeDataView); \
	DECLARE_FUNCTION(execDisconnectNodePins); \
	DECLARE_FUNCTION(execConnectNodePins); \
	DECLARE_FUNCTION(execRemoveNode); \
	DECLARE_FUNCTION(execRepositionNode); \
	DECLARE_FUNCTION(execGetNodeInfo); \
	DECLARE_FUNCTION(execSetNodeComment); \
	DECLARE_FUNCTION(execUpdateNode); \
	DECLARE_FUNCTION(execAddSubgraphNode); \
	DECLARE_FUNCTION(execAddNode); \
	DECLARE_FUNCTION(execGetNativeNodeSchema); \
	DECLARE_FUNCTION(execListAvailableSubgraphs); \
	DECLARE_FUNCTION(execListNativeNodes); \
	DECLARE_FUNCTION(execResetGraphInstanceParams); \
	DECLARE_FUNCTION(execSetGraphInstanceParams); \
	DECLARE_FUNCTION(execGetGraphInstanceParams); \
	DECLARE_FUNCTION(execExecuteGraphInstance); \
	DECLARE_FUNCTION(execSpawnGraphInstance); \
	DECLARE_FUNCTION(execListGraphInstances); \
	DECLARE_FUNCTION(execSetGraphDescription); \
	DECLARE_FUNCTION(execGetGraphDescription); \
	DECLARE_FUNCTION(execGetGraphSchema); \
	DECLARE_FUNCTION(execRemoveGraphParams); \
	DECLARE_FUNCTION(execSetGraphParams); \
	DECLARE_FUNCTION(execGetGraphStructure); \
	DECLARE_FUNCTION(execCreateGraph);


struct Z_Construct_UClass_UPCGToolset_Statics;
PCGTOOLSET_API UClass* Z_Construct_UClass_UPCGToolset_NoRegister();

#define FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolset_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPCGToolset(); \
	friend struct ::Z_Construct_UClass_UPCGToolset_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PCGTOOLSET_API UClass* ::Z_Construct_UClass_UPCGToolset_NoRegister(); \
public: \
	DECLARE_CLASS2(UPCGToolset, UToolsetDefinition, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PCGToolset"), Z_Construct_UClass_UPCGToolset_NoRegister) \
	DECLARE_SERIALIZER(UPCGToolset)


#define FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolset_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPCGToolset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPCGToolset(UPCGToolset&&) = delete; \
	UPCGToolset(const UPCGToolset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPCGToolset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPCGToolset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPCGToolset) \
	NO_API virtual ~UPCGToolset();


#define FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolset_h_15_PROLOG
#define FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolset_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolset_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolset_h_18_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolset_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPCGToolset;

// ********** End Class UPCGToolset ****************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolset_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
