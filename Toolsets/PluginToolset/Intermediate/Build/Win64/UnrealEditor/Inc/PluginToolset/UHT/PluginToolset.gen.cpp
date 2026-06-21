// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PluginToolset.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodePluginToolset() {}

// ********** Begin Cross Module References ********************************************************
PLUGINTOOLSET_API UClass* Z_Construct_UClass_UPluginToolset();
PLUGINTOOLSET_API UClass* Z_Construct_UClass_UPluginToolset_NoRegister();
PLUGINTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FPluginDependencyToolsetInfo();
PLUGINTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo();
PLUGINTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FPluginTemplateDescriptionToolsetInfo();
PLUGINTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FPluginToolsetInfo();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition();
UPackage* Z_Construct_UPackage__Script_PluginToolset();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FPluginDescriptorToolsetInfo **************************************
struct Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FPluginDescriptorToolsetInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FPluginDescriptorToolsetInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Editable metadata fields from a plugin's descriptor.\n" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Editable metadata fields from a plugin's descriptor." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FriendlyName_MetaData[] = {
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Friendly name of the plugin. */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Friendly name of the plugin." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Description of the plugin. */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Description of the plugin." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Category_MetaData[] = {
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The name of the category this plugin belongs to. */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The name of the category this plugin belongs to." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VersionName_MetaData[] = {
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Name of the version for this plugin. This is the front-facing part of the version number. It doesn't need to\n\x09 * match the version number numerically, but should be updated when the version number is increased accordingly.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Name of the version for this plugin. This is the front-facing part of the version number. It doesn't need to\nmatch the version number numerically, but should be updated when the version number is increased accordingly." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Version_MetaData[] = {
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Version number for the plugin. The version number must increase with every version of the plugin, so that the\n\x09 * system can determine whether one version of a plugin is newer than another, or to enforce other requirements.\n\x09 * This version number is not displayed in front-facing UI. Use the VersionName for that.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Version number for the plugin. The version number must increase with every version of the plugin, so that the\nsystem can determine whether one version of a plugin is newer than another, or to enforce other requirements.\nThis version number is not displayed in front-facing UI. Use the VersionName for that." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CreatedBy_MetaData[] = {
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The company or individual who created this plugin. This is an optional field that may be displayed in the user interface. */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The company or individual who created this plugin. This is an optional field that may be displayed in the user interface." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CreatedByURL_MetaData[] = {
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Hyperlink URL string for the company or individual who created this plugin. This is optional. */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Hyperlink URL string for the company or individual who created this plugin. This is optional." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DocsURL_MetaData[] = {
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Documentation URL string. */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Documentation URL string." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MarketplaceURL_MetaData[] = {
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Marketplace URL for this plugin. This URL will be embedded into projects that enable this plugin, so we can redirect to the marketplace if a user doesn't have it installed. */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Marketplace URL for this plugin. This URL will be embedded into projects that enable this plugin, so we can redirect to the marketplace if a user doesn't have it installed." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SupportURL_MetaData[] = {
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Support URL/email for this plugin. */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Support URL/email for this plugin." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCanContainContent_MetaData[] = {
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Can this plugin contain content? */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Can this plugin contain content?" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsBetaVersion_MetaData[] = {
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Marks the plugin as beta in the UI. */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Marks the plugin as beta in the UI." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsExperimentalVersion_MetaData[] = {
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Marks the plugin as experimental in the UI. */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Marks the plugin as experimental in the UI." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsSealed_MetaData[] = {
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Prevents other plugins from depending on this plugin. */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Prevents other plugins from depending on this plugin." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FPluginDescriptorToolsetInfo constinit property declarations ******
	static const UECodeGen_Private::FStrPropertyParams NewProp_FriendlyName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Description;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Category;
	static const UECodeGen_Private::FStrPropertyParams NewProp_VersionName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Version;
	static const UECodeGen_Private::FStrPropertyParams NewProp_CreatedBy;
	static const UECodeGen_Private::FStrPropertyParams NewProp_CreatedByURL;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DocsURL;
	static const UECodeGen_Private::FStrPropertyParams NewProp_MarketplaceURL;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SupportURL;
	static void NewProp_bCanContainContent_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanContainContent;
	static void NewProp_bIsBetaVersion_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsBetaVersion;
	static void NewProp_bIsExperimentalVersion_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsExperimentalVersion;
	static void NewProp_bIsSealed_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsSealed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FPluginDescriptorToolsetInfo constinit property declarations ********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPluginDescriptorToolsetInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FPluginDescriptorToolsetInfo;
class UScriptStruct* FPluginDescriptorToolsetInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FPluginDescriptorToolsetInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FPluginDescriptorToolsetInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo, (UObject*)Z_Construct_UPackage__Script_PluginToolset(), TEXT("PluginDescriptorToolsetInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FPluginDescriptorToolsetInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FPluginDescriptorToolsetInfo Property Definitions *****************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_FriendlyName = { "FriendlyName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginDescriptorToolsetInfo, FriendlyName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FriendlyName_MetaData), NewProp_FriendlyName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginDescriptorToolsetInfo, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_Category = { "Category", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginDescriptorToolsetInfo, Category), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Category_MetaData), NewProp_Category_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_VersionName = { "VersionName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginDescriptorToolsetInfo, VersionName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VersionName_MetaData), NewProp_VersionName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_Version = { "Version", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginDescriptorToolsetInfo, Version), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Version_MetaData), NewProp_Version_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_CreatedBy = { "CreatedBy", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginDescriptorToolsetInfo, CreatedBy), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CreatedBy_MetaData), NewProp_CreatedBy_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_CreatedByURL = { "CreatedByURL", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginDescriptorToolsetInfo, CreatedByURL), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CreatedByURL_MetaData), NewProp_CreatedByURL_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_DocsURL = { "DocsURL", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginDescriptorToolsetInfo, DocsURL), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DocsURL_MetaData), NewProp_DocsURL_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_MarketplaceURL = { "MarketplaceURL", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginDescriptorToolsetInfo, MarketplaceURL), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MarketplaceURL_MetaData), NewProp_MarketplaceURL_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_SupportURL = { "SupportURL", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginDescriptorToolsetInfo, SupportURL), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SupportURL_MetaData), NewProp_SupportURL_MetaData) };
void Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_bCanContainContent_SetBit(void* Obj)
{
	((FPluginDescriptorToolsetInfo*)Obj)->bCanContainContent = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_bCanContainContent = { "bCanContainContent", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FPluginDescriptorToolsetInfo), &Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_bCanContainContent_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCanContainContent_MetaData), NewProp_bCanContainContent_MetaData) };
void Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_bIsBetaVersion_SetBit(void* Obj)
{
	((FPluginDescriptorToolsetInfo*)Obj)->bIsBetaVersion = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_bIsBetaVersion = { "bIsBetaVersion", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FPluginDescriptorToolsetInfo), &Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_bIsBetaVersion_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsBetaVersion_MetaData), NewProp_bIsBetaVersion_MetaData) };
void Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_bIsExperimentalVersion_SetBit(void* Obj)
{
	((FPluginDescriptorToolsetInfo*)Obj)->bIsExperimentalVersion = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_bIsExperimentalVersion = { "bIsExperimentalVersion", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FPluginDescriptorToolsetInfo), &Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_bIsExperimentalVersion_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsExperimentalVersion_MetaData), NewProp_bIsExperimentalVersion_MetaData) };
void Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_bIsSealed_SetBit(void* Obj)
{
	((FPluginDescriptorToolsetInfo*)Obj)->bIsSealed = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_bIsSealed = { "bIsSealed", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FPluginDescriptorToolsetInfo), &Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_bIsSealed_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsSealed_MetaData), NewProp_bIsSealed_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_FriendlyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_Category,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_VersionName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_Version,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_CreatedBy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_CreatedByURL,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_DocsURL,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_MarketplaceURL,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_SupportURL,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_bCanContainContent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_bIsBetaVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_bIsExperimentalVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewProp_bIsSealed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FPluginDescriptorToolsetInfo Property Definitions *******************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_PluginToolset,
	nullptr,
	&NewStructOps,
	"PluginDescriptorToolsetInfo",
	Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::PropPointers),
	sizeof(FPluginDescriptorToolsetInfo),
	alignof(FPluginDescriptorToolsetInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FPluginDescriptorToolsetInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FPluginDescriptorToolsetInfo.InnerSingleton, Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FPluginDescriptorToolsetInfo.InnerSingleton);
}
// ********** End ScriptStruct FPluginDescriptorToolsetInfo ****************************************

