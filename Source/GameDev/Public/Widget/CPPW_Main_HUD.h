#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Enum/E_Storage_Type.h"
#include "CPPW_Main_HUD.generated.h"

//-------------------------------------------------------------------------------------------------------------

class UCPPW_HealthBar;
class UCPPW_Level_Bar;
class UCPPW_Inventory;
class UCPPW_Chest;
class UCPPW_Portal_Altar;
struct FS_Items;

//-------------------------------------------------------------------------------------------------------------

UCLASS()
class GAMEDEV_API UCPPW_Main_HUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drag & Drop") int Drop_Index;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drag & Drop") int Drag_Index;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget)) class UCPPW_HealthBar* WBP_Health_Bar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget)) class UCPPW_HealthBar* WBP_Mana_Bar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget)) class UCPPW_Level_Bar* WBP_Level_Bar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget)) class UCPPW_Inventory* WBP_Inventory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget)) class UCPPW_Chest* WBP_Chest;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget)) class UCPPW_Portal_Altar* WBP_Portal_Altar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drag & Drop") E_Storage_Type Drop_Storage_Type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drag & Drop") E_Storage_Type Drag_Storage_Type;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Portal") TSubclassOf<AActor> Portal_Altar;

protected:
	void OnDrop();

private:

	void AddItemSwitchItem(TArray<FS_Items> &drag_array, TArray<FS_Items> &drop_array);

};

//-------------------------------------------------------------------------------------------------------------