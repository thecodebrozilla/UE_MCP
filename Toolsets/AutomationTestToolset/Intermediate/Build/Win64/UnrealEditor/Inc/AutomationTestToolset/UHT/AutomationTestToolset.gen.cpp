// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AutomationTestToolset.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeAutomationTestToolset() {}

// ********** Begin Cross Module References ********************************************************
AUTOMATIONTESTTOOLSET_API UClass* Z_Construct_UClass_UAutomationTestToolset();
AUTOMATIONTESTTOOLSET_API UClass* Z_Construct_UClass_UAutomationTestToolset_NoRegister();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolCallAsyncResultString_NoRegister();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition();
UPackage* Z_Construct_UPackage__Script_AutomationTestToolset();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UAutomationTestToolset Function DiscoverTests ****************************
struct Z_Construct_UFunction_UAutomationTestToolset_DiscoverTests_Statics
{
	struct AutomationTestToolset_eventDiscoverTests_Parms
	{
		bool bForceRediscover;
		UToolCallAsyncResultString* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "AutomationTestToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Initialize automation worker discovery and load the test list.\n\x09 * Must be called once before ListTests or RunTests. Takes several seconds\n\x09 * as it discovers the local automation worker and enumerates all registered\n\x09 * tests. Returns an async result that completes with a JSON status object\n\x09 * when tests are available, or an error if discovery fails.\n\x09 * @param bForceRediscover  When true, bypass the cached report tree and re-poll\n\x09 *   workers. Used after reloading Python test modules mid-session. */" },
#endif
		{ "ModuleRelativePath", "Public/AutomationTestToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initialize automation worker discovery and load the test list.\nMust be called once before ListTests or RunTests. Takes several seconds\nas it discovers the local automation worker and enumerates all registered\ntests. Returns an async result that completes with a JSON status object\nwhen tests are available, or an error if discovery fails.\n@param bForceRediscover  When true, bypass the cached report tree and re-poll\n workers. Used after reloading Python test modules mid-session." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function DiscoverTests constinit property declarations *************************
	static void NewProp_bForceRediscover_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bForceRediscover;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DiscoverTests constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DiscoverTests Property Definitions ************************************
void Z_Construct_UFunction_UAutomationTestToolset_DiscoverTests_Statics::NewProp_bForceRediscover_SetBit(void* Obj)
{
	((AutomationTestToolset_eventDiscoverTests_Parms*)Obj)->bForceRediscover = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAutomationTestToolset_DiscoverTests_Statics::NewProp_bForceRediscover = { "bForceRediscover", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AutomationTestToolset_eventDiscoverTests_Parms), &Z_Construct_UFunction_UAutomationTestToolset_DiscoverTests_Statics::NewProp_bForceRediscover_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAutomationTestToolset_DiscoverTests_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AutomationTestToolset_eventDiscoverTests_Parms, ReturnValue), Z_Construct_UClass_UToolCallAsyncResultString_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAutomationTestToolset_DiscoverTests_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAutomationTestToolset_DiscoverTests_Statics::NewProp_bForceRediscover,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAutomationTestToolset_DiscoverTests_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAutomationTestToolset_DiscoverTests_Statics::PropPointers) < 2048);
// ********** End Function DiscoverTests Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAutomationTestToolset_DiscoverTests_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAutomationTestToolset, nullptr, "DiscoverTests", 	Z_Construct_UFunction_UAutomationTestToolset_DiscoverTests_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAutomationTestToolset_DiscoverTests_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAutomationTestToolset_DiscoverTests_Statics::AutomationTestToolset_eventDiscoverTests_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAutomationTestToolset_DiscoverTests_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAutomationTestToolset_DiscoverTests_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAutomationTestToolset_DiscoverTests_Statics::AutomationTestToolset_eventDiscoverTests_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAutomationTestToolset_DiscoverTests()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAutomationTestToolset_DiscoverTests_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAutomationTestToolset::execDiscoverTests)
{
	P_GET_UBOOL(Z_Param_bForceRediscover);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UToolCallAsyncResultString**)Z_Param__Result=UAutomationTestToolset::DiscoverTests(Z_Param_bForceRediscover);
	P_NATIVE_END;
}
// ********** End Class UAutomationTestToolset Function DiscoverTests ******************************

