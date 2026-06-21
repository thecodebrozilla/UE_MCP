// Copyright Epic Games, Inc. All Rights Reserved.

#include "TerminalSubsystem.h"

#include "ConPTYSession.h"
#include "TerminalSettings.h"

#include "Interfaces/IPluginManager.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

void UTerminalSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	DefaultScheme = FTerminalColorScheme::MakeDefault();
	ReloadColorSchemes();
}

void UTerminalSubsystem::Deinitialize()
{
	ColorSchemes.Empty();

	Super::Deinitialize();
}

FTerminalColorScheme UTerminalSubsystem::GetActiveColorScheme() const
{
	const UTerminalSettings* Settings = GetDefault<UTerminalSettings>();
	const FString SchemeName = Settings ? Settings->ColorSchemeName : TEXT("Default");
	return GetColorScheme(SchemeName);
}

FTerminalColorScheme UTerminalSubsystem::GetColorScheme(const FString& Name) const
{
	if (const FTerminalColorScheme* Found = ColorSchemes.Find(Name))
	{
		return *Found;
	}

	UE_LOG(LogTerminal, Warning, TEXT("Color scheme '%ls' not found, using default."), *Name);
	return DefaultScheme;
}

void UTerminalSubsystem::ReloadColorSchemes()
{
	ColorSchemes.Empty();

	// Always register the hardcoded default.
	ColorSchemes.Add(DefaultScheme.Name, DefaultScheme);

	// Find the plugin's Config/ColorSchemes/ directory.
	TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(UE_PLUGIN_NAME);
	if (!Plugin.IsValid())
	{
		return;
	}

	const FString ColorSchemesDirectory = FPaths::Combine(Plugin->GetBaseDir(), TEXT("Config"), TEXT("ColorSchemes"));
	if (!FPaths::DirectoryExists(ColorSchemesDirectory))
	{
		return;
	}

	// Scan for JSON files.
	TArray<FString> JSONFiles;
	IFileManager::Get().FindFiles(JSONFiles, *FPaths::Combine(ColorSchemesDirectory, TEXT("*.json")), true, false);

	for (const FString& FileName : JSONFiles)
	{
		const FString FilePath = FPaths::Combine(ColorSchemesDirectory, FileName);
		FString JSONContent;
		if (FFileHelper::LoadFileToString(JSONContent, *FilePath))
		{
			FTerminalColorScheme Scheme;
			if (FTerminalColorScheme::FromJSON(JSONContent, Scheme) && !Scheme.Name.IsEmpty())
			{
				ColorSchemes.Add(Scheme.Name, Scheme);
				UE_LOG(LogTerminal, Verbose, TEXT("Loaded color scheme: %ls"), *Scheme.Name);
			}
			else
			{
				UE_LOG(LogTerminal, Warning, TEXT("Failed to parse color scheme file: %ls"), *FilePath);
			}
		}
	}

	UE_LOG(LogTerminal, Display, TEXT("Loaded %d terminal color scheme(s)."), ColorSchemes.Num());
}
