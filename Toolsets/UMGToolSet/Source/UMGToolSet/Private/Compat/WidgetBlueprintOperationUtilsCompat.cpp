// Copyright Epic Games, Inc. All Rights Reserved.
//
// [5.7 port] See WidgetBlueprintOperationUtilsCompat.h for the rationale. Reimplements UE 5.8's
// FWidgetBlueprintOperationUtils against 5.7-available UMG / UMGEditor APIs.

#include "Compat/WidgetBlueprintOperationUtilsCompat.h"

#if UE_VERSION_OLDER_THAN(5, 8, 0)

#include "AssetRegistry/AssetData.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintGeneratedClass.h"
#include "Blueprint/WidgetTree.h"
#include "Components/NamedSlotInterface.h"
#include "Components/PanelWidget.h"
#include "Components/PanelSlot.h"
#include "Animation/WidgetAnimation.h"
#include "MovieScene.h"
#include "Extensions/UIComponent.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "Kismet2/Kismet2NameValidators.h"
#include "Modules/ModuleManager.h"
#include "Templates/WidgetTemplateClass.h"
#include "UMGEditorModule.h"
#include "UMGEditorProjectSettings.h"
#include "UObject/Package.h"
#include "WidgetBlueprint.h"
#include "WidgetBlueprintEditorUtils.h"
#include "UIComponentWidgetBlueprintExtension.h"

#define LOCTEXT_NAMESPACE "UMGToolSetCompat"

