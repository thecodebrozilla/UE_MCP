// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameFeaturesToolset.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeGameFeaturesToolset() {}

// ********** Begin Cross Module References ********************************************************
GAMEFEATURESTOOLSET_API UClass* Z_Construct_UClass_UGameFeaturesToolset();
GAMEFEATURESTOOLSET_API UClass* Z_Construct_UClass_UGameFeaturesToolset_NoRegister();
GAMEFEATURESTOOLSET_API UEnum* Z_Construct_UEnum_GameFeaturesToolset_EPluginToolsetGFPState();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition();
UPackage* Z_Construct_UPackage__Script_GameFeaturesToolset();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EPluginToolsetGFPState ****************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPluginToolsetGFPState;
static UEnum* EPluginToolsetGFPState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EPluginToolsetGFPState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EPluginToolsetGFPState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_GameFeaturesToolset_EPluginToolsetGFPState, (UObject*)Z_Construct_UPackage__Script_GameFeaturesToolset(), TEXT("EPluginToolsetGFPState"));
	}
	return Z_Registration_Info_UEnum_EPluginToolsetGFPState.OuterSingleton;
}
template<> GAMEFEATURESTOOLSET_NON_ATTRIBUTED_API UEnum* StaticEnum<EPluginToolsetGFPState>()
{
	return EPluginToolsetGFPState_StaticEnum();
}
struct Z_Construct_UEnum_GameFeaturesToolset_EPluginToolsetGFPState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Active.Name", "EPluginToolsetGFPState::Active" },
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Simplified Game Feature Plugin state for AI tools.\n/// Maps the engine's ~34 internal states to user-facing\n/// states that an LLM would act on.\n" },
#endif
		{ "Installed.Name", "EPluginToolsetGFPState::Installed" },
		{ "Loaded.Name", "EPluginToolsetGFPState::Loaded" },
		{ "ModuleRelativePath", "Private/GameFeaturesToolset.h" },
		{ "Registered.Name", "EPluginToolsetGFPState::Registered" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simplified Game Feature Plugin state for AI tools.\nMaps the engine's ~34 internal states to user-facing\nstates that an LLM would act on." },
#endif
		{ "Uninitialized.Name", "EPluginToolsetGFPState::Uninitialized" },
		{ "Unknown.Name", "EPluginToolsetGFPState::Unknown" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EPluginToolsetGFPState::Uninitialized", (int64)EPluginToolsetGFPState::Uninitialized },
		{ "EPluginToolsetGFPState::Installed", (int64)EPluginToolsetGFPState::Installed },
		{ "EPluginToolsetGFPState::Registered", (int64)EPluginToolsetGFPState::Registered },
		{ "EPluginToolsetGFPState::Loaded", (int64)EPluginToolsetGFPState::Loaded },
		{ "EPluginToolsetGFPState::Active", (int64)EPluginToolsetGFPState::Active },
		{ "EPluginToolsetGFPState::Unknown", (int64)EPluginToolsetGFPState::Unknown },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_GameFeaturesToolset_EPluginToolsetGFPState_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_GameFeaturesToolset_EPluginToolsetGFPState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_GameFeaturesToolset,
	nullptr,
	"EPluginToolsetGFPState",
	"EPluginToolsetGFPState",
	Z_Construct_UEnum_GameFeaturesToolset_EPluginToolsetGFPState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_GameFeaturesToolset_EPluginToolsetGFPState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_GameFeaturesToolset_EPluginToolsetGFPState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_GameFeaturesToolset_EPluginToolsetGFPState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_GameFeaturesToolset_EPluginToolsetGFPState()
{
	if (!Z_Registration_Info_UEnum_EPluginToolsetGFPState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPluginToolsetGFPState.InnerSingleton, Z_Construct_UEnum_GameFeaturesToolset_EPluginToolsetGFPState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EPluginToolsetGFPState.InnerSingleton;
}
// ********** End Enum EPluginToolsetGFPState ******************************************************

// ********** Begin Class UGameFeaturesToolset Function GetGameFeatureState ************************
struct Z_Construct_UFunction_UGameFeaturesToolset_GetGameFeatureState_Statics
{
	struct GameFeaturesToolset_eventGetGameFeatureState_Parms
	{
		FString PluginName;
		EPluginToolsetGFPState ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "GameFeatures" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Gets the current state of a Game Feature Plugin.\n\x09 * @param PluginName Name of the Game Feature Plugin.\n\x09 * @return Simplified state enum. Raises an error if the subsystem is unavailable or the\n\x09 *         plugin is not found.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/GameFeaturesToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Gets the current state of a Game Feature Plugin.\n@param PluginName Name of the Game Feature Plugin.\n@return Simplified state enum. Raises an error if the subsystem is unavailable or the\n        plugin is not found." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetGameFeatureState constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_PluginName;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGameFeatureState constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGameFeatureState Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameFeaturesToolset_GetGameFeatureState_Statics::NewProp_PluginName = { "PluginName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameFeaturesToolset_eventGetGameFeatureState_Parms, PluginName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PluginName_MetaData), NewProp_PluginName_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UGameFeaturesToolset_GetGameFeatureState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UGameFeaturesToolset_GetGameFeatureState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameFeaturesToolset_eventGetGameFeatureState_Parms, ReturnValue), Z_Construct_UEnum_GameFeaturesToolset_EPluginToolsetGFPState, METADATA_PARAMS(0, nullptr) }; // 3384079534
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameFeaturesToolset_GetGameFeatureState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameFeaturesToolset_GetGameFeatureState_Statics::NewProp_PluginName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameFeaturesToolset_GetGameFeatureState_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameFeaturesToolset_GetGameFeatureState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameFeaturesToolset_GetGameFeatureState_Statics::PropPointers) < 2048);
// ********** End Function GetGameFeatureState Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameFeaturesToolset_GetGameFeatureState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGameFeaturesToolset, nullptr, "GetGameFeatureState", 	Z_Construct_UFunction_UGameFeaturesToolset_GetGameFeatureState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGameFeaturesToolset_GetGameFeatureState_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGameFeaturesToolset_GetGameFeatureState_Statics::GameFeaturesToolset_eventGetGameFeatureState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameFeaturesToolset_GetGameFeatureState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameFeaturesToolset_GetGameFeatureState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGameFeaturesToolset_GetGameFeatureState_Statics::GameFeaturesToolset_eventGetGameFeatureState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGameFeaturesToolset_GetGameFeatureState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameFeaturesToolset_GetGameFeatureState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGameFeaturesToolset::execGetGameFeatureState)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_PluginName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EPluginToolsetGFPState*)Z_Param__Result=UGameFeaturesToolset::GetGameFeatureState(Z_Param_PluginName);
	P_NATIVE_END;
}
// ********** End Class UGameFeaturesToolset Function GetGameFeatureState **************************

