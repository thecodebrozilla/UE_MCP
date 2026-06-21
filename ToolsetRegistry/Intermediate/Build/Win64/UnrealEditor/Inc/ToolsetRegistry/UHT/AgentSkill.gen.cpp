// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ToolsetRegistry/AgentSkill.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeAgentSkill() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UAgentSkill();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UAgentSkill_NoRegister();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UAgentSkillToolset();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UAgentSkillToolset_NoRegister();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition();
TOOLSETREGISTRY_API UScriptStruct* Z_Construct_UScriptStruct_FAgentSkillDetails();
UPackage* Z_Construct_UPackage__Script_ToolsetRegistry();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FAgentSkillDetails ************************************************
struct Z_Construct_UScriptStruct_FAgentSkillDetails_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FAgentSkillDetails); }
	static inline consteval int16 GetStructAlignment() { return alignof(FAgentSkillDetails); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Detailed information about a specific AgentSkill.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/AgentSkill.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Detailed information about a specific AgentSkill." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Instructions_MetaData[] = {
		{ "Category", "AgentSkill" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Detailed information about how to use the skill.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/AgentSkill.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Detailed information about how to use the skill." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FAgentSkillDetails constinit property declarations ****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Instructions;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FAgentSkillDetails constinit property declarations ******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAgentSkillDetails>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FAgentSkillDetails_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FAgentSkillDetails;
class UScriptStruct* FAgentSkillDetails::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FAgentSkillDetails.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FAgentSkillDetails.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAgentSkillDetails, (UObject*)Z_Construct_UPackage__Script_ToolsetRegistry(), TEXT("AgentSkillDetails"));
	}
	return Z_Registration_Info_UScriptStruct_FAgentSkillDetails.OuterSingleton;
	}

// ********** Begin ScriptStruct FAgentSkillDetails Property Definitions ***************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAgentSkillDetails_Statics::NewProp_Instructions = { "Instructions", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAgentSkillDetails, Instructions), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Instructions_MetaData), NewProp_Instructions_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAgentSkillDetails_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAgentSkillDetails_Statics::NewProp_Instructions,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAgentSkillDetails_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FAgentSkillDetails Property Definitions *****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAgentSkillDetails_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ToolsetRegistry,
	nullptr,
	&NewStructOps,
	"AgentSkillDetails",
	Z_Construct_UScriptStruct_FAgentSkillDetails_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAgentSkillDetails_Statics::PropPointers),
	sizeof(FAgentSkillDetails),
	alignof(FAgentSkillDetails),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAgentSkillDetails_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAgentSkillDetails_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAgentSkillDetails()
{
	if (!Z_Registration_Info_UScriptStruct_FAgentSkillDetails.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FAgentSkillDetails.InnerSingleton, Z_Construct_UScriptStruct_FAgentSkillDetails_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FAgentSkillDetails.InnerSingleton);
}
// ********** End ScriptStruct FAgentSkillDetails **************************************************

// ********** Begin Class UAgentSkill Function GeneratePrompt **************************************
struct AgentSkill_eventGeneratePrompt_Parms
{
	FString InitialInstructions;
	FString ReturnValue;
};
static FName NAME_UAgentSkill_GeneratePrompt = FName(TEXT("GeneratePrompt"));
FString UAgentSkill::GeneratePrompt(const FString& InitialInstructions) const
{
	UFunction* Func = FindFunctionChecked(NAME_UAgentSkill_GeneratePrompt);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		AgentSkill_eventGeneratePrompt_Parms Parms;
		Parms.InitialInstructions=InitialInstructions;
		const_cast<UAgentSkill*>(this)->ProcessEvent(Func,&Parms);
		return Parms.ReturnValue;
	}
	else
	{
		return const_cast<UAgentSkill*>(this)->GeneratePrompt_Implementation(InitialInstructions);
	}
}
struct Z_Construct_UFunction_UAgentSkill_GeneratePrompt_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "AgentSkill" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Generates the final prompt text for the Agent Skill.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/AgentSkill.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Generates the final prompt text for the Agent Skill." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InitialInstructions_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GeneratePrompt constinit property declarations ************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InitialInstructions;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GeneratePrompt constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GeneratePrompt Property Definitions ***********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAgentSkill_GeneratePrompt_Statics::NewProp_InitialInstructions = { "InitialInstructions", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AgentSkill_eventGeneratePrompt_Parms, InitialInstructions), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InitialInstructions_MetaData), NewProp_InitialInstructions_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAgentSkill_GeneratePrompt_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AgentSkill_eventGeneratePrompt_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAgentSkill_GeneratePrompt_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAgentSkill_GeneratePrompt_Statics::NewProp_InitialInstructions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAgentSkill_GeneratePrompt_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAgentSkill_GeneratePrompt_Statics::PropPointers) < 2048);
// ********** End Function GeneratePrompt Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAgentSkill_GeneratePrompt_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAgentSkill, nullptr, "GeneratePrompt", 	Z_Construct_UFunction_UAgentSkill_GeneratePrompt_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAgentSkill_GeneratePrompt_Statics::PropPointers), 
sizeof(AgentSkill_eventGeneratePrompt_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x48080C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAgentSkill_GeneratePrompt_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAgentSkill_GeneratePrompt_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(AgentSkill_eventGeneratePrompt_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAgentSkill_GeneratePrompt()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAgentSkill_GeneratePrompt_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAgentSkill::execGeneratePrompt)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InitialInstructions);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GeneratePrompt_Implementation(Z_Param_InitialInstructions);
	P_NATIVE_END;
}
// ********** End Class UAgentSkill Function GeneratePrompt ****************************************

