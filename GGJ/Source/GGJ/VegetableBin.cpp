#include "VegetableBin.h"

#include "Carrot.h"
#include "GGJGameMode.h"
#include "Components/BoxComponent.h"
#include "Interfaces/VegetableInterface.h"
#include "Kismet/GameplayStatics.h"

AVegetableBin::AVegetableBin()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Trigger->SetupAttachment(Mesh);
	Trigger->SetBoxExtent({100,100,100});
	Trigger->SetCollisionProfileName("Trigger");
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AVegetableBin::OnBeginOverlap);
}

void AVegetableBin::BeginPlay()
{
	Super::BeginPlay();
}

void AVegetableBin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVegetableBin::OnBeginOverlap(UPrimitiveComponent* Comp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
		if (ACarrot* carrot = Cast<ACarrot>(OtherActor))
		{
			if (AGGJGameMode * gameMode = (AGGJGameMode*)GetWorld()->GetAuthGameMode())
			{
				if (IsPlayerOne)
					gameMode->P1CurrentCarrotCount++;
				else
					gameMode->P2CurrentCarrotCount++;
			}
			OtherActor->Destroy();
		}
	}
}

