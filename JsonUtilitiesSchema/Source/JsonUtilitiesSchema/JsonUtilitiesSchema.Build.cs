// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class JsonUtilitiesSchema : ModuleRules
{
	public JsonUtilitiesSchema(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Json",
				"JsonUtilities"
			});

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Engine"
			});
	}
}
