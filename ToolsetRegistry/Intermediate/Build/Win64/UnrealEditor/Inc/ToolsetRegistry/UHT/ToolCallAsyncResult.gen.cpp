// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ToolsetRegistry/ToolCallAsyncResult.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeToolCallAsyncResult() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolCallAsyncResult();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolCallAsyncResult_NoRegister();
TOOLSETREGISTRY_API UFunction* Z_Construct_UDelegateFunction_ToolsetRegistry_ToolCallAsyncResultCompleted__DelegateSignature();
UPackage* Z_Construct_UPackage__Script_ToolsetRegistry();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FToolCallAsyncResultCompleted *****************************************
struct Z_Construct_UDelegateFunction_ToolsetRegistry_ToolCallAsyncResultCompleted__DelegateSignature_Statics
{
	struct _Script_ToolsetRegistry_eventToolCallAsyncResultCompleted_Parms
	{
		UToolCallAsyncResult* Result;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Notified when an async tool call completes successfully or with an error.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolCallAsyncResult.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Notified when an async tool call completes successfully or with an error." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Delegate FToolCallAsyncResultCompleted constinit property declarations *********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Result;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FToolCallAsyncResultCompleted constinit property declarations ***********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FToolCallAsyncResultCompleted Property Definitions ********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_ToolsetRegistry_ToolCallAsyncResultCompleted__DelegateSignature_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ToolsetRegistry_eventToolCallAsyncResultCompleted_Parms, Result), Z_Construct_UClass_UToolCallAsyncResult_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ToolsetRegistry_ToolCallAsyncResultCompleted__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ToolsetRegistry_ToolCallAsyncResultCompleted__DelegateSignature_Statics::NewProp_Result,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ToolsetRegistry_ToolCallAsyncResultCompleted__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FToolCallAsyncResultCompleted Property Definitions **********************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_ToolsetRegistry_ToolCallAsyncResultCompleted__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_ToolsetRegistry, nullptr, "ToolCallAsyncResultCompleted__DelegateSignature", 	Z_Construct_UDelegateFunction_ToolsetRegistry_ToolCallAsyncResultCompleted__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ToolsetRegistry_ToolCallAsyncResultCompleted__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_ToolsetRegistry_ToolCallAsyncResultCompleted__DelegateSignature_Statics::_Script_ToolsetRegistry_eventToolCallAsyncResultCompleted_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ToolsetRegistry_ToolCallAsyncResultCompleted__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ToolsetRegistry_ToolCallAsyncResultCompleted__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_ToolsetRegistry_ToolCallAsyncResultCompleted__DelegateSignature_Statics::_Script_ToolsetRegistry_eventToolCallAsyncResultCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ToolsetRegistry_ToolCallAsyncResultCompleted__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ToolsetRegistry_ToolCallAsyncResultCompleted__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FToolCallAsyncResultCompleted_DelegateWrapper(const FMulticastScriptDelegate& ToolCallAsyncResultCompleted, UToolCallAsyncResult* Result)
{
	struct _Script_ToolsetRegistry_eventToolCallAsyncResultCompleted_Parms
	{
		UToolCallAsyncResult* Result;
	};
	_Script_ToolsetRegistry_eventToolCallAsyncResultCompleted_Parms Parms;
	Parms.Result=Result;
	ToolCallAsyncResultCompleted.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FToolCallAsyncResultCompleted *******************************************

// ********** Begin Class UToolCallAsyncResult Function BroadcastOnCompletedIfComplete *************
struct Z_Construct_UFunction_UToolCallAsyncResult_BroadcastOnCompletedIfComplete_Statics
{
	struct ToolCallAsyncResult_eventBroadcastOnCompletedIfComplete_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ToolsetRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Broadcast to subscribers of the OnCompleted delegate if the result is already complete.\n///\n/// This *must* be called after subscribing to OnCompleted to ensure an event receives a\n/// notification when the result is already complete.\n///\n/// @returns true if the result was complete, false otherwise.\n///\n/// @note This is thread safe, OnCompleted will always be signaled on the main thread.\n///\n/// @remark Ideally we would override subscription methods for the OnCompleted delegate\n/// and notify subscribers there but unfortunately that isn't possible.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolCallAsyncResult.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Broadcast to subscribers of the OnCompleted delegate if the result is already complete.\n\nThis *must* be called after subscribing to OnCompleted to ensure an event receives a\nnotification when the result is already complete.\n\n@returns true if the result was complete, false otherwise.\n\n@note This is thread safe, OnCompleted will always be signaled on the main thread.\n\n@remark Ideally we would override subscription methods for the OnCompleted delegate\nand notify subscribers there but unfortunately that isn't possible." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function BroadcastOnCompletedIfComplete constinit property declarations ********
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BroadcastOnCompletedIfComplete constinit property declarations **********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BroadcastOnCompletedIfComplete Property Definitions *******************
void Z_Construct_UFunction_UToolCallAsyncResult_BroadcastOnCompletedIfComplete_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ToolCallAsyncResult_eventBroadcastOnCompletedIfComplete_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UToolCallAsyncResult_BroadcastOnCompletedIfComplete_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ToolCallAsyncResult_eventBroadcastOnCompletedIfComplete_Parms), &Z_Construct_UFunction_UToolCallAsyncResult_BroadcastOnCompletedIfComplete_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UToolCallAsyncResult_BroadcastOnCompletedIfComplete_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolCallAsyncResult_BroadcastOnCompletedIfComplete_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolCallAsyncResult_BroadcastOnCompletedIfComplete_Statics::PropPointers) < 2048);
// ********** End Function BroadcastOnCompletedIfComplete Property Definitions *********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UToolCallAsyncResult_BroadcastOnCompletedIfComplete_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UToolCallAsyncResult, nullptr, "BroadcastOnCompletedIfComplete", 	Z_Construct_UFunction_UToolCallAsyncResult_BroadcastOnCompletedIfComplete_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UToolCallAsyncResult_BroadcastOnCompletedIfComplete_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UToolCallAsyncResult_BroadcastOnCompletedIfComplete_Statics::ToolCallAsyncResult_eventBroadcastOnCompletedIfComplete_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolCallAsyncResult_BroadcastOnCompletedIfComplete_Statics::Function_MetaDataParams), Z_Construct_UFunction_UToolCallAsyncResult_BroadcastOnCompletedIfComplete_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UToolCallAsyncResult_BroadcastOnCompletedIfComplete_Statics::ToolCallAsyncResult_eventBroadcastOnCompletedIfComplete_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UToolCallAsyncResult_BroadcastOnCompletedIfComplete()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UToolCallAsyncResult_BroadcastOnCompletedIfComplete_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UToolCallAsyncResult::execBroadcastOnCompletedIfComplete)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->BroadcastOnCompletedIfComplete();
	P_NATIVE_END;
}
// ********** End Class UToolCallAsyncResult Function BroadcastOnCompletedIfComplete ***************