// ********** Begin Class UAutomationTestToolset Function GetTestResults ***************************
struct Z_Construct_UFunction_UAutomationTestToolset_GetTestResults_Statics
{
	struct AutomationTestToolset_eventGetTestResults_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "AutomationTestToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Get detailed results for the current or most recent test run.\n\x09 * Requires DiscoverTests() to have completed.\n\x09 * Returns a JSON object with per-test state, duration, errors, and warnings. */" },
#endif
		{ "ModuleRelativePath", "Public/AutomationTestToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get detailed results for the current or most recent test run.\nRequires DiscoverTests() to have completed.\nReturns a JSON object with per-test state, duration, errors, and warnings." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetTestResults constinit property declarations ************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetTestResults constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetTestResults Property Definitions ***********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAutomationTestToolset_GetTestResults_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AutomationTestToolset_eventGetTestResults_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAutomationTestToolset_GetTestResults_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAutomationTestToolset_GetTestResults_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAutomationTestToolset_GetTestResults_Statics::PropPointers) < 2048);
// ********** End Function GetTestResults Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAutomationTestToolset_GetTestResults_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAutomationTestToolset, nullptr, "GetTestResults", 	Z_Construct_UFunction_UAutomationTestToolset_GetTestResults_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAutomationTestToolset_GetTestResults_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAutomationTestToolset_GetTestResults_Statics::AutomationTestToolset_eventGetTestResults_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAutomationTestToolset_GetTestResults_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAutomationTestToolset_GetTestResults_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAutomationTestToolset_GetTestResults_Statics::AutomationTestToolset_eventGetTestResults_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAutomationTestToolset_GetTestResults()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAutomationTestToolset_GetTestResults_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAutomationTestToolset::execGetTestResults)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UAutomationTestToolset::GetTestResults();
	P_NATIVE_END;
}
// ********** End Class UAutomationTestToolset Function GetTestResults *****************************

// ********** Begin Class UAutomationTestToolset Function GetTestStatus ****************************
struct Z_Construct_UFunction_UAutomationTestToolset_GetTestStatus_Statics
{
	struct AutomationTestToolset_eventGetTestStatus_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "AutomationTestToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Get a lightweight status snapshot of the automation controller.\n\x09 * Requires DiscoverTests() to have completed.\n\x09 * Returns a JSON object with the controller state, enabled test count,\n\x09 * and completion/pass/fail counts. */" },
#endif
		{ "ModuleRelativePath", "Public/AutomationTestToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get a lightweight status snapshot of the automation controller.\nRequires DiscoverTests() to have completed.\nReturns a JSON object with the controller state, enabled test count,\nand completion/pass/fail counts." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetTestStatus constinit property declarations *************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetTestStatus constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetTestStatus Property Definitions ************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAutomationTestToolset_GetTestStatus_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AutomationTestToolset_eventGetTestStatus_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAutomationTestToolset_GetTestStatus_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAutomationTestToolset_GetTestStatus_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAutomationTestToolset_GetTestStatus_Statics::PropPointers) < 2048);
// ********** End Function GetTestStatus Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAutomationTestToolset_GetTestStatus_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAutomationTestToolset, nullptr, "GetTestStatus", 	Z_Construct_UFunction_UAutomationTestToolset_GetTestStatus_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAutomationTestToolset_GetTestStatus_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAutomationTestToolset_GetTestStatus_Statics::AutomationTestToolset_eventGetTestStatus_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAutomationTestToolset_GetTestStatus_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAutomationTestToolset_GetTestStatus_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAutomationTestToolset_GetTestStatus_Statics::AutomationTestToolset_eventGetTestStatus_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAutomationTestToolset_GetTestStatus()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAutomationTestToolset_GetTestStatus_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAutomationTestToolset::execGetTestStatus)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UAutomationTestToolset::GetTestStatus();
	P_NATIVE_END;
}
// ********** End Class UAutomationTestToolset Function GetTestStatus ******************************

