// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDataflowAgent_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_DataflowAgent;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_DataflowAgent()
	{
		if (!Z_Registration_Info_UPackage__Script_DataflowAgent.OuterSingleton)
		{
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/DataflowAgent",
			nullptr,
			0,
			PKG_CompiledIn | 0x00000040,
			0x673C486F,
			0x4169E556,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_DataflowAgent.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_DataflowAgent.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_DataflowAgent(Z_Construct_UPackage__Script_DataflowAgent, TEXT("/Script/DataflowAgent"), Z_Registration_Info_UPackage__Script_DataflowAgent, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x673C486F, 0x4169E556));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
