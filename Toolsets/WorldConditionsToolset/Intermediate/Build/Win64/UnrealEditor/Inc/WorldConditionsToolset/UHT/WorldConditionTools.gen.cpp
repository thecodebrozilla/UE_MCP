// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WorldConditionTools.h"
#include "StructUtils/InstancedStruct.h"
#include "WorldConditionQuery.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeWorldConditionTools() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FInstancedStruct();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition();
UPackage* Z_Construct_UPackage__Script_WorldConditionsToolset();
WORLDCONDITIONS_API UScriptStruct* Z_Construct_UScriptStruct_FWorldConditionQueryDefinition();
WORLDCONDITIONSTOOLSET_API UClass* Z_Construct_UClass_UWorldConditionTools();
WORLDCONDITIONSTOOLSET_API UClass* Z_Construct_UClass_UWorldConditionTools_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UWorldConditionTools Function GetConditionDescription ********************
struct Z_Construct_UFunction_UWorldConditionTools_GetConditionDescription_Statics
{
	struct WorldConditionTools_eventGetConditionDescription_Parms
	{
		FInstancedStruct Condition;
		FText ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "WorldConditions" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns a human-readable description of a single world condition.\n\x09 * The condition must be passed as an FInstancedStruct containing an FWorldConditionBase-derived struct.\n\x09 * @param Condition The instanced struct holding the world condition.\n\x09 * @return Text description of the condition, or empty if invalid.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/WorldConditionTools.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns a human-readable description of a single world condition.\nThe condition must be passed as an FInstancedStruct containing an FWorldConditionBase-derived struct.\n@param Condition The instanced struct holding the world condition.\n@return Text description of the condition, or empty if invalid." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Condition_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetConditionDescription constinit property declarations ***************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Condition;
	static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetConditionDescription constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetConditionDescription Property Definitions **************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWorldConditionTools_GetConditionDescription_Statics::NewProp_Condition = { "Condition", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WorldConditionTools_eventGetConditionDescription_Parms, Condition), Z_Construct_UScriptStruct_FInstancedStruct, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Condition_MetaData), NewProp_Condition_MetaData) }; // 3949785911
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UWorldConditionTools_GetConditionDescription_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WorldConditionTools_eventGetConditionDescription_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWorldConditionTools_GetConditionDescription_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWorldConditionTools_GetConditionDescription_Statics::NewProp_Condition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWorldConditionTools_GetConditionDescription_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldConditionTools_GetConditionDescription_Statics::PropPointers) < 2048);
// ********** End Function GetConditionDescription Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWorldConditionTools_GetConditionDescription_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWorldConditionTools, nullptr, "GetConditionDescription", 	Z_Construct_UFunction_UWorldConditionTools_GetConditionDescription_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldConditionTools_GetConditionDescription_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UWorldConditionTools_GetConditionDescription_Statics::WorldConditionTools_eventGetConditionDescription_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldConditionTools_GetConditionDescription_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWorldConditionTools_GetConditionDescription_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWorldConditionTools_GetConditionDescription_Statics::WorldConditionTools_eventGetConditionDescription_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWorldConditionTools_GetConditionDescription()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWorldConditionTools_GetConditionDescription_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UWorldConditionTools::execGetConditionDescription)
{
	P_GET_STRUCT_REF(FInstancedStruct,Z_Param_Out_Condition);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FText*)Z_Param__Result=UWorldConditionTools::GetConditionDescription(Z_Param_Out_Condition);
	P_NATIVE_END;
}
// ********** End Class UWorldConditionTools Function GetConditionDescription **********************

// ********** Begin Class UWorldConditionTools Function GetQueryDescription ************************
struct Z_Construct_UFunction_UWorldConditionTools_GetQueryDescription_Statics
{
	struct WorldConditionTools_eventGetQueryDescription_Parms
	{
		FWorldConditionQueryDefinition QueryDefinition;
		FText ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "WorldConditions" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns a human-readable description of a world condition query.\n\x09 * @param QueryDefinition The query definition to describe.\n\x09 * @return Text description of all conditions in the query.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/WorldConditionTools.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns a human-readable description of a world condition query.\n@param QueryDefinition The query definition to describe.\n@return Text description of all conditions in the query." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_QueryDefinition_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetQueryDescription constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_QueryDefinition;
	static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetQueryDescription constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetQueryDescription Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWorldConditionTools_GetQueryDescription_Statics::NewProp_QueryDefinition = { "QueryDefinition", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WorldConditionTools_eventGetQueryDescription_Parms, QueryDefinition), Z_Construct_UScriptStruct_FWorldConditionQueryDefinition, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_QueryDefinition_MetaData), NewProp_QueryDefinition_MetaData) }; // 1413488158
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UWorldConditionTools_GetQueryDescription_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WorldConditionTools_eventGetQueryDescription_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWorldConditionTools_GetQueryDescription_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWorldConditionTools_GetQueryDescription_Statics::NewProp_QueryDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWorldConditionTools_GetQueryDescription_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldConditionTools_GetQueryDescription_Statics::PropPointers) < 2048);
// ********** End Function GetQueryDescription Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWorldConditionTools_GetQueryDescription_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWorldConditionTools, nullptr, "GetQueryDescription", 	Z_Construct_UFunction_UWorldConditionTools_GetQueryDescription_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldConditionTools_GetQueryDescription_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UWorldConditionTools_GetQueryDescription_Statics::WorldConditionTools_eventGetQueryDescription_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldConditionTools_GetQueryDescription_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWorldConditionTools_GetQueryDescription_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWorldConditionTools_GetQueryDescription_Statics::WorldConditionTools_eventGetQueryDescription_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWorldConditionTools_GetQueryDescription()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWorldConditionTools_GetQueryDescription_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UWorldConditionTools::execGetQueryDescription)
{
	P_GET_STRUCT_REF(FWorldConditionQueryDefinition,Z_Param_Out_QueryDefinition);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FText*)Z_Param__Result=UWorldConditionTools::GetQueryDescription(Z_Param_Out_QueryDefinition);
	P_NATIVE_END;
}
// ********** End Class UWorldConditionTools Function GetQueryDescription **************************

