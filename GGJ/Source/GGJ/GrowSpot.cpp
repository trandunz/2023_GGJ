#include "GrowSpot.h"

AGrowSpot::AGrowSpot()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
	Mesh->SetCollisionProfileName(FName("Trigger"));
}

void AGrowSpot::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGrowSpot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

