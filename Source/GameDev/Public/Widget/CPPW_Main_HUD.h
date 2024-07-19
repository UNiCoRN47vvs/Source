#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Enum/E_Storage_Type.h"
#include "Components/HorizontalBox.h"
#include "CPPW_Main_HUD.generated.h"
//-------------------------------------------------------------------------------------------------------------
class UCPPW_HealthBar;
class UCPPW_Level_Bar;
class UCPPW_Inventory;
class UCPPW_Chest;
class UCPPW_Portal_Altar;
class UCPPW_Rune_Menu;
class UCPPW_Upgrade_Menu;
class UCPPW_Pick_Up_Menu;
class UCPPW_Skill_Bar;
class UCPPW_Character_Stats;
class UCPPW_Skill_Tree;
class UCPPW_Item_Menu;
struct FS_Items;
//-------------------------------------------------------------------------------------------------------------
UCLASS()
class GAMEDEV_API UCPPW_Main_HUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drag & Drop") int Drop_Index;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drag & Drop") int Drag_Index;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CPPW_Main_HUD") UUserWidget *Left_Widget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CPPW_Main_HUD") UUserWidget *Center_Widget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CPPW_Main_HUD") UUserWidget *Right_Widget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CPPW_Main_HUD") UCPPW_Item_Menu *Current_Item_Menu_Widget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget)) UCPPW_HealthBar* WBP_Health_Bar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget)) UCPPW_HealthBar* WBP_Mana_Bar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget)) UCPPW_Level_Bar* WBP_Level_Bar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget)) UCPPW_Inventory* WBP_Inventory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget)) UCPPW_Chest* WBP_Chest;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget)) UCPPW_Portal_Altar* WBP_Portal_Altar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget)) UCPPW_Rune_Menu* WBP_Rune_Menu;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget)) UCPPW_Upgrade_Menu* WBP_Upgrade_Menu;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget)) UCPPW_Pick_Up_Menu* WBP_Pick_Up_Menu;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget)) UCPPW_Skill_Bar* WBP_Skill_Bar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget)) UCPPW_Character_Stats* WBP_Character_Stats;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget)) UCPPW_Skill_Tree* WBP_Skill_Tree;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget)) UHorizontalBox* Buff_Info_Menu;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drag & Drop") E_Storage_Type Drop_Storage_Type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drag & Drop") E_Storage_Type Drag_Storage_Type;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Portal") TSubclassOf<AActor> Portal_Altar;

protected:
	virtual bool OnDrop(const FGeometry &MyGeometry, const FDragDropEvent &DragDropEvent, UDragDropOperation *Operation);

private:
	void DragDropLogic();
	void AddItemSwitchItem(TArray<FS_Items> &drag_array, TArray<FS_Items> &drop_array);

};
//-------------------------------------------------------------------------------------------------------------