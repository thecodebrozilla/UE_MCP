// Copyright Epic Games, Inc. All Rights Reserved.

namespace UnrealBuildTool.Rules
{
	public class SlateInspectorToolset : ModuleRules
	{
		public SlateInspectorToolset(ReadOnlyTargetRules Target) : base(Target)
		{
			PublicDependencyModuleNames.AddRange(
				new string[] {
					"ToolsetRegistry",
				}
			);

			PrivateDependencyModuleNames.AddRange(
				new string[] {
					"Core",
					"CoreUObject",
					"EditorSubsystem",
					"Engine",
					"ImageWrapper",
					"InputCore",
					"Slate",
					"SlateCore",
					"UnrealEd",
				}
			);
		}
	}
}
