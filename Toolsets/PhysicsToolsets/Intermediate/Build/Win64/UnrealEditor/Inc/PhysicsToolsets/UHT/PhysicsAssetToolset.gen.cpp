// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PhysicsToolsets/PhysicsAssetToolset.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodePhysicsAssetToolset() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_UPhysicsAsset_NoRegister();
PHYSICSTOOLSETS_API UClass* Z_Construct_UClass_UPhysicsAssetToolset();
PHYSICSTOOLSETS_API UClass* Z_Construct_UClass_UPhysicsAssetToolset_NoRegister();
PHYSICSTOOLSETS_API UEnum* Z_Construct_UEnum_PhysicsToolsets_EBodyPhysicsMode();
PHYSICSTOOLSETS_API UEnum* Z_Construct_UEnum_PhysicsToolsets_EConstraintMotion();
PHYSICSTOOLSETS_API UEnum* Z_Construct_UEnum_PhysicsToolsets_EPhysicsShapeType();
PHYSICSTOOLSETS_API UScriptStruct* Z_Construct_UScriptStruct_FPhysicsConstraintInfo();
PHYSICSTOOLSETS_API UScriptStruct* Z_Construct_UScriptStruct_FPhysicsShapeInfo();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition();
UPackage* Z_Construct_UPackage__Script_PhysicsToolsets();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EPhysicsShapeType *********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPhysicsShapeType;
static UEnum* EPhysicsShapeType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EPhysicsShapeType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EPhysicsShapeType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PhysicsToolsets_EPhysicsShapeType, (UObject*)Z_Construct_UPackage__Script_PhysicsToolsets(), TEXT("EPhysicsShapeType"));
	}
	return Z_Registration_Info_UEnum_EPhysicsShapeType.OuterSingleton;
}
template<> PHYSICSTOOLSETS_NON_ATTRIBUTED_API UEnum* StaticEnum<EPhysicsShapeType>()
{
	return EPhysicsShapeType_StaticEnum();
}
struct Z_Construct_UEnum_PhysicsToolsets_EPhysicsShapeType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Box.Name", "EPhysicsShapeType::Box" },
		{ "Capsule.Name", "EPhysicsShapeType::Capsule" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The type of collision primitive. */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
		{ "Sphere.Name", "EPhysicsShapeType::Sphere" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The type of collision primitive." },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EPhysicsShapeType::Sphere", (int64)EPhysicsShapeType::Sphere },
		{ "EPhysicsShapeType::Capsule", (int64)EPhysicsShapeType::Capsule },
		{ "EPhysicsShapeType::Box", (int64)EPhysicsShapeType::Box },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_PhysicsToolsets_EPhysicsShapeType_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PhysicsToolsets_EPhysicsShapeType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_PhysicsToolsets,
	nullptr,
	"EPhysicsShapeType",
	"EPhysicsShapeType",
	Z_Construct_UEnum_PhysicsToolsets_EPhysicsShapeType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_PhysicsToolsets_EPhysicsShapeType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PhysicsToolsets_EPhysicsShapeType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PhysicsToolsets_EPhysicsShapeType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_PhysicsToolsets_EPhysicsShapeType()
{
	if (!Z_Registration_Info_UEnum_EPhysicsShapeType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPhysicsShapeType.InnerSingleton, Z_Construct_UEnum_PhysicsToolsets_EPhysicsShapeType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EPhysicsShapeType.InnerSingleton;
}
// ********** End Enum EPhysicsShapeType ***********************************************************

// ********** Begin Enum EBodyPhysicsMode **********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EBodyPhysicsMode;
static UEnum* EBodyPhysicsMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EBodyPhysicsMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EBodyPhysicsMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PhysicsToolsets_EBodyPhysicsMode, (UObject*)Z_Construct_UPackage__Script_PhysicsToolsets(), TEXT("EBodyPhysicsMode"));
	}
	return Z_Registration_Info_UEnum_EBodyPhysicsMode.OuterSingleton;
}
template<> PHYSICSTOOLSETS_NON_ATTRIBUTED_API UEnum* StaticEnum<EBodyPhysicsMode>()
{
	return EBodyPhysicsMode_StaticEnum();
}
struct Z_Construct_UEnum_PhysicsToolsets_EBodyPhysicsMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Controls whether a physics body participates in world simulation. */" },
#endif
		{ "Default.Comment", "/** Follows the skeletal mesh component's simulation state. */" },
		{ "Default.Name", "EBodyPhysicsMode::Default" },
		{ "Default.ToolTip", "Follows the skeletal mesh component's simulation state." },
		{ "Kinematic.Comment", "/** Always kinematic: moves with animation and is not simulated. */" },
		{ "Kinematic.Name", "EBodyPhysicsMode::Kinematic" },
		{ "Kinematic.ToolTip", "Always kinematic: moves with animation and is not simulated." },
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
		{ "Simulated.Comment", "/** Always simulated, regardless of the component's state. */" },
		{ "Simulated.Name", "EBodyPhysicsMode::Simulated" },
		{ "Simulated.ToolTip", "Always simulated, regardless of the component's state." },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Controls whether a physics body participates in world simulation." },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EBodyPhysicsMode::Default", (int64)EBodyPhysicsMode::Default },
		{ "EBodyPhysicsMode::Kinematic", (int64)EBodyPhysicsMode::Kinematic },
		{ "EBodyPhysicsMode::Simulated", (int64)EBodyPhysicsMode::Simulated },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_PhysicsToolsets_EBodyPhysicsMode_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PhysicsToolsets_EBodyPhysicsMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_PhysicsToolsets,
	nullptr,
	"EBodyPhysicsMode",
	"EBodyPhysicsMode",
	Z_Construct_UEnum_PhysicsToolsets_EBodyPhysicsMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_PhysicsToolsets_EBodyPhysicsMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PhysicsToolsets_EBodyPhysicsMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PhysicsToolsets_EBodyPhysicsMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_PhysicsToolsets_EBodyPhysicsMode()
{
	if (!Z_Registration_Info_UEnum_EBodyPhysicsMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EBodyPhysicsMode.InnerSingleton, Z_Construct_UEnum_PhysicsToolsets_EBodyPhysicsMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EBodyPhysicsMode.InnerSingleton;
}
// ********** End Enum EBodyPhysicsMode ************************************************************

// ********** Begin Enum EConstraintMotion *********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EConstraintMotion;
static UEnum* EConstraintMotion_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EConstraintMotion.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EConstraintMotion.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PhysicsToolsets_EConstraintMotion, (UObject*)Z_Construct_UPackage__Script_PhysicsToolsets(), TEXT("EConstraintMotion"));
	}
	return Z_Registration_Info_UEnum_EConstraintMotion.OuterSingleton;
}
template<> PHYSICSTOOLSETS_NON_ATTRIBUTED_API UEnum* StaticEnum<EConstraintMotion>()
{
	return EConstraintMotion_StaticEnum();
}
struct Z_Construct_UEnum_PhysicsToolsets_EConstraintMotion_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** How a constraint axis may move. */" },
#endif
		{ "Free.Comment", "/** No restriction \xe2\x80\x94 the axis is completely free. */" },
		{ "Free.Name", "EConstraintMotion::Free" },
		{ "Free.ToolTip", "No restriction \xe2\x80\x94 the axis is completely free." },
		{ "Limited.Comment", "/** Restricted to the specified limit angle. */" },
		{ "Limited.Name", "EConstraintMotion::Limited" },
		{ "Limited.ToolTip", "Restricted to the specified limit angle." },
		{ "Locked.Comment", "/** Fully locked \xe2\x80\x94 no movement on this axis. */" },
		{ "Locked.Name", "EConstraintMotion::Locked" },
		{ "Locked.ToolTip", "Fully locked \xe2\x80\x94 no movement on this axis." },
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "How a constraint axis may move." },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EConstraintMotion::Free", (int64)EConstraintMotion::Free },
		{ "EConstraintMotion::Limited", (int64)EConstraintMotion::Limited },
		{ "EConstraintMotion::Locked", (int64)EConstraintMotion::Locked },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_PhysicsToolsets_EConstraintMotion_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PhysicsToolsets_EConstraintMotion_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_PhysicsToolsets,
	nullptr,
	"EConstraintMotion",
	"EConstraintMotion",
	Z_Construct_UEnum_PhysicsToolsets_EConstraintMotion_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_PhysicsToolsets_EConstraintMotion_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PhysicsToolsets_EConstraintMotion_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PhysicsToolsets_EConstraintMotion_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_PhysicsToolsets_EConstraintMotion()
{
	if (!Z_Registration_Info_UEnum_EConstraintMotion.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EConstraintMotion.InnerSingleton, Z_Construct_UEnum_PhysicsToolsets_EConstraintMotion_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EConstraintMotion.InnerSingleton;
}
// ********** End Enum EConstraintMotion ***********************************************************

// ********** Begin ScriptStruct FPhysicsShapeInfo *************************************************
struct Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FPhysicsShapeInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FPhysicsShapeInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Describes a single collision primitive on a physics body.\n * All positions and rotations are in the bone's local space.\n */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Describes a single collision primitive on a physics body.\nAll positions and rotations are in the bone's local space." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShapeName_MetaData[] = {
		{ "Category", "PhysicsShape" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** User-defined name that uniquely identifies this shape on the body. */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "User-defined name that uniquely identifies this shape on the body." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShapeType_MetaData[] = {
		{ "Category", "PhysicsShape" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The type of collision primitive. */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The type of collision primitive." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Center_MetaData[] = {
		{ "Category", "PhysicsShape" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Center position in bone-local space (cm). */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Center position in bone-local space (cm)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_MetaData[] = {
		{ "Category", "PhysicsShape" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Orientation in bone-local space.\n\x09 * For Capsule, Z is the long axis. Unused for Sphere.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Orientation in bone-local space.\nFor Capsule, Z is the long axis. Unused for Sphere." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Radius_MetaData[] = {
		{ "Category", "PhysicsShape" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Radius (cm). Used by Sphere and Capsule. */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Radius (cm). Used by Sphere and Capsule." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Length_MetaData[] = {
		{ "Category", "PhysicsShape" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Cylinder section length (cm). Used by Capsule only.\n\x09 * Total capsule height = Length + 2 * Radius.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cylinder section length (cm). Used by Capsule only.\nTotal capsule height = Length + 2 * Radius." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExtentX_MetaData[] = {
		{ "Category", "PhysicsShape" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Full extent along local X (cm). Used by Box only. */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Full extent along local X (cm). Used by Box only." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExtentY_MetaData[] = {
		{ "Category", "PhysicsShape" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Full extent along local Y (cm). Used by Box only. */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Full extent along local Y (cm). Used by Box only." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExtentZ_MetaData[] = {
		{ "Category", "PhysicsShape" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Full extent along local Z (cm). Used by Box only. */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Full extent along local Z (cm). Used by Box only." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FPhysicsShapeInfo constinit property declarations *****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ShapeName;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ShapeType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ShapeType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Center;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Radius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Length;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ExtentX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ExtentY;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ExtentZ;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FPhysicsShapeInfo constinit property declarations *******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPhysicsShapeInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FPhysicsShapeInfo;
class UScriptStruct* FPhysicsShapeInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FPhysicsShapeInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FPhysicsShapeInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPhysicsShapeInfo, (UObject*)Z_Construct_UPackage__Script_PhysicsToolsets(), TEXT("PhysicsShapeInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FPhysicsShapeInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FPhysicsShapeInfo Property Definitions ****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics::NewProp_ShapeName = { "ShapeName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPhysicsShapeInfo, ShapeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShapeName_MetaData), NewProp_ShapeName_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics::NewProp_ShapeType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics::NewProp_ShapeType = { "ShapeType", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPhysicsShapeInfo, ShapeType), Z_Construct_UEnum_PhysicsToolsets_EPhysicsShapeType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShapeType_MetaData), NewProp_ShapeType_MetaData) }; // 2939295466
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics::NewProp_Center = { "Center", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPhysicsShapeInfo, Center), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Center_MetaData), NewProp_Center_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPhysicsShapeInfo, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_MetaData), NewProp_Rotation_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics::NewProp_Radius = { "Radius", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPhysicsShapeInfo, Radius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Radius_MetaData), NewProp_Radius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics::NewProp_Length = { "Length", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPhysicsShapeInfo, Length), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Length_MetaData), NewProp_Length_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics::NewProp_ExtentX = { "ExtentX", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPhysicsShapeInfo, ExtentX), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExtentX_MetaData), NewProp_ExtentX_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics::NewProp_ExtentY = { "ExtentY", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPhysicsShapeInfo, ExtentY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExtentY_MetaData), NewProp_ExtentY_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics::NewProp_ExtentZ = { "ExtentZ", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPhysicsShapeInfo, ExtentZ), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExtentZ_MetaData), NewProp_ExtentZ_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics::NewProp_ShapeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics::NewProp_ShapeType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics::NewProp_ShapeType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics::NewProp_Center,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics::NewProp_Rotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics::NewProp_Radius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics::NewProp_Length,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics::NewProp_ExtentX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics::NewProp_ExtentY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics::NewProp_ExtentZ,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FPhysicsShapeInfo Property Definitions ******************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_PhysicsToolsets,
	nullptr,
	&NewStructOps,
	"PhysicsShapeInfo",
	Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics::PropPointers),
	sizeof(FPhysicsShapeInfo),
	alignof(FPhysicsShapeInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FPhysicsShapeInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FPhysicsShapeInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FPhysicsShapeInfo.InnerSingleton, Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FPhysicsShapeInfo.InnerSingleton);
}
// ********** End ScriptStruct FPhysicsShapeInfo ***************************************************

// ********** Begin ScriptStruct FPhysicsConstraintInfo ********************************************
struct Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FPhysicsConstraintInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FPhysicsConstraintInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Describes the angular limits for a single constraint between two bodies.\n * Bone1 is the child bone; Bone2 is the parent bone.\n * All limit angles are in degrees [0, 180].\n */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Describes the angular limits for a single constraint between two bodies.\nBone1 is the child bone; Bone2 is the parent bone.\nAll limit angles are in degrees [0, 180]." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Bone1Name_MetaData[] = {
		{ "Category", "PhysicsConstraint" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Name of the child bone. */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Name of the child bone." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Bone2Name_MetaData[] = {
		{ "Category", "PhysicsConstraint" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Name of the parent bone. */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Name of the parent bone." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Swing1Motion_MetaData[] = {
		{ "Category", "PhysicsConstraint" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Motion type for Swing 1 (rotation around the body-local Y axis). */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Motion type for Swing 1 (rotation around the body-local Y axis)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Swing1LimitDegrees_MetaData[] = {
		{ "Category", "PhysicsConstraint" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Swing 1 limit in degrees. Used when Swing1Motion is Limited. */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Swing 1 limit in degrees. Used when Swing1Motion is Limited." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Swing2Motion_MetaData[] = {
		{ "Category", "PhysicsConstraint" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Motion type for Swing 2 (rotation around the body-local Z axis). */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Motion type for Swing 2 (rotation around the body-local Z axis)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Swing2LimitDegrees_MetaData[] = {
		{ "Category", "PhysicsConstraint" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Swing 2 limit in degrees. Used when Swing2Motion is Limited. */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Swing 2 limit in degrees. Used when Swing2Motion is Limited." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TwistMotion_MetaData[] = {
		{ "Category", "PhysicsConstraint" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Motion type for Twist (rotation around the body-local X axis). */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Motion type for Twist (rotation around the body-local X axis)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TwistLimitDegrees_MetaData[] = {
		{ "Category", "PhysicsConstraint" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Twist limit in degrees. Used when TwistMotion is Limited. */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Twist limit in degrees. Used when TwistMotion is Limited." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FPhysicsConstraintInfo constinit property declarations ************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Bone1Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Bone2Name;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Swing1Motion_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Swing1Motion;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Swing1LimitDegrees;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Swing2Motion_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Swing2Motion;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Swing2LimitDegrees;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TwistMotion_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TwistMotion;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TwistLimitDegrees;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FPhysicsConstraintInfo constinit property declarations **************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPhysicsConstraintInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FPhysicsConstraintInfo;
class UScriptStruct* FPhysicsConstraintInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FPhysicsConstraintInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FPhysicsConstraintInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPhysicsConstraintInfo, (UObject*)Z_Construct_UPackage__Script_PhysicsToolsets(), TEXT("PhysicsConstraintInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FPhysicsConstraintInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FPhysicsConstraintInfo Property Definitions ***********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics::NewProp_Bone1Name = { "Bone1Name", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPhysicsConstraintInfo, Bone1Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Bone1Name_MetaData), NewProp_Bone1Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics::NewProp_Bone2Name = { "Bone2Name", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPhysicsConstraintInfo, Bone2Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Bone2Name_MetaData), NewProp_Bone2Name_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics::NewProp_Swing1Motion_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics::NewProp_Swing1Motion = { "Swing1Motion", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPhysicsConstraintInfo, Swing1Motion), Z_Construct_UEnum_PhysicsToolsets_EConstraintMotion, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Swing1Motion_MetaData), NewProp_Swing1Motion_MetaData) }; // 3764922626
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics::NewProp_Swing1LimitDegrees = { "Swing1LimitDegrees", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPhysicsConstraintInfo, Swing1LimitDegrees), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Swing1LimitDegrees_MetaData), NewProp_Swing1LimitDegrees_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics::NewProp_Swing2Motion_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics::NewProp_Swing2Motion = { "Swing2Motion", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPhysicsConstraintInfo, Swing2Motion), Z_Construct_UEnum_PhysicsToolsets_EConstraintMotion, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Swing2Motion_MetaData), NewProp_Swing2Motion_MetaData) }; // 3764922626
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics::NewProp_Swing2LimitDegrees = { "Swing2LimitDegrees", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPhysicsConstraintInfo, Swing2LimitDegrees), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Swing2LimitDegrees_MetaData), NewProp_Swing2LimitDegrees_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics::NewProp_TwistMotion_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics::NewProp_TwistMotion = { "TwistMotion", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPhysicsConstraintInfo, TwistMotion), Z_Construct_UEnum_PhysicsToolsets_EConstraintMotion, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TwistMotion_MetaData), NewProp_TwistMotion_MetaData) }; // 3764922626
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics::NewProp_TwistLimitDegrees = { "TwistLimitDegrees", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPhysicsConstraintInfo, TwistLimitDegrees), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TwistLimitDegrees_MetaData), NewProp_TwistLimitDegrees_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics::NewProp_Bone1Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics::NewProp_Bone2Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics::NewProp_Swing1Motion_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics::NewProp_Swing1Motion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics::NewProp_Swing1LimitDegrees,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics::NewProp_Swing2Motion_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics::NewProp_Swing2Motion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics::NewProp_Swing2LimitDegrees,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics::NewProp_TwistMotion_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics::NewProp_TwistMotion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics::NewProp_TwistLimitDegrees,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FPhysicsConstraintInfo Property Definitions *************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_PhysicsToolsets,
	nullptr,
	&NewStructOps,
	"PhysicsConstraintInfo",
	Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics::PropPointers),
	sizeof(FPhysicsConstraintInfo),
	alignof(FPhysicsConstraintInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FPhysicsConstraintInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FPhysicsConstraintInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FPhysicsConstraintInfo.InnerSingleton, Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FPhysicsConstraintInfo.InnerSingleton);
}
// ********** End ScriptStruct FPhysicsConstraintInfo **********************************************

// ********** Begin Class UPhysicsAssetToolset Function AddBody ************************************
struct Z_Construct_UFunction_UPhysicsAssetToolset_AddBody_Statics
{
	struct PhysicsAssetToolset_eventAddBody_Parms
	{
		UPhysicsAsset* PhysicsAsset;
		FString BoneName;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PhysicsAsset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Adds a new empty body for the given bone.\n\x09 * @param PhysicsAsset The physics asset to modify.\n\x09 * @param BoneName The name of the bone to add a body for.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds a new empty body for the given bone.\n@param PhysicsAsset The physics asset to modify.\n@param BoneName The name of the bone to add a body for." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoneName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddBody constinit property declarations *******************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PhysicsAsset;
	static const UECodeGen_Private::FStrPropertyParams NewProp_BoneName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddBody constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddBody Property Definitions ******************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_AddBody_Statics::NewProp_PhysicsAsset = { "PhysicsAsset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventAddBody_Parms, PhysicsAsset), Z_Construct_UClass_UPhysicsAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_AddBody_Statics::NewProp_BoneName = { "BoneName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventAddBody_Parms, BoneName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoneName_MetaData), NewProp_BoneName_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPhysicsAssetToolset_AddBody_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_AddBody_Statics::NewProp_PhysicsAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_AddBody_Statics::NewProp_BoneName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_AddBody_Statics::PropPointers) < 2048);
// ********** End Function AddBody Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPhysicsAssetToolset_AddBody_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPhysicsAssetToolset, nullptr, "AddBody", 	Z_Construct_UFunction_UPhysicsAssetToolset_AddBody_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_AddBody_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_AddBody_Statics::PhysicsAssetToolset_eventAddBody_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_AddBody_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPhysicsAssetToolset_AddBody_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_AddBody_Statics::PhysicsAssetToolset_eventAddBody_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPhysicsAssetToolset_AddBody()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPhysicsAssetToolset_AddBody_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPhysicsAssetToolset::execAddBody)
{
	P_GET_OBJECT(UPhysicsAsset,Z_Param_PhysicsAsset);
	P_GET_PROPERTY(FStrProperty,Z_Param_BoneName);
	P_FINISH;
	P_NATIVE_BEGIN;
	UPhysicsAssetToolset::AddBody(Z_Param_PhysicsAsset,Z_Param_BoneName);
	P_NATIVE_END;
}
// ********** End Class UPhysicsAssetToolset Function AddBody **************************************

// ********** Begin Class UPhysicsAssetToolset Function AddConstraint ******************************
struct Z_Construct_UFunction_UPhysicsAssetToolset_AddConstraint_Statics
{
	struct PhysicsAssetToolset_eventAddConstraint_Parms
	{
		UPhysicsAsset* PhysicsAsset;
		FString Bone1Name;
		FString Bone2Name;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PhysicsAsset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Adds a new constraint between two bodies. Both bodies must already exist.\n\x09 * @param PhysicsAsset The physics asset to modify.\n\x09 * @param Bone1Name Name of the child bone.\n\x09 * @param Bone2Name Name of the parent bone.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds a new constraint between two bodies. Both bodies must already exist.\n@param PhysicsAsset The physics asset to modify.\n@param Bone1Name Name of the child bone.\n@param Bone2Name Name of the parent bone." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Bone1Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Bone2Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddConstraint constinit property declarations *************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PhysicsAsset;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Bone1Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Bone2Name;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddConstraint constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddConstraint Property Definitions ************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_AddConstraint_Statics::NewProp_PhysicsAsset = { "PhysicsAsset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventAddConstraint_Parms, PhysicsAsset), Z_Construct_UClass_UPhysicsAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_AddConstraint_Statics::NewProp_Bone1Name = { "Bone1Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventAddConstraint_Parms, Bone1Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Bone1Name_MetaData), NewProp_Bone1Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_AddConstraint_Statics::NewProp_Bone2Name = { "Bone2Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventAddConstraint_Parms, Bone2Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Bone2Name_MetaData), NewProp_Bone2Name_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPhysicsAssetToolset_AddConstraint_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_AddConstraint_Statics::NewProp_PhysicsAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_AddConstraint_Statics::NewProp_Bone1Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_AddConstraint_Statics::NewProp_Bone2Name,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_AddConstraint_Statics::PropPointers) < 2048);
// ********** End Function AddConstraint Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPhysicsAssetToolset_AddConstraint_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPhysicsAssetToolset, nullptr, "AddConstraint", 	Z_Construct_UFunction_UPhysicsAssetToolset_AddConstraint_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_AddConstraint_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_AddConstraint_Statics::PhysicsAssetToolset_eventAddConstraint_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_AddConstraint_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPhysicsAssetToolset_AddConstraint_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_AddConstraint_Statics::PhysicsAssetToolset_eventAddConstraint_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPhysicsAssetToolset_AddConstraint()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPhysicsAssetToolset_AddConstraint_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPhysicsAssetToolset::execAddConstraint)
{
	P_GET_OBJECT(UPhysicsAsset,Z_Param_PhysicsAsset);
	P_GET_PROPERTY(FStrProperty,Z_Param_Bone1Name);
	P_GET_PROPERTY(FStrProperty,Z_Param_Bone2Name);
	P_FINISH;
	P_NATIVE_BEGIN;
	UPhysicsAssetToolset::AddConstraint(Z_Param_PhysicsAsset,Z_Param_Bone1Name,Z_Param_Bone2Name);
	P_NATIVE_END;
}
// ********** End Class UPhysicsAssetToolset Function AddConstraint ********************************

// ********** Begin Class UPhysicsAssetToolset Function CreateFromMesh *****************************
struct Z_Construct_UFunction_UPhysicsAssetToolset_CreateFromMesh_Statics
{
	struct PhysicsAssetToolset_eventCreateFromMesh_Parms
	{
		FString MeshPath;
		bool bAssignToMesh;
		UPhysicsAsset* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PhysicsAsset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Creates a physics asset from a skeletal mesh, auto-generating collision bodies for\n\x09 * each bone. The asset is placed in the same folder as the mesh with the suffix\n\x09 * \"_PhysicsAsset\".\n\x09 * @param MeshPath Content-browser path to the skeletal mesh, e.g. '/Game/Characters/SKM_Hero'.\n\x09 * @param bAssignToMesh If true, assigns the new physics asset to the mesh.\n\x09 * @return The newly created physics asset.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Creates a physics asset from a skeletal mesh, auto-generating collision bodies for\neach bone. The asset is placed in the same folder as the mesh with the suffix\n\"_PhysicsAsset\".\n@param MeshPath Content-browser path to the skeletal mesh, e.g. '/Game/Characters/SKM_Hero'.\n@param bAssignToMesh If true, assigns the new physics asset to the mesh.\n@return The newly created physics asset." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MeshPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CreateFromMesh constinit property declarations ************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_MeshPath;
	static void NewProp_bAssignToMesh_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAssignToMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CreateFromMesh constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CreateFromMesh Property Definitions ***********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_CreateFromMesh_Statics::NewProp_MeshPath = { "MeshPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventCreateFromMesh_Parms, MeshPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MeshPath_MetaData), NewProp_MeshPath_MetaData) };
void Z_Construct_UFunction_UPhysicsAssetToolset_CreateFromMesh_Statics::NewProp_bAssignToMesh_SetBit(void* Obj)
{
	((PhysicsAssetToolset_eventCreateFromMesh_Parms*)Obj)->bAssignToMesh = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_CreateFromMesh_Statics::NewProp_bAssignToMesh = { "bAssignToMesh", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PhysicsAssetToolset_eventCreateFromMesh_Parms), &Z_Construct_UFunction_UPhysicsAssetToolset_CreateFromMesh_Statics::NewProp_bAssignToMesh_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_CreateFromMesh_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventCreateFromMesh_Parms, ReturnValue), Z_Construct_UClass_UPhysicsAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPhysicsAssetToolset_CreateFromMesh_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_CreateFromMesh_Statics::NewProp_MeshPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_CreateFromMesh_Statics::NewProp_bAssignToMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_CreateFromMesh_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_CreateFromMesh_Statics::PropPointers) < 2048);
// ********** End Function CreateFromMesh Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPhysicsAssetToolset_CreateFromMesh_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPhysicsAssetToolset, nullptr, "CreateFromMesh", 	Z_Construct_UFunction_UPhysicsAssetToolset_CreateFromMesh_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_CreateFromMesh_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_CreateFromMesh_Statics::PhysicsAssetToolset_eventCreateFromMesh_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_CreateFromMesh_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPhysicsAssetToolset_CreateFromMesh_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_CreateFromMesh_Statics::PhysicsAssetToolset_eventCreateFromMesh_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPhysicsAssetToolset_CreateFromMesh()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPhysicsAssetToolset_CreateFromMesh_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPhysicsAssetToolset::execCreateFromMesh)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_MeshPath);
	P_GET_UBOOL(Z_Param_bAssignToMesh);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UPhysicsAsset**)Z_Param__Result=UPhysicsAssetToolset::CreateFromMesh(Z_Param_MeshPath,Z_Param_bAssignToMesh);
	P_NATIVE_END;
}
// ********** End Class UPhysicsAssetToolset Function CreateFromMesh *******************************

// ********** Begin Class UPhysicsAssetToolset Function GetBodyMassScale ***************************
struct Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyMassScale_Statics
{
	struct PhysicsAssetToolset_eventGetBodyMassScale_Parms
	{
		UPhysicsAsset* PhysicsAsset;
		FString BoneName;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PhysicsAsset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the mass-scale multiplier for the given body.\n\x09 * @param PhysicsAsset The physics asset to query.\n\x09 * @param BoneName The name of the bone whose body to query.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the mass-scale multiplier for the given body.\n@param PhysicsAsset The physics asset to query.\n@param BoneName The name of the bone whose body to query." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoneName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetBodyMassScale constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PhysicsAsset;
	static const UECodeGen_Private::FStrPropertyParams NewProp_BoneName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetBodyMassScale constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetBodyMassScale Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyMassScale_Statics::NewProp_PhysicsAsset = { "PhysicsAsset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventGetBodyMassScale_Parms, PhysicsAsset), Z_Construct_UClass_UPhysicsAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyMassScale_Statics::NewProp_BoneName = { "BoneName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventGetBodyMassScale_Parms, BoneName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoneName_MetaData), NewProp_BoneName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyMassScale_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventGetBodyMassScale_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyMassScale_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyMassScale_Statics::NewProp_PhysicsAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyMassScale_Statics::NewProp_BoneName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyMassScale_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyMassScale_Statics::PropPointers) < 2048);
// ********** End Function GetBodyMassScale Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyMassScale_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPhysicsAssetToolset, nullptr, "GetBodyMassScale", 	Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyMassScale_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyMassScale_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyMassScale_Statics::PhysicsAssetToolset_eventGetBodyMassScale_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyMassScale_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyMassScale_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyMassScale_Statics::PhysicsAssetToolset_eventGetBodyMassScale_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyMassScale()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyMassScale_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPhysicsAssetToolset::execGetBodyMassScale)
{
	P_GET_OBJECT(UPhysicsAsset,Z_Param_PhysicsAsset);
	P_GET_PROPERTY(FStrProperty,Z_Param_BoneName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=UPhysicsAssetToolset::GetBodyMassScale(Z_Param_PhysicsAsset,Z_Param_BoneName);
	P_NATIVE_END;
}
// ********** End Class UPhysicsAssetToolset Function GetBodyMassScale *****************************

// ********** Begin Class UPhysicsAssetToolset Function GetBodyNames *******************************
struct Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyNames_Statics
{
	struct PhysicsAssetToolset_eventGetBodyNames_Parms
	{
		UPhysicsAsset* PhysicsAsset;
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PhysicsAsset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the bone name for each rigid body in a physics asset.\n\x09 * @param PhysicsAsset The physics asset to query.\n\x09 * @return A list of bone names, one per body.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the bone name for each rigid body in a physics asset.\n@param PhysicsAsset The physics asset to query.\n@return A list of bone names, one per body." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetBodyNames constinit property declarations **************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PhysicsAsset;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetBodyNames constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetBodyNames Property Definitions *************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyNames_Statics::NewProp_PhysicsAsset = { "PhysicsAsset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventGetBodyNames_Parms, PhysicsAsset), Z_Construct_UClass_UPhysicsAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyNames_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyNames_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventGetBodyNames_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyNames_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyNames_Statics::NewProp_PhysicsAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyNames_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyNames_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyNames_Statics::PropPointers) < 2048);
// ********** End Function GetBodyNames Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyNames_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPhysicsAssetToolset, nullptr, "GetBodyNames", 	Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyNames_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyNames_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyNames_Statics::PhysicsAssetToolset_eventGetBodyNames_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyNames_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyNames_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyNames_Statics::PhysicsAssetToolset_eventGetBodyNames_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyNames()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyNames_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPhysicsAssetToolset::execGetBodyNames)
{
	P_GET_OBJECT(UPhysicsAsset,Z_Param_PhysicsAsset);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=UPhysicsAssetToolset::GetBodyNames(Z_Param_PhysicsAsset);
	P_NATIVE_END;
}
// ********** End Class UPhysicsAssetToolset Function GetBodyNames *********************************

// ********** Begin Class UPhysicsAssetToolset Function GetBodyPhysicsMode *************************
struct Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyPhysicsMode_Statics
{
	struct PhysicsAssetToolset_eventGetBodyPhysicsMode_Parms
	{
		UPhysicsAsset* PhysicsAsset;
		FString BoneName;
		EBodyPhysicsMode ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PhysicsAsset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the physics simulation mode for the given body.\n\x09 * @param PhysicsAsset The physics asset to query.\n\x09 * @param BoneName The name of the bone whose body to query.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the physics simulation mode for the given body.\n@param PhysicsAsset The physics asset to query.\n@param BoneName The name of the bone whose body to query." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoneName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetBodyPhysicsMode constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PhysicsAsset;
	static const UECodeGen_Private::FStrPropertyParams NewProp_BoneName;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetBodyPhysicsMode constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetBodyPhysicsMode Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyPhysicsMode_Statics::NewProp_PhysicsAsset = { "PhysicsAsset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventGetBodyPhysicsMode_Parms, PhysicsAsset), Z_Construct_UClass_UPhysicsAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyPhysicsMode_Statics::NewProp_BoneName = { "BoneName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventGetBodyPhysicsMode_Parms, BoneName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoneName_MetaData), NewProp_BoneName_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyPhysicsMode_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyPhysicsMode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventGetBodyPhysicsMode_Parms, ReturnValue), Z_Construct_UEnum_PhysicsToolsets_EBodyPhysicsMode, METADATA_PARAMS(0, nullptr) }; // 2074038648
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyPhysicsMode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyPhysicsMode_Statics::NewProp_PhysicsAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyPhysicsMode_Statics::NewProp_BoneName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyPhysicsMode_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyPhysicsMode_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyPhysicsMode_Statics::PropPointers) < 2048);
// ********** End Function GetBodyPhysicsMode Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyPhysicsMode_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPhysicsAssetToolset, nullptr, "GetBodyPhysicsMode", 	Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyPhysicsMode_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyPhysicsMode_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyPhysicsMode_Statics::PhysicsAssetToolset_eventGetBodyPhysicsMode_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyPhysicsMode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyPhysicsMode_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyPhysicsMode_Statics::PhysicsAssetToolset_eventGetBodyPhysicsMode_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyPhysicsMode()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyPhysicsMode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPhysicsAssetToolset::execGetBodyPhysicsMode)
{
	P_GET_OBJECT(UPhysicsAsset,Z_Param_PhysicsAsset);
	P_GET_PROPERTY(FStrProperty,Z_Param_BoneName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EBodyPhysicsMode*)Z_Param__Result=UPhysicsAssetToolset::GetBodyPhysicsMode(Z_Param_PhysicsAsset,Z_Param_BoneName);
	P_NATIVE_END;
}
// ********** End Class UPhysicsAssetToolset Function GetBodyPhysicsMode ***************************

