#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/VegetableInterface.h"
#include "Beet.generated.h"

UCLASS()

class GGJ_API ABeet : public AActor, public IVegetableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABeet();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	void SetSimulatePhysics(bool _simulatePhysics);

	virtual void Throw(FVector _direction) override;
	virtual void Harvest() override;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Mesh, meta = (AllowPrivateAccess))
	class UStaticMeshComponent* Mesh;
};
