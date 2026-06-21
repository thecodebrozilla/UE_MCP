// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ModelContextProtocolSession.h"
#include "ModelContextProtocolCapabilities.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeModelContextProtocolSession() {}

// ********** Begin Cross Module References ********************************************************
MODELCONTEXTPROTOCOL_API UEnum* Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolSessionStatus();
MODELCONTEXTPROTOCOL_API UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolClientCapabilities();
MODELCONTEXTPROTOCOL_API UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolClientInfo();
MODELCONTEXTPROTOCOL_API UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolInitializeParams();
MODELCONTEXTPROTOCOL_API UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolInitializeResult();
MODELCONTEXTPROTOCOL_API UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolPingResult();
MODELCONTEXTPROTOCOL_API UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities();
MODELCONTEXTPROTOCOL_API UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolServerInfo();
UPackage* Z_Construct_UPackage__Script_ModelContextProtocol();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EModelContextProtocolSessionStatus ****************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EModelContextProtocolSessionStatus;
static UEnum* EModelContextProtocolSessionStatus_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EModelContextProtocolSessionStatus.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EModelContextProtocolSessionStatus.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolSessionStatus, (UObject*)Z_Construct_UPackage__Script_ModelContextProtocol(), TEXT("EModelContextProtocolSessionStatus"));
	}
	return Z_Registration_Info_UEnum_EModelContextProtocolSessionStatus.OuterSingleton;
}
template<> MODELCONTEXTPROTOCOL_NON_ATTRIBUTED_API UEnum* StaticEnum<EModelContextProtocolSessionStatus>()
{
	return EModelContextProtocolSessionStatus_StaticEnum();
}
struct Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolSessionStatus_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Initialized.Comment", "/** Server and client are both initialized */" },
		{ "Initialized.Name", "EModelContextProtocolSessionStatus::Initialized" },
		{ "Initialized.ToolTip", "Server and client are both initialized" },
		{ "Initializing.Comment", "/** Server and client are handshaking */" },
		{ "Initializing.Name", "EModelContextProtocolSessionStatus::Initializing" },
		{ "Initializing.ToolTip", "Server and client are handshaking" },
		{ "ModuleRelativePath", "Public/ModelContextProtocolSession.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EModelContextProtocolSessionStatus::Initializing", (int64)EModelContextProtocolSessionStatus::Initializing },
		{ "EModelContextProtocolSessionStatus::Initialized", (int64)EModelContextProtocolSessionStatus::Initialized },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolSessionStatus_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolSessionStatus_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ModelContextProtocol,
	nullptr,
	"EModelContextProtocolSessionStatus",
	"EModelContextProtocolSessionStatus",
	Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolSessionStatus_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolSessionStatus_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolSessionStatus_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolSessionStatus_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolSessionStatus()
{
	if (!Z_Registration_Info_UEnum_EModelContextProtocolSessionStatus.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EModelContextProtocolSessionStatus.InnerSingleton, Z_Construct_UEnum_ModelContextProtocol_EModelContextProtocolSessionStatus_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EModelContextProtocolSessionStatus.InnerSingleton;
}
// ********** End Enum EModelContextProtocolSessionStatus ******************************************

// ********** Begin ScriptStruct FModelContextProtocolClientInfo ***********************************
struct Z_Construct_UScriptStruct_FModelContextProtocolClientInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FModelContextProtocolClientInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FModelContextProtocolClientInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ModelContextProtocolSession.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "ModuleRelativePath", "Public/ModelContextProtocolSession.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Title_MetaData[] = {
		{ "ModuleRelativePath", "Public/ModelContextProtocolSession.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Version_MetaData[] = {
		{ "ModuleRelativePath", "Public/ModelContextProtocolSession.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FModelContextProtocolClientInfo constinit property declarations ***
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Title;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Version;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FModelContextProtocolClientInfo constinit property declarations *****
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FModelContextProtocolClientInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FModelContextProtocolClientInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FModelContextProtocolClientInfo;
class UScriptStruct* FModelContextProtocolClientInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolClientInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FModelContextProtocolClientInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FModelContextProtocolClientInfo, (UObject*)Z_Construct_UPackage__Script_ModelContextProtocol(), TEXT("ModelContextProtocolClientInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FModelContextProtocolClientInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FModelContextProtocolClientInfo Property Definitions **************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolClientInfo_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolClientInfo, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolClientInfo_Statics::NewProp_Title = { "Title", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolClientInfo, Title), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Title_MetaData), NewProp_Title_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolClientInfo_Statics::NewProp_Version = { "Version", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolClientInfo, Version), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Version_MetaData), NewProp_Version_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FModelContextProtocolClientInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolClientInfo_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolClientInfo_Statics::NewProp_Title,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolClientInfo_Statics::NewProp_Version,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolClientInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FModelContextProtocolClientInfo Property Definitions ****************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FModelContextProtocolClientInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ModelContextProtocol,
	nullptr,
	&NewStructOps,
	"ModelContextProtocolClientInfo",
	Z_Construct_UScriptStruct_FModelContextProtocolClientInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolClientInfo_Statics::PropPointers),
	sizeof(FModelContextProtocolClientInfo),
	alignof(FModelContextProtocolClientInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolClientInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FModelContextProtocolClientInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolClientInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolClientInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FModelContextProtocolClientInfo.InnerSingleton, Z_Construct_UScriptStruct_FModelContextProtocolClientInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FModelContextProtocolClientInfo.InnerSingleton);
}
// ********** End ScriptStruct FModelContextProtocolClientInfo *************************************

// ********** Begin ScriptStruct FModelContextProtocolServerInfo ***********************************
struct Z_Construct_UScriptStruct_FModelContextProtocolServerInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FModelContextProtocolServerInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FModelContextProtocolServerInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ModelContextProtocolSession.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "ModuleRelativePath", "Public/ModelContextProtocolSession.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Title_MetaData[] = {
		{ "ModuleRelativePath", "Public/ModelContextProtocolSession.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Version_MetaData[] = {
		{ "ModuleRelativePath", "Public/ModelContextProtocolSession.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FModelContextProtocolServerInfo constinit property declarations ***
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Title;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Version;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FModelContextProtocolServerInfo constinit property declarations *****
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FModelContextProtocolServerInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FModelContextProtocolServerInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FModelContextProtocolServerInfo;
class UScriptStruct* FModelContextProtocolServerInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolServerInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FModelContextProtocolServerInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FModelContextProtocolServerInfo, (UObject*)Z_Construct_UPackage__Script_ModelContextProtocol(), TEXT("ModelContextProtocolServerInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FModelContextProtocolServerInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FModelContextProtocolServerInfo Property Definitions **************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolServerInfo_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolServerInfo, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolServerInfo_Statics::NewProp_Title = { "Title", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolServerInfo, Title), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Title_MetaData), NewProp_Title_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolServerInfo_Statics::NewProp_Version = { "Version", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolServerInfo, Version), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Version_MetaData), NewProp_Version_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FModelContextProtocolServerInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolServerInfo_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolServerInfo_Statics::NewProp_Title,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolServerInfo_Statics::NewProp_Version,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolServerInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FModelContextProtocolServerInfo Property Definitions ****************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FModelContextProtocolServerInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ModelContextProtocol,
	nullptr,
	&NewStructOps,
	"ModelContextProtocolServerInfo",
	Z_Construct_UScriptStruct_FModelContextProtocolServerInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolServerInfo_Statics::PropPointers),
	sizeof(FModelContextProtocolServerInfo),
	alignof(FModelContextProtocolServerInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolServerInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FModelContextProtocolServerInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolServerInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolServerInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FModelContextProtocolServerInfo.InnerSingleton, Z_Construct_UScriptStruct_FModelContextProtocolServerInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FModelContextProtocolServerInfo.InnerSingleton);
}
// ********** End ScriptStruct FModelContextProtocolServerInfo *************************************

// ********** Begin ScriptStruct FModelContextProtocolPingResult ***********************************
struct Z_Construct_UScriptStruct_FModelContextProtocolPingResult_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FModelContextProtocolPingResult); }
	static inline consteval int16 GetStructAlignment() { return alignof(FModelContextProtocolPingResult); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ModelContextProtocolSession.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FModelContextProtocolPingResult constinit property declarations ***
// ********** End ScriptStruct FModelContextProtocolPingResult constinit property declarations *****
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FModelContextProtocolPingResult>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FModelContextProtocolPingResult_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FModelContextProtocolPingResult;
class UScriptStruct* FModelContextProtocolPingResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolPingResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FModelContextProtocolPingResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FModelContextProtocolPingResult, (UObject*)Z_Construct_UPackage__Script_ModelContextProtocol(), TEXT("ModelContextProtocolPingResult"));
	}
	return Z_Registration_Info_UScriptStruct_FModelContextProtocolPingResult.OuterSingleton;
	}
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FModelContextProtocolPingResult_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ModelContextProtocol,
	nullptr,
	&NewStructOps,
	"ModelContextProtocolPingResult",
	nullptr,
	0,
	sizeof(FModelContextProtocolPingResult),
	alignof(FModelContextProtocolPingResult),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolPingResult_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FModelContextProtocolPingResult_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolPingResult()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolPingResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FModelContextProtocolPingResult.InnerSingleton, Z_Construct_UScriptStruct_FModelContextProtocolPingResult_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FModelContextProtocolPingResult.InnerSingleton);
}
// ********** End ScriptStruct FModelContextProtocolPingResult *************************************