// ********** Begin ScriptStruct FPluginToolsetInfo ************************************************
struct Z_Construct_UScriptStruct_FPluginToolsetInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FPluginToolsetInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FPluginToolsetInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Metadata about a plugin.\n" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Metadata about a plugin." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "Category", "PluginToolset" },
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Version_MetaData[] = {
		{ "Category", "PluginToolset" },
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VersionName_MetaData[] = {
		{ "Category", "PluginToolset" },
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseDir_MetaData[] = {
		{ "Category", "PluginToolset" },
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContentDir_MetaData[] = {
		{ "Category", "PluginToolset" },
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DescriptorPath_MetaData[] = {
		{ "Category", "PluginToolset" },
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MountedAssetPath_MetaData[] = {
		{ "Category", "PluginToolset" },
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FPluginToolsetInfo constinit property declarations ****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Description;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Version;
	static const UECodeGen_Private::FStrPropertyParams NewProp_VersionName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_BaseDir;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ContentDir;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DescriptorPath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_MountedAssetPath;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FPluginToolsetInfo constinit property declarations ******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPluginToolsetInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FPluginToolsetInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FPluginToolsetInfo;
class UScriptStruct* FPluginToolsetInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FPluginToolsetInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FPluginToolsetInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPluginToolsetInfo, (UObject*)Z_Construct_UPackage__Script_PluginToolset(), TEXT("PluginToolsetInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FPluginToolsetInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FPluginToolsetInfo Property Definitions ***************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPluginToolsetInfo_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginToolsetInfo, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPluginToolsetInfo_Statics::NewProp_Version = { "Version", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginToolsetInfo, Version), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Version_MetaData), NewProp_Version_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPluginToolsetInfo_Statics::NewProp_VersionName = { "VersionName", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginToolsetInfo, VersionName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VersionName_MetaData), NewProp_VersionName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPluginToolsetInfo_Statics::NewProp_BaseDir = { "BaseDir", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginToolsetInfo, BaseDir), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseDir_MetaData), NewProp_BaseDir_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPluginToolsetInfo_Statics::NewProp_ContentDir = { "ContentDir", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginToolsetInfo, ContentDir), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContentDir_MetaData), NewProp_ContentDir_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPluginToolsetInfo_Statics::NewProp_DescriptorPath = { "DescriptorPath", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginToolsetInfo, DescriptorPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DescriptorPath_MetaData), NewProp_DescriptorPath_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPluginToolsetInfo_Statics::NewProp_MountedAssetPath = { "MountedAssetPath", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginToolsetInfo, MountedAssetPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MountedAssetPath_MetaData), NewProp_MountedAssetPath_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPluginToolsetInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginToolsetInfo_Statics::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginToolsetInfo_Statics::NewProp_Version,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginToolsetInfo_Statics::NewProp_VersionName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginToolsetInfo_Statics::NewProp_BaseDir,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginToolsetInfo_Statics::NewProp_ContentDir,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginToolsetInfo_Statics::NewProp_DescriptorPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginToolsetInfo_Statics::NewProp_MountedAssetPath,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPluginToolsetInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FPluginToolsetInfo Property Definitions *****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPluginToolsetInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_PluginToolset,
	nullptr,
	&NewStructOps,
	"PluginToolsetInfo",
	Z_Construct_UScriptStruct_FPluginToolsetInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPluginToolsetInfo_Statics::PropPointers),
	sizeof(FPluginToolsetInfo),
	alignof(FPluginToolsetInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPluginToolsetInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPluginToolsetInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FPluginToolsetInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FPluginToolsetInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FPluginToolsetInfo.InnerSingleton, Z_Construct_UScriptStruct_FPluginToolsetInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FPluginToolsetInfo.InnerSingleton);
}
// ********** End ScriptStruct FPluginToolsetInfo **************************************************

// ********** Begin ScriptStruct FPluginDependencyToolsetInfo **************************************
struct Z_Construct_UScriptStruct_FPluginDependencyToolsetInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FPluginDependencyToolsetInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FPluginDependencyToolsetInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// A single dependency entry from a plugin's Plugins array.\n" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A single dependency entry from a plugin's Plugins array." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Name of the dependency plugin. */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Name of the dependency plugin." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOptional_MetaData[] = {
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether the dependency is optional. */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether the dependency is optional." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnabled_MetaData[] = {
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether the dependency should be enabled. */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether the dependency should be enabled." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FPluginDependencyToolsetInfo constinit property declarations ******
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static void NewProp_bOptional_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOptional;
	static void NewProp_bEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FPluginDependencyToolsetInfo constinit property declarations ********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPluginDependencyToolsetInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FPluginDependencyToolsetInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FPluginDependencyToolsetInfo;
class UScriptStruct* FPluginDependencyToolsetInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FPluginDependencyToolsetInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FPluginDependencyToolsetInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPluginDependencyToolsetInfo, (UObject*)Z_Construct_UPackage__Script_PluginToolset(), TEXT("PluginDependencyToolsetInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FPluginDependencyToolsetInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FPluginDependencyToolsetInfo Property Definitions *****************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPluginDependencyToolsetInfo_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginDependencyToolsetInfo, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
void Z_Construct_UScriptStruct_FPluginDependencyToolsetInfo_Statics::NewProp_bOptional_SetBit(void* Obj)
{
	((FPluginDependencyToolsetInfo*)Obj)->bOptional = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPluginDependencyToolsetInfo_Statics::NewProp_bOptional = { "bOptional", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FPluginDependencyToolsetInfo), &Z_Construct_UScriptStruct_FPluginDependencyToolsetInfo_Statics::NewProp_bOptional_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOptional_MetaData), NewProp_bOptional_MetaData) };
void Z_Construct_UScriptStruct_FPluginDependencyToolsetInfo_Statics::NewProp_bEnabled_SetBit(void* Obj)
{
	((FPluginDependencyToolsetInfo*)Obj)->bEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPluginDependencyToolsetInfo_Statics::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FPluginDependencyToolsetInfo), &Z_Construct_UScriptStruct_FPluginDependencyToolsetInfo_Statics::NewProp_bEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnabled_MetaData), NewProp_bEnabled_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPluginDependencyToolsetInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginDependencyToolsetInfo_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginDependencyToolsetInfo_Statics::NewProp_bOptional,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginDependencyToolsetInfo_Statics::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPluginDependencyToolsetInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FPluginDependencyToolsetInfo Property Definitions *******************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPluginDependencyToolsetInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_PluginToolset,
	nullptr,
	&NewStructOps,
	"PluginDependencyToolsetInfo",
	Z_Construct_UScriptStruct_FPluginDependencyToolsetInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPluginDependencyToolsetInfo_Statics::PropPointers),
	sizeof(FPluginDependencyToolsetInfo),
	alignof(FPluginDependencyToolsetInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPluginDependencyToolsetInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPluginDependencyToolsetInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FPluginDependencyToolsetInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FPluginDependencyToolsetInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FPluginDependencyToolsetInfo.InnerSingleton, Z_Construct_UScriptStruct_FPluginDependencyToolsetInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FPluginDependencyToolsetInfo.InnerSingleton);
}
// ********** End ScriptStruct FPluginDependencyToolsetInfo ****************************************

// ********** Begin ScriptStruct FPluginTemplateDescriptionToolsetInfo *****************************
struct Z_Construct_UScriptStruct_FPluginTemplateDescriptionToolsetInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FPluginTemplateDescriptionToolsetInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FPluginTemplateDescriptionToolsetInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Metadata about a plugin template description.\n" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Metadata about a plugin template description." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Name of this template in the GUI */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Name of this template in the GUI" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Description of this template in the GUI */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Description of this template in the GUI" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnDiskPath_MetaData[] = {
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Path to the directory containing template files. */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Path to the directory containing template files." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultTemplateName_MetaData[] = {
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Default plugin name. Typically a prefix. */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Default plugin name. Typically a prefix." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCanBePlacedInEngine_MetaData[] = {
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether or not this template can be used for Engine plugins */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether or not this template can be used for Engine plugins" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FPluginTemplateDescriptionToolsetInfo constinit property declarations 
	static const UECodeGen_Private::FTextPropertyParams NewProp_Name;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Description;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OnDiskPath;
	static const UECodeGen_Private::FTextPropertyParams NewProp_DefaultTemplateName;
	static void NewProp_bCanBePlacedInEngine_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanBePlacedInEngine;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FPluginTemplateDescriptionToolsetInfo constinit property declarations 
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPluginTemplateDescriptionToolsetInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FPluginTemplateDescriptionToolsetInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FPluginTemplateDescriptionToolsetInfo;
class UScriptStruct* FPluginTemplateDescriptionToolsetInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FPluginTemplateDescriptionToolsetInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FPluginTemplateDescriptionToolsetInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPluginTemplateDescriptionToolsetInfo, (UObject*)Z_Construct_UPackage__Script_PluginToolset(), TEXT("PluginTemplateDescriptionToolsetInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FPluginTemplateDescriptionToolsetInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FPluginTemplateDescriptionToolsetInfo Property Definitions ********
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FPluginTemplateDescriptionToolsetInfo_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginTemplateDescriptionToolsetInfo, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FPluginTemplateDescriptionToolsetInfo_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginTemplateDescriptionToolsetInfo, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPluginTemplateDescriptionToolsetInfo_Statics::NewProp_OnDiskPath = { "OnDiskPath", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginTemplateDescriptionToolsetInfo, OnDiskPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnDiskPath_MetaData), NewProp_OnDiskPath_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FPluginTemplateDescriptionToolsetInfo_Statics::NewProp_DefaultTemplateName = { "DefaultTemplateName", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginTemplateDescriptionToolsetInfo, DefaultTemplateName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultTemplateName_MetaData), NewProp_DefaultTemplateName_MetaData) };
void Z_Construct_UScriptStruct_FPluginTemplateDescriptionToolsetInfo_Statics::NewProp_bCanBePlacedInEngine_SetBit(void* Obj)
{
	((FPluginTemplateDescriptionToolsetInfo*)Obj)->bCanBePlacedInEngine = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPluginTemplateDescriptionToolsetInfo_Statics::NewProp_bCanBePlacedInEngine = { "bCanBePlacedInEngine", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FPluginTemplateDescriptionToolsetInfo), &Z_Construct_UScriptStruct_FPluginTemplateDescriptionToolsetInfo_Statics::NewProp_bCanBePlacedInEngine_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCanBePlacedInEngine_MetaData), NewProp_bCanBePlacedInEngine_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPluginTemplateDescriptionToolsetInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginTemplateDescriptionToolsetInfo_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginTemplateDescriptionToolsetInfo_Statics::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginTemplateDescriptionToolsetInfo_Statics::NewProp_OnDiskPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginTemplateDescriptionToolsetInfo_Statics::NewProp_DefaultTemplateName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginTemplateDescriptionToolsetInfo_Statics::NewProp_bCanBePlacedInEngine,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPluginTemplateDescriptionToolsetInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FPluginTemplateDescriptionToolsetInfo Property Definitions **********
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPluginTemplateDescriptionToolsetInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_PluginToolset,
	nullptr,
	&NewStructOps,
	"PluginTemplateDescriptionToolsetInfo",
	Z_Construct_UScriptStruct_FPluginTemplateDescriptionToolsetInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPluginTemplateDescriptionToolsetInfo_Statics::PropPointers),
	sizeof(FPluginTemplateDescriptionToolsetInfo),
	alignof(FPluginTemplateDescriptionToolsetInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPluginTemplateDescriptionToolsetInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPluginTemplateDescriptionToolsetInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FPluginTemplateDescriptionToolsetInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FPluginTemplateDescriptionToolsetInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FPluginTemplateDescriptionToolsetInfo.InnerSingleton, Z_Construct_UScriptStruct_FPluginTemplateDescriptionToolsetInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FPluginTemplateDescriptionToolsetInfo.InnerSingleton);
}
// ********** End ScriptStruct FPluginTemplateDescriptionToolsetInfo *******************************

