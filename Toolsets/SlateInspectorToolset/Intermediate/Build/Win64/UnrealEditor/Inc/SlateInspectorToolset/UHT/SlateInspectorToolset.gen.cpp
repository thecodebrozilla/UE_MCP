// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SlateInspectorToolset.h"
#include "ToolsetRegistry/ToolsetImage.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSlateInspectorToolset() {}

// ********** Begin Cross Module References ********************************************************
SLATEINSPECTORTOOLSET_API UClass* Z_Construct_UClass_USlateInspectorToolset();
SLATEINSPECTORTOOLSET_API UClass* Z_Construct_UClass_USlateInspectorToolset_NoRegister();
SLATEINSPECTORTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FSlateInspectorToolsetFormField();
SLATEINSPECTORTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition();
TOOLSETREGISTRY_API UScriptStruct* Z_Construct_UScriptStruct_FToolsetImage();
UPackage* Z_Construct_UPackage__Script_SlateInspectorToolset();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FSlateInspectorToolsetModifierKeys ********************************
struct Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FSlateInspectorToolsetModifierKeys); }
	static inline consteval int16 GetStructAlignment() { return alignof(FSlateInspectorToolsetModifierKeys); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Modifier keys held during an input simulation (click, drag, etc.). */" },
#endif
		{ "ModuleRelativePath", "Public/SlateInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Modifier keys held during an input simulation (click, drag, etc.)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShift_MetaData[] = {
		{ "Category", "SlateInspectorToolset" },
		{ "ModuleRelativePath", "Public/SlateInspectorToolset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCtrl_MetaData[] = {
		{ "Category", "SlateInspectorToolset" },
		{ "ModuleRelativePath", "Public/SlateInspectorToolset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAlt_MetaData[] = {
		{ "Category", "SlateInspectorToolset" },
		{ "ModuleRelativePath", "Public/SlateInspectorToolset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCmd_MetaData[] = {
		{ "Category", "SlateInspectorToolset" },
		{ "ModuleRelativePath", "Public/SlateInspectorToolset.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FSlateInspectorToolsetModifierKeys constinit property declarations 
	static void NewProp_bShift_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShift;
	static void NewProp_bCtrl_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCtrl;
	static void NewProp_bAlt_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAlt;
	static void NewProp_bCmd_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCmd;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FSlateInspectorToolsetModifierKeys constinit property declarations **
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSlateInspectorToolsetModifierKeys>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FSlateInspectorToolsetModifierKeys;
class UScriptStruct* FSlateInspectorToolsetModifierKeys::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FSlateInspectorToolsetModifierKeys.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FSlateInspectorToolsetModifierKeys.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys, (UObject*)Z_Construct_UPackage__Script_SlateInspectorToolset(), TEXT("SlateInspectorToolsetModifierKeys"));
	}
	return Z_Registration_Info_UScriptStruct_FSlateInspectorToolsetModifierKeys.OuterSingleton;
	}

// ********** Begin ScriptStruct FSlateInspectorToolsetModifierKeys Property Definitions ***********
void Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys_Statics::NewProp_bShift_SetBit(void* Obj)
{
	((FSlateInspectorToolsetModifierKeys*)Obj)->bShift = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys_Statics::NewProp_bShift = { "bShift", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FSlateInspectorToolsetModifierKeys), &Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys_Statics::NewProp_bShift_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShift_MetaData), NewProp_bShift_MetaData) };
void Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys_Statics::NewProp_bCtrl_SetBit(void* Obj)
{
	((FSlateInspectorToolsetModifierKeys*)Obj)->bCtrl = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys_Statics::NewProp_bCtrl = { "bCtrl", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FSlateInspectorToolsetModifierKeys), &Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys_Statics::NewProp_bCtrl_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCtrl_MetaData), NewProp_bCtrl_MetaData) };
void Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys_Statics::NewProp_bAlt_SetBit(void* Obj)
{
	((FSlateInspectorToolsetModifierKeys*)Obj)->bAlt = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys_Statics::NewProp_bAlt = { "bAlt", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FSlateInspectorToolsetModifierKeys), &Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys_Statics::NewProp_bAlt_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAlt_MetaData), NewProp_bAlt_MetaData) };
void Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys_Statics::NewProp_bCmd_SetBit(void* Obj)
{
	((FSlateInspectorToolsetModifierKeys*)Obj)->bCmd = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys_Statics::NewProp_bCmd = { "bCmd", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FSlateInspectorToolsetModifierKeys), &Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys_Statics::NewProp_bCmd_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCmd_MetaData), NewProp_bCmd_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys_Statics::NewProp_bShift,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys_Statics::NewProp_bCtrl,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys_Statics::NewProp_bAlt,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys_Statics::NewProp_bCmd,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FSlateInspectorToolsetModifierKeys Property Definitions *************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_SlateInspectorToolset,
	nullptr,
	&NewStructOps,
	"SlateInspectorToolsetModifierKeys",
	Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys_Statics::PropPointers),
	sizeof(FSlateInspectorToolsetModifierKeys),
	alignof(FSlateInspectorToolsetModifierKeys),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys()
{
	if (!Z_Registration_Info_UScriptStruct_FSlateInspectorToolsetModifierKeys.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FSlateInspectorToolsetModifierKeys.InnerSingleton, Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FSlateInspectorToolsetModifierKeys.InnerSingleton);
}
// ********** End ScriptStruct FSlateInspectorToolsetModifierKeys **********************************

