// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PCGSpatialToolset.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodePCGSpatialToolset() {}

// ********** Begin Cross Module References ********************************************************
PCG_API UClass* Z_Construct_UClass_UPCGGraph_NoRegister();
PCGTOOLSET_API UClass* Z_Construct_UClass_UPCGExecuteGraphInstanceAsyncResult_NoRegister();
PCGTOOLSET_API UClass* Z_Construct_UClass_UPCGSpatialToolset();
PCGTOOLSET_API UClass* Z_Construct_UClass_UPCGSpatialToolset_NoRegister();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition();
UPackage* Z_Construct_UPackage__Script_PCGToolset();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UPCGSpatialToolset Function RunPCGInstantGraph ***************************
struct Z_Construct_UFunction_UPCGSpatialToolset_RunPCGInstantGraph_Statics
{
	struct PCGSpatialToolset_eventRunPCGInstantGraph_Parms
	{
		UPCGGraph* Graph;
		TMap<FString,FString> Params;
		UPCGExecuteGraphInstanceAsyncResult* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PCG|Graph" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Runs an instant PCG graph with the specified parameters in fire-and-forget mode\n\x09 * (Should be called directly: Not callable in a python context execution context)\n\x09 *\n\x09 * @param Graph - The PCG graph to execute\n\x09 * @param Params - Key-value parameters to pass to the graph\n\x09 * @return Array of per-node execution messages emitted while running the graph (empty on success with no issues).\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/PCGSpatialToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Runs an instant PCG graph with the specified parameters in fire-and-forget mode\n(Should be called directly: Not callable in a python context execution context)\n\n@param Graph - The PCG graph to execute\n@param Params - Key-value parameters to pass to the graph\n@return Array of per-node execution messages emitted while running the graph (empty on success with no issues)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Params_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RunPCGInstantGraph constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Graph;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Params_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Params_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_Params;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RunPCGInstantGraph constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RunPCGInstantGraph Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGSpatialToolset_RunPCGInstantGraph_Statics::NewProp_Graph = { "Graph", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGSpatialToolset_eventRunPCGInstantGraph_Parms, Graph), Z_Construct_UClass_UPCGGraph_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGSpatialToolset_RunPCGInstantGraph_Statics::NewProp_Params_ValueProp = { "Params", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGSpatialToolset_RunPCGInstantGraph_Statics::NewProp_Params_Key_KeyProp = { "Params_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UPCGSpatialToolset_RunPCGInstantGraph_Statics::NewProp_Params = { "Params", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGSpatialToolset_eventRunPCGInstantGraph_Parms, Params), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Params_MetaData), NewProp_Params_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGSpatialToolset_RunPCGInstantGraph_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGSpatialToolset_eventRunPCGInstantGraph_Parms, ReturnValue), Z_Construct_UClass_UPCGExecuteGraphInstanceAsyncResult_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPCGSpatialToolset_RunPCGInstantGraph_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGSpatialToolset_RunPCGInstantGraph_Statics::NewProp_Graph,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGSpatialToolset_RunPCGInstantGraph_Statics::NewProp_Params_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGSpatialToolset_RunPCGInstantGraph_Statics::NewProp_Params_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGSpatialToolset_RunPCGInstantGraph_Statics::NewProp_Params,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGSpatialToolset_RunPCGInstantGraph_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGSpatialToolset_RunPCGInstantGraph_Statics::PropPointers) < 2048);
