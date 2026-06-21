// Copyright Epic Games, Inc. All Rights Reserved.
//
// [5.7 port] Compatibility re-implementation of UE 5.8's engine class
// FWidgetBlueprintOperationUtils (declared in UMGEditor's WidgetBlueprintOperationUtils.h on 5.8).
//
// That class is a 5.8-only, editor-agnostic helper that operates directly on a UWidgetBlueprint
// (as opposed to the 5.7 FWidgetBlueprintEditorUtils, which is bound to a live FWidgetBlueprintEditor
// instance and FWidgetReference). It does NOT exist in the 5.7 engine, and is not present in the
// 5.8 plugin reference tree (only engine plugins were captured there, not engine Source).
//
// Each method below is reimplemented from scratch against UMG / UMGEditor APIs that DO exist in 5.7:
//   - FWidgetBlueprintEditorUtils public statics (DeleteWidgets, ReplaceWidgets, named-slot helpers)
//   - FWidgetTemplateClass (palette widget construction)
//   - UWidgetTree / UPanelWidget / UWidgetBlueprint (OnVariableAdded/Renamed/Removed, WidgetTree ops)
//   - UUIComponentWidgetBlueprintExtension (UI component add/remove/move)
//   - FKismetEditorUtilities (bound-event creation, blueprint creation)
//
// On 5.8 the suite uses the native engine FWidgetBlueprintOperationUtils directly; these compat
// shims are only compiled in on UE < 5.8 (see WidgetBlueprintOperationUtilsCompat.cpp guard and the
// call-site alias in UMGToolSet.cpp).

#pragma once

#include "Misc/EngineVersionComparison.h"

#if UE_VERSION_OLDER_THAN(5, 8, 0)

#include "CoreMinimal.h"
#include "WidgetBlueprintEditorUtils.h" // for EDeleteWidgetWarningType

class UWidget;
class UPanelWidget;
class UWidgetBlueprint;
class UWidgetTree;
class UClass;
class UUIComponent;
struct FAssetData;

namespace UMGToolSetCompat
{
/**
 * 5.7 stand-in for UE 5.8's FWidgetBlueprintOperationUtils. Static-only. All methods operate
 * directly on a UWidgetBlueprint with no live editor required. Behavior is matched to the
 * documented 5.8 contract used by UUMGToolSet; where 5.8 used internal/private machinery the
 * equivalent public 5.7 path is used (noted per-method in the .cpp).
 */
struct FWidgetBlueprintOperationUtilsCompat
{
	// ---- Creation ----

	/** Creates a Widget Blueprint asset in Package with the given parent + root widget class, then registers & (optionally) compiles. Mirrors UWidgetBlueprintFactory::FactoryCreateNew. */
	static UWidgetBlueprint* CreateWidgetBlueprint(UObject* Package, FName Name, EBlueprintType BlueprintType, UClass* ParentClass, UClass* RootWidgetClass, FName CallingContext, bool bRegisterAndCompile);

	/** Constructs a widget of WidgetAsset's class into Tree (no parenting). Returns nullptr + OutError on failure. */
	static UWidget* CreateWidgetFromAsset(UWidgetBlueprint* BP, const FAssetData& WidgetAsset, UWidgetTree* Tree, FText& OutErrorMessage);

	// ---- Add / rename / move / remove ----

	/** Validates that NewName is a legal, unique widget name for Widget within BP. */
	static bool VerifyWidgetRename(UWidgetBlueprint* BP, UWidget* Widget, const FText& NewName, FText& OutErrorMessage);

	/** Parents NewWidget under ParentWidget (a panel) at ChildIndex, or makes it the tree root if ParentWidget is null. Registers the variable. */
	static bool AddWidget(UWidgetBlueprint* BP, UWidget* NewWidget, UWidget* ParentWidget, int32 ChildIndex, FText& OutErrorMessage);

	/** Renames Widget to NewDisplayName, fixing up the variable map, graph references, bindings and animations. */
	static bool RenameWidget(UWidgetBlueprint* BP, UWidget* Widget, const FString& NewDisplayName);

	/** Reparents Widget under NewParent at ChildIndex. */
	static bool MoveWidget(UWidgetBlueprint* BP, UWidget* Widget, UPanelWidget* NewParent, int32 ChildIndex, FText& OutErrorMessage);

