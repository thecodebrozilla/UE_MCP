// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ToolsetRegistry/UToolsetRegistry.h"
#include "UObject/Class.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeUToolsetRegistry() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolCallAsyncResultString_NoRegister();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition_NoRegister();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetRegistry();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetRegistry_NoRegister();
UPackage* Z_Construct_UPackage__Script_ToolsetRegistry();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UToolsetRegistry Function ExecuteTool ************************************
struct Z_Construct_UFunction_UToolsetRegistry_ExecuteTool_Statics
{
	struct ToolsetRegistry_eventExecuteTool_Parms
	{
		FString ToolsetName;
		FString ToolName;
		FString JsonInput;
		UToolCallAsyncResultString* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ToolsetRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Execute a registered tool given a toolset and tool name as if it was being executed by an \n// AI assistant. If successful, the result's value is a JSON string containing the tool's\n// return value. If a failure occurs, the result will contain an error.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/UToolsetRegistry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Execute a registered tool given a toolset and tool name as if it was being executed by an\nAI assistant. If successful, the result's value is a JSON string containing the tool's\nreturn value. If a failure occurs, the result will contain an error." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ToolsetName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ToolName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonInput_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ExecuteTool constinit property declarations ***************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ToolsetName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ToolName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_JsonInput;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ExecuteTool constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ExecuteTool Property Definitions **************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UToolsetRegistry_ExecuteTool_Statics::NewProp_ToolsetName = { "ToolsetName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ToolsetRegistry_eventExecuteTool_Parms, ToolsetName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ToolsetName_MetaData), NewProp_ToolsetName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UToolsetRegistry_ExecuteTool_Statics::NewProp_ToolName = { "ToolName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ToolsetRegistry_eventExecuteTool_Parms, ToolName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ToolName_MetaData), NewProp_ToolName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UToolsetRegistry_ExecuteTool_Statics::NewProp_JsonInput = { "JsonInput", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ToolsetRegistry_eventExecuteTool_Parms, JsonInput), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonInput_MetaData), NewProp_JsonInput_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UToolsetRegistry_ExecuteTool_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ToolsetRegistry_eventExecuteTool_Parms, ReturnValue), Z_Construct_UClass_UToolCallAsyncResultString_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UToolsetRegistry_ExecuteTool_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetRegistry_ExecuteTool_Statics::NewProp_ToolsetName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetRegistry_ExecuteTool_Statics::NewProp_ToolName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetRegistry_ExecuteTool_Statics::NewProp_JsonInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetRegistry_ExecuteTool_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetRegistry_ExecuteTool_Statics::PropPointers) < 2048);
// ********** End Function ExecuteTool Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UToolsetRegistry_ExecuteTool_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UToolsetRegistry, nullptr, "ExecuteTool", 	Z_Construct_UFunction_UToolsetRegistry_ExecuteTool_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetRegistry_ExecuteTool_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UToolsetRegistry_ExecuteTool_Statics::ToolsetRegistry_eventExecuteTool_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetRegistry_ExecuteTool_Statics::Function_MetaDataParams), Z_Construct_UFunction_UToolsetRegistry_ExecuteTool_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UToolsetRegistry_ExecuteTool_Statics::ToolsetRegistry_eventExecuteTool_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UToolsetRegistry_ExecuteTool()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UToolsetRegistry_ExecuteTool_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UToolsetRegistry::execExecuteTool)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ToolsetName);
	P_GET_PROPERTY(FStrProperty,Z_Param_ToolName);
	P_GET_PROPERTY(FStrProperty,Z_Param_JsonInput);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UToolCallAsyncResultString**)Z_Param__Result=UToolsetRegistry::ExecuteTool(Z_Param_ToolsetName,Z_Param_ToolName,Z_Param_JsonInput);
	P_NATIVE_END;
}
// ********** End Class UToolsetRegistry Function ExecuteTool **************************************

