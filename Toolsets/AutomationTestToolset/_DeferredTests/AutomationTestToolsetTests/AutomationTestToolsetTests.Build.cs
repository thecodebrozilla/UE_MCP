// Copyright Epic Games, Inc. All Rights Reserved.

namespace UnrealBuildTool.Rules
{
	public class AutomationTestToolsetTests : ModuleRules
	{
		public AutomationTestToolsetTests(ReadOnlyTargetRules Target) : base(Target)
		{
			PrivateDependencyModuleNames.AddRange(new string[]
			{
				"AutomationController",
				"AutomationTestToolset",
				"Core",
				"CoreUObject",
				"CQTest",
				"Engine",
				"UnrealEd",
			});
		}
	}
}
