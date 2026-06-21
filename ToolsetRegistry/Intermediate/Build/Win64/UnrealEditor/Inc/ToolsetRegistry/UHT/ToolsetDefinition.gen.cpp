// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ToolsetRegistry/ToolsetDefinition.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeToolsetDefinition() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition_NoRegister();
UPackage* Z_Construct_UPackage__Script_ToolsetRegistry();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UToolsetDefinition *******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UToolsetDefinition;
UClass* UToolsetDefinition::GetPrivateStaticClass()
{
	using TClass = UToolsetDefinition;
	if (!Z_Registration_Info_UClass_UToolsetDefinition.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ToolsetDefinition"),
			Z_Registration_Info_UClass_UToolsetDefinition.InnerSingleton,
			StaticRegisterNativesUToolsetDefinition,
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
	return Z_Registration_Info_UClass_UToolsetDefinition.InnerSingleton;
}
UClass* Z_Construct_UClass_UToolsetDefinition_NoRegister()
{
	return UToolsetDefinition::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UToolsetDefinition_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// This is the common base class for Toolsets defined as UObjects.\n// UFunctions that define tools in this class should be static functions \n//   and be marked with meta = (AICallable). This is used both by UHT and the runtime UToolRegistry.\n// UFunctions which should be ignored by tools should be marked with meta = (AIIgnore) \n//   in order to silence errors about invalid UFunctions\n" },
#endif
		{ "IncludePath", "ToolsetRegistry/ToolsetDefinition.h" },
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolsetDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "This is the common base class for Toolsets defined as UObjects.\nUFunctions that define tools in this class should be static functions\n  and be marked with meta = (AICallable). This is used both by UHT and the runtime UToolRegistry.\nUFunctions which should be ignored by tools should be marked with meta = (AIIgnore)\n  in order to silence errors about invalid UFunctions" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UToolsetDefinition constinit property declarations ***********************
// ********** End Class UToolsetDefinition constinit property declarations *************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UToolsetDefinition>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UToolsetDefinition_Statics
UObject* (*const Z_Construct_UClass_UToolsetDefinition_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_ToolsetRegistry,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UToolsetDefinition_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UToolsetDefinition_Statics::ClassParams = {
	&UToolsetDefinition::StaticClass,
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
	0x000800A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UToolsetDefinition_Statics::Class_MetaDataParams), Z_Construct_UClass_UToolsetDefinition_Statics::Class_MetaDataParams)
};
void UToolsetDefinition::StaticRegisterNativesUToolsetDefinition()
{
}
UClass* Z_Construct_UClass_UToolsetDefinition()
{
	if (!Z_Registration_Info_UClass_UToolsetDefinition.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UToolsetDefinition.OuterSingleton, Z_Construct_UClass_UToolsetDefinition_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UToolsetDefinition.OuterSingleton;
}
UToolsetDefinition::UToolsetDefinition(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UToolsetDefinition);
UToolsetDefinition::~UToolsetDefinition() {}
// ********** End Class UToolsetDefinition *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetDefinition_h__Script_ToolsetRegistry_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UToolsetDefinition, UToolsetDefinition::StaticClass, TEXT("UToolsetDefinition"), &Z_Registration_Info_UClass_UToolsetDefinition, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UToolsetDefinition), 1751888271U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetDefinition_h__Script_ToolsetRegistry_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetDefinition_h__Script_ToolsetRegistry_1734678216{
	TEXT("/Script/ToolsetRegistry"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetDefinition_h__Script_ToolsetRegistry_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetDefinition_h__Script_ToolsetRegistry_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
