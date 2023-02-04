#include "GGJGameMode.h"
#include "GGJCharacter.h"
#include "Algo/RandomShuffle.h"
#include "GameFramework/PlayerStart.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

AGGJGameMode::AGGJGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_GGJCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AGGJGameMode::BeginPlay()
{
	Super::BeginPlay();

	SpawnPlayer2();
}

void AGGJGameMode::SpawnPlayer2()
{
	if (Player2Prefab)
	{
		FString outError;
		DefaultPawnClass = Player2Prefab;
		GetGameInstance()->CreateLocalPlayer(1, outError, true);
	}
}

FTransform AGGJGameMode::FindRandomPlayerStart()
{
	TArray<AActor*> spawnPoints{};
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), spawnPoints);
	int randomSpawn = rand() % spawnPoints.Num();
	return spawnPoints[randomSpawn]->GetActorTransform();
}