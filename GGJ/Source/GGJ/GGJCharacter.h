#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "InputMappingContext.h"
#include "GGJ/Widgets/Widget_GameScreen.h"
#include "GGJCharacter.generated.h"

class AGrowPatch;
UCLASS(config=Game)
class AGGJCharacter : public ACharacter
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* HarvestAction;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Prefabs, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AGrowPatch> GrowPatchPrefab;

	UPROPERTY(EditAnywhere, BlueprintreadOnly, Category = PlayerUI, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UWidget_GameScreen> GameScreenPrefab;
	
public:
	AGGJCharacter();
	
protected:
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void BeginPlay();
	virtual void Tick(float DeltaSeconds) override;

	virtual void TryHarvest();
	
private:
	void SpawnPlayerPatch();

	void InitaliseWidgets();
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class AGrowSpot* LastGrowSpot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class AGrowPatch* PlayerPatch;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UWidget_GameScreen* GameScreenWidget;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 PlayerIndex{};

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class AActor* CurrentVegetable;
};

