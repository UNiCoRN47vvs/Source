#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Border.h"
#include "Enum/E_Storage_Type.h"
#include "Containers/Map.h" //Необходимо для использования переменной типа map
#include "Structure/S_Items.h"
#include "CPPW_Inventory_Slot.generated.h"

//-------------------------------------------------------------------------------------------------------------

class UCPPW_Item_Info_Panel;

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Var", meta = (ExposeOnSpawn = "VALUE")) int Index;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Var", meta = (ExposeOnSpawn = "VALUE")) E_Storage_Type Storage_Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets", meta = (BindWidget)) class UBorder* Border_Icon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets") TSubclassOf<UCPPW_Item_Info_Panel> Widget_Class;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets") class UCPPW_Item_Info_Panel *Tool_Tip;

};

//-------------------------------------------------------------------------------------------------------------