// ********** Begin Class UGameFeaturesToolset Function IsGameFeatureActive ************************
struct Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeatureActive_Statics
{
	struct GameFeaturesToolset_eventIsGameFeatureActive_Parms
	{
		FString PluginName;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "GameFeatures" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Checks whether a Game Feature Plugin is active. Raises an error if the subsystem is unavailable\n\x09 * or the plugin is not found.\n\x09 * Use GetGameFeatureState if you need the current state when the plugin is not active.\n\x09 * @param PluginName Name of the Game Feature Plugin.\n\x09 * @return True if the Game Feature Plugin is active.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/GameFeaturesToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Checks whether a Game Feature Plugin is active. Raises an error if the subsystem is unavailable\nor the plugin is not found.\nUse GetGameFeatureState if you need the current state when the plugin is not active.\n@param PluginName Name of the Game Feature Plugin.\n@return True if the Game Feature Plugin is active." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsGameFeatureActive constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_PluginName;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsGameFeatureActive constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsGameFeatureActive Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeatureActive_Statics::NewProp_PluginName = { "PluginName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameFeaturesToolset_eventIsGameFeatureActive_Parms, PluginName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PluginName_MetaData), NewProp_PluginName_MetaData) };
void Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeatureActive_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((GameFeaturesToolset_eventIsGameFeatureActive_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeatureActive_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GameFeaturesToolset_eventIsGameFeatureActive_Parms), &Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeatureActive_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeatureActive_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeatureActive_Statics::NewProp_PluginName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeatureActive_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeatureActive_Statics::PropPointers) < 2048);
// ********** End Function IsGameFeatureActive Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeatureActive_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGameFeaturesToolset, nullptr, "IsGameFeatureActive", 	Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeatureActive_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeatureActive_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeatureActive_Statics::GameFeaturesToolset_eventIsGameFeatureActive_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeatureActive_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeatureActive_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeatureActive_Statics::GameFeaturesToolset_eventIsGameFeatureActive_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeatureActive()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeatureActive_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGameFeaturesToolset::execIsGameFeatureActive)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_PluginName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UGameFeaturesToolset::IsGameFeatureActive(Z_Param_PluginName);
	P_NATIVE_END;
}
// ********** End Class UGameFeaturesToolset Function IsGameFeatureActive **************************