// ********** Begin Class UPluginToolset Function AddPluginDependency ******************************
struct Z_Construct_UFunction_UPluginToolset_AddPluginDependency_Statics
{
	struct PluginToolset_eventAddPluginDependency_Parms
	{
		FString PluginName;
		FString DependencyName;
		bool bOptional;
		bool bEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Adds a dependency entry to a plugin's Plugins array in its .uplugin file.\n\x09 * No-ops if a dependency with that name already exists with matching settings.\n\x09 * The dependency plugin does not need to be currently discovered.\n\x09 * @param PluginName The name of the plugin to modify.\n\x09 * @param DependencyName The name of the plugin to add as a dependency.\n\x09 * @param bOptional Whether the dependency is optional.\n\x09 * @param bEnabled Whether the dependency should be enabled.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds a dependency entry to a plugin's Plugins array in its .uplugin file.\nNo-ops if a dependency with that name already exists with matching settings.\nThe dependency plugin does not need to be currently discovered.\n@param PluginName The name of the plugin to modify.\n@param DependencyName The name of the plugin to add as a dependency.\n@param bOptional Whether the dependency is optional.\n@param bEnabled Whether the dependency should be enabled." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DependencyName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddPluginDependency constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_PluginName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DependencyName;
	static void NewProp_bOptional_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOptional;
	static void NewProp_bEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddPluginDependency constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddPluginDependency Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPluginToolset_AddPluginDependency_Statics::NewProp_PluginName = { "PluginName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PluginToolset_eventAddPluginDependency_Parms, PluginName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PluginName_MetaData), NewProp_PluginName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPluginToolset_AddPluginDependency_Statics::NewProp_DependencyName = { "DependencyName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PluginToolset_eventAddPluginDependency_Parms, DependencyName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DependencyName_MetaData), NewProp_DependencyName_MetaData) };
void Z_Construct_UFunction_UPluginToolset_AddPluginDependency_Statics::NewProp_bOptional_SetBit(void* Obj)
{
	((PluginToolset_eventAddPluginDependency_Parms*)Obj)->bOptional = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPluginToolset_AddPluginDependency_Statics::NewProp_bOptional = { "bOptional", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PluginToolset_eventAddPluginDependency_Parms), &Z_Construct_UFunction_UPluginToolset_AddPluginDependency_Statics::NewProp_bOptional_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPluginToolset_AddPluginDependency_Statics::NewProp_bEnabled_SetBit(void* Obj)
{
	((PluginToolset_eventAddPluginDependency_Parms*)Obj)->bEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPluginToolset_AddPluginDependency_Statics::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PluginToolset_eventAddPluginDependency_Parms), &Z_Construct_UFunction_UPluginToolset_AddPluginDependency_Statics::NewProp_bEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPluginToolset_AddPluginDependency_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_AddPluginDependency_Statics::NewProp_PluginName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_AddPluginDependency_Statics::NewProp_DependencyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_AddPluginDependency_Statics::NewProp_bOptional,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_AddPluginDependency_Statics::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_AddPluginDependency_Statics::PropPointers) < 2048);
// ********** End Function AddPluginDependency Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPluginToolset_AddPluginDependency_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPluginToolset, nullptr, "AddPluginDependency", 	Z_Construct_UFunction_UPluginToolset_AddPluginDependency_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_AddPluginDependency_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPluginToolset_AddPluginDependency_Statics::PluginToolset_eventAddPluginDependency_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_AddPluginDependency_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPluginToolset_AddPluginDependency_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPluginToolset_AddPluginDependency_Statics::PluginToolset_eventAddPluginDependency_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPluginToolset_AddPluginDependency()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPluginToolset_AddPluginDependency_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPluginToolset::execAddPluginDependency)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_PluginName);
	P_GET_PROPERTY(FStrProperty,Z_Param_DependencyName);
	P_GET_UBOOL(Z_Param_bOptional);
	P_GET_UBOOL(Z_Param_bEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	UPluginToolset::AddPluginDependency(Z_Param_PluginName,Z_Param_DependencyName,Z_Param_bOptional,Z_Param_bEnabled);
	P_NATIVE_END;
}
// ********** End Class UPluginToolset Function AddPluginDependency ********************************

// ********** Begin Class UPluginToolset Function CreatePlugin *************************************
struct Z_Construct_UFunction_UPluginToolset_CreatePlugin_Statics
{
	struct PluginToolset_eventCreatePlugin_Parms
	{
		FString PluginName;
		FString RelativePluginLocation;
		bool bPlaceInEngine;
		FPluginTemplateDescriptionToolsetInfo TemplateInfo;
		FString Description;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Creates a new plugin from a template and loads it into the editor.\n\x09 * Use GetPluginTemplateDescriptions to obtain a valid TemplateInfo.\n\x09 * @param PluginName Name for the new plugin.\n\x09 * @param RelativePluginLocation Parent directory for the new plugin relative to template's default location.\n\x09 *     This should be empty unless you wish to specify a subdirectory.\n\x09 * @param bPlaceInEngine Use Engine Plugins directory rather than Game Plugins directory location.\n\x09 *     Only some Templates allow placing in Engine. See the TemplateInfo's bCanBePlacedInEngine.\n\x09 *     This should be false unless explicitly requested by the user.\n\x09 * @param TemplateInfo The plugin template to create from.\n\x09 * @param Description A description for the new plugin.\n\x09 * @return Created plugin's descriptor filename. Empty on failure.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Creates a new plugin from a template and loads it into the editor.\nUse GetPluginTemplateDescriptions to obtain a valid TemplateInfo.\n@param PluginName Name for the new plugin.\n@param RelativePluginLocation Parent directory for the new plugin relative to template's default location.\n    This should be empty unless you wish to specify a subdirectory.\n@param bPlaceInEngine Use Engine Plugins directory rather than Game Plugins directory location.\n    Only some Templates allow placing in Engine. See the TemplateInfo's bCanBePlacedInEngine.\n    This should be false unless explicitly requested by the user.\n@param TemplateInfo The plugin template to create from.\n@param Description A description for the new plugin.\n@return Created plugin's descriptor filename. Empty on failure." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RelativePluginLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPlaceInEngine_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TemplateInfo_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CreatePlugin constinit property declarations **************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_PluginName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_RelativePluginLocation;
	static void NewProp_bPlaceInEngine_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPlaceInEngine;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TemplateInfo;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Description;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CreatePlugin constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CreatePlugin Property Definitions *************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPluginToolset_CreatePlugin_Statics::NewProp_PluginName = { "PluginName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PluginToolset_eventCreatePlugin_Parms, PluginName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PluginName_MetaData), NewProp_PluginName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPluginToolset_CreatePlugin_Statics::NewProp_RelativePluginLocation = { "RelativePluginLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PluginToolset_eventCreatePlugin_Parms, RelativePluginLocation), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RelativePluginLocation_MetaData), NewProp_RelativePluginLocation_MetaData) };
void Z_Construct_UFunction_UPluginToolset_CreatePlugin_Statics::NewProp_bPlaceInEngine_SetBit(void* Obj)
{
	((PluginToolset_eventCreatePlugin_Parms*)Obj)->bPlaceInEngine = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPluginToolset_CreatePlugin_Statics::NewProp_bPlaceInEngine = { "bPlaceInEngine", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PluginToolset_eventCreatePlugin_Parms), &Z_Construct_UFunction_UPluginToolset_CreatePlugin_Statics::NewProp_bPlaceInEngine_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPlaceInEngine_MetaData), NewProp_bPlaceInEngine_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPluginToolset_CreatePlugin_Statics::NewProp_TemplateInfo = { "TemplateInfo", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PluginToolset_eventCreatePlugin_Parms, TemplateInfo), Z_Construct_UScriptStruct_FPluginTemplateDescriptionToolsetInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TemplateInfo_MetaData), NewProp_TemplateInfo_MetaData) }; // 4229272450
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPluginToolset_CreatePlugin_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PluginToolset_eventCreatePlugin_Parms, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPluginToolset_CreatePlugin_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PluginToolset_eventCreatePlugin_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPluginToolset_CreatePlugin_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_CreatePlugin_Statics::NewProp_PluginName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_CreatePlugin_Statics::NewProp_RelativePluginLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_CreatePlugin_Statics::NewProp_bPlaceInEngine,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_CreatePlugin_Statics::NewProp_TemplateInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_CreatePlugin_Statics::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_CreatePlugin_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_CreatePlugin_Statics::PropPointers) < 2048);
// ********** End Function CreatePlugin Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPluginToolset_CreatePlugin_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPluginToolset, nullptr, "CreatePlugin", 	Z_Construct_UFunction_UPluginToolset_CreatePlugin_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_CreatePlugin_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPluginToolset_CreatePlugin_Statics::PluginToolset_eventCreatePlugin_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_CreatePlugin_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPluginToolset_CreatePlugin_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPluginToolset_CreatePlugin_Statics::PluginToolset_eventCreatePlugin_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPluginToolset_CreatePlugin()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPluginToolset_CreatePlugin_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPluginToolset::execCreatePlugin)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_PluginName);
	P_GET_PROPERTY(FStrProperty,Z_Param_RelativePluginLocation);
	P_GET_UBOOL(Z_Param_bPlaceInEngine);
	P_GET_STRUCT_REF(FPluginTemplateDescriptionToolsetInfo,Z_Param_Out_TemplateInfo);
	P_GET_PROPERTY(FStrProperty,Z_Param_Description);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UPluginToolset::CreatePlugin(Z_Param_PluginName,Z_Param_RelativePluginLocation,Z_Param_bPlaceInEngine,Z_Param_Out_TemplateInfo,Z_Param_Description);
	P_NATIVE_END;
}
// ********** End Class UPluginToolset Function CreatePlugin ***************************************