// ********** Begin ScriptStruct FSlateInspectorToolsetFormField ***********************************
struct Z_Construct_UScriptStruct_FSlateInspectorToolsetFormField_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FSlateInspectorToolsetFormField); }
	static inline consteval int16 GetStructAlignment() { return alignof(FSlateInspectorToolsetFormField); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Describes a single form field for the FillForm tool. */" },
#endif
		{ "ModuleRelativePath", "Public/SlateInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Describes a single form field for the FillForm tool." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Ref_MetaData[] = {
		{ "Category", "SlateInspectorToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The ref identifier of the form field widget. */" },
#endif
		{ "ModuleRelativePath", "Public/SlateInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The ref identifier of the form field widget." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "Category", "SlateInspectorToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The value to set. */" },
#endif
		{ "ModuleRelativePath", "Public/SlateInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The value to set." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldType_MetaData[] = {
		{ "Category", "SlateInspectorToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The type of field: \"textbox\", \"checkbox\", or \"combobox\". */" },
#endif
		{ "ModuleRelativePath", "Public/SlateInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The type of field: \"textbox\", \"checkbox\", or \"combobox\"." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FSlateInspectorToolsetFormField constinit property declarations ***
	static const UECodeGen_Private::FStrPropertyParams NewProp_Ref;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Value;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FSlateInspectorToolsetFormField constinit property declarations *****
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSlateInspectorToolsetFormField>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FSlateInspectorToolsetFormField_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FSlateInspectorToolsetFormField;
class UScriptStruct* FSlateInspectorToolsetFormField::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FSlateInspectorToolsetFormField.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FSlateInspectorToolsetFormField.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSlateInspectorToolsetFormField, (UObject*)Z_Construct_UPackage__Script_SlateInspectorToolset(), TEXT("SlateInspectorToolsetFormField"));
	}
	return Z_Registration_Info_UScriptStruct_FSlateInspectorToolsetFormField.OuterSingleton;
	}

// ********** Begin ScriptStruct FSlateInspectorToolsetFormField Property Definitions **************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSlateInspectorToolsetFormField_Statics::NewProp_Ref = { "Ref", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSlateInspectorToolsetFormField, Ref), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Ref_MetaData), NewProp_Ref_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSlateInspectorToolsetFormField_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSlateInspectorToolsetFormField, Value), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSlateInspectorToolsetFormField_Statics::NewProp_FieldType = { "FieldType", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSlateInspectorToolsetFormField, FieldType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldType_MetaData), NewProp_FieldType_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSlateInspectorToolsetFormField_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSlateInspectorToolsetFormField_Statics::NewProp_Ref,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSlateInspectorToolsetFormField_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSlateInspectorToolsetFormField_Statics::NewProp_FieldType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSlateInspectorToolsetFormField_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FSlateInspectorToolsetFormField Property Definitions ****************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSlateInspectorToolsetFormField_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_SlateInspectorToolset,
	nullptr,
	&NewStructOps,
	"SlateInspectorToolsetFormField",
	Z_Construct_UScriptStruct_FSlateInspectorToolsetFormField_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSlateInspectorToolsetFormField_Statics::PropPointers),
	sizeof(FSlateInspectorToolsetFormField),
	alignof(FSlateInspectorToolsetFormField),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSlateInspectorToolsetFormField_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSlateInspectorToolsetFormField_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSlateInspectorToolsetFormField()
{
	if (!Z_Registration_Info_UScriptStruct_FSlateInspectorToolsetFormField.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FSlateInspectorToolsetFormField.InnerSingleton, Z_Construct_UScriptStruct_FSlateInspectorToolsetFormField_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FSlateInspectorToolsetFormField.InnerSingleton);
}
// ********** End ScriptStruct FSlateInspectorToolsetFormField *************************************

// ********** Begin Class USlateInspectorToolset Function Click ************************************
struct Z_Construct_UFunction_USlateInspectorToolset_Click_Statics
{
	struct SlateInspectorToolset_eventClick_Parms
	{
		FString Ref;
		FString Button;
		bool DoubleClick;
		FSlateInspectorToolsetModifierKeys Modifiers;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "SlateInspectorToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Click a Slate widget identified by its ref.\n\x09 * @param Ref         Slate widget ref.\n\x09 * @param Button      \"left\", \"right\", or \"middle\".\n\x09 * @param DoubleClick True for double-click.\n\x09 * @param Modifiers   Modifier keys held during the click. */" },
#endif
		{ "ModuleRelativePath", "Public/SlateInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Click a Slate widget identified by its ref.\n@param Ref         Slate widget ref.\n@param Button      \"left\", \"right\", or \"middle\".\n@param DoubleClick True for double-click.\n@param Modifiers   Modifier keys held during the click." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Ref_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Button_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Modifiers_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function Click constinit property declarations *********************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Ref;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Button;
	static void NewProp_DoubleClick_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_DoubleClick;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Modifiers;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Click constinit property declarations ***********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Click Property Definitions ********************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USlateInspectorToolset_Click_Statics::NewProp_Ref = { "Ref", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SlateInspectorToolset_eventClick_Parms, Ref), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Ref_MetaData), NewProp_Ref_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USlateInspectorToolset_Click_Statics::NewProp_Button = { "Button", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SlateInspectorToolset_eventClick_Parms, Button), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Button_MetaData), NewProp_Button_MetaData) };
void Z_Construct_UFunction_USlateInspectorToolset_Click_Statics::NewProp_DoubleClick_SetBit(void* Obj)
{
	((SlateInspectorToolset_eventClick_Parms*)Obj)->DoubleClick = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlateInspectorToolset_Click_Statics::NewProp_DoubleClick = { "DoubleClick", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SlateInspectorToolset_eventClick_Parms), &Z_Construct_UFunction_USlateInspectorToolset_Click_Statics::NewProp_DoubleClick_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlateInspectorToolset_Click_Statics::NewProp_Modifiers = { "Modifiers", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SlateInspectorToolset_eventClick_Parms, Modifiers), Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Modifiers_MetaData), NewProp_Modifiers_MetaData) }; // 4123751977
void Z_Construct_UFunction_USlateInspectorToolset_Click_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((SlateInspectorToolset_eventClick_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlateInspectorToolset_Click_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SlateInspectorToolset_eventClick_Parms), &Z_Construct_UFunction_USlateInspectorToolset_Click_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlateInspectorToolset_Click_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_Click_Statics::NewProp_Ref,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_Click_Statics::NewProp_Button,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_Click_Statics::NewProp_DoubleClick,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_Click_Statics::NewProp_Modifiers,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_Click_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_Click_Statics::PropPointers) < 2048);
// ********** End Function Click Property Definitions **********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlateInspectorToolset_Click_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USlateInspectorToolset, nullptr, "Click", 	Z_Construct_UFunction_USlateInspectorToolset_Click_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_Click_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USlateInspectorToolset_Click_Statics::SlateInspectorToolset_eventClick_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_Click_Statics::Function_MetaDataParams), Z_Construct_UFunction_USlateInspectorToolset_Click_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USlateInspectorToolset_Click_Statics::SlateInspectorToolset_eventClick_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USlateInspectorToolset_Click()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlateInspectorToolset_Click_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USlateInspectorToolset::execClick)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Ref);
	P_GET_PROPERTY(FStrProperty,Z_Param_Button);
	P_GET_UBOOL(Z_Param_DoubleClick);
	P_GET_STRUCT_REF(FSlateInspectorToolsetModifierKeys,Z_Param_Out_Modifiers);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=USlateInspectorToolset::Click(Z_Param_Ref,Z_Param_Button,Z_Param_DoubleClick,Z_Param_Out_Modifiers);
	P_NATIVE_END;
}
// ********** End Class USlateInspectorToolset Function Click **************************************

// ********** Begin Class USlateInspectorToolset Function Drag *************************************
struct Z_Construct_UFunction_USlateInspectorToolset_Drag_Statics
{
	struct SlateInspectorToolset_eventDrag_Parms
	{
		FString StartRef;
		FString EndRef;
		FSlateInspectorToolsetModifierKeys Modifiers;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "SlateInspectorToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Drag from one Slate widget to another (mouse down, move, release).\n\x09 * @param StartRef   Slate widget ref for the drag source.\n\x09 * @param EndRef     Slate widget ref for the drop target.\n\x09 * @param Modifiers  Modifier keys held during the drag. */" },
#endif
		{ "ModuleRelativePath", "Public/SlateInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Drag from one Slate widget to another (mouse down, move, release).\n@param StartRef   Slate widget ref for the drag source.\n@param EndRef     Slate widget ref for the drop target.\n@param Modifiers  Modifier keys held during the drag." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartRef_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EndRef_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Modifiers_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function Drag constinit property declarations **********************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_StartRef;
	static const UECodeGen_Private::FStrPropertyParams NewProp_EndRef;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Modifiers;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Drag constinit property declarations ************************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Drag Property Definitions *********************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USlateInspectorToolset_Drag_Statics::NewProp_StartRef = { "StartRef", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SlateInspectorToolset_eventDrag_Parms, StartRef), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartRef_MetaData), NewProp_StartRef_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USlateInspectorToolset_Drag_Statics::NewProp_EndRef = { "EndRef", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SlateInspectorToolset_eventDrag_Parms, EndRef), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EndRef_MetaData), NewProp_EndRef_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlateInspectorToolset_Drag_Statics::NewProp_Modifiers = { "Modifiers", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SlateInspectorToolset_eventDrag_Parms, Modifiers), Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Modifiers_MetaData), NewProp_Modifiers_MetaData) }; // 4123751977