// ********** Begin Class UPhysicsAssetToolset Function GetBodyShapes ******************************
struct Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyShapes_Statics
{
	struct PhysicsAssetToolset_eventGetBodyShapes_Parms
	{
		UPhysicsAsset* PhysicsAsset;
		FString BoneName;
		TArray<FPhysicsShapeInfo> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PhysicsAsset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns all collision shapes assigned to a body.\n\x09 * @param PhysicsAsset The physics asset to query.\n\x09 * @param BoneName The name of the bone whose body shapes to retrieve.\n\x09 * @return A list of shape descriptors. Raises a script error if no body exists for the bone.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns all collision shapes assigned to a body.\n@param PhysicsAsset The physics asset to query.\n@param BoneName The name of the bone whose body shapes to retrieve.\n@return A list of shape descriptors. Raises a script error if no body exists for the bone." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoneName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetBodyShapes constinit property declarations *************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PhysicsAsset;
	static const UECodeGen_Private::FStrPropertyParams NewProp_BoneName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetBodyShapes constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetBodyShapes Property Definitions ************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyShapes_Statics::NewProp_PhysicsAsset = { "PhysicsAsset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventGetBodyShapes_Parms, PhysicsAsset), Z_Construct_UClass_UPhysicsAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyShapes_Statics::NewProp_BoneName = { "BoneName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventGetBodyShapes_Parms, BoneName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoneName_MetaData), NewProp_BoneName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyShapes_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FPhysicsShapeInfo, METADATA_PARAMS(0, nullptr) }; // 84720847
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyShapes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventGetBodyShapes_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 84720847
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyShapes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyShapes_Statics::NewProp_PhysicsAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyShapes_Statics::NewProp_BoneName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyShapes_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyShapes_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyShapes_Statics::PropPointers) < 2048);
// ********** End Function GetBodyShapes Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyShapes_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPhysicsAssetToolset, nullptr, "GetBodyShapes", 	Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyShapes_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyShapes_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyShapes_Statics::PhysicsAssetToolset_eventGetBodyShapes_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyShapes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyShapes_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyShapes_Statics::PhysicsAssetToolset_eventGetBodyShapes_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyShapes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyShapes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPhysicsAssetToolset::execGetBodyShapes)
{
	P_GET_OBJECT(UPhysicsAsset,Z_Param_PhysicsAsset);
	P_GET_PROPERTY(FStrProperty,Z_Param_BoneName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FPhysicsShapeInfo>*)Z_Param__Result=UPhysicsAssetToolset::GetBodyShapes(Z_Param_PhysicsAsset,Z_Param_BoneName);
	P_NATIVE_END;
}
// ********** End Class UPhysicsAssetToolset Function GetBodyShapes ********************************

