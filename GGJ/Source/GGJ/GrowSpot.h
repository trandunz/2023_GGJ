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

	AActor* Harvest();

protected:
	virtual void BeginPlay() override;
	void DebugSpriteColorChange();

public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* Comp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AActor* ActiveVegetable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UGrowComponent* GrowComponent;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	float SpawnTimer{};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	class UBoxComponent* Trigger;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	TSubclassOf<ACarrot> CarrotPrefab;
};