// ********** Begin Class UGameFeaturesToolset Function IsGameFeaturePlugin ************************
struct Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeaturePlugin_Statics
{
	struct GameFeaturesToolset_eventIsGameFeaturePlugin_Parms
	{
		FString PluginName;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "GameFeatures" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Return whether or not a plugin is a Game Feature Plugin. Will error if no plugin of this\n\x09 * name can be found by the Plugin Manager.\n\x09 * @param PluginName Name of the plugin\n\x09 * @return True if the plugin is a Game Feature Plugin\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/GameFeaturesToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Return whether or not a plugin is a Game Feature Plugin. Will error if no plugin of this\nname can be found by the Plugin Manager.\n@param PluginName Name of the plugin\n@return True if the plugin is a Game Feature Plugin" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsGameFeaturePlugin constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_PluginName;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsGameFeaturePlugin constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsGameFeaturePlugin Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeaturePlugin_Statics::NewProp_PluginName = { "PluginName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameFeaturesToolset_eventIsGameFeaturePlugin_Parms, PluginName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PluginName_MetaData), NewProp_PluginName_MetaData) };
void Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeaturePlugin_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((GameFeaturesToolset_eventIsGameFeaturePlugin_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeaturePlugin_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GameFeaturesToolset_eventIsGameFeaturePlugin_Parms), &Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeaturePlugin_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeaturePlugin_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeaturePlugin_Statics::NewProp_PluginName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeaturePlugin_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeaturePlugin_Statics::PropPointers) < 2048);
// ********** End Function IsGameFeaturePlugin Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeaturePlugin_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGameFeaturesToolset, nullptr, "IsGameFeaturePlugin", 	Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeaturePlugin_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeaturePlugin_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeaturePlugin_Statics::GameFeaturesToolset_eventIsGameFeaturePlugin_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeaturePlugin_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeaturePlugin_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeaturePlugin_Statics::GameFeaturesToolset_eventIsGameFeaturePlugin_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeaturePlugin()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeaturePlugin_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGameFeaturesToolset::execIsGameFeaturePlugin)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_PluginName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UGameFeaturesToolset::IsGameFeaturePlugin(Z_Param_PluginName);
	P_NATIVE_END;
}
// ********** End Class UGameFeaturesToolset Function IsGameFeaturePlugin **************************

// ********** Begin Class UGameFeaturesToolset Function ListDiscoveredGameFeaturePlugins ***********
struct Z_Construct_UFunction_UGameFeaturesToolset_ListDiscoveredGameFeaturePlugins_Statics
{
	struct GameFeaturesToolset_eventListDiscoveredGameFeaturePlugins_Parms
	{
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "GameFeatures" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Lists all discovered Game Feature Plugins sorted by name. This includes enabled and disabled \n\x09 * plugins. Only enabled plugins are known by the Game Features system beyond identifying if a\n\x09 * plugin is a Game Feature Plugin.\n\x09 * Use the Plugins toolset to do general plugin enable/disable tasks.\n\x09 * @return Sorted names of all discovered Game Feature Plugins.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/GameFeaturesToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lists all discovered Game Feature Plugins sorted by name. This includes enabled and disabled\nplugins. Only enabled plugins are known by the Game Features system beyond identifying if a\nplugin is a Game Feature Plugin.\nUse the Plugins toolset to do general plugin enable/disable tasks.\n@return Sorted names of all discovered Game Feature Plugins." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ListDiscoveredGameFeaturePlugins constinit property declarations ******
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListDiscoveredGameFeaturePlugins constinit property declarations ********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListDiscoveredGameFeaturePlugins Property Definitions *****************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameFeaturesToolset_ListDiscoveredGameFeaturePlugins_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UGameFeaturesToolset_ListDiscoveredGameFeaturePlugins_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameFeaturesToolset_eventListDiscoveredGameFeaturePlugins_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameFeaturesToolset_ListDiscoveredGameFeaturePlugins_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameFeaturesToolset_ListDiscoveredGameFeaturePlugins_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameFeaturesToolset_ListDiscoveredGameFeaturePlugins_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameFeaturesToolset_ListDiscoveredGameFeaturePlugins_Statics::PropPointers) < 2048);
// ********** End Function ListDiscoveredGameFeaturePlugins Property Definitions *******************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameFeaturesToolset_ListDiscoveredGameFeaturePlugins_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGameFeaturesToolset, nullptr, "ListDiscoveredGameFeaturePlugins", 	Z_Construct_UFunction_UGameFeaturesToolset_ListDiscoveredGameFeaturePlugins_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGameFeaturesToolset_ListDiscoveredGameFeaturePlugins_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGameFeaturesToolset_ListDiscoveredGameFeaturePlugins_Statics::GameFeaturesToolset_eventListDiscoveredGameFeaturePlugins_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameFeaturesToolset_ListDiscoveredGameFeaturePlugins_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameFeaturesToolset_ListDiscoveredGameFeaturePlugins_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGameFeaturesToolset_ListDiscoveredGameFeaturePlugins_Statics::GameFeaturesToolset_eventListDiscoveredGameFeaturePlugins_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGameFeaturesToolset_ListDiscoveredGameFeaturePlugins()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameFeaturesToolset_ListDiscoveredGameFeaturePlugins_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGameFeaturesToolset::execListDiscoveredGameFeaturePlugins)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=UGameFeaturesToolset::ListDiscoveredGameFeaturePlugins();
	P_NATIVE_END;
}
// ********** End Class UGameFeaturesToolset Function ListDiscoveredGameFeaturePlugins *************

