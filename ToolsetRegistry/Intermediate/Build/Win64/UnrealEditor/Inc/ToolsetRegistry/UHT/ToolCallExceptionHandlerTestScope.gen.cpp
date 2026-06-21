// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ToolsetRegistry/ToolCallExceptionHandlerTestScope.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeToolCallExceptionHandlerTestScope() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolCallExceptionHandlerTestScope();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolCallExceptionHandlerTestScope_NoRegister();
UPackage* Z_Construct_UPackage__Script_ToolsetRegistry();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UToolCallExceptionHandlerTestScope Function CallFunctionInternal *********
struct Z_Construct_UFunction_UToolCallExceptionHandlerTestScope_CallFunctionInternal_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Calls FunctionToCall if set.\n" },
#endif
		{ "ModuleRelativePath", "Private/ToolsetRegistry/ToolCallExceptionHandlerTestScope.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Calls FunctionToCall if set." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function CallFunctionInternal constinit property declarations ******************
// ********** End Function CallFunctionInternal constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UToolCallExceptionHandlerTestScope_CallFunctionInternal_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UToolCallExceptionHandlerTestScope, nullptr, "CallFunctionInternal", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolCallExceptionHandlerTestScope_CallFunctionInternal_Statics::Function_MetaDataParams), Z_Construct_UFunction_UToolCallExceptionHandlerTestScope_CallFunctionInternal_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UToolCallExceptionHandlerTestScope_CallFunctionInternal()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UToolCallExceptionHandlerTestScope_CallFunctionInternal_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UToolCallExceptionHandlerTestScope::execCallFunctionInternal)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CallFunctionInternal();
	P_NATIVE_END;
}
// ********** End Class UToolCallExceptionHandlerTestScope Function CallFunctionInternal ***********

// ********** Begin Class UToolCallExceptionHandlerTestScope ***************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UToolCallExceptionHandlerTestScope;
UClass* UToolCallExceptionHandlerTestScope::GetPrivateStaticClass()
{
	using TClass = UToolCallExceptionHandlerTestScope;
	if (!Z_Registration_Info_UClass_UToolCallExceptionHandlerTestScope.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ToolCallExceptionHandlerTestScope"),
			Z_Registration_Info_UClass_UToolCallExceptionHandlerTestScope.InnerSingleton,
			StaticRegisterNativesUToolCallExceptionHandlerTestScope,
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
	return Z_Registration_Info_UClass_UToolCallExceptionHandlerTestScope.InnerSingleton;
}
UClass* Z_Construct_UClass_UToolCallExceptionHandlerTestScope_NoRegister()
{
	return UToolCallExceptionHandlerTestScope::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UToolCallExceptionHandlerTestScope_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Simplifies testing Blueprint toolsets that raise errors caught by FToolCallExceptionHandler.\n// NOTE: This is tested by ToolCallExceptionHandlerTest.cpp.\n" },
#endif
		{ "IncludePath", "ToolsetRegistry/ToolCallExceptionHandlerTestScope.h" },
		{ "ModuleRelativePath", "Private/ToolsetRegistry/ToolCallExceptionHandlerTestScope.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simplifies testing Blueprint toolsets that raise errors caught by FToolCallExceptionHandler.\nNOTE: This is tested by ToolCallExceptionHandlerTest.cpp." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UToolCallExceptionHandlerTestScope constinit property declarations *******
// ********** End Class UToolCallExceptionHandlerTestScope constinit property declarations *********
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CallFunctionInternal"), .Pointer = &UToolCallExceptionHandlerTestScope::execCallFunctionInternal },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UToolCallExceptionHandlerTestScope_CallFunctionInternal, "CallFunctionInternal" }, // 3714761789
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UToolCallExceptionHandlerTestScope>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UToolCallExceptionHandlerTestScope_Statics
UObject* (*const Z_Construct_UClass_UToolCallExceptionHandlerTestScope_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_ToolsetRegistry,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UToolCallExceptionHandlerTestScope_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UToolCallExceptionHandlerTestScope_Statics::ClassParams = {
	&UToolCallExceptionHandlerTestScope::StaticClass,
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
	0x040000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UToolCallExceptionHandlerTestScope_Statics::Class_MetaDataParams), Z_Construct_UClass_UToolCallExceptionHandlerTestScope_Statics::Class_MetaDataParams)
};
void UToolCallExceptionHandlerTestScope::StaticRegisterNativesUToolCallExceptionHandlerTestScope()
{
	UClass* Class = UToolCallExceptionHandlerTestScope::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UToolCallExceptionHandlerTestScope_Statics::Funcs));
}
UClass* Z_Construct_UClass_UToolCallExceptionHandlerTestScope()
{
	if (!Z_Registration_Info_UClass_UToolCallExceptionHandlerTestScope.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UToolCallExceptionHandlerTestScope.OuterSingleton, Z_Construct_UClass_UToolCallExceptionHandlerTestScope_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UToolCallExceptionHandlerTestScope.OuterSingleton;
}
UToolCallExceptionHandlerTestScope::UToolCallExceptionHandlerTestScope(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UToolCallExceptionHandlerTestScope);
UToolCallExceptionHandlerTestScope::~UToolCallExceptionHandlerTestScope() {}
// ********** End Class UToolCallExceptionHandlerTestScope *****************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Private_ToolsetRegistry_ToolCallExceptionHandlerTestScope_h__Script_ToolsetRegistry_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UToolCallExceptionHandlerTestScope, UToolCallExceptionHandlerTestScope::StaticClass, TEXT("UToolCallExceptionHandlerTestScope"), &Z_Registration_Info_UClass_UToolCallExceptionHandlerTestScope, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UToolCallExceptionHandlerTestScope), 52715160U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Private_ToolsetRegistry_ToolCallExceptionHandlerTestScope_h__Script_ToolsetRegistry_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Private_ToolsetRegistry_ToolCallExceptionHandlerTestScope_h__Script_ToolsetRegistry_3992350478{
	TEXT("/Script/ToolsetRegistry"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Private_ToolsetRegistry_ToolCallExceptionHandlerTestScope_h__Script_ToolsetRegistry_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Private_ToolsetRegistry_ToolCallExceptionHandlerTestScope_h__Script_ToolsetRegistry_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
