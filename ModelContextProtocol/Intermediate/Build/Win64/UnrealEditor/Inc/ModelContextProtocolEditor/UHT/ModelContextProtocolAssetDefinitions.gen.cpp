// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ModelContextProtocolAssetDefinitions.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeModelContextProtocolAssetDefinitions() {}

// ********** Begin Cross Module References ********************************************************
ENGINEASSETDEFINITIONS_API UClass* Z_Construct_UClass_UAssetDefinition_Blueprint();
MODELCONTEXTPROTOCOLEDITOR_API UClass* Z_Construct_UClass_UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint();
MODELCONTEXTPROTOCOLEDITOR_API UClass* Z_Construct_UClass_UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint_NoRegister();
MODELCONTEXTPROTOCOLEDITOR_API UClass* Z_Construct_UClass_UAssetDefinition_ModelContextProtocolToolLibraryBlueprint();
MODELCONTEXTPROTOCOLEDITOR_API UClass* Z_Construct_UClass_UAssetDefinition_ModelContextProtocolToolLibraryBlueprint_NoRegister();
UPackage* Z_Construct_UPackage__Script_ModelContextProtocolEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UAssetDefinition_ModelContextProtocolToolLibraryBlueprint ****************
FClassRegistrationInfo Z_Registration_Info_UClass_UAssetDefinition_ModelContextProtocolToolLibraryBlueprint;
UClass* UAssetDefinition_ModelContextProtocolToolLibraryBlueprint::GetPrivateStaticClass()
{
	using TClass = UAssetDefinition_ModelContextProtocolToolLibraryBlueprint;
	if (!Z_Registration_Info_UClass_UAssetDefinition_ModelContextProtocolToolLibraryBlueprint.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("AssetDefinition_ModelContextProtocolToolLibraryBlueprint"),
			Z_Registration_Info_UClass_UAssetDefinition_ModelContextProtocolToolLibraryBlueprint.InnerSingleton,
			StaticRegisterNativesUAssetDefinition_ModelContextProtocolToolLibraryBlueprint,
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
	return Z_Registration_Info_UClass_UAssetDefinition_ModelContextProtocolToolLibraryBlueprint.InnerSingleton;
}
UClass* Z_Construct_UClass_UAssetDefinition_ModelContextProtocolToolLibraryBlueprint_NoRegister()
{
	return UAssetDefinition_ModelContextProtocolToolLibraryBlueprint::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UAssetDefinition_ModelContextProtocolToolLibraryBlueprint_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "ModelContextProtocolAssetDefinitions.h" },
		{ "ModuleRelativePath", "Public/ModelContextProtocolAssetDefinitions.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UAssetDefinition_ModelContextProtocolToolLibraryBlueprint constinit property declarations 
// ********** End Class UAssetDefinition_ModelContextProtocolToolLibraryBlueprint constinit property declarations 
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAssetDefinition_ModelContextProtocolToolLibraryBlueprint>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UAssetDefinition_ModelContextProtocolToolLibraryBlueprint_Statics
UObject* (*const Z_Construct_UClass_UAssetDefinition_ModelContextProtocolToolLibraryBlueprint_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAssetDefinition_Blueprint,
	(UObject* (*)())Z_Construct_UPackage__Script_ModelContextProtocolEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAssetDefinition_ModelContextProtocolToolLibraryBlueprint_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAssetDefinition_ModelContextProtocolToolLibraryBlueprint_Statics::ClassParams = {
	&UAssetDefinition_ModelContextProtocolToolLibraryBlueprint::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAssetDefinition_ModelContextProtocolToolLibraryBlueprint_Statics::Class_MetaDataParams), Z_Construct_UClass_UAssetDefinition_ModelContextProtocolToolLibraryBlueprint_Statics::Class_MetaDataParams)
};
void UAssetDefinition_ModelContextProtocolToolLibraryBlueprint::StaticRegisterNativesUAssetDefinition_ModelContextProtocolToolLibraryBlueprint()
{
}
UClass* Z_Construct_UClass_UAssetDefinition_ModelContextProtocolToolLibraryBlueprint()
{
	if (!Z_Registration_Info_UClass_UAssetDefinition_ModelContextProtocolToolLibraryBlueprint.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAssetDefinition_ModelContextProtocolToolLibraryBlueprint.OuterSingleton, Z_Construct_UClass_UAssetDefinition_ModelContextProtocolToolLibraryBlueprint_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAssetDefinition_ModelContextProtocolToolLibraryBlueprint.OuterSingleton;
}
UAssetDefinition_ModelContextProtocolToolLibraryBlueprint::UAssetDefinition_ModelContextProtocolToolLibraryBlueprint() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UAssetDefinition_ModelContextProtocolToolLibraryBlueprint);
UAssetDefinition_ModelContextProtocolToolLibraryBlueprint::~UAssetDefinition_ModelContextProtocolToolLibraryBlueprint() {}
// ********** End Class UAssetDefinition_ModelContextProtocolToolLibraryBlueprint ******************

// ********** Begin Class UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint **********
FClassRegistrationInfo Z_Registration_Info_UClass_UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint;
UClass* UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint::GetPrivateStaticClass()
{
	using TClass = UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint;
	if (!Z_Registration_Info_UClass_UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("AssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint"),
			Z_Registration_Info_UClass_UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint.InnerSingleton,
			StaticRegisterNativesUAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint,
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
	return Z_Registration_Info_UClass_UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint.InnerSingleton;
}
UClass* Z_Construct_UClass_UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint_NoRegister()
{
	return UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "ModelContextProtocolAssetDefinitions.h" },
		{ "ModuleRelativePath", "Public/ModelContextProtocolAssetDefinitions.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint constinit property declarations 
// ********** End Class UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint constinit property declarations 
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint_Statics
UObject* (*const Z_Construct_UClass_UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAssetDefinition_Blueprint,
	(UObject* (*)())Z_Construct_UPackage__Script_ModelContextProtocolEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint_Statics::ClassParams = {
	&UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint_Statics::Class_MetaDataParams), Z_Construct_UClass_UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint_Statics::Class_MetaDataParams)
};
void UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint::StaticRegisterNativesUAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint()
{
}
UClass* Z_Construct_UClass_UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint()
{
	if (!Z_Registration_Info_UClass_UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint.OuterSingleton, Z_Construct_UClass_UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint.OuterSingleton;
}
UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint::UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint);
UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint::~UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint() {}
// ********** End Class UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint ************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEditor_Public_ModelContextProtocolAssetDefinitions_h__Script_ModelContextProtocolEditor_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAssetDefinition_ModelContextProtocolToolLibraryBlueprint, UAssetDefinition_ModelContextProtocolToolLibraryBlueprint::StaticClass, TEXT("UAssetDefinition_ModelContextProtocolToolLibraryBlueprint"), &Z_Registration_Info_UClass_UAssetDefinition_ModelContextProtocolToolLibraryBlueprint, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAssetDefinition_ModelContextProtocolToolLibraryBlueprint), 990133553U) },
		{ Z_Construct_UClass_UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint, UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint::StaticClass, TEXT("UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint"), &Z_Registration_Info_UClass_UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAssetDefinition_ModelContextProtocolEditorToolLibraryBlueprint), 1563070203U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEditor_Public_ModelContextProtocolAssetDefinitions_h__Script_ModelContextProtocolEditor_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEditor_Public_ModelContextProtocolAssetDefinitions_h__Script_ModelContextProtocolEditor_1609199303{
	TEXT("/Script/ModelContextProtocolEditor"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEditor_Public_ModelContextProtocolAssetDefinitions_h__Script_ModelContextProtocolEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEditor_Public_ModelContextProtocolAssetDefinitions_h__Script_ModelContextProtocolEditor_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
