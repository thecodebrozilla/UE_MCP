// Copyright Epic Games, Inc. All Rights Reserved.

#include "BlueprintEditorLibrary/EditorToolsetCompatLibrary.h"

#include "Internationalization/StringTable.h"
#include "Internationalization/StringTableCore.h"
#include "Engine/CurveTable.h"
#include "Curves/SimpleCurve.h"

#include "EdGraph/EdGraphNode.h"
#include "EdGraphSchema_K2.h"
#include "KismetCompilerMisc.h"
#include "K2Node_CreateDelegate.h"
#include "UObject/UnrealType.h"
#include "UObject/Class.h"

#include "AssetRegistry/AssetRegistryModule.h"
#include "PackageTools.h"
#include "UObject/Package.h"
#include "Misc/PackageName.h"

#define LOCTEXT_NAMESPACE "EditorToolsetCompatLibrary"

namespace
{
	UStringTable* AsStringTable(UObject* InObject)
	{
		return Cast<UStringTable>(InObject);
	}

	UCurveTable* AsCurveTable(UObject* InObject)
	{
		return Cast<UCurveTable>(InObject);
	}

	// Returns the (mutable) simple curve for a row, or nullptr if the row is missing
	// or the table is not storing simple curves.
	FSimpleCurve* FindSimpleCurve(UCurveTable* Table, FName RowName)
	{
		if (!Table || Table->GetCurveTableMode() == ECurveTableMode::RichCurves)
		{
			return nullptr;
		}
		return Table->FindSimpleCurve(RowName, TEXT("EditorToolsetCompatLibrary"), /*bWarnIfNotFound*/ false);
	}
}

// ---- Asset creation -------------------------------------------------------

namespace
{
	// Mirrors UAssetToolsImpl::CreateAsset for the no-factory path: create the
	// package, NewObject the asset, register it and mark the package dirty.
	UObject* CreateAssetNative(const FString& PackagePath, const FString& AssetName, UClass* AssetClass)
	{
		if (!AssetClass || PackagePath.IsEmpty() || AssetName.IsEmpty())
		{
			return nullptr;
		}

		const FString PackageName = UPackageTools::SanitizePackageName(PackagePath + TEXT("/") + AssetName);
		if (FPackageName::DoesPackageExist(PackageName))
		{
			return nullptr;
		}

		UPackage* Pkg = CreatePackage(*PackageName);
		if (!Pkg)
		{
			return nullptr;
		}

		const EObjectFlags Flags = RF_Public | RF_Standalone | RF_Transactional;
		UObject* NewObj = NewObject<UObject>(Pkg, AssetClass, FName(*AssetName), Flags);
		if (NewObj)
		{
			FAssetRegistryModule::AssetCreated(NewObj);
			Pkg->MarkPackageDirty();
		}
		return NewObj;
	}
}

UObject* UEditorToolsetCompatLibrary::CreateStringTableAsset(const FString& PackagePath, const FString& AssetName)
{
	return CreateAssetNative(PackagePath, AssetName, UStringTable::StaticClass());
}

UObject* UEditorToolsetCompatLibrary::CreateCurveTableAsset(const FString& PackagePath, const FString& AssetName)
{
	UObject* NewObj = CreateAssetNative(PackagePath, AssetName, UCurveTable::StaticClass());
	if (UCurveTable* Table = Cast<UCurveTable>(NewObj))
	{
		// Match UCurveTableFactory's default (linear simple curve) so subsequent
		// simple-curve edits are valid and the table is not left in Empty mode.
		FSimpleCurve& Curve = Table->AddSimpleCurve(FName("Curve"));
		Curve.SetKeyInterpMode(RCIM_Linear);
		Table->MarkPackageDirty();
	}
	return NewObj;
}

// ---- StringTable ----------------------------------------------------------

FString UEditorToolsetCompatLibrary::StringTableGetId(UObject* StringTable)
{
	UStringTable* Table = AsStringTable(StringTable);
	return Table ? Table->GetStringTableId().ToString() : FString();
}

FString UEditorToolsetCompatLibrary::StringTableGetNamespace(UObject* StringTable)
{
	UStringTable* Table = AsStringTable(StringTable);
	return Table ? Table->GetStringTable()->GetNamespace() : FString();
}

TArray<FString> UEditorToolsetCompatLibrary::StringTableListKeys(UObject* StringTable)
{
	TArray<FString> Keys;
	if (UStringTable* Table = AsStringTable(StringTable))
	{
		Table->GetStringTable()->EnumerateSourceStrings(
			[&Keys](const FString& InKey, const FString& /*InSourceString*/) -> bool
			{
				Keys.Add(InKey);
				return true;
			});
	}
	return Keys;
}

