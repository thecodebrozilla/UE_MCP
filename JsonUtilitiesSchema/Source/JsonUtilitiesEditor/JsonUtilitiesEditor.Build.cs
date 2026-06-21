// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class JsonUtilitiesEditor : ModuleRules
{
	public JsonUtilitiesEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"UnrealEd",
				"Slate",
				"SlateCore",
				"Json",
				"JsonUtilities",
				"JsonUtilitiesSchema",
				"BlueprintGraph",
				"AssetTools"
			});

		// The editor schema generator reaches into the runtime module's private
		// JsonSchema headers (e.g. JsonSchema/JsonSchemaVisitorStack.h).
		PrivateIncludePaths.Add(
			System.IO.Path.Combine(GetModuleDirectory("JsonUtilitiesSchema"), "Private"));
	}
}
