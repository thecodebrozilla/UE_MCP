// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LogsToolset.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeLogsToolset() {}

// ********** Begin Cross Module References ********************************************************
EDITORTOOLSET_API UClass* Z_Construct_UClass_ULogsToolset();
EDITORTOOLSET_API UClass* Z_Construct_UClass_ULogsToolset_NoRegister();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition();
UPackage* Z_Construct_UPackage__Script_EditorToolset();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ULogsToolset Function GetLogCategories ***********************************
struct Z_Construct_UFunction_ULogsToolset_GetLogCategories_Statics
{
	struct LogsToolset_eventGetLogCategories_Parms
	{
		FString Filter;
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "LogsToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns a sorted list of registered log categories.\n\x09 * @param Filter If non-empty, only returns categories whose name contains this\n\x09 *   substring.\n\x09 * @return A sorted list of log category names (e.g. [\"LogBlueprint\", \"LogTemp\"]).\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/LogsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns a sorted list of registered log categories.\n@param Filter If non-empty, only returns categories whose name contains this\n  substring.\n@return A sorted list of log category names (e.g. [\"LogBlueprint\", \"LogTemp\"])." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Filter_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetLogCategories constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Filter;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetLogCategories constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetLogCategories Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ULogsToolset_GetLogCategories_Statics::NewProp_Filter = { "Filter", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LogsToolset_eventGetLogCategories_Parms, Filter), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Filter_MetaData), NewProp_Filter_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ULogsToolset_GetLogCategories_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULogsToolset_GetLogCategories_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LogsToolset_eventGetLogCategories_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULogsToolset_GetLogCategories_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULogsToolset_GetLogCategories_Statics::NewProp_Filter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULogsToolset_GetLogCategories_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULogsToolset_GetLogCategories_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULogsToolset_GetLogCategories_Statics::PropPointers) < 2048);
// ********** End Function GetLogCategories Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULogsToolset_GetLogCategories_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULogsToolset, nullptr, "GetLogCategories", 	Z_Construct_UFunction_ULogsToolset_GetLogCategories_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ULogsToolset_GetLogCategories_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_ULogsToolset_GetLogCategories_Statics::LogsToolset_eventGetLogCategories_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULogsToolset_GetLogCategories_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULogsToolset_GetLogCategories_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULogsToolset_GetLogCategories_Statics::LogsToolset_eventGetLogCategories_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULogsToolset_GetLogCategories()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULogsToolset_GetLogCategories_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULogsToolset::execGetLogCategories)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Filter);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=ULogsToolset::GetLogCategories(Z_Param_Filter);
	P_NATIVE_END;
}
// ********** End Class ULogsToolset Function GetLogCategories *************************************

// ********** Begin Class ULogsToolset Function GetLogEntries **************************************
struct Z_Construct_UFunction_ULogsToolset_GetLogEntries_Statics
{
	struct LogsToolset_eventGetLogEntries_Parms
	{
		FString Category;
		FString Pattern;
		int32 MaxEntries;
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "LogsToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns log entries from the current session's log file.\n\x09 * @param Category If non-empty, only returns entries from this log category (e.g. \"LogTemp\").\n\x09 * @param Pattern If non-empty, only returns entries whose text matches this regular\n\x09 *   expression.\n\x09 * @param MaxEntries Maximum number of entries to return, taken from the end of the log.\n\x09 *   Pass 0 for no limit. Defaults to 1000.\n\x09 * @return A list of matching log entries in chronological order.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/LogsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns log entries from the current session's log file.\n@param Category If non-empty, only returns entries from this log category (e.g. \"LogTemp\").\n@param Pattern If non-empty, only returns entries whose text matches this regular\n  expression.\n@param MaxEntries Maximum number of entries to return, taken from the end of the log.\n  Pass 0 for no limit. Defaults to 1000.\n@return A list of matching log entries in chronological order." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Category_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Pattern_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetLogEntries constinit property declarations *************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Category;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Pattern;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxEntries;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetLogEntries constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetLogEntries Property Definitions ************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ULogsToolset_GetLogEntries_Statics::NewProp_Category = { "Category", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LogsToolset_eventGetLogEntries_Parms, Category), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Category_MetaData), NewProp_Category_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ULogsToolset_GetLogEntries_Statics::NewProp_Pattern = { "Pattern", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LogsToolset_eventGetLogEntries_Parms, Pattern), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Pattern_MetaData), NewProp_Pattern_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULogsToolset_GetLogEntries_Statics::NewProp_MaxEntries = { "MaxEntries", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LogsToolset_eventGetLogEntries_Parms, MaxEntries), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ULogsToolset_GetLogEntries_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULogsToolset_GetLogEntries_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LogsToolset_eventGetLogEntries_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULogsToolset_GetLogEntries_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULogsToolset_GetLogEntries_Statics::NewProp_Category,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULogsToolset_GetLogEntries_Statics::NewProp_Pattern,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULogsToolset_GetLogEntries_Statics::NewProp_MaxEntries,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULogsToolset_GetLogEntries_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULogsToolset_GetLogEntries_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULogsToolset_GetLogEntries_Statics::PropPointers) < 2048);
// ********** End Function GetLogEntries Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULogsToolset_GetLogEntries_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULogsToolset, nullptr, "GetLogEntries", 	Z_Construct_UFunction_ULogsToolset_GetLogEntries_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ULogsToolset_GetLogEntries_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_ULogsToolset_GetLogEntries_Statics::LogsToolset_eventGetLogEntries_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULogsToolset_GetLogEntries_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULogsToolset_GetLogEntries_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULogsToolset_GetLogEntries_Statics::LogsToolset_eventGetLogEntries_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULogsToolset_GetLogEntries()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULogsToolset_GetLogEntries_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULogsToolset::execGetLogEntries)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Category);
	P_GET_PROPERTY(FStrProperty,Z_Param_Pattern);
	P_GET_PROPERTY(FIntProperty,Z_Param_MaxEntries);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=ULogsToolset::GetLogEntries(Z_Param_Category,Z_Param_Pattern,Z_Param_MaxEntries);
	P_NATIVE_END;
}
// ********** End Class ULogsToolset Function GetLogEntries ****************************************

