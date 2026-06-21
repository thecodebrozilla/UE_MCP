// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DataflowAgentToolset.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeDataflowAgentToolset() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
DATAFLOWAGENT_API UClass* Z_Construct_UClass_UDataflowAgentToolset();
DATAFLOWAGENT_API UClass* Z_Construct_UClass_UDataflowAgentToolset_NoRegister();
DATAFLOWENGINE_API UClass* Z_Construct_UClass_UDataflow_NoRegister();
DATAFLOWENGINE_API UClass* Z_Construct_UClass_UDataflowEdNode_NoRegister();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition();
UPackage* Z_Construct_UPackage__Script_DataflowAgent();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDataflowAgentToolset Function AddCommentBox *****************************
struct Z_Construct_UFunction_UDataflowAgentToolset_AddCommentBox_Statics
{
	struct DataflowAgentToolset_eventAddCommentBox_Parms
	{
		UDataflow* Graph;
		TArray<UDataflowEdNode*> Nodes;
		FString Comment;
		FLinearColor Color;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "Dataflow|Comments" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Adds a comment box around the given nodes.\n\x09 *\n\x09 * @param Graph   - The Dataflow asset to add the comment to\n\x09 * @param Nodes   - List of EdNodes to surround with the comment box\n\x09 * @param Comment - Text to display on the comment box\n\x09 * @param Color   - Background color of the comment box (defaults to White)\n\x09 * @return Node ID string of the created comment node, or empty string on failure\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/DataflowAgentToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds a comment box around the given nodes.\n\n@param Graph   - The Dataflow asset to add the comment to\n@param Nodes   - List of EdNodes to surround with the comment box\n@param Comment - Text to display on the comment box\n@param Color   - Background color of the comment box (defaults to White)\n@return Node ID string of the created comment node, or empty string on failure" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Nodes_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Comment_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddCommentBox constinit property declarations *************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Graph;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Nodes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Nodes;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Comment;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Color;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddCommentBox constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddCommentBox Property Definitions ************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_AddCommentBox_Statics::NewProp_Graph = { "Graph", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventAddCommentBox_Parms, Graph), Z_Construct_UClass_UDataflow_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_AddCommentBox_Statics::NewProp_Nodes_Inner = { "Nodes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UDataflowEdNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_AddCommentBox_Statics::NewProp_Nodes = { "Nodes", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventAddCommentBox_Parms, Nodes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Nodes_MetaData), NewProp_Nodes_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_AddCommentBox_Statics::NewProp_Comment = { "Comment", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventAddCommentBox_Parms, Comment), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Comment_MetaData), NewProp_Comment_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_AddCommentBox_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventAddCommentBox_Parms, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_AddCommentBox_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventAddCommentBox_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataflowAgentToolset_AddCommentBox_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_AddCommentBox_Statics::NewProp_Graph,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_AddCommentBox_Statics::NewProp_Nodes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_AddCommentBox_Statics::NewProp_Nodes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_AddCommentBox_Statics::NewProp_Comment,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_AddCommentBox_Statics::NewProp_Color,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_AddCommentBox_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_AddCommentBox_Statics::PropPointers) < 2048);
// ********** End Function AddCommentBox Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataflowAgentToolset_AddCommentBox_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDataflowAgentToolset, nullptr, "AddCommentBox", 	Z_Construct_UFunction_UDataflowAgentToolset_AddCommentBox_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_AddCommentBox_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDataflowAgentToolset_AddCommentBox_Statics::DataflowAgentToolset_eventAddCommentBox_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_AddCommentBox_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDataflowAgentToolset_AddCommentBox_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDataflowAgentToolset_AddCommentBox_Statics::DataflowAgentToolset_eventAddCommentBox_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDataflowAgentToolset_AddCommentBox()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataflowAgentToolset_AddCommentBox_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDataflowAgentToolset::execAddCommentBox)
{
	P_GET_OBJECT(UDataflow,Z_Param_Graph);
	P_GET_TARRAY_REF(UDataflowEdNode*,Z_Param_Out_Nodes);
	P_GET_PROPERTY(FStrProperty,Z_Param_Comment);
	P_GET_STRUCT(FLinearColor,Z_Param_Color);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UDataflowAgentToolset::AddCommentBox(Z_Param_Graph,Z_Param_Out_Nodes,Z_Param_Comment,Z_Param_Color);
	P_NATIVE_END;
}
// ********** End Class UDataflowAgentToolset Function AddCommentBox *******************************

// ********** Begin Class UDataflowAgentToolset Function AddNode ***********************************
struct Z_Construct_UFunction_UDataflowAgentToolset_AddNode_Statics
{
	struct DataflowAgentToolset_eventAddNode_Parms
	{
		UDataflow* Graph;
		FString TypeName;
		FString NodeName;
		FString JsonParams;
		int32 X;
		int32 Y;
		UDataflowEdNode* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "Dataflow|Nodes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Adds a node of the given type to the Dataflow graph.\n\x09 *\n\x09 * @param Graph      - The Dataflow asset to add the node to\n\x09 * @param TypeName   - The node type name (e.g., \"FAddFloatsDataflowNode\")\n\x09 * @param NodeName   - Unique name for the node within this graph\n\x09 * @param JsonParams - Optional JSON object of property overrides (e.g., {\"Value\": 3.14})\n\x09 * @param X          - X position in the graph editor (default 0, typical node width ~200)\n\x09 * @param Y          - Y position in the graph editor (default 0, typical node height ~100)\n\x09 * @return The newly created UDataflowEdNode, or nullptr on failure\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/DataflowAgentToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds a node of the given type to the Dataflow graph.\n\n@param Graph      - The Dataflow asset to add the node to\n@param TypeName   - The node type name (e.g., \"FAddFloatsDataflowNode\")\n@param NodeName   - Unique name for the node within this graph\n@param JsonParams - Optional JSON object of property overrides (e.g., {\"Value\": 3.14})\n@param X          - X position in the graph editor (default 0, typical node width ~200)\n@param Y          - Y position in the graph editor (default 0, typical node height ~100)\n@return The newly created UDataflowEdNode, or nullptr on failure" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TypeName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NodeName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonParams_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_X_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Y_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddNode constinit property declarations *******************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Graph;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TypeName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_NodeName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_JsonParams;
	static const UECodeGen_Private::FIntPropertyParams NewProp_X;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Y;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddNode constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddNode Property Definitions ******************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_AddNode_Statics::NewProp_Graph = { "Graph", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventAddNode_Parms, Graph), Z_Construct_UClass_UDataflow_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_AddNode_Statics::NewProp_TypeName = { "TypeName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventAddNode_Parms, TypeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TypeName_MetaData), NewProp_TypeName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_AddNode_Statics::NewProp_NodeName = { "NodeName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventAddNode_Parms, NodeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NodeName_MetaData), NewProp_NodeName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_AddNode_Statics::NewProp_JsonParams = { "JsonParams", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventAddNode_Parms, JsonParams), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonParams_MetaData), NewProp_JsonParams_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_AddNode_Statics::NewProp_X = { "X", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventAddNode_Parms, X), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_X_MetaData), NewProp_X_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_AddNode_Statics::NewProp_Y = { "Y", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventAddNode_Parms, Y), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Y_MetaData), NewProp_Y_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_AddNode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventAddNode_Parms, ReturnValue), Z_Construct_UClass_UDataflowEdNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataflowAgentToolset_AddNode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_AddNode_Statics::NewProp_Graph,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_AddNode_Statics::NewProp_TypeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_AddNode_Statics::NewProp_NodeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_AddNode_Statics::NewProp_JsonParams,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_AddNode_Statics::NewProp_X,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_AddNode_Statics::NewProp_Y,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_AddNode_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_AddNode_Statics::PropPointers) < 2048);
// ********** End Function AddNode Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataflowAgentToolset_AddNode_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDataflowAgentToolset, nullptr, "AddNode", 	Z_Construct_UFunction_UDataflowAgentToolset_AddNode_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_AddNode_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDataflowAgentToolset_AddNode_Statics::DataflowAgentToolset_eventAddNode_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_AddNode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDataflowAgentToolset_AddNode_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDataflowAgentToolset_AddNode_Statics::DataflowAgentToolset_eventAddNode_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDataflowAgentToolset_AddNode()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataflowAgentToolset_AddNode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDataflowAgentToolset::execAddNode)
{
	P_GET_OBJECT(UDataflow,Z_Param_Graph);
	P_GET_PROPERTY(FStrProperty,Z_Param_TypeName);
	P_GET_PROPERTY(FStrProperty,Z_Param_NodeName);
	P_GET_PROPERTY(FStrProperty,Z_Param_JsonParams);
	P_GET_PROPERTY(FIntProperty,Z_Param_X);
	P_GET_PROPERTY(FIntProperty,Z_Param_Y);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UDataflowEdNode**)Z_Param__Result=UDataflowAgentToolset::AddNode(Z_Param_Graph,Z_Param_TypeName,Z_Param_NodeName,Z_Param_JsonParams,Z_Param_X,Z_Param_Y);
	P_NATIVE_END;
}
// ********** End Class UDataflowAgentToolset Function AddNode *************************************

