// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ToolsetRegistry/ToolsetLibrary.h"

#ifdef TOOLSETREGISTRY_ToolsetLibrary_generated_h
#error "ToolsetLibrary.generated.h already included, missing '#pragma once' in ToolsetLibrary.h"
#endif
#define TOOLSETREGISTRY_ToolsetLibrary_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UClass;
class UObject;
class UScriptStruct;
class UStruct;
enum class EBypassContainerCheck : uint8;
struct FSoftClassPath;

// ********** Begin Class UToolsetLibrary **********************************************************
#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetLibrary_h_32_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetActiveUndoCount); \
	DECLARE_FUNCTION(execUndoTransaction); \
	DECLARE_FUNCTION(execGetDerivedStructs); \
	DECLARE_FUNCTION(execGetDerivedClasses); \
	DECLARE_FUNCTION(execSetObjectProperties); \
	DECLARE_FUNCTION(execGetObjectProperties); \
	DECLARE_FUNCTION(execListStructProperties);


struct Z_Construct_UClass_UToolsetLibrary_Statics;
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetLibrary_NoRegister();

#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetLibrary_h_32_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUToolsetLibrary(); \
	friend struct ::Z_Construct_UClass_UToolsetLibrary_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend TOOLSETREGISTRY_API UClass* ::Z_Construct_UClass_UToolsetLibrary_NoRegister(); \
public: \
	DECLARE_CLASS2(UToolsetLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ToolsetRegistry"), Z_Construct_UClass_UToolsetLibrary_NoRegister) \
	DECLARE_SERIALIZER(UToolsetLibrary)


#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetLibrary_h_32_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	TOOLSETREGISTRY_API UToolsetLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UToolsetLibrary(UToolsetLibrary&&) = delete; \
	UToolsetLibrary(const UToolsetLibrary&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(TOOLSETREGISTRY_API, UToolsetLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UToolsetLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UToolsetLibrary) \
	TOOLSETREGISTRY_API virtual ~UToolsetLibrary();


#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetLibrary_h_29_PROLOG
#define FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetLibrary_h_32_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetLibrary_h_32_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetLibrary_h_32_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetLibrary_h_32_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UToolsetLibrary;

// ********** End Class UToolsetLibrary ************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetLibrary_h

// ********** Begin Enum EBypassContainerCheck *****************************************************
#define FOREACH_ENUM_EBYPASSCONTAINERCHECK(op) \
	op(EBypassContainerCheck::No) \
	op(EBypassContainerCheck::Yes) 

enum class EBypassContainerCheck : uint8;
template<> struct TIsUEnumClass<EBypassContainerCheck> { enum { Value = true }; };
template<> TOOLSETREGISTRY_NON_ATTRIBUTED_API UEnum* StaticEnum<EBypassContainerCheck>();
// ********** End Enum EBypassContainerCheck *******************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
