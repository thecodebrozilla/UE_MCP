// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ModelContextProtocolCapabilities.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeModelContextProtocolCapabilities() {}

// ********** Begin Cross Module References ********************************************************
MODELCONTEXTPROTOCOL_API UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolClientCapabilities();
MODELCONTEXTPROTOCOL_API UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolElicitationCapability();
MODELCONTEXTPROTOCOL_API UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolLoggingCapability();
MODELCONTEXTPROTOCOL_API UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolPromptsCapability();
MODELCONTEXTPROTOCOL_API UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolResourcesCapability();
MODELCONTEXTPROTOCOL_API UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolRootsCapability();
MODELCONTEXTPROTOCOL_API UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolSamplingCapability();
MODELCONTEXTPROTOCOL_API UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities();
MODELCONTEXTPROTOCOL_API UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolToolsCapability();
UPackage* Z_Construct_UPackage__Script_ModelContextProtocol();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FModelContextProtocolRootsCapability ******************************
struct Z_Construct_UScriptStruct_FModelContextProtocolRootsCapability_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FModelContextProtocolRootsCapability); }
	static inline consteval int16 GetStructAlignment() { return alignof(FModelContextProtocolRootsCapability); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ModelContextProtocolCapabilities.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ListChanged_MetaData[] = {
		{ "Category", "Capabilities" },
		{ "ModuleRelativePath", "Public/ModelContextProtocolCapabilities.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FModelContextProtocolRootsCapability constinit property declarations 
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ListChanged_Inner;
	static const UECodeGen_Private::FGenericPropertyParams NewProp_ListChanged;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FModelContextProtocolRootsCapability constinit property declarations 
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FModelContextProtocolRootsCapability>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FModelContextProtocolRootsCapability_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FModelContextProtocolRootsCapability;
class UScriptStruct* FModelContextProtocolRootsCapability::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolRootsCapability.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FModelContextProtocolRootsCapability.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FModelContextProtocolRootsCapability, (UObject*)Z_Construct_UPackage__Script_ModelContextProtocol(), TEXT("ModelContextProtocolRootsCapability"));
	}
	return Z_Registration_Info_UScriptStruct_FModelContextProtocolRootsCapability.OuterSingleton;
	}

// ********** Begin ScriptStruct FModelContextProtocolRootsCapability Property Definitions *********
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolRootsCapability_Statics::NewProp_ListChanged_Inner = { "ListChanged", nullptr, (EPropertyFlags)0x0000000000020001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FGenericPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolRootsCapability_Statics::NewProp_ListChanged = { "ListChanged", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Optional, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolRootsCapability, ListChanged), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ListChanged_MetaData), NewProp_ListChanged_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FModelContextProtocolRootsCapability_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolRootsCapability_Statics::NewProp_ListChanged_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolRootsCapability_Statics::NewProp_ListChanged,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolRootsCapability_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FModelContextProtocolRootsCapability Property Definitions ***********
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FModelContextProtocolRootsCapability_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ModelContextProtocol,
	nullptr,
	&NewStructOps,
	"ModelContextProtocolRootsCapability",
	Z_Construct_UScriptStruct_FModelContextProtocolRootsCapability_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolRootsCapability_Statics::PropPointers),
	sizeof(FModelContextProtocolRootsCapability),
	alignof(FModelContextProtocolRootsCapability),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolRootsCapability_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FModelContextProtocolRootsCapability_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolRootsCapability()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolRootsCapability.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FModelContextProtocolRootsCapability.InnerSingleton, Z_Construct_UScriptStruct_FModelContextProtocolRootsCapability_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FModelContextProtocolRootsCapability.InnerSingleton);
}
// ********** End ScriptStruct FModelContextProtocolRootsCapability ********************************