// ********** Begin Class UToolCallAsyncResult Function GetValueAsJsonString ***********************
struct Z_Construct_UFunction_UToolCallAsyncResult_GetValueAsJsonString_Statics
{
	struct ToolCallAsyncResult_eventGetValueAsJsonString_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ToolsetRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Get the JSON representation of the Value. If the associated tool call is not complete or an\n/// error occurred, this returns an empty string.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolCallAsyncResult.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the JSON representation of the Value. If the associated tool call is not complete or an\nerror occurred, this returns an empty string." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetValueAsJsonString constinit property declarations ******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetValueAsJsonString constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetValueAsJsonString Property Definitions *****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UToolCallAsyncResult_GetValueAsJsonString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ToolCallAsyncResult_eventGetValueAsJsonString_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UToolCallAsyncResult_GetValueAsJsonString_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolCallAsyncResult_GetValueAsJsonString_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolCallAsyncResult_GetValueAsJsonString_Statics::PropPointers) < 2048);
// ********** End Function GetValueAsJsonString Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UToolCallAsyncResult_GetValueAsJsonString_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UToolCallAsyncResult, nullptr, "GetValueAsJsonString", 	Z_Construct_UFunction_UToolCallAsyncResult_GetValueAsJsonString_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UToolCallAsyncResult_GetValueAsJsonString_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UToolCallAsyncResult_GetValueAsJsonString_Statics::ToolCallAsyncResult_eventGetValueAsJsonString_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolCallAsyncResult_GetValueAsJsonString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UToolCallAsyncResult_GetValueAsJsonString_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UToolCallAsyncResult_GetValueAsJsonString_Statics::ToolCallAsyncResult_eventGetValueAsJsonString_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UToolCallAsyncResult_GetValueAsJsonString()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UToolCallAsyncResult_GetValueAsJsonString_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UToolCallAsyncResult::execGetValueAsJsonString)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetValueAsJsonString();
	P_NATIVE_END;
}
// ********** End Class UToolCallAsyncResult Function GetValueAsJsonString *************************