// ********** Begin Class UPhysicsAssetToolset Function GetConstraints *****************************
struct Z_Construct_UFunction_UPhysicsAssetToolset_GetConstraints_Statics
{
	struct PhysicsAssetToolset_eventGetConstraints_Parms
	{
		UPhysicsAsset* PhysicsAsset;
		TArray<FPhysicsConstraintInfo> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PhysicsAsset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns all constraints in the physics asset with their current angular limits.\n\x09 * @param PhysicsAsset The physics asset to query.\n\x09 * @return A list of constraint descriptors.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns all constraints in the physics asset with their current angular limits.\n@param PhysicsAsset The physics asset to query.\n@return A list of constraint descriptors." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetConstraints constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PhysicsAsset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetConstraints constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetConstraints Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_GetConstraints_Statics::NewProp_PhysicsAsset = { "PhysicsAsset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventGetConstraints_Parms, PhysicsAsset), Z_Construct_UClass_UPhysicsAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_GetConstraints_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FPhysicsConstraintInfo, METADATA_PARAMS(0, nullptr) }; // 1539179589
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_GetConstraints_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventGetConstraints_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 1539179589
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPhysicsAssetToolset_GetConstraints_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_GetConstraints_Statics::NewProp_PhysicsAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_GetConstraints_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_GetConstraints_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_GetConstraints_Statics::PropPointers) < 2048);
// ********** End Function GetConstraints Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPhysicsAssetToolset_GetConstraints_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPhysicsAssetToolset, nullptr, "GetConstraints", 	Z_Construct_UFunction_UPhysicsAssetToolset_GetConstraints_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_GetConstraints_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_GetConstraints_Statics::PhysicsAssetToolset_eventGetConstraints_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_GetConstraints_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPhysicsAssetToolset_GetConstraints_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_GetConstraints_Statics::PhysicsAssetToolset_eventGetConstraints_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPhysicsAssetToolset_GetConstraints()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPhysicsAssetToolset_GetConstraints_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPhysicsAssetToolset::execGetConstraints)
{
	P_GET_OBJECT(UPhysicsAsset,Z_Param_PhysicsAsset);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FPhysicsConstraintInfo>*)Z_Param__Result=UPhysicsAssetToolset::GetConstraints(Z_Param_PhysicsAsset);
	P_NATIVE_END;
}
// ********** End Class UPhysicsAssetToolset Function GetConstraints *******************************