// ********** Begin Class UAutomationTestToolset Function ListTests ********************************
struct Z_Construct_UFunction_UAutomationTestToolset_ListTests_Statics
{
	struct AutomationTestToolset_eventListTests_Parms
	{
		FString NameFilter;
		FString TagFilter;
		int32 Limit;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "AutomationTestToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** List available automation tests. Requires DiscoverTests() to have completed.\n\x09 * Returns a JSON object: {\"tests\": [\"path1\", ...], \"total\": N, \"returned\": N}.\n\x09 * @param NameFilter  Optional substring filter applied to the test's full path.\n\x09 * @param TagFilter   Optional substring filter applied to the test's tags.\n\x09 * @param Limit       Maximum number of tests to return (0 = unlimited, default 200). */" },
#endif
		{ "ModuleRelativePath", "Public/AutomationTestToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "List available automation tests. Requires DiscoverTests() to have completed.\nReturns a JSON object: {\"tests\": [\"path1\", ...], \"total\": N, \"returned\": N}.\n@param NameFilter  Optional substring filter applied to the test's full path.\n@param TagFilter   Optional substring filter applied to the test's tags.\n@param Limit       Maximum number of tests to return (0 = unlimited, default 200)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NameFilter_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TagFilter_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ListTests constinit property declarations *****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_NameFilter;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TagFilter;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Limit;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListTests constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListTests Property Definitions ****************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAutomationTestToolset_ListTests_Statics::NewProp_NameFilter = { "NameFilter", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AutomationTestToolset_eventListTests_Parms, NameFilter), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NameFilter_MetaData), NewProp_NameFilter_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAutomationTestToolset_ListTests_Statics::NewProp_TagFilter = { "TagFilter", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AutomationTestToolset_eventListTests_Parms, TagFilter), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TagFilter_MetaData), NewProp_TagFilter_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAutomationTestToolset_ListTests_Statics::NewProp_Limit = { "Limit", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AutomationTestToolset_eventListTests_Parms, Limit), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAutomationTestToolset_ListTests_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AutomationTestToolset_eventListTests_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAutomationTestToolset_ListTests_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAutomationTestToolset_ListTests_Statics::NewProp_NameFilter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAutomationTestToolset_ListTests_Statics::NewProp_TagFilter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAutomationTestToolset_ListTests_Statics::NewProp_Limit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAutomationTestToolset_ListTests_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAutomationTestToolset_ListTests_Statics::PropPointers) < 2048);
// ********** End Function ListTests Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAutomationTestToolset_ListTests_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAutomationTestToolset, nullptr, "ListTests", 	Z_Construct_UFunction_UAutomationTestToolset_ListTests_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAutomationTestToolset_ListTests_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAutomationTestToolset_ListTests_Statics::AutomationTestToolset_eventListTests_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAutomationTestToolset_ListTests_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAutomationTestToolset_ListTests_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAutomationTestToolset_ListTests_Statics::AutomationTestToolset_eventListTests_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAutomationTestToolset_ListTests()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAutomationTestToolset_ListTests_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAutomationTestToolset::execListTests)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_NameFilter);
	P_GET_PROPERTY(FStrProperty,Z_Param_TagFilter);
	P_GET_PROPERTY(FIntProperty,Z_Param_Limit);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UAutomationTestToolset::ListTests(Z_Param_NameFilter,Z_Param_TagFilter,Z_Param_Limit);
	P_NATIVE_END;
}
// ********** End Class UAutomationTestToolset Function ListTests **********************************

// ********** Begin Class UAutomationTestToolset Function RunTests *********************************
struct Z_Construct_UFunction_UAutomationTestToolset_RunTests_Statics
{
	struct AutomationTestToolset_eventRunTests_Parms
	{
		TArray<FString> TestNames;
		UToolCallAsyncResultString* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "AutomationTestToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Run a set of automation tests by name. Requires DiscoverTests() to have completed.\n\x09 * Starts executing the specified tests and returns an async result that\n\x09 * completes with a JSON summary when all tests finish.\n\x09 * @param TestNames  Array of full test paths as returned by ListTests. */" },
#endif
		{ "ModuleRelativePath", "Public/AutomationTestToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Run a set of automation tests by name. Requires DiscoverTests() to have completed.\nStarts executing the specified tests and returns an async result that\ncompletes with a JSON summary when all tests finish.\n@param TestNames  Array of full test paths as returned by ListTests." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TestNames_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RunTests constinit property declarations ******************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_TestNames_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_TestNames;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RunTests constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RunTests Property Definitions *****************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAutomationTestToolset_RunTests_Statics::NewProp_TestNames_Inner = { "TestNames", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UAutomationTestToolset_RunTests_Statics::NewProp_TestNames = { "TestNames", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AutomationTestToolset_eventRunTests_Parms, TestNames), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TestNames_MetaData), NewProp_TestNames_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAutomationTestToolset_RunTests_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AutomationTestToolset_eventRunTests_Parms, ReturnValue), Z_Construct_UClass_UToolCallAsyncResultString_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAutomationTestToolset_RunTests_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAutomationTestToolset_RunTests_Statics::NewProp_TestNames_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAutomationTestToolset_RunTests_Statics::NewProp_TestNames,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAutomationTestToolset_RunTests_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAutomationTestToolset_RunTests_Statics::PropPointers) < 2048);
// ********** End Function RunTests Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAutomationTestToolset_RunTests_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAutomationTestToolset, nullptr, "RunTests", 	Z_Construct_UFunction_UAutomationTestToolset_RunTests_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAutomationTestToolset_RunTests_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAutomationTestToolset_RunTests_Statics::AutomationTestToolset_eventRunTests_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAutomationTestToolset_RunTests_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAutomationTestToolset_RunTests_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAutomationTestToolset_RunTests_Statics::AutomationTestToolset_eventRunTests_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAutomationTestToolset_RunTests()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAutomationTestToolset_RunTests_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAutomationTestToolset::execRunTests)
{
	P_GET_TARRAY_REF(FString,Z_Param_Out_TestNames);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UToolCallAsyncResultString**)Z_Param__Result=UAutomationTestToolset::RunTests(Z_Param_Out_TestNames);
	P_NATIVE_END;
}
// ********** End Class UAutomationTestToolset Function RunTests ***********************************

