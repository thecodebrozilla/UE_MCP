// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PCGToolset.h"
#include "PCGToolsetCustomTypes.h"
#include "StructUtils/PropertyBag.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodePCGToolset() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FInstancedPropertyBag();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
PCG_API UClass* Z_Construct_UClass_APCGVolume_NoRegister();
PCG_API UClass* Z_Construct_UClass_UPCGGraph_NoRegister();
PCG_API UClass* Z_Construct_UClass_UPCGNode_NoRegister();
PCGTOOLSET_API UClass* Z_Construct_UClass_UPCGExecuteGraphInstanceAsyncResult_NoRegister();
PCGTOOLSET_API UClass* Z_Construct_UClass_UPCGToolset();
PCGTOOLSET_API UClass* Z_Construct_UClass_UPCGToolset_NoRegister();
PCGTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FPCGGraphInstanceInfo();
PCGTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FPCGGraphSchema();
PCGTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FPCGGraphStructure();
PCGTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FPCGNativeNodeSchema();
PCGTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FPCGNodeInfo();
PCGTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FPCGParamDefinition();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolCallAsyncResultVoid_NoRegister();
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition();
UPackage* Z_Construct_UPackage__Script_PCGToolset();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UPCGToolset Function AddCommentBox ***************************************
struct Z_Construct_UFunction_UPCGToolset_AddCommentBox_Statics
{
	struct PCGToolset_eventAddCommentBox_Parms
	{
		UPCGGraph* Graph;
		TArray<UPCGNode*> Nodes;
		FString Comment;
		FLinearColor Color;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PCG|CommentBox" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Adds a comment box around the given nodes. \n\x09 *  Note: If the bounding box of the nodes include other nodes, they will be included in the comment.\n\x09 *\n\x09 * @param Graph - Graph to add comment to.\n\x09 * @param Nodes - The list of nodes to include in the comment box.\n\x09 * @param Comment - The comment to put on the comment box.\n\x09 * @param Color - The color of the comment box. Defaults to White\n\x09 * @return The unique id of the comment node. (Can be used to edit/remove the comment)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/PCGToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds a comment box around the given nodes.\n Note: If the bounding box of the nodes include other nodes, they will be included in the comment.\n\n@param Graph - Graph to add comment to.\n@param Nodes - The list of nodes to include in the comment box.\n@param Comment - The comment to put on the comment box.\n@param Color - The color of the comment box. Defaults to White\n@return The unique id of the comment node. (Can be used to edit/remove the comment)" },
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
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_AddCommentBox_Statics::NewProp_Graph = { "Graph", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventAddCommentBox_Parms, Graph), Z_Construct_UClass_UPCGGraph_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_AddCommentBox_Statics::NewProp_Nodes_Inner = { "Nodes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UPCGNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPCGToolset_AddCommentBox_Statics::NewProp_Nodes = { "Nodes", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventAddCommentBox_Parms, Nodes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Nodes_MetaData), NewProp_Nodes_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_AddCommentBox_Statics::NewProp_Comment = { "Comment", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventAddCommentBox_Parms, Comment), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Comment_MetaData), NewProp_Comment_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPCGToolset_AddCommentBox_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventAddCommentBox_Parms, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_AddCommentBox_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventAddCommentBox_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPCGToolset_AddCommentBox_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_AddCommentBox_Statics::NewProp_Graph,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_AddCommentBox_Statics::NewProp_Nodes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_AddCommentBox_Statics::NewProp_Nodes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_AddCommentBox_Statics::NewProp_Comment,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_AddCommentBox_Statics::NewProp_Color,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_AddCommentBox_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_AddCommentBox_Statics::PropPointers) < 2048);
// ********** End Function AddCommentBox Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPCGToolset_AddCommentBox_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPCGToolset, nullptr, "AddCommentBox", 	Z_Construct_UFunction_UPCGToolset_AddCommentBox_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_AddCommentBox_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPCGToolset_AddCommentBox_Statics::PCGToolset_eventAddCommentBox_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_AddCommentBox_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPCGToolset_AddCommentBox_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPCGToolset_AddCommentBox_Statics::PCGToolset_eventAddCommentBox_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPCGToolset_AddCommentBox()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPCGToolset_AddCommentBox_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPCGToolset::execAddCommentBox)
{
	P_GET_OBJECT(UPCGGraph,Z_Param_Graph);
	P_GET_TARRAY_REF(UPCGNode*,Z_Param_Out_Nodes);
	P_GET_PROPERTY(FStrProperty,Z_Param_Comment);
	P_GET_STRUCT(FLinearColor,Z_Param_Color);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UPCGToolset::AddCommentBox(Z_Param_Graph,Z_Param_Out_Nodes,Z_Param_Comment,Z_Param_Color);
	P_NATIVE_END;
}
// ********** End Class UPCGToolset Function AddCommentBox *****************************************

// ********** Begin Class UPCGToolset Function AddNode *********************************************
struct Z_Construct_UFunction_UPCGToolset_AddNode_Statics
{
	struct PCGToolset_eventAddNode_Parms
	{
		UPCGGraph* Graph;
		FString NativeNodeType;
		FString NodeName;
		FString JsonParams;
		FString NodeTitle;
		FString NodeComment;
		int32 XPositionIdx;
		int32 YPositionIdx;
		UPCGNode* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PCG|Nodes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Adds a native node to the graph. \n\x09 *\n\x09 * @param Graph - Graph to modify.\n\x09 * @param NativeNodeType - The native type of the added node.\n\x09 * @param NodeName - The name of the added node. (Must be unique identifier in the graph)\n\x09 * @param JsonParams - The Json string representing a dictionary of the params to set on the node. Optional. Default is empty. Only non-default params need be included.\n\x09 * @param NodeTitle - The Display Title of the node. Optional. Default is empty.\n\x09 * @param NodeComment - The comment attached to the node, if needed. Default is empty.\n\x09 * @param XPositionIdx - The X coordinate of the position of the node in the editor. Optional. Default is 0. Typical node size X is 200\n\x09 * @param YPositionIdx - The Y coordinate of the position of the node in the editor. Optional. Default is 0. Typical node size Y is 100\n\x09 * @return The Added Node object\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/PCGToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds a native node to the graph.\n\n@param Graph - Graph to modify.\n@param NativeNodeType - The native type of the added node.\n@param NodeName - The name of the added node. (Must be unique identifier in the graph)\n@param JsonParams - The Json string representing a dictionary of the params to set on the node. Optional. Default is empty. Only non-default params need be included.\n@param NodeTitle - The Display Title of the node. Optional. Default is empty.\n@param NodeComment - The comment attached to the node, if needed. Default is empty.\n@param XPositionIdx - The X coordinate of the position of the node in the editor. Optional. Default is 0. Typical node size X is 200\n@param YPositionIdx - The Y coordinate of the position of the node in the editor. Optional. Default is 0. Typical node size Y is 100\n@return The Added Node object" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NativeNodeType_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NodeName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonParams_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NodeTitle_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NodeComment_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_XPositionIdx_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_YPositionIdx_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddNode constinit property declarations *******************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Graph;
	static const UECodeGen_Private::FStrPropertyParams NewProp_NativeNodeType;
	static const UECodeGen_Private::FStrPropertyParams NewProp_NodeName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_JsonParams;
	static const UECodeGen_Private::FStrPropertyParams NewProp_NodeTitle;
	static const UECodeGen_Private::FStrPropertyParams NewProp_NodeComment;
	static const UECodeGen_Private::FIntPropertyParams NewProp_XPositionIdx;
	static const UECodeGen_Private::FIntPropertyParams NewProp_YPositionIdx;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddNode constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddNode Property Definitions ******************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_AddNode_Statics::NewProp_Graph = { "Graph", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventAddNode_Parms, Graph), Z_Construct_UClass_UPCGGraph_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_AddNode_Statics::NewProp_NativeNodeType = { "NativeNodeType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventAddNode_Parms, NativeNodeType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NativeNodeType_MetaData), NewProp_NativeNodeType_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_AddNode_Statics::NewProp_NodeName = { "NodeName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventAddNode_Parms, NodeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NodeName_MetaData), NewProp_NodeName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_AddNode_Statics::NewProp_JsonParams = { "JsonParams", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventAddNode_Parms, JsonParams), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonParams_MetaData), NewProp_JsonParams_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_AddNode_Statics::NewProp_NodeTitle = { "NodeTitle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventAddNode_Parms, NodeTitle), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NodeTitle_MetaData), NewProp_NodeTitle_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_AddNode_Statics::NewProp_NodeComment = { "NodeComment", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventAddNode_Parms, NodeComment), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NodeComment_MetaData), NewProp_NodeComment_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPCGToolset_AddNode_Statics::NewProp_XPositionIdx = { "XPositionIdx", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventAddNode_Parms, XPositionIdx), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_XPositionIdx_MetaData), NewProp_XPositionIdx_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPCGToolset_AddNode_Statics::NewProp_YPositionIdx = { "YPositionIdx", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventAddNode_Parms, YPositionIdx), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_YPositionIdx_MetaData), NewProp_YPositionIdx_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_AddNode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventAddNode_Parms, ReturnValue), Z_Construct_UClass_UPCGNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPCGToolset_AddNode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_AddNode_Statics::NewProp_Graph,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_AddNode_Statics::NewProp_NativeNodeType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_AddNode_Statics::NewProp_NodeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_AddNode_Statics::NewProp_JsonParams,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_AddNode_Statics::NewProp_NodeTitle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_AddNode_Statics::NewProp_NodeComment,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_AddNode_Statics::NewProp_XPositionIdx,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_AddNode_Statics::NewProp_YPositionIdx,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_AddNode_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_AddNode_Statics::PropPointers) < 2048);
// ********** End Function AddNode Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPCGToolset_AddNode_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPCGToolset, nullptr, "AddNode", 	Z_Construct_UFunction_UPCGToolset_AddNode_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_AddNode_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPCGToolset_AddNode_Statics::PCGToolset_eventAddNode_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_AddNode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPCGToolset_AddNode_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPCGToolset_AddNode_Statics::PCGToolset_eventAddNode_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPCGToolset_AddNode()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPCGToolset_AddNode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPCGToolset::execAddNode)
{
	P_GET_OBJECT(UPCGGraph,Z_Param_Graph);
	P_GET_PROPERTY(FStrProperty,Z_Param_NativeNodeType);
	P_GET_PROPERTY(FStrProperty,Z_Param_NodeName);
	P_GET_PROPERTY(FStrProperty,Z_Param_JsonParams);
	P_GET_PROPERTY(FStrProperty,Z_Param_NodeTitle);
	P_GET_PROPERTY(FStrProperty,Z_Param_NodeComment);
	P_GET_PROPERTY(FIntProperty,Z_Param_XPositionIdx);
	P_GET_PROPERTY(FIntProperty,Z_Param_YPositionIdx);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UPCGNode**)Z_Param__Result=UPCGToolset::AddNode(Z_Param_Graph,Z_Param_NativeNodeType,Z_Param_NodeName,Z_Param_JsonParams,Z_Param_NodeTitle,Z_Param_NodeComment,Z_Param_XPositionIdx,Z_Param_YPositionIdx);
	P_NATIVE_END;
}
// ********** End Class UPCGToolset Function AddNode ***********************************************

// ********** Begin Class UPCGToolset Function AddSubgraphNode *************************************
struct Z_Construct_UFunction_UPCGToolset_AddSubgraphNode_Statics
{
	struct PCGToolset_eventAddSubgraphNode_Parms
	{
		UPCGGraph* Graph;
		UPCGGraph* SubGraphForNode;
		FString NodeName;
		FString JsonParams;
		FString NodeTitle;
		FString NodeComment;
		int32 XPositionIdx;
		int32 YPositionIdx;
		UPCGNode* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PCG|Nodes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Adds a subgraph node to the graph. \n\x09 *\n\x09 * @param Graph - Graph to modify.\n\x09 * @param SubGraphForNode - The subgraph to use in the added node.\n\x09 * @param NodeName - The name of the added node. (Must be unique identifier in the graph)\n\x09 * @param JsonParams - The Json string representing a dictionary of the params to override on the graph. Optional. Default is empty. Only non-default params need be included\n\x09 * @param NodeTitle - The Display Title of the node. Optional. Default is empty.\n\x09 * @param NodeComment - The comment attached to the node, if needed. Default is empty and will clear the comment.\n\x09 * @param XPositionIdx - The X coordinate of the position of the node in the editor. Optional. Default is 0. Typical node size X is 200\n\x09 * @param YPositionIdx - The Y coordinate of the position of the node in the editor. Optional. Default is 0. Typical node size Y is 100\n\x09 * @return The Added Node object\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/PCGToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds a subgraph node to the graph.\n\n@param Graph - Graph to modify.\n@param SubGraphForNode - The subgraph to use in the added node.\n@param NodeName - The name of the added node. (Must be unique identifier in the graph)\n@param JsonParams - The Json string representing a dictionary of the params to override on the graph. Optional. Default is empty. Only non-default params need be included\n@param NodeTitle - The Display Title of the node. Optional. Default is empty.\n@param NodeComment - The comment attached to the node, if needed. Default is empty and will clear the comment.\n@param XPositionIdx - The X coordinate of the position of the node in the editor. Optional. Default is 0. Typical node size X is 200\n@param YPositionIdx - The Y coordinate of the position of the node in the editor. Optional. Default is 0. Typical node size Y is 100\n@return The Added Node object" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NodeName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonParams_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NodeTitle_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NodeComment_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_XPositionIdx_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_YPositionIdx_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddSubgraphNode constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Graph;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SubGraphForNode;
	static const UECodeGen_Private::FStrPropertyParams NewProp_NodeName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_JsonParams;
	static const UECodeGen_Private::FStrPropertyParams NewProp_NodeTitle;
	static const UECodeGen_Private::FStrPropertyParams NewProp_NodeComment;
	static const UECodeGen_Private::FIntPropertyParams NewProp_XPositionIdx;
	static const UECodeGen_Private::FIntPropertyParams NewProp_YPositionIdx;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddSubgraphNode constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddSubgraphNode Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_AddSubgraphNode_Statics::NewProp_Graph = { "Graph", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventAddSubgraphNode_Parms, Graph), Z_Construct_UClass_UPCGGraph_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_AddSubgraphNode_Statics::NewProp_SubGraphForNode = { "SubGraphForNode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventAddSubgraphNode_Parms, SubGraphForNode), Z_Construct_UClass_UPCGGraph_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_AddSubgraphNode_Statics::NewProp_NodeName = { "NodeName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventAddSubgraphNode_Parms, NodeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NodeName_MetaData), NewProp_NodeName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_AddSubgraphNode_Statics::NewProp_JsonParams = { "JsonParams", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventAddSubgraphNode_Parms, JsonParams), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonParams_MetaData), NewProp_JsonParams_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_AddSubgraphNode_Statics::NewProp_NodeTitle = { "NodeTitle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventAddSubgraphNode_Parms, NodeTitle), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NodeTitle_MetaData), NewProp_NodeTitle_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_AddSubgraphNode_Statics::NewProp_NodeComment = { "NodeComment", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventAddSubgraphNode_Parms, NodeComment), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NodeComment_MetaData), NewProp_NodeComment_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPCGToolset_AddSubgraphNode_Statics::NewProp_XPositionIdx = { "XPositionIdx", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventAddSubgraphNode_Parms, XPositionIdx), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_XPositionIdx_MetaData), NewProp_XPositionIdx_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPCGToolset_AddSubgraphNode_Statics::NewProp_YPositionIdx = { "YPositionIdx", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventAddSubgraphNode_Parms, YPositionIdx), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_YPositionIdx_MetaData), NewProp_YPositionIdx_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_AddSubgraphNode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventAddSubgraphNode_Parms, ReturnValue), Z_Construct_UClass_UPCGNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPCGToolset_AddSubgraphNode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_AddSubgraphNode_Statics::NewProp_Graph,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_AddSubgraphNode_Statics::NewProp_SubGraphForNode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_AddSubgraphNode_Statics::NewProp_NodeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_AddSubgraphNode_Statics::NewProp_JsonParams,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_AddSubgraphNode_Statics::NewProp_NodeTitle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_AddSubgraphNode_Statics::NewProp_NodeComment,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_AddSubgraphNode_Statics::NewProp_XPositionIdx,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_AddSubgraphNode_Statics::NewProp_YPositionIdx,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_AddSubgraphNode_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_AddSubgraphNode_Statics::PropPointers) < 2048);
// ********** End Function AddSubgraphNode Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPCGToolset_AddSubgraphNode_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPCGToolset, nullptr, "AddSubgraphNode", 	Z_Construct_UFunction_UPCGToolset_AddSubgraphNode_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_AddSubgraphNode_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPCGToolset_AddSubgraphNode_Statics::PCGToolset_eventAddSubgraphNode_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_AddSubgraphNode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPCGToolset_AddSubgraphNode_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPCGToolset_AddSubgraphNode_Statics::PCGToolset_eventAddSubgraphNode_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPCGToolset_AddSubgraphNode()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPCGToolset_AddSubgraphNode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPCGToolset::execAddSubgraphNode)
{
	P_GET_OBJECT(UPCGGraph,Z_Param_Graph);
	P_GET_OBJECT(UPCGGraph,Z_Param_SubGraphForNode);
	P_GET_PROPERTY(FStrProperty,Z_Param_NodeName);
	P_GET_PROPERTY(FStrProperty,Z_Param_JsonParams);
	P_GET_PROPERTY(FStrProperty,Z_Param_NodeTitle);
	P_GET_PROPERTY(FStrProperty,Z_Param_NodeComment);
	P_GET_PROPERTY(FIntProperty,Z_Param_XPositionIdx);
	P_GET_PROPERTY(FIntProperty,Z_Param_YPositionIdx);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UPCGNode**)Z_Param__Result=UPCGToolset::AddSubgraphNode(Z_Param_Graph,Z_Param_SubGraphForNode,Z_Param_NodeName,Z_Param_JsonParams,Z_Param_NodeTitle,Z_Param_NodeComment,Z_Param_XPositionIdx,Z_Param_YPositionIdx);
	P_NATIVE_END;
}
// ********** End Class UPCGToolset Function AddSubgraphNode ***************************************

// ********** Begin Class UPCGToolset Function ConnectNodePins *************************************
struct Z_Construct_UFunction_UPCGToolset_ConnectNodePins_Statics
{
	struct PCGToolset_eventConnectNodePins_Parms
	{
		UPCGNode* FromNode;
		FString FromPinLabel;
		UPCGNode* ToNode;
		FString ToPinLabel;
		TArray<UPCGNode*> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PCG|Nodes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Add an edge between two nodes connected to the specified pins. \n\x09 *\n\x09 * @param FromNode - The source node of the edge to add. \n\x09 * @param FromPinLabel - The label of the source pin of the source node. \n\x09 * @param ToNode - The destination node of the edge to add. \n\x09 * @param ToPinLabel - The label of the destination pin of the destination node. \n\x09 * @return The list of nodes (conversions and/or filters) that were added to allow the connection to work. \n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/PCGToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Add an edge between two nodes connected to the specified pins.\n\n@param FromNode - The source node of the edge to add.\n@param FromPinLabel - The label of the source pin of the source node.\n@param ToNode - The destination node of the edge to add.\n@param ToPinLabel - The label of the destination pin of the destination node.\n@return The list of nodes (conversions and/or filters) that were added to allow the connection to work." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FromPinLabel_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ToPinLabel_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ConnectNodePins constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FromNode;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FromPinLabel;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ToNode;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ToPinLabel;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ConnectNodePins constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ConnectNodePins Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_ConnectNodePins_Statics::NewProp_FromNode = { "FromNode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventConnectNodePins_Parms, FromNode), Z_Construct_UClass_UPCGNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_ConnectNodePins_Statics::NewProp_FromPinLabel = { "FromPinLabel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventConnectNodePins_Parms, FromPinLabel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FromPinLabel_MetaData), NewProp_FromPinLabel_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_ConnectNodePins_Statics::NewProp_ToNode = { "ToNode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventConnectNodePins_Parms, ToNode), Z_Construct_UClass_UPCGNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_ConnectNodePins_Statics::NewProp_ToPinLabel = { "ToPinLabel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventConnectNodePins_Parms, ToPinLabel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ToPinLabel_MetaData), NewProp_ToPinLabel_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_ConnectNodePins_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UPCGNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPCGToolset_ConnectNodePins_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventConnectNodePins_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPCGToolset_ConnectNodePins_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_ConnectNodePins_Statics::NewProp_FromNode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_ConnectNodePins_Statics::NewProp_FromPinLabel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_ConnectNodePins_Statics::NewProp_ToNode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_ConnectNodePins_Statics::NewProp_ToPinLabel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_ConnectNodePins_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_ConnectNodePins_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_ConnectNodePins_Statics::PropPointers) < 2048);
// ********** End Function ConnectNodePins Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPCGToolset_ConnectNodePins_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPCGToolset, nullptr, "ConnectNodePins", 	Z_Construct_UFunction_UPCGToolset_ConnectNodePins_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_ConnectNodePins_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPCGToolset_ConnectNodePins_Statics::PCGToolset_eventConnectNodePins_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_ConnectNodePins_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPCGToolset_ConnectNodePins_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPCGToolset_ConnectNodePins_Statics::PCGToolset_eventConnectNodePins_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPCGToolset_ConnectNodePins()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPCGToolset_ConnectNodePins_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPCGToolset::execConnectNodePins)
{
	P_GET_OBJECT(UPCGNode,Z_Param_FromNode);
	P_GET_PROPERTY(FStrProperty,Z_Param_FromPinLabel);
	P_GET_OBJECT(UPCGNode,Z_Param_ToNode);
	P_GET_PROPERTY(FStrProperty,Z_Param_ToPinLabel);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<UPCGNode*>*)Z_Param__Result=UPCGToolset::ConnectNodePins(Z_Param_FromNode,Z_Param_FromPinLabel,Z_Param_ToNode,Z_Param_ToPinLabel);
	P_NATIVE_END;
}
// ********** End Class UPCGToolset Function ConnectNodePins ***************************************

// ********** Begin Class UPCGToolset Function CreateGraph *****************************************
struct Z_Construct_UFunction_UPCGToolset_CreateGraph_Statics
{
	struct PCGToolset_eventCreateGraph_Parms
	{
		FString Name;
		FString Path;
		UPCGGraph* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PCG|Graph" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Creates a new saved PCG graph asset.\n\x09 *\n\x09 * @param Name - Name for the new PCG graph asset (e.g., \"PCG_ForestScatter\")\n\x09 * @param Path - Content folder path where the asset should be created. Defaults to \"/Game/PCG\"\n\x09 * @return The created PCG graph\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/PCGToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Creates a new saved PCG graph asset.\n\n@param Name - Name for the new PCG graph asset (e.g., \"PCG_ForestScatter\")\n@param Path - Content folder path where the asset should be created. Defaults to \"/Game/PCG\"\n@return The created PCG graph" },
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
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CreateGraph constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CreateGraph Property Definitions **************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_CreateGraph_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventCreateGraph_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_CreateGraph_Statics::NewProp_Path = { "Path", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventCreateGraph_Parms, Path), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Path_MetaData), NewProp_Path_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_CreateGraph_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventCreateGraph_Parms, ReturnValue), Z_Construct_UClass_UPCGGraph_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPCGToolset_CreateGraph_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_CreateGraph_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_CreateGraph_Statics::NewProp_Path,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_CreateGraph_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_CreateGraph_Statics::PropPointers) < 2048);
// ********** End Function CreateGraph Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPCGToolset_CreateGraph_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPCGToolset, nullptr, "CreateGraph", 	Z_Construct_UFunction_UPCGToolset_CreateGraph_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_CreateGraph_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPCGToolset_CreateGraph_Statics::PCGToolset_eventCreateGraph_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_CreateGraph_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPCGToolset_CreateGraph_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPCGToolset_CreateGraph_Statics::PCGToolset_eventCreateGraph_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPCGToolset_CreateGraph()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPCGToolset_CreateGraph_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPCGToolset::execCreateGraph)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FStrProperty,Z_Param_Path);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UPCGGraph**)Z_Param__Result=UPCGToolset::CreateGraph(Z_Param_Name,Z_Param_Path);
	P_NATIVE_END;
}
// ********** End Class UPCGToolset Function CreateGraph *******************************************

// ********** Begin Class UPCGToolset Function DisconnectNodePins **********************************
struct Z_Construct_UFunction_UPCGToolset_DisconnectNodePins_Statics
{
	struct PCGToolset_eventDisconnectNodePins_Parms
	{
		UPCGNode* FromNode;
		FString FromPinLabel;
		UPCGNode* ToNode;
		FString ToPinLabel;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PCG|Nodes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Removes the edge between two nodes connected to the specified pins. \n\x09 *\n\x09 * @param FromNode - The source node of the edge to add. \n\x09 * @param FromPinLabel - The label of the source pin of the source node. \n\x09 * @param ToNode - The destination node of the edge to add. \n\x09 * @param ToPinLabel - The label of the destination pin of the destination node.\n\x09 * @return boolean representing success/failed \n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/PCGToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Removes the edge between two nodes connected to the specified pins.\n\n@param FromNode - The source node of the edge to add.\n@param FromPinLabel - The label of the source pin of the source node.\n@param ToNode - The destination node of the edge to add.\n@param ToPinLabel - The label of the destination pin of the destination node.\n@return boolean representing success/failed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FromPinLabel_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ToPinLabel_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function DisconnectNodePins constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FromNode;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FromPinLabel;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ToNode;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ToPinLabel;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DisconnectNodePins constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DisconnectNodePins Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_DisconnectNodePins_Statics::NewProp_FromNode = { "FromNode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventDisconnectNodePins_Parms, FromNode), Z_Construct_UClass_UPCGNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_DisconnectNodePins_Statics::NewProp_FromPinLabel = { "FromPinLabel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventDisconnectNodePins_Parms, FromPinLabel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FromPinLabel_MetaData), NewProp_FromPinLabel_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_DisconnectNodePins_Statics::NewProp_ToNode = { "ToNode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventDisconnectNodePins_Parms, ToNode), Z_Construct_UClass_UPCGNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_DisconnectNodePins_Statics::NewProp_ToPinLabel = { "ToPinLabel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventDisconnectNodePins_Parms, ToPinLabel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ToPinLabel_MetaData), NewProp_ToPinLabel_MetaData) };
void Z_Construct_UFunction_UPCGToolset_DisconnectNodePins_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PCGToolset_eventDisconnectNodePins_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPCGToolset_DisconnectNodePins_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PCGToolset_eventDisconnectNodePins_Parms), &Z_Construct_UFunction_UPCGToolset_DisconnectNodePins_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPCGToolset_DisconnectNodePins_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_DisconnectNodePins_Statics::NewProp_FromNode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_DisconnectNodePins_Statics::NewProp_FromPinLabel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_DisconnectNodePins_Statics::NewProp_ToNode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_DisconnectNodePins_Statics::NewProp_ToPinLabel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_DisconnectNodePins_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_DisconnectNodePins_Statics::PropPointers) < 2048);
// ********** End Function DisconnectNodePins Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPCGToolset_DisconnectNodePins_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPCGToolset, nullptr, "DisconnectNodePins", 	Z_Construct_UFunction_UPCGToolset_DisconnectNodePins_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_DisconnectNodePins_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPCGToolset_DisconnectNodePins_Statics::PCGToolset_eventDisconnectNodePins_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_DisconnectNodePins_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPCGToolset_DisconnectNodePins_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPCGToolset_DisconnectNodePins_Statics::PCGToolset_eventDisconnectNodePins_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPCGToolset_DisconnectNodePins()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPCGToolset_DisconnectNodePins_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPCGToolset::execDisconnectNodePins)
{
	P_GET_OBJECT(UPCGNode,Z_Param_FromNode);
	P_GET_PROPERTY(FStrProperty,Z_Param_FromPinLabel);
	P_GET_OBJECT(UPCGNode,Z_Param_ToNode);
	P_GET_PROPERTY(FStrProperty,Z_Param_ToPinLabel);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPCGToolset::DisconnectNodePins(Z_Param_FromNode,Z_Param_FromPinLabel,Z_Param_ToNode,Z_Param_ToPinLabel);
	P_NATIVE_END;
}
// ********** End Class UPCGToolset Function DisconnectNodePins ************************************

