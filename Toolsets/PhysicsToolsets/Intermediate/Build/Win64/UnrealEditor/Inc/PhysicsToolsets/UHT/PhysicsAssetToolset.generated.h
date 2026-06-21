// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PhysicsToolsets/PhysicsAssetToolset.h"

#ifdef PHYSICSTOOLSETS_PhysicsAssetToolset_generated_h
#error "PhysicsAssetToolset.generated.h already included, missing '#pragma once' in PhysicsAssetToolset.h"
#endif
#define PHYSICSTOOLSETS_PhysicsAssetToolset_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPhysicsAsset;
enum class EBodyPhysicsMode : uint8;
struct FPhysicsConstraintInfo;
struct FPhysicsShapeInfo;

// ********** Begin ScriptStruct FPhysicsShapeInfo *************************************************
struct Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics;
#define FID_UE_MCP_Plugins_Toolsets_PhysicsToolsets_Source_PhysicsToolsets_Private_PhysicsToolsets_PhysicsAssetToolset_h_54_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics; \
	PHYSICSTOOLSETS_API static class UScriptStruct* StaticStruct();


struct FPhysicsShapeInfo;
// ********** End ScriptStruct FPhysicsShapeInfo ***************************************************

// ********** Begin ScriptStruct FPhysicsConstraintInfo ********************************************
struct Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics;
#define FID_UE_MCP_Plugins_Toolsets_PhysicsToolsets_Source_PhysicsToolsets_Private_PhysicsToolsets_PhysicsAssetToolset_h_107_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics; \
	PHYSICSTOOLSETS_API static class UScriptStruct* StaticStruct();


struct FPhysicsConstraintInfo;
// ********** End ScriptStruct FPhysicsConstraintInfo **********************************************

// ********** Begin Class UPhysicsAssetToolset *****************************************************
#define FID_UE_MCP_Plugins_Toolsets_PhysicsToolsets_Source_PhysicsToolsets_Private_PhysicsToolsets_PhysicsAssetToolset_h_146_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execRemoveConstraint); \
	DECLARE_FUNCTION(execSetConstraintLimits); \
	DECLARE_FUNCTION(execAddConstraint); \
	DECLARE_FUNCTION(execGetConstraints); \
	DECLARE_FUNCTION(execSetBodyMassScale); \
	DECLARE_FUNCTION(execGetBodyMassScale); \
	DECLARE_FUNCTION(execSetBodyPhysicsMode); \
	DECLARE_FUNCTION(execGetBodyPhysicsMode); \
	DECLARE_FUNCTION(execRemoveBody); \
	DECLARE_FUNCTION(execAddBody); \
	DECLARE_FUNCTION(execRemoveShape); \
	DECLARE_FUNCTION(execSetBox); \
	DECLARE_FUNCTION(execSetCapsule); \
	DECLARE_FUNCTION(execSetSphere); \
	DECLARE_FUNCTION(execGetBodyShapes); \
	DECLARE_FUNCTION(execGetBodyNames); \
	DECLARE_FUNCTION(execCreateFromMesh);


struct Z_Construct_UClass_UPhysicsAssetToolset_Statics;
PHYSICSTOOLSETS_API UClass* Z_Construct_UClass_UPhysicsAssetToolset_NoRegister();

#define FID_UE_MCP_Plugins_Toolsets_PhysicsToolsets_Source_PhysicsToolsets_Private_PhysicsToolsets_PhysicsAssetToolset_h_146_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPhysicsAssetToolset(); \
	friend struct ::Z_Construct_UClass_UPhysicsAssetToolset_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PHYSICSTOOLSETS_API UClass* ::Z_Construct_UClass_UPhysicsAssetToolset_NoRegister(); \
public: \
	DECLARE_CLASS2(UPhysicsAssetToolset, UToolsetDefinition, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PhysicsToolsets"), Z_Construct_UClass_UPhysicsAssetToolset_NoRegister) \
	DECLARE_SERIALIZER(UPhysicsAssetToolset)


#define FID_UE_MCP_Plugins_Toolsets_PhysicsToolsets_Source_PhysicsToolsets_Private_PhysicsToolsets_PhysicsAssetToolset_h_146_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	PHYSICSTOOLSETS_API UPhysicsAssetToolset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPhysicsAssetToolset(UPhysicsAssetToolset&&) = delete; \
	UPhysicsAssetToolset(const UPhysicsAssetToolset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(PHYSICSTOOLSETS_API, UPhysicsAssetToolset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPhysicsAssetToolset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPhysicsAssetToolset) \
	PHYSICSTOOLSETS_API virtual ~UPhysicsAssetToolset();


#define FID_UE_MCP_Plugins_Toolsets_PhysicsToolsets_Source_PhysicsToolsets_Private_PhysicsToolsets_PhysicsAssetToolset_h_143_PROLOG
#define FID_UE_MCP_Plugins_Toolsets_PhysicsToolsets_Source_PhysicsToolsets_Private_PhysicsToolsets_PhysicsAssetToolset_h_146_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_Toolsets_PhysicsToolsets_Source_PhysicsToolsets_Private_PhysicsToolsets_PhysicsAssetToolset_h_146_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_PhysicsToolsets_Source_PhysicsToolsets_Private_PhysicsToolsets_PhysicsAssetToolset_h_146_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_PhysicsToolsets_Source_PhysicsToolsets_Private_PhysicsToolsets_PhysicsAssetToolset_h_146_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPhysicsAssetToolset;

// ********** End Class UPhysicsAssetToolset *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_Toolsets_PhysicsToolsets_Source_PhysicsToolsets_Private_PhysicsToolsets_PhysicsAssetToolset_h

// ********** Begin Enum EPhysicsShapeType *********************************************************
#define FOREACH_ENUM_EPHYSICSSHAPETYPE(op) \
	op(EPhysicsShapeType::Sphere) \
	op(EPhysicsShapeType::Capsule) \
	op(EPhysicsShapeType::Box) 

enum class EPhysicsShapeType : uint8;
template<> struct TIsUEnumClass<EPhysicsShapeType> { enum { Value = true }; };
template<> PHYSICSTOOLSETS_NON_ATTRIBUTED_API UEnum* StaticEnum<EPhysicsShapeType>();
// ********** End Enum EPhysicsShapeType ***********************************************************

// ********** Begin Enum EBodyPhysicsMode **********************************************************
#define FOREACH_ENUM_EBODYPHYSICSMODE(op) \
	op(EBodyPhysicsMode::Default) \
	op(EBodyPhysicsMode::Kinematic) \
	op(EBodyPhysicsMode::Simulated) 

enum class EBodyPhysicsMode : uint8;
template<> struct TIsUEnumClass<EBodyPhysicsMode> { enum { Value = true }; };
template<> PHYSICSTOOLSETS_NON_ATTRIBUTED_API UEnum* StaticEnum<EBodyPhysicsMode>();
// ********** End Enum EBodyPhysicsMode ************************************************************

// ********** Begin Enum EConstraintMotion *********************************************************
#define FOREACH_ENUM_ECONSTRAINTMOTION(op) \
	op(EConstraintMotion::Free) \
	op(EConstraintMotion::Limited) \
	op(EConstraintMotion::Locked) 

enum class EConstraintMotion : uint8;
template<> struct TIsUEnumClass<EConstraintMotion> { enum { Value = true }; };
template<> PHYSICSTOOLSETS_NON_ATTRIBUTED_API UEnum* StaticEnum<EConstraintMotion>();
// ********** End Enum EConstraintMotion ***********************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
