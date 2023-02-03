#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GGJPlayerController.generated.h"

UCLASS()
class GGJ_API AGGJPlayerController : public APlayerController
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

	UFUNCTION(Reliable, Server, WithValidation)
	void Server_SpawnPlayer();
	void Server_SpawnPlayer_Implementation();
	bool Server_SpawnPlayer_Validate();
};
