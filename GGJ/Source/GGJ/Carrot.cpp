#include "Carrot.h"

ACarrot::ACarrot()
{
    PrimaryActorTick.bCanEverTick = true;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
	Mesh->SetWorldScale3D({0.5f, 0.5f, 0.5f});
}

void ACarrot::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACarrot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACarrot::SetSimulatePhysics(bool _simulatePhysics)
{
	Mesh->SetSimulatePhysics(_simulatePhysics);
}

void ACarrot::Throw(FVector _direction)
{
	Mesh->SetSimulatePhysics(true);
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Mesh->SetCollisionProfileName("BlockAll");
	Mesh->AddImpulse(_direction * 25000);
}

