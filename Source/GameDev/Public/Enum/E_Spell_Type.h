#pragma once

#include "CoreMinimal.h"
#include "E_Spell_Type.generated.h"

//-------------------------------------------------------------------------------------------------------------

UENUM(BlueprintType)

enum class E_Spell_Type :uint8
{
	E_Attack UMETA(DisplayName = "Attack"),
	E_Buff UMETA(DisplayName = "Buff"),
	E_Ultimate UMETA(DisplayName = "Ultimate")
};
