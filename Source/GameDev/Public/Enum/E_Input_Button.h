#pragma once

#include "CoreMinimal.h"
#include "E_Input_Button.generated.h"

//-------------------------------------------------------------------------------------------------------------

UENUM(BlueprintType)

enum class E_Input_Button :uint8
{
	E_LMB UMETA(DisplayName = "LMB"),
	E_RMB UMETA(DisplayName = "RMB"),
	E_1 UMETA(DisplayName = "1"),
	E_2 UMETA(DisplayName = "2"),
	E_3 UMETA(DisplayName = "3"),
	E_4 UMETA(DisplayName = "4")
};
