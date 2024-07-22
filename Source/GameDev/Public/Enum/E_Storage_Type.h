#pragma once

#include "CoreMinimal.h"
#include "E_Storage_Type.generated.h"
//-------------------------------------------------------------------------------------------------------------
UENUM(BlueprintType)

enum class E_Storage_Type :uint8
{
	E_None UMETA(DisplayName = "None"),
	E_Inventory UMETA(DisplayName = "Inventory"),
	E_Chest UMETA(DisplayName = "Chest"),
	E_Drop_Zone UMETA(DisplayName = "Drop_Zone"),
	E_Portal_Altar UMETA(DisplayName = "Portal_Altar"),
	E_Rune_Menu UMETA(DisplayName = "Rune_Menu"),
	E_Upgrate UMETA(DisplayName = "Upgrate")
};
