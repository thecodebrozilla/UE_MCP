// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TerminalSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeTerminalSettings() {}

// ********** Begin Cross Module References ********************************************************
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
TERMINAL_API UClass* Z_Construct_UClass_UTerminalSettings();
TERMINAL_API UClass* Z_Construct_UClass_UTerminalSettings_NoRegister();
UPackage* Z_Construct_UPackage__Script_Terminal();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UTerminalSettings ********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UTerminalSettings;
UClass* UTerminalSettings::GetPrivateStaticClass()
{
	using TClass = UTerminalSettings;
	if (!Z_Registration_Info_UClass_UTerminalSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("TerminalSettings"),
			Z_Registration_Info_UClass_UTerminalSettings.InnerSingleton,
			StaticRegisterNativesUTerminalSettings,
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
	return Z_Registration_Info_UClass_UTerminalSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UTerminalSettings_NoRegister()
{
	return UTerminalSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UTerminalSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "DisplayName", "Terminal" },
		{ "IncludePath", "TerminalSettings.h" },
		{ "ModuleRelativePath", "Public/TerminalSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShellExecutablePath_MetaData[] = {
		{ "Category", "Terminal" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Path to the shell executable. Leave empty to use the system default (COMSPEC on Windows, SHELL on Unix). */" },
#endif
		{ "ModuleRelativePath", "Public/TerminalSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Path to the shell executable. Leave empty to use the system default (COMSPEC on Windows, SHELL on Unix)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FontFamily_MetaData[] = {
		{ "Category", "Terminal" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Font filename stem (without extension) as found in the system Fonts directory, e.g. \"consola\" for Consolas. */" },
#endif
		{ "ModuleRelativePath", "Public/TerminalSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Font filename stem (without extension) as found in the system Fonts directory, e.g. \"consola\" for Consolas." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FontSize_MetaData[] = {
		{ "Category", "Terminal" },
		{ "ClampMax", "72" },
		{ "ClampMin", "6" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Font size in points. */" },
#endif
		{ "ModuleRelativePath", "Public/TerminalSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Font size in points." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScrollbackLimit_MetaData[] = {
		{ "Category", "Terminal" },
		{ "ClampMax", "1000000" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum number of scrollback rows retained by the terminal. */" },
#endif
		{ "ModuleRelativePath", "Public/TerminalSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum number of scrollback rows retained by the terminal." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ColorSchemeName_MetaData[] = {
		{ "Category", "Terminal" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Name of the color scheme to use. Must match a JSON file in Config/ColorSchemes/. */" },
#endif
		{ "ModuleRelativePath", "Public/TerminalSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Name of the color scheme to use. Must match a JSON file in Config/ColorSchemes/." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartupCommands_MetaData[] = {
		{ "Category", "Terminal" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Commands to execute automatically when a new terminal window is created. Each entry is sent as a separate command. */" },
#endif
		{ "ModuleRelativePath", "Public/TerminalSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Commands to execute automatically when a new terminal window is created. Each entry is sent as a separate command." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPreventCloseDuringActivity_MetaData[] = {
		{ "Category", "Terminal|Activity" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** When true, prompt for confirmation if the editor is closed while a terminal session is producing output. */" },
#endif
		{ "ModuleRelativePath", "Public/TerminalSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "When true, prompt for confirmation if the editor is closed while a terminal session is producing output." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActivityTimeoutSeconds_MetaData[] = {
		{ "Category", "Terminal|Activity" },
		{ "ClampMax", "60.000000" },
		{ "ClampMin", "1.000000" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Seconds of silence after which a terminal is no longer considered active. Floor is 1.0s to stay above realistic tick jitter (frame hitches, GC pauses). */" },
#endif
		{ "EditCondition", "bPreventCloseDuringActivity" },
		{ "ModuleRelativePath", "Public/TerminalSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Seconds of silence after which a terminal is no longer considered active. Floor is 1.0s to stay above realistic tick jitter (frame hitches, GC pauses)." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UTerminalSettings constinit property declarations ************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ShellExecutablePath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FontFamily;
	static const UECodeGen_Private::FIntPropertyParams NewProp_FontSize;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ScrollbackLimit;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ColorSchemeName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_StartupCommands_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_StartupCommands;
	static void NewProp_bPreventCloseDuringActivity_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPreventCloseDuringActivity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ActivityTimeoutSeconds;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UTerminalSettings constinit property declarations **************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTerminalSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UTerminalSettings_Statics

// ********** Begin Class UTerminalSettings Property Definitions ***********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UTerminalSettings_Statics::NewProp_ShellExecutablePath = { "ShellExecutablePath", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTerminalSettings, ShellExecutablePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShellExecutablePath_MetaData), NewProp_ShellExecutablePath_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UTerminalSettings_Statics::NewProp_FontFamily = { "FontFamily", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTerminalSettings, FontFamily), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FontFamily_MetaData), NewProp_FontFamily_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UTerminalSettings_Statics::NewProp_FontSize = { "FontSize", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTerminalSettings, FontSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FontSize_MetaData), NewProp_FontSize_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UTerminalSettings_Statics::NewProp_ScrollbackLimit = { "ScrollbackLimit", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTerminalSettings, ScrollbackLimit), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScrollbackLimit_MetaData), NewProp_ScrollbackLimit_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UTerminalSettings_Statics::NewProp_ColorSchemeName = { "ColorSchemeName", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTerminalSettings, ColorSchemeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ColorSchemeName_MetaData), NewProp_ColorSchemeName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UTerminalSettings_Statics::NewProp_StartupCommands_Inner = { "StartupCommands", nullptr, (EPropertyFlags)0x0000000000004000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UTerminalSettings_Statics::NewProp_StartupCommands = { "StartupCommands", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTerminalSettings, StartupCommands), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartupCommands_MetaData), NewProp_StartupCommands_MetaData) };
void Z_Construct_UClass_UTerminalSettings_Statics::NewProp_bPreventCloseDuringActivity_SetBit(void* Obj)
{
	((UTerminalSettings*)Obj)->bPreventCloseDuringActivity = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UTerminalSettings_Statics::NewProp_bPreventCloseDuringActivity = { "bPreventCloseDuringActivity", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UTerminalSettings), &Z_Construct_UClass_UTerminalSettings_Statics::NewProp_bPreventCloseDuringActivity_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPreventCloseDuringActivity_MetaData), NewProp_bPreventCloseDuringActivity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UTerminalSettings_Statics::NewProp_ActivityTimeoutSeconds = { "ActivityTimeoutSeconds", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTerminalSettings, ActivityTimeoutSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActivityTimeoutSeconds_MetaData), NewProp_ActivityTimeoutSeconds_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UTerminalSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTerminalSettings_Statics::NewProp_ShellExecutablePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTerminalSettings_Statics::NewProp_FontFamily,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTerminalSettings_Statics::NewProp_FontSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTerminalSettings_Statics::NewProp_ScrollbackLimit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTerminalSettings_Statics::NewProp_ColorSchemeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTerminalSettings_Statics::NewProp_StartupCommands_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTerminalSettings_Statics::NewProp_StartupCommands,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTerminalSettings_Statics::NewProp_bPreventCloseDuringActivity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTerminalSettings_Statics::NewProp_ActivityTimeoutSeconds,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTerminalSettings_Statics::PropPointers) < 2048);
// ********** End Class UTerminalSettings Property Definitions *************************************
UObject* (*const Z_Construct_UClass_UTerminalSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_Terminal,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTerminalSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UTerminalSettings_Statics::ClassParams = {
	&UTerminalSettings::StaticClass,
	"EditorPerProjectUserSettings",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UTerminalSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UTerminalSettings_Statics::PropPointers),
	0,
	0x000800A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTerminalSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UTerminalSettings_Statics::Class_MetaDataParams)
};
void UTerminalSettings::StaticRegisterNativesUTerminalSettings()
{
}
UClass* Z_Construct_UClass_UTerminalSettings()
{
	if (!Z_Registration_Info_UClass_UTerminalSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTerminalSettings.OuterSingleton, Z_Construct_UClass_UTerminalSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UTerminalSettings.OuterSingleton;
}
UTerminalSettings::UTerminalSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UTerminalSettings);
UTerminalSettings::~UTerminalSettings() {}
// ********** End Class UTerminalSettings **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Terminal_Source_Terminal_Public_TerminalSettings_h__Script_Terminal_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UTerminalSettings, UTerminalSettings::StaticClass, TEXT("UTerminalSettings"), &Z_Registration_Info_UClass_UTerminalSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTerminalSettings), 1300925487U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Terminal_Source_Terminal_Public_TerminalSettings_h__Script_Terminal_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Terminal_Source_Terminal_Public_TerminalSettings_h__Script_Terminal_3315479497{
	TEXT("/Script/Terminal"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Terminal_Source_Terminal_Public_TerminalSettings_h__Script_Terminal_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Terminal_Source_Terminal_Public_TerminalSettings_h__Script_Terminal_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
