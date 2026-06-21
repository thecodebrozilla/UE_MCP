// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GameFeaturesToolset.h"

#ifdef GAMEFEATURESTOOLSET_GameFeaturesToolset_generated_h
#error "GameFeaturesToolset.generated.h already included, missing '#pragma once' in GameFeaturesToolset.h"
#endif
#define GAMEFEATURESTOOLSET_GameFeaturesToolset_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EPluginToolsetGFPState : uint8;

// ********** Begin Class UGameFeaturesToolset *****************************************************
#define FID_UE_MCP_Plugins_Toolsets_GameFeaturesToolset_Source_GameFeaturesToolset_Private_GameFeaturesToolset_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execRequestDeactivateGameFeature); \
	DECLARE_FUNCTION(execRequestActivateGameFeature); \
	DECLARE_FUNCTION(execGetGameFeatureState); \
	DECLARE_FUNCTION(execIsGameFeatureActive); \
	DECLARE_FUNCTION(execIsGameFeaturePlugin); \
	DECLARE_FUNCTION(execListDiscoveredGameFeaturePlugins); \
	DECLARE_FUNCTION(execListEnabledGameFeaturePlugins);


struct Z_Construct_UClass_UGameFeaturesToolset_Statics;
GAMEFEATURESTOOLSET_API UClass* Z_Construct_UClass_UGameFeaturesToolset_NoRegister();

#define FID_UE_MCP_Plugins_Toolsets_GameFeaturesToolset_Source_GameFeaturesToolset_Private_GameFeaturesToolset_h_30_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGameFeaturesToolset(); \
	friend struct ::Z_Construct_UClass_UGameFeaturesToolset_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GAMEFEATURESTOOLSET_API UClass* ::Z_Construct_UClass_UGameFeaturesToolset_NoRegister(); \
public: \
	DECLARE_CLASS2(UGameFeaturesToolset, UToolsetDefinition, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameFeaturesToolset"), Z_Construct_UClass_UGameFeaturesToolset_NoRegister) \
	DECLARE_SERIALIZER(UGameFeaturesToolset)


#define FID_UE_MCP_Plugins_Toolsets_GameFeaturesToolset_Source_GameFeaturesToolset_Private_GameFeaturesToolset_h_30_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGameFeaturesToolset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UGameFeaturesToolset(UGameFeaturesToolset&&) = delete; \
	UGameFeaturesToolset(const UGameFeaturesToolset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGameFeaturesToolset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameFeaturesToolset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGameFeaturesToolset) \
	NO_API virtual ~UGameFeaturesToolset();


#define FID_UE_MCP_Plugins_Toolsets_GameFeaturesToolset_Source_GameFeaturesToolset_Private_GameFeaturesToolset_h_27_PROLOG
#define FID_UE_MCP_Plugins_Toolsets_GameFeaturesToolset_Source_GameFeaturesToolset_Private_GameFeaturesToolset_h_30_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_Toolsets_GameFeaturesToolset_Source_GameFeaturesToolset_Private_GameFeaturesToolset_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_GameFeaturesToolset_Source_GameFeaturesToolset_Private_GameFeaturesToolset_h_30_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_GameFeaturesToolset_Source_GameFeaturesToolset_Private_GameFeaturesToolset_h_30_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UGameFeaturesToolset;

// ********** End Class UGameFeaturesToolset *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_Toolsets_GameFeaturesToolset_Source_GameFeaturesToolset_Private_GameFeaturesToolset_h

// ********** Begin Enum EPluginToolsetGFPState ****************************************************
#define FOREACH_ENUM_EPLUGINTOOLSETGFPSTATE(op) \
	op(EPluginToolsetGFPState::Uninitialized) \
	op(EPluginToolsetGFPState::Installed) \
	op(EPluginToolsetGFPState::Registered) \
	op(EPluginToolsetGFPState::Loaded) \
	op(EPluginToolsetGFPState::Active) \
	op(EPluginToolsetGFPState::Unknown) 

enum class EPluginToolsetGFPState : uint8;
template<> struct TIsUEnumClass<EPluginToolsetGFPState> { enum { Value = true }; };
template<> GAMEFEATURESTOOLSET_NON_ATTRIBUTED_API UEnum* StaticEnum<EPluginToolsetGFPState>();
// ********** End Enum EPluginToolsetGFPState ******************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