// ********** Begin ScriptStruct FModelContextProtocolInitializeParams *****************************
struct Z_Construct_UScriptStruct_FModelContextProtocolInitializeParams_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FModelContextProtocolInitializeParams); }
	static inline consteval int16 GetStructAlignment() { return alignof(FModelContextProtocolInitializeParams); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ModelContextProtocolSession.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProtocolVersion_MetaData[] = {
		{ "ModuleRelativePath", "Public/ModelContextProtocolSession.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Capabilities_MetaData[] = {
		{ "ModuleRelativePath", "Public/ModelContextProtocolSession.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClientInfo_MetaData[] = {
		{ "ModuleRelativePath", "Public/ModelContextProtocolSession.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FModelContextProtocolInitializeParams constinit property declarations 
	static const UECodeGen_Private::FStrPropertyParams NewProp_ProtocolVersion;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Capabilities;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ClientInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FModelContextProtocolInitializeParams constinit property declarations 
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FModelContextProtocolInitializeParams>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FModelContextProtocolInitializeParams_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FModelContextProtocolInitializeParams;
class UScriptStruct* FModelContextProtocolInitializeParams::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolInitializeParams.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FModelContextProtocolInitializeParams.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FModelContextProtocolInitializeParams, (UObject*)Z_Construct_UPackage__Script_ModelContextProtocol(), TEXT("ModelContextProtocolInitializeParams"));
	}
	return Z_Registration_Info_UScriptStruct_FModelContextProtocolInitializeParams.OuterSingleton;
	}

// ********** Begin ScriptStruct FModelContextProtocolInitializeParams Property Definitions ********
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolInitializeParams_Statics::NewProp_ProtocolVersion = { "ProtocolVersion", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolInitializeParams, ProtocolVersion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProtocolVersion_MetaData), NewProp_ProtocolVersion_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolInitializeParams_Statics::NewProp_Capabilities = { "Capabilities", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolInitializeParams, Capabilities), Z_Construct_UScriptStruct_FModelContextProtocolClientCapabilities, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Capabilities_MetaData), NewProp_Capabilities_MetaData) }; // 16853613
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolInitializeParams_Statics::NewProp_ClientInfo = { "ClientInfo", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolInitializeParams, ClientInfo), Z_Construct_UScriptStruct_FModelContextProtocolClientInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClientInfo_MetaData), NewProp_ClientInfo_MetaData) }; // 2712049467
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FModelContextProtocolInitializeParams_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolInitializeParams_Statics::NewProp_ProtocolVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolInitializeParams_Statics::NewProp_Capabilities,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolInitializeParams_Statics::NewProp_ClientInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolInitializeParams_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FModelContextProtocolInitializeParams Property Definitions **********
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FModelContextProtocolInitializeParams_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ModelContextProtocol,
	nullptr,
	&NewStructOps,
	"ModelContextProtocolInitializeParams",
	Z_Construct_UScriptStruct_FModelContextProtocolInitializeParams_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolInitializeParams_Statics::PropPointers),
	sizeof(FModelContextProtocolInitializeParams),
	alignof(FModelContextProtocolInitializeParams),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolInitializeParams_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FModelContextProtocolInitializeParams_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolInitializeParams()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolInitializeParams.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FModelContextProtocolInitializeParams.InnerSingleton, Z_Construct_UScriptStruct_FModelContextProtocolInitializeParams_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FModelContextProtocolInitializeParams.InnerSingleton);
}
// ********** End ScriptStruct FModelContextProtocolInitializeParams *******************************

