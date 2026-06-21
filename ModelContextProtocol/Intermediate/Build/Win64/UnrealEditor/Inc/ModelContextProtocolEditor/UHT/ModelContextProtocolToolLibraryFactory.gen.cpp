// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ModelContextProtocolToolLibraryFactory.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeModelContextProtocolToolLibraryFactory() {}

// ********** Begin Cross Module References ********************************************************
MODELCONTEXTPROTOCOLEDITOR_API UClass* Z_Construct_UClass_UModelContextProtocolEditorToolLibraryFactory();
MODELCONTEXTPROTOCOLEDITOR_API UClass* Z_Construct_UClass_UModelContextProtocolEditorToolLibraryFactory_NoRegister();
MODELCONTEXTPROTOCOLEDITOR_API UClass* Z_Construct_UClass_UModelContextProtocolToolLibraryFactory();
MODELCONTEXTPROTOCOLEDITOR_API UClass* Z_Construct_UClass_UModelContextProtocolToolLibraryFactory_NoRegister();
UNREALED_API UClass* Z_Construct_UClass_UBlueprintFactory();
UPackage* Z_Construct_UPackage__Script_ModelContextProtocolEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UModelContextProtocolToolLibraryFactory **********************************
FClassRegistrationInfo Z_Registration_Info_UClass_UModelContextProtocolToolLibraryFactory;
UClass* UModelContextProtocolToolLibraryFactory::GetPrivateStaticClass()
{
	using TClass = UModelContextProtocolToolLibraryFactory;
	if (!Z_Registration_Info_UClass_UModelContextProtocolToolLibraryFactory.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ModelContextProtocolToolLibraryFactory"),
			Z_Registration_Info_UClass_UModelContextProtocolToolLibraryFactory.InnerSingleton,
			StaticRegisterNativesUModelContextProtocolToolLibraryFactory,
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
	return Z_Registration_Info_UClass_UModelContextProtocolToolLibraryFactory.InnerSingleton;
}
UClass* Z_Construct_UClass_UModelContextProtocolToolLibraryFactory_NoRegister()
{
	return UModelContextProtocolToolLibraryFactory::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UModelContextProtocolToolLibraryFactory_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Object" },
		{ "IncludePath", "ModelContextProtocolToolLibraryFactory.h" },
		{ "ModuleRelativePath", "Public/ModelContextProtocolToolLibraryFactory.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif // WITH_METADATA

// ********** Begin Class UModelContextProtocolToolLibraryFactory constinit property declarations **
// ********** End Class UModelContextProtocolToolLibraryFactory constinit property declarations ****
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UModelContextProtocolToolLibraryFactory>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UModelContextProtocolToolLibraryFactory_Statics
UObject* (*const Z_Construct_UClass_UModelContextProtocolToolLibraryFactory_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFactory,
	(UObject* (*)())Z_Construct_UPackage__Script_ModelContextProtocolEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UModelContextProtocolToolLibraryFactory_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UModelContextProtocolToolLibraryFactory_Statics::ClassParams = {
	&UModelContextProtocolToolLibraryFactory::StaticClass,
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
	0x000820A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UModelContextProtocolToolLibraryFactory_Statics::Class_MetaDataParams), Z_Construct_UClass_UModelContextProtocolToolLibraryFactory_Statics::Class_MetaDataParams)
};
void UModelContextProtocolToolLibraryFactory::StaticRegisterNativesUModelContextProtocolToolLibraryFactory()
{
}
UClass* Z_Construct_UClass_UModelContextProtocolToolLibraryFactory()
{
	if (!Z_Registration_Info_UClass_UModelContextProtocolToolLibraryFactory.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UModelContextProtocolToolLibraryFactory.OuterSingleton, Z_Construct_UClass_UModelContextProtocolToolLibraryFactory_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UModelContextProtocolToolLibraryFactory.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UModelContextProtocolToolLibraryFactory);
UModelContextProtocolToolLibraryFactory::~UModelContextProtocolToolLibraryFactory() {}
// ********** End Class UModelContextProtocolToolLibraryFactory ************************************

// ********** Begin Class UModelContextProtocolEditorToolLibraryFactory ****************************
FClassRegistrationInfo Z_Registration_Info_UClass_UModelContextProtocolEditorToolLibraryFactory;
UClass* UModelContextProtocolEditorToolLibraryFactory::GetPrivateStaticClass()
{
	using TClass = UModelContextProtocolEditorToolLibraryFactory;
	if (!Z_Registration_Info_UClass_UModelContextProtocolEditorToolLibraryFactory.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ModelContextProtocolEditorToolLibraryFactory"),
			Z_Registration_Info_UClass_UModelContextProtocolEditorToolLibraryFactory.InnerSingleton,
			StaticRegisterNativesUModelContextProtocolEditorToolLibraryFactory,
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
	return Z_Registration_Info_UClass_UModelContextProtocolEditorToolLibraryFactory.InnerSingleton;
}
UClass* Z_Construct_UClass_UModelContextProtocolEditorToolLibraryFactory_NoRegister()
{
	return UModelContextProtocolEditorToolLibraryFactory::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UModelContextProtocolEditorToolLibraryFactory_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Editor-specific UModelContextProtocolToolLibrary factory which produces a UModelContextProtocolEditorToolLibraryBlueprint editor utility blueprint,\n * allowing editor-specific BP node usage in tool function implementations.\n */" },
#endif
		{ "HideCategories", "Object" },
		{ "IncludePath", "ModelContextProtocolToolLibraryFactory.h" },
		{ "ModuleRelativePath", "Public/ModelContextProtocolToolLibraryFactory.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Editor-specific UModelContextProtocolToolLibrary factory which produces a UModelContextProtocolEditorToolLibraryBlueprint editor utility blueprint,\nallowing editor-specific BP node usage in tool function implementations." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UModelContextProtocolEditorToolLibraryFactory constinit property declarations 
// ********** End Class UModelContextProtocolEditorToolLibraryFactory constinit property declarations 
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UModelContextProtocolEditorToolLibraryFactory>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UModelContextProtocolEditorToolLibraryFactory_Statics
UObject* (*const Z_Construct_UClass_UModelContextProtocolEditorToolLibraryFactory_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UModelContextProtocolToolLibraryFactory,
	(UObject* (*)())Z_Construct_UPackage__Script_ModelContextProtocolEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UModelContextProtocolEditorToolLibraryFactory_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UModelContextProtocolEditorToolLibraryFactory_Statics::ClassParams = {
	&UModelContextProtocolEditorToolLibraryFactory::StaticClass,
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
	0x000820A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UModelContextProtocolEditorToolLibraryFactory_Statics::Class_MetaDataParams), Z_Construct_UClass_UModelContextProtocolEditorToolLibraryFactory_Statics::Class_MetaDataParams)
};
void UModelContextProtocolEditorToolLibraryFactory::StaticRegisterNativesUModelContextProtocolEditorToolLibraryFactory()
{
}
UClass* Z_Construct_UClass_UModelContextProtocolEditorToolLibraryFactory()
{
	if (!Z_Registration_Info_UClass_UModelContextProtocolEditorToolLibraryFactory.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UModelContextProtocolEditorToolLibraryFactory.OuterSingleton, Z_Construct_UClass_UModelContextProtocolEditorToolLibraryFactory_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UModelContextProtocolEditorToolLibraryFactory.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UModelContextProtocolEditorToolLibraryFactory);
UModelContextProtocolEditorToolLibraryFactory::~UModelContextProtocolEditorToolLibraryFactory() {}
// ********** End Class UModelContextProtocolEditorToolLibraryFactory ******************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEditor_Public_ModelContextProtocolToolLibraryFactory_h__Script_ModelContextProtocolEditor_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UModelContextProtocolToolLibraryFactory, UModelContextProtocolToolLibraryFactory::StaticClass, TEXT("UModelContextProtocolToolLibraryFactory"), &Z_Registration_Info_UClass_UModelContextProtocolToolLibraryFactory, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UModelContextProtocolToolLibraryFactory), 475110147U) },
		{ Z_Construct_UClass_UModelContextProtocolEditorToolLibraryFactory, UModelContextProtocolEditorToolLibraryFactory::StaticClass, TEXT("UModelContextProtocolEditorToolLibraryFactory"), &Z_Registration_Info_UClass_UModelContextProtocolEditorToolLibraryFactory, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UModelContextProtocolEditorToolLibraryFactory), 1102070986U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEditor_Public_ModelContextProtocolToolLibraryFactory_h__Script_ModelContextProtocolEditor_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEditor_Public_ModelContextProtocolToolLibraryFactory_h__Script_ModelContextProtocolEditor_2193306803{
	TEXT("/Script/ModelContextProtocolEditor"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEditor_Public_ModelContextProtocolToolLibraryFactory_h__Script_ModelContextProtocolEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEditor_Public_ModelContextProtocolToolLibraryFactory_h__Script_ModelContextProtocolEditor_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
