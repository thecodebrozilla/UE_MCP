// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Data/ManifestData.h"
#include "Data/AbsoluteFilePathArray.h"
#include "Data/MountPointInfo.h"
#include "Data/TimedAbsoluteFilePathArray.h"
#include "Data/VersionInfo.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeManifestData() {}

// ********** Begin Cross Module References ********************************************************
FILESANDBOXCORE_API UScriptStruct* Z_Construct_UScriptStruct_FFileSandboxCore_AbsoluteFilePathArray();
FILESANDBOXCORE_API UScriptStruct* Z_Construct_UScriptStruct_FFileSandboxCore_ManifestData();
FILESANDBOXCORE_API UScriptStruct* Z_Construct_UScriptStruct_FFileSandboxCore_MountPointsInfo();
FILESANDBOXCORE_API UScriptStruct* Z_Construct_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray();
FILESANDBOXCORE_API UScriptStruct* Z_Construct_UScriptStruct_FFileSandboxCore_VersionInfo();
UPackage* Z_Construct_UPackage__Script_FileSandboxCore();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FFileSandboxCore_ManifestData *************************************
struct Z_Construct_UScriptStruct_FFileSandboxCore_ManifestData_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FFileSandboxCore_ManifestData); }
	static inline consteval int16 GetStructAlignment() { return alignof(FFileSandboxCore_ManifestData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \n * Internal bookkeeping data for the sandbox logic.\n * This data is owned by the sandbox system and should not be directly modified via public API.\n */" },
#endif
		{ "ModuleRelativePath", "Private/Data/ManifestData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Internal bookkeeping data for the sandbox logic.\nThis data is owned by the sandbox system and should not be directly modified via public API." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeletedFiles_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Absolute non-sandbox paths to files deleted in sandbox. \n\x09 * Also saved the timestamp of the remove operation.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/Data/ManifestData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Absolute non-sandbox paths to files deleted in sandbox.\nAlso saved the timestamp of the remove operation." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ModifiedFiles_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Absolute non-sandbox paths to files modified in sandbox. */" },
#endif
		{ "ModuleRelativePath", "Private/Data/ManifestData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Absolute non-sandbox paths to files modified in sandbox." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AddedFiles_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Absolute non-sandbox paths to files added in sandbox. */" },
#endif
		{ "ModuleRelativePath", "Private/Data/ManifestData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Absolute non-sandbox paths to files added in sandbox." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VersionInfo_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Version info when this sandbox was created.\n\x09 * Holds info about the file version, engine version, and custom versions (for FArchives).\n\x09 * \n\x09 * This information is saved in the manifest to minimize the risk of API users directly editing and corrupting it.\n\x09 * It could also have been saved in the metadata file but that has API for mutating it (= risk of corruption / mutation via API).\n\x09 * \n\x09 * May be needed to parse the content in FFileSandboxCore_SandboxMetaData. \n\x09 * TODO UE-350242: This information can also be used to reject loading a sandbox with newer version info than the current engine version.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/Data/ManifestData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Version info when this sandbox was created.\nHolds info about the file version, engine version, and custom versions (for FArchives).\n\nThis information is saved in the manifest to minimize the risk of API users directly editing and corrupting it.\nIt could also have been saved in the metadata file but that has API for mutating it (= risk of corruption / mutation via API).\n\nMay be needed to parse the content in FFileSandboxCore_SandboxMetaData.\nTODO UE-350242: This information can also be used to reject loading a sandbox with newer version info than the current engine version." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MountPoints_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * The mount points that were referenced by either DeletedFiles, ModifiedFiles, or AddedFiles when the manifest was last saved.\n\x09 * This information is used to migrate file paths when a sandbox instance is created in case a mount point location changes, e.g. when importing\n\x09 * a sandbox or if the user changes the location of the underlying uproject.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/Data/ManifestData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The mount points that were referenced by either DeletedFiles, ModifiedFiles, or AddedFiles when the manifest was last saved.\nThis information is used to migrate file paths when a sandbox instance is created in case a mount point location changes, e.g. when importing\na sandbox or if the user changes the location of the underlying uproject." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FFileSandboxCore_ManifestData constinit property declarations *****
	static const UECodeGen_Private::FStructPropertyParams NewProp_DeletedFiles;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ModifiedFiles;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AddedFiles;
	static const UECodeGen_Private::FStructPropertyParams NewProp_VersionInfo;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MountPoints;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FFileSandboxCore_ManifestData constinit property declarations *******
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFileSandboxCore_ManifestData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FFileSandboxCore_ManifestData_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FFileSandboxCore_ManifestData;
class UScriptStruct* FFileSandboxCore_ManifestData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FFileSandboxCore_ManifestData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FFileSandboxCore_ManifestData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FFileSandboxCore_ManifestData, (UObject*)Z_Construct_UPackage__Script_FileSandboxCore(), TEXT("FileSandboxCore_ManifestData"));
	}
	return Z_Registration_Info_UScriptStruct_FFileSandboxCore_ManifestData.OuterSingleton;
	}

// ********** Begin ScriptStruct FFileSandboxCore_ManifestData Property Definitions ****************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_ManifestData_Statics::NewProp_DeletedFiles = { "DeletedFiles", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFileSandboxCore_ManifestData, DeletedFiles), Z_Construct_UScriptStruct_FFileSandboxCore_TimedAbsoluteFilePathArray, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeletedFiles_MetaData), NewProp_DeletedFiles_MetaData) }; // 3450424683
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_ManifestData_Statics::NewProp_ModifiedFiles = { "ModifiedFiles", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFileSandboxCore_ManifestData, ModifiedFiles), Z_Construct_UScriptStruct_FFileSandboxCore_AbsoluteFilePathArray, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ModifiedFiles_MetaData), NewProp_ModifiedFiles_MetaData) }; // 1892007055
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_ManifestData_Statics::NewProp_AddedFiles = { "AddedFiles", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFileSandboxCore_ManifestData, AddedFiles), Z_Construct_UScriptStruct_FFileSandboxCore_AbsoluteFilePathArray, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AddedFiles_MetaData), NewProp_AddedFiles_MetaData) }; // 1892007055
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_ManifestData_Statics::NewProp_VersionInfo = { "VersionInfo", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFileSandboxCore_ManifestData, VersionInfo), Z_Construct_UScriptStruct_FFileSandboxCore_VersionInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VersionInfo_MetaData), NewProp_VersionInfo_MetaData) }; // 3815150898
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FFileSandboxCore_ManifestData_Statics::NewProp_MountPoints = { "MountPoints", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFileSandboxCore_ManifestData, MountPoints), Z_Construct_UScriptStruct_FFileSandboxCore_MountPointsInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MountPoints_MetaData), NewProp_MountPoints_MetaData) }; // 1940577762
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FFileSandboxCore_ManifestData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_ManifestData_Statics::NewProp_DeletedFiles,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_ManifestData_Statics::NewProp_ModifiedFiles,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_ManifestData_Statics::NewProp_AddedFiles,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_ManifestData_Statics::NewProp_VersionInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileSandboxCore_ManifestData_Statics::NewProp_MountPoints,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_ManifestData_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FFileSandboxCore_ManifestData Property Definitions ******************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFileSandboxCore_ManifestData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_FileSandboxCore,
	nullptr,
	&NewStructOps,
	"FileSandboxCore_ManifestData",
	Z_Construct_UScriptStruct_FFileSandboxCore_ManifestData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_ManifestData_Statics::PropPointers),
	sizeof(FFileSandboxCore_ManifestData),
	alignof(FFileSandboxCore_ManifestData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileSandboxCore_ManifestData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FFileSandboxCore_ManifestData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FFileSandboxCore_ManifestData()
{
	if (!Z_Registration_Info_UScriptStruct_FFileSandboxCore_ManifestData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FFileSandboxCore_ManifestData.InnerSingleton, Z_Construct_UScriptStruct_FFileSandboxCore_ManifestData_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FFileSandboxCore_ManifestData.InnerSingleton);
}
// ********** End ScriptStruct FFileSandboxCore_ManifestData ***************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Private_Data_ManifestData_h__Script_FileSandboxCore_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FFileSandboxCore_ManifestData::StaticStruct, Z_Construct_UScriptStruct_FFileSandboxCore_ManifestData_Statics::NewStructOps, TEXT("FileSandboxCore_ManifestData"),&Z_Registration_Info_UScriptStruct_FFileSandboxCore_ManifestData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FFileSandboxCore_ManifestData), 2171311537U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Private_Data_ManifestData_h__Script_FileSandboxCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Private_Data_ManifestData_h__Script_FileSandboxCore_2293965268{
	TEXT("/Script/FileSandboxCore"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Private_Data_ManifestData_h__Script_FileSandboxCore_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_FileSandbox_Source_FileSandboxCore_Private_Data_ManifestData_h__Script_FileSandboxCore_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