// ********** End Function RunPCGInstantGraph Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPCGSpatialToolset_RunPCGInstantGraph_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPCGSpatialToolset, nullptr, "RunPCGInstantGraph", 	Z_Construct_UFunction_UPCGSpatialToolset_RunPCGInstantGraph_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGSpatialToolset_RunPCGInstantGraph_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPCGSpatialToolset_RunPCGInstantGraph_Statics::PCGSpatialToolset_eventRunPCGInstantGraph_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGSpatialToolset_RunPCGInstantGraph_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPCGSpatialToolset_RunPCGInstantGraph_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPCGSpatialToolset_RunPCGInstantGraph_Statics::PCGSpatialToolset_eventRunPCGInstantGraph_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPCGSpatialToolset_RunPCGInstantGraph()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPCGSpatialToolset_RunPCGInstantGraph_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPCGSpatialToolset::execRunPCGInstantGraph)
{
	P_GET_OBJECT(UPCGGraph,Z_Param_Graph);
	P_GET_TMAP_REF(FString,FString,Z_Param_Out_Params);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UPCGExecuteGraphInstanceAsyncResult**)Z_Param__Result=UPCGSpatialToolset::RunPCGInstantGraph(Z_Param_Graph,Z_Param_Out_Params);
	P_NATIVE_END;
}
// ********** End Class UPCGSpatialToolset Function RunPCGInstantGraph *****************************

// ********** Begin Class UPCGSpatialToolset *******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UPCGSpatialToolset;
UClass* UPCGSpatialToolset::GetPrivateStaticClass()
{
	using TClass = UPCGSpatialToolset;
	if (!Z_Registration_Info_UClass_UPCGSpatialToolset.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("PCGSpatialToolset"),
			Z_Registration_Info_UClass_UPCGSpatialToolset.InnerSingleton,
			StaticRegisterNativesUPCGSpatialToolset,
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
	return Z_Registration_Info_UClass_UPCGSpatialToolset.InnerSingleton;
}
UClass* Z_Construct_UClass_UPCGSpatialToolset_NoRegister()
{
	return UPCGSpatialToolset::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPCGSpatialToolset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "PCGSpatialToolset.h" },
		{ "ModuleRelativePath", "Public/PCGSpatialToolset.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UPCGSpatialToolset constinit property declarations ***********************
// ********** End Class UPCGSpatialToolset constinit property declarations *************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("RunPCGInstantGraph"), .Pointer = &UPCGSpatialToolset::execRunPCGInstantGraph },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UPCGSpatialToolset_RunPCGInstantGraph, "RunPCGInstantGraph" }, // 31066668
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPCGSpatialToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UPCGSpatialToolset_Statics
UObject* (*const Z_Construct_UClass_UPCGSpatialToolset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UToolsetDefinition,
	(UObject* (*)())Z_Construct_UPackage__Script_PCGToolset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPCGSpatialToolset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPCGSpatialToolset_Statics::ClassParams = {
	&UPCGSpatialToolset::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPCGSpatialToolset_Statics::Class_MetaDataParams), Z_Construct_UClass_UPCGSpatialToolset_Statics::Class_MetaDataParams)
};
void UPCGSpatialToolset::StaticRegisterNativesUPCGSpatialToolset()
{
	UClass* Class = UPCGSpatialToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UPCGSpatialToolset_Statics::Funcs));
}
UClass* Z_Construct_UClass_UPCGSpatialToolset()
{
	if (!Z_Registration_Info_UClass_UPCGSpatialToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPCGSpatialToolset.OuterSingleton, Z_Construct_UClass_UPCGSpatialToolset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPCGSpatialToolset.OuterSingleton;
}
UPCGSpatialToolset::UPCGSpatialToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UPCGSpatialToolset);
UPCGSpatialToolset::~UPCGSpatialToolset() {}
// ********** End Class UPCGSpatialToolset *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGSpatialToolset_h__Script_PCGToolset_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPCGSpatialToolset, UPCGSpatialToolset::StaticClass, TEXT("UPCGSpatialToolset"), &Z_Registration_Info_UClass_UPCGSpatialToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPCGSpatialToolset), 495577208U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGSpatialToolset_h__Script_PCGToolset_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGSpatialToolset_h__Script_PCGToolset_3183970800{
	TEXT("/Script/PCGToolset"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGSpatialToolset_h__Script_PCGToolset_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGSpatialToolset_h__Script_PCGToolset_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
