#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GrowSpot.generated.h"

UCLASS()
class GGJ_API AGrowSpot : public AActor
{
	GENERATED_BODY()
	
public:	
	AGrowSpot();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* Mesh;
};
