// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Data/MountPointInfo.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeMountPointInfo() {}

// ********** Begin Cross Module References ********************************************************
FILESANDBOXCORE_API UScriptStruct* Z_Construct_UScriptStruct_FFileSandboxCore_MountPoint();
FILESANDBOXCORE_API UScriptStruct* Z_Construct_UScriptStruct_FFileSandboxCore_MountPointsInfo();
UPackage* Z_Construct_UPackage__Script_FileSandboxCore();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FFileSandboxCore_MountPoint ***************************************
struct Z_Construct_UScriptStruct_FFileSandboxCore_MountPoint_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FFileSandboxCore_MountPoint); }
	static inline consteval int16 GetStructAlignment() { return alignof(FFileSandboxCore_MountPoint); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Describes a single mount point. */" },
#endif
		{ "ModuleRelativePath", "Private/Data/MountPointInfo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Describes a single mount point." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MountName_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Logical name of the mount point, e.g. \"/Game/\" */" },
#endif
		{ "ModuleRelativePath", "Private/Data/MountPointInfo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Logical name of the mount point, e.g. \"/Game/\"" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RootPath_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Absolute path to the root of the mount point. e.g. \"C:/MyProject/Content\" */" },
#endif
		{ "ModuleRelativePath", "Private/Data/MountPointInfo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Absolute path to the root of the mount point. e.g. \"C:/MyProject/Content\"" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FFileSandboxCore_MountPoint constinit property declarations *******
	static const UECodeGen_Private::FStrPropertyParams NewProp_MountName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_RootPath;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FFileSandboxCore_MountPoint constinit property declarations *********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFileSandboxCore_MountPoint>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FFileSandboxCore_MountPoint_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FFileSandboxCore_MountPoint;
class UScriptStruct* FFileSandboxCore_MountPoint::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FFileSandboxCore_MountPoint.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FFileSandboxCore_MountPoint.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FFileSandboxCore_MountPoint, (UObject*)Z_Construct_UPackage__Script_FileSandboxCore(), TEXT("FileSandboxCore_MountPoint"));
	}
	return Z_Registration_Info_UScriptStruct_FFileSandboxCore_MountPoint.OuterSingleton;
	}

// ********** Begin ScriptStruct FFileSandboxCore_MountPoint Property Definitions ******************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_MountPoint_Statics::NewProp_MountName = { "MountName", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFileSandboxCore_MountPoint, MountName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MountName_MetaData), NewProp_MountName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_MountPoint_Statics::NewProp_RootPath = { "RootPath", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFileSandboxCore_MountPoint, RootPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RootPath_MetaData), NewProp_RootPath_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FFileSandboxCore_MountPoint_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_MountPoint_Statics::NewProp_MountName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_MountPoint_Statics::NewProp_RootPath,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_MountPoint_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FFileSandboxCore_MountPoint Property Definitions ********************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFileSandboxCore_MountPoint_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_FileSandboxCore,
	nullptr,
	&NewStructOps,
	"FileSandboxCore_MountPoint",
	Z_Construct_UScriptStruct_FFileSandboxCore_MountPoint_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_MountPoint_Statics::PropPointers),
	sizeof(FFileSandboxCore_MountPoint),
	alignof(FFileSandboxCore_MountPoint),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_MountPoint_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FFileSandboxCore_MountPoint_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FFileSandboxCore_MountPoint()
{
	if (!Z_Registration_Info_UScriptStruct_FFileSandboxCore_MountPoint.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FFileSandboxCore_MountPoint.InnerSingleton, Z_Construct_UScriptStruct_FFileSandboxCore_MountPoint_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FFileSandboxCore_MountPoint.InnerSingleton);
}
// ********** End ScriptStruct FFileSandboxCore_MountPoint *****************************************

