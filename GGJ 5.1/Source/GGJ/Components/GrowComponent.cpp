#include "GrowComponent.h"

UGrowComponent::UGrowComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UGrowComponent::BeginPlay()
{
	Super::BeginPlay();
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
					GrowTimer = SeedTime;
					GrowState = JUVENILE;
					break;
				}
			case JUVENILE:
				{
					GrowTimer = JuvenileTime;
					GrowState = MATURE;
					break;
				}
			case MATURE:
				{
					GrowTimer = MaatureTime;
					GrowState = HARVESTABLE;
					break;
				}
			case HARVESTABLE:
				{
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

