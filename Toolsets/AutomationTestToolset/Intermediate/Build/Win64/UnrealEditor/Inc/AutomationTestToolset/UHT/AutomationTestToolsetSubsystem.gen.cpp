// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AutomationTestToolsetSubsystem.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeAutomationTestToolsetSubsystem() {}

// ********** Begin Cross Module References ********************************************************
AUTOMATIONTESTTOOLSET_API UClass* Z_Construct_UClass_UAutomationTestToolsetSubsystem();
AUTOMATIONTESTTOOLSET_API UClass* Z_Construct_UClass_UAutomationTestToolsetSubsystem_NoRegister();
EDITORSUBSYSTEM_API UClass* Z_Construct_UClass_UEditorSubsystem();
UPackage* Z_Construct_UPackage__Script_AutomationTestToolset();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UAutomationTestToolsetSubsystem ******************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UAutomationTestToolsetSubsystem;
UClass* UAutomationTestToolsetSubsystem::GetPrivateStaticClass()
{
	using TClass = UAutomationTestToolsetSubsystem;
	if (!Z_Registration_Info_UClass_UAutomationTestToolsetSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("AutomationTestToolsetSubsystem"),
			Z_Registration_Info_UClass_UAutomationTestToolsetSubsystem.InnerSingleton,
			StaticRegisterNativesUAutomationTestToolsetSubsystem,
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
	return Z_Registration_Info_UClass_UAutomationTestToolsetSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UAutomationTestToolsetSubsystem_NoRegister()
{
	return UAutomationTestToolsetSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UAutomationTestToolsetSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Manages the automation controller lifecycle for the AutomationTestToolset.\n *\n * Handles session discovery, worker communication, and test execution polling.\n * The toolset's static tool functions delegate to this subsystem for state management.\n */" },
#endif
		{ "IncludePath", "AutomationTestToolsetSubsystem.h" },
		{ "ModuleRelativePath", "Public/AutomationTestToolsetSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Manages the automation controller lifecycle for the AutomationTestToolset.\n\nHandles session discovery, worker communication, and test execution polling.\nThe toolset's static tool functions delegate to this subsystem for state management." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UAutomationTestToolsetSubsystem constinit property declarations **********
// ********** End Class UAutomationTestToolsetSubsystem constinit property declarations ************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAutomationTestToolsetSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UAutomationTestToolsetSubsystem_Statics
UObject* (*const Z_Construct_UClass_UAutomationTestToolsetSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEditorSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_AutomationTestToolset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAutomationTestToolsetSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAutomationTestToolsetSubsystem_Statics::ClassParams = {
	&UAutomationTestToolsetSubsystem::StaticClass,
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
	0x000800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAutomationTestToolsetSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UAutomationTestToolsetSubsystem_Statics::Class_MetaDataParams)
};
void UAutomationTestToolsetSubsystem::StaticRegisterNativesUAutomationTestToolsetSubsystem()
{
}
UClass* Z_Construct_UClass_UAutomationTestToolsetSubsystem()
{
	if (!Z_Registration_Info_UClass_UAutomationTestToolsetSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAutomationTestToolsetSubsystem.OuterSingleton, Z_Construct_UClass_UAutomationTestToolsetSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAutomationTestToolsetSubsystem.OuterSingleton;
}
UAutomationTestToolsetSubsystem::UAutomationTestToolsetSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UAutomationTestToolsetSubsystem);
UAutomationTestToolsetSubsystem::~UAutomationTestToolsetSubsystem() {}
// ********** End Class UAutomationTestToolsetSubsystem ********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_AutomationTestToolset_Source_AutomationTestToolset_Public_AutomationTestToolsetSubsystem_h__Script_AutomationTestToolset_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAutomationTestToolsetSubsystem, UAutomationTestToolsetSubsystem::StaticClass, TEXT("UAutomationTestToolsetSubsystem"), &Z_Registration_Info_UClass_UAutomationTestToolsetSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAutomationTestToolsetSubsystem), 135508202U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_AutomationTestToolset_Source_AutomationTestToolset_Public_AutomationTestToolsetSubsystem_h__Script_AutomationTestToolset_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_AutomationTestToolset_Source_AutomationTestToolset_Public_AutomationTestToolsetSubsystem_h__Script_AutomationTestToolset_93617483{
	TEXT("/Script/AutomationTestToolset"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_AutomationTestToolset_Source_AutomationTestToolset_Public_AutomationTestToolsetSubsystem_h__Script_AutomationTestToolset_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_AutomationTestToolset_Source_AutomationTestToolset_Public_AutomationTestToolsetSubsystem_h__Script_AutomationTestToolset_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
