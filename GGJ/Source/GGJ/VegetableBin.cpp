#include "VegetableBin.h"

AVegetableBin::AVegetableBin()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
}

void AVegetableBin::BeginPlay()
{
	Super::BeginPlay();
}

void AVegetableBin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

