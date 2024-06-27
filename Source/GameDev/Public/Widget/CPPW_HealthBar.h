#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CPPW_HealthBar.generated.h"

//-------------------------------------------------------------------------------------------------------------

class UProgessBar;
class UTextBlock;

//-------------------------------------------------------------------------------------------------------------

UCLASS()
class GAMEDEV_API UCPPW_HealthBar : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable) void Update_HP_Bar(double current_hp, double max_hp);
	UFUNCTION(BlueprintCallable) void Update_MP_Bar(double current_mp, double max_mp);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget)) class UProgressBar* Progress_Bar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget)) class UTextBlock* Info_Text;

protected:
	virtual void NativeOnMouseEnter(const FGeometry &InGeometry, const FPointerEvent &InMouseIvent) override;
	virtual void NativeOnMouseLeave(const FPointerEvent& InMouseIvent) override;
};

//-------------------------------------------------------------------------------------------------------------