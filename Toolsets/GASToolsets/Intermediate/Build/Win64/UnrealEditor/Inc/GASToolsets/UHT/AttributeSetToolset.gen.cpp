// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AttributeSetToolset.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeAttributeSetToolset() {}

// ********** Begin Cross Module References ********************************************************
GASTOOLSETS_API UClass* Z_Construct_UClass_UAttributeSetToolset();
GASTOOLSETS_API UClass* Z_Construct_UClass_UAttributeSetToolset_NoRegister();
GASTOOLSETS_API UScriptStruct* Z_Construct_UScriptStruct_FAttributeSetClassInfo();
GASTOOLSETS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayAttributeInfo();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition();
UPackage* Z_Construct_UPackage__Script_GASToolsets();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FGameplayAttributeInfo ********************************************
struct Z_Construct_UScriptStruct_FGameplayAttributeInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FGameplayAttributeInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FGameplayAttributeInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Describes a gameplay attribute belonging to an AttributeSet class.\n" },
#endif
		{ "ModuleRelativePath", "Private/AttributeSetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Describes a gameplay attribute belonging to an AttributeSet class." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttributeName_MetaData[] = {
		{ "Category", "AttributeSet" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The short attribute name (e.g. \"Health\").\n" },
#endif
		{ "ModuleRelativePath", "Private/AttributeSetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The short attribute name (e.g. \"Health\")." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FullName_MetaData[] = {
		{ "Category", "AttributeSet" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The fully-qualified attribute name including the set class (e.g. \"UMyHealthSet.Health\").\n" },
#endif
		{ "ModuleRelativePath", "Private/AttributeSetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The fully-qualified attribute name including the set class (e.g. \"UMyHealthSet.Health\")." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SetClassName_MetaData[] = {
		{ "Category", "AttributeSet" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The name of the AttributeSet class that owns this attribute (e.g. \"UMyHealthSet\").\n" },
#endif
		{ "ModuleRelativePath", "Private/AttributeSetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The name of the AttributeSet class that owns this attribute (e.g. \"UMyHealthSet\")." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FGameplayAttributeInfo constinit property declarations ************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AttributeName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FullName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SetClassName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FGameplayAttributeInfo constinit property declarations **************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGameplayAttributeInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FGameplayAttributeInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FGameplayAttributeInfo;
class UScriptStruct* FGameplayAttributeInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FGameplayAttributeInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FGameplayAttributeInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FGameplayAttributeInfo, (UObject*)Z_Construct_UPackage__Script_GASToolsets(), TEXT("GameplayAttributeInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FGameplayAttributeInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FGameplayAttributeInfo Property Definitions ***********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FGameplayAttributeInfo_Statics::NewProp_AttributeName = { "AttributeName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGameplayAttributeInfo, AttributeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttributeName_MetaData), NewProp_AttributeName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FGameplayAttributeInfo_Statics::NewProp_FullName = { "FullName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGameplayAttributeInfo, FullName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FullName_MetaData), NewProp_FullName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FGameplayAttributeInfo_Statics::NewProp_SetClassName = { "SetClassName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGameplayAttributeInfo, SetClassName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SetClassName_MetaData), NewProp_SetClassName_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGameplayAttributeInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameplayAttributeInfo_Statics::NewProp_AttributeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameplayAttributeInfo_Statics::NewProp_FullName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameplayAttributeInfo_Statics::NewProp_SetClassName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameplayAttributeInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FGameplayAttributeInfo Property Definitions *************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGameplayAttributeInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GASToolsets,
	nullptr,
	&NewStructOps,
	"GameplayAttributeInfo",
	Z_Construct_UScriptStruct_FGameplayAttributeInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameplayAttributeInfo_Statics::PropPointers),
	sizeof(FGameplayAttributeInfo),
	alignof(FGameplayAttributeInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameplayAttributeInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FGameplayAttributeInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FGameplayAttributeInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FGameplayAttributeInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FGameplayAttributeInfo.InnerSingleton, Z_Construct_UScriptStruct_FGameplayAttributeInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FGameplayAttributeInfo.InnerSingleton);
}
// ********** End ScriptStruct FGameplayAttributeInfo **********************************************

// ********** Begin ScriptStruct FAttributeSetClassInfo ********************************************
struct Z_Construct_UScriptStruct_FAttributeSetClassInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FAttributeSetClassInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FAttributeSetClassInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Describes an AttributeSet subclass found in the project.\n" },
#endif
		{ "ModuleRelativePath", "Private/AttributeSetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Describes an AttributeSet subclass found in the project." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClassName_MetaData[] = {
		{ "Category", "AttributeSet" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The UClass name of the attribute set (e.g. \"UMyHealthSet\").\n" },
#endif
		{ "ModuleRelativePath", "Private/AttributeSetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The UClass name of the attribute set (e.g. \"UMyHealthSet\")." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AssetPath_MetaData[] = {
		{ "Category", "AttributeSet" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The object path to the Blueprint asset, or empty for native C++ classes.\n" },
#endif
		{ "ModuleRelativePath", "Private/AttributeSetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The object path to the Blueprint asset, or empty for native C++ classes." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Attributes_MetaData[] = {
		{ "Category", "AttributeSet" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The gameplay attributes defined on this set.\n" },
#endif
		{ "ModuleRelativePath", "Private/AttributeSetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The gameplay attributes defined on this set." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FAttributeSetClassInfo constinit property declarations ************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ClassName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AssetPath;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Attributes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Attributes;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FAttributeSetClassInfo constinit property declarations **************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAttributeSetClassInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FAttributeSetClassInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FAttributeSetClassInfo;
class UScriptStruct* FAttributeSetClassInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FAttributeSetClassInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FAttributeSetClassInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAttributeSetClassInfo, (UObject*)Z_Construct_UPackage__Script_GASToolsets(), TEXT("AttributeSetClassInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FAttributeSetClassInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FAttributeSetClassInfo Property Definitions ***********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAttributeSetClassInfo_Statics::NewProp_ClassName = { "ClassName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAttributeSetClassInfo, ClassName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClassName_MetaData), NewProp_ClassName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAttributeSetClassInfo_Statics::NewProp_AssetPath = { "AssetPath", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAttributeSetClassInfo, AssetPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AssetPath_MetaData), NewProp_AssetPath_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAttributeSetClassInfo_Statics::NewProp_Attributes_Inner = { "Attributes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGameplayAttributeInfo, METADATA_PARAMS(0, nullptr) }; // 3174530925
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FAttributeSetClassInfo_Statics::NewProp_Attributes = { "Attributes", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAttributeSetClassInfo, Attributes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Attributes_MetaData), NewProp_Attributes_MetaData) }; // 3174530925
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAttributeSetClassInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAttributeSetClassInfo_Statics::NewProp_ClassName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAttributeSetClassInfo_Statics::NewProp_AssetPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAttributeSetClassInfo_Statics::NewProp_Attributes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAttributeSetClassInfo_Statics::NewProp_Attributes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAttributeSetClassInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FAttributeSetClassInfo Property Definitions *************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAttributeSetClassInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GASToolsets,
	nullptr,
	&NewStructOps,
	"AttributeSetClassInfo",
	Z_Construct_UScriptStruct_FAttributeSetClassInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAttributeSetClassInfo_Statics::PropPointers),
	sizeof(FAttributeSetClassInfo),
	alignof(FAttributeSetClassInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAttributeSetClassInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAttributeSetClassInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAttributeSetClassInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FAttributeSetClassInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FAttributeSetClassInfo.InnerSingleton, Z_Construct_UScriptStruct_FAttributeSetClassInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FAttributeSetClassInfo.InnerSingleton);
}
// ********** End ScriptStruct FAttributeSetClassInfo **********************************************

// ********** Begin Class UAttributeSetToolset Function FindAttributeSetClasses ********************
struct Z_Construct_UFunction_UAttributeSetToolset_FindAttributeSetClasses_Statics
{
	struct AttributeSetToolset_eventFindAttributeSetClasses_Parms
	{
		TArray<FAttributeSetClassInfo> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "AttributeSets" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns all AttributeSet subclasses found in the project, including their attributes.\n\x09 * Covers both native C++ subclasses and Blueprint subclasses discovered via the asset registry.\n\x09 * @return A list of attribute set descriptors sorted by class name.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/AttributeSetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns all AttributeSet subclasses found in the project, including their attributes.\nCovers both native C++ subclasses and Blueprint subclasses discovered via the asset registry.\n@return A list of attribute set descriptors sorted by class name." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function FindAttributeSetClasses constinit property declarations ***************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FindAttributeSetClasses constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FindAttributeSetClasses Property Definitions **************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAttributeSetToolset_FindAttributeSetClasses_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FAttributeSetClassInfo, METADATA_PARAMS(0, nullptr) }; // 3572316319
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UAttributeSetToolset_FindAttributeSetClasses_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AttributeSetToolset_eventFindAttributeSetClasses_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 3572316319
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAttributeSetToolset_FindAttributeSetClasses_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAttributeSetToolset_FindAttributeSetClasses_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAttributeSetToolset_FindAttributeSetClasses_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAttributeSetToolset_FindAttributeSetClasses_Statics::PropPointers) < 2048);
// ********** End Function FindAttributeSetClasses Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAttributeSetToolset_FindAttributeSetClasses_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAttributeSetToolset, nullptr, "FindAttributeSetClasses", 	Z_Construct_UFunction_UAttributeSetToolset_FindAttributeSetClasses_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAttributeSetToolset_FindAttributeSetClasses_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAttributeSetToolset_FindAttributeSetClasses_Statics::AttributeSetToolset_eventFindAttributeSetClasses_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAttributeSetToolset_FindAttributeSetClasses_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAttributeSetToolset_FindAttributeSetClasses_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAttributeSetToolset_FindAttributeSetClasses_Statics::AttributeSetToolset_eventFindAttributeSetClasses_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAttributeSetToolset_FindAttributeSetClasses()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAttributeSetToolset_FindAttributeSetClasses_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAttributeSetToolset::execFindAttributeSetClasses)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FAttributeSetClassInfo>*)Z_Param__Result=UAttributeSetToolset::FindAttributeSetClasses();
	P_NATIVE_END;
}
// ********** End Class UAttributeSetToolset Function FindAttributeSetClasses **********************

// ********** Begin Class UAttributeSetToolset Function ListAttributes *****************************
struct Z_Construct_UFunction_UAttributeSetToolset_ListAttributes_Statics
{
	struct AttributeSetToolset_eventListAttributes_Parms
	{
		FString ClassName;
		TArray<FGameplayAttributeInfo> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "AttributeSets" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the gameplay attributes defined on a specific AttributeSet class.\n\x09 * @param ClassName The UClass name to look up, e.g. \"UMyHealthSet\".\n\x09 *   Raises a script error if the class is not found or is not an AttributeSet subclass.\n\x09 * @return A list of attribute descriptors defined on the class.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/AttributeSetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the gameplay attributes defined on a specific AttributeSet class.\n@param ClassName The UClass name to look up, e.g. \"UMyHealthSet\".\n  Raises a script error if the class is not found or is not an AttributeSet subclass.\n@return A list of attribute descriptors defined on the class." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClassName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ListAttributes constinit property declarations ************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ClassName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListAttributes constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListAttributes Property Definitions ***********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAttributeSetToolset_ListAttributes_Statics::NewProp_ClassName = { "ClassName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AttributeSetToolset_eventListAttributes_Parms, ClassName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClassName_MetaData), NewProp_ClassName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAttributeSetToolset_ListAttributes_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGameplayAttributeInfo, METADATA_PARAMS(0, nullptr) }; // 3174530925
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UAttributeSetToolset_ListAttributes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AttributeSetToolset_eventListAttributes_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 3174530925
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAttributeSetToolset_ListAttributes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAttributeSetToolset_ListAttributes_Statics::NewProp_ClassName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAttributeSetToolset_ListAttributes_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAttributeSetToolset_ListAttributes_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAttributeSetToolset_ListAttributes_Statics::PropPointers) < 2048);
// ********** End Function ListAttributes Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAttributeSetToolset_ListAttributes_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAttributeSetToolset, nullptr, "ListAttributes", 	Z_Construct_UFunction_UAttributeSetToolset_ListAttributes_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAttributeSetToolset_ListAttributes_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAttributeSetToolset_ListAttributes_Statics::AttributeSetToolset_eventListAttributes_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAttributeSetToolset_ListAttributes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAttributeSetToolset_ListAttributes_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAttributeSetToolset_ListAttributes_Statics::AttributeSetToolset_eventListAttributes_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAttributeSetToolset_ListAttributes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAttributeSetToolset_ListAttributes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAttributeSetToolset::execListAttributes)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ClassName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FGameplayAttributeInfo>*)Z_Param__Result=UAttributeSetToolset::ListAttributes(Z_Param_ClassName);
	P_NATIVE_END;
}
// ********** End Class UAttributeSetToolset Function ListAttributes *******************************

// ********** Begin Class UAttributeSetToolset *****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UAttributeSetToolset;
UClass* UAttributeSetToolset::GetPrivateStaticClass()
{
	using TClass = UAttributeSetToolset;
	if (!Z_Registration_Info_UClass_UAttributeSetToolset.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("AttributeSetToolset"),
			Z_Registration_Info_UClass_UAttributeSetToolset.InnerSingleton,
			StaticRegisterNativesUAttributeSetToolset,
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
	return Z_Registration_Info_UClass_UAttributeSetToolset.InnerSingleton;
}
UClass* Z_Construct_UClass_UAttributeSetToolset_NoRegister()
{
	return UAttributeSetToolset::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UAttributeSetToolset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Provides tools for discovering AttributeSet classes and their gameplay attributes.\n" },
#endif
		{ "IncludePath", "AttributeSetToolset.h" },
		{ "ModuleRelativePath", "Private/AttributeSetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Provides tools for discovering AttributeSet classes and their gameplay attributes." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UAttributeSetToolset constinit property declarations *********************
// ********** End Class UAttributeSetToolset constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("FindAttributeSetClasses"), .Pointer = &UAttributeSetToolset::execFindAttributeSetClasses },
		{ .NameUTF8 = UTF8TEXT("ListAttributes"), .Pointer = &UAttributeSetToolset::execListAttributes },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UAttributeSetToolset_FindAttributeSetClasses, "FindAttributeSetClasses" }, // 2424485906
		{ &Z_Construct_UFunction_UAttributeSetToolset_ListAttributes, "ListAttributes" }, // 1874476964
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAttributeSetToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UAttributeSetToolset_Statics
UObject* (*const Z_Construct_UClass_UAttributeSetToolset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UToolsetDefinition,
	(UObject* (*)())Z_Construct_UPackage__Script_GASToolsets,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAttributeSetToolset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAttributeSetToolset_Statics::ClassParams = {
	&UAttributeSetToolset::StaticClass,
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
	0x010000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAttributeSetToolset_Statics::Class_MetaDataParams), Z_Construct_UClass_UAttributeSetToolset_Statics::Class_MetaDataParams)
};
void UAttributeSetToolset::StaticRegisterNativesUAttributeSetToolset()
{
	UClass* Class = UAttributeSetToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UAttributeSetToolset_Statics::Funcs));
}
UClass* Z_Construct_UClass_UAttributeSetToolset()
{
	if (!Z_Registration_Info_UClass_UAttributeSetToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAttributeSetToolset.OuterSingleton, Z_Construct_UClass_UAttributeSetToolset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAttributeSetToolset.OuterSingleton;
}
UAttributeSetToolset::UAttributeSetToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UAttributeSetToolset);
UAttributeSetToolset::~UAttributeSetToolset() {}
// ********** End Class UAttributeSetToolset *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AttributeSetToolset_h__Script_GASToolsets_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FGameplayAttributeInfo::StaticStruct, Z_Construct_UScriptStruct_FGameplayAttributeInfo_Statics::NewStructOps, TEXT("GameplayAttributeInfo"),&Z_Registration_Info_UScriptStruct_FGameplayAttributeInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGameplayAttributeInfo), 3174530925U) },
		{ FAttributeSetClassInfo::StaticStruct, Z_Construct_UScriptStruct_FAttributeSetClassInfo_Statics::NewStructOps, TEXT("AttributeSetClassInfo"),&Z_Registration_Info_UScriptStruct_FAttributeSetClassInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAttributeSetClassInfo), 3572316319U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAttributeSetToolset, UAttributeSetToolset::StaticClass, TEXT("UAttributeSetToolset"), &Z_Registration_Info_UClass_UAttributeSetToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAttributeSetToolset), 1995917255U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AttributeSetToolset_h__Script_GASToolsets_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AttributeSetToolset_h__Script_GASToolsets_4011210834{
	TEXT("/Script/GASToolsets"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AttributeSetToolset_h__Script_GASToolsets_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AttributeSetToolset_h__Script_GASToolsets_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AttributeSetToolset_h__Script_GASToolsets_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AttributeSetToolset_h__Script_GASToolsets_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