void Z_Construct_UFunction_USlateInspectorToolset_Drag_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((SlateInspectorToolset_eventDrag_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlateInspectorToolset_Drag_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SlateInspectorToolset_eventDrag_Parms), &Z_Construct_UFunction_USlateInspectorToolset_Drag_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlateInspectorToolset_Drag_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_Drag_Statics::NewProp_StartRef,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_Drag_Statics::NewProp_EndRef,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_Drag_Statics::NewProp_Modifiers,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_Drag_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_Drag_Statics::PropPointers) < 2048);
// ********** End Function Drag Property Definitions ***********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlateInspectorToolset_Drag_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USlateInspectorToolset, nullptr, "Drag", 	Z_Construct_UFunction_USlateInspectorToolset_Drag_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_Drag_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USlateInspectorToolset_Drag_Statics::SlateInspectorToolset_eventDrag_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_Drag_Statics::Function_MetaDataParams), Z_Construct_UFunction_USlateInspectorToolset_Drag_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USlateInspectorToolset_Drag_Statics::SlateInspectorToolset_eventDrag_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USlateInspectorToolset_Drag()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlateInspectorToolset_Drag_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USlateInspectorToolset::execDrag)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_StartRef);
	P_GET_PROPERTY(FStrProperty,Z_Param_EndRef);
	P_GET_STRUCT_REF(FSlateInspectorToolsetModifierKeys,Z_Param_Out_Modifiers);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=USlateInspectorToolset::Drag(Z_Param_StartRef,Z_Param_EndRef,Z_Param_Out_Modifiers);
	P_NATIVE_END;
}
// ********** End Class USlateInspectorToolset Function Drag ***************************************

// ********** Begin Class USlateInspectorToolset Function FillForm *********************************
struct Z_Construct_UFunction_USlateInspectorToolset_FillForm_Statics
{
	struct SlateInspectorToolset_eventFillForm_Parms
	{
		TArray<FSlateInspectorToolsetFormField> Fields;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "SlateInspectorToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fill multiple Slate form fields at once.\n\x09 * @param Fields  Array of {Ref, Value, FieldType} where FieldType is\n\x09 *                \"textbox\", \"checkbox\", or \"combobox\". */" },
#endif
		{ "ModuleRelativePath", "Public/SlateInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fill multiple Slate form fields at once.\n@param Fields  Array of {Ref, Value, FieldType} where FieldType is\n              \"textbox\", \"checkbox\", or \"combobox\"." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Fields_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function FillForm constinit property declarations ******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Fields_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Fields;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FillForm constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FillForm Property Definitions *****************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlateInspectorToolset_FillForm_Statics::NewProp_Fields_Inner = { "Fields", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FSlateInspectorToolsetFormField, METADATA_PARAMS(0, nullptr) }; // 3427158049
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USlateInspectorToolset_FillForm_Statics::NewProp_Fields = { "Fields", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SlateInspectorToolset_eventFillForm_Parms, Fields), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Fields_MetaData), NewProp_Fields_MetaData) }; // 3427158049
void Z_Construct_UFunction_USlateInspectorToolset_FillForm_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((SlateInspectorToolset_eventFillForm_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlateInspectorToolset_FillForm_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SlateInspectorToolset_eventFillForm_Parms), &Z_Construct_UFunction_USlateInspectorToolset_FillForm_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlateInspectorToolset_FillForm_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_FillForm_Statics::NewProp_Fields_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_FillForm_Statics::NewProp_Fields,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_FillForm_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_FillForm_Statics::PropPointers) < 2048);
// ********** End Function FillForm Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlateInspectorToolset_FillForm_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USlateInspectorToolset, nullptr, "FillForm", 	Z_Construct_UFunction_USlateInspectorToolset_FillForm_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_FillForm_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USlateInspectorToolset_FillForm_Statics::SlateInspectorToolset_eventFillForm_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_FillForm_Statics::Function_MetaDataParams), Z_Construct_UFunction_USlateInspectorToolset_FillForm_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USlateInspectorToolset_FillForm_Statics::SlateInspectorToolset_eventFillForm_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USlateInspectorToolset_FillForm()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlateInspectorToolset_FillForm_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USlateInspectorToolset::execFillForm)
{
	P_GET_TARRAY_REF(FSlateInspectorToolsetFormField,Z_Param_Out_Fields);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=USlateInspectorToolset::FillForm(Z_Param_Out_Fields);
	P_NATIVE_END;
}
// ********** End Class USlateInspectorToolset Function FillForm ***********************************

// ********** Begin Class USlateInspectorToolset Function Hover ************************************
struct Z_Construct_UFunction_USlateInspectorToolset_Hover_Statics
{
	struct SlateInspectorToolset_eventHover_Parms
	{
		FString Ref;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "SlateInspectorToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Hover over a Slate widget, triggering any hover state or tooltip.\n\x09 * @param Ref  Slate widget ref. */" },
#endif
		{ "ModuleRelativePath", "Public/SlateInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Hover over a Slate widget, triggering any hover state or tooltip.\n@param Ref  Slate widget ref." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Ref_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function Hover constinit property declarations *********************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Ref;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Hover constinit property declarations ***********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Hover Property Definitions ********************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USlateInspectorToolset_Hover_Statics::NewProp_Ref = { "Ref", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SlateInspectorToolset_eventHover_Parms, Ref), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Ref_MetaData), NewProp_Ref_MetaData) };
void Z_Construct_UFunction_USlateInspectorToolset_Hover_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((SlateInspectorToolset_eventHover_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlateInspectorToolset_Hover_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SlateInspectorToolset_eventHover_Parms), &Z_Construct_UFunction_USlateInspectorToolset_Hover_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlateInspectorToolset_Hover_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_Hover_Statics::NewProp_Ref,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_Hover_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_Hover_Statics::PropPointers) < 2048);
// ********** End Function Hover Property Definitions **********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlateInspectorToolset_Hover_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USlateInspectorToolset, nullptr, "Hover", 	Z_Construct_UFunction_USlateInspectorToolset_Hover_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_Hover_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USlateInspectorToolset_Hover_Statics::SlateInspectorToolset_eventHover_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_Hover_Statics::Function_MetaDataParams), Z_Construct_UFunction_USlateInspectorToolset_Hover_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USlateInspectorToolset_Hover_Statics::SlateInspectorToolset_eventHover_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USlateInspectorToolset_Hover()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlateInspectorToolset_Hover_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USlateInspectorToolset::execHover)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Ref);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=USlateInspectorToolset::Hover(Z_Param_Ref);
	P_NATIVE_END;
}
// ********** End Class USlateInspectorToolset Function Hover **************************************

// ********** Begin Class USlateInspectorToolset Function ListObservers ****************************
struct Z_Construct_UFunction_USlateInspectorToolset_ListObservers_Statics
{
	struct SlateInspectorToolset_eventListObservers_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "SlateInspectorToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** List all active observers as a JSON array for debugging.\n\x09 * Each entry includes the observer identifier, whether it is the root observer,\n\x09 * the root widget ref (if any), max depth, and cached snapshot size. */" },
