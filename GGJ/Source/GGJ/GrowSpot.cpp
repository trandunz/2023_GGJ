#include "GrowSpot.h"

#include "Carrot.h"
#include "Mandrake.h"
#include "GGJCharacter.h"
#include "Components/BoxComponent.h"
#include "Components/GrowComponent.h"

AGrowSpot::AGrowSpot()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
	Mesh->SetCollisionProfileName(FName("Trigger"));

	GrowComponent = CreateDefaultSubobject<UGrowComponent>(TEXT("Grow Component"));

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Trigger->SetupAttachment(Mesh);
	Trigger->SetBoxExtent({50,50,50});
	Trigger->SetCollisionProfileName(FName("Trigger"));
	Trigger->SetGenerateOverlapEvents(true);


}

AActor* AGrowSpot::Harvest()
{
	AActor* activeVeg = ActiveVegetable;
	ActiveVegetable = nullptr;
	return activeVeg;
}

void AGrowSpot::BeginPlay()
{
	Super::BeginPlay();
	if (Trigger)
	{
		Trigger->OnComponentBeginOverlap.RemoveDynamic(
			   this, &AGrowSpot::OnBeginOverlap);

		Trigger->OnComponentBeginOverlap.AddDynamic(
			   this, &AGrowSpot::OnBeginOverlap);
	}
}

void AGrowSpot::DebugSpriteColorChange()
{
	
}

void AGrowSpot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GrowComponent && ActiveVegetable)
	{
		if (UStaticMeshComponent* mesh = Cast<UStaticMeshComponent>(ActiveVegetable->GetComponentByClass(UStaticMeshComponent::StaticClass())))
		{
			
			auto currentMat = mesh->CreateDynamicMaterialInstance(0);

			switch(GrowComponent->GrowState)
			{
			case DEAD:
				{
					ActiveVegetable->Destroy();
					ActiveVegetable = nullptr;
					break;
				}
			case SEED:
				{
					currentMat->SetVectorParameterValue(FName("Color"), FLinearColor::Red);
					break;
				}
			case JUVENILE:
				{
					currentMat->SetVectorParameterValue(FName("Color"), FColor::Orange);
					break;
				}
			case MATURE:
				{
					currentMat->SetVectorParameterValue(FName("Color"), FLinearColor::Yellow);
					break;
				}
			case HARVESTABLE:
				{
					currentMat->SetVectorParameterValue(FName("Color"), FLinearColor::Green);
					break;
				}
			default:
				currentMat->SetVectorParameterValue(FName("Color"), FLinearColor::Red);
				break;
			}
				
			mesh->SetMaterial(0, currentMat);
		}
			
	}
	else if (CarrotPrefab && !ActiveVegetable)
	{
		int randomSelection = rand() % 2;
		if (randomSelection == 0)
		{
			ActiveVegetable = GetWorld()->SpawnActor<ACarrot>(CarrotPrefab, GetActorLocation(), FRotator(FQuat::Identity));
		}
		else if (randomSelection == 1)
		{
			ActiveVegetable = GetWorld()->SpawnActor<AMandrake>(MangrovePrefab, GetActorLocation(), FRotator(FQuat::Identity));
		}
	}
}

void AGrowSpot::OnBeginOverlap(UPrimitiveComponent* Comp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && 
	 (OtherActor != this))
	{
		if (AGGJCharacter* character = Cast<AGGJCharacter>(OtherActor))
		{
			character->LastGrowSpot = this;
		}
	}
}

