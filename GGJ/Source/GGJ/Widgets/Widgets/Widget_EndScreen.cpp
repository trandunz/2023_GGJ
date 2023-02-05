#include "Widget_EndScreen.h"

#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UWidget_EndScreen::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	//HomeButton->OnPressed.AddDynamic(this, &UWidget_EndScreen::GoHome);
	ReplayButton->OnPressed.AddDynamic(this, &UWidget_EndScreen::Replay);
}

void UWidget_EndScreen::GoHome()
{
	UGameplayStatics::OpenLevel(this, "Level_testMenu", true);
}

void UWidget_EndScreen::Replay()
{
	
}