// ********** Begin Class UPCGToolset Function DrawSpline ******************************************
struct Z_Construct_UFunction_UPCGToolset_DrawSpline_Statics
{
	struct PCGToolset_eventDrawSpline_Parms
	{
		FString ActorLabel;
		FString ActorTag;
		bool bRedraw;
		bool bClosedSpline;
		UToolCallAsyncResultVoid* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PCG|Other" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Triggers the user to draw a spline in the viewport to be used later in the world building. Waits for the user to be done. \n\x09 *\n\x09 * @param ActorLabel - The label of the actor created or if bRedraw, the label of the actor to redraw the spline\n\x09 * @param ActorTag - Tag assigned to the actor\n\x09 * @param bRedraw - false: creates a new actor with the spline. true: find an actor with the label, and replaces its spline.\n\x09 * @param bClosedSpline - true: closed spline (region) false: path.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/PCGToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Triggers the user to draw a spline in the viewport to be used later in the world building. Waits for the user to be done.\n\n@param ActorLabel - The label of the actor created or if bRedraw, the label of the actor to redraw the spline\n@param ActorTag - Tag assigned to the actor\n@param bRedraw - false: creates a new actor with the spline. true: find an actor with the label, and replaces its spline.\n@param bClosedSpline - true: closed spline (region) false: path." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorLabel_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorTag_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function DrawSpline constinit property declarations ****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ActorLabel;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ActorTag;
	static void NewProp_bRedraw_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRedraw;
	static void NewProp_bClosedSpline_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bClosedSpline;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DrawSpline constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DrawSpline Property Definitions ***************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_DrawSpline_Statics::NewProp_ActorLabel = { "ActorLabel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventDrawSpline_Parms, ActorLabel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorLabel_MetaData), NewProp_ActorLabel_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_DrawSpline_Statics::NewProp_ActorTag = { "ActorTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventDrawSpline_Parms, ActorTag), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorTag_MetaData), NewProp_ActorTag_MetaData) };
