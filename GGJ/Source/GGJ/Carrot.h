#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/VegetableInterface.h"
#include "Carrot.generated.h"

UCLASS()
class GGJ_API ACarrot : public AActor, public IVegetableInterface
{
	GENERATED_BODY()
	
public:	
	ACarrot();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	void SetSimulatePhysics(bool _simulatePhysics);

	virtual void Throw(FVector _direction) override;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Mesh, meta = (AllowPrivateAccess))
	class UStaticMeshComponent* Mesh;
};
