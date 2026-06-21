// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BlueprintGraphEditorPort : ModuleRules
{
	public BlueprintGraphEditorPort(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"BlueprintGraph",
				"BlueprintEditorLibrary"
			});

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"AnimGraph",
				"AssetRegistry",
				"CoreUObject",
				"Engine",
				"Json",
				"JsonUtilities",
				"JsonUtilitiesSchema",
				"KismetCompiler",
				"UnrealEd"
			});
	}
}