#endif
		{ "ModuleRelativePath", "Public/SlateInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "List all active observers as a JSON array for debugging.\nEach entry includes the observer identifier, whether it is the root observer,\nthe root widget ref (if any), max depth, and cached snapshot size." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ListObservers constinit property declarations *************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListObservers constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListObservers Property Definitions ************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USlateInspectorToolset_ListObservers_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SlateInspectorToolset_eventListObservers_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlateInspectorToolset_ListObservers_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_ListObservers_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_ListObservers_Statics::PropPointers) < 2048);
// ********** End Function ListObservers Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlateInspectorToolset_ListObservers_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USlateInspectorToolset, nullptr, "ListObservers", 	Z_Construct_UFunction_USlateInspectorToolset_ListObservers_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_ListObservers_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USlateInspectorToolset_ListObservers_Statics::SlateInspectorToolset_eventListObservers_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_ListObservers_Statics::Function_MetaDataParams), Z_Construct_UFunction_USlateInspectorToolset_ListObservers_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USlateInspectorToolset_ListObservers_Statics::SlateInspectorToolset_eventListObservers_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USlateInspectorToolset_ListObservers()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlateInspectorToolset_ListObservers_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USlateInspectorToolset::execListObservers)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=USlateInspectorToolset::ListObservers();
	P_NATIVE_END;
}
// ********** End Class USlateInspectorToolset Function ListObservers ******************************

// ********** Begin Class USlateInspectorToolset Function Observe **********************************
struct Z_Construct_UFunction_USlateInspectorToolset_Observe_Statics
{
	struct SlateInspectorToolset_eventObserve_Parms
	{
		FString Ref;
		int32 MaxDepth;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "SlateInspectorToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Register an observer on a widget subtree so its refs are continuously\n\x09 * kept up to date (~100ms tick).  Call this on the window or panel you are\n\x09 * about to work with. It ensures new widgets appearing in that subtree\n\x09 * are assigned refs automatically.  Unobserve when you are done.\n\x09 * A shallow root observer (depth 0) already covers top-level windows.\n\x09 * @param Ref       Root widget ref to observe. Empty = all visible windows.\n\x09 * @param MaxDepth  Maximum depth to walk from the root. */" },
#endif
		{ "ModuleRelativePath", "Public/SlateInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Register an observer on a widget subtree so its refs are continuously\nkept up to date (~100ms tick).  Call this on the window or panel you are\nabout to work with. It ensures new widgets appearing in that subtree\nare assigned refs automatically.  Unobserve when you are done.\nA shallow root observer (depth 0) already covers top-level windows.\n@param Ref       Root widget ref to observe. Empty = all visible windows.\n@param MaxDepth  Maximum depth to walk from the root." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Ref_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function Observe constinit property declarations *******************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Ref;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxDepth;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Observe constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Observe Property Definitions ******************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USlateInspectorToolset_Observe_Statics::NewProp_Ref = { "Ref", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SlateInspectorToolset_eventObserve_Parms, Ref), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Ref_MetaData), NewProp_Ref_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USlateInspectorToolset_Observe_Statics::NewProp_MaxDepth = { "MaxDepth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SlateInspectorToolset_eventObserve_Parms, MaxDepth), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USlateInspectorToolset_Observe_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SlateInspectorToolset_eventObserve_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlateInspectorToolset_Observe_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_Observe_Statics::NewProp_Ref,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_Observe_Statics::NewProp_MaxDepth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_Observe_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_Observe_Statics::PropPointers) < 2048);
// ********** End Function Observe Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlateInspectorToolset_Observe_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USlateInspectorToolset, nullptr, "Observe", 	Z_Construct_UFunction_USlateInspectorToolset_Observe_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_Observe_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USlateInspectorToolset_Observe_Statics::SlateInspectorToolset_eventObserve_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_Observe_Statics::Function_MetaDataParams), Z_Construct_UFunction_USlateInspectorToolset_Observe_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USlateInspectorToolset_Observe_Statics::SlateInspectorToolset_eventObserve_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USlateInspectorToolset_Observe()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlateInspectorToolset_Observe_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USlateInspectorToolset::execObserve)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Ref);
	P_GET_PROPERTY(FIntProperty,Z_Param_MaxDepth);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=USlateInspectorToolset::Observe(Z_Param_Ref,Z_Param_MaxDepth);
	P_NATIVE_END;
}
// ********** End Class USlateInspectorToolset Function Observe ************************************

// ********** Begin Class USlateInspectorToolset Function PressKey *********************************
struct Z_Construct_UFunction_USlateInspectorToolset_PressKey_Statics
{
	struct SlateInspectorToolset_eventPressKey_Parms
	{
		FString Key;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "SlateInspectorToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Press and release a keyboard key on the currently focused Slate widget.\n\x09 * Supports modifier prefixes: \"Ctrl+C\", \"Shift+1\".\n\x09 * @param Key  Key name with optional modifiers, e.g. \"Enter\", \"Ctrl+A\", \"Shift+Tab\". */" },
#endif
		{ "ModuleRelativePath", "Public/SlateInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Press and release a keyboard key on the currently focused Slate widget.\nSupports modifier prefixes: \"Ctrl+C\", \"Shift+1\".\n@param Key  Key name with optional modifiers, e.g. \"Enter\", \"Ctrl+A\", \"Shift+Tab\"." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Key_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function PressKey constinit property declarations ******************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Key;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function PressKey constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function PressKey Property Definitions *****************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USlateInspectorToolset_PressKey_Statics::NewProp_Key = { "Key", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SlateInspectorToolset_eventPressKey_Parms, Key), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Key_MetaData), NewProp_Key_MetaData) };
void Z_Construct_UFunction_USlateInspectorToolset_PressKey_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((SlateInspectorToolset_eventPressKey_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlateInspectorToolset_PressKey_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SlateInspectorToolset_eventPressKey_Parms), &Z_Construct_UFunction_USlateInspectorToolset_PressKey_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlateInspectorToolset_PressKey_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_PressKey_Statics::NewProp_Key,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_PressKey_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_PressKey_Statics::PropPointers) < 2048);
// ********** End Function PressKey Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlateInspectorToolset_PressKey_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USlateInspectorToolset, nullptr, "PressKey", 	Z_Construct_UFunction_USlateInspectorToolset_PressKey_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_PressKey_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USlateInspectorToolset_PressKey_Statics::SlateInspectorToolset_eventPressKey_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_PressKey_Statics::Function_MetaDataParams), Z_Construct_UFunction_USlateInspectorToolset_PressKey_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USlateInspectorToolset_PressKey_Statics::SlateInspectorToolset_eventPressKey_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USlateInspectorToolset_PressKey()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlateInspectorToolset_PressKey_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USlateInspectorToolset::execPressKey)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Key);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=USlateInspectorToolset::PressKey(Z_Param_Key);
	P_NATIVE_END;
}
// ********** End Class USlateInspectorToolset Function PressKey ***********************************

