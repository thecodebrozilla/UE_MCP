// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ToolsetRegistry/ToolsetLibrary.h"
#include "UObject/Class.h"
#include "UObject/SoftObjectPath.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeToolsetLibrary() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UScriptStruct_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UStruct_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FSoftClassPath();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetLibrary();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetLibrary_NoRegister();
TOOLSETREGISTRY_API UEnum* Z_Construct_UEnum_ToolsetRegistry_EBypassContainerCheck();
UPackage* Z_Construct_UPackage__Script_ToolsetRegistry();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EBypassContainerCheck *****************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EBypassContainerCheck;
static UEnum* EBypassContainerCheck_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EBypassContainerCheck.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EBypassContainerCheck.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ToolsetRegistry_EBypassContainerCheck, (UObject*)Z_Construct_UPackage__Script_ToolsetRegistry(), TEXT("EBypassContainerCheck"));
	}
	return Z_Registration_Info_UEnum_EBypassContainerCheck.OuterSingleton;
}
template<> TOOLSETREGISTRY_NON_ATTRIBUTED_API UEnum* StaticEnum<EBypassContainerCheck>()
{
	return EBypassContainerCheck_StaticEnum();
}
struct Z_Construct_UEnum_ToolsetRegistry_EBypassContainerCheck_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Selects whether SetObjectProperties performs container diff-and-recurse logic or\n/// emits a single ValueSet for the whole property. Named (rather than bool) so call\n/// sites read clearly at the point of use.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolsetLibrary.h" },
		{ "No.Comment", "/// Default. Compare incoming JSON against the live container and emit precise\n/// ArrayAdd / ArrayRemove / ArrayClear / ValueSet notifications with element indices.\n" },
		{ "No.Name", "EBypassContainerCheck::No" },
		{ "No.ToolTip", "Default. Compare incoming JSON against the live container and emit precise\nArrayAdd / ArrayRemove / ArrayClear / ValueSet notifications with element indices." },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Selects whether SetObjectProperties performs container diff-and-recurse logic or\nemits a single ValueSet for the whole property. Named (rather than bool) so call\nsites read clearly at the point of use." },
#endif
		{ "Yes.Comment", "/// Skip container diff logic and emit a single ValueSet for the property.\n/// Use when the receiving object handles a top-level ValueSet instead of per-element events.\n" },
		{ "Yes.Name", "EBypassContainerCheck::Yes" },
		{ "Yes.ToolTip", "Skip container diff logic and emit a single ValueSet for the property.\nUse when the receiving object handles a top-level ValueSet instead of per-element events." },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EBypassContainerCheck::No", (int64)EBypassContainerCheck::No },
		{ "EBypassContainerCheck::Yes", (int64)EBypassContainerCheck::Yes },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_ToolsetRegistry_EBypassContainerCheck_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ToolsetRegistry_EBypassContainerCheck_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ToolsetRegistry,
	nullptr,
	"EBypassContainerCheck",
	"EBypassContainerCheck",
	Z_Construct_UEnum_ToolsetRegistry_EBypassContainerCheck_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ToolsetRegistry_EBypassContainerCheck_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ToolsetRegistry_EBypassContainerCheck_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ToolsetRegistry_EBypassContainerCheck_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ToolsetRegistry_EBypassContainerCheck()
{
	if (!Z_Registration_Info_UEnum_EBypassContainerCheck.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EBypassContainerCheck.InnerSingleton, Z_Construct_UEnum_ToolsetRegistry_EBypassContainerCheck_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EBypassContainerCheck.InnerSingleton;
}
// ********** End Enum EBypassContainerCheck *******************************************************

// ********** Begin Class UToolsetLibrary Function GetActiveUndoCount ******************************
struct Z_Construct_UFunction_UToolsetLibrary_GetActiveUndoCount_Statics
{
	struct ToolsetLibrary_eventGetActiveUndoCount_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Toolset Library" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Returns the number of entries currently undoable on the global undo stack\n\x09 * (queue length minus undo count, i.e. entries above the redo split).\n\x09 *\n\x09 * Snapshotting this around a BeginTransaction / EndTransaction pair lets\n\x09 * a caller tell whether the pair actually committed a record: a transient\n\x09 * transaction (no UObject changes) is silently dropped by UTransBuffer::End,\n\x09 * leaving the count unchanged.\n\x09 *\n\x09 * @return The active undo count, or 0 when there is no editor transaction\n\x09 *         buffer available (e.g. no GEditor).\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolsetLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Returns the number of entries currently undoable on the global undo stack\n* (queue length minus undo count, i.e. entries above the redo split).\n*\n* Snapshotting this around a BeginTransaction / EndTransaction pair lets\n* a caller tell whether the pair actually committed a record: a transient\n* transaction (no UObject changes) is silently dropped by UTransBuffer::End,\n* leaving the count unchanged.\n*\n* @return The active undo count, or 0 when there is no editor transaction\n*         buffer available (e.g. no GEditor)." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetActiveUndoCount constinit property declarations ********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetActiveUndoCount constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetActiveUndoCount Property Definitions *******************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UToolsetLibrary_GetActiveUndoCount_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ToolsetLibrary_eventGetActiveUndoCount_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UToolsetLibrary_GetActiveUndoCount_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetLibrary_GetActiveUndoCount_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetLibrary_GetActiveUndoCount_Statics::PropPointers) < 2048);
