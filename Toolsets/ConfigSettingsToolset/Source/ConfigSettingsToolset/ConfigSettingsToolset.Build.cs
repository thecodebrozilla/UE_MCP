// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ConfigSettingsToolset : ModuleRules
{
	public ConfigSettingsToolset(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
			}
			);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Kismet",
				"Settings",
				"SourceControl",
				"ToolsetRegistry",
			}
			);
	}
}