// ********** Begin Class UWorldConditionTools *****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UWorldConditionTools;
UClass* UWorldConditionTools::GetPrivateStaticClass()
{
	using TClass = UWorldConditionTools;
	if (!Z_Registration_Info_UClass_UWorldConditionTools.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("WorldConditionTools"),
			Z_Registration_Info_UClass_UWorldConditionTools.InnerSingleton,
			StaticRegisterNativesUWorldConditionTools,
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
	return Z_Registration_Info_UClass_UWorldConditionTools.InnerSingleton;
}
UClass* Z_Construct_UClass_UWorldConditionTools_NoRegister()
{
	return UWorldConditionTools::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UWorldConditionTools_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Inspect WorldCondition (FWorldConditionQueryDefinition, FWorldConditionBase) structs. */" },
#endif
		{ "IncludePath", "WorldConditionTools.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Private/WorldConditionTools.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Inspect WorldCondition (FWorldConditionQueryDefinition, FWorldConditionBase) structs." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UWorldConditionTools constinit property declarations *********************
// ********** End Class UWorldConditionTools constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetConditionDescription"), .Pointer = &UWorldConditionTools::execGetConditionDescription },
		{ .NameUTF8 = UTF8TEXT("GetQueryDescription"), .Pointer = &UWorldConditionTools::execGetQueryDescription },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UWorldConditionTools_GetConditionDescription, "GetConditionDescription" }, // 1525105256
		{ &Z_Construct_UFunction_UWorldConditionTools_GetQueryDescription, "GetQueryDescription" }, // 2320105788
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UWorldConditionTools>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UWorldConditionTools_Statics
UObject* (*const Z_Construct_UClass_UWorldConditionTools_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UToolsetDefinition,
	(UObject* (*)())Z_Construct_UPackage__Script_WorldConditionsToolset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UWorldConditionTools_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UWorldConditionTools_Statics::ClassParams = {
	&UWorldConditionTools::StaticClass,
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
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UWorldConditionTools_Statics::Class_MetaDataParams), Z_Construct_UClass_UWorldConditionTools_Statics::Class_MetaDataParams)
};
void UWorldConditionTools::StaticRegisterNativesUWorldConditionTools()
{
	UClass* Class = UWorldConditionTools::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UWorldConditionTools_Statics::Funcs));
}
UClass* Z_Construct_UClass_UWorldConditionTools()
{
	if (!Z_Registration_Info_UClass_UWorldConditionTools.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UWorldConditionTools.OuterSingleton, Z_Construct_UClass_UWorldConditionTools_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UWorldConditionTools.OuterSingleton;
}
UWorldConditionTools::UWorldConditionTools(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UWorldConditionTools);
UWorldConditionTools::~UWorldConditionTools() {}
// ********** End Class UWorldConditionTools *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_WorldConditionsToolset_Source_WorldConditionsToolset_Private_WorldConditionTools_h__Script_WorldConditionsToolset_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UWorldConditionTools, UWorldConditionTools::StaticClass, TEXT("UWorldConditionTools"), &Z_Registration_Info_UClass_UWorldConditionTools, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UWorldConditionTools), 1429716910U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_WorldConditionsToolset_Source_WorldConditionsToolset_Private_WorldConditionTools_h__Script_WorldConditionsToolset_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_WorldConditionsToolset_Source_WorldConditionsToolset_Private_WorldConditionTools_h__Script_WorldConditionsToolset_981158959{
	TEXT("/Script/WorldConditionsToolset"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_WorldConditionsToolset_Source_WorldConditionsToolset_Private_WorldConditionTools_h__Script_WorldConditionsToolset_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_WorldConditionsToolset_Source_WorldConditionsToolset_Private_WorldConditionTools_h__Script_WorldConditionsToolset_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
