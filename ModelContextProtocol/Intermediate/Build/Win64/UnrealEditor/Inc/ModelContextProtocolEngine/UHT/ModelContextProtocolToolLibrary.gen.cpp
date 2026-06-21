// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ModelContextProtocolToolLibrary.h"
#include "ModelContextProtocolMetaData.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeModelContextProtocolToolLibrary() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UBlueprint();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
MODELCONTEXTPROTOCOL_API UScriptStruct* Z_Construct_UScriptStruct_FModelContextProtocolFunctionMetaData();
MODELCONTEXTPROTOCOLENGINE_API UClass* Z_Construct_UClass_UModelContextProtocolToolLibrary();
MODELCONTEXTPROTOCOLENGINE_API UClass* Z_Construct_UClass_UModelContextProtocolToolLibrary_NoRegister();
MODELCONTEXTPROTOCOLENGINE_API UClass* Z_Construct_UClass_UModelContextProtocolToolLibraryBlueprint();
MODELCONTEXTPROTOCOLENGINE_API UClass* Z_Construct_UClass_UModelContextProtocolToolLibraryBlueprint_NoRegister();
UPackage* Z_Construct_UPackage__Script_ModelContextProtocolEngine();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UModelContextProtocolToolLibrary *****************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UModelContextProtocolToolLibrary;
UClass* UModelContextProtocolToolLibrary::GetPrivateStaticClass()
{
	using TClass = UModelContextProtocolToolLibrary;
	if (!Z_Registration_Info_UClass_UModelContextProtocolToolLibrary.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ModelContextProtocolToolLibrary"),
			Z_Registration_Info_UClass_UModelContextProtocolToolLibrary.InnerSingleton,
			StaticRegisterNativesUModelContextProtocolToolLibrary,
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
	return Z_Registration_Info_UClass_UModelContextProtocolToolLibrary.InnerSingleton;
}
UClass* Z_Construct_UClass_UModelContextProtocolToolLibrary_NoRegister()
{
	return UModelContextProtocolToolLibrary::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UModelContextProtocolToolLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Automatically registers an FModelContextProtocolLibraryTool for each public UFUNCTION on module load, using cached / cooked meta-data.\n *\n * UBlueprintFunctionLibrary specialization allows caching and cooking otherwise-editor-only UFUNCTION descriptions and parameter meta-data.\n *\n * Can be subclassed in either C++ or Blueprints.\n *\n * For Blueprints:\x09""Create via Content Browser -> Add -> MCP Tool Library, then simply define public functions with a doxygen-style\n *\x09\x09\x09\x09\x09""function tooltip.\n *\n * @deprecated Use UToolsetDefinition (ToolsetRegistry plugin) instead. UModelContextProtocolToolLibrary is maintained as a legacy fallback\n *             and will be removed in a future release.\n */" },
#endif
		{ "DeprecatedNode", "" },
		{ "DeprecationMessage", "Use UToolsetDefinition (ToolsetRegistry plugin) instead." },
		{ "IncludePath", "ModelContextProtocolToolLibrary.h" },
		{ "ModuleRelativePath", "Public/ModelContextProtocolToolLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Automatically registers an FModelContextProtocolLibraryTool for each public UFUNCTION on module load, using cached / cooked meta-data.\n\nUBlueprintFunctionLibrary specialization allows caching and cooking otherwise-editor-only UFUNCTION descriptions and parameter meta-data.\n\nCan be subclassed in either C++ or Blueprints.\n\nFor Blueprints:     Create via Content Browser -> Add -> MCP Tool Library, then simply define public functions with a doxygen-style\n                                    function tooltip.\n\n@deprecated Use UToolsetDefinition (ToolsetRegistry plugin) instead. UModelContextProtocolToolLibrary is maintained as a legacy fallback\n            and will be removed in a future release." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoRegisterTools_MetaData[] = {
		{ "Category", "Model Context Protocol" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * If true, automatically registers an FModelContextProtocolLibraryTool for each public UFUNCTION on module load.\n\x09 * If false, RegisterTools must manually be called.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/ModelContextProtocolToolLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If true, automatically registers an FModelContextProtocolLibraryTool for each public UFUNCTION on module load.\nIf false, RegisterTools must manually be called." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FunctionMetaData_MetaData[] = {
		{ "Category", "Model Context Protocol" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Per-UFUNCTION cached meta-data to allow meta-data use on cooked platforms */" },
#endif
		{ "ModuleRelativePath", "Public/ModelContextProtocolToolLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Per-UFUNCTION cached meta-data to allow meta-data use on cooked platforms" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UModelContextProtocolToolLibrary constinit property declarations *********
	static void NewProp_bAutoRegisterTools_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoRegisterTools;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FunctionMetaData_ValueProp;
	static const UECodeGen_Private::FNamePropertyParams NewProp_FunctionMetaData_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_FunctionMetaData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UModelContextProtocolToolLibrary constinit property declarations ***********
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UModelContextProtocolToolLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UModelContextProtocolToolLibrary_Statics

// ********** Begin Class UModelContextProtocolToolLibrary Property Definitions ********************
void Z_Construct_UClass_UModelContextProtocolToolLibrary_Statics::NewProp_bAutoRegisterTools_SetBit(void* Obj)
{
	((UModelContextProtocolToolLibrary*)Obj)->bAutoRegisterTools = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UModelContextProtocolToolLibrary_Statics::NewProp_bAutoRegisterTools = { "bAutoRegisterTools", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UModelContextProtocolToolLibrary), &Z_Construct_UClass_UModelContextProtocolToolLibrary_Statics::NewProp_bAutoRegisterTools_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoRegisterTools_MetaData), NewProp_bAutoRegisterTools_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UModelContextProtocolToolLibrary_Statics::NewProp_FunctionMetaData_ValueProp = { "FunctionMetaData", nullptr, (EPropertyFlags)0x0000000000020001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FModelContextProtocolFunctionMetaData, METADATA_PARAMS(0, nullptr) }; // 4184287625
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UModelContextProtocolToolLibrary_Statics::NewProp_FunctionMetaData_Key_KeyProp = { "FunctionMetaData_Key", nullptr, (EPropertyFlags)0x0000000000020001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UModelContextProtocolToolLibrary_Statics::NewProp_FunctionMetaData = { "FunctionMetaData", nullptr, (EPropertyFlags)0x0020080000030001, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModelContextProtocolToolLibrary, FunctionMetaData), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FunctionMetaData_MetaData), NewProp_FunctionMetaData_MetaData) }; // 4184287625
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UModelContextProtocolToolLibrary_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModelContextProtocolToolLibrary_Statics::NewProp_bAutoRegisterTools,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModelContextProtocolToolLibrary_Statics::NewProp_FunctionMetaData_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModelContextProtocolToolLibrary_Statics::NewProp_FunctionMetaData_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModelContextProtocolToolLibrary_Statics::NewProp_FunctionMetaData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UModelContextProtocolToolLibrary_Statics::PropPointers) < 2048);
// ********** End Class UModelContextProtocolToolLibrary Property Definitions **********************
UObject* (*const Z_Construct_UClass_UModelContextProtocolToolLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_ModelContextProtocolEngine,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UModelContextProtocolToolLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UModelContextProtocolToolLibrary_Statics::ClassParams = {
	&UModelContextProtocolToolLibrary::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UModelContextProtocolToolLibrary_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UModelContextProtocolToolLibrary_Statics::PropPointers),
	0,
	0x000800A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UModelContextProtocolToolLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UModelContextProtocolToolLibrary_Statics::Class_MetaDataParams)
};
void UModelContextProtocolToolLibrary::StaticRegisterNativesUModelContextProtocolToolLibrary()
{
}
UClass* Z_Construct_UClass_UModelContextProtocolToolLibrary()
{
	if (!Z_Registration_Info_UClass_UModelContextProtocolToolLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UModelContextProtocolToolLibrary.OuterSingleton, Z_Construct_UClass_UModelContextProtocolToolLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UModelContextProtocolToolLibrary.OuterSingleton;
}
UModelContextProtocolToolLibrary::UModelContextProtocolToolLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UModelContextProtocolToolLibrary);
UModelContextProtocolToolLibrary::~UModelContextProtocolToolLibrary() {}
// ********** End Class UModelContextProtocolToolLibrary *******************************************

// ********** Begin Class UModelContextProtocolToolLibraryBlueprint ********************************
FClassRegistrationInfo Z_Registration_Info_UClass_UModelContextProtocolToolLibraryBlueprint;
UClass* UModelContextProtocolToolLibraryBlueprint::GetPrivateStaticClass()
{
	using TClass = UModelContextProtocolToolLibraryBlueprint;
	if (!Z_Registration_Info_UClass_UModelContextProtocolToolLibraryBlueprint.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ModelContextProtocolToolLibraryBlueprint"),
			Z_Registration_Info_UClass_UModelContextProtocolToolLibraryBlueprint.InnerSingleton,
			StaticRegisterNativesUModelContextProtocolToolLibraryBlueprint,
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
	return Z_Registration_Info_UClass_UModelContextProtocolToolLibraryBlueprint.InnerSingleton;
}
UClass* Z_Construct_UClass_UModelContextProtocolToolLibraryBlueprint_NoRegister()
{
	return UModelContextProtocolToolLibraryBlueprint::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UModelContextProtocolToolLibraryBlueprint_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "ModelContextProtocolToolLibrary.h" },
		{ "ModuleRelativePath", "Public/ModelContextProtocolToolLibrary.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UModelContextProtocolToolLibraryBlueprint constinit property declarations 
// ********** End Class UModelContextProtocolToolLibraryBlueprint constinit property declarations **
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UModelContextProtocolToolLibraryBlueprint>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UModelContextProtocolToolLibraryBlueprint_Statics
UObject* (*const Z_Construct_UClass_UModelContextProtocolToolLibraryBlueprint_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprint,
	(UObject* (*)())Z_Construct_UPackage__Script_ModelContextProtocolEngine,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UModelContextProtocolToolLibraryBlueprint_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UModelContextProtocolToolLibraryBlueprint_Statics::ClassParams = {
	&UModelContextProtocolToolLibraryBlueprint::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008800A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UModelContextProtocolToolLibraryBlueprint_Statics::Class_MetaDataParams), Z_Construct_UClass_UModelContextProtocolToolLibraryBlueprint_Statics::Class_MetaDataParams)
};
void UModelContextProtocolToolLibraryBlueprint::StaticRegisterNativesUModelContextProtocolToolLibraryBlueprint()
{
}
UClass* Z_Construct_UClass_UModelContextProtocolToolLibraryBlueprint()
{
	if (!Z_Registration_Info_UClass_UModelContextProtocolToolLibraryBlueprint.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UModelContextProtocolToolLibraryBlueprint.OuterSingleton, Z_Construct_UClass_UModelContextProtocolToolLibraryBlueprint_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UModelContextProtocolToolLibraryBlueprint.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UModelContextProtocolToolLibraryBlueprint);
UModelContextProtocolToolLibraryBlueprint::~UModelContextProtocolToolLibraryBlueprint() {}
// ********** End Class UModelContextProtocolToolLibraryBlueprint **********************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolToolLibrary_h__Script_ModelContextProtocolEngine_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UModelContextProtocolToolLibrary, UModelContextProtocolToolLibrary::StaticClass, TEXT("UModelContextProtocolToolLibrary"), &Z_Registration_Info_UClass_UModelContextProtocolToolLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UModelContextProtocolToolLibrary), 3282516860U) },
		{ Z_Construct_UClass_UModelContextProtocolToolLibraryBlueprint, UModelContextProtocolToolLibraryBlueprint::StaticClass, TEXT("UModelContextProtocolToolLibraryBlueprint"), &Z_Registration_Info_UClass_UModelContextProtocolToolLibraryBlueprint, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UModelContextProtocolToolLibraryBlueprint), 3684837121U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolToolLibrary_h__Script_ModelContextProtocolEngine_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolToolLibrary_h__Script_ModelContextProtocolEngine_1216718908{
	TEXT("/Script/ModelContextProtocolEngine"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolToolLibrary_h__Script_ModelContextProtocolEngine_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_ModelContextProtocol_Source_ModelContextProtocolEngine_Public_ModelContextProtocolToolLibrary_h__Script_ModelContextProtocolEngine_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
