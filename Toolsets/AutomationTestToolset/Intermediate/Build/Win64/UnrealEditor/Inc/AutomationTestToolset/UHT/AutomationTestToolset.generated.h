// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AutomationTestToolset.h"

#ifdef AUTOMATIONTESTTOOLSET_AutomationTestToolset_generated_h
#error "AutomationTestToolset.generated.h already included, missing '#pragma once' in AutomationTestToolset.h"
#endif
#define AUTOMATIONTESTTOOLSET_AutomationTestToolset_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UToolCallAsyncResultString;

// ********** Begin Class UAutomationTestToolset ***************************************************
#define FID_UE_MCP_Plugins_Toolsets_AutomationTestToolset_Source_AutomationTestToolset_Public_AutomationTestToolset_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execStopTests); \
	DECLARE_FUNCTION(execGetTestStatus); \
	DECLARE_FUNCTION(execGetTestResults); \
	DECLARE_FUNCTION(execRunTestsByFilter); \
	DECLARE_FUNCTION(execRunTests); \
	DECLARE_FUNCTION(execListTests); \
	DECLARE_FUNCTION(execDiscoverTests);


struct Z_Construct_UClass_UAutomationTestToolset_Statics;
AUTOMATIONTESTTOOLSET_API UClass* Z_Construct_UClass_UAutomationTestToolset_NoRegister();

#define FID_UE_MCP_Plugins_Toolsets_AutomationTestToolset_Source_AutomationTestToolset_Public_AutomationTestToolset_h_28_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAutomationTestToolset(); \
	friend struct ::Z_Construct_UClass_UAutomationTestToolset_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend AUTOMATIONTESTTOOLSET_API UClass* ::Z_Construct_UClass_UAutomationTestToolset_NoRegister(); \
public: \
	DECLARE_CLASS2(UAutomationTestToolset, UToolsetDefinition, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AutomationTestToolset"), Z_Construct_UClass_UAutomationTestToolset_NoRegister) \
	DECLARE_SERIALIZER(UAutomationTestToolset)


#define FID_UE_MCP_Plugins_Toolsets_AutomationTestToolset_Source_AutomationTestToolset_Public_AutomationTestToolset_h_28_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	AUTOMATIONTESTTOOLSET_API UAutomationTestToolset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UAutomationTestToolset(UAutomationTestToolset&&) = delete; \
	UAutomationTestToolset(const UAutomationTestToolset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(AUTOMATIONTESTTOOLSET_API, UAutomationTestToolset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAutomationTestToolset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAutomationTestToolset) \
	AUTOMATIONTESTTOOLSET_API virtual ~UAutomationTestToolset();


#define FID_UE_MCP_Plugins_Toolsets_AutomationTestToolset_Source_AutomationTestToolset_Public_AutomationTestToolset_h_25_PROLOG
#define FID_UE_MCP_Plugins_Toolsets_AutomationTestToolset_Source_AutomationTestToolset_Public_AutomationTestToolset_h_28_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_Toolsets_AutomationTestToolset_Source_AutomationTestToolset_Public_AutomationTestToolset_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_AutomationTestToolset_Source_AutomationTestToolset_Public_AutomationTestToolset_h_28_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_AutomationTestToolset_Source_AutomationTestToolset_Public_AutomationTestToolset_h_28_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UAutomationTestToolset;

// ********** End Class UAutomationTestToolset *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_Toolsets_AutomationTestToolset_Source_AutomationTestToolset_Public_AutomationTestToolset_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