// ********** Begin Class UToolCallAsyncResult Function SetError ***********************************
struct Z_Construct_UFunction_UToolCallAsyncResult_SetError_Statics
{
	struct ToolCallAsyncResult_eventSetError_Parms
	{
		FString InError;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ToolsetRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Complete this result with an error and notify listeners of OnCompleted.\n///\n/// @returns true the result was completed with the error, false otherwise.\n///\n/// @note This is thread safe, the Error property will always be updated and OnCompleted\n/// will be signaled on the main thread.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolCallAsyncResult.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Complete this result with an error and notify listeners of OnCompleted.\n\n@returns true the result was completed with the error, false otherwise.\n\n@note This is thread safe, the Error property will always be updated and OnCompleted\nwill be signaled on the main thread." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InError_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetError constinit property declarations ******************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InError;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetError constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetError Property Definitions *****************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UToolCallAsyncResult_SetError_Statics::NewProp_InError = { "InError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ToolCallAsyncResult_eventSetError_Parms, InError), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InError_MetaData), NewProp_InError_MetaData) };
void Z_Construct_UFunction_UToolCallAsyncResult_SetError_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ToolCallAsyncResult_eventSetError_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UToolCallAsyncResult_SetError_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ToolCallAsyncResult_eventSetError_Parms), &Z_Construct_UFunction_UToolCallAsyncResult_SetError_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UToolCallAsyncResult_SetError_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolCallAsyncResult_SetError_Statics::NewProp_InError,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolCallAsyncResult_SetError_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolCallAsyncResult_SetError_Statics::PropPointers) < 2048);
// ********** End Function SetError Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UToolCallAsyncResult_SetError_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UToolCallAsyncResult, nullptr, "SetError", 	Z_Construct_UFunction_UToolCallAsyncResult_SetError_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UToolCallAsyncResult_SetError_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UToolCallAsyncResult_SetError_Statics::ToolCallAsyncResult_eventSetError_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolCallAsyncResult_SetError_Statics::Function_MetaDataParams), Z_Construct_UFunction_UToolCallAsyncResult_SetError_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UToolCallAsyncResult_SetError_Statics::ToolCallAsyncResult_eventSetError_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UToolCallAsyncResult_SetError()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UToolCallAsyncResult_SetError_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UToolCallAsyncResult::execSetError)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InError);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SetError(Z_Param_InError);
	P_NATIVE_END;
}
// ********** End Class UToolCallAsyncResult Function SetError *************************************