	/** Removes Widget (and children) from the tree. Delegates to FWidgetBlueprintEditorUtils::DeleteWidgets. */
	static bool RemoveWidget(UWidgetBlueprint* BP, UWidget* Widget, FText& OutErrorMessage);

	/** Removes a transient/just-constructed widget that was never parented into the tree (cleanup on a failed add). */
	static void RemoveTransientWidgetFromTree(UWidgetBlueprint* BP, UWidget* Widget);

	/** Toggles the bIsVariable flag and registers/unregisters the variable accordingly. */
	static void ToggleWidgetAsVariable(UWidgetBlueprint* BP, UWidget* Widget, bool bIsVariable);

	// ---- Wrap / replace ----

	/** Wraps the root-most of Widgets in newly created WrapperClass panels. Returns the created wrappers. */
	static TArray<UWidget*> WrapWidgets(UWidgetBlueprint* BP, TArray<UWidget*> Widgets, UClass* WrapperClass);

	/** Replaces WidgetToReplace with a new instance of TemplateClass, maintaining name & references. Delegates to FWidgetBlueprintEditorUtils::ReplaceWidgets. */
	static bool ReplaceWidgetWithTemplate(UWidgetBlueprint* BP, UWidget* WidgetToReplace, UClass* TemplateClass, FText& OutErrorMessage);

	/** Replaces a named-slot host widget with the content of one of its slots. */
	static bool ReplaceWidgetWithNamedSlot(UWidgetBlueprint* BP, UWidget* WidgetToReplace, FName NamedSlot, FWidgetBlueprintEditorUtils::EDeleteWidgetWarningType WarningType, FText& OutErrorMessage);

	/** Replaces a single-child panel widget with its only child. */
	static bool ReplaceWidgetWithChild(UWidgetBlueprint* BP, UWidget* WidgetToReplace, FText& OutErrorMessage);

	// ---- Bind event ----

	/** Adds (or focuses) a component-bound event handler graph node for EventName on PropertyName's widget. */
	static bool BindToEventProperty(UWidgetBlueprint* BP, FName EventName, FName PropertyName, UClass* PropertyClass, bool bUnused, FText& OutErrorMessage);

	// ---- UI Components ----

	/** Adds a UI component of ComponentClass to the named widget. Returns the host widget. */
	static UWidget* AddUIComponent(UWidgetBlueprint* BP, UClass* ComponentClass, FName WidgetName, FText& OutErrorMessage);

	/** Removes a UI component of ComponentClass from the named widget. */
	static bool RemoveUIComponent(UWidgetBlueprint* BP, UClass* ComponentClass, FName WidgetName, FText& OutErrorMessage);

	/** Reorders a UI component before/after another on the named widget. */
	static bool MoveUIComponent(UWidgetBlueprint* BP, UClass* ComponentClassToMove, UClass* RelativeToComponentClass, FName WidgetName, bool bMoveAfter, FText& OutErrorMessage);

	// ---- Replacement compatibility analysis ----

	/** True if Property has a compatible counterpart (same name, compatible type) on NewClass; else OutReason explains why not. */
	static bool DoesPropertyExistInClass(UClass* NewClass, const FProperty* Property, FText& OutReason);

	/** True if Function has a compatible counterpart (same name, compatible signature) on NewClass; else OutReason explains why not. */
	static bool DoesFunctionExistInClass(UClass* NewClass, const UFunction* Function, FText& OutReason);

	// ---- Description / depth ----

	/** Depth-first walk of the widget tree (from StartWidget or the root), invoking Visitor(Widget, Depth, NamedSlotName) per widget. MaxDepth -1 = unlimited. */
	static void WalkWidgetTree(const UWidgetBlueprint* BP, const UWidget* StartWidget, int32 MaxDepth, TFunctionRef<void(const UWidget*, int32, FName)> Visitor);

	/** Returns the maximum depth of the tree below StartWidget (root with no children = 0). -1 if empty. */
	static int32 ComputeWidgetTreeDepth(const UWidgetBlueprint* BP, const UWidget* StartWidget);
};
} // namespace UMGToolSetCompat

#endif // UE_VERSION_OLDER_THAN(5, 8, 0)
