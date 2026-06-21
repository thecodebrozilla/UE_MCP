// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SemanticSearchToolset : ModuleRules
{
	public SemanticSearchToolset(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		IWYUSupport = IWYUSupport.Full;
		bUseUnity = true;

		PublicDependencyModuleNames.Add("Core");

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"AssetRegistry",
			"CoreUObject",
			"Engine",
			"Json",
			"SemanticSearch",
			"ToolsetRegistry",
			"UnrealEd",
		});
	}
}