void Z_Construct_UFunction_UPCGToolset_DrawSpline_Statics::NewProp_bRedraw_SetBit(void* Obj)
{
	((PCGToolset_eventDrawSpline_Parms*)Obj)->bRedraw = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPCGToolset_DrawSpline_Statics::NewProp_bRedraw = { "bRedraw", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PCGToolset_eventDrawSpline_Parms), &Z_Construct_UFunction_UPCGToolset_DrawSpline_Statics::NewProp_bRedraw_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPCGToolset_DrawSpline_Statics::NewProp_bClosedSpline_SetBit(void* Obj)
{
	((PCGToolset_eventDrawSpline_Parms*)Obj)->bClosedSpline = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPCGToolset_DrawSpline_Statics::NewProp_bClosedSpline = { "bClosedSpline", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PCGToolset_eventDrawSpline_Parms), &Z_Construct_UFunction_UPCGToolset_DrawSpline_Statics::NewProp_bClosedSpline_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_DrawSpline_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventDrawSpline_Parms, ReturnValue), Z_Construct_UClass_UToolCallAsyncResultVoid_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPCGToolset_DrawSpline_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_DrawSpline_Statics::NewProp_ActorLabel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_DrawSpline_Statics::NewProp_ActorTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_DrawSpline_Statics::NewProp_bRedraw,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_DrawSpline_Statics::NewProp_bClosedSpline,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_DrawSpline_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_DrawSpline_Statics::PropPointers) < 2048);
// ********** End Function DrawSpline Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPCGToolset_DrawSpline_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPCGToolset, nullptr, "DrawSpline", 	Z_Construct_UFunction_UPCGToolset_DrawSpline_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_DrawSpline_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPCGToolset_DrawSpline_Statics::PCGToolset_eventDrawSpline_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_DrawSpline_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPCGToolset_DrawSpline_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPCGToolset_DrawSpline_Statics::PCGToolset_eventDrawSpline_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPCGToolset_DrawSpline()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPCGToolset_DrawSpline_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPCGToolset::execDrawSpline)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ActorLabel);
	P_GET_PROPERTY(FStrProperty,Z_Param_ActorTag);
	P_GET_UBOOL(Z_Param_bRedraw);
	P_GET_UBOOL(Z_Param_bClosedSpline);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UToolCallAsyncResultVoid**)Z_Param__Result=UPCGToolset::DrawSpline(Z_Param_ActorLabel,Z_Param_ActorTag,Z_Param_bRedraw,Z_Param_bClosedSpline);
	P_NATIVE_END;
}
// ********** End Class UPCGToolset Function DrawSpline ********************************************

// ********** Begin Class UPCGToolset Function ExecuteGraphInstance ********************************
struct Z_Construct_UFunction_UPCGToolset_ExecuteGraphInstance_Statics
{
	struct PCGToolset_eventExecuteGraphInstance_Parms
	{
		const APCGVolume* PCGVolume;
		UPCGExecuteGraphInstanceAsyncResult* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PCG|GraphInstanceParams" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Executes the graph instance and returns any issues encountered during execution.\n\x09 *\n\x09 * @param PCGVolume - The PCG Volume whose graph instance to execute.\n\x09 * @return Array of messages emitted while executing the graph instance (empty on success with no issues)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/PCGToolset.h" },
		{ "NonTransactableToolCall", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Executes the graph instance and returns any issues encountered during execution.\n\n@param PCGVolume - The PCG Volume whose graph instance to execute.\n@return Array of messages emitted while executing the graph instance (empty on success with no issues)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PCGVolume_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ExecuteGraphInstance constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PCGVolume;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ExecuteGraphInstance constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ExecuteGraphInstance Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_ExecuteGraphInstance_Statics::NewProp_PCGVolume = { "PCGVolume", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventExecuteGraphInstance_Parms, PCGVolume), Z_Construct_UClass_APCGVolume_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PCGVolume_MetaData), NewProp_PCGVolume_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_ExecuteGraphInstance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventExecuteGraphInstance_Parms, ReturnValue), Z_Construct_UClass_UPCGExecuteGraphInstanceAsyncResult_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPCGToolset_ExecuteGraphInstance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_ExecuteGraphInstance_Statics::NewProp_PCGVolume,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_ExecuteGraphInstance_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_ExecuteGraphInstance_Statics::PropPointers) < 2048);
// ********** End Function ExecuteGraphInstance Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPCGToolset_ExecuteGraphInstance_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPCGToolset, nullptr, "ExecuteGraphInstance", 	Z_Construct_UFunction_UPCGToolset_ExecuteGraphInstance_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_ExecuteGraphInstance_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPCGToolset_ExecuteGraphInstance_Statics::PCGToolset_eventExecuteGraphInstance_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_ExecuteGraphInstance_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPCGToolset_ExecuteGraphInstance_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPCGToolset_ExecuteGraphInstance_Statics::PCGToolset_eventExecuteGraphInstance_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPCGToolset_ExecuteGraphInstance()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPCGToolset_ExecuteGraphInstance_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPCGToolset::execExecuteGraphInstance)
{
	P_GET_OBJECT(APCGVolume,Z_Param_PCGVolume);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UPCGExecuteGraphInstanceAsyncResult**)Z_Param__Result=UPCGToolset::ExecuteGraphInstance(Z_Param_PCGVolume);
	P_NATIVE_END;
}
// ********** End Class UPCGToolset Function ExecuteGraphInstance **********************************

// ********** Begin Class UPCGToolset Function GetGraphDescription *********************************
struct Z_Construct_UFunction_UPCGToolset_GetGraphDescription_Statics
{
	struct PCGToolset_eventGetGraphDescription_Parms
	{
		const UPCGGraph* Graph;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PCG|GraphParams" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the description of a PCG graph.\n\x09 *\n\x09 * @param Graph - Graph to get the description of.\n\x09 * @return The graph's description text, or empty string if the graph has no description set.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/PCGToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the description of a PCG graph.\n\n@param Graph - Graph to get the description of.\n@return The graph's description text, or empty string if the graph has no description set." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Graph_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetGraphDescription constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Graph;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGraphDescription constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGraphDescription Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_GetGraphDescription_Statics::NewProp_Graph = { "Graph", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventGetGraphDescription_Parms, Graph), Z_Construct_UClass_UPCGGraph_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Graph_MetaData), NewProp_Graph_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_GetGraphDescription_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventGetGraphDescription_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPCGToolset_GetGraphDescription_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_GetGraphDescription_Statics::NewProp_Graph,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_GetGraphDescription_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_GetGraphDescription_Statics::PropPointers) < 2048);
// ********** End Function GetGraphDescription Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPCGToolset_GetGraphDescription_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPCGToolset, nullptr, "GetGraphDescription", 	Z_Construct_UFunction_UPCGToolset_GetGraphDescription_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_GetGraphDescription_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPCGToolset_GetGraphDescription_Statics::PCGToolset_eventGetGraphDescription_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_GetGraphDescription_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPCGToolset_GetGraphDescription_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPCGToolset_GetGraphDescription_Statics::PCGToolset_eventGetGraphDescription_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPCGToolset_GetGraphDescription()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPCGToolset_GetGraphDescription_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPCGToolset::execGetGraphDescription)
{
	P_GET_OBJECT(UPCGGraph,Z_Param_Graph);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UPCGToolset::GetGraphDescription(Z_Param_Graph);
	P_NATIVE_END;
}
// ********** End Class UPCGToolset Function GetGraphDescription ***********************************

// ********** Begin Class UPCGToolset Function GetGraphInstanceParams ******************************
struct Z_Construct_UFunction_UPCGToolset_GetGraphInstanceParams_Statics
{
	struct PCGToolset_eventGetGraphInstanceParams_Parms
	{
		const APCGVolume* PCGVolume;
		FInstancedPropertyBag ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PCG|GraphInstanceParams" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Gets the graph instance params of a specific actor, actor MUST have a graph instance\n\x09 *\n\x09 * @param PCGVolume - The actor to get graph instance params from\n\x09 * @return FInstancedPropertyBag containing the filtered graph instance parameters\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/PCGToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Gets the graph instance params of a specific actor, actor MUST have a graph instance\n\n@param PCGVolume - The actor to get graph instance params from\n@return FInstancedPropertyBag containing the filtered graph instance parameters" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PCGVolume_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetGraphInstanceParams constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PCGVolume;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGraphInstanceParams constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGraphInstanceParams Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_GetGraphInstanceParams_Statics::NewProp_PCGVolume = { "PCGVolume", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventGetGraphInstanceParams_Parms, PCGVolume), Z_Construct_UClass_APCGVolume_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PCGVolume_MetaData), NewProp_PCGVolume_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPCGToolset_GetGraphInstanceParams_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventGetGraphInstanceParams_Parms, ReturnValue), Z_Construct_UScriptStruct_FInstancedPropertyBag, METADATA_PARAMS(0, nullptr) }; // 1261298821
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPCGToolset_GetGraphInstanceParams_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_GetGraphInstanceParams_Statics::NewProp_PCGVolume,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_GetGraphInstanceParams_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_GetGraphInstanceParams_Statics::PropPointers) < 2048);
// ********** End Function GetGraphInstanceParams Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPCGToolset_GetGraphInstanceParams_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPCGToolset, nullptr, "GetGraphInstanceParams", 	Z_Construct_UFunction_UPCGToolset_GetGraphInstanceParams_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_GetGraphInstanceParams_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPCGToolset_GetGraphInstanceParams_Statics::PCGToolset_eventGetGraphInstanceParams_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_GetGraphInstanceParams_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPCGToolset_GetGraphInstanceParams_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPCGToolset_GetGraphInstanceParams_Statics::PCGToolset_eventGetGraphInstanceParams_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPCGToolset_GetGraphInstanceParams()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPCGToolset_GetGraphInstanceParams_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPCGToolset::execGetGraphInstanceParams)
{
	P_GET_OBJECT(APCGVolume,Z_Param_PCGVolume);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FInstancedPropertyBag*)Z_Param__Result=UPCGToolset::GetGraphInstanceParams(Z_Param_PCGVolume);
	P_NATIVE_END;
}
// ********** End Class UPCGToolset Function GetGraphInstanceParams ********************************

// ********** Begin Class UPCGToolset Function GetGraphSchema **************************************
struct Z_Construct_UFunction_UPCGToolset_GetGraphSchema_Statics
{
	struct PCGToolset_eventGetGraphSchema_Parms
	{
		const UPCGGraph* Graph;
		FPCGGraphSchema ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PCG|GraphParams" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the schema for a PCG Graph's graph parameters\n\x09 *\n\x09 * @param Graph - Graph to get the graph parameters of.\n\x09 * @return FPCGGraphSchema with graph name, params schema (JSON), input/output pins\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/PCGToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the schema for a PCG Graph's graph parameters\n\n@param Graph - Graph to get the graph parameters of.\n@return FPCGGraphSchema with graph name, params schema (JSON), input/output pins" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Graph_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetGraphSchema constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Graph;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGraphSchema constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGraphSchema Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_GetGraphSchema_Statics::NewProp_Graph = { "Graph", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventGetGraphSchema_Parms, Graph), Z_Construct_UClass_UPCGGraph_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Graph_MetaData), NewProp_Graph_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPCGToolset_GetGraphSchema_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventGetGraphSchema_Parms, ReturnValue), Z_Construct_UScriptStruct_FPCGGraphSchema, METADATA_PARAMS(0, nullptr) }; // 1829918540
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPCGToolset_GetGraphSchema_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_GetGraphSchema_Statics::NewProp_Graph,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_GetGraphSchema_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_GetGraphSchema_Statics::PropPointers) < 2048);
// ********** End Function GetGraphSchema Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPCGToolset_GetGraphSchema_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPCGToolset, nullptr, "GetGraphSchema", 	Z_Construct_UFunction_UPCGToolset_GetGraphSchema_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_GetGraphSchema_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPCGToolset_GetGraphSchema_Statics::PCGToolset_eventGetGraphSchema_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_GetGraphSchema_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPCGToolset_GetGraphSchema_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPCGToolset_GetGraphSchema_Statics::PCGToolset_eventGetGraphSchema_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPCGToolset_GetGraphSchema()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPCGToolset_GetGraphSchema_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPCGToolset::execGetGraphSchema)
{
	P_GET_OBJECT(UPCGGraph,Z_Param_Graph);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FPCGGraphSchema*)Z_Param__Result=UPCGToolset::GetGraphSchema(Z_Param_Graph);
	P_NATIVE_END;
}
// ********** End Class UPCGToolset Function GetGraphSchema ****************************************

