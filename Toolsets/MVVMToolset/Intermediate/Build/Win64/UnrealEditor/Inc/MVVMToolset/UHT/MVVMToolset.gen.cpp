// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MVVMToolset/MVVMToolset.h"
#include "MVVMBlueprintViewBinding.h"
#include "UObject/Class.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeMVVMToolset() {}

// ********** Begin Cross Module References ********************************************************
BLUEPRINTGRAPH_API UClass* Z_Construct_UClass_UK2Node_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UFunction_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ENGINE_API UClass* Z_Construct_UClass_UBlueprint_NoRegister();
MODELVIEWVIEWMODELBLUEPRINT_API UScriptStruct* Z_Construct_UScriptStruct_FMVVMBlueprintViewBinding();
MVVMTOOLSET_API UClass* Z_Construct_UClass_UMVVMToolset();
MVVMTOOLSET_API UClass* Z_Construct_UClass_UMVVMToolset_NoRegister();
MVVMTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FMVVMViewConversionFunctionDescription();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition();
UMGEDITOR_API UClass* Z_Construct_UClass_UWidgetBlueprint_NoRegister();
UPackage* Z_Construct_UPackage__Script_MVVMToolset();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FMVVMViewConversionFunctionDescription ****************************
struct Z_Construct_UScriptStruct_FMVVMViewConversionFunctionDescription_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FMVVMViewConversionFunctionDescription); }
	static inline consteval int16 GetStructAlignment() { return alignof(FMVVMViewConversionFunctionDescription); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Information about a conversion function*/" },
#endif
		{ "ModuleRelativePath", "Private/MVVMToolset/MVVMToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Information about a conversion function" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConversionFunction_MetaData[] = {
		{ "Category", "MVVM" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* If the conversion function is a UFunction, this value will be set */" },
#endif
		{ "ModuleRelativePath", "Private/MVVMToolset/MVVMToolset.h" },
		{ "NativeConstTemplateArg", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If the conversion function is a UFunction, this value will be set" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConversionNode_MetaData[] = {
		{ "Category", "MVVM" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* If the conversion function is a UK2Node, this value will be set */" },
#endif
		{ "ModuleRelativePath", "Private/MVVMToolset/MVVMToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If the conversion function is a UK2Node, this value will be set" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FMVVMViewConversionFunctionDescription constinit property declarations 
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ConversionFunction;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ConversionNode;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FMVVMViewConversionFunctionDescription constinit property declarations 
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMVVMViewConversionFunctionDescription>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FMVVMViewConversionFunctionDescription_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FMVVMViewConversionFunctionDescription;
class UScriptStruct* FMVVMViewConversionFunctionDescription::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FMVVMViewConversionFunctionDescription.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FMVVMViewConversionFunctionDescription.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMVVMViewConversionFunctionDescription, (UObject*)Z_Construct_UPackage__Script_MVVMToolset(), TEXT("MVVMViewConversionFunctionDescription"));
	}
	return Z_Registration_Info_UScriptStruct_FMVVMViewConversionFunctionDescription.OuterSingleton;
	}

// ********** Begin ScriptStruct FMVVMViewConversionFunctionDescription Property Definitions *******
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FMVVMViewConversionFunctionDescription_Statics::NewProp_ConversionFunction = { "ConversionFunction", nullptr, (EPropertyFlags)0x0114000000000014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMVVMViewConversionFunctionDescription, ConversionFunction), Z_Construct_UClass_UFunction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ConversionFunction_MetaData), NewProp_ConversionFunction_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FMVVMViewConversionFunctionDescription_Statics::NewProp_ConversionNode = { "ConversionNode", nullptr, (EPropertyFlags)0x0014000000000014, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMVVMViewConversionFunctionDescription, ConversionNode), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UK2Node_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ConversionNode_MetaData), NewProp_ConversionNode_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMVVMViewConversionFunctionDescription_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMVVMViewConversionFunctionDescription_Statics::NewProp_ConversionFunction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMVVMViewConversionFunctionDescription_Statics::NewProp_ConversionNode,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMVVMViewConversionFunctionDescription_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FMVVMViewConversionFunctionDescription Property Definitions *********
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMVVMViewConversionFunctionDescription_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_MVVMToolset,
	nullptr,
	&NewStructOps,
	"MVVMViewConversionFunctionDescription",
	Z_Construct_UScriptStruct_FMVVMViewConversionFunctionDescription_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMVVMViewConversionFunctionDescription_Statics::PropPointers),
	sizeof(FMVVMViewConversionFunctionDescription),
	alignof(FMVVMViewConversionFunctionDescription),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMVVMViewConversionFunctionDescription_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMVVMViewConversionFunctionDescription_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FMVVMViewConversionFunctionDescription()
{
	if (!Z_Registration_Info_UScriptStruct_FMVVMViewConversionFunctionDescription.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FMVVMViewConversionFunctionDescription.InnerSingleton, Z_Construct_UScriptStruct_FMVVMViewConversionFunctionDescription_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FMVVMViewConversionFunctionDescription.InnerSingleton);
}
// ********** End ScriptStruct FMVVMViewConversionFunctionDescription ******************************

// ********** Begin Class UMVVMToolset Function AddViewModelProperty *******************************
struct Z_Construct_UFunction_UMVVMToolset_AddViewModelProperty_Statics
{
	struct MVVMToolset_eventAddViewModelProperty_Parms
	{
		UBlueprint* ViewModel;
		FString PropertyName;
		FString PropertyType;
		FString DefaultValue;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "MVVM" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* \n\x09""Add a property to an existing ViewModel\n\x09\x09\n\x09@param ViewModel - ViewModel asset to use. \n\x09@param PropertyName - Desired name of the new property \n\x09@param PropertyType - Desired type of the new property. Corresponds with PinType\n\x09@param DefaultValue - If a default property is desired, string representation of the value\n\x09@return True if property was succesfully added.\n\x09*/" },
#endif
		{ "Experimental", "" },
		{ "ModuleRelativePath", "Private/MVVMToolset/MVVMToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Add a property to an existing ViewModel\n\n@param ViewModel - ViewModel asset to use.\n@param PropertyName - Desired name of the new property\n@param PropertyType - Desired type of the new property. Corresponds with PinType\n@param DefaultValue - If a default property is desired, string representation of the value\n@return True if property was succesfully added." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropertyName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropertyType_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddViewModelProperty constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ViewModel;
	static const UECodeGen_Private::FStrPropertyParams NewProp_PropertyName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_PropertyType;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DefaultValue;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddViewModelProperty constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddViewModelProperty Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMVVMToolset_AddViewModelProperty_Statics::NewProp_ViewModel = { "ViewModel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MVVMToolset_eventAddViewModelProperty_Parms, ViewModel), Z_Construct_UClass_UBlueprint_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMVVMToolset_AddViewModelProperty_Statics::NewProp_PropertyName = { "PropertyName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MVVMToolset_eventAddViewModelProperty_Parms, PropertyName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropertyName_MetaData), NewProp_PropertyName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMVVMToolset_AddViewModelProperty_Statics::NewProp_PropertyType = { "PropertyType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MVVMToolset_eventAddViewModelProperty_Parms, PropertyType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropertyType_MetaData), NewProp_PropertyType_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMVVMToolset_AddViewModelProperty_Statics::NewProp_DefaultValue = { "DefaultValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MVVMToolset_eventAddViewModelProperty_Parms, DefaultValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultValue_MetaData), NewProp_DefaultValue_MetaData) };
void Z_Construct_UFunction_UMVVMToolset_AddViewModelProperty_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((MVVMToolset_eventAddViewModelProperty_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMVVMToolset_AddViewModelProperty_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MVVMToolset_eventAddViewModelProperty_Parms), &Z_Construct_UFunction_UMVVMToolset_AddViewModelProperty_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMVVMToolset_AddViewModelProperty_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_AddViewModelProperty_Statics::NewProp_ViewModel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_AddViewModelProperty_Statics::NewProp_PropertyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_AddViewModelProperty_Statics::NewProp_PropertyType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_AddViewModelProperty_Statics::NewProp_DefaultValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_AddViewModelProperty_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMVVMToolset_AddViewModelProperty_Statics::PropPointers) < 2048);
// ********** End Function AddViewModelProperty Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMVVMToolset_AddViewModelProperty_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UMVVMToolset, nullptr, "AddViewModelProperty", 	Z_Construct_UFunction_UMVVMToolset_AddViewModelProperty_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UMVVMToolset_AddViewModelProperty_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UMVVMToolset_AddViewModelProperty_Statics::MVVMToolset_eventAddViewModelProperty_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMVVMToolset_AddViewModelProperty_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMVVMToolset_AddViewModelProperty_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UMVVMToolset_AddViewModelProperty_Statics::MVVMToolset_eventAddViewModelProperty_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMVVMToolset_AddViewModelProperty()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMVVMToolset_AddViewModelProperty_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMVVMToolset::execAddViewModelProperty)
{
	P_GET_OBJECT(UBlueprint,Z_Param_ViewModel);
	P_GET_PROPERTY(FStrProperty,Z_Param_PropertyName);
	P_GET_PROPERTY(FStrProperty,Z_Param_PropertyType);
	P_GET_PROPERTY(FStrProperty,Z_Param_DefaultValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UMVVMToolset::AddViewModelProperty(Z_Param_ViewModel,Z_Param_PropertyName,Z_Param_PropertyType,Z_Param_DefaultValue);
	P_NATIVE_END;
}
// ********** End Class UMVVMToolset Function AddViewModelProperty *********************************

// ********** Begin Class UMVVMToolset Function AddViewModelToWidget *******************************
struct Z_Construct_UFunction_UMVVMToolset_AddViewModelToWidget_Statics
{
	struct MVVMToolset_eventAddViewModelToWidget_Parms
	{
		UWidgetBlueprint* WidgetBlueprint;
		UClass* ViewModelClass;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "MVVM" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* \n\x09""Adds a ViewModel to the WidgetBlueprint\n\x09\x09\n\x09@param WidgetBlueprint - WidgetBlueprint to use\n\x09@param ViewModelClass - ViewModel class to use.\n\x09*/" },
#endif
		{ "Experimental", "" },
		{ "ModuleRelativePath", "Private/MVVMToolset/MVVMToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds a ViewModel to the WidgetBlueprint\n\n@param WidgetBlueprint - WidgetBlueprint to use\n@param ViewModelClass - ViewModel class to use." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function AddViewModelToWidget constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WidgetBlueprint;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ViewModelClass;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddViewModelToWidget constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddViewModelToWidget Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMVVMToolset_AddViewModelToWidget_Statics::NewProp_WidgetBlueprint = { "WidgetBlueprint", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MVVMToolset_eventAddViewModelToWidget_Parms, WidgetBlueprint), Z_Construct_UClass_UWidgetBlueprint_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UMVVMToolset_AddViewModelToWidget_Statics::NewProp_ViewModelClass = { "ViewModelClass", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MVVMToolset_eventAddViewModelToWidget_Parms, ViewModelClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMVVMToolset_AddViewModelToWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_AddViewModelToWidget_Statics::NewProp_WidgetBlueprint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_AddViewModelToWidget_Statics::NewProp_ViewModelClass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMVVMToolset_AddViewModelToWidget_Statics::PropPointers) < 2048);
// ********** End Function AddViewModelToWidget Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMVVMToolset_AddViewModelToWidget_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UMVVMToolset, nullptr, "AddViewModelToWidget", 	Z_Construct_UFunction_UMVVMToolset_AddViewModelToWidget_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UMVVMToolset_AddViewModelToWidget_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UMVVMToolset_AddViewModelToWidget_Statics::MVVMToolset_eventAddViewModelToWidget_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMVVMToolset_AddViewModelToWidget_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMVVMToolset_AddViewModelToWidget_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UMVVMToolset_AddViewModelToWidget_Statics::MVVMToolset_eventAddViewModelToWidget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMVVMToolset_AddViewModelToWidget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMVVMToolset_AddViewModelToWidget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMVVMToolset::execAddViewModelToWidget)
{
	P_GET_OBJECT(UWidgetBlueprint,Z_Param_WidgetBlueprint);
	P_GET_OBJECT(UClass,Z_Param_ViewModelClass);
	P_FINISH;
	P_NATIVE_BEGIN;
	UMVVMToolset::AddViewModelToWidget(Z_Param_WidgetBlueprint,Z_Param_ViewModelClass);
	P_NATIVE_END;
}
// ********** End Class UMVVMToolset Function AddViewModelToWidget *********************************

// ********** Begin Class UMVVMToolset Function CreateViewBinding **********************************
struct Z_Construct_UFunction_UMVVMToolset_CreateViewBinding_Statics
{
	struct MVVMToolset_eventCreateViewBinding_Parms
	{
		UWidgetBlueprint* WidgetBlueprint;
		UObject* SourceContext;
		FString SourcePropertyPath;
		UObject* DestinationContext;
		FString DestinationPropertyPath;
		FName ConversionName;
		FGuid ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "MVVM" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* \n\x09""Creates a View Binding from the SourceProperty to the Destination property. \n\x09If there is a type mismatch, an existing conversion function will try to be used.\n\x09\n\x09@param WidgetBlueprint - WidgetBlueprint to use\n\x09@param SourceContext - Source object that contains the source property. \n\x09\x09""Can be the following:\n\x09\x09- UWidget: source property is from a widget in the widget blueprint's widgettree\n\x09\x09- UClass: source property is from a widget blueprint's ViewModel \n\x09\x09- Null: source property is from the widget blueprint\n\x09@param SourcePropertyPath - Property to read data from. Contains a dot '.' separated path to the field (path.subfield)\n\x09@param DestinationContext - Destination object that contains the destination property. \n\x09\x09""Can be the following:\n\x09\x09- UWidget: destination property is from a widget in the widget blueprint's widgettree\n\x09\x09- UClass: destination property is from a widget blueprint's ViewModel \n\x09\x09- Null: destination property is from the widget blueprint\n\x09@param DestinationPropertyPath - Property to write data to. Contains a dot '.' separated path to the field (path.subfield)\n\x09@param ConversionName - Optional parameter, name of a conversion function to use if needed. If none is provided, this will be inferred.\n\x09@return Valid FGuid if the binding was created\n\x09*/" },
#endif
		{ "Experimental", "" },
		{ "ModuleRelativePath", "Private/MVVMToolset/MVVMToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Creates a View Binding from the SourceProperty to the Destination property.\nIf there is a type mismatch, an existing conversion function will try to be used.\n\n@param WidgetBlueprint - WidgetBlueprint to use\n@param SourceContext - Source object that contains the source property.\n        Can be the following:\n        - UWidget: source property is from a widget in the widget blueprint's widgettree\n        - UClass: source property is from a widget blueprint's ViewModel\n        - Null: source property is from the widget blueprint\n@param SourcePropertyPath - Property to read data from. Contains a dot '.' separated path to the field (path.subfield)\n@param DestinationContext - Destination object that contains the destination property.\n        Can be the following:\n        - UWidget: destination property is from a widget in the widget blueprint's widgettree\n        - UClass: destination property is from a widget blueprint's ViewModel\n        - Null: destination property is from the widget blueprint\n@param DestinationPropertyPath - Property to write data to. Contains a dot '.' separated path to the field (path.subfield)\n@param ConversionName - Optional parameter, name of a conversion function to use if needed. If none is provided, this will be inferred.\n@return Valid FGuid if the binding was created" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourcePropertyPath_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DestinationPropertyPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CreateViewBinding constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WidgetBlueprint;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SourceContext;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SourcePropertyPath;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DestinationContext;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DestinationPropertyPath;
	static const UECodeGen_Private::FNamePropertyParams NewProp_ConversionName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CreateViewBinding constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CreateViewBinding Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMVVMToolset_CreateViewBinding_Statics::NewProp_WidgetBlueprint = { "WidgetBlueprint", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MVVMToolset_eventCreateViewBinding_Parms, WidgetBlueprint), Z_Construct_UClass_UWidgetBlueprint_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMVVMToolset_CreateViewBinding_Statics::NewProp_SourceContext = { "SourceContext", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MVVMToolset_eventCreateViewBinding_Parms, SourceContext), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMVVMToolset_CreateViewBinding_Statics::NewProp_SourcePropertyPath = { "SourcePropertyPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MVVMToolset_eventCreateViewBinding_Parms, SourcePropertyPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourcePropertyPath_MetaData), NewProp_SourcePropertyPath_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMVVMToolset_CreateViewBinding_Statics::NewProp_DestinationContext = { "DestinationContext", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MVVMToolset_eventCreateViewBinding_Parms, DestinationContext), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMVVMToolset_CreateViewBinding_Statics::NewProp_DestinationPropertyPath = { "DestinationPropertyPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MVVMToolset_eventCreateViewBinding_Parms, DestinationPropertyPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DestinationPropertyPath_MetaData), NewProp_DestinationPropertyPath_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UMVVMToolset_CreateViewBinding_Statics::NewProp_ConversionName = { "ConversionName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MVVMToolset_eventCreateViewBinding_Parms, ConversionName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMVVMToolset_CreateViewBinding_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MVVMToolset_eventCreateViewBinding_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMVVMToolset_CreateViewBinding_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_CreateViewBinding_Statics::NewProp_WidgetBlueprint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_CreateViewBinding_Statics::NewProp_SourceContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_CreateViewBinding_Statics::NewProp_SourcePropertyPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_CreateViewBinding_Statics::NewProp_DestinationContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_CreateViewBinding_Statics::NewProp_DestinationPropertyPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_CreateViewBinding_Statics::NewProp_ConversionName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_CreateViewBinding_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMVVMToolset_CreateViewBinding_Statics::PropPointers) < 2048);
// ********** End Function CreateViewBinding Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMVVMToolset_CreateViewBinding_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UMVVMToolset, nullptr, "CreateViewBinding", 	Z_Construct_UFunction_UMVVMToolset_CreateViewBinding_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UMVVMToolset_CreateViewBinding_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UMVVMToolset_CreateViewBinding_Statics::MVVMToolset_eventCreateViewBinding_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMVVMToolset_CreateViewBinding_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMVVMToolset_CreateViewBinding_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UMVVMToolset_CreateViewBinding_Statics::MVVMToolset_eventCreateViewBinding_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMVVMToolset_CreateViewBinding()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMVVMToolset_CreateViewBinding_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMVVMToolset::execCreateViewBinding)
{
	P_GET_OBJECT(UWidgetBlueprint,Z_Param_WidgetBlueprint);
	P_GET_OBJECT(UObject,Z_Param_SourceContext);
	P_GET_PROPERTY(FStrProperty,Z_Param_SourcePropertyPath);
	P_GET_OBJECT(UObject,Z_Param_DestinationContext);
	P_GET_PROPERTY(FStrProperty,Z_Param_DestinationPropertyPath);
	P_GET_PROPERTY(FNameProperty,Z_Param_ConversionName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGuid*)Z_Param__Result=UMVVMToolset::CreateViewBinding(Z_Param_WidgetBlueprint,Z_Param_SourceContext,Z_Param_SourcePropertyPath,Z_Param_DestinationContext,Z_Param_DestinationPropertyPath,Z_Param_ConversionName);
	P_NATIVE_END;
}
// ********** End Class UMVVMToolset Function CreateViewBinding ************************************

// ********** Begin Class UMVVMToolset Function CreateViewModel ************************************
struct Z_Construct_UFunction_UMVVMToolset_CreateViewModel_Statics
{
	struct MVVMToolset_eventCreateViewModel_Parms
	{
		FString ViewModelName;
		FString PackagePath;
		UClass* ParentClass;
		UBlueprint* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "MVVM" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* \n\x09""Creates a new ViewModel asset\n\x09\x09\n\x09@param ViewModelName - Desired ViewModel asset name. \n\x09@param PackagePath - Target path in which the asset should reside\n\x09@param ParentClass - Class of which the ViewModel should derive. Must derive UMVVMViewModelBase \n\x09@return newly created ViewModel blueprint.\n\x09*/" },
#endif
		{ "Experimental", "" },
		{ "ModuleRelativePath", "Private/MVVMToolset/MVVMToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Creates a new ViewModel asset\n\n@param ViewModelName - Desired ViewModel asset name.\n@param PackagePath - Target path in which the asset should reside\n@param ParentClass - Class of which the ViewModel should derive. Must derive UMVVMViewModelBase\n@return newly created ViewModel blueprint." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ViewModelName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PackagePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CreateViewModel constinit property declarations ***********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ViewModelName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_PackagePath;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ParentClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CreateViewModel constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CreateViewModel Property Definitions **********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMVVMToolset_CreateViewModel_Statics::NewProp_ViewModelName = { "ViewModelName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MVVMToolset_eventCreateViewModel_Parms, ViewModelName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ViewModelName_MetaData), NewProp_ViewModelName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMVVMToolset_CreateViewModel_Statics::NewProp_PackagePath = { "PackagePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MVVMToolset_eventCreateViewModel_Parms, PackagePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PackagePath_MetaData), NewProp_PackagePath_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UMVVMToolset_CreateViewModel_Statics::NewProp_ParentClass = { "ParentClass", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MVVMToolset_eventCreateViewModel_Parms, ParentClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMVVMToolset_CreateViewModel_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MVVMToolset_eventCreateViewModel_Parms, ReturnValue), Z_Construct_UClass_UBlueprint_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMVVMToolset_CreateViewModel_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_CreateViewModel_Statics::NewProp_ViewModelName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_CreateViewModel_Statics::NewProp_PackagePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_CreateViewModel_Statics::NewProp_ParentClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_CreateViewModel_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMVVMToolset_CreateViewModel_Statics::PropPointers) < 2048);
// ********** End Function CreateViewModel Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMVVMToolset_CreateViewModel_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UMVVMToolset, nullptr, "CreateViewModel", 	Z_Construct_UFunction_UMVVMToolset_CreateViewModel_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UMVVMToolset_CreateViewModel_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UMVVMToolset_CreateViewModel_Statics::MVVMToolset_eventCreateViewModel_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMVVMToolset_CreateViewModel_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMVVMToolset_CreateViewModel_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UMVVMToolset_CreateViewModel_Statics::MVVMToolset_eventCreateViewModel_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMVVMToolset_CreateViewModel()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMVVMToolset_CreateViewModel_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMVVMToolset::execCreateViewModel)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ViewModelName);
	P_GET_PROPERTY(FStrProperty,Z_Param_PackagePath);
	P_GET_OBJECT(UClass,Z_Param_ParentClass);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UBlueprint**)Z_Param__Result=UMVVMToolset::CreateViewModel(Z_Param_ViewModelName,Z_Param_PackagePath,Z_Param_ParentClass);
	P_NATIVE_END;
}
// ********** End Class UMVVMToolset Function CreateViewModel **************************************

// ********** Begin Class UMVVMToolset Function ListConversionFunctions ****************************
struct Z_Construct_UFunction_UMVVMToolset_ListConversionFunctions_Statics
{
	struct MVVMToolset_eventListConversionFunctions_Parms
	{
		UWidgetBlueprint* WidgetBlueprint;
		TArray<FMVVMViewConversionFunctionDescription> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "MVVM" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* \n\x09List Available Conversion functions for a WidgetBlueprint that bind a Source Property to a Destination Property\n\x09@param WidgetBlueprint - WidgetBlueprint to use\n\x09@return the FMVVMViewConversionFunctionDescription for available conversion functions. \n\x09*/" },
#endif
		{ "Experimental", "" },
		{ "ModuleRelativePath", "Private/MVVMToolset/MVVMToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "List Available Conversion functions for a WidgetBlueprint that bind a Source Property to a Destination Property\n@param WidgetBlueprint - WidgetBlueprint to use\n@return the FMVVMViewConversionFunctionDescription for available conversion functions." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ListConversionFunctions constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WidgetBlueprint;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListConversionFunctions constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListConversionFunctions Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMVVMToolset_ListConversionFunctions_Statics::NewProp_WidgetBlueprint = { "WidgetBlueprint", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MVVMToolset_eventListConversionFunctions_Parms, WidgetBlueprint), Z_Construct_UClass_UWidgetBlueprint_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMVVMToolset_ListConversionFunctions_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FMVVMViewConversionFunctionDescription, METADATA_PARAMS(0, nullptr) }; // 1959060471
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UMVVMToolset_ListConversionFunctions_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MVVMToolset_eventListConversionFunctions_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 1959060471
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMVVMToolset_ListConversionFunctions_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_ListConversionFunctions_Statics::NewProp_WidgetBlueprint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_ListConversionFunctions_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_ListConversionFunctions_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMVVMToolset_ListConversionFunctions_Statics::PropPointers) < 2048);
// ********** End Function ListConversionFunctions Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMVVMToolset_ListConversionFunctions_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UMVVMToolset, nullptr, "ListConversionFunctions", 	Z_Construct_UFunction_UMVVMToolset_ListConversionFunctions_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UMVVMToolset_ListConversionFunctions_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UMVVMToolset_ListConversionFunctions_Statics::MVVMToolset_eventListConversionFunctions_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMVVMToolset_ListConversionFunctions_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMVVMToolset_ListConversionFunctions_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UMVVMToolset_ListConversionFunctions_Statics::MVVMToolset_eventListConversionFunctions_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMVVMToolset_ListConversionFunctions()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMVVMToolset_ListConversionFunctions_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMVVMToolset::execListConversionFunctions)
{
	P_GET_OBJECT(UWidgetBlueprint,Z_Param_WidgetBlueprint);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FMVVMViewConversionFunctionDescription>*)Z_Param__Result=UMVVMToolset::ListConversionFunctions(Z_Param_WidgetBlueprint);
	P_NATIVE_END;
}
// ********** End Class UMVVMToolset Function ListConversionFunctions ******************************

// ********** Begin Class UMVVMToolset Function ListViewModels *************************************
struct Z_Construct_UFunction_UMVVMToolset_ListViewModels_Statics
{
	struct MVVMToolset_eventListViewModels_Parms
	{
		FString SearchPath;
		TArray<UClass*> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "MVVM" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* \n\x09List all ViewModel under the search path\n\x09\x09\n\x09@param SearchPath - Mount point search path for ViewModel assets\n\x09@return List of ViewModel classes.\n\x09*/" },
#endif
		{ "Experimental", "" },
		{ "ModuleRelativePath", "Private/MVVMToolset/MVVMToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "List all ViewModel under the search path\n\n@param SearchPath - Mount point search path for ViewModel assets\n@return List of ViewModel classes." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SearchPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ListViewModels constinit property declarations ************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_SearchPath;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListViewModels constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListViewModels Property Definitions ***********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMVVMToolset_ListViewModels_Statics::NewProp_SearchPath = { "SearchPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MVVMToolset_eventListViewModels_Parms, SearchPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SearchPath_MetaData), NewProp_SearchPath_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UMVVMToolset_ListViewModels_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UMVVMToolset_ListViewModels_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MVVMToolset_eventListViewModels_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMVVMToolset_ListViewModels_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_ListViewModels_Statics::NewProp_SearchPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_ListViewModels_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_ListViewModels_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMVVMToolset_ListViewModels_Statics::PropPointers) < 2048);
// ********** End Function ListViewModels Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMVVMToolset_ListViewModels_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UMVVMToolset, nullptr, "ListViewModels", 	Z_Construct_UFunction_UMVVMToolset_ListViewModels_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UMVVMToolset_ListViewModels_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UMVVMToolset_ListViewModels_Statics::MVVMToolset_eventListViewModels_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMVVMToolset_ListViewModels_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMVVMToolset_ListViewModels_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UMVVMToolset_ListViewModels_Statics::MVVMToolset_eventListViewModels_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMVVMToolset_ListViewModels()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMVVMToolset_ListViewModels_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMVVMToolset::execListViewModels)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_SearchPath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<UClass*>*)Z_Param__Result=UMVVMToolset::ListViewModels(Z_Param_SearchPath);
	P_NATIVE_END;
}
// ********** End Class UMVVMToolset Function ListViewModels ***************************************

// ********** Begin Class UMVVMToolset Function ListWidgetViewBindings *****************************
struct Z_Construct_UFunction_UMVVMToolset_ListWidgetViewBindings_Statics
{
	struct MVVMToolset_eventListWidgetViewBindings_Parms
	{
		UWidgetBlueprint* WidgetBlueprint;
		TArray<FMVVMBlueprintViewBinding> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "MVVM" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* \n\x09List all view bindings on the WidgetBlueprint\n\x09\x09\n\x09@param WidgetBlueprint - WidgetBlueprint to use\n\x09@return List of FMVVMBlueprintViewBinding that describe each available view binding.\n\x09*/" },
#endif
		{ "Experimental", "" },
		{ "ModuleRelativePath", "Private/MVVMToolset/MVVMToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "List all view bindings on the WidgetBlueprint\n\n@param WidgetBlueprint - WidgetBlueprint to use\n@return List of FMVVMBlueprintViewBinding that describe each available view binding." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ListWidgetViewBindings constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WidgetBlueprint;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListWidgetViewBindings constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListWidgetViewBindings Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMVVMToolset_ListWidgetViewBindings_Statics::NewProp_WidgetBlueprint = { "WidgetBlueprint", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MVVMToolset_eventListWidgetViewBindings_Parms, WidgetBlueprint), Z_Construct_UClass_UWidgetBlueprint_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMVVMToolset_ListWidgetViewBindings_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FMVVMBlueprintViewBinding, METADATA_PARAMS(0, nullptr) }; // 3981776742
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UMVVMToolset_ListWidgetViewBindings_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010008000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MVVMToolset_eventListWidgetViewBindings_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 3981776742
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMVVMToolset_ListWidgetViewBindings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_ListWidgetViewBindings_Statics::NewProp_WidgetBlueprint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_ListWidgetViewBindings_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_ListWidgetViewBindings_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMVVMToolset_ListWidgetViewBindings_Statics::PropPointers) < 2048);
// ********** End Function ListWidgetViewBindings Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMVVMToolset_ListWidgetViewBindings_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UMVVMToolset, nullptr, "ListWidgetViewBindings", 	Z_Construct_UFunction_UMVVMToolset_ListWidgetViewBindings_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UMVVMToolset_ListWidgetViewBindings_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UMVVMToolset_ListWidgetViewBindings_Statics::MVVMToolset_eventListWidgetViewBindings_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMVVMToolset_ListWidgetViewBindings_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMVVMToolset_ListWidgetViewBindings_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UMVVMToolset_ListWidgetViewBindings_Statics::MVVMToolset_eventListWidgetViewBindings_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMVVMToolset_ListWidgetViewBindings()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMVVMToolset_ListWidgetViewBindings_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMVVMToolset::execListWidgetViewBindings)
{
	P_GET_OBJECT(UWidgetBlueprint,Z_Param_WidgetBlueprint);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FMVVMBlueprintViewBinding>*)Z_Param__Result=UMVVMToolset::ListWidgetViewBindings(Z_Param_WidgetBlueprint);
	P_NATIVE_END;
}
// ********** End Class UMVVMToolset Function ListWidgetViewBindings *******************************

// ********** Begin Class UMVVMToolset Function ListWidgetViewModels *******************************
struct Z_Construct_UFunction_UMVVMToolset_ListWidgetViewModels_Statics
{
	struct MVVMToolset_eventListWidgetViewModels_Parms
	{
		UWidgetBlueprint* WidgetBlueprint;
		TArray<UClass*> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "MVVM" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* \n\x09List all ViewModel on the WidgetBlueprint\n\x09\x09\n\x09@param WidgetBlueprint - WidgetBlueprint to use\n\x09@return List of ViewModel classes.\n\x09*/" },
#endif
		{ "Experimental", "" },
		{ "ModuleRelativePath", "Private/MVVMToolset/MVVMToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "List all ViewModel on the WidgetBlueprint\n\n@param WidgetBlueprint - WidgetBlueprint to use\n@return List of ViewModel classes." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ListWidgetViewModels constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WidgetBlueprint;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListWidgetViewModels constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListWidgetViewModels Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMVVMToolset_ListWidgetViewModels_Statics::NewProp_WidgetBlueprint = { "WidgetBlueprint", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MVVMToolset_eventListWidgetViewModels_Parms, WidgetBlueprint), Z_Construct_UClass_UWidgetBlueprint_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UMVVMToolset_ListWidgetViewModels_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UMVVMToolset_ListWidgetViewModels_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MVVMToolset_eventListWidgetViewModels_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMVVMToolset_ListWidgetViewModels_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_ListWidgetViewModels_Statics::NewProp_WidgetBlueprint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_ListWidgetViewModels_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_ListWidgetViewModels_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMVVMToolset_ListWidgetViewModels_Statics::PropPointers) < 2048);
// ********** End Function ListWidgetViewModels Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMVVMToolset_ListWidgetViewModels_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UMVVMToolset, nullptr, "ListWidgetViewModels", 	Z_Construct_UFunction_UMVVMToolset_ListWidgetViewModels_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UMVVMToolset_ListWidgetViewModels_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UMVVMToolset_ListWidgetViewModels_Statics::MVVMToolset_eventListWidgetViewModels_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMVVMToolset_ListWidgetViewModels_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMVVMToolset_ListWidgetViewModels_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UMVVMToolset_ListWidgetViewModels_Statics::MVVMToolset_eventListWidgetViewModels_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMVVMToolset_ListWidgetViewModels()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMVVMToolset_ListWidgetViewModels_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMVVMToolset::execListWidgetViewModels)
{
	P_GET_OBJECT(UWidgetBlueprint,Z_Param_WidgetBlueprint);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<UClass*>*)Z_Param__Result=UMVVMToolset::ListWidgetViewModels(Z_Param_WidgetBlueprint);
	P_NATIVE_END;
}
// ********** End Class UMVVMToolset Function ListWidgetViewModels *********************************

// ********** Begin Class UMVVMToolset Function RemoveWidgetViewBinding ****************************
struct Z_Construct_UFunction_UMVVMToolset_RemoveWidgetViewBinding_Statics
{
	struct MVVMToolset_eventRemoveWidgetViewBinding_Parms
	{
		UWidgetBlueprint* WidgetBlueprint;
		FGuid BindingID;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "MVVM" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* \n\x09Removes View Binding on the WidgetBlueprint\n\x09\x09\n\x09@param WidgetBlueprint - WidgetBlueprint to use\n\x09@return True if binding was removed.\n\x09*/" },
#endif
		{ "Experimental", "" },
		{ "ModuleRelativePath", "Private/MVVMToolset/MVVMToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Removes View Binding on the WidgetBlueprint\n\n@param WidgetBlueprint - WidgetBlueprint to use\n@return True if binding was removed." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BindingID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RemoveWidgetViewBinding constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WidgetBlueprint;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BindingID;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RemoveWidgetViewBinding constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RemoveWidgetViewBinding Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMVVMToolset_RemoveWidgetViewBinding_Statics::NewProp_WidgetBlueprint = { "WidgetBlueprint", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MVVMToolset_eventRemoveWidgetViewBinding_Parms, WidgetBlueprint), Z_Construct_UClass_UWidgetBlueprint_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMVVMToolset_RemoveWidgetViewBinding_Statics::NewProp_BindingID = { "BindingID", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MVVMToolset_eventRemoveWidgetViewBinding_Parms, BindingID), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BindingID_MetaData), NewProp_BindingID_MetaData) };
void Z_Construct_UFunction_UMVVMToolset_RemoveWidgetViewBinding_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((MVVMToolset_eventRemoveWidgetViewBinding_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMVVMToolset_RemoveWidgetViewBinding_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MVVMToolset_eventRemoveWidgetViewBinding_Parms), &Z_Construct_UFunction_UMVVMToolset_RemoveWidgetViewBinding_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMVVMToolset_RemoveWidgetViewBinding_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_RemoveWidgetViewBinding_Statics::NewProp_WidgetBlueprint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_RemoveWidgetViewBinding_Statics::NewProp_BindingID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMVVMToolset_RemoveWidgetViewBinding_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMVVMToolset_RemoveWidgetViewBinding_Statics::PropPointers) < 2048);
// ********** End Function RemoveWidgetViewBinding Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMVVMToolset_RemoveWidgetViewBinding_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UMVVMToolset, nullptr, "RemoveWidgetViewBinding", 	Z_Construct_UFunction_UMVVMToolset_RemoveWidgetViewBinding_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UMVVMToolset_RemoveWidgetViewBinding_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UMVVMToolset_RemoveWidgetViewBinding_Statics::MVVMToolset_eventRemoveWidgetViewBinding_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMVVMToolset_RemoveWidgetViewBinding_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMVVMToolset_RemoveWidgetViewBinding_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UMVVMToolset_RemoveWidgetViewBinding_Statics::MVVMToolset_eventRemoveWidgetViewBinding_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMVVMToolset_RemoveWidgetViewBinding()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMVVMToolset_RemoveWidgetViewBinding_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMVVMToolset::execRemoveWidgetViewBinding)
{
	P_GET_OBJECT(UWidgetBlueprint,Z_Param_WidgetBlueprint);
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_BindingID);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UMVVMToolset::RemoveWidgetViewBinding(Z_Param_WidgetBlueprint,Z_Param_Out_BindingID);
	P_NATIVE_END;
}
// ********** End Class UMVVMToolset Function RemoveWidgetViewBinding ******************************

// ********** Begin Class UMVVMToolset *************************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UMVVMToolset;
UClass* UMVVMToolset::GetPrivateStaticClass()
{
	using TClass = UMVVMToolset;
	if (!Z_Registration_Info_UClass_UMVVMToolset.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("MVVMToolset"),
			Z_Registration_Info_UClass_UMVVMToolset.InnerSingleton,
			StaticRegisterNativesUMVVMToolset,
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
	return Z_Registration_Info_UClass_UMVVMToolset.InnerSingleton;
}
UClass* Z_Construct_UClass_UMVVMToolset_NoRegister()
{
	return UMVVMToolset::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UMVVMToolset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "MVVMToolset/MVVMToolset.h" },
		{ "ModuleRelativePath", "Private/MVVMToolset/MVVMToolset.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UMVVMToolset constinit property declarations *****************************
// ********** End Class UMVVMToolset constinit property declarations *******************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AddViewModelProperty"), .Pointer = &UMVVMToolset::execAddViewModelProperty },
		{ .NameUTF8 = UTF8TEXT("AddViewModelToWidget"), .Pointer = &UMVVMToolset::execAddViewModelToWidget },
		{ .NameUTF8 = UTF8TEXT("CreateViewBinding"), .Pointer = &UMVVMToolset::execCreateViewBinding },
		{ .NameUTF8 = UTF8TEXT("CreateViewModel"), .Pointer = &UMVVMToolset::execCreateViewModel },
		{ .NameUTF8 = UTF8TEXT("ListConversionFunctions"), .Pointer = &UMVVMToolset::execListConversionFunctions },
		{ .NameUTF8 = UTF8TEXT("ListViewModels"), .Pointer = &UMVVMToolset::execListViewModels },
		{ .NameUTF8 = UTF8TEXT("ListWidgetViewBindings"), .Pointer = &UMVVMToolset::execListWidgetViewBindings },
		{ .NameUTF8 = UTF8TEXT("ListWidgetViewModels"), .Pointer = &UMVVMToolset::execListWidgetViewModels },
		{ .NameUTF8 = UTF8TEXT("RemoveWidgetViewBinding"), .Pointer = &UMVVMToolset::execRemoveWidgetViewBinding },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMVVMToolset_AddViewModelProperty, "AddViewModelProperty" }, // 169684173
		{ &Z_Construct_UFunction_UMVVMToolset_AddViewModelToWidget, "AddViewModelToWidget" }, // 2452313836
		{ &Z_Construct_UFunction_UMVVMToolset_CreateViewBinding, "CreateViewBinding" }, // 1174487664
		{ &Z_Construct_UFunction_UMVVMToolset_CreateViewModel, "CreateViewModel" }, // 2989611182
		{ &Z_Construct_UFunction_UMVVMToolset_ListConversionFunctions, "ListConversionFunctions" }, // 3317983738
		{ &Z_Construct_UFunction_UMVVMToolset_ListViewModels, "ListViewModels" }, // 246880663
		{ &Z_Construct_UFunction_UMVVMToolset_ListWidgetViewBindings, "ListWidgetViewBindings" }, // 1764675205
		{ &Z_Construct_UFunction_UMVVMToolset_ListWidgetViewModels, "ListWidgetViewModels" }, // 1231384776
		{ &Z_Construct_UFunction_UMVVMToolset_RemoveWidgetViewBinding, "RemoveWidgetViewBinding" }, // 3449474582
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMVVMToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UMVVMToolset_Statics
UObject* (*const Z_Construct_UClass_UMVVMToolset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UToolsetDefinition,
	(UObject* (*)())Z_Construct_UPackage__Script_MVVMToolset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMVVMToolset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMVVMToolset_Statics::ClassParams = {
	&UMVVMToolset::StaticClass,
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
	0x010000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMVVMToolset_Statics::Class_MetaDataParams), Z_Construct_UClass_UMVVMToolset_Statics::Class_MetaDataParams)
};
void UMVVMToolset::StaticRegisterNativesUMVVMToolset()
{
	UClass* Class = UMVVMToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UMVVMToolset_Statics::Funcs));
}
UClass* Z_Construct_UClass_UMVVMToolset()
{
	if (!Z_Registration_Info_UClass_UMVVMToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMVVMToolset.OuterSingleton, Z_Construct_UClass_UMVVMToolset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMVVMToolset.OuterSingleton;
}
UMVVMToolset::UMVVMToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UMVVMToolset);
UMVVMToolset::~UMVVMToolset() {}
// ********** End Class UMVVMToolset ***************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_MVVMToolset_Source_MVVMToolset_Private_MVVMToolset_MVVMToolset_h__Script_MVVMToolset_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FMVVMViewConversionFunctionDescription::StaticStruct, Z_Construct_UScriptStruct_FMVVMViewConversionFunctionDescription_Statics::NewStructOps, TEXT("MVVMViewConversionFunctionDescription"),&Z_Registration_Info_UScriptStruct_FMVVMViewConversionFunctionDescription, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMVVMViewConversionFunctionDescription), 1959060471U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMVVMToolset, UMVVMToolset::StaticClass, TEXT("UMVVMToolset"), &Z_Registration_Info_UClass_UMVVMToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMVVMToolset), 2422498146U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_MVVMToolset_Source_MVVMToolset_Private_MVVMToolset_MVVMToolset_h__Script_MVVMToolset_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_MVVMToolset_Source_MVVMToolset_Private_MVVMToolset_MVVMToolset_h__Script_MVVMToolset_310769459{
	TEXT("/Script/MVVMToolset"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_MVVMToolset_Source_MVVMToolset_Private_MVVMToolset_MVVMToolset_h__Script_MVVMToolset_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_MVVMToolset_Source_MVVMToolset_Private_MVVMToolset_MVVMToolset_h__Script_MVVMToolset_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_MVVMToolset_Source_MVVMToolset_Private_MVVMToolset_MVVMToolset_h__Script_MVVMToolset_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_MVVMToolset_Source_MVVMToolset_Private_MVVMToolset_MVVMToolset_h__Script_MVVMToolset_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