// ********** Begin Class UPluginToolset Function GetPluginDependencies ****************************
struct Z_Construct_UFunction_UPluginToolset_GetPluginDependencies_Statics
{
	struct PluginToolset_eventGetPluginDependencies_Parms
	{
		FString PluginName;
		TArray<FPluginDependencyToolsetInfo> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the dependency entries from a plugin's Plugins array in its .uplugin file.\n\x09 * @param PluginName The name of the plugin.\n\x09 * @return Array of dependency entries declared in the plugin's .uplugin file.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the dependency entries from a plugin's Plugins array in its .uplugin file.\n@param PluginName The name of the plugin.\n@return Array of dependency entries declared in the plugin's .uplugin file." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPluginDependencies constinit property declarations *****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_PluginName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPluginDependencies constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPluginDependencies Property Definitions ****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPluginToolset_GetPluginDependencies_Statics::NewProp_PluginName = { "PluginName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PluginToolset_eventGetPluginDependencies_Parms, PluginName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PluginName_MetaData), NewProp_PluginName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPluginToolset_GetPluginDependencies_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FPluginDependencyToolsetInfo, METADATA_PARAMS(0, nullptr) }; // 1823409718
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPluginToolset_GetPluginDependencies_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PluginToolset_eventGetPluginDependencies_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 1823409718
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPluginToolset_GetPluginDependencies_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_GetPluginDependencies_Statics::NewProp_PluginName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_GetPluginDependencies_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_GetPluginDependencies_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_GetPluginDependencies_Statics::PropPointers) < 2048);
// ********** End Function GetPluginDependencies Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPluginToolset_GetPluginDependencies_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPluginToolset, nullptr, "GetPluginDependencies", 	Z_Construct_UFunction_UPluginToolset_GetPluginDependencies_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_GetPluginDependencies_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPluginToolset_GetPluginDependencies_Statics::PluginToolset_eventGetPluginDependencies_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_GetPluginDependencies_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPluginToolset_GetPluginDependencies_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPluginToolset_GetPluginDependencies_Statics::PluginToolset_eventGetPluginDependencies_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPluginToolset_GetPluginDependencies()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPluginToolset_GetPluginDependencies_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPluginToolset::execGetPluginDependencies)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_PluginName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FPluginDependencyToolsetInfo>*)Z_Param__Result=UPluginToolset::GetPluginDependencies(Z_Param_PluginName);
	P_NATIVE_END;
}
// ********** End Class UPluginToolset Function GetPluginDependencies ******************************

// ********** Begin Class UPluginToolset Function GetPluginDependents ******************************
struct Z_Construct_UFunction_UPluginToolset_GetPluginDependents_Statics
{
	struct PluginToolset_eventGetPluginDependents_Parms
	{
		FString PluginName;
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the names of all discovered plugins that declare a dependency on the given plugin.\n\x09 * @param PluginName The name of the plugin to search for as a dependency target.\n\x09 * @return Sorted array of plugin names that list the given plugin in their Plugins array.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the names of all discovered plugins that declare a dependency on the given plugin.\n@param PluginName The name of the plugin to search for as a dependency target.\n@return Sorted array of plugin names that list the given plugin in their Plugins array." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPluginDependents constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_PluginName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPluginDependents constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPluginDependents Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPluginToolset_GetPluginDependents_Statics::NewProp_PluginName = { "PluginName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PluginToolset_eventGetPluginDependents_Parms, PluginName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PluginName_MetaData), NewProp_PluginName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPluginToolset_GetPluginDependents_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPluginToolset_GetPluginDependents_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PluginToolset_eventGetPluginDependents_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPluginToolset_GetPluginDependents_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_GetPluginDependents_Statics::NewProp_PluginName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_GetPluginDependents_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_GetPluginDependents_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_GetPluginDependents_Statics::PropPointers) < 2048);
// ********** End Function GetPluginDependents Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPluginToolset_GetPluginDependents_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPluginToolset, nullptr, "GetPluginDependents", 	Z_Construct_UFunction_UPluginToolset_GetPluginDependents_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_GetPluginDependents_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPluginToolset_GetPluginDependents_Statics::PluginToolset_eventGetPluginDependents_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_GetPluginDependents_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPluginToolset_GetPluginDependents_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPluginToolset_GetPluginDependents_Statics::PluginToolset_eventGetPluginDependents_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPluginToolset_GetPluginDependents()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPluginToolset_GetPluginDependents_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPluginToolset::execGetPluginDependents)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_PluginName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=UPluginToolset::GetPluginDependents(Z_Param_PluginName);
	P_NATIVE_END;
}
// ********** End Class UPluginToolset Function GetPluginDependents ********************************

// ********** Begin Class UPluginToolset Function GetPluginDescriptor ******************************
struct Z_Construct_UFunction_UPluginToolset_GetPluginDescriptor_Statics
{
	struct PluginToolset_eventGetPluginDescriptor_Parms
	{
		FString PluginName;
		FPluginDescriptorToolsetInfo ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Gets the editable descriptor fields for a discovered plugin.\n\x09 * @param PluginName The name of the plugin.\n\x09 * @return The plugin's current editable descriptor fields.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Gets the editable descriptor fields for a discovered plugin.\n@param PluginName The name of the plugin.\n@return The plugin's current editable descriptor fields." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPluginDescriptor constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_PluginName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPluginDescriptor constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPluginDescriptor Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPluginToolset_GetPluginDescriptor_Statics::NewProp_PluginName = { "PluginName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PluginToolset_eventGetPluginDescriptor_Parms, PluginName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PluginName_MetaData), NewProp_PluginName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPluginToolset_GetPluginDescriptor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PluginToolset_eventGetPluginDescriptor_Parms, ReturnValue), Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo, METADATA_PARAMS(0, nullptr) }; // 2496262418
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPluginToolset_GetPluginDescriptor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_GetPluginDescriptor_Statics::NewProp_PluginName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_GetPluginDescriptor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_GetPluginDescriptor_Statics::PropPointers) < 2048);
// ********** End Function GetPluginDescriptor Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPluginToolset_GetPluginDescriptor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPluginToolset, nullptr, "GetPluginDescriptor", 	Z_Construct_UFunction_UPluginToolset_GetPluginDescriptor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_GetPluginDescriptor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPluginToolset_GetPluginDescriptor_Statics::PluginToolset_eventGetPluginDescriptor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_GetPluginDescriptor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPluginToolset_GetPluginDescriptor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPluginToolset_GetPluginDescriptor_Statics::PluginToolset_eventGetPluginDescriptor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPluginToolset_GetPluginDescriptor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPluginToolset_GetPluginDescriptor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPluginToolset::execGetPluginDescriptor)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_PluginName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FPluginDescriptorToolsetInfo*)Z_Param__Result=UPluginToolset::GetPluginDescriptor(Z_Param_PluginName);
	P_NATIVE_END;
}
// ********** End Class UPluginToolset Function GetPluginDescriptor ********************************

// ********** Begin Class UPluginToolset Function GetPluginForAsset ********************************
struct Z_Construct_UFunction_UPluginToolset_GetPluginForAsset_Statics
{
	struct PluginToolset_eventGetPluginForAsset_Parms
	{
		FString AssetPath;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the name of the enabled plugin whose content mount point contains the given asset path.\n\x09 * Accepts full asset paths or mount point prefixes (e.g. /PluginName/ or /Game/Path/To/Asset).\n\x09 * @param AssetPath The asset or mount point path to look up.\n\x09 * @return The name of the plugin that owns the asset.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the name of the enabled plugin whose content mount point contains the given asset path.\nAccepts full asset paths or mount point prefixes (e.g. /PluginName/ or /Game/Path/To/Asset).\n@param AssetPath The asset or mount point path to look up.\n@return The name of the plugin that owns the asset." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AssetPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPluginForAsset constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AssetPath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPluginForAsset constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPluginForAsset Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPluginToolset_GetPluginForAsset_Statics::NewProp_AssetPath = { "AssetPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PluginToolset_eventGetPluginForAsset_Parms, AssetPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AssetPath_MetaData), NewProp_AssetPath_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPluginToolset_GetPluginForAsset_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PluginToolset_eventGetPluginForAsset_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPluginToolset_GetPluginForAsset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_GetPluginForAsset_Statics::NewProp_AssetPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_GetPluginForAsset_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_GetPluginForAsset_Statics::PropPointers) < 2048);
