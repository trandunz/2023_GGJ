#include "GrowComponent.h"

#include "GGJ/GrowSpot.h"

UGrowComponent::UGrowComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UGrowComponent::BeginPlay()
{
	Super::BeginPlay();
	StartPos = GetOwner()->GetActorLocation();
}


void UGrowComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsGrowing)
	{
		if (GrowTimer > 0)
		{
			GrowTimer -= DeltaTime;
		}
		else
		{
			if (AGrowSpot* growSpot = Cast<AGrowSpot>(GetOwner()))
			{
				if (growSpot->ActiveVegetable)
				{
					switch(GrowState)
					{
					case DEAD:
						{
							GrowTimer = DeadTime;
							GrowState = SEED;
							break;
						}
					case SEED:
						{
							growSpot->ActiveVegetable->SetActorLocation(StartPos + FVector::DownVector * 25.0f);
					
							GrowTimer = SeedTime;
							GrowState = JUVENILE;
							break;
						}
					case JUVENILE:
						{
							growSpot->ActiveVegetable->SetActorLocation(StartPos);
							GrowTimer = JuvenileTime;
							GrowState = MATURE;
							break;
						}
					case MATURE:
						{
							growSpot->ActiveVegetable->SetActorLocation(StartPos + FVector::UpVector * 25.0f);
							GrowTimer = MatureTime;
							GrowState = HARVESTABLE;
							break;
						}
					case HARVESTABLE:
						{
							growSpot->ActiveVegetable->SetActorLocation(StartPos + FVector::UpVector * 50.0f);
							GrowTimer = HarvestableTime;
							GrowState = DEAD;
							break;
						}
					default:
						break;
					}
				}
			}
			
		}
	}
}

