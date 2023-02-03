
#include "Widget_Mainmenu.h"
#include "Components/Button.h"
#include "Kismet/KismetStringLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

void UWidget_Mainmenu::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	
	Play_Button->OnPressed.AddDynamic(this,&UWidget_Mainmenu::ChangeLevel);
	Quit_Button->OnPressed.AddDynamic(this,&UWidget_Mainmenu::QuitApplication);
	
}

void UWidget_Mainmenu::QuitApplication()
{
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, false);
}

void UWidget_Mainmenu::ChangeLevel()
{
	UGameplayStatics::OpenLevel(this, this->LevelLoad_Name, true);
}
