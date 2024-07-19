#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Enum/E_Items_Type.h"
#include "Enum/E_Storage_Type.h"
#include "CPPW_Item_Menu.generated.h"
//-------------------------------------------------------------------------------------------------------------
class UWidgetAnimation;
//-------------------------------------------------------------------------------------------------------------
UCLASS()
class GAMEDEV_API UCPPW_Item_Menu : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable) void HideItemMenu();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item_Menu", meta = (ExposeOnSpawn = "true")) int Item_Index;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item_Menu", meta = (ExposeOnSpawn = "true")) E_Items_Type Item_Type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item_Menu", meta = (ExposeOnSpawn = "true")) E_Storage_Type Storage_Type;
protected:
	void SelfRemoveFromParent();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item_Menu") UWidgetAnimation *Show_Hide_Anim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item_Menu") FTimerHandle Timer_Handle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item_Menu") FTimerHandle Main_Timer_Handle;

};
//-------------------------------------------------------------------------------------------------------------