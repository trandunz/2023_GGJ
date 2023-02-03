#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GGJGameMode.generated.h"

class AGGJCharacter;
UCLASS(minimalapi)
class AGGJGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGGJGameMode();

	FTransform FindRandomPlayerStart();
	void SpawnPlayer(APlayerController* _playerController);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Prefabs, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AGGJCharacter> CharacterPrefab;
};



