#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GrowComponent.generated.h"

UENUM()
enum GROWSTATE
{
	DEAD = 0,
	SEED,
	JUVENILE,
	MATURE,
	HARVESTABLE
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GGJ_API UGrowComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UGrowComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool IsGrowing{};
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float GrowTimer{};

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TEnumAsByte<GROWSTATE> GrowState{};

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int DeadTime{5};
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int SeedTime{2};
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int JuvenileTime{1};
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int MaatureTime{2};
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int HarvestableTime{3};
};