// ********** Begin Class USlateInspectorToolset Function Screenshot *******************************
struct Z_Construct_UFunction_USlateInspectorToolset_Screenshot_Statics
{
	struct SlateInspectorToolset_eventScreenshot_Parms
	{
		FString Ref;
		FToolsetImage ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "SlateInspectorToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Screenshot a Slate widget or the active editor window. Prefer this over\n\x09 * SceneTools.take_screenshot for Editor UI; use SceneTools only for 3D viewport.\n\x09 * @param Ref  Slate widget ref. Empty = active window. */" },
#endif
		{ "ModuleRelativePath", "Public/SlateInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Screenshot a Slate widget or the active editor window. Prefer this over\nSceneTools.take_screenshot for Editor UI; use SceneTools only for 3D viewport.\n@param Ref  Slate widget ref. Empty = active window." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Ref_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function Screenshot constinit property declarations ****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Ref;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Screenshot constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Screenshot Property Definitions ***************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USlateInspectorToolset_Screenshot_Statics::NewProp_Ref = { "Ref", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SlateInspectorToolset_eventScreenshot_Parms, Ref), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Ref_MetaData), NewProp_Ref_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlateInspectorToolset_Screenshot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SlateInspectorToolset_eventScreenshot_Parms, ReturnValue), Z_Construct_UScriptStruct_FToolsetImage, METADATA_PARAMS(0, nullptr) }; // 1290813077
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlateInspectorToolset_Screenshot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_Screenshot_Statics::NewProp_Ref,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_Screenshot_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_Screenshot_Statics::PropPointers) < 2048);
// ********** End Function Screenshot Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlateInspectorToolset_Screenshot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USlateInspectorToolset, nullptr, "Screenshot", 	Z_Construct_UFunction_USlateInspectorToolset_Screenshot_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_Screenshot_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USlateInspectorToolset_Screenshot_Statics::SlateInspectorToolset_eventScreenshot_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_Screenshot_Statics::Function_MetaDataParams), Z_Construct_UFunction_USlateInspectorToolset_Screenshot_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USlateInspectorToolset_Screenshot_Statics::SlateInspectorToolset_eventScreenshot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USlateInspectorToolset_Screenshot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlateInspectorToolset_Screenshot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USlateInspectorToolset::execScreenshot)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Ref);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FToolsetImage*)Z_Param__Result=USlateInspectorToolset::Screenshot(Z_Param_Ref);
	P_NATIVE_END;
}
// ********** End Class USlateInspectorToolset Function Screenshot *********************************

// ********** Begin Class USlateInspectorToolset Function SelectOption *****************************
struct Z_Construct_UFunction_USlateInspectorToolset_SelectOption_Statics
{
	struct SlateInspectorToolset_eventSelectOption_Parms
	{
		FString Ref;
		FString Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "SlateInspectorToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Select an option in a Slate combobox by its text label.\n\x09 * Opens the dropdown, finds the matching text, and clicks it.\n\x09 * @param Ref    Slate combobox ref.\n\x09 * @param Value  Exact option text to select. */" },
#endif
		{ "ModuleRelativePath", "Public/SlateInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Select an option in a Slate combobox by its text label.\nOpens the dropdown, finds the matching text, and clicks it.\n@param Ref    Slate combobox ref.\n@param Value  Exact option text to select." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Ref_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SelectOption constinit property declarations **************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Ref;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SelectOption constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SelectOption Property Definitions *************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USlateInspectorToolset_SelectOption_Statics::NewProp_Ref = { "Ref", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SlateInspectorToolset_eventSelectOption_Parms, Ref), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Ref_MetaData), NewProp_Ref_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USlateInspectorToolset_SelectOption_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SlateInspectorToolset_eventSelectOption_Parms, Value), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
void Z_Construct_UFunction_USlateInspectorToolset_SelectOption_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((SlateInspectorToolset_eventSelectOption_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlateInspectorToolset_SelectOption_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SlateInspectorToolset_eventSelectOption_Parms), &Z_Construct_UFunction_USlateInspectorToolset_SelectOption_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlateInspectorToolset_SelectOption_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_SelectOption_Statics::NewProp_Ref,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_SelectOption_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_SelectOption_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_SelectOption_Statics::PropPointers) < 2048);
// ********** End Function SelectOption Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlateInspectorToolset_SelectOption_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USlateInspectorToolset, nullptr, "SelectOption", 	Z_Construct_UFunction_USlateInspectorToolset_SelectOption_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_SelectOption_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USlateInspectorToolset_SelectOption_Statics::SlateInspectorToolset_eventSelectOption_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_SelectOption_Statics::Function_MetaDataParams), Z_Construct_UFunction_USlateInspectorToolset_SelectOption_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USlateInspectorToolset_SelectOption_Statics::SlateInspectorToolset_eventSelectOption_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USlateInspectorToolset_SelectOption()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlateInspectorToolset_SelectOption_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USlateInspectorToolset::execSelectOption)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Ref);
	P_GET_PROPERTY(FStrProperty,Z_Param_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=USlateInspectorToolset::SelectOption(Z_Param_Ref,Z_Param_Value);
	P_NATIVE_END;
}
// ********** End Class USlateInspectorToolset Function SelectOption *******************************

// ********** Begin Class USlateInspectorToolset Function Snapshot *********************************
struct Z_Construct_UFunction_USlateInspectorToolset_Snapshot_Statics
{
	struct SlateInspectorToolset_eventSnapshot_Parms
	{
		FString Ref;
		int32 MaxDepth;
		bool bIncludeSourceLocations;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "SlateInspectorToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Capture a Slate UI accessibility snapshot.  Use this to read the current\n\x09 * widget tree and discover refs for action tools (Click, Type, Hover, etc.).\n\x09 * A shallow root observer (depth 0) covers top-level windows automatically.\n\x09 * Before interacting with a specific window or panel, call Observe() on it\n\x09 * to get deep coverage, then Snapshot that subtree to see its contents.\n\x09 * Refs discovered by a previous Snapshot remain usable. You do NOT need to\n\x09 * call Snapshot again before every action.\n\x09 * @param Ref                      Subtree root ref. Empty = all windows.\n\x09 * @param MaxDepth                 Maximum depth (default 30).\n\x09 * @param bIncludeSourceLocations  Include [src=File:Line] tags showing where each widget was created in C++. */" },
#endif
		{ "ModuleRelativePath", "Public/SlateInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Capture a Slate UI accessibility snapshot.  Use this to read the current\nwidget tree and discover refs for action tools (Click, Type, Hover, etc.).\nA shallow root observer (depth 0) covers top-level windows automatically.\nBefore interacting with a specific window or panel, call Observe() on it\nto get deep coverage, then Snapshot that subtree to see its contents.\nRefs discovered by a previous Snapshot remain usable. You do NOT need to\ncall Snapshot again before every action.\n@param Ref                      Subtree root ref. Empty = all windows.\n@param MaxDepth                 Maximum depth (default 30).\n@param bIncludeSourceLocations  Include [src=File:Line] tags showing where each widget was created in C++." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Ref_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function Snapshot constinit property declarations ******************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Ref;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxDepth;
	static void NewProp_bIncludeSourceLocations_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIncludeSourceLocations;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Snapshot constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Snapshot Property Definitions *****************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USlateInspectorToolset_Snapshot_Statics::NewProp_Ref = { "Ref", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SlateInspectorToolset_eventSnapshot_Parms, Ref), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Ref_MetaData), NewProp_Ref_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USlateInspectorToolset_Snapshot_Statics::NewProp_MaxDepth = { "MaxDepth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SlateInspectorToolset_eventSnapshot_Parms, MaxDepth), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_USlateInspectorToolset_Snapshot_Statics::NewProp_bIncludeSourceLocations_SetBit(void* Obj)
{
	((SlateInspectorToolset_eventSnapshot_Parms*)Obj)->bIncludeSourceLocations = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlateInspectorToolset_Snapshot_Statics::NewProp_bIncludeSourceLocations = { "bIncludeSourceLocations", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SlateInspectorToolset_eventSnapshot_Parms), &Z_Construct_UFunction_USlateInspectorToolset_Snapshot_Statics::NewProp_bIncludeSourceLocations_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USlateInspectorToolset_Snapshot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SlateInspectorToolset_eventSnapshot_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlateInspectorToolset_Snapshot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_Snapshot_Statics::NewProp_Ref,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_Snapshot_Statics::NewProp_MaxDepth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_Snapshot_Statics::NewProp_bIncludeSourceLocations,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_Snapshot_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_Snapshot_Statics::PropPointers) < 2048);
// ********** End Function Snapshot Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlateInspectorToolset_Snapshot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USlateInspectorToolset, nullptr, "Snapshot", 	Z_Construct_UFunction_USlateInspectorToolset_Snapshot_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_Snapshot_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USlateInspectorToolset_Snapshot_Statics::SlateInspectorToolset_eventSnapshot_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_Snapshot_Statics::Function_MetaDataParams), Z_Construct_UFunction_USlateInspectorToolset_Snapshot_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USlateInspectorToolset_Snapshot_Statics::SlateInspectorToolset_eventSnapshot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USlateInspectorToolset_Snapshot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlateInspectorToolset_Snapshot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USlateInspectorToolset::execSnapshot)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Ref);
	P_GET_PROPERTY(FIntProperty,Z_Param_MaxDepth);
	P_GET_UBOOL(Z_Param_bIncludeSourceLocations);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=USlateInspectorToolset::Snapshot(Z_Param_Ref,Z_Param_MaxDepth,Z_Param_bIncludeSourceLocations);
	P_NATIVE_END;
}
// ********** End Class USlateInspectorToolset Function Snapshot ***********************************