// ********** Begin ScriptStruct FModelContextProtocolSamplingCapability ***************************
struct Z_Construct_UScriptStruct_FModelContextProtocolSamplingCapability_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FModelContextProtocolSamplingCapability); }
	static inline consteval int16 GetStructAlignment() { return alignof(FModelContextProtocolSamplingCapability); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ModelContextProtocolCapabilities.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FModelContextProtocolSamplingCapability constinit property declarations 
// ********** End ScriptStruct FModelContextProtocolSamplingCapability constinit property declarations 
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FModelContextProtocolSamplingCapability>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FModelContextProtocolSamplingCapability_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FModelContextProtocolSamplingCapability;
class UScriptStruct* FModelContextProtocolSamplingCapability::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolSamplingCapability.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FModelContextProtocolSamplingCapability.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FModelContextProtocolSamplingCapability, (UObject*)Z_Construct_UPackage__Script_ModelContextProtocol(), TEXT("ModelContextProtocolSamplingCapability"));
	}
	return Z_Registration_Info_UScriptStruct_FModelContextProtocolSamplingCapability.OuterSingleton;
	}
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FModelContextProtocolSamplingCapability_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ModelContextProtocol,
	nullptr,
	&NewStructOps,
	"ModelContextProtocolSamplingCapability",
	nullptr,
	0,
	sizeof(FModelContextProtocolSamplingCapability),
	alignof(FModelContextProtocolSamplingCapability),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolSamplingCapability_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FModelContextProtocolSamplingCapability_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolSamplingCapability()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolSamplingCapability.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FModelContextProtocolSamplingCapability.InnerSingleton, Z_Construct_UScriptStruct_FModelContextProtocolSamplingCapability_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FModelContextProtocolSamplingCapability.InnerSingleton);
}
// ********** End ScriptStruct FModelContextProtocolSamplingCapability *****************************

// ********** Begin ScriptStruct FModelContextProtocolElicitationCapability ************************
struct Z_Construct_UScriptStruct_FModelContextProtocolElicitationCapability_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FModelContextProtocolElicitationCapability); }
	static inline consteval int16 GetStructAlignment() { return alignof(FModelContextProtocolElicitationCapability); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ModelContextProtocolCapabilities.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FModelContextProtocolElicitationCapability constinit property declarations 
// ********** End ScriptStruct FModelContextProtocolElicitationCapability constinit property declarations 
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FModelContextProtocolElicitationCapability>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FModelContextProtocolElicitationCapability_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FModelContextProtocolElicitationCapability;
class UScriptStruct* FModelContextProtocolElicitationCapability::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolElicitationCapability.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FModelContextProtocolElicitationCapability.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FModelContextProtocolElicitationCapability, (UObject*)Z_Construct_UPackage__Script_ModelContextProtocol(), TEXT("ModelContextProtocolElicitationCapability"));
	}
	return Z_Registration_Info_UScriptStruct_FModelContextProtocolElicitationCapability.OuterSingleton;
	}
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FModelContextProtocolElicitationCapability_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ModelContextProtocol,
	nullptr,
	&NewStructOps,
	"ModelContextProtocolElicitationCapability",
	nullptr,
	0,
	sizeof(FModelContextProtocolElicitationCapability),
	alignof(FModelContextProtocolElicitationCapability),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolElicitationCapability_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FModelContextProtocolElicitationCapability_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolElicitationCapability()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolElicitationCapability.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FModelContextProtocolElicitationCapability.InnerSingleton, Z_Construct_UScriptStruct_FModelContextProtocolElicitationCapability_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FModelContextProtocolElicitationCapability.InnerSingleton);
}
// ********** End ScriptStruct FModelContextProtocolElicitationCapability **************************

