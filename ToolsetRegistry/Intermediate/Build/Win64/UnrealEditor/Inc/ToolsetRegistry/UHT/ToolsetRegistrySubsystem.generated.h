// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ToolsetRegistry/ToolsetRegistrySubsystem.h"

#ifdef TOOLSETREGISTRY_ToolsetRegistrySubsystem_generated_h
#error "ToolsetRegistrySubsystem.generated.h already included, missing '#pragma once' in ToolsetRegistrySubsystem.h"
#endif
#define TOOLSETREGISTRY_ToolsetRegistrySubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UToolsetRegistrySettings *************************************************
struct Z_Construct_UClass_UToolsetRegistrySettings_Statics;
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetRegistrySettings_NoRegister();

#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetRegistrySubsystem_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUToolsetRegistrySettings(); \
	friend struct ::Z_Construct_UClass_UToolsetRegistrySettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend TOOLSETREGISTRY_API UClass* ::Z_Construct_UClass_UToolsetRegistrySettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UToolsetRegistrySettings, UDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/ToolsetRegistry"), Z_Construct_UClass_UToolsetRegistrySettings_NoRegister) \
	DECLARE_SERIALIZER(UToolsetRegistrySettings) \
	static constexpr const TCHAR* StaticConfigName() {return TEXT("EditorPerProjectUserSettings");} \



#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetRegistrySubsystem_h_24_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	TOOLSETREGISTRY_API UToolsetRegistrySettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UToolsetRegistrySettings(UToolsetRegistrySettings&&) = delete; \
	UToolsetRegistrySettings(const UToolsetRegistrySettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(TOOLSETREGISTRY_API, UToolsetRegistrySettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UToolsetRegistrySettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UToolsetRegistrySettings) \
	TOOLSETREGISTRY_API virtual ~UToolsetRegistrySettings();


#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetRegistrySubsystem_h_21_PROLOG
#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetRegistrySubsystem_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetRegistrySubsystem_h_24_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetRegistrySubsystem_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UToolsetRegistrySettings;

// ********** End Class UToolsetRegistrySettings ***************************************************

// ********** Begin Class UToolsetRegistrySubsystem ************************************************
struct Z_Construct_UClass_UToolsetRegistrySubsystem_Statics;
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetRegistrySubsystem_NoRegister();

#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetRegistrySubsystem_h_74_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUToolsetRegistrySubsystem(); \
	friend struct ::Z_Construct_UClass_UToolsetRegistrySubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend TOOLSETREGISTRY_API UClass* ::Z_Construct_UClass_UToolsetRegistrySubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UToolsetRegistrySubsystem, UEditorSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ToolsetRegistry"), Z_Construct_UClass_UToolsetRegistrySubsystem_NoRegister) \
	DECLARE_SERIALIZER(UToolsetRegistrySubsystem)


#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetRegistrySubsystem_h_74_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	TOOLSETREGISTRY_API UToolsetRegistrySubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UToolsetRegistrySubsystem(UToolsetRegistrySubsystem&&) = delete; \
	UToolsetRegistrySubsystem(const UToolsetRegistrySubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(TOOLSETREGISTRY_API, UToolsetRegistrySubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UToolsetRegistrySubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UToolsetRegistrySubsystem) \
	TOOLSETREGISTRY_API virtual ~UToolsetRegistrySubsystem();


#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetRegistrySubsystem_h_71_PROLOG
#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetRegistrySubsystem_h_74_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetRegistrySubsystem_h_74_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetRegistrySubsystem_h_74_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UToolsetRegistrySubsystem;

// ********** End Class UToolsetRegistrySubsystem **************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetRegistrySubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
