// Copyright Epic Games, Inc. All Rights Reserved.
//
// [5.7 port] EditorToolsetCompatLibrary: thin C++ UFUNCTION entry points that let
// the 5.7 Python EditorToolset drive engine functionality that is *not reflected to
// Python on 5.7* and so cannot be reached via the native `unreal.*` API that the
// 5.8 toolset expects. Three families of types are involved:
//
//   * unreal.StringTable      - UStringTable is UCLASS(MinimalAPI) with no BlueprintType
//                               and is not referenced by any BlueprintCallable signature
//                               on 5.7, so PythonScriptPlugin never exposes it. The 5.8
//                               StringTableLibrary helpers (get_table_id /
//                               import_table_from_csv_*) also do not exist on 5.7.
//   * unreal.SimpleCurveKey   - FSimpleCurveKey is USTRUCT() without BlueprintType and is
//                               not referenced by any reflected signature on 5.7, so it is
//                               not exposed. The 5.8 DataTableFunctionLibrary curve-editing
//                               helpers (add_simple_curve_to_table, add_curve_table_key,
//                               get_curve_table_keys, ...) also do not exist on 5.7.
//                               (unreal.CurveTable itself *is* exposed on 5.7 via
//                                EvaluateCurveTableRow, so it is still used in the Python.)
//   * unreal.K2Node_CreateDelegate - UCLASS(MinimalAPI) with no BlueprintType, not in any
//                               reflected signature on 5.7, so it is not exposed. The 5.8
//                               BlueprintEditorLibrary delegate helpers
//                               (get/set_create_delegate_function,
//                                list_compatible_functions_for_delegate) do not exist on 5.7.
//
// Every method below takes only primitives / already-exposed UObject types (UObject*,
// UEdGraphNode*) so 5.7 Python can call them. Behaviour mirrors the 5.8 native paths.
//
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "EditorToolsetCompatLibrary.generated.h"

class UObject;
class UEdGraphNode;