// ********** Begin ScriptStruct FModelContextProtocolClientCapabilities ***************************
struct Z_Construct_UScriptStruct_FModelContextProtocolClientCapabilities_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FModelContextProtocolClientCapabilities); }
	static inline consteval int16 GetStructAlignment() { return alignof(FModelContextProtocolClientCapabilities); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ModelContextProtocolCapabilities.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Roots_MetaData[] = {
		{ "Category", "Capabilities" },
		{ "ModuleRelativePath", "Public/ModelContextProtocolCapabilities.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Sampling_MetaData[] = {
		{ "Category", "Capabilities" },
		{ "ModuleRelativePath", "Public/ModelContextProtocolCapabilities.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Elicitation_MetaData[] = {
		{ "Category", "Capabilities" },
		{ "ModuleRelativePath", "Public/ModelContextProtocolCapabilities.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FModelContextProtocolClientCapabilities constinit property declarations 
	static const UECodeGen_Private::FStructPropertyParams NewProp_Roots_Inner;
	static const UECodeGen_Private::FGenericPropertyParams NewProp_Roots;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Sampling_Inner;
	static const UECodeGen_Private::FGenericPropertyParams NewProp_Sampling;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Elicitation_Inner;
	static const UECodeGen_Private::FGenericPropertyParams NewProp_Elicitation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FModelContextProtocolClientCapabilities constinit property declarations 
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FModelContextProtocolClientCapabilities>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FModelContextProtocolClientCapabilities_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FModelContextProtocolClientCapabilities;
class UScriptStruct* FModelContextProtocolClientCapabilities::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolClientCapabilities.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FModelContextProtocolClientCapabilities.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FModelContextProtocolClientCapabilities, (UObject*)Z_Construct_UPackage__Script_ModelContextProtocol(), TEXT("ModelContextProtocolClientCapabilities"));
	}
	return Z_Registration_Info_UScriptStruct_FModelContextProtocolClientCapabilities.OuterSingleton;
	}

// ********** Begin ScriptStruct FModelContextProtocolClientCapabilities Property Definitions ******
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolClientCapabilities_Statics::NewProp_Roots_Inner = { "Roots", nullptr, (EPropertyFlags)0x0000000000020001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FModelContextProtocolRootsCapability, METADATA_PARAMS(0, nullptr) }; // 1410381822
const UECodeGen_Private::FGenericPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolClientCapabilities_Statics::NewProp_Roots = { "Roots", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Optional, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolClientCapabilities, Roots), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Roots_MetaData), NewProp_Roots_MetaData) }; // 1410381822
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolClientCapabilities_Statics::NewProp_Sampling_Inner = { "Sampling", nullptr, (EPropertyFlags)0x0000000000020001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FModelContextProtocolSamplingCapability, METADATA_PARAMS(0, nullptr) }; // 3842701395
const UECodeGen_Private::FGenericPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolClientCapabilities_Statics::NewProp_Sampling = { "Sampling", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Optional, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolClientCapabilities, Sampling), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Sampling_MetaData), NewProp_Sampling_MetaData) }; // 3842701395
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolClientCapabilities_Statics::NewProp_Elicitation_Inner = { "Elicitation", nullptr, (EPropertyFlags)0x0000000000020001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FModelContextProtocolElicitationCapability, METADATA_PARAMS(0, nullptr) }; // 3958163714
const UECodeGen_Private::FGenericPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolClientCapabilities_Statics::NewProp_Elicitation = { "Elicitation", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Optional, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolClientCapabilities, Elicitation), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Elicitation_MetaData), NewProp_Elicitation_MetaData) }; // 3958163714
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FModelContextProtocolClientCapabilities_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolClientCapabilities_Statics::NewProp_Roots_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolClientCapabilities_Statics::NewProp_Roots,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolClientCapabilities_Statics::NewProp_Sampling_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolClientCapabilities_Statics::NewProp_Sampling,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolClientCapabilities_Statics::NewProp_Elicitation_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolClientCapabilities_Statics::NewProp_Elicitation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolClientCapabilities_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FModelContextProtocolClientCapabilities Property Definitions ********
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FModelContextProtocolClientCapabilities_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ModelContextProtocol,
	nullptr,
	&NewStructOps,
	"ModelContextProtocolClientCapabilities",
	Z_Construct_UScriptStruct_FModelContextProtocolClientCapabilities_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolClientCapabilities_Statics::PropPointers),
	sizeof(FModelContextProtocolClientCapabilities),
	alignof(FModelContextProtocolClientCapabilities),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolClientCapabilities_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FModelContextProtocolClientCapabilities_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolClientCapabilities()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolClientCapabilities.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FModelContextProtocolClientCapabilities.InnerSingleton, Z_Construct_UScriptStruct_FModelContextProtocolClientCapabilities_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FModelContextProtocolClientCapabilities.InnerSingleton);
}
// ********** End ScriptStruct FModelContextProtocolClientCapabilities *****************************