// ********** Begin Class UPhysicsAssetToolset Function RemoveBody *********************************
struct Z_Construct_UFunction_UPhysicsAssetToolset_RemoveBody_Statics
{
	struct PhysicsAssetToolset_eventRemoveBody_Parms
	{
		UPhysicsAsset* PhysicsAsset;
		FString BoneName;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PhysicsAsset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Removes the body for the given bone along with any constraints that reference it.\n\x09 * Raises a script error if PhysicsAsset is null or no body exists for BoneName.\n\x09 * @param PhysicsAsset The physics asset to modify.\n\x09 * @param BoneName The name of the bone whose body to remove.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Removes the body for the given bone along with any constraints that reference it.\nRaises a script error if PhysicsAsset is null or no body exists for BoneName.\n@param PhysicsAsset The physics asset to modify.\n@param BoneName The name of the bone whose body to remove." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoneName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RemoveBody constinit property declarations ****************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PhysicsAsset;
	static const UECodeGen_Private::FStrPropertyParams NewProp_BoneName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RemoveBody constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RemoveBody Property Definitions ***************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_RemoveBody_Statics::NewProp_PhysicsAsset = { "PhysicsAsset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventRemoveBody_Parms, PhysicsAsset), Z_Construct_UClass_UPhysicsAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_RemoveBody_Statics::NewProp_BoneName = { "BoneName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventRemoveBody_Parms, BoneName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoneName_MetaData), NewProp_BoneName_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPhysicsAssetToolset_RemoveBody_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_RemoveBody_Statics::NewProp_PhysicsAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_RemoveBody_Statics::NewProp_BoneName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_RemoveBody_Statics::PropPointers) < 2048);
