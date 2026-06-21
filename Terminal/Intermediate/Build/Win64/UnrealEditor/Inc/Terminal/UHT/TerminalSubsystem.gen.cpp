// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TerminalSubsystem.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeTerminalSubsystem() {}

// ********** Begin Cross Module References ********************************************************
EDITORSUBSYSTEM_API UClass* Z_Construct_UClass_UEditorSubsystem();
TERMINAL_API UClass* Z_Construct_UClass_UTerminalSubsystem();
TERMINAL_API UClass* Z_Construct_UClass_UTerminalSubsystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_Terminal();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UTerminalSubsystem *******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UTerminalSubsystem;
UClass* UTerminalSubsystem::GetPrivateStaticClass()
{
	using TClass = UTerminalSubsystem;
	if (!Z_Registration_Info_UClass_UTerminalSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("TerminalSubsystem"),
			Z_Registration_Info_UClass_UTerminalSubsystem.InnerSingleton,
			StaticRegisterNativesUTerminalSubsystem,
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
	return Z_Registration_Info_UClass_UTerminalSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UTerminalSubsystem_NoRegister()
{
	return UTerminalSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UTerminalSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Editor subsystem that manages terminal sessions and color schemes.\n */" },
#endif
		{ "IncludePath", "TerminalSubsystem.h" },
		{ "ModuleRelativePath", "Public/TerminalSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Editor subsystem that manages terminal sessions and color schemes." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UTerminalSubsystem constinit property declarations ***********************
// ********** End Class UTerminalSubsystem constinit property declarations *************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTerminalSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UTerminalSubsystem_Statics
UObject* (*const Z_Construct_UClass_UTerminalSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEditorSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_Terminal,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTerminalSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UTerminalSubsystem_Statics::ClassParams = {
	&UTerminalSubsystem::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTerminalSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UTerminalSubsystem_Statics::Class_MetaDataParams)
};
void UTerminalSubsystem::StaticRegisterNativesUTerminalSubsystem()
{
}
UClass* Z_Construct_UClass_UTerminalSubsystem()
{
	if (!Z_Registration_Info_UClass_UTerminalSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTerminalSubsystem.OuterSingleton, Z_Construct_UClass_UTerminalSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UTerminalSubsystem.OuterSingleton;
}
UTerminalSubsystem::UTerminalSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UTerminalSubsystem);
UTerminalSubsystem::~UTerminalSubsystem() {}
// ********** End Class UTerminalSubsystem *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Terminal_Source_Terminal_Public_TerminalSubsystem_h__Script_Terminal_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UTerminalSubsystem, UTerminalSubsystem::StaticClass, TEXT("UTerminalSubsystem"), &Z_Registration_Info_UClass_UTerminalSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTerminalSubsystem), 2561478447U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Terminal_Source_Terminal_Public_TerminalSubsystem_h__Script_Terminal_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Terminal_Source_Terminal_Public_TerminalSubsystem_h__Script_Terminal_655184024{
	TEXT("/Script/Terminal"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Terminal_Source_Terminal_Public_TerminalSubsystem_h__Script_Terminal_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Terminal_Source_Terminal_Public_TerminalSubsystem_h__Script_Terminal_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
