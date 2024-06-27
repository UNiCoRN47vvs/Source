#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CPPW_Level_Bar.generated.h"

//-------------------------------------------------------------------------------------------------------------
class UProgessBar;
class UTextBlock;
//-------------------------------------------------------------------------------------------------------------

UCLASS()
class GAMEDEV_API UCPPW_Level_Bar : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable) void Update_EXP_Bar(double current_exp, double need_exp, int level);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget)) class UProgressBar* Progress_Bar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget)) class UTextBlock* Info_Text;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget)) class UTextBlock* Level_TB;

protected:
	virtual void NativeOnMouseEnter(const FGeometry &InGeometry, const FPointerEvent &InMouseIvent) override;
	virtual void NativeOnMouseLeave(const FPointerEvent& InMouseIvent) override;
};

//-------------------------------------------------------------------------------------------------------------