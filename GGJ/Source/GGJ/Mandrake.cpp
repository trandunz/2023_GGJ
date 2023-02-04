#include "Mandrake.h"

#include "Kismet/GameplayStatics.h"

AMandrake::AMandrake()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
	Mesh->SetWorldScale3D({0.5f, 0.5f, 0.5f});
}

void AMandrake::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMandrake::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMandrake::Throw(FVector _direction)
{
	Mesh->SetSimulatePhysics(true);
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Mesh->SetCollisionProfileName("BlockAll");
	Mesh->AddImpulse(_direction * 25000);
}

void AMandrake::Harvest()
{
	if (!IsHarvested && ScreamSound)
	{
		IsHarvested = true;
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), ScreamSound, GetActorLocation(), 1, 1, 0, {}, {});
	}
}