// ********** Begin ScriptStruct FModelContextProtocolLoggingCapability ****************************
struct Z_Construct_UScriptStruct_FModelContextProtocolLoggingCapability_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FModelContextProtocolLoggingCapability); }
	static inline consteval int16 GetStructAlignment() { return alignof(FModelContextProtocolLoggingCapability); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ModelContextProtocolCapabilities.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FModelContextProtocolLoggingCapability constinit property declarations 
// ********** End ScriptStruct FModelContextProtocolLoggingCapability constinit property declarations 
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FModelContextProtocolLoggingCapability>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FModelContextProtocolLoggingCapability_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FModelContextProtocolLoggingCapability;
class UScriptStruct* FModelContextProtocolLoggingCapability::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolLoggingCapability.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FModelContextProtocolLoggingCapability.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FModelContextProtocolLoggingCapability, (UObject*)Z_Construct_UPackage__Script_ModelContextProtocol(), TEXT("ModelContextProtocolLoggingCapability"));
	}
	return Z_Registration_Info_UScriptStruct_FModelContextProtocolLoggingCapability.OuterSingleton;
	}
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FModelContextProtocolLoggingCapability_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ModelContextProtocol,
	nullptr,
	&NewStructOps,
	"ModelContextProtocolLoggingCapability",
	nullptr,
	0,
	sizeof(FModelContextProtocolLoggingCapability),
	alignof(FModelContextProtocolLoggingCapability),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolLoggingCapability_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FModelContextProtocolLoggingCapability_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolLoggingCapability()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolLoggingCapability.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FModelContextProtocolLoggingCapability.InnerSingleton, Z_Construct_UScriptStruct_FModelContextProtocolLoggingCapability_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FModelContextProtocolLoggingCapability.InnerSingleton);
}
// ********** End ScriptStruct FModelContextProtocolLoggingCapability ******************************

// ********** Begin ScriptStruct FModelContextProtocolPromptsCapability ****************************
struct Z_Construct_UScriptStruct_FModelContextProtocolPromptsCapability_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FModelContextProtocolPromptsCapability); }
	static inline consteval int16 GetStructAlignment() { return alignof(FModelContextProtocolPromptsCapability); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ModelContextProtocolCapabilities.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ListChanged_MetaData[] = {
		{ "Category", "Capabilities" },
		{ "ModuleRelativePath", "Public/ModelContextProtocolCapabilities.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FModelContextProtocolPromptsCapability constinit property declarations 
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ListChanged_Inner;
	static const UECodeGen_Private::FGenericPropertyParams NewProp_ListChanged;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FModelContextProtocolPromptsCapability constinit property declarations 
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FModelContextProtocolPromptsCapability>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FModelContextProtocolPromptsCapability_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FModelContextProtocolPromptsCapability;
class UScriptStruct* FModelContextProtocolPromptsCapability::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolPromptsCapability.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FModelContextProtocolPromptsCapability.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FModelContextProtocolPromptsCapability, (UObject*)Z_Construct_UPackage__Script_ModelContextProtocol(), TEXT("ModelContextProtocolPromptsCapability"));
	}
	return Z_Registration_Info_UScriptStruct_FModelContextProtocolPromptsCapability.OuterSingleton;
	}