// ********** End Function GetPluginForAsset Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPluginToolset_GetPluginForAsset_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPluginToolset, nullptr, "GetPluginForAsset", 	Z_Construct_UFunction_UPluginToolset_GetPluginForAsset_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_GetPluginForAsset_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPluginToolset_GetPluginForAsset_Statics::PluginToolset_eventGetPluginForAsset_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_GetPluginForAsset_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPluginToolset_GetPluginForAsset_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPluginToolset_GetPluginForAsset_Statics::PluginToolset_eventGetPluginForAsset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPluginToolset_GetPluginForAsset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPluginToolset_GetPluginForAsset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPluginToolset::execGetPluginForAsset)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AssetPath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UPluginToolset::GetPluginForAsset(Z_Param_AssetPath);
	P_NATIVE_END;
}
// ********** End Class UPluginToolset Function GetPluginForAsset **********************************

// ********** Begin Class UPluginToolset Function GetPluginInfo ************************************
struct Z_Construct_UFunction_UPluginToolset_GetPluginInfo_Statics
{
	struct PluginToolset_eventGetPluginInfo_Parms
	{
		FString PluginName;
		FPluginToolsetInfo ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Gets metadata for a discovered plugin, including description, version, base directory,\n\x09 * content directory, descriptor path, and mounted asset path.\n\x09 * @param PluginName The name of the plugin.\n\x09 * @return Metadata for the plugin.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Gets metadata for a discovered plugin, including description, version, base directory,\ncontent directory, descriptor path, and mounted asset path.\n@param PluginName The name of the plugin.\n@return Metadata for the plugin." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPluginInfo constinit property declarations *************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_PluginName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPluginInfo constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPluginInfo Property Definitions ************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPluginToolset_GetPluginInfo_Statics::NewProp_PluginName = { "PluginName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PluginToolset_eventGetPluginInfo_Parms, PluginName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PluginName_MetaData), NewProp_PluginName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPluginToolset_GetPluginInfo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PluginToolset_eventGetPluginInfo_Parms, ReturnValue), Z_Construct_UScriptStruct_FPluginToolsetInfo, METADATA_PARAMS(0, nullptr) }; // 899329902
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPluginToolset_GetPluginInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_GetPluginInfo_Statics::NewProp_PluginName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_GetPluginInfo_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_GetPluginInfo_Statics::PropPointers) < 2048);
// ********** End Function GetPluginInfo Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPluginToolset_GetPluginInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPluginToolset, nullptr, "GetPluginInfo", 	Z_Construct_UFunction_UPluginToolset_GetPluginInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_GetPluginInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPluginToolset_GetPluginInfo_Statics::PluginToolset_eventGetPluginInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_GetPluginInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPluginToolset_GetPluginInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPluginToolset_GetPluginInfo_Statics::PluginToolset_eventGetPluginInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPluginToolset_GetPluginInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPluginToolset_GetPluginInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPluginToolset::execGetPluginInfo)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_PluginName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FPluginToolsetInfo*)Z_Param__Result=UPluginToolset::GetPluginInfo(Z_Param_PluginName);
	P_NATIVE_END;
}
// ********** End Class UPluginToolset Function GetPluginInfo **************************************

// ********** Begin Class UPluginToolset Function GetPluginTemplateDescriptions ********************
struct Z_Construct_UFunction_UPluginToolset_GetPluginTemplateDescriptions_Statics
{
	struct PluginToolset_eventGetPluginTemplateDescriptions_Parms
	{
		TArray<FPluginTemplateDescriptionToolsetInfo> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the list of available plugin templates. Pass one of the results to CreatePlugin\n\x09 * to create a new plugin from that template.\n\x09 * @return Array of available plugin template descriptors.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the list of available plugin templates. Pass one of the results to CreatePlugin\nto create a new plugin from that template.\n@return Array of available plugin template descriptors." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetPluginTemplateDescriptions constinit property declarations *********
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPluginTemplateDescriptions constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPluginTemplateDescriptions Property Definitions ********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPluginToolset_GetPluginTemplateDescriptions_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FPluginTemplateDescriptionToolsetInfo, METADATA_PARAMS(0, nullptr) }; // 4229272450
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPluginToolset_GetPluginTemplateDescriptions_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PluginToolset_eventGetPluginTemplateDescriptions_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 4229272450
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPluginToolset_GetPluginTemplateDescriptions_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_GetPluginTemplateDescriptions_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_GetPluginTemplateDescriptions_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_GetPluginTemplateDescriptions_Statics::PropPointers) < 2048);
// ********** End Function GetPluginTemplateDescriptions Property Definitions **********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPluginToolset_GetPluginTemplateDescriptions_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPluginToolset, nullptr, "GetPluginTemplateDescriptions", 	Z_Construct_UFunction_UPluginToolset_GetPluginTemplateDescriptions_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_GetPluginTemplateDescriptions_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPluginToolset_GetPluginTemplateDescriptions_Statics::PluginToolset_eventGetPluginTemplateDescriptions_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_GetPluginTemplateDescriptions_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPluginToolset_GetPluginTemplateDescriptions_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPluginToolset_GetPluginTemplateDescriptions_Statics::PluginToolset_eventGetPluginTemplateDescriptions_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPluginToolset_GetPluginTemplateDescriptions()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPluginToolset_GetPluginTemplateDescriptions_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPluginToolset::execGetPluginTemplateDescriptions)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FPluginTemplateDescriptionToolsetInfo>*)Z_Param__Result=UPluginToolset::GetPluginTemplateDescriptions();
	P_NATIVE_END;
}
// ********** End Class UPluginToolset Function GetPluginTemplateDescriptions **********************

// ********** Begin Class UPluginToolset Function IsEnabled ****************************************
struct Z_Construct_UFunction_UPluginToolset_IsEnabled_Statics
{
	struct PluginToolset_eventIsEnabled_Parms
	{
		FString PluginName;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Checks whether a discovered plugin is currently enabled.\n\x09 * @param PluginName The name of the plugin.\n\x09 * @return True if the plugin is enabled, false if it is disabled.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Checks whether a discovered plugin is currently enabled.\n@param PluginName The name of the plugin.\n@return True if the plugin is enabled, false if it is disabled." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsEnabled constinit property declarations *****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_PluginName;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsEnabled constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsEnabled Property Definitions ****************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPluginToolset_IsEnabled_Statics::NewProp_PluginName = { "PluginName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PluginToolset_eventIsEnabled_Parms, PluginName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PluginName_MetaData), NewProp_PluginName_MetaData) };
void Z_Construct_UFunction_UPluginToolset_IsEnabled_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PluginToolset_eventIsEnabled_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPluginToolset_IsEnabled_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PluginToolset_eventIsEnabled_Parms), &Z_Construct_UFunction_UPluginToolset_IsEnabled_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPluginToolset_IsEnabled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_IsEnabled_Statics::NewProp_PluginName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_IsEnabled_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_IsEnabled_Statics::PropPointers) < 2048);
// ********** End Function IsEnabled Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPluginToolset_IsEnabled_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPluginToolset, nullptr, "IsEnabled", 	Z_Construct_UFunction_UPluginToolset_IsEnabled_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_IsEnabled_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPluginToolset_IsEnabled_Statics::PluginToolset_eventIsEnabled_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_IsEnabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPluginToolset_IsEnabled_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPluginToolset_IsEnabled_Statics::PluginToolset_eventIsEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPluginToolset_IsEnabled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPluginToolset_IsEnabled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPluginToolset::execIsEnabled)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_PluginName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPluginToolset::IsEnabled(Z_Param_PluginName);
	P_NATIVE_END;
}
// ********** End Class UPluginToolset Function IsEnabled ******************************************

// ********** Begin Class UPluginToolset Function IsPluginCreationAllowed **************************
struct Z_Construct_UFunction_UPluginToolset_IsPluginCreationAllowed_Statics
{
	struct PluginToolset_eventIsPluginCreationAllowed_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Checks whether the editor settings permit plugin creation from the plugin browser.\n\x09 * @return True if plugin creation is allowed, false if it is disabled in Editor Settings.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Checks whether the editor settings permit plugin creation from the plugin browser.\n@return True if plugin creation is allowed, false if it is disabled in Editor Settings." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsPluginCreationAllowed constinit property declarations ***************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsPluginCreationAllowed constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsPluginCreationAllowed Property Definitions **************************
void Z_Construct_UFunction_UPluginToolset_IsPluginCreationAllowed_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PluginToolset_eventIsPluginCreationAllowed_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPluginToolset_IsPluginCreationAllowed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PluginToolset_eventIsPluginCreationAllowed_Parms), &Z_Construct_UFunction_UPluginToolset_IsPluginCreationAllowed_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPluginToolset_IsPluginCreationAllowed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_IsPluginCreationAllowed_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_IsPluginCreationAllowed_Statics::PropPointers) < 2048);
// ********** End Function IsPluginCreationAllowed Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPluginToolset_IsPluginCreationAllowed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPluginToolset, nullptr, "IsPluginCreationAllowed", 	Z_Construct_UFunction_UPluginToolset_IsPluginCreationAllowed_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_IsPluginCreationAllowed_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPluginToolset_IsPluginCreationAllowed_Statics::PluginToolset_eventIsPluginCreationAllowed_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_IsPluginCreationAllowed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPluginToolset_IsPluginCreationAllowed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPluginToolset_IsPluginCreationAllowed_Statics::PluginToolset_eventIsPluginCreationAllowed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPluginToolset_IsPluginCreationAllowed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPluginToolset_IsPluginCreationAllowed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPluginToolset::execIsPluginCreationAllowed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPluginToolset::IsPluginCreationAllowed();
	P_NATIVE_END;
}
// ********** End Class UPluginToolset Function IsPluginCreationAllowed ****************************