// ********** Begin Class UToolCallAsyncResult *****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UToolCallAsyncResult;
UClass* UToolCallAsyncResult::GetPrivateStaticClass()
{
	using TClass = UToolCallAsyncResult;
	if (!Z_Registration_Info_UClass_UToolCallAsyncResult.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ToolCallAsyncResult"),
			Z_Registration_Info_UClass_UToolCallAsyncResult.InnerSingleton,
			StaticRegisterNativesUToolCallAsyncResult,
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
	return Z_Registration_Info_UClass_UToolCallAsyncResult.InnerSingleton;
}
UClass* Z_Construct_UClass_UToolCallAsyncResult_NoRegister()
{
	return UToolCallAsyncResult::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UToolCallAsyncResult_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Base class for an asynchronous tool call result that is analogous to a promise.\n///\n/// Asynchronous tools should *not* use this base class directly, instead they should use an \n/// either define or use an existing derivative of this base class for asynchronous results.\n///\n/// Asynchronous tools return derivatives of this class to indicate a pending result.\n/// When an asynchronous tool completes its operation it should perform one of the following\n/// operations:\n/// * If successful, use MaybeBroadcastSuccessfulCompletion() from the derived class\n///   - ideally implemented in a method called `SetValue` - to notify listeners of the\n///   `OnCompleted` delegate, set bIsComplete to true and set the result's value.\n/// * If an error occurs, use SetError() to set the `Error` property, set bIsComplete to true\n///    and notify listeners of the `OnCompleted` delegate.\n///\n" },
#endif
		{ "IncludePath", "ToolsetRegistry/ToolCallAsyncResult.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolCallAsyncResult.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Base class for an asynchronous tool call result that is analogous to a promise.\n\nAsynchronous tools should *not* use this base class directly, instead they should use an\neither define or use an existing derivative of this base class for asynchronous results.\n\nAsynchronous tools return derivatives of this class to indicate a pending result.\nWhen an asynchronous tool completes its operation it should perform one of the following\noperations:\n* If successful, use MaybeBroadcastSuccessfulCompletion() from the derived class\n  - ideally implemented in a method called `SetValue` - to notify listeners of the\n  `OnCompleted` delegate, set bIsComplete to true and set the result's value.\n* If an error occurs, use SetError() to set the `Error` property, set bIsComplete to true\n   and notify listeners of the `OnCompleted` delegate." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsComplete_MetaData[] = {
		{ "Category", "ToolsetRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Whether the associated tool call is complete and the result via Value and GetValueAsJson()\n/// or Error are available to read.\n///\n/// @warning Do *not* set this from C++ instead use SetError() or SetValue() if implemented by\n/// the subclass.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolCallAsyncResult.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether the associated tool call is complete and the result via Value and GetValueAsJson()\nor Error are available to read.\n\n@warning Do *not* set this from C++ instead use SetError() or SetValue() if implemented by\nthe subclass." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCompleted_MetaData[] = {
		{ "Category", "ToolsetRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Notified when the tool call is completes successfully or with an error.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolCallAsyncResult.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Notified when the tool call is completes successfully or with an error." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Error_MetaData[] = {
		{ "Category", "ToolsetRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// If this is an non-empty string, an error occurred while executing the tool that returned\n/// this instance. An empty string indicates either no error occurred or the associated tool\n/// call is not complete.\n/// \n/// @warning Do *not* set this from C++ instead use SetError() or SetValue() if implemented by\n/// the subclass.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/ToolCallAsyncResult.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If this is an non-empty string, an error occurred while executing the tool that returned\nthis instance. An empty string indicates either no error occurred or the associated tool\ncall is not complete.\n\n@warning Do *not* set this from C++ instead use SetError() or SetValue() if implemented by\nthe subclass." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UToolCallAsyncResult constinit property declarations *********************
	static void NewProp_bIsComplete_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsComplete;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCompleted;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Error;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UToolCallAsyncResult constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("BroadcastOnCompletedIfComplete"), .Pointer = &UToolCallAsyncResult::execBroadcastOnCompletedIfComplete },
		{ .NameUTF8 = UTF8TEXT("GetValueAsJsonString"), .Pointer = &UToolCallAsyncResult::execGetValueAsJsonString },
		{ .NameUTF8 = UTF8TEXT("SetError"), .Pointer = &UToolCallAsyncResult::execSetError },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UToolCallAsyncResult_BroadcastOnCompletedIfComplete, "BroadcastOnCompletedIfComplete" }, // 4128700845
		{ &Z_Construct_UFunction_UToolCallAsyncResult_GetValueAsJsonString, "GetValueAsJsonString" }, // 1681884294
		{ &Z_Construct_UFunction_UToolCallAsyncResult_SetError, "SetError" }, // 1651253859
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UToolCallAsyncResult>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UToolCallAsyncResult_Statics

// ********** Begin Class UToolCallAsyncResult Property Definitions ********************************
void Z_Construct_UClass_UToolCallAsyncResult_Statics::NewProp_bIsComplete_SetBit(void* Obj)
{
	((UToolCallAsyncResult*)Obj)->bIsComplete = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UToolCallAsyncResult_Statics::NewProp_bIsComplete = { "bIsComplete", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UToolCallAsyncResult), &Z_Construct_UClass_UToolCallAsyncResult_Statics::NewProp_bIsComplete_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsComplete_MetaData), NewProp_bIsComplete_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UToolCallAsyncResult_Statics::NewProp_OnCompleted = { "OnCompleted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UToolCallAsyncResult, OnCompleted), Z_Construct_UDelegateFunction_ToolsetRegistry_ToolCallAsyncResultCompleted__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCompleted_MetaData), NewProp_OnCompleted_MetaData) }; // 1790884565
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UToolCallAsyncResult_Statics::NewProp_Error = { "Error", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UToolCallAsyncResult, Error), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Error_MetaData), NewProp_Error_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UToolCallAsyncResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UToolCallAsyncResult_Statics::NewProp_bIsComplete,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UToolCallAsyncResult_Statics::NewProp_OnCompleted,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UToolCallAsyncResult_Statics::NewProp_Error,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UToolCallAsyncResult_Statics::PropPointers) < 2048);
// ********** End Class UToolCallAsyncResult Property Definitions **********************************
UObject* (*const Z_Construct_UClass_UToolCallAsyncResult_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_ToolsetRegistry,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UToolCallAsyncResult_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UToolCallAsyncResult_Statics::ClassParams = {
	&UToolCallAsyncResult::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UToolCallAsyncResult_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UToolCallAsyncResult_Statics::PropPointers),
	0,
	0x008800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UToolCallAsyncResult_Statics::Class_MetaDataParams), Z_Construct_UClass_UToolCallAsyncResult_Statics::Class_MetaDataParams)
};
void UToolCallAsyncResult::StaticRegisterNativesUToolCallAsyncResult()
{
	UClass* Class = UToolCallAsyncResult::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UToolCallAsyncResult_Statics::Funcs));
}
UClass* Z_Construct_UClass_UToolCallAsyncResult()
{
	if (!Z_Registration_Info_UClass_UToolCallAsyncResult.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UToolCallAsyncResult.OuterSingleton, Z_Construct_UClass_UToolCallAsyncResult_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UToolCallAsyncResult.OuterSingleton;
}
UToolCallAsyncResult::UToolCallAsyncResult(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UToolCallAsyncResult);
UToolCallAsyncResult::~UToolCallAsyncResult() {}
// ********** End Class UToolCallAsyncResult *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResult_h__Script_ToolsetRegistry_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UToolCallAsyncResult, UToolCallAsyncResult::StaticClass, TEXT("UToolCallAsyncResult"), &Z_Registration_Info_UClass_UToolCallAsyncResult, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UToolCallAsyncResult), 2641219963U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResult_h__Script_ToolsetRegistry_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResult_h__Script_ToolsetRegistry_901933745{
	TEXT("/Script/ToolsetRegistry"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResult_h__Script_ToolsetRegistry_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_ToolCallAsyncResult_h__Script_ToolsetRegistry_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
