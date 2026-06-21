// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MetaHumanGenerator.h"

#ifdef METAHUMANGENERATOR_MetaHumanGenerator_generated_h
#error "MetaHumanGenerator.generated.h already included, missing '#pragma once' in MetaHumanGenerator.h"
#endif
#define METAHUMANGENERATOR_MetaHumanGenerator_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UMetaHumanCharacter;

// ********** Begin Class UMetaHumanGeneratorSubsystemWrapper **************************************
#define FID_UE_MCP_Plugins_Toolsets_MetaHumanGenerator_Source_Public_MetaHumanGenerator_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execResetNeckToBody);


struct Z_Construct_UClass_UMetaHumanGeneratorSubsystemWrapper_Statics;
METAHUMANGENERATOR_API UClass* Z_Construct_UClass_UMetaHumanGeneratorSubsystemWrapper_NoRegister();

#define FID_UE_MCP_Plugins_Toolsets_MetaHumanGenerator_Source_Public_MetaHumanGenerator_h_25_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMetaHumanGeneratorSubsystemWrapper(); \
	friend struct ::Z_Construct_UClass_UMetaHumanGeneratorSubsystemWrapper_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend METAHUMANGENERATOR_API UClass* ::Z_Construct_UClass_UMetaHumanGeneratorSubsystemWrapper_NoRegister(); \
public: \
	DECLARE_CLASS2(UMetaHumanGeneratorSubsystemWrapper, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MetaHumanGenerator"), Z_Construct_UClass_UMetaHumanGeneratorSubsystemWrapper_NoRegister) \
	DECLARE_SERIALIZER(UMetaHumanGeneratorSubsystemWrapper)


#define FID_UE_MCP_Plugins_Toolsets_MetaHumanGenerator_Source_Public_MetaHumanGenerator_h_25_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMetaHumanGeneratorSubsystemWrapper(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UMetaHumanGeneratorSubsystemWrapper(UMetaHumanGeneratorSubsystemWrapper&&) = delete; \
	UMetaHumanGeneratorSubsystemWrapper(const UMetaHumanGeneratorSubsystemWrapper&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMetaHumanGeneratorSubsystemWrapper); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMetaHumanGeneratorSubsystemWrapper); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMetaHumanGeneratorSubsystemWrapper) \
	NO_API virtual ~UMetaHumanGeneratorSubsystemWrapper();


#define FID_UE_MCP_Plugins_Toolsets_MetaHumanGenerator_Source_Public_MetaHumanGenerator_h_22_PROLOG
#define FID_UE_MCP_Plugins_Toolsets_MetaHumanGenerator_Source_Public_MetaHumanGenerator_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_Toolsets_MetaHumanGenerator_Source_Public_MetaHumanGenerator_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_MetaHumanGenerator_Source_Public_MetaHumanGenerator_h_25_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_MetaHumanGenerator_Source_Public_MetaHumanGenerator_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UMetaHumanGeneratorSubsystemWrapper;

// ********** End Class UMetaHumanGeneratorSubsystemWrapper ****************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_Toolsets_MetaHumanGenerator_Source_Public_MetaHumanGenerator_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
