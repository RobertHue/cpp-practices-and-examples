// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class SkeletalMeshTest3EditorTarget : TargetRules
{
	public SkeletalMeshTest3EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("SkeletalMeshTest3");
	}
}
