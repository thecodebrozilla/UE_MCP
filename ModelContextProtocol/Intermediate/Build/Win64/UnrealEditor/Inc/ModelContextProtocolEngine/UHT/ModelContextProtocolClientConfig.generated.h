// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ModelContextProtocolClientConfig.h"

#ifdef MODELCONTEXTPROTOCOLENGINE_ModelContextProtocolClientConfig_generated_h
#error "ModelContextProtocolClientConfig.generated.h already included, missing '#pragma once' in ModelContextProtocolClientConfig.h"
#endif
#define MODELCONTEXTPROTOCOLENGINE_ModelContextProtocolClientConfig_generated_h

#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "Templates/NoDestroy.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolClientConfig_h

// ********** Begin Enum EModelContextProtocolClient ***********************************************
#define FOREACH_ENUM_EMODELCONTEXTPROTOCOLCLIENT(op) \
	op(EModelContextProtocolClient::ClaudeCode) \
	op(EModelContextProtocolClient::Cursor) \
	op(EModelContextProtocolClient::VSCode) \
	op(EModelContextProtocolClient::Gemini) \
	op(EModelContextProtocolClient::Codex) 

enum class EModelContextProtocolClient : uint8;
template<> struct TIsUEnumClass<EModelContextProtocolClient> { enum { Value = true }; };
template<> MODELCONTEXTPROTOCOLENGINE_NON_ATTRIBUTED_API UEnum* StaticEnum<EModelContextProtocolClient>();
// ********** End Enum EModelContextProtocolClient *************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
