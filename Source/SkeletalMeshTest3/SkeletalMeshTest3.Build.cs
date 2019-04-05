// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SkeletalMeshTest3 : ModuleRules
{
	public SkeletalMeshTest3(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "HeadMountedDisplay"
        });

        /*
        // shouldn't be needed because setup by unreal
        PrivateIncludePaths.AddRange(new string[] {
            ".",
        });
        */
    }
}