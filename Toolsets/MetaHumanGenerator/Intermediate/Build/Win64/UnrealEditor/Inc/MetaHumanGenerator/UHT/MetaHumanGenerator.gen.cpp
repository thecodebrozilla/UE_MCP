// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MetaHumanGenerator.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeMetaHumanGenerator() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
METAHUMANCHARACTER_API UClass* Z_Construct_UClass_UMetaHumanCharacter_NoRegister();
METAHUMANGENERATOR_API UClass* Z_Construct_UClass_UMetaHumanGeneratorSubsystemWrapper();
METAHUMANGENERATOR_API UClass* Z_Construct_UClass_UMetaHumanGeneratorSubsystemWrapper_NoRegister();
UPackage* Z_Construct_UPackage__Script_MetaHumanGenerator();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UMetaHumanGeneratorSubsystemWrapper Function ResetNeckToBody *************
struct Z_Construct_UFunction_UMetaHumanGeneratorSubsystemWrapper_ResetNeckToBody_Statics
{
	struct MetaHumanGeneratorSubsystemWrapper_eventResetNeckToBody_Parms
	{
		UMetaHumanCharacter* InCharacter;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MetaHumanGenerator" },
		{ "ModuleRelativePath", "Public/MetaHumanGenerator.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ResetNeckToBody constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InCharacter;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ResetNeckToBody constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ResetNeckToBody Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMetaHumanGeneratorSubsystemWrapper_ResetNeckToBody_Statics::NewProp_InCharacter = { "InCharacter", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MetaHumanGeneratorSubsystemWrapper_eventResetNeckToBody_Parms, InCharacter), Z_Construct_UClass_UMetaHumanCharacter_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMetaHumanGeneratorSubsystemWrapper_ResetNeckToBody_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaHumanGeneratorSubsystemWrapper_ResetNeckToBody_Statics::NewProp_InCharacter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaHumanGeneratorSubsystemWrapper_ResetNeckToBody_Statics::PropPointers) < 2048);
// ********** End Function ResetNeckToBody Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMetaHumanGeneratorSubsystemWrapper_ResetNeckToBody_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UMetaHumanGeneratorSubsystemWrapper, nullptr, "ResetNeckToBody", 	Z_Construct_UFunction_UMetaHumanGeneratorSubsystemWrapper_ResetNeckToBody_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaHumanGeneratorSubsystemWrapper_ResetNeckToBody_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UMetaHumanGeneratorSubsystemWrapper_ResetNeckToBody_Statics::MetaHumanGeneratorSubsystemWrapper_eventResetNeckToBody_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaHumanGeneratorSubsystemWrapper_ResetNeckToBody_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMetaHumanGeneratorSubsystemWrapper_ResetNeckToBody_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UMetaHumanGeneratorSubsystemWrapper_ResetNeckToBody_Statics::MetaHumanGeneratorSubsystemWrapper_eventResetNeckToBody_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMetaHumanGeneratorSubsystemWrapper_ResetNeckToBody()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMetaHumanGeneratorSubsystemWrapper_ResetNeckToBody_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMetaHumanGeneratorSubsystemWrapper::execResetNeckToBody)
{
	P_GET_OBJECT(UMetaHumanCharacter,Z_Param_InCharacter);
	P_FINISH;
	P_NATIVE_BEGIN;
	UMetaHumanGeneratorSubsystemWrapper::ResetNeckToBody(Z_Param_InCharacter);
	P_NATIVE_END;
}
// ********** End Class UMetaHumanGeneratorSubsystemWrapper Function ResetNeckToBody ***************

// ********** Begin Class UMetaHumanGeneratorSubsystemWrapper **************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UMetaHumanGeneratorSubsystemWrapper;
UClass* UMetaHumanGeneratorSubsystemWrapper::GetPrivateStaticClass()
{
	using TClass = UMetaHumanGeneratorSubsystemWrapper;
	if (!Z_Registration_Info_UClass_UMetaHumanGeneratorSubsystemWrapper.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("MetaHumanGeneratorSubsystemWrapper"),
			Z_Registration_Info_UClass_UMetaHumanGeneratorSubsystemWrapper.InnerSingleton,
			StaticRegisterNativesUMetaHumanGeneratorSubsystemWrapper,
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
	return Z_Registration_Info_UClass_UMetaHumanGeneratorSubsystemWrapper.InnerSingleton;
}
UClass* Z_Construct_UClass_UMetaHumanGeneratorSubsystemWrapper_NoRegister()
{
	return UMetaHumanGeneratorSubsystemWrapper::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UMetaHumanGeneratorSubsystemWrapper_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "MetaHumanGenerator.h" },
		{ "ModuleRelativePath", "Public/MetaHumanGenerator.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UMetaHumanGeneratorSubsystemWrapper constinit property declarations ******
// ********** End Class UMetaHumanGeneratorSubsystemWrapper constinit property declarations ********
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ResetNeckToBody"), .Pointer = &UMetaHumanGeneratorSubsystemWrapper::execResetNeckToBody },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMetaHumanGeneratorSubsystemWrapper_ResetNeckToBody, "ResetNeckToBody" }, // 2366358311
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMetaHumanGeneratorSubsystemWrapper>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UMetaHumanGeneratorSubsystemWrapper_Statics
UObject* (*const Z_Construct_UClass_UMetaHumanGeneratorSubsystemWrapper_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_MetaHumanGenerator,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMetaHumanGeneratorSubsystemWrapper_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMetaHumanGeneratorSubsystemWrapper_Statics::ClassParams = {
	&UMetaHumanGeneratorSubsystemWrapper::StaticClass,
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
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMetaHumanGeneratorSubsystemWrapper_Statics::Class_MetaDataParams), Z_Construct_UClass_UMetaHumanGeneratorSubsystemWrapper_Statics::Class_MetaDataParams)
};
void UMetaHumanGeneratorSubsystemWrapper::StaticRegisterNativesUMetaHumanGeneratorSubsystemWrapper()
{
	UClass* Class = UMetaHumanGeneratorSubsystemWrapper::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UMetaHumanGeneratorSubsystemWrapper_Statics::Funcs));
}
UClass* Z_Construct_UClass_UMetaHumanGeneratorSubsystemWrapper()
{
	if (!Z_Registration_Info_UClass_UMetaHumanGeneratorSubsystemWrapper.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMetaHumanGeneratorSubsystemWrapper.OuterSingleton, Z_Construct_UClass_UMetaHumanGeneratorSubsystemWrapper_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMetaHumanGeneratorSubsystemWrapper.OuterSingleton;
}
UMetaHumanGeneratorSubsystemWrapper::UMetaHumanGeneratorSubsystemWrapper(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UMetaHumanGeneratorSubsystemWrapper);
UMetaHumanGeneratorSubsystemWrapper::~UMetaHumanGeneratorSubsystemWrapper() {}
// ********** End Class UMetaHumanGeneratorSubsystemWrapper ****************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_MetaHumanGenerator_Source_Public_MetaHumanGenerator_h__Script_MetaHumanGenerator_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMetaHumanGeneratorSubsystemWrapper, UMetaHumanGeneratorSubsystemWrapper::StaticClass, TEXT("UMetaHumanGeneratorSubsystemWrapper"), &Z_Registration_Info_UClass_UMetaHumanGeneratorSubsystemWrapper, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMetaHumanGeneratorSubsystemWrapper), 2692310048U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_MetaHumanGenerator_Source_Public_MetaHumanGenerator_h__Script_MetaHumanGenerator_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_MetaHumanGenerator_Source_Public_MetaHumanGenerator_h__Script_MetaHumanGenerator_2290305636{
	TEXT("/Script/MetaHumanGenerator"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_MetaHumanGenerator_Source_Public_MetaHumanGenerator_h__Script_MetaHumanGenerator_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_MetaHumanGenerator_Source_Public_MetaHumanGenerator_h__Script_MetaHumanGenerator_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