// ********** End Function GetActiveUndoCount Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UToolsetLibrary_GetActiveUndoCount_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UToolsetLibrary, nullptr, "GetActiveUndoCount", 	Z_Construct_UFunction_UToolsetLibrary_GetActiveUndoCount_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetLibrary_GetActiveUndoCount_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UToolsetLibrary_GetActiveUndoCount_Statics::ToolsetLibrary_eventGetActiveUndoCount_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetLibrary_GetActiveUndoCount_Statics::Function_MetaDataParams), Z_Construct_UFunction_UToolsetLibrary_GetActiveUndoCount_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UToolsetLibrary_GetActiveUndoCount_Statics::ToolsetLibrary_eventGetActiveUndoCount_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UToolsetLibrary_GetActiveUndoCount()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UToolsetLibrary_GetActiveUndoCount_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UToolsetLibrary::execGetActiveUndoCount)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UToolsetLibrary::GetActiveUndoCount();
	P_NATIVE_END;
}
// ********** End Class UToolsetLibrary Function GetActiveUndoCount ********************************

// ********** Begin Class UToolsetLibrary Function GetDerivedClasses *******************************
struct Z_Construct_UFunction_UToolsetLibrary_GetDerivedClasses_Statics
{
	struct ToolsetLibrary_eventGetDerivedClasses_Parms
	{
		UClass* BaseClass;
		TArray<FSoftClassPath> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Toolset Library" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Returns the list of subclasses that derive from a class.\n\x09 * Uses the Asset Registry to find native and BP subclasses.\n\x09 * @param BaseClass The class to get subclasses from.\n\x09 * @return The list of native and BP classes that derive from the base class.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolsetLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Returns the list of subclasses that derive from a class.\n* Uses the Asset Registry to find native and BP subclasses.\n* @param BaseClass The class to get subclasses from.\n* @return The list of native and BP classes that derive from the base class." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetDerivedClasses constinit property declarations *********************
	static const UECodeGen_Private::FClassPropertyParams NewProp_BaseClass;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDerivedClasses constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDerivedClasses Property Definitions ********************************
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UToolsetLibrary_GetDerivedClasses_Statics::NewProp_BaseClass = { "BaseClass", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ToolsetLibrary_eventGetDerivedClasses_Parms, BaseClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UToolsetLibrary_GetDerivedClasses_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FSoftClassPath, METADATA_PARAMS(0, nullptr) }; // 3467803280
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UToolsetLibrary_GetDerivedClasses_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ToolsetLibrary_eventGetDerivedClasses_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 3467803280
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UToolsetLibrary_GetDerivedClasses_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetLibrary_GetDerivedClasses_Statics::NewProp_BaseClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetLibrary_GetDerivedClasses_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetLibrary_GetDerivedClasses_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetLibrary_GetDerivedClasses_Statics::PropPointers) < 2048);
// ********** End Function GetDerivedClasses Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UToolsetLibrary_GetDerivedClasses_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UToolsetLibrary, nullptr, "GetDerivedClasses", 	Z_Construct_UFunction_UToolsetLibrary_GetDerivedClasses_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetLibrary_GetDerivedClasses_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UToolsetLibrary_GetDerivedClasses_Statics::ToolsetLibrary_eventGetDerivedClasses_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetLibrary_GetDerivedClasses_Statics::Function_MetaDataParams), Z_Construct_UFunction_UToolsetLibrary_GetDerivedClasses_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UToolsetLibrary_GetDerivedClasses_Statics::ToolsetLibrary_eventGetDerivedClasses_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UToolsetLibrary_GetDerivedClasses()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UToolsetLibrary_GetDerivedClasses_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UToolsetLibrary::execGetDerivedClasses)
{
	P_GET_OBJECT(UClass,Z_Param_BaseClass);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FSoftClassPath>*)Z_Param__Result=UToolsetLibrary::GetDerivedClasses(Z_Param_BaseClass);
	P_NATIVE_END;
}
// ********** End Class UToolsetLibrary Function GetDerivedClasses *********************************

