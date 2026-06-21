// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AbilitySystemInspectorToolset.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeAbilitySystemInspectorToolset() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
GASTOOLSETS_API UClass* Z_Construct_UClass_UAbilitySystemInspectorToolset();
GASTOOLSETS_API UClass* Z_Construct_UClass_UAbilitySystemInspectorToolset_NoRegister();
GASTOOLSETS_API UScriptStruct* Z_Construct_UScriptStruct_FActiveEffectInfo();
GASTOOLSETS_API UScriptStruct* Z_Construct_UScriptStruct_FGrantedAbilityInfo();
GASTOOLSETS_API UScriptStruct* Z_Construct_UScriptStruct_FRuntimeAttributeValue();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition();
UPackage* Z_Construct_UPackage__Script_GASToolsets();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FRuntimeAttributeValue ********************************************
struct Z_Construct_UScriptStruct_FRuntimeAttributeValue_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FRuntimeAttributeValue); }
	static inline consteval int16 GetStructAlignment() { return alignof(FRuntimeAttributeValue); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The runtime base and current value of a single gameplay attribute.\n" },
#endif
		{ "ModuleRelativePath", "Private/AbilitySystemInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The runtime base and current value of a single gameplay attribute." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttributeName_MetaData[] = {
		{ "Category", "AbilitySystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The short attribute name (e.g. \"Health\").\n" },
#endif
		{ "ModuleRelativePath", "Private/AbilitySystemInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The short attribute name (e.g. \"Health\")." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FullName_MetaData[] = {
		{ "Category", "AbilitySystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The fully-qualified name including the owning set (e.g. \"UMyHealthSet.Health\").\n" },
#endif
		{ "ModuleRelativePath", "Private/AbilitySystemInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The fully-qualified name including the owning set (e.g. \"UMyHealthSet.Health\")." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SetClassName_MetaData[] = {
		{ "Category", "AbilitySystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The name of the AttributeSet class that owns this attribute (e.g. \"UMyHealthSet\").\n" },
#endif
		{ "ModuleRelativePath", "Private/AbilitySystemInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The name of the AttributeSet class that owns this attribute (e.g. \"UMyHealthSet\")." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseValue_MetaData[] = {
		{ "Category", "AbilitySystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The permanent base value, unaffected by temporary modifiers.\n" },
#endif
		{ "ModuleRelativePath", "Private/AbilitySystemInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The permanent base value, unaffected by temporary modifiers." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentValue_MetaData[] = {
		{ "Category", "AbilitySystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The current value after all active modifiers are applied.\n" },
#endif
		{ "ModuleRelativePath", "Private/AbilitySystemInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The current value after all active modifiers are applied." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FRuntimeAttributeValue constinit property declarations ************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AttributeName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FullName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SetClassName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseValue;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FRuntimeAttributeValue constinit property declarations **************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FRuntimeAttributeValue>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FRuntimeAttributeValue_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FRuntimeAttributeValue;
class UScriptStruct* FRuntimeAttributeValue::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FRuntimeAttributeValue.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FRuntimeAttributeValue.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FRuntimeAttributeValue, (UObject*)Z_Construct_UPackage__Script_GASToolsets(), TEXT("RuntimeAttributeValue"));
	}
	return Z_Registration_Info_UScriptStruct_FRuntimeAttributeValue.OuterSingleton;
	}

// ********** Begin ScriptStruct FRuntimeAttributeValue Property Definitions ***********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FRuntimeAttributeValue_Statics::NewProp_AttributeName = { "AttributeName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRuntimeAttributeValue, AttributeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttributeName_MetaData), NewProp_AttributeName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FRuntimeAttributeValue_Statics::NewProp_FullName = { "FullName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRuntimeAttributeValue, FullName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FullName_MetaData), NewProp_FullName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FRuntimeAttributeValue_Statics::NewProp_SetClassName = { "SetClassName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRuntimeAttributeValue, SetClassName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SetClassName_MetaData), NewProp_SetClassName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRuntimeAttributeValue_Statics::NewProp_BaseValue = { "BaseValue", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRuntimeAttributeValue, BaseValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseValue_MetaData), NewProp_BaseValue_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRuntimeAttributeValue_Statics::NewProp_CurrentValue = { "CurrentValue", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRuntimeAttributeValue, CurrentValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentValue_MetaData), NewProp_CurrentValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FRuntimeAttributeValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRuntimeAttributeValue_Statics::NewProp_AttributeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRuntimeAttributeValue_Statics::NewProp_FullName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRuntimeAttributeValue_Statics::NewProp_SetClassName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRuntimeAttributeValue_Statics::NewProp_BaseValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRuntimeAttributeValue_Statics::NewProp_CurrentValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRuntimeAttributeValue_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FRuntimeAttributeValue Property Definitions *************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FRuntimeAttributeValue_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GASToolsets,
	nullptr,
	&NewStructOps,
	"RuntimeAttributeValue",
	Z_Construct_UScriptStruct_FRuntimeAttributeValue_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRuntimeAttributeValue_Statics::PropPointers),
	sizeof(FRuntimeAttributeValue),
	alignof(FRuntimeAttributeValue),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRuntimeAttributeValue_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FRuntimeAttributeValue_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FRuntimeAttributeValue()
{
	if (!Z_Registration_Info_UScriptStruct_FRuntimeAttributeValue.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FRuntimeAttributeValue.InnerSingleton, Z_Construct_UScriptStruct_FRuntimeAttributeValue_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FRuntimeAttributeValue.InnerSingleton);
}
// ********** End ScriptStruct FRuntimeAttributeValue **********************************************

// ********** Begin ScriptStruct FActiveEffectInfo *************************************************
struct Z_Construct_UScriptStruct_FActiveEffectInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FActiveEffectInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FActiveEffectInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Summarizes a gameplay effect that is currently active on an AbilitySystemComponent.\n" },
#endif
		{ "ModuleRelativePath", "Private/AbilitySystemInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Summarizes a gameplay effect that is currently active on an AbilitySystemComponent." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EffectName_MetaData[] = {
		{ "Category", "AbilitySystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The name of the GameplayEffect class (e.g. \"GE_Burning\").\n" },
#endif
		{ "ModuleRelativePath", "Private/AbilitySystemInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The name of the GameplayEffect class (e.g. \"GE_Burning\")." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StackCount_MetaData[] = {
		{ "Category", "AbilitySystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Current stack count. 1 for non-stacking effects.\n" },
#endif
		{ "ModuleRelativePath", "Private/AbilitySystemInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current stack count. 1 for non-stacking effects." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalDuration_MetaData[] = {
		{ "Category", "AbilitySystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Total duration in seconds. -1 means infinite.\n" },
#endif
		{ "ModuleRelativePath", "Private/AbilitySystemInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Total duration in seconds. -1 means infinite." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RemainingDuration_MetaData[] = {
		{ "Category", "AbilitySystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Remaining duration in seconds. -1 means infinite.\n" },
#endif
		{ "ModuleRelativePath", "Private/AbilitySystemInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Remaining duration in seconds. -1 means infinite." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GrantedTags_MetaData[] = {
		{ "Category", "AbilitySystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Tags granted to the owner by this effect.\n" },
#endif
		{ "ModuleRelativePath", "Private/AbilitySystemInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Tags granted to the owner by this effect." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FActiveEffectInfo constinit property declarations *****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_EffectName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_StackCount;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TotalDuration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RemainingDuration;
	static const UECodeGen_Private::FStrPropertyParams NewProp_GrantedTags_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_GrantedTags;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FActiveEffectInfo constinit property declarations *******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FActiveEffectInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FActiveEffectInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FActiveEffectInfo;
class UScriptStruct* FActiveEffectInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FActiveEffectInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FActiveEffectInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FActiveEffectInfo, (UObject*)Z_Construct_UPackage__Script_GASToolsets(), TEXT("ActiveEffectInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FActiveEffectInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FActiveEffectInfo Property Definitions ****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FActiveEffectInfo_Statics::NewProp_EffectName = { "EffectName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActiveEffectInfo, EffectName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EffectName_MetaData), NewProp_EffectName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FActiveEffectInfo_Statics::NewProp_StackCount = { "StackCount", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActiveEffectInfo, StackCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StackCount_MetaData), NewProp_StackCount_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FActiveEffectInfo_Statics::NewProp_TotalDuration = { "TotalDuration", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActiveEffectInfo, TotalDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalDuration_MetaData), NewProp_TotalDuration_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FActiveEffectInfo_Statics::NewProp_RemainingDuration = { "RemainingDuration", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActiveEffectInfo, RemainingDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RemainingDuration_MetaData), NewProp_RemainingDuration_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FActiveEffectInfo_Statics::NewProp_GrantedTags_Inner = { "GrantedTags", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FActiveEffectInfo_Statics::NewProp_GrantedTags = { "GrantedTags", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActiveEffectInfo, GrantedTags), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GrantedTags_MetaData), NewProp_GrantedTags_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FActiveEffectInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActiveEffectInfo_Statics::NewProp_EffectName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActiveEffectInfo_Statics::NewProp_StackCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActiveEffectInfo_Statics::NewProp_TotalDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActiveEffectInfo_Statics::NewProp_RemainingDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActiveEffectInfo_Statics::NewProp_GrantedTags_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActiveEffectInfo_Statics::NewProp_GrantedTags,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActiveEffectInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FActiveEffectInfo Property Definitions ******************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FActiveEffectInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GASToolsets,
	nullptr,
	&NewStructOps,
	"ActiveEffectInfo",
	Z_Construct_UScriptStruct_FActiveEffectInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActiveEffectInfo_Statics::PropPointers),
	sizeof(FActiveEffectInfo),
	alignof(FActiveEffectInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActiveEffectInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FActiveEffectInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FActiveEffectInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FActiveEffectInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FActiveEffectInfo.InnerSingleton, Z_Construct_UScriptStruct_FActiveEffectInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FActiveEffectInfo.InnerSingleton);
}
// ********** End ScriptStruct FActiveEffectInfo ***************************************************

// ********** Begin ScriptStruct FGrantedAbilityInfo ***********************************************
struct Z_Construct_UScriptStruct_FGrantedAbilityInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FGrantedAbilityInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FGrantedAbilityInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Summarizes an ability that has been granted to an AbilitySystemComponent.\n" },
#endif
		{ "ModuleRelativePath", "Private/AbilitySystemInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Summarizes an ability that has been granted to an AbilitySystemComponent." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbilityName_MetaData[] = {
		{ "Category", "AbilitySystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The name of the ability class (e.g. \"GA_Sprint\").\n" },
#endif
		{ "ModuleRelativePath", "Private/AbilitySystemInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The name of the ability class (e.g. \"GA_Sprint\")." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Level_MetaData[] = {
		{ "Category", "AbilitySystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// The level at which this ability was granted.\n" },
#endif
		{ "ModuleRelativePath", "Private/AbilitySystemInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The level at which this ability was granted." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsActive_MetaData[] = {
		{ "Category", "AbilitySystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// True if the ability is currently executing (at least one active instance).\n" },
#endif
		{ "ModuleRelativePath", "Private/AbilitySystemInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "True if the ability is currently executing (at least one active instance)." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FGrantedAbilityInfo constinit property declarations ***************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AbilityName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Level;
	static void NewProp_bIsActive_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsActive;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FGrantedAbilityInfo constinit property declarations *****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGrantedAbilityInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FGrantedAbilityInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FGrantedAbilityInfo;
class UScriptStruct* FGrantedAbilityInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FGrantedAbilityInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FGrantedAbilityInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FGrantedAbilityInfo, (UObject*)Z_Construct_UPackage__Script_GASToolsets(), TEXT("GrantedAbilityInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FGrantedAbilityInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FGrantedAbilityInfo Property Definitions **************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FGrantedAbilityInfo_Statics::NewProp_AbilityName = { "AbilityName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGrantedAbilityInfo, AbilityName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbilityName_MetaData), NewProp_AbilityName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FGrantedAbilityInfo_Statics::NewProp_Level = { "Level", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGrantedAbilityInfo, Level), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Level_MetaData), NewProp_Level_MetaData) };
void Z_Construct_UScriptStruct_FGrantedAbilityInfo_Statics::NewProp_bIsActive_SetBit(void* Obj)
{
	((FGrantedAbilityInfo*)Obj)->bIsActive = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FGrantedAbilityInfo_Statics::NewProp_bIsActive = { "bIsActive", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FGrantedAbilityInfo), &Z_Construct_UScriptStruct_FGrantedAbilityInfo_Statics::NewProp_bIsActive_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsActive_MetaData), NewProp_bIsActive_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGrantedAbilityInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGrantedAbilityInfo_Statics::NewProp_AbilityName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGrantedAbilityInfo_Statics::NewProp_Level,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGrantedAbilityInfo_Statics::NewProp_bIsActive,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGrantedAbilityInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FGrantedAbilityInfo Property Definitions ****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGrantedAbilityInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GASToolsets,
	nullptr,
	&NewStructOps,
	"GrantedAbilityInfo",
	Z_Construct_UScriptStruct_FGrantedAbilityInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGrantedAbilityInfo_Statics::PropPointers),
	sizeof(FGrantedAbilityInfo),
	alignof(FGrantedAbilityInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGrantedAbilityInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FGrantedAbilityInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FGrantedAbilityInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FGrantedAbilityInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FGrantedAbilityInfo.InnerSingleton, Z_Construct_UScriptStruct_FGrantedAbilityInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FGrantedAbilityInfo.InnerSingleton);
}
// ********** End ScriptStruct FGrantedAbilityInfo *************************************************

// ********** Begin Class UAbilitySystemInspectorToolset Function GetActiveEffects *****************
struct Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveEffects_Statics
{
	struct AbilitySystemInspectorToolset_eventGetActiveEffects_Parms
	{
		AActor* Actor;
		TArray<FActiveEffectInfo> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "AbilitySystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns all gameplay effects currently active on the actor's\n\x09 * AbilitySystemComponent.\n\x09 * @param Actor  The target actor.\n\x09 * @return A list of active effect summaries sorted by effect name.\n\x09 *   Raises a script error if Actor is null or has no ASC.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/AbilitySystemInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns all gameplay effects currently active on the actor's\nAbilitySystemComponent.\n@param Actor  The target actor.\n@return A list of active effect summaries sorted by effect name.\n  Raises a script error if Actor is null or has no ASC." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetActiveEffects constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetActiveEffects constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetActiveEffects Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveEffects_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AbilitySystemInspectorToolset_eventGetActiveEffects_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveEffects_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FActiveEffectInfo, METADATA_PARAMS(0, nullptr) }; // 3893272559
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveEffects_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AbilitySystemInspectorToolset_eventGetActiveEffects_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 3893272559
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveEffects_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveEffects_Statics::NewProp_Actor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveEffects_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveEffects_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveEffects_Statics::PropPointers) < 2048);
// ********** End Function GetActiveEffects Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveEffects_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAbilitySystemInspectorToolset, nullptr, "GetActiveEffects", 	Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveEffects_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveEffects_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveEffects_Statics::AbilitySystemInspectorToolset_eventGetActiveEffects_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveEffects_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveEffects_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveEffects_Statics::AbilitySystemInspectorToolset_eventGetActiveEffects_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveEffects()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveEffects_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAbilitySystemInspectorToolset::execGetActiveEffects)
{
	P_GET_OBJECT(AActor,Z_Param_Actor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FActiveEffectInfo>*)Z_Param__Result=UAbilitySystemInspectorToolset::GetActiveEffects(Z_Param_Actor);
	P_NATIVE_END;
}
// ********** End Class UAbilitySystemInspectorToolset Function GetActiveEffects *******************

// ********** Begin Class UAbilitySystemInspectorToolset Function GetActiveTags ********************
struct Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveTags_Statics
{
	struct AbilitySystemInspectorToolset_eventGetActiveTags_Parms
	{
		AActor* Actor;
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "AbilitySystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the gameplay tags currently owned by the actor's\n\x09 * AbilitySystemComponent (includes loose tags, effect-granted tags, etc.).\n\x09 * @param Actor  The target actor.\n\x09 * @return A sorted list of gameplay tag name strings.\n\x09 *   Raises a script error if Actor is null or has no ASC.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/AbilitySystemInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the gameplay tags currently owned by the actor's\nAbilitySystemComponent (includes loose tags, effect-granted tags, etc.).\n@param Actor  The target actor.\n@return A sorted list of gameplay tag name strings.\n  Raises a script error if Actor is null or has no ASC." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetActiveTags constinit property declarations *************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetActiveTags constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetActiveTags Property Definitions ************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveTags_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AbilitySystemInspectorToolset_eventGetActiveTags_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveTags_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveTags_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AbilitySystemInspectorToolset_eventGetActiveTags_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveTags_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveTags_Statics::NewProp_Actor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveTags_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveTags_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveTags_Statics::PropPointers) < 2048);
// ********** End Function GetActiveTags Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveTags_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAbilitySystemInspectorToolset, nullptr, "GetActiveTags", 	Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveTags_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveTags_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveTags_Statics::AbilitySystemInspectorToolset_eventGetActiveTags_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveTags_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveTags_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveTags_Statics::AbilitySystemInspectorToolset_eventGetActiveTags_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveTags()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveTags_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAbilitySystemInspectorToolset::execGetActiveTags)
{
	P_GET_OBJECT(AActor,Z_Param_Actor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=UAbilitySystemInspectorToolset::GetActiveTags(Z_Param_Actor);
	P_NATIVE_END;
}
// ********** End Class UAbilitySystemInspectorToolset Function GetActiveTags **********************

// ********** Begin Class UAbilitySystemInspectorToolset Function GetAttributeValues ***************
struct Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetAttributeValues_Statics
{
	struct AbilitySystemInspectorToolset_eventGetAttributeValues_Parms
	{
		AActor* Actor;
		TArray<FRuntimeAttributeValue> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "AbilitySystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the current base and modified values of all gameplay attributes\n\x09 * on the actor's AbilitySystemComponent.\n\x09 * @param Actor  The target actor.\n\x09 * @return A list of attribute values sorted by full name.\n\x09 *   Raises a script error if Actor is null or has no ASC.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/AbilitySystemInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the current base and modified values of all gameplay attributes\non the actor's AbilitySystemComponent.\n@param Actor  The target actor.\n@return A list of attribute values sorted by full name.\n  Raises a script error if Actor is null or has no ASC." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetAttributeValues constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAttributeValues constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAttributeValues Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetAttributeValues_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AbilitySystemInspectorToolset_eventGetAttributeValues_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetAttributeValues_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FRuntimeAttributeValue, METADATA_PARAMS(0, nullptr) }; // 2822871216
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetAttributeValues_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AbilitySystemInspectorToolset_eventGetAttributeValues_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 2822871216
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetAttributeValues_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetAttributeValues_Statics::NewProp_Actor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetAttributeValues_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetAttributeValues_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetAttributeValues_Statics::PropPointers) < 2048);
// ********** End Function GetAttributeValues Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetAttributeValues_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAbilitySystemInspectorToolset, nullptr, "GetAttributeValues", 	Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetAttributeValues_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetAttributeValues_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetAttributeValues_Statics::AbilitySystemInspectorToolset_eventGetAttributeValues_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetAttributeValues_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetAttributeValues_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetAttributeValues_Statics::AbilitySystemInspectorToolset_eventGetAttributeValues_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetAttributeValues()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetAttributeValues_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAbilitySystemInspectorToolset::execGetAttributeValues)
{
	P_GET_OBJECT(AActor,Z_Param_Actor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FRuntimeAttributeValue>*)Z_Param__Result=UAbilitySystemInspectorToolset::GetAttributeValues(Z_Param_Actor);
	P_NATIVE_END;
}
// ********** End Class UAbilitySystemInspectorToolset Function GetAttributeValues *****************

// ********** Begin Class UAbilitySystemInspectorToolset Function GetGrantedAbilities **************
struct Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetGrantedAbilities_Statics
{
	struct AbilitySystemInspectorToolset_eventGetGrantedAbilities_Parms
	{
		AActor* Actor;
		TArray<FGrantedAbilityInfo> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "AbilitySystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns all abilities granted to the actor's AbilitySystemComponent.\n\x09 * @param Actor  The target actor.\n\x09 * @return A list of granted ability summaries sorted by ability name.\n\x09 *   Raises a script error if Actor is null or has no ASC.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/AbilitySystemInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns all abilities granted to the actor's AbilitySystemComponent.\n@param Actor  The target actor.\n@return A list of granted ability summaries sorted by ability name.\n  Raises a script error if Actor is null or has no ASC." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetGrantedAbilities constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGrantedAbilities constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGrantedAbilities Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetGrantedAbilities_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AbilitySystemInspectorToolset_eventGetGrantedAbilities_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetGrantedAbilities_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGrantedAbilityInfo, METADATA_PARAMS(0, nullptr) }; // 2298203593
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetGrantedAbilities_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AbilitySystemInspectorToolset_eventGetGrantedAbilities_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 2298203593
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetGrantedAbilities_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetGrantedAbilities_Statics::NewProp_Actor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetGrantedAbilities_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetGrantedAbilities_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetGrantedAbilities_Statics::PropPointers) < 2048);
// ********** End Function GetGrantedAbilities Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetGrantedAbilities_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAbilitySystemInspectorToolset, nullptr, "GetGrantedAbilities", 	Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetGrantedAbilities_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetGrantedAbilities_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetGrantedAbilities_Statics::AbilitySystemInspectorToolset_eventGetGrantedAbilities_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetGrantedAbilities_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetGrantedAbilities_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetGrantedAbilities_Statics::AbilitySystemInspectorToolset_eventGetGrantedAbilities_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetGrantedAbilities()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetGrantedAbilities_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAbilitySystemInspectorToolset::execGetGrantedAbilities)
{
	P_GET_OBJECT(AActor,Z_Param_Actor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FGrantedAbilityInfo>*)Z_Param__Result=UAbilitySystemInspectorToolset::GetGrantedAbilities(Z_Param_Actor);
	P_NATIVE_END;
}
// ********** End Class UAbilitySystemInspectorToolset Function GetGrantedAbilities ****************

// ********** Begin Class UAbilitySystemInspectorToolset *******************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UAbilitySystemInspectorToolset;
UClass* UAbilitySystemInspectorToolset::GetPrivateStaticClass()
{
	using TClass = UAbilitySystemInspectorToolset;
	if (!Z_Registration_Info_UClass_UAbilitySystemInspectorToolset.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("AbilitySystemInspectorToolset"),
			Z_Registration_Info_UClass_UAbilitySystemInspectorToolset.InnerSingleton,
			StaticRegisterNativesUAbilitySystemInspectorToolset,
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
	return Z_Registration_Info_UClass_UAbilitySystemInspectorToolset.InnerSingleton;
}
UClass* Z_Construct_UClass_UAbilitySystemInspectorToolset_NoRegister()
{
	return UAbilitySystemInspectorToolset::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UAbilitySystemInspectorToolset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Provides tools for inspecting the runtime state of an AbilitySystemComponent.\n * Each function takes a direct actor pointer and raises a script error if the\n * actor is null or has no AbilitySystemComponent.\n */" },
#endif
		{ "IncludePath", "AbilitySystemInspectorToolset.h" },
		{ "ModuleRelativePath", "Private/AbilitySystemInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Provides tools for inspecting the runtime state of an AbilitySystemComponent.\nEach function takes a direct actor pointer and raises a script error if the\nactor is null or has no AbilitySystemComponent." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UAbilitySystemInspectorToolset constinit property declarations ***********
// ********** End Class UAbilitySystemInspectorToolset constinit property declarations *************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetActiveEffects"), .Pointer = &UAbilitySystemInspectorToolset::execGetActiveEffects },
		{ .NameUTF8 = UTF8TEXT("GetActiveTags"), .Pointer = &UAbilitySystemInspectorToolset::execGetActiveTags },
		{ .NameUTF8 = UTF8TEXT("GetAttributeValues"), .Pointer = &UAbilitySystemInspectorToolset::execGetAttributeValues },
		{ .NameUTF8 = UTF8TEXT("GetGrantedAbilities"), .Pointer = &UAbilitySystemInspectorToolset::execGetGrantedAbilities },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveEffects, "GetActiveEffects" }, // 2157105253
		{ &Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetActiveTags, "GetActiveTags" }, // 785499100
		{ &Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetAttributeValues, "GetAttributeValues" }, // 4098084329
		{ &Z_Construct_UFunction_UAbilitySystemInspectorToolset_GetGrantedAbilities, "GetGrantedAbilities" }, // 1113608290
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAbilitySystemInspectorToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UAbilitySystemInspectorToolset_Statics
UObject* (*const Z_Construct_UClass_UAbilitySystemInspectorToolset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UToolsetDefinition,
	(UObject* (*)())Z_Construct_UPackage__Script_GASToolsets,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAbilitySystemInspectorToolset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAbilitySystemInspectorToolset_Statics::ClassParams = {
	&UAbilitySystemInspectorToolset::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x010000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAbilitySystemInspectorToolset_Statics::Class_MetaDataParams), Z_Construct_UClass_UAbilitySystemInspectorToolset_Statics::Class_MetaDataParams)
};
void UAbilitySystemInspectorToolset::StaticRegisterNativesUAbilitySystemInspectorToolset()
{
	UClass* Class = UAbilitySystemInspectorToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UAbilitySystemInspectorToolset_Statics::Funcs));
}
UClass* Z_Construct_UClass_UAbilitySystemInspectorToolset()
{
	if (!Z_Registration_Info_UClass_UAbilitySystemInspectorToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAbilitySystemInspectorToolset.OuterSingleton, Z_Construct_UClass_UAbilitySystemInspectorToolset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAbilitySystemInspectorToolset.OuterSingleton;
}
UAbilitySystemInspectorToolset::UAbilitySystemInspectorToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UAbilitySystemInspectorToolset);
UAbilitySystemInspectorToolset::~UAbilitySystemInspectorToolset() {}
// ********** End Class UAbilitySystemInspectorToolset *********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AbilitySystemInspectorToolset_h__Script_GASToolsets_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FRuntimeAttributeValue::StaticStruct, Z_Construct_UScriptStruct_FRuntimeAttributeValue_Statics::NewStructOps, TEXT("RuntimeAttributeValue"),&Z_Registration_Info_UScriptStruct_FRuntimeAttributeValue, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FRuntimeAttributeValue), 2822871216U) },
		{ FActiveEffectInfo::StaticStruct, Z_Construct_UScriptStruct_FActiveEffectInfo_Statics::NewStructOps, TEXT("ActiveEffectInfo"),&Z_Registration_Info_UScriptStruct_FActiveEffectInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FActiveEffectInfo), 3893272559U) },
		{ FGrantedAbilityInfo::StaticStruct, Z_Construct_UScriptStruct_FGrantedAbilityInfo_Statics::NewStructOps, TEXT("GrantedAbilityInfo"),&Z_Registration_Info_UScriptStruct_FGrantedAbilityInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGrantedAbilityInfo), 2298203593U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAbilitySystemInspectorToolset, UAbilitySystemInspectorToolset::StaticClass, TEXT("UAbilitySystemInspectorToolset"), &Z_Registration_Info_UClass_UAbilitySystemInspectorToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAbilitySystemInspectorToolset), 3186541952U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AbilitySystemInspectorToolset_h__Script_GASToolsets_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AbilitySystemInspectorToolset_h__Script_GASToolsets_1317871751{
	TEXT("/Script/GASToolsets"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AbilitySystemInspectorToolset_h__Script_GASToolsets_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AbilitySystemInspectorToolset_h__Script_GASToolsets_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AbilitySystemInspectorToolset_h__Script_GASToolsets_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GASToolsets_Source_GASToolsets_Private_AbilitySystemInspectorToolset_h__Script_GASToolsets_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
