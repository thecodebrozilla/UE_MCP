// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ModelContextProtocolTests : ModuleRules
{
	public ModelContextProtocolTests(ReadOnlyTargetRules Target) : base(Target)
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
				"CoreUObject",
				"Analytics",
				"AnalyticsET",
				"Json",
				"JsonUtilities",
				"HTTPServer",
				"HTTP",
				"ModelContextProtocol",
				"ModelContextProtocolEngine"
			});

		PrivateIncludePaths.Add(System.IO.Path.Combine(ModuleDirectory, "..", "ModelContextProtocol", "Private", "Tests"));
	}
}