// ********** Begin Class UPCGToolset Function GetGraphStructure ***********************************
struct Z_Construct_UFunction_UPCGToolset_GetGraphStructure_Statics
{
	struct PCGToolset_eventGetGraphStructure_Parms
	{
		const UPCGGraph* Graph;
		FPCGGraphStructure ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PCG|GraphParams" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the complete structure of a PCG graph including all nodes,\n\x09 * connections, exposed parameters, and comment boxes.\n\x09 *\n\x09 * @param Graph - Graph to inspect\n\x09 * @return FPCGGraphStructure with graph name, description, nodes, and edges\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/PCGToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the complete structure of a PCG graph including all nodes,\nconnections, exposed parameters, and comment boxes.\n\n@param Graph - Graph to inspect\n@return FPCGGraphStructure with graph name, description, nodes, and edges" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Graph_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetGraphStructure constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Graph;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGraphStructure constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGraphStructure Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_GetGraphStructure_Statics::NewProp_Graph = { "Graph", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventGetGraphStructure_Parms, Graph), Z_Construct_UClass_UPCGGraph_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Graph_MetaData), NewProp_Graph_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPCGToolset_GetGraphStructure_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventGetGraphStructure_Parms, ReturnValue), Z_Construct_UScriptStruct_FPCGGraphStructure, METADATA_PARAMS(0, nullptr) }; // 403529749
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPCGToolset_GetGraphStructure_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_GetGraphStructure_Statics::NewProp_Graph,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_GetGraphStructure_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_GetGraphStructure_Statics::PropPointers) < 2048);
// ********** End Function GetGraphStructure Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPCGToolset_GetGraphStructure_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPCGToolset, nullptr, "GetGraphStructure", 	Z_Construct_UFunction_UPCGToolset_GetGraphStructure_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_GetGraphStructure_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPCGToolset_GetGraphStructure_Statics::PCGToolset_eventGetGraphStructure_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_GetGraphStructure_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPCGToolset_GetGraphStructure_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPCGToolset_GetGraphStructure_Statics::PCGToolset_eventGetGraphStructure_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPCGToolset_GetGraphStructure()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPCGToolset_GetGraphStructure_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPCGToolset::execGetGraphStructure)
{
	P_GET_OBJECT(UPCGGraph,Z_Param_Graph);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FPCGGraphStructure*)Z_Param__Result=UPCGToolset::GetGraphStructure(Z_Param_Graph);
	P_NATIVE_END;
}
// ********** End Class UPCGToolset Function GetGraphStructure *************************************

// ********** Begin Class UPCGToolset Function GetNativeNodeSchema *********************************
struct Z_Construct_UFunction_UPCGToolset_GetNativeNodeSchema_Statics
{
	struct PCGToolset_eventGetNativeNodeSchema_Parms
	{
		FString NodeName;
		FPCGNativeNodeSchema ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PCG|Nodes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the schema for a PCG node type including input/output pins,\n\x09 * parameters, and their types.\n\x09 *\n\x09 * @param NodeName - Node name\n\x09 * @return FPCGNativeNodeSchema with node name, description, properties schema (JSON), input/output pins\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/PCGToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the schema for a PCG node type including input/output pins,\nparameters, and their types.\n\n@param NodeName - Node name\n@return FPCGNativeNodeSchema with node name, description, properties schema (JSON), input/output pins" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NodeName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetNativeNodeSchema constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_NodeName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetNativeNodeSchema constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetNativeNodeSchema Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_GetNativeNodeSchema_Statics::NewProp_NodeName = { "NodeName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventGetNativeNodeSchema_Parms, NodeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NodeName_MetaData), NewProp_NodeName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPCGToolset_GetNativeNodeSchema_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventGetNativeNodeSchema_Parms, ReturnValue), Z_Construct_UScriptStruct_FPCGNativeNodeSchema, METADATA_PARAMS(0, nullptr) }; // 3790087811
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPCGToolset_GetNativeNodeSchema_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_GetNativeNodeSchema_Statics::NewProp_NodeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_GetNativeNodeSchema_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_GetNativeNodeSchema_Statics::PropPointers) < 2048);
// ********** End Function GetNativeNodeSchema Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPCGToolset_GetNativeNodeSchema_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPCGToolset, nullptr, "GetNativeNodeSchema", 	Z_Construct_UFunction_UPCGToolset_GetNativeNodeSchema_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_GetNativeNodeSchema_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPCGToolset_GetNativeNodeSchema_Statics::PCGToolset_eventGetNativeNodeSchema_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_GetNativeNodeSchema_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPCGToolset_GetNativeNodeSchema_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPCGToolset_GetNativeNodeSchema_Statics::PCGToolset_eventGetNativeNodeSchema_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPCGToolset_GetNativeNodeSchema()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPCGToolset_GetNativeNodeSchema_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPCGToolset::execGetNativeNodeSchema)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_NodeName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FPCGNativeNodeSchema*)Z_Param__Result=UPCGToolset::GetNativeNodeSchema(Z_Param_NodeName);
	P_NATIVE_END;
}
// ********** End Class UPCGToolset Function GetNativeNodeSchema ***********************************

// ********** Begin Class UPCGToolset Function GetNodeDataView *************************************
struct Z_Construct_UFunction_UPCGToolset_GetNodeDataView_Statics
{
	struct PCGToolset_eventGetNodeDataView_Parms
	{
		const APCGVolume* PCGVolume;
		const UPCGNode* Node;
		FString PinLabel;
		FString AttributeName;
		int32 StartIndex;
		int32 EndIndex;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PCG|Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns a JSON Data View of a specific node's output data from the last graph execution.\n\x09 * On first call, enables inspection so future ExecuteGraphInstance calls store per-node data.\n\x09 * If no inspection data exists, returns an error prompting re-execution.\n\x09 *\n\x09 * IMPORTANT: Inspection state is shared at the graph asset level. If multiple actors use the\n\x09 * same graph, you MUST call this tool (and ExecuteGraphInstance) on only one actor at a time.\n\x09 * Wait for each call to fully complete before calling on the next actor. Concurrent calls on\n\x09 * actors sharing the same graph will cause a freeze.\n\x09 *\n\x09 * @param PCGVolume - The PCG Volume whose graph was executed.\n\x09 * @param Node - The node whose output to inspect.\n\x09 * @param PinLabel - Output pin label to read. Defaults to \"Out\".\n\x09 * @param AttributeName - Filter to a single attribute/property (e.g. \"$Position\", \"$Density\", \"MyCustomAttr\"). Empty = all attributes.\n\x09 * @param StartIndex - Element range start, inclusive, 0-based. Default 0.\n\x09 * @param EndIndex - Element range end, exclusive. -1 means all elements (Python slice convention). Default -1.\n\x09 * @return JSON string with the data view contents\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/PCGToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns a JSON Data View of a specific node's output data from the last graph execution.\nOn first call, enables inspection so future ExecuteGraphInstance calls store per-node data.\nIf no inspection data exists, returns an error prompting re-execution.\n\nIMPORTANT: Inspection state is shared at the graph asset level. If multiple actors use the\nsame graph, you MUST call this tool (and ExecuteGraphInstance) on only one actor at a time.\nWait for each call to fully complete before calling on the next actor. Concurrent calls on\nactors sharing the same graph will cause a freeze.\n\n@param PCGVolume - The PCG Volume whose graph was executed.\n@param Node - The node whose output to inspect.\n@param PinLabel - Output pin label to read. Defaults to \"Out\".\n@param AttributeName - Filter to a single attribute/property (e.g. \"$Position\", \"$Density\", \"MyCustomAttr\"). Empty = all attributes.\n@param StartIndex - Element range start, inclusive, 0-based. Default 0.\n@param EndIndex - Element range end, exclusive. -1 means all elements (Python slice convention). Default -1.\n@return JSON string with the data view contents" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PCGVolume_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Node_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PinLabel_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttributeName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartIndex_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EndIndex_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetNodeDataView constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PCGVolume;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Node;
	static const UECodeGen_Private::FStrPropertyParams NewProp_PinLabel;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AttributeName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_StartIndex;
	static const UECodeGen_Private::FIntPropertyParams NewProp_EndIndex;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetNodeDataView constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetNodeDataView Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_GetNodeDataView_Statics::NewProp_PCGVolume = { "PCGVolume", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventGetNodeDataView_Parms, PCGVolume), Z_Construct_UClass_APCGVolume_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PCGVolume_MetaData), NewProp_PCGVolume_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_GetNodeDataView_Statics::NewProp_Node = { "Node", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventGetNodeDataView_Parms, Node), Z_Construct_UClass_UPCGNode_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Node_MetaData), NewProp_Node_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_GetNodeDataView_Statics::NewProp_PinLabel = { "PinLabel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventGetNodeDataView_Parms, PinLabel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PinLabel_MetaData), NewProp_PinLabel_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_GetNodeDataView_Statics::NewProp_AttributeName = { "AttributeName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventGetNodeDataView_Parms, AttributeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttributeName_MetaData), NewProp_AttributeName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPCGToolset_GetNodeDataView_Statics::NewProp_StartIndex = { "StartIndex", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventGetNodeDataView_Parms, StartIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartIndex_MetaData), NewProp_StartIndex_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPCGToolset_GetNodeDataView_Statics::NewProp_EndIndex = { "EndIndex", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventGetNodeDataView_Parms, EndIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EndIndex_MetaData), NewProp_EndIndex_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_GetNodeDataView_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventGetNodeDataView_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPCGToolset_GetNodeDataView_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_GetNodeDataView_Statics::NewProp_PCGVolume,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_GetNodeDataView_Statics::NewProp_Node,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_GetNodeDataView_Statics::NewProp_PinLabel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_GetNodeDataView_Statics::NewProp_AttributeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_GetNodeDataView_Statics::NewProp_StartIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_GetNodeDataView_Statics::NewProp_EndIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_GetNodeDataView_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_GetNodeDataView_Statics::PropPointers) < 2048);
// ********** End Function GetNodeDataView Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPCGToolset_GetNodeDataView_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPCGToolset, nullptr, "GetNodeDataView", 	Z_Construct_UFunction_UPCGToolset_GetNodeDataView_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_GetNodeDataView_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPCGToolset_GetNodeDataView_Statics::PCGToolset_eventGetNodeDataView_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_GetNodeDataView_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPCGToolset_GetNodeDataView_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPCGToolset_GetNodeDataView_Statics::PCGToolset_eventGetNodeDataView_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPCGToolset_GetNodeDataView()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPCGToolset_GetNodeDataView_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPCGToolset::execGetNodeDataView)
{
	P_GET_OBJECT(APCGVolume,Z_Param_PCGVolume);
	P_GET_OBJECT(UPCGNode,Z_Param_Node);
	P_GET_PROPERTY(FStrProperty,Z_Param_PinLabel);
	P_GET_PROPERTY(FStrProperty,Z_Param_AttributeName);
	P_GET_PROPERTY(FIntProperty,Z_Param_StartIndex);
	P_GET_PROPERTY(FIntProperty,Z_Param_EndIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UPCGToolset::GetNodeDataView(Z_Param_PCGVolume,Z_Param_Node,Z_Param_PinLabel,Z_Param_AttributeName,Z_Param_StartIndex,Z_Param_EndIndex);
	P_NATIVE_END;
}
// ********** End Class UPCGToolset Function GetNodeDataView ***************************************

// ********** Begin Class UPCGToolset Function GetNodeInfo *****************************************
struct Z_Construct_UFunction_UPCGToolset_GetNodeInfo_Statics
{
	struct PCGToolset_eventGetNodeInfo_Parms
	{
		const UPCGNode* Node;
		FPCGNodeInfo ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PCG|Nodes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns node details including name, position, and all parameter values.\n\x09 *\n\x09 * @param Node - The node to get info from.\n\x09 * @return FPCGNodeInfo with node details including name, position, type, and parameter overrides\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/PCGToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns node details including name, position, and all parameter values.\n\n@param Node - The node to get info from.\n@return FPCGNodeInfo with node details including name, position, type, and parameter overrides" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Node_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetNodeInfo constinit property declarations ***************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Node;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetNodeInfo constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetNodeInfo Property Definitions **************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_GetNodeInfo_Statics::NewProp_Node = { "Node", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventGetNodeInfo_Parms, Node), Z_Construct_UClass_UPCGNode_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Node_MetaData), NewProp_Node_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPCGToolset_GetNodeInfo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventGetNodeInfo_Parms, ReturnValue), Z_Construct_UScriptStruct_FPCGNodeInfo, METADATA_PARAMS(0, nullptr) }; // 1617287642
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPCGToolset_GetNodeInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_GetNodeInfo_Statics::NewProp_Node,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_GetNodeInfo_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_GetNodeInfo_Statics::PropPointers) < 2048);
// ********** End Function GetNodeInfo Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPCGToolset_GetNodeInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPCGToolset, nullptr, "GetNodeInfo", 	Z_Construct_UFunction_UPCGToolset_GetNodeInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_GetNodeInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPCGToolset_GetNodeInfo_Statics::PCGToolset_eventGetNodeInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_GetNodeInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPCGToolset_GetNodeInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPCGToolset_GetNodeInfo_Statics::PCGToolset_eventGetNodeInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPCGToolset_GetNodeInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPCGToolset_GetNodeInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPCGToolset::execGetNodeInfo)
{
	P_GET_OBJECT(UPCGNode,Z_Param_Node);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FPCGNodeInfo*)Z_Param__Result=UPCGToolset::GetNodeInfo(Z_Param_Node);
	P_NATIVE_END;
}
// ********** End Class UPCGToolset Function GetNodeInfo *******************************************