// ********** Begin Class UToolsetRegistry Function GetAllToolsetJsonSchemas ***********************
struct Z_Construct_UFunction_UToolsetRegistry_GetAllToolsetJsonSchemas_Statics
{
	struct ToolsetRegistry_eventGetAllToolsetJsonSchemas_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ToolsetRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Get JSON schemas for all registered toolsets.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/UToolsetRegistry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get JSON schemas for all registered toolsets." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetAllToolsetJsonSchemas constinit property declarations **************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAllToolsetJsonSchemas constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAllToolsetJsonSchemas Property Definitions *************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UToolsetRegistry_GetAllToolsetJsonSchemas_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ToolsetRegistry_eventGetAllToolsetJsonSchemas_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UToolsetRegistry_GetAllToolsetJsonSchemas_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetRegistry_GetAllToolsetJsonSchemas_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetRegistry_GetAllToolsetJsonSchemas_Statics::PropPointers) < 2048);
// ********** End Function GetAllToolsetJsonSchemas Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UToolsetRegistry_GetAllToolsetJsonSchemas_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UToolsetRegistry, nullptr, "GetAllToolsetJsonSchemas", 	Z_Construct_UFunction_UToolsetRegistry_GetAllToolsetJsonSchemas_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetRegistry_GetAllToolsetJsonSchemas_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UToolsetRegistry_GetAllToolsetJsonSchemas_Statics::ToolsetRegistry_eventGetAllToolsetJsonSchemas_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetRegistry_GetAllToolsetJsonSchemas_Statics::Function_MetaDataParams), Z_Construct_UFunction_UToolsetRegistry_GetAllToolsetJsonSchemas_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UToolsetRegistry_GetAllToolsetJsonSchemas_Statics::ToolsetRegistry_eventGetAllToolsetJsonSchemas_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UToolsetRegistry_GetAllToolsetJsonSchemas()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UToolsetRegistry_GetAllToolsetJsonSchemas_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UToolsetRegistry::execGetAllToolsetJsonSchemas)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UToolsetRegistry::GetAllToolsetJsonSchemas();
	P_NATIVE_END;
}
// ********** End Class UToolsetRegistry Function GetAllToolsetJsonSchemas *************************

// ********** Begin Class UToolsetRegistry Function GetToolsetJsonSchema ***************************
struct Z_Construct_UFunction_UToolsetRegistry_GetToolsetJsonSchema_Statics
{
	struct ToolsetRegistry_eventGetToolsetJsonSchema_Parms
	{
		TSubclassOf<UToolsetDefinition> InToolsetClass;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ToolsetRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Get toolset JSON schema for a toolset class.\n// Meant for use while testing.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/UToolsetRegistry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get toolset JSON schema for a toolset class.\nMeant for use while testing." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetToolsetJsonSchema constinit property declarations ******************
	static const UECodeGen_Private::FClassPropertyParams NewProp_InToolsetClass;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetToolsetJsonSchema constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetToolsetJsonSchema Property Definitions *****************************
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UToolsetRegistry_GetToolsetJsonSchema_Statics::NewProp_InToolsetClass = { "InToolsetClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ToolsetRegistry_eventGetToolsetJsonSchema_Parms, InToolsetClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UToolsetDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UToolsetRegistry_GetToolsetJsonSchema_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ToolsetRegistry_eventGetToolsetJsonSchema_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UToolsetRegistry_GetToolsetJsonSchema_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetRegistry_GetToolsetJsonSchema_Statics::NewProp_InToolsetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetRegistry_GetToolsetJsonSchema_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetRegistry_GetToolsetJsonSchema_Statics::PropPointers) < 2048);
// ********** End Function GetToolsetJsonSchema Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UToolsetRegistry_GetToolsetJsonSchema_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UToolsetRegistry, nullptr, "GetToolsetJsonSchema", 	Z_Construct_UFunction_UToolsetRegistry_GetToolsetJsonSchema_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetRegistry_GetToolsetJsonSchema_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UToolsetRegistry_GetToolsetJsonSchema_Statics::ToolsetRegistry_eventGetToolsetJsonSchema_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetRegistry_GetToolsetJsonSchema_Statics::Function_MetaDataParams), Z_Construct_UFunction_UToolsetRegistry_GetToolsetJsonSchema_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UToolsetRegistry_GetToolsetJsonSchema_Statics::ToolsetRegistry_eventGetToolsetJsonSchema_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UToolsetRegistry_GetToolsetJsonSchema()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UToolsetRegistry_GetToolsetJsonSchema_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UToolsetRegistry::execGetToolsetJsonSchema)
{
	P_GET_OBJECT(UClass,Z_Param_InToolsetClass);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UToolsetRegistry::GetToolsetJsonSchema(Z_Param_InToolsetClass);
	P_NATIVE_END;
}
// ********** End Class UToolsetRegistry Function GetToolsetJsonSchema *****************************

// ********** Begin Class UToolsetRegistry Function IsAvailable ************************************
struct Z_Construct_UFunction_UToolsetRegistry_IsAvailable_Statics
{
	struct ToolsetRegistry_eventIsAvailable_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ToolsetRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Whether the toolset registry is available.\n// For example, this will return false if the editor is not available.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/UToolsetRegistry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether the toolset registry is available.\nFor example, this will return false if the editor is not available." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsAvailable constinit property declarations ***************************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsAvailable constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsAvailable Property Definitions **************************************
void Z_Construct_UFunction_UToolsetRegistry_IsAvailable_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ToolsetRegistry_eventIsAvailable_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UToolsetRegistry_IsAvailable_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ToolsetRegistry_eventIsAvailable_Parms), &Z_Construct_UFunction_UToolsetRegistry_IsAvailable_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UToolsetRegistry_IsAvailable_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetRegistry_IsAvailable_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetRegistry_IsAvailable_Statics::PropPointers) < 2048);
// ********** End Function IsAvailable Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UToolsetRegistry_IsAvailable_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UToolsetRegistry, nullptr, "IsAvailable", 	Z_Construct_UFunction_UToolsetRegistry_IsAvailable_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetRegistry_IsAvailable_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UToolsetRegistry_IsAvailable_Statics::ToolsetRegistry_eventIsAvailable_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetRegistry_IsAvailable_Statics::Function_MetaDataParams), Z_Construct_UFunction_UToolsetRegistry_IsAvailable_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UToolsetRegistry_IsAvailable_Statics::ToolsetRegistry_eventIsAvailable_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UToolsetRegistry_IsAvailable()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UToolsetRegistry_IsAvailable_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UToolsetRegistry::execIsAvailable)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UToolsetRegistry::IsAvailable();
	P_NATIVE_END;
}
// ********** End Class UToolsetRegistry Function IsAvailable **************************************

