#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VegetableBox.generated.h"

UCLASS()
class GGJ_API AVegetableBox : public AActor
{
	GENERATED_BODY()
	
public:	
	AVegetableBox();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* Mesh;
};
