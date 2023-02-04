#include "GrowPatch.h"
#include "Components/StaticMeshComponent.h"
#include "GrowSpot.h"

AGrowPatch::AGrowPatch()
{
	PrimaryActorTick.bCanEverTick = true;
}

FVector AGrowPatch::GetClosestGridPosition(FVector _inVec)
{
	if (GridArray.Num() > 0)
	{
		FVector closestPos = GridArray[0]->GetActorLocation();
		float closestDist = FVector::Distance(_inVec, GridArray[0]->GetActorLocation());

		for(auto& cell : GridArray)
		{
			if (FVector::Distance(_inVec, cell->GetActorLocation()) < closestDist)
			{
				closestDist = FVector::Distance(_inVec, cell->GetActorLocation());
				closestPos = cell->GetActorLocation();
			}
		}
		return closestPos;
	}
	return {};
}

AActor* AGrowPatch::HarvestClosestGridPosition(FVector _inVec)
{
	if (GridArray.Num() > 0)
	{
		AGrowSpot* closestSpot = GridArray[0];
		float closestDist = FVector::Distance(_inVec, GridArray[0]->GetActorLocation());
		int closestIndex = 0;
			
		for(int i = 0; i < GridArray.Num(); i++)
		{
			if (FVector::Distance(_inVec, GridArray[i]->GetActorLocation()) < closestDist)
			{
				closestIndex = i;
				closestDist = FVector::Distance(_inVec, GridArray[i]->GetActorLocation());
				closestSpot = GridArray[i];
			}
		}
		GridArray.RemoveAt(closestIndex);
		GridArray.Shrink();
		return closestSpot->Harvest();
	}

	return nullptr;
}

bool AGrowPatch::IsGridPositionValid(FVector _inVec)
{
	return {};
}

void AGrowPatch::PopulateGrid()
{
	if (GridCellPrefab)
	{
		GridArray = {};
	
		float worldOffset = ((WorldGridSize * (((GridSizeX + GridSizeY)/2) / 2)) * 0.5f) - (WorldGridSize* 0.5f);
		for(int i = 0; i < GridSizeX; i++)
		{
			for(int y = 0; y < GridSizeY; y++)
			{
				if (y <= (((GridSizeX + GridSizeY)/2) / 2) - 1 ||  y >= (((GridSizeX + GridSizeY)/2) / 2) + 1 )
				{
					if (i <= (((GridSizeX + GridSizeY)/2) / 2) - 1 ||  i >= (((GridSizeX + GridSizeY)/2) / 2) + 1 )
					{
						auto a = y * WorldGridSize;
						auto b = i * WorldGridSize;

						auto da = a - worldOffset;
						auto db = b - worldOffset;

						FVector vec {da, db, GetActorLocation().Z};
						vec += GetActorLocation();

						FActorSpawnParameters params{};
						GridArray[GridArray.Add(GetWorld()->SpawnActor<AGrowSpot>(GridCellPrefab, vec, FRotator(FQuat::Identity)))]->SetActorScale3D({0.5f,0.5f,0.5f});
					}
				}
				
			}
		}
	}
}

void AGrowPatch::BeginPlay()
{
	Super::BeginPlay();
	PopulateGrid();
}

void AGrowPatch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

