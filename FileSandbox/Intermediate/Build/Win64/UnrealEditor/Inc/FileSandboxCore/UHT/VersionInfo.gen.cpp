// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Data/VersionInfo.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeVersionInfo() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
FILESANDBOXCORE_API UScriptStruct* Z_Construct_UScriptStruct_FFileSandboxCore_CustomVersionInfo();
FILESANDBOXCORE_API UScriptStruct* Z_Construct_UScriptStruct_FFileSandboxCore_EngineVersionInfo();
FILESANDBOXCORE_API UScriptStruct* Z_Construct_UScriptStruct_FFileSandboxCore_FileVersionInfo();
FILESANDBOXCORE_API UScriptStruct* Z_Construct_UScriptStruct_FFileSandboxCore_VersionInfo();
UPackage* Z_Construct_UPackage__Script_FileSandboxCore();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FFileSandboxCore_FileVersionInfo **********************************
struct Z_Construct_UScriptStruct_FFileSandboxCore_FileVersionInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FFileSandboxCore_FileVersionInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FFileSandboxCore_FileVersionInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Holds file version information */" },
#endif
		{ "ModuleRelativePath", "Public/Data/VersionInfo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Holds file version information" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FileVersionUE5_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* UE5 File version */" },
#endif
		{ "ModuleRelativePath", "Public/Data/VersionInfo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UE5 File version" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FileVersionLicensee_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Licensee file version */" },
#endif
		{ "ModuleRelativePath", "Public/Data/VersionInfo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Licensee file version" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FFileSandboxCore_FileVersionInfo constinit property declarations **
	static const UECodeGen_Private::FIntPropertyParams NewProp_FileVersionUE5;
	static const UECodeGen_Private::FIntPropertyParams NewProp_FileVersionLicensee;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FFileSandboxCore_FileVersionInfo constinit property declarations ****
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFileSandboxCore_FileVersionInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FFileSandboxCore_FileVersionInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FFileSandboxCore_FileVersionInfo;
class UScriptStruct* FFileSandboxCore_FileVersionInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FFileSandboxCore_FileVersionInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FFileSandboxCore_FileVersionInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FFileSandboxCore_FileVersionInfo, (UObject*)Z_Construct_UPackage__Script_FileSandboxCore(), TEXT("FileSandboxCore_FileVersionInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FFileSandboxCore_FileVersionInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FFileSandboxCore_FileVersionInfo Property Definitions *************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_FileVersionInfo_Statics::NewProp_FileVersionUE5 = { "FileVersionUE5", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFileSandboxCore_FileVersionInfo, FileVersionUE5), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FileVersionUE5_MetaData), NewProp_FileVersionUE5_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_FileVersionInfo_Statics::NewProp_FileVersionLicensee = { "FileVersionLicensee", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFileSandboxCore_FileVersionInfo, FileVersionLicensee), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FileVersionLicensee_MetaData), NewProp_FileVersionLicensee_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FFileSandboxCore_FileVersionInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_FileVersionInfo_Statics::NewProp_FileVersionUE5,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_FileVersionInfo_Statics::NewProp_FileVersionLicensee,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_FileVersionInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FFileSandboxCore_FileVersionInfo Property Definitions ***************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFileSandboxCore_FileVersionInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_FileSandboxCore,
	nullptr,
	&NewStructOps,
	"FileSandboxCore_FileVersionInfo",
	Z_Construct_UScriptStruct_FFileSandboxCore_FileVersionInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_FileVersionInfo_Statics::PropPointers),
	sizeof(FFileSandboxCore_FileVersionInfo),
	alignof(FFileSandboxCore_FileVersionInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_FileVersionInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FFileSandboxCore_FileVersionInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FFileSandboxCore_FileVersionInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FFileSandboxCore_FileVersionInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FFileSandboxCore_FileVersionInfo.InnerSingleton, Z_Construct_UScriptStruct_FFileSandboxCore_FileVersionInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FFileSandboxCore_FileVersionInfo.InnerSingleton);
}
// ********** End ScriptStruct FFileSandboxCore_FileVersionInfo ************************************

// ********** Begin ScriptStruct FFileSandboxCore_EngineVersionInfo ********************************
struct Z_Construct_UScriptStruct_FFileSandboxCore_EngineVersionInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FFileSandboxCore_EngineVersionInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FFileSandboxCore_EngineVersionInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Holds engine version information */" },
#endif
		{ "ModuleRelativePath", "Public/Data/VersionInfo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Holds engine version information" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Major_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Major version number */" },
#endif
		{ "ModuleRelativePath", "Public/Data/VersionInfo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Major version number" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Minor_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Minor version number */" },
#endif
		{ "ModuleRelativePath", "Public/Data/VersionInfo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Minor version number" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Patch_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Patch version number */" },
#endif
		{ "ModuleRelativePath", "Public/Data/VersionInfo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Patch version number" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Changelist_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Changelist number. This is used to arbitrate when Major/Minor/Patch version numbers match */" },
#endif
		{ "ModuleRelativePath", "Public/Data/VersionInfo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Changelist number. This is used to arbitrate when Major/Minor/Patch version numbers match" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FFileSandboxCore_EngineVersionInfo constinit property declarations 
	static const UECodeGen_Private::FUInt16PropertyParams NewProp_Major;
	static const UECodeGen_Private::FUInt16PropertyParams NewProp_Minor;
	static const UECodeGen_Private::FUInt16PropertyParams NewProp_Patch;
	static const UECodeGen_Private::FUInt32PropertyParams NewProp_Changelist;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FFileSandboxCore_EngineVersionInfo constinit property declarations **
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFileSandboxCore_EngineVersionInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FFileSandboxCore_EngineVersionInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FFileSandboxCore_EngineVersionInfo;
class UScriptStruct* FFileSandboxCore_EngineVersionInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FFileSandboxCore_EngineVersionInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FFileSandboxCore_EngineVersionInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FFileSandboxCore_EngineVersionInfo, (UObject*)Z_Construct_UPackage__Script_FileSandboxCore(), TEXT("FileSandboxCore_EngineVersionInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FFileSandboxCore_EngineVersionInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FFileSandboxCore_EngineVersionInfo Property Definitions ***********
const UECodeGen_Private::FUInt16PropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_EngineVersionInfo_Statics::NewProp_Major = { "Major", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::UInt16, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFileSandboxCore_EngineVersionInfo, Major), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Major_MetaData), NewProp_Major_MetaData) };
const UECodeGen_Private::FUInt16PropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_EngineVersionInfo_Statics::NewProp_Minor = { "Minor", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::UInt16, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFileSandboxCore_EngineVersionInfo, Minor), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Minor_MetaData), NewProp_Minor_MetaData) };
const UECodeGen_Private::FUInt16PropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_EngineVersionInfo_Statics::NewProp_Patch = { "Patch", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::UInt16, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFileSandboxCore_EngineVersionInfo, Patch), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Patch_MetaData), NewProp_Patch_MetaData) };
const UECodeGen_Private::FUInt32PropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_EngineVersionInfo_Statics::NewProp_Changelist = { "Changelist", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFileSandboxCore_EngineVersionInfo, Changelist), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Changelist_MetaData), NewProp_Changelist_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FFileSandboxCore_EngineVersionInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_EngineVersionInfo_Statics::NewProp_Major,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_EngineVersionInfo_Statics::NewProp_Minor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_EngineVersionInfo_Statics::NewProp_Patch,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_EngineVersionInfo_Statics::NewProp_Changelist,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_EngineVersionInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FFileSandboxCore_EngineVersionInfo Property Definitions *************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFileSandboxCore_EngineVersionInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_FileSandboxCore,
	nullptr,
	&NewStructOps,
	"FileSandboxCore_EngineVersionInfo",
	Z_Construct_UScriptStruct_FFileSandboxCore_EngineVersionInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_EngineVersionInfo_Statics::PropPointers),
	sizeof(FFileSandboxCore_EngineVersionInfo),
	alignof(FFileSandboxCore_EngineVersionInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_EngineVersionInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FFileSandboxCore_EngineVersionInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FFileSandboxCore_EngineVersionInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FFileSandboxCore_EngineVersionInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FFileSandboxCore_EngineVersionInfo.InnerSingleton, Z_Construct_UScriptStruct_FFileSandboxCore_EngineVersionInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FFileSandboxCore_EngineVersionInfo.InnerSingleton);
}
// ********** End ScriptStruct FFileSandboxCore_EngineVersionInfo **********************************

