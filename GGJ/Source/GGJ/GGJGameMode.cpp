#include "GGJGameMode.h"
#include "GGJCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGGJGameMode::AGGJGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_GGJCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
