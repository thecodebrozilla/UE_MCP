// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePluginToolset_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_PluginToolset;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_PluginToolset()
	{
		if (!Z_Registration_Info_UPackage__Script_PluginToolset.OuterSingleton)
		{
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/PluginToolset",
			nullptr,
			0,
			PKG_CompiledIn | 0x00000040,
			0x715E8E97,
			0x6CB51075,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_PluginToolset.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_PluginToolset.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_PluginToolset(Z_Construct_UPackage__Script_PluginToolset, TEXT("/Script/PluginToolset"), Z_Registration_Info_UPackage__Script_PluginToolset, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x715E8E97, 0x6CB51075));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
