// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ModelContextProtocolEditorToolLibrary.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeModelContextProtocolEditorToolLibrary() {}

// ********** Begin Cross Module References ********************************************************
BLUTILITY_API UClass* Z_Construct_UClass_UEditorUtilityBlueprint();
MODELCONTEXTPROTOCOLEDITOR_API UClass* Z_Construct_UClass_UModelContextProtocolEditorToolLibrary();
MODELCONTEXTPROTOCOLEDITOR_API UClass* Z_Construct_UClass_UModelContextProtocolEditorToolLibrary_NoRegister();
MODELCONTEXTPROTOCOLEDITOR_API UClass* Z_Construct_UClass_UModelContextProtocolEditorToolLibraryBlueprint();
MODELCONTEXTPROTOCOLEDITOR_API UClass* Z_Construct_UClass_UModelContextProtocolEditorToolLibraryBlueprint_NoRegister();
MODELCONTEXTPROTOCOLENGINE_API UClass* Z_Construct_UClass_UModelContextProtocolToolLibrary();
UPackage* Z_Construct_UPackage__Script_ModelContextProtocolEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UModelContextProtocolEditorToolLibrary ***********************************
FClassRegistrationInfo Z_Registration_Info_UClass_UModelContextProtocolEditorToolLibrary;
UClass* UModelContextProtocolEditorToolLibrary::GetPrivateStaticClass()
{
	using TClass = UModelContextProtocolEditorToolLibrary;
	if (!Z_Registration_Info_UClass_UModelContextProtocolEditorToolLibrary.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ModelContextProtocolEditorToolLibrary"),
			Z_Registration_Info_UClass_UModelContextProtocolEditorToolLibrary.InnerSingleton,
			StaticRegisterNativesUModelContextProtocolEditorToolLibrary,
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
	return Z_Registration_Info_UClass_UModelContextProtocolEditorToolLibrary.InnerSingleton;
}
UClass* Z_Construct_UClass_UModelContextProtocolEditorToolLibrary_NoRegister()
{
	return UModelContextProtocolEditorToolLibrary::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UModelContextProtocolEditorToolLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Automatically registers an FModelContextProtocolLibraryTool for each public UFUNCTION on module load, using cached / cooked meta-data.\n * \n * UBlueprintFunctionLibrary specialization allows caching and cooking otherwise-editor-only UFUNCTION descriptions and parameter meta-data.\n *\n * Can be subclassed in either C++ or Blueprints.\n *\n * For Blueprints:\x09""Create via Content Browser -> Add -> MCP Tool Library, then simply define public functions with a doxygen-style\n *\x09\x09\x09\x09\x09""function tooltip.   \n */" },
#endif
		{ "IncludePath", "ModelContextProtocolEditorToolLibrary.h" },
		{ "ModuleRelativePath", "Public/ModelContextProtocolEditorToolLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Automatically registers an FModelContextProtocolLibraryTool for each public UFUNCTION on module load, using cached / cooked meta-data.\n\nUBlueprintFunctionLibrary specialization allows caching and cooking otherwise-editor-only UFUNCTION descriptions and parameter meta-data.\n\nCan be subclassed in either C++ or Blueprints.\n\nFor Blueprints:     Create via Content Browser -> Add -> MCP Tool Library, then simply define public functions with a doxygen-style\n                                    function tooltip." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UModelContextProtocolEditorToolLibrary constinit property declarations ***
// ********** End Class UModelContextProtocolEditorToolLibrary constinit property declarations *****
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UModelContextProtocolEditorToolLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UModelContextProtocolEditorToolLibrary_Statics
UObject* (*const Z_Construct_UClass_UModelContextProtocolEditorToolLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UModelContextProtocolToolLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_ModelContextProtocolEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UModelContextProtocolEditorToolLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UModelContextProtocolEditorToolLibrary_Statics::ClassParams = {
	&UModelContextProtocolEditorToolLibrary::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UModelContextProtocolEditorToolLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UModelContextProtocolEditorToolLibrary_Statics::Class_MetaDataParams)
};
void UModelContextProtocolEditorToolLibrary::StaticRegisterNativesUModelContextProtocolEditorToolLibrary()
{
}
UClass* Z_Construct_UClass_UModelContextProtocolEditorToolLibrary()
{
	if (!Z_Registration_Info_UClass_UModelContextProtocolEditorToolLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UModelContextProtocolEditorToolLibrary.OuterSingleton, Z_Construct_UClass_UModelContextProtocolEditorToolLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UModelContextProtocolEditorToolLibrary.OuterSingleton;
}
UModelContextProtocolEditorToolLibrary::UModelContextProtocolEditorToolLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UModelContextProtocolEditorToolLibrary);
UModelContextProtocolEditorToolLibrary::~UModelContextProtocolEditorToolLibrary() {}
// ********** End Class UModelContextProtocolEditorToolLibrary *************************************

// ********** Begin Class UModelContextProtocolEditorToolLibraryBlueprint **************************
FClassRegistrationInfo Z_Registration_Info_UClass_UModelContextProtocolEditorToolLibraryBlueprint;
UClass* UModelContextProtocolEditorToolLibraryBlueprint::GetPrivateStaticClass()
{
	using TClass = UModelContextProtocolEditorToolLibraryBlueprint;
	if (!Z_Registration_Info_UClass_UModelContextProtocolEditorToolLibraryBlueprint.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ModelContextProtocolEditorToolLibraryBlueprint"),
			Z_Registration_Info_UClass_UModelContextProtocolEditorToolLibraryBlueprint.InnerSingleton,
			StaticRegisterNativesUModelContextProtocolEditorToolLibraryBlueprint,
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
	return Z_Registration_Info_UClass_UModelContextProtocolEditorToolLibraryBlueprint.InnerSingleton;
}
UClass* Z_Construct_UClass_UModelContextProtocolEditorToolLibraryBlueprint_NoRegister()
{
	return UModelContextProtocolEditorToolLibraryBlueprint::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UModelContextProtocolEditorToolLibraryBlueprint_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Editor-specific UModelContextProtocolToolLibrary function library editor utility blueprint, allowing Editor-only BP node use in MCP tool functions.\n * @see UModelContextProtocolToolLibraryBlueprint\n */" },
#endif
		{ "IncludePath", "ModelContextProtocolEditorToolLibrary.h" },
		{ "ModuleRelativePath", "Public/ModelContextProtocolEditorToolLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Editor-specific UModelContextProtocolToolLibrary function library editor utility blueprint, allowing Editor-only BP node use in MCP tool functions.\n@see UModelContextProtocolToolLibraryBlueprint" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UModelContextProtocolEditorToolLibraryBlueprint constinit property declarations 
// ********** End Class UModelContextProtocolEditorToolLibraryBlueprint constinit property declarations 
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UModelContextProtocolEditorToolLibraryBlueprint>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UModelContextProtocolEditorToolLibraryBlueprint_Statics
UObject* (*const Z_Construct_UClass_UModelContextProtocolEditorToolLibraryBlueprint_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEditorUtilityBlueprint,
	(UObject* (*)())Z_Construct_UPackage__Script_ModelContextProtocolEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UModelContextProtocolEditorToolLibraryBlueprint_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UModelContextProtocolEditorToolLibraryBlueprint_Statics::ClassParams = {
	&UModelContextProtocolEditorToolLibraryBlueprint::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008800A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UModelContextProtocolEditorToolLibraryBlueprint_Statics::Class_MetaDataParams), Z_Construct_UClass_UModelContextProtocolEditorToolLibraryBlueprint_Statics::Class_MetaDataParams)
};
void UModelContextProtocolEditorToolLibraryBlueprint::StaticRegisterNativesUModelContextProtocolEditorToolLibraryBlueprint()
{
}
UClass* Z_Construct_UClass_UModelContextProtocolEditorToolLibraryBlueprint()
{
	if (!Z_Registration_Info_UClass_UModelContextProtocolEditorToolLibraryBlueprint.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UModelContextProtocolEditorToolLibraryBlueprint.OuterSingleton, Z_Construct_UClass_UModelContextProtocolEditorToolLibraryBlueprint_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UModelContextProtocolEditorToolLibraryBlueprint.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UModelContextProtocolEditorToolLibraryBlueprint);
UModelContextProtocolEditorToolLibraryBlueprint::~UModelContextProtocolEditorToolLibraryBlueprint() {}
// ********** End Class UModelContextProtocolEditorToolLibraryBlueprint ****************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEditor_Public_ModelContextProtocolEditorToolLibrary_h__Script_ModelContextProtocolEditor_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UModelContextProtocolEditorToolLibrary, UModelContextProtocolEditorToolLibrary::StaticClass, TEXT("UModelContextProtocolEditorToolLibrary"), &Z_Registration_Info_UClass_UModelContextProtocolEditorToolLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UModelContextProtocolEditorToolLibrary), 1178515996U) },
		{ Z_Construct_UClass_UModelContextProtocolEditorToolLibraryBlueprint, UModelContextProtocolEditorToolLibraryBlueprint::StaticClass, TEXT("UModelContextProtocolEditorToolLibraryBlueprint"), &Z_Registration_Info_UClass_UModelContextProtocolEditorToolLibraryBlueprint, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UModelContextProtocolEditorToolLibraryBlueprint), 1511216264U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEditor_Public_ModelContextProtocolEditorToolLibrary_h__Script_ModelContextProtocolEditor_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEditor_Public_ModelContextProtocolEditorToolLibrary_h__Script_ModelContextProtocolEditor_1691049519{
	TEXT("/Script/ModelContextProtocolEditor"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEditor_Public_ModelContextProtocolEditorToolLibrary_h__Script_ModelContextProtocolEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEditor_Public_ModelContextProtocolEditorToolLibrary_h__Script_ModelContextProtocolEditor_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
