// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ConfigSettingsToolset.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeConfigSettingsToolset() {}

// ********** Begin Cross Module References ********************************************************
CONFIGSETTINGSTOOLSET_API UClass* Z_Construct_UClass_UConfigSettingsToolset();
CONFIGSETTINGSTOOLSET_API UClass* Z_Construct_UClass_UConfigSettingsToolset_NoRegister();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition();
UPackage* Z_Construct_UPackage__Script_ConfigSettingsToolset();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UConfigSettingsToolset Function GetSectionPropertyValues *****************
struct Z_Construct_UFunction_UConfigSettingsToolset_GetSectionPropertyValues_Statics
{
	struct ConfigSettingsToolset_eventGetSectionPropertyValues_Parms
	{
		FString ContainerName;
		FString CategoryName;
		FString SectionName;
		TArray<FString> PropertyNames;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "ConfigSettingsToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the current values of the specified properties as a JSON object.\n\x09 * Raises an error if the section does not exist, has no settings object, or any\n\x09 * requested property cannot be read.\n\x09 * @param ContainerName The name of the container (e.g. \"Project\").\n\x09 * @param CategoryName The name of the category (e.g. \"Engine\").\n\x09 * @param SectionName The name of the section (e.g. \"General\").\n\x09 * @param PropertyNames The names of the properties to read.\n\x09 * @return JSON object mapping property names to their current values, or empty string on failure.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/ConfigSettingsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the current values of the specified properties as a JSON object.\nRaises an error if the section does not exist, has no settings object, or any\nrequested property cannot be read.\n@param ContainerName The name of the container (e.g. \"Project\").\n@param CategoryName The name of the category (e.g. \"Engine\").\n@param SectionName The name of the section (e.g. \"General\").\n@param PropertyNames The names of the properties to read.\n@return JSON object mapping property names to their current values, or empty string on failure." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContainerName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CategoryName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SectionName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropertyNames_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSectionPropertyValues constinit property declarations **************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ContainerName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_CategoryName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SectionName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_PropertyNames_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_PropertyNames;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSectionPropertyValues constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSectionPropertyValues Property Definitions *************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_GetSectionPropertyValues_Statics::NewProp_ContainerName = { "ContainerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConfigSettingsToolset_eventGetSectionPropertyValues_Parms, ContainerName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContainerName_MetaData), NewProp_ContainerName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_GetSectionPropertyValues_Statics::NewProp_CategoryName = { "CategoryName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConfigSettingsToolset_eventGetSectionPropertyValues_Parms, CategoryName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CategoryName_MetaData), NewProp_CategoryName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_GetSectionPropertyValues_Statics::NewProp_SectionName = { "SectionName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConfigSettingsToolset_eventGetSectionPropertyValues_Parms, SectionName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SectionName_MetaData), NewProp_SectionName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_GetSectionPropertyValues_Statics::NewProp_PropertyNames_Inner = { "PropertyNames", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_GetSectionPropertyValues_Statics::NewProp_PropertyNames = { "PropertyNames", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConfigSettingsToolset_eventGetSectionPropertyValues_Parms, PropertyNames), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropertyNames_MetaData), NewProp_PropertyNames_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_GetSectionPropertyValues_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConfigSettingsToolset_eventGetSectionPropertyValues_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UConfigSettingsToolset_GetSectionPropertyValues_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_GetSectionPropertyValues_Statics::NewProp_ContainerName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_GetSectionPropertyValues_Statics::NewProp_CategoryName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_GetSectionPropertyValues_Statics::NewProp_SectionName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_GetSectionPropertyValues_Statics::NewProp_PropertyNames_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_GetSectionPropertyValues_Statics::NewProp_PropertyNames,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_GetSectionPropertyValues_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UConfigSettingsToolset_GetSectionPropertyValues_Statics::PropPointers) < 2048);
// ********** End Function GetSectionPropertyValues Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UConfigSettingsToolset_GetSectionPropertyValues_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UConfigSettingsToolset, nullptr, "GetSectionPropertyValues", 	Z_Construct_UFunction_UConfigSettingsToolset_GetSectionPropertyValues_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UConfigSettingsToolset_GetSectionPropertyValues_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UConfigSettingsToolset_GetSectionPropertyValues_Statics::ConfigSettingsToolset_eventGetSectionPropertyValues_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UConfigSettingsToolset_GetSectionPropertyValues_Statics::Function_MetaDataParams), Z_Construct_UFunction_UConfigSettingsToolset_GetSectionPropertyValues_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UConfigSettingsToolset_GetSectionPropertyValues_Statics::ConfigSettingsToolset_eventGetSectionPropertyValues_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UConfigSettingsToolset_GetSectionPropertyValues()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UConfigSettingsToolset_GetSectionPropertyValues_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UConfigSettingsToolset::execGetSectionPropertyValues)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ContainerName);
	P_GET_PROPERTY(FStrProperty,Z_Param_CategoryName);
	P_GET_PROPERTY(FStrProperty,Z_Param_SectionName);
	P_GET_TARRAY_REF(FString,Z_Param_Out_PropertyNames);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UConfigSettingsToolset::GetSectionPropertyValues(Z_Param_ContainerName,Z_Param_CategoryName,Z_Param_SectionName,Z_Param_Out_PropertyNames);
	P_NATIVE_END;
}
// ********** End Class UConfigSettingsToolset Function GetSectionPropertyValues *******************

// ********** Begin Class UConfigSettingsToolset Function GetSectionSchema *************************
struct Z_Construct_UFunction_UConfigSettingsToolset_GetSectionSchema_Statics
{
	struct ConfigSettingsToolset_eventGetSectionSchema_Parms
	{
		FString ContainerName;
		FString CategoryName;
		FString SectionName;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "ConfigSettingsToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns a JSON Schema describing the user-visible properties of a settings section.\n\x09 * The schema maps each property name to its type, description, and constraints.\n\x09 * Raises an error if the section does not exist or has no backing settings object\n\x09 * (e.g. uses a custom widget instead).\n\x09 * @param ContainerName The name of the container (e.g. \"Project\").\n\x09 * @param CategoryName The name of the category (e.g. \"Engine\").\n\x09 * @param SectionName The name of the section (e.g. \"General\").\n\x09 * @return JSON Schema string describing the section's properties, or empty string on failure.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/ConfigSettingsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns a JSON Schema describing the user-visible properties of a settings section.\nThe schema maps each property name to its type, description, and constraints.\nRaises an error if the section does not exist or has no backing settings object\n(e.g. uses a custom widget instead).\n@param ContainerName The name of the container (e.g. \"Project\").\n@param CategoryName The name of the category (e.g. \"Engine\").\n@param SectionName The name of the section (e.g. \"General\").\n@return JSON Schema string describing the section's properties, or empty string on failure." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContainerName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CategoryName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SectionName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSectionSchema constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ContainerName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_CategoryName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SectionName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSectionSchema constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSectionSchema Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_GetSectionSchema_Statics::NewProp_ContainerName = { "ContainerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConfigSettingsToolset_eventGetSectionSchema_Parms, ContainerName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContainerName_MetaData), NewProp_ContainerName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_GetSectionSchema_Statics::NewProp_CategoryName = { "CategoryName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConfigSettingsToolset_eventGetSectionSchema_Parms, CategoryName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CategoryName_MetaData), NewProp_CategoryName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_GetSectionSchema_Statics::NewProp_SectionName = { "SectionName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConfigSettingsToolset_eventGetSectionSchema_Parms, SectionName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SectionName_MetaData), NewProp_SectionName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_GetSectionSchema_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConfigSettingsToolset_eventGetSectionSchema_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UConfigSettingsToolset_GetSectionSchema_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_GetSectionSchema_Statics::NewProp_ContainerName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_GetSectionSchema_Statics::NewProp_CategoryName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_GetSectionSchema_Statics::NewProp_SectionName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_GetSectionSchema_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UConfigSettingsToolset_GetSectionSchema_Statics::PropPointers) < 2048);
// ********** End Function GetSectionSchema Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UConfigSettingsToolset_GetSectionSchema_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UConfigSettingsToolset, nullptr, "GetSectionSchema", 	Z_Construct_UFunction_UConfigSettingsToolset_GetSectionSchema_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UConfigSettingsToolset_GetSectionSchema_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UConfigSettingsToolset_GetSectionSchema_Statics::ConfigSettingsToolset_eventGetSectionSchema_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UConfigSettingsToolset_GetSectionSchema_Statics::Function_MetaDataParams), Z_Construct_UFunction_UConfigSettingsToolset_GetSectionSchema_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UConfigSettingsToolset_GetSectionSchema_Statics::ConfigSettingsToolset_eventGetSectionSchema_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UConfigSettingsToolset_GetSectionSchema()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UConfigSettingsToolset_GetSectionSchema_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UConfigSettingsToolset::execGetSectionSchema)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ContainerName);
	P_GET_PROPERTY(FStrProperty,Z_Param_CategoryName);
	P_GET_PROPERTY(FStrProperty,Z_Param_SectionName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UConfigSettingsToolset::GetSectionSchema(Z_Param_ContainerName,Z_Param_CategoryName,Z_Param_SectionName);
	P_NATIVE_END;
}
// ********** End Class UConfigSettingsToolset Function GetSectionSchema ***************************

// ********** Begin Class UConfigSettingsToolset Function ListCategories ***************************
struct Z_Construct_UFunction_UConfigSettingsToolset_ListCategories_Statics
{
	struct ConfigSettingsToolset_eventListCategories_Parms
	{
		FString ContainerName;
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "ConfigSettingsToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Lists the names of all categories within a settings container, sorted alphabetically.\n\x09 * Raises an error if the container does not exist.\n\x09 * @param ContainerName The name of the container (e.g. \"Project\").\n\x09 * @return Sorted array of category names.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/ConfigSettingsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lists the names of all categories within a settings container, sorted alphabetically.\nRaises an error if the container does not exist.\n@param ContainerName The name of the container (e.g. \"Project\").\n@return Sorted array of category names." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContainerName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ListCategories constinit property declarations ************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ContainerName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListCategories constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListCategories Property Definitions ***********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_ListCategories_Statics::NewProp_ContainerName = { "ContainerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConfigSettingsToolset_eventListCategories_Parms, ContainerName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContainerName_MetaData), NewProp_ContainerName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_ListCategories_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_ListCategories_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConfigSettingsToolset_eventListCategories_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UConfigSettingsToolset_ListCategories_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_ListCategories_Statics::NewProp_ContainerName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_ListCategories_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_ListCategories_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UConfigSettingsToolset_ListCategories_Statics::PropPointers) < 2048);
// ********** End Function ListCategories Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UConfigSettingsToolset_ListCategories_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UConfigSettingsToolset, nullptr, "ListCategories", 	Z_Construct_UFunction_UConfigSettingsToolset_ListCategories_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UConfigSettingsToolset_ListCategories_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UConfigSettingsToolset_ListCategories_Statics::ConfigSettingsToolset_eventListCategories_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UConfigSettingsToolset_ListCategories_Statics::Function_MetaDataParams), Z_Construct_UFunction_UConfigSettingsToolset_ListCategories_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UConfigSettingsToolset_ListCategories_Statics::ConfigSettingsToolset_eventListCategories_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UConfigSettingsToolset_ListCategories()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UConfigSettingsToolset_ListCategories_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UConfigSettingsToolset::execListCategories)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ContainerName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=UConfigSettingsToolset::ListCategories(Z_Param_ContainerName);
	P_NATIVE_END;
}
// ********** End Class UConfigSettingsToolset Function ListCategories *****************************

// ********** Begin Class UConfigSettingsToolset Function ListContainers ***************************
struct Z_Construct_UFunction_UConfigSettingsToolset_ListContainers_Statics
{
	struct ConfigSettingsToolset_eventListContainers_Parms
	{
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "ConfigSettingsToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Lists the names of all known settings containers, sorted alphabetically.\n\x09 * Common containers are \"Editor\" and \"Project\".\n\x09 * @return Sorted array of container names.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/ConfigSettingsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lists the names of all known settings containers, sorted alphabetically.\nCommon containers are \"Editor\" and \"Project\".\n@return Sorted array of container names." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ListContainers constinit property declarations ************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListContainers constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListContainers Property Definitions ***********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_ListContainers_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_ListContainers_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConfigSettingsToolset_eventListContainers_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UConfigSettingsToolset_ListContainers_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_ListContainers_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_ListContainers_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UConfigSettingsToolset_ListContainers_Statics::PropPointers) < 2048);
// ********** End Function ListContainers Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UConfigSettingsToolset_ListContainers_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UConfigSettingsToolset, nullptr, "ListContainers", 	Z_Construct_UFunction_UConfigSettingsToolset_ListContainers_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UConfigSettingsToolset_ListContainers_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UConfigSettingsToolset_ListContainers_Statics::ConfigSettingsToolset_eventListContainers_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UConfigSettingsToolset_ListContainers_Statics::Function_MetaDataParams), Z_Construct_UFunction_UConfigSettingsToolset_ListContainers_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UConfigSettingsToolset_ListContainers_Statics::ConfigSettingsToolset_eventListContainers_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UConfigSettingsToolset_ListContainers()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UConfigSettingsToolset_ListContainers_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UConfigSettingsToolset::execListContainers)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=UConfigSettingsToolset::ListContainers();
	P_NATIVE_END;
}
// ********** End Class UConfigSettingsToolset Function ListContainers *****************************

// ********** Begin Class UConfigSettingsToolset Function ListSections *****************************
struct Z_Construct_UFunction_UConfigSettingsToolset_ListSections_Statics
{
	struct ConfigSettingsToolset_eventListSections_Parms
	{
		FString ContainerName;
		FString CategoryName;
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "ConfigSettingsToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Lists the names of all sections within a settings category, sorted alphabetically.\n\x09 * Raises an error if the container or category does not exist.\n\x09 * @param ContainerName The name of the container (e.g. \"Project\").\n\x09 * @param CategoryName The name of the category (e.g. \"Engine\").\n\x09 * @return Sorted array of section names.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/ConfigSettingsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lists the names of all sections within a settings category, sorted alphabetically.\nRaises an error if the container or category does not exist.\n@param ContainerName The name of the container (e.g. \"Project\").\n@param CategoryName The name of the category (e.g. \"Engine\").\n@return Sorted array of section names." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContainerName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CategoryName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ListSections constinit property declarations **************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ContainerName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_CategoryName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListSections constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListSections Property Definitions *************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_ListSections_Statics::NewProp_ContainerName = { "ContainerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConfigSettingsToolset_eventListSections_Parms, ContainerName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContainerName_MetaData), NewProp_ContainerName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_ListSections_Statics::NewProp_CategoryName = { "CategoryName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConfigSettingsToolset_eventListSections_Parms, CategoryName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CategoryName_MetaData), NewProp_CategoryName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_ListSections_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_ListSections_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConfigSettingsToolset_eventListSections_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UConfigSettingsToolset_ListSections_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_ListSections_Statics::NewProp_ContainerName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_ListSections_Statics::NewProp_CategoryName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_ListSections_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_ListSections_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UConfigSettingsToolset_ListSections_Statics::PropPointers) < 2048);
// ********** End Function ListSections Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UConfigSettingsToolset_ListSections_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UConfigSettingsToolset, nullptr, "ListSections", 	Z_Construct_UFunction_UConfigSettingsToolset_ListSections_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UConfigSettingsToolset_ListSections_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UConfigSettingsToolset_ListSections_Statics::ConfigSettingsToolset_eventListSections_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UConfigSettingsToolset_ListSections_Statics::Function_MetaDataParams), Z_Construct_UFunction_UConfigSettingsToolset_ListSections_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UConfigSettingsToolset_ListSections_Statics::ConfigSettingsToolset_eventListSections_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UConfigSettingsToolset_ListSections()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UConfigSettingsToolset_ListSections_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UConfigSettingsToolset::execListSections)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ContainerName);
	P_GET_PROPERTY(FStrProperty,Z_Param_CategoryName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=UConfigSettingsToolset::ListSections(Z_Param_ContainerName,Z_Param_CategoryName);
	P_NATIVE_END;
}
// ********** End Class UConfigSettingsToolset Function ListSections *******************************

// ********** Begin Class UConfigSettingsToolset Function ResetSectionToDefaults *******************
struct Z_Construct_UFunction_UConfigSettingsToolset_ResetSectionToDefaults_Statics
{
	struct ConfigSettingsToolset_eventResetSectionToDefaults_Parms
	{
		FString ContainerName;
		FString CategoryName;
		FString SectionName;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "ConfigSettingsToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Resets the settings in a section to their default values.\n\x09 * Raises an error if the section does not exist or reset is not supported.\n\x09 * @param ContainerName The name of the container (e.g. \"Project\").\n\x09 * @param CategoryName The name of the category (e.g. \"Engine\").\n\x09 * @param SectionName The name of the section (e.g. \"General\").\n\x09 * @return True on success.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/ConfigSettingsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Resets the settings in a section to their default values.\nRaises an error if the section does not exist or reset is not supported.\n@param ContainerName The name of the container (e.g. \"Project\").\n@param CategoryName The name of the category (e.g. \"Engine\").\n@param SectionName The name of the section (e.g. \"General\").\n@return True on success." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContainerName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CategoryName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SectionName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ResetSectionToDefaults constinit property declarations ****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ContainerName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_CategoryName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SectionName;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ResetSectionToDefaults constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ResetSectionToDefaults Property Definitions ***************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_ResetSectionToDefaults_Statics::NewProp_ContainerName = { "ContainerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConfigSettingsToolset_eventResetSectionToDefaults_Parms, ContainerName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContainerName_MetaData), NewProp_ContainerName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_ResetSectionToDefaults_Statics::NewProp_CategoryName = { "CategoryName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConfigSettingsToolset_eventResetSectionToDefaults_Parms, CategoryName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CategoryName_MetaData), NewProp_CategoryName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_ResetSectionToDefaults_Statics::NewProp_SectionName = { "SectionName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConfigSettingsToolset_eventResetSectionToDefaults_Parms, SectionName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SectionName_MetaData), NewProp_SectionName_MetaData) };
void Z_Construct_UFunction_UConfigSettingsToolset_ResetSectionToDefaults_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ConfigSettingsToolset_eventResetSectionToDefaults_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_ResetSectionToDefaults_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ConfigSettingsToolset_eventResetSectionToDefaults_Parms), &Z_Construct_UFunction_UConfigSettingsToolset_ResetSectionToDefaults_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UConfigSettingsToolset_ResetSectionToDefaults_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_ResetSectionToDefaults_Statics::NewProp_ContainerName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_ResetSectionToDefaults_Statics::NewProp_CategoryName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_ResetSectionToDefaults_Statics::NewProp_SectionName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_ResetSectionToDefaults_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UConfigSettingsToolset_ResetSectionToDefaults_Statics::PropPointers) < 2048);
// ********** End Function ResetSectionToDefaults Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UConfigSettingsToolset_ResetSectionToDefaults_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UConfigSettingsToolset, nullptr, "ResetSectionToDefaults", 	Z_Construct_UFunction_UConfigSettingsToolset_ResetSectionToDefaults_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UConfigSettingsToolset_ResetSectionToDefaults_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UConfigSettingsToolset_ResetSectionToDefaults_Statics::ConfigSettingsToolset_eventResetSectionToDefaults_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UConfigSettingsToolset_ResetSectionToDefaults_Statics::Function_MetaDataParams), Z_Construct_UFunction_UConfigSettingsToolset_ResetSectionToDefaults_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UConfigSettingsToolset_ResetSectionToDefaults_Statics::ConfigSettingsToolset_eventResetSectionToDefaults_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UConfigSettingsToolset_ResetSectionToDefaults()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UConfigSettingsToolset_ResetSectionToDefaults_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UConfigSettingsToolset::execResetSectionToDefaults)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ContainerName);
	P_GET_PROPERTY(FStrProperty,Z_Param_CategoryName);
	P_GET_PROPERTY(FStrProperty,Z_Param_SectionName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UConfigSettingsToolset::ResetSectionToDefaults(Z_Param_ContainerName,Z_Param_CategoryName,Z_Param_SectionName);
	P_NATIVE_END;
}
// ********** End Class UConfigSettingsToolset Function ResetSectionToDefaults *********************

// ********** Begin Class UConfigSettingsToolset Function SaveSection ******************************
struct Z_Construct_UFunction_UConfigSettingsToolset_SaveSection_Statics
{
	struct ConfigSettingsToolset_eventSaveSection_Parms
	{
		FString ContainerName;
		FString CategoryName;
		FString SectionName;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "ConfigSettingsToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Saves the settings in a section.\n\x09 * Raises an error if the section does not exist or saving is not supported.\n\x09 * @param ContainerName The name of the container (e.g. \"Project\").\n\x09 * @param CategoryName The name of the category (e.g. \"Engine\").\n\x09 * @param SectionName The name of the section (e.g. \"General\").\n\x09 * @return True on success.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/ConfigSettingsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Saves the settings in a section.\nRaises an error if the section does not exist or saving is not supported.\n@param ContainerName The name of the container (e.g. \"Project\").\n@param CategoryName The name of the category (e.g. \"Engine\").\n@param SectionName The name of the section (e.g. \"General\").\n@return True on success." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContainerName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CategoryName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SectionName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SaveSection constinit property declarations ***************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ContainerName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_CategoryName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SectionName;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SaveSection constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SaveSection Property Definitions **************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_SaveSection_Statics::NewProp_ContainerName = { "ContainerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConfigSettingsToolset_eventSaveSection_Parms, ContainerName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContainerName_MetaData), NewProp_ContainerName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_SaveSection_Statics::NewProp_CategoryName = { "CategoryName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConfigSettingsToolset_eventSaveSection_Parms, CategoryName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CategoryName_MetaData), NewProp_CategoryName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_SaveSection_Statics::NewProp_SectionName = { "SectionName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConfigSettingsToolset_eventSaveSection_Parms, SectionName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SectionName_MetaData), NewProp_SectionName_MetaData) };
void Z_Construct_UFunction_UConfigSettingsToolset_SaveSection_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ConfigSettingsToolset_eventSaveSection_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_SaveSection_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ConfigSettingsToolset_eventSaveSection_Parms), &Z_Construct_UFunction_UConfigSettingsToolset_SaveSection_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UConfigSettingsToolset_SaveSection_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_SaveSection_Statics::NewProp_ContainerName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_SaveSection_Statics::NewProp_CategoryName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_SaveSection_Statics::NewProp_SectionName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_SaveSection_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UConfigSettingsToolset_SaveSection_Statics::PropPointers) < 2048);
// ********** End Function SaveSection Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UConfigSettingsToolset_SaveSection_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UConfigSettingsToolset, nullptr, "SaveSection", 	Z_Construct_UFunction_UConfigSettingsToolset_SaveSection_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UConfigSettingsToolset_SaveSection_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UConfigSettingsToolset_SaveSection_Statics::ConfigSettingsToolset_eventSaveSection_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UConfigSettingsToolset_SaveSection_Statics::Function_MetaDataParams), Z_Construct_UFunction_UConfigSettingsToolset_SaveSection_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UConfigSettingsToolset_SaveSection_Statics::ConfigSettingsToolset_eventSaveSection_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UConfigSettingsToolset_SaveSection()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UConfigSettingsToolset_SaveSection_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UConfigSettingsToolset::execSaveSection)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ContainerName);
	P_GET_PROPERTY(FStrProperty,Z_Param_CategoryName);
	P_GET_PROPERTY(FStrProperty,Z_Param_SectionName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UConfigSettingsToolset::SaveSection(Z_Param_ContainerName,Z_Param_CategoryName,Z_Param_SectionName);
	P_NATIVE_END;
}
// ********** End Class UConfigSettingsToolset Function SaveSection ********************************

// ********** Begin Class UConfigSettingsToolset Function SetSectionProperties *********************
struct Z_Construct_UFunction_UConfigSettingsToolset_SetSectionProperties_Statics
{
	struct ConfigSettingsToolset_eventSetSectionProperties_Parms
	{
		FString ContainerName;
		FString CategoryName;
		FString SectionName;
		FString PropertiesJson;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "ConfigSettingsToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Sets one or more properties on a settings section from a JSON object and saves.\n\x09 * PropertiesJson must be a JSON object mapping property names to new values,\n\x09 * in the same format returned by GetSectionPropertyValues.\n\x09 * Raises an error if the section does not exist, cannot be edited, has no settings\n\x09 * object, the default config file is not writable, or any property cannot be set.\n\x09 * @param ContainerName The name of the container (e.g. \"Project\").\n\x09 * @param CategoryName The name of the category (e.g. \"Engine\").\n\x09 * @param SectionName The name of the section (e.g. \"General\").\n\x09 * @param PropertiesJson JSON object with property name to new value pairs.\n\x09 * @return True if all properties successfully set.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/ConfigSettingsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets one or more properties on a settings section from a JSON object and saves.\nPropertiesJson must be a JSON object mapping property names to new values,\nin the same format returned by GetSectionPropertyValues.\nRaises an error if the section does not exist, cannot be edited, has no settings\nobject, the default config file is not writable, or any property cannot be set.\n@param ContainerName The name of the container (e.g. \"Project\").\n@param CategoryName The name of the category (e.g. \"Engine\").\n@param SectionName The name of the section (e.g. \"General\").\n@param PropertiesJson JSON object with property name to new value pairs.\n@return True if all properties successfully set." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContainerName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CategoryName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SectionName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropertiesJson_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetSectionProperties constinit property declarations ******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ContainerName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_CategoryName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SectionName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_PropertiesJson;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSectionProperties constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSectionProperties Property Definitions *****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_SetSectionProperties_Statics::NewProp_ContainerName = { "ContainerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConfigSettingsToolset_eventSetSectionProperties_Parms, ContainerName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContainerName_MetaData), NewProp_ContainerName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_SetSectionProperties_Statics::NewProp_CategoryName = { "CategoryName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConfigSettingsToolset_eventSetSectionProperties_Parms, CategoryName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CategoryName_MetaData), NewProp_CategoryName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_SetSectionProperties_Statics::NewProp_SectionName = { "SectionName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConfigSettingsToolset_eventSetSectionProperties_Parms, SectionName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SectionName_MetaData), NewProp_SectionName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_SetSectionProperties_Statics::NewProp_PropertiesJson = { "PropertiesJson", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConfigSettingsToolset_eventSetSectionProperties_Parms, PropertiesJson), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropertiesJson_MetaData), NewProp_PropertiesJson_MetaData) };
void Z_Construct_UFunction_UConfigSettingsToolset_SetSectionProperties_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ConfigSettingsToolset_eventSetSectionProperties_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UConfigSettingsToolset_SetSectionProperties_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ConfigSettingsToolset_eventSetSectionProperties_Parms), &Z_Construct_UFunction_UConfigSettingsToolset_SetSectionProperties_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UConfigSettingsToolset_SetSectionProperties_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_SetSectionProperties_Statics::NewProp_ContainerName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_SetSectionProperties_Statics::NewProp_CategoryName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_SetSectionProperties_Statics::NewProp_SectionName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_SetSectionProperties_Statics::NewProp_PropertiesJson,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConfigSettingsToolset_SetSectionProperties_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UConfigSettingsToolset_SetSectionProperties_Statics::PropPointers) < 2048);
// ********** End Function SetSectionProperties Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UConfigSettingsToolset_SetSectionProperties_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UConfigSettingsToolset, nullptr, "SetSectionProperties", 	Z_Construct_UFunction_UConfigSettingsToolset_SetSectionProperties_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UConfigSettingsToolset_SetSectionProperties_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UConfigSettingsToolset_SetSectionProperties_Statics::ConfigSettingsToolset_eventSetSectionProperties_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UConfigSettingsToolset_SetSectionProperties_Statics::Function_MetaDataParams), Z_Construct_UFunction_UConfigSettingsToolset_SetSectionProperties_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UConfigSettingsToolset_SetSectionProperties_Statics::ConfigSettingsToolset_eventSetSectionProperties_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UConfigSettingsToolset_SetSectionProperties()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UConfigSettingsToolset_SetSectionProperties_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UConfigSettingsToolset::execSetSectionProperties)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ContainerName);
	P_GET_PROPERTY(FStrProperty,Z_Param_CategoryName);
	P_GET_PROPERTY(FStrProperty,Z_Param_SectionName);
	P_GET_PROPERTY(FStrProperty,Z_Param_PropertiesJson);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UConfigSettingsToolset::SetSectionProperties(Z_Param_ContainerName,Z_Param_CategoryName,Z_Param_SectionName,Z_Param_PropertiesJson);
	P_NATIVE_END;
}
// ********** End Class UConfigSettingsToolset Function SetSectionProperties ***********************

// ********** Begin Class UConfigSettingsToolset ***************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UConfigSettingsToolset;
UClass* UConfigSettingsToolset::GetPrivateStaticClass()
{
	using TClass = UConfigSettingsToolset;
	if (!Z_Registration_Info_UClass_UConfigSettingsToolset.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ConfigSettingsToolset"),
			Z_Registration_Info_UClass_UConfigSettingsToolset.InnerSingleton,
			StaticRegisterNativesUConfigSettingsToolset,
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
	return Z_Registration_Info_UClass_UConfigSettingsToolset.InnerSingleton;
}
UClass* Z_Construct_UClass_UConfigSettingsToolset_NoRegister()
{
	return UConfigSettingsToolset::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UConfigSettingsToolset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Tools for listing, inspecting, and editing Config Settings sections\n" },
#endif
		{ "IncludePath", "ConfigSettingsToolset.h" },
		{ "ModuleRelativePath", "Private/ConfigSettingsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Tools for listing, inspecting, and editing Config Settings sections" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UConfigSettingsToolset constinit property declarations *******************
// ********** End Class UConfigSettingsToolset constinit property declarations *********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetSectionPropertyValues"), .Pointer = &UConfigSettingsToolset::execGetSectionPropertyValues },
		{ .NameUTF8 = UTF8TEXT("GetSectionSchema"), .Pointer = &UConfigSettingsToolset::execGetSectionSchema },
		{ .NameUTF8 = UTF8TEXT("ListCategories"), .Pointer = &UConfigSettingsToolset::execListCategories },
		{ .NameUTF8 = UTF8TEXT("ListContainers"), .Pointer = &UConfigSettingsToolset::execListContainers },
		{ .NameUTF8 = UTF8TEXT("ListSections"), .Pointer = &UConfigSettingsToolset::execListSections },
		{ .NameUTF8 = UTF8TEXT("ResetSectionToDefaults"), .Pointer = &UConfigSettingsToolset::execResetSectionToDefaults },
		{ .NameUTF8 = UTF8TEXT("SaveSection"), .Pointer = &UConfigSettingsToolset::execSaveSection },
		{ .NameUTF8 = UTF8TEXT("SetSectionProperties"), .Pointer = &UConfigSettingsToolset::execSetSectionProperties },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UConfigSettingsToolset_GetSectionPropertyValues, "GetSectionPropertyValues" }, // 539733073
		{ &Z_Construct_UFunction_UConfigSettingsToolset_GetSectionSchema, "GetSectionSchema" }, // 2752047948
		{ &Z_Construct_UFunction_UConfigSettingsToolset_ListCategories, "ListCategories" }, // 3896329669
		{ &Z_Construct_UFunction_UConfigSettingsToolset_ListContainers, "ListContainers" }, // 1578204048
		{ &Z_Construct_UFunction_UConfigSettingsToolset_ListSections, "ListSections" }, // 845825825
		{ &Z_Construct_UFunction_UConfigSettingsToolset_ResetSectionToDefaults, "ResetSectionToDefaults" }, // 3390506419
		{ &Z_Construct_UFunction_UConfigSettingsToolset_SaveSection, "SaveSection" }, // 3741515502
		{ &Z_Construct_UFunction_UConfigSettingsToolset_SetSectionProperties, "SetSectionProperties" }, // 2448890323
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UConfigSettingsToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UConfigSettingsToolset_Statics
UObject* (*const Z_Construct_UClass_UConfigSettingsToolset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UToolsetDefinition,
	(UObject* (*)())Z_Construct_UPackage__Script_ConfigSettingsToolset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UConfigSettingsToolset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UConfigSettingsToolset_Statics::ClassParams = {
	&UConfigSettingsToolset::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UConfigSettingsToolset_Statics::Class_MetaDataParams), Z_Construct_UClass_UConfigSettingsToolset_Statics::Class_MetaDataParams)
};
void UConfigSettingsToolset::StaticRegisterNativesUConfigSettingsToolset()
{
	UClass* Class = UConfigSettingsToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UConfigSettingsToolset_Statics::Funcs));
}
UClass* Z_Construct_UClass_UConfigSettingsToolset()
{
	if (!Z_Registration_Info_UClass_UConfigSettingsToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UConfigSettingsToolset.OuterSingleton, Z_Construct_UClass_UConfigSettingsToolset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UConfigSettingsToolset.OuterSingleton;
}
UConfigSettingsToolset::UConfigSettingsToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UConfigSettingsToolset);
UConfigSettingsToolset::~UConfigSettingsToolset() {}
// ********** End Class UConfigSettingsToolset *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_ConfigSettingsToolset_Source_ConfigSettingsToolset_Private_ConfigSettingsToolset_h__Script_ConfigSettingsToolset_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UConfigSettingsToolset, UConfigSettingsToolset::StaticClass, TEXT("UConfigSettingsToolset"), &Z_Registration_Info_UClass_UConfigSettingsToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UConfigSettingsToolset), 3152089911U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_ConfigSettingsToolset_Source_ConfigSettingsToolset_Private_ConfigSettingsToolset_h__Script_ConfigSettingsToolset_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_ConfigSettingsToolset_Source_ConfigSettingsToolset_Private_ConfigSettingsToolset_h__Script_ConfigSettingsToolset_1940550228{
	TEXT("/Script/ConfigSettingsToolset"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_ConfigSettingsToolset_Source_ConfigSettingsToolset_Private_ConfigSettingsToolset_h__Script_ConfigSettingsToolset_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_ConfigSettingsToolset_Source_ConfigSettingsToolset_Private_ConfigSettingsToolset_h__Script_ConfigSettingsToolset_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