// ********** Begin Class UPCGToolset Function ListAvailableSubgraphs ******************************
struct Z_Construct_UFunction_UPCGToolset_ListAvailableSubgraphs_Statics
{
	struct PCGToolset_eventListAvailableSubgraphs_Parms
	{
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PCG|Nodes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Lists the PCG graphs that can be used with the Subgraph native node. Only these graphs should be used with\n\x09 * the Subgraph native node.\n\x09 *\n\x09 * @return Array of graph asset paths that can be used with the Subgraph native node\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Public/PCGToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lists the PCG graphs that can be used with the Subgraph native node. Only these graphs should be used with\nthe Subgraph native node.\n\n@return Array of graph asset paths that can be used with the Subgraph native node" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ListAvailableSubgraphs constinit property declarations ****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListAvailableSubgraphs constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListAvailableSubgraphs Property Definitions ***************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_ListAvailableSubgraphs_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPCGToolset_ListAvailableSubgraphs_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventListAvailableSubgraphs_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPCGToolset_ListAvailableSubgraphs_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_ListAvailableSubgraphs_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_ListAvailableSubgraphs_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_ListAvailableSubgraphs_Statics::PropPointers) < 2048);
// ********** End Function ListAvailableSubgraphs Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPCGToolset_ListAvailableSubgraphs_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPCGToolset, nullptr, "ListAvailableSubgraphs", 	Z_Construct_UFunction_UPCGToolset_ListAvailableSubgraphs_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_ListAvailableSubgraphs_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPCGToolset_ListAvailableSubgraphs_Statics::PCGToolset_eventListAvailableSubgraphs_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_ListAvailableSubgraphs_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPCGToolset_ListAvailableSubgraphs_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPCGToolset_ListAvailableSubgraphs_Statics::PCGToolset_eventListAvailableSubgraphs_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPCGToolset_ListAvailableSubgraphs()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPCGToolset_ListAvailableSubgraphs_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPCGToolset::execListAvailableSubgraphs)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=UPCGToolset::ListAvailableSubgraphs();
	P_NATIVE_END;
}
// ********** End Class UPCGToolset Function ListAvailableSubgraphs ********************************

// ********** Begin Class UPCGToolset Function ListGraphInstances **********************************
struct Z_Construct_UFunction_UPCGToolset_ListGraphInstances_Statics
{
	struct PCGToolset_eventListGraphInstances_Parms
	{
		TArray<FPCGGraphInstanceInfo> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PCG|GraphInstance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Gets all actors with a PCG graph instance in the scene.\n\x09 *\n\x09 * @return Array of FPCGGraphInstanceInfo for all actors with a graph instance\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/PCGToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Gets all actors with a PCG graph instance in the scene.\n\n@return Array of FPCGGraphInstanceInfo for all actors with a graph instance" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ListGraphInstances constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListGraphInstances constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListGraphInstances Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPCGToolset_ListGraphInstances_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FPCGGraphInstanceInfo, METADATA_PARAMS(0, nullptr) }; // 313673020
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPCGToolset_ListGraphInstances_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventListGraphInstances_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 313673020
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPCGToolset_ListGraphInstances_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_ListGraphInstances_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_ListGraphInstances_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_ListGraphInstances_Statics::PropPointers) < 2048);
// ********** End Function ListGraphInstances Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPCGToolset_ListGraphInstances_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPCGToolset, nullptr, "ListGraphInstances", 	Z_Construct_UFunction_UPCGToolset_ListGraphInstances_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_ListGraphInstances_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPCGToolset_ListGraphInstances_Statics::PCGToolset_eventListGraphInstances_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_ListGraphInstances_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPCGToolset_ListGraphInstances_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPCGToolset_ListGraphInstances_Statics::PCGToolset_eventListGraphInstances_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPCGToolset_ListGraphInstances()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPCGToolset_ListGraphInstances_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPCGToolset::execListGraphInstances)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FPCGGraphInstanceInfo>*)Z_Param__Result=UPCGToolset::ListGraphInstances();
	P_NATIVE_END;
}
// ********** End Class UPCGToolset Function ListGraphInstances ************************************

// ********** Begin Class UPCGToolset Function ListNativeNodes *************************************
struct Z_Construct_UFunction_UPCGToolset_ListNativeNodes_Statics
{
	struct PCGToolset_eventListNativeNodes_Parms
	{
		bool bCommonOnly;
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PCG|Nodes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns a list of available native PCG node type names.\n\x09 *\n\x09 * @param bCommonOnly Whether to only return the commonly used Native nodes. Only use bCommonOnly = false if the user specifically asks for it.\n\x09 * @return Array of native node type names\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/PCGToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns a list of available native PCG node type names.\n\n@param bCommonOnly Whether to only return the commonly used Native nodes. Only use bCommonOnly = false if the user specifically asks for it.\n@return Array of native node type names" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCommonOnly_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ListNativeNodes constinit property declarations ***********************
	static void NewProp_bCommonOnly_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCommonOnly;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListNativeNodes constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListNativeNodes Property Definitions **********************************
void Z_Construct_UFunction_UPCGToolset_ListNativeNodes_Statics::NewProp_bCommonOnly_SetBit(void* Obj)
{
	((PCGToolset_eventListNativeNodes_Parms*)Obj)->bCommonOnly = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPCGToolset_ListNativeNodes_Statics::NewProp_bCommonOnly = { "bCommonOnly", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PCGToolset_eventListNativeNodes_Parms), &Z_Construct_UFunction_UPCGToolset_ListNativeNodes_Statics::NewProp_bCommonOnly_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCommonOnly_MetaData), NewProp_bCommonOnly_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_ListNativeNodes_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPCGToolset_ListNativeNodes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventListNativeNodes_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPCGToolset_ListNativeNodes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_ListNativeNodes_Statics::NewProp_bCommonOnly,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_ListNativeNodes_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_ListNativeNodes_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_ListNativeNodes_Statics::PropPointers) < 2048);
// ********** End Function ListNativeNodes Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPCGToolset_ListNativeNodes_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPCGToolset, nullptr, "ListNativeNodes", 	Z_Construct_UFunction_UPCGToolset_ListNativeNodes_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_ListNativeNodes_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPCGToolset_ListNativeNodes_Statics::PCGToolset_eventListNativeNodes_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_ListNativeNodes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPCGToolset_ListNativeNodes_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPCGToolset_ListNativeNodes_Statics::PCGToolset_eventListNativeNodes_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPCGToolset_ListNativeNodes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPCGToolset_ListNativeNodes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPCGToolset::execListNativeNodes)
{
	P_GET_UBOOL(Z_Param_bCommonOnly);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=UPCGToolset::ListNativeNodes(Z_Param_bCommonOnly);
	P_NATIVE_END;
}
// ********** End Class UPCGToolset Function ListNativeNodes ***************************************

// ********** Begin Class UPCGToolset Function RemoveCommentBox ************************************
struct Z_Construct_UFunction_UPCGToolset_RemoveCommentBox_Statics
{
	struct PCGToolset_eventRemoveCommentBox_Parms
	{
		UPCGGraph* Graph;
		FString CommentId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PCG|CommentBox" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Removes a comment box from the graph. Does not affect the nodes it contains.\n\x09 *\n\x09 * @param Graph - Graph to remove the comment from.\n\x09 * @param CommentId - The unique id of the comment to remove.\n\x09 * @return boolean representing success/failed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/PCGToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Removes a comment box from the graph. Does not affect the nodes it contains.\n\n@param Graph - Graph to remove the comment from.\n@param CommentId - The unique id of the comment to remove.\n@return boolean representing success/failed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CommentId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RemoveCommentBox constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Graph;
	static const UECodeGen_Private::FStrPropertyParams NewProp_CommentId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RemoveCommentBox constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RemoveCommentBox Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_RemoveCommentBox_Statics::NewProp_Graph = { "Graph", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventRemoveCommentBox_Parms, Graph), Z_Construct_UClass_UPCGGraph_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_RemoveCommentBox_Statics::NewProp_CommentId = { "CommentId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventRemoveCommentBox_Parms, CommentId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CommentId_MetaData), NewProp_CommentId_MetaData) };
void Z_Construct_UFunction_UPCGToolset_RemoveCommentBox_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PCGToolset_eventRemoveCommentBox_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPCGToolset_RemoveCommentBox_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PCGToolset_eventRemoveCommentBox_Parms), &Z_Construct_UFunction_UPCGToolset_RemoveCommentBox_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPCGToolset_RemoveCommentBox_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_RemoveCommentBox_Statics::NewProp_Graph,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_RemoveCommentBox_Statics::NewProp_CommentId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_RemoveCommentBox_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_RemoveCommentBox_Statics::PropPointers) < 2048);
// ********** End Function RemoveCommentBox Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPCGToolset_RemoveCommentBox_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPCGToolset, nullptr, "RemoveCommentBox", 	Z_Construct_UFunction_UPCGToolset_RemoveCommentBox_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_RemoveCommentBox_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPCGToolset_RemoveCommentBox_Statics::PCGToolset_eventRemoveCommentBox_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_RemoveCommentBox_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPCGToolset_RemoveCommentBox_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPCGToolset_RemoveCommentBox_Statics::PCGToolset_eventRemoveCommentBox_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPCGToolset_RemoveCommentBox()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPCGToolset_RemoveCommentBox_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPCGToolset::execRemoveCommentBox)
{
	P_GET_OBJECT(UPCGGraph,Z_Param_Graph);
	P_GET_PROPERTY(FStrProperty,Z_Param_CommentId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPCGToolset::RemoveCommentBox(Z_Param_Graph,Z_Param_CommentId);
	P_NATIVE_END;
}
// ********** End Class UPCGToolset Function RemoveCommentBox **************************************

// ********** Begin Class UPCGToolset Function RemoveGraphParams ***********************************
struct Z_Construct_UFunction_UPCGToolset_RemoveGraphParams_Statics
{
	struct PCGToolset_eventRemoveGraphParams_Parms
	{
		UPCGGraph* Graph;
		TArray<FName> ParamNames;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PCG|GraphParams" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Removes graph parameters to a specific PCG graph, such that they are not overridable anymore.\n\x09 *\n\x09 * @param Graph - Graph to remove graph parameter(s) from\n\x09 * @param ParamNames - An array of existing param names that will be removed.\n\x09 * @return boolean representing success/failed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/PCGToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Removes graph parameters to a specific PCG graph, such that they are not overridable anymore.\n\n@param Graph - Graph to remove graph parameter(s) from\n@param ParamNames - An array of existing param names that will be removed.\n@return boolean representing success/failed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ParamNames_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RemoveGraphParams constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Graph;
	static const UECodeGen_Private::FNamePropertyParams NewProp_ParamNames_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ParamNames;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RemoveGraphParams constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RemoveGraphParams Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_RemoveGraphParams_Statics::NewProp_Graph = { "Graph", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventRemoveGraphParams_Parms, Graph), Z_Construct_UClass_UPCGGraph_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UPCGToolset_RemoveGraphParams_Statics::NewProp_ParamNames_Inner = { "ParamNames", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPCGToolset_RemoveGraphParams_Statics::NewProp_ParamNames = { "ParamNames", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventRemoveGraphParams_Parms, ParamNames), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ParamNames_MetaData), NewProp_ParamNames_MetaData) };
void Z_Construct_UFunction_UPCGToolset_RemoveGraphParams_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PCGToolset_eventRemoveGraphParams_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPCGToolset_RemoveGraphParams_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PCGToolset_eventRemoveGraphParams_Parms), &Z_Construct_UFunction_UPCGToolset_RemoveGraphParams_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPCGToolset_RemoveGraphParams_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_RemoveGraphParams_Statics::NewProp_Graph,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_RemoveGraphParams_Statics::NewProp_ParamNames_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_RemoveGraphParams_Statics::NewProp_ParamNames,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_RemoveGraphParams_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_RemoveGraphParams_Statics::PropPointers) < 2048);
// ********** End Function RemoveGraphParams Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPCGToolset_RemoveGraphParams_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPCGToolset, nullptr, "RemoveGraphParams", 	Z_Construct_UFunction_UPCGToolset_RemoveGraphParams_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_RemoveGraphParams_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPCGToolset_RemoveGraphParams_Statics::PCGToolset_eventRemoveGraphParams_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_RemoveGraphParams_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPCGToolset_RemoveGraphParams_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPCGToolset_RemoveGraphParams_Statics::PCGToolset_eventRemoveGraphParams_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPCGToolset_RemoveGraphParams()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPCGToolset_RemoveGraphParams_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPCGToolset::execRemoveGraphParams)
{
	P_GET_OBJECT(UPCGGraph,Z_Param_Graph);
	P_GET_TARRAY_REF(FName,Z_Param_Out_ParamNames);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPCGToolset::RemoveGraphParams(Z_Param_Graph,Z_Param_Out_ParamNames);
	P_NATIVE_END;
}
// ********** End Class UPCGToolset Function RemoveGraphParams *************************************

