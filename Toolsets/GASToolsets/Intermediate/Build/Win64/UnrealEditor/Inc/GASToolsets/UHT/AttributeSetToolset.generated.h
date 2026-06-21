// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AttributeSetToolset.h"

#ifdef GASTOOLSETS_AttributeSetToolset_generated_h
#error "AttributeSetToolset.generated.h already included, missing '#pragma once' in AttributeSetToolset.h"
#endif
#define GASTOOLSETS_AttributeSetToolset_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FAttributeSetClassInfo;
struct FGameplayAttributeInfo;

// ********** Begin ScriptStruct FGameplayAttributeInfo ********************************************
struct Z_Construct_UScriptStruct_FGameplayAttributeInfo_Statics;
#define FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AttributeSetToolset_h_14_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FGameplayAttributeInfo_Statics; \
	GASTOOLSETS_API static class UScriptStruct* StaticStruct();


struct FGameplayAttributeInfo;
// ********** End ScriptStruct FGameplayAttributeInfo **********************************************

// ********** Begin ScriptStruct FAttributeSetClassInfo ********************************************
struct Z_Construct_UScriptStruct_FAttributeSetClassInfo_Statics;
#define FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AttributeSetToolset_h_33_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FAttributeSetClassInfo_Statics; \
	GASTOOLSETS_API static class UScriptStruct* StaticStruct();


struct FAttributeSetClassInfo;
// ********** End ScriptStruct FAttributeSetClassInfo **********************************************

// ********** Begin Class UAttributeSetToolset *****************************************************
#define FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AttributeSetToolset_h_52_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execListAttributes); \
	DECLARE_FUNCTION(execFindAttributeSetClasses);


struct Z_Construct_UClass_UAttributeSetToolset_Statics;
GASTOOLSETS_API UClass* Z_Construct_UClass_UAttributeSetToolset_NoRegister();

#define FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AttributeSetToolset_h_52_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAttributeSetToolset(); \
	friend struct ::Z_Construct_UClass_UAttributeSetToolset_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GASTOOLSETS_API UClass* ::Z_Construct_UClass_UAttributeSetToolset_NoRegister(); \
public: \
	DECLARE_CLASS2(UAttributeSetToolset, UToolsetDefinition, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GASToolsets"), Z_Construct_UClass_UAttributeSetToolset_NoRegister) \
	DECLARE_SERIALIZER(UAttributeSetToolset)


#define FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AttributeSetToolset_h_52_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAttributeSetToolset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UAttributeSetToolset(UAttributeSetToolset&&) = delete; \
	UAttributeSetToolset(const UAttributeSetToolset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAttributeSetToolset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAttributeSetToolset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAttributeSetToolset) \
	NO_API virtual ~UAttributeSetToolset();


#define FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AttributeSetToolset_h_49_PROLOG
#define FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AttributeSetToolset_h_52_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AttributeSetToolset_h_52_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AttributeSetToolset_h_52_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AttributeSetToolset_h_52_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UAttributeSetToolset;

// ********** End Class UAttributeSetToolset *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AttributeSetToolset_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
