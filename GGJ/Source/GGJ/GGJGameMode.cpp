// Copyright Epic Games, Inc. All Rights Reserved.

#include "GGJGameMode.h"
#include "GGJCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGGJGameMode::AGGJGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
