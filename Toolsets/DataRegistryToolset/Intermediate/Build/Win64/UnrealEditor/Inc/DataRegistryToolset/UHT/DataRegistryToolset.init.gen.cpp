// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDataRegistryToolset_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_DataRegistryToolset;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_DataRegistryToolset()
	{
		if (!Z_Registration_Info_UPackage__Script_DataRegistryToolset.OuterSingleton)
		{
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/DataRegistryToolset",
			nullptr,
			0,
			PKG_CompiledIn | 0x00000040,
			0xB36FC419,
			0xD2AADAC9,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_DataRegistryToolset.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_DataRegistryToolset.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_DataRegistryToolset(Z_Construct_UPackage__Script_DataRegistryToolset, TEXT("/Script/DataRegistryToolset"), Z_Registration_Info_UPackage__Script_DataRegistryToolset, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xB36FC419, 0xD2AADAC9));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
