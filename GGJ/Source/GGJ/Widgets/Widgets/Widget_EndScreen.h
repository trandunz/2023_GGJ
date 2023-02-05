#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Widget_EndScreen.generated.h"

class UTextBlock;
class UButton;
UCLASS()
class GGJ_API UWidget_EndScreen : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= TEXT, meta = (BindWidget))
	UTextBlock* Player1_Carrots;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= TEXT, meta = (BindWidget))
	UTextBlock* Player2_Carrots;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= TEXT, meta = (BindWidget))
	//UButton* HomeButton;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= TEXT, meta = (BindWidget))
	UButton* ReplayButton;

	virtual void NativeOnInitialized() override;
	
	UFUNCTION(BlueprintCallable)
	void GoHome();
	UFUNCTION()
	void Replay();
};