// ********** Begin Class ULogsToolset Function GetVerbosity ***************************************
struct Z_Construct_UFunction_ULogsToolset_GetVerbosity_Statics
{
	struct LogsToolset_eventGetVerbosity_Parms
	{
		FString Category;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "LogsToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the current verbosity level for a log category.\n\x09 * @param Category The log category name, e.g. \"LogTemp\".\n\x09 * @return The verbosity level as a string: one of \"NoLogging\", \"Fatal\", \"Error\",\n\x09 *   \"Warning\", \"Display\", \"Log\", \"Verbose\", or \"VeryVerbose\". Raises a script error\n\x09 *   if the category is not found.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/LogsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the current verbosity level for a log category.\n@param Category The log category name, e.g. \"LogTemp\".\n@return The verbosity level as a string: one of \"NoLogging\", \"Fatal\", \"Error\",\n  \"Warning\", \"Display\", \"Log\", \"Verbose\", or \"VeryVerbose\". Raises a script error\n  if the category is not found." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Category_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetVerbosity constinit property declarations **************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Category;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetVerbosity constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetVerbosity Property Definitions *************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ULogsToolset_GetVerbosity_Statics::NewProp_Category = { "Category", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LogsToolset_eventGetVerbosity_Parms, Category), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Category_MetaData), NewProp_Category_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ULogsToolset_GetVerbosity_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LogsToolset_eventGetVerbosity_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULogsToolset_GetVerbosity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULogsToolset_GetVerbosity_Statics::NewProp_Category,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULogsToolset_GetVerbosity_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULogsToolset_GetVerbosity_Statics::PropPointers) < 2048);
// ********** End Function GetVerbosity Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULogsToolset_GetVerbosity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULogsToolset, nullptr, "GetVerbosity", 	Z_Construct_UFunction_ULogsToolset_GetVerbosity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ULogsToolset_GetVerbosity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_ULogsToolset_GetVerbosity_Statics::LogsToolset_eventGetVerbosity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULogsToolset_GetVerbosity_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULogsToolset_GetVerbosity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULogsToolset_GetVerbosity_Statics::LogsToolset_eventGetVerbosity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULogsToolset_GetVerbosity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULogsToolset_GetVerbosity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULogsToolset::execGetVerbosity)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Category);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=ULogsToolset::GetVerbosity(Z_Param_Category);
	P_NATIVE_END;
}
// ********** End Class ULogsToolset Function GetVerbosity *****************************************

