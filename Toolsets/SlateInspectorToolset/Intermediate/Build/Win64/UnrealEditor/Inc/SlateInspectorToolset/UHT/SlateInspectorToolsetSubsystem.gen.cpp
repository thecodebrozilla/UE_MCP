// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SlateInspectorToolsetSubsystem.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSlateInspectorToolsetSubsystem() {}

// ********** Begin Cross Module References ********************************************************
EDITORSUBSYSTEM_API UClass* Z_Construct_UClass_UEditorSubsystem();
SLATEINSPECTORTOOLSET_API UClass* Z_Construct_UClass_USlateInspectorToolsetSubsystem();
SLATEINSPECTORTOOLSET_API UClass* Z_Construct_UClass_USlateInspectorToolsetSubsystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_SlateInspectorToolset();
// ********** End Cross Module References **********************************************************

// ********** Begin Class USlateInspectorToolsetSubsystem ******************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USlateInspectorToolsetSubsystem;
UClass* USlateInspectorToolsetSubsystem::GetPrivateStaticClass()
{
	using TClass = USlateInspectorToolsetSubsystem;
	if (!Z_Registration_Info_UClass_USlateInspectorToolsetSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SlateInspectorToolsetSubsystem"),
			Z_Registration_Info_UClass_USlateInspectorToolsetSubsystem.InnerSingleton,
			StaticRegisterNativesUSlateInspectorToolsetSubsystem,
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
	return Z_Registration_Info_UClass_USlateInspectorToolsetSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_USlateInspectorToolsetSubsystem_NoRegister()
{
	return USlateInspectorToolsetSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USlateInspectorToolsetSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "SlateInspectorToolsetSubsystem.h" },
		{ "ModuleRelativePath", "Public/SlateInspectorToolsetSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class USlateInspectorToolsetSubsystem constinit property declarations **********
// ********** End Class USlateInspectorToolsetSubsystem constinit property declarations ************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USlateInspectorToolsetSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USlateInspectorToolsetSubsystem_Statics
UObject* (*const Z_Construct_UClass_USlateInspectorToolsetSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEditorSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_SlateInspectorToolset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USlateInspectorToolsetSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USlateInspectorToolsetSubsystem_Statics::ClassParams = {
	&USlateInspectorToolsetSubsystem::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USlateInspectorToolsetSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_USlateInspectorToolsetSubsystem_Statics::Class_MetaDataParams)
};
void USlateInspectorToolsetSubsystem::StaticRegisterNativesUSlateInspectorToolsetSubsystem()
{
}
UClass* Z_Construct_UClass_USlateInspectorToolsetSubsystem()
{
	if (!Z_Registration_Info_UClass_USlateInspectorToolsetSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USlateInspectorToolsetSubsystem.OuterSingleton, Z_Construct_UClass_USlateInspectorToolsetSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USlateInspectorToolsetSubsystem.OuterSingleton;
}
USlateInspectorToolsetSubsystem::USlateInspectorToolsetSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USlateInspectorToolsetSubsystem);
USlateInspectorToolsetSubsystem::~USlateInspectorToolsetSubsystem() {}
// ********** End Class USlateInspectorToolsetSubsystem ********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_SlateInspectorToolset_Source_SlateInspectorToolset_Public_SlateInspectorToolsetSubsystem_h__Script_SlateInspectorToolset_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USlateInspectorToolsetSubsystem, USlateInspectorToolsetSubsystem::StaticClass, TEXT("USlateInspectorToolsetSubsystem"), &Z_Registration_Info_UClass_USlateInspectorToolsetSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USlateInspectorToolsetSubsystem), 1774596942U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_SlateInspectorToolset_Source_SlateInspectorToolset_Public_SlateInspectorToolsetSubsystem_h__Script_SlateInspectorToolset_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_SlateInspectorToolset_Source_SlateInspectorToolset_Public_SlateInspectorToolsetSubsystem_h__Script_SlateInspectorToolset_3869285625{
	TEXT("/Script/SlateInspectorToolset"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_SlateInspectorToolset_Source_SlateInspectorToolset_Public_SlateInspectorToolsetSubsystem_h__Script_SlateInspectorToolset_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_SlateInspectorToolset_Source_SlateInspectorToolset_Public_SlateInspectorToolsetSubsystem_h__Script_SlateInspectorToolset_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
