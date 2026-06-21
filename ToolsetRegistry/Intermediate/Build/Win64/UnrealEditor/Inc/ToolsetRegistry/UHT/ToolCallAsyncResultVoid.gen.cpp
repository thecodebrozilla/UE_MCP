// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ToolsetRegistry/ToolCallAsyncResultVoid.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeToolCallAsyncResultVoid() {}

// ********** Begin Cross Module References ********************************************************
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolCallAsyncResult();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolCallAsyncResultVoid();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolCallAsyncResultVoid_NoRegister();
UPackage* Z_Construct_UPackage__Script_ToolsetRegistry();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UToolCallAsyncResultVoid Function SetCompleted ***************************
struct Z_Construct_UFunction_UToolCallAsyncResultVoid_SetCompleted_Statics
{
	struct ToolCallAsyncResultVoid_eventSetCompleted_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ToolsetRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Complete this result with no value and notify listeners of OnCompleted.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolCallAsyncResultVoid.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Complete this result with no value and notify listeners of OnCompleted." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetCompleted constinit property declarations **************************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetCompleted constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetCompleted Property Definitions *************************************
void Z_Construct_UFunction_UToolCallAsyncResultVoid_SetCompleted_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ToolCallAsyncResultVoid_eventSetCompleted_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UToolCallAsyncResultVoid_SetCompleted_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ToolCallAsyncResultVoid_eventSetCompleted_Parms), &Z_Construct_UFunction_UToolCallAsyncResultVoid_SetCompleted_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UToolCallAsyncResultVoid_SetCompleted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolCallAsyncResultVoid_SetCompleted_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolCallAsyncResultVoid_SetCompleted_Statics::PropPointers) < 2048);
// ********** End Function SetCompleted Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UToolCallAsyncResultVoid_SetCompleted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UToolCallAsyncResultVoid, nullptr, "SetCompleted", 	Z_Construct_UFunction_UToolCallAsyncResultVoid_SetCompleted_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UToolCallAsyncResultVoid_SetCompleted_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UToolCallAsyncResultVoid_SetCompleted_Statics::ToolCallAsyncResultVoid_eventSetCompleted_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolCallAsyncResultVoid_SetCompleted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UToolCallAsyncResultVoid_SetCompleted_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UToolCallAsyncResultVoid_SetCompleted_Statics::ToolCallAsyncResultVoid_eventSetCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UToolCallAsyncResultVoid_SetCompleted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UToolCallAsyncResultVoid_SetCompleted_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UToolCallAsyncResultVoid::execSetCompleted)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SetCompleted();
	P_NATIVE_END;
}
// ********** End Class UToolCallAsyncResultVoid Function SetCompleted *****************************

// ********** Begin Class UToolCallAsyncResultVoid *************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UToolCallAsyncResultVoid;
UClass* UToolCallAsyncResultVoid::GetPrivateStaticClass()
{
	using TClass = UToolCallAsyncResultVoid;
	if (!Z_Registration_Info_UClass_UToolCallAsyncResultVoid.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ToolCallAsyncResultVoid"),
			Z_Registration_Info_UClass_UToolCallAsyncResultVoid.InnerSingleton,
			StaticRegisterNativesUToolCallAsyncResultVoid,
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
	return Z_Registration_Info_UClass_UToolCallAsyncResultVoid.InnerSingleton;
}
UClass* Z_Construct_UClass_UToolCallAsyncResultVoid_NoRegister()
{
	return UToolCallAsyncResultVoid::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UToolCallAsyncResultVoid_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Async tool call result that completes with no value.\n" },
#endif
		{ "IncludePath", "ToolsetRegistry/ToolCallAsyncResultVoid.h" },
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolCallAsyncResultVoid.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Async tool call result that completes with no value." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UToolCallAsyncResultVoid constinit property declarations *****************
// ********** End Class UToolCallAsyncResultVoid constinit property declarations *******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("SetCompleted"), .Pointer = &UToolCallAsyncResultVoid::execSetCompleted },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UToolCallAsyncResultVoid_SetCompleted, "SetCompleted" }, // 1599362774
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UToolCallAsyncResultVoid>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UToolCallAsyncResultVoid_Statics
UObject* (*const Z_Construct_UClass_UToolCallAsyncResultVoid_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UToolCallAsyncResult,
	(UObject* (*)())Z_Construct_UPackage__Script_ToolsetRegistry,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UToolCallAsyncResultVoid_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UToolCallAsyncResultVoid_Statics::ClassParams = {
	&UToolCallAsyncResultVoid::StaticClass,
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
	0x008000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UToolCallAsyncResultVoid_Statics::Class_MetaDataParams), Z_Construct_UClass_UToolCallAsyncResultVoid_Statics::Class_MetaDataParams)
};
void UToolCallAsyncResultVoid::StaticRegisterNativesUToolCallAsyncResultVoid()
{
	UClass* Class = UToolCallAsyncResultVoid::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UToolCallAsyncResultVoid_Statics::Funcs));
}
UClass* Z_Construct_UClass_UToolCallAsyncResultVoid()
{
	if (!Z_Registration_Info_UClass_UToolCallAsyncResultVoid.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UToolCallAsyncResultVoid.OuterSingleton, Z_Construct_UClass_UToolCallAsyncResultVoid_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UToolCallAsyncResultVoid.OuterSingleton;
}
UToolCallAsyncResultVoid::UToolCallAsyncResultVoid(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UToolCallAsyncResultVoid);
UToolCallAsyncResultVoid::~UToolCallAsyncResultVoid() {}
// ********** End Class UToolCallAsyncResultVoid ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultVoid_h__Script_ToolsetRegistry_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UToolCallAsyncResultVoid, UToolCallAsyncResultVoid::StaticClass, TEXT("UToolCallAsyncResultVoid"), &Z_Registration_Info_UClass_UToolCallAsyncResultVoid, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UToolCallAsyncResultVoid), 919248651U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultVoid_h__Script_ToolsetRegistry_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultVoid_h__Script_ToolsetRegistry_3033804846{
	TEXT("/Script/ToolsetRegistry"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultVoid_h__Script_ToolsetRegistry_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultVoid_h__Script_ToolsetRegistry_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
