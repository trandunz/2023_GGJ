#include "Carrot.h"

ACarrot::ACarrot()
{
    PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
}

void ACarrot::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACarrot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

