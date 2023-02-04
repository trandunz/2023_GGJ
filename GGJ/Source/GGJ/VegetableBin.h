#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VegetableBin.generated.h"

UCLASS()
class GGJ_API AVegetableBin : public AActor
{
	GENERATED_BODY()
	
public:	
	AVegetableBin();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* Comp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Mesh)
	class UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Collision)
	class UBoxComponent* Trigger;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Collision)
	bool IsPlayerOne{true};
};