// ********** Begin Class UToolsetLibrary Function GetDerivedStructs *******************************
struct Z_Construct_UFunction_UToolsetLibrary_GetDerivedStructs_Statics
{
	struct ToolsetLibrary_eventGetDerivedStructs_Parms
	{
		UScriptStruct* BaseStruct;
		TArray<UScriptStruct*> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Toolset Library" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Returns the list of substructs that derive from a struct.\n\x09 * Iterates all loaded UScriptStruct objects to find matching substructs.\n\x09 * @param BaseStruct The struct to get substructs from.\n\x09 * @return The list of loaded structs that derive from the base struct.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolsetLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Returns the list of substructs that derive from a struct.\n* Iterates all loaded UScriptStruct objects to find matching substructs.\n* @param BaseStruct The struct to get substructs from.\n* @return The list of loaded structs that derive from the base struct." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetDerivedStructs constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BaseStruct;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDerivedStructs constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDerivedStructs Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UToolsetLibrary_GetDerivedStructs_Statics::NewProp_BaseStruct = { "BaseStruct", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ToolsetLibrary_eventGetDerivedStructs_Parms, BaseStruct), Z_Construct_UClass_UScriptStruct_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UToolsetLibrary_GetDerivedStructs_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UScriptStruct_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UToolsetLibrary_GetDerivedStructs_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ToolsetLibrary_eventGetDerivedStructs_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UToolsetLibrary_GetDerivedStructs_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetLibrary_GetDerivedStructs_Statics::NewProp_BaseStruct,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetLibrary_GetDerivedStructs_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetLibrary_GetDerivedStructs_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetLibrary_GetDerivedStructs_Statics::PropPointers) < 2048);
// ********** End Function GetDerivedStructs Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UToolsetLibrary_GetDerivedStructs_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UToolsetLibrary, nullptr, "GetDerivedStructs", 	Z_Construct_UFunction_UToolsetLibrary_GetDerivedStructs_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetLibrary_GetDerivedStructs_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UToolsetLibrary_GetDerivedStructs_Statics::ToolsetLibrary_eventGetDerivedStructs_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetLibrary_GetDerivedStructs_Statics::Function_MetaDataParams), Z_Construct_UFunction_UToolsetLibrary_GetDerivedStructs_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UToolsetLibrary_GetDerivedStructs_Statics::ToolsetLibrary_eventGetDerivedStructs_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UToolsetLibrary_GetDerivedStructs()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UToolsetLibrary_GetDerivedStructs_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UToolsetLibrary::execGetDerivedStructs)
{
	P_GET_OBJECT(UScriptStruct,Z_Param_BaseStruct);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<UScriptStruct*>*)Z_Param__Result=UToolsetLibrary::GetDerivedStructs(Z_Param_BaseStruct);
	P_NATIVE_END;
}
// ********** End Class UToolsetLibrary Function GetDerivedStructs *********************************

// ********** Begin Class UToolsetLibrary Function GetObjectProperties *****************************
struct Z_Construct_UFunction_UToolsetLibrary_GetObjectProperties_Statics
{
	struct ToolsetLibrary_eventGetObjectProperties_Parms
	{
		const UObject* Object;
		TArray<FName> PropertyNames;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Toolset Library" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Returns the values of the requested properties.\n\x09 * @param Object The object from which to extract properties.\n\x09 * @param PropertyNames The names of the properties to extract.\n\x09 * @return A JSON formatted string that contains the values of the requested properties.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolsetLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Returns the values of the requested properties.\n* @param Object The object from which to extract properties.\n* @param PropertyNames The names of the properties to extract.\n* @return A JSON formatted string that contains the values of the requested properties." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Object_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropertyNames_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetObjectProperties constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Object;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PropertyNames_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_PropertyNames;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetObjectProperties constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetObjectProperties Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UToolsetLibrary_GetObjectProperties_Statics::NewProp_Object = { "Object", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ToolsetLibrary_eventGetObjectProperties_Parms, Object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Object_MetaData), NewProp_Object_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UToolsetLibrary_GetObjectProperties_Statics::NewProp_PropertyNames_Inner = { "PropertyNames", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UToolsetLibrary_GetObjectProperties_Statics::NewProp_PropertyNames = { "PropertyNames", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ToolsetLibrary_eventGetObjectProperties_Parms, PropertyNames), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropertyNames_MetaData), NewProp_PropertyNames_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UToolsetLibrary_GetObjectProperties_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ToolsetLibrary_eventGetObjectProperties_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UToolsetLibrary_GetObjectProperties_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetLibrary_GetObjectProperties_Statics::NewProp_Object,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetLibrary_GetObjectProperties_Statics::NewProp_PropertyNames_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetLibrary_GetObjectProperties_Statics::NewProp_PropertyNames,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetLibrary_GetObjectProperties_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetLibrary_GetObjectProperties_Statics::PropPointers) < 2048);