// ********** Begin Class USlateInspectorToolset Function Type *************************************
struct Z_Construct_UFunction_USlateInspectorToolset_Type_Statics
{
	struct SlateInspectorToolset_eventType_Parms
	{
		FString Ref;
		FString Text;
		bool Submit;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "SlateInspectorToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Type text into a Slate text input widget. Focuses the widget first,\n\x09 * then sends one key event per character.\n\x09 * @param Ref    Slate textbox ref.\n\x09 * @param Text   Text to type.\n\x09 * @param Submit Press Enter after typing. */" },
#endif
		{ "ModuleRelativePath", "Public/SlateInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Type text into a Slate text input widget. Focuses the widget first,\nthen sends one key event per character.\n@param Ref    Slate textbox ref.\n@param Text   Text to type.\n@param Submit Press Enter after typing." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Ref_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function Type constinit property declarations **********************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Ref;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Text;
	static void NewProp_Submit_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_Submit;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Type constinit property declarations ************************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Type Property Definitions *********************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USlateInspectorToolset_Type_Statics::NewProp_Ref = { "Ref", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SlateInspectorToolset_eventType_Parms, Ref), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Ref_MetaData), NewProp_Ref_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USlateInspectorToolset_Type_Statics::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SlateInspectorToolset_eventType_Parms, Text), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_MetaData), NewProp_Text_MetaData) };
void Z_Construct_UFunction_USlateInspectorToolset_Type_Statics::NewProp_Submit_SetBit(void* Obj)
{
	((SlateInspectorToolset_eventType_Parms*)Obj)->Submit = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlateInspectorToolset_Type_Statics::NewProp_Submit = { "Submit", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SlateInspectorToolset_eventType_Parms), &Z_Construct_UFunction_USlateInspectorToolset_Type_Statics::NewProp_Submit_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_USlateInspectorToolset_Type_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((SlateInspectorToolset_eventType_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlateInspectorToolset_Type_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SlateInspectorToolset_eventType_Parms), &Z_Construct_UFunction_USlateInspectorToolset_Type_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlateInspectorToolset_Type_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_Type_Statics::NewProp_Ref,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_Type_Statics::NewProp_Text,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_Type_Statics::NewProp_Submit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_Type_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_Type_Statics::PropPointers) < 2048);
// ********** End Function Type Property Definitions ***********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlateInspectorToolset_Type_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USlateInspectorToolset, nullptr, "Type", 	Z_Construct_UFunction_USlateInspectorToolset_Type_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_Type_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USlateInspectorToolset_Type_Statics::SlateInspectorToolset_eventType_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_Type_Statics::Function_MetaDataParams), Z_Construct_UFunction_USlateInspectorToolset_Type_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USlateInspectorToolset_Type_Statics::SlateInspectorToolset_eventType_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USlateInspectorToolset_Type()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlateInspectorToolset_Type_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USlateInspectorToolset::execType)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Ref);
	P_GET_PROPERTY(FStrProperty,Z_Param_Text);
	P_GET_UBOOL(Z_Param_Submit);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=USlateInspectorToolset::Type(Z_Param_Ref,Z_Param_Text,Z_Param_Submit);
	P_NATIVE_END;
}
// ********** End Class USlateInspectorToolset Function Type ***************************************

// ********** Begin Class USlateInspectorToolset Function Unobserve ********************************
struct Z_Construct_UFunction_USlateInspectorToolset_Unobserve_Statics
{
	struct SlateInspectorToolset_eventUnobserve_Parms
	{
		FString Identifier;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "SlateInspectorToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Remove an observer by its identifier.\n\x09 * @param Identifier  The identifier returned by Observe(). */" },
#endif
		{ "ModuleRelativePath", "Public/SlateInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Remove an observer by its identifier.\n@param Identifier  The identifier returned by Observe()." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Identifier_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function Unobserve constinit property declarations *****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Identifier;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Unobserve constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Unobserve Property Definitions ****************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USlateInspectorToolset_Unobserve_Statics::NewProp_Identifier = { "Identifier", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SlateInspectorToolset_eventUnobserve_Parms, Identifier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Identifier_MetaData), NewProp_Identifier_MetaData) };
void Z_Construct_UFunction_USlateInspectorToolset_Unobserve_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((SlateInspectorToolset_eventUnobserve_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlateInspectorToolset_Unobserve_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SlateInspectorToolset_eventUnobserve_Parms), &Z_Construct_UFunction_USlateInspectorToolset_Unobserve_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlateInspectorToolset_Unobserve_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_Unobserve_Statics::NewProp_Identifier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_Unobserve_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_Unobserve_Statics::PropPointers) < 2048);
// ********** End Function Unobserve Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlateInspectorToolset_Unobserve_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USlateInspectorToolset, nullptr, "Unobserve", 	Z_Construct_UFunction_USlateInspectorToolset_Unobserve_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_Unobserve_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USlateInspectorToolset_Unobserve_Statics::SlateInspectorToolset_eventUnobserve_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_Unobserve_Statics::Function_MetaDataParams), Z_Construct_UFunction_USlateInspectorToolset_Unobserve_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USlateInspectorToolset_Unobserve_Statics::SlateInspectorToolset_eventUnobserve_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USlateInspectorToolset_Unobserve()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlateInspectorToolset_Unobserve_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USlateInspectorToolset::execUnobserve)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Identifier);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=USlateInspectorToolset::Unobserve(Z_Param_Identifier);
	P_NATIVE_END;
}
// ********** End Class USlateInspectorToolset Function Unobserve **********************************

