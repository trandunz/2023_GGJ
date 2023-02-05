#include "Beet.h"
#include "Components/StaticMeshComponent.h"

ABeet::ABeet()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
	Mesh->SetWorldScale3D({0.5f, 0.5f, 0.5f});
}

void ABeet::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABeet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABeet::SetSimulatePhysics(bool _simulatePhysics)
{
	Mesh->SetSimulatePhysics(_simulatePhysics);
}

void ABeet::Throw(FVector _direction)
{
	Mesh->SetSimulatePhysics(true);
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Mesh->SetCollisionProfileName("BlockAll");
	Mesh->AddImpulse(_direction *  2000);
}

void ABeet::Harvest()
{
}