// ********** Begin ScriptStruct FModelContextProtocolInitializeResult *****************************
struct Z_Construct_UScriptStruct_FModelContextProtocolInitializeResult_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FModelContextProtocolInitializeResult); }
	static inline consteval int16 GetStructAlignment() { return alignof(FModelContextProtocolInitializeResult); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ModelContextProtocolSession.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProtocolVersion_MetaData[] = {
		{ "ModuleRelativePath", "Public/ModelContextProtocolSession.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Capabilities_MetaData[] = {
		{ "ModuleRelativePath", "Public/ModelContextProtocolSession.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ServerInfo_MetaData[] = {
		{ "ModuleRelativePath", "Public/ModelContextProtocolSession.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Instructions_MetaData[] = {
		{ "ModuleRelativePath", "Public/ModelContextProtocolSession.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FModelContextProtocolInitializeResult constinit property declarations 
	static const UECodeGen_Private::FStrPropertyParams NewProp_ProtocolVersion;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Capabilities;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ServerInfo;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Instructions_Inner;
	static const UECodeGen_Private::FGenericPropertyParams NewProp_Instructions;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FModelContextProtocolInitializeResult constinit property declarations 
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FModelContextProtocolInitializeResult>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FModelContextProtocolInitializeResult_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FModelContextProtocolInitializeResult;
class UScriptStruct* FModelContextProtocolInitializeResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolInitializeResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FModelContextProtocolInitializeResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FModelContextProtocolInitializeResult, (UObject*)Z_Construct_UPackage__Script_ModelContextProtocol(), TEXT("ModelContextProtocolInitializeResult"));
	}
	return Z_Registration_Info_UScriptStruct_FModelContextProtocolInitializeResult.OuterSingleton;
	}

// ********** Begin ScriptStruct FModelContextProtocolInitializeResult Property Definitions ********
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolInitializeResult_Statics::NewProp_ProtocolVersion = { "ProtocolVersion", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolInitializeResult, ProtocolVersion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProtocolVersion_MetaData), NewProp_ProtocolVersion_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolInitializeResult_Statics::NewProp_Capabilities = { "Capabilities", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolInitializeResult, Capabilities), Z_Construct_UScriptStruct_FModelContextProtocolServerCapabilities, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Capabilities_MetaData), NewProp_Capabilities_MetaData) }; // 3139911809
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolInitializeResult_Statics::NewProp_ServerInfo = { "ServerInfo", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolInitializeResult, ServerInfo), Z_Construct_UScriptStruct_FModelContextProtocolServerInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ServerInfo_MetaData), NewProp_ServerInfo_MetaData) }; // 1811045495
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolInitializeResult_Statics::NewProp_Instructions_Inner = { "Instructions", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FGenericPropertyParams Z_Construct_UScriptStruct_FModelContextProtocolInitializeResult_Statics::NewProp_Instructions = { "Instructions", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Optional, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModelContextProtocolInitializeResult, Instructions), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Instructions_MetaData), NewProp_Instructions_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FModelContextProtocolInitializeResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolInitializeResult_Statics::NewProp_ProtocolVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolInitializeResult_Statics::NewProp_Capabilities,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolInitializeResult_Statics::NewProp_ServerInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolInitializeResult_Statics::NewProp_Instructions_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModelContextProtocolInitializeResult_Statics::NewProp_Instructions,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolInitializeResult_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FModelContextProtocolInitializeResult Property Definitions **********
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FModelContextProtocolInitializeResult_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ModelContextProtocol,
	nullptr,
	&NewStructOps,
	"ModelContextProtocolInitializeResult",
	Z_Construct_UScriptStruct_FModelContextProtocolInitializeResult_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolInitializeResult_Statics::PropPointers),
	sizeof(FModelContextProtocolInitializeResult),
	alignof(FModelContextProtocolInitializeResult),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModelContextProtocolInitializeResult_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FModelContextProtocolInitializeResult_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolInitializeResult()
{
	if (!Z_Registration_Info_UScriptStruct_FModelContextProtocolInitializeResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FModelContextProtocolInitializeResult.InnerSingleton, Z_Construct_UScriptStruct_FModelContextProtocolInitializeResult_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FModelContextProtocolInitializeResult.InnerSingleton);
}
// ********** End ScriptStruct FModelContextProtocolInitializeResult *******************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolSession_h__Script_ModelContextProtocol_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EModelContextProtocolSessionStatus_StaticEnum, TEXT("EModelContextProtocolSessionStatus"), &Z_Registration_Info_UEnum_EModelContextProtocolSessionStatus, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 356196702U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FModelContextProtocolClientInfo::StaticStruct, Z_Construct_UScriptStruct_FModelContextProtocolClientInfo_Statics::NewStructOps, TEXT("ModelContextProtocolClientInfo"),&Z_Registration_Info_UScriptStruct_FModelContextProtocolClientInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FModelContextProtocolClientInfo), 2712049467U) },
		{ FModelContextProtocolServerInfo::StaticStruct, Z_Construct_UScriptStruct_FModelContextProtocolServerInfo_Statics::NewStructOps, TEXT("ModelContextProtocolServerInfo"),&Z_Registration_Info_UScriptStruct_FModelContextProtocolServerInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FModelContextProtocolServerInfo), 1811045495U) },
		{ FModelContextProtocolPingResult::StaticStruct, Z_Construct_UScriptStruct_FModelContextProtocolPingResult_Statics::NewStructOps, TEXT("ModelContextProtocolPingResult"),&Z_Registration_Info_UScriptStruct_FModelContextProtocolPingResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FModelContextProtocolPingResult), 2001110911U) },
		{ FModelContextProtocolInitializeParams::StaticStruct, Z_Construct_UScriptStruct_FModelContextProtocolInitializeParams_Statics::NewStructOps, TEXT("ModelContextProtocolInitializeParams"),&Z_Registration_Info_UScriptStruct_FModelContextProtocolInitializeParams, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FModelContextProtocolInitializeParams), 461120765U) },
		{ FModelContextProtocolInitializeResult::StaticStruct, Z_Construct_UScriptStruct_FModelContextProtocolInitializeResult_Statics::NewStructOps, TEXT("ModelContextProtocolInitializeResult"),&Z_Registration_Info_UScriptStruct_FModelContextProtocolInitializeResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FModelContextProtocolInitializeResult), 393532166U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolSession_h__Script_ModelContextProtocol_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolSession_h__Script_ModelContextProtocol_2667454016{
	TEXT("/Script/ModelContextProtocol"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolSession_h__Script_ModelContextProtocol_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolSession_h__Script_ModelContextProtocol_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolSession_h__Script_ModelContextProtocol_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolSession_h__Script_ModelContextProtocol_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
