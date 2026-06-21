// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ModelContextProtocolToolHashMappingCommandlet.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeModelContextProtocolToolHashMappingCommandlet() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UCommandlet();
MODELCONTEXTPROTOCOLEDITOR_API UClass* Z_Construct_UClass_UModelContextProtocolToolHashMappingCommandlet();
MODELCONTEXTPROTOCOLEDITOR_API UClass* Z_Construct_UClass_UModelContextProtocolToolHashMappingCommandlet_NoRegister();
UPackage* Z_Construct_UPackage__Script_ModelContextProtocolEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UModelContextProtocolToolHashMappingCommandlet ***************************
FClassRegistrationInfo Z_Registration_Info_UClass_UModelContextProtocolToolHashMappingCommandlet;
UClass* UModelContextProtocolToolHashMappingCommandlet::GetPrivateStaticClass()
{
	using TClass = UModelContextProtocolToolHashMappingCommandlet;
	if (!Z_Registration_Info_UClass_UModelContextProtocolToolHashMappingCommandlet.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ModelContextProtocolToolHashMappingCommandlet"),
			Z_Registration_Info_UClass_UModelContextProtocolToolHashMappingCommandlet.InnerSingleton,
			StaticRegisterNativesUModelContextProtocolToolHashMappingCommandlet,
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
	return Z_Registration_Info_UClass_UModelContextProtocolToolHashMappingCommandlet.InnerSingleton;
}
UClass* Z_Construct_UClass_UModelContextProtocolToolHashMappingCommandlet_NoRegister()
{
	return UModelContextProtocolToolHashMappingCommandlet::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UModelContextProtocolToolHashMappingCommandlet_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Writes a JSON mapping of blake3 tool and toolset identifier hashes (as emitted by UE::ModelContextProtocol::Analytics::HashToolIdentifier) to their human-readable names. The mapping lets downstream consumers decode ToolNameHash / ToolsetNameHash fields in analytics events.\n *\n * Usage:\n *   UnrealEditor-Cmd.exe <uproject> <TargetName> -run=ModelContextProtocolToolHashMapping [-Output=<path>] [-TickEngineSeconds=<float>] [-Print]\n *\n * Default output path is <ProjectSavedDir>/ModelContextProtocol/ToolHashMapping.json.\n *\n * Only tools registered with IModelContextProtocolModule at enumeration time are captured.\n *\n * Toolsets packaged as explicitly-loaded Game Feature Plugins are not active by default and must be activated before enumeration via -ExecCmds (use the `LoadGameFeaturePlugin` console command).\n *\n * Because commandlets do not run the normal editor tick loop, the commandlet manually drives engine frames for -TickEngineSeconds (default 20.0) so async GFP activations and their downstream toolset registrations can complete before the mapping is built. Pass -TickEngineSeconds=0 to skip the loop entirely. The default is sized for a typical GFP activation; bump it higher for larger aggregates or cold caches.\n *\n * Example that activates a toolset aggregate GFP before enumerating:\n *   UnrealEditor-Cmd.exe <uproject> <EditorTarget> -run=ModelContextProtocolToolHashMapping -ExecCmds=\"LoadGameFeaturePlugin <YourToolsetsPluginName>\"\n */" },
#endif
		{ "IncludePath", "ModelContextProtocolToolHashMappingCommandlet.h" },
		{ "ModuleRelativePath", "Private/ModelContextProtocolToolHashMappingCommandlet.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Writes a JSON mapping of blake3 tool and toolset identifier hashes (as emitted by UE::ModelContextProtocol::Analytics::HashToolIdentifier) to their human-readable names. The mapping lets downstream consumers decode ToolNameHash / ToolsetNameHash fields in analytics events.\n\nUsage:\n  UnrealEditor-Cmd.exe <uproject> <TargetName> -run=ModelContextProtocolToolHashMapping [-Output=<path>] [-TickEngineSeconds=<float>] [-Print]\n\nDefault output path is <ProjectSavedDir>/ModelContextProtocol/ToolHashMapping.json.\n\nOnly tools registered with IModelContextProtocolModule at enumeration time are captured.\n\nToolsets packaged as explicitly-loaded Game Feature Plugins are not active by default and must be activated before enumeration via -ExecCmds (use the `LoadGameFeaturePlugin` console command).\n\nBecause commandlets do not run the normal editor tick loop, the commandlet manually drives engine frames for -TickEngineSeconds (default 20.0) so async GFP activations and their downstream toolset registrations can complete before the mapping is built. Pass -TickEngineSeconds=0 to skip the loop entirely. The default is sized for a typical GFP activation; bump it higher for larger aggregates or cold caches.\n\nExample that activates a toolset aggregate GFP before enumerating:\n  UnrealEditor-Cmd.exe <uproject> <EditorTarget> -run=ModelContextProtocolToolHashMapping -ExecCmds=\"LoadGameFeaturePlugin <YourToolsetsPluginName>\"" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UModelContextProtocolToolHashMappingCommandlet constinit property declarations 
// ********** End Class UModelContextProtocolToolHashMappingCommandlet constinit property declarations 
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UModelContextProtocolToolHashMappingCommandlet>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UModelContextProtocolToolHashMappingCommandlet_Statics
UObject* (*const Z_Construct_UClass_UModelContextProtocolToolHashMappingCommandlet_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UCommandlet,
	(UObject* (*)())Z_Construct_UPackage__Script_ModelContextProtocolEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UModelContextProtocolToolHashMappingCommandlet_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UModelContextProtocolToolHashMappingCommandlet_Statics::ClassParams = {
	&UModelContextProtocolToolHashMappingCommandlet::StaticClass,
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
	0x000000A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UModelContextProtocolToolHashMappingCommandlet_Statics::Class_MetaDataParams), Z_Construct_UClass_UModelContextProtocolToolHashMappingCommandlet_Statics::Class_MetaDataParams)
};
void UModelContextProtocolToolHashMappingCommandlet::StaticRegisterNativesUModelContextProtocolToolHashMappingCommandlet()
{
}
UClass* Z_Construct_UClass_UModelContextProtocolToolHashMappingCommandlet()
{
	if (!Z_Registration_Info_UClass_UModelContextProtocolToolHashMappingCommandlet.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UModelContextProtocolToolHashMappingCommandlet.OuterSingleton, Z_Construct_UClass_UModelContextProtocolToolHashMappingCommandlet_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UModelContextProtocolToolHashMappingCommandlet.OuterSingleton;
}
UModelContextProtocolToolHashMappingCommandlet::UModelContextProtocolToolHashMappingCommandlet(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UModelContextProtocolToolHashMappingCommandlet);
UModelContextProtocolToolHashMappingCommandlet::~UModelContextProtocolToolHashMappingCommandlet() {}
// ********** End Class UModelContextProtocolToolHashMappingCommandlet *****************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEditor_Private_ModelContextProtocolToolHashMappingCommandlet_h__Script_ModelContextProtocolEditor_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UModelContextProtocolToolHashMappingCommandlet, UModelContextProtocolToolHashMappingCommandlet::StaticClass, TEXT("UModelContextProtocolToolHashMappingCommandlet"), &Z_Registration_Info_UClass_UModelContextProtocolToolHashMappingCommandlet, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UModelContextProtocolToolHashMappingCommandlet), 3139622026U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEditor_Private_ModelContextProtocolToolHashMappingCommandlet_h__Script_ModelContextProtocolEditor_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEditor_Private_ModelContextProtocolToolHashMappingCommandlet_h__Script_ModelContextProtocolEditor_2068471450{
	TEXT("/Script/ModelContextProtocolEditor"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEditor_Private_ModelContextProtocolToolHashMappingCommandlet_h__Script_ModelContextProtocolEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEditor_Private_ModelContextProtocolToolHashMappingCommandlet_h__Script_ModelContextProtocolEditor_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
