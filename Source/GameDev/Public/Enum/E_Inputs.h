#pragma once

#include "CoreMinimal.h"
#include "E_Inputs.generated.h"

//-------------------------------------------------------------------------------------------------------------
UENUM(BlueprintType)

enum class E_Inputs :uint8
{
	E_Left_Mouse_Button UMETA(DisplayName = "Left_Mouse_Button"),
	E_Right_Mouse_Button UMETA(DisplayName = "Right_Mouse_Button"),
	E_Button_1 UMETA(DisplayName = "Button_1"),
	E_Button_2 UMETA(DisplayName = "Button_2"),
	E_Button_3 UMETA(DisplayName = "Button_3"),
	E_Button_4 UMETA(DisplayName = "Button_4")
};
