// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ToolsetRegistry/ToolCallAsyncResultString.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeToolCallAsyncResultString() {}

// ********** Begin Cross Module References ********************************************************
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolCallAsyncResult();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolCallAsyncResultString();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolCallAsyncResultString_NoRegister();
UPackage* Z_Construct_UPackage__Script_ToolsetRegistry();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UToolCallAsyncResultString Function SetValue *****************************
struct Z_Construct_UFunction_UToolCallAsyncResultString_SetValue_Statics
{
	struct ToolCallAsyncResultString_eventSetValue_Parms
	{
		FString InValue;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ToolsetRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Set the result.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolCallAsyncResultString.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set the result." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetValue constinit property declarations ******************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InValue;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetValue constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetValue Property Definitions *****************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UToolCallAsyncResultString_SetValue_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ToolCallAsyncResultString_eventSetValue_Parms, InValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InValue_MetaData), NewProp_InValue_MetaData) };
void Z_Construct_UFunction_UToolCallAsyncResultString_SetValue_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ToolCallAsyncResultString_eventSetValue_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UToolCallAsyncResultString_SetValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ToolCallAsyncResultString_eventSetValue_Parms), &Z_Construct_UFunction_UToolCallAsyncResultString_SetValue_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UToolCallAsyncResultString_SetValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolCallAsyncResultString_SetValue_Statics::NewProp_InValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolCallAsyncResultString_SetValue_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolCallAsyncResultString_SetValue_Statics::PropPointers) < 2048);
// ********** End Function SetValue Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UToolCallAsyncResultString_SetValue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UToolCallAsyncResultString, nullptr, "SetValue", 	Z_Construct_UFunction_UToolCallAsyncResultString_SetValue_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UToolCallAsyncResultString_SetValue_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UToolCallAsyncResultString_SetValue_Statics::ToolCallAsyncResultString_eventSetValue_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolCallAsyncResultString_SetValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UToolCallAsyncResultString_SetValue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UToolCallAsyncResultString_SetValue_Statics::ToolCallAsyncResultString_eventSetValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UToolCallAsyncResultString_SetValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UToolCallAsyncResultString_SetValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UToolCallAsyncResultString::execSetValue)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SetValue(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UToolCallAsyncResultString Function SetValue *******************************

// ********** Begin Class UToolCallAsyncResultString ***********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UToolCallAsyncResultString;
UClass* UToolCallAsyncResultString::GetPrivateStaticClass()
{
	using TClass = UToolCallAsyncResultString;
	if (!Z_Registration_Info_UClass_UToolCallAsyncResultString.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ToolCallAsyncResultString"),
			Z_Registration_Info_UClass_UToolCallAsyncResultString.InnerSingleton,
			StaticRegisterNativesUToolCallAsyncResultString,
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
	return Z_Registration_Info_UClass_UToolCallAsyncResultString.InnerSingleton;
}
UClass* Z_Construct_UClass_UToolCallAsyncResultString_NoRegister()
{
	return UToolCallAsyncResultString::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UToolCallAsyncResultString_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Async tool call result that completes with a string.\n" },
#endif
		{ "IncludePath", "ToolsetRegistry/ToolCallAsyncResultString.h" },
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolCallAsyncResultString.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Async tool call result that completes with a string." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "Category", "ToolsetRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Value of the result.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolCallAsyncResultString.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Value of the result." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UToolCallAsyncResultString constinit property declarations ***************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UToolCallAsyncResultString constinit property declarations *****************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("SetValue"), .Pointer = &UToolCallAsyncResultString::execSetValue },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UToolCallAsyncResultString_SetValue, "SetValue" }, // 3792499108
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UToolCallAsyncResultString>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UToolCallAsyncResultString_Statics

// ********** Begin Class UToolCallAsyncResultString Property Definitions **************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UToolCallAsyncResultString_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UToolCallAsyncResultString, Value), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UToolCallAsyncResultString_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UToolCallAsyncResultString_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UToolCallAsyncResultString_Statics::PropPointers) < 2048);
// ********** End Class UToolCallAsyncResultString Property Definitions ****************************
UObject* (*const Z_Construct_UClass_UToolCallAsyncResultString_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UToolCallAsyncResult,
	(UObject* (*)())Z_Construct_UPackage__Script_ToolsetRegistry,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UToolCallAsyncResultString_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UToolCallAsyncResultString_Statics::ClassParams = {
	&UToolCallAsyncResultString::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UToolCallAsyncResultString_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UToolCallAsyncResultString_Statics::PropPointers),
	0,
	0x008000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UToolCallAsyncResultString_Statics::Class_MetaDataParams), Z_Construct_UClass_UToolCallAsyncResultString_Statics::Class_MetaDataParams)
};
void UToolCallAsyncResultString::StaticRegisterNativesUToolCallAsyncResultString()
{
	UClass* Class = UToolCallAsyncResultString::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UToolCallAsyncResultString_Statics::Funcs));
}
UClass* Z_Construct_UClass_UToolCallAsyncResultString()
{
	if (!Z_Registration_Info_UClass_UToolCallAsyncResultString.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UToolCallAsyncResultString.OuterSingleton, Z_Construct_UClass_UToolCallAsyncResultString_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UToolCallAsyncResultString.OuterSingleton;
}
UToolCallAsyncResultString::UToolCallAsyncResultString(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UToolCallAsyncResultString);
UToolCallAsyncResultString::~UToolCallAsyncResultString() {}
// ********** End Class UToolCallAsyncResultString *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultString_h__Script_ToolsetRegistry_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UToolCallAsyncResultString, UToolCallAsyncResultString::StaticClass, TEXT("UToolCallAsyncResultString"), &Z_Registration_Info_UClass_UToolCallAsyncResultString, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UToolCallAsyncResultString), 1450093445U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultString_h__Script_ToolsetRegistry_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultString_h__Script_ToolsetRegistry_3374810151{
	TEXT("/Script/ToolsetRegistry"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultString_h__Script_ToolsetRegistry_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultString_h__Script_ToolsetRegistry_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