// ********** Begin ScriptStruct FModelContextProtocolPromptsCapability Property Definitions *******
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolPromptsCapability_Statics::NewProp_ListChanged_Inner = { "ListChanged", nullptr, (EPropertyFlags)0x0000000000020001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FGenericPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolPromptsCapability_Statics::NewProp_ListChanged = { "ListChanged", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Optional, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolPromptsCapability, ListChanged), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ListChanged_MetaData), NewProp_ListChanged_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FModelContextProtocolPromptsCapability_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolPromptsCapability_Statics::NewProp_ListChanged_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolPromptsCapability_Statics::NewProp_ListChanged,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolPromptsCapability_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FModelContextProtocolPromptsCapability Property Definitions *********
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FModelContextProtocolPromptsCapability_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ModelContextProtocol,
	nullptr,
	&NewStructOps,
	"ModelContextProtocolPromptsCapability",
	Z_Construct_UScriptStruct_FModelContextProtocolPromptsCapability_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolPromptsCapability_Statics::PropPointers),
	sizeof(FModelContextProtocolPromptsCapability),
	alignof(FModelContextProtocolPromptsCapability),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolPromptsCapability_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FModelContextProtocolPromptsCapability_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolPromptsCapability()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolPromptsCapability.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FModelContextProtocolPromptsCapability.InnerSingleton, Z_Construct_UScriptStruct_FModelContextProtocolPromptsCapability_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FModelContextProtocolPromptsCapability.InnerSingleton);
}
// ********** End ScriptStruct FModelContextProtocolPromptsCapability ******************************

// ********** Begin ScriptStruct FModelContextProtocolResourcesCapability **************************
struct Z_Construct_UScriptStruct_FModelContextProtocolResourcesCapability_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FModelContextProtocolResourcesCapability); }
	static inline consteval int16 GetStructAlignment() { return alignof(FModelContextProtocolResourcesCapability); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ModelContextProtocolCapabilities.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Subscribe_MetaData[] = {
		{ "Category", "Capabilities" },
		{ "ModuleRelativePath", "Public/ModelContextProtocolCapabilities.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ListChanged_MetaData[] = {
		{ "Category", "Capabilities" },
		{ "ModuleRelativePath", "Public/ModelContextProtocolCapabilities.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FModelContextProtocolResourcesCapability constinit property declarations 
	static const UECodeGen_Private::FBoolPropertyParams NewProp_Subscribe_Inner;
	static const UECodeGen_Private::FGenericPropertyParams NewProp_Subscribe;
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ListChanged_Inner;
	static const UECodeGen_Private::FGenericPropertyParams NewProp_ListChanged;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FModelContextProtocolResourcesCapability constinit property declarations 
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FModelContextProtocolResourcesCapability>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FModelContextProtocolResourcesCapability_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FModelContextProtocolResourcesCapability;
class UScriptStruct* FModelContextProtocolResourcesCapability::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolResourcesCapability.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FModelContextProtocolResourcesCapability.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FModelContextProtocolResourcesCapability, (UObject*)Z_Construct_UPackage__Script_ModelContextProtocol(), TEXT("ModelContextProtocolResourcesCapability"));
	}
	return Z_Registration_Info_UScriptStruct_FModelContextProtocolResourcesCapability.OuterSingleton;
	}

// ********** Begin ScriptStruct FModelContextProtocolResourcesCapability Property Definitions *****
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolResourcesCapability_Statics::NewProp_Subscribe_Inner = { "Subscribe", nullptr, (EPropertyFlags)0x0000000000020001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FGenericPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolResourcesCapability_Statics::NewProp_Subscribe = { "Subscribe", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Optional, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolResourcesCapability, Subscribe), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Subscribe_MetaData), NewProp_Subscribe_MetaData) };
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolResourcesCapability_Statics::NewProp_ListChanged_Inner = { "ListChanged", nullptr, (EPropertyFlags)0x0000000000020001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FGenericPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolResourcesCapability_Statics::NewProp_ListChanged = { "ListChanged", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Optional, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolResourcesCapability, ListChanged), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ListChanged_MetaData), NewProp_ListChanged_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FModelContextProtocolResourcesCapability_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolResourcesCapability_Statics::NewProp_Subscribe_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolResourcesCapability_Statics::NewProp_Subscribe,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolResourcesCapability_Statics::NewProp_ListChanged_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolResourcesCapability_Statics::NewProp_ListChanged,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolResourcesCapability_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FModelContextProtocolResourcesCapability Property Definitions *******
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FModelContextProtocolResourcesCapability_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ModelContextProtocol,
	nullptr,
	&NewStructOps,
	"ModelContextProtocolResourcesCapability",
	Z_Construct_UScriptStruct_FModelContextProtocolResourcesCapability_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolResourcesCapability_Statics::PropPointers),
	sizeof(FModelContextProtocolResourcesCapability),
	alignof(FModelContextProtocolResourcesCapability),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolResourcesCapability_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FModelContextProtocolResourcesCapability_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolResourcesCapability()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolResourcesCapability.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FModelContextProtocolResourcesCapability.InnerSingleton, Z_Construct_UScriptStruct_FModelContextProtocolResourcesCapability_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FModelContextProtocolResourcesCapability.InnerSingleton);
}
// ********** End ScriptStruct FModelContextProtocolResourcesCapability ****************************

