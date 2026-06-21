// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ConversationToolset : ModuleRules
{
	public ConversationToolset(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.Add("Core");
	}
}