// ********** Begin Class ULogsToolset Function SetVerbosity ***************************************
struct Z_Construct_UFunction_ULogsToolset_SetVerbosity_Statics
{
	struct LogsToolset_eventSetVerbosity_Parms
	{
		FString Category;
		FString Verbosity;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "LogsToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Sets the verbosity level for a log category.\n\x09 * @param Category The log category name, e.g. \"LogTemp\".\n\x09 * @param Verbosity The verbosity level: one of \"NoLogging\", \"Fatal\", \"Error\",\n\x09 *   \"Warning\", \"Display\", \"Log\", \"Verbose\", or \"VeryVerbose\".\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/LogsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the verbosity level for a log category.\n@param Category The log category name, e.g. \"LogTemp\".\n@param Verbosity The verbosity level: one of \"NoLogging\", \"Fatal\", \"Error\",\n  \"Warning\", \"Display\", \"Log\", \"Verbose\", or \"VeryVerbose\"." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Category_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Verbosity_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetVerbosity constinit property declarations **************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Category;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Verbosity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetVerbosity constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetVerbosity Property Definitions *************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ULogsToolset_SetVerbosity_Statics::NewProp_Category = { "Category", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LogsToolset_eventSetVerbosity_Parms, Category), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Category_MetaData), NewProp_Category_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ULogsToolset_SetVerbosity_Statics::NewProp_Verbosity = { "Verbosity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LogsToolset_eventSetVerbosity_Parms, Verbosity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Verbosity_MetaData), NewProp_Verbosity_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULogsToolset_SetVerbosity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULogsToolset_SetVerbosity_Statics::NewProp_Category,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULogsToolset_SetVerbosity_Statics::NewProp_Verbosity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULogsToolset_SetVerbosity_Statics::PropPointers) < 2048);
// ********** End Function SetVerbosity Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULogsToolset_SetVerbosity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULogsToolset, nullptr, "SetVerbosity", 	Z_Construct_UFunction_ULogsToolset_SetVerbosity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ULogsToolset_SetVerbosity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_ULogsToolset_SetVerbosity_Statics::LogsToolset_eventSetVerbosity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULogsToolset_SetVerbosity_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULogsToolset_SetVerbosity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULogsToolset_SetVerbosity_Statics::LogsToolset_eventSetVerbosity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULogsToolset_SetVerbosity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULogsToolset_SetVerbosity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULogsToolset::execSetVerbosity)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Category);
	P_GET_PROPERTY(FStrProperty,Z_Param_Verbosity);
	P_FINISH;
	P_NATIVE_BEGIN;
	ULogsToolset::SetVerbosity(Z_Param_Category,Z_Param_Verbosity);
	P_NATIVE_END;
}
// ********** End Class ULogsToolset Function SetVerbosity *****************************************

// ********** Begin Class ULogsToolset *************************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_ULogsToolset;
UClass* ULogsToolset::GetPrivateStaticClass()
{
	using TClass = ULogsToolset;
	if (!Z_Registration_Info_UClass_ULogsToolset.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("LogsToolset"),
			Z_Registration_Info_UClass_ULogsToolset.InnerSingleton,
			StaticRegisterNativesULogsToolset,
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
	return Z_Registration_Info_UClass_ULogsToolset.InnerSingleton;
}
UClass* Z_Construct_UClass_ULogsToolset_NoRegister()
{
	return ULogsToolset::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ULogsToolset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Provides tools for reading the Unreal Engine output log and controlling\n/// log category verbosity.\n" },
#endif
		{ "IncludePath", "LogsToolset.h" },
		{ "ModuleRelativePath", "Private/LogsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Provides tools for reading the Unreal Engine output log and controlling\nlog category verbosity." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class ULogsToolset constinit property declarations *****************************
// ********** End Class ULogsToolset constinit property declarations *******************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetLogCategories"), .Pointer = &ULogsToolset::execGetLogCategories },
		{ .NameUTF8 = UTF8TEXT("GetLogEntries"), .Pointer = &ULogsToolset::execGetLogEntries },
		{ .NameUTF8 = UTF8TEXT("GetVerbosity"), .Pointer = &ULogsToolset::execGetVerbosity },
		{ .NameUTF8 = UTF8TEXT("SetVerbosity"), .Pointer = &ULogsToolset::execSetVerbosity },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ULogsToolset_GetLogCategories, "GetLogCategories" }, // 3264601295
		{ &Z_Construct_UFunction_ULogsToolset_GetLogEntries, "GetLogEntries" }, // 2757982295
		{ &Z_Construct_UFunction_ULogsToolset_GetVerbosity, "GetVerbosity" }, // 2795372029
		{ &Z_Construct_UFunction_ULogsToolset_SetVerbosity, "SetVerbosity" }, // 2399226779
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULogsToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_ULogsToolset_Statics
UObject* (*const Z_Construct_UClass_ULogsToolset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UToolsetDefinition,
	(UObject* (*)())Z_Construct_UPackage__Script_EditorToolset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULogsToolset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULogsToolset_Statics::ClassParams = {
	&ULogsToolset::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULogsToolset_Statics::Class_MetaDataParams), Z_Construct_UClass_ULogsToolset_Statics::Class_MetaDataParams)
};
void ULogsToolset::StaticRegisterNativesULogsToolset()
{
	UClass* Class = ULogsToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_ULogsToolset_Statics::Funcs));
}
UClass* Z_Construct_UClass_ULogsToolset()
{
	if (!Z_Registration_Info_UClass_ULogsToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULogsToolset.OuterSingleton, Z_Construct_UClass_ULogsToolset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULogsToolset.OuterSingleton;
}
ULogsToolset::ULogsToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ULogsToolset);
ULogsToolset::~ULogsToolset() {}
// ********** End Class ULogsToolset ***************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_LogsToolset_h__Script_EditorToolset_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULogsToolset, ULogsToolset::StaticClass, TEXT("ULogsToolset"), &Z_Registration_Info_UClass_ULogsToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULogsToolset), 1292322073U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_LogsToolset_h__Script_EditorToolset_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_LogsToolset_h__Script_EditorToolset_1738098678{
	TEXT("/Script/EditorToolset"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_LogsToolset_h__Script_EditorToolset_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_LogsToolset_h__Script_EditorToolset_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
