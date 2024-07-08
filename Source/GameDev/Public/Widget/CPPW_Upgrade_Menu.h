#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Structure/S_Items.h"
#include "CPPW_Upgrade_Menu.generated.h"

//-------------------------------------------------------------------------------------------------------------

class UCPPW_Inventory_Slot;

//-------------------------------------------------------------------------------------------------------------

UCLASS()
class GAMEDEV_API UCPPW_Upgrade_Menu : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget)) UCPPW_Inventory_Slot *WBP_Inventory_Slot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget)) UCPPW_Inventory_Slot *WBP_Inventory_Slot_1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Upgrate_Menu") TArray<FS_Items> Upgrade_Storage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Upgrate_Menu") TArray<UCPPW_Inventory_Slot*> Upgrade_Slot_Widget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Upgrate_Menu") int Upgrade_Fails_Count;

protected:
	virtual void NativeConstruct() override;
};

//-------------------------------------------------------------------------------------------------------------