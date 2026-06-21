// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PCGToolsetSettings.h"
#include "UObject/SoftObjectPath.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodePCGToolsetSettings() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDirectoryPath();
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
PCGTOOLSET_API UClass* Z_Construct_UClass_UPCGToolsetSettings();
PCGTOOLSET_API UClass* Z_Construct_UClass_UPCGToolsetSettings_NoRegister();
UPackage* Z_Construct_UPackage__Script_PCGToolset();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UPCGToolsetSettings ******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UPCGToolsetSettings;
UClass* UPCGToolsetSettings::GetPrivateStaticClass()
{
	using TClass = UPCGToolsetSettings;
	if (!Z_Registration_Info_UClass_UPCGToolsetSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("PCGToolsetSettings"),
			Z_Registration_Info_UClass_UPCGToolsetSettings.InnerSingleton,
			StaticRegisterNativesUPCGToolsetSettings,
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
	return Z_Registration_Info_UClass_UPCGToolsetSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UPCGToolsetSettings_NoRegister()
{
	return UPCGToolsetSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPCGToolsetSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Settings for the PCGToolset plugin\n */" },
#endif
		{ "DisplayName", "PCG Toolset" },
		{ "IncludePath", "PCGToolsetSettings.h" },
		{ "ModuleRelativePath", "Public/PCGToolsetSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Settings for the PCGToolset plugin" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SubgraphDirectories_MetaData[] = {
		{ "Category", "Primitives" },
		{ "ContentDir", "" },
		{ "DisplayName", "Subgraph Directories" },
		{ "LongPackageName", "" },
		{ "ModuleRelativePath", "Public/PCGToolsetSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "Tooltip", "Directories containing PCG subgraph primitives to expose to the AI" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExampleGraphDirectories_MetaData[] = {
		{ "Category", "Examples" },
		{ "ContentDir", "" },
		{ "DisplayName", "Example Graph Directories" },
		{ "LongPackageName", "" },
		{ "ModuleRelativePath", "Public/PCGToolsetSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "Tooltip", "Directories containing example PCG graphs for AI reference" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InstantGraphDirectories_MetaData[] = {
		{ "Category", "Instants" },
		{ "ContentDir", "" },
		{ "DisplayName", "Instant Graph Directories" },
		{ "LongPackageName", "" },
		{ "ModuleRelativePath", "Public/PCGToolsetSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "Tooltip", "Directories containing instant PCG graphs for AI execution" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UPCGToolsetSettings constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SubgraphDirectories_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SubgraphDirectories;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ExampleGraphDirectories_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ExampleGraphDirectories;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InstantGraphDirectories_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_InstantGraphDirectories;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UPCGToolsetSettings constinit property declarations ************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPCGToolsetSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UPCGToolsetSettings_Statics

// ********** Begin Class UPCGToolsetSettings Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPCGToolsetSettings_Statics::NewProp_SubgraphDirectories_Inner = { "SubgraphDirectories", nullptr, (EPropertyFlags)0x0000000000004000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDirectoryPath, METADATA_PARAMS(0, nullptr) }; // 1225349189
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPCGToolsetSettings_Statics::NewProp_SubgraphDirectories = { "SubgraphDirectories", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPCGToolsetSettings, SubgraphDirectories), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SubgraphDirectories_MetaData), NewProp_SubgraphDirectories_MetaData) }; // 1225349189
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPCGToolsetSettings_Statics::NewProp_ExampleGraphDirectories_Inner = { "ExampleGraphDirectories", nullptr, (EPropertyFlags)0x0000000000004000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDirectoryPath, METADATA_PARAMS(0, nullptr) }; // 1225349189
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPCGToolsetSettings_Statics::NewProp_ExampleGraphDirectories = { "ExampleGraphDirectories", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPCGToolsetSettings, ExampleGraphDirectories), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExampleGraphDirectories_MetaData), NewProp_ExampleGraphDirectories_MetaData) }; // 1225349189
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPCGToolsetSettings_Statics::NewProp_InstantGraphDirectories_Inner = { "InstantGraphDirectories", nullptr, (EPropertyFlags)0x0000000000004000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDirectoryPath, METADATA_PARAMS(0, nullptr) }; // 1225349189
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPCGToolsetSettings_Statics::NewProp_InstantGraphDirectories = { "InstantGraphDirectories", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPCGToolsetSettings, InstantGraphDirectories), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InstantGraphDirectories_MetaData), NewProp_InstantGraphDirectories_MetaData) }; // 1225349189
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPCGToolsetSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPCGToolsetSettings_Statics::NewProp_SubgraphDirectories_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPCGToolsetSettings_Statics::NewProp_SubgraphDirectories,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPCGToolsetSettings_Statics::NewProp_ExampleGraphDirectories_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPCGToolsetSettings_Statics::NewProp_ExampleGraphDirectories,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPCGToolsetSettings_Statics::NewProp_InstantGraphDirectories_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPCGToolsetSettings_Statics::NewProp_InstantGraphDirectories,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPCGToolsetSettings_Statics::PropPointers) < 2048);
// ********** End Class UPCGToolsetSettings Property Definitions ***********************************
UObject* (*const Z_Construct_UClass_UPCGToolsetSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_PCGToolset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPCGToolsetSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPCGToolsetSettings_Statics::ClassParams = {
	&UPCGToolsetSettings::StaticClass,
	"Editor",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UPCGToolsetSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UPCGToolsetSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPCGToolsetSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UPCGToolsetSettings_Statics::Class_MetaDataParams)
};
void UPCGToolsetSettings::StaticRegisterNativesUPCGToolsetSettings()
{
}
UClass* Z_Construct_UClass_UPCGToolsetSettings()
{
	if (!Z_Registration_Info_UClass_UPCGToolsetSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPCGToolsetSettings.OuterSingleton, Z_Construct_UClass_UPCGToolsetSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPCGToolsetSettings.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UPCGToolsetSettings);
UPCGToolsetSettings::~UPCGToolsetSettings() {}
// ********** End Class UPCGToolsetSettings ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolsetSettings_h__Script_PCGToolset_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPCGToolsetSettings, UPCGToolsetSettings::StaticClass, TEXT("UPCGToolsetSettings"), &Z_Registration_Info_UClass_UPCGToolsetSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPCGToolsetSettings), 2022868071U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolsetSettings_h__Script_PCGToolset_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolsetSettings_h__Script_PCGToolset_1569230338{
	TEXT("/Script/PCGToolset"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolsetSettings_h__Script_PCGToolset_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolsetSettings_h__Script_PCGToolset_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
