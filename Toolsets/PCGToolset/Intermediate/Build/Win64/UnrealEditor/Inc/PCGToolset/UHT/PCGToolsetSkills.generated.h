// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PCGToolsetSkills.h"

#ifdef PCGTOOLSET_PCGToolsetSkills_generated_h
#error "PCGToolsetSkills.generated.h already included, missing '#pragma once' in PCGToolsetSkills.h"
#endif
#define PCGTOOLSET_PCGToolsetSkills_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UPCGGraphGenerationSkill *************************************************
struct Z_Construct_UClass_UPCGGraphGenerationSkill_Statics;
PCGTOOLSET_API UClass* Z_Construct_UClass_UPCGGraphGenerationSkill_NoRegister();

#define FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolsetSkills_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPCGGraphGenerationSkill(); \
	friend struct ::Z_Construct_UClass_UPCGGraphGenerationSkill_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PCGTOOLSET_API UClass* ::Z_Construct_UClass_UPCGGraphGenerationSkill_NoRegister(); \
public: \
	DECLARE_CLASS2(UPCGGraphGenerationSkill, UAgentSkill, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PCGToolset"), Z_Construct_UClass_UPCGGraphGenerationSkill_NoRegister) \
	DECLARE_SERIALIZER(UPCGGraphGenerationSkill)


#define FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolsetSkills_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPCGGraphGenerationSkill(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPCGGraphGenerationSkill(UPCGGraphGenerationSkill&&) = delete; \
	UPCGGraphGenerationSkill(const UPCGGraphGenerationSkill&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPCGGraphGenerationSkill); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPCGGraphGenerationSkill); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPCGGraphGenerationSkill) \
	NO_API virtual ~UPCGGraphGenerationSkill();


#define FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolsetSkills_h_10_PROLOG
#define FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolsetSkills_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolsetSkills_h_13_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolsetSkills_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPCGGraphGenerationSkill;

// ********** End Class UPCGGraphGenerationSkill ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolsetSkills_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
