// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE_AssignmentGameMode.h"
#include "UE_AssignmentCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE_AssignmentGameMode::AUE_AssignmentGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
