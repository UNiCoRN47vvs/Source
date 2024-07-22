#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "CPPW_Pick_Up_Info.generated.h"
//-------------------------------------------------------------------------------------------------------------
UCLASS()
class GAMEDEV_API UCPPW_Pick_Up_Info : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pick_Up_Info", meta = (ExposeOnSpawn = "true")) int Amount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pick_Up_Info", meta = (ExposeOnSpawn = "true")) FName Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pick_Up_Info", meta = (BindWidget)) UImage* Image;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pick_Up_Info", meta = (BindWidget)) UTextBlock* Item_Name_TB;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pick_Up_Info", meta = (BindWidget)) UTextBlock* Amount_TB;
protected:
	virtual void NativeConstruct() override;
private:
	void SetItemText();
	UPROPERTY(EditAnywhere, Category = "Pick_Up_Info") FDataTableRowHandle Data_Table;
};
//-------------------------------------------------------------------------------------------------------------