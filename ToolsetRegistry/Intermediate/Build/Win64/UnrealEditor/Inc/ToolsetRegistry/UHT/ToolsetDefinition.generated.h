// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ToolsetRegistry/ToolsetDefinition.h"

#ifdef TOOLSETREGISTRY_ToolsetDefinition_generated_h
#error "ToolsetDefinition.generated.h already included, missing '#pragma once' in ToolsetDefinition.h"
#endif
#define TOOLSETREGISTRY_ToolsetDefinition_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UToolsetDefinition *******************************************************
struct Z_Construct_UClass_UToolsetDefinition_Statics;
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition_NoRegister();

#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetDefinition_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUToolsetDefinition(); \
	friend struct ::Z_Construct_UClass_UToolsetDefinition_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend TOOLSETREGISTRY_API UClass* ::Z_Construct_UClass_UToolsetDefinition_NoRegister(); \
public: \
	DECLARE_CLASS2(UToolsetDefinition, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/ToolsetRegistry"), Z_Construct_UClass_UToolsetDefinition_NoRegister) \
	DECLARE_SERIALIZER(UToolsetDefinition)


#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetDefinition_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	TOOLSETREGISTRY_API UToolsetDefinition(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UToolsetDefinition(UToolsetDefinition&&) = delete; \
	UToolsetDefinition(const UToolsetDefinition&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(TOOLSETREGISTRY_API, UToolsetDefinition); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UToolsetDefinition); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UToolsetDefinition) \
	TOOLSETREGISTRY_API virtual ~UToolsetDefinition();


#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetDefinition_h_17_PROLOG
#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetDefinition_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetDefinition_h_20_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetDefinition_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UToolsetDefinition;

// ********** End Class UToolsetDefinition *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetDefinition_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
