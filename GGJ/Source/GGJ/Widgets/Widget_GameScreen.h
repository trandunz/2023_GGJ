
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
// #include "AdvancedWidgets/Public/Components/RadialSlider.h"
#include "Widget_GameScreen.generated.h"


UCLASS()
class GGJ_API UWidget_GameScreen : public UUserWidget
{
	GENERATED_BODY()
public:
	// UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Timer, meta = (BindWidget))
	// URadialSlider* Timer_RadialSlider;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Timer, meta = (BindWidget))
	FText Timer_Text;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Timer)
	float MaxTime = 60.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= TEXT, meta = (BindWidget))
	FText LCarrotCount_Text;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= TEXT, meta = (BindWidget))
	FText RCarrotCount_Text;

	
	virtual void NativeOnInitialized() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
	UFUNCTION(BlueprintCallable)
	void SetTimerValue(float _Fincrease);
	
};
