// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LiveCodingToolsetSubsystem.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeLiveCodingToolsetSubsystem() {}

// ********** Begin Cross Module References ********************************************************
EDITORSUBSYSTEM_API UClass* Z_Construct_UClass_UEditorSubsystem();
LIVECODINGTOOLSET_API UClass* Z_Construct_UClass_ULiveCodingToolsetSubsystem();
LIVECODINGTOOLSET_API UClass* Z_Construct_UClass_ULiveCodingToolsetSubsystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_LiveCodingToolset();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ULiveCodingToolsetSubsystem **********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_ULiveCodingToolsetSubsystem;
UClass* ULiveCodingToolsetSubsystem::GetPrivateStaticClass()
{
	using TClass = ULiveCodingToolsetSubsystem;
	if (!Z_Registration_Info_UClass_ULiveCodingToolsetSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("LiveCodingToolsetSubsystem"),
			Z_Registration_Info_UClass_ULiveCodingToolsetSubsystem.InnerSingleton,
			StaticRegisterNativesULiveCodingToolsetSubsystem,
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
	return Z_Registration_Info_UClass_ULiveCodingToolsetSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_ULiveCodingToolsetSubsystem_NoRegister()
{
	return ULiveCodingToolsetSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ULiveCodingToolsetSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Registers the LiveCodingToolset with UToolsetRegistry for the lifetime of the editor.\n * Registration can be toggled at runtime via the LiveCodingToolset.Enable CVar.\n */" },
#endif
		{ "IncludePath", "LiveCodingToolsetSubsystem.h" },
		{ "ModuleRelativePath", "Public/LiveCodingToolsetSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Registers the LiveCodingToolset with UToolsetRegistry for the lifetime of the editor.\nRegistration can be toggled at runtime via the LiveCodingToolset.Enable CVar." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class ULiveCodingToolsetSubsystem constinit property declarations **************
// ********** End Class ULiveCodingToolsetSubsystem constinit property declarations ****************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULiveCodingToolsetSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_ULiveCodingToolsetSubsystem_Statics
UObject* (*const Z_Construct_UClass_ULiveCodingToolsetSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEditorSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_LiveCodingToolset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULiveCodingToolsetSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULiveCodingToolsetSubsystem_Statics::ClassParams = {
	&ULiveCodingToolsetSubsystem::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULiveCodingToolsetSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_ULiveCodingToolsetSubsystem_Statics::Class_MetaDataParams)
};
void ULiveCodingToolsetSubsystem::StaticRegisterNativesULiveCodingToolsetSubsystem()
{
}
UClass* Z_Construct_UClass_ULiveCodingToolsetSubsystem()
{
	if (!Z_Registration_Info_UClass_ULiveCodingToolsetSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULiveCodingToolsetSubsystem.OuterSingleton, Z_Construct_UClass_ULiveCodingToolsetSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULiveCodingToolsetSubsystem.OuterSingleton;
}
ULiveCodingToolsetSubsystem::ULiveCodingToolsetSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ULiveCodingToolsetSubsystem);
ULiveCodingToolsetSubsystem::~ULiveCodingToolsetSubsystem() {}
// ********** End Class ULiveCodingToolsetSubsystem ************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_LiveCodingToolset_Source_LiveCodingToolset_Public_LiveCodingToolsetSubsystem_h__Script_LiveCodingToolset_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULiveCodingToolsetSubsystem, ULiveCodingToolsetSubsystem::StaticClass, TEXT("ULiveCodingToolsetSubsystem"), &Z_Registration_Info_UClass_ULiveCodingToolsetSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULiveCodingToolsetSubsystem), 4164181810U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_LiveCodingToolset_Source_LiveCodingToolset_Public_LiveCodingToolsetSubsystem_h__Script_LiveCodingToolset_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_LiveCodingToolset_Source_LiveCodingToolset_Public_LiveCodingToolsetSubsystem_h__Script_LiveCodingToolset_2196339882{
	TEXT("/Script/LiveCodingToolset"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_LiveCodingToolset_Source_LiveCodingToolset_Public_LiveCodingToolsetSubsystem_h__Script_LiveCodingToolset_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_LiveCodingToolset_Source_LiveCodingToolset_Public_LiveCodingToolsetSubsystem_h__Script_LiveCodingToolset_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