// ********** Begin Class UAutomationTestToolset Function RunTestsByFilter *************************
struct Z_Construct_UFunction_UAutomationTestToolset_RunTestsByFilter_Statics
{
	struct AutomationTestToolset_eventRunTestsByFilter_Parms
	{
		FString FilterExpression;
		UToolCallAsyncResultString* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "AutomationTestToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Run automation tests selected by a filter expression. Requires DiscoverTests()\n\x09 * to have completed. Much faster than RunTests when targeting a large batch\n\x09 * because the engine narrows the report tree in a single pass instead of\n\x09 * running a per-leaf membership check against the requested name list.\n\x09 *\n\x09 * Filter syntax (multiple expressions joined by '+'):\n\x09 *   \"StartsWith:System.Engine\"  prefix match against the full test path\n\x09 *   \"^Foo\"                       prefix anchor (equivalent to StartsWith:)\n\x09 *   \"Bar$\"                       suffix anchor\n\x09 *   \"Substring\"                  bare token matches anywhere in the path\n\x09 *   \"Group:Smoke\"                expand a named group from\n\x09 *                                AutomationControllerSettings ini Groups\n\x09 *\n\x09 * Returns an async result that completes with the same JSON summary as RunTests.\n\x09 * @param FilterExpression  Filter expression as described above. */" },
#endif
		{ "ModuleRelativePath", "Public/AutomationTestToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Run automation tests selected by a filter expression. Requires DiscoverTests()\nto have completed. Much faster than RunTests when targeting a large batch\nbecause the engine narrows the report tree in a single pass instead of\nrunning a per-leaf membership check against the requested name list.\n\nFilter syntax (multiple expressions joined by '+'):\n \"StartsWith:System.Engine\"  prefix match against the full test path\n \"^Foo\"                       prefix anchor (equivalent to StartsWith:)\n \"Bar$\"                       suffix anchor\n \"Substring\"                  bare token matches anywhere in the path\n \"Group:Smoke\"                expand a named group from\n                              AutomationControllerSettings ini Groups\n\nReturns an async result that completes with the same JSON summary as RunTests.\n@param FilterExpression  Filter expression as described above." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FilterExpression_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RunTestsByFilter constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FilterExpression;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RunTestsByFilter constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RunTestsByFilter Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAutomationTestToolset_RunTestsByFilter_Statics::NewProp_FilterExpression = { "FilterExpression", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AutomationTestToolset_eventRunTestsByFilter_Parms, FilterExpression), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FilterExpression_MetaData), NewProp_FilterExpression_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAutomationTestToolset_RunTestsByFilter_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AutomationTestToolset_eventRunTestsByFilter_Parms, ReturnValue), Z_Construct_UClass_UToolCallAsyncResultString_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAutomationTestToolset_RunTestsByFilter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAutomationTestToolset_RunTestsByFilter_Statics::NewProp_FilterExpression,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAutomationTestToolset_RunTestsByFilter_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAutomationTestToolset_RunTestsByFilter_Statics::PropPointers) < 2048);