namespace UMGToolSetCompat
{
namespace
{
	/** Slug an arbitrary display name down to a legal FName, matching the engine's private SanitizeWidgetName. */
	FName SanitizeWidgetName(const FString& InName, const FName CurrentName)
	{
		FString GeneratedName = SlugStringForValidName(InName);

		// If the slugging removed everything, fall back to the current name.
		if (GeneratedName.IsEmpty())
		{
			return CurrentName;
		}

		return FName(*GeneratedName);
	}
} // anonymous namespace

// ---------------------------------------------------------------------------
// Creation
// ---------------------------------------------------------------------------

UWidgetBlueprint* FWidgetBlueprintOperationUtilsCompat::CreateWidgetBlueprint(UObject* Package, FName Name, EBlueprintType BlueprintType, UClass* ParentClass, UClass* RootWidgetClass, FName CallingContext, bool bRegisterAndCompile)
{
	// Mirrors UWidgetBlueprintFactory::FactoryCreateNew (5.7) without the modal UI.
	if (ParentClass == nullptr || !FKismetEditorUtilities::CanCreateBlueprintOfClass(ParentClass) || !ParentClass->IsChildOf(UUserWidget::StaticClass()))
	{
		return nullptr;
	}

	UWidgetBlueprint* NewBP = CastChecked<UWidgetBlueprint>(FKismetEditorUtilities::CreateBlueprint(
		ParentClass, Package, Name, BlueprintType,
		UWidgetBlueprint::StaticClass(), UWidgetBlueprintGeneratedClass::StaticClass(), CallingContext));

	// Create the desired root widget, matching the factory's behavior.
	if (NewBP->WidgetTree->RootWidget == nullptr)
	{
		if (TSubclassOf<UPanelWidget> RootWidgetPanel = RootWidgetClass)
		{
			UWidget* Root = NewBP->WidgetTree->ConstructWidget<UWidget>(RootWidgetPanel);
			NewBP->WidgetTree->RootWidget = Root;
			NewBP->OnVariableAdded(Root->GetFName());
		}
	}

	NewBP->bCanCallInitializedWithoutPlayerContext = GetDefault<UUMGEditorProjectSettings>()->bCanCallInitializedWithoutPlayerContext;

	if (FModuleManager::Get().IsModuleLoaded("UMGEditor"))
	{
		IUMGEditorModule::FWidgetBlueprintCreatedArgs Args;
		Args.ParentClass = ParentClass;
		Args.Blueprint = NewBP;
		IUMGEditorModule& UMGEditor = FModuleManager::LoadModuleChecked<IUMGEditorModule>("UMGEditor");
		UMGEditor.OnWidgetBlueprintCreated().Broadcast(Args);
	}

	if (bRegisterAndCompile)
	{
		FKismetEditorUtilities::CompileBlueprint(NewBP, EBlueprintCompileOptions::SkipGarbageCollection);
	}

	return NewBP;
}

UWidget* FWidgetBlueprintOperationUtilsCompat::CreateWidgetFromAsset(UWidgetBlueprint* BP, const FAssetData& WidgetAsset, UWidgetTree* Tree, FText& OutErrorMessage)
{
	if (!BP || !Tree)
	{
		OutErrorMessage = LOCTEXT("CreateWidgetFromAsset_BadArgs", "WidgetBlueprint and WidgetTree are required.");
		return nullptr;
	}

	// The toolset builds the FAssetData from a TSubclassOf<UWidget> via FAssetData(WidgetClass.Get()),
	// so the underlying asset is the UClass itself. Also tolerate an FAssetData pointing at a
	// UWidgetBlueprint asset (extract its generated class).
	UObject* Asset = WidgetAsset.GetAsset();
	UClass* WidgetClass = Cast<UClass>(Asset);
	if (!WidgetClass)
	{
		if (UBlueprint* AsBlueprint = Cast<UBlueprint>(Asset))
		{
			WidgetClass = AsBlueprint->GeneratedClass;
		}
	}
	if (!WidgetClass || !WidgetClass->IsChildOf(UWidget::StaticClass()))
	{
		OutErrorMessage = LOCTEXT("CreateWidgetFromAsset_NotWidget", "Asset is not a widget class.");
		return nullptr;
	}

	if (WidgetClass->HasAnyClassFlags(CLASS_Abstract))
	{
		OutErrorMessage = FText::Format(LOCTEXT("CreateWidgetFromAsset_Abstract", "'{0}' is abstract and cannot be instantiated."), FText::FromString(WidgetClass->GetName()));
		return nullptr;
	}

	// FWidgetTemplateClass::Create constructs into the tree using the engine's palette path
	// (same code that the UMG designer drag/drop uses), so naming/registration matches.
	FWidgetTemplateClass Template(WidgetClass);
	UWidget* NewWidget = Template.Create(Tree);
	if (!NewWidget)
	{
		OutErrorMessage = LOCTEXT("CreateWidgetFromAsset_Failed", "Failed to construct widget.");
	}
	return NewWidget;
}

// ---------------------------------------------------------------------------
// Add / rename / move / remove
// ---------------------------------------------------------------------------

bool FWidgetBlueprintOperationUtilsCompat::VerifyWidgetRename(UWidgetBlueprint* BP, UWidget* Widget, const FText& NewName, FText& OutErrorMessage)
{
	// Self-contained mirror of FWidgetBlueprintEditorUtils::VerifyWidgetRename without the preview widget.
	if (!BP || !Widget)
	{
		OutErrorMessage = LOCTEXT("VerifyRename_BadArgs", "WidgetBlueprint and Widget are required.");
		return false;
	}

	if (NewName.IsEmptyOrWhitespace())
	{
		OutErrorMessage = LOCTEXT("EmptyWidgetName", "Empty Widget Name");
		return false;
	}

	const FString& NewNameString = NewName.ToString();
	if (NewNameString.Len() >= NAME_SIZE)
	{
		OutErrorMessage = LOCTEXT("WidgetNameTooLong", "Widget Name is Too Long");
		return false;
	}

	const FName NewNameSlug = SanitizeWidgetName(NewNameString, Widget->GetFName());

	UWidget* ExistingTemplate = BP->WidgetTree ? BP->WidgetTree->FindWidget(NewNameSlug) : nullptr;
	bool bIsSameWidget = false;
	if (ExistingTemplate != nullptr)
	{
		if (Widget != ExistingTemplate)
		{
			OutErrorMessage = LOCTEXT("ExistingWidgetName", "Existing Widget Name");
			return false;
		}
		bIsSameWidget = true;
	}
	else
	{
		// Dummy rename to detect a UObject name clash.
		if (!Widget->Rename(*NewNameSlug.ToString(), nullptr, REN_Test))
		{
			OutErrorMessage = LOCTEXT("ExistingObjectName", "Existing Object Name");
			return false;
		}
	}

	// A BindWidget property of the right type on the parent class is an allowed (intentional) match.
	FObjectPropertyBase* Property = BP->ParentClass ? CastField<FObjectPropertyBase>(BP->ParentClass->FindPropertyByName(NewNameSlug)) : nullptr;
	if (Property && FWidgetBlueprintEditorUtils::IsBindWidgetProperty(Property))
	{
		if (!Widget->IsA(Property->PropertyClass))
		{
			OutErrorMessage = FText::Format(LOCTEXT("WidgetBindingOfWrongType", "Widget Binding is not type {0}"), Property->PropertyClass->GetDisplayNameText());
			return false;
		}
		return true;
	}

	FKismetNameValidator Validator(BP);
	const EValidatorResult ValidatorResult = Validator.IsValid(NewNameSlug);
	if (ValidatorResult != EValidatorResult::Ok)
	{
		if (bIsSameWidget && (ValidatorResult == EValidatorResult::AlreadyInUse || ValidatorResult == EValidatorResult::ExistingName))
		{
			return true;
		}
		OutErrorMessage = INameValidatorInterface::GetErrorText(NewNameString, ValidatorResult);
		return false;
	}

	return true;
}

bool FWidgetBlueprintOperationUtilsCompat::AddWidget(UWidgetBlueprint* BP, UWidget* NewWidget, UWidget* ParentWidget, int32 ChildIndex, FText& OutErrorMessage)
{
	if (!BP || !BP->WidgetTree || !NewWidget)
	{
		OutErrorMessage = LOCTEXT("AddWidget_BadArgs", "WidgetBlueprint and NewWidget are required.");
		return false;
	}

	BP->WidgetTree->SetFlags(RF_Transactional);
	BP->WidgetTree->Modify();
	BP->Modify();

	if (ParentWidget == nullptr)
	{
		// No parent: become the root if the tree is empty, otherwise add under the existing root if it's a panel.
		if (BP->WidgetTree->RootWidget == nullptr)
		{
			BP->WidgetTree->RootWidget = NewWidget;
		}
		else if (UPanelWidget* RootPanel = Cast<UPanelWidget>(BP->WidgetTree->RootWidget))
		{
			if (!RootPanel->CanAddMoreChildren())
			{
				OutErrorMessage = LOCTEXT("AddWidget_RootFull", "Root panel cannot take more children; specify a parent.");
				return false;
			}
			if (ChildIndex >= 0 && ChildIndex < RootPanel->GetChildrenCount())
			{
				RootPanel->InsertChildAt(ChildIndex, NewWidget);
			}
			else
			{
				RootPanel->AddChild(NewWidget);
			}
		}
		else
		{
			OutErrorMessage = LOCTEXT("AddWidget_NoParent", "A root already exists and is not a panel; specify a parent widget.");
			return false;
		}
	}
	else
	{
		UPanelWidget* ParentPanel = Cast<UPanelWidget>(ParentWidget);
		if (!ParentPanel)
		{
			OutErrorMessage = FText::Format(LOCTEXT("AddWidget_ParentNotPanel", "Parent widget '{0}' is not a panel."), FText::FromName(ParentWidget->GetFName()));
			return false;
		}
		if (!ParentPanel->CanAddMoreChildren())
		{
			OutErrorMessage = FText::Format(LOCTEXT("AddWidget_ParentFull", "Parent panel '{0}' cannot take more children."), FText::FromName(ParentWidget->GetFName()));
			return false;
		}
		ParentPanel->Modify();
		if (ChildIndex >= 0 && ChildIndex < ParentPanel->GetChildrenCount())
		{
			ParentPanel->InsertChildAt(ChildIndex, NewWidget);
		}
		else
		{
			ParentPanel->AddChild(NewWidget);
		}
	}

	if (!BP->WidgetVariableNameToGuidMap.Contains(NewWidget->GetFName()))
	{
		BP->OnVariableAdded(NewWidget->GetFName());
	}

	FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(BP);
	return true;
}

bool FWidgetBlueprintOperationUtilsCompat::RenameWidget(UWidgetBlueprint* BP, UWidget* Widget, const FString& NewDisplayName)
{
	if (!BP || !Widget)
	{
		return false;
	}

	const FName OldName = Widget->GetFName();
	const FName NewFName = SanitizeWidgetName(NewDisplayName, OldName);
	if (NewFName == OldName)
	{
		// Even if the FName is unchanged, the display label may differ.
		Widget->SetDisplayLabel(NewDisplayName);
		return true;
	}

	UClass* ParentClass = BP->ParentClass;
	FObjectPropertyBase* ExistingProperty = ParentClass ? CastField<FObjectPropertyBase>(ParentClass->FindPropertyByName(NewFName)) : nullptr;
	const bool bBindWidget = ExistingProperty && FWidgetBlueprintEditorUtils::IsBindWidgetProperty(ExistingProperty) && Widget->IsA(ExistingProperty->PropertyClass);

	FKismetNameValidator NameValidator(BP, OldName);
	const bool bUniqueName = (EValidatorResult::Ok == NameValidator.IsValid(NewFName)) || bBindWidget;
	if (!bUniqueName)
	{
		return false;
	}

	const FString NewNameStr = NewFName.ToString();
	const FString OldNameStr = OldName.ToString();

	BP->Modify();
	Widget->Modify();

	// Update the guid map so external references are fixed up on compile.
	BP->OnVariableRenamed(OldName, NewFName);

	Widget->SetDisplayLabel(NewDisplayName);
	Widget->Rename(*NewNameStr, nullptr, REN_DontCreateRedirectors);

	// Fix up graph variable references to the renamed widget.
	FBlueprintEditorUtils::ReplaceVariableReferences(BP, OldName, NewFName);

	// Fix up legacy delegate bindings.
	for (FDelegateEditorBinding& Binding : BP->Bindings)
	{
		if (Binding.ObjectName == OldNameStr)
		{
			Binding.ObjectName = NewNameStr;
		}
	}

	// Fix up animation bindings + possessable names.
	for (UWidgetAnimation* WidgetAnimation : BP->Animations)
	{
		if (!WidgetAnimation)
		{
			continue;
		}
		for (FWidgetAnimationBinding& AnimBinding : WidgetAnimation->AnimationBindings)
		{
			if (AnimBinding.WidgetName == OldName)
			{
				AnimBinding.WidgetName = NewFName;
				if (WidgetAnimation->MovieScene && AnimBinding.SlotWidgetName == NAME_None)
				{
					WidgetAnimation->MovieScene->Modify();
					if (FMovieScenePossessable* Possessable = WidgetAnimation->MovieScene->FindPossessable(AnimBinding.AnimationGuid))
					{
						Possessable->SetName(NewNameStr);
					}
				}
			}
		}
	}

	FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(BP);
	return true;
}

bool FWidgetBlueprintOperationUtilsCompat::MoveWidget(UWidgetBlueprint* BP, UWidget* Widget, UPanelWidget* NewParent, int32 ChildIndex, FText& OutErrorMessage)
{
	if (!BP || !BP->WidgetTree || !Widget || !NewParent)
	{
		OutErrorMessage = LOCTEXT("MoveWidget_BadArgs", "WidgetBlueprint, Widget and NewParent are required.");
		return false;
	}

	if (Widget == NewParent)
	{
		OutErrorMessage = LOCTEXT("MoveWidget_Self", "Cannot move a widget into itself.");
		return false;
	}

	// Disallow moving a widget into one of its own descendants.
	TArray<UWidget*> Descendants;
	UWidgetTree::GetChildWidgets(Widget, Descendants);
	if (Descendants.Contains(NewParent))
	{
		OutErrorMessage = LOCTEXT("MoveWidget_IntoDescendant", "Cannot move a widget into its own child.");
		return false;
	}

	if (!NewParent->CanAddMoreChildren())
	{
		OutErrorMessage = FText::Format(LOCTEXT("MoveWidget_ParentFull", "Parent panel '{0}' cannot take more children."), FText::FromName(NewParent->GetFName()));
		return false;
	}

	BP->WidgetTree->SetFlags(RF_Transactional);
	BP->WidgetTree->Modify();
	Widget->Modify();
	NewParent->Modify();

	// Detach from current parent / named-slot host / root.
	if (UPanelWidget* OldParent = Widget->GetParent())
	{
		OldParent->Modify();
		OldParent->RemoveChild(Widget);
	}
	else if (TScriptInterface<INamedSlotInterface> NamedSlotHost = FWidgetBlueprintEditorUtils::FindNamedSlotHostForContent(Widget, BP->WidgetTree))
	{
		FWidgetBlueprintEditorUtils::RemoveNamedSlotHostContent(Widget, NamedSlotHost);
	}
	else if (BP->WidgetTree->RootWidget == Widget)
	{
		BP->WidgetTree->RootWidget = nullptr;
	}

	if (ChildIndex >= 0 && ChildIndex < NewParent->GetChildrenCount())
	{
		NewParent->InsertChildAt(ChildIndex, Widget);
	}
	else
	{
		NewParent->AddChild(Widget);
	}

	FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(BP);
	return true;
}

bool FWidgetBlueprintOperationUtilsCompat::RemoveWidget(UWidgetBlueprint* BP, UWidget* Widget, FText& OutErrorMessage)
{
	if (!BP || !Widget)
	{
		OutErrorMessage = LOCTEXT("RemoveWidget_BadArgs", "WidgetBlueprint and Widget are required.");
		return false;
	}

	FWidgetBlueprintEditorUtils::DeleteWidgets(BP, TSet<UWidget*>{ Widget }, FWidgetBlueprintEditorUtils::EDeleteWidgetWarningType::DeleteSilently);
	return true;
}

void FWidgetBlueprintOperationUtilsCompat::RemoveTransientWidgetFromTree(UWidgetBlueprint* BP, UWidget* Widget)
{
	if (!Widget)
	{
		return;
	}

	// The widget was constructed into the tree but never parented. Detach it if it slipped into
	// the root or a named slot, drop any registered variable, then rename it to the transient package.
	if (BP && BP->WidgetTree)
	{
		if (BP->WidgetTree->RootWidget == Widget)
		{
			BP->WidgetTree->RootWidget = nullptr;
		}
		BP->WidgetTree->RemoveWidget(Widget);
	}

	if (BP)
	{
		const FName WidgetName = Widget->GetFName();
		if (BP->WidgetVariableNameToGuidMap.Contains(WidgetName))
		{
			BP->OnVariableRemoved(WidgetName);
		}
	}

	Widget->Rename(nullptr, GetTransientPackage(), REN_DontCreateRedirectors);
}

void FWidgetBlueprintOperationUtilsCompat::ToggleWidgetAsVariable(UWidgetBlueprint* BP, UWidget* Widget, bool bIsVariable)
{
	if (!BP || !Widget)
	{
		return;
	}

	if (Widget->bIsVariable == bIsVariable)
	{
		return;
	}

	BP->Modify();
	Widget->Modify();
	Widget->bIsVariable = bIsVariable;

	const FName WidgetName = Widget->GetFName();
	if (bIsVariable)
	{
		if (!BP->WidgetVariableNameToGuidMap.Contains(WidgetName))
		{
			BP->OnVariableAdded(WidgetName);
		}
	}
	else
	{
		// Only drop the variable entry if it isn't required by a graph reference.
		if (!FBlueprintEditorUtils::IsVariableUsed(BP, WidgetName))
		{
			BP->OnVariableRemoved(WidgetName);
		}
	}

	FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(BP);
}

// ---------------------------------------------------------------------------
// Wrap / replace
// ---------------------------------------------------------------------------

TArray<UWidget*> FWidgetBlueprintOperationUtilsCompat::WrapWidgets(UWidgetBlueprint* BP, TArray<UWidget*> Widgets, UClass* WrapperClass)
{
	// Reimplements the private FWidgetBlueprintEditorUtils::WrapWidgets without designer flags.
	TArray<UWidget*> CreatedWrappers;
	if (!BP || !BP->WidgetTree || !WrapperClass || !WrapperClass->IsChildOf(UPanelWidget::StaticClass()))
	{
		return CreatedWrappers;
	}

	TSet<UWidget*> WidgetSet(Widgets);

	// Skip widgets that are children of other selected widgets (their parent gets wrapped instead).
	TSet<UWidget*> WidgetsToRemove;
	for (UWidget* Item : WidgetSet)
	{
		int32 OutIndex = INDEX_NONE;
		UPanelWidget* CurrentParent = BP->WidgetTree->FindWidgetParent(Item, OutIndex);
		if (CurrentParent && WidgetSet.Contains(CurrentParent))
		{
			WidgetsToRemove.Add(Item);
		}
	}
	for (UWidget* Item : WidgetsToRemove)
	{
		WidgetSet.Remove(Item);
	}

	TSharedRef<FWidgetTemplateClass> Template = MakeShared<FWidgetTemplateClass>(WrapperClass);
	TMap<UPanelWidget*, UPanelWidget*> OldParentToNewParent;

	for (UWidget* Widget : WidgetSet)
	{
		int32 OutIndex = INDEX_NONE;
		UPanelWidget* CurrentParent = BP->WidgetTree->FindWidgetParent(Widget, OutIndex);
		TScriptInterface<INamedSlotInterface> NamedSlotHost = FWidgetBlueprintEditorUtils::FindNamedSlotHostForContent(Widget, BP->WidgetTree);

		if (NamedSlotHost == nullptr && CurrentParent == nullptr && Widget != BP->WidgetTree->RootWidget)
		{
			continue;
		}

		Widget->Modify();
		BP->WidgetTree->SetFlags(RF_Transactional);
		BP->WidgetTree->Modify();

		if (NamedSlotHost)
		{
			if (UObject* NamedSlotObject = NamedSlotHost.GetObject())
			{
				NamedSlotObject->SetFlags(RF_Transactional);
				NamedSlotObject->Modify();

				UPanelWidget* NewSlotContents = CastChecked<UPanelWidget>(Template->Create(BP->WidgetTree));
				BP->OnVariableAdded(NewSlotContents->GetFName());
				FWidgetBlueprintEditorUtils::ReplaceNamedSlotHostContent(Widget, NamedSlotHost, NewSlotContents);
				NewSlotContents->AddChild(Widget);
				CreatedWrappers.Add(NewSlotContents);
			}
		}
		else if (CurrentParent)
		{
			UPanelWidget*& NewWrapperWidget = OldParentToNewParent.FindOrAdd(CurrentParent);
			if (NewWrapperWidget == nullptr || !NewWrapperWidget->CanAddMoreChildren())
			{
				NewWrapperWidget = CastChecked<UPanelWidget>(Template->Create(BP->WidgetTree));
				BP->OnVariableAdded(NewWrapperWidget->GetFName());
				CurrentParent->SetFlags(RF_Transactional);
				CurrentParent->Modify();
				CurrentParent->ReplaceChildAt(OutIndex, NewWrapperWidget);
				CreatedWrappers.Add(NewWrapperWidget);
			}

			if (NewWrapperWidget != nullptr && NewWrapperWidget->CanAddMoreChildren())
			{
				NewWrapperWidget->Modify();
				NewWrapperWidget->AddChild(Widget);
			}
		}
		else
		{
			UPanelWidget* NewRootContents = CastChecked<UPanelWidget>(Template->Create(BP->WidgetTree));
			BP->OnVariableAdded(NewRootContents->GetFName());
			BP->WidgetTree->RootWidget = NewRootContents;
			NewRootContents->AddChild(Widget);
			CreatedWrappers.Add(NewRootContents);
		}
	}

	FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(BP);
	return CreatedWrappers;
}

bool FWidgetBlueprintOperationUtilsCompat::ReplaceWidgetWithTemplate(UWidgetBlueprint* BP, UWidget* WidgetToReplace, UClass* TemplateClass, FText& OutErrorMessage)
{
	if (!BP || !WidgetToReplace || !TemplateClass)
	{
		OutErrorMessage = LOCTEXT("Replace_BadArgs", "WidgetBlueprint, WidgetToReplace and TemplateClass are required.");
		return false;
	}

	// Panel-with-children must be replaced by another panel.
	if (UPanelWidget* ExistingPanel = Cast<UPanelWidget>(WidgetToReplace))
	{
		if (ExistingPanel->GetChildrenCount() > 0 && !TemplateClass->IsChildOf(UPanelWidget::StaticClass()))
		{
			OutErrorMessage = LOCTEXT("Replace_PanelNonPanel", "Cannot replace a panel that has children with a non-panel class.");
			return false;
		}
	}

	FWidgetBlueprintEditorUtils::ReplaceWidgets(
		BP, TSet<UWidget*>{ WidgetToReplace }, TemplateClass,
		FWidgetBlueprintEditorUtils::EReplaceWidgetNamingMethod::MaintainNameAndReferences);

	return true;
}

bool FWidgetBlueprintOperationUtilsCompat::ReplaceWidgetWithNamedSlot(UWidgetBlueprint* BP, UWidget* WidgetToReplace, FName NamedSlot, FWidgetBlueprintEditorUtils::EDeleteWidgetWarningType WarningType, FText& OutErrorMessage)
{
	// Reimplements the private FWidgetBlueprintEditorUtils::ReplaceWidgetWithNamedSlot.
	if (!BP || !BP->WidgetTree || !WidgetToReplace)
	{
		OutErrorMessage = LOCTEXT("ReplaceNamedSlot_BadArgs", "WidgetBlueprint and WidgetToReplace are required.");
		return false;
	}

	INamedSlotInterface* SlotContainer = Cast<INamedSlotInterface>(WidgetToReplace);
	if (!SlotContainer)
	{
		OutErrorMessage = FText::Format(LOCTEXT("ReplaceNamedSlot_NotHost", "Widget '{0}' does not implement INamedSlotInterface."), FText::FromName(WidgetToReplace->GetFName()));
		return false;
	}

	UWidget* SlotContent = SlotContainer->GetContentForSlot(NamedSlot);
	if (!SlotContent)
	{
		OutErrorMessage = FText::Format(LOCTEXT("ReplaceNamedSlot_Empty", "Named slot '{0}' has no content."), FText::FromName(NamedSlot));
		return false;
	}

	WidgetToReplace->SetFlags(RF_Transactional);
	WidgetToReplace->Modify();
	SlotContent->SetFlags(RF_Transactional);
	SlotContent->Modify();

	if (TScriptInterface<INamedSlotInterface> NamedSlotHost = FWidgetBlueprintEditorUtils::FindNamedSlotHostForContent(WidgetToReplace, BP->WidgetTree))
	{
		FWidgetBlueprintEditorUtils::ReplaceNamedSlotHostContent(WidgetToReplace, NamedSlotHost, SlotContent);
	}
	else if (UPanelWidget* PanelParent = WidgetToReplace->GetParent())
	{
		PanelParent->Modify();
		if (TScriptInterface<INamedSlotInterface> ContentNamedSlotHost = FWidgetBlueprintEditorUtils::FindNamedSlotHostForContent(SlotContent, BP->WidgetTree))
		{
			FWidgetBlueprintEditorUtils::RemoveNamedSlotHostContent(SlotContent, ContentNamedSlotHost);
		}
		PanelParent->ReplaceChild(WidgetToReplace, SlotContent);
	}
	else if (WidgetToReplace == BP->WidgetTree->RootWidget)
	{
		if (UPanelWidget* Parent = SlotContent->GetParent())
		{
			Parent->Modify();
			SlotContent->RemoveFromParent();
		}
		BP->WidgetTree->Modify();
		BP->WidgetTree->RootWidget = SlotContent;
	}
	else
	{
		OutErrorMessage = LOCTEXT("ReplaceNamedSlot_NoHostPath", "Could not determine where to reparent the slot content.");
		return false;
	}

	FWidgetBlueprintEditorUtils::DeleteWidgets(BP, TSet<UWidget*>{ WidgetToReplace }, WarningType);
	FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(BP);
	return true;
}

bool FWidgetBlueprintOperationUtilsCompat::ReplaceWidgetWithChild(UWidgetBlueprint* BP, UWidget* WidgetToReplace, FText& OutErrorMessage)
{
	// Reimplements the private FWidgetBlueprintEditorUtils::ReplaceWidgetWithChildren.
	if (!BP || !BP->WidgetTree || !WidgetToReplace)
	{
		OutErrorMessage = LOCTEXT("ReplaceChild_BadArgs", "WidgetBlueprint and WidgetToReplace are required.");
		return false;
	}

	UPanelWidget* ExistingPanel = Cast<UPanelWidget>(WidgetToReplace);
	if (!ExistingPanel)
	{
		OutErrorMessage = FText::Format(LOCTEXT("ReplaceChild_NotPanel", "Widget '{0}' is not a panel."), FText::FromName(WidgetToReplace->GetFName()));
		return false;
	}
	if (ExistingPanel->GetChildrenCount() != 1)
	{
		OutErrorMessage = LOCTEXT("ReplaceChild_NotSingleChild", "Panel must have exactly one child to be replaced by it.");
		return false;
	}

	UWidget* FirstChild = ExistingPanel->GetChildAt(0);
	ExistingPanel->SetFlags(RF_Transactional);
	ExistingPanel->Modify();
	FirstChild->SetFlags(RF_Transactional);
	FirstChild->Modify();

	if (TScriptInterface<INamedSlotInterface> NamedSlotHost = FWidgetBlueprintEditorUtils::FindNamedSlotHostForContent(ExistingPanel, BP->WidgetTree))
	{
		FWidgetBlueprintEditorUtils::ReplaceNamedSlotHostContent(ExistingPanel, NamedSlotHost, FirstChild);
	}
	else if (UPanelWidget* PanelParent = ExistingPanel->GetParent())
	{
		PanelParent->Modify();
		FirstChild->RemoveFromParent();
		PanelParent->ReplaceChild(ExistingPanel, FirstChild);
	}
	else if (ExistingPanel == BP->WidgetTree->RootWidget)
	{
		FirstChild->RemoveFromParent();
		BP->WidgetTree->Modify();
		BP->WidgetTree->RootWidget = FirstChild;
	}
	else
	{
		OutErrorMessage = LOCTEXT("ReplaceChild_NoPath", "Could not determine where to reparent the child.");
		return false;
	}

	FWidgetBlueprintEditorUtils::DeleteWidgets(BP, TSet<UWidget*>{ ExistingPanel }, FWidgetBlueprintEditorUtils::EDeleteWidgetWarningType::DeleteSilently);
	FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(BP);
	return true;
}

// ---------------------------------------------------------------------------
// Bind event
// ---------------------------------------------------------------------------

bool FWidgetBlueprintOperationUtilsCompat::BindToEventProperty(UWidgetBlueprint* BP, FName EventName, FName PropertyName, UClass* PropertyClass, bool /*bUnused*/, FText& OutErrorMessage)
{
	// Mirrors FBlueprintWidgetCustomization::HandleAddOrViewEventForVariable.
	if (!BP || EventName.IsNone() || PropertyName.IsNone() || !PropertyClass)
	{
		OutErrorMessage = LOCTEXT("BindEvent_BadArgs", "WidgetBlueprint, EventName, PropertyName and PropertyClass are required.");
		return false;
	}

	// [5.7 port] SkeletonGeneratedClass/GeneratedClass are raw UClass* in 5.7 (TObjectPtr in 5.8); assign directly so this compiles on both.
	UClass* SearchClass = BP->SkeletonGeneratedClass ? BP->SkeletonGeneratedClass : BP->GeneratedClass;
	if (!SearchClass)
	{
		OutErrorMessage = LOCTEXT("BindEvent_NoClass", "WidgetBlueprint has no generated class; compile it first.");
		return false;
	}

	FObjectProperty* VariableProperty = FindFProperty<FObjectProperty>(SearchClass, PropertyName);
	if (!VariableProperty)
	{
		OutErrorMessage = FText::Format(LOCTEXT("BindEvent_NoProperty", "No widget variable named '{0}' was found."), FText::FromName(PropertyName));
		return false;
	}

	// Validate that the delegate exists on PropertyClass.
	if (!FindFProperty<FMulticastDelegateProperty>(PropertyClass, EventName))
	{
		OutErrorMessage = FText::Format(LOCTEXT("BindEvent_NoDelegate", "Class '{0}' has no multicast delegate '{1}'."), FText::FromString(PropertyClass->GetName()), FText::FromName(EventName));
		return false;
	}

	if (!FKismetEditorUtilities::FindBoundEventForComponent(BP, EventName, VariableProperty->GetFName()))
	{
		FKismetEditorUtilities::CreateNewBoundEventForClass(PropertyClass, EventName, BP, VariableProperty);
	}

	return true;
}

// ---------------------------------------------------------------------------
// UI Components
// ---------------------------------------------------------------------------

UWidget* FWidgetBlueprintOperationUtilsCompat::AddUIComponent(UWidgetBlueprint* BP, UClass* ComponentClass, FName WidgetName, FText& OutErrorMessage)
{
	if (!BP || !ComponentClass || WidgetName.IsNone())
	{
		OutErrorMessage = LOCTEXT("AddUIComp_BadArgs", "WidgetBlueprint, ComponentClass and WidgetName are required.");
		return nullptr;
	}

	UWidget* Widget = BP->WidgetTree ? BP->WidgetTree->FindWidget(WidgetName) : nullptr;
	if (!Widget)
	{
		OutErrorMessage = FText::Format(LOCTEXT("AddUIComp_NoWidget", "No widget named '{0}' was found."), FText::FromName(WidgetName));
		return nullptr;
	}

	UUIComponentWidgetBlueprintExtension* Ext = UWidgetBlueprintExtension::RequestExtension<UUIComponentWidgetBlueprintExtension>(BP);
	if (!Ext)
	{
		OutErrorMessage = LOCTEXT("AddUIComp_NoExt", "Failed to obtain the UIComponent extension.");
		return nullptr;
	}

	BP->Modify();
	if (!Ext->AddComponent(ComponentClass, WidgetName))
	{
		OutErrorMessage = FText::Format(LOCTEXT("AddUIComp_Failed", "Failed to add component '{0}' to '{1}' (it may already exist)."), FText::FromString(ComponentClass->GetName()), FText::FromName(WidgetName));
		return nullptr;
	}

	FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(BP);
	return Widget;
}

bool FWidgetBlueprintOperationUtilsCompat::RemoveUIComponent(UWidgetBlueprint* BP, UClass* ComponentClass, FName WidgetName, FText& OutErrorMessage)
{
	if (!BP || !ComponentClass || WidgetName.IsNone())
	{
		OutErrorMessage = LOCTEXT("RemUIComp_BadArgs", "WidgetBlueprint, ComponentClass and WidgetName are required.");
		return false;
	}

	UUIComponentWidgetBlueprintExtension* Ext = UWidgetBlueprintExtension::GetExtension<UUIComponentWidgetBlueprintExtension>(BP);
	if (!Ext || !Ext->GetComponent(ComponentClass, WidgetName))
	{
		OutErrorMessage = FText::Format(LOCTEXT("RemUIComp_NotFound", "Component '{0}' was not found on '{1}'."), FText::FromString(ComponentClass->GetName()), FText::FromName(WidgetName));
		return false;
	}

	BP->Modify();
	Ext->RemoveComponent(ComponentClass, WidgetName);
	FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(BP);
	return true;
}

bool FWidgetBlueprintOperationUtilsCompat::MoveUIComponent(UWidgetBlueprint* BP, UClass* ComponentClassToMove, UClass* RelativeToComponentClass, FName WidgetName, bool bMoveAfter, FText& OutErrorMessage)
{
	if (!BP || !ComponentClassToMove || !RelativeToComponentClass || WidgetName.IsNone())
	{
		OutErrorMessage = LOCTEXT("MoveUIComp_BadArgs", "WidgetBlueprint, both component classes and WidgetName are required.");
		return false;
	}

	UUIComponentWidgetBlueprintExtension* Ext = UWidgetBlueprintExtension::GetExtension<UUIComponentWidgetBlueprintExtension>(BP);
	if (!Ext || !Ext->GetComponent(ComponentClassToMove, WidgetName) || !Ext->GetComponent(RelativeToComponentClass, WidgetName))
	{
		OutErrorMessage = FText::Format(LOCTEXT("MoveUIComp_NotFound", "Both components must exist on '{0}'."), FText::FromName(WidgetName));
		return false;
	}

	BP->Modify();
	Ext->MoveComponent(WidgetName, ComponentClassToMove, RelativeToComponentClass, bMoveAfter);
	FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(BP);
	return true;
}

// ---------------------------------------------------------------------------
// Replacement compatibility analysis
// ---------------------------------------------------------------------------

bool FWidgetBlueprintOperationUtilsCompat::DoesPropertyExistInClass(UClass* NewClass, const FProperty* Property, FText& OutReason)
{
	if (!NewClass || !Property)
	{
		OutReason = LOCTEXT("PropExist_BadArgs", "Invalid arguments.");
		return false;
	}

	const FName PropName = Property->GetFName();
	FProperty* NewProperty = FindFProperty<FProperty>(NewClass, PropName);
	if (!NewProperty)
	{
		OutReason = FText::Format(LOCTEXT("PropExist_Missing", "No property named '{0}' on the new class."), FText::FromName(PropName));
		return false;
	}

	// SameType handles matching by class for object props, struct for struct props, etc.
	if (!NewProperty->SameType(Property))
	{
		OutReason = FText::Format(LOCTEXT("PropExist_TypeMismatch", "Property '{0}' exists but has an incompatible type."), FText::FromName(PropName));
		return false;
	}

	return true;
}

bool FWidgetBlueprintOperationUtilsCompat::DoesFunctionExistInClass(UClass* NewClass, const UFunction* Function, FText& OutReason)
{
	if (!NewClass || !Function)
	{
		OutReason = LOCTEXT("FuncExist_BadArgs", "Invalid arguments.");
		return false;
	}

	const FName FuncName = Function->GetFName();
	UFunction* NewFunction = NewClass->FindFunctionByName(FuncName);
	if (!NewFunction)
	{
		OutReason = FText::Format(LOCTEXT("FuncExist_Missing", "No function named '{0}' on the new class."), FText::FromName(FuncName));
		return false;
	}

	// Compatible signature check (params + return), same test the blueprint compiler uses.
	if (!NewFunction->IsSignatureCompatibleWith(Function))
	{
		OutReason = FText::Format(LOCTEXT("FuncExist_SigMismatch", "Function '{0}' exists but its signature is incompatible."), FText::FromName(FuncName));
		return false;
	}

	return true;
}

// ---------------------------------------------------------------------------
// Description / depth
// ---------------------------------------------------------------------------

namespace
{
	void WalkWidgetTreeRecursive(const UWidget* Widget, int32 Depth, FName SlotName, int32 MaxDepth, TFunctionRef<void(const UWidget*, int32, FName)> Visitor)
	{
		if (!Widget)
		{
			return;
		}

		Visitor(Widget, Depth, SlotName);

		if (MaxDepth >= 0 && Depth >= MaxDepth)
		{
			return;
		}

		if (const UPanelWidget* Panel = Cast<UPanelWidget>(Widget))
		{
			for (int32 i = 0; i < Panel->GetChildrenCount(); ++i)
			{
				WalkWidgetTreeRecursive(Panel->GetChildAt(i), Depth + 1, NAME_None, MaxDepth, Visitor);
			}
		}

		if (const INamedSlotInterface* SlotHost = Cast<INamedSlotInterface>(Widget))
		{
			TArray<FName> SlotNames;
			SlotHost->GetSlotNames(SlotNames);
			for (const FName& Name : SlotNames)
			{
				if (UWidget* Content = SlotHost->GetContentForSlot(Name))
				{
					WalkWidgetTreeRecursive(Content, Depth + 1, Name, MaxDepth, Visitor);
				}
			}
		}
	}