// ********** Begin Class UPluginToolset Function IsPluginModificationAllowed **********************
struct Z_Construct_UFunction_UPluginToolset_IsPluginModificationAllowed_Statics
{
	struct PluginToolset_eventIsPluginModificationAllowed_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Checks whether the editor settings permit modifying plugins from the plugin browser.\n\x09 * @return True if plugin modification is allowed, false if it is disabled in Editor Settings.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Checks whether the editor settings permit modifying plugins from the plugin browser.\n@return True if plugin modification is allowed, false if it is disabled in Editor Settings." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsPluginModificationAllowed constinit property declarations ***********
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsPluginModificationAllowed constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsPluginModificationAllowed Property Definitions **********************
void Z_Construct_UFunction_UPluginToolset_IsPluginModificationAllowed_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PluginToolset_eventIsPluginModificationAllowed_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPluginToolset_IsPluginModificationAllowed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PluginToolset_eventIsPluginModificationAllowed_Parms), &Z_Construct_UFunction_UPluginToolset_IsPluginModificationAllowed_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPluginToolset_IsPluginModificationAllowed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_IsPluginModificationAllowed_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_IsPluginModificationAllowed_Statics::PropPointers) < 2048);
// ********** End Function IsPluginModificationAllowed Property Definitions ************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPluginToolset_IsPluginModificationAllowed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPluginToolset, nullptr, "IsPluginModificationAllowed", 	Z_Construct_UFunction_UPluginToolset_IsPluginModificationAllowed_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_IsPluginModificationAllowed_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPluginToolset_IsPluginModificationAllowed_Statics::PluginToolset_eventIsPluginModificationAllowed_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_IsPluginModificationAllowed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPluginToolset_IsPluginModificationAllowed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPluginToolset_IsPluginModificationAllowed_Statics::PluginToolset_eventIsPluginModificationAllowed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPluginToolset_IsPluginModificationAllowed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPluginToolset_IsPluginModificationAllowed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPluginToolset::execIsPluginModificationAllowed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPluginToolset::IsPluginModificationAllowed();
	P_NATIVE_END;
}
// ********** End Class UPluginToolset Function IsPluginModificationAllowed ************************

// ********** Begin Class UPluginToolset Function ListDiscoveredPlugins ****************************
struct Z_Construct_UFunction_UPluginToolset_ListDiscoveredPlugins_Statics
{
	struct PluginToolset_eventListDiscoveredPlugins_Parms
	{
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Lists the names of all discovered plugins (enabled and disabled), sorted alphabetically.\n\x09 * @return Sorted array of discovered plugin names.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lists the names of all discovered plugins (enabled and disabled), sorted alphabetically.\n@return Sorted array of discovered plugin names." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ListDiscoveredPlugins constinit property declarations *****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListDiscoveredPlugins constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListDiscoveredPlugins Property Definitions ****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPluginToolset_ListDiscoveredPlugins_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPluginToolset_ListDiscoveredPlugins_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PluginToolset_eventListDiscoveredPlugins_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPluginToolset_ListDiscoveredPlugins_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_ListDiscoveredPlugins_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_ListDiscoveredPlugins_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_ListDiscoveredPlugins_Statics::PropPointers) < 2048);
// ********** End Function ListDiscoveredPlugins Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPluginToolset_ListDiscoveredPlugins_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPluginToolset, nullptr, "ListDiscoveredPlugins", 	Z_Construct_UFunction_UPluginToolset_ListDiscoveredPlugins_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_ListDiscoveredPlugins_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPluginToolset_ListDiscoveredPlugins_Statics::PluginToolset_eventListDiscoveredPlugins_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_ListDiscoveredPlugins_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPluginToolset_ListDiscoveredPlugins_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPluginToolset_ListDiscoveredPlugins_Statics::PluginToolset_eventListDiscoveredPlugins_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPluginToolset_ListDiscoveredPlugins()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPluginToolset_ListDiscoveredPlugins_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPluginToolset::execListDiscoveredPlugins)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=UPluginToolset::ListDiscoveredPlugins();
	P_NATIVE_END;
}
// ********** End Class UPluginToolset Function ListDiscoveredPlugins ******************************

// ********** Begin Class UPluginToolset Function ListEnabledPlugins *******************************
struct Z_Construct_UFunction_UPluginToolset_ListEnabledPlugins_Statics
{
	struct PluginToolset_eventListEnabledPlugins_Parms
	{
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Lists the names of all enabled plugins, sorted alphabetically.\n\x09 * @return Sorted array of enabled plugin names.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lists the names of all enabled plugins, sorted alphabetically.\n@return Sorted array of enabled plugin names." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ListEnabledPlugins constinit property declarations ********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListEnabledPlugins constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListEnabledPlugins Property Definitions *******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPluginToolset_ListEnabledPlugins_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPluginToolset_ListEnabledPlugins_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PluginToolset_eventListEnabledPlugins_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPluginToolset_ListEnabledPlugins_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_ListEnabledPlugins_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_ListEnabledPlugins_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_ListEnabledPlugins_Statics::PropPointers) < 2048);
// ********** End Function ListEnabledPlugins Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPluginToolset_ListEnabledPlugins_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPluginToolset, nullptr, "ListEnabledPlugins", 	Z_Construct_UFunction_UPluginToolset_ListEnabledPlugins_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_ListEnabledPlugins_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPluginToolset_ListEnabledPlugins_Statics::PluginToolset_eventListEnabledPlugins_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_ListEnabledPlugins_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPluginToolset_ListEnabledPlugins_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPluginToolset_ListEnabledPlugins_Statics::PluginToolset_eventListEnabledPlugins_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPluginToolset_ListEnabledPlugins()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPluginToolset_ListEnabledPlugins_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPluginToolset::execListEnabledPlugins)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=UPluginToolset::ListEnabledPlugins();
	P_NATIVE_END;
}
// ********** End Class UPluginToolset Function ListEnabledPlugins *********************************

// ********** Begin Class UPluginToolset Function RemovePluginDependency ***************************
struct Z_Construct_UFunction_UPluginToolset_RemovePluginDependency_Statics
{
	struct PluginToolset_eventRemovePluginDependency_Parms
	{
		FString PluginName;
		FString DependencyName;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Removes a dependency entry from a plugin's Plugins array in its .uplugin file.\n\x09 * @param PluginName The name of the plugin to modify.\n\x09 * @param DependencyName The name of the dependency to remove.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Removes a dependency entry from a plugin's Plugins array in its .uplugin file.\n@param PluginName The name of the plugin to modify.\n@param DependencyName The name of the dependency to remove." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DependencyName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RemovePluginDependency constinit property declarations ****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_PluginName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DependencyName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RemovePluginDependency constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RemovePluginDependency Property Definitions ***************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPluginToolset_RemovePluginDependency_Statics::NewProp_PluginName = { "PluginName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PluginToolset_eventRemovePluginDependency_Parms, PluginName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PluginName_MetaData), NewProp_PluginName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPluginToolset_RemovePluginDependency_Statics::NewProp_DependencyName = { "DependencyName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PluginToolset_eventRemovePluginDependency_Parms, DependencyName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DependencyName_MetaData), NewProp_DependencyName_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPluginToolset_RemovePluginDependency_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_RemovePluginDependency_Statics::NewProp_PluginName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_RemovePluginDependency_Statics::NewProp_DependencyName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_RemovePluginDependency_Statics::PropPointers) < 2048);
// ********** End Function RemovePluginDependency Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPluginToolset_RemovePluginDependency_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPluginToolset, nullptr, "RemovePluginDependency", 	Z_Construct_UFunction_UPluginToolset_RemovePluginDependency_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_RemovePluginDependency_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPluginToolset_RemovePluginDependency_Statics::PluginToolset_eventRemovePluginDependency_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_RemovePluginDependency_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPluginToolset_RemovePluginDependency_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPluginToolset_RemovePluginDependency_Statics::PluginToolset_eventRemovePluginDependency_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPluginToolset_RemovePluginDependency()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPluginToolset_RemovePluginDependency_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPluginToolset::execRemovePluginDependency)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_PluginName);
	P_GET_PROPERTY(FStrProperty,Z_Param_DependencyName);
	P_FINISH;
	P_NATIVE_BEGIN;
	UPluginToolset::RemovePluginDependency(Z_Param_PluginName,Z_Param_DependencyName);
	P_NATIVE_END;
}
// ********** End Class UPluginToolset Function RemovePluginDependency *****************************

// ********** Begin Class UPluginToolset Function SetPluginEnabled *********************************
struct Z_Construct_UFunction_UPluginToolset_SetPluginEnabled_Statics
{
	struct PluginToolset_eventSetPluginEnabled_Parms
	{
		FString PluginName;
		bool bEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Enables or disables a plugin in the project config. The change takes effect on the next editor restart.\n\x09 * @param PluginName The name of the plugin.\n\x09 * @param bEnabled True to enable, false to disable.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enables or disables a plugin in the project config. The change takes effect on the next editor restart.\n@param PluginName The name of the plugin.\n@param bEnabled True to enable, false to disable." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetPluginEnabled constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_PluginName;
	static void NewProp_bEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetPluginEnabled constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetPluginEnabled Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPluginToolset_SetPluginEnabled_Statics::NewProp_PluginName = { "PluginName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PluginToolset_eventSetPluginEnabled_Parms, PluginName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PluginName_MetaData), NewProp_PluginName_MetaData) };
void Z_Construct_UFunction_UPluginToolset_SetPluginEnabled_Statics::NewProp_bEnabled_SetBit(void* Obj)
{
	((PluginToolset_eventSetPluginEnabled_Parms*)Obj)->bEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPluginToolset_SetPluginEnabled_Statics::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PluginToolset_eventSetPluginEnabled_Parms), &Z_Construct_UFunction_UPluginToolset_SetPluginEnabled_Statics::NewProp_bEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPluginToolset_SetPluginEnabled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_SetPluginEnabled_Statics::NewProp_PluginName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_SetPluginEnabled_Statics::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_SetPluginEnabled_Statics::PropPointers) < 2048);
// ********** End Function SetPluginEnabled Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPluginToolset_SetPluginEnabled_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPluginToolset, nullptr, "SetPluginEnabled", 	Z_Construct_UFunction_UPluginToolset_SetPluginEnabled_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_SetPluginEnabled_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPluginToolset_SetPluginEnabled_Statics::PluginToolset_eventSetPluginEnabled_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_SetPluginEnabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPluginToolset_SetPluginEnabled_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPluginToolset_SetPluginEnabled_Statics::PluginToolset_eventSetPluginEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPluginToolset_SetPluginEnabled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPluginToolset_SetPluginEnabled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPluginToolset::execSetPluginEnabled)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_PluginName);
	P_GET_UBOOL(Z_Param_bEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	UPluginToolset::SetPluginEnabled(Z_Param_PluginName,Z_Param_bEnabled);
	P_NATIVE_END;
}
// ********** End Class UPluginToolset Function SetPluginEnabled ***********************************

// ********** Begin Class UPluginToolset Function UpdatePluginDescriptor ***************************
struct Z_Construct_UFunction_UPluginToolset_UpdatePluginDescriptor_Statics
{
	struct PluginToolset_eventUpdatePluginDescriptor_Parms
	{
		FString PluginName;
		FPluginDescriptorToolsetInfo NewDescriptor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Updates a plugin's descriptor fields and writes them to its .uplugin file.\n\x09 * Checks out the file via source control if source control is enabled.\n\x09 * No-ops if the serialized descriptor is unchanged (file is not touched).\n\x09 * @param PluginName The name of the plugin to update.\n\x09 * @param NewDescriptor The new descriptor field values to apply.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Updates a plugin's descriptor fields and writes them to its .uplugin file.\nChecks out the file via source control if source control is enabled.\nNo-ops if the serialized descriptor is unchanged (file is not touched).\n@param PluginName The name of the plugin to update.\n@param NewDescriptor The new descriptor field values to apply." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewDescriptor_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function UpdatePluginDescriptor constinit property declarations ****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_PluginName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NewDescriptor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UpdatePluginDescriptor constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UpdatePluginDescriptor Property Definitions ***************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPluginToolset_UpdatePluginDescriptor_Statics::NewProp_PluginName = { "PluginName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PluginToolset_eventUpdatePluginDescriptor_Parms, PluginName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PluginName_MetaData), NewProp_PluginName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPluginToolset_UpdatePluginDescriptor_Statics::NewProp_NewDescriptor = { "NewDescriptor", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PluginToolset_eventUpdatePluginDescriptor_Parms, NewDescriptor), Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewDescriptor_MetaData), NewProp_NewDescriptor_MetaData) }; // 2496262418
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPluginToolset_UpdatePluginDescriptor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_UpdatePluginDescriptor_Statics::NewProp_PluginName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_UpdatePluginDescriptor_Statics::NewProp_NewDescriptor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_UpdatePluginDescriptor_Statics::PropPointers) < 2048);
// ********** End Function UpdatePluginDescriptor Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPluginToolset_UpdatePluginDescriptor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPluginToolset, nullptr, "UpdatePluginDescriptor", 	Z_Construct_UFunction_UPluginToolset_UpdatePluginDescriptor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_UpdatePluginDescriptor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPluginToolset_UpdatePluginDescriptor_Statics::PluginToolset_eventUpdatePluginDescriptor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_UpdatePluginDescriptor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPluginToolset_UpdatePluginDescriptor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPluginToolset_UpdatePluginDescriptor_Statics::PluginToolset_eventUpdatePluginDescriptor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPluginToolset_UpdatePluginDescriptor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPluginToolset_UpdatePluginDescriptor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPluginToolset::execUpdatePluginDescriptor)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_PluginName);
	P_GET_STRUCT_REF(FPluginDescriptorToolsetInfo,Z_Param_Out_NewDescriptor);
	P_FINISH;
	P_NATIVE_BEGIN;
	UPluginToolset::UpdatePluginDescriptor(Z_Param_PluginName,Z_Param_Out_NewDescriptor);
	P_NATIVE_END;
}
// ********** End Class UPluginToolset Function UpdatePluginDescriptor *****************************

