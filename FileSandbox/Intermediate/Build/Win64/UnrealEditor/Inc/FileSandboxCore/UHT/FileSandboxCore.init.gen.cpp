// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFileSandboxCore_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_FileSandboxCore;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_FileSandboxCore()
	{
		if (!Z_Registration_Info_UPackage__Script_FileSandboxCore.OuterSingleton)
		{
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/FileSandboxCore",
			nullptr,
			0,
			PKG_CompiledIn | 0x00000100,
			0x60C6CAE6,
			0x6F640946,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_FileSandboxCore.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_FileSandboxCore.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_FileSandboxCore(Z_Construct_UPackage__Script_FileSandboxCore, TEXT("/Script/FileSandboxCore"), Z_Registration_Info_UPackage__Script_FileSandboxCore, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x60C6CAE6, 0x6F640946));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
