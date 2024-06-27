#pragma once

#include "CoreMinimal.h"
#include "E_Supplies_Info.generated.h"

//-------------------------------------------------------------------------------------------------------------
UENUM(BlueprintType)

enum class E_Supplies_Info :uint8
{
	E_None UMETA(DisplayName = "None"),
	E_Inc_Health UMETA(DisplayName = "Inc Health"),
	E_Inc_Mana UMETA(DisplayName = "Inc Mana"),
	E_Inc_Regen_HP UMETA(DisplayName = "Inc_Regen_HP"),
	E_Inc_Regen_MP UMETA(DisplayName = "Inc_Regen_MP")
};

//-------------------------------------------------------------------------------------------------------------