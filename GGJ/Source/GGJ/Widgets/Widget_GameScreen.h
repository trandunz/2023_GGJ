
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
// #include "AdvancedWidgets/Public/Components/RadialSlider.h"
#include "Widget_GameScreen.generated.h"


class UTextBlock;
UCLASS()
class GGJ_API UWidget_GameScreen : public UUserWidget
{
	GENERATED_BODY()
public:
	// UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Timer, meta = (BindWidget))
	// URadialSlider* Timer_RadialSlider;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Timer, meta = (BindWidget))
	UTextBlock* Timer_Text;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Timer)
	float MaxTime = 60.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= TEXT, meta = (BindWidget))
	UTextBlock* LCarrotCount_Text1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= TEXT, meta = (BindWidget))
	UTextBlock* RCarrotCount_Text2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= TEXT, meta = (BindWidget))
	class URadialSlider* RadialSliderTimer;

	
	virtual void NativeOnInitialized() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
	UFUNCTION()
	void SetTimerValue();

	UFUNCTION()
	void SetPlayer1Carrots();

	UFUNCTION()
	void SetPlayer2Carrots();
	
};
