// Copyright Epic Games, Inc. All Rights Reserved.

namespace UnrealBuildTool.Rules
{
	public class LiveCodingToolsetTests : ModuleRules
	{
		public LiveCodingToolsetTests(ReadOnlyTargetRules Target) : base(Target)
		{
			PrivateDependencyModuleNames.AddRange(new string[]
			{
				"Core",
				"CoreUObject",
				"CQTest",
				"Engine",
				"LiveCodingToolset",
				"ToolsetRegistry",
				"UnrealEd",
			});
		}
	}
}
