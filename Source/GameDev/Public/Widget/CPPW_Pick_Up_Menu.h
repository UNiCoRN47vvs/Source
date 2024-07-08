#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/VerticalBox.h"
#include "CPPW_Pick_Up_Menu.generated.h"

//-------------------------------------------------------------------------------------------------------------

UCLASS()
class GAMEDEV_API UCPPW_Pick_Up_Menu : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pick_Up_Menu") UVerticalBox *Vertical_Box;
};

//-------------------------------------------------------------------------------------------------------------