// ********** Begin Class UDataflowAgentToolset Function AddVariable *******************************
struct Z_Construct_UFunction_UDataflowAgentToolset_AddVariable_Statics
{
	struct DataflowAgentToolset_eventAddVariable_Parms
	{
		UDataflow* Graph;
		FString Name;
		FString Type;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "Dataflow|Variables" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Adds a new variable to the Dataflow graph.\n\x09 *\n\x09 * Supported type strings:\n\x09 *   Primitives : \"Bool\", \"Int32\", \"Int64\", \"Float\", \"Double\", \"Name\", \"String\"\n\x09 *   Structs    : UScriptStruct name with or without the \"F\" prefix\n\x09 *                e.g. \"Vector\", \"FVector\", \"Transform\", \"FTransform\", \"Rotator\", \"LinearColor\"\n\x09 *   Objects    : \"Object:<ClassName>\" where ClassName is with or without the \"U\"/\"A\" prefix\n\x09 *                e.g. \"Object:StaticMesh\", \"Object:USkeletalMesh\"\n\x09 *\n\x09 * @param Graph - The Dataflow asset to modify\n\x09 * @param Name  - Unique name for the new variable\n\x09 * @param Type  - Type string as described above\n\x09 * @return true on success, false if the variable already exists or the type cannot be resolved\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/DataflowAgentToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds a new variable to the Dataflow graph.\n\nSupported type strings:\n  Primitives : \"Bool\", \"Int32\", \"Int64\", \"Float\", \"Double\", \"Name\", \"String\"\n  Structs    : UScriptStruct name with or without the \"F\" prefix\n               e.g. \"Vector\", \"FVector\", \"Transform\", \"FTransform\", \"Rotator\", \"LinearColor\"\n  Objects    : \"Object:<ClassName>\" where ClassName is with or without the \"U\"/\"A\" prefix\n               e.g. \"Object:StaticMesh\", \"Object:USkeletalMesh\"\n\n@param Graph - The Dataflow asset to modify\n@param Name  - Unique name for the new variable\n@param Type  - Type string as described above\n@return true on success, false if the variable already exists or the type cannot be resolved" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Type_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddVariable constinit property declarations ***************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Graph;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Type;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddVariable constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddVariable Property Definitions **************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_AddVariable_Statics::NewProp_Graph = { "Graph", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventAddVariable_Parms, Graph), Z_Construct_UClass_UDataflow_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_AddVariable_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventAddVariable_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_AddVariable_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventAddVariable_Parms, Type), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Type_MetaData), NewProp_Type_MetaData) };
void Z_Construct_UFunction_UDataflowAgentToolset_AddVariable_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((DataflowAgentToolset_eventAddVariable_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_AddVariable_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DataflowAgentToolset_eventAddVariable_Parms), &Z_Construct_UFunction_UDataflowAgentToolset_AddVariable_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataflowAgentToolset_AddVariable_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_AddVariable_Statics::NewProp_Graph,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_AddVariable_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_AddVariable_Statics::NewProp_Type,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_AddVariable_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_AddVariable_Statics::PropPointers) < 2048);
// ********** End Function AddVariable Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataflowAgentToolset_AddVariable_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDataflowAgentToolset, nullptr, "AddVariable", 	Z_Construct_UFunction_UDataflowAgentToolset_AddVariable_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_AddVariable_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDataflowAgentToolset_AddVariable_Statics::DataflowAgentToolset_eventAddVariable_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_AddVariable_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDataflowAgentToolset_AddVariable_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDataflowAgentToolset_AddVariable_Statics::DataflowAgentToolset_eventAddVariable_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDataflowAgentToolset_AddVariable()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataflowAgentToolset_AddVariable_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDataflowAgentToolset::execAddVariable)
{
	P_GET_OBJECT(UDataflow,Z_Param_Graph);
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FStrProperty,Z_Param_Type);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UDataflowAgentToolset::AddVariable(Z_Param_Graph,Z_Param_Name,Z_Param_Type);
	P_NATIVE_END;
}
// ********** End Class UDataflowAgentToolset Function AddVariable *********************************