// ********** Begin Class UPCGToolset Function RemoveNode ******************************************
struct Z_Construct_UFunction_UPCGToolset_RemoveNode_Statics
{
	struct PCGToolset_eventRemoveNode_Parms
	{
		UPCGGraph* Graph;
		UPCGNode* Node;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PCG|Nodes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Removes the node from the graph, will also remove edges connected to the node. \n\x09 *\n\x09 * @param Graph - The graph to remove the node from. \n\x09 * @param Node - The node to remove. \n\x09 * @return boolean representing success/failed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/PCGToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Removes the node from the graph, will also remove edges connected to the node.\n\n@param Graph - The graph to remove the node from.\n@param Node - The node to remove.\n@return boolean representing success/failed" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RemoveNode constinit property declarations ****************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Graph;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Node;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RemoveNode constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RemoveNode Property Definitions ***************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_RemoveNode_Statics::NewProp_Graph = { "Graph", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventRemoveNode_Parms, Graph), Z_Construct_UClass_UPCGGraph_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_RemoveNode_Statics::NewProp_Node = { "Node", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventRemoveNode_Parms, Node), Z_Construct_UClass_UPCGNode_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPCGToolset_RemoveNode_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PCGToolset_eventRemoveNode_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPCGToolset_RemoveNode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PCGToolset_eventRemoveNode_Parms), &Z_Construct_UFunction_UPCGToolset_RemoveNode_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPCGToolset_RemoveNode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_RemoveNode_Statics::NewProp_Graph,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_RemoveNode_Statics::NewProp_Node,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_RemoveNode_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_RemoveNode_Statics::PropPointers) < 2048);
// ********** End Function RemoveNode Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPCGToolset_RemoveNode_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPCGToolset, nullptr, "RemoveNode", 	Z_Construct_UFunction_UPCGToolset_RemoveNode_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_RemoveNode_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPCGToolset_RemoveNode_Statics::PCGToolset_eventRemoveNode_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_RemoveNode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPCGToolset_RemoveNode_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPCGToolset_RemoveNode_Statics::PCGToolset_eventRemoveNode_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPCGToolset_RemoveNode()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPCGToolset_RemoveNode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPCGToolset::execRemoveNode)
{
	P_GET_OBJECT(UPCGGraph,Z_Param_Graph);
	P_GET_OBJECT(UPCGNode,Z_Param_Node);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPCGToolset::RemoveNode(Z_Param_Graph,Z_Param_Node);
	P_NATIVE_END;
}
// ********** End Class UPCGToolset Function RemoveNode ********************************************

// ********** Begin Class UPCGToolset Function RepositionNode **************************************
struct Z_Construct_UFunction_UPCGToolset_RepositionNode_Statics
{
	struct PCGToolset_eventRepositionNode_Parms
	{
		UPCGNode* Node;
		int32 XPositionIdx;
		int32 YPositionIdx;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PCG|Nodes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Change the position of node. \n\x09 *\n\x09 * @param Node - The node to modify the position. \n\x09 * @param XPositionIdx - The X coordinate of the position of the node in the editor. \n\x09 * @param YPositionIdx - The Y coordinate of the position of the node in the editor.\n\x09 * @return boolean representing success/failed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/PCGToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Change the position of node.\n\n@param Node - The node to modify the position.\n@param XPositionIdx - The X coordinate of the position of the node in the editor.\n@param YPositionIdx - The Y coordinate of the position of the node in the editor.\n@return boolean representing success/failed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_XPositionIdx_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_YPositionIdx_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RepositionNode constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Node;
	static const UECodeGen_Private::FIntPropertyParams NewProp_XPositionIdx;
	static const UECodeGen_Private::FIntPropertyParams NewProp_YPositionIdx;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RepositionNode constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RepositionNode Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_RepositionNode_Statics::NewProp_Node = { "Node", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventRepositionNode_Parms, Node), Z_Construct_UClass_UPCGNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPCGToolset_RepositionNode_Statics::NewProp_XPositionIdx = { "XPositionIdx", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventRepositionNode_Parms, XPositionIdx), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_XPositionIdx_MetaData), NewProp_XPositionIdx_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPCGToolset_RepositionNode_Statics::NewProp_YPositionIdx = { "YPositionIdx", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventRepositionNode_Parms, YPositionIdx), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_YPositionIdx_MetaData), NewProp_YPositionIdx_MetaData) };
void Z_Construct_UFunction_UPCGToolset_RepositionNode_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PCGToolset_eventRepositionNode_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPCGToolset_RepositionNode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PCGToolset_eventRepositionNode_Parms), &Z_Construct_UFunction_UPCGToolset_RepositionNode_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPCGToolset_RepositionNode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_RepositionNode_Statics::NewProp_Node,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_RepositionNode_Statics::NewProp_XPositionIdx,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_RepositionNode_Statics::NewProp_YPositionIdx,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_RepositionNode_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_RepositionNode_Statics::PropPointers) < 2048);
// ********** End Function RepositionNode Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPCGToolset_RepositionNode_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPCGToolset, nullptr, "RepositionNode", 	Z_Construct_UFunction_UPCGToolset_RepositionNode_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_RepositionNode_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPCGToolset_RepositionNode_Statics::PCGToolset_eventRepositionNode_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_RepositionNode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPCGToolset_RepositionNode_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPCGToolset_RepositionNode_Statics::PCGToolset_eventRepositionNode_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPCGToolset_RepositionNode()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPCGToolset_RepositionNode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPCGToolset::execRepositionNode)
{
	P_GET_OBJECT(UPCGNode,Z_Param_Node);
	P_GET_PROPERTY(FIntProperty,Z_Param_XPositionIdx);
	P_GET_PROPERTY(FIntProperty,Z_Param_YPositionIdx);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPCGToolset::RepositionNode(Z_Param_Node,Z_Param_XPositionIdx,Z_Param_YPositionIdx);
	P_NATIVE_END;
}
// ********** End Class UPCGToolset Function RepositionNode ****************************************

// ********** Begin Class UPCGToolset Function ResetGraphInstanceParams ****************************
struct Z_Construct_UFunction_UPCGToolset_ResetGraphInstanceParams_Statics
{
	struct PCGToolset_eventResetGraphInstanceParams_Parms
	{
		const APCGVolume* PCGVolume;
		TArray<FName> ParamNames;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PCG|GraphInstanceParams" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Resets the given graph instance params back to the graph's default values. Actor MUST have a graph instance.\n\x09 *\n\x09 * @param PCGVolume - The actor to reset graph instance params for.\n\x09 * @param ParamNames - Names of the parameters to reset.\n\x09 * @return boolean representing success/failed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/PCGToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Resets the given graph instance params back to the graph's default values. Actor MUST have a graph instance.\n\n@param PCGVolume - The actor to reset graph instance params for.\n@param ParamNames - Names of the parameters to reset.\n@return boolean representing success/failed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PCGVolume_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ParamNames_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ResetGraphInstanceParams constinit property declarations **************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PCGVolume;
	static const UECodeGen_Private::FNamePropertyParams NewProp_ParamNames_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ParamNames;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ResetGraphInstanceParams constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ResetGraphInstanceParams Property Definitions *************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_ResetGraphInstanceParams_Statics::NewProp_PCGVolume = { "PCGVolume", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventResetGraphInstanceParams_Parms, PCGVolume), Z_Construct_UClass_APCGVolume_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PCGVolume_MetaData), NewProp_PCGVolume_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UPCGToolset_ResetGraphInstanceParams_Statics::NewProp_ParamNames_Inner = { "ParamNames", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPCGToolset_ResetGraphInstanceParams_Statics::NewProp_ParamNames = { "ParamNames", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventResetGraphInstanceParams_Parms, ParamNames), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ParamNames_MetaData), NewProp_ParamNames_MetaData) };
void Z_Construct_UFunction_UPCGToolset_ResetGraphInstanceParams_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PCGToolset_eventResetGraphInstanceParams_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPCGToolset_ResetGraphInstanceParams_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PCGToolset_eventResetGraphInstanceParams_Parms), &Z_Construct_UFunction_UPCGToolset_ResetGraphInstanceParams_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPCGToolset_ResetGraphInstanceParams_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_ResetGraphInstanceParams_Statics::NewProp_PCGVolume,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_ResetGraphInstanceParams_Statics::NewProp_ParamNames_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_ResetGraphInstanceParams_Statics::NewProp_ParamNames,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_ResetGraphInstanceParams_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_ResetGraphInstanceParams_Statics::PropPointers) < 2048);
// ********** End Function ResetGraphInstanceParams Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPCGToolset_ResetGraphInstanceParams_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPCGToolset, nullptr, "ResetGraphInstanceParams", 	Z_Construct_UFunction_UPCGToolset_ResetGraphInstanceParams_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_ResetGraphInstanceParams_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPCGToolset_ResetGraphInstanceParams_Statics::PCGToolset_eventResetGraphInstanceParams_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_ResetGraphInstanceParams_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPCGToolset_ResetGraphInstanceParams_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPCGToolset_ResetGraphInstanceParams_Statics::PCGToolset_eventResetGraphInstanceParams_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPCGToolset_ResetGraphInstanceParams()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPCGToolset_ResetGraphInstanceParams_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPCGToolset::execResetGraphInstanceParams)
{
	P_GET_OBJECT(APCGVolume,Z_Param_PCGVolume);
	P_GET_TARRAY_REF(FName,Z_Param_Out_ParamNames);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPCGToolset::ResetGraphInstanceParams(Z_Param_PCGVolume,Z_Param_Out_ParamNames);
	P_NATIVE_END;
}
// ********** End Class UPCGToolset Function ResetGraphInstanceParams ******************************

// ********** Begin Class UPCGToolset Function SetGraphDescription *********************************
struct Z_Construct_UFunction_UPCGToolset_SetGraphDescription_Statics
{
	struct PCGToolset_eventSetGraphDescription_Parms
	{
		UPCGGraph* Graph;
		FString Description;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PCG|GraphParams" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Set the description of a PCGGraph\n\x09 *\n\x09 * @param Graph - Graph to set description of.\n\x09 * @param Description - New description of graph\n\x09 * @return boolean representing success/failed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/PCGToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set the description of a PCGGraph\n\n@param Graph - Graph to set description of.\n@param Description - New description of graph\n@return boolean representing success/failed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetGraphDescription constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Graph;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Description;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetGraphDescription constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetGraphDescription Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_SetGraphDescription_Statics::NewProp_Graph = { "Graph", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventSetGraphDescription_Parms, Graph), Z_Construct_UClass_UPCGGraph_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_SetGraphDescription_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventSetGraphDescription_Parms, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
void Z_Construct_UFunction_UPCGToolset_SetGraphDescription_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PCGToolset_eventSetGraphDescription_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPCGToolset_SetGraphDescription_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PCGToolset_eventSetGraphDescription_Parms), &Z_Construct_UFunction_UPCGToolset_SetGraphDescription_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPCGToolset_SetGraphDescription_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_SetGraphDescription_Statics::NewProp_Graph,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_SetGraphDescription_Statics::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_SetGraphDescription_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_SetGraphDescription_Statics::PropPointers) < 2048);
// ********** End Function SetGraphDescription Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPCGToolset_SetGraphDescription_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPCGToolset, nullptr, "SetGraphDescription", 	Z_Construct_UFunction_UPCGToolset_SetGraphDescription_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_SetGraphDescription_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPCGToolset_SetGraphDescription_Statics::PCGToolset_eventSetGraphDescription_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_SetGraphDescription_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPCGToolset_SetGraphDescription_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPCGToolset_SetGraphDescription_Statics::PCGToolset_eventSetGraphDescription_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPCGToolset_SetGraphDescription()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPCGToolset_SetGraphDescription_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPCGToolset::execSetGraphDescription)
{
	P_GET_OBJECT(UPCGGraph,Z_Param_Graph);
	P_GET_PROPERTY(FStrProperty,Z_Param_Description);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPCGToolset::SetGraphDescription(Z_Param_Graph,Z_Param_Description);
	P_NATIVE_END;
}
// ********** End Class UPCGToolset Function SetGraphDescription ***********************************

// ********** Begin Class UPCGToolset Function SetGraphInstanceParams ******************************
struct Z_Construct_UFunction_UPCGToolset_SetGraphInstanceParams_Statics
{
	struct PCGToolset_eventSetGraphInstanceParams_Parms
	{
		const APCGVolume* PCGVolume;
		FString JsonParams;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PCG|GraphInstanceParams" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Sets the graph instance params of a specific actor, actor MUST have a graph instance\n\x09 *\n\x09 * @param PCGVolume - The actor to set graph instance params for\n\x09 * @param JsonParams - JSON string representing JsonObject for the params to set. MUST be in format: {{\"property_1_name\": \"property_1_value\"}, ...}\n\x09 * @return boolean representing success/failed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/PCGToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the graph instance params of a specific actor, actor MUST have a graph instance\n\n@param PCGVolume - The actor to set graph instance params for\n@param JsonParams - JSON string representing JsonObject for the params to set. MUST be in format: {{\"property_1_name\": \"property_1_value\"}, ...}\n@return boolean representing success/failed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PCGVolume_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonParams_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetGraphInstanceParams constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PCGVolume;
	static const UECodeGen_Private::FStrPropertyParams NewProp_JsonParams;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetGraphInstanceParams constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetGraphInstanceParams Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_SetGraphInstanceParams_Statics::NewProp_PCGVolume = { "PCGVolume", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventSetGraphInstanceParams_Parms, PCGVolume), Z_Construct_UClass_APCGVolume_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PCGVolume_MetaData), NewProp_PCGVolume_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_SetGraphInstanceParams_Statics::NewProp_JsonParams = { "JsonParams", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventSetGraphInstanceParams_Parms, JsonParams), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonParams_MetaData), NewProp_JsonParams_MetaData) };
void Z_Construct_UFunction_UPCGToolset_SetGraphInstanceParams_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PCGToolset_eventSetGraphInstanceParams_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPCGToolset_SetGraphInstanceParams_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PCGToolset_eventSetGraphInstanceParams_Parms), &Z_Construct_UFunction_UPCGToolset_SetGraphInstanceParams_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPCGToolset_SetGraphInstanceParams_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_SetGraphInstanceParams_Statics::NewProp_PCGVolume,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_SetGraphInstanceParams_Statics::NewProp_JsonParams,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_SetGraphInstanceParams_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_SetGraphInstanceParams_Statics::PropPointers) < 2048);
// ********** End Function SetGraphInstanceParams Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPCGToolset_SetGraphInstanceParams_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPCGToolset, nullptr, "SetGraphInstanceParams", 	Z_Construct_UFunction_UPCGToolset_SetGraphInstanceParams_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_SetGraphInstanceParams_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPCGToolset_SetGraphInstanceParams_Statics::PCGToolset_eventSetGraphInstanceParams_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_SetGraphInstanceParams_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPCGToolset_SetGraphInstanceParams_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPCGToolset_SetGraphInstanceParams_Statics::PCGToolset_eventSetGraphInstanceParams_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPCGToolset_SetGraphInstanceParams()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPCGToolset_SetGraphInstanceParams_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPCGToolset::execSetGraphInstanceParams)
{
	P_GET_OBJECT(APCGVolume,Z_Param_PCGVolume);
	P_GET_PROPERTY(FStrProperty,Z_Param_JsonParams);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPCGToolset::SetGraphInstanceParams(Z_Param_PCGVolume,Z_Param_JsonParams);
	P_NATIVE_END;
}
// ********** End Class UPCGToolset Function SetGraphInstanceParams ********************************

