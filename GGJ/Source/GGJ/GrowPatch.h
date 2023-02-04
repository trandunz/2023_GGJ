#pragma once

#include "CoreMinimal.h"
#include "GrowSpot.h"
#include "GameFramework/Actor.h"
#include "GrowPatch.generated.h"

UCLASS()
class GGJ_API AGrowPatch : public AActor
{
	GENERATED_BODY()
	
public:	
	AGrowPatch();

	UFUNCTION()
	FVector GetClosestGridPosition(FVector _inVec);

	UFUNCTION()
	AActor* HarvestClosestGridPosition(FVector _inVec);

	UFUNCTION()
	bool IsGridPositionValid(FVector _inVec);

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void PopulateGrid();

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AGrowSpot> GridCellPrefab;
	
public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	int GridSizeX = 10;
	UPROPERTY(EditAnywhere)
	int GridSizeY = 10;

	UPROPERTY(EditAnywhere)
	int WorldGridSize = 1000;

	UPROPERTY(EditAnywhere)
	TArray<AGrowSpot*> GridArray;
};
