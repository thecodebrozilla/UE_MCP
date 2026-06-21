// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLiveCodingToolset_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_LiveCodingToolset;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_LiveCodingToolset()
	{
		if (!Z_Registration_Info_UPackage__Script_LiveCodingToolset.OuterSingleton)
		{
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/LiveCodingToolset",
			nullptr,
			0,
			PKG_CompiledIn | 0x00000040,
			0x00C373C8,
			0x1E57A827,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_LiveCodingToolset.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_LiveCodingToolset.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_LiveCodingToolset(Z_Construct_UPackage__Script_LiveCodingToolset, TEXT("/Script/LiveCodingToolset"), Z_Registration_Info_UPackage__Script_LiveCodingToolset, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x00C373C8, 0x1E57A827));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
