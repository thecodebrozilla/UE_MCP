// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ModelContextProtocol : ModuleRules
{
	public ModelContextProtocol(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"Analytics",
				"AnalyticsET",
				"HTTPServer",
				"JsonUtilities",
				"Json"
			});

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject"
			});
	}
}