// ********** Begin Class UAgentSkill **************************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UAgentSkill;
UClass* UAgentSkill::GetPrivateStaticClass()
{
	using TClass = UAgentSkill;
	if (!Z_Registration_Info_UClass_UAgentSkill.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("AgentSkill"),
			Z_Registration_Info_UClass_UAgentSkill.InnerSingleton,
			StaticRegisterNativesUAgentSkill,
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
	return Z_Registration_Info_UClass_UAgentSkill.InnerSingleton;
}
UClass* Z_Construct_UClass_UAgentSkill_NoRegister()
{
	return UAgentSkill::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UAgentSkill_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "ToolsetRegistry/AgentSkill.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/ToolsetRegistry/AgentSkill.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "Category", "AgentSkill" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// A brief description of what the skill does or how it should be used.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/AgentSkill.h" },
		{ "MultiLine", "TRUE" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A brief description of what the skill does or how it should be used." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Instructions_MetaData[] = {
		{ "Category", "AgentSkill" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Detailed instructions for how to use this skill and its associated tools.\n" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/AgentSkill.h" },
		{ "MultiLine", "TRUE" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Detailed instructions for how to use this skill and its associated tools." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UAgentSkill constinit property declarations ******************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Description;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Instructions;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UAgentSkill constinit property declarations ********************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GeneratePrompt"), .Pointer = &UAgentSkill::execGeneratePrompt },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UAgentSkill_GeneratePrompt, "GeneratePrompt" }, // 3266027078
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAgentSkill>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UAgentSkill_Statics