// ********** Begin ScriptStruct FModelContextProtocolToolsCapability ******************************
struct Z_Construct_UScriptStruct_FModelContextProtocolToolsCapability_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FModelContextProtocolToolsCapability); }
	static inline consteval int16 GetStructAlignment() { return alignof(FModelContextProtocolToolsCapability); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ModelContextProtocolCapabilities.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ListChanged_MetaData[] = {
		{ "Category", "Capabilities" },
		{ "ModuleRelativePath", "Public/ModelContextProtocolCapabilities.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FModelContextProtocolToolsCapability constinit property declarations 
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ListChanged_Inner;
	static const UECodeGen_Private::FGenericPropertyParams NewProp_ListChanged;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FModelContextProtocolToolsCapability constinit property declarations 
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FModelContextProtocolToolsCapability>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FModelContextProtocolToolsCapability_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FModelContextProtocolToolsCapability;
class UScriptStruct* FModelContextProtocolToolsCapability::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolToolsCapability.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FModelContextProtocolToolsCapability.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FModelContextProtocolToolsCapability, (UObject*)Z_Construct_UPackage__Script_ModelContextProtocol(), TEXT("ModelContextProtocolToolsCapability"));
	}
	return Z_Registration_Info_UScriptStruct_FModelContextProtocolToolsCapability.OuterSingleton;
	}

// ********** Begin ScriptStruct FModelContextProtocolToolsCapability Property Definitions *********
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolToolsCapability_Statics::NewProp_ListChanged_Inner = { "ListChanged", nullptr, (EPropertyFlags)0x0000000000020001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FGenericPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolToolsCapability_Statics::NewProp_ListChanged = { "ListChanged", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Optional, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolToolsCapability, ListChanged), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ListChanged_MetaData), NewProp_ListChanged_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FModelContextProtocolToolsCapability_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolToolsCapability_Statics::NewProp_ListChanged_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolToolsCapability_Statics::NewProp_ListChanged,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolToolsCapability_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FModelContextProtocolToolsCapability Property Definitions ***********
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FModelContextProtocolToolsCapability_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ModelContextProtocol,
	nullptr,
	&NewStructOps,
	"ModelContextProtocolToolsCapability",
	Z_Construct_UScriptStruct_FModelContextProtocolToolsCapability_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolToolsCapability_Statics::PropPointers),
	sizeof(FModelContextProtocolToolsCapability),
	alignof(FModelContextProtocolToolsCapability),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolToolsCapability_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FModelContextProtocolToolsCapability_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolToolsCapability()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolToolsCapability.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FModelContextProtocolToolsCapability.InnerSingleton, Z_Construct_UScriptStruct_FModelContextProtocolToolsCapability_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FModelContextProtocolToolsCapability.InnerSingleton);
}
// ********** End ScriptStruct FModelContextProtocolToolsCapability ********************************