// ********** Begin Class UPCGToolset Function SetGraphParams **************************************
struct Z_Construct_UFunction_UPCGToolset_SetGraphParams_Statics
{
	struct PCGToolset_eventSetGraphParams_Parms
	{
		UPCGGraph* Graph;
		TArray<FPCGParamDefinition> Params;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PCG|GraphParams" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Adds one or more graph user parameters to a specific PCG graph, such that they will be overridable in per graph instance.\n\x09 *\n\x09 * @param Graph - Graph to add graph parameter to\n\x09 * @param Params - TArray<FPCGParamDefinition> An array of UStruct for Name, Type, Description, ContainerType (optional) and DefaultValueJson (optional). If user explicitly want special default values the DefaultValueJson MUST be set, otherwise OMIT DefaultValueJson for standard UE default values!\n\x09 * @return boolean representing success/failed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/PCGToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds one or more graph user parameters to a specific PCG graph, such that they will be overridable in per graph instance.\n\n@param Graph - Graph to add graph parameter to\n@param Params - TArray<FPCGParamDefinition> An array of UStruct for Name, Type, Description, ContainerType (optional) and DefaultValueJson (optional). If user explicitly want special default values the DefaultValueJson MUST be set, otherwise OMIT DefaultValueJson for standard UE default values!\n@return boolean representing success/failed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Params_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetGraphParams constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Graph;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Params_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Params;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetGraphParams constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetGraphParams Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_SetGraphParams_Statics::NewProp_Graph = { "Graph", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventSetGraphParams_Parms, Graph), Z_Construct_UClass_UPCGGraph_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPCGToolset_SetGraphParams_Statics::NewProp_Params_Inner = { "Params", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FPCGParamDefinition, METADATA_PARAMS(0, nullptr) }; // 2235050558
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPCGToolset_SetGraphParams_Statics::NewProp_Params = { "Params", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventSetGraphParams_Parms, Params), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Params_MetaData), NewProp_Params_MetaData) }; // 2235050558
void Z_Construct_UFunction_UPCGToolset_SetGraphParams_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PCGToolset_eventSetGraphParams_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPCGToolset_SetGraphParams_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PCGToolset_eventSetGraphParams_Parms), &Z_Construct_UFunction_UPCGToolset_SetGraphParams_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPCGToolset_SetGraphParams_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_SetGraphParams_Statics::NewProp_Graph,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_SetGraphParams_Statics::NewProp_Params_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_SetGraphParams_Statics::NewProp_Params,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_SetGraphParams_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_SetGraphParams_Statics::PropPointers) < 2048);
// ********** End Function SetGraphParams Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPCGToolset_SetGraphParams_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPCGToolset, nullptr, "SetGraphParams", 	Z_Construct_UFunction_UPCGToolset_SetGraphParams_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_SetGraphParams_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPCGToolset_SetGraphParams_Statics::PCGToolset_eventSetGraphParams_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_SetGraphParams_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPCGToolset_SetGraphParams_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPCGToolset_SetGraphParams_Statics::PCGToolset_eventSetGraphParams_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPCGToolset_SetGraphParams()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPCGToolset_SetGraphParams_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPCGToolset::execSetGraphParams)
{
	P_GET_OBJECT(UPCGGraph,Z_Param_Graph);
	P_GET_TARRAY_REF(FPCGParamDefinition,Z_Param_Out_Params);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPCGToolset::SetGraphParams(Z_Param_Graph,Z_Param_Out_Params);
	P_NATIVE_END;
}
// ********** End Class UPCGToolset Function SetGraphParams ****************************************

// ********** Begin Class UPCGToolset Function SetNodeComment **************************************
struct Z_Construct_UFunction_UPCGToolset_SetNodeComment_Statics
{
	struct PCGToolset_eventSetNodeComment_Parms
	{
		UPCGNode* Node;
		FString NodeComment;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PCG|Nodes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Change the comment on the specified node.\n\x09 *\n\x09 * @param Node - The node to set the comment on. \n\x09 * @param NodeComment - The comment attached to the node.\n\x09 * @return boolean representing success/failed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/PCGToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Change the comment on the specified node.\n\n@param Node - The node to set the comment on.\n@param NodeComment - The comment attached to the node.\n@return boolean representing success/failed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NodeComment_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetNodeComment constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Node;
	static const UECodeGen_Private::FStrPropertyParams NewProp_NodeComment;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetNodeComment constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetNodeComment Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_SetNodeComment_Statics::NewProp_Node = { "Node", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventSetNodeComment_Parms, Node), Z_Construct_UClass_UPCGNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_SetNodeComment_Statics::NewProp_NodeComment = { "NodeComment", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventSetNodeComment_Parms, NodeComment), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NodeComment_MetaData), NewProp_NodeComment_MetaData) };
void Z_Construct_UFunction_UPCGToolset_SetNodeComment_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PCGToolset_eventSetNodeComment_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPCGToolset_SetNodeComment_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PCGToolset_eventSetNodeComment_Parms), &Z_Construct_UFunction_UPCGToolset_SetNodeComment_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPCGToolset_SetNodeComment_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_SetNodeComment_Statics::NewProp_Node,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_SetNodeComment_Statics::NewProp_NodeComment,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_SetNodeComment_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_SetNodeComment_Statics::PropPointers) < 2048);
// ********** End Function SetNodeComment Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPCGToolset_SetNodeComment_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPCGToolset, nullptr, "SetNodeComment", 	Z_Construct_UFunction_UPCGToolset_SetNodeComment_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_SetNodeComment_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPCGToolset_SetNodeComment_Statics::PCGToolset_eventSetNodeComment_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_SetNodeComment_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPCGToolset_SetNodeComment_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPCGToolset_SetNodeComment_Statics::PCGToolset_eventSetNodeComment_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPCGToolset_SetNodeComment()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPCGToolset_SetNodeComment_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPCGToolset::execSetNodeComment)
{
	P_GET_OBJECT(UPCGNode,Z_Param_Node);
	P_GET_PROPERTY(FStrProperty,Z_Param_NodeComment);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPCGToolset::SetNodeComment(Z_Param_Node,Z_Param_NodeComment);
	P_NATIVE_END;
}
// ********** End Class UPCGToolset Function SetNodeComment ****************************************

// ********** Begin Class UPCGToolset Function SpawnGraphInstance **********************************
struct Z_Construct_UFunction_UPCGToolset_SpawnGraphInstance_Statics
{
	struct PCGToolset_eventSpawnGraphInstance_Parms
	{
		UPCGGraph* Graph;
		FString Name;
		FTransform Transform;
		FString JsonParams;
		FPCGGraphInstanceInfo ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PCG|GraphInstance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Spawns a PCG Volume with associated Graph Instance into the scene, optionally with Graph Param overrides.\n\x09*\n\x09* @param Graph - The PCG graph to spawn an instance of\n\x09* @param Name - The name of the PCGVolume actor to spawn in the scene.\n\x09* @param Transform - The transform to use for the new PCGVolume actor. Place at the origin unless there is a reason not to and use default scale3D of {\"x\": 25,\"y\": 25,\"z\": 10}\n\x09* @param JsonParams - (Optional) JSON string representing JsonObject for the params to set. MUST be in format: {{\"property_1_name\": \"property_1_value\"}, ...}\n\x09*\x09The default values for the graph params will be used if not set.\n\x09* @return UStruct with information of the created actor and the corresponding graph instance\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Public/PCGToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Spawns a PCG Volume with associated Graph Instance into the scene, optionally with Graph Param overrides.\n\n@param Graph - The PCG graph to spawn an instance of\n@param Name - The name of the PCGVolume actor to spawn in the scene.\n@param Transform - The transform to use for the new PCGVolume actor. Place at the origin unless there is a reason not to and use default scale3D of {\"x\": 25,\"y\": 25,\"z\": 10}\n@param JsonParams - (Optional) JSON string representing JsonObject for the params to set. MUST be in format: {{\"property_1_name\": \"property_1_value\"}, ...}\n      The default values for the graph params will be used if not set.\n@return UStruct with information of the created actor and the corresponding graph instance" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Transform_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonParams_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SpawnGraphInstance constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Graph;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Transform;
	static const UECodeGen_Private::FStrPropertyParams NewProp_JsonParams;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SpawnGraphInstance constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SpawnGraphInstance Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_SpawnGraphInstance_Statics::NewProp_Graph = { "Graph", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventSpawnGraphInstance_Parms, Graph), Z_Construct_UClass_UPCGGraph_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_SpawnGraphInstance_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventSpawnGraphInstance_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPCGToolset_SpawnGraphInstance_Statics::NewProp_Transform = { "Transform", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventSpawnGraphInstance_Parms, Transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Transform_MetaData), NewProp_Transform_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_SpawnGraphInstance_Statics::NewProp_JsonParams = { "JsonParams", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventSpawnGraphInstance_Parms, JsonParams), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonParams_MetaData), NewProp_JsonParams_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPCGToolset_SpawnGraphInstance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventSpawnGraphInstance_Parms, ReturnValue), Z_Construct_UScriptStruct_FPCGGraphInstanceInfo, METADATA_PARAMS(0, nullptr) }; // 313673020
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPCGToolset_SpawnGraphInstance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_SpawnGraphInstance_Statics::NewProp_Graph,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_SpawnGraphInstance_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_SpawnGraphInstance_Statics::NewProp_Transform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_SpawnGraphInstance_Statics::NewProp_JsonParams,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_SpawnGraphInstance_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_SpawnGraphInstance_Statics::PropPointers) < 2048);
// ********** End Function SpawnGraphInstance Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPCGToolset_SpawnGraphInstance_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPCGToolset, nullptr, "SpawnGraphInstance", 	Z_Construct_UFunction_UPCGToolset_SpawnGraphInstance_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_SpawnGraphInstance_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPCGToolset_SpawnGraphInstance_Statics::PCGToolset_eventSpawnGraphInstance_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_SpawnGraphInstance_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPCGToolset_SpawnGraphInstance_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPCGToolset_SpawnGraphInstance_Statics::PCGToolset_eventSpawnGraphInstance_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPCGToolset_SpawnGraphInstance()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPCGToolset_SpawnGraphInstance_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPCGToolset::execSpawnGraphInstance)
{
	P_GET_OBJECT(UPCGGraph,Z_Param_Graph);
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_STRUCT_REF(FTransform,Z_Param_Out_Transform);
	P_GET_PROPERTY(FStrProperty,Z_Param_JsonParams);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FPCGGraphInstanceInfo*)Z_Param__Result=UPCGToolset::SpawnGraphInstance(Z_Param_Graph,Z_Param_Name,Z_Param_Out_Transform,Z_Param_JsonParams);
	P_NATIVE_END;
}
// ********** End Class UPCGToolset Function SpawnGraphInstance ************************************

// ********** Begin Class UPCGToolset Function UpdateCommentBox ************************************
struct Z_Construct_UFunction_UPCGToolset_UpdateCommentBox_Statics
{
	struct PCGToolset_eventUpdateCommentBox_Parms
	{
		UPCGGraph* Graph;
		FString CommentId;
		TArray<UPCGNode*> Nodes;
		FString Comment;
		FLinearColor Color;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PCG|CommentBox" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Updates an existing comment box with new nodes and value. \n\x09 *  Note: If the bounding box of the nodes include other nodes, they will be included in the comment.\n\x09 *\n\x09 * @param Graph - Graph to add comment to.\n\x09 * @param CommentId - The unique id of the comment to update.\n\x09 * @param Nodes - The list of nodes to include in the comment box. If empty, the box will keep its current dimensions.\n\x09 * @param Comment - The new comment to put on the comment box. If empty, will keep the same text as it was. Default is empty.\n\x09 * @param Color - The color of the comment box. Defaults to White\n\x09 * @return boolean representing success/failed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/PCGToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Updates an existing comment box with new nodes and value.\n Note: If the bounding box of the nodes include other nodes, they will be included in the comment.\n\n@param Graph - Graph to add comment to.\n@param CommentId - The unique id of the comment to update.\n@param Nodes - The list of nodes to include in the comment box. If empty, the box will keep its current dimensions.\n@param Comment - The new comment to put on the comment box. If empty, will keep the same text as it was. Default is empty.\n@param Color - The color of the comment box. Defaults to White\n@return boolean representing success/failed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CommentId_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Nodes_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Comment_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function UpdateCommentBox constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Graph;
	static const UECodeGen_Private::FStrPropertyParams NewProp_CommentId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Nodes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Nodes;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Comment;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Color;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UpdateCommentBox constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UpdateCommentBox Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_UpdateCommentBox_Statics::NewProp_Graph = { "Graph", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventUpdateCommentBox_Parms, Graph), Z_Construct_UClass_UPCGGraph_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_UpdateCommentBox_Statics::NewProp_CommentId = { "CommentId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventUpdateCommentBox_Parms, CommentId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CommentId_MetaData), NewProp_CommentId_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_UpdateCommentBox_Statics::NewProp_Nodes_Inner = { "Nodes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UPCGNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPCGToolset_UpdateCommentBox_Statics::NewProp_Nodes = { "Nodes", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventUpdateCommentBox_Parms, Nodes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Nodes_MetaData), NewProp_Nodes_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_UpdateCommentBox_Statics::NewProp_Comment = { "Comment", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventUpdateCommentBox_Parms, Comment), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Comment_MetaData), NewProp_Comment_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPCGToolset_UpdateCommentBox_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventUpdateCommentBox_Parms, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPCGToolset_UpdateCommentBox_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PCGToolset_eventUpdateCommentBox_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPCGToolset_UpdateCommentBox_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PCGToolset_eventUpdateCommentBox_Parms), &Z_Construct_UFunction_UPCGToolset_UpdateCommentBox_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPCGToolset_UpdateCommentBox_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_UpdateCommentBox_Statics::NewProp_Graph,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_UpdateCommentBox_Statics::NewProp_CommentId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_UpdateCommentBox_Statics::NewProp_Nodes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_UpdateCommentBox_Statics::NewProp_Nodes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_UpdateCommentBox_Statics::NewProp_Comment,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_UpdateCommentBox_Statics::NewProp_Color,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_UpdateCommentBox_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_UpdateCommentBox_Statics::PropPointers) < 2048);
// ********** End Function UpdateCommentBox Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPCGToolset_UpdateCommentBox_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPCGToolset, nullptr, "UpdateCommentBox", 	Z_Construct_UFunction_UPCGToolset_UpdateCommentBox_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_UpdateCommentBox_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPCGToolset_UpdateCommentBox_Statics::PCGToolset_eventUpdateCommentBox_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_UpdateCommentBox_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPCGToolset_UpdateCommentBox_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPCGToolset_UpdateCommentBox_Statics::PCGToolset_eventUpdateCommentBox_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPCGToolset_UpdateCommentBox()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPCGToolset_UpdateCommentBox_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPCGToolset::execUpdateCommentBox)
{
	P_GET_OBJECT(UPCGGraph,Z_Param_Graph);
	P_GET_PROPERTY(FStrProperty,Z_Param_CommentId);
	P_GET_TARRAY_REF(UPCGNode*,Z_Param_Out_Nodes);
	P_GET_PROPERTY(FStrProperty,Z_Param_Comment);
	P_GET_STRUCT(FLinearColor,Z_Param_Color);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPCGToolset::UpdateCommentBox(Z_Param_Graph,Z_Param_CommentId,Z_Param_Out_Nodes,Z_Param_Comment,Z_Param_Color);
	P_NATIVE_END;
}
// ********** End Class UPCGToolset Function UpdateCommentBox **************************************

