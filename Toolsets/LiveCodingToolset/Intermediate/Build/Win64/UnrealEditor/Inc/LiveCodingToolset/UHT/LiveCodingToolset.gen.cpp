// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LiveCodingToolset.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeLiveCodingToolset() {}

// ********** Begin Cross Module References ********************************************************
LIVECODINGTOOLSET_API UClass* Z_Construct_UClass_ULiveCodingToolset();
LIVECODINGTOOLSET_API UClass* Z_Construct_UClass_ULiveCodingToolset_NoRegister();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition();
UPackage* Z_Construct_UPackage__Script_LiveCodingToolset();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ULiveCodingToolset Function CompileLiveCoding ****************************
struct Z_Construct_UFunction_ULiveCodingToolset_CompileLiveCoding_Statics
{
	struct LiveCodingToolset_eventCompileLiveCoding_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "LiveCodingToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Triggers a Live Coding compile and waits for the result.\n\x09 * Live Coding must be enabled in Editor Preferences.\n\x09 * @return The compile result status followed by any compiler output (errors, warnings, etc). */" },
#endif
		{ "ModuleRelativePath", "Public/LiveCodingToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Triggers a Live Coding compile and waits for the result.\nLive Coding must be enabled in Editor Preferences.\n@return The compile result status followed by any compiler output (errors, warnings, etc)." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function CompileLiveCoding constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CompileLiveCoding constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CompileLiveCoding Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ULiveCodingToolset_CompileLiveCoding_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LiveCodingToolset_eventCompileLiveCoding_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULiveCodingToolset_CompileLiveCoding_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULiveCodingToolset_CompileLiveCoding_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULiveCodingToolset_CompileLiveCoding_Statics::PropPointers) < 2048);
// ********** End Function CompileLiveCoding Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULiveCodingToolset_CompileLiveCoding_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULiveCodingToolset, nullptr, "CompileLiveCoding", 	Z_Construct_UFunction_ULiveCodingToolset_CompileLiveCoding_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ULiveCodingToolset_CompileLiveCoding_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_ULiveCodingToolset_CompileLiveCoding_Statics::LiveCodingToolset_eventCompileLiveCoding_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULiveCodingToolset_CompileLiveCoding_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULiveCodingToolset_CompileLiveCoding_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULiveCodingToolset_CompileLiveCoding_Statics::LiveCodingToolset_eventCompileLiveCoding_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULiveCodingToolset_CompileLiveCoding()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULiveCodingToolset_CompileLiveCoding_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULiveCodingToolset::execCompileLiveCoding)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=ULiveCodingToolset::CompileLiveCoding();
	P_NATIVE_END;
}
// ********** End Class ULiveCodingToolset Function CompileLiveCoding ******************************

// ********** Begin Class ULiveCodingToolset *******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_ULiveCodingToolset;
UClass* ULiveCodingToolset::GetPrivateStaticClass()
{
	using TClass = ULiveCodingToolset;
	if (!Z_Registration_Info_UClass_ULiveCodingToolset.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("LiveCodingToolset"),
			Z_Registration_Info_UClass_ULiveCodingToolset.InnerSingleton,
			StaticRegisterNativesULiveCodingToolset,
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
	return Z_Registration_Info_UClass_ULiveCodingToolset.InnerSingleton;
}
UClass* Z_Construct_UClass_ULiveCodingToolset_NoRegister()
{
	return ULiveCodingToolset::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ULiveCodingToolset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Live Coding compile toolset.\n *\n * Exposes an MCP tool that triggers a Live Coding compile from the running\n * editor and waits for the result, returning the compile status together with\n * any captured LogLiveCoding output and UBT compiler diagnostics.\n */" },
#endif
		{ "IncludePath", "LiveCodingToolset.h" },
		{ "ModuleRelativePath", "Public/LiveCodingToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Live Coding compile toolset.\n\nExposes an MCP tool that triggers a Live Coding compile from the running\neditor and waits for the result, returning the compile status together with\nany captured LogLiveCoding output and UBT compiler diagnostics." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class ULiveCodingToolset constinit property declarations ***********************
// ********** End Class ULiveCodingToolset constinit property declarations *************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CompileLiveCoding"), .Pointer = &ULiveCodingToolset::execCompileLiveCoding },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ULiveCodingToolset_CompileLiveCoding, "CompileLiveCoding" }, // 1550908223
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULiveCodingToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_ULiveCodingToolset_Statics
UObject* (*const Z_Construct_UClass_ULiveCodingToolset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UToolsetDefinition,
	(UObject* (*)())Z_Construct_UPackage__Script_LiveCodingToolset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULiveCodingToolset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULiveCodingToolset_Statics::ClassParams = {
	&ULiveCodingToolset::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULiveCodingToolset_Statics::Class_MetaDataParams), Z_Construct_UClass_ULiveCodingToolset_Statics::Class_MetaDataParams)
};
void ULiveCodingToolset::StaticRegisterNativesULiveCodingToolset()
{
	UClass* Class = ULiveCodingToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_ULiveCodingToolset_Statics::Funcs));
}
UClass* Z_Construct_UClass_ULiveCodingToolset()
{
	if (!Z_Registration_Info_UClass_ULiveCodingToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULiveCodingToolset.OuterSingleton, Z_Construct_UClass_ULiveCodingToolset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULiveCodingToolset.OuterSingleton;
}
ULiveCodingToolset::ULiveCodingToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ULiveCodingToolset);
ULiveCodingToolset::~ULiveCodingToolset() {}
// ********** End Class ULiveCodingToolset *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_LiveCodingToolset_Source_LiveCodingToolset_Public_LiveCodingToolset_h__Script_LiveCodingToolset_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULiveCodingToolset, ULiveCodingToolset::StaticClass, TEXT("ULiveCodingToolset"), &Z_Registration_Info_UClass_ULiveCodingToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULiveCodingToolset), 2780134837U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_LiveCodingToolset_Source_LiveCodingToolset_Public_LiveCodingToolset_h__Script_LiveCodingToolset_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_LiveCodingToolset_Source_LiveCodingToolset_Public_LiveCodingToolset_h__Script_LiveCodingToolset_2073566974{
	TEXT("/Script/LiveCodingToolset"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_LiveCodingToolset_Source_LiveCodingToolset_Public_LiveCodingToolset_h__Script_LiveCodingToolset_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_LiveCodingToolset_Source_LiveCodingToolset_Public_LiveCodingToolset_h__Script_LiveCodingToolset_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
