// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TerminalTests : ModuleRules
{
	public TerminalTests(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core"
			});

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"ApplicationCore",
				"CoreUObject",
				"Engine",
				"InputCore",
				"Slate",
				"SlateCore",
				"Terminal",
				"UnrealEd"
			});
	}
}