// ********** Begin Class UPluginToolset Function ValidateNewPluginNameAndLocation *****************
struct Z_Construct_UFunction_UPluginToolset_ValidateNewPluginNameAndLocation_Statics
{
	struct PluginToolset_eventValidateNewPluginNameAndLocation_Parms
	{
		FString PluginName;
		FString RelativePluginLocation;
		bool bPlaceInEngine;
		FPluginTemplateDescriptionToolsetInfo TemplateInfo;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PluginToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Validates that PluginName and RelativePluginLocation are acceptable for a new plugin.\n\x09 * @param PluginName The proposed plugin name.\n\x09 * @param RelativePluginLocation Parent directory for the new plugin relative to template's default location.\n\x09 *     This should be empty unless you wish to specify a subdirectory.\n\x09 * @param bPlaceInEngine Use Engine Plugins directory rather than Game Plugins directory location.\n\x09 *     Only some Templates allow placing in Engine. See the TemplateInfo's bCanBePlacedInEngine.\n\x09 *     This should be false unless explicitly requested by the user.\n\x09 * @param TemplateInfo The plugin template to potentially create from.\n\x09 * @return True if the name and location are valid.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Validates that PluginName and RelativePluginLocation are acceptable for a new plugin.\n@param PluginName The proposed plugin name.\n@param RelativePluginLocation Parent directory for the new plugin relative to template's default location.\n    This should be empty unless you wish to specify a subdirectory.\n@param bPlaceInEngine Use Engine Plugins directory rather than Game Plugins directory location.\n    Only some Templates allow placing in Engine. See the TemplateInfo's bCanBePlacedInEngine.\n    This should be false unless explicitly requested by the user.\n@param TemplateInfo The plugin template to potentially create from.\n@return True if the name and location are valid." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RelativePluginLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPlaceInEngine_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TemplateInfo_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ValidateNewPluginNameAndLocation constinit property declarations ******
	static const UECodeGen_Private::FStrPropertyParams NewProp_PluginName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_RelativePluginLocation;
	static void NewProp_bPlaceInEngine_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPlaceInEngine;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TemplateInfo;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ValidateNewPluginNameAndLocation constinit property declarations ********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ValidateNewPluginNameAndLocation Property Definitions *****************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPluginToolset_ValidateNewPluginNameAndLocation_Statics::NewProp_PluginName = { "PluginName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PluginToolset_eventValidateNewPluginNameAndLocation_Parms, PluginName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PluginName_MetaData), NewProp_PluginName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPluginToolset_ValidateNewPluginNameAndLocation_Statics::NewProp_RelativePluginLocation = { "RelativePluginLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PluginToolset_eventValidateNewPluginNameAndLocation_Parms, RelativePluginLocation), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RelativePluginLocation_MetaData), NewProp_RelativePluginLocation_MetaData) };
void Z_Construct_UFunction_UPluginToolset_ValidateNewPluginNameAndLocation_Statics::NewProp_bPlaceInEngine_SetBit(void* Obj)
{
	((PluginToolset_eventValidateNewPluginNameAndLocation_Parms*)Obj)->bPlaceInEngine = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPluginToolset_ValidateNewPluginNameAndLocation_Statics::NewProp_bPlaceInEngine = { "bPlaceInEngine", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PluginToolset_eventValidateNewPluginNameAndLocation_Parms), &Z_Construct_UFunction_UPluginToolset_ValidateNewPluginNameAndLocation_Statics::NewProp_bPlaceInEngine_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPlaceInEngine_MetaData), NewProp_bPlaceInEngine_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPluginToolset_ValidateNewPluginNameAndLocation_Statics::NewProp_TemplateInfo = { "TemplateInfo", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PluginToolset_eventValidateNewPluginNameAndLocation_Parms, TemplateInfo), Z_Construct_UScriptStruct_FPluginTemplateDescriptionToolsetInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TemplateInfo_MetaData), NewProp_TemplateInfo_MetaData) }; // 4229272450
void Z_Construct_UFunction_UPluginToolset_ValidateNewPluginNameAndLocation_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PluginToolset_eventValidateNewPluginNameAndLocation_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPluginToolset_ValidateNewPluginNameAndLocation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PluginToolset_eventValidateNewPluginNameAndLocation_Parms), &Z_Construct_UFunction_UPluginToolset_ValidateNewPluginNameAndLocation_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPluginToolset_ValidateNewPluginNameAndLocation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_ValidateNewPluginNameAndLocation_Statics::NewProp_PluginName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_ValidateNewPluginNameAndLocation_Statics::NewProp_RelativePluginLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_ValidateNewPluginNameAndLocation_Statics::NewProp_bPlaceInEngine,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_ValidateNewPluginNameAndLocation_Statics::NewProp_TemplateInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPluginToolset_ValidateNewPluginNameAndLocation_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_ValidateNewPluginNameAndLocation_Statics::PropPointers) < 2048);
// ********** End Function ValidateNewPluginNameAndLocation Property Definitions *******************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPluginToolset_ValidateNewPluginNameAndLocation_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPluginToolset, nullptr, "ValidateNewPluginNameAndLocation", 	Z_Construct_UFunction_UPluginToolset_ValidateNewPluginNameAndLocation_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_ValidateNewPluginNameAndLocation_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPluginToolset_ValidateNewPluginNameAndLocation_Statics::PluginToolset_eventValidateNewPluginNameAndLocation_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPluginToolset_ValidateNewPluginNameAndLocation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPluginToolset_ValidateNewPluginNameAndLocation_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPluginToolset_ValidateNewPluginNameAndLocation_Statics::PluginToolset_eventValidateNewPluginNameAndLocation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPluginToolset_ValidateNewPluginNameAndLocation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPluginToolset_ValidateNewPluginNameAndLocation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPluginToolset::execValidateNewPluginNameAndLocation)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_PluginName);
	P_GET_PROPERTY(FStrProperty,Z_Param_RelativePluginLocation);
	P_GET_UBOOL(Z_Param_bPlaceInEngine);
	P_GET_STRUCT_REF(FPluginTemplateDescriptionToolsetInfo,Z_Param_Out_TemplateInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPluginToolset::ValidateNewPluginNameAndLocation(Z_Param_PluginName,Z_Param_RelativePluginLocation,Z_Param_bPlaceInEngine,Z_Param_Out_TemplateInfo);
	P_NATIVE_END;
}
// ********** End Class UPluginToolset Function ValidateNewPluginNameAndLocation *******************