UCLASS()
class UEditorToolsetCompatLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// ---- Asset creation -------------------------------------------------------
	// [5.7 port] unreal.StringTable / unreal.CurveTable (and their factories) are
	// not all reflected on 5.7, so the Python create() helpers cannot reference
	// unreal.StringTable.static_class() / unreal.StringTableFactory. These create
	// the asset natively (package + NewObject + registration) and return it as a
	// plain UObject*. CurveTable assets are created in simple-curve (linear) mode.

	/** Creates a StringTable asset at PackagePath/AssetName. Returns the asset or nullptr. */
	UFUNCTION(BlueprintCallable, Category = "Editor Toolset Compat|StringTable")
	static UObject* CreateStringTableAsset(const FString& PackagePath, const FString& AssetName);

	/** Creates a (simple/linear) CurveTable asset at PackagePath/AssetName. Returns the asset or nullptr. */
	UFUNCTION(BlueprintCallable, Category = "Editor Toolset Compat|CurveTable")
	static UObject* CreateCurveTableAsset(const FString& PackagePath, const FString& AssetName);

	// ---- StringTable ----------------------------------------------------------

	/** Returns the string table ID for a StringTable asset (UStringTable::GetStringTableId). */
	UFUNCTION(BlueprintCallable, Category = "Editor Toolset Compat|StringTable")
	static FString StringTableGetId(UObject* StringTable);

	/** Returns the namespace of a StringTable asset. */
	UFUNCTION(BlueprintCallable, Category = "Editor Toolset Compat|StringTable")
	static FString StringTableGetNamespace(UObject* StringTable);

	/** Returns all entry keys in the StringTable asset. */
	UFUNCTION(BlueprintCallable, Category = "Editor Toolset Compat|StringTable")
	static TArray<FString> StringTableListKeys(UObject* StringTable);

	/** Returns the source string for the given key, or empty string if absent. */
	UFUNCTION(BlueprintCallable, Category = "Editor Toolset Compat|StringTable")
	static FString StringTableGetEntry(UObject* StringTable, const FString& Key);

	/** Returns true if the StringTable contains the given key. */
	UFUNCTION(BlueprintCallable, Category = "Editor Toolset Compat|StringTable")
	static bool StringTableHasEntry(UObject* StringTable, const FString& Key);

	/** Adds or updates an entry (key -> source string). Marks the package dirty. */
	UFUNCTION(BlueprintCallable, Category = "Editor Toolset Compat|StringTable")
	static bool StringTableSetEntry(UObject* StringTable, const FString& Key, const FString& Value);

	/** Removes an entry by key. Returns true if an entry was removed. Marks the package dirty. */
	UFUNCTION(BlueprintCallable, Category = "Editor Toolset Compat|StringTable")
	static bool StringTableRemoveEntry(UObject* StringTable, const FString& Key);

	/** Imports entries from a CSV file on disk (header: Key,SourceString[,meta...]). */
	UFUNCTION(BlueprintCallable, Category = "Editor Toolset Compat|StringTable")
	static bool StringTableImportCsvFile(UObject* StringTable, const FString& Filename);

	// ---- CurveTable (Simple curves) -------------------------------------------

	/** Returns the names of all rows in the curve table. */
	UFUNCTION(BlueprintCallable, Category = "Editor Toolset Compat|CurveTable")
	static TArray<FString> CurveTableListRows(UObject* CurveTable);

	/** Adds a new simple-curve row. Returns false if it already exists or the table is in rich-curve mode. */
	UFUNCTION(BlueprintCallable, Category = "Editor Toolset Compat|CurveTable")
	static bool CurveTableAddRow(UObject* CurveTable, const FString& RowName);

	/** Sets the default (out-of-range) value for a simple-curve row. */
	UFUNCTION(BlueprintCallable, Category = "Editor Toolset Compat|CurveTable")
	static bool CurveTableSetRowDefault(UObject* CurveTable, const FString& RowName, float DefaultValue);

	/** Removes a row. Returns true if it existed. */
	UFUNCTION(BlueprintCallable, Category = "Editor Toolset Compat|CurveTable")
	static bool CurveTableRemoveRow(UObject* CurveTable, const FString& RowName);

	/** Renames a row. Returns false if the source is missing or the target already exists. */
	UFUNCTION(BlueprintCallable, Category = "Editor Toolset Compat|CurveTable")
	static bool CurveTableRenameRow(UObject* CurveTable, const FString& RowName, const FString& NewRowName);

	/** Adds a single key (time, value) to a simple-curve row. */
	UFUNCTION(BlueprintCallable, Category = "Editor Toolset Compat|CurveTable")
	static bool CurveTableAddKey(UObject* CurveTable, const FString& RowName, float Time, float Value);

	/**
	 * Replaces all keys of a simple-curve row with the supplied parallel (Times, Values) arrays.
	 * The two arrays must be the same length. Returns false on length mismatch or missing row.
	 */
	UFUNCTION(BlueprintCallable, Category = "Editor Toolset Compat|CurveTable")
	static bool CurveTableSetKeys(UObject* CurveTable, const FString& RowName,
		const TArray<float>& Times, const TArray<float>& Values);

	/** Returns the key times for a simple-curve row (parallel to CurveTableGetKeyValues). */
	UFUNCTION(BlueprintCallable, Category = "Editor Toolset Compat|CurveTable")
	static TArray<float> CurveTableGetKeyTimes(UObject* CurveTable, const FString& RowName);

	/** Returns the key values for a simple-curve row (parallel to CurveTableGetKeyTimes). */
	UFUNCTION(BlueprintCallable, Category = "Editor Toolset Compat|CurveTable")
	static TArray<float> CurveTableGetKeyValues(UObject* CurveTable, const FString& RowName);

	// ---- K2Node_CreateDelegate ------------------------------------------------

	/** True if Node is (or derives from) UK2Node_CreateDelegate. */
	UFUNCTION(BlueprintCallable, Category = "Editor Toolset Compat|Delegate")
	static bool IsCreateDelegateNode(UEdGraphNode* Node);

	/** Returns the function currently bound to a Create Event (UK2Node_CreateDelegate) node, or empty. */
	UFUNCTION(BlueprintCallable, Category = "Editor Toolset Compat|Delegate")
	static FString GetCreateDelegateFunction(UEdGraphNode* Node);

	/** Binds a function (by member name) to a Create Event node. Returns false if the node is wrong or the bind failed. */
	UFUNCTION(BlueprintCallable, Category = "Editor Toolset Compat|Delegate")
	static bool SetCreateDelegateFunction(UEdGraphNode* Node, const FString& FunctionName);

	/** Lists member function names compatible with the node's delegate signature (mirrors the editor's combo box). */
	UFUNCTION(BlueprintCallable, Category = "Editor Toolset Compat|Delegate")
	static TArray<FString> ListCompatibleFunctionsForDelegate(UEdGraphNode* Node);
};
