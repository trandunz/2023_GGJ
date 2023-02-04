#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "VegetableInterface.generated.h"

UINTERFACE(MinimalAPI)
class UVegetableInterface : public UInterface
{
	GENERATED_BODY()
};

class GGJ_API IVegetableInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void Throw(FVector _direction) = 0;
};
