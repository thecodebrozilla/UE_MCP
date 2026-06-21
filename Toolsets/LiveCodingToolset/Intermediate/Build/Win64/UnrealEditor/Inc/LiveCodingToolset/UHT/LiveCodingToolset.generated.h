// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "LiveCodingToolset.h"

#ifdef LIVECODINGTOOLSET_LiveCodingToolset_generated_h
#error "LiveCodingToolset.generated.h already included, missing '#pragma once' in LiveCodingToolset.h"
#endif
#define LIVECODINGTOOLSET_LiveCodingToolset_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class ULiveCodingToolset *******************************************************
#define FID_UE_MCP_Plugins_Toolsets_LiveCodingToolset_Source_LiveCodingToolset_Public_LiveCodingToolset_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execCompileLiveCoding);


struct Z_Construct_UClass_ULiveCodingToolset_Statics;
LIVECODINGTOOLSET_API UClass* Z_Construct_UClass_ULiveCodingToolset_NoRegister();

#define FID_UE_MCP_Plugins_Toolsets_LiveCodingToolset_Source_LiveCodingToolset_Public_LiveCodingToolset_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULiveCodingToolset(); \
	friend struct ::Z_Construct_UClass_ULiveCodingToolset_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend LIVECODINGTOOLSET_API UClass* ::Z_Construct_UClass_ULiveCodingToolset_NoRegister(); \
public: \
	DECLARE_CLASS2(ULiveCodingToolset, UToolsetDefinition, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LiveCodingToolset"), Z_Construct_UClass_ULiveCodingToolset_NoRegister) \
	DECLARE_SERIALIZER(ULiveCodingToolset)


#define FID_UE_MCP_Plugins_Toolsets_LiveCodingToolset_Source_LiveCodingToolset_Public_LiveCodingToolset_h_19_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	LIVECODINGTOOLSET_API ULiveCodingToolset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	ULiveCodingToolset(ULiveCodingToolset&&) = delete; \
	ULiveCodingToolset(const ULiveCodingToolset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(LIVECODINGTOOLSET_API, ULiveCodingToolset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULiveCodingToolset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULiveCodingToolset) \
	LIVECODINGTOOLSET_API virtual ~ULiveCodingToolset();


#define FID_UE_MCP_Plugins_Toolsets_LiveCodingToolset_Source_LiveCodingToolset_Public_LiveCodingToolset_h_16_PROLOG
#define FID_UE_MCP_Plugins_Toolsets_LiveCodingToolset_Source_LiveCodingToolset_Public_LiveCodingToolset_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_Toolsets_LiveCodingToolset_Source_LiveCodingToolset_Public_LiveCodingToolset_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_LiveCodingToolset_Source_LiveCodingToolset_Public_LiveCodingToolset_h_19_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_LiveCodingToolset_Source_LiveCodingToolset_Public_LiveCodingToolset_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ULiveCodingToolset;

// ********** End Class ULiveCodingToolset *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_Toolsets_LiveCodingToolset_Source_LiveCodingToolset_Public_LiveCodingToolset_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