	int32 ComputeDepthRecursive(const UWidget* Widget)
	{
		if (!Widget)
		{
			return -1;
		}

		int32 MaxChildDepth = -1;
		if (const UPanelWidget* Panel = Cast<UPanelWidget>(Widget))
		{
			for (int32 i = 0; i < Panel->GetChildrenCount(); ++i)
			{
				MaxChildDepth = FMath::Max(MaxChildDepth, ComputeDepthRecursive(Panel->GetChildAt(i)));
			}
		}
		if (const INamedSlotInterface* SlotHost = Cast<INamedSlotInterface>(Widget))
		{
			TArray<FName> SlotNames;
			SlotHost->GetSlotNames(SlotNames);
			for (const FName& Name : SlotNames)
			{
				if (UWidget* Content = SlotHost->GetContentForSlot(Name))
				{
					MaxChildDepth = FMath::Max(MaxChildDepth, ComputeDepthRecursive(Content));
				}
			}
		}
		return MaxChildDepth + 1;
	}
} // anonymous namespace

void FWidgetBlueprintOperationUtilsCompat::WalkWidgetTree(const UWidgetBlueprint* BP, const UWidget* StartWidget, int32 MaxDepth, TFunctionRef<void(const UWidget*, int32, FName)> Visitor)
{
	if (!BP || !BP->WidgetTree)
	{
		return;
	}

	const UWidget* Root = StartWidget ? StartWidget : ToRawPtr(BP->WidgetTree->RootWidget);
	WalkWidgetTreeRecursive(Root, 0, NAME_None, MaxDepth, Visitor);
}

int32 FWidgetBlueprintOperationUtilsCompat::ComputeWidgetTreeDepth(const UWidgetBlueprint* BP, const UWidget* StartWidget)
{
	if (!BP || !BP->WidgetTree)
	{
		return -1;
	}

	const UWidget* Root = StartWidget ? StartWidget : ToRawPtr(BP->WidgetTree->RootWidget);
	return ComputeDepthRecursive(Root);
}

} // namespace UMGToolSetCompat

#undef LOCTEXT_NAMESPACE

#endif // UE_VERSION_OLDER_THAN(5, 8, 0)
