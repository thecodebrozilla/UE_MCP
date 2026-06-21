// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PCGToolsetSkills.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodePCGToolsetSkills() {}

// ********** Begin Cross Module References ********************************************************
PCGTOOLSET_API UClass* Z_Construct_UClass_UPCGGraphGenerationSkill();
PCGTOOLSET_API UClass* Z_Construct_UClass_UPCGGraphGenerationSkill_NoRegister();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UAgentSkill();
UPackage* Z_Construct_UPackage__Script_PCGToolset();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UPCGGraphGenerationSkill *************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UPCGGraphGenerationSkill;
UClass* UPCGGraphGenerationSkill::GetPrivateStaticClass()
{
	using TClass = UPCGGraphGenerationSkill;
	if (!Z_Registration_Info_UClass_UPCGGraphGenerationSkill.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("PCGGraphGenerationSkill"),
			Z_Registration_Info_UClass_UPCGGraphGenerationSkill.InnerSingleton,
			StaticRegisterNativesUPCGGraphGenerationSkill,
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
	return Z_Registration_Info_UClass_UPCGGraphGenerationSkill.InnerSingleton;
}
UClass* Z_Construct_UClass_UPCGGraphGenerationSkill_NoRegister()
{
	return UPCGGraphGenerationSkill::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPCGGraphGenerationSkill_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "PCGToolsetSkills.h" },
		{ "ModuleRelativePath", "Public/PCGToolsetSkills.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UPCGGraphGenerationSkill constinit property declarations *****************
// ********** End Class UPCGGraphGenerationSkill constinit property declarations *******************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPCGGraphGenerationSkill>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UPCGGraphGenerationSkill_Statics
UObject* (*const Z_Construct_UClass_UPCGGraphGenerationSkill_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAgentSkill,
	(UObject* (*)())Z_Construct_UPackage__Script_PCGToolset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPCGGraphGenerationSkill_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPCGGraphGenerationSkill_Statics::ClassParams = {
	&UPCGGraphGenerationSkill::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPCGGraphGenerationSkill_Statics::Class_MetaDataParams), Z_Construct_UClass_UPCGGraphGenerationSkill_Statics::Class_MetaDataParams)
};
void UPCGGraphGenerationSkill::StaticRegisterNativesUPCGGraphGenerationSkill()
{
}
UClass* Z_Construct_UClass_UPCGGraphGenerationSkill()
{
	if (!Z_Registration_Info_UClass_UPCGGraphGenerationSkill.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPCGGraphGenerationSkill.OuterSingleton, Z_Construct_UClass_UPCGGraphGenerationSkill_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPCGGraphGenerationSkill.OuterSingleton;
}
UPCGGraphGenerationSkill::UPCGGraphGenerationSkill(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UPCGGraphGenerationSkill);
UPCGGraphGenerationSkill::~UPCGGraphGenerationSkill() {}
// ********** End Class UPCGGraphGenerationSkill ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolsetSkills_h__Script_PCGToolset_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPCGGraphGenerationSkill, UPCGGraphGenerationSkill::StaticClass, TEXT("UPCGGraphGenerationSkill"), &Z_Registration_Info_UClass_UPCGGraphGenerationSkill, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPCGGraphGenerationSkill), 2525939466U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolsetSkills_h__Script_PCGToolset_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolsetSkills_h__Script_PCGToolset_1624567686{
	TEXT("/Script/PCGToolset"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolsetSkills_h__Script_PCGToolset_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolsetSkills_h__Script_PCGToolset_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