// ********** End Function RunTestsByFilter Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAutomationTestToolset_RunTestsByFilter_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAutomationTestToolset, nullptr, "RunTestsByFilter", 	Z_Construct_UFunction_UAutomationTestToolset_RunTestsByFilter_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAutomationTestToolset_RunTestsByFilter_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAutomationTestToolset_RunTestsByFilter_Statics::AutomationTestToolset_eventRunTestsByFilter_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAutomationTestToolset_RunTestsByFilter_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAutomationTestToolset_RunTestsByFilter_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAutomationTestToolset_RunTestsByFilter_Statics::AutomationTestToolset_eventRunTestsByFilter_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAutomationTestToolset_RunTestsByFilter()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAutomationTestToolset_RunTestsByFilter_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAutomationTestToolset::execRunTestsByFilter)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FilterExpression);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UToolCallAsyncResultString**)Z_Param__Result=UAutomationTestToolset::RunTestsByFilter(Z_Param_FilterExpression);
	P_NATIVE_END;
}
// ********** End Class UAutomationTestToolset Function RunTestsByFilter ***************************

// ********** Begin Class UAutomationTestToolset Function StopTests ********************************
struct Z_Construct_UFunction_UAutomationTestToolset_StopTests_Statics
{
	struct AutomationTestToolset_eventStopTests_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "AutomationTestToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Stop all currently running tests. Requires DiscoverTests() to have completed.\n\x09 * If a RunTests async result is pending, it will be completed with an error.\n\x09 * @return True if the stop request was issued successfully. */" },
#endif
		{ "ModuleRelativePath", "Public/AutomationTestToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stop all currently running tests. Requires DiscoverTests() to have completed.\nIf a RunTests async result is pending, it will be completed with an error.\n@return True if the stop request was issued successfully." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function StopTests constinit property declarations *****************************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function StopTests constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function StopTests Property Definitions ****************************************
void Z_Construct_UFunction_UAutomationTestToolset_StopTests_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((AutomationTestToolset_eventStopTests_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAutomationTestToolset_StopTests_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AutomationTestToolset_eventStopTests_Parms), &Z_Construct_UFunction_UAutomationTestToolset_StopTests_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAutomationTestToolset_StopTests_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAutomationTestToolset_StopTests_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAutomationTestToolset_StopTests_Statics::PropPointers) < 2048);
// ********** End Function StopTests Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAutomationTestToolset_StopTests_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAutomationTestToolset, nullptr, "StopTests", 	Z_Construct_UFunction_UAutomationTestToolset_StopTests_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAutomationTestToolset_StopTests_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAutomationTestToolset_StopTests_Statics::AutomationTestToolset_eventStopTests_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAutomationTestToolset_StopTests_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAutomationTestToolset_StopTests_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAutomationTestToolset_StopTests_Statics::AutomationTestToolset_eventStopTests_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAutomationTestToolset_StopTests()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAutomationTestToolset_StopTests_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAutomationTestToolset::execStopTests)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UAutomationTestToolset::StopTests();
	P_NATIVE_END;
}
// ********** End Class UAutomationTestToolset Function StopTests **********************************

