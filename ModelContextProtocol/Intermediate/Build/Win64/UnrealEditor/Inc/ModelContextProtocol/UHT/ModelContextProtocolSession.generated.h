// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ModelContextProtocolSession.h"

#ifdef MODELCONTEXTPROTOCOL_ModelContextProtocolSession_generated_h
#error "ModelContextProtocolSession.generated.h already included, missing '#pragma once' in ModelContextProtocolSession.h"
#endif
#define MODELCONTEXTPROTOCOL_ModelContextProtocolSession_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FModelContextProtocolClientInfo ***********************************
struct Z_Construct_UScriptStruct_FModelContextProtocolClientInfo_Statics;
#define FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolSession_h_30_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FModelContextProtocolClientInfo_Statics; \
	MODELCONTEXTPROTOCOL_API static class UScriptStruct* StaticStruct();


struct FModelContextProtocolClientInfo;
// ********** End ScriptStruct FModelContextProtocolClientInfo *************************************

// ********** Begin ScriptStruct FModelContextProtocolServerInfo ***********************************
struct Z_Construct_UScriptStruct_FModelContextProtocolServerInfo_Statics;
#define FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolSession_h_45_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FModelContextProtocolServerInfo_Statics; \
	MODELCONTEXTPROTOCOL_API static class UScriptStruct* StaticStruct();


struct FModelContextProtocolServerInfo;
// ********** End ScriptStruct FModelContextProtocolServerInfo *************************************

// ********** Begin ScriptStruct FModelContextProtocolPingResult ***********************************
struct Z_Construct_UScriptStruct_FModelContextProtocolPingResult_Statics;
#define FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolSession_h_60_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FModelContextProtocolPingResult_Statics; \
	MODELCONTEXTPROTOCOL_API static class UScriptStruct* StaticStruct();


struct FModelContextProtocolPingResult;
// ********** End ScriptStruct FModelContextProtocolPingResult *************************************

// ********** Begin ScriptStruct FModelContextProtocolInitializeParams *****************************
struct Z_Construct_UScriptStruct_FModelContextProtocolInitializeParams_Statics;
#define FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolSession_h_66_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FModelContextProtocolInitializeParams_Statics; \
	MODELCONTEXTPROTOCOL_API static class UScriptStruct* StaticStruct();


struct FModelContextProtocolInitializeParams;
// ********** End ScriptStruct FModelContextProtocolInitializeParams *******************************

// ********** Begin ScriptStruct FModelContextProtocolInitializeResult *****************************
struct Z_Construct_UScriptStruct_FModelContextProtocolInitializeResult_Statics;
#define FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolSession_h_81_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FModelContextProtocolInitializeResult_Statics; \
	MODELCONTEXTPROTOCOL_API static class UScriptStruct* StaticStruct();


struct FModelContextProtocolInitializeResult;
// ********** End ScriptStruct FModelContextProtocolInitializeResult *******************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolSession_h

// ********** Begin Enum EModelContextProtocolSessionStatus ****************************************
#define FOREACH_ENUM_EMODELCONTEXTPROTOCOLSESSIONSTATUS(op) \
	op(EModelContextProtocolSessionStatus::Initializing) \
	op(EModelContextProtocolSessionStatus::Initialized) 

enum class EModelContextProtocolSessionStatus;
template<> struct TIsUEnumClass<EModelContextProtocolSessionStatus> { enum { Value = true }; };
template<> MODELCONTEXTPROTOCOL_NON_ATTRIBUTED_API UEnum* StaticEnum<EModelContextProtocolSessionStatus>();
// ********** End Enum EModelContextProtocolSessionStatus ******************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
