#pragma once

#include "CoreMinimal.h"
#include "E_After_Death.generated.h"

//-------------------------------------------------------------------------------------------------------------

UENUM(BlueprintType)

enum class E_After_Death :uint8
{
	E_None UMETA(DisplayName = "None"),
	E_Explode UMETA(DisplayName = "Explode"),
	E_Poison_Pool UMETA(DisplayName = "Poison_Pool"),
	E_Heal_Pool UMETA(DisplayName = "Heal_Pool")

};
