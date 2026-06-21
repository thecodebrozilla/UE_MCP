// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChaosClothAsset/ClothAssetToolset.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeClothAssetToolset() {}

// ********** Begin Cross Module References ********************************************************
CHAOSCLOTHASSETTOOLSET_API UClass* Z_Construct_UClass_UChaosClothAssetToolset();
CHAOSCLOTHASSETTOOLSET_API UClass* Z_Construct_UClass_UChaosClothAssetToolset_NoRegister();
CHAOSCLOTHASSETTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FClothingAssetInfo();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition();
UPackage* Z_Construct_UPackage__Script_ChaosClothAssetToolset();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FClothingAssetInfo ************************************************
struct Z_Construct_UScriptStruct_FClothingAssetInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FClothingAssetInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FClothingAssetInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Information about a clothing asset on a skeletal mesh, returned by ListClothingAssets.\n */" },
#endif
		{ "ModuleRelativePath", "Private/ChaosClothAsset/ClothAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Information about a clothing asset on a skeletal mesh, returned by ListClothingAssets." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AssetName_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Name of the clothing asset. Pass to AssignClothingToSection. */" },
#endif
		{ "ModuleRelativePath", "Private/ChaosClothAsset/ClothAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Name of the clothing asset. Pass to AssignClothingToSection." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRequiresMatchingLodIndex_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * If true, ClothingLodIndex passed to AssignClothingToSection must match the skeletal mesh\n\x09 * LodIndex. This is the case for ChaosClothAsset-derived types.\n\x09 * If false (UClothingAssetCommon), any value in [0, NumClothingLods-1] is valid.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/ChaosClothAsset/ClothAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If true, ClothingLodIndex passed to AssignClothingToSection must match the skeletal mesh\nLodIndex. This is the case for ChaosClothAsset-derived types.\nIf false (UClothingAssetCommon), any value in [0, NumClothingLods-1] is valid." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NumClothingLods_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Number of LODs available in this clothing asset.\n\x09 * Only relevant when bRequiresMatchingLodIndex is false.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/ChaosClothAsset/ClothAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Number of LODs available in this clothing asset.\nOnly relevant when bRequiresMatchingLodIndex is false." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FClothingAssetInfo constinit property declarations ****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AssetName;
	static void NewProp_bRequiresMatchingLodIndex_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRequiresMatchingLodIndex;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NumClothingLods;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FClothingAssetInfo constinit property declarations ******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FClothingAssetInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FClothingAssetInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FClothingAssetInfo;
class UScriptStruct* FClothingAssetInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FClothingAssetInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FClothingAssetInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FClothingAssetInfo, (UObject*)Z_Construct_UPackage__Script_ChaosClothAssetToolset(), TEXT("ClothingAssetInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FClothingAssetInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FClothingAssetInfo Property Definitions ***************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FClothingAssetInfo_Statics::NewProp_AssetName = { "AssetName", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClothingAssetInfo, AssetName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AssetName_MetaData), NewProp_AssetName_MetaData) };
void Z_Construct_UScriptStruct_FClothingAssetInfo_Statics::NewProp_bRequiresMatchingLodIndex_SetBit(void* Obj)
{
	((FClothingAssetInfo*)Obj)->bRequiresMatchingLodIndex = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FClothingAssetInfo_Statics::NewProp_bRequiresMatchingLodIndex = { "bRequiresMatchingLodIndex", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FClothingAssetInfo), &Z_Construct_UScriptStruct_FClothingAssetInfo_Statics::NewProp_bRequiresMatchingLodIndex_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRequiresMatchingLodIndex_MetaData), NewProp_bRequiresMatchingLodIndex_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FClothingAssetInfo_Statics::NewProp_NumClothingLods = { "NumClothingLods", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClothingAssetInfo, NumClothingLods), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NumClothingLods_MetaData), NewProp_NumClothingLods_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FClothingAssetInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClothingAssetInfo_Statics::NewProp_AssetName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClothingAssetInfo_Statics::NewProp_bRequiresMatchingLodIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClothingAssetInfo_Statics::NewProp_NumClothingLods,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClothingAssetInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FClothingAssetInfo Property Definitions *****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FClothingAssetInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ChaosClothAssetToolset,
	nullptr,
	&NewStructOps,
	"ClothingAssetInfo",
	Z_Construct_UScriptStruct_FClothingAssetInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClothingAssetInfo_Statics::PropPointers),
	sizeof(FClothingAssetInfo),
	alignof(FClothingAssetInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClothingAssetInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FClothingAssetInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FClothingAssetInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FClothingAssetInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FClothingAssetInfo.InnerSingleton, Z_Construct_UScriptStruct_FClothingAssetInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FClothingAssetInfo.InnerSingleton);
}
// ********** End ScriptStruct FClothingAssetInfo **************************************************