// ********** End Function GetObjectProperties Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UToolsetLibrary_GetObjectProperties_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UToolsetLibrary, nullptr, "GetObjectProperties", 	Z_Construct_UFunction_UToolsetLibrary_GetObjectProperties_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetLibrary_GetObjectProperties_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UToolsetLibrary_GetObjectProperties_Statics::ToolsetLibrary_eventGetObjectProperties_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetLibrary_GetObjectProperties_Statics::Function_MetaDataParams), Z_Construct_UFunction_UToolsetLibrary_GetObjectProperties_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UToolsetLibrary_GetObjectProperties_Statics::ToolsetLibrary_eventGetObjectProperties_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UToolsetLibrary_GetObjectProperties()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UToolsetLibrary_GetObjectProperties_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UToolsetLibrary::execGetObjectProperties)
{
	P_GET_OBJECT(UObject,Z_Param_Object);
	P_GET_TARRAY_REF(FName,Z_Param_Out_PropertyNames);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UToolsetLibrary::GetObjectProperties(Z_Param_Object,Z_Param_Out_PropertyNames);
	P_NATIVE_END;
}
// ********** End Class UToolsetLibrary Function GetObjectProperties *******************************

// ********** Begin Class UToolsetLibrary Function ListStructProperties ****************************
struct Z_Construct_UFunction_UToolsetLibrary_ListStructProperties_Statics
{
	struct ToolsetLibrary_eventListStructProperties_Parms
	{
		const UStruct* Struct;
		bool bUserVisiblePropertiesOnly;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Toolset Library" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Returns the properties of a struct as JSON Schema.\n\x09 * By default only returns user-visible (Blueprint-accessible) properties.\n\x09 *\n\x09 * WARNING: bUserVisiblePropertiesOnly=false bypasses all visibility filtering and returns\n\x09 * every non-deprecated property on the struct. Only use this when you know that all struct\n\x09 * properties should be exposed. For example, DataTable row structs where every field is a\n\x09 * data column regardless of its Blueprint visibility flags.\n\x09 *\n\x09 * @param Struct The struct to extract properties from.\n\x09 * @param bUserVisiblePropertiesOnly When true (default), only Blueprint-accessible properties\n\x09 *        are included. When false, all non-deprecated properties are returned.\n\x09 * @return A JSON Schema formatted string that describes the properties.\n\x09 */" },
#endif
		{ "CPP_Default_bUserVisiblePropertiesOnly", "true" },
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolsetLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Returns the properties of a struct as JSON Schema.\n* By default only returns user-visible (Blueprint-accessible) properties.\n*\n* WARNING: bUserVisiblePropertiesOnly=false bypasses all visibility filtering and returns\n* every non-deprecated property on the struct. Only use this when you know that all struct\n* properties should be exposed. For example, DataTable row structs where every field is a\n* data column regardless of its Blueprint visibility flags.\n*\n* @param Struct The struct to extract properties from.\n* @param bUserVisiblePropertiesOnly When true (default), only Blueprint-accessible properties\n*        are included. When false, all non-deprecated properties are returned.\n* @return A JSON Schema formatted string that describes the properties." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Struct_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ListStructProperties constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Struct;
	static void NewProp_bUserVisiblePropertiesOnly_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUserVisiblePropertiesOnly;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListStructProperties constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListStructProperties Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UToolsetLibrary_ListStructProperties_Statics::NewProp_Struct = { "Struct", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ToolsetLibrary_eventListStructProperties_Parms, Struct), Z_Construct_UClass_UStruct_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Struct_MetaData), NewProp_Struct_MetaData) };
