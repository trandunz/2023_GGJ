#include "VegetableBox.h"

AVegetableBox::AVegetableBox()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
}

void AVegetableBox::BeginPlay()
{
	Super::BeginPlay();
	
}

void AVegetableBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

