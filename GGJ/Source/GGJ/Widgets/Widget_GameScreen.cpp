#include "Widget_GameScreen.h"

#include "AdvancedWidgets/Public/Components/RadialSlider.h"
#include "Components/TextBlock.h"
#include "GGJ/GGJGameMode.h"

void UWidget_GameScreen::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UWidget_GameScreen::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	
}

void UWidget_GameScreen::SetTimerValue()
{
	if (AGGJGameMode* gamemode = Cast<AGGJGameMode>(GetWorld()->GetAuthGameMode()))
	{
		Timer_Text->SetText(FText::FromString(FString::FromInt(gamemode->RoundTimer)));
		RadialSliderTimer->SetValue(gamemode->RoundTimer / gamemode->RoundTime);
	}
}

void UWidget_GameScreen::SetPlayer1Carrots()
{
	if (AGGJGameMode* gamemode = Cast<AGGJGameMode>(GetWorld()->GetAuthGameMode()))
	{
		LCarrotCount_Text1->SetText(FText::FromString(FString::FromInt(gamemode->P1CurrentCarrotCount)));
	}
}

void UWidget_GameScreen::SetPlayer2Carrots()
{
	if (AGGJGameMode* gamemode = Cast<AGGJGameMode>(GetWorld()->GetAuthGameMode()))
	{
		RCarrotCount_Text2->SetText(FText::FromString(FString::FromInt(gamemode->P2CurrentCarrotCount)));
	}
}
