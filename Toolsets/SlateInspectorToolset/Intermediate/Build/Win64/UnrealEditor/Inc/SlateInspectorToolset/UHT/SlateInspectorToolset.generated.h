// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SlateInspectorToolset.h"

#ifdef SLATEINSPECTORTOOLSET_SlateInspectorToolset_generated_h
#error "SlateInspectorToolset.generated.h already included, missing '#pragma once' in SlateInspectorToolset.h"
#endif
#define SLATEINSPECTORTOOLSET_SlateInspectorToolset_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FSlateInspectorToolsetFormField;
struct FSlateInspectorToolsetModifierKeys;
struct FToolsetImage;

// ********** Begin ScriptStruct FSlateInspectorToolsetModifierKeys ********************************
struct Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys_Statics;
#define FID_UE_MCP_Plugins_Toolsets_SlateInspectorToolset_Source_SlateInspectorToolset_Public_SlateInspectorToolset_h_16_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys_Statics; \
	SLATEINSPECTORTOOLSET_API static class UScriptStruct* StaticStruct();


struct FSlateInspectorToolsetModifierKeys;
// ********** End ScriptStruct FSlateInspectorToolsetModifierKeys **********************************

// ********** Begin ScriptStruct FSlateInspectorToolsetFormField ***********************************
struct Z_Construct_UScriptStruct_FSlateInspectorToolsetFormField_Statics;
#define FID_UE_MCP_Plugins_Toolsets_SlateInspectorToolset_Source_SlateInspectorToolset_Public_SlateInspectorToolset_h_41_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FSlateInspectorToolsetFormField_Statics; \
	SLATEINSPECTORTOOLSET_API static class UScriptStruct* StaticStruct();


struct FSlateInspectorToolsetFormField;
// ********** End ScriptStruct FSlateInspectorToolsetFormField *************************************

// ********** Begin Class USlateInspectorToolset ***************************************************
#define FID_UE_MCP_Plugins_Toolsets_SlateInspectorToolset_Source_SlateInspectorToolset_Public_SlateInspectorToolset_h_77_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execFillForm); \
	DECLARE_FUNCTION(execWaitFor); \
	DECLARE_FUNCTION(execWindows); \
	DECLARE_FUNCTION(execDrag); \
	DECLARE_FUNCTION(execSelectOption); \
	DECLARE_FUNCTION(execPressKey); \
	DECLARE_FUNCTION(execType); \
	DECLARE_FUNCTION(execHover); \
	DECLARE_FUNCTION(execClick); \
	DECLARE_FUNCTION(execScreenshot); \
	DECLARE_FUNCTION(execListObservers); \
	DECLARE_FUNCTION(execUnobserve); \
	DECLARE_FUNCTION(execObserve); \
	DECLARE_FUNCTION(execSnapshot);


struct Z_Construct_UClass_USlateInspectorToolset_Statics;
SLATEINSPECTORTOOLSET_API UClass* Z_Construct_UClass_USlateInspectorToolset_NoRegister();

#define FID_UE_MCP_Plugins_Toolsets_SlateInspectorToolset_Source_SlateInspectorToolset_Public_SlateInspectorToolset_h_77_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSlateInspectorToolset(); \
	friend struct ::Z_Construct_UClass_USlateInspectorToolset_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend SLATEINSPECTORTOOLSET_API UClass* ::Z_Construct_UClass_USlateInspectorToolset_NoRegister(); \
public: \
	DECLARE_CLASS2(USlateInspectorToolset, UToolsetDefinition, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SlateInspectorToolset"), Z_Construct_UClass_USlateInspectorToolset_NoRegister) \
	DECLARE_SERIALIZER(USlateInspectorToolset)


#define FID_UE_MCP_Plugins_Toolsets_SlateInspectorToolset_Source_SlateInspectorToolset_Public_SlateInspectorToolset_h_77_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	SLATEINSPECTORTOOLSET_API USlateInspectorToolset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	USlateInspectorToolset(USlateInspectorToolset&&) = delete; \
	USlateInspectorToolset(const USlateInspectorToolset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(SLATEINSPECTORTOOLSET_API, USlateInspectorToolset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USlateInspectorToolset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USlateInspectorToolset) \
	SLATEINSPECTORTOOLSET_API virtual ~USlateInspectorToolset();


#define FID_UE_MCP_Plugins_Toolsets_SlateInspectorToolset_Source_SlateInspectorToolset_Public_SlateInspectorToolset_h_74_PROLOG
#define FID_UE_MCP_Plugins_Toolsets_SlateInspectorToolset_Source_SlateInspectorToolset_Public_SlateInspectorToolset_h_77_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_Toolsets_SlateInspectorToolset_Source_SlateInspectorToolset_Public_SlateInspectorToolset_h_77_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_SlateInspectorToolset_Source_SlateInspectorToolset_Public_SlateInspectorToolset_h_77_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_SlateInspectorToolset_Source_SlateInspectorToolset_Public_SlateInspectorToolset_h_77_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class USlateInspectorToolset;

// ********** End Class USlateInspectorToolset *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_Toolsets_SlateInspectorToolset_Source_SlateInspectorToolset_Public_SlateInspectorToolset_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
