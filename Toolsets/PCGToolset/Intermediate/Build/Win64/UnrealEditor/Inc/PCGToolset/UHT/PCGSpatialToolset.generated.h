// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PCGSpatialToolset.h"

#ifdef PCGTOOLSET_PCGSpatialToolset_generated_h
#error "PCGSpatialToolset.generated.h already included, missing '#pragma once' in PCGSpatialToolset.h"
#endif
#define PCGTOOLSET_PCGSpatialToolset_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPCGExecuteGraphInstanceAsyncResult;
class UPCGGraph;

// ********** Begin Class UPCGSpatialToolset *******************************************************
#define FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGSpatialToolset_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execRunPCGInstantGraph);


struct Z_Construct_UClass_UPCGSpatialToolset_Statics;
PCGTOOLSET_API UClass* Z_Construct_UClass_UPCGSpatialToolset_NoRegister();

#define FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGSpatialToolset_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPCGSpatialToolset(); \
	friend struct ::Z_Construct_UClass_UPCGSpatialToolset_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PCGTOOLSET_API UClass* ::Z_Construct_UClass_UPCGSpatialToolset_NoRegister(); \
public: \
	DECLARE_CLASS2(UPCGSpatialToolset, UToolsetDefinition, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PCGToolset"), Z_Construct_UClass_UPCGSpatialToolset_NoRegister) \
	DECLARE_SERIALIZER(UPCGSpatialToolset)


#define FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGSpatialToolset_h_12_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPCGSpatialToolset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPCGSpatialToolset(UPCGSpatialToolset&&) = delete; \
	UPCGSpatialToolset(const UPCGSpatialToolset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPCGSpatialToolset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPCGSpatialToolset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPCGSpatialToolset) \
	NO_API virtual ~UPCGSpatialToolset();


#define FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGSpatialToolset_h_9_PROLOG
#define FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGSpatialToolset_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGSpatialToolset_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGSpatialToolset_h_12_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGSpatialToolset_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPCGSpatialToolset;

// ********** End Class UPCGSpatialToolset *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGSpatialToolset_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
