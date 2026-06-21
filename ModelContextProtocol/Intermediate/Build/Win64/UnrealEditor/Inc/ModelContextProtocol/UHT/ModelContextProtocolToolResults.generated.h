// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ModelContextProtocolToolResults.h"

#ifdef MODELCONTEXTPROTOCOL_ModelContextProtocolToolResults_generated_h
#error "ModelContextProtocolToolResults.generated.h already included, missing '#pragma once' in ModelContextProtocolToolResults.h"
#endif
#define MODELCONTEXTPROTOCOL_ModelContextProtocolToolResults_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FModelContextProtocolToolResult ***********************************
struct Z_Construct_UScriptStruct_FModelContextProtocolToolResult_Statics;
#define FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolToolResults_h_49_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FModelContextProtocolToolResult_Statics; \
	MODELCONTEXTPROTOCOL_API static class UScriptStruct* StaticStruct(); \
	typedef FJsonObjectWrapper Super;


struct FModelContextProtocolToolResult;
// ********** End ScriptStruct FModelContextProtocolToolResult *************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocol_Public_ModelContextProtocolToolResults_h

// ********** Begin Enum EModelContextProtocolToolResultType ***************************************
#define FOREACH_ENUM_EMODELCONTEXTPROTOCOLTOOLRESULTTYPE(op) \
	op(EModelContextProtocolToolResultType::None) \
	op(EModelContextProtocolToolResultType::Text) \
	op(EModelContextProtocolToolResultType::Image) \
	op(EModelContextProtocolToolResultType::Audio) \
	op(EModelContextProtocolToolResultType::ResourceLink) \
	op(EModelContextProtocolToolResultType::EmbeddedResource) \
	op(EModelContextProtocolToolResultType::StructuredContent) 

enum class EModelContextProtocolToolResultType;
template<> struct TIsUEnumClass<EModelContextProtocolToolResultType> { enum { Value = true }; };
template<> MODELCONTEXTPROTOCOL_NON_ATTRIBUTED_API UEnum* StaticEnum<EModelContextProtocolToolResultType>();
// ********** End Enum EModelContextProtocolToolResultType *****************************************

// ********** Begin Enum EModelContextProtocolAudience *********************************************
#define FOREACH_ENUM_EMODELCONTEXTPROTOCOLAUDIENCE(op) \
	op(EModelContextProtocolAudience::None) \
	op(EModelContextProtocolAudience::User) \
	op(EModelContextProtocolAudience::Assistant) \
	op(EModelContextProtocolAudience::All) 

enum class EModelContextProtocolAudience;
template<> struct TIsUEnumClass<EModelContextProtocolAudience> { enum { Value = true }; };
template<> MODELCONTEXTPROTOCOL_NON_ATTRIBUTED_API UEnum* StaticEnum<EModelContextProtocolAudience>();
// ********** End Enum EModelContextProtocolAudience ***********************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
