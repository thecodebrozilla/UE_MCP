// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ToolsetRegistry/ToolsetRegistrySubsystem.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeToolsetRegistrySubsystem() {}

// ********** Begin Cross Module References ********************************************************
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
EDITORSUBSYSTEM_API UClass* Z_Construct_UClass_UEditorSubsystem();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetRegistrySettings();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetRegistrySettings_NoRegister();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetRegistrySubsystem();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetRegistrySubsystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_ToolsetRegistry();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UToolsetRegistrySettings *************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UToolsetRegistrySettings;
UClass* UToolsetRegistrySettings::GetPrivateStaticClass()
{
	using TClass = UToolsetRegistrySettings;
	if (!Z_Registration_Info_UClass_UToolsetRegistrySettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ToolsetRegistrySettings"),
			Z_Registration_Info_UClass_UToolsetRegistrySettings.InnerSingleton,
			StaticRegisterNativesUToolsetRegistrySettings,
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
	return Z_Registration_Info_UClass_UToolsetRegistrySettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UToolsetRegistrySettings_NoRegister()
{
	return UToolsetRegistrySettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UToolsetRegistrySettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "DisplayName", "Toolset Registry" },
		{ "IncludePath", "ToolsetRegistry/ToolsetRegistrySubsystem.h" },
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolsetRegistrySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlockedNames_MetaData[] = {
		{ "Category", "Toolsets" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Toolsets and tools whose names match any of these patterns are hidden. Patterns\n// enclosed in forward slashes (e.g., /^Fake.*/) are treated as regular expressions;\n// all others are matched as case-insensitive substrings. Block takes precedence over\n// ToolsetAllowedNames.\n" },
#endif
		{ "DisplayName", "ToolsetBlockedNames" },
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolsetRegistrySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Toolsets and tools whose names match any of these patterns are hidden. Patterns\nenclosed in forward slashes (e.g., /^Fake.*/) are treated as regular expressions;\nall others are matched as case-insensitive substrings. Block takes precedence over\nToolsetAllowedNames." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AllowedNames_MetaData[] = {
		{ "Category", "Toolsets" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// When non-empty, only toolsets and tools whose names match one of these patterns are\n// visible. Same pattern syntax as ToolsetBlockedNames. Block takes precedence over\n// this list.\n" },
#endif
		{ "DisplayName", "ToolsetAllowedNames" },
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolsetRegistrySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "When non-empty, only toolsets and tools whose names match one of these patterns are\nvisible. Same pattern syntax as ToolsetBlockedNames. Block takes precedence over\nthis list." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AgentSkillBlockedNames_MetaData[] = {
		{ "Category", "Agent Skills" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// AgentSkills whose paths match any of these patterns are hidden from ListSkills\n// and GetSkills. Patterns enclosed in forward slashes (e.g., /^Foo.*/) are treated\n// as regular expressions; all others are matched as case-insensitive substrings\n// against the skill's full path. Block takes precedence over AgentSkillAllowedNames.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolsetRegistrySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "AgentSkills whose paths match any of these patterns are hidden from ListSkills\nand GetSkills. Patterns enclosed in forward slashes (e.g., /^Foo.*/) are treated\nas regular expressions; all others are matched as case-insensitive substrings\nagainst the skill's full path. Block takes precedence over AgentSkillAllowedNames." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AgentSkillAllowedNames_MetaData[] = {
		{ "Category", "Agent Skills" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// When non-empty, only AgentSkills whose paths match one of these patterns are\n// visible. Same pattern syntax as AgentSkillBlockedNames. Block takes precedence\n// over this list.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolsetRegistrySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "When non-empty, only AgentSkills whose paths match one of these patterns are\nvisible. Same pattern syntax as AgentSkillBlockedNames. Block takes precedence\nover this list." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SetObjectPropertiesBlockedClasses_MetaData[] = {
		{ "Category", "SetObjectProperties Block List" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Classes whose instances must be rejected by UToolsetLibrary::SetObjectProperties.\n// Matched against the object's class and every parent class. Pattern syntax matches\n// ToolsetBlockedNames (forward-slash-wrapped patterns are regex; others are\n// case-insensitive substring).\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolsetRegistrySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Classes whose instances must be rejected by UToolsetLibrary::SetObjectProperties.\nMatched against the object's class and every parent class. Pattern syntax matches\nToolsetBlockedNames (forward-slash-wrapped patterns are regex; others are\ncase-insensitive substring)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SetObjectPropertiesBlockedProperties_MetaData[] = {
		{ "Category", "SetObjectProperties Block List" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Class/property pairs that must be rejected by UToolsetLibrary::SetObjectProperties.\n// Each pattern is matched against \"ClassName.PropertyName\" for every class in the\n// target object's inheritance chain. Use a bare property name with a regex\n// (e.g., /\\.RootComponent$/) to match the property on every class. Same pattern\n// syntax as SetObjectPropertiesBlockedClasses.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolsetRegistrySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Class/property pairs that must be rejected by UToolsetLibrary::SetObjectProperties.\nEach pattern is matched against \"ClassName.PropertyName\" for every class in the\ntarget object's inheritance chain. Use a bare property name with a regex\n(e.g., /\\.RootComponent$/) to match the property on every class. Same pattern\nsyntax as SetObjectPropertiesBlockedClasses." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UToolsetRegistrySettings constinit property declarations *****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_BlockedNames_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_BlockedNames;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AllowedNames_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_AllowedNames;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AgentSkillBlockedNames_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_AgentSkillBlockedNames;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AgentSkillAllowedNames_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_AgentSkillAllowedNames;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SetObjectPropertiesBlockedClasses_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SetObjectPropertiesBlockedClasses;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SetObjectPropertiesBlockedProperties_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SetObjectPropertiesBlockedProperties;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UToolsetRegistrySettings constinit property declarations *******************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UToolsetRegistrySettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UToolsetRegistrySettings_Statics

// ********** Begin Class UToolsetRegistrySettings Property Definitions ****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UToolsetRegistrySettings_Statics::NewProp_BlockedNames_Inner = { "BlockedNames", nullptr, (EPropertyFlags)0x0000000000004000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UToolsetRegistrySettings_Statics::NewProp_BlockedNames = { "BlockedNames", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UToolsetRegistrySettings, BlockedNames), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlockedNames_MetaData), NewProp_BlockedNames_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UToolsetRegistrySettings_Statics::NewProp_AllowedNames_Inner = { "AllowedNames", nullptr, (EPropertyFlags)0x0000000000004000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UToolsetRegistrySettings_Statics::NewProp_AllowedNames = { "AllowedNames", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UToolsetRegistrySettings, AllowedNames), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AllowedNames_MetaData), NewProp_AllowedNames_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UToolsetRegistrySettings_Statics::NewProp_AgentSkillBlockedNames_Inner = { "AgentSkillBlockedNames", nullptr, (EPropertyFlags)0x0000000000004000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UToolsetRegistrySettings_Statics::NewProp_AgentSkillBlockedNames = { "AgentSkillBlockedNames", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UToolsetRegistrySettings, AgentSkillBlockedNames), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AgentSkillBlockedNames_MetaData), NewProp_AgentSkillBlockedNames_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UToolsetRegistrySettings_Statics::NewProp_AgentSkillAllowedNames_Inner = { "AgentSkillAllowedNames", nullptr, (EPropertyFlags)0x0000000000004000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UToolsetRegistrySettings_Statics::NewProp_AgentSkillAllowedNames = { "AgentSkillAllowedNames", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UToolsetRegistrySettings, AgentSkillAllowedNames), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AgentSkillAllowedNames_MetaData), NewProp_AgentSkillAllowedNames_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UToolsetRegistrySettings_Statics::NewProp_SetObjectPropertiesBlockedClasses_Inner = { "SetObjectPropertiesBlockedClasses", nullptr, (EPropertyFlags)0x0000000000004000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UToolsetRegistrySettings_Statics::NewProp_SetObjectPropertiesBlockedClasses = { "SetObjectPropertiesBlockedClasses", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UToolsetRegistrySettings, SetObjectPropertiesBlockedClasses), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SetObjectPropertiesBlockedClasses_MetaData), NewProp_SetObjectPropertiesBlockedClasses_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UToolsetRegistrySettings_Statics::NewProp_SetObjectPropertiesBlockedProperties_Inner = { "SetObjectPropertiesBlockedProperties", nullptr, (EPropertyFlags)0x0000000000004000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UToolsetRegistrySettings_Statics::NewProp_SetObjectPropertiesBlockedProperties = { "SetObjectPropertiesBlockedProperties", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UToolsetRegistrySettings, SetObjectPropertiesBlockedProperties), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SetObjectPropertiesBlockedProperties_MetaData), NewProp_SetObjectPropertiesBlockedProperties_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UToolsetRegistrySettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UToolsetRegistrySettings_Statics::NewProp_BlockedNames_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UToolsetRegistrySettings_Statics::NewProp_BlockedNames,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UToolsetRegistrySettings_Statics::NewProp_AllowedNames_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UToolsetRegistrySettings_Statics::NewProp_AllowedNames,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UToolsetRegistrySettings_Statics::NewProp_AgentSkillBlockedNames_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UToolsetRegistrySettings_Statics::NewProp_AgentSkillBlockedNames,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UToolsetRegistrySettings_Statics::NewProp_AgentSkillAllowedNames_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UToolsetRegistrySettings_Statics::NewProp_AgentSkillAllowedNames,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UToolsetRegistrySettings_Statics::NewProp_SetObjectPropertiesBlockedClasses_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UToolsetRegistrySettings_Statics::NewProp_SetObjectPropertiesBlockedClasses,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UToolsetRegistrySettings_Statics::NewProp_SetObjectPropertiesBlockedProperties_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UToolsetRegistrySettings_Statics::NewProp_SetObjectPropertiesBlockedProperties,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UToolsetRegistrySettings_Statics::PropPointers) < 2048);
// ********** End Class UToolsetRegistrySettings Property Definitions ******************************
UObject* (*const Z_Construct_UClass_UToolsetRegistrySettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_ToolsetRegistry,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UToolsetRegistrySettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UToolsetRegistrySettings_Statics::ClassParams = {
	&UToolsetRegistrySettings::StaticClass,
	"EditorPerProjectUserSettings",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UToolsetRegistrySettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UToolsetRegistrySettings_Statics::PropPointers),
	0,
	0x000800A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UToolsetRegistrySettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UToolsetRegistrySettings_Statics::Class_MetaDataParams)
};
void UToolsetRegistrySettings::StaticRegisterNativesUToolsetRegistrySettings()
{
}
UClass* Z_Construct_UClass_UToolsetRegistrySettings()
{
	if (!Z_Registration_Info_UClass_UToolsetRegistrySettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UToolsetRegistrySettings.OuterSingleton, Z_Construct_UClass_UToolsetRegistrySettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UToolsetRegistrySettings.OuterSingleton;
}
UToolsetRegistrySettings::UToolsetRegistrySettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UToolsetRegistrySettings);
UToolsetRegistrySettings::~UToolsetRegistrySettings() {}
// ********** End Class UToolsetRegistrySettings ***************************************************

// ********** Begin Class UToolsetRegistrySubsystem ************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UToolsetRegistrySubsystem;
UClass* UToolsetRegistrySubsystem::GetPrivateStaticClass()
{
	using TClass = UToolsetRegistrySubsystem;
	if (!Z_Registration_Info_UClass_UToolsetRegistrySubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ToolsetRegistrySubsystem"),
			Z_Registration_Info_UClass_UToolsetRegistrySubsystem.InnerSingleton,
			StaticRegisterNativesUToolsetRegistrySubsystem,
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
	return Z_Registration_Info_UClass_UToolsetRegistrySubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UToolsetRegistrySubsystem_NoRegister()
{
	return UToolsetRegistrySubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UToolsetRegistrySubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "ToolsetRegistry/ToolsetRegistrySubsystem.h" },
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolsetRegistrySubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UToolsetRegistrySubsystem constinit property declarations ****************
// ********** End Class UToolsetRegistrySubsystem constinit property declarations ******************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UToolsetRegistrySubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UToolsetRegistrySubsystem_Statics
UObject* (*const Z_Construct_UClass_UToolsetRegistrySubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEditorSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_ToolsetRegistry,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UToolsetRegistrySubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UToolsetRegistrySubsystem_Statics::ClassParams = {
	&UToolsetRegistrySubsystem::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UToolsetRegistrySubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UToolsetRegistrySubsystem_Statics::Class_MetaDataParams)
};
void UToolsetRegistrySubsystem::StaticRegisterNativesUToolsetRegistrySubsystem()
{
}
UClass* Z_Construct_UClass_UToolsetRegistrySubsystem()
{
	if (!Z_Registration_Info_UClass_UToolsetRegistrySubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UToolsetRegistrySubsystem.OuterSingleton, Z_Construct_UClass_UToolsetRegistrySubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UToolsetRegistrySubsystem.OuterSingleton;
}
UToolsetRegistrySubsystem::UToolsetRegistrySubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UToolsetRegistrySubsystem);
UToolsetRegistrySubsystem::~UToolsetRegistrySubsystem() {}
// ********** End Class UToolsetRegistrySubsystem **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetRegistrySubsystem_h__Script_ToolsetRegistry_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UToolsetRegistrySettings, UToolsetRegistrySettings::StaticClass, TEXT("UToolsetRegistrySettings"), &Z_Registration_Info_UClass_UToolsetRegistrySettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UToolsetRegistrySettings), 745627894U) },
		{ Z_Construct_UClass_UToolsetRegistrySubsystem, UToolsetRegistrySubsystem::StaticClass, TEXT("UToolsetRegistrySubsystem"), &Z_Registration_Info_UClass_UToolsetRegistrySubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UToolsetRegistrySubsystem), 317192692U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetRegistrySubsystem_h__Script_ToolsetRegistry_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetRegistrySubsystem_h__Script_ToolsetRegistry_257876738{
	TEXT("/Script/ToolsetRegistry"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetRegistrySubsystem_h__Script_ToolsetRegistry_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetRegistrySubsystem_h__Script_ToolsetRegistry_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
