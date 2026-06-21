// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class WorldConditionsToolset : ModuleRules
{
	public WorldConditionsToolset(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.Add("Core");
		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"CoreUObject",
			"Engine",
			"Json",
			"ToolsetRegistry",
			"UnrealEd",
			"WorldConditions",
		});
	}
}
