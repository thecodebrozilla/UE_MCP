// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DataflowAgentSkills.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeDataflowAgentSkills() {}

// ********** Begin Cross Module References ********************************************************
DATAFLOWAGENT_API UClass* Z_Construct_UClass_UDataflowGraphEditingSkill();
DATAFLOWAGENT_API UClass* Z_Construct_UClass_UDataflowGraphEditingSkill_NoRegister();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UAgentSkill();
UPackage* Z_Construct_UPackage__Script_DataflowAgent();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDataflowGraphEditingSkill ***********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UDataflowGraphEditingSkill;
UClass* UDataflowGraphEditingSkill::GetPrivateStaticClass()
{
	using TClass = UDataflowGraphEditingSkill;
	if (!Z_Registration_Info_UClass_UDataflowGraphEditingSkill.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("DataflowGraphEditingSkill"),
			Z_Registration_Info_UClass_UDataflowGraphEditingSkill.InnerSingleton,
			StaticRegisterNativesUDataflowGraphEditingSkill,
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
	return Z_Registration_Info_UClass_UDataflowGraphEditingSkill.InnerSingleton;
}
UClass* Z_Construct_UClass_UDataflowGraphEditingSkill_NoRegister()
{
	return UDataflowGraphEditingSkill::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDataflowGraphEditingSkill_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DataflowAgentSkills.h" },
		{ "ModuleRelativePath", "Public/DataflowAgentSkills.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDataflowGraphEditingSkill constinit property declarations ***************
// ********** End Class UDataflowGraphEditingSkill constinit property declarations *****************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDataflowGraphEditingSkill>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UDataflowGraphEditingSkill_Statics
UObject* (*const Z_Construct_UClass_UDataflowGraphEditingSkill_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAgentSkill,
	(UObject* (*)())Z_Construct_UPackage__Script_DataflowAgent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDataflowGraphEditingSkill_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDataflowGraphEditingSkill_Statics::ClassParams = {
	&UDataflowGraphEditingSkill::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDataflowGraphEditingSkill_Statics::Class_MetaDataParams), Z_Construct_UClass_UDataflowGraphEditingSkill_Statics::Class_MetaDataParams)
};
void UDataflowGraphEditingSkill::StaticRegisterNativesUDataflowGraphEditingSkill()
{
}
UClass* Z_Construct_UClass_UDataflowGraphEditingSkill()
{
	if (!Z_Registration_Info_UClass_UDataflowGraphEditingSkill.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDataflowGraphEditingSkill.OuterSingleton, Z_Construct_UClass_UDataflowGraphEditingSkill_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDataflowGraphEditingSkill.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDataflowGraphEditingSkill);
UDataflowGraphEditingSkill::~UDataflowGraphEditingSkill() {}
// ********** End Class UDataflowGraphEditingSkill *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_DataflowAgent_Source_DataflowAgent_Public_DataflowAgentSkills_h__Script_DataflowAgent_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDataflowGraphEditingSkill, UDataflowGraphEditingSkill::StaticClass, TEXT("UDataflowGraphEditingSkill"), &Z_Registration_Info_UClass_UDataflowGraphEditingSkill, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDataflowGraphEditingSkill), 3685782029U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_DataflowAgent_Source_DataflowAgent_Public_DataflowAgentSkills_h__Script_DataflowAgent_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_DataflowAgent_Source_DataflowAgent_Public_DataflowAgentSkills_h__Script_DataflowAgent_3688661379{
	TEXT("/Script/DataflowAgent"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_DataflowAgent_Source_DataflowAgent_Public_DataflowAgentSkills_h__Script_DataflowAgent_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_DataflowAgent_Source_DataflowAgent_Public_DataflowAgentSkills_h__Script_DataflowAgent_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
