#pragma once

#include "CoreMinimal.h"
#include "E_Current_Actions.generated.h"

//-------------------------------------------------------------------------------------------------------------

UENUM(BlueprintType)

enum class E_Current_Actions :uint8
{
	E_None UMETA(DisplayName = "None"),
	E_Chest UMETA(DisplayName = "Chest"),
	E_Door UMETA(DisplayName = "Door"),
	E_NPC UMETA(DisplayName = "NPC"),
	E_Portal_Altar UMETA(DisplayName = "Portal_Altar")
};