// ********** Begin Class UGameFeaturesToolset Function ListEnabledGameFeaturePlugins **************
struct Z_Construct_UFunction_UGameFeaturesToolset_ListEnabledGameFeaturePlugins_Statics
{
	struct GameFeaturesToolset_eventListEnabledGameFeaturePlugins_Parms
	{
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "GameFeatures" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Lists all enabled Game Feature Plugins  sorted by name. Enabled plugins are the only plugins\n\x09 * known by the Game Features system beyond identifying if a plugin is a Game Feature Plugin.\n\x09 * Use the Plugins toolset to do general plugin enable/disable tasks.\n\x09 * @return Sorted names of all enabled Game Feature Plugins.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/GameFeaturesToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lists all enabled Game Feature Plugins  sorted by name. Enabled plugins are the only plugins\nknown by the Game Features system beyond identifying if a plugin is a Game Feature Plugin.\nUse the Plugins toolset to do general plugin enable/disable tasks.\n@return Sorted names of all enabled Game Feature Plugins." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ListEnabledGameFeaturePlugins constinit property declarations *********
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListEnabledGameFeaturePlugins constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListEnabledGameFeaturePlugins Property Definitions ********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameFeaturesToolset_ListEnabledGameFeaturePlugins_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UGameFeaturesToolset_ListEnabledGameFeaturePlugins_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameFeaturesToolset_eventListEnabledGameFeaturePlugins_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameFeaturesToolset_ListEnabledGameFeaturePlugins_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameFeaturesToolset_ListEnabledGameFeaturePlugins_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameFeaturesToolset_ListEnabledGameFeaturePlugins_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameFeaturesToolset_ListEnabledGameFeaturePlugins_Statics::PropPointers) < 2048);
// ********** End Function ListEnabledGameFeaturePlugins Property Definitions **********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameFeaturesToolset_ListEnabledGameFeaturePlugins_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGameFeaturesToolset, nullptr, "ListEnabledGameFeaturePlugins", 	Z_Construct_UFunction_UGameFeaturesToolset_ListEnabledGameFeaturePlugins_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGameFeaturesToolset_ListEnabledGameFeaturePlugins_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGameFeaturesToolset_ListEnabledGameFeaturePlugins_Statics::GameFeaturesToolset_eventListEnabledGameFeaturePlugins_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameFeaturesToolset_ListEnabledGameFeaturePlugins_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameFeaturesToolset_ListEnabledGameFeaturePlugins_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGameFeaturesToolset_ListEnabledGameFeaturePlugins_Statics::GameFeaturesToolset_eventListEnabledGameFeaturePlugins_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGameFeaturesToolset_ListEnabledGameFeaturePlugins()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameFeaturesToolset_ListEnabledGameFeaturePlugins_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGameFeaturesToolset::execListEnabledGameFeaturePlugins)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=UGameFeaturesToolset::ListEnabledGameFeaturePlugins();
	P_NATIVE_END;
}
// ********** End Class UGameFeaturesToolset Function ListEnabledGameFeaturePlugins ****************

