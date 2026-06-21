// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ToolsetRegistry/ToolsetImage.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeToolsetImage() {}

// ********** Begin Cross Module References ********************************************************
TOOLSETREGISTRY_API UScriptStruct* Z_Construct_UScriptStruct_FToolsetImage();
UPackage* Z_Construct_UPackage__Script_ToolsetRegistry();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FToolsetImage *****************************************************
struct Z_Construct_UScriptStruct_FToolsetImage_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FToolsetImage); }
	static inline consteval int16 GetStructAlignment() { return alignof(FToolsetImage); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The standard image format that toolsets should return.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolsetImage.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The standard image format that toolsets should return." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MimeType_MetaData[] = {
		{ "Category", "Image" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The format the image is encoded in.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolsetImage.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The format the image is encoded in." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Data_MetaData[] = {
		{ "Category", "Image" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The image data encoded as a base64 string.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolsetImage.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The image data encoded as a base64 string." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FToolsetImage constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_MimeType;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Data;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FToolsetImage constinit property declarations ***********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FToolsetImage>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FToolsetImage_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FToolsetImage;
class UScriptStruct* FToolsetImage::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FToolsetImage.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FToolsetImage.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FToolsetImage, (UObject*)Z_Construct_UPackage__Script_ToolsetRegistry(), TEXT("ToolsetImage"));
	}
	return Z_Registration_Info_UScriptStruct_FToolsetImage.OuterSingleton;
	}

// ********** Begin ScriptStruct FToolsetImage Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FToolsetImage_Statics::NewProp_MimeType = { "MimeType", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FToolsetImage, MimeType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MimeType_MetaData), NewProp_MimeType_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FToolsetImage_Statics::NewProp_Data = { "Data", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FToolsetImage, Data), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Data_MetaData), NewProp_Data_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FToolsetImage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FToolsetImage_Statics::NewProp_MimeType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FToolsetImage_Statics::NewProp_Data,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FToolsetImage_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FToolsetImage Property Definitions **********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FToolsetImage_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ToolsetRegistry,
	nullptr,
	&NewStructOps,
	"ToolsetImage",
	Z_Construct_UScriptStruct_FToolsetImage_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FToolsetImage_Statics::PropPointers),
	sizeof(FToolsetImage),
	alignof(FToolsetImage),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FToolsetImage_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FToolsetImage_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FToolsetImage()
{
	if (!Z_Registration_Info_UScriptStruct_FToolsetImage.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FToolsetImage.InnerSingleton, Z_Construct_UScriptStruct_FToolsetImage_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FToolsetImage.InnerSingleton);
}
// ********** End ScriptStruct FToolsetImage *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetImage_h__Script_ToolsetRegistry_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FToolsetImage::StaticStruct, Z_Construct_UScriptStruct_FToolsetImage_Statics::NewStructOps, TEXT("ToolsetImage"),&Z_Registration_Info_UScriptStruct_FToolsetImage, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FToolsetImage), 1290813077U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetImage_h__Script_ToolsetRegistry_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetImage_h__Script_ToolsetRegistry_786731792{
	TEXT("/Script/ToolsetRegistry"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetImage_h__Script_ToolsetRegistry_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetImage_h__Script_ToolsetRegistry_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
