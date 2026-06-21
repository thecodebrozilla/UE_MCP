// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GameplayTagsToolset : ModuleRules
{
	public GameplayTagsToolset(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		IWYUSupport = IWYUSupport.Full;
		bUseUnity = true;

		PublicDependencyModuleNames.Add("Core");

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"AssetRegistry",
			"CoreUObject",
			"EditorScriptingUtilities",
			"Engine",
			"GameplayTags",
			"GameplayTagsEditor",
			"Kismet",
			"ToolsetRegistry",
			"UnrealEd",
		});
	}
}
