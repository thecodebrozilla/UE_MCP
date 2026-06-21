// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ChaosClothAsset/ClothAssetToolset.h"

#ifdef CHAOSCLOTHASSETTOOLSET_ClothAssetToolset_generated_h
#error "ClothAssetToolset.generated.h already included, missing '#pragma once' in ClothAssetToolset.h"
#endif
#define CHAOSCLOTHASSETTOOLSET_ClothAssetToolset_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FClothingAssetInfo;

// ********** Begin ScriptStruct FClothingAssetInfo ************************************************
struct Z_Construct_UScriptStruct_FClothingAssetInfo_Statics;
#define FID_UE_MCP_Plugins_Toolsets_ChaosClothAssetToolset_Source_ChaosClothAssetToolset_Private_ChaosClothAsset_ClothAssetToolset_h_16_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FClothingAssetInfo_Statics; \
	CHAOSCLOTHASSETTOOLSET_API static class UScriptStruct* StaticStruct();


struct FClothingAssetInfo;
// ********** End ScriptStruct FClothingAssetInfo **************************************************

// ********** Begin Class UChaosClothAssetToolset **************************************************
#define FID_UE_MCP_Plugins_Toolsets_ChaosClothAssetToolset_Source_ChaosClothAssetToolset_Private_ChaosClothAsset_ClothAssetToolset_h_45_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execConvertClothingAssetCommonToChaosClothAsset); \
	DECLARE_FUNCTION(execGetSectionClothing); \
	DECLARE_FUNCTION(execListClothingAssets); \
	DECLARE_FUNCTION(execRemoveClothingFromSection); \
	DECLARE_FUNCTION(execAssignClothingToSection); \
	DECLARE_FUNCTION(execCreateClothingAsset);


struct Z_Construct_UClass_UChaosClothAssetToolset_Statics;
CHAOSCLOTHASSETTOOLSET_API UClass* Z_Construct_UClass_UChaosClothAssetToolset_NoRegister();

#define FID_UE_MCP_Plugins_Toolsets_ChaosClothAssetToolset_Source_ChaosClothAssetToolset_Private_ChaosClothAsset_ClothAssetToolset_h_45_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUChaosClothAssetToolset(); \
	friend struct ::Z_Construct_UClass_UChaosClothAssetToolset_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend CHAOSCLOTHASSETTOOLSET_API UClass* ::Z_Construct_UClass_UChaosClothAssetToolset_NoRegister(); \
public: \
	DECLARE_CLASS2(UChaosClothAssetToolset, UToolsetDefinition, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ChaosClothAssetToolset"), Z_Construct_UClass_UChaosClothAssetToolset_NoRegister) \
	DECLARE_SERIALIZER(UChaosClothAssetToolset)


#define FID_UE_MCP_Plugins_Toolsets_ChaosClothAssetToolset_Source_ChaosClothAssetToolset_Private_ChaosClothAsset_ClothAssetToolset_h_45_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	CHAOSCLOTHASSETTOOLSET_API UChaosClothAssetToolset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UChaosClothAssetToolset(UChaosClothAssetToolset&&) = delete; \
	UChaosClothAssetToolset(const UChaosClothAssetToolset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(CHAOSCLOTHASSETTOOLSET_API, UChaosClothAssetToolset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UChaosClothAssetToolset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UChaosClothAssetToolset) \
	CHAOSCLOTHASSETTOOLSET_API virtual ~UChaosClothAssetToolset();


#define FID_UE_MCP_Plugins_Toolsets_ChaosClothAssetToolset_Source_ChaosClothAssetToolset_Private_ChaosClothAsset_ClothAssetToolset_h_42_PROLOG
#define FID_UE_MCP_Plugins_Toolsets_ChaosClothAssetToolset_Source_ChaosClothAssetToolset_Private_ChaosClothAsset_ClothAssetToolset_h_45_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_Toolsets_ChaosClothAssetToolset_Source_ChaosClothAssetToolset_Private_ChaosClothAsset_ClothAssetToolset_h_45_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_ChaosClothAssetToolset_Source_ChaosClothAssetToolset_Private_ChaosClothAsset_ClothAssetToolset_h_45_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_ChaosClothAssetToolset_Source_ChaosClothAssetToolset_Private_ChaosClothAsset_ClothAssetToolset_h_45_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UChaosClothAssetToolset;

// ********** End Class UChaosClothAssetToolset ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_Toolsets_ChaosClothAssetToolset_Source_ChaosClothAssetToolset_Private_ChaosClothAsset_ClothAssetToolset_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
