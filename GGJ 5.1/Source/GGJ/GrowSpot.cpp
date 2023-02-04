#include "GrowSpot.h"

#include "Carrot.h"
#include "Components/GrowComponent.h"

AGrowSpot::AGrowSpot()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
	Mesh->SetCollisionProfileName(FName("Trigger"));

	GrowComponent = CreateDefaultSubobject<UGrowComponent>(TEXT("Grow Component"));
}

void AGrowSpot::BeginPlay()
{
	Super::BeginPlay();
	
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
			UE_LOG(LogTemp, Warning, TEXT("Found Static Mesh On Grow Spot") );
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
		ActiveVegetable = GetWorld()->SpawnActor<ACarrot>(CarrotPrefab, GetActorLocation(), FRotator(FQuat::Identity));
	}
}