// ********** Begin Class UPluginToolset ***********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UPluginToolset;
UClass* UPluginToolset::GetPrivateStaticClass()
{
	using TClass = UPluginToolset;
	if (!Z_Registration_Info_UClass_UPluginToolset.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("PluginToolset"),
			Z_Registration_Info_UClass_UPluginToolset.InnerSingleton,
			StaticRegisterNativesUPluginToolset,
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
	return Z_Registration_Info_UClass_UPluginToolset.InnerSingleton;
}
UClass* Z_Construct_UClass_UPluginToolset_NoRegister()
{
	return UPluginToolset::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPluginToolset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Tools for creating, editing, enabling, and querying Unreal plugins\n" },
#endif
		{ "IncludePath", "PluginToolset.h" },
		{ "ModuleRelativePath", "Private/PluginToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Tools for creating, editing, enabling, and querying Unreal plugins" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UPluginToolset constinit property declarations ***************************
// ********** End Class UPluginToolset constinit property declarations *****************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AddPluginDependency"), .Pointer = &UPluginToolset::execAddPluginDependency },
		{ .NameUTF8 = UTF8TEXT("CreatePlugin"), .Pointer = &UPluginToolset::execCreatePlugin },
		{ .NameUTF8 = UTF8TEXT("GetPluginDependencies"), .Pointer = &UPluginToolset::execGetPluginDependencies },
		{ .NameUTF8 = UTF8TEXT("GetPluginDependents"), .Pointer = &UPluginToolset::execGetPluginDependents },
		{ .NameUTF8 = UTF8TEXT("GetPluginDescriptor"), .Pointer = &UPluginToolset::execGetPluginDescriptor },
		{ .NameUTF8 = UTF8TEXT("GetPluginForAsset"), .Pointer = &UPluginToolset::execGetPluginForAsset },
		{ .NameUTF8 = UTF8TEXT("GetPluginInfo"), .Pointer = &UPluginToolset::execGetPluginInfo },
		{ .NameUTF8 = UTF8TEXT("GetPluginTemplateDescriptions"), .Pointer = &UPluginToolset::execGetPluginTemplateDescriptions },
		{ .NameUTF8 = UTF8TEXT("IsEnabled"), .Pointer = &UPluginToolset::execIsEnabled },
		{ .NameUTF8 = UTF8TEXT("IsPluginCreationAllowed"), .Pointer = &UPluginToolset::execIsPluginCreationAllowed },
		{ .NameUTF8 = UTF8TEXT("IsPluginModificationAllowed"), .Pointer = &UPluginToolset::execIsPluginModificationAllowed },
		{ .NameUTF8 = UTF8TEXT("ListDiscoveredPlugins"), .Pointer = &UPluginToolset::execListDiscoveredPlugins },
		{ .NameUTF8 = UTF8TEXT("ListEnabledPlugins"), .Pointer = &UPluginToolset::execListEnabledPlugins },
		{ .NameUTF8 = UTF8TEXT("RemovePluginDependency"), .Pointer = &UPluginToolset::execRemovePluginDependency },
		{ .NameUTF8 = UTF8TEXT("SetPluginEnabled"), .Pointer = &UPluginToolset::execSetPluginEnabled },
		{ .NameUTF8 = UTF8TEXT("UpdatePluginDescriptor"), .Pointer = &UPluginToolset::execUpdatePluginDescriptor },
		{ .NameUTF8 = UTF8TEXT("ValidateNewPluginNameAndLocation"), .Pointer = &UPluginToolset::execValidateNewPluginNameAndLocation },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UPluginToolset_AddPluginDependency, "AddPluginDependency" }, // 2016608530
		{ &Z_Construct_UFunction_UPluginToolset_CreatePlugin, "CreatePlugin" }, // 3994550045
		{ &Z_Construct_UFunction_UPluginToolset_GetPluginDependencies, "GetPluginDependencies" }, // 3941556647
		{ &Z_Construct_UFunction_UPluginToolset_GetPluginDependents, "GetPluginDependents" }, // 3316779928
		{ &Z_Construct_UFunction_UPluginToolset_GetPluginDescriptor, "GetPluginDescriptor" }, // 2877661758
		{ &Z_Construct_UFunction_UPluginToolset_GetPluginForAsset, "GetPluginForAsset" }, // 107364174
		{ &Z_Construct_UFunction_UPluginToolset_GetPluginInfo, "GetPluginInfo" }, // 1907809132
		{ &Z_Construct_UFunction_UPluginToolset_GetPluginTemplateDescriptions, "GetPluginTemplateDescriptions" }, // 4128476318
		{ &Z_Construct_UFunction_UPluginToolset_IsEnabled, "IsEnabled" }, // 1319596658
		{ &Z_Construct_UFunction_UPluginToolset_IsPluginCreationAllowed, "IsPluginCreationAllowed" }, // 849519465
		{ &Z_Construct_UFunction_UPluginToolset_IsPluginModificationAllowed, "IsPluginModificationAllowed" }, // 419545058
		{ &Z_Construct_UFunction_UPluginToolset_ListDiscoveredPlugins, "ListDiscoveredPlugins" }, // 4213062637
		{ &Z_Construct_UFunction_UPluginToolset_ListEnabledPlugins, "ListEnabledPlugins" }, // 3743548263
		{ &Z_Construct_UFunction_UPluginToolset_RemovePluginDependency, "RemovePluginDependency" }, // 1180652421
		{ &Z_Construct_UFunction_UPluginToolset_SetPluginEnabled, "SetPluginEnabled" }, // 3369316121
		{ &Z_Construct_UFunction_UPluginToolset_UpdatePluginDescriptor, "UpdatePluginDescriptor" }, // 1325551714
		{ &Z_Construct_UFunction_UPluginToolset_ValidateNewPluginNameAndLocation, "ValidateNewPluginNameAndLocation" }, // 2607163653
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPluginToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UPluginToolset_Statics
UObject* (*const Z_Construct_UClass_UPluginToolset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UToolsetDefinition,
	(UObject* (*)())Z_Construct_UPackage__Script_PluginToolset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPluginToolset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPluginToolset_Statics::ClassParams = {
	&UPluginToolset::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPluginToolset_Statics::Class_MetaDataParams), Z_Construct_UClass_UPluginToolset_Statics::Class_MetaDataParams)
};
void UPluginToolset::StaticRegisterNativesUPluginToolset()
{
	UClass* Class = UPluginToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UPluginToolset_Statics::Funcs));
}
UClass* Z_Construct_UClass_UPluginToolset()
{
	if (!Z_Registration_Info_UClass_UPluginToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPluginToolset.OuterSingleton, Z_Construct_UClass_UPluginToolset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPluginToolset.OuterSingleton;
}
UPluginToolset::UPluginToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UPluginToolset);
UPluginToolset::~UPluginToolset() {}
// ********** End Class UPluginToolset *************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PluginToolset_Source_PluginToolset_Private_PluginToolset_h__Script_PluginToolset_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FPluginDescriptorToolsetInfo::StaticStruct, Z_Construct_UScriptStruct_FPluginDescriptorToolsetInfo_Statics::NewStructOps, TEXT("PluginDescriptorToolsetInfo"),&Z_Registration_Info_UScriptStruct_FPluginDescriptorToolsetInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPluginDescriptorToolsetInfo), 2496262418U) },
		{ FPluginToolsetInfo::StaticStruct, Z_Construct_UScriptStruct_FPluginToolsetInfo_Statics::NewStructOps, TEXT("PluginToolsetInfo"),&Z_Registration_Info_UScriptStruct_FPluginToolsetInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPluginToolsetInfo), 899329902U) },
		{ FPluginDependencyToolsetInfo::StaticStruct, Z_Construct_UScriptStruct_FPluginDependencyToolsetInfo_Statics::NewStructOps, TEXT("PluginDependencyToolsetInfo"),&Z_Registration_Info_UScriptStruct_FPluginDependencyToolsetInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPluginDependencyToolsetInfo), 1823409718U) },
		{ FPluginTemplateDescriptionToolsetInfo::StaticStruct, Z_Construct_UScriptStruct_FPluginTemplateDescriptionToolsetInfo_Statics::NewStructOps, TEXT("PluginTemplateDescriptionToolsetInfo"),&Z_Registration_Info_UScriptStruct_FPluginTemplateDescriptionToolsetInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPluginTemplateDescriptionToolsetInfo), 4229272450U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPluginToolset, UPluginToolset::StaticClass, TEXT("UPluginToolset"), &Z_Registration_Info_UClass_UPluginToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPluginToolset), 727141804U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PluginToolset_Source_PluginToolset_Private_PluginToolset_h__Script_PluginToolset_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PluginToolset_Source_PluginToolset_Private_PluginToolset_h__Script_PluginToolset_3936112340{
	TEXT("/Script/PluginToolset"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PluginToolset_Source_PluginToolset_Private_PluginToolset_h__Script_PluginToolset_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PluginToolset_Source_PluginToolset_Private_PluginToolset_h__Script_PluginToolset_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PluginToolset_Source_PluginToolset_Private_PluginToolset_h__Script_PluginToolset_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PluginToolset_Source_PluginToolset_Private_PluginToolset_h__Script_PluginToolset_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
