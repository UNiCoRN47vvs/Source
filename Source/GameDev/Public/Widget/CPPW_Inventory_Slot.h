#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Border.h"
#include "Enum/E_Storage_Type.h"
#include "Enum/E_Items_Type.h"
#include "Containers/Map.h" //Необходимо для использования переменной типа map
#include "Structure/S_Items.h"
#include "CPPW_Inventory_Slot.generated.h"
//-------------------------------------------------------------------------------------------------------------
class ACPP_Player_Controller;
class UCPPW_Item_Info_Panel;
class UCPPW_Item_Menu;
//-------------------------------------------------------------------------------------------------------------
UCLASS()
class GAMEDEV_API UCPPW_Inventory_Slot : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable) void GetRuneStats();
	UFUNCTION(BlueprintCallable) void SetNewSlot(FName name, int amount, TSoftObjectPtr<UTexture2D> icon);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Var") int Amount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Var") int Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Var") FName Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Var") TSoftObjectPtr<UTexture2D> Item_Icon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Var") TMap<FName, double> Map_Rune_Stats; //Переменная типа map (Ключ-значение)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Var", meta = (ExposeOnSpawn = "Inventory_Slot")) int Index;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Var", meta = (ExposeOnSpawn = "Inventory_Slot")) E_Storage_Type Storage_Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets", meta = (BindWidget)) class UBorder* Border_Icon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets") TSubclassOf<UCPPW_Item_Info_Panel> Widget_Class;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets") class UCPPW_Item_Info_Panel *Tool_Tip;
protected:

private:
	ACPP_Player_Controller *Player_Controller;
	UFUNCTION(BlueprintCallable) void ShowItemMenuWidget(int item_index, E_Items_Type item_type, E_Storage_Type temp_storage_type);

	UPROPERTY(EditAnywhere, Category = "Inventory_Slot") TSubclassOf<UCPPW_Item_Menu> Item_Menu_Widget;
	UPROPERTY(EditAnywhere, Category = "Inventory_Slot") TSoftObjectPtr<UTexture2D> Slot_Icon;
};
//-------------------------------------------------------------------------------------------------------------