// ********** Begin Class USlateInspectorToolset Function WaitFor **********************************
struct Z_Construct_UFunction_USlateInspectorToolset_WaitFor_Statics
{
	struct SlateInspectorToolset_eventWaitFor_Parms
	{
		FString Text;
		FString TextGone;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "SlateInspectorToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Check if text is present or absent in the Slate widget tree.\n\x09 * Non-blocking: checks once and returns immediately. Poll to wait.\n\x09 * @param Text       Text that must be present (empty = skip).\n\x09 * @param TextGone   Text that must be absent (empty = skip). */" },
#endif
		{ "ModuleRelativePath", "Public/SlateInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if text is present or absent in the Slate widget tree.\nNon-blocking: checks once and returns immediately. Poll to wait.\n@param Text       Text that must be present (empty = skip).\n@param TextGone   Text that must be absent (empty = skip)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextGone_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function WaitFor constinit property declarations *******************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Text;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TextGone;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function WaitFor constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function WaitFor Property Definitions ******************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USlateInspectorToolset_WaitFor_Statics::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SlateInspectorToolset_eventWaitFor_Parms, Text), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_MetaData), NewProp_Text_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USlateInspectorToolset_WaitFor_Statics::NewProp_TextGone = { "TextGone", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SlateInspectorToolset_eventWaitFor_Parms, TextGone), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextGone_MetaData), NewProp_TextGone_MetaData) };
void Z_Construct_UFunction_USlateInspectorToolset_WaitFor_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((SlateInspectorToolset_eventWaitFor_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlateInspectorToolset_WaitFor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SlateInspectorToolset_eventWaitFor_Parms), &Z_Construct_UFunction_USlateInspectorToolset_WaitFor_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlateInspectorToolset_WaitFor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_WaitFor_Statics::NewProp_Text,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_WaitFor_Statics::NewProp_TextGone,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_WaitFor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_WaitFor_Statics::PropPointers) < 2048);
// ********** End Function WaitFor Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlateInspectorToolset_WaitFor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USlateInspectorToolset, nullptr, "WaitFor", 	Z_Construct_UFunction_USlateInspectorToolset_WaitFor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_WaitFor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USlateInspectorToolset_WaitFor_Statics::SlateInspectorToolset_eventWaitFor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_WaitFor_Statics::Function_MetaDataParams), Z_Construct_UFunction_USlateInspectorToolset_WaitFor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USlateInspectorToolset_WaitFor_Statics::SlateInspectorToolset_eventWaitFor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USlateInspectorToolset_WaitFor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlateInspectorToolset_WaitFor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USlateInspectorToolset::execWaitFor)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Text);
	P_GET_PROPERTY(FStrProperty,Z_Param_TextGone);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=USlateInspectorToolset::WaitFor(Z_Param_Text,Z_Param_TextGone);
	P_NATIVE_END;
}
// ********** End Class USlateInspectorToolset Function WaitFor ************************************

// ********** Begin Class USlateInspectorToolset Function Windows **********************************
struct Z_Construct_UFunction_USlateInspectorToolset_Windows_Statics
{
	struct SlateInspectorToolset_eventWindows_Parms
	{
		FString Action;
		int32 Index;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "SlateInspectorToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** List, select, or close top-level Slate editor windows.\n\x09 * @param Action  \"list\" returns JSON array, \"select\" brings to front, \"close\" destroys.\n\x09 * @param Index   Window index for select/close. */" },
#endif
		{ "ModuleRelativePath", "Public/SlateInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "List, select, or close top-level Slate editor windows.\n@param Action  \"list\" returns JSON array, \"select\" brings to front, \"close\" destroys.\n@param Index   Window index for select/close." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Action_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function Windows constinit property declarations *******************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Action;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Windows constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Windows Property Definitions ******************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USlateInspectorToolset_Windows_Statics::NewProp_Action = { "Action", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SlateInspectorToolset_eventWindows_Parms, Action), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Action_MetaData), NewProp_Action_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USlateInspectorToolset_Windows_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SlateInspectorToolset_eventWindows_Parms, Index), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USlateInspectorToolset_Windows_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SlateInspectorToolset_eventWindows_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlateInspectorToolset_Windows_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_Windows_Statics::NewProp_Action,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_Windows_Statics::NewProp_Index,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlateInspectorToolset_Windows_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_Windows_Statics::PropPointers) < 2048);
// ********** End Function Windows Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlateInspectorToolset_Windows_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USlateInspectorToolset, nullptr, "Windows", 	Z_Construct_UFunction_USlateInspectorToolset_Windows_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_Windows_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USlateInspectorToolset_Windows_Statics::SlateInspectorToolset_eventWindows_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USlateInspectorToolset_Windows_Statics::Function_MetaDataParams), Z_Construct_UFunction_USlateInspectorToolset_Windows_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USlateInspectorToolset_Windows_Statics::SlateInspectorToolset_eventWindows_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USlateInspectorToolset_Windows()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlateInspectorToolset_Windows_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USlateInspectorToolset::execWindows)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Action);
	P_GET_PROPERTY(FIntProperty,Z_Param_Index);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=USlateInspectorToolset::Windows(Z_Param_Action,Z_Param_Index);
	P_NATIVE_END;
}
// ********** End Class USlateInspectorToolset Function Windows ************************************