// ********** Begin Class UAutomationTestToolset ***************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UAutomationTestToolset;
UClass* UAutomationTestToolset::GetPrivateStaticClass()
{
	using TClass = UAutomationTestToolset;
	if (!Z_Registration_Info_UClass_UAutomationTestToolset.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("AutomationTestToolset"),
			Z_Registration_Info_UClass_UAutomationTestToolset.InnerSingleton,
			StaticRegisterNativesUAutomationTestToolset,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UAutomationTestToolset.InnerSingleton;
}
UClass* Z_Construct_UClass_UAutomationTestToolset_NoRegister()
{
	return UAutomationTestToolset::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UAutomationTestToolset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Automation test discovery and execution toolset.\n *\n * Wraps the IAutomationControllerManager API (the same backend the Session\n * Frontend uses) to let MCP clients list available tests, run them, and\n * retrieve results.\n *\n * Typical workflow:\n *   1. DiscoverTests() once per session to initialize workers and load the test list.\n *   2. ListTests() to find tests by name or tag.\n *   3. RunTests() with the desired test names.\n *   4. GetTestStatus() / GetTestResults() to monitor and retrieve results.\n *   5. StopTests() to abort if needed.\n */" },
#endif
		{ "IncludePath", "AutomationTestToolset.h" },
		{ "ModuleRelativePath", "Public/AutomationTestToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Automation test discovery and execution toolset.\n\nWraps the IAutomationControllerManager API (the same backend the Session\nFrontend uses) to let MCP clients list available tests, run them, and\nretrieve results.\n\nTypical workflow:\n  1. DiscoverTests() once per session to initialize workers and load the test list.\n  2. ListTests() to find tests by name or tag.\n  3. RunTests() with the desired test names.\n  4. GetTestStatus() / GetTestResults() to monitor and retrieve results.\n  5. StopTests() to abort if needed." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UAutomationTestToolset constinit property declarations *******************
// ********** End Class UAutomationTestToolset constinit property declarations *********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("DiscoverTests"), .Pointer = &UAutomationTestToolset::execDiscoverTests },
		{ .NameUTF8 = UTF8TEXT("GetTestResults"), .Pointer = &UAutomationTestToolset::execGetTestResults },
		{ .NameUTF8 = UTF8TEXT("GetTestStatus"), .Pointer = &UAutomationTestToolset::execGetTestStatus },
		{ .NameUTF8 = UTF8TEXT("ListTests"), .Pointer = &UAutomationTestToolset::execListTests },
		{ .NameUTF8 = UTF8TEXT("RunTests"), .Pointer = &UAutomationTestToolset::execRunTests },
		{ .NameUTF8 = UTF8TEXT("RunTestsByFilter"), .Pointer = &UAutomationTestToolset::execRunTestsByFilter },
		{ .NameUTF8 = UTF8TEXT("StopTests"), .Pointer = &UAutomationTestToolset::execStopTests },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UAutomationTestToolset_DiscoverTests, "DiscoverTests" }, // 2070866174
		{ &Z_Construct_UFunction_UAutomationTestToolset_GetTestResults, "GetTestResults" }, // 596736890
		{ &Z_Construct_UFunction_UAutomationTestToolset_GetTestStatus, "GetTestStatus" }, // 384528499
		{ &Z_Construct_UFunction_UAutomationTestToolset_ListTests, "ListTests" }, // 905641698
		{ &Z_Construct_UFunction_UAutomationTestToolset_RunTests, "RunTests" }, // 1529181430
		{ &Z_Construct_UFunction_UAutomationTestToolset_RunTestsByFilter, "RunTestsByFilter" }, // 1061736806
		{ &Z_Construct_UFunction_UAutomationTestToolset_StopTests, "StopTests" }, // 3700862929
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAutomationTestToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UAutomationTestToolset_Statics
UObject* (*const Z_Construct_UClass_UAutomationTestToolset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UToolsetDefinition,
	(UObject* (*)())Z_Construct_UPackage__Script_AutomationTestToolset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAutomationTestToolset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAutomationTestToolset_Statics::ClassParams = {
	&UAutomationTestToolset::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x000800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAutomationTestToolset_Statics::Class_MetaDataParams), Z_Construct_UClass_UAutomationTestToolset_Statics::Class_MetaDataParams)
};
void UAutomationTestToolset::StaticRegisterNativesUAutomationTestToolset()
{
	UClass* Class = UAutomationTestToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UAutomationTestToolset_Statics::Funcs));
}
UClass* Z_Construct_UClass_UAutomationTestToolset()
{
	if (!Z_Registration_Info_UClass_UAutomationTestToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAutomationTestToolset.OuterSingleton, Z_Construct_UClass_UAutomationTestToolset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAutomationTestToolset.OuterSingleton;
}
UAutomationTestToolset::UAutomationTestToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UAutomationTestToolset);
UAutomationTestToolset::~UAutomationTestToolset() {}
// ********** End Class UAutomationTestToolset *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_AutomationTestToolset_Source_AutomationTestToolset_Public_AutomationTestToolset_h__Script_AutomationTestToolset_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAutomationTestToolset, UAutomationTestToolset::StaticClass, TEXT("UAutomationTestToolset"), &Z_Registration_Info_UClass_UAutomationTestToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAutomationTestToolset), 426456123U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_AutomationTestToolset_Source_AutomationTestToolset_Public_AutomationTestToolset_h__Script_AutomationTestToolset_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_AutomationTestToolset_Source_AutomationTestToolset_Public_AutomationTestToolset_h__Script_AutomationTestToolset_1859317538{
	TEXT("/Script/AutomationTestToolset"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_AutomationTestToolset_Source_AutomationTestToolset_Public_AutomationTestToolset_h__Script_AutomationTestToolset_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_AutomationTestToolset_Source_AutomationTestToolset_Public_AutomationTestToolset_h__Script_AutomationTestToolset_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
