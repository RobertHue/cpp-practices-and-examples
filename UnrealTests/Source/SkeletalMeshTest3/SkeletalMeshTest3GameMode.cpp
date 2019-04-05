// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "SkeletalMeshTest3GameMode.h"
#include "SkeletalMeshTest3Character.h"
#include "UObject/ConstructorHelpers.h"

ASkeletalMeshTest3GameMode::ASkeletalMeshTest3GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