FString UEditorToolsetCompatLibrary::StringTableGetEntry(UObject* StringTable, const FString& Key)
{
	FString SourceString;
	if (UStringTable* Table = AsStringTable(StringTable))
	{
		Table->GetStringTable()->GetSourceString(Key, SourceString);
	}
	return SourceString;
}

bool UEditorToolsetCompatLibrary::StringTableHasEntry(UObject* StringTable, const FString& Key)
{
	FString SourceString;
	if (UStringTable* Table = AsStringTable(StringTable))
	{
		return Table->GetStringTable()->GetSourceString(Key, SourceString);
	}
	return false;
}

bool UEditorToolsetCompatLibrary::StringTableSetEntry(UObject* StringTable, const FString& Key, const FString& Value)
{
	UStringTable* Table = AsStringTable(StringTable);
	if (!Table || Key.IsEmpty())
	{
		return false;
	}
	Table->GetMutableStringTable()->SetSourceString(Key, Value);
	Table->MarkPackageDirty();
	return true;
}

bool UEditorToolsetCompatLibrary::StringTableRemoveEntry(UObject* StringTable, const FString& Key)
{
	UStringTable* Table = AsStringTable(StringTable);
	if (!Table)
	{
		return false;
	}
	FString Existing;
	if (!Table->GetStringTable()->GetSourceString(Key, Existing))
	{
		return false;
	}
	Table->GetMutableStringTable()->RemoveSourceString(Key);
	Table->MarkPackageDirty();
	return true;
}

bool UEditorToolsetCompatLibrary::StringTableImportCsvFile(UObject* StringTable, const FString& Filename)
{
	UStringTable* Table = AsStringTable(StringTable);
	if (!Table)
	{
		return false;
	}
	const bool bOk = Table->GetMutableStringTable()->ImportStrings(Filename);
	if (bOk)
	{
		Table->MarkPackageDirty();
	}
	return bOk;
}

// ---- CurveTable (Simple curves) -------------------------------------------

TArray<FString> UEditorToolsetCompatLibrary::CurveTableListRows(UObject* CurveTable)
{
	TArray<FString> Rows;
	if (UCurveTable* Table = AsCurveTable(CurveTable))
	{
		for (const TPair<FName, FRealCurve*>& Pair : Table->GetRowMap())
		{
			Rows.Add(Pair.Key.ToString());
		}
	}
	return Rows;
}

bool UEditorToolsetCompatLibrary::CurveTableAddRow(UObject* CurveTable, const FString& RowName)
{
	UCurveTable* Table = AsCurveTable(CurveTable);
	if (!Table)
	{
		return false;
	}
	const FName Row(*RowName);
	if (Table->GetRowMap().Contains(Row))
	{
		return false;
	}
	// AddSimpleCurve checks against RichCurves mode; refuse if the table stores rich curves.
	if (Table->GetCurveTableMode() == ECurveTableMode::RichCurves)
	{
		return false;
	}
	Table->AddSimpleCurve(Row);
	Table->OnCurveTableChanged().Broadcast();
	Table->MarkPackageDirty();
	return true;
}

bool UEditorToolsetCompatLibrary::CurveTableSetRowDefault(UObject* CurveTable, const FString& RowName, float DefaultValue)
{
	UCurveTable* Table = AsCurveTable(CurveTable);
	FSimpleCurve* Curve = FindSimpleCurve(Table, FName(*RowName));
	if (!Curve)
	{
		return false;
	}
	Curve->SetDefaultValue(DefaultValue);
	Table->OnCurveTableChanged().Broadcast();
	Table->MarkPackageDirty();
	return true;
}

bool UEditorToolsetCompatLibrary::CurveTableRemoveRow(UObject* CurveTable, const FString& RowName)
{
	UCurveTable* Table = AsCurveTable(CurveTable);
	if (!Table)
	{
		return false;
	}
	const FName Row(*RowName);
	if (!Table->GetRowMap().Contains(Row))
	{
		return false;
	}
	Table->RemoveRow(Row);
	Table->OnCurveTableChanged().Broadcast();
	Table->MarkPackageDirty();
	return true;
}

bool UEditorToolsetCompatLibrary::CurveTableRenameRow(UObject* CurveTable, const FString& RowName, const FString& NewRowName)
{
	UCurveTable* Table = AsCurveTable(CurveTable);
	if (!Table)
	{
		return false;
	}
	FName Row(*RowName);
	FName NewRow(*NewRowName);
	if (!Table->GetRowMap().Contains(Row) || Table->GetRowMap().Contains(NewRow))
	{
		return false;
	}
	Table->RenameRow(Row, NewRow);
	Table->OnCurveTableChanged().Broadcast();
	Table->MarkPackageDirty();
	return true;
}

