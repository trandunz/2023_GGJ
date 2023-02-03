#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GrowSpot.generated.h"

class ACarrot;
UCLASS()
class GGJ_API AGrowSpot : public AActor
{
	GENERATED_BODY()
	
public:	
	AGrowSpot();

protected:
	virtual void BeginPlay() override;
	void DebugSpriteColorChange();

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AActor* ActiveVegetable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UGrowComponent* GrowComponent;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	float SpawnTimer{};

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	TSubclassOf<ACarrot> CarrotPrefab;
};
