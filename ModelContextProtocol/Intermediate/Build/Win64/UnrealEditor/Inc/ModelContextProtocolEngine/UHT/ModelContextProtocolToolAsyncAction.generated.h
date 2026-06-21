// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ModelContextProtocolToolAsyncAction.h"

#ifdef MODELCONTEXTPROTOCOLENGINE_ModelContextProtocolToolAsyncAction_generated_h
#error "ModelContextProtocolToolAsyncAction.generated.h already included, missing '#pragma once' in ModelContextProtocolToolAsyncAction.h"
#endif
#define MODELCONTEXTPROTOCOLENGINE_ModelContextProtocolToolAsyncAction_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UModelContextProtocolToolAsyncAction *************************************
struct Z_Construct_UClass_UModelContextProtocolToolAsyncAction_Statics;
MODELCONTEXTPROTOCOLENGINE_API UClass* Z_Construct_UClass_UModelContextProtocolToolAsyncAction_NoRegister();

#define FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolToolAsyncAction_h_26_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUModelContextProtocolToolAsyncAction(); \
	friend struct ::Z_Construct_UClass_UModelContextProtocolToolAsyncAction_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend MODELCONTEXTPROTOCOLENGINE_API UClass* ::Z_Construct_UClass_UModelContextProtocolToolAsyncAction_NoRegister(); \
public: \
	DECLARE_CLASS2(UModelContextProtocolToolAsyncAction, UCancellableAsyncAction, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/ModelContextProtocolEngine"), Z_Construct_UClass_UModelContextProtocolToolAsyncAction_NoRegister) \
	DECLARE_SERIALIZER(UModelContextProtocolToolAsyncAction)


#define FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolToolAsyncAction_h_26_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	MODELCONTEXTPROTOCOLENGINE_API UModelContextProtocolToolAsyncAction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UModelContextProtocolToolAsyncAction(UModelContextProtocolToolAsyncAction&&) = delete; \
	UModelContextProtocolToolAsyncAction(const UModelContextProtocolToolAsyncAction&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(MODELCONTEXTPROTOCOLENGINE_API, UModelContextProtocolToolAsyncAction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UModelContextProtocolToolAsyncAction); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UModelContextProtocolToolAsyncAction) \
	MODELCONTEXTPROTOCOLENGINE_API virtual ~UModelContextProtocolToolAsyncAction();


#define FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolToolAsyncAction_h_23_PROLOG
#define FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolToolAsyncAction_h_26_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolToolAsyncAction_h_26_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolToolAsyncAction_h_26_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UModelContextProtocolToolAsyncAction;

// ********** End Class UModelContextProtocolToolAsyncAction ***************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolToolAsyncAction_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
