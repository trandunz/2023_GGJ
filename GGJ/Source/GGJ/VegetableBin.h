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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Mesh)
	class UStaticMeshComponent* Mesh;

	
};
