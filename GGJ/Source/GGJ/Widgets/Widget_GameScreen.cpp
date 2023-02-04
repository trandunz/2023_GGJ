// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget_GameScreen.h"



void UWidget_GameScreen::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	Timer_RadialSlider->Value = MaxTime;
}

void UWidget_GameScreen::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	SetTimerValue(InDeltaTime);
}

void UWidget_GameScreen::SetTimerValue(float _Fincrease)
{
	Timer_RadialSlider->Value += _Fincrease;
}
