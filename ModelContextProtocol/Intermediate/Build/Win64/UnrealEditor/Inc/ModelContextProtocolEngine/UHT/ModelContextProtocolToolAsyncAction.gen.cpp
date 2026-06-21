// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ModelContextProtocolToolAsyncAction.h"
#include "ModelContextProtocolMetaData.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeModelContextProtocolToolAsyncAction() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UCancellableAsyncAction();
MODELCONTEXTPROTOCOL_API UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolFunctionMetaData();
MODELCONTEXTPROTOCOLENGINE_API UClass* Z_Construct_UClass_UModelContextProtocolToolAsyncAction();
MODELCONTEXTPROTOCOLENGINE_API UClass* Z_Construct_UClass_UModelContextProtocolToolAsyncAction_NoRegister();
UPackage* Z_Construct_UPackage__Script_ModelContextProtocolEngine();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UModelContextProtocolToolAsyncAction *************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UModelContextProtocolToolAsyncAction;
UClass* UModelContextProtocolToolAsyncAction::GetPrivateStaticClass()
{
	using TClass = UModelContextProtocolToolAsyncAction;
	if (!Z_Registration_Info_UClass_UModelContextProtocolToolAsyncAction.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ModelContextProtocolToolAsyncAction"),
			Z_Registration_Info_UClass_UModelContextProtocolToolAsyncAction.InnerSingleton,
			StaticRegisterNativesUModelContextProtocolToolAsyncAction,
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
	return Z_Registration_Info_UClass_UModelContextProtocolToolAsyncAction.InnerSingleton;
}
UClass* Z_Construct_UClass_UModelContextProtocolToolAsyncAction_NoRegister()
{
	return UModelContextProtocolToolAsyncAction::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UModelContextProtocolToolAsyncAction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * @deprecated Use UToolsetDefinition (ToolsetRegistry plugin) instead. UModelContextProtocolToolAsyncAction is maintained as a legacy\n *             fallback and will be removed in a future release.\n */" },
#endif
		{ "DeprecatedNode", "" },
		{ "DeprecationMessage", "Use UToolsetDefinition (ToolsetRegistry plugin) instead." },
		{ "IncludePath", "ModelContextProtocolToolAsyncAction.h" },
		{ "ModuleRelativePath", "Public/ModelContextProtocolToolAsyncAction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@deprecated Use UToolsetDefinition (ToolsetRegistry plugin) instead. UModelContextProtocolToolAsyncAction is maintained as a legacy\n            fallback and will be removed in a future release." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoRegisterTool_MetaData[] = {
		{ "Category", "Model Context Protocol" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * If true, automatically registers on module load.\n\x09 * If false, RegisterTool must manually be called.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/ModelContextProtocolToolAsyncAction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If true, automatically registers on module load.\nIf false, RegisterTool must manually be called." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ToolFunctionMetaData_MetaData[] = {
		{ "Category", "Model Context Protocol" },
		{ "ModuleRelativePath", "Public/ModelContextProtocolToolAsyncAction.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ToolResultMetaData_MetaData[] = {
		{ "Category", "Model Context Protocol" },
		{ "ModuleRelativePath", "Public/ModelContextProtocolToolAsyncAction.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UModelContextProtocolToolAsyncAction constinit property declarations *****
	static void NewProp_bAutoRegisterTool_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoRegisterTool;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ToolFunctionMetaData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ToolResultMetaData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UModelContextProtocolToolAsyncAction constinit property declarations *******
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UModelContextProtocolToolAsyncAction>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UModelContextProtocolToolAsyncAction_Statics

// ********** Begin Class UModelContextProtocolToolAsyncAction Property Definitions ****************
void Z_Construct_UClass_UModelContextProtocolToolAsyncAction_Statics::NewProp_bAutoRegisterTool_SetBit(void* Obj)
{
	((UModelContextProtocolToolAsyncAction*)Obj)->bAutoRegisterTool = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UModelContextProtocolToolAsyncAction_Statics::NewProp_bAutoRegisterTool = { "bAutoRegisterTool", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UModelContextProtocolToolAsyncAction), &Z_Construct_UClass_UModelContextProtocolToolAsyncAction_Statics::NewProp_bAutoRegisterTool_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoRegisterTool_MetaData), NewProp_bAutoRegisterTool_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UModelContextProtocolToolAsyncAction_Statics::NewProp_ToolFunctionMetaData = { "ToolFunctionMetaData", nullptr, (EPropertyFlags)0x0020080000030001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModelContextProtocolToolAsyncAction, ToolFunctionMetaData), Z_Construct_UScriptStruct_FModelContextProtocolFunctionMetaData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ToolFunctionMetaData_MetaData), NewProp_ToolFunctionMetaData_MetaData) }; // 4184287625
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UModelContextProtocolToolAsyncAction_Statics::NewProp_ToolResultMetaData = { "ToolResultMetaData", nullptr, (EPropertyFlags)0x0020080000030001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModelContextProtocolToolAsyncAction, ToolResultMetaData), Z_Construct_UScriptStruct_FModelContextProtocolFunctionMetaData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ToolResultMetaData_MetaData), NewProp_ToolResultMetaData_MetaData) }; // 4184287625
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UModelContextProtocolToolAsyncAction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModelContextProtocolToolAsyncAction_Statics::NewProp_bAutoRegisterTool,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModelContextProtocolToolAsyncAction_Statics::NewProp_ToolFunctionMetaData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModelContextProtocolToolAsyncAction_Statics::NewProp_ToolResultMetaData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UModelContextProtocolToolAsyncAction_Statics::PropPointers) < 2048);
// ********** End Class UModelContextProtocolToolAsyncAction Property Definitions ******************
UObject* (*const Z_Construct_UClass_UModelContextProtocolToolAsyncAction_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UCancellableAsyncAction,
	(UObject* (*)())Z_Construct_UPackage__Script_ModelContextProtocolEngine,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UModelContextProtocolToolAsyncAction_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UModelContextProtocolToolAsyncAction_Statics::ClassParams = {
	&UModelContextProtocolToolAsyncAction::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UModelContextProtocolToolAsyncAction_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UModelContextProtocolToolAsyncAction_Statics::PropPointers),
	0,
	0x000800A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UModelContextProtocolToolAsyncAction_Statics::Class_MetaDataParams), Z_Construct_UClass_UModelContextProtocolToolAsyncAction_Statics::Class_MetaDataParams)
};
void UModelContextProtocolToolAsyncAction::StaticRegisterNativesUModelContextProtocolToolAsyncAction()
{
}
UClass* Z_Construct_UClass_UModelContextProtocolToolAsyncAction()
{
	if (!Z_Registration_Info_UClass_UModelContextProtocolToolAsyncAction.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UModelContextProtocolToolAsyncAction.OuterSingleton, Z_Construct_UClass_UModelContextProtocolToolAsyncAction_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UModelContextProtocolToolAsyncAction.OuterSingleton;
}
UModelContextProtocolToolAsyncAction::UModelContextProtocolToolAsyncAction(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UModelContextProtocolToolAsyncAction);
UModelContextProtocolToolAsyncAction::~UModelContextProtocolToolAsyncAction() {}
// ********** End Class UModelContextProtocolToolAsyncAction ***************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolToolAsyncAction_h__Script_ModelContextProtocolEngine_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UModelContextProtocolToolAsyncAction, UModelContextProtocolToolAsyncAction::StaticClass, TEXT("UModelContextProtocolToolAsyncAction"), &Z_Registration_Info_UClass_UModelContextProtocolToolAsyncAction, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UModelContextProtocolToolAsyncAction), 1106150701U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolToolAsyncAction_h__Script_ModelContextProtocolEngine_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolToolAsyncAction_h__Script_ModelContextProtocolEngine_3998620994{
	TEXT("/Script/ModelContextProtocolEngine"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolToolAsyncAction_h__Script_ModelContextProtocolEngine_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolToolAsyncAction_h__Script_ModelContextProtocolEngine_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
