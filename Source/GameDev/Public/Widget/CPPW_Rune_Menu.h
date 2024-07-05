#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CPPW_Rune_Menu.generated.h"

//-------------------------------------------------------------------------------------------------------------
  
class UCPPW_Inventory_Slot;

//-------------------------------------------------------------------------------------------------------------

UCLASS()
class GAMEDEV_API UCPPW_Rune_Menu : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget)) UCPPW_Inventory_Slot *WBP_Inventory_Slot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget)) UCPPW_Inventory_Slot *WBP_Inventory_Slot_1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget)) UCPPW_Inventory_Slot *WBP_Inventory_Slot_2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget)) UCPPW_Inventory_Slot *WBP_Inventory_Slot_3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget)) UCPPW_Inventory_Slot *WBP_Inventory_Slot_4;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget") TArray<UCPPW_Inventory_Slot*> Inventory_Slot_Array;

protected:
	virtual void NativeConstruct() override;
};

//-------------------------------------------------------------------------------------------------------------