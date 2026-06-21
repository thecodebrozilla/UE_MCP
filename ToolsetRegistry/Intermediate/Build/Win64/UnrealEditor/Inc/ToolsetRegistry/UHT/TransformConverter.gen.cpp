// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ToolsetRegistry/TransformConverter.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeTransformConverter() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
TOOLSETREGISTRY_API UScriptStruct* Z_Construct_UScriptStruct_FToolsetTransform();
UPackage* Z_Construct_UPackage__Script_ToolsetRegistry();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FToolsetTransform *************************************************
struct Z_Construct_UScriptStruct_FToolsetTransform_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FToolsetTransform); }
	static inline consteval int16 GetStructAlignment() { return alignof(FToolsetTransform); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Represents a 3D transformation with optional location, rotation, and scale.\n/// Unset fields mean \"identity\" when creating objects and \"don't change\" when modifying existing ones.\n" },
#endif
		{ "ModuleRelativePath", "Private/ToolsetRegistry/TransformConverter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Represents a 3D transformation with optional location, rotation, and scale.\nUnset fields mean \"identity\" when creating objects and \"don't change\" when modifying existing ones." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[] = {
		{ "Category", "Transform" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The world-space location.\n" },
#endif
		{ "ModuleRelativePath", "Private/ToolsetRegistry/TransformConverter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The world-space location." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_MetaData[] = {
		{ "Category", "Transform" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The world-space rotation.\n" },
#endif
		{ "ModuleRelativePath", "Private/ToolsetRegistry/TransformConverter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The world-space rotation." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Scale_MetaData[] = {
		{ "Category", "Transform" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The scale.\n" },
#endif
		{ "ModuleRelativePath", "Private/ToolsetRegistry/TransformConverter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The scale." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FToolsetTransform constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Location_Inner;
	static const UECodeGen_Private::FGenericPropertyParams NewProp_Location;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation_Inner;
	static const UECodeGen_Private::FGenericPropertyParams NewProp_Rotation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Scale_Inner;
	static const UECodeGen_Private::FGenericPropertyParams NewProp_Scale;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FToolsetTransform constinit property declarations *******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FToolsetTransform>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FToolsetTransform_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FToolsetTransform;
class UScriptStruct* FToolsetTransform::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FToolsetTransform.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FToolsetTransform.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FToolsetTransform, (UObject*)Z_Construct_UPackage__Script_ToolsetRegistry(), TEXT("ToolsetTransform"));
	}
	return Z_Registration_Info_UScriptStruct_FToolsetTransform.OuterSingleton;
	}

// ********** Begin ScriptStruct FToolsetTransform Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FToolsetTransform_Statics::NewProp_Location_Inner = { "Location", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FGenericPropertyParams Z_Construct_UScriptStruct_FToolsetTransform_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Optional, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FToolsetTransform, Location), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Location_MetaData), NewProp_Location_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FToolsetTransform_Statics::NewProp_Rotation_Inner = { "Rotation", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FGenericPropertyParams Z_Construct_UScriptStruct_FToolsetTransform_Statics::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Optional, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FToolsetTransform, Rotation), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_MetaData), NewProp_Rotation_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FToolsetTransform_Statics::NewProp_Scale_Inner = { "Scale", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FGenericPropertyParams Z_Construct_UScriptStruct_FToolsetTransform_Statics::NewProp_Scale = { "Scale", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Optional, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FToolsetTransform, Scale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Scale_MetaData), NewProp_Scale_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FToolsetTransform_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FToolsetTransform_Statics::NewProp_Location_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FToolsetTransform_Statics::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FToolsetTransform_Statics::NewProp_Rotation_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FToolsetTransform_Statics::NewProp_Rotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FToolsetTransform_Statics::NewProp_Scale_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FToolsetTransform_Statics::NewProp_Scale,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FToolsetTransform_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FToolsetTransform Property Definitions ******************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FToolsetTransform_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ToolsetRegistry,
	nullptr,
	&NewStructOps,
	"ToolsetTransform",
	Z_Construct_UScriptStruct_FToolsetTransform_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FToolsetTransform_Statics::PropPointers),
	sizeof(FToolsetTransform),
	alignof(FToolsetTransform),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FToolsetTransform_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FToolsetTransform_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FToolsetTransform()
{
	if (!Z_Registration_Info_UScriptStruct_FToolsetTransform.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FToolsetTransform.InnerSingleton, Z_Construct_UScriptStruct_FToolsetTransform_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FToolsetTransform.InnerSingleton);
}
// ********** End ScriptStruct FToolsetTransform ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Private_ToolsetRegistry_TransformConverter_h__Script_ToolsetRegistry_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FToolsetTransform::StaticStruct, Z_Construct_UScriptStruct_FToolsetTransform_Statics::NewStructOps, TEXT("ToolsetTransform"),&Z_Registration_Info_UScriptStruct_FToolsetTransform, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FToolsetTransform), 138394900U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Private_ToolsetRegistry_TransformConverter_h__Script_ToolsetRegistry_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Private_ToolsetRegistry_TransformConverter_h__Script_ToolsetRegistry_4222920967{
	TEXT("/Script/ToolsetRegistry"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Private_ToolsetRegistry_TransformConverter_h__Script_ToolsetRegistry_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Private_ToolsetRegistry_TransformConverter_h__Script_ToolsetRegistry_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
