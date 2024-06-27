#pragma once

#include "CoreMinimal.h"
#include "E_Items_Type.generated.h"

//-------------------------------------------------------------------------------------------------------------
UENUM(BlueprintType)

enum class E_Items_Type :uint8
{
	E_None UMETA(DisplayName = "None"),
	E_Health_Bottle UMETA(DisplayName = "Health Bottle"),
	E_Mana_Bottle UMETA(DisplayName = "Mana Bottle"),
	E_Supplies UMETA(DisplayName = "Supplies"),
	E_Quest_Item UMETA(DisplayName = "Quest Item"),
	E_Rune UMETA(DisplayName = "Rune"),
	E_Currency UMETA(DisplayName = "Currency"),
	E_Portal UMETA(DisplayName = "Portal")
};

//-------------------------------------------------------------------------------------------------------------