void Z_Construct_UFunction_UToolsetLibrary_ListStructProperties_Statics::NewProp_bUserVisiblePropertiesOnly_SetBit(void* Obj)
{
	((ToolsetLibrary_eventListStructProperties_Parms*)Obj)->bUserVisiblePropertiesOnly = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UToolsetLibrary_ListStructProperties_Statics::NewProp_bUserVisiblePropertiesOnly = { "bUserVisiblePropertiesOnly", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ToolsetLibrary_eventListStructProperties_Parms), &Z_Construct_UFunction_UToolsetLibrary_ListStructProperties_Statics::NewProp_bUserVisiblePropertiesOnly_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UToolsetLibrary_ListStructProperties_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ToolsetLibrary_eventListStructProperties_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UToolsetLibrary_ListStructProperties_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetLibrary_ListStructProperties_Statics::NewProp_Struct,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetLibrary_ListStructProperties_Statics::NewProp_bUserVisiblePropertiesOnly,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetLibrary_ListStructProperties_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetLibrary_ListStructProperties_Statics::PropPointers) < 2048);
// ********** End Function ListStructProperties Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UToolsetLibrary_ListStructProperties_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UToolsetLibrary, nullptr, "ListStructProperties", 	Z_Construct_UFunction_UToolsetLibrary_ListStructProperties_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetLibrary_ListStructProperties_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UToolsetLibrary_ListStructProperties_Statics::ToolsetLibrary_eventListStructProperties_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetLibrary_ListStructProperties_Statics::Function_MetaDataParams), Z_Construct_UFunction_UToolsetLibrary_ListStructProperties_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UToolsetLibrary_ListStructProperties_Statics::ToolsetLibrary_eventListStructProperties_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UToolsetLibrary_ListStructProperties()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UToolsetLibrary_ListStructProperties_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UToolsetLibrary::execListStructProperties)
{
	P_GET_OBJECT(UStruct,Z_Param_Struct);
	P_GET_UBOOL(Z_Param_bUserVisiblePropertiesOnly);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UToolsetLibrary::ListStructProperties(Z_Param_Struct,Z_Param_bUserVisiblePropertiesOnly);
	P_NATIVE_END;
}
// ********** End Class UToolsetLibrary Function ListStructProperties ******************************