// ********** End Function RemoveBody Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPhysicsAssetToolset_RemoveBody_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPhysicsAssetToolset, nullptr, "RemoveBody", 	Z_Construct_UFunction_UPhysicsAssetToolset_RemoveBody_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_RemoveBody_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_RemoveBody_Statics::PhysicsAssetToolset_eventRemoveBody_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_RemoveBody_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPhysicsAssetToolset_RemoveBody_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_RemoveBody_Statics::PhysicsAssetToolset_eventRemoveBody_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPhysicsAssetToolset_RemoveBody()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPhysicsAssetToolset_RemoveBody_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPhysicsAssetToolset::execRemoveBody)
{
	P_GET_OBJECT(UPhysicsAsset,Z_Param_PhysicsAsset);
	P_GET_PROPERTY(FStrProperty,Z_Param_BoneName);
	P_FINISH;
	P_NATIVE_BEGIN;
	UPhysicsAssetToolset::RemoveBody(Z_Param_PhysicsAsset,Z_Param_BoneName);
	P_NATIVE_END;
}
// ********** End Class UPhysicsAssetToolset Function RemoveBody ***********************************

// ********** Begin Class UPhysicsAssetToolset Function RemoveConstraint ***************************
struct Z_Construct_UFunction_UPhysicsAssetToolset_RemoveConstraint_Statics
{
	struct PhysicsAssetToolset_eventRemoveConstraint_Parms
	{
		UPhysicsAsset* PhysicsAsset;
		FString Bone1Name;
		FString Bone2Name;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PhysicsAsset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Removes the constraint between two bodies.\n\x09 * @param PhysicsAsset The physics asset to modify.\n\x09 * @param Bone1Name Name of the child bone.\n\x09 * @param Bone2Name Name of the parent bone.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Removes the constraint between two bodies.\n@param PhysicsAsset The physics asset to modify.\n@param Bone1Name Name of the child bone.\n@param Bone2Name Name of the parent bone." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Bone1Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Bone2Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RemoveConstraint constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PhysicsAsset;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Bone1Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Bone2Name;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RemoveConstraint constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RemoveConstraint Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_RemoveConstraint_Statics::NewProp_PhysicsAsset = { "PhysicsAsset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventRemoveConstraint_Parms, PhysicsAsset), Z_Construct_UClass_UPhysicsAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_RemoveConstraint_Statics::NewProp_Bone1Name = { "Bone1Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventRemoveConstraint_Parms, Bone1Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Bone1Name_MetaData), NewProp_Bone1Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_RemoveConstraint_Statics::NewProp_Bone2Name = { "Bone2Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventRemoveConstraint_Parms, Bone2Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Bone2Name_MetaData), NewProp_Bone2Name_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPhysicsAssetToolset_RemoveConstraint_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_RemoveConstraint_Statics::NewProp_PhysicsAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_RemoveConstraint_Statics::NewProp_Bone1Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_RemoveConstraint_Statics::NewProp_Bone2Name,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_RemoveConstraint_Statics::PropPointers) < 2048);
// ********** End Function RemoveConstraint Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPhysicsAssetToolset_RemoveConstraint_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPhysicsAssetToolset, nullptr, "RemoveConstraint", 	Z_Construct_UFunction_UPhysicsAssetToolset_RemoveConstraint_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_RemoveConstraint_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_RemoveConstraint_Statics::PhysicsAssetToolset_eventRemoveConstraint_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_RemoveConstraint_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPhysicsAssetToolset_RemoveConstraint_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_RemoveConstraint_Statics::PhysicsAssetToolset_eventRemoveConstraint_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPhysicsAssetToolset_RemoveConstraint()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPhysicsAssetToolset_RemoveConstraint_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPhysicsAssetToolset::execRemoveConstraint)
{
	P_GET_OBJECT(UPhysicsAsset,Z_Param_PhysicsAsset);
	P_GET_PROPERTY(FStrProperty,Z_Param_Bone1Name);
	P_GET_PROPERTY(FStrProperty,Z_Param_Bone2Name);
	P_FINISH;
	P_NATIVE_BEGIN;
	UPhysicsAssetToolset::RemoveConstraint(Z_Param_PhysicsAsset,Z_Param_Bone1Name,Z_Param_Bone2Name);
	P_NATIVE_END;
}
// ********** End Class UPhysicsAssetToolset Function RemoveConstraint *****************************

