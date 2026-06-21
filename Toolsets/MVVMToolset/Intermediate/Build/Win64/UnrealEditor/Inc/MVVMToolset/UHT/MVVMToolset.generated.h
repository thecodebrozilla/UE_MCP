// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MVVMToolset/MVVMToolset.h"

#ifdef MVVMTOOLSET_MVVMToolset_generated_h
#error "MVVMToolset.generated.h already included, missing '#pragma once' in MVVMToolset.h"
#endif
#define MVVMTOOLSET_MVVMToolset_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UBlueprint;
class UClass;
class UObject;
class UWidgetBlueprint;
struct FGuid;
struct FMVVMBlueprintViewBinding;
struct FMVVMViewConversionFunctionDescription;

// ********** Begin ScriptStruct FMVVMViewConversionFunctionDescription ****************************
struct Z_Construct_UScriptStruct_FMVVMViewConversionFunctionDescription_Statics;
#define FID_UE_MCP_Plugins_Toolsets_MVVMToolset_Source_MVVMToolset_Private_MVVMToolset_MVVMToolset_h_17_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FMVVMViewConversionFunctionDescription_Statics; \
	MVVMTOOLSET_API static class UScriptStruct* StaticStruct();


struct FMVVMViewConversionFunctionDescription;
// ********** End ScriptStruct FMVVMViewConversionFunctionDescription ******************************

// ********** Begin Class UMVVMToolset *************************************************************
#define FID_UE_MCP_Plugins_Toolsets_MVVMToolset_Source_MVVMToolset_Private_MVVMToolset_MVVMToolset_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execListConversionFunctions); \
	DECLARE_FUNCTION(execCreateViewBinding); \
	DECLARE_FUNCTION(execRemoveWidgetViewBinding); \
	DECLARE_FUNCTION(execListWidgetViewBindings); \
	DECLARE_FUNCTION(execAddViewModelToWidget); \
	DECLARE_FUNCTION(execListWidgetViewModels); \
	DECLARE_FUNCTION(execListViewModels); \
	DECLARE_FUNCTION(execAddViewModelProperty); \
	DECLARE_FUNCTION(execCreateViewModel);


struct Z_Construct_UClass_UMVVMToolset_Statics;
MVVMTOOLSET_API UClass* Z_Construct_UClass_UMVVMToolset_NoRegister();

#define FID_UE_MCP_Plugins_Toolsets_MVVMToolset_Source_MVVMToolset_Private_MVVMToolset_MVVMToolset_h_31_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMVVMToolset(); \
	friend struct ::Z_Construct_UClass_UMVVMToolset_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend MVVMTOOLSET_API UClass* ::Z_Construct_UClass_UMVVMToolset_NoRegister(); \
public: \
	DECLARE_CLASS2(UMVVMToolset, UToolsetDefinition, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MVVMToolset"), Z_Construct_UClass_UMVVMToolset_NoRegister) \
	DECLARE_SERIALIZER(UMVVMToolset)


#define FID_UE_MCP_Plugins_Toolsets_MVVMToolset_Source_MVVMToolset_Private_MVVMToolset_MVVMToolset_h_31_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMVVMToolset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UMVVMToolset(UMVVMToolset&&) = delete; \
	UMVVMToolset(const UMVVMToolset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMVVMToolset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMVVMToolset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMVVMToolset) \
	NO_API virtual ~UMVVMToolset();


#define FID_UE_MCP_Plugins_Toolsets_MVVMToolset_Source_MVVMToolset_Private_MVVMToolset_MVVMToolset_h_28_PROLOG
#define FID_UE_MCP_Plugins_Toolsets_MVVMToolset_Source_MVVMToolset_Private_MVVMToolset_MVVMToolset_h_31_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_Toolsets_MVVMToolset_Source_MVVMToolset_Private_MVVMToolset_MVVMToolset_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_MVVMToolset_Source_MVVMToolset_Private_MVVMToolset_MVVMToolset_h_31_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_MVVMToolset_Source_MVVMToolset_Private_MVVMToolset_MVVMToolset_h_31_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UMVVMToolset;

// ********** End Class UMVVMToolset ***************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_Toolsets_MVVMToolset_Source_MVVMToolset_Private_MVVMToolset_MVVMToolset_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
