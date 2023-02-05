#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GGJ/Widgets/Widgets/Widget_EndScreen.h"
#include "GGJGameMode.generated.h"

class AGGJCharacter;
UCLASS(minimalapi)
class AGGJGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGGJGameMode();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	void SpawnPlayer2();

	UFUNCTION()
	void ResetGamemode();

	FTransform FindRandomPlayerStart();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Prefabs, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AGGJCharacter> Player2Prefab;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Prefabs, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UWidget_EndScreen> EndScreenPrefab;

	UWidget_EndScreen* EndScreen;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float RoundTimer{};
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float RoundTime{90};
	bool GameOver{};
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int P1CurrentCarrotCount{};
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int P2CurrentCarrotCount{};
};