// ********** Begin Class UToolsetRegistry Function IsToolsetClassRegistered ***********************
struct Z_Construct_UFunction_UToolsetRegistry_IsToolsetClassRegistered_Statics
{
	struct ToolsetRegistry_eventIsToolsetClassRegistered_Parms
	{
		TSubclassOf<UToolsetDefinition> InToolsetClass;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ToolsetRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Return whether a toolset class is already registered.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/UToolsetRegistry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Return whether a toolset class is already registered." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsToolsetClassRegistered constinit property declarations **************
	static const UECodeGen_Private::FClassPropertyParams NewProp_InToolsetClass;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsToolsetClassRegistered constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsToolsetClassRegistered Property Definitions *************************
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UToolsetRegistry_IsToolsetClassRegistered_Statics::NewProp_InToolsetClass = { "InToolsetClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ToolsetRegistry_eventIsToolsetClassRegistered_Parms, InToolsetClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UToolsetDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UToolsetRegistry_IsToolsetClassRegistered_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ToolsetRegistry_eventIsToolsetClassRegistered_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UToolsetRegistry_IsToolsetClassRegistered_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ToolsetRegistry_eventIsToolsetClassRegistered_Parms), &Z_Construct_UFunction_UToolsetRegistry_IsToolsetClassRegistered_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UToolsetRegistry_IsToolsetClassRegistered_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetRegistry_IsToolsetClassRegistered_Statics::NewProp_InToolsetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetRegistry_IsToolsetClassRegistered_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetRegistry_IsToolsetClassRegistered_Statics::PropPointers) < 2048);
// ********** End Function IsToolsetClassRegistered Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UToolsetRegistry_IsToolsetClassRegistered_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UToolsetRegistry, nullptr, "IsToolsetClassRegistered", 	Z_Construct_UFunction_UToolsetRegistry_IsToolsetClassRegistered_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetRegistry_IsToolsetClassRegistered_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UToolsetRegistry_IsToolsetClassRegistered_Statics::ToolsetRegistry_eventIsToolsetClassRegistered_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetRegistry_IsToolsetClassRegistered_Statics::Function_MetaDataParams), Z_Construct_UFunction_UToolsetRegistry_IsToolsetClassRegistered_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UToolsetRegistry_IsToolsetClassRegistered_Statics::ToolsetRegistry_eventIsToolsetClassRegistered_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UToolsetRegistry_IsToolsetClassRegistered()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UToolsetRegistry_IsToolsetClassRegistered_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UToolsetRegistry::execIsToolsetClassRegistered)
{
	P_GET_OBJECT(UClass,Z_Param_InToolsetClass);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UToolsetRegistry::IsToolsetClassRegistered(Z_Param_InToolsetClass);
	P_NATIVE_END;
}
// ********** End Class UToolsetRegistry Function IsToolsetClassRegistered *************************

// ********** Begin Class UToolsetRegistry Function IsToolsetRegistered ****************************
struct Z_Construct_UFunction_UToolsetRegistry_IsToolsetRegistered_Statics
{
	struct ToolsetRegistry_eventIsToolsetRegistered_Parms
	{
		FString InToolsetName;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ToolsetRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Return whether a toolset is already registered by name.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/UToolsetRegistry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Return whether a toolset is already registered by name." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InToolsetName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsToolsetRegistered constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InToolsetName;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsToolsetRegistered constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsToolsetRegistered Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UToolsetRegistry_IsToolsetRegistered_Statics::NewProp_InToolsetName = { "InToolsetName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ToolsetRegistry_eventIsToolsetRegistered_Parms, InToolsetName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InToolsetName_MetaData), NewProp_InToolsetName_MetaData) };
void Z_Construct_UFunction_UToolsetRegistry_IsToolsetRegistered_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ToolsetRegistry_eventIsToolsetRegistered_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UToolsetRegistry_IsToolsetRegistered_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ToolsetRegistry_eventIsToolsetRegistered_Parms), &Z_Construct_UFunction_UToolsetRegistry_IsToolsetRegistered_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UToolsetRegistry_IsToolsetRegistered_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetRegistry_IsToolsetRegistered_Statics::NewProp_InToolsetName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetRegistry_IsToolsetRegistered_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetRegistry_IsToolsetRegistered_Statics::PropPointers) < 2048);
// ********** End Function IsToolsetRegistered Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UToolsetRegistry_IsToolsetRegistered_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UToolsetRegistry, nullptr, "IsToolsetRegistered", 	Z_Construct_UFunction_UToolsetRegistry_IsToolsetRegistered_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetRegistry_IsToolsetRegistered_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UToolsetRegistry_IsToolsetRegistered_Statics::ToolsetRegistry_eventIsToolsetRegistered_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetRegistry_IsToolsetRegistered_Statics::Function_MetaDataParams), Z_Construct_UFunction_UToolsetRegistry_IsToolsetRegistered_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UToolsetRegistry_IsToolsetRegistered_Statics::ToolsetRegistry_eventIsToolsetRegistered_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UToolsetRegistry_IsToolsetRegistered()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UToolsetRegistry_IsToolsetRegistered_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UToolsetRegistry::execIsToolsetRegistered)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InToolsetName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UToolsetRegistry::IsToolsetRegistered(Z_Param_InToolsetName);
	P_NATIVE_END;
}
// ********** End Class UToolsetRegistry Function IsToolsetRegistered ******************************

