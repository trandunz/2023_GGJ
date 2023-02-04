#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/VegetableInterface.h"
#include "Mandrake.generated.h"

UCLASS()
class GGJ_API AMandrake : public AActor, public IVegetableInterface
{
	GENERATED_BODY()
	
public:	
	AMandrake();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void Throw(FVector _direction) override;
	virtual void Harvest() override;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Mesh, meta = (AllowPrivateAccess))
	class UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Audio, meta = (AllowPrivateAccess))
	class USoundWave* ScreamSound;

	bool IsHarvested{};
};