// ********** Begin Class UPhysicsAssetToolset Function RemoveShape ********************************
struct Z_Construct_UFunction_UPhysicsAssetToolset_RemoveShape_Statics
{
	struct PhysicsAssetToolset_eventRemoveShape_Parms
	{
		UPhysicsAsset* PhysicsAsset;
		FString BoneName;
		FString ShapeName;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PhysicsAsset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Removes a collision primitive from a body by name.\n\x09 * @param PhysicsAsset The physics asset to modify.\n\x09 * @param BoneName The name of the bone whose body to modify.\n\x09 * @param ShapeName The name of the shape to remove.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Removes a collision primitive from a body by name.\n@param PhysicsAsset The physics asset to modify.\n@param BoneName The name of the bone whose body to modify.\n@param ShapeName The name of the shape to remove." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoneName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShapeName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RemoveShape constinit property declarations ***************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PhysicsAsset;
	static const UECodeGen_Private::FStrPropertyParams NewProp_BoneName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ShapeName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RemoveShape constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RemoveShape Property Definitions **************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_RemoveShape_Statics::NewProp_PhysicsAsset = { "PhysicsAsset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventRemoveShape_Parms, PhysicsAsset), Z_Construct_UClass_UPhysicsAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_RemoveShape_Statics::NewProp_BoneName = { "BoneName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventRemoveShape_Parms, BoneName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoneName_MetaData), NewProp_BoneName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_RemoveShape_Statics::NewProp_ShapeName = { "ShapeName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventRemoveShape_Parms, ShapeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShapeName_MetaData), NewProp_ShapeName_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPhysicsAssetToolset_RemoveShape_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_RemoveShape_Statics::NewProp_PhysicsAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_RemoveShape_Statics::NewProp_BoneName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_RemoveShape_Statics::NewProp_ShapeName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_RemoveShape_Statics::PropPointers) < 2048);
// ********** End Function RemoveShape Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPhysicsAssetToolset_RemoveShape_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPhysicsAssetToolset, nullptr, "RemoveShape", 	Z_Construct_UFunction_UPhysicsAssetToolset_RemoveShape_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_RemoveShape_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_RemoveShape_Statics::PhysicsAssetToolset_eventRemoveShape_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_RemoveShape_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPhysicsAssetToolset_RemoveShape_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_RemoveShape_Statics::PhysicsAssetToolset_eventRemoveShape_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPhysicsAssetToolset_RemoveShape()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPhysicsAssetToolset_RemoveShape_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPhysicsAssetToolset::execRemoveShape)
{
	P_GET_OBJECT(UPhysicsAsset,Z_Param_PhysicsAsset);
	P_GET_PROPERTY(FStrProperty,Z_Param_BoneName);
	P_GET_PROPERTY(FStrProperty,Z_Param_ShapeName);
	P_FINISH;
	P_NATIVE_BEGIN;
	UPhysicsAssetToolset::RemoveShape(Z_Param_PhysicsAsset,Z_Param_BoneName,Z_Param_ShapeName);
	P_NATIVE_END;
}
// ********** End Class UPhysicsAssetToolset Function RemoveShape **********************************

// ********** Begin Class UPhysicsAssetToolset Function SetBodyMassScale ***************************
struct Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyMassScale_Statics
{
	struct PhysicsAssetToolset_eventSetBodyMassScale_Parms
	{
		UPhysicsAsset* PhysicsAsset;
		FString BoneName;
		float MassScale;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PhysicsAsset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Sets the mass-scale multiplier for the given body.\n\x09 * @param PhysicsAsset The physics asset to modify.\n\x09 * @param BoneName The name of the bone whose body to modify.\n\x09 * @param MassScale Multiplier applied to the computed mass. Must be greater than zero.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the mass-scale multiplier for the given body.\n@param PhysicsAsset The physics asset to modify.\n@param BoneName The name of the bone whose body to modify.\n@param MassScale Multiplier applied to the computed mass. Must be greater than zero." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoneName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetBodyMassScale constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PhysicsAsset;
	static const UECodeGen_Private::FStrPropertyParams NewProp_BoneName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MassScale;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetBodyMassScale constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetBodyMassScale Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyMassScale_Statics::NewProp_PhysicsAsset = { "PhysicsAsset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventSetBodyMassScale_Parms, PhysicsAsset), Z_Construct_UClass_UPhysicsAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyMassScale_Statics::NewProp_BoneName = { "BoneName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventSetBodyMassScale_Parms, BoneName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoneName_MetaData), NewProp_BoneName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyMassScale_Statics::NewProp_MassScale = { "MassScale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventSetBodyMassScale_Parms, MassScale), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyMassScale_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyMassScale_Statics::NewProp_PhysicsAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyMassScale_Statics::NewProp_BoneName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyMassScale_Statics::NewProp_MassScale,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyMassScale_Statics::PropPointers) < 2048);
// ********** End Function SetBodyMassScale Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyMassScale_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPhysicsAssetToolset, nullptr, "SetBodyMassScale", 	Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyMassScale_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyMassScale_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyMassScale_Statics::PhysicsAssetToolset_eventSetBodyMassScale_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyMassScale_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyMassScale_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyMassScale_Statics::PhysicsAssetToolset_eventSetBodyMassScale_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyMassScale()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyMassScale_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPhysicsAssetToolset::execSetBodyMassScale)
{
	P_GET_OBJECT(UPhysicsAsset,Z_Param_PhysicsAsset);
	P_GET_PROPERTY(FStrProperty,Z_Param_BoneName);
	P_GET_PROPERTY(FFloatProperty,Z_Param_MassScale);
	P_FINISH;
	P_NATIVE_BEGIN;
	UPhysicsAssetToolset::SetBodyMassScale(Z_Param_PhysicsAsset,Z_Param_BoneName,Z_Param_MassScale);
	P_NATIVE_END;
}
// ********** End Class UPhysicsAssetToolset Function SetBodyMassScale *****************************

// ********** Begin Class UPhysicsAssetToolset Function SetBodyPhysicsMode *************************
struct Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyPhysicsMode_Statics
{
	struct PhysicsAssetToolset_eventSetBodyPhysicsMode_Parms
	{
		UPhysicsAsset* PhysicsAsset;
		FString BoneName;
		EBodyPhysicsMode Mode;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PhysicsAsset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Sets the physics simulation mode for the given body.\n\x09 * @param PhysicsAsset The physics asset to modify.\n\x09 * @param BoneName The name of the bone whose body to modify.\n\x09 * @param Mode The desired simulation mode.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the physics simulation mode for the given body.\n@param PhysicsAsset The physics asset to modify.\n@param BoneName The name of the bone whose body to modify.\n@param Mode The desired simulation mode." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoneName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetBodyPhysicsMode constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PhysicsAsset;
	static const UECodeGen_Private::FStrPropertyParams NewProp_BoneName;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Mode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Mode;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetBodyPhysicsMode constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetBodyPhysicsMode Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyPhysicsMode_Statics::NewProp_PhysicsAsset = { "PhysicsAsset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventSetBodyPhysicsMode_Parms, PhysicsAsset), Z_Construct_UClass_UPhysicsAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyPhysicsMode_Statics::NewProp_BoneName = { "BoneName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventSetBodyPhysicsMode_Parms, BoneName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoneName_MetaData), NewProp_BoneName_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyPhysicsMode_Statics::NewProp_Mode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyPhysicsMode_Statics::NewProp_Mode = { "Mode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventSetBodyPhysicsMode_Parms, Mode), Z_Construct_UEnum_PhysicsToolsets_EBodyPhysicsMode, METADATA_PARAMS(0, nullptr) }; // 2074038648
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyPhysicsMode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyPhysicsMode_Statics::NewProp_PhysicsAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyPhysicsMode_Statics::NewProp_BoneName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyPhysicsMode_Statics::NewProp_Mode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyPhysicsMode_Statics::NewProp_Mode,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyPhysicsMode_Statics::PropPointers) < 2048);
// ********** End Function SetBodyPhysicsMode Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyPhysicsMode_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPhysicsAssetToolset, nullptr, "SetBodyPhysicsMode", 	Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyPhysicsMode_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyPhysicsMode_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyPhysicsMode_Statics::PhysicsAssetToolset_eventSetBodyPhysicsMode_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyPhysicsMode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyPhysicsMode_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyPhysicsMode_Statics::PhysicsAssetToolset_eventSetBodyPhysicsMode_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyPhysicsMode()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyPhysicsMode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPhysicsAssetToolset::execSetBodyPhysicsMode)
{
	P_GET_OBJECT(UPhysicsAsset,Z_Param_PhysicsAsset);
	P_GET_PROPERTY(FStrProperty,Z_Param_BoneName);
	P_GET_ENUM(EBodyPhysicsMode,Z_Param_Mode);
	P_FINISH;
	P_NATIVE_BEGIN;
	UPhysicsAssetToolset::SetBodyPhysicsMode(Z_Param_PhysicsAsset,Z_Param_BoneName,EBodyPhysicsMode(Z_Param_Mode));
	P_NATIVE_END;
}
// ********** End Class UPhysicsAssetToolset Function SetBodyPhysicsMode ***************************

// ********** Begin Class UPhysicsAssetToolset Function SetBox *************************************
struct Z_Construct_UFunction_UPhysicsAssetToolset_SetBox_Statics
{
	struct PhysicsAssetToolset_eventSetBox_Parms
	{
		UPhysicsAsset* PhysicsAsset;
		FString BoneName;
		FString ShapeName;
		FVector Center;
		FRotator Rotation;
		float ExtentX;
		float ExtentY;
		float ExtentZ;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PhysicsAsset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Adds or replaces a box collision primitive on a body.\n\x09 * If any shape with the given name already exists on the body it is removed first.\n\x09 * @param PhysicsAsset The physics asset to modify.\n\x09 * @param BoneName The name of the bone whose body to modify.\n\x09 * @param ShapeName A name that uniquely identifies this shape on the body.\n\x09 * @param Center Center of the box in bone-local space (cm).\n\x09 * @param Rotation Orientation of the box in bone-local space.\n\x09 * @param ExtentX Full extent along local X (cm). Must be greater than zero.\n\x09 * @param ExtentY Full extent along local Y (cm). Must be greater than zero.\n\x09 * @param ExtentZ Full extent along local Z (cm). Must be greater than zero.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds or replaces a box collision primitive on a body.\nIf any shape with the given name already exists on the body it is removed first.\n@param PhysicsAsset The physics asset to modify.\n@param BoneName The name of the bone whose body to modify.\n@param ShapeName A name that uniquely identifies this shape on the body.\n@param Center Center of the box in bone-local space (cm).\n@param Rotation Orientation of the box in bone-local space.\n@param ExtentX Full extent along local X (cm). Must be greater than zero.\n@param ExtentY Full extent along local Y (cm). Must be greater than zero.\n@param ExtentZ Full extent along local Z (cm). Must be greater than zero." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoneName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShapeName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Center_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetBox constinit property declarations ********************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PhysicsAsset;
	static const UECodeGen_Private::FStrPropertyParams NewProp_BoneName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ShapeName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Center;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ExtentX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ExtentY;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ExtentZ;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetBox constinit property declarations **********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetBox Property Definitions *******************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_SetBox_Statics::NewProp_PhysicsAsset = { "PhysicsAsset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventSetBox_Parms, PhysicsAsset), Z_Construct_UClass_UPhysicsAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_SetBox_Statics::NewProp_BoneName = { "BoneName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventSetBox_Parms, BoneName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoneName_MetaData), NewProp_BoneName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_SetBox_Statics::NewProp_ShapeName = { "ShapeName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventSetBox_Parms, ShapeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShapeName_MetaData), NewProp_ShapeName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_SetBox_Statics::NewProp_Center = { "Center", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventSetBox_Parms, Center), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Center_MetaData), NewProp_Center_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_SetBox_Statics::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventSetBox_Parms, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_MetaData), NewProp_Rotation_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_SetBox_Statics::NewProp_ExtentX = { "ExtentX", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventSetBox_Parms, ExtentX), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_SetBox_Statics::NewProp_ExtentY = { "ExtentY", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventSetBox_Parms, ExtentY), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_SetBox_Statics::NewProp_ExtentZ = { "ExtentZ", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventSetBox_Parms, ExtentZ), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPhysicsAssetToolset_SetBox_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_SetBox_Statics::NewProp_PhysicsAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_SetBox_Statics::NewProp_BoneName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_SetBox_Statics::NewProp_ShapeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_SetBox_Statics::NewProp_Center,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_SetBox_Statics::NewProp_Rotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_SetBox_Statics::NewProp_ExtentX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_SetBox_Statics::NewProp_ExtentY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_SetBox_Statics::NewProp_ExtentZ,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_SetBox_Statics::PropPointers) < 2048);
// ********** End Function SetBox Property Definitions *********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPhysicsAssetToolset_SetBox_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPhysicsAssetToolset, nullptr, "SetBox", 	Z_Construct_UFunction_UPhysicsAssetToolset_SetBox_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_SetBox_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_SetBox_Statics::PhysicsAssetToolset_eventSetBox_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_SetBox_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPhysicsAssetToolset_SetBox_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_SetBox_Statics::PhysicsAssetToolset_eventSetBox_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPhysicsAssetToolset_SetBox()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPhysicsAssetToolset_SetBox_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPhysicsAssetToolset::execSetBox)
{
	P_GET_OBJECT(UPhysicsAsset,Z_Param_PhysicsAsset);
	P_GET_PROPERTY(FStrProperty,Z_Param_BoneName);
	P_GET_PROPERTY(FStrProperty,Z_Param_ShapeName);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Center);
	P_GET_STRUCT_REF(FRotator,Z_Param_Out_Rotation);
	P_GET_PROPERTY(FFloatProperty,Z_Param_ExtentX);
	P_GET_PROPERTY(FFloatProperty,Z_Param_ExtentY);
	P_GET_PROPERTY(FFloatProperty,Z_Param_ExtentZ);
	P_FINISH;
	P_NATIVE_BEGIN;
	UPhysicsAssetToolset::SetBox(Z_Param_PhysicsAsset,Z_Param_BoneName,Z_Param_ShapeName,Z_Param_Out_Center,Z_Param_Out_Rotation,Z_Param_ExtentX,Z_Param_ExtentY,Z_Param_ExtentZ);
	P_NATIVE_END;
}
// ********** End Class UPhysicsAssetToolset Function SetBox ***************************************

// ********** Begin Class UPhysicsAssetToolset Function SetCapsule *********************************
struct Z_Construct_UFunction_UPhysicsAssetToolset_SetCapsule_Statics
{
	struct PhysicsAssetToolset_eventSetCapsule_Parms
	{
		UPhysicsAsset* PhysicsAsset;
		FString BoneName;
		FString ShapeName;
		FVector Center;
		FRotator Rotation;
		float Radius;
		float Length;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PhysicsAsset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Adds or replaces a capsule collision primitive on a body.\n\x09 * If any shape with the given name already exists on the body it is removed first.\n\x09 * The capsule's long axis is its local Z after applying Rotation.\n\x09 * @param PhysicsAsset The physics asset to modify.\n\x09 * @param BoneName The name of the bone whose body to modify.\n\x09 * @param ShapeName A name that uniquely identifies this shape on the body.\n\x09 * @param Center Center of the capsule in bone-local space (cm).\n\x09 * @param Rotation Orientation of the capsule in bone-local space.\n\x09 * @param Radius Radius of the capsule end-caps (cm). Must be greater than zero.\n\x09 * @param Length Length of the cylindrical section (cm). Must be non-negative.\n\x09 *   Total capsule height = Length + 2 * Radius.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds or replaces a capsule collision primitive on a body.\nIf any shape with the given name already exists on the body it is removed first.\nThe capsule's long axis is its local Z after applying Rotation.\n@param PhysicsAsset The physics asset to modify.\n@param BoneName The name of the bone whose body to modify.\n@param ShapeName A name that uniquely identifies this shape on the body.\n@param Center Center of the capsule in bone-local space (cm).\n@param Rotation Orientation of the capsule in bone-local space.\n@param Radius Radius of the capsule end-caps (cm). Must be greater than zero.\n@param Length Length of the cylindrical section (cm). Must be non-negative.\n  Total capsule height = Length + 2 * Radius." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoneName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShapeName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Center_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetCapsule constinit property declarations ****************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PhysicsAsset;
	static const UECodeGen_Private::FStrPropertyParams NewProp_BoneName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ShapeName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Center;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Radius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Length;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetCapsule constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetCapsule Property Definitions ***************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_SetCapsule_Statics::NewProp_PhysicsAsset = { "PhysicsAsset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventSetCapsule_Parms, PhysicsAsset), Z_Construct_UClass_UPhysicsAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_SetCapsule_Statics::NewProp_BoneName = { "BoneName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventSetCapsule_Parms, BoneName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoneName_MetaData), NewProp_BoneName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_SetCapsule_Statics::NewProp_ShapeName = { "ShapeName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventSetCapsule_Parms, ShapeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShapeName_MetaData), NewProp_ShapeName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_SetCapsule_Statics::NewProp_Center = { "Center", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventSetCapsule_Parms, Center), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Center_MetaData), NewProp_Center_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_SetCapsule_Statics::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventSetCapsule_Parms, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_MetaData), NewProp_Rotation_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_SetCapsule_Statics::NewProp_Radius = { "Radius", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventSetCapsule_Parms, Radius), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_SetCapsule_Statics::NewProp_Length = { "Length", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventSetCapsule_Parms, Length), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPhysicsAssetToolset_SetCapsule_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_SetCapsule_Statics::NewProp_PhysicsAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_SetCapsule_Statics::NewProp_BoneName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_SetCapsule_Statics::NewProp_ShapeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_SetCapsule_Statics::NewProp_Center,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_SetCapsule_Statics::NewProp_Rotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_SetCapsule_Statics::NewProp_Radius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_SetCapsule_Statics::NewProp_Length,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_SetCapsule_Statics::PropPointers) < 2048);
// ********** End Function SetCapsule Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPhysicsAssetToolset_SetCapsule_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPhysicsAssetToolset, nullptr, "SetCapsule", 	Z_Construct_UFunction_UPhysicsAssetToolset_SetCapsule_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_SetCapsule_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_SetCapsule_Statics::PhysicsAssetToolset_eventSetCapsule_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_SetCapsule_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPhysicsAssetToolset_SetCapsule_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_SetCapsule_Statics::PhysicsAssetToolset_eventSetCapsule_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPhysicsAssetToolset_SetCapsule()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPhysicsAssetToolset_SetCapsule_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPhysicsAssetToolset::execSetCapsule)
{
	P_GET_OBJECT(UPhysicsAsset,Z_Param_PhysicsAsset);
	P_GET_PROPERTY(FStrProperty,Z_Param_BoneName);
	P_GET_PROPERTY(FStrProperty,Z_Param_ShapeName);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Center);
	P_GET_STRUCT_REF(FRotator,Z_Param_Out_Rotation);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Radius);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Length);
	P_FINISH;
	P_NATIVE_BEGIN;
	UPhysicsAssetToolset::SetCapsule(Z_Param_PhysicsAsset,Z_Param_BoneName,Z_Param_ShapeName,Z_Param_Out_Center,Z_Param_Out_Rotation,Z_Param_Radius,Z_Param_Length);
	P_NATIVE_END;
}
// ********** End Class UPhysicsAssetToolset Function SetCapsule ***********************************

// ********** Begin Class UPhysicsAssetToolset Function SetConstraintLimits ************************
struct Z_Construct_UFunction_UPhysicsAssetToolset_SetConstraintLimits_Statics
{
	struct PhysicsAssetToolset_eventSetConstraintLimits_Parms
	{
		UPhysicsAsset* PhysicsAsset;
		FPhysicsConstraintInfo Info;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PhysicsAsset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Updates the angular limits for an existing constraint.\n\x09 * @param PhysicsAsset The physics asset to modify.\n\x09 * @param Info Constraint descriptor. Bone1Name and Bone2Name identify the constraint.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Updates the angular limits for an existing constraint.\n@param PhysicsAsset The physics asset to modify.\n@param Info Constraint descriptor. Bone1Name and Bone2Name identify the constraint." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetConstraintLimits constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PhysicsAsset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Info;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetConstraintLimits constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetConstraintLimits Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_SetConstraintLimits_Statics::NewProp_PhysicsAsset = { "PhysicsAsset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventSetConstraintLimits_Parms, PhysicsAsset), Z_Construct_UClass_UPhysicsAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_SetConstraintLimits_Statics::NewProp_Info = { "Info", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventSetConstraintLimits_Parms, Info), Z_Construct_UScriptStruct_FPhysicsConstraintInfo, METADATA_PARAMS(0, nullptr) }; // 1539179589
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPhysicsAssetToolset_SetConstraintLimits_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_SetConstraintLimits_Statics::NewProp_PhysicsAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_SetConstraintLimits_Statics::NewProp_Info,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_SetConstraintLimits_Statics::PropPointers) < 2048);
// ********** End Function SetConstraintLimits Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPhysicsAssetToolset_SetConstraintLimits_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPhysicsAssetToolset, nullptr, "SetConstraintLimits", 	Z_Construct_UFunction_UPhysicsAssetToolset_SetConstraintLimits_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_SetConstraintLimits_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_SetConstraintLimits_Statics::PhysicsAssetToolset_eventSetConstraintLimits_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_SetConstraintLimits_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPhysicsAssetToolset_SetConstraintLimits_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_SetConstraintLimits_Statics::PhysicsAssetToolset_eventSetConstraintLimits_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPhysicsAssetToolset_SetConstraintLimits()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPhysicsAssetToolset_SetConstraintLimits_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPhysicsAssetToolset::execSetConstraintLimits)
{
	P_GET_OBJECT(UPhysicsAsset,Z_Param_PhysicsAsset);
	P_GET_STRUCT(FPhysicsConstraintInfo,Z_Param_Info);
	P_FINISH;
	P_NATIVE_BEGIN;
	UPhysicsAssetToolset::SetConstraintLimits(Z_Param_PhysicsAsset,Z_Param_Info);
	P_NATIVE_END;
}
// ********** End Class UPhysicsAssetToolset Function SetConstraintLimits **************************

// ********** Begin Class UPhysicsAssetToolset Function SetSphere **********************************
struct Z_Construct_UFunction_UPhysicsAssetToolset_SetSphere_Statics
{
	struct PhysicsAssetToolset_eventSetSphere_Parms
	{
		UPhysicsAsset* PhysicsAsset;
		FString BoneName;
		FString ShapeName;
		FVector Center;
		float Radius;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PhysicsAsset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Adds or replaces a sphere collision primitive on a body.\n\x09 * If any shape with the given name already exists on the body it is removed first.\n\x09 * @param PhysicsAsset The physics asset to modify.\n\x09 * @param BoneName The name of the bone whose body to modify.\n\x09 * @param ShapeName A name that uniquely identifies this shape on the body.\n\x09 * @param Center Center of the sphere in bone-local space (cm).\n\x09 * @param Radius Radius of the sphere (cm). Must be greater than zero.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds or replaces a sphere collision primitive on a body.\nIf any shape with the given name already exists on the body it is removed first.\n@param PhysicsAsset The physics asset to modify.\n@param BoneName The name of the bone whose body to modify.\n@param ShapeName A name that uniquely identifies this shape on the body.\n@param Center Center of the sphere in bone-local space (cm).\n@param Radius Radius of the sphere (cm). Must be greater than zero." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoneName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShapeName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Center_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetSphere constinit property declarations *****************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PhysicsAsset;
	static const UECodeGen_Private::FStrPropertyParams NewProp_BoneName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ShapeName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Center;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Radius;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSphere constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSphere Property Definitions ****************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_SetSphere_Statics::NewProp_PhysicsAsset = { "PhysicsAsset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventSetSphere_Parms, PhysicsAsset), Z_Construct_UClass_UPhysicsAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_SetSphere_Statics::NewProp_BoneName = { "BoneName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventSetSphere_Parms, BoneName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoneName_MetaData), NewProp_BoneName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_SetSphere_Statics::NewProp_ShapeName = { "ShapeName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventSetSphere_Parms, ShapeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShapeName_MetaData), NewProp_ShapeName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_SetSphere_Statics::NewProp_Center = { "Center", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventSetSphere_Parms, Center), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Center_MetaData), NewProp_Center_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPhysicsAssetToolset_SetSphere_Statics::NewProp_Radius = { "Radius", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PhysicsAssetToolset_eventSetSphere_Parms, Radius), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPhysicsAssetToolset_SetSphere_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_SetSphere_Statics::NewProp_PhysicsAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_SetSphere_Statics::NewProp_BoneName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_SetSphere_Statics::NewProp_ShapeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_SetSphere_Statics::NewProp_Center,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPhysicsAssetToolset_SetSphere_Statics::NewProp_Radius,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_SetSphere_Statics::PropPointers) < 2048);
// ********** End Function SetSphere Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPhysicsAssetToolset_SetSphere_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPhysicsAssetToolset, nullptr, "SetSphere", 	Z_Construct_UFunction_UPhysicsAssetToolset_SetSphere_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_SetSphere_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_SetSphere_Statics::PhysicsAssetToolset_eventSetSphere_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPhysicsAssetToolset_SetSphere_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPhysicsAssetToolset_SetSphere_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPhysicsAssetToolset_SetSphere_Statics::PhysicsAssetToolset_eventSetSphere_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPhysicsAssetToolset_SetSphere()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPhysicsAssetToolset_SetSphere_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPhysicsAssetToolset::execSetSphere)
{
	P_GET_OBJECT(UPhysicsAsset,Z_Param_PhysicsAsset);
	P_GET_PROPERTY(FStrProperty,Z_Param_BoneName);
	P_GET_PROPERTY(FStrProperty,Z_Param_ShapeName);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Center);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Radius);
	P_FINISH;
	P_NATIVE_BEGIN;
	UPhysicsAssetToolset::SetSphere(Z_Param_PhysicsAsset,Z_Param_BoneName,Z_Param_ShapeName,Z_Param_Out_Center,Z_Param_Radius);
	P_NATIVE_END;
}
// ********** End Class UPhysicsAssetToolset Function SetSphere ************************************

// ********** Begin Class UPhysicsAssetToolset *****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UPhysicsAssetToolset;
UClass* UPhysicsAssetToolset::GetPrivateStaticClass()
{
	using TClass = UPhysicsAssetToolset;
	if (!Z_Registration_Info_UClass_UPhysicsAssetToolset.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("PhysicsAssetToolset"),
			Z_Registration_Info_UClass_UPhysicsAssetToolset.InnerSingleton,
			StaticRegisterNativesUPhysicsAssetToolset,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UPhysicsAssetToolset.InnerSingleton;
}
UClass* Z_Construct_UClass_UPhysicsAssetToolset_NoRegister()
{
	return UPhysicsAssetToolset::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPhysicsAssetToolset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Provides tools for creating and managing Physics Assets. */" },
#endif
		{ "IncludePath", "PhysicsToolsets/PhysicsAssetToolset.h" },
		{ "ModuleRelativePath", "Private/PhysicsToolsets/PhysicsAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Provides tools for creating and managing Physics Assets." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UPhysicsAssetToolset constinit property declarations *********************
// ********** End Class UPhysicsAssetToolset constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AddBody"), .Pointer = &UPhysicsAssetToolset::execAddBody },
		{ .NameUTF8 = UTF8TEXT("AddConstraint"), .Pointer = &UPhysicsAssetToolset::execAddConstraint },
		{ .NameUTF8 = UTF8TEXT("CreateFromMesh"), .Pointer = &UPhysicsAssetToolset::execCreateFromMesh },
		{ .NameUTF8 = UTF8TEXT("GetBodyMassScale"), .Pointer = &UPhysicsAssetToolset::execGetBodyMassScale },
		{ .NameUTF8 = UTF8TEXT("GetBodyNames"), .Pointer = &UPhysicsAssetToolset::execGetBodyNames },
		{ .NameUTF8 = UTF8TEXT("GetBodyPhysicsMode"), .Pointer = &UPhysicsAssetToolset::execGetBodyPhysicsMode },
		{ .NameUTF8 = UTF8TEXT("GetBodyShapes"), .Pointer = &UPhysicsAssetToolset::execGetBodyShapes },
		{ .NameUTF8 = UTF8TEXT("GetConstraints"), .Pointer = &UPhysicsAssetToolset::execGetConstraints },
		{ .NameUTF8 = UTF8TEXT("RemoveBody"), .Pointer = &UPhysicsAssetToolset::execRemoveBody },
		{ .NameUTF8 = UTF8TEXT("RemoveConstraint"), .Pointer = &UPhysicsAssetToolset::execRemoveConstraint },
		{ .NameUTF8 = UTF8TEXT("RemoveShape"), .Pointer = &UPhysicsAssetToolset::execRemoveShape },
		{ .NameUTF8 = UTF8TEXT("SetBodyMassScale"), .Pointer = &UPhysicsAssetToolset::execSetBodyMassScale },
		{ .NameUTF8 = UTF8TEXT("SetBodyPhysicsMode"), .Pointer = &UPhysicsAssetToolset::execSetBodyPhysicsMode },
		{ .NameUTF8 = UTF8TEXT("SetBox"), .Pointer = &UPhysicsAssetToolset::execSetBox },
		{ .NameUTF8 = UTF8TEXT("SetCapsule"), .Pointer = &UPhysicsAssetToolset::execSetCapsule },
		{ .NameUTF8 = UTF8TEXT("SetConstraintLimits"), .Pointer = &UPhysicsAssetToolset::execSetConstraintLimits },
		{ .NameUTF8 = UTF8TEXT("SetSphere"), .Pointer = &UPhysicsAssetToolset::execSetSphere },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UPhysicsAssetToolset_AddBody, "AddBody" }, // 3373854135
		{ &Z_Construct_UFunction_UPhysicsAssetToolset_AddConstraint, "AddConstraint" }, // 2945393838
		{ &Z_Construct_UFunction_UPhysicsAssetToolset_CreateFromMesh, "CreateFromMesh" }, // 2021149191
		{ &Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyMassScale, "GetBodyMassScale" }, // 1990719216
		{ &Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyNames, "GetBodyNames" }, // 637195981
		{ &Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyPhysicsMode, "GetBodyPhysicsMode" }, // 3075235808
		{ &Z_Construct_UFunction_UPhysicsAssetToolset_GetBodyShapes, "GetBodyShapes" }, // 3422901294
		{ &Z_Construct_UFunction_UPhysicsAssetToolset_GetConstraints, "GetConstraints" }, // 3144189213
		{ &Z_Construct_UFunction_UPhysicsAssetToolset_RemoveBody, "RemoveBody" }, // 238576899
		{ &Z_Construct_UFunction_UPhysicsAssetToolset_RemoveConstraint, "RemoveConstraint" }, // 355076077
		{ &Z_Construct_UFunction_UPhysicsAssetToolset_RemoveShape, "RemoveShape" }, // 3868505422
		{ &Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyMassScale, "SetBodyMassScale" }, // 774020886
		{ &Z_Construct_UFunction_UPhysicsAssetToolset_SetBodyPhysicsMode, "SetBodyPhysicsMode" }, // 2845315093
		{ &Z_Construct_UFunction_UPhysicsAssetToolset_SetBox, "SetBox" }, // 618744530
		{ &Z_Construct_UFunction_UPhysicsAssetToolset_SetCapsule, "SetCapsule" }, // 3008326874
		{ &Z_Construct_UFunction_UPhysicsAssetToolset_SetConstraintLimits, "SetConstraintLimits" }, // 1068006367
		{ &Z_Construct_UFunction_UPhysicsAssetToolset_SetSphere, "SetSphere" }, // 3563684817
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPhysicsAssetToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UPhysicsAssetToolset_Statics
UObject* (*const Z_Construct_UClass_UPhysicsAssetToolset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UToolsetDefinition,
	(UObject* (*)())Z_Construct_UPackage__Script_PhysicsToolsets,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPhysicsAssetToolset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPhysicsAssetToolset_Statics::ClassParams = {
	&UPhysicsAssetToolset::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x000800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPhysicsAssetToolset_Statics::Class_MetaDataParams), Z_Construct_UClass_UPhysicsAssetToolset_Statics::Class_MetaDataParams)
};
void UPhysicsAssetToolset::StaticRegisterNativesUPhysicsAssetToolset()
{
	UClass* Class = UPhysicsAssetToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UPhysicsAssetToolset_Statics::Funcs));
}
UClass* Z_Construct_UClass_UPhysicsAssetToolset()
{
	if (!Z_Registration_Info_UClass_UPhysicsAssetToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPhysicsAssetToolset.OuterSingleton, Z_Construct_UClass_UPhysicsAssetToolset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPhysicsAssetToolset.OuterSingleton;
}
UPhysicsAssetToolset::UPhysicsAssetToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UPhysicsAssetToolset);
UPhysicsAssetToolset::~UPhysicsAssetToolset() {}
// ********** End Class UPhysicsAssetToolset *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PhysicsToolsets_Source_PhysicsToolsets_Private_PhysicsToolsets_PhysicsAssetToolset_h__Script_PhysicsToolsets_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EPhysicsShapeType_StaticEnum, TEXT("EPhysicsShapeType"), &Z_Registration_Info_UEnum_EPhysicsShapeType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2939295466U) },
		{ EBodyPhysicsMode_StaticEnum, TEXT("EBodyPhysicsMode"), &Z_Registration_Info_UEnum_EBodyPhysicsMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2074038648U) },
		{ EConstraintMotion_StaticEnum, TEXT("EConstraintMotion"), &Z_Registration_Info_UEnum_EConstraintMotion, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3764922626U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FPhysicsShapeInfo::StaticStruct, Z_Construct_UScriptStruct_FPhysicsShapeInfo_Statics::NewStructOps, TEXT("PhysicsShapeInfo"),&Z_Registration_Info_UScriptStruct_FPhysicsShapeInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPhysicsShapeInfo), 84720847U) },
		{ FPhysicsConstraintInfo::StaticStruct, Z_Construct_UScriptStruct_FPhysicsConstraintInfo_Statics::NewStructOps, TEXT("PhysicsConstraintInfo"),&Z_Registration_Info_UScriptStruct_FPhysicsConstraintInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPhysicsConstraintInfo), 1539179589U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPhysicsAssetToolset, UPhysicsAssetToolset::StaticClass, TEXT("UPhysicsAssetToolset"), &Z_Registration_Info_UClass_UPhysicsAssetToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPhysicsAssetToolset), 2875424667U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PhysicsToolsets_Source_PhysicsToolsets_Private_PhysicsToolsets_PhysicsAssetToolset_h__Script_PhysicsToolsets_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PhysicsToolsets_Source_PhysicsToolsets_Private_PhysicsToolsets_PhysicsAssetToolset_h__Script_PhysicsToolsets_194601438{
	TEXT("/Script/PhysicsToolsets"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PhysicsToolsets_Source_PhysicsToolsets_Private_PhysicsToolsets_PhysicsAssetToolset_h__Script_PhysicsToolsets_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PhysicsToolsets_Source_PhysicsToolsets_Private_PhysicsToolsets_PhysicsAssetToolset_h__Script_PhysicsToolsets_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PhysicsToolsets_Source_PhysicsToolsets_Private_PhysicsToolsets_PhysicsAssetToolset_h__Script_PhysicsToolsets_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PhysicsToolsets_Source_PhysicsToolsets_Private_PhysicsToolsets_PhysicsAssetToolset_h__Script_PhysicsToolsets_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PhysicsToolsets_Source_PhysicsToolsets_Private_PhysicsToolsets_PhysicsAssetToolset_h__Script_PhysicsToolsets_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PhysicsToolsets_Source_PhysicsToolsets_Private_PhysicsToolsets_PhysicsAssetToolset_h__Script_PhysicsToolsets_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