// ********** Begin Class UAgentSkill Property Definitions *****************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UAgentSkill_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAgentSkill, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UAgentSkill_Statics::NewProp_Instructions = { "Instructions", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAgentSkill, Instructions), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Instructions_MetaData), NewProp_Instructions_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAgentSkill_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAgentSkill_Statics::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAgentSkill_Statics::NewProp_Instructions,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAgentSkill_Statics::PropPointers) < 2048);
// ********** End Class UAgentSkill Property Definitions *******************************************
UObject* (*const Z_Construct_UClass_UAgentSkill_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_ToolsetRegistry,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAgentSkill_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAgentSkill_Statics::ClassParams = {
	&UAgentSkill::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UAgentSkill_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UAgentSkill_Statics::PropPointers),
	0,
	0x000800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAgentSkill_Statics::Class_MetaDataParams), Z_Construct_UClass_UAgentSkill_Statics::Class_MetaDataParams)
};
void UAgentSkill::StaticRegisterNativesUAgentSkill()
{
	UClass* Class = UAgentSkill::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UAgentSkill_Statics::Funcs));
}
UClass* Z_Construct_UClass_UAgentSkill()
{
	if (!Z_Registration_Info_UClass_UAgentSkill.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAgentSkill.OuterSingleton, Z_Construct_UClass_UAgentSkill_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAgentSkill.OuterSingleton;
}
UAgentSkill::UAgentSkill(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UAgentSkill);
UAgentSkill::~UAgentSkill() {}
// ********** End Class UAgentSkill ****************************************************************

// ********** Begin Class UAgentSkillToolset Function CreateSkill **********************************
struct Z_Construct_UFunction_UAgentSkillToolset_CreateSkill_Statics
{
	struct AgentSkillToolset_eventCreateSkill_Parms
	{
		FString FolderPath;
		FString AssetName;
		FString Description;
		FAgentSkillDetails Details;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "Agent Skill" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Creates a new AgentSkill.\n\x09 * This should ONLY be called after getting explicit direction or permission from the user.\n\x09 * @param FolderPath The folder in which to create the skill. i.e. /Game/Skills/.\n\x09 * @param AssetName The name of the skill to create i.e. MySkill.\n\x09 * @param Description The brief description of the skill.\n\x09 * @param Details Detailed information about how to use the skill.\n\x09 * @return The path for the created Skill class. Empty if unsuccessful.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/AgentSkill.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Creates a new AgentSkill.\nThis should ONLY be called after getting explicit direction or permission from the user.\n@param FolderPath The folder in which to create the skill. i.e. /Game/Skills/.\n@param AssetName The name of the skill to create i.e. MySkill.\n@param Description The brief description of the skill.\n@param Details Detailed information about how to use the skill.\n@return The path for the created Skill class. Empty if unsuccessful." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FolderPath_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AssetName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Details_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CreateSkill constinit property declarations ***************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FolderPath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AssetName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Description;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Details;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CreateSkill constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CreateSkill Property Definitions **************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAgentSkillToolset_CreateSkill_Statics::NewProp_FolderPath = { "FolderPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AgentSkillToolset_eventCreateSkill_Parms, FolderPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FolderPath_MetaData), NewProp_FolderPath_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAgentSkillToolset_CreateSkill_Statics::NewProp_AssetName = { "AssetName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AgentSkillToolset_eventCreateSkill_Parms, AssetName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AssetName_MetaData), NewProp_AssetName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAgentSkillToolset_CreateSkill_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AgentSkillToolset_eventCreateSkill_Parms, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAgentSkillToolset_CreateSkill_Statics::NewProp_Details = { "Details", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AgentSkillToolset_eventCreateSkill_Parms, Details), Z_Construct_UScriptStruct_FAgentSkillDetails, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Details_MetaData), NewProp_Details_MetaData) }; // 3247014256
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAgentSkillToolset_CreateSkill_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AgentSkillToolset_eventCreateSkill_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAgentSkillToolset_CreateSkill_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAgentSkillToolset_CreateSkill_Statics::NewProp_FolderPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAgentSkillToolset_CreateSkill_Statics::NewProp_AssetName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAgentSkillToolset_CreateSkill_Statics::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAgentSkillToolset_CreateSkill_Statics::NewProp_Details,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAgentSkillToolset_CreateSkill_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAgentSkillToolset_CreateSkill_Statics::PropPointers) < 2048);
// ********** End Function CreateSkill Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAgentSkillToolset_CreateSkill_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAgentSkillToolset, nullptr, "CreateSkill", 	Z_Construct_UFunction_UAgentSkillToolset_CreateSkill_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAgentSkillToolset_CreateSkill_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAgentSkillToolset_CreateSkill_Statics::AgentSkillToolset_eventCreateSkill_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAgentSkillToolset_CreateSkill_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAgentSkillToolset_CreateSkill_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAgentSkillToolset_CreateSkill_Statics::AgentSkillToolset_eventCreateSkill_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAgentSkillToolset_CreateSkill()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAgentSkillToolset_CreateSkill_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAgentSkillToolset::execCreateSkill)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FolderPath);
	P_GET_PROPERTY(FStrProperty,Z_Param_AssetName);
	P_GET_PROPERTY(FStrProperty,Z_Param_Description);
	P_GET_STRUCT_REF(FAgentSkillDetails,Z_Param_Out_Details);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UAgentSkillToolset::CreateSkill(Z_Param_FolderPath,Z_Param_AssetName,Z_Param_Description,Z_Param_Out_Details);
	P_NATIVE_END;
}
// ********** End Class UAgentSkillToolset Function CreateSkill ************************************