bool UEditorToolsetCompatLibrary::CurveTableAddKey(UObject* CurveTable, const FString& RowName, float Time, float Value)
{
	UCurveTable* Table = AsCurveTable(CurveTable);
	FSimpleCurve* Curve = FindSimpleCurve(Table, FName(*RowName));
	if (!Curve)
	{
		return false;
	}
	Curve->AddKey(Time, Value);
	Table->OnCurveTableChanged().Broadcast();
	Table->MarkPackageDirty();
	return true;
}

bool UEditorToolsetCompatLibrary::CurveTableSetKeys(UObject* CurveTable, const FString& RowName,
	const TArray<float>& Times, const TArray<float>& Values)
{
	if (Times.Num() != Values.Num())
	{
		return false;
	}
	UCurveTable* Table = AsCurveTable(CurveTable);
	FSimpleCurve* Curve = FindSimpleCurve(Table, FName(*RowName));
	if (!Curve)
	{
		return false;
	}
	TArray<FSimpleCurveKey> Keys;
	Keys.Reserve(Times.Num());
	for (int32 Index = 0; Index < Times.Num(); ++Index)
	{
		Keys.Emplace(Times[Index], Values[Index]);
	}
	Curve->SetKeys(Keys);
	Table->OnCurveTableChanged().Broadcast();
	Table->MarkPackageDirty();
	return true;
}

TArray<float> UEditorToolsetCompatLibrary::CurveTableGetKeyTimes(UObject* CurveTable, const FString& RowName)
{
	TArray<float> Times;
	if (FSimpleCurve* Curve = FindSimpleCurve(AsCurveTable(CurveTable), FName(*RowName)))
	{
		for (const FSimpleCurveKey& Key : Curve->GetConstRefOfKeys())
		{
			Times.Add(Key.Time);
		}
	}
	return Times;
}

TArray<float> UEditorToolsetCompatLibrary::CurveTableGetKeyValues(UObject* CurveTable, const FString& RowName)
{
	TArray<float> Values;
	if (FSimpleCurve* Curve = FindSimpleCurve(AsCurveTable(CurveTable), FName(*RowName)))
	{
		for (const FSimpleCurveKey& Key : Curve->GetConstRefOfKeys())
		{
			Values.Add(Key.Value);
		}
	}
	return Values;
}

// ---- K2Node_CreateDelegate ------------------------------------------------

bool UEditorToolsetCompatLibrary::IsCreateDelegateNode(UEdGraphNode* Node)
{
	return Cast<UK2Node_CreateDelegate>(Node) != nullptr;
}

FString UEditorToolsetCompatLibrary::GetCreateDelegateFunction(UEdGraphNode* Node)
{
	if (UK2Node_CreateDelegate* DelegateNode = Cast<UK2Node_CreateDelegate>(Node))
	{
		const FName FunctionName = DelegateNode->GetFunctionName();
		return FunctionName.IsNone() ? FString() : FunctionName.ToString();
	}
	return FString();
}

bool UEditorToolsetCompatLibrary::SetCreateDelegateFunction(UEdGraphNode* Node, const FString& FunctionName)
{
	UK2Node_CreateDelegate* DelegateNode = Cast<UK2Node_CreateDelegate>(Node);
	if (!DelegateNode)
	{
		return false;
	}
	DelegateNode->SetFunction(FName(*FunctionName));
	// Mirror the editor combo box: notify the node/graph/blueprint of the change so
	// the bound function is committed and the node reconstructs.
	DelegateNode->HandleAnyChange(/*bForceModify*/ true);
	return DelegateNode->GetFunctionName() == FName(*FunctionName);
}

TArray<FString> UEditorToolsetCompatLibrary::ListCompatibleFunctionsForDelegate(UEdGraphNode* Node)
{
	TArray<FString> Result;
	UK2Node_CreateDelegate* DelegateNode = Cast<UK2Node_CreateDelegate>(Node);
	if (!DelegateNode)
	{
		return Result;
	}

	UFunction* FunctionSignature = DelegateNode->GetDelegateSignature();
	UClass* ScopeClass = DelegateNode->GetScopeClass();
	if (!FunctionSignature || !ScopeClass)
	{
		return Result;
	}

	// Mirror SGraphNodeK2CreateDelegate::CreateBelowPinControls: a function is a valid
	// binding target when its signature is (float-)convertible to the delegate signature
	// and it can be used in a delegate (right flags, not latent, etc.).
	for (TFieldIterator<UFunction> It(ScopeClass); It; ++It)
	{
		UFunction* Func = *It;
		if (Func &&
			(FKismetCompilerUtilities::DoSignaturesHaveConvertibleFloatTypes(Func, FunctionSignature)
				!= ConvertibleSignatureMatchResult::Different) &&
			UEdGraphSchema_K2::FunctionCanBeUsedInDelegate(Func))
		{
			Result.Add(Func->GetFName().ToString());
		}
	}
	return Result;
}

#undef LOCTEXT_NAMESPACE