// ********** Begin Class UToolsetLibrary Function SetObjectProperties *****************************
struct Z_Construct_UFunction_UToolsetLibrary_SetObjectProperties_Statics
{
	struct ToolsetLibrary_eventSetObjectProperties_Parms
	{
		UObject* Object;
		FString PropertiesJson;
		EBypassContainerCheck BypassContainerCheck;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Toolset Library" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Sets the values of specific properties in an Object.\n\x09 *\n\x09 * Partial-write semantics: writes are NOT transactional. Sibling properties whose JSON\n\x09 * resolves cleanly are committed even when other properties (or other JSON keys within\n\x09 * a nested struct) fail. A false return value means at least one property could not be\n\x09 * set; it does not mean the object is unchanged. Callers that need all-or-nothing\n\x09 * semantics should wrap the call in a transaction and roll back on failure.\n\x09 *\n\x09 * Example: passing {\"name\": \"ok\", \"doesNotExist\": 0} into a struct returns false, raises\n\x09 * a script error naming \"doesNotExist\", AND leaves \"name\" set to \"ok\". Same applies to\n\x09 * unknown keys inside nested structs, which surface via the same error path.\n\x09 *\n\x09 * @param Object The object to modify.\n\x09 * @param PropertiesJson The property names and values in a JSON formatted string.\n\x09 * @param BypassContainerCheck When Yes, container-size change detection is skipped and\n\x09 *        every property emits a plain ValueSet. Only use this when you know your object\n\x09 *        can handle top-level ValueSet changes instead of expecting individual\n\x09 *        ArrayAdd/ArrayRemove/ArrayClear change events when resizing containers.\n\x09 * @return True if every property was set successfully. False indicates at least one\n\x09 *         failure; the object may already contain partial writes from sibling properties.\n\x09 */" },
#endif
		{ "CPP_Default_BypassContainerCheck", "No" },
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolsetLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Sets the values of specific properties in an Object.\n*\n* Partial-write semantics: writes are NOT transactional. Sibling properties whose JSON\n* resolves cleanly are committed even when other properties (or other JSON keys within\n* a nested struct) fail. A false return value means at least one property could not be\n* set; it does not mean the object is unchanged. Callers that need all-or-nothing\n* semantics should wrap the call in a transaction and roll back on failure.\n*\n* Example: passing {\"name\": \"ok\", \"doesNotExist\": 0} into a struct returns false, raises\n* a script error naming \"doesNotExist\", AND leaves \"name\" set to \"ok\". Same applies to\n* unknown keys inside nested structs, which surface via the same error path.\n*\n* @param Object The object to modify.\n* @param PropertiesJson The property names and values in a JSON formatted string.\n* @param BypassContainerCheck When Yes, container-size change detection is skipped and\n*        every property emits a plain ValueSet. Only use this when you know your object\n*        can handle top-level ValueSet changes instead of expecting individual\n*        ArrayAdd/ArrayRemove/ArrayClear change events when resizing containers.\n* @return True if every property was set successfully. False indicates at least one\n*         failure; the object may already contain partial writes from sibling properties." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropertiesJson_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetObjectProperties constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Object;
	static const UECodeGen_Private::FStrPropertyParams NewProp_PropertiesJson;
	static const UECodeGen_Private::FBytePropertyParams NewProp_BypassContainerCheck_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_BypassContainerCheck;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetObjectProperties constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetObjectProperties Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UToolsetLibrary_SetObjectProperties_Statics::NewProp_Object = { "Object", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ToolsetLibrary_eventSetObjectProperties_Parms, Object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UToolsetLibrary_SetObjectProperties_Statics::NewProp_PropertiesJson = { "PropertiesJson", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ToolsetLibrary_eventSetObjectProperties_Parms, PropertiesJson), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropertiesJson_MetaData), NewProp_PropertiesJson_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UToolsetLibrary_SetObjectProperties_Statics::NewProp_BypassContainerCheck_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UToolsetLibrary_SetObjectProperties_Statics::NewProp_BypassContainerCheck = { "BypassContainerCheck", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ToolsetLibrary_eventSetObjectProperties_Parms, BypassContainerCheck), Z_Construct_UEnum_ToolsetRegistry_EBypassContainerCheck, METADATA_PARAMS(0, nullptr) }; // 241149770
void Z_Construct_UFunction_UToolsetLibrary_SetObjectProperties_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ToolsetLibrary_eventSetObjectProperties_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UToolsetLibrary_SetObjectProperties_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ToolsetLibrary_eventSetObjectProperties_Parms), &Z_Construct_UFunction_UToolsetLibrary_SetObjectProperties_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UToolsetLibrary_SetObjectProperties_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetLibrary_SetObjectProperties_Statics::NewProp_Object,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetLibrary_SetObjectProperties_Statics::NewProp_PropertiesJson,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetLibrary_SetObjectProperties_Statics::NewProp_BypassContainerCheck_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetLibrary_SetObjectProperties_Statics::NewProp_BypassContainerCheck,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetLibrary_SetObjectProperties_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetLibrary_SetObjectProperties_Statics::PropPointers) < 2048);
// ********** End Function SetObjectProperties Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UToolsetLibrary_SetObjectProperties_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UToolsetLibrary, nullptr, "SetObjectProperties", 	Z_Construct_UFunction_UToolsetLibrary_SetObjectProperties_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetLibrary_SetObjectProperties_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UToolsetLibrary_SetObjectProperties_Statics::ToolsetLibrary_eventSetObjectProperties_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetLibrary_SetObjectProperties_Statics::Function_MetaDataParams), Z_Construct_UFunction_UToolsetLibrary_SetObjectProperties_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UToolsetLibrary_SetObjectProperties_Statics::ToolsetLibrary_eventSetObjectProperties_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UToolsetLibrary_SetObjectProperties()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UToolsetLibrary_SetObjectProperties_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UToolsetLibrary::execSetObjectProperties)
{
	P_GET_OBJECT(UObject,Z_Param_Object);
	P_GET_PROPERTY(FStrProperty,Z_Param_PropertiesJson);
	P_GET_ENUM(EBypassContainerCheck,Z_Param_BypassContainerCheck);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UToolsetLibrary::SetObjectProperties(Z_Param_Object,Z_Param_PropertiesJson,EBypassContainerCheck(Z_Param_BypassContainerCheck));
	P_NATIVE_END;
}
// ********** End Class UToolsetLibrary Function SetObjectProperties *******************************