// ********** Begin Class UAgentSkillToolset Function GetSkills ************************************
struct Z_Construct_UFunction_UAgentSkillToolset_GetSkills_Statics
{
	struct AgentSkillToolset_eventGetSkills_Parms
	{
		TArray<FString> SkillPaths;
		TMap<FString,FAgentSkillDetails> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "Agent Skill" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns detailed information about a specific set of AgentSkills.\n\x09 * @param SkillPaths A list of paths to the AgentSkills to retrieve.\n\x09 * @return A dictionary where the key is the Skill path and the value is detailed info.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/AgentSkill.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns detailed information about a specific set of AgentSkills.\n@param SkillPaths A list of paths to the AgentSkills to retrieve.\n@return A dictionary where the key is the Skill path and the value is detailed info." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkillPaths_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSkills constinit property declarations *****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_SkillPaths_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SkillPaths;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSkills constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSkills Property Definitions ****************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAgentSkillToolset_GetSkills_Statics::NewProp_SkillPaths_Inner = { "SkillPaths", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UAgentSkillToolset_GetSkills_Statics::NewProp_SkillPaths = { "SkillPaths", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AgentSkillToolset_eventGetSkills_Parms, SkillPaths), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkillPaths_MetaData), NewProp_SkillPaths_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAgentSkillToolset_GetSkills_Statics::NewProp_ReturnValue_ValueProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FAgentSkillDetails, METADATA_PARAMS(0, nullptr) }; // 3247014256
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAgentSkillToolset_GetSkills_Statics::NewProp_ReturnValue_Key_KeyProp = { "ReturnValue_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UAgentSkillToolset_GetSkills_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AgentSkillToolset_eventGetSkills_Parms, ReturnValue), EMapPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 3247014256
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAgentSkillToolset_GetSkills_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAgentSkillToolset_GetSkills_Statics::NewProp_SkillPaths_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAgentSkillToolset_GetSkills_Statics::NewProp_SkillPaths,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAgentSkillToolset_GetSkills_Statics::NewProp_ReturnValue_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAgentSkillToolset_GetSkills_Statics::NewProp_ReturnValue_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAgentSkillToolset_GetSkills_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAgentSkillToolset_GetSkills_Statics::PropPointers) < 2048);
// ********** End Function GetSkills Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAgentSkillToolset_GetSkills_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAgentSkillToolset, nullptr, "GetSkills", 	Z_Construct_UFunction_UAgentSkillToolset_GetSkills_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAgentSkillToolset_GetSkills_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAgentSkillToolset_GetSkills_Statics::AgentSkillToolset_eventGetSkills_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAgentSkillToolset_GetSkills_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAgentSkillToolset_GetSkills_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAgentSkillToolset_GetSkills_Statics::AgentSkillToolset_eventGetSkills_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAgentSkillToolset_GetSkills()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAgentSkillToolset_GetSkills_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAgentSkillToolset::execGetSkills)
{
	P_GET_TARRAY_REF(FString,Z_Param_Out_SkillPaths);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TMap<FString,FAgentSkillDetails>*)Z_Param__Result=UAgentSkillToolset::GetSkills(Z_Param_Out_SkillPaths);
	P_NATIVE_END;
}
// ********** End Class UAgentSkillToolset Function GetSkills **************************************

// ********** Begin Class UAgentSkillToolset Function ListSkills ***********************************
struct Z_Construct_UFunction_UAgentSkillToolset_ListSkills_Statics
{
	struct AgentSkillToolset_eventListSkills_Parms
	{
		TMap<FString,FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "Agent Skill" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Gets a summary of all AgentSkills in the project.\n\x09 * @return A dictionary where the key is the Skill path and the value is a description.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/AgentSkill.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Gets a summary of all AgentSkills in the project.\n@return A dictionary where the key is the Skill path and the value is a description." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ListSkills constinit property declarations ****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListSkills constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListSkills Property Definitions ***************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAgentSkillToolset_ListSkills_Statics::NewProp_ReturnValue_ValueProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAgentSkillToolset_ListSkills_Statics::NewProp_ReturnValue_Key_KeyProp = { "ReturnValue_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UAgentSkillToolset_ListSkills_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AgentSkillToolset_eventListSkills_Parms, ReturnValue), EMapPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAgentSkillToolset_ListSkills_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAgentSkillToolset_ListSkills_Statics::NewProp_ReturnValue_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAgentSkillToolset_ListSkills_Statics::NewProp_ReturnValue_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAgentSkillToolset_ListSkills_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAgentSkillToolset_ListSkills_Statics::PropPointers) < 2048);
