// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SlateInspectorToolsetTests : ModuleRules
{
	public SlateInspectorToolsetTests(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"CQTest",
			"Engine",
			"InputCore",
			"Slate",
			"SlateCore",
			"SlateInspectorToolset",
		});
	}
}
