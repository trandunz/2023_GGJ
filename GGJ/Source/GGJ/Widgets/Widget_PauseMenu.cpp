#include "Widget_PauseMenu.h"
#include "Kismet/KismetStringLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"

void UWidget_PauseMenu::HideWidget(bool _hideState)
{
	if(_hideState)
	{
		//Hide Widget and Hide Cursor

	}
	else
	{
		//UnHide Widget and Show Cursor
		
	}
}

void UWidget_PauseMenu::ResumeGame()
{
	RemoveFromParent();
}

void UWidget_PauseMenu::ChangeScene()
{
	UGameplayStatics::OpenLevel(this, LevelLoad_Name, true);
}

void UWidget_PauseMenu::QuitApplication()
{
	UKismetSystemLibrary::QuitGame(this, nullptr,EQuitPreference::Quit, true);
}

void UWidget_PauseMenu::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	Resume_Button->OnPressed.AddDynamic(this, &UWidget_PauseMenu::ResumeGame);
	Home_Button->OnPressed.AddDynamic(this, &UWidget_PauseMenu::ChangeScene);
	Quit_Button->OnPressed.AddDynamic(this, &UWidget_PauseMenu::QuitApplication);
	
}
