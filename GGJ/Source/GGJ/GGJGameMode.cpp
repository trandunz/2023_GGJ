#include "GGJGameMode.h"
#include "GGJCharacter.h"
#include "Algo/RandomShuffle.h"
#include "Controllers/GGJPlayerController.h"
#include "GameFramework/GameSession.h"
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

	PrimaryActorTick.bStartWithTickEnabled = true;
	PrimaryActorTick.bCanEverTick = true;
}

void AGGJGameMode::BeginPlay()
{
	Super::BeginPlay();


	
	SpawnPlayer2();

	RoundTimer = RoundTime;
}

void AGGJGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (RoundTimer > 0)
	{
		RoundTimer -= DeltaSeconds;
	}
	else if (!GameOver)
	{
		GameOver = true;
		// Show Win Screen

		if (!EndScreen && EndScreenPrefab)
		{
			if (AGGJPlayerController* controlller = Cast<AGGJPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0)))
			{
				EndScreen = CreateWidget<UWidget_EndScreen>(controlller, EndScreenPrefab);
				EndScreen->AddToViewport();
				controlller->bShowMouseCursor = true;
				controlller->SetInputMode(FInputModeUIOnly{});
			}
		}
	}
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

void AGGJGameMode::ResetGamemode()
{
	Super::ResetLevel();

	SpawnPlayer2();
}

FTransform AGGJGameMode::FindRandomPlayerStart()
{
	TArray<AActor*> spawnPoints{};
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), spawnPoints);
	int randomSpawn = rand() % spawnPoints.Num();
	return spawnPoints[randomSpawn]->GetActorTransform();
}
