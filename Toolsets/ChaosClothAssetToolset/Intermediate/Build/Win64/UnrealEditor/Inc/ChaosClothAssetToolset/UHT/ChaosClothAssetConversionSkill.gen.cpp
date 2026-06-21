// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChaosClothAsset/ChaosClothAssetConversionSkill.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeChaosClothAssetConversionSkill() {}

// ********** Begin Cross Module References ********************************************************
CHAOSCLOTHASSETTOOLSET_API UClass* Z_Construct_UClass_UChaosClothAssetConversionSkill();
CHAOSCLOTHASSETTOOLSET_API UClass* Z_Construct_UClass_UChaosClothAssetConversionSkill_NoRegister();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UAgentSkill();
UPackage* Z_Construct_UPackage__Script_ChaosClothAssetToolset();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UChaosClothAssetConversionSkill ******************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UChaosClothAssetConversionSkill;
UClass* UChaosClothAssetConversionSkill::GetPrivateStaticClass()
{
	using TClass = UChaosClothAssetConversionSkill;
	if (!Z_Registration_Info_UClass_UChaosClothAssetConversionSkill.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ChaosClothAssetConversionSkill"),
			Z_Registration_Info_UClass_UChaosClothAssetConversionSkill.InnerSingleton,
			StaticRegisterNativesUChaosClothAssetConversionSkill,
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
	return Z_Registration_Info_UClass_UChaosClothAssetConversionSkill.InnerSingleton;
}
UClass* Z_Construct_UClass_UChaosClothAssetConversionSkill_NoRegister()
{
	return UChaosClothAssetConversionSkill::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UChaosClothAssetConversionSkill_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Agent skill that documents the end-to-end workflow for converting a legacy UClothingAssetCommon\n * on a SkeletalMesh into a new UChaosClothAsset using the ChaosClothAsset toolset.\n */" },
#endif
		{ "IncludePath", "ChaosClothAsset/ChaosClothAssetConversionSkill.h" },
		{ "ModuleRelativePath", "Private/ChaosClothAsset/ChaosClothAssetConversionSkill.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Agent skill that documents the end-to-end workflow for converting a legacy UClothingAssetCommon\non a SkeletalMesh into a new UChaosClothAsset using the ChaosClothAsset toolset." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UChaosClothAssetConversionSkill constinit property declarations **********
// ********** End Class UChaosClothAssetConversionSkill constinit property declarations ************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UChaosClothAssetConversionSkill>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UChaosClothAssetConversionSkill_Statics
UObject* (*const Z_Construct_UClass_UChaosClothAssetConversionSkill_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAgentSkill,
	(UObject* (*)())Z_Construct_UPackage__Script_ChaosClothAssetToolset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UChaosClothAssetConversionSkill_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UChaosClothAssetConversionSkill_Statics::ClassParams = {
	&UChaosClothAssetConversionSkill::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UChaosClothAssetConversionSkill_Statics::Class_MetaDataParams), Z_Construct_UClass_UChaosClothAssetConversionSkill_Statics::Class_MetaDataParams)
};
void UChaosClothAssetConversionSkill::StaticRegisterNativesUChaosClothAssetConversionSkill()
{
}
UClass* Z_Construct_UClass_UChaosClothAssetConversionSkill()
{
	if (!Z_Registration_Info_UClass_UChaosClothAssetConversionSkill.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UChaosClothAssetConversionSkill.OuterSingleton, Z_Construct_UClass_UChaosClothAssetConversionSkill_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UChaosClothAssetConversionSkill.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UChaosClothAssetConversionSkill);
UChaosClothAssetConversionSkill::~UChaosClothAssetConversionSkill() {}
// ********** End Class UChaosClothAssetConversionSkill ********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_ChaosClothAssetToolset_Source_ChaosClothAssetToolset_Private_ChaosClothAsset_ChaosClothAssetConversionSkill_h__Script_ChaosClothAssetToolset_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UChaosClothAssetConversionSkill, UChaosClothAssetConversionSkill::StaticClass, TEXT("UChaosClothAssetConversionSkill"), &Z_Registration_Info_UClass_UChaosClothAssetConversionSkill, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UChaosClothAssetConversionSkill), 2257083095U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_ChaosClothAssetToolset_Source_ChaosClothAssetToolset_Private_ChaosClothAsset_ChaosClothAssetConversionSkill_h__Script_ChaosClothAssetToolset_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_ChaosClothAssetToolset_Source_ChaosClothAssetToolset_Private_ChaosClothAsset_ChaosClothAssetConversionSkill_h__Script_ChaosClothAssetToolset_3383317304{
	TEXT("/Script/ChaosClothAssetToolset"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_ChaosClothAssetToolset_Source_ChaosClothAssetToolset_Private_ChaosClothAsset_ChaosClothAssetConversionSkill_h__Script_ChaosClothAssetToolset_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_ChaosClothAssetToolset_Source_ChaosClothAssetToolset_Private_ChaosClothAsset_ChaosClothAssetConversionSkill_h__Script_ChaosClothAssetToolset_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
