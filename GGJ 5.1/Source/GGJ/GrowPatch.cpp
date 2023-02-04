#include "GrowPatch.h"
#include "Components/StaticMeshComponent.h"
#include "GrowSpot.h"

AGrowPatch::AGrowPatch()
{
	PrimaryActorTick.bCanEverTick = true;
}

FVector AGrowPatch::GetClosestGridPosition(FVector& _inVec)
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

bool AGrowPatch::IsGridPositionValid(FVector _inVec)
{
	return {};
}

void AGrowPatch::PopulateGrid()
{
	if (GridCellPrefab)
	{
		GridArray = {};
	
		float worldOffset = ((WorldGridSize * GridSize) * 0.5f) - (WorldGridSize* 0.5f);
		for(int i = 0; i < GridSize; i++)
		{
			for(int y = 0; y < GridSize; y++)
			{
				auto a = y * WorldGridSize;
				auto b = i * WorldGridSize;

				auto da = a - worldOffset;
				auto db = b - worldOffset;

				FVector vec {da, db, GetActorLocation().Z};
				vec += GetActorLocation();

				FActorSpawnParameters params{};
				GridArray.Add(GetWorld()->SpawnActor<AGrowSpot>(GridCellPrefab, vec, FRotator(FQuat::Identity)));
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
