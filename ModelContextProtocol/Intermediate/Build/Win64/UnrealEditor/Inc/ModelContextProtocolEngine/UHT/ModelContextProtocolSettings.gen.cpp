// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ModelContextProtocolSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeModelContextProtocolSettings() {}

// ********** Begin Cross Module References ********************************************************
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
MODELCONTEXTPROTOCOLENGINE_API UClass* Z_Construct_UClass_UModelContextProtocolSettings();
MODELCONTEXTPROTOCOLENGINE_API UClass* Z_Construct_UClass_UModelContextProtocolSettings_NoRegister();
UPackage* Z_Construct_UPackage__Script_ModelContextProtocolEngine();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UModelContextProtocolSettings ********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UModelContextProtocolSettings;
UClass* UModelContextProtocolSettings::GetPrivateStaticClass()
{
	using TClass = UModelContextProtocolSettings;
	if (!Z_Registration_Info_UClass_UModelContextProtocolSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ModelContextProtocolSettings"),
			Z_Registration_Info_UClass_UModelContextProtocolSettings.InnerSingleton,
			StaticRegisterNativesUModelContextProtocolSettings,
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
	return Z_Registration_Info_UClass_UModelContextProtocolSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UModelContextProtocolSettings_NoRegister()
{
	return UModelContextProtocolSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UModelContextProtocolSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "DisplayName", "Model Context Protocol" },
		{ "IncludePath", "ModelContextProtocolSettings.h" },
		{ "ModuleRelativePath", "Public/ModelContextProtocolSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ServerUrlPath_MetaData[] = {
		{ "Category", "Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The URL base path to serve from e.g: \"/mcp\" -> http://localhost/mcp */" },
#endif
		{ "ModuleRelativePath", "Public/ModelContextProtocolSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The URL base path to serve from e.g: \"/mcp\" -> http://localhost/mcp" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ServerPortNumber_MetaData[] = {
		{ "Category", "Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The port number to serve from e.g: 8000 -> http://localhost:8000/mcp */" },
#endif
		{ "ModuleRelativePath", "Public/ModelContextProtocolSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The port number to serve from e.g: 8000 -> http://localhost:8000/mcp" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoStartServer_MetaData[] = {
		{ "Category", "Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If true, the HTTP server route will be automatically registered and HTTP listeners started during module startup. */" },
#endif
		{ "ModuleRelativePath", "Public/ModelContextProtocolSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If true, the HTTP server route will be automatically registered and HTTP listeners started during module startup." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableToolSearch_MetaData[] = {
		{ "Category", "Tools" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If true, tools/list returns only list_toolsets, describe_toolset, and call_tool. The LLM discovers toolset tools on demand and dispatches them through call_tool without ever registering them as native MCP tools. If false, every toolset tool is registered natively at startup. */" },
#endif
		{ "ModuleRelativePath", "Public/ModelContextProtocolSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If true, tools/list returns only list_toolsets, describe_toolset, and call_tool. The LLM discovers toolset tools on demand and dispatches them through call_tool without ever registering them as native MCP tools. If false, every toolset tool is registered natively at startup." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UModelContextProtocolSettings constinit property declarations ************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ServerUrlPath;
	static const UECodeGen_Private::FUInt32PropertyParams NewProp_ServerPortNumber;
	static void NewProp_bAutoStartServer_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoStartServer;
	static void NewProp_bEnableToolSearch_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableToolSearch;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UModelContextProtocolSettings constinit property declarations **************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UModelContextProtocolSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UModelContextProtocolSettings_Statics

// ********** Begin Class UModelContextProtocolSettings Property Definitions ***********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UModelContextProtocolSettings_Statics::NewProp_ServerUrlPath = { "ServerUrlPath", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModelContextProtocolSettings, ServerUrlPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ServerUrlPath_MetaData), NewProp_ServerUrlPath_MetaData) };
const UECodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_UModelContextProtocolSettings_Statics::NewProp_ServerPortNumber = { "ServerPortNumber", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModelContextProtocolSettings, ServerPortNumber), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ServerPortNumber_MetaData), NewProp_ServerPortNumber_MetaData) };
void Z_Construct_UClass_UModelContextProtocolSettings_Statics::NewProp_bAutoStartServer_SetBit(void* Obj)
{
	((UModelContextProtocolSettings*)Obj)->bAutoStartServer = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UModelContextProtocolSettings_Statics::NewProp_bAutoStartServer = { "bAutoStartServer", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UModelContextProtocolSettings), &Z_Construct_UClass_UModelContextProtocolSettings_Statics::NewProp_bAutoStartServer_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoStartServer_MetaData), NewProp_bAutoStartServer_MetaData) };
void Z_Construct_UClass_UModelContextProtocolSettings_Statics::NewProp_bEnableToolSearch_SetBit(void* Obj)
{
	((UModelContextProtocolSettings*)Obj)->bEnableToolSearch = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UModelContextProtocolSettings_Statics::NewProp_bEnableToolSearch = { "bEnableToolSearch", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UModelContextProtocolSettings), &Z_Construct_UClass_UModelContextProtocolSettings_Statics::NewProp_bEnableToolSearch_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableToolSearch_MetaData), NewProp_bEnableToolSearch_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UModelContextProtocolSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModelContextProtocolSettings_Statics::NewProp_ServerUrlPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModelContextProtocolSettings_Statics::NewProp_ServerPortNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModelContextProtocolSettings_Statics::NewProp_bAutoStartServer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModelContextProtocolSettings_Statics::NewProp_bEnableToolSearch,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UModelContextProtocolSettings_Statics::PropPointers) < 2048);
// ********** End Class UModelContextProtocolSettings Property Definitions *************************
UObject* (*const Z_Construct_UClass_UModelContextProtocolSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_ModelContextProtocolEngine,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UModelContextProtocolSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UModelContextProtocolSettings_Statics::ClassParams = {
	&UModelContextProtocolSettings::StaticClass,
	"EditorPerProjectUserSettings",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UModelContextProtocolSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UModelContextProtocolSettings_Statics::PropPointers),
	0,
	0x000800A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UModelContextProtocolSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UModelContextProtocolSettings_Statics::Class_MetaDataParams)
};
void UModelContextProtocolSettings::StaticRegisterNativesUModelContextProtocolSettings()
{
}
UClass* Z_Construct_UClass_UModelContextProtocolSettings()
{
	if (!Z_Registration_Info_UClass_UModelContextProtocolSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UModelContextProtocolSettings.OuterSingleton, Z_Construct_UClass_UModelContextProtocolSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UModelContextProtocolSettings.OuterSingleton;
}
UModelContextProtocolSettings::UModelContextProtocolSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UModelContextProtocolSettings);
UModelContextProtocolSettings::~UModelContextProtocolSettings() {}
// ********** End Class UModelContextProtocolSettings **********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolSettings_h__Script_ModelContextProtocolEngine_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UModelContextProtocolSettings, UModelContextProtocolSettings::StaticClass, TEXT("UModelContextProtocolSettings"), &Z_Registration_Info_UClass_UModelContextProtocolSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UModelContextProtocolSettings), 2972468181U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolSettings_h__Script_ModelContextProtocolEngine_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolSettings_h__Script_ModelContextProtocolEngine_3400045704{
	TEXT("/Script/ModelContextProtocolEngine"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolSettings_h__Script_ModelContextProtocolEngine_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolSettings_h__Script_ModelContextProtocolEngine_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