// ********** End Function ListSkills Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAgentSkillToolset_ListSkills_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAgentSkillToolset, nullptr, "ListSkills", 	Z_Construct_UFunction_UAgentSkillToolset_ListSkills_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAgentSkillToolset_ListSkills_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAgentSkillToolset_ListSkills_Statics::AgentSkillToolset_eventListSkills_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAgentSkillToolset_ListSkills_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAgentSkillToolset_ListSkills_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAgentSkillToolset_ListSkills_Statics::AgentSkillToolset_eventListSkills_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAgentSkillToolset_ListSkills()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAgentSkillToolset_ListSkills_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAgentSkillToolset::execListSkills)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TMap<FString,FString>*)Z_Param__Result=UAgentSkillToolset::ListSkills();
	P_NATIVE_END;
}
// ********** End Class UAgentSkillToolset Function ListSkills *************************************

// ********** Begin Class UAgentSkillToolset Function UpdateSkill **********************************
struct Z_Construct_UFunction_UAgentSkillToolset_UpdateSkill_Statics
{
	struct AgentSkillToolset_eventUpdateSkill_Parms
	{
		FString SkillPath;
		FString Description;
		FAgentSkillDetails Details;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "Agent Skill" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Updates an existing AgentSkill.\n\x09 * This should ONLY be called after getting explicit direction or permission from the user.\n\x09 * @param SkillPath The full path to the skill to modify i.e. /Game/Skills/MySkill.MySkill_C.\n\x09 * @param Description The brief description of the skill.\n\x09 * @param Details Detailed information about how to use the skill.\n\x09 * @return True if the skill was updated.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/ToolsetRegistry/AgentSkill.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Updates an existing AgentSkill.\nThis should ONLY be called after getting explicit direction or permission from the user.\n@param SkillPath The full path to the skill to modify i.e. /Game/Skills/MySkill.MySkill_C.\n@param Description The brief description of the skill.\n@param Details Detailed information about how to use the skill.\n@return True if the skill was updated." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkillPath_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Details_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function UpdateSkill constinit property declarations ***************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_SkillPath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Description;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Details;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UpdateSkill constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UpdateSkill Property Definitions **************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAgentSkillToolset_UpdateSkill_Statics::NewProp_SkillPath = { "SkillPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AgentSkillToolset_eventUpdateSkill_Parms, SkillPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkillPath_MetaData), NewProp_SkillPath_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAgentSkillToolset_UpdateSkill_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AgentSkillToolset_eventUpdateSkill_Parms, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAgentSkillToolset_UpdateSkill_Statics::NewProp_Details = { "Details", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AgentSkillToolset_eventUpdateSkill_Parms, Details), Z_Construct_UScriptStruct_FAgentSkillDetails, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Details_MetaData), NewProp_Details_MetaData) }; // 3247014256
void Z_Construct_UFunction_UAgentSkillToolset_UpdateSkill_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((AgentSkillToolset_eventUpdateSkill_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAgentSkillToolset_UpdateSkill_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AgentSkillToolset_eventUpdateSkill_Parms), &Z_Construct_UFunction_UAgentSkillToolset_UpdateSkill_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAgentSkillToolset_UpdateSkill_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAgentSkillToolset_UpdateSkill_Statics::NewProp_SkillPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAgentSkillToolset_UpdateSkill_Statics::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAgentSkillToolset_UpdateSkill_Statics::NewProp_Details,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAgentSkillToolset_UpdateSkill_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAgentSkillToolset_UpdateSkill_Statics::PropPointers) < 2048);
// ********** End Function UpdateSkill Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAgentSkillToolset_UpdateSkill_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAgentSkillToolset, nullptr, "UpdateSkill", 	Z_Construct_UFunction_UAgentSkillToolset_UpdateSkill_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAgentSkillToolset_UpdateSkill_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAgentSkillToolset_UpdateSkill_Statics::AgentSkillToolset_eventUpdateSkill_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAgentSkillToolset_UpdateSkill_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAgentSkillToolset_UpdateSkill_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAgentSkillToolset_UpdateSkill_Statics::AgentSkillToolset_eventUpdateSkill_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAgentSkillToolset_UpdateSkill()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAgentSkillToolset_UpdateSkill_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAgentSkillToolset::execUpdateSkill)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_SkillPath);
	P_GET_PROPERTY(FStrProperty,Z_Param_Description);
	P_GET_STRUCT_REF(FAgentSkillDetails,Z_Param_Out_Details);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UAgentSkillToolset::UpdateSkill(Z_Param_SkillPath,Z_Param_Description,Z_Param_Out_Details);
	P_NATIVE_END;
}
// ********** End Class UAgentSkillToolset Function UpdateSkill ************************************