// ********** Begin Class UChaosClothAssetToolset Function AssignClothingToSection *****************
struct Z_Construct_UFunction_UChaosClothAssetToolset_AssignClothingToSection_Statics
{
	struct ChaosClothAssetToolset_eventAssignClothingToSection_Parms
	{
		FString SkeletalMeshPath;
		FString ClothingAssetName;
		int32 LodIndex;
		int32 SectionIndex;
		int32 ClothingLodIndex;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "ChaosClothAsset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Binds a clothing asset to a specific LOD and section on the skeletal mesh.\n\x09 * Mirrors the SkeletalMesh Editor's \"Apply Clothing Data\" action.\n\x09 * Any clothing already bound to the section is unbound first.\n\x09 * @param SkeletalMeshPath Object path to the target USkeletalMesh asset.\n\x09 * @param ClothingAssetName Name of the Clothing Asset on the mesh\n\x09 *    (e.g., from CreateClothingAsset or ListClothingAssets).\n\x09 * @param LodIndex Skeletal mesh LOD index to bind to.\n\x09 * @param SectionIndex Section index within the LOD to bind to.\n\x09 * @param ClothingLodIndex LOD index within the clothing asset to bind.\n\x09 *    For ChaosClothAsset-derived types (bRequiresMatchingLodIndex == true in ListClothingAssets),\n\x09 *    pass the same value as LodIndex. For UClothingAssetCommon, pass the desired clothing LOD\n\x09 *    (0 to NumClothingLods-1 as reported by ListClothingAssets).\n\x09 * @return True if the binding succeeded.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/ChaosClothAsset/ClothAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Binds a clothing asset to a specific LOD and section on the skeletal mesh.\nMirrors the SkeletalMesh Editor's \"Apply Clothing Data\" action.\nAny clothing already bound to the section is unbound first.\n@param SkeletalMeshPath Object path to the target USkeletalMesh asset.\n@param ClothingAssetName Name of the Clothing Asset on the mesh\n   (e.g., from CreateClothingAsset or ListClothingAssets).\n@param LodIndex Skeletal mesh LOD index to bind to.\n@param SectionIndex Section index within the LOD to bind to.\n@param ClothingLodIndex LOD index within the clothing asset to bind.\n   For ChaosClothAsset-derived types (bRequiresMatchingLodIndex == true in ListClothingAssets),\n   pass the same value as LodIndex. For UClothingAssetCommon, pass the desired clothing LOD\n   (0 to NumClothingLods-1 as reported by ListClothingAssets).\n@return True if the binding succeeded." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkeletalMeshPath_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClothingAssetName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AssignClothingToSection constinit property declarations ***************
	static const UECodeGen_Private::FStrPropertyParams NewProp_SkeletalMeshPath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ClothingAssetName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_LodIndex;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SectionIndex;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ClothingLodIndex;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AssignClothingToSection constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AssignClothingToSection Property Definitions **************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UChaosClothAssetToolset_AssignClothingToSection_Statics::NewProp_SkeletalMeshPath = { "SkeletalMeshPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChaosClothAssetToolset_eventAssignClothingToSection_Parms, SkeletalMeshPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkeletalMeshPath_MetaData), NewProp_SkeletalMeshPath_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UChaosClothAssetToolset_AssignClothingToSection_Statics::NewProp_ClothingAssetName = { "ClothingAssetName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChaosClothAssetToolset_eventAssignClothingToSection_Parms, ClothingAssetName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClothingAssetName_MetaData), NewProp_ClothingAssetName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UChaosClothAssetToolset_AssignClothingToSection_Statics::NewProp_LodIndex = { "LodIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChaosClothAssetToolset_eventAssignClothingToSection_Parms, LodIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UChaosClothAssetToolset_AssignClothingToSection_Statics::NewProp_SectionIndex = { "SectionIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChaosClothAssetToolset_eventAssignClothingToSection_Parms, SectionIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UChaosClothAssetToolset_AssignClothingToSection_Statics::NewProp_ClothingLodIndex = { "ClothingLodIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChaosClothAssetToolset_eventAssignClothingToSection_Parms, ClothingLodIndex), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UChaosClothAssetToolset_AssignClothingToSection_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ChaosClothAssetToolset_eventAssignClothingToSection_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UChaosClothAssetToolset_AssignClothingToSection_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ChaosClothAssetToolset_eventAssignClothingToSection_Parms), &Z_Construct_UFunction_UChaosClothAssetToolset_AssignClothingToSection_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChaosClothAssetToolset_AssignClothingToSection_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChaosClothAssetToolset_AssignClothingToSection_Statics::NewProp_SkeletalMeshPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChaosClothAssetToolset_AssignClothingToSection_Statics::NewProp_ClothingAssetName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChaosClothAssetToolset_AssignClothingToSection_Statics::NewProp_LodIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChaosClothAssetToolset_AssignClothingToSection_Statics::NewProp_SectionIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChaosClothAssetToolset_AssignClothingToSection_Statics::NewProp_ClothingLodIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChaosClothAssetToolset_AssignClothingToSection_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChaosClothAssetToolset_AssignClothingToSection_Statics::PropPointers) < 2048);
// ********** End Function AssignClothingToSection Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChaosClothAssetToolset_AssignClothingToSection_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChaosClothAssetToolset, nullptr, "AssignClothingToSection", 	Z_Construct_UFunction_UChaosClothAssetToolset_AssignClothingToSection_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UChaosClothAssetToolset_AssignClothingToSection_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UChaosClothAssetToolset_AssignClothingToSection_Statics::ChaosClothAssetToolset_eventAssignClothingToSection_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChaosClothAssetToolset_AssignClothingToSection_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChaosClothAssetToolset_AssignClothingToSection_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChaosClothAssetToolset_AssignClothingToSection_Statics::ChaosClothAssetToolset_eventAssignClothingToSection_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChaosClothAssetToolset_AssignClothingToSection()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChaosClothAssetToolset_AssignClothingToSection_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChaosClothAssetToolset::execAssignClothingToSection)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_SkeletalMeshPath);
	P_GET_PROPERTY(FStrProperty,Z_Param_ClothingAssetName);
	P_GET_PROPERTY(FIntProperty,Z_Param_LodIndex);
	P_GET_PROPERTY(FIntProperty,Z_Param_SectionIndex);
	P_GET_PROPERTY(FIntProperty,Z_Param_ClothingLodIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UChaosClothAssetToolset::AssignClothingToSection(Z_Param_SkeletalMeshPath,Z_Param_ClothingAssetName,Z_Param_LodIndex,Z_Param_SectionIndex,Z_Param_ClothingLodIndex);
	P_NATIVE_END;
}
// ********** End Class UChaosClothAssetToolset Function AssignClothingToSection *******************

// ********** Begin Class UChaosClothAssetToolset Function ConvertClothingAssetCommonToChaosClothAsset 
struct Z_Construct_UFunction_UChaosClothAssetToolset_ConvertClothingAssetCommonToChaosClothAsset_Statics
{
	struct ChaosClothAssetToolset_eventConvertClothingAssetCommonToChaosClothAsset_Parms
	{
		FString SkeletalMeshPath;
		FString ClothingAssetName;
		FString OutputPackagePath;
		FString AssetName;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "ChaosClothAsset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Converts a legacy UClothingAssetCommon (the cloth asset created via UChaosClothingSimulationFactory)\n\x09 * into a new UChaosClothAsset whose embedded Dataflow graph mirrors the legacy UChaosClothConfig and\n\x09 * UChaosClothSharedSimConfig values, with one WeightMap node per legacy weight map.\n\x09 * @param SkeletalMeshPath  Object path to the USkeletalMesh that owns the legacy clothing asset.\n\x09 * @param ClothingAssetName Name of the UClothingAssetCommon on the mesh (from ListClothingAssets).\n\x09 * @param OutputPackagePath Folder where the new asset should be created (e.g. \"/Game/Cloth/\").\n\x09 * @param AssetName         Name of the new asset; empty for default (\"CA_Converted_<source>\").\n\x09 * @return Object path of the new UChaosClothAsset; empty on failure.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/ChaosClothAsset/ClothAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Converts a legacy UClothingAssetCommon (the cloth asset created via UChaosClothingSimulationFactory)\ninto a new UChaosClothAsset whose embedded Dataflow graph mirrors the legacy UChaosClothConfig and\nUChaosClothSharedSimConfig values, with one WeightMap node per legacy weight map.\n@param SkeletalMeshPath  Object path to the USkeletalMesh that owns the legacy clothing asset.\n@param ClothingAssetName Name of the UClothingAssetCommon on the mesh (from ListClothingAssets).\n@param OutputPackagePath Folder where the new asset should be created (e.g. \"/Game/Cloth/\").\n@param AssetName         Name of the new asset; empty for default (\"CA_Converted_<source>\").\n@return Object path of the new UChaosClothAsset; empty on failure." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkeletalMeshPath_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClothingAssetName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutputPackagePath_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AssetName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ConvertClothingAssetCommonToChaosClothAsset constinit property declarations 
	static const UECodeGen_Private::FStrPropertyParams NewProp_SkeletalMeshPath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ClothingAssetName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OutputPackagePath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AssetName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ConvertClothingAssetCommonToChaosClothAsset constinit property declarations 
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ConvertClothingAssetCommonToChaosClothAsset Property Definitions ******
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UChaosClothAssetToolset_ConvertClothingAssetCommonToChaosClothAsset_Statics::NewProp_SkeletalMeshPath = { "SkeletalMeshPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChaosClothAssetToolset_eventConvertClothingAssetCommonToChaosClothAsset_Parms, SkeletalMeshPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkeletalMeshPath_MetaData), NewProp_SkeletalMeshPath_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UChaosClothAssetToolset_ConvertClothingAssetCommonToChaosClothAsset_Statics::NewProp_ClothingAssetName = { "ClothingAssetName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChaosClothAssetToolset_eventConvertClothingAssetCommonToChaosClothAsset_Parms, ClothingAssetName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClothingAssetName_MetaData), NewProp_ClothingAssetName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UChaosClothAssetToolset_ConvertClothingAssetCommonToChaosClothAsset_Statics::NewProp_OutputPackagePath = { "OutputPackagePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChaosClothAssetToolset_eventConvertClothingAssetCommonToChaosClothAsset_Parms, OutputPackagePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutputPackagePath_MetaData), NewProp_OutputPackagePath_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UChaosClothAssetToolset_ConvertClothingAssetCommonToChaosClothAsset_Statics::NewProp_AssetName = { "AssetName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChaosClothAssetToolset_eventConvertClothingAssetCommonToChaosClothAsset_Parms, AssetName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AssetName_MetaData), NewProp_AssetName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UChaosClothAssetToolset_ConvertClothingAssetCommonToChaosClothAsset_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChaosClothAssetToolset_eventConvertClothingAssetCommonToChaosClothAsset_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChaosClothAssetToolset_ConvertClothingAssetCommonToChaosClothAsset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChaosClothAssetToolset_ConvertClothingAssetCommonToChaosClothAsset_Statics::NewProp_SkeletalMeshPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChaosClothAssetToolset_ConvertClothingAssetCommonToChaosClothAsset_Statics::NewProp_ClothingAssetName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChaosClothAssetToolset_ConvertClothingAssetCommonToChaosClothAsset_Statics::NewProp_OutputPackagePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChaosClothAssetToolset_ConvertClothingAssetCommonToChaosClothAsset_Statics::NewProp_AssetName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChaosClothAssetToolset_ConvertClothingAssetCommonToChaosClothAsset_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChaosClothAssetToolset_ConvertClothingAssetCommonToChaosClothAsset_Statics::PropPointers) < 2048);
// ********** End Function ConvertClothingAssetCommonToChaosClothAsset Property Definitions ********
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChaosClothAssetToolset_ConvertClothingAssetCommonToChaosClothAsset_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChaosClothAssetToolset, nullptr, "ConvertClothingAssetCommonToChaosClothAsset", 	Z_Construct_UFunction_UChaosClothAssetToolset_ConvertClothingAssetCommonToChaosClothAsset_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UChaosClothAssetToolset_ConvertClothingAssetCommonToChaosClothAsset_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UChaosClothAssetToolset_ConvertClothingAssetCommonToChaosClothAsset_Statics::ChaosClothAssetToolset_eventConvertClothingAssetCommonToChaosClothAsset_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChaosClothAssetToolset_ConvertClothingAssetCommonToChaosClothAsset_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChaosClothAssetToolset_ConvertClothingAssetCommonToChaosClothAsset_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChaosClothAssetToolset_ConvertClothingAssetCommonToChaosClothAsset_Statics::ChaosClothAssetToolset_eventConvertClothingAssetCommonToChaosClothAsset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChaosClothAssetToolset_ConvertClothingAssetCommonToChaosClothAsset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChaosClothAssetToolset_ConvertClothingAssetCommonToChaosClothAsset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChaosClothAssetToolset::execConvertClothingAssetCommonToChaosClothAsset)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_SkeletalMeshPath);
	P_GET_PROPERTY(FStrProperty,Z_Param_ClothingAssetName);
	P_GET_PROPERTY(FStrProperty,Z_Param_OutputPackagePath);
	P_GET_PROPERTY(FStrProperty,Z_Param_AssetName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UChaosClothAssetToolset::ConvertClothingAssetCommonToChaosClothAsset(Z_Param_SkeletalMeshPath,Z_Param_ClothingAssetName,Z_Param_OutputPackagePath,Z_Param_AssetName);
	P_NATIVE_END;
}
// ********** End Class UChaosClothAssetToolset Function ConvertClothingAssetCommonToChaosClothAsset 

// ********** Begin Class UChaosClothAssetToolset Function CreateClothingAsset *********************
struct Z_Construct_UFunction_UChaosClothAssetToolset_CreateClothingAsset_Statics
{
	struct ChaosClothAssetToolset_eventCreateClothingAsset_Parms
	{
		FString SkeletalMeshPath;
		FString ChaosClothAssetPath;
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "ChaosClothAsset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Creates a UChaosClothAssetSKMClothingAsset from a Chaos Cloth/Outfit Asset and adds it\n\x09 * to the skeletal mesh's clothing asset array, making it available to assign to sections.\n\x09 * @param SkeletalMeshPath Object path to the target USkeletalMesh asset.\n\x09 * @param ChaosClothAssetPath Object path to the source UChaosClothAssetBase (cloth or outfit asset).\n\x09 * @return List of created clothing assets, or empty if failed.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/ChaosClothAsset/ClothAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Creates a UChaosClothAssetSKMClothingAsset from a Chaos Cloth/Outfit Asset and adds it\nto the skeletal mesh's clothing asset array, making it available to assign to sections.\n@param SkeletalMeshPath Object path to the target USkeletalMesh asset.\n@param ChaosClothAssetPath Object path to the source UChaosClothAssetBase (cloth or outfit asset).\n@return List of created clothing assets, or empty if failed." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkeletalMeshPath_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChaosClothAssetPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CreateClothingAsset constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_SkeletalMeshPath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ChaosClothAssetPath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CreateClothingAsset constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CreateClothingAsset Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UChaosClothAssetToolset_CreateClothingAsset_Statics::NewProp_SkeletalMeshPath = { "SkeletalMeshPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChaosClothAssetToolset_eventCreateClothingAsset_Parms, SkeletalMeshPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkeletalMeshPath_MetaData), NewProp_SkeletalMeshPath_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UChaosClothAssetToolset_CreateClothingAsset_Statics::NewProp_ChaosClothAssetPath = { "ChaosClothAssetPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChaosClothAssetToolset_eventCreateClothingAsset_Parms, ChaosClothAssetPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChaosClothAssetPath_MetaData), NewProp_ChaosClothAssetPath_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UChaosClothAssetToolset_CreateClothingAsset_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UChaosClothAssetToolset_CreateClothingAsset_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChaosClothAssetToolset_eventCreateClothingAsset_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChaosClothAssetToolset_CreateClothingAsset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChaosClothAssetToolset_CreateClothingAsset_Statics::NewProp_SkeletalMeshPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChaosClothAssetToolset_CreateClothingAsset_Statics::NewProp_ChaosClothAssetPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChaosClothAssetToolset_CreateClothingAsset_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChaosClothAssetToolset_CreateClothingAsset_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChaosClothAssetToolset_CreateClothingAsset_Statics::PropPointers) < 2048);
// ********** End Function CreateClothingAsset Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChaosClothAssetToolset_CreateClothingAsset_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChaosClothAssetToolset, nullptr, "CreateClothingAsset", 	Z_Construct_UFunction_UChaosClothAssetToolset_CreateClothingAsset_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UChaosClothAssetToolset_CreateClothingAsset_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UChaosClothAssetToolset_CreateClothingAsset_Statics::ChaosClothAssetToolset_eventCreateClothingAsset_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChaosClothAssetToolset_CreateClothingAsset_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChaosClothAssetToolset_CreateClothingAsset_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChaosClothAssetToolset_CreateClothingAsset_Statics::ChaosClothAssetToolset_eventCreateClothingAsset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChaosClothAssetToolset_CreateClothingAsset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChaosClothAssetToolset_CreateClothingAsset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChaosClothAssetToolset::execCreateClothingAsset)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_SkeletalMeshPath);
	P_GET_PROPERTY(FStrProperty,Z_Param_ChaosClothAssetPath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=UChaosClothAssetToolset::CreateClothingAsset(Z_Param_SkeletalMeshPath,Z_Param_ChaosClothAssetPath);
	P_NATIVE_END;
}
// ********** End Class UChaosClothAssetToolset Function CreateClothingAsset ***********************

// ********** Begin Class UChaosClothAssetToolset Function GetSectionClothing **********************
struct Z_Construct_UFunction_UChaosClothAssetToolset_GetSectionClothing_Statics
{
	struct ChaosClothAssetToolset_eventGetSectionClothing_Parms
	{
		FString SkeletalMeshPath;
		int32 LodIndex;
		int32 SectionIndex;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "ChaosClothAsset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the name of clothing bound for a specific LOD section (if any).\n\x09 * @param SkeletalMeshPath Object path to the target USkeletalMesh asset.\n\x09 * @param LodIndex Skeletal mesh LOD index.\n\x09 * @param SectionIndex Section index within the LOD.\n\x09 * @return The name of the clothing asset, or empty if none bound.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/ChaosClothAsset/ClothAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the name of clothing bound for a specific LOD section (if any).\n@param SkeletalMeshPath Object path to the target USkeletalMesh asset.\n@param LodIndex Skeletal mesh LOD index.\n@param SectionIndex Section index within the LOD.\n@return The name of the clothing asset, or empty if none bound." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkeletalMeshPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSectionClothing constinit property declarations ********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_SkeletalMeshPath;
	static const UECodeGen_Private::FIntPropertyParams NewProp_LodIndex;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SectionIndex;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSectionClothing constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSectionClothing Property Definitions *******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UChaosClothAssetToolset_GetSectionClothing_Statics::NewProp_SkeletalMeshPath = { "SkeletalMeshPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChaosClothAssetToolset_eventGetSectionClothing_Parms, SkeletalMeshPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkeletalMeshPath_MetaData), NewProp_SkeletalMeshPath_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UChaosClothAssetToolset_GetSectionClothing_Statics::NewProp_LodIndex = { "LodIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChaosClothAssetToolset_eventGetSectionClothing_Parms, LodIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UChaosClothAssetToolset_GetSectionClothing_Statics::NewProp_SectionIndex = { "SectionIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChaosClothAssetToolset_eventGetSectionClothing_Parms, SectionIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UChaosClothAssetToolset_GetSectionClothing_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChaosClothAssetToolset_eventGetSectionClothing_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChaosClothAssetToolset_GetSectionClothing_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChaosClothAssetToolset_GetSectionClothing_Statics::NewProp_SkeletalMeshPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChaosClothAssetToolset_GetSectionClothing_Statics::NewProp_LodIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChaosClothAssetToolset_GetSectionClothing_Statics::NewProp_SectionIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChaosClothAssetToolset_GetSectionClothing_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChaosClothAssetToolset_GetSectionClothing_Statics::PropPointers) < 2048);
// ********** End Function GetSectionClothing Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChaosClothAssetToolset_GetSectionClothing_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChaosClothAssetToolset, nullptr, "GetSectionClothing", 	Z_Construct_UFunction_UChaosClothAssetToolset_GetSectionClothing_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UChaosClothAssetToolset_GetSectionClothing_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UChaosClothAssetToolset_GetSectionClothing_Statics::ChaosClothAssetToolset_eventGetSectionClothing_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChaosClothAssetToolset_GetSectionClothing_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChaosClothAssetToolset_GetSectionClothing_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChaosClothAssetToolset_GetSectionClothing_Statics::ChaosClothAssetToolset_eventGetSectionClothing_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChaosClothAssetToolset_GetSectionClothing()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChaosClothAssetToolset_GetSectionClothing_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChaosClothAssetToolset::execGetSectionClothing)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_SkeletalMeshPath);
	P_GET_PROPERTY(FIntProperty,Z_Param_LodIndex);
	P_GET_PROPERTY(FIntProperty,Z_Param_SectionIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UChaosClothAssetToolset::GetSectionClothing(Z_Param_SkeletalMeshPath,Z_Param_LodIndex,Z_Param_SectionIndex);
	P_NATIVE_END;
}
// ********** End Class UChaosClothAssetToolset Function GetSectionClothing ************************

// ********** Begin Class UChaosClothAssetToolset Function ListClothingAssets **********************
struct Z_Construct_UFunction_UChaosClothAssetToolset_ListClothingAssets_Statics
{
	struct ChaosClothAssetToolset_eventListClothingAssets_Parms
	{
		FString SkeletalMeshPath;
		TArray<FClothingAssetInfo> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "ChaosClothAsset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns information about all Clothing Assets on a skeletal mesh.\n\x09 * Use AssetName with AssignClothingToSection.\n\x09 * Check bRequiresMatchingLodIndex to determine how to supply ClothingLodIndex:\n\x09 *   - true  (ChaosClothAsset): pass the same value as LodIndex\n\x09 *   - false (UClothingAssetCommon): pass any value in [0, NumClothingLods-1]\n\x09 * @param SkeletalMeshPath Object path to the target USkeletalMesh asset.\n\x09 * @return Array of clothing asset info structs.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/ChaosClothAsset/ClothAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns information about all Clothing Assets on a skeletal mesh.\nUse AssetName with AssignClothingToSection.\nCheck bRequiresMatchingLodIndex to determine how to supply ClothingLodIndex:\n  - true  (ChaosClothAsset): pass the same value as LodIndex\n  - false (UClothingAssetCommon): pass any value in [0, NumClothingLods-1]\n@param SkeletalMeshPath Object path to the target USkeletalMesh asset.\n@return Array of clothing asset info structs." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkeletalMeshPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ListClothingAssets constinit property declarations ********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_SkeletalMeshPath;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListClothingAssets constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListClothingAssets Property Definitions *******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UChaosClothAssetToolset_ListClothingAssets_Statics::NewProp_SkeletalMeshPath = { "SkeletalMeshPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChaosClothAssetToolset_eventListClothingAssets_Parms, SkeletalMeshPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkeletalMeshPath_MetaData), NewProp_SkeletalMeshPath_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UChaosClothAssetToolset_ListClothingAssets_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FClothingAssetInfo, METADATA_PARAMS(0, nullptr) }; // 2019810136
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UChaosClothAssetToolset_ListClothingAssets_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChaosClothAssetToolset_eventListClothingAssets_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 2019810136
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChaosClothAssetToolset_ListClothingAssets_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChaosClothAssetToolset_ListClothingAssets_Statics::NewProp_SkeletalMeshPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChaosClothAssetToolset_ListClothingAssets_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChaosClothAssetToolset_ListClothingAssets_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChaosClothAssetToolset_ListClothingAssets_Statics::PropPointers) < 2048);
// ********** End Function ListClothingAssets Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChaosClothAssetToolset_ListClothingAssets_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChaosClothAssetToolset, nullptr, "ListClothingAssets", 	Z_Construct_UFunction_UChaosClothAssetToolset_ListClothingAssets_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UChaosClothAssetToolset_ListClothingAssets_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UChaosClothAssetToolset_ListClothingAssets_Statics::ChaosClothAssetToolset_eventListClothingAssets_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChaosClothAssetToolset_ListClothingAssets_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChaosClothAssetToolset_ListClothingAssets_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChaosClothAssetToolset_ListClothingAssets_Statics::ChaosClothAssetToolset_eventListClothingAssets_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChaosClothAssetToolset_ListClothingAssets()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChaosClothAssetToolset_ListClothingAssets_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChaosClothAssetToolset::execListClothingAssets)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_SkeletalMeshPath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FClothingAssetInfo>*)Z_Param__Result=UChaosClothAssetToolset::ListClothingAssets(Z_Param_SkeletalMeshPath);
	P_NATIVE_END;
}
// ********** End Class UChaosClothAssetToolset Function ListClothingAssets ************************

// ********** Begin Class UChaosClothAssetToolset Function RemoveClothingFromSection ***************
struct Z_Construct_UFunction_UChaosClothAssetToolset_RemoveClothingFromSection_Statics
{
	struct ChaosClothAssetToolset_eventRemoveClothingFromSection_Parms
	{
		FString SkeletalMeshPath;
		int32 LodIndex;
		int32 SectionIndex;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "ChaosClothAsset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Removes the clothing binding from a specific LOD section on the skeletal mesh.\n\x09 * Mirrors the SkeletalMesh Editor's \"Remove Clothing Data\" action.\n\x09 * @param SkeletalMeshPath Object path to the target USkeletalMesh asset.\n\x09 * @param LodIndex Skeletal mesh LOD index.\n\x09 * @param SectionIndex Section index within the LOD.\n\x09 * @return True if a binding was found and removed.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/ChaosClothAsset/ClothAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Removes the clothing binding from a specific LOD section on the skeletal mesh.\nMirrors the SkeletalMesh Editor's \"Remove Clothing Data\" action.\n@param SkeletalMeshPath Object path to the target USkeletalMesh asset.\n@param LodIndex Skeletal mesh LOD index.\n@param SectionIndex Section index within the LOD.\n@return True if a binding was found and removed." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkeletalMeshPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RemoveClothingFromSection constinit property declarations *************
	static const UECodeGen_Private::FStrPropertyParams NewProp_SkeletalMeshPath;
	static const UECodeGen_Private::FIntPropertyParams NewProp_LodIndex;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SectionIndex;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RemoveClothingFromSection constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RemoveClothingFromSection Property Definitions ************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UChaosClothAssetToolset_RemoveClothingFromSection_Statics::NewProp_SkeletalMeshPath = { "SkeletalMeshPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChaosClothAssetToolset_eventRemoveClothingFromSection_Parms, SkeletalMeshPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkeletalMeshPath_MetaData), NewProp_SkeletalMeshPath_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UChaosClothAssetToolset_RemoveClothingFromSection_Statics::NewProp_LodIndex = { "LodIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChaosClothAssetToolset_eventRemoveClothingFromSection_Parms, LodIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UChaosClothAssetToolset_RemoveClothingFromSection_Statics::NewProp_SectionIndex = { "SectionIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChaosClothAssetToolset_eventRemoveClothingFromSection_Parms, SectionIndex), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UChaosClothAssetToolset_RemoveClothingFromSection_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ChaosClothAssetToolset_eventRemoveClothingFromSection_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UChaosClothAssetToolset_RemoveClothingFromSection_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ChaosClothAssetToolset_eventRemoveClothingFromSection_Parms), &Z_Construct_UFunction_UChaosClothAssetToolset_RemoveClothingFromSection_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChaosClothAssetToolset_RemoveClothingFromSection_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChaosClothAssetToolset_RemoveClothingFromSection_Statics::NewProp_SkeletalMeshPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChaosClothAssetToolset_RemoveClothingFromSection_Statics::NewProp_LodIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChaosClothAssetToolset_RemoveClothingFromSection_Statics::NewProp_SectionIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChaosClothAssetToolset_RemoveClothingFromSection_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChaosClothAssetToolset_RemoveClothingFromSection_Statics::PropPointers) < 2048);
// ********** End Function RemoveClothingFromSection Property Definitions **************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChaosClothAssetToolset_RemoveClothingFromSection_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChaosClothAssetToolset, nullptr, "RemoveClothingFromSection", 	Z_Construct_UFunction_UChaosClothAssetToolset_RemoveClothingFromSection_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UChaosClothAssetToolset_RemoveClothingFromSection_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UChaosClothAssetToolset_RemoveClothingFromSection_Statics::ChaosClothAssetToolset_eventRemoveClothingFromSection_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChaosClothAssetToolset_RemoveClothingFromSection_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChaosClothAssetToolset_RemoveClothingFromSection_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChaosClothAssetToolset_RemoveClothingFromSection_Statics::ChaosClothAssetToolset_eventRemoveClothingFromSection_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChaosClothAssetToolset_RemoveClothingFromSection()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChaosClothAssetToolset_RemoveClothingFromSection_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChaosClothAssetToolset::execRemoveClothingFromSection)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_SkeletalMeshPath);
	P_GET_PROPERTY(FIntProperty,Z_Param_LodIndex);
	P_GET_PROPERTY(FIntProperty,Z_Param_SectionIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UChaosClothAssetToolset::RemoveClothingFromSection(Z_Param_SkeletalMeshPath,Z_Param_LodIndex,Z_Param_SectionIndex);
	P_NATIVE_END;
}
// ********** End Class UChaosClothAssetToolset Function RemoveClothingFromSection *****************

// ********** Begin Class UChaosClothAssetToolset **************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UChaosClothAssetToolset;
UClass* UChaosClothAssetToolset::GetPrivateStaticClass()
{
	using TClass = UChaosClothAssetToolset;
	if (!Z_Registration_Info_UClass_UChaosClothAssetToolset.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ChaosClothAssetToolset"),
			Z_Registration_Info_UClass_UChaosClothAssetToolset.InnerSingleton,
			StaticRegisterNativesUChaosClothAssetToolset,
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
	return Z_Registration_Info_UClass_UChaosClothAssetToolset.InnerSingleton;
}
UClass* Z_Construct_UClass_UChaosClothAssetToolset_NoRegister()
{
	return UChaosClothAssetToolset::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UChaosClothAssetToolset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Provides tools for creating and assigning ChaosClothAsset clothing data to skeletal meshes.\n * Replicates the workflow available via the SkeletalMesh Editor viewport context menu.\n */" },
#endif
		{ "IncludePath", "ChaosClothAsset/ClothAssetToolset.h" },
		{ "ModuleRelativePath", "Private/ChaosClothAsset/ClothAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Provides tools for creating and assigning ChaosClothAsset clothing data to skeletal meshes.\nReplicates the workflow available via the SkeletalMesh Editor viewport context menu." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UChaosClothAssetToolset constinit property declarations ******************
// ********** End Class UChaosClothAssetToolset constinit property declarations ********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AssignClothingToSection"), .Pointer = &UChaosClothAssetToolset::execAssignClothingToSection },
		{ .NameUTF8 = UTF8TEXT("ConvertClothingAssetCommonToChaosClothAsset"), .Pointer = &UChaosClothAssetToolset::execConvertClothingAssetCommonToChaosClothAsset },
		{ .NameUTF8 = UTF8TEXT("CreateClothingAsset"), .Pointer = &UChaosClothAssetToolset::execCreateClothingAsset },
		{ .NameUTF8 = UTF8TEXT("GetSectionClothing"), .Pointer = &UChaosClothAssetToolset::execGetSectionClothing },
		{ .NameUTF8 = UTF8TEXT("ListClothingAssets"), .Pointer = &UChaosClothAssetToolset::execListClothingAssets },
		{ .NameUTF8 = UTF8TEXT("RemoveClothingFromSection"), .Pointer = &UChaosClothAssetToolset::execRemoveClothingFromSection },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UChaosClothAssetToolset_AssignClothingToSection, "AssignClothingToSection" }, // 4170741108
		{ &Z_Construct_UFunction_UChaosClothAssetToolset_ConvertClothingAssetCommonToChaosClothAsset, "ConvertClothingAssetCommonToChaosClothAsset" }, // 3373525453
		{ &Z_Construct_UFunction_UChaosClothAssetToolset_CreateClothingAsset, "CreateClothingAsset" }, // 361331480
		{ &Z_Construct_UFunction_UChaosClothAssetToolset_GetSectionClothing, "GetSectionClothing" }, // 1822471765
		{ &Z_Construct_UFunction_UChaosClothAssetToolset_ListClothingAssets, "ListClothingAssets" }, // 1876284832
		{ &Z_Construct_UFunction_UChaosClothAssetToolset_RemoveClothingFromSection, "RemoveClothingFromSection" }, // 1696300170
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UChaosClothAssetToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UChaosClothAssetToolset_Statics
UObject* (*const Z_Construct_UClass_UChaosClothAssetToolset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UToolsetDefinition,
	(UObject* (*)())Z_Construct_UPackage__Script_ChaosClothAssetToolset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UChaosClothAssetToolset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UChaosClothAssetToolset_Statics::ClassParams = {
	&UChaosClothAssetToolset::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UChaosClothAssetToolset_Statics::Class_MetaDataParams), Z_Construct_UClass_UChaosClothAssetToolset_Statics::Class_MetaDataParams)
};
void UChaosClothAssetToolset::StaticRegisterNativesUChaosClothAssetToolset()
{
	UClass* Class = UChaosClothAssetToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UChaosClothAssetToolset_Statics::Funcs));
}
UClass* Z_Construct_UClass_UChaosClothAssetToolset()
{
	if (!Z_Registration_Info_UClass_UChaosClothAssetToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UChaosClothAssetToolset.OuterSingleton, Z_Construct_UClass_UChaosClothAssetToolset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UChaosClothAssetToolset.OuterSingleton;
}
UChaosClothAssetToolset::UChaosClothAssetToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UChaosClothAssetToolset);
UChaosClothAssetToolset::~UChaosClothAssetToolset() {}
// ********** End Class UChaosClothAssetToolset ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_ChaosClothAssetToolset_Source_ChaosClothAssetToolset_Private_ChaosClothAsset_ClothAssetToolset_h__Script_ChaosClothAssetToolset_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FClothingAssetInfo::StaticStruct, Z_Construct_UScriptStruct_FClothingAssetInfo_Statics::NewStructOps, TEXT("ClothingAssetInfo"),&Z_Registration_Info_UScriptStruct_FClothingAssetInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FClothingAssetInfo), 2019810136U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UChaosClothAssetToolset, UChaosClothAssetToolset::StaticClass, TEXT("UChaosClothAssetToolset"), &Z_Registration_Info_UClass_UChaosClothAssetToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UChaosClothAssetToolset), 1005300467U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_ChaosClothAssetToolset_Source_ChaosClothAssetToolset_Private_ChaosClothAsset_ClothAssetToolset_h__Script_ChaosClothAssetToolset_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_ChaosClothAssetToolset_Source_ChaosClothAssetToolset_Private_ChaosClothAsset_ClothAssetToolset_h__Script_ChaosClothAssetToolset_405997371{
	TEXT("/Script/ChaosClothAssetToolset"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_ChaosClothAssetToolset_Source_ChaosClothAssetToolset_Private_ChaosClothAsset_ClothAssetToolset_h__Script_ChaosClothAssetToolset_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_ChaosClothAssetToolset_Source_ChaosClothAssetToolset_Private_ChaosClothAsset_ClothAssetToolset_h__Script_ChaosClothAssetToolset_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_ChaosClothAssetToolset_Source_ChaosClothAssetToolset_Private_ChaosClothAsset_ClothAssetToolset_h__Script_ChaosClothAssetToolset_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_ChaosClothAssetToolset_Source_ChaosClothAssetToolset_Private_ChaosClothAsset_ClothAssetToolset_h__Script_ChaosClothAssetToolset_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
