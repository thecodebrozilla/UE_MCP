// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ToolsetRegistry/ToolCallAsyncResultFutureHandler.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeToolCallAsyncResultFutureHandler() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolCallAsyncResult_NoRegister();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolCallAsyncResultFutureHandler();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolCallAsyncResultFutureHandler_NoRegister();
UPackage* Z_Construct_UPackage__Script_ToolsetRegistry();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UToolCallAsyncResultFutureHandler Function OnCompleted *******************
struct Z_Construct_UFunction_UToolCallAsyncResultFutureHandler_OnCompleted_Statics
{
	struct ToolCallAsyncResultFutureHandler_eventOnCompleted_Parms
	{
		UToolCallAsyncResult* Result;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Handles a result completion.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolCallAsyncResultFutureHandler.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handles a result completion." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnCompleted constinit property declarations ***************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Result;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnCompleted constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnCompleted Property Definitions **************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UToolCallAsyncResultFutureHandler_OnCompleted_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ToolCallAsyncResultFutureHandler_eventOnCompleted_Parms, Result), Z_Construct_UClass_UToolCallAsyncResult_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UToolCallAsyncResultFutureHandler_OnCompleted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolCallAsyncResultFutureHandler_OnCompleted_Statics::NewProp_Result,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolCallAsyncResultFutureHandler_OnCompleted_Statics::PropPointers) < 2048);
// ********** End Function OnCompleted Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UToolCallAsyncResultFutureHandler_OnCompleted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UToolCallAsyncResultFutureHandler, nullptr, "OnCompleted", 	Z_Construct_UFunction_UToolCallAsyncResultFutureHandler_OnCompleted_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UToolCallAsyncResultFutureHandler_OnCompleted_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UToolCallAsyncResultFutureHandler_OnCompleted_Statics::ToolCallAsyncResultFutureHandler_eventOnCompleted_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolCallAsyncResultFutureHandler_OnCompleted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UToolCallAsyncResultFutureHandler_OnCompleted_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UToolCallAsyncResultFutureHandler_OnCompleted_Statics::ToolCallAsyncResultFutureHandler_eventOnCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UToolCallAsyncResultFutureHandler_OnCompleted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UToolCallAsyncResultFutureHandler_OnCompleted_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UToolCallAsyncResultFutureHandler::execOnCompleted)
{
	P_GET_OBJECT(UToolCallAsyncResult,Z_Param_Result);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnCompleted(Z_Param_Result);
	P_NATIVE_END;
}
// ********** End Class UToolCallAsyncResultFutureHandler Function OnCompleted *********************

// ********** Begin Class UToolCallAsyncResultFutureHandler ****************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UToolCallAsyncResultFutureHandler;
UClass* UToolCallAsyncResultFutureHandler::GetPrivateStaticClass()
{
	using TClass = UToolCallAsyncResultFutureHandler;
	if (!Z_Registration_Info_UClass_UToolCallAsyncResultFutureHandler.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ToolCallAsyncResultFutureHandler"),
			Z_Registration_Info_UClass_UToolCallAsyncResultFutureHandler.InnerSingleton,
			StaticRegisterNativesUToolCallAsyncResultFutureHandler,
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
	return Z_Registration_Info_UClass_UToolCallAsyncResultFutureHandler.InnerSingleton;
}
UClass* Z_Construct_UClass_UToolCallAsyncResultFutureHandler_NoRegister()
{
	return UToolCallAsyncResultFutureHandler::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UToolCallAsyncResultFutureHandler_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Handles UToolCallAsyncResult::OnCompleted by completing the associated future.\n//\n// NOTE: This is tested by ToolCallAsyncResultTest.cpp.\n" },
#endif
		{ "IncludePath", "ToolsetRegistry/ToolCallAsyncResultFutureHandler.h" },
		{ "IsBlueprintBase", "false" },
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolCallAsyncResultFutureHandler.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handles UToolCallAsyncResult::OnCompleted by completing the associated future.\n\nNOTE: This is tested by ToolCallAsyncResultTest.cpp." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UToolCallAsyncResultFutureHandler constinit property declarations ********
// ********** End Class UToolCallAsyncResultFutureHandler constinit property declarations **********
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("OnCompleted"), .Pointer = &UToolCallAsyncResultFutureHandler::execOnCompleted },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UToolCallAsyncResultFutureHandler_OnCompleted, "OnCompleted" }, // 2264597503
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UToolCallAsyncResultFutureHandler>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UToolCallAsyncResultFutureHandler_Statics
UObject* (*const Z_Construct_UClass_UToolCallAsyncResultFutureHandler_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_ToolsetRegistry,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UToolCallAsyncResultFutureHandler_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UToolCallAsyncResultFutureHandler_Statics::ClassParams = {
	&UToolCallAsyncResultFutureHandler::StaticClass,
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
	0x040800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UToolCallAsyncResultFutureHandler_Statics::Class_MetaDataParams), Z_Construct_UClass_UToolCallAsyncResultFutureHandler_Statics::Class_MetaDataParams)
};
void UToolCallAsyncResultFutureHandler::StaticRegisterNativesUToolCallAsyncResultFutureHandler()
{
	UClass* Class = UToolCallAsyncResultFutureHandler::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UToolCallAsyncResultFutureHandler_Statics::Funcs));
}
UClass* Z_Construct_UClass_UToolCallAsyncResultFutureHandler()
{
	if (!Z_Registration_Info_UClass_UToolCallAsyncResultFutureHandler.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UToolCallAsyncResultFutureHandler.OuterSingleton, Z_Construct_UClass_UToolCallAsyncResultFutureHandler_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UToolCallAsyncResultFutureHandler.OuterSingleton;
}
UToolCallAsyncResultFutureHandler::UToolCallAsyncResultFutureHandler(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UToolCallAsyncResultFutureHandler);
// ********** End Class UToolCallAsyncResultFutureHandler ******************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultFutureHandler_h__Script_ToolsetRegistry_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UToolCallAsyncResultFutureHandler, UToolCallAsyncResultFutureHandler::StaticClass, TEXT("UToolCallAsyncResultFutureHandler"), &Z_Registration_Info_UClass_UToolCallAsyncResultFutureHandler, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UToolCallAsyncResultFutureHandler), 2868605703U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultFutureHandler_h__Script_ToolsetRegistry_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultFutureHandler_h__Script_ToolsetRegistry_281668196{
	TEXT("/Script/ToolsetRegistry"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultFutureHandler_h__Script_ToolsetRegistry_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultFutureHandler_h__Script_ToolsetRegistry_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
