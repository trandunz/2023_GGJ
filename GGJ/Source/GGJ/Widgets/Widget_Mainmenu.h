
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Widget_Mainmenu.generated.h"



UCLASS()
class GGJ_API UWidget_Mainmenu : public UUserWidget
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= buttons, meta = (BindWidget))
	class UButton* Play_Button;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= buttons, meta = (BindWidget))
	class UButton* Quit_Button;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= loadName)
	FName LevelLoad_Name;
	
protected:
	virtual void NativeOnInitialized() override;

	UFUNCTION()
	void QuitApplication();

	UFUNCTION()
	void ChangeLevel();
	
};
