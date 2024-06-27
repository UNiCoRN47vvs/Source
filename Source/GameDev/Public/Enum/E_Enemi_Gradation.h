#pragma once

#include "CoreMinimal.h"
#include "E_Enemi_Gradation.generated.h"

//-------------------------------------------------------------------------------------------------------------

UENUM(BlueprintType)

enum class E_Enemy_Gradation :uint8
{
	E_White UMETA(DisplayName = "White"),
	E_Green UMETA(DisplayName = "Green"),
	E_Blue UMETA(DisplayName = "Blue"),
	E_Purpule UMETA(DisplayName = "Purpule"),
	E_Legendary UMETA(DisplayName = "Legendary")

};