// ********** Begin ScriptStruct FFileSandboxCore_MountPointsInfo **********************************
struct Z_Construct_UScriptStruct_FFileSandboxCore_MountPointsInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FFileSandboxCore_MountPointsInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FFileSandboxCore_MountPointsInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Holds mount points the engine has. */" },
#endif
		{ "ModuleRelativePath", "Private/Data/MountPointInfo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Holds mount points the engine has." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MountPoints_MetaData[] = {
		{ "ModuleRelativePath", "Private/Data/MountPointInfo.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FFileSandboxCore_MountPointsInfo constinit property declarations **
	static const UECodeGen_Private::FStructPropertyParams NewProp_MountPoints_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_MountPoints;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FFileSandboxCore_MountPointsInfo constinit property declarations ****
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFileSandboxCore_MountPointsInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FFileSandboxCore_MountPointsInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FFileSandboxCore_MountPointsInfo;
class UScriptStruct* FFileSandboxCore_MountPointsInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FFileSandboxCore_MountPointsInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FFileSandboxCore_MountPointsInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FFileSandboxCore_MountPointsInfo, (UObject*)Z_Construct_UPackage__Script_FileSandboxCore(), TEXT("FileSandboxCore_MountPointsInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FFileSandboxCore_MountPointsInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FFileSandboxCore_MountPointsInfo Property Definitions *************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_MountPointsInfo_Statics::NewProp_MountPoints_Inner = { "MountPoints", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FFileSandboxCore_MountPoint, METADATA_PARAMS(0, nullptr) }; // 4013324363
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_MountPointsInfo_Statics::NewProp_MountPoints = { "MountPoints", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFileSandboxCore_MountPointsInfo, MountPoints), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MountPoints_MetaData), NewProp_MountPoints_MetaData) }; // 4013324363
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FFileSandboxCore_MountPointsInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_MountPointsInfo_Statics::NewProp_MountPoints_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_MountPointsInfo_Statics::NewProp_MountPoints,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_MountPointsInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FFileSandboxCore_MountPointsInfo Property Definitions ***************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFileSandboxCore_MountPointsInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_FileSandboxCore,
	nullptr,
	&NewStructOps,
	"FileSandboxCore_MountPointsInfo",
	Z_Construct_UScriptStruct_FFileSandboxCore_MountPointsInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_MountPointsInfo_Statics::PropPointers),
	sizeof(FFileSandboxCore_MountPointsInfo),
	alignof(FFileSandboxCore_MountPointsInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_MountPointsInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FFileSandboxCore_MountPointsInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FFileSandboxCore_MountPointsInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FFileSandboxCore_MountPointsInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FFileSandboxCore_MountPointsInfo.InnerSingleton, Z_Construct_UScriptStruct_FFileSandboxCore_MountPointsInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FFileSandboxCore_MountPointsInfo.InnerSingleton);
}
// ********** End ScriptStruct FFileSandboxCore_MountPointsInfo ************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Private_Data_MountPointInfo_h__Script_FileSandboxCore_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FFileSandboxCore_MountPoint::StaticStruct, Z_Construct_UScriptStruct_FFileSandboxCore_MountPoint_Statics::NewStructOps, TEXT("FileSandboxCore_MountPoint"),&Z_Registration_Info_UScriptStruct_FFileSandboxCore_MountPoint, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FFileSandboxCore_MountPoint), 4013324363U) },
		{ FFileSandboxCore_MountPointsInfo::StaticStruct, Z_Construct_UScriptStruct_FFileSandboxCore_MountPointsInfo_Statics::NewStructOps, TEXT("FileSandboxCore_MountPointsInfo"),&Z_Registration_Info_UScriptStruct_FFileSandboxCore_MountPointsInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FFileSandboxCore_MountPointsInfo), 1940577762U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Private_Data_MountPointInfo_h__Script_FileSandboxCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Private_Data_MountPointInfo_h__Script_FileSandboxCore_852872769{
	TEXT("/Script/FileSandboxCore"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Private_Data_MountPointInfo_h__Script_FileSandboxCore_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Private_Data_MountPointInfo_h__Script_FileSandboxCore_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
