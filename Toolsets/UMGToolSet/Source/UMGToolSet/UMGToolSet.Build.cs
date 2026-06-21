// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UMGToolSet : ModuleRules
{
	public UMGToolSet(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"ToolsetRegistry",
				"UMG",
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"UnrealEd",
				"Slate",
				"SlateCore",
				"UMGEditor",
				"Kismet",
				"AssetRegistry",
				"MessageLog",
				"BlueprintGraph",
				"MovieScene",
				"MovieSceneTracks",
			}
		);
	}
}
