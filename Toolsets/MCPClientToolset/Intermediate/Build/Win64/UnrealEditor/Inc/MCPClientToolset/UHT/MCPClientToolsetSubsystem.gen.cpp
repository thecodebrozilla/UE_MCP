// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MCPClientToolset/MCPClientToolsetSubsystem.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeMCPClientToolsetSubsystem() {}

// ********** Begin Cross Module References ********************************************************
EDITORSUBSYSTEM_API UClass* Z_Construct_UClass_UEditorSubsystem();
MCPCLIENTTOOLSET_API UClass* Z_Construct_UClass_UMCPClientToolsetSubsystem();
MCPCLIENTTOOLSET_API UClass* Z_Construct_UClass_UMCPClientToolsetSubsystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_MCPClientToolset();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UMCPClientToolsetSubsystem ***********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UMCPClientToolsetSubsystem;
UClass* UMCPClientToolsetSubsystem::GetPrivateStaticClass()
{
	using TClass = UMCPClientToolsetSubsystem;
	if (!Z_Registration_Info_UClass_UMCPClientToolsetSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("MCPClientToolsetSubsystem"),
			Z_Registration_Info_UClass_UMCPClientToolsetSubsystem.InnerSingleton,
			StaticRegisterNativesUMCPClientToolsetSubsystem,
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
	return Z_Registration_Info_UClass_UMCPClientToolsetSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UMCPClientToolsetSubsystem_NoRegister()
{
	return UMCPClientToolsetSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UMCPClientToolsetSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Editor subsystem that reads UMCPToolsetSettings on startup, creates FMCPClientToolset\n *  instances, and registers them with UToolsetRegistrySubsystem. */" },
#endif
		{ "IncludePath", "MCPClientToolset/MCPClientToolsetSubsystem.h" },
		{ "ModuleRelativePath", "Public/MCPClientToolset/MCPClientToolsetSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Editor subsystem that reads UMCPToolsetSettings on startup, creates FMCPClientToolset\ninstances, and registers them with UToolsetRegistrySubsystem." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UMCPClientToolsetSubsystem constinit property declarations ***************
// ********** End Class UMCPClientToolsetSubsystem constinit property declarations *****************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMCPClientToolsetSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UMCPClientToolsetSubsystem_Statics
UObject* (*const Z_Construct_UClass_UMCPClientToolsetSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEditorSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_MCPClientToolset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMCPClientToolsetSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMCPClientToolsetSubsystem_Statics::ClassParams = {
	&UMCPClientToolsetSubsystem::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMCPClientToolsetSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UMCPClientToolsetSubsystem_Statics::Class_MetaDataParams)
};
void UMCPClientToolsetSubsystem::StaticRegisterNativesUMCPClientToolsetSubsystem()
{
}
UClass* Z_Construct_UClass_UMCPClientToolsetSubsystem()
{
	if (!Z_Registration_Info_UClass_UMCPClientToolsetSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMCPClientToolsetSubsystem.OuterSingleton, Z_Construct_UClass_UMCPClientToolsetSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMCPClientToolsetSubsystem.OuterSingleton;
}
UMCPClientToolsetSubsystem::UMCPClientToolsetSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UMCPClientToolsetSubsystem);
UMCPClientToolsetSubsystem::~UMCPClientToolsetSubsystem() {}
// ********** End Class UMCPClientToolsetSubsystem *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_MCPClientToolset_Source_MCPClientToolset_Public_MCPClientToolset_MCPClientToolsetSubsystem_h__Script_MCPClientToolset_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMCPClientToolsetSubsystem, UMCPClientToolsetSubsystem::StaticClass, TEXT("UMCPClientToolsetSubsystem"), &Z_Registration_Info_UClass_UMCPClientToolsetSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMCPClientToolsetSubsystem), 983199889U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_MCPClientToolset_Source_MCPClientToolset_Public_MCPClientToolset_MCPClientToolsetSubsystem_h__Script_MCPClientToolset_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_MCPClientToolset_Source_MCPClientToolset_Public_MCPClientToolset_MCPClientToolsetSubsystem_h__Script_MCPClientToolset_347285891{
	TEXT("/Script/MCPClientToolset"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_MCPClientToolset_Source_MCPClientToolset_Public_MCPClientToolset_MCPClientToolsetSubsystem_h__Script_MCPClientToolset_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_MCPClientToolset_Source_MCPClientToolset_Public_MCPClientToolset_MCPClientToolsetSubsystem_h__Script_MCPClientToolset_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