// ********** Begin Class USlateInspectorToolset ***************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USlateInspectorToolset;
UClass* USlateInspectorToolset::GetPrivateStaticClass()
{
	using TClass = USlateInspectorToolset;
	if (!Z_Registration_Info_UClass_USlateInspectorToolset.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SlateInspectorToolset"),
			Z_Registration_Info_UClass_USlateInspectorToolset.InnerSingleton,
			StaticRegisterNativesUSlateInspectorToolset,
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
	return Z_Registration_Info_UClass_USlateInspectorToolset.InnerSingleton;
}
UClass* Z_Construct_UClass_USlateInspectorToolset_NoRegister()
{
	return USlateInspectorToolset::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USlateInspectorToolset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Playwright-style Slate UI automation toolset.\n *\n * Exposes snapshot, screenshot, and interaction tools for driving the\n * Unreal Editor UI programmatically.  Registered via UToolsetRegistry\n * so the ModelContextProtocol plugin picks them up automatically.\n *\n * A shallow root observer (depth 0) continuously tracks top-level\n * windows.  Before working with a specific window or panel, call\n * Observe() on it to get deep widget coverage, then Unobserve() when\n * done.  Observers walk their subtree every ~100ms, assigning refs to\n * newly appeared widgets and keeping the ref cache current.\n *\n * Input simulation uses direct Slate event APIs (ProcessKeyCharEvent,\n * ProcessMouseButtonDownEvent, etc.) rather than the AutomationDriver,\n * because AutomationDriver's synchronous API deadlocks when called from\n * the game thread (which is where MCP tool calls execute).\n */" },
#endif
		{ "IncludePath", "SlateInspectorToolset.h" },
		{ "ModuleRelativePath", "Public/SlateInspectorToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Playwright-style Slate UI automation toolset.\n\nExposes snapshot, screenshot, and interaction tools for driving the\nUnreal Editor UI programmatically.  Registered via UToolsetRegistry\nso the ModelContextProtocol plugin picks them up automatically.\n\nA shallow root observer (depth 0) continuously tracks top-level\nwindows.  Before working with a specific window or panel, call\nObserve() on it to get deep widget coverage, then Unobserve() when\ndone.  Observers walk their subtree every ~100ms, assigning refs to\nnewly appeared widgets and keeping the ref cache current.\n\nInput simulation uses direct Slate event APIs (ProcessKeyCharEvent,\nProcessMouseButtonDownEvent, etc.) rather than the AutomationDriver,\nbecause AutomationDriver's synchronous API deadlocks when called from\nthe game thread (which is where MCP tool calls execute)." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class USlateInspectorToolset constinit property declarations *******************
// ********** End Class USlateInspectorToolset constinit property declarations *********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("Click"), .Pointer = &USlateInspectorToolset::execClick },
		{ .NameUTF8 = UTF8TEXT("Drag"), .Pointer = &USlateInspectorToolset::execDrag },
		{ .NameUTF8 = UTF8TEXT("FillForm"), .Pointer = &USlateInspectorToolset::execFillForm },
		{ .NameUTF8 = UTF8TEXT("Hover"), .Pointer = &USlateInspectorToolset::execHover },
		{ .NameUTF8 = UTF8TEXT("ListObservers"), .Pointer = &USlateInspectorToolset::execListObservers },
		{ .NameUTF8 = UTF8TEXT("Observe"), .Pointer = &USlateInspectorToolset::execObserve },
		{ .NameUTF8 = UTF8TEXT("PressKey"), .Pointer = &USlateInspectorToolset::execPressKey },
		{ .NameUTF8 = UTF8TEXT("Screenshot"), .Pointer = &USlateInspectorToolset::execScreenshot },
		{ .NameUTF8 = UTF8TEXT("SelectOption"), .Pointer = &USlateInspectorToolset::execSelectOption },
		{ .NameUTF8 = UTF8TEXT("Snapshot"), .Pointer = &USlateInspectorToolset::execSnapshot },
		{ .NameUTF8 = UTF8TEXT("Type"), .Pointer = &USlateInspectorToolset::execType },
		{ .NameUTF8 = UTF8TEXT("Unobserve"), .Pointer = &USlateInspectorToolset::execUnobserve },
		{ .NameUTF8 = UTF8TEXT("WaitFor"), .Pointer = &USlateInspectorToolset::execWaitFor },
		{ .NameUTF8 = UTF8TEXT("Windows"), .Pointer = &USlateInspectorToolset::execWindows },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_USlateInspectorToolset_Click, "Click" }, // 2666752619
		{ &Z_Construct_UFunction_USlateInspectorToolset_Drag, "Drag" }, // 1938423495
		{ &Z_Construct_UFunction_USlateInspectorToolset_FillForm, "FillForm" }, // 568819262
		{ &Z_Construct_UFunction_USlateInspectorToolset_Hover, "Hover" }, // 939414016
		{ &Z_Construct_UFunction_USlateInspectorToolset_ListObservers, "ListObservers" }, // 3605052598
		{ &Z_Construct_UFunction_USlateInspectorToolset_Observe, "Observe" }, // 2330963894
		{ &Z_Construct_UFunction_USlateInspectorToolset_PressKey, "PressKey" }, // 3872526581
		{ &Z_Construct_UFunction_USlateInspectorToolset_Screenshot, "Screenshot" }, // 684574163
		{ &Z_Construct_UFunction_USlateInspectorToolset_SelectOption, "SelectOption" }, // 4228522060
		{ &Z_Construct_UFunction_USlateInspectorToolset_Snapshot, "Snapshot" }, // 3785362922
		{ &Z_Construct_UFunction_USlateInspectorToolset_Type, "Type" }, // 2160597935
		{ &Z_Construct_UFunction_USlateInspectorToolset_Unobserve, "Unobserve" }, // 2489228136
		{ &Z_Construct_UFunction_USlateInspectorToolset_WaitFor, "WaitFor" }, // 4260455049
		{ &Z_Construct_UFunction_USlateInspectorToolset_Windows, "Windows" }, // 1863222386
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USlateInspectorToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USlateInspectorToolset_Statics
UObject* (*const Z_Construct_UClass_USlateInspectorToolset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UToolsetDefinition,
	(UObject* (*)())Z_Construct_UPackage__Script_SlateInspectorToolset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USlateInspectorToolset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USlateInspectorToolset_Statics::ClassParams = {
	&USlateInspectorToolset::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USlateInspectorToolset_Statics::Class_MetaDataParams), Z_Construct_UClass_USlateInspectorToolset_Statics::Class_MetaDataParams)
};
void USlateInspectorToolset::StaticRegisterNativesUSlateInspectorToolset()
{
	UClass* Class = USlateInspectorToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_USlateInspectorToolset_Statics::Funcs));
}
UClass* Z_Construct_UClass_USlateInspectorToolset()
{
	if (!Z_Registration_Info_UClass_USlateInspectorToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USlateInspectorToolset.OuterSingleton, Z_Construct_UClass_USlateInspectorToolset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USlateInspectorToolset.OuterSingleton;
}
USlateInspectorToolset::USlateInspectorToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USlateInspectorToolset);
USlateInspectorToolset::~USlateInspectorToolset() {}
// ********** End Class USlateInspectorToolset *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_SlateInspectorToolset_Source_SlateInspectorToolset_Public_SlateInspectorToolset_h__Script_SlateInspectorToolset_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FSlateInspectorToolsetModifierKeys::StaticStruct, Z_Construct_UScriptStruct_FSlateInspectorToolsetModifierKeys_Statics::NewStructOps, TEXT("SlateInspectorToolsetModifierKeys"),&Z_Registration_Info_UScriptStruct_FSlateInspectorToolsetModifierKeys, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSlateInspectorToolsetModifierKeys), 4123751977U) },
		{ FSlateInspectorToolsetFormField::StaticStruct, Z_Construct_UScriptStruct_FSlateInspectorToolsetFormField_Statics::NewStructOps, TEXT("SlateInspectorToolsetFormField"),&Z_Registration_Info_UScriptStruct_FSlateInspectorToolsetFormField, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSlateInspectorToolsetFormField), 3427158049U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USlateInspectorToolset, USlateInspectorToolset::StaticClass, TEXT("USlateInspectorToolset"), &Z_Registration_Info_UClass_USlateInspectorToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USlateInspectorToolset), 1180223794U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_SlateInspectorToolset_Source_SlateInspectorToolset_Public_SlateInspectorToolset_h__Script_SlateInspectorToolset_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_SlateInspectorToolset_Source_SlateInspectorToolset_Public_SlateInspectorToolset_h__Script_SlateInspectorToolset_906485594{
	TEXT("/Script/SlateInspectorToolset"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_SlateInspectorToolset_Source_SlateInspectorToolset_Public_SlateInspectorToolset_h__Script_SlateInspectorToolset_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_SlateInspectorToolset_Source_SlateInspectorToolset_Public_SlateInspectorToolset_h__Script_SlateInspectorToolset_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_SlateInspectorToolset_Source_SlateInspectorToolset_Public_SlateInspectorToolset_h__Script_SlateInspectorToolset_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_SlateInspectorToolset_Source_SlateInspectorToolset_Public_SlateInspectorToolset_h__Script_SlateInspectorToolset_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
