#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CPPW_Portal_Altar.generated.h"

//-------------------------------------------------------------------------------------------------------------

class UCPPW_Inventory_Slot;

//-------------------------------------------------------------------------------------------------------------

UCLASS()
class GAMEDEV_API UCPPW_Portal_Altar : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget)) UCPPW_Inventory_Slot *Portal_Altar_Slot;
};

//-------------------------------------------------------------------------------------------------------------