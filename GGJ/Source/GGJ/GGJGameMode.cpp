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

FTransform AGGJGameMode::FindRandomPlayerStart()
{
	TArray<AActor*> spawnPoints{};
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), spawnPoints);
	int randomSpawn = rand() % spawnPoints.Num();
	return spawnPoints[randomSpawn]->GetActorTransform();
}

void AGGJGameMode::SpawnPlayer(APlayerController* _playerController)
{
	//if (APawn* pawn = _playerController->GetPawn())
	//{
	//	pawn->Destroy();
	//}
//
	//if (AGGJCharacter* playerCharacter = GetWorld()->SpawnActor<AGGJCharacter>(CharacterPrefab, FindRandomPlayerStart()))
	//{
	//	_playerController->Possess(playerCharacter);
	//}
}