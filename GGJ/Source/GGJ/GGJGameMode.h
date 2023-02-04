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

	virtual void BeginPlay() override;

	void SpawnPlayer2();

	FTransform FindRandomPlayerStart();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Prefabs, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AGGJCharacter> Player2Prefab;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int P1CurrentCarrotCount{};
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int P2CurrentCarrotCount{};
};



