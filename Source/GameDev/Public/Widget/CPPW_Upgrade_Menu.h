#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
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

	UFUNCTION(BlueprintCallable) void UpdateText();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget)) UCPPW_Inventory_Slot *WBP_Inventory_Slot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget)) UCPPW_Inventory_Slot *WBP_Inventory_Slot_1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget)) UTextBlock *Upgrade_Chance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget)) UTextBlock *Upgrade_Fails;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Upgrade_Menu") TArray<FS_Items> Upgrade_Storage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Upgrade_Menu") TArray<UCPPW_Inventory_Slot*> Upgrade_Slot_Widget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Upgrade_Menu") int Upgrade_Fails_Count;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Upgrade_Menu") double Fails_Chance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Upgrade_Menu") double Chance;

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Upgrade_Menu") FDataTableRowHandle Data_Table;
};

//-------------------------------------------------------------------------------------------------------------