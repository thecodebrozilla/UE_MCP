// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ToolsetRegistry/ToolCallAsyncResultImage.h"
#include "ToolsetRegistry/ToolsetImage.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeToolCallAsyncResultImage() {}

// ********** Begin Cross Module References ********************************************************
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolCallAsyncResult();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolCallAsyncResultImage();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolCallAsyncResultImage_NoRegister();
TOOLSETREGISTRY_API UScriptStruct* Z_Construct_UScriptStruct_FToolsetImage();
UPackage* Z_Construct_UPackage__Script_ToolsetRegistry();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UToolCallAsyncResultImage Function SetValue ******************************
struct Z_Construct_UFunction_UToolCallAsyncResultImage_SetValue_Statics
{
	struct ToolCallAsyncResultImage_eventSetValue_Parms
	{
		FToolsetImage InValue;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ToolsetRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Set the result.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolCallAsyncResultImage.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set the result." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetValue constinit property declarations ******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetValue constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetValue Property Definitions *****************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UToolCallAsyncResultImage_SetValue_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ToolCallAsyncResultImage_eventSetValue_Parms, InValue), Z_Construct_UScriptStruct_FToolsetImage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InValue_MetaData), NewProp_InValue_MetaData) }; // 1290813077
void Z_Construct_UFunction_UToolCallAsyncResultImage_SetValue_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ToolCallAsyncResultImage_eventSetValue_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UToolCallAsyncResultImage_SetValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ToolCallAsyncResultImage_eventSetValue_Parms), &Z_Construct_UFunction_UToolCallAsyncResultImage_SetValue_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UToolCallAsyncResultImage_SetValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolCallAsyncResultImage_SetValue_Statics::NewProp_InValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolCallAsyncResultImage_SetValue_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolCallAsyncResultImage_SetValue_Statics::PropPointers) < 2048);
// ********** End Function SetValue Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UToolCallAsyncResultImage_SetValue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UToolCallAsyncResultImage, nullptr, "SetValue", 	Z_Construct_UFunction_UToolCallAsyncResultImage_SetValue_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UToolCallAsyncResultImage_SetValue_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UToolCallAsyncResultImage_SetValue_Statics::ToolCallAsyncResultImage_eventSetValue_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolCallAsyncResultImage_SetValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UToolCallAsyncResultImage_SetValue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UToolCallAsyncResultImage_SetValue_Statics::ToolCallAsyncResultImage_eventSetValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UToolCallAsyncResultImage_SetValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UToolCallAsyncResultImage_SetValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UToolCallAsyncResultImage::execSetValue)
{
	P_GET_STRUCT_REF(FToolsetImage,Z_Param_Out_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SetValue(Z_Param_Out_InValue);
	P_NATIVE_END;
}
// ********** End Class UToolCallAsyncResultImage Function SetValue ********************************

// ********** Begin Class UToolCallAsyncResultImage ************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UToolCallAsyncResultImage;
UClass* UToolCallAsyncResultImage::GetPrivateStaticClass()
{
	using TClass = UToolCallAsyncResultImage;
	if (!Z_Registration_Info_UClass_UToolCallAsyncResultImage.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ToolCallAsyncResultImage"),
			Z_Registration_Info_UClass_UToolCallAsyncResultImage.InnerSingleton,
			StaticRegisterNativesUToolCallAsyncResultImage,
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
	return Z_Registration_Info_UClass_UToolCallAsyncResultImage.InnerSingleton;
}
UClass* Z_Construct_UClass_UToolCallAsyncResultImage_NoRegister()
{
	return UToolCallAsyncResultImage::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UToolCallAsyncResultImage_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Async tool call result that completes with a ToolsetImage.\n" },
#endif
		{ "IncludePath", "ToolsetRegistry/ToolCallAsyncResultImage.h" },
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolCallAsyncResultImage.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Async tool call result that completes with a ToolsetImage." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "Category", "ToolsetRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Value of the result.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolCallAsyncResultImage.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Value of the result." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UToolCallAsyncResultImage constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UToolCallAsyncResultImage constinit property declarations ******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("SetValue"), .Pointer = &UToolCallAsyncResultImage::execSetValue },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UToolCallAsyncResultImage_SetValue, "SetValue" }, // 2935487043
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UToolCallAsyncResultImage>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UToolCallAsyncResultImage_Statics

// ********** Begin Class UToolCallAsyncResultImage Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UToolCallAsyncResultImage_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UToolCallAsyncResultImage, Value), Z_Construct_UScriptStruct_FToolsetImage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) }; // 1290813077
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UToolCallAsyncResultImage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UToolCallAsyncResultImage_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UToolCallAsyncResultImage_Statics::PropPointers) < 2048);
// ********** End Class UToolCallAsyncResultImage Property Definitions *****************************
UObject* (*const Z_Construct_UClass_UToolCallAsyncResultImage_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UToolCallAsyncResult,
	(UObject* (*)())Z_Construct_UPackage__Script_ToolsetRegistry,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UToolCallAsyncResultImage_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UToolCallAsyncResultImage_Statics::ClassParams = {
	&UToolCallAsyncResultImage::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UToolCallAsyncResultImage_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UToolCallAsyncResultImage_Statics::PropPointers),
	0,
	0x008000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UToolCallAsyncResultImage_Statics::Class_MetaDataParams), Z_Construct_UClass_UToolCallAsyncResultImage_Statics::Class_MetaDataParams)
};
void UToolCallAsyncResultImage::StaticRegisterNativesUToolCallAsyncResultImage()
{
	UClass* Class = UToolCallAsyncResultImage::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UToolCallAsyncResultImage_Statics::Funcs));
}
UClass* Z_Construct_UClass_UToolCallAsyncResultImage()
{
	if (!Z_Registration_Info_UClass_UToolCallAsyncResultImage.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UToolCallAsyncResultImage.OuterSingleton, Z_Construct_UClass_UToolCallAsyncResultImage_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UToolCallAsyncResultImage.OuterSingleton;
}
UToolCallAsyncResultImage::UToolCallAsyncResultImage(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UToolCallAsyncResultImage);
UToolCallAsyncResultImage::~UToolCallAsyncResultImage() {}
// ********** End Class UToolCallAsyncResultImage **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultImage_h__Script_ToolsetRegistry_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UToolCallAsyncResultImage, UToolCallAsyncResultImage::StaticClass, TEXT("UToolCallAsyncResultImage"), &Z_Registration_Info_UClass_UToolCallAsyncResultImage, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UToolCallAsyncResultImage), 2025470145U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultImage_h__Script_ToolsetRegistry_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultImage_h__Script_ToolsetRegistry_4257064541{
	TEXT("/Script/ToolsetRegistry"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultImage_h__Script_ToolsetRegistry_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResultImage_h__Script_ToolsetRegistry_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