// ********** Begin ScriptStruct FFileSandboxCore_CustomVersionInfo ********************************
struct Z_Construct_UScriptStruct_FFileSandboxCore_CustomVersionInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FFileSandboxCore_CustomVersionInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FFileSandboxCore_CustomVersionInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Holds custom version information */" },
#endif
		{ "ModuleRelativePath", "Public/Data/VersionInfo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Holds custom version information" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FriendlyName_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Friendly name of the version */" },
#endif
		{ "ModuleRelativePath", "Public/Data/VersionInfo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Friendly name of the version" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Key_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Unique custom key */" },
#endif
		{ "ModuleRelativePath", "Public/Data/VersionInfo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Unique custom key" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Version_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Custom version */" },
#endif
		{ "ModuleRelativePath", "Public/Data/VersionInfo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Custom version" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FFileSandboxCore_CustomVersionInfo constinit property declarations 
	static const UECodeGen_Private::FNamePropertyParams NewProp_FriendlyName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Key;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Version;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FFileSandboxCore_CustomVersionInfo constinit property declarations **
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFileSandboxCore_CustomVersionInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FFileSandboxCore_CustomVersionInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FFileSandboxCore_CustomVersionInfo;
class UScriptStruct* FFileSandboxCore_CustomVersionInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FFileSandboxCore_CustomVersionInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FFileSandboxCore_CustomVersionInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FFileSandboxCore_CustomVersionInfo, (UObject*)Z_Construct_UPackage__Script_FileSandboxCore(), TEXT("FileSandboxCore_CustomVersionInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FFileSandboxCore_CustomVersionInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FFileSandboxCore_CustomVersionInfo Property Definitions ***********
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_CustomVersionInfo_Statics::NewProp_FriendlyName = { "FriendlyName", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFileSandboxCore_CustomVersionInfo, FriendlyName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FriendlyName_MetaData), NewProp_FriendlyName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_CustomVersionInfo_Statics::NewProp_Key = { "Key", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFileSandboxCore_CustomVersionInfo, Key), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Key_MetaData), NewProp_Key_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_CustomVersionInfo_Statics::NewProp_Version = { "Version", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFileSandboxCore_CustomVersionInfo, Version), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Version_MetaData), NewProp_Version_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FFileSandboxCore_CustomVersionInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_CustomVersionInfo_Statics::NewProp_FriendlyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_CustomVersionInfo_Statics::NewProp_Key,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_CustomVersionInfo_Statics::NewProp_Version,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_CustomVersionInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FFileSandboxCore_CustomVersionInfo Property Definitions *************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFileSandboxCore_CustomVersionInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_FileSandboxCore,
	nullptr,
	&NewStructOps,
	"FileSandboxCore_CustomVersionInfo",
	Z_Construct_UScriptStruct_FFileSandboxCore_CustomVersionInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_CustomVersionInfo_Statics::PropPointers),
	sizeof(FFileSandboxCore_CustomVersionInfo),
	alignof(FFileSandboxCore_CustomVersionInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_CustomVersionInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FFileSandboxCore_CustomVersionInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FFileSandboxCore_CustomVersionInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FFileSandboxCore_CustomVersionInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FFileSandboxCore_CustomVersionInfo.InnerSingleton, Z_Construct_UScriptStruct_FFileSandboxCore_CustomVersionInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FFileSandboxCore_CustomVersionInfo.InnerSingleton);
}
// ********** End ScriptStruct FFileSandboxCore_CustomVersionInfo **********************************

// ********** Begin ScriptStruct FFileSandboxCore_VersionInfo **************************************
struct Z_Construct_UScriptStruct_FFileSandboxCore_VersionInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FFileSandboxCore_VersionInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FFileSandboxCore_VersionInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Holds version information for a session */" },
#endif
		{ "ModuleRelativePath", "Public/Data/VersionInfo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Holds version information for a session" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FileVersion_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** File version info */" },
#endif
		{ "ModuleRelativePath", "Public/Data/VersionInfo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "File version info" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EngineVersion_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Engine version info */" },
#endif
		{ "ModuleRelativePath", "Public/Data/VersionInfo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Engine version info" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CustomVersions_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Custom version info */" },
#endif
		{ "ModuleRelativePath", "Public/Data/VersionInfo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Custom version info" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FFileSandboxCore_VersionInfo constinit property declarations ******
	static const UECodeGen_Private::FStructPropertyParams NewProp_FileVersion;
	static const UECodeGen_Private::FStructPropertyParams NewProp_EngineVersion;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CustomVersions_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_CustomVersions;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FFileSandboxCore_VersionInfo constinit property declarations ********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFileSandboxCore_VersionInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FFileSandboxCore_VersionInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FFileSandboxCore_VersionInfo;
class UScriptStruct* FFileSandboxCore_VersionInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FFileSandboxCore_VersionInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FFileSandboxCore_VersionInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FFileSandboxCore_VersionInfo, (UObject*)Z_Construct_UPackage__Script_FileSandboxCore(), TEXT("FileSandboxCore_VersionInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FFileSandboxCore_VersionInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FFileSandboxCore_VersionInfo Property Definitions *****************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_VersionInfo_Statics::NewProp_FileVersion = { "FileVersion", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFileSandboxCore_VersionInfo, FileVersion), Z_Construct_UScriptStruct_FFileSandboxCore_FileVersionInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FileVersion_MetaData), NewProp_FileVersion_MetaData) }; // 847349978
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_VersionInfo_Statics::NewProp_EngineVersion = { "EngineVersion", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFileSandboxCore_VersionInfo, EngineVersion), Z_Construct_UScriptStruct_FFileSandboxCore_EngineVersionInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EngineVersion_MetaData), NewProp_EngineVersion_MetaData) }; // 3115176133
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_VersionInfo_Statics::NewProp_CustomVersions_Inner = { "CustomVersions", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FFileSandboxCore_CustomVersionInfo, METADATA_PARAMS(0, nullptr) }; // 1338540708
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_VersionInfo_Statics::NewProp_CustomVersions = { "CustomVersions", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFileSandboxCore_VersionInfo, CustomVersions), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CustomVersions_MetaData), NewProp_CustomVersions_MetaData) }; // 1338540708
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FFileSandboxCore_VersionInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_VersionInfo_Statics::NewProp_FileVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_VersionInfo_Statics::NewProp_EngineVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_VersionInfo_Statics::NewProp_CustomVersions_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_VersionInfo_Statics::NewProp_CustomVersions,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_VersionInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FFileSandboxCore_VersionInfo Property Definitions *******************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFileSandboxCore_VersionInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_FileSandboxCore,
	nullptr,
	&NewStructOps,
	"FileSandboxCore_VersionInfo",
	Z_Construct_UScriptStruct_FFileSandboxCore_VersionInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_VersionInfo_Statics::PropPointers),
	sizeof(FFileSandboxCore_VersionInfo),
	alignof(FFileSandboxCore_VersionInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_VersionInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FFileSandboxCore_VersionInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FFileSandboxCore_VersionInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FFileSandboxCore_VersionInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FFileSandboxCore_VersionInfo.InnerSingleton, Z_Construct_UScriptStruct_FFileSandboxCore_VersionInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FFileSandboxCore_VersionInfo.InnerSingleton);
}
// ********** End ScriptStruct FFileSandboxCore_VersionInfo ****************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Public_Data_VersionInfo_h__Script_FileSandboxCore_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FFileSandboxCore_FileVersionInfo::StaticStruct, Z_Construct_UScriptStruct_FFileSandboxCore_FileVersionInfo_Statics::NewStructOps, TEXT("FileSandboxCore_FileVersionInfo"),&Z_Registration_Info_UScriptStruct_FFileSandboxCore_FileVersionInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FFileSandboxCore_FileVersionInfo), 847349978U) },
		{ FFileSandboxCore_EngineVersionInfo::StaticStruct, Z_Construct_UScriptStruct_FFileSandboxCore_EngineVersionInfo_Statics::NewStructOps, TEXT("FileSandboxCore_EngineVersionInfo"),&Z_Registration_Info_UScriptStruct_FFileSandboxCore_EngineVersionInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FFileSandboxCore_EngineVersionInfo), 3115176133U) },
		{ FFileSandboxCore_CustomVersionInfo::StaticStruct, Z_Construct_UScriptStruct_FFileSandboxCore_CustomVersionInfo_Statics::NewStructOps, TEXT("FileSandboxCore_CustomVersionInfo"),&Z_Registration_Info_UScriptStruct_FFileSandboxCore_CustomVersionInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FFileSandboxCore_CustomVersionInfo), 1338540708U) },
		{ FFileSandboxCore_VersionInfo::StaticStruct, Z_Construct_UScriptStruct_FFileSandboxCore_VersionInfo_Statics::NewStructOps, TEXT("FileSandboxCore_VersionInfo"),&Z_Registration_Info_UScriptStruct_FFileSandboxCore_VersionInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FFileSandboxCore_VersionInfo), 3815150898U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Public_Data_VersionInfo_h__Script_FileSandboxCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Public_Data_VersionInfo_h__Script_FileSandboxCore_2997769722{
	TEXT("/Script/FileSandboxCore"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Public_Data_VersionInfo_h__Script_FileSandboxCore_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Public_Data_VersionInfo_h__Script_FileSandboxCore_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