// ********** Begin Class UDataflowAgentToolset Function AssignDataflowTemplate ********************
struct Z_Construct_UFunction_UDataflowAgentToolset_AssignDataflowTemplate_Statics
{
	struct DataflowAgentToolset_eventAssignDataflowTemplate_Parms
	{
		UObject* Asset;
		FString TemplateId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "Dataflow|Templates" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Assigns a Dataflow template to an existing Dataflow-compatible asset by duplicating\n\x09 * the template graph and embedding it. Replaces any existing embedded graph.\n\x09 *\n\x09 * @param Asset      - The target asset (must implement IDataflowInstanceInterface)\n\x09 * @param TemplateId - Template identifier returned by ListDataflowTemplatesForAssetClass.\n\x09 *                     Pass an empty string to assign a fresh empty graph.\n\x09 * @return true on success, false on failure\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/DataflowAgentToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Assigns a Dataflow template to an existing Dataflow-compatible asset by duplicating\nthe template graph and embedding it. Replaces any existing embedded graph.\n\n@param Asset      - The target asset (must implement IDataflowInstanceInterface)\n@param TemplateId - Template identifier returned by ListDataflowTemplatesForAssetClass.\n                    Pass an empty string to assign a fresh empty graph.\n@return true on success, false on failure" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TemplateId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AssignDataflowTemplate constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Asset;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TemplateId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AssignDataflowTemplate constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AssignDataflowTemplate Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_AssignDataflowTemplate_Statics::NewProp_Asset = { "Asset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventAssignDataflowTemplate_Parms, Asset), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_AssignDataflowTemplate_Statics::NewProp_TemplateId = { "TemplateId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventAssignDataflowTemplate_Parms, TemplateId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TemplateId_MetaData), NewProp_TemplateId_MetaData) };
void Z_Construct_UFunction_UDataflowAgentToolset_AssignDataflowTemplate_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((DataflowAgentToolset_eventAssignDataflowTemplate_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_AssignDataflowTemplate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DataflowAgentToolset_eventAssignDataflowTemplate_Parms), &Z_Construct_UFunction_UDataflowAgentToolset_AssignDataflowTemplate_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataflowAgentToolset_AssignDataflowTemplate_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_AssignDataflowTemplate_Statics::NewProp_Asset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_AssignDataflowTemplate_Statics::NewProp_TemplateId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_AssignDataflowTemplate_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_AssignDataflowTemplate_Statics::PropPointers) < 2048);
// ********** End Function AssignDataflowTemplate Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataflowAgentToolset_AssignDataflowTemplate_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDataflowAgentToolset, nullptr, "AssignDataflowTemplate", 	Z_Construct_UFunction_UDataflowAgentToolset_AssignDataflowTemplate_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_AssignDataflowTemplate_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDataflowAgentToolset_AssignDataflowTemplate_Statics::DataflowAgentToolset_eventAssignDataflowTemplate_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_AssignDataflowTemplate_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDataflowAgentToolset_AssignDataflowTemplate_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDataflowAgentToolset_AssignDataflowTemplate_Statics::DataflowAgentToolset_eventAssignDataflowTemplate_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDataflowAgentToolset_AssignDataflowTemplate()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataflowAgentToolset_AssignDataflowTemplate_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDataflowAgentToolset::execAssignDataflowTemplate)
{
	P_GET_OBJECT(UObject,Z_Param_Asset);
	P_GET_PROPERTY(FStrProperty,Z_Param_TemplateId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UDataflowAgentToolset::AssignDataflowTemplate(Z_Param_Asset,Z_Param_TemplateId);
	P_NATIVE_END;
}
// ********** End Class UDataflowAgentToolset Function AssignDataflowTemplate **********************

// ********** Begin Class UDataflowAgentToolset Function ConnectNodePins ***************************
struct Z_Construct_UFunction_UDataflowAgentToolset_ConnectNodePins_Statics
{
	struct DataflowAgentToolset_eventConnectNodePins_Parms
	{
		UDataflowEdNode* FromNode;
		FString FromPin;
		UDataflowEdNode* ToNode;
		FString ToPin;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "Dataflow|Connections" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Connects an output pin of one node to an input pin of another.\n\x09 *\n\x09 * @param FromNode - The source EdNode\n\x09 * @param FromPin  - Name of the output pin on the source node\n\x09 * @param ToNode   - The destination EdNode\n\x09 * @param ToPin    - Name of the input pin on the destination node\n\x09 * @return true on success, false on failure\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/DataflowAgentToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Connects an output pin of one node to an input pin of another.\n\n@param FromNode - The source EdNode\n@param FromPin  - Name of the output pin on the source node\n@param ToNode   - The destination EdNode\n@param ToPin    - Name of the input pin on the destination node\n@return true on success, false on failure" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FromPin_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ToPin_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ConnectNodePins constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FromNode;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FromPin;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ToNode;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ToPin;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ConnectNodePins constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ConnectNodePins Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_ConnectNodePins_Statics::NewProp_FromNode = { "FromNode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventConnectNodePins_Parms, FromNode), Z_Construct_UClass_UDataflowEdNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_ConnectNodePins_Statics::NewProp_FromPin = { "FromPin", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventConnectNodePins_Parms, FromPin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FromPin_MetaData), NewProp_FromPin_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_ConnectNodePins_Statics::NewProp_ToNode = { "ToNode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventConnectNodePins_Parms, ToNode), Z_Construct_UClass_UDataflowEdNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_ConnectNodePins_Statics::NewProp_ToPin = { "ToPin", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventConnectNodePins_Parms, ToPin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ToPin_MetaData), NewProp_ToPin_MetaData) };
void Z_Construct_UFunction_UDataflowAgentToolset_ConnectNodePins_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((DataflowAgentToolset_eventConnectNodePins_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_ConnectNodePins_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DataflowAgentToolset_eventConnectNodePins_Parms), &Z_Construct_UFunction_UDataflowAgentToolset_ConnectNodePins_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataflowAgentToolset_ConnectNodePins_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_ConnectNodePins_Statics::NewProp_FromNode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_ConnectNodePins_Statics::NewProp_FromPin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_ConnectNodePins_Statics::NewProp_ToNode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_ConnectNodePins_Statics::NewProp_ToPin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_ConnectNodePins_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_ConnectNodePins_Statics::PropPointers) < 2048);
// ********** End Function ConnectNodePins Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataflowAgentToolset_ConnectNodePins_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDataflowAgentToolset, nullptr, "ConnectNodePins", 	Z_Construct_UFunction_UDataflowAgentToolset_ConnectNodePins_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_ConnectNodePins_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDataflowAgentToolset_ConnectNodePins_Statics::DataflowAgentToolset_eventConnectNodePins_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_ConnectNodePins_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDataflowAgentToolset_ConnectNodePins_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDataflowAgentToolset_ConnectNodePins_Statics::DataflowAgentToolset_eventConnectNodePins_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDataflowAgentToolset_ConnectNodePins()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataflowAgentToolset_ConnectNodePins_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDataflowAgentToolset::execConnectNodePins)
{
	P_GET_OBJECT(UDataflowEdNode,Z_Param_FromNode);
	P_GET_PROPERTY(FStrProperty,Z_Param_FromPin);
	P_GET_OBJECT(UDataflowEdNode,Z_Param_ToNode);
	P_GET_PROPERTY(FStrProperty,Z_Param_ToPin);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UDataflowAgentToolset::ConnectNodePins(Z_Param_FromNode,Z_Param_FromPin,Z_Param_ToNode,Z_Param_ToPin);
	P_NATIVE_END;
}
// ********** End Class UDataflowAgentToolset Function ConnectNodePins *****************************

// ********** Begin Class UDataflowAgentToolset Function CreateDataflowCompatibleAsset *************
struct Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAsset_Statics
{
	struct DataflowAgentToolset_eventCreateDataflowCompatibleAsset_Parms
	{
		FString ClassName;
		FString Name;
		FString Path;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "Dataflow|Assets" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Creates a new Dataflow-compatible asset (e.g. ChaosClothAsset, GeometryCollection,\n\x09 * FleshAsset, GroomAsset) with an empty embedded Dataflow graph.\n\x09 *\n\x09 * @param ClassName - Asset class name with or without the \"U\"/\"A\" prefix\n\x09 *                    (e.g. \"ChaosClothAsset\" or \"UChaosClothAsset\")\n\x09 * @param Name      - Name for the new asset\n\x09 * @param Path      - Content folder path where the asset should be created. Defaults to \"/Game/Dataflow\"\n\x09 * @return The full asset path of the created asset, or empty string on failure\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/DataflowAgentToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Creates a new Dataflow-compatible asset (e.g. ChaosClothAsset, GeometryCollection,\nFleshAsset, GroomAsset) with an empty embedded Dataflow graph.\n\n@param ClassName - Asset class name with or without the \"U\"/\"A\" prefix\n                   (e.g. \"ChaosClothAsset\" or \"UChaosClothAsset\")\n@param Name      - Name for the new asset\n@param Path      - Content folder path where the asset should be created. Defaults to \"/Game/Dataflow\"\n@return The full asset path of the created asset, or empty string on failure" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClassName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Path_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CreateDataflowCompatibleAsset constinit property declarations *********
	static const UECodeGen_Private::FStrPropertyParams NewProp_ClassName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Path;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CreateDataflowCompatibleAsset constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CreateDataflowCompatibleAsset Property Definitions ********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAsset_Statics::NewProp_ClassName = { "ClassName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventCreateDataflowCompatibleAsset_Parms, ClassName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClassName_MetaData), NewProp_ClassName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAsset_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventCreateDataflowCompatibleAsset_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAsset_Statics::NewProp_Path = { "Path", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventCreateDataflowCompatibleAsset_Parms, Path), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Path_MetaData), NewProp_Path_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAsset_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventCreateDataflowCompatibleAsset_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAsset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAsset_Statics::NewProp_ClassName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAsset_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAsset_Statics::NewProp_Path,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAsset_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAsset_Statics::PropPointers) < 2048);
// ********** End Function CreateDataflowCompatibleAsset Property Definitions **********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAsset_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDataflowAgentToolset, nullptr, "CreateDataflowCompatibleAsset", 	Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAsset_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAsset_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAsset_Statics::DataflowAgentToolset_eventCreateDataflowCompatibleAsset_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAsset_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAsset_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAsset_Statics::DataflowAgentToolset_eventCreateDataflowCompatibleAsset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAsset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAsset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDataflowAgentToolset::execCreateDataflowCompatibleAsset)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ClassName);
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FStrProperty,Z_Param_Path);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UDataflowAgentToolset::CreateDataflowCompatibleAsset(Z_Param_ClassName,Z_Param_Name,Z_Param_Path);
	P_NATIVE_END;
}
// ********** End Class UDataflowAgentToolset Function CreateDataflowCompatibleAsset ***************

// ********** Begin Class UDataflowAgentToolset Function CreateDataflowCompatibleAssetFromTemplate *
struct Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAssetFromTemplate_Statics
{
	struct DataflowAgentToolset_eventCreateDataflowCompatibleAssetFromTemplate_Parms
	{
		FString ClassName;
		FString Name;
		FString Path;
		FString TemplateId;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "Dataflow|Assets" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Creates a new Dataflow-compatible asset and initialises its embedded Dataflow graph\n\x09 * from a registered template in one step.\n\x09 *\n\x09 * @param ClassName  - Asset class name with or without the \"U\"/\"A\" prefix\n\x09 * @param Name       - Name for the new asset\n\x09 * @param Path       - Content folder path\n\x09 * @param TemplateId - Template identifier returned by ListDataflowTemplatesForAssetClass.\n\x09 *                     Pass an empty string to create with an empty embedded graph\n\x09 *                     (equivalent to CreateDataflowCompatibleAsset).\n\x09 * @return The full asset path of the created asset, or empty string on failure\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/DataflowAgentToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Creates a new Dataflow-compatible asset and initialises its embedded Dataflow graph\nfrom a registered template in one step.\n\n@param ClassName  - Asset class name with or without the \"U\"/\"A\" prefix\n@param Name       - Name for the new asset\n@param Path       - Content folder path\n@param TemplateId - Template identifier returned by ListDataflowTemplatesForAssetClass.\n                    Pass an empty string to create with an empty embedded graph\n                    (equivalent to CreateDataflowCompatibleAsset).\n@return The full asset path of the created asset, or empty string on failure" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClassName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Path_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TemplateId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CreateDataflowCompatibleAssetFromTemplate constinit property declarations 
	static const UECodeGen_Private::FStrPropertyParams NewProp_ClassName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Path;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TemplateId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CreateDataflowCompatibleAssetFromTemplate constinit property declarations 
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CreateDataflowCompatibleAssetFromTemplate Property Definitions ********
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAssetFromTemplate_Statics::NewProp_ClassName = { "ClassName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventCreateDataflowCompatibleAssetFromTemplate_Parms, ClassName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClassName_MetaData), NewProp_ClassName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAssetFromTemplate_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventCreateDataflowCompatibleAssetFromTemplate_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAssetFromTemplate_Statics::NewProp_Path = { "Path", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventCreateDataflowCompatibleAssetFromTemplate_Parms, Path), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Path_MetaData), NewProp_Path_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAssetFromTemplate_Statics::NewProp_TemplateId = { "TemplateId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventCreateDataflowCompatibleAssetFromTemplate_Parms, TemplateId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TemplateId_MetaData), NewProp_TemplateId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAssetFromTemplate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventCreateDataflowCompatibleAssetFromTemplate_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAssetFromTemplate_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAssetFromTemplate_Statics::NewProp_ClassName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAssetFromTemplate_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAssetFromTemplate_Statics::NewProp_Path,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAssetFromTemplate_Statics::NewProp_TemplateId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAssetFromTemplate_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAssetFromTemplate_Statics::PropPointers) < 2048);
// ********** End Function CreateDataflowCompatibleAssetFromTemplate Property Definitions **********
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAssetFromTemplate_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDataflowAgentToolset, nullptr, "CreateDataflowCompatibleAssetFromTemplate", 	Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAssetFromTemplate_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAssetFromTemplate_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAssetFromTemplate_Statics::DataflowAgentToolset_eventCreateDataflowCompatibleAssetFromTemplate_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAssetFromTemplate_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAssetFromTemplate_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAssetFromTemplate_Statics::DataflowAgentToolset_eventCreateDataflowCompatibleAssetFromTemplate_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAssetFromTemplate()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAssetFromTemplate_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDataflowAgentToolset::execCreateDataflowCompatibleAssetFromTemplate)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ClassName);
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FStrProperty,Z_Param_Path);
	P_GET_PROPERTY(FStrProperty,Z_Param_TemplateId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UDataflowAgentToolset::CreateDataflowCompatibleAssetFromTemplate(Z_Param_ClassName,Z_Param_Name,Z_Param_Path,Z_Param_TemplateId);
	P_NATIVE_END;
}
// ********** End Class UDataflowAgentToolset Function CreateDataflowCompatibleAssetFromTemplate ***

// ********** Begin Class UDataflowAgentToolset Function CreateGraph *******************************
struct Z_Construct_UFunction_UDataflowAgentToolset_CreateGraph_Statics
{
	struct DataflowAgentToolset_eventCreateGraph_Parms
	{
		FString Name;
		FString Path;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "Dataflow|Graph" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Creates a new saved Dataflow graph asset.\n\x09 *\n\x09 * @param Name - Name for the new Dataflow asset (e.g., \"DF_Simulation\")\n\x09 * @param Path - Content folder path where the asset should be created. Defaults to \"/Game/Dataflow\"\n\x09 * @return The full asset path of the created graph, or empty string on failure\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/DataflowAgentToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Creates a new saved Dataflow graph asset.\n\n@param Name - Name for the new Dataflow asset (e.g., \"DF_Simulation\")\n@param Path - Content folder path where the asset should be created. Defaults to \"/Game/Dataflow\"\n@return The full asset path of the created graph, or empty string on failure" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Path_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CreateGraph constinit property declarations ***************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Path;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CreateGraph constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CreateGraph Property Definitions **************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_CreateGraph_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventCreateGraph_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_CreateGraph_Statics::NewProp_Path = { "Path", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventCreateGraph_Parms, Path), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Path_MetaData), NewProp_Path_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_CreateGraph_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventCreateGraph_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataflowAgentToolset_CreateGraph_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_CreateGraph_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_CreateGraph_Statics::NewProp_Path,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_CreateGraph_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_CreateGraph_Statics::PropPointers) < 2048);
// ********** End Function CreateGraph Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataflowAgentToolset_CreateGraph_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDataflowAgentToolset, nullptr, "CreateGraph", 	Z_Construct_UFunction_UDataflowAgentToolset_CreateGraph_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_CreateGraph_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDataflowAgentToolset_CreateGraph_Statics::DataflowAgentToolset_eventCreateGraph_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_CreateGraph_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDataflowAgentToolset_CreateGraph_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDataflowAgentToolset_CreateGraph_Statics::DataflowAgentToolset_eventCreateGraph_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDataflowAgentToolset_CreateGraph()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataflowAgentToolset_CreateGraph_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDataflowAgentToolset::execCreateGraph)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FStrProperty,Z_Param_Path);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UDataflowAgentToolset::CreateGraph(Z_Param_Name,Z_Param_Path);
	P_NATIVE_END;
}
// ********** End Class UDataflowAgentToolset Function CreateGraph *********************************

