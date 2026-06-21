// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "WorldConditionTools.h"

#ifdef WORLDCONDITIONSTOOLSET_WorldConditionTools_generated_h
#error "WorldConditionTools.generated.h already included, missing '#pragma once' in WorldConditionTools.h"
#endif
#define WORLDCONDITIONSTOOLSET_WorldConditionTools_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FInstancedStruct;
struct FWorldConditionQueryDefinition;

// ********** Begin Class UWorldConditionTools *****************************************************
#define FID_UE_MCP_Plugins_Toolsets_WorldConditionsToolset_Source_WorldConditionsToolset_Private_WorldConditionTools_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetConditionDescription); \
	DECLARE_FUNCTION(execGetQueryDescription);


struct Z_Construct_UClass_UWorldConditionTools_Statics;
WORLDCONDITIONSTOOLSET_API UClass* Z_Construct_UClass_UWorldConditionTools_NoRegister();

#define FID_UE_MCP_Plugins_Toolsets_WorldConditionsToolset_Source_WorldConditionsToolset_Private_WorldConditionTools_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUWorldConditionTools(); \
	friend struct ::Z_Construct_UClass_UWorldConditionTools_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend WORLDCONDITIONSTOOLSET_API UClass* ::Z_Construct_UClass_UWorldConditionTools_NoRegister(); \
public: \
	DECLARE_CLASS2(UWorldConditionTools, UToolsetDefinition, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/WorldConditionsToolset"), Z_Construct_UClass_UWorldConditionTools_NoRegister) \
	DECLARE_SERIALIZER(UWorldConditionTools)


#define FID_UE_MCP_Plugins_Toolsets_WorldConditionsToolset_Source_WorldConditionsToolset_Private_WorldConditionTools_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWorldConditionTools(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UWorldConditionTools(UWorldConditionTools&&) = delete; \
	UWorldConditionTools(const UWorldConditionTools&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWorldConditionTools); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWorldConditionTools); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWorldConditionTools) \
	NO_API virtual ~UWorldConditionTools();


#define FID_UE_MCP_Plugins_Toolsets_WorldConditionsToolset_Source_WorldConditionsToolset_Private_WorldConditionTools_h_12_PROLOG
#define FID_UE_MCP_Plugins_Toolsets_WorldConditionsToolset_Source_WorldConditionsToolset_Private_WorldConditionTools_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_Toolsets_WorldConditionsToolset_Source_WorldConditionsToolset_Private_WorldConditionTools_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_WorldConditionsToolset_Source_WorldConditionsToolset_Private_WorldConditionTools_h_15_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_WorldConditionsToolset_Source_WorldConditionsToolset_Private_WorldConditionTools_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UWorldConditionTools;

// ********** End Class UWorldConditionTools *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_Toolsets_WorldConditionsToolset_Source_WorldConditionsToolset_Private_WorldConditionTools_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