// ********** Begin Class UPCGToolset Function UpdateNode ******************************************
struct Z_Construct_UFunction_UPCGToolset_UpdateNode_Statics
{
	struct PCGToolset_eventUpdateNode_Parms
	{
		UPCGNode* Node;
		FString JsonParams;
		FString NodeTitle;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AICallable", "" },
		{ "Category", "PCG|Nodes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Updates a node by changing its params and/or title.\n\x09 *\n\x09 * @param Node - The node to modify.\n\x09 * @param JsonParams - The Json string representing a dictionary of the params to override. Optional. Default is empty. Only non-default params need be included\n\x09 * @param NodeTitle - The Display Title of the node. Optional. Default is empty. Empty will keep the old title\n\x09 * @return boolean representing success/failed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/PCGToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Updates a node by changing its params and/or title.\n\n@param Node - The node to modify.\n@param JsonParams - The Json string representing a dictionary of the params to override. Optional. Default is empty. Only non-default params need be included\n@param NodeTitle - The Display Title of the node. Optional. Default is empty. Empty will keep the old title\n@return boolean representing success/failed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonParams_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NodeTitle_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function UpdateNode constinit property declarations ****************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Node;
	static const UECodeGen_Private::FStrPropertyParams NewProp_JsonParams;
	static const UECodeGen_Private::FStrPropertyParams NewProp_NodeTitle;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UpdateNode constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UpdateNode Property Definitions ***************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPCGToolset_UpdateNode_Statics::NewProp_Node = { "Node", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventUpdateNode_Parms, Node), Z_Construct_UClass_UPCGNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_UpdateNode_Statics::NewProp_JsonParams = { "JsonParams", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventUpdateNode_Parms, JsonParams), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonParams_MetaData), NewProp_JsonParams_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPCGToolset_UpdateNode_Statics::NewProp_NodeTitle = { "NodeTitle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PCGToolset_eventUpdateNode_Parms, NodeTitle), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NodeTitle_MetaData), NewProp_NodeTitle_MetaData) };
void Z_Construct_UFunction_UPCGToolset_UpdateNode_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PCGToolset_eventUpdateNode_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPCGToolset_UpdateNode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PCGToolset_eventUpdateNode_Parms), &Z_Construct_UFunction_UPCGToolset_UpdateNode_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPCGToolset_UpdateNode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_UpdateNode_Statics::NewProp_Node,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_UpdateNode_Statics::NewProp_JsonParams,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_UpdateNode_Statics::NewProp_NodeTitle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPCGToolset_UpdateNode_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_UpdateNode_Statics::PropPointers) < 2048);
// ********** End Function UpdateNode Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPCGToolset_UpdateNode_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPCGToolset, nullptr, "UpdateNode", 	Z_Construct_UFunction_UPCGToolset_UpdateNode_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_UpdateNode_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPCGToolset_UpdateNode_Statics::PCGToolset_eventUpdateNode_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPCGToolset_UpdateNode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPCGToolset_UpdateNode_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPCGToolset_UpdateNode_Statics::PCGToolset_eventUpdateNode_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPCGToolset_UpdateNode()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPCGToolset_UpdateNode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPCGToolset::execUpdateNode)
{
	P_GET_OBJECT(UPCGNode,Z_Param_Node);
	P_GET_PROPERTY(FStrProperty,Z_Param_JsonParams);
	P_GET_PROPERTY(FStrProperty,Z_Param_NodeTitle);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPCGToolset::UpdateNode(Z_Param_Node,Z_Param_JsonParams,Z_Param_NodeTitle);
	P_NATIVE_END;
}
// ********** End Class UPCGToolset Function UpdateNode ********************************************

// ********** Begin Class UPCGToolset **************************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UPCGToolset;
UClass* UPCGToolset::GetPrivateStaticClass()
{
	using TClass = UPCGToolset;
	if (!Z_Registration_Info_UClass_UPCGToolset.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("PCGToolset"),
			Z_Registration_Info_UClass_UPCGToolset.InnerSingleton,
			StaticRegisterNativesUPCGToolset,
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
	return Z_Registration_Info_UClass_UPCGToolset.InnerSingleton;
}
UClass* Z_Construct_UClass_UPCGToolset_NoRegister()
{
	return UPCGToolset::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPCGToolset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Toolset for building and modifying PCG graphs\n */" },
#endif
		{ "IncludePath", "PCGToolset.h" },
		{ "ModuleRelativePath", "Public/PCGToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Toolset for building and modifying PCG graphs" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UPCGToolset constinit property declarations ******************************
// ********** End Class UPCGToolset constinit property declarations ********************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AddCommentBox"), .Pointer = &UPCGToolset::execAddCommentBox },
		{ .NameUTF8 = UTF8TEXT("AddNode"), .Pointer = &UPCGToolset::execAddNode },
		{ .NameUTF8 = UTF8TEXT("AddSubgraphNode"), .Pointer = &UPCGToolset::execAddSubgraphNode },
		{ .NameUTF8 = UTF8TEXT("ConnectNodePins"), .Pointer = &UPCGToolset::execConnectNodePins },
		{ .NameUTF8 = UTF8TEXT("CreateGraph"), .Pointer = &UPCGToolset::execCreateGraph },
		{ .NameUTF8 = UTF8TEXT("DisconnectNodePins"), .Pointer = &UPCGToolset::execDisconnectNodePins },
		{ .NameUTF8 = UTF8TEXT("DrawSpline"), .Pointer = &UPCGToolset::execDrawSpline },
		{ .NameUTF8 = UTF8TEXT("ExecuteGraphInstance"), .Pointer = &UPCGToolset::execExecuteGraphInstance },
		{ .NameUTF8 = UTF8TEXT("GetGraphDescription"), .Pointer = &UPCGToolset::execGetGraphDescription },
		{ .NameUTF8 = UTF8TEXT("GetGraphInstanceParams"), .Pointer = &UPCGToolset::execGetGraphInstanceParams },
		{ .NameUTF8 = UTF8TEXT("GetGraphSchema"), .Pointer = &UPCGToolset::execGetGraphSchema },
		{ .NameUTF8 = UTF8TEXT("GetGraphStructure"), .Pointer = &UPCGToolset::execGetGraphStructure },
		{ .NameUTF8 = UTF8TEXT("GetNativeNodeSchema"), .Pointer = &UPCGToolset::execGetNativeNodeSchema },
		{ .NameUTF8 = UTF8TEXT("GetNodeDataView"), .Pointer = &UPCGToolset::execGetNodeDataView },
		{ .NameUTF8 = UTF8TEXT("GetNodeInfo"), .Pointer = &UPCGToolset::execGetNodeInfo },
		{ .NameUTF8 = UTF8TEXT("ListAvailableSubgraphs"), .Pointer = &UPCGToolset::execListAvailableSubgraphs },
		{ .NameUTF8 = UTF8TEXT("ListGraphInstances"), .Pointer = &UPCGToolset::execListGraphInstances },
		{ .NameUTF8 = UTF8TEXT("ListNativeNodes"), .Pointer = &UPCGToolset::execListNativeNodes },
		{ .NameUTF8 = UTF8TEXT("RemoveCommentBox"), .Pointer = &UPCGToolset::execRemoveCommentBox },
		{ .NameUTF8 = UTF8TEXT("RemoveGraphParams"), .Pointer = &UPCGToolset::execRemoveGraphParams },
		{ .NameUTF8 = UTF8TEXT("RemoveNode"), .Pointer = &UPCGToolset::execRemoveNode },
		{ .NameUTF8 = UTF8TEXT("RepositionNode"), .Pointer = &UPCGToolset::execRepositionNode },
		{ .NameUTF8 = UTF8TEXT("ResetGraphInstanceParams"), .Pointer = &UPCGToolset::execResetGraphInstanceParams },
		{ .NameUTF8 = UTF8TEXT("SetGraphDescription"), .Pointer = &UPCGToolset::execSetGraphDescription },
		{ .NameUTF8 = UTF8TEXT("SetGraphInstanceParams"), .Pointer = &UPCGToolset::execSetGraphInstanceParams },
		{ .NameUTF8 = UTF8TEXT("SetGraphParams"), .Pointer = &UPCGToolset::execSetGraphParams },
		{ .NameUTF8 = UTF8TEXT("SetNodeComment"), .Pointer = &UPCGToolset::execSetNodeComment },
		{ .NameUTF8 = UTF8TEXT("SpawnGraphInstance"), .Pointer = &UPCGToolset::execSpawnGraphInstance },
		{ .NameUTF8 = UTF8TEXT("UpdateCommentBox"), .Pointer = &UPCGToolset::execUpdateCommentBox },
		{ .NameUTF8 = UTF8TEXT("UpdateNode"), .Pointer = &UPCGToolset::execUpdateNode },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UPCGToolset_AddCommentBox, "AddCommentBox" }, // 3391059434
		{ &Z_Construct_UFunction_UPCGToolset_AddNode, "AddNode" }, // 2929968936
		{ &Z_Construct_UFunction_UPCGToolset_AddSubgraphNode, "AddSubgraphNode" }, // 1280222846
		{ &Z_Construct_UFunction_UPCGToolset_ConnectNodePins, "ConnectNodePins" }, // 3637706933
		{ &Z_Construct_UFunction_UPCGToolset_CreateGraph, "CreateGraph" }, // 4228004369
		{ &Z_Construct_UFunction_UPCGToolset_DisconnectNodePins, "DisconnectNodePins" }, // 3670909863
		{ &Z_Construct_UFunction_UPCGToolset_DrawSpline, "DrawSpline" }, // 723934332
		{ &Z_Construct_UFunction_UPCGToolset_ExecuteGraphInstance, "ExecuteGraphInstance" }, // 2830860839
		{ &Z_Construct_UFunction_UPCGToolset_GetGraphDescription, "GetGraphDescription" }, // 1063209516
		{ &Z_Construct_UFunction_UPCGToolset_GetGraphInstanceParams, "GetGraphInstanceParams" }, // 1386787227
		{ &Z_Construct_UFunction_UPCGToolset_GetGraphSchema, "GetGraphSchema" }, // 829942730
		{ &Z_Construct_UFunction_UPCGToolset_GetGraphStructure, "GetGraphStructure" }, // 3846468401
		{ &Z_Construct_UFunction_UPCGToolset_GetNativeNodeSchema, "GetNativeNodeSchema" }, // 3059457335
		{ &Z_Construct_UFunction_UPCGToolset_GetNodeDataView, "GetNodeDataView" }, // 1369481951
		{ &Z_Construct_UFunction_UPCGToolset_GetNodeInfo, "GetNodeInfo" }, // 2260832989
		{ &Z_Construct_UFunction_UPCGToolset_ListAvailableSubgraphs, "ListAvailableSubgraphs" }, // 149162538
		{ &Z_Construct_UFunction_UPCGToolset_ListGraphInstances, "ListGraphInstances" }, // 637639015
		{ &Z_Construct_UFunction_UPCGToolset_ListNativeNodes, "ListNativeNodes" }, // 1820411105
		{ &Z_Construct_UFunction_UPCGToolset_RemoveCommentBox, "RemoveCommentBox" }, // 795613411
		{ &Z_Construct_UFunction_UPCGToolset_RemoveGraphParams, "RemoveGraphParams" }, // 3105769668
		{ &Z_Construct_UFunction_UPCGToolset_RemoveNode, "RemoveNode" }, // 4227317984
		{ &Z_Construct_UFunction_UPCGToolset_RepositionNode, "RepositionNode" }, // 1734645162
		{ &Z_Construct_UFunction_UPCGToolset_ResetGraphInstanceParams, "ResetGraphInstanceParams" }, // 2644344747
		{ &Z_Construct_UFunction_UPCGToolset_SetGraphDescription, "SetGraphDescription" }, // 3622750564
		{ &Z_Construct_UFunction_UPCGToolset_SetGraphInstanceParams, "SetGraphInstanceParams" }, // 2717746227
		{ &Z_Construct_UFunction_UPCGToolset_SetGraphParams, "SetGraphParams" }, // 1805632404
		{ &Z_Construct_UFunction_UPCGToolset_SetNodeComment, "SetNodeComment" }, // 212819158
		{ &Z_Construct_UFunction_UPCGToolset_SpawnGraphInstance, "SpawnGraphInstance" }, // 776777200
		{ &Z_Construct_UFunction_UPCGToolset_UpdateCommentBox, "UpdateCommentBox" }, // 2652869534
		{ &Z_Construct_UFunction_UPCGToolset_UpdateNode, "UpdateNode" }, // 2894551194
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPCGToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UPCGToolset_Statics
UObject* (*const Z_Construct_UClass_UPCGToolset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UToolsetDefinition,
	(UObject* (*)())Z_Construct_UPackage__Script_PCGToolset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPCGToolset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPCGToolset_Statics::ClassParams = {
	&UPCGToolset::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPCGToolset_Statics::Class_MetaDataParams), Z_Construct_UClass_UPCGToolset_Statics::Class_MetaDataParams)
};
void UPCGToolset::StaticRegisterNativesUPCGToolset()
{
	UClass* Class = UPCGToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UPCGToolset_Statics::Funcs));
}
UClass* Z_Construct_UClass_UPCGToolset()
{
	if (!Z_Registration_Info_UClass_UPCGToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPCGToolset.OuterSingleton, Z_Construct_UClass_UPCGToolset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPCGToolset.OuterSingleton;
}
UPCGToolset::UPCGToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UPCGToolset);
UPCGToolset::~UPCGToolset() {}
// ********** End Class UPCGToolset ****************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolset_h__Script_PCGToolset_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPCGToolset, UPCGToolset::StaticClass, TEXT("UPCGToolset"), &Z_Registration_Info_UClass_UPCGToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPCGToolset), 1144592613U) },
	};
}; // Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolset_h__Script_PCGToolset_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolset_h__Script_PCGToolset_1628791521{
	TEXT("/Script/PCGToolset"),
	Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolset_h__Script_PCGToolset_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_MCP_Plugins_Toolsets_PCGToolset_Source_PCGToolset_Public_PCGToolset_h__Script_PCGToolset_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
