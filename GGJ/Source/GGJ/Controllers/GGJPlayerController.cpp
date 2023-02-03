#include "GGJPlayerController.h"

#include "GGJ/GGJGameMode.h"
#include "Kismet/GameplayStatics.h"

void AGGJPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (IsLocalPlayerController())
	{
		Server_SpawnPlayer();
	}
}

void AGGJPlayerController::Server_SpawnPlayer_Implementation()
{
	if (AGGJGameMode* gameMode = Cast<AGGJGameMode>(UGameplayStatics::GetGameMode(GetWorld())))
	{
		gameMode->SpawnPlayer(this);
	}
}

bool AGGJPlayerController::Server_SpawnPlayer_Validate()
{
	return true;
}