// ********** Begin Class UToolsetRegistry Function RegisterToolsetClass ***************************
struct Z_Construct_UFunction_UToolsetRegistry_RegisterToolsetClass_Statics
{
	struct ToolsetRegistry_eventRegisterToolsetClass_Parms
	{
		TSubclassOf<UToolsetDefinition> InToolsetClass;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ToolsetRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Register a Blueprint function library class as a toolset.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/UToolsetRegistry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Register a Blueprint function library class as a toolset." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RegisterToolsetClass constinit property declarations ******************
	static const UECodeGen_Private::FClassPropertyParams NewProp_InToolsetClass;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RegisterToolsetClass constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RegisterToolsetClass Property Definitions *****************************
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UToolsetRegistry_RegisterToolsetClass_Statics::NewProp_InToolsetClass = { "InToolsetClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ToolsetRegistry_eventRegisterToolsetClass_Parms, InToolsetClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UToolsetDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UToolsetRegistry_RegisterToolsetClass_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetRegistry_RegisterToolsetClass_Statics::NewProp_InToolsetClass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetRegistry_RegisterToolsetClass_Statics::PropPointers) < 2048);
// ********** End Function RegisterToolsetClass Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UToolsetRegistry_RegisterToolsetClass_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UToolsetRegistry, nullptr, "RegisterToolsetClass", 	Z_Construct_UFunction_UToolsetRegistry_RegisterToolsetClass_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetRegistry_RegisterToolsetClass_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UToolsetRegistry_RegisterToolsetClass_Statics::ToolsetRegistry_eventRegisterToolsetClass_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetRegistry_RegisterToolsetClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UToolsetRegistry_RegisterToolsetClass_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UToolsetRegistry_RegisterToolsetClass_Statics::ToolsetRegistry_eventRegisterToolsetClass_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UToolsetRegistry_RegisterToolsetClass()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UToolsetRegistry_RegisterToolsetClass_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UToolsetRegistry::execRegisterToolsetClass)
{
	P_GET_OBJECT(UClass,Z_Param_InToolsetClass);
	P_FINISH;
	P_NATIVE_BEGIN;
	UToolsetRegistry::RegisterToolsetClass(Z_Param_InToolsetClass);
	P_NATIVE_END;
}
// ********** End Class UToolsetRegistry Function RegisterToolsetClass *****************************

// ********** Begin Class UToolsetRegistry Function UnregisterToolsetClass *************************
struct Z_Construct_UFunction_UToolsetRegistry_UnregisterToolsetClass_Statics
{
	struct ToolsetRegistry_eventUnregisterToolsetClass_Parms
	{
		TSubclassOf<UToolsetDefinition> InToolsetClass;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ToolsetRegistry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Unregister a Blueprint function library class as a toolset.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/UToolsetRegistry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Unregister a Blueprint function library class as a toolset." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function UnregisterToolsetClass constinit property declarations ****************
	static const UECodeGen_Private::FClassPropertyParams NewProp_InToolsetClass;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UnregisterToolsetClass constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UnregisterToolsetClass Property Definitions ***************************
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UToolsetRegistry_UnregisterToolsetClass_Statics::NewProp_InToolsetClass = { "InToolsetClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ToolsetRegistry_eventUnregisterToolsetClass_Parms, InToolsetClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UToolsetDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UToolsetRegistry_UnregisterToolsetClass_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToolsetRegistry_UnregisterToolsetClass_Statics::NewProp_InToolsetClass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetRegistry_UnregisterToolsetClass_Statics::PropPointers) < 2048);
// ********** End Function UnregisterToolsetClass Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UToolsetRegistry_UnregisterToolsetClass_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UToolsetRegistry, nullptr, "UnregisterToolsetClass", 	Z_Construct_UFunction_UToolsetRegistry_UnregisterToolsetClass_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetRegistry_UnregisterToolsetClass_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UToolsetRegistry_UnregisterToolsetClass_Statics::ToolsetRegistry_eventUnregisterToolsetClass_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UToolsetRegistry_UnregisterToolsetClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UToolsetRegistry_UnregisterToolsetClass_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UToolsetRegistry_UnregisterToolsetClass_Statics::ToolsetRegistry_eventUnregisterToolsetClass_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UToolsetRegistry_UnregisterToolsetClass()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UToolsetRegistry_UnregisterToolsetClass_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UToolsetRegistry::execUnregisterToolsetClass)
{
	P_GET_OBJECT(UClass,Z_Param_InToolsetClass);
	P_FINISH;
	P_NATIVE_BEGIN;
	UToolsetRegistry::UnregisterToolsetClass(Z_Param_InToolsetClass);
	P_NATIVE_END;
}
// ********** End Class UToolsetRegistry Function UnregisterToolsetClass ***************************

// ********** Begin Class UToolsetRegistry *********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UToolsetRegistry;
UClass* UToolsetRegistry::GetPrivateStaticClass()
{
	using TClass = UToolsetRegistry;
	if (!Z_Registration_Info_UClass_UToolsetRegistry.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ToolsetRegistry"),
			Z_Registration_Info_UClass_UToolsetRegistry.InnerSingleton,
			StaticRegisterNativesUToolsetRegistry,
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
	return Z_Registration_Info_UClass_UToolsetRegistry.InnerSingleton;
}
UClass* Z_Construct_UClass_UToolsetRegistry_NoRegister()
{
	return UToolsetRegistry::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UToolsetRegistry_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Blueprint-accessible wrapper to allow queries against the AI Toolset Registry.\n" },
#endif
		{ "IncludePath", "ToolsetRegistry/UToolsetRegistry.h" },
		{ "ModuleRelativePath", "Public/ToolsetRegistry/UToolsetRegistry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint-accessible wrapper to allow queries against the AI Toolset Registry." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UToolsetRegistry constinit property declarations *************************
// ********** End Class UToolsetRegistry constinit property declarations ***************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ExecuteTool"), .Pointer = &UToolsetRegistry::execExecuteTool },
		{ .NameUTF8 = UTF8TEXT("GetAllToolsetJsonSchemas"), .Pointer = &UToolsetRegistry::execGetAllToolsetJsonSchemas },
		{ .NameUTF8 = UTF8TEXT("GetToolsetJsonSchema"), .Pointer = &UToolsetRegistry::execGetToolsetJsonSchema },
		{ .NameUTF8 = UTF8TEXT("IsAvailable"), .Pointer = &UToolsetRegistry::execIsAvailable },
		{ .NameUTF8 = UTF8TEXT("IsToolsetClassRegistered"), .Pointer = &UToolsetRegistry::execIsToolsetClassRegistered },
		{ .NameUTF8 = UTF8TEXT("IsToolsetRegistered"), .Pointer = &UToolsetRegistry::execIsToolsetRegistered },
		{ .NameUTF8 = UTF8TEXT("RegisterToolsetClass"), .Pointer = &UToolsetRegistry::execRegisterToolsetClass },
		{ .NameUTF8 = UTF8TEXT("UnregisterToolsetClass"), .Pointer = &UToolsetRegistry::execUnregisterToolsetClass },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UToolsetRegistry_ExecuteTool, "ExecuteTool" }, // 2048681178
		{ &Z_Construct_UFunction_UToolsetRegistry_GetAllToolsetJsonSchemas, "GetAllToolsetJsonSchemas" }, // 1411848134
		{ &Z_Construct_UFunction_UToolsetRegistry_GetToolsetJsonSchema, "GetToolsetJsonSchema" }, // 498004136
		{ &Z_Construct_UFunction_UToolsetRegistry_IsAvailable, "IsAvailable" }, // 862972374
		{ &Z_Construct_UFunction_UToolsetRegistry_IsToolsetClassRegistered, "IsToolsetClassRegistered" }, // 3715331942
		{ &Z_Construct_UFunction_UToolsetRegistry_IsToolsetRegistered, "IsToolsetRegistered" }, // 3377292539
		{ &Z_Construct_UFunction_UToolsetRegistry_RegisterToolsetClass, "RegisterToolsetClass" }, // 4291774338
		{ &Z_Construct_UFunction_UToolsetRegistry_UnregisterToolsetClass, "UnregisterToolsetClass" }, // 790154682
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UToolsetRegistry>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UToolsetRegistry_Statics
UObject* (*const Z_Construct_UClass_UToolsetRegistry_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_ToolsetRegistry,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UToolsetRegistry_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UToolsetRegistry_Statics::ClassParams = {
	&UToolsetRegistry::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UToolsetRegistry_Statics::Class_MetaDataParams), Z_Construct_UClass_UToolsetRegistry_Statics::Class_MetaDataParams)
};
void UToolsetRegistry::StaticRegisterNativesUToolsetRegistry()
{
	UClass* Class = UToolsetRegistry::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UToolsetRegistry_Statics::Funcs));
}
UClass* Z_Construct_UClass_UToolsetRegistry()
{
	if (!Z_Registration_Info_UClass_UToolsetRegistry.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UToolsetRegistry.OuterSingleton, Z_Construct_UClass_UToolsetRegistry_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UToolsetRegistry.OuterSingleton;
}
UToolsetRegistry::UToolsetRegistry(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UToolsetRegistry);
UToolsetRegistry::~UToolsetRegistry() {}
// ********** End Class UToolsetRegistry ***********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_UToolsetRegistry_h__Script_ToolsetRegistry_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UToolsetRegistry, UToolsetRegistry::StaticClass, TEXT("UToolsetRegistry"), &Z_Registration_Info_UClass_UToolsetRegistry, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UToolsetRegistry), 3418377973U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_UToolsetRegistry_h__Script_ToolsetRegistry_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_UToolsetRegistry_h__Script_ToolsetRegistry_2125027564{
	TEXT("/Script/ToolsetRegistry"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_UToolsetRegistry_h__Script_ToolsetRegistry_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_UToolsetRegistry_h__Script_ToolsetRegistry_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