// ********** Begin Class UToolsetLibrary Function UndoTransaction *********************************
struct Z_Construct_UFunction_UToolsetLibrary_UndoTransaction_Statics
{
	struct ToolsetLibrary_eventUndoTransaction_Parms
	{
		bool bCanRedo;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Toolset Library" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Undo the most recent transaction on the global undo stack.\n\x09 *\n\x09 * Companion to UKismetSystemLibrary's BeginTransaction / EndTransaction /\n\x09 * CancelTransaction, which cover starting and finalizing transactions but\n\x09 * stop short of actually reverting them: CancelTransaction only discards\n\x09 * the undo-stack entry without applying the inverse, so any modifications\n\x09 * a partial transaction made to UObjects survive. Used by\n\x09 * programmatic.execute_tool_script to roll back scripts that error out\n\x09 * partway through.\n\x09 *\n\x09 * @param bCanRedo If true, the undone transaction stays on the redo stack.\n\x09 *        If false (default), it is removed entirely so a rolled-back\n\x09 *        script leaves no trace on the undo history.\n\x09 * @return True if a transaction was undone; false if there was nothing to\n\x09 *         undo or the editor is in a state that prevents undo (e.g. saving\n\x09 *         a package, GC running, or no GEditor).\n\x09 */" },
#endif
		{ "CPP_Default_bCanRedo", "false" },
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolsetLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Undo the most recent transaction on the global undo stack.\n*\n* Companion to UKismetSystemLibrary's BeginTransaction / EndTransaction /\n* CancelTransaction, which cover starting and finalizing transactions but\n* stop short of actually reverting them: CancelTransaction only discards\n* the undo-stack entry without applying the inverse, so any modifications\n* a partial transaction made to UObjects survive. Used by\n* programmatic.execute_tool_script to roll back scripts that error out\n* partway through.\n*\n* @param bCanRedo If true, the undone transaction stays on the redo stack.\n*        If false (default), it is removed entirely so a rolled-back\n*        script leaves no trace on the undo history.\n* @return True if a transaction was undone; false if there was nothing to\n*         undo or the editor is in a state that prevents undo (e.g. saving\n*         a package, GC running, or no GEditor)." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function UndoTransaction constinit property declarations ***********************
	static void NewProp_bCanRedo_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanRedo;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UndoTransaction constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UndoTransaction Property Definitions **********************************
void Z_Construct_UFunction_UToolsetLibrary_UndoTransaction_Statics::NewProp_bCanRedo_SetBit(void* Obj)
{
	((ToolsetLibrary_eventUndoTransaction_Parms*)Obj)->bCanRedo = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UToolsetLibrary_UndoTransaction_Statics::NewProp_bCanRedo = { "bCanRedo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ToolsetLibrary_eventUndoTransaction_Parms), &Z_Construct_UFunction_UToolsetLibrary_UndoTransaction_Statics::NewProp_bCanRedo_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UToolsetLibrary_UndoTransaction_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ToolsetLibrary_eventUndoTransaction_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UToolsetLibrary_UndoTransaction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ToolsetLibrary_eventUndoTransaction_Parms), &Z_Construct_UFunction_UToolsetLibrary_UndoTransaction_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UToolsetLibrary_UndoTransaction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetLibrary_UndoTransaction_Statics::NewProp_bCanRedo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetLibrary_UndoTransaction_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetLibrary_UndoTransaction_Statics::PropPointers) < 2048);
// ********** End Function UndoTransaction Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UToolsetLibrary_UndoTransaction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UToolsetLibrary, nullptr, "UndoTransaction", 	Z_Construct_UFunction_UToolsetLibrary_UndoTransaction_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetLibrary_UndoTransaction_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UToolsetLibrary_UndoTransaction_Statics::ToolsetLibrary_eventUndoTransaction_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetLibrary_UndoTransaction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UToolsetLibrary_UndoTransaction_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UToolsetLibrary_UndoTransaction_Statics::ToolsetLibrary_eventUndoTransaction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UToolsetLibrary_UndoTransaction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UToolsetLibrary_UndoTransaction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UToolsetLibrary::execUndoTransaction)
{
	P_GET_UBOOL(Z_Param_bCanRedo);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UToolsetLibrary::UndoTransaction(Z_Param_bCanRedo);
	P_NATIVE_END;
}
// ********** End Class UToolsetLibrary Function UndoTransaction ***********************************

// ********** Begin Class UToolsetLibrary **********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UToolsetLibrary;
UClass* UToolsetLibrary::GetPrivateStaticClass()
{
	using TClass = UToolsetLibrary;
	if (!Z_Registration_Info_UClass_UToolsetLibrary.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ToolsetLibrary"),
			Z_Registration_Info_UClass_UToolsetLibrary.InnerSingleton,
			StaticRegisterNativesUToolsetLibrary,
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
	return Z_Registration_Info_UClass_UToolsetLibrary.InnerSingleton;
}
UClass* Z_Construct_UClass_UToolsetLibrary_NoRegister()
{
	return UToolsetLibrary::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UToolsetLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Provides functions that are critical to Python toolset operation but which are not available\n/// in and cannot be added to any other BFPL.\n" },
#endif
		{ "IncludePath", "ToolsetRegistry/ToolsetLibrary.h" },
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolsetLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Provides functions that are critical to Python toolset operation but which are not available\nin and cannot be added to any other BFPL." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UToolsetLibrary constinit property declarations **************************
// ********** End Class UToolsetLibrary constinit property declarations ****************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetActiveUndoCount"), .Pointer = &UToolsetLibrary::execGetActiveUndoCount },
		{ .NameUTF8 = UTF8TEXT("GetDerivedClasses"), .Pointer = &UToolsetLibrary::execGetDerivedClasses },
		{ .NameUTF8 = UTF8TEXT("GetDerivedStructs"), .Pointer = &UToolsetLibrary::execGetDerivedStructs },
		{ .NameUTF8 = UTF8TEXT("GetObjectProperties"), .Pointer = &UToolsetLibrary::execGetObjectProperties },
		{ .NameUTF8 = UTF8TEXT("ListStructProperties"), .Pointer = &UToolsetLibrary::execListStructProperties },
		{ .NameUTF8 = UTF8TEXT("SetObjectProperties"), .Pointer = &UToolsetLibrary::execSetObjectProperties },
		{ .NameUTF8 = UTF8TEXT("UndoTransaction"), .Pointer = &UToolsetLibrary::execUndoTransaction },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UToolsetLibrary_GetActiveUndoCount, "GetActiveUndoCount" }, // 1124546363
		{ &Z_Construct_UFunction_UToolsetLibrary_GetDerivedClasses, "GetDerivedClasses" }, // 92788120
		{ &Z_Construct_UFunction_UToolsetLibrary_GetDerivedStructs, "GetDerivedStructs" }, // 2376486037
		{ &Z_Construct_UFunction_UToolsetLibrary_GetObjectProperties, "GetObjectProperties" }, // 3891756095
		{ &Z_Construct_UFunction_UToolsetLibrary_ListStructProperties, "ListStructProperties" }, // 236051803
		{ &Z_Construct_UFunction_UToolsetLibrary_SetObjectProperties, "SetObjectProperties" }, // 3259453160
		{ &Z_Construct_UFunction_UToolsetLibrary_UndoTransaction, "UndoTransaction" }, // 1505359320
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UToolsetLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UToolsetLibrary_Statics
UObject* (*const Z_Construct_UClass_UToolsetLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_ToolsetRegistry,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UToolsetLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UToolsetLibrary_Statics::ClassParams = {
	&UToolsetLibrary::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UToolsetLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UToolsetLibrary_Statics::Class_MetaDataParams)
};
void UToolsetLibrary::StaticRegisterNativesUToolsetLibrary()
{
	UClass* Class = UToolsetLibrary::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UToolsetLibrary_Statics::Funcs));
}
UClass* Z_Construct_UClass_UToolsetLibrary()
{
	if (!Z_Registration_Info_UClass_UToolsetLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UToolsetLibrary.OuterSingleton, Z_Construct_UClass_UToolsetLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UToolsetLibrary.OuterSingleton;
}
UToolsetLibrary::UToolsetLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UToolsetLibrary);
UToolsetLibrary::~UToolsetLibrary() {}
// ********** End Class UToolsetLibrary ************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetLibrary_h__Script_ToolsetRegistry_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EBypassContainerCheck_StaticEnum, TEXT("EBypassContainerCheck"), &Z_Registration_Info_UEnum_EBypassContainerCheck, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 241149770U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UToolsetLibrary, UToolsetLibrary::StaticClass, TEXT("UToolsetLibrary"), &Z_Registration_Info_UClass_UToolsetLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UToolsetLibrary), 726726063U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetLibrary_h__Script_ToolsetRegistry_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetLibrary_h__Script_ToolsetRegistry_3767171133{
	TEXT("/Script/ToolsetRegistry"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetLibrary_h__Script_ToolsetRegistry_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetLibrary_h__Script_ToolsetRegistry_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetLibrary_h__Script_ToolsetRegistry_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolsetLibrary_h__Script_ToolsetRegistry_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
