// Copyright Epic Games, Inc. All Rights Reserved.

namespace UnrealBuildTool.Rules
{
	public class AutomationTestToolset : ModuleRules
	{
		public AutomationTestToolset(ReadOnlyTargetRules Target) : base(Target)
		{
			PublicDependencyModuleNames.AddRange(
				new string[] {
					"ToolsetRegistry",
				}
			);

			PrivateDependencyModuleNames.AddRange(
				new string[] {
					"AutomationController",
					"AutomationTest",
					"Core",
					"CoreUObject",
					"EditorSubsystem",
					"Engine",
					"Json",
					"SessionServices",
					"UnrealEd",
				}
			);
		}
	}
}
