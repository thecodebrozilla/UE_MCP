// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DataRegistryTools.h"
#include "StructUtils/InstancedStruct.h"
#include "UObject/SoftObjectPath.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeDataRegistryTools() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UScriptStruct_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FInstancedStruct();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FSoftObjectPath();
DATAREGISTRY_API UEnum* Z_Construct_UEnum_DataRegistry_EDataRegistryAvailability();
DATAREGISTRYTOOLSET_API UClass* Z_Construct_UClass_UDataRegistryTools();
DATAREGISTRYTOOLSET_API UClass* Z_Construct_UClass_UDataRegistryTools_NoRegister();
DATAREGISTRYTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FDataRegistryInfo();
DATAREGISTRYTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FDataRegistrySourceSummary();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition();
UPackage* Z_Construct_UPackage__Script_DataRegistryToolset();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FDataRegistryInfo *************************************************
struct Z_Construct_UScriptStruct_FDataRegistryInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FDataRegistryInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDataRegistryInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Detailed information about a single Data Registry.\n" },
#endif
		{ "ModuleRelativePath", "Private/DataRegistryTools.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Detailed information about a single Data Registry." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RegistryName_MetaData[] = {
		{ "Category", "DataRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The registry name.\n" },
#endif
		{ "ModuleRelativePath", "Private/DataRegistryTools.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The registry name." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "Category", "DataRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Human-readable description.\n" },
#endif
		{ "ModuleRelativePath", "Private/DataRegistryTools.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Human-readable description." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemStruct_MetaData[] = {
		{ "Category", "DataRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The UScriptStruct used for items in this registry. May be null.\n" },
#endif
		{ "ModuleRelativePath", "Private/DataRegistryTools.h" },
		{ "NativeConstTemplateArg", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The UScriptStruct used for items in this registry. May be null." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemCount_MetaData[] = {
		{ "Category", "DataRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Number of item IDs known to this registry.\n" },
#endif
		{ "ModuleRelativePath", "Private/DataRegistryTools.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Number of item IDs known to this registry." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Availability_MetaData[] = {
		{ "Category", "DataRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Lowest availability across all sources on this registry. DoesNotExist indicates the\n/// registry has not been initialized.\n" },
#endif
		{ "ModuleRelativePath", "Private/DataRegistryTools.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lowest availability across all sources on this registry. DoesNotExist indicates the\nregistry has not been initialized." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IdFormat_MetaData[] = {
		{ "Category", "DataRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Base GameplayTag of the ID format, if any.\n" },
#endif
		{ "ModuleRelativePath", "Private/DataRegistryTools.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Base GameplayTag of the ID format, if any." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDataRegistryInfo constinit property declarations *****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_RegistryName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Description;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemStruct;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ItemCount;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Availability_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Availability;
	static const UECodeGen_Private::FStrPropertyParams NewProp_IdFormat;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDataRegistryInfo constinit property declarations *******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDataRegistryInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FDataRegistryInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDataRegistryInfo;
class UScriptStruct* FDataRegistryInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDataRegistryInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDataRegistryInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDataRegistryInfo, (UObject*)Z_Construct_UPackage__Script_DataRegistryToolset(), TEXT("DataRegistryInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FDataRegistryInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FDataRegistryInfo Property Definitions ****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDataRegistryInfo_Statics::NewProp_RegistryName = { "RegistryName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDataRegistryInfo, RegistryName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RegistryName_MetaData), NewProp_RegistryName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDataRegistryInfo_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDataRegistryInfo, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FDataRegistryInfo_Statics::NewProp_ItemStruct = { "ItemStruct", nullptr, (EPropertyFlags)0x0114000000000004, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDataRegistryInfo, ItemStruct), Z_Construct_UClass_UScriptStruct_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemStruct_MetaData), NewProp_ItemStruct_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDataRegistryInfo_Statics::NewProp_ItemCount = { "ItemCount", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDataRegistryInfo, ItemCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemCount_MetaData), NewProp_ItemCount_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FDataRegistryInfo_Statics::NewProp_Availability_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FDataRegistryInfo_Statics::NewProp_Availability = { "Availability", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDataRegistryInfo, Availability), Z_Construct_UEnum_DataRegistry_EDataRegistryAvailability, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Availability_MetaData), NewProp_Availability_MetaData) }; // 2933187837
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDataRegistryInfo_Statics::NewProp_IdFormat = { "IdFormat", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDataRegistryInfo, IdFormat), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IdFormat_MetaData), NewProp_IdFormat_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDataRegistryInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDataRegistryInfo_Statics::NewProp_RegistryName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDataRegistryInfo_Statics::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDataRegistryInfo_Statics::NewProp_ItemStruct,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDataRegistryInfo_Statics::NewProp_ItemCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDataRegistryInfo_Statics::NewProp_Availability_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDataRegistryInfo_Statics::NewProp_Availability,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDataRegistryInfo_Statics::NewProp_IdFormat,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDataRegistryInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FDataRegistryInfo Property Definitions ******************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDataRegistryInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_DataRegistryToolset,
	nullptr,
	&NewStructOps,
	"DataRegistryInfo",
	Z_Construct_UScriptStruct_FDataRegistryInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDataRegistryInfo_Statics::PropPointers),
	sizeof(FDataRegistryInfo),
	alignof(FDataRegistryInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDataRegistryInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDataRegistryInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDataRegistryInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FDataRegistryInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDataRegistryInfo.InnerSingleton, Z_Construct_UScriptStruct_FDataRegistryInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDataRegistryInfo.InnerSingleton);
}
// ********** End ScriptStruct FDataRegistryInfo ***************************************************

// ********** Begin ScriptStruct FDataRegistrySourceSummary ****************************************
struct Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FDataRegistrySourceSummary); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDataRegistrySourceSummary); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Summary information about a single UDataRegistrySource entry.\n" },
#endif
		{ "ModuleRelativePath", "Private/DataRegistryTools.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Summary information about a single UDataRegistrySource entry." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceClass_MetaData[] = {
		{ "Category", "DataRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Class of the source.\n" },
#endif
		{ "ModuleRelativePath", "Private/DataRegistryTools.h" },
		{ "NativeConstTemplateArg", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Class of the source." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DebugString_MetaData[] = {
		{ "Category", "DataRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Human-readable description of the source.\n" },
#endif
		{ "ModuleRelativePath", "Private/DataRegistryTools.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Human-readable description of the source." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceAssetPath_MetaData[] = {
		{ "Category", "DataRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Path to the underlying asset, if any.\n" },
#endif
		{ "ModuleRelativePath", "Private/DataRegistryTools.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Path to the underlying asset, if any." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Availability_MetaData[] = {
		{ "Category", "DataRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Availability of this source.\n" },
#endif
		{ "ModuleRelativePath", "Private/DataRegistryTools.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Availability of this source." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsInitialized_MetaData[] = {
		{ "Category", "DataRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Whether the source is initialized.\n" },
#endif
		{ "ModuleRelativePath", "Private/DataRegistryTools.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether the source is initialized." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsTransient_MetaData[] = {
		{ "Category", "DataRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Whether this is a runtime-only (transient) source.\n" },
#endif
		{ "ModuleRelativePath", "Private/DataRegistryTools.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether this is a runtime-only (transient) source." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ParentSourceDebugString_MetaData[] = {
		{ "Category", "DataRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Debug string of the parent (original) source, if this is a transient child. Empty otherwise.\n" },
#endif
		{ "ModuleRelativePath", "Private/DataRegistryTools.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Debug string of the parent (original) source, if this is a transient child. Empty otherwise." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDataRegistrySourceSummary constinit property declarations ********
	static const UECodeGen_Private::FClassPropertyParams NewProp_SourceClass;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DebugString;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SourceAssetPath;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Availability_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Availability;
	static void NewProp_bIsInitialized_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsInitialized;
	static void NewProp_bIsTransient_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsTransient;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ParentSourceDebugString;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDataRegistrySourceSummary constinit property declarations **********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDataRegistrySourceSummary>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDataRegistrySourceSummary;
class UScriptStruct* FDataRegistrySourceSummary::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDataRegistrySourceSummary.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDataRegistrySourceSummary.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDataRegistrySourceSummary, (UObject*)Z_Construct_UPackage__Script_DataRegistryToolset(), TEXT("DataRegistrySourceSummary"));
	}
	return Z_Registration_Info_UScriptStruct_FDataRegistrySourceSummary.OuterSingleton;
	}

// ********** Begin ScriptStruct FDataRegistrySourceSummary Property Definitions *******************
const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics::NewProp_SourceClass = { "SourceClass", nullptr, (EPropertyFlags)0x0114000000000004, UECodeGen_Private::EPropertyGenFlags::Class | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDataRegistrySourceSummary, SourceClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceClass_MetaData), NewProp_SourceClass_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics::NewProp_DebugString = { "DebugString", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDataRegistrySourceSummary, DebugString), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DebugString_MetaData), NewProp_DebugString_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics::NewProp_SourceAssetPath = { "SourceAssetPath", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDataRegistrySourceSummary, SourceAssetPath), Z_Construct_UScriptStruct_FSoftObjectPath, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceAssetPath_MetaData), NewProp_SourceAssetPath_MetaData) }; // 2425717601
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics::NewProp_Availability_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics::NewProp_Availability = { "Availability", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDataRegistrySourceSummary, Availability), Z_Construct_UEnum_DataRegistry_EDataRegistryAvailability, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Availability_MetaData), NewProp_Availability_MetaData) }; // 2933187837
void Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics::NewProp_bIsInitialized_SetBit(void* Obj)
{
	((FDataRegistrySourceSummary*)Obj)->bIsInitialized = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics::NewProp_bIsInitialized = { "bIsInitialized", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDataRegistrySourceSummary), &Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics::NewProp_bIsInitialized_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsInitialized_MetaData), NewProp_bIsInitialized_MetaData) };
void Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics::NewProp_bIsTransient_SetBit(void* Obj)
{
	((FDataRegistrySourceSummary*)Obj)->bIsTransient = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics::NewProp_bIsTransient = { "bIsTransient", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDataRegistrySourceSummary), &Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics::NewProp_bIsTransient_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsTransient_MetaData), NewProp_bIsTransient_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics::NewProp_ParentSourceDebugString = { "ParentSourceDebugString", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDataRegistrySourceSummary, ParentSourceDebugString), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ParentSourceDebugString_MetaData), NewProp_ParentSourceDebugString_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics::NewProp_SourceClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics::NewProp_DebugString,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics::NewProp_SourceAssetPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics::NewProp_Availability_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics::NewProp_Availability,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics::NewProp_bIsInitialized,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics::NewProp_bIsTransient,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics::NewProp_ParentSourceDebugString,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FDataRegistrySourceSummary Property Definitions *********************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_DataRegistryToolset,
	nullptr,
	&NewStructOps,
	"DataRegistrySourceSummary",
	Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics::PropPointers),
	sizeof(FDataRegistrySourceSummary),
	alignof(FDataRegistrySourceSummary),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDataRegistrySourceSummary()
{
	if (!Z_Registration_Info_UScriptStruct_FDataRegistrySourceSummary.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDataRegistrySourceSummary.InnerSingleton, Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDataRegistrySourceSummary.InnerSingleton);
}
// ********** End ScriptStruct FDataRegistrySourceSummary ******************************************

// ********** Begin Class UDataRegistryTools Function GetItems *************************************
struct Z_Construct_UFunction_UDataRegistryTools_GetItems_Statics
{
	struct DataRegistryTools_eventGetItems_Parms
	{
		FString RegistryName;
		TArray<FString> ItemNames;
		TMap<FString,FInstancedStruct> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "DataRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns cached item data.\n\x09 * Items must be loaded in the registry cache to be returned.\n\x09 * @param RegistryName The registry name.\n\x09 * @param ItemNames Item names to retrieve.\n\x09 * @return A map from item name to its struct data. Names that were not found in the cache\n\x09 *   are simply omitted from the result.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/DataRegistryTools.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns cached item data.\nItems must be loaded in the registry cache to be returned.\n@param RegistryName The registry name.\n@param ItemNames Item names to retrieve.\n@return A map from item name to its struct data. Names that were not found in the cache\n  are simply omitted from the result." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RegistryName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemNames_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetItems constinit property declarations ******************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_RegistryName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ItemNames_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ItemNames;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetItems constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetItems Property Definitions *****************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataRegistryTools_GetItems_Statics::NewProp_RegistryName = { "RegistryName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataRegistryTools_eventGetItems_Parms, RegistryName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RegistryName_MetaData), NewProp_RegistryName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataRegistryTools_GetItems_Statics::NewProp_ItemNames_Inner = { "ItemNames", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDataRegistryTools_GetItems_Statics::NewProp_ItemNames = { "ItemNames", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataRegistryTools_eventGetItems_Parms, ItemNames), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemNames_MetaData), NewProp_ItemNames_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDataRegistryTools_GetItems_Statics::NewProp_ReturnValue_ValueProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FInstancedStruct, METADATA_PARAMS(0, nullptr) }; // 3949785911
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataRegistryTools_GetItems_Statics::NewProp_ReturnValue_Key_KeyProp = { "ReturnValue_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UDataRegistryTools_GetItems_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataRegistryTools_eventGetItems_Parms, ReturnValue), EMapPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 3949785911
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataRegistryTools_GetItems_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataRegistryTools_GetItems_Statics::NewProp_RegistryName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataRegistryTools_GetItems_Statics::NewProp_ItemNames_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataRegistryTools_GetItems_Statics::NewProp_ItemNames,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataRegistryTools_GetItems_Statics::NewProp_ReturnValue_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataRegistryTools_GetItems_Statics::NewProp_ReturnValue_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataRegistryTools_GetItems_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataRegistryTools_GetItems_Statics::PropPointers) < 2048);
// ********** End Function GetItems Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataRegistryTools_GetItems_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDataRegistryTools, nullptr, "GetItems", 	Z_Construct_UFunction_UDataRegistryTools_GetItems_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDataRegistryTools_GetItems_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDataRegistryTools_GetItems_Statics::DataRegistryTools_eventGetItems_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataRegistryTools_GetItems_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDataRegistryTools_GetItems_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDataRegistryTools_GetItems_Statics::DataRegistryTools_eventGetItems_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDataRegistryTools_GetItems()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataRegistryTools_GetItems_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDataRegistryTools::execGetItems)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_RegistryName);
	P_GET_TARRAY_REF(FString,Z_Param_Out_ItemNames);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TMap<FString,FInstancedStruct>*)Z_Param__Result=UDataRegistryTools::GetItems(Z_Param_RegistryName,Z_Param_Out_ItemNames);
	P_NATIVE_END;
}
// ********** End Class UDataRegistryTools Function GetItems ***************************************

// ********** Begin Class UDataRegistryTools Function GetRegistryInfo ******************************
struct Z_Construct_UFunction_UDataRegistryTools_GetRegistryInfo_Statics
{
	struct DataRegistryTools_eventGetRegistryInfo_Parms
	{
		FString RegistryName;
		FDataRegistryInfo ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "DataRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns detailed information about a specific registry.\n\x09 * @param RegistryName The registry name.\n\x09 * @return Detailed info including description and id format.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/DataRegistryTools.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns detailed information about a specific registry.\n@param RegistryName The registry name.\n@return Detailed info including description and id format." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RegistryName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetRegistryInfo constinit property declarations ***********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_RegistryName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetRegistryInfo constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetRegistryInfo Property Definitions **********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataRegistryTools_GetRegistryInfo_Statics::NewProp_RegistryName = { "RegistryName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataRegistryTools_eventGetRegistryInfo_Parms, RegistryName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RegistryName_MetaData), NewProp_RegistryName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDataRegistryTools_GetRegistryInfo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataRegistryTools_eventGetRegistryInfo_Parms, ReturnValue), Z_Construct_UScriptStruct_FDataRegistryInfo, METADATA_PARAMS(0, nullptr) }; // 2334098401
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataRegistryTools_GetRegistryInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataRegistryTools_GetRegistryInfo_Statics::NewProp_RegistryName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataRegistryTools_GetRegistryInfo_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataRegistryTools_GetRegistryInfo_Statics::PropPointers) < 2048);
// ********** End Function GetRegistryInfo Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataRegistryTools_GetRegistryInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDataRegistryTools, nullptr, "GetRegistryInfo", 	Z_Construct_UFunction_UDataRegistryTools_GetRegistryInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDataRegistryTools_GetRegistryInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDataRegistryTools_GetRegistryInfo_Statics::DataRegistryTools_eventGetRegistryInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataRegistryTools_GetRegistryInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDataRegistryTools_GetRegistryInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDataRegistryTools_GetRegistryInfo_Statics::DataRegistryTools_eventGetRegistryInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDataRegistryTools_GetRegistryInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataRegistryTools_GetRegistryInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDataRegistryTools::execGetRegistryInfo)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_RegistryName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FDataRegistryInfo*)Z_Param__Result=UDataRegistryTools::GetRegistryInfo(Z_Param_RegistryName);
	P_NATIVE_END;
}
// ********** End Class UDataRegistryTools Function GetRegistryInfo ********************************

// ********** Begin Class UDataRegistryTools Function GetSchema ************************************
struct Z_Construct_UFunction_UDataRegistryTools_GetSchema_Statics
{
	struct DataRegistryTools_eventGetSchema_Parms
	{
		FString RegistryName;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "DataRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the item struct schema as JSON.\n\x09 * @param RegistryName The registry name.\n\x09 * @return A JSON string describing the struct's fields and types.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/DataRegistryTools.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the item struct schema as JSON.\n@param RegistryName The registry name.\n@return A JSON string describing the struct's fields and types." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RegistryName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSchema constinit property declarations *****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_RegistryName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSchema constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSchema Property Definitions ****************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataRegistryTools_GetSchema_Statics::NewProp_RegistryName = { "RegistryName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataRegistryTools_eventGetSchema_Parms, RegistryName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RegistryName_MetaData), NewProp_RegistryName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataRegistryTools_GetSchema_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataRegistryTools_eventGetSchema_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataRegistryTools_GetSchema_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataRegistryTools_GetSchema_Statics::NewProp_RegistryName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataRegistryTools_GetSchema_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataRegistryTools_GetSchema_Statics::PropPointers) < 2048);
// ********** End Function GetSchema Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataRegistryTools_GetSchema_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDataRegistryTools, nullptr, "GetSchema", 	Z_Construct_UFunction_UDataRegistryTools_GetSchema_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDataRegistryTools_GetSchema_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDataRegistryTools_GetSchema_Statics::DataRegistryTools_eventGetSchema_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataRegistryTools_GetSchema_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDataRegistryTools_GetSchema_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDataRegistryTools_GetSchema_Statics::DataRegistryTools_eventGetSchema_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDataRegistryTools_GetSchema()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataRegistryTools_GetSchema_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDataRegistryTools::execGetSchema)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_RegistryName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UDataRegistryTools::GetSchema(Z_Param_RegistryName);
	P_NATIVE_END;
}
// ********** End Class UDataRegistryTools Function GetSchema **************************************

// ********** Begin Class UDataRegistryTools Function ListDataSources ******************************
struct Z_Construct_UFunction_UDataRegistryTools_ListDataSources_Statics
{
	struct DataRegistryTools_eventListDataSources_Parms
	{
		FString RegistryName;
		TArray<FDataRegistrySourceSummary> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "DataRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the editor-defined sources configured on a Data Registry.\n\x09 * These are the sources as authored on the registry asset, before any runtime expansion\n\x09 * of meta sources.\n\x09 * @param RegistryName The registry name.\n\x09 * @return A list of source summaries, in definition order.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/DataRegistryTools.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the editor-defined sources configured on a Data Registry.\nThese are the sources as authored on the registry asset, before any runtime expansion\nof meta sources.\n@param RegistryName The registry name.\n@return A list of source summaries, in definition order." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RegistryName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ListDataSources constinit property declarations ***********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_RegistryName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListDataSources constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListDataSources Property Definitions **********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataRegistryTools_ListDataSources_Statics::NewProp_RegistryName = { "RegistryName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataRegistryTools_eventListDataSources_Parms, RegistryName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RegistryName_MetaData), NewProp_RegistryName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDataRegistryTools_ListDataSources_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDataRegistrySourceSummary, METADATA_PARAMS(0, nullptr) }; // 2624023397
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDataRegistryTools_ListDataSources_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataRegistryTools_eventListDataSources_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 2624023397
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataRegistryTools_ListDataSources_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataRegistryTools_ListDataSources_Statics::NewProp_RegistryName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataRegistryTools_ListDataSources_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataRegistryTools_ListDataSources_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataRegistryTools_ListDataSources_Statics::PropPointers) < 2048);
// ********** End Function ListDataSources Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataRegistryTools_ListDataSources_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDataRegistryTools, nullptr, "ListDataSources", 	Z_Construct_UFunction_UDataRegistryTools_ListDataSources_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDataRegistryTools_ListDataSources_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDataRegistryTools_ListDataSources_Statics::DataRegistryTools_eventListDataSources_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataRegistryTools_ListDataSources_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDataRegistryTools_ListDataSources_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDataRegistryTools_ListDataSources_Statics::DataRegistryTools_eventListDataSources_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDataRegistryTools_ListDataSources()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataRegistryTools_ListDataSources_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDataRegistryTools::execListDataSources)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_RegistryName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FDataRegistrySourceSummary>*)Z_Param__Result=UDataRegistryTools::ListDataSources(Z_Param_RegistryName);
	P_NATIVE_END;
}
// ********** End Class UDataRegistryTools Function ListDataSources ********************************

// ********** Begin Class UDataRegistryTools Function ListItems ************************************
struct Z_Construct_UFunction_UDataRegistryTools_ListItems_Statics
{
	struct DataRegistryTools_eventListItems_Parms
	{
		FString RegistryName;
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "DataRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns all item names in a Data Registry.\n\x09 * @param RegistryName The registry name.\n\x09 * @return All item names defined on the registry, in registry order.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/DataRegistryTools.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns all item names in a Data Registry.\n@param RegistryName The registry name.\n@return All item names defined on the registry, in registry order." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RegistryName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ListItems constinit property declarations *****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_RegistryName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListItems constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListItems Property Definitions ****************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataRegistryTools_ListItems_Statics::NewProp_RegistryName = { "RegistryName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataRegistryTools_eventListItems_Parms, RegistryName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RegistryName_MetaData), NewProp_RegistryName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataRegistryTools_ListItems_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDataRegistryTools_ListItems_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataRegistryTools_eventListItems_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataRegistryTools_ListItems_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataRegistryTools_ListItems_Statics::NewProp_RegistryName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataRegistryTools_ListItems_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataRegistryTools_ListItems_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataRegistryTools_ListItems_Statics::PropPointers) < 2048);
// ********** End Function ListItems Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataRegistryTools_ListItems_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDataRegistryTools, nullptr, "ListItems", 	Z_Construct_UFunction_UDataRegistryTools_ListItems_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDataRegistryTools_ListItems_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDataRegistryTools_ListItems_Statics::DataRegistryTools_eventListItems_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataRegistryTools_ListItems_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDataRegistryTools_ListItems_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDataRegistryTools_ListItems_Statics::DataRegistryTools_eventListItems_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDataRegistryTools_ListItems()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataRegistryTools_ListItems_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDataRegistryTools::execListItems)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_RegistryName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=UDataRegistryTools::ListItems(Z_Param_RegistryName);
	P_NATIVE_END;
}
// ********** End Class UDataRegistryTools Function ListItems **************************************

// ********** Begin Class UDataRegistryTools Function ListRegistries *******************************
struct Z_Construct_UFunction_UDataRegistryTools_ListRegistries_Statics
{
	struct DataRegistryTools_eventListRegistries_Parms
	{
		const UScriptStruct* StructFilter;
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "DataRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the names of all registered Data Registries.\n\x09 * @param StructFilter If non-null, only registries whose item struct inherits from this\n\x09 *   struct are returned.\n\x09 * @return A list of registry names.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/DataRegistryTools.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the names of all registered Data Registries.\n@param StructFilter If non-null, only registries whose item struct inherits from this\n  struct are returned.\n@return A list of registry names." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StructFilter_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ListRegistries constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StructFilter;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListRegistries constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListRegistries Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataRegistryTools_ListRegistries_Statics::NewProp_StructFilter = { "StructFilter", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataRegistryTools_eventListRegistries_Parms, StructFilter), Z_Construct_UClass_UScriptStruct_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StructFilter_MetaData), NewProp_StructFilter_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataRegistryTools_ListRegistries_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDataRegistryTools_ListRegistries_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataRegistryTools_eventListRegistries_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataRegistryTools_ListRegistries_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataRegistryTools_ListRegistries_Statics::NewProp_StructFilter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataRegistryTools_ListRegistries_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataRegistryTools_ListRegistries_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataRegistryTools_ListRegistries_Statics::PropPointers) < 2048);
// ********** End Function ListRegistries Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataRegistryTools_ListRegistries_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDataRegistryTools, nullptr, "ListRegistries", 	Z_Construct_UFunction_UDataRegistryTools_ListRegistries_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDataRegistryTools_ListRegistries_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDataRegistryTools_ListRegistries_Statics::DataRegistryTools_eventListRegistries_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataRegistryTools_ListRegistries_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDataRegistryTools_ListRegistries_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDataRegistryTools_ListRegistries_Statics::DataRegistryTools_eventListRegistries_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDataRegistryTools_ListRegistries()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataRegistryTools_ListRegistries_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDataRegistryTools::execListRegistries)
{
	P_GET_OBJECT(UScriptStruct,Z_Param_StructFilter);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=UDataRegistryTools::ListRegistries(Z_Param_StructFilter);
	P_NATIVE_END;
}
// ********** End Class UDataRegistryTools Function ListRegistries *********************************

// ********** Begin Class UDataRegistryTools Function ListRuntimeSources ***************************
struct Z_Construct_UFunction_UDataRegistryTools_ListRuntimeSources_Statics
{
	struct DataRegistryTools_eventListRuntimeSources_Parms
	{
		FString RegistryName;
		TArray<FDataRegistrySourceSummary> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "DataRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the runtime sources for a Data Registry.\n\x09 * This is the expanded list including transient child sources generated from meta sources.\n\x09 * Will equal ListDataSources when the registry has no meta sources.\n\x09 * @param RegistryName The registry name.\n\x09 * @return A list of source summaries, in runtime order.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/DataRegistryTools.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the runtime sources for a Data Registry.\nThis is the expanded list including transient child sources generated from meta sources.\nWill equal ListDataSources when the registry has no meta sources.\n@param RegistryName The registry name.\n@return A list of source summaries, in runtime order." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RegistryName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ListRuntimeSources constinit property declarations ********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_RegistryName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListRuntimeSources constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListRuntimeSources Property Definitions *******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataRegistryTools_ListRuntimeSources_Statics::NewProp_RegistryName = { "RegistryName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataRegistryTools_eventListRuntimeSources_Parms, RegistryName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RegistryName_MetaData), NewProp_RegistryName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDataRegistryTools_ListRuntimeSources_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDataRegistrySourceSummary, METADATA_PARAMS(0, nullptr) }; // 2624023397
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDataRegistryTools_ListRuntimeSources_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataRegistryTools_eventListRuntimeSources_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 2624023397
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataRegistryTools_ListRuntimeSources_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataRegistryTools_ListRuntimeSources_Statics::NewProp_RegistryName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataRegistryTools_ListRuntimeSources_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataRegistryTools_ListRuntimeSources_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataRegistryTools_ListRuntimeSources_Statics::PropPointers) < 2048);
// ********** End Function ListRuntimeSources Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataRegistryTools_ListRuntimeSources_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDataRegistryTools, nullptr, "ListRuntimeSources", 	Z_Construct_UFunction_UDataRegistryTools_ListRuntimeSources_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDataRegistryTools_ListRuntimeSources_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDataRegistryTools_ListRuntimeSources_Statics::DataRegistryTools_eventListRuntimeSources_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataRegistryTools_ListRuntimeSources_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDataRegistryTools_ListRuntimeSources_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDataRegistryTools_ListRuntimeSources_Statics::DataRegistryTools_eventListRuntimeSources_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDataRegistryTools_ListRuntimeSources()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataRegistryTools_ListRuntimeSources_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDataRegistryTools::execListRuntimeSources)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_RegistryName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FDataRegistrySourceSummary>*)Z_Param__Result=UDataRegistryTools::ListRuntimeSources(Z_Param_RegistryName);
	P_NATIVE_END;
}
// ********** End Class UDataRegistryTools Function ListRuntimeSources *****************************

// ********** Begin Class UDataRegistryTools *******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UDataRegistryTools;
UClass* UDataRegistryTools::GetPrivateStaticClass()
{
	using TClass = UDataRegistryTools;
	if (!Z_Registration_Info_UClass_UDataRegistryTools.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("DataRegistryTools"),
			Z_Registration_Info_UClass_UDataRegistryTools.InnerSingleton,
			StaticRegisterNativesUDataRegistryTools,
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
	return Z_Registration_Info_UClass_UDataRegistryTools.InnerSingleton;
}
UClass* Z_Construct_UClass_UDataRegistryTools_NoRegister()
{
	return UDataRegistryTools::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDataRegistryTools_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Provides tools for querying and inspecting Data Registries.\n" },
#endif
		{ "IncludePath", "DataRegistryTools.h" },
		{ "ModuleRelativePath", "Private/DataRegistryTools.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Provides tools for querying and inspecting Data Registries." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UDataRegistryTools constinit property declarations ***********************
// ********** End Class UDataRegistryTools constinit property declarations *************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetItems"), .Pointer = &UDataRegistryTools::execGetItems },
		{ .NameUTF8 = UTF8TEXT("GetRegistryInfo"), .Pointer = &UDataRegistryTools::execGetRegistryInfo },
		{ .NameUTF8 = UTF8TEXT("GetSchema"), .Pointer = &UDataRegistryTools::execGetSchema },
		{ .NameUTF8 = UTF8TEXT("ListDataSources"), .Pointer = &UDataRegistryTools::execListDataSources },
		{ .NameUTF8 = UTF8TEXT("ListItems"), .Pointer = &UDataRegistryTools::execListItems },
		{ .NameUTF8 = UTF8TEXT("ListRegistries"), .Pointer = &UDataRegistryTools::execListRegistries },
		{ .NameUTF8 = UTF8TEXT("ListRuntimeSources"), .Pointer = &UDataRegistryTools::execListRuntimeSources },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDataRegistryTools_GetItems, "GetItems" }, // 827010235
		{ &Z_Construct_UFunction_UDataRegistryTools_GetRegistryInfo, "GetRegistryInfo" }, // 413902837
		{ &Z_Construct_UFunction_UDataRegistryTools_GetSchema, "GetSchema" }, // 3199486915
		{ &Z_Construct_UFunction_UDataRegistryTools_ListDataSources, "ListDataSources" }, // 3484140450
		{ &Z_Construct_UFunction_UDataRegistryTools_ListItems, "ListItems" }, // 3543860654
		{ &Z_Construct_UFunction_UDataRegistryTools_ListRegistries, "ListRegistries" }, // 3279440363
		{ &Z_Construct_UFunction_UDataRegistryTools_ListRuntimeSources, "ListRuntimeSources" }, // 2695909897
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDataRegistryTools>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UDataRegistryTools_Statics
UObject* (*const Z_Construct_UClass_UDataRegistryTools_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UToolsetDefinition,
	(UObject* (*)())Z_Construct_UPackage__Script_DataRegistryToolset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDataRegistryTools_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDataRegistryTools_Statics::ClassParams = {
	&UDataRegistryTools::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDataRegistryTools_Statics::Class_MetaDataParams), Z_Construct_UClass_UDataRegistryTools_Statics::Class_MetaDataParams)
};
void UDataRegistryTools::StaticRegisterNativesUDataRegistryTools()
{
	UClass* Class = UDataRegistryTools::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UDataRegistryTools_Statics::Funcs));
}
UClass* Z_Construct_UClass_UDataRegistryTools()
{
	if (!Z_Registration_Info_UClass_UDataRegistryTools.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDataRegistryTools.OuterSingleton, Z_Construct_UClass_UDataRegistryTools_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDataRegistryTools.OuterSingleton;
}
UDataRegistryTools::UDataRegistryTools(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDataRegistryTools);
UDataRegistryTools::~UDataRegistryTools() {}
// ********** End Class UDataRegistryTools *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_DataRegistryToolset_Source_DataRegistryToolset_Private_DataRegistryTools_h__Script_DataRegistryToolset_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FDataRegistryInfo::StaticStruct, Z_Construct_UScriptStruct_FDataRegistryInfo_Statics::NewStructOps, TEXT("DataRegistryInfo"),&Z_Registration_Info_UScriptStruct_FDataRegistryInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDataRegistryInfo), 2334098401U) },
		{ FDataRegistrySourceSummary::StaticStruct, Z_Construct_UScriptStruct_FDataRegistrySourceSummary_Statics::NewStructOps, TEXT("DataRegistrySourceSummary"),&Z_Registration_Info_UScriptStruct_FDataRegistrySourceSummary, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDataRegistrySourceSummary), 2624023397U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDataRegistryTools, UDataRegistryTools::StaticClass, TEXT("UDataRegistryTools"), &Z_Registration_Info_UClass_UDataRegistryTools, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDataRegistryTools), 197495927U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_DataRegistryToolset_Source_DataRegistryToolset_Private_DataRegistryTools_h__Script_DataRegistryToolset_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_DataRegistryToolset_Source_DataRegistryToolset_Private_DataRegistryTools_h__Script_DataRegistryToolset_3899655729{
	TEXT("/Script/DataRegistryToolset"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_DataRegistryToolset_Source_DataRegistryToolset_Private_DataRegistryTools_h__Script_DataRegistryToolset_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_DataRegistryToolset_Source_DataRegistryToolset_Private_DataRegistryTools_h__Script_DataRegistryToolset_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_DataRegistryToolset_Source_DataRegistryToolset_Private_DataRegistryTools_h__Script_DataRegistryToolset_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_DataRegistryToolset_Source_DataRegistryToolset_Private_DataRegistryTools_h__Script_DataRegistryToolset_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