// ********** Begin Class UAgentSkillToolset *******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UAgentSkillToolset;
UClass* UAgentSkillToolset::GetPrivateStaticClass()
{
	using TClass = UAgentSkillToolset;
	if (!Z_Registration_Info_UClass_UAgentSkillToolset.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("AgentSkillToolset"),
			Z_Registration_Info_UClass_UAgentSkillToolset.InnerSingleton,
			StaticRegisterNativesUAgentSkillToolset,
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
	return Z_Registration_Info_UClass_UAgentSkillToolset.InnerSingleton;
}
UClass* Z_Construct_UClass_UAgentSkillToolset_NoRegister()
{
	return UAgentSkillToolset::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UAgentSkillToolset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Provides tools for listing, reading, and creating/updating skills.\n" },
#endif
		{ "IncludePath", "ToolsetRegistry/AgentSkill.h" },
		{ "ModuleRelativePath", "Public/ToolsetRegistry/AgentSkill.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Provides tools for listing, reading, and creating/updating skills." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UAgentSkillToolset constinit property declarations ***********************
// ********** End Class UAgentSkillToolset constinit property declarations *************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CreateSkill"), .Pointer = &UAgentSkillToolset::execCreateSkill },
		{ .NameUTF8 = UTF8TEXT("GetSkills"), .Pointer = &UAgentSkillToolset::execGetSkills },
		{ .NameUTF8 = UTF8TEXT("ListSkills"), .Pointer = &UAgentSkillToolset::execListSkills },
		{ .NameUTF8 = UTF8TEXT("UpdateSkill"), .Pointer = &UAgentSkillToolset::execUpdateSkill },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UAgentSkillToolset_CreateSkill, "CreateSkill" }, // 840569545
		{ &Z_Construct_UFunction_UAgentSkillToolset_GetSkills, "GetSkills" }, // 1592527252
		{ &Z_Construct_UFunction_UAgentSkillToolset_ListSkills, "ListSkills" }, // 3150259879
		{ &Z_Construct_UFunction_UAgentSkillToolset_UpdateSkill, "UpdateSkill" }, // 3576130594
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAgentSkillToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UAgentSkillToolset_Statics
UObject* (*const Z_Construct_UClass_UAgentSkillToolset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UToolsetDefinition,
	(UObject* (*)())Z_Construct_UPackage__Script_ToolsetRegistry,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAgentSkillToolset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAgentSkillToolset_Statics::ClassParams = {
	&UAgentSkillToolset::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAgentSkillToolset_Statics::Class_MetaDataParams), Z_Construct_UClass_UAgentSkillToolset_Statics::Class_MetaDataParams)
};
void UAgentSkillToolset::StaticRegisterNativesUAgentSkillToolset()
{
	UClass* Class = UAgentSkillToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UAgentSkillToolset_Statics::Funcs));
}
UClass* Z_Construct_UClass_UAgentSkillToolset()
{
	if (!Z_Registration_Info_UClass_UAgentSkillToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAgentSkillToolset.OuterSingleton, Z_Construct_UClass_UAgentSkillToolset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAgentSkillToolset.OuterSingleton;
}
UAgentSkillToolset::UAgentSkillToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UAgentSkillToolset);
UAgentSkillToolset::~UAgentSkillToolset() {}
// ********** End Class UAgentSkillToolset *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_AgentSkill_h__Script_ToolsetRegistry_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FAgentSkillDetails::StaticStruct, Z_Construct_UScriptStruct_FAgentSkillDetails_Statics::NewStructOps, TEXT("AgentSkillDetails"),&Z_Registration_Info_UScriptStruct_FAgentSkillDetails, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAgentSkillDetails), 3247014256U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAgentSkill, UAgentSkill::StaticClass, TEXT("UAgentSkill"), &Z_Registration_Info_UClass_UAgentSkill, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAgentSkill), 4044696412U) },
		{ Z_Construct_UClass_UAgentSkillToolset, UAgentSkillToolset::StaticClass, TEXT("UAgentSkillToolset"), &Z_Registration_Info_UClass_UAgentSkillToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAgentSkillToolset), 585878690U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_AgentSkill_h__Script_ToolsetRegistry_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_AgentSkill_h__Script_ToolsetRegistry_1154796230{
	TEXT("/Script/ToolsetRegistry"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_AgentSkill_h__Script_ToolsetRegistry_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_AgentSkill_h__Script_ToolsetRegistry_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_AgentSkill_h__Script_ToolsetRegistry_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ToolsetRegistry_Source_ToolsetRegistry_Public_ToolsetRegistry_AgentSkill_h__Script_ToolsetRegistry_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
