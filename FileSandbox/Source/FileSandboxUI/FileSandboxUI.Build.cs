// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FileSandboxUI : ModuleRules
{
    public FileSandboxUI(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "Slate", 
                "FileSandboxCore",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "SlateCore",
                "ToolWidgets"
            }
        );
    }
}