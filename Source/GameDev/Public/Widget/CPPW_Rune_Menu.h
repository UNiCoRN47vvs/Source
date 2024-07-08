#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/VerticalBox.h"
#include "Components/TextBlock.h"
#include "CPPW_Rune_Menu.generated.h"

//-------------------------------------------------------------------------------------------------------------
  
class UCPPW_Inventory_Slot;

//-------------------------------------------------------------------------------------------------------------

UCLASS()
class GAMEDEV_API UCPPW_Rune_Menu : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable) void InitParamsRuneMenu();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget)) UCPPW_Inventory_Slot *WBP_Inventory_Slot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget)) UCPPW_Inventory_Slot *WBP_Inventory_Slot_1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget)) UCPPW_Inventory_Slot *WBP_Inventory_Slot_2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget)) UCPPW_Inventory_Slot *WBP_Inventory_Slot_3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget)) UCPPW_Inventory_Slot *WBP_Inventory_Slot_4;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget)) UVerticalBox *Vertical_Text_Box;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget)) UVerticalBox *Vertical_Text_Box_1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget)) UVerticalBox *Vertical_Text_Box_2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget)) UVerticalBox *Vertical_Text_Box_3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget)) UVerticalBox *Vertical_Text_Box_4;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget)) UTextBlock *Text_Block;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget)) UTextBlock *Text_Block_1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget)) UTextBlock *Text_Block_2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget)) UTextBlock *Text_Block_3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget)) UTextBlock *Text_Block_4;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget") TArray<UCPPW_Inventory_Slot*> Inventory_Slot_Array;


protected:
	virtual void NativeConstruct() override;
};

//-------------------------------------------------------------------------------------------------------------