// ********** Begin Class UDataflowAgentToolset Function DisconnectNodePins ************************
struct Z_Construct_UFunction_UDataflowAgentToolset_DisconnectNodePins_Statics
{
	struct DataflowAgentToolset_eventDisconnectNodePins_Parms
	{
		UDataflowEdNode* FromNode;
		FString FromPin;
		UDataflowEdNode* ToNode;
		FString ToPin;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "Dataflow|Connections" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Removes the connection between two node pins.\n\x09 *\n\x09 * @param FromNode - The source EdNode\n\x09 * @param FromPin  - Name of the output pin on the source node\n\x09 * @param ToNode   - The destination EdNode\n\x09 * @param ToPin    - Name of the input pin on the destination node\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/DataflowAgentToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Removes the connection between two node pins.\n\n@param FromNode - The source EdNode\n@param FromPin  - Name of the output pin on the source node\n@param ToNode   - The destination EdNode\n@param ToPin    - Name of the input pin on the destination node" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FromPin_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ToPin_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function DisconnectNodePins constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FromNode;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FromPin;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ToNode;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ToPin;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DisconnectNodePins constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DisconnectNodePins Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_DisconnectNodePins_Statics::NewProp_FromNode = { "FromNode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventDisconnectNodePins_Parms, FromNode), Z_Construct_UClass_UDataflowEdNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_DisconnectNodePins_Statics::NewProp_FromPin = { "FromPin", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventDisconnectNodePins_Parms, FromPin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FromPin_MetaData), NewProp_FromPin_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_DisconnectNodePins_Statics::NewProp_ToNode = { "ToNode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventDisconnectNodePins_Parms, ToNode), Z_Construct_UClass_UDataflowEdNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_DisconnectNodePins_Statics::NewProp_ToPin = { "ToPin", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventDisconnectNodePins_Parms, ToPin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ToPin_MetaData), NewProp_ToPin_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataflowAgentToolset_DisconnectNodePins_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_DisconnectNodePins_Statics::NewProp_FromNode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_DisconnectNodePins_Statics::NewProp_FromPin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_DisconnectNodePins_Statics::NewProp_ToNode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_DisconnectNodePins_Statics::NewProp_ToPin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_DisconnectNodePins_Statics::PropPointers) < 2048);
// ********** End Function DisconnectNodePins Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataflowAgentToolset_DisconnectNodePins_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDataflowAgentToolset, nullptr, "DisconnectNodePins", 	Z_Construct_UFunction_UDataflowAgentToolset_DisconnectNodePins_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_DisconnectNodePins_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDataflowAgentToolset_DisconnectNodePins_Statics::DataflowAgentToolset_eventDisconnectNodePins_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_DisconnectNodePins_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDataflowAgentToolset_DisconnectNodePins_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDataflowAgentToolset_DisconnectNodePins_Statics::DataflowAgentToolset_eventDisconnectNodePins_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDataflowAgentToolset_DisconnectNodePins()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataflowAgentToolset_DisconnectNodePins_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDataflowAgentToolset::execDisconnectNodePins)
{
	P_GET_OBJECT(UDataflowEdNode,Z_Param_FromNode);
	P_GET_PROPERTY(FStrProperty,Z_Param_FromPin);
	P_GET_OBJECT(UDataflowEdNode,Z_Param_ToNode);
	P_GET_PROPERTY(FStrProperty,Z_Param_ToPin);
	P_FINISH;
	P_NATIVE_BEGIN;
	UDataflowAgentToolset::DisconnectNodePins(Z_Param_FromNode,Z_Param_FromPin,Z_Param_ToNode,Z_Param_ToPin);
	P_NATIVE_END;
}
// ********** End Class UDataflowAgentToolset Function DisconnectNodePins **************************

// ********** Begin Class UDataflowAgentToolset Function GetGraphStructure *************************
struct Z_Construct_UFunction_UDataflowAgentToolset_GetGraphStructure_Statics
{
	struct DataflowAgentToolset_eventGetGraphStructure_Parms
	{
		const UDataflow* Graph;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "Dataflow|Graph" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the complete structure of a Dataflow graph including all nodes and connections.\n\x09 *\n\x09 * @param Graph - The Dataflow asset to inspect\n\x09 * @return JSON string with graph structure (nodes + connections), or error message on failure\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/DataflowAgentToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the complete structure of a Dataflow graph including all nodes and connections.\n\n@param Graph - The Dataflow asset to inspect\n@return JSON string with graph structure (nodes + connections), or error message on failure" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Graph_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetGraphStructure constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Graph;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGraphStructure constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGraphStructure Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_GetGraphStructure_Statics::NewProp_Graph = { "Graph", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventGetGraphStructure_Parms, Graph), Z_Construct_UClass_UDataflow_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Graph_MetaData), NewProp_Graph_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_GetGraphStructure_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventGetGraphStructure_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataflowAgentToolset_GetGraphStructure_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_GetGraphStructure_Statics::NewProp_Graph,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_GetGraphStructure_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_GetGraphStructure_Statics::PropPointers) < 2048);
// ********** End Function GetGraphStructure Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataflowAgentToolset_GetGraphStructure_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDataflowAgentToolset, nullptr, "GetGraphStructure", 	Z_Construct_UFunction_UDataflowAgentToolset_GetGraphStructure_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_GetGraphStructure_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDataflowAgentToolset_GetGraphStructure_Statics::DataflowAgentToolset_eventGetGraphStructure_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_GetGraphStructure_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDataflowAgentToolset_GetGraphStructure_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDataflowAgentToolset_GetGraphStructure_Statics::DataflowAgentToolset_eventGetGraphStructure_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDataflowAgentToolset_GetGraphStructure()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataflowAgentToolset_GetGraphStructure_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDataflowAgentToolset::execGetGraphStructure)
{
	P_GET_OBJECT(UDataflow,Z_Param_Graph);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UDataflowAgentToolset::GetGraphStructure(Z_Param_Graph);
	P_NATIVE_END;
}
// ********** End Class UDataflowAgentToolset Function GetGraphStructure ***************************

// ********** Begin Class UDataflowAgentToolset Function GetNodeInfo *******************************
struct Z_Construct_UFunction_UDataflowAgentToolset_GetNodeInfo_Statics
{
	struct DataflowAgentToolset_eventGetNodeInfo_Parms
	{
		UDataflowEdNode* Node;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "Dataflow|Nodes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns information about a node as a JSON object (name, type, position, pins).\n\x09 *\n\x09 * @param Node - The EdNode to query\n\x09 * @return JSON string with node info, or error message on failure\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/DataflowAgentToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns information about a node as a JSON object (name, type, position, pins).\n\n@param Node - The EdNode to query\n@return JSON string with node info, or error message on failure" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetNodeInfo constinit property declarations ***************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Node;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetNodeInfo constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetNodeInfo Property Definitions **************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_GetNodeInfo_Statics::NewProp_Node = { "Node", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventGetNodeInfo_Parms, Node), Z_Construct_UClass_UDataflowEdNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_GetNodeInfo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventGetNodeInfo_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataflowAgentToolset_GetNodeInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_GetNodeInfo_Statics::NewProp_Node,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_GetNodeInfo_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_GetNodeInfo_Statics::PropPointers) < 2048);
// ********** End Function GetNodeInfo Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataflowAgentToolset_GetNodeInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDataflowAgentToolset, nullptr, "GetNodeInfo", 	Z_Construct_UFunction_UDataflowAgentToolset_GetNodeInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_GetNodeInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDataflowAgentToolset_GetNodeInfo_Statics::DataflowAgentToolset_eventGetNodeInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_GetNodeInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDataflowAgentToolset_GetNodeInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDataflowAgentToolset_GetNodeInfo_Statics::DataflowAgentToolset_eventGetNodeInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDataflowAgentToolset_GetNodeInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataflowAgentToolset_GetNodeInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDataflowAgentToolset::execGetNodeInfo)
{
	P_GET_OBJECT(UDataflowEdNode,Z_Param_Node);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UDataflowAgentToolset::GetNodeInfo(Z_Param_Node);
	P_NATIVE_END;
}
// ********** End Class UDataflowAgentToolset Function GetNodeInfo *********************************

// ********** Begin Class UDataflowAgentToolset Function GetNodeTypeSchema *************************
struct Z_Construct_UFunction_UDataflowAgentToolset_GetNodeTypeSchema_Statics
{
	struct DataflowAgentToolset_eventGetNodeTypeSchema_Parms
	{
		FString TypeName;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "Dataflow|NodeTypes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the schema for a Dataflow node type including its input/output pins\n\x09 * and editable UPROPERTY parameters.\n\x09 *\n\x09 * @param TypeName - The node type name (e.g., \"FAddFloatsDataflowNode\")\n\x09 * @return JSON object with name, category, tooltip, inputPins, outputPins, and properties\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/DataflowAgentToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the schema for a Dataflow node type including its input/output pins\nand editable UPROPERTY parameters.\n\n@param TypeName - The node type name (e.g., \"FAddFloatsDataflowNode\")\n@return JSON object with name, category, tooltip, inputPins, outputPins, and properties" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TypeName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetNodeTypeSchema constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_TypeName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetNodeTypeSchema constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetNodeTypeSchema Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_GetNodeTypeSchema_Statics::NewProp_TypeName = { "TypeName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventGetNodeTypeSchema_Parms, TypeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TypeName_MetaData), NewProp_TypeName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_GetNodeTypeSchema_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventGetNodeTypeSchema_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataflowAgentToolset_GetNodeTypeSchema_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_GetNodeTypeSchema_Statics::NewProp_TypeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_GetNodeTypeSchema_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_GetNodeTypeSchema_Statics::PropPointers) < 2048);
// ********** End Function GetNodeTypeSchema Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataflowAgentToolset_GetNodeTypeSchema_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDataflowAgentToolset, nullptr, "GetNodeTypeSchema", 	Z_Construct_UFunction_UDataflowAgentToolset_GetNodeTypeSchema_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_GetNodeTypeSchema_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDataflowAgentToolset_GetNodeTypeSchema_Statics::DataflowAgentToolset_eventGetNodeTypeSchema_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_GetNodeTypeSchema_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDataflowAgentToolset_GetNodeTypeSchema_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDataflowAgentToolset_GetNodeTypeSchema_Statics::DataflowAgentToolset_eventGetNodeTypeSchema_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDataflowAgentToolset_GetNodeTypeSchema()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataflowAgentToolset_GetNodeTypeSchema_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDataflowAgentToolset::execGetNodeTypeSchema)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_TypeName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UDataflowAgentToolset::GetNodeTypeSchema(Z_Param_TypeName);
	P_NATIVE_END;
}
// ********** End Class UDataflowAgentToolset Function GetNodeTypeSchema ***************************

// ********** Begin Class UDataflowAgentToolset Function ListDataflowCompatibleAssetTypes **********
struct Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowCompatibleAssetTypes_Statics
{
	struct DataflowAgentToolset_eventListDataflowCompatibleAssetTypes_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "Dataflow|Assets" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns a JSON list of every UClass that can host an embedded Dataflow graph\n\x09 * (i.e. implements IDataflowInstanceInterface). Each entry has \"className\",\n\x09 * \"displayName\", and \"modulePath\" fields.\n\x09 *\n\x09 * Use the \"className\" value as input to CreateDataflowCompatibleAsset or\n\x09 * ListDataflowTemplatesForAssetClass.\n\x09 *\n\x09 * @return JSON array of compatible asset type descriptors\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/DataflowAgentToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns a JSON list of every UClass that can host an embedded Dataflow graph\n(i.e. implements IDataflowInstanceInterface). Each entry has \"className\",\n\"displayName\", and \"modulePath\" fields.\n\nUse the \"className\" value as input to CreateDataflowCompatibleAsset or\nListDataflowTemplatesForAssetClass.\n\n@return JSON array of compatible asset type descriptors" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ListDataflowCompatibleAssetTypes constinit property declarations ******
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListDataflowCompatibleAssetTypes constinit property declarations ********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListDataflowCompatibleAssetTypes Property Definitions *****************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowCompatibleAssetTypes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventListDataflowCompatibleAssetTypes_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowCompatibleAssetTypes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowCompatibleAssetTypes_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowCompatibleAssetTypes_Statics::PropPointers) < 2048);
// ********** End Function ListDataflowCompatibleAssetTypes Property Definitions *******************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowCompatibleAssetTypes_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDataflowAgentToolset, nullptr, "ListDataflowCompatibleAssetTypes", 	Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowCompatibleAssetTypes_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowCompatibleAssetTypes_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowCompatibleAssetTypes_Statics::DataflowAgentToolset_eventListDataflowCompatibleAssetTypes_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowCompatibleAssetTypes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowCompatibleAssetTypes_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowCompatibleAssetTypes_Statics::DataflowAgentToolset_eventListDataflowCompatibleAssetTypes_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowCompatibleAssetTypes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowCompatibleAssetTypes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDataflowAgentToolset::execListDataflowCompatibleAssetTypes)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UDataflowAgentToolset::ListDataflowCompatibleAssetTypes();
	P_NATIVE_END;
}
// ********** End Class UDataflowAgentToolset Function ListDataflowCompatibleAssetTypes ************

// ********** Begin Class UDataflowAgentToolset Function ListDataflowTemplatesForAssetClass ********
struct Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowTemplatesForAssetClass_Statics
{
	struct DataflowAgentToolset_eventListDataflowTemplatesForAssetClass_Parms
	{
		FString ClassName;
		bool bIncludeBlank;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "Dataflow|Templates" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns a JSON list of Dataflow templates registered for the given asset class.\n\x09 * Templates registered for parent classes are included (class hierarchy walk).\n\x09 *\n\x09 * @param ClassName     - Asset class name with or without the \"U\"/\"A\" prefix\n\x09 * @param bIncludeBlank - When true, include a \"Blank\" option (empty graph) at the start\n\x09 * @return JSON array of `{ \"templateId\", \"displayName\", \"tooltip\" }` objects.\n\x09 *         \"templateId\" is opaque - pass it back to AssignDataflowTemplate or\n\x09 *         CreateDataflowCompatibleAssetFromTemplate.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/DataflowAgentToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns a JSON list of Dataflow templates registered for the given asset class.\nTemplates registered for parent classes are included (class hierarchy walk).\n\n@param ClassName     - Asset class name with or without the \"U\"/\"A\" prefix\n@param bIncludeBlank - When true, include a \"Blank\" option (empty graph) at the start\n@return JSON array of `{ \"templateId\", \"displayName\", \"tooltip\" }` objects.\n        \"templateId\" is opaque - pass it back to AssignDataflowTemplate or\n        CreateDataflowCompatibleAssetFromTemplate." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClassName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIncludeBlank_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ListDataflowTemplatesForAssetClass constinit property declarations ****
	static const UECodeGen_Private::FStrPropertyParams NewProp_ClassName;
	static void NewProp_bIncludeBlank_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIncludeBlank;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListDataflowTemplatesForAssetClass constinit property declarations ******
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListDataflowTemplatesForAssetClass Property Definitions ***************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowTemplatesForAssetClass_Statics::NewProp_ClassName = { "ClassName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventListDataflowTemplatesForAssetClass_Parms, ClassName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClassName_MetaData), NewProp_ClassName_MetaData) };
void Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowTemplatesForAssetClass_Statics::NewProp_bIncludeBlank_SetBit(void* Obj)
{
	((DataflowAgentToolset_eventListDataflowTemplatesForAssetClass_Parms*)Obj)->bIncludeBlank = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowTemplatesForAssetClass_Statics::NewProp_bIncludeBlank = { "bIncludeBlank", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DataflowAgentToolset_eventListDataflowTemplatesForAssetClass_Parms), &Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowTemplatesForAssetClass_Statics::NewProp_bIncludeBlank_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIncludeBlank_MetaData), NewProp_bIncludeBlank_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowTemplatesForAssetClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventListDataflowTemplatesForAssetClass_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowTemplatesForAssetClass_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowTemplatesForAssetClass_Statics::NewProp_ClassName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowTemplatesForAssetClass_Statics::NewProp_bIncludeBlank,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowTemplatesForAssetClass_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowTemplatesForAssetClass_Statics::PropPointers) < 2048);
// ********** End Function ListDataflowTemplatesForAssetClass Property Definitions *****************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowTemplatesForAssetClass_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDataflowAgentToolset, nullptr, "ListDataflowTemplatesForAssetClass", 	Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowTemplatesForAssetClass_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowTemplatesForAssetClass_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowTemplatesForAssetClass_Statics::DataflowAgentToolset_eventListDataflowTemplatesForAssetClass_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowTemplatesForAssetClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowTemplatesForAssetClass_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowTemplatesForAssetClass_Statics::DataflowAgentToolset_eventListDataflowTemplatesForAssetClass_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowTemplatesForAssetClass()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowTemplatesForAssetClass_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDataflowAgentToolset::execListDataflowTemplatesForAssetClass)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ClassName);
	P_GET_UBOOL(Z_Param_bIncludeBlank);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UDataflowAgentToolset::ListDataflowTemplatesForAssetClass(Z_Param_ClassName,Z_Param_bIncludeBlank);
	P_NATIVE_END;
}
// ********** End Class UDataflowAgentToolset Function ListDataflowTemplatesForAssetClass **********

// ********** Begin Class UDataflowAgentToolset Function ListNodeTypes *****************************
struct Z_Construct_UFunction_UDataflowAgentToolset_ListNodeTypes_Statics
{
	struct DataflowAgentToolset_eventListNodeTypes_Parms
	{
		bool bCommonOnly;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "Dataflow|NodeTypes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns a JSON list of all registered Dataflow node types.\n\x09 *\n\x09 * @param bCommonOnly - When true, only return non-deprecated non-experimental nodes. Default is true.\n\x09 * @return JSON array of node type names\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/DataflowAgentToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns a JSON list of all registered Dataflow node types.\n\n@param bCommonOnly - When true, only return non-deprecated non-experimental nodes. Default is true.\n@return JSON array of node type names" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCommonOnly_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ListNodeTypes constinit property declarations *************************
	static void NewProp_bCommonOnly_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCommonOnly;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListNodeTypes constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListNodeTypes Property Definitions ************************************
void Z_Construct_UFunction_UDataflowAgentToolset_ListNodeTypes_Statics::NewProp_bCommonOnly_SetBit(void* Obj)
{
	((DataflowAgentToolset_eventListNodeTypes_Parms*)Obj)->bCommonOnly = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_ListNodeTypes_Statics::NewProp_bCommonOnly = { "bCommonOnly", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DataflowAgentToolset_eventListNodeTypes_Parms), &Z_Construct_UFunction_UDataflowAgentToolset_ListNodeTypes_Statics::NewProp_bCommonOnly_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCommonOnly_MetaData), NewProp_bCommonOnly_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_ListNodeTypes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventListNodeTypes_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataflowAgentToolset_ListNodeTypes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_ListNodeTypes_Statics::NewProp_bCommonOnly,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_ListNodeTypes_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_ListNodeTypes_Statics::PropPointers) < 2048);
// ********** End Function ListNodeTypes Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataflowAgentToolset_ListNodeTypes_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDataflowAgentToolset, nullptr, "ListNodeTypes", 	Z_Construct_UFunction_UDataflowAgentToolset_ListNodeTypes_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_ListNodeTypes_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDataflowAgentToolset_ListNodeTypes_Statics::DataflowAgentToolset_eventListNodeTypes_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_ListNodeTypes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDataflowAgentToolset_ListNodeTypes_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDataflowAgentToolset_ListNodeTypes_Statics::DataflowAgentToolset_eventListNodeTypes_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDataflowAgentToolset_ListNodeTypes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataflowAgentToolset_ListNodeTypes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDataflowAgentToolset::execListNodeTypes)
{
	P_GET_UBOOL(Z_Param_bCommonOnly);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UDataflowAgentToolset::ListNodeTypes(Z_Param_bCommonOnly);
	P_NATIVE_END;
}
// ********** End Class UDataflowAgentToolset Function ListNodeTypes *******************************

// ********** Begin Class UDataflowAgentToolset Function ListVariables *****************************
struct Z_Construct_UFunction_UDataflowAgentToolset_ListVariables_Statics
{
	struct DataflowAgentToolset_eventListVariables_Parms
	{
		const UDataflow* Graph;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "Dataflow|Variables" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns all variables defined on the Dataflow graph as a JSON array.\n\x09 * Each entry contains \"name\", \"type\", and \"value\" fields.\n\x09 *\n\x09 * @param Graph - The Dataflow asset to inspect\n\x09 * @return JSON array of variable descriptors, or empty string on failure\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/DataflowAgentToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns all variables defined on the Dataflow graph as a JSON array.\nEach entry contains \"name\", \"type\", and \"value\" fields.\n\n@param Graph - The Dataflow asset to inspect\n@return JSON array of variable descriptors, or empty string on failure" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Graph_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ListVariables constinit property declarations *************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Graph;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListVariables constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListVariables Property Definitions ************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_ListVariables_Statics::NewProp_Graph = { "Graph", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventListVariables_Parms, Graph), Z_Construct_UClass_UDataflow_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Graph_MetaData), NewProp_Graph_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_ListVariables_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventListVariables_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataflowAgentToolset_ListVariables_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_ListVariables_Statics::NewProp_Graph,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_ListVariables_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_ListVariables_Statics::PropPointers) < 2048);
// ********** End Function ListVariables Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataflowAgentToolset_ListVariables_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDataflowAgentToolset, nullptr, "ListVariables", 	Z_Construct_UFunction_UDataflowAgentToolset_ListVariables_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_ListVariables_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDataflowAgentToolset_ListVariables_Statics::DataflowAgentToolset_eventListVariables_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_ListVariables_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDataflowAgentToolset_ListVariables_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDataflowAgentToolset_ListVariables_Statics::DataflowAgentToolset_eventListVariables_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDataflowAgentToolset_ListVariables()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataflowAgentToolset_ListVariables_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDataflowAgentToolset::execListVariables)
{
	P_GET_OBJECT(UDataflow,Z_Param_Graph);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UDataflowAgentToolset::ListVariables(Z_Param_Graph);
	P_NATIVE_END;
}
// ********** End Class UDataflowAgentToolset Function ListVariables *******************************

// ********** Begin Class UDataflowAgentToolset Function RemoveCommentBox **************************
struct Z_Construct_UFunction_UDataflowAgentToolset_RemoveCommentBox_Statics
{
	struct DataflowAgentToolset_eventRemoveCommentBox_Parms
	{
		UDataflow* Graph;
		FString CommentId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "Dataflow|Comments" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Removes a comment box node from the graph.\n\x09 *\n\x09 * @param Graph     - The Dataflow asset containing the comment\n\x09 * @param CommentId - The node GUID string returned by AddCommentBox\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/DataflowAgentToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Removes a comment box node from the graph.\n\n@param Graph     - The Dataflow asset containing the comment\n@param CommentId - The node GUID string returned by AddCommentBox" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CommentId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RemoveCommentBox constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Graph;
	static const UECodeGen_Private::FStrPropertyParams NewProp_CommentId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RemoveCommentBox constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RemoveCommentBox Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_RemoveCommentBox_Statics::NewProp_Graph = { "Graph", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventRemoveCommentBox_Parms, Graph), Z_Construct_UClass_UDataflow_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_RemoveCommentBox_Statics::NewProp_CommentId = { "CommentId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventRemoveCommentBox_Parms, CommentId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CommentId_MetaData), NewProp_CommentId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataflowAgentToolset_RemoveCommentBox_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_RemoveCommentBox_Statics::NewProp_Graph,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_RemoveCommentBox_Statics::NewProp_CommentId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_RemoveCommentBox_Statics::PropPointers) < 2048);
// ********** End Function RemoveCommentBox Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataflowAgentToolset_RemoveCommentBox_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDataflowAgentToolset, nullptr, "RemoveCommentBox", 	Z_Construct_UFunction_UDataflowAgentToolset_RemoveCommentBox_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_RemoveCommentBox_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDataflowAgentToolset_RemoveCommentBox_Statics::DataflowAgentToolset_eventRemoveCommentBox_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_RemoveCommentBox_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDataflowAgentToolset_RemoveCommentBox_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDataflowAgentToolset_RemoveCommentBox_Statics::DataflowAgentToolset_eventRemoveCommentBox_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDataflowAgentToolset_RemoveCommentBox()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataflowAgentToolset_RemoveCommentBox_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDataflowAgentToolset::execRemoveCommentBox)
{
	P_GET_OBJECT(UDataflow,Z_Param_Graph);
	P_GET_PROPERTY(FStrProperty,Z_Param_CommentId);
	P_FINISH;
	P_NATIVE_BEGIN;
	UDataflowAgentToolset::RemoveCommentBox(Z_Param_Graph,Z_Param_CommentId);
	P_NATIVE_END;
}
// ********** End Class UDataflowAgentToolset Function RemoveCommentBox ****************************

// ********** Begin Class UDataflowAgentToolset Function RemoveNode ********************************
struct Z_Construct_UFunction_UDataflowAgentToolset_RemoveNode_Statics
{
	struct DataflowAgentToolset_eventRemoveNode_Parms
	{
		UDataflow* Graph;
		UDataflowEdNode* Node;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "Dataflow|Nodes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Removes a node and all its connections from the Dataflow graph.\n\x09 *\n\x09 * @param Graph - The Dataflow asset containing the node\n\x09 * @param Node  - The EdNode to remove\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/DataflowAgentToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Removes a node and all its connections from the Dataflow graph.\n\n@param Graph - The Dataflow asset containing the node\n@param Node  - The EdNode to remove" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RemoveNode constinit property declarations ****************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Graph;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Node;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RemoveNode constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RemoveNode Property Definitions ***************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_RemoveNode_Statics::NewProp_Graph = { "Graph", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventRemoveNode_Parms, Graph), Z_Construct_UClass_UDataflow_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_RemoveNode_Statics::NewProp_Node = { "Node", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventRemoveNode_Parms, Node), Z_Construct_UClass_UDataflowEdNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataflowAgentToolset_RemoveNode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_RemoveNode_Statics::NewProp_Graph,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_RemoveNode_Statics::NewProp_Node,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_RemoveNode_Statics::PropPointers) < 2048);
// ********** End Function RemoveNode Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataflowAgentToolset_RemoveNode_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDataflowAgentToolset, nullptr, "RemoveNode", 	Z_Construct_UFunction_UDataflowAgentToolset_RemoveNode_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_RemoveNode_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDataflowAgentToolset_RemoveNode_Statics::DataflowAgentToolset_eventRemoveNode_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_RemoveNode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDataflowAgentToolset_RemoveNode_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDataflowAgentToolset_RemoveNode_Statics::DataflowAgentToolset_eventRemoveNode_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDataflowAgentToolset_RemoveNode()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataflowAgentToolset_RemoveNode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDataflowAgentToolset::execRemoveNode)
{
	P_GET_OBJECT(UDataflow,Z_Param_Graph);
	P_GET_OBJECT(UDataflowEdNode,Z_Param_Node);
	P_FINISH;
	P_NATIVE_BEGIN;
	UDataflowAgentToolset::RemoveNode(Z_Param_Graph,Z_Param_Node);
	P_NATIVE_END;
}
// ********** End Class UDataflowAgentToolset Function RemoveNode **********************************

// ********** Begin Class UDataflowAgentToolset Function RemoveVariable ****************************
struct Z_Construct_UFunction_UDataflowAgentToolset_RemoveVariable_Statics
{
	struct DataflowAgentToolset_eventRemoveVariable_Parms
	{
		UDataflow* Graph;
		FString Name;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "Dataflow|Variables" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Removes a variable from the Dataflow graph.\n\x09 *\n\x09 * @param Graph - The Dataflow asset to modify\n\x09 * @param Name  - Name of the variable to remove\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/DataflowAgentToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Removes a variable from the Dataflow graph.\n\n@param Graph - The Dataflow asset to modify\n@param Name  - Name of the variable to remove" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RemoveVariable constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Graph;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RemoveVariable constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RemoveVariable Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_RemoveVariable_Statics::NewProp_Graph = { "Graph", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventRemoveVariable_Parms, Graph), Z_Construct_UClass_UDataflow_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_RemoveVariable_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventRemoveVariable_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataflowAgentToolset_RemoveVariable_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_RemoveVariable_Statics::NewProp_Graph,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_RemoveVariable_Statics::NewProp_Name,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_RemoveVariable_Statics::PropPointers) < 2048);
// ********** End Function RemoveVariable Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataflowAgentToolset_RemoveVariable_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDataflowAgentToolset, nullptr, "RemoveVariable", 	Z_Construct_UFunction_UDataflowAgentToolset_RemoveVariable_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_RemoveVariable_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDataflowAgentToolset_RemoveVariable_Statics::DataflowAgentToolset_eventRemoveVariable_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_RemoveVariable_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDataflowAgentToolset_RemoveVariable_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDataflowAgentToolset_RemoveVariable_Statics::DataflowAgentToolset_eventRemoveVariable_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDataflowAgentToolset_RemoveVariable()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataflowAgentToolset_RemoveVariable_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDataflowAgentToolset::execRemoveVariable)
{
	P_GET_OBJECT(UDataflow,Z_Param_Graph);
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_FINISH;
	P_NATIVE_BEGIN;
	UDataflowAgentToolset::RemoveVariable(Z_Param_Graph,Z_Param_Name);
	P_NATIVE_END;
}
// ********** End Class UDataflowAgentToolset Function RemoveVariable ******************************

// ********** Begin Class UDataflowAgentToolset Function RepositionNode ****************************
struct Z_Construct_UFunction_UDataflowAgentToolset_RepositionNode_Statics
{
	struct DataflowAgentToolset_eventRepositionNode_Parms
	{
		UDataflowEdNode* Node;
		int32 X;
		int32 Y;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "Dataflow|Nodes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Moves a node to a new position in the graph editor.\n\x09 *\n\x09 * @param Node - The EdNode to reposition\n\x09 * @param X    - New X position\n\x09 * @param Y    - New Y position\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/DataflowAgentToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Moves a node to a new position in the graph editor.\n\n@param Node - The EdNode to reposition\n@param X    - New X position\n@param Y    - New Y position" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_X_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Y_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RepositionNode constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Node;
	static const UECodeGen_Private::FIntPropertyParams NewProp_X;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Y;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RepositionNode constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RepositionNode Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_RepositionNode_Statics::NewProp_Node = { "Node", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventRepositionNode_Parms, Node), Z_Construct_UClass_UDataflowEdNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_RepositionNode_Statics::NewProp_X = { "X", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventRepositionNode_Parms, X), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_X_MetaData), NewProp_X_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_RepositionNode_Statics::NewProp_Y = { "Y", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventRepositionNode_Parms, Y), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Y_MetaData), NewProp_Y_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataflowAgentToolset_RepositionNode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_RepositionNode_Statics::NewProp_Node,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_RepositionNode_Statics::NewProp_X,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_RepositionNode_Statics::NewProp_Y,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_RepositionNode_Statics::PropPointers) < 2048);
// ********** End Function RepositionNode Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataflowAgentToolset_RepositionNode_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDataflowAgentToolset, nullptr, "RepositionNode", 	Z_Construct_UFunction_UDataflowAgentToolset_RepositionNode_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_RepositionNode_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDataflowAgentToolset_RepositionNode_Statics::DataflowAgentToolset_eventRepositionNode_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_RepositionNode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDataflowAgentToolset_RepositionNode_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDataflowAgentToolset_RepositionNode_Statics::DataflowAgentToolset_eventRepositionNode_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDataflowAgentToolset_RepositionNode()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataflowAgentToolset_RepositionNode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDataflowAgentToolset::execRepositionNode)
{
	P_GET_OBJECT(UDataflowEdNode,Z_Param_Node);
	P_GET_PROPERTY(FIntProperty,Z_Param_X);
	P_GET_PROPERTY(FIntProperty,Z_Param_Y);
	P_FINISH;
	P_NATIVE_BEGIN;
	UDataflowAgentToolset::RepositionNode(Z_Param_Node,Z_Param_X,Z_Param_Y);
	P_NATIVE_END;
}
// ********** End Class UDataflowAgentToolset Function RepositionNode ******************************

// ********** Begin Class UDataflowAgentToolset Function SetVariable *******************************
struct Z_Construct_UFunction_UDataflowAgentToolset_SetVariable_Statics
{
	struct DataflowAgentToolset_eventSetVariable_Parms
	{
		UDataflow* Graph;
		FString Name;
		FString Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "Dataflow|Variables" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Sets the value of an existing variable using its serialized string representation.\n\x09 * The format depends on the variable's type (e.g., \"3.14\" for float, \"true\" for bool,\n\x09 * \"42\" for int, \"MyName\" for FName).\n\x09 *\n\x09 * @param Graph - The Dataflow asset to modify\n\x09 * @param Name  - Name of the variable to set\n\x09 * @param Value - Serialized string value to assign\n\x09 * @return true on success, false if the variable is not found or the value cannot be parsed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/DataflowAgentToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the value of an existing variable using its serialized string representation.\nThe format depends on the variable's type (e.g., \"3.14\" for float, \"true\" for bool,\n\"42\" for int, \"MyName\" for FName).\n\n@param Graph - The Dataflow asset to modify\n@param Name  - Name of the variable to set\n@param Value - Serialized string value to assign\n@return true on success, false if the variable is not found or the value cannot be parsed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetVariable constinit property declarations ***************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Graph;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetVariable constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetVariable Property Definitions **************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_SetVariable_Statics::NewProp_Graph = { "Graph", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventSetVariable_Parms, Graph), Z_Construct_UClass_UDataflow_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_SetVariable_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventSetVariable_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_SetVariable_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventSetVariable_Parms, Value), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
void Z_Construct_UFunction_UDataflowAgentToolset_SetVariable_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((DataflowAgentToolset_eventSetVariable_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_SetVariable_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DataflowAgentToolset_eventSetVariable_Parms), &Z_Construct_UFunction_UDataflowAgentToolset_SetVariable_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataflowAgentToolset_SetVariable_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_SetVariable_Statics::NewProp_Graph,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_SetVariable_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_SetVariable_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_SetVariable_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_SetVariable_Statics::PropPointers) < 2048);
// ********** End Function SetVariable Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataflowAgentToolset_SetVariable_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDataflowAgentToolset, nullptr, "SetVariable", 	Z_Construct_UFunction_UDataflowAgentToolset_SetVariable_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_SetVariable_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDataflowAgentToolset_SetVariable_Statics::DataflowAgentToolset_eventSetVariable_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_SetVariable_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDataflowAgentToolset_SetVariable_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDataflowAgentToolset_SetVariable_Statics::DataflowAgentToolset_eventSetVariable_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDataflowAgentToolset_SetVariable()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataflowAgentToolset_SetVariable_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDataflowAgentToolset::execSetVariable)
{
	P_GET_OBJECT(UDataflow,Z_Param_Graph);
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FStrProperty,Z_Param_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UDataflowAgentToolset::SetVariable(Z_Param_Graph,Z_Param_Name,Z_Param_Value);
	P_NATIVE_END;
}
// ********** End Class UDataflowAgentToolset Function SetVariable *********************************

// ********** Begin Class UDataflowAgentToolset Function UpdateNode ********************************
struct Z_Construct_UFunction_UDataflowAgentToolset_UpdateNode_Statics
{
	struct DataflowAgentToolset_eventUpdateNode_Parms
	{
		UDataflowEdNode* Node;
		FString JsonParams;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "Dataflow|Nodes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Updates an existing node's editable properties via JSON.\n\x09 *\n\x09 * @param Node       - The EdNode to modify\n\x09 * @param JsonParams - JSON object of property overrides (e.g., {\"Value\": 3.14})\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/DataflowAgentToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Updates an existing node's editable properties via JSON.\n\n@param Node       - The EdNode to modify\n@param JsonParams - JSON object of property overrides (e.g., {\"Value\": 3.14})" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonParams_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function UpdateNode constinit property declarations ****************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Node;
	static const UECodeGen_Private::FStrPropertyParams NewProp_JsonParams;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UpdateNode constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UpdateNode Property Definitions ***************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_UpdateNode_Statics::NewProp_Node = { "Node", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventUpdateNode_Parms, Node), Z_Construct_UClass_UDataflowEdNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataflowAgentToolset_UpdateNode_Statics::NewProp_JsonParams = { "JsonParams", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DataflowAgentToolset_eventUpdateNode_Parms, JsonParams), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonParams_MetaData), NewProp_JsonParams_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataflowAgentToolset_UpdateNode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_UpdateNode_Statics::NewProp_Node,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataflowAgentToolset_UpdateNode_Statics::NewProp_JsonParams,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_UpdateNode_Statics::PropPointers) < 2048);
// ********** End Function UpdateNode Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataflowAgentToolset_UpdateNode_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDataflowAgentToolset, nullptr, "UpdateNode", 	Z_Construct_UFunction_UDataflowAgentToolset_UpdateNode_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_UpdateNode_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDataflowAgentToolset_UpdateNode_Statics::DataflowAgentToolset_eventUpdateNode_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDataflowAgentToolset_UpdateNode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDataflowAgentToolset_UpdateNode_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDataflowAgentToolset_UpdateNode_Statics::DataflowAgentToolset_eventUpdateNode_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDataflowAgentToolset_UpdateNode()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataflowAgentToolset_UpdateNode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDataflowAgentToolset::execUpdateNode)
{
	P_GET_OBJECT(UDataflowEdNode,Z_Param_Node);
	P_GET_PROPERTY(FStrProperty,Z_Param_JsonParams);
	P_FINISH;
	P_NATIVE_BEGIN;
	UDataflowAgentToolset::UpdateNode(Z_Param_Node,Z_Param_JsonParams);
	P_NATIVE_END;
}
// ********** End Class UDataflowAgentToolset Function UpdateNode **********************************

// ********** Begin Class UDataflowAgentToolset ****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UDataflowAgentToolset;
UClass* UDataflowAgentToolset::GetPrivateStaticClass()
{
	using TClass = UDataflowAgentToolset;
	if (!Z_Registration_Info_UClass_UDataflowAgentToolset.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("DataflowAgentToolset"),
			Z_Registration_Info_UClass_UDataflowAgentToolset.InnerSingleton,
			StaticRegisterNativesUDataflowAgentToolset,
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
	return Z_Registration_Info_UClass_UDataflowAgentToolset.InnerSingleton;
}
UClass* Z_Construct_UClass_UDataflowAgentToolset_NoRegister()
{
	return UDataflowAgentToolset::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDataflowAgentToolset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Dataflow Agent Toolset - exposes Dataflow graph editing operations as AI agent tools.\n */" },
#endif
		{ "IncludePath", "DataflowAgentToolset.h" },
		{ "ModuleRelativePath", "Private/DataflowAgentToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Dataflow Agent Toolset - exposes Dataflow graph editing operations as AI agent tools." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UDataflowAgentToolset constinit property declarations ********************
// ********** End Class UDataflowAgentToolset constinit property declarations **********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AddCommentBox"), .Pointer = &UDataflowAgentToolset::execAddCommentBox },
		{ .NameUTF8 = UTF8TEXT("AddNode"), .Pointer = &UDataflowAgentToolset::execAddNode },
		{ .NameUTF8 = UTF8TEXT("AddVariable"), .Pointer = &UDataflowAgentToolset::execAddVariable },
		{ .NameUTF8 = UTF8TEXT("AssignDataflowTemplate"), .Pointer = &UDataflowAgentToolset::execAssignDataflowTemplate },
		{ .NameUTF8 = UTF8TEXT("ConnectNodePins"), .Pointer = &UDataflowAgentToolset::execConnectNodePins },
		{ .NameUTF8 = UTF8TEXT("CreateDataflowCompatibleAsset"), .Pointer = &UDataflowAgentToolset::execCreateDataflowCompatibleAsset },
		{ .NameUTF8 = UTF8TEXT("CreateDataflowCompatibleAssetFromTemplate"), .Pointer = &UDataflowAgentToolset::execCreateDataflowCompatibleAssetFromTemplate },
		{ .NameUTF8 = UTF8TEXT("CreateGraph"), .Pointer = &UDataflowAgentToolset::execCreateGraph },
		{ .NameUTF8 = UTF8TEXT("DisconnectNodePins"), .Pointer = &UDataflowAgentToolset::execDisconnectNodePins },
		{ .NameUTF8 = UTF8TEXT("GetGraphStructure"), .Pointer = &UDataflowAgentToolset::execGetGraphStructure },
		{ .NameUTF8 = UTF8TEXT("GetNodeInfo"), .Pointer = &UDataflowAgentToolset::execGetNodeInfo },
		{ .NameUTF8 = UTF8TEXT("GetNodeTypeSchema"), .Pointer = &UDataflowAgentToolset::execGetNodeTypeSchema },
		{ .NameUTF8 = UTF8TEXT("ListDataflowCompatibleAssetTypes"), .Pointer = &UDataflowAgentToolset::execListDataflowCompatibleAssetTypes },
		{ .NameUTF8 = UTF8TEXT("ListDataflowTemplatesForAssetClass"), .Pointer = &UDataflowAgentToolset::execListDataflowTemplatesForAssetClass },
		{ .NameUTF8 = UTF8TEXT("ListNodeTypes"), .Pointer = &UDataflowAgentToolset::execListNodeTypes },
		{ .NameUTF8 = UTF8TEXT("ListVariables"), .Pointer = &UDataflowAgentToolset::execListVariables },
		{ .NameUTF8 = UTF8TEXT("RemoveCommentBox"), .Pointer = &UDataflowAgentToolset::execRemoveCommentBox },
		{ .NameUTF8 = UTF8TEXT("RemoveNode"), .Pointer = &UDataflowAgentToolset::execRemoveNode },
		{ .NameUTF8 = UTF8TEXT("RemoveVariable"), .Pointer = &UDataflowAgentToolset::execRemoveVariable },
		{ .NameUTF8 = UTF8TEXT("RepositionNode"), .Pointer = &UDataflowAgentToolset::execRepositionNode },
		{ .NameUTF8 = UTF8TEXT("SetVariable"), .Pointer = &UDataflowAgentToolset::execSetVariable },
		{ .NameUTF8 = UTF8TEXT("UpdateNode"), .Pointer = &UDataflowAgentToolset::execUpdateNode },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDataflowAgentToolset_AddCommentBox, "AddCommentBox" }, // 2858288201
		{ &Z_Construct_UFunction_UDataflowAgentToolset_AddNode, "AddNode" }, // 104845293
		{ &Z_Construct_UFunction_UDataflowAgentToolset_AddVariable, "AddVariable" }, // 1404448619
		{ &Z_Construct_UFunction_UDataflowAgentToolset_AssignDataflowTemplate, "AssignDataflowTemplate" }, // 3176987448
		{ &Z_Construct_UFunction_UDataflowAgentToolset_ConnectNodePins, "ConnectNodePins" }, // 2345044597
		{ &Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAsset, "CreateDataflowCompatibleAsset" }, // 3213229561
		{ &Z_Construct_UFunction_UDataflowAgentToolset_CreateDataflowCompatibleAssetFromTemplate, "CreateDataflowCompatibleAssetFromTemplate" }, // 1310510038
		{ &Z_Construct_UFunction_UDataflowAgentToolset_CreateGraph, "CreateGraph" }, // 3681672373
		{ &Z_Construct_UFunction_UDataflowAgentToolset_DisconnectNodePins, "DisconnectNodePins" }, // 3021253264
		{ &Z_Construct_UFunction_UDataflowAgentToolset_GetGraphStructure, "GetGraphStructure" }, // 3709077585
		{ &Z_Construct_UFunction_UDataflowAgentToolset_GetNodeInfo, "GetNodeInfo" }, // 2773808358
		{ &Z_Construct_UFunction_UDataflowAgentToolset_GetNodeTypeSchema, "GetNodeTypeSchema" }, // 718026990
		{ &Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowCompatibleAssetTypes, "ListDataflowCompatibleAssetTypes" }, // 858400547
		{ &Z_Construct_UFunction_UDataflowAgentToolset_ListDataflowTemplatesForAssetClass, "ListDataflowTemplatesForAssetClass" }, // 3850261108
		{ &Z_Construct_UFunction_UDataflowAgentToolset_ListNodeTypes, "ListNodeTypes" }, // 1983049480
		{ &Z_Construct_UFunction_UDataflowAgentToolset_ListVariables, "ListVariables" }, // 2594536419
		{ &Z_Construct_UFunction_UDataflowAgentToolset_RemoveCommentBox, "RemoveCommentBox" }, // 685961031
		{ &Z_Construct_UFunction_UDataflowAgentToolset_RemoveNode, "RemoveNode" }, // 2292538309
		{ &Z_Construct_UFunction_UDataflowAgentToolset_RemoveVariable, "RemoveVariable" }, // 3472873257
		{ &Z_Construct_UFunction_UDataflowAgentToolset_RepositionNode, "RepositionNode" }, // 2475155455
		{ &Z_Construct_UFunction_UDataflowAgentToolset_SetVariable, "SetVariable" }, // 322139479
		{ &Z_Construct_UFunction_UDataflowAgentToolset_UpdateNode, "UpdateNode" }, // 363339937
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDataflowAgentToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UDataflowAgentToolset_Statics
UObject* (*const Z_Construct_UClass_UDataflowAgentToolset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UToolsetDefinition,
	(UObject* (*)())Z_Construct_UPackage__Script_DataflowAgent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDataflowAgentToolset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDataflowAgentToolset_Statics::ClassParams = {
	&UDataflowAgentToolset::StaticClass,
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
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDataflowAgentToolset_Statics::Class_MetaDataParams), Z_Construct_UClass_UDataflowAgentToolset_Statics::Class_MetaDataParams)
};
void UDataflowAgentToolset::StaticRegisterNativesUDataflowAgentToolset()
{
	UClass* Class = UDataflowAgentToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UDataflowAgentToolset_Statics::Funcs));
}
UClass* Z_Construct_UClass_UDataflowAgentToolset()
{
	if (!Z_Registration_Info_UClass_UDataflowAgentToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDataflowAgentToolset.OuterSingleton, Z_Construct_UClass_UDataflowAgentToolset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDataflowAgentToolset.OuterSingleton;
}
UDataflowAgentToolset::UDataflowAgentToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDataflowAgentToolset);
UDataflowAgentToolset::~UDataflowAgentToolset() {}
// ********** End Class UDataflowAgentToolset ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_DataflowAgent_Source_DataflowAgent_Private_DataflowAgentToolset_h__Script_DataflowAgent_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDataflowAgentToolset, UDataflowAgentToolset::StaticClass, TEXT("UDataflowAgentToolset"), &Z_Registration_Info_UClass_UDataflowAgentToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDataflowAgentToolset), 2592648683U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_DataflowAgent_Source_DataflowAgent_Private_DataflowAgentToolset_h__Script_DataflowAgent_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_DataflowAgent_Source_DataflowAgent_Private_DataflowAgentToolset_h__Script_DataflowAgent_1300617071{
	TEXT("/Script/DataflowAgent"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_DataflowAgent_Source_DataflowAgent_Private_DataflowAgentToolset_h__Script_DataflowAgent_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_DataflowAgent_Source_DataflowAgent_Private_DataflowAgentToolset_h__Script_DataflowAgent_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
