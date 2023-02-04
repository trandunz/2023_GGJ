#include "VegetableBox.h"

#include "Carrot.h"
#include "Components/BoxComponent.h"
#include "GGJGameMode.h"
#include "Interfaces/VegetableInterface.h"

AVegetableBox::AVegetableBox()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Trigger->SetupAttachment(Mesh);
	Trigger->SetupAttachment(Mesh);
	Trigger->SetBoxExtent({100,100,100});
	Trigger->SetCollisionProfileName("Trigger");
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AVegetableBox::OnBeginOverlap);
}

void AVegetableBox::BeginPlay()
{
	Super::BeginPlay();
	
}

void AVegetableBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVegetableBox::OnBeginOverlap(UPrimitiveComponent* Comp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
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