// ********** Begin ScriptStruct FModelContextProtocolServerCapabilities ***************************
struct Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FModelContextProtocolServerCapabilities); }
	static inline consteval int16 GetStructAlignment() { return alignof(FModelContextProtocolServerCapabilities); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ModelContextProtocolCapabilities.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Logging_MetaData[] = {
		{ "Category", "Capabilities" },
		{ "ModuleRelativePath", "Public/ModelContextProtocolCapabilities.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Prompts_MetaData[] = {
		{ "Category", "Capabilities" },
		{ "ModuleRelativePath", "Public/ModelContextProtocolCapabilities.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Resources_MetaData[] = {
		{ "Category", "Capabilities" },
		{ "ModuleRelativePath", "Public/ModelContextProtocolCapabilities.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Tools_MetaData[] = {
		{ "Category", "Capabilities" },
		{ "ModuleRelativePath", "Public/ModelContextProtocolCapabilities.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FModelContextProtocolServerCapabilities constinit property declarations 
	static const UECodeGen_Private::FStructPropertyParams NewProp_Logging_Inner;
	static const UECodeGen_Private::FGenericPropertyParams NewProp_Logging;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Prompts_Inner;
	static const UECodeGen_Private::FGenericPropertyParams NewProp_Prompts;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Resources_Inner;
	static const UECodeGen_Private::FGenericPropertyParams NewProp_Resources;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Tools_Inner;
	static const UECodeGen_Private::FGenericPropertyParams NewProp_Tools;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FModelContextProtocolServerCapabilities constinit property declarations 
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FModelContextProtocolServerCapabilities>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FModelContextProtocolServerCapabilities;
class UScriptStruct* FModelContextProtocolServerCapabilities::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolServerCapabilities.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FModelContextProtocolServerCapabilities.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities, (UObject*)Z_Construct_UPackage__Script_ModelContextProtocol(), TEXT("ModelContextProtocolServerCapabilities"));
	}
	return Z_Registration_Info_UScriptStruct_FModelContextProtocolServerCapabilities.OuterSingleton;
	}

// ********** Begin ScriptStruct FModelContextProtocolServerCapabilities Property Definitions ******
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities_Statics::NewProp_Logging_Inner = { "Logging", nullptr, (EPropertyFlags)0x0000000000020001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FModelContextProtocolLoggingCapability, METADATA_PARAMS(0, nullptr) }; // 1036532332
const UECodeGen_Private::FGenericPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities_Statics::NewProp_Logging = { "Logging", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Optional, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolServerCapabilities, Logging), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Logging_MetaData), NewProp_Logging_MetaData) }; // 1036532332
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities_Statics::NewProp_Prompts_Inner = { "Prompts", nullptr, (EPropertyFlags)0x0000000000020001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FModelContextProtocolPromptsCapability, METADATA_PARAMS(0, nullptr) }; // 3354730122
const UECodeGen_Private::FGenericPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities_Statics::NewProp_Prompts = { "Prompts", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Optional, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolServerCapabilities, Prompts), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Prompts_MetaData), NewProp_Prompts_MetaData) }; // 3354730122
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities_Statics::NewProp_Resources_Inner = { "Resources", nullptr, (EPropertyFlags)0x0000000000020001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FModelContextProtocolResourcesCapability, METADATA_PARAMS(0, nullptr) }; // 1746944612
const UECodeGen_Private::FGenericPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities_Statics::NewProp_Resources = { "Resources", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Optional, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolServerCapabilities, Resources), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Resources_MetaData), NewProp_Resources_MetaData) }; // 1746944612
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities_Statics::NewProp_Tools_Inner = { "Tools", nullptr, (EPropertyFlags)0x0000000000020001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FModelContextProtocolToolsCapability, METADATA_PARAMS(0, nullptr) }; // 1374373714
const UECodeGen_Private::FGenericPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities_Statics::NewProp_Tools = { "Tools", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Optional, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolServerCapabilities, Tools), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Tools_MetaData), NewProp_Tools_MetaData) }; // 1374373714
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities_Statics::NewProp_Logging_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities_Statics::NewProp_Logging,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities_Statics::NewProp_Prompts_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities_Statics::NewProp_Prompts,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities_Statics::NewProp_Resources_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities_Statics::NewProp_Resources,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities_Statics::NewProp_Tools_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities_Statics::NewProp_Tools,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FModelContextProtocolServerCapabilities Property Definitions ********
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ModelContextProtocol,
	nullptr,
	&NewStructOps,
	"ModelContextProtocolServerCapabilities",
	Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities_Statics::PropPointers),
	sizeof(FModelContextProtocolServerCapabilities),
	alignof(FModelContextProtocolServerCapabilities),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolServerCapabilities.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FModelContextProtocolServerCapabilities.InnerSingleton, Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FModelContextProtocolServerCapabilities.InnerSingleton);
}
// ********** End ScriptStruct FModelContextProtocolServerCapabilities *****************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolCapabilities_h__Script_ModelContextProtocol_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FModelContextProtocolRootsCapability::StaticStruct, Z_Construct_UScriptStruct_FModelContextProtocolRootsCapability_Statics::NewStructOps, TEXT("ModelContextProtocolRootsCapability"),&Z_Registration_Info_UScriptStruct_FModelContextProtocolRootsCapability, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FModelContextProtocolRootsCapability), 1410381822U) },
		{ FModelContextProtocolSamplingCapability::StaticStruct, Z_Construct_UScriptStruct_FModelContextProtocolSamplingCapability_Statics::NewStructOps, TEXT("ModelContextProtocolSamplingCapability"),&Z_Registration_Info_UScriptStruct_FModelContextProtocolSamplingCapability, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FModelContextProtocolSamplingCapability), 3842701395U) },
		{ FModelContextProtocolElicitationCapability::StaticStruct, Z_Construct_UScriptStruct_FModelContextProtocolElicitationCapability_Statics::NewStructOps, TEXT("ModelContextProtocolElicitationCapability"),&Z_Registration_Info_UScriptStruct_FModelContextProtocolElicitationCapability, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FModelContextProtocolElicitationCapability), 3958163714U) },
		{ FModelContextProtocolClientCapabilities::StaticStruct, Z_Construct_UScriptStruct_FModelContextProtocolClientCapabilities_Statics::NewStructOps, TEXT("ModelContextProtocolClientCapabilities"),&Z_Registration_Info_UScriptStruct_FModelContextProtocolClientCapabilities, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FModelContextProtocolClientCapabilities), 16853613U) },
		{ FModelContextProtocolLoggingCapability::StaticStruct, Z_Construct_UScriptStruct_FModelContextProtocolLoggingCapability_Statics::NewStructOps, TEXT("ModelContextProtocolLoggingCapability"),&Z_Registration_Info_UScriptStruct_FModelContextProtocolLoggingCapability, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FModelContextProtocolLoggingCapability), 1036532332U) },
		{ FModelContextProtocolPromptsCapability::StaticStruct, Z_Construct_UScriptStruct_FModelContextProtocolPromptsCapability_Statics::NewStructOps, TEXT("ModelContextProtocolPromptsCapability"),&Z_Registration_Info_UScriptStruct_FModelContextProtocolPromptsCapability, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FModelContextProtocolPromptsCapability), 3354730122U) },
		{ FModelContextProtocolResourcesCapability::StaticStruct, Z_Construct_UScriptStruct_FModelContextProtocolResourcesCapability_Statics::NewStructOps, TEXT("ModelContextProtocolResourcesCapability"),&Z_Registration_Info_UScriptStruct_FModelContextProtocolResourcesCapability, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FModelContextProtocolResourcesCapability), 1746944612U) },
		{ FModelContextProtocolToolsCapability::StaticStruct, Z_Construct_UScriptStruct_FModelContextProtocolToolsCapability_Statics::NewStructOps, TEXT("ModelContextProtocolToolsCapability"),&Z_Registration_Info_UScriptStruct_FModelContextProtocolToolsCapability, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FModelContextProtocolToolsCapability), 1374373714U) },
		{ FModelContextProtocolServerCapabilities::StaticStruct, Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities_Statics::NewStructOps, TEXT("ModelContextProtocolServerCapabilities"),&Z_Registration_Info_UScriptStruct_FModelContextProtocolServerCapabilities, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FModelContextProtocolServerCapabilities), 3139911809U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolCapabilities_h__Script_ModelContextProtocol_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolCapabilities_h__Script_ModelContextProtocol_2131496907{
	TEXT("/Script/ModelContextProtocol"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolCapabilities_h__Script_ModelContextProtocol_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolCapabilities_h__Script_ModelContextProtocol_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
