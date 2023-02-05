// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Widget_PauseMenu.generated.h"

/**
 * 
 */
UCLASS()
class GGJ_API UWidget_PauseMenu : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Buttons, meta = (BindWidget))
	class UButton* Resume_Button;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Buttons, meta = (BindWidget))
	class UButton* Home_Button;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Buttons, meta = (BindWidget))
	class UButton* Quit_Button;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= loadName)
	FName LevelLoad_Name;

	UFUNCTION()
	void HideWidget(bool _hideState);
	
private:
	UFUNCTION()
	void ResumeGame();
	UFUNCTION()
	void ChangeScene();
	UFUNCTION()
	void QuitApplication();

protected:
	virtual void NativeOnInitialized() override;
	
};
