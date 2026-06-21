// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "EditorAppToolset.h"

#ifdef EDITORTOOLSET_EditorAppToolset_generated_h
#error "EditorAppToolset.generated.h already included, missing '#pragma once' in EditorAppToolset.h"
#endif
#define EDITORTOOLSET_EditorAppToolset_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UToolCallAsyncResultImage;
class UToolCallAsyncResultVoid;
struct FPIESessionOptions;
struct FToolsetImage;
struct FViewportAnnotationConfig;
struct FViewportCapture;

// ********** Begin ScriptStruct FPIESessionOptions ************************************************
struct Z_Construct_UScriptStruct_FPIESessionOptions_Statics;
#define FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_EditorAppToolset_h_29_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FPIESessionOptions_Statics; \
	EDITORTOOLSET_API static class UScriptStruct* StaticStruct();


struct FPIESessionOptions;
// ********** End ScriptStruct FPIESessionOptions **************************************************

// ********** Begin ScriptStruct FViewportLabel ****************************************************
struct Z_Construct_UScriptStruct_FViewportLabel_Statics;
#define FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_EditorAppToolset_h_79_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FViewportLabel_Statics; \
	EDITORTOOLSET_API static class UScriptStruct* StaticStruct();


struct FViewportLabel;
// ********** End ScriptStruct FViewportLabel ******************************************************

// ********** Begin ScriptStruct FViewportGrid *****************************************************
struct Z_Construct_UScriptStruct_FViewportGrid_Statics;
#define FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_EditorAppToolset_h_110_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FViewportGrid_Statics; \
	EDITORTOOLSET_API static class UScriptStruct* StaticStruct();


struct FViewportGrid;
// ********** End ScriptStruct FViewportGrid *******************************************************

// ********** Begin ScriptStruct FViewportAnnotationConfig *****************************************
struct Z_Construct_UScriptStruct_FViewportAnnotationConfig_Statics;
#define FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_EditorAppToolset_h_131_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FViewportAnnotationConfig_Statics; \
	EDITORTOOLSET_API static class UScriptStruct* StaticStruct();


struct FViewportAnnotationConfig;
// ********** End ScriptStruct FViewportAnnotationConfig *******************************************

// ********** Begin ScriptStruct FViewportCapture **************************************************
struct Z_Construct_UScriptStruct_FViewportCapture_Statics;
#define FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_EditorAppToolset_h_166_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FViewportCapture_Statics; \
	EDITORTOOLSET_API static class UScriptStruct* StaticStruct();


struct FViewportCapture;
// ********** End ScriptStruct FViewportCapture ****************************************************

// ********** Begin Class UEditorAppToolset ********************************************************
#define FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_EditorAppToolset_h_199_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execIsPIERunning); \
	DECLARE_FUNCTION(execStopPIE); \
	DECLARE_FUNCTION(execStartPIE); \
	DECLARE_FUNCTION(execGetOpenAssets); \
	DECLARE_FUNCTION(execOpenEditorForAsset); \
	DECLARE_FUNCTION(execSetContentBrowserPath); \
	DECLARE_FUNCTION(execGetContentBrowserPath); \
	DECLARE_FUNCTION(execSelectAssets); \
	DECLARE_FUNCTION(execGetSelectedAssets); \
	DECLARE_FUNCTION(execScreenCoordsToWorld); \
	DECLARE_FUNCTION(execWorldPosToScreenCoords); \
	DECLARE_FUNCTION(execGetVisibleActors); \
	DECLARE_FUNCTION(execFocusOnActors); \
	DECLARE_FUNCTION(execSetCameraTransform); \
	DECLARE_FUNCTION(execGetCameraTransform); \
	DECLARE_FUNCTION(execSelectActors); \
	DECLARE_FUNCTION(execGetSelectedActors); \
	DECLARE_FUNCTION(execCaptureViewport); \
	DECLARE_FUNCTION(execCaptureEditorImage); \
	DECLARE_FUNCTION(execCaptureAssetImage); \
	DECLARE_FUNCTION(execSearchCVars);


struct Z_Construct_UClass_UEditorAppToolset_Statics;
EDITORTOOLSET_API UClass* Z_Construct_UClass_UEditorAppToolset_NoRegister();

#define FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_EditorAppToolset_h_199_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEditorAppToolset(); \
	friend struct ::Z_Construct_UClass_UEditorAppToolset_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend EDITORTOOLSET_API UClass* ::Z_Construct_UClass_UEditorAppToolset_NoRegister(); \
public: \
	DECLARE_CLASS2(UEditorAppToolset, UToolsetDefinition, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/EditorToolset"), Z_Construct_UClass_UEditorAppToolset_NoRegister) \
	DECLARE_SERIALIZER(UEditorAppToolset)


#define FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_EditorAppToolset_h_199_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	EDITORTOOLSET_API UEditorAppToolset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEditorAppToolset(UEditorAppToolset&&) = delete; \
	UEditorAppToolset(const UEditorAppToolset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(EDITORTOOLSET_API, UEditorAppToolset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEditorAppToolset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEditorAppToolset) \
	EDITORTOOLSET_API virtual ~UEditorAppToolset();


#define FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_EditorAppToolset_h_196_PROLOG
#define FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_EditorAppToolset_h_199_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_EditorAppToolset_h_199_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_EditorAppToolset_h_199_INCLASS_NO_PURE_DECLS \
	FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_EditorAppToolset_h_199_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEditorAppToolset;

// ********** End Class UEditorAppToolset **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_MCP_Plugins_Toolsets_EditorToolset_Source_EditorToolset_Private_EditorAppToolset_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