// ********** Begin Class UGameFeaturesToolset Function RequestActivateGameFeature *****************
struct Z_Construct_UFunction_UGameFeaturesToolset_RequestActivateGameFeature_Statics
{
	struct GameFeaturesToolset_eventRequestActivateGameFeature_Parms
	{
		FString PluginName;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "GameFeatures" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Requests activation of a Game Feature Plugin.\n\x09 * Returns true if the activation request was submitted successfully. The actual activation\n\x09 * happens asynchronously -- poll GetGameFeatureState() or IsGameFeatureActive()\n\x09 * to confirm completion. Raises an error if the subsystem is unavailable\n\x09 * or the plugin is not found.\n\x09 * @param PluginName Name of the GFP.\n\x09 * @return True if the request was submitted.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/GameFeaturesToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Requests activation of a Game Feature Plugin.\nReturns true if the activation request was submitted successfully. The actual activation\nhappens asynchronously -- poll GetGameFeatureState() or IsGameFeatureActive()\nto confirm completion. Raises an error if the subsystem is unavailable\nor the plugin is not found.\n@param PluginName Name of the GFP.\n@return True if the request was submitted." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RequestActivateGameFeature constinit property declarations ************
	static const UECodeGen_Private::FStrPropertyParams NewProp_PluginName;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RequestActivateGameFeature constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RequestActivateGameFeature Property Definitions ***********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameFeaturesToolset_RequestActivateGameFeature_Statics::NewProp_PluginName = { "PluginName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameFeaturesToolset_eventRequestActivateGameFeature_Parms, PluginName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PluginName_MetaData), NewProp_PluginName_MetaData) };
void Z_Construct_UFunction_UGameFeaturesToolset_RequestActivateGameFeature_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((GameFeaturesToolset_eventRequestActivateGameFeature_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGameFeaturesToolset_RequestActivateGameFeature_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GameFeaturesToolset_eventRequestActivateGameFeature_Parms), &Z_Construct_UFunction_UGameFeaturesToolset_RequestActivateGameFeature_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameFeaturesToolset_RequestActivateGameFeature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameFeaturesToolset_RequestActivateGameFeature_Statics::NewProp_PluginName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameFeaturesToolset_RequestActivateGameFeature_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameFeaturesToolset_RequestActivateGameFeature_Statics::PropPointers) < 2048);
// ********** End Function RequestActivateGameFeature Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameFeaturesToolset_RequestActivateGameFeature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGameFeaturesToolset, nullptr, "RequestActivateGameFeature", 	Z_Construct_UFunction_UGameFeaturesToolset_RequestActivateGameFeature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGameFeaturesToolset_RequestActivateGameFeature_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGameFeaturesToolset_RequestActivateGameFeature_Statics::GameFeaturesToolset_eventRequestActivateGameFeature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameFeaturesToolset_RequestActivateGameFeature_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameFeaturesToolset_RequestActivateGameFeature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGameFeaturesToolset_RequestActivateGameFeature_Statics::GameFeaturesToolset_eventRequestActivateGameFeature_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGameFeaturesToolset_RequestActivateGameFeature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameFeaturesToolset_RequestActivateGameFeature_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGameFeaturesToolset::execRequestActivateGameFeature)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_PluginName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UGameFeaturesToolset::RequestActivateGameFeature(Z_Param_PluginName);
	P_NATIVE_END;
}
// ********** End Class UGameFeaturesToolset Function RequestActivateGameFeature *******************

// ********** Begin Class UGameFeaturesToolset Function RequestDeactivateGameFeature ***************
struct Z_Construct_UFunction_UGameFeaturesToolset_RequestDeactivateGameFeature_Statics
{
	struct GameFeaturesToolset_eventRequestDeactivateGameFeature_Parms
	{
		FString PluginName;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "GameFeatures" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Requests deactivation of a Game Feature Plugin.\n\x09 * Returns true if the deactivation request was submitted successfully. The actual deactivation\n\x09 * happens asynchronously -- poll GetGameFeatureState() to confirm completion.\n\x09 * Raises an error if the subsystem is unavailable or the plugin is not found.\n\x09 * @param PluginName Name of the GFP.\n\x09 * @return True if the request was submitted.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/GameFeaturesToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Requests deactivation of a Game Feature Plugin.\nReturns true if the deactivation request was submitted successfully. The actual deactivation\nhappens asynchronously -- poll GetGameFeatureState() to confirm completion.\nRaises an error if the subsystem is unavailable or the plugin is not found.\n@param PluginName Name of the GFP.\n@return True if the request was submitted." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RequestDeactivateGameFeature constinit property declarations **********
	static const UECodeGen_Private::FStrPropertyParams NewProp_PluginName;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RequestDeactivateGameFeature constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RequestDeactivateGameFeature Property Definitions *********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameFeaturesToolset_RequestDeactivateGameFeature_Statics::NewProp_PluginName = { "PluginName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameFeaturesToolset_eventRequestDeactivateGameFeature_Parms, PluginName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PluginName_MetaData), NewProp_PluginName_MetaData) };
void Z_Construct_UFunction_UGameFeaturesToolset_RequestDeactivateGameFeature_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((GameFeaturesToolset_eventRequestDeactivateGameFeature_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGameFeaturesToolset_RequestDeactivateGameFeature_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GameFeaturesToolset_eventRequestDeactivateGameFeature_Parms), &Z_Construct_UFunction_UGameFeaturesToolset_RequestDeactivateGameFeature_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameFeaturesToolset_RequestDeactivateGameFeature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameFeaturesToolset_RequestDeactivateGameFeature_Statics::NewProp_PluginName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameFeaturesToolset_RequestDeactivateGameFeature_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameFeaturesToolset_RequestDeactivateGameFeature_Statics::PropPointers) < 2048);
// ********** End Function RequestDeactivateGameFeature Property Definitions ***********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameFeaturesToolset_RequestDeactivateGameFeature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGameFeaturesToolset, nullptr, "RequestDeactivateGameFeature", 	Z_Construct_UFunction_UGameFeaturesToolset_RequestDeactivateGameFeature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGameFeaturesToolset_RequestDeactivateGameFeature_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGameFeaturesToolset_RequestDeactivateGameFeature_Statics::GameFeaturesToolset_eventRequestDeactivateGameFeature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameFeaturesToolset_RequestDeactivateGameFeature_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameFeaturesToolset_RequestDeactivateGameFeature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGameFeaturesToolset_RequestDeactivateGameFeature_Statics::GameFeaturesToolset_eventRequestDeactivateGameFeature_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGameFeaturesToolset_RequestDeactivateGameFeature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameFeaturesToolset_RequestDeactivateGameFeature_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGameFeaturesToolset::execRequestDeactivateGameFeature)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_PluginName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UGameFeaturesToolset::RequestDeactivateGameFeature(Z_Param_PluginName);
	P_NATIVE_END;
}
// ********** End Class UGameFeaturesToolset Function RequestDeactivateGameFeature *****************

// ********** Begin Class UGameFeaturesToolset *****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UGameFeaturesToolset;
UClass* UGameFeaturesToolset::GetPrivateStaticClass()
{
	using TClass = UGameFeaturesToolset;
	if (!Z_Registration_Info_UClass_UGameFeaturesToolset.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("GameFeaturesToolset"),
			Z_Registration_Info_UClass_UGameFeaturesToolset.InnerSingleton,
			StaticRegisterNativesUGameFeaturesToolset,
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
	return Z_Registration_Info_UClass_UGameFeaturesToolset.InnerSingleton;
}
UClass* Z_Construct_UClass_UGameFeaturesToolset_NoRegister()
{
	return UGameFeaturesToolset::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UGameFeaturesToolset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// Provides tools for listing, activating, and deactivating Game Feature Plugins.\n" },
#endif
		{ "IncludePath", "GameFeaturesToolset.h" },
		{ "ModuleRelativePath", "Private/GameFeaturesToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Provides tools for listing, activating, and deactivating Game Feature Plugins." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UGameFeaturesToolset constinit property declarations *********************
// ********** End Class UGameFeaturesToolset constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetGameFeatureState"), .Pointer = &UGameFeaturesToolset::execGetGameFeatureState },
		{ .NameUTF8 = UTF8TEXT("IsGameFeatureActive"), .Pointer = &UGameFeaturesToolset::execIsGameFeatureActive },
		{ .NameUTF8 = UTF8TEXT("IsGameFeaturePlugin"), .Pointer = &UGameFeaturesToolset::execIsGameFeaturePlugin },
		{ .NameUTF8 = UTF8TEXT("ListDiscoveredGameFeaturePlugins"), .Pointer = &UGameFeaturesToolset::execListDiscoveredGameFeaturePlugins },
		{ .NameUTF8 = UTF8TEXT("ListEnabledGameFeaturePlugins"), .Pointer = &UGameFeaturesToolset::execListEnabledGameFeaturePlugins },
		{ .NameUTF8 = UTF8TEXT("RequestActivateGameFeature"), .Pointer = &UGameFeaturesToolset::execRequestActivateGameFeature },
		{ .NameUTF8 = UTF8TEXT("RequestDeactivateGameFeature"), .Pointer = &UGameFeaturesToolset::execRequestDeactivateGameFeature },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UGameFeaturesToolset_GetGameFeatureState, "GetGameFeatureState" }, // 2288725651
		{ &Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeatureActive, "IsGameFeatureActive" }, // 2796136173
		{ &Z_Construct_UFunction_UGameFeaturesToolset_IsGameFeaturePlugin, "IsGameFeaturePlugin" }, // 3878616345
		{ &Z_Construct_UFunction_UGameFeaturesToolset_ListDiscoveredGameFeaturePlugins, "ListDiscoveredGameFeaturePlugins" }, // 3457613920
		{ &Z_Construct_UFunction_UGameFeaturesToolset_ListEnabledGameFeaturePlugins, "ListEnabledGameFeaturePlugins" }, // 2091278139
		{ &Z_Construct_UFunction_UGameFeaturesToolset_RequestActivateGameFeature, "RequestActivateGameFeature" }, // 4010361433
		{ &Z_Construct_UFunction_UGameFeaturesToolset_RequestDeactivateGameFeature, "RequestDeactivateGameFeature" }, // 656753177
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameFeaturesToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UGameFeaturesToolset_Statics
UObject* (*const Z_Construct_UClass_UGameFeaturesToolset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UToolsetDefinition,
	(UObject* (*)())Z_Construct_UPackage__Script_GameFeaturesToolset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGameFeaturesToolset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGameFeaturesToolset_Statics::ClassParams = {
	&UGameFeaturesToolset::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGameFeaturesToolset_Statics::Class_MetaDataParams), Z_Construct_UClass_UGameFeaturesToolset_Statics::Class_MetaDataParams)
};
void UGameFeaturesToolset::StaticRegisterNativesUGameFeaturesToolset()
{
	UClass* Class = UGameFeaturesToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UGameFeaturesToolset_Statics::Funcs));
}
UClass* Z_Construct_UClass_UGameFeaturesToolset()
{
	if (!Z_Registration_Info_UClass_UGameFeaturesToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGameFeaturesToolset.OuterSingleton, Z_Construct_UClass_UGameFeaturesToolset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGameFeaturesToolset.OuterSingleton;
}
UGameFeaturesToolset::UGameFeaturesToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UGameFeaturesToolset);
UGameFeaturesToolset::~UGameFeaturesToolset() {}
// ********** End Class UGameFeaturesToolset *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GameFeaturesToolset_Source_GameFeaturesToolset_Private_GameFeaturesToolset_h__Script_GameFeaturesToolset_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EPluginToolsetGFPState_StaticEnum, TEXT("EPluginToolsetGFPState"), &Z_Registration_Info_UEnum_EPluginToolsetGFPState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3384079534U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGameFeaturesToolset, UGameFeaturesToolset::StaticClass, TEXT("UGameFeaturesToolset"), &Z_Registration_Info_UClass_UGameFeaturesToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGameFeaturesToolset), 4267263430U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GameFeaturesToolset_Source_GameFeaturesToolset_Private_GameFeaturesToolset_h__Script_GameFeaturesToolset_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GameFeaturesToolset_Source_GameFeaturesToolset_Private_GameFeaturesToolset_h__Script_GameFeaturesToolset_3587133399{
	TEXT("/Script/GameFeaturesToolset"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GameFeaturesToolset_Source_GameFeaturesToolset_Private_GameFeaturesToolset_h__Script_GameFeaturesToolset_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GameFeaturesToolset_Source_GameFeaturesToolset_Private_GameFeaturesToolset_h__Script_GameFeaturesToolset_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GameFeaturesToolset_Source_GameFeaturesToolset_Private_GameFeaturesToolset_h__Script_GameFeaturesToolset_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_GameFeaturesToolset_Source_GameFeaturesToolset_Private_GameFeaturesToolset_h__Script_GameFeaturesToolset_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
