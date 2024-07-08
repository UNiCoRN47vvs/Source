#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "CPPW_Rune_Menu_Stats_Text.generated.h"

//-------------------------------------------------------------------------------------------------------------

UCLASS()
class GAMEDEV_API UCPPW_Rune_Menu_Stats_Text : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget)) UTextBlock *Text_Block_Sample;

	void InitTBSample(FText sign, FText value, FText stat_name);
	
};

//-------------------------------------------------------------------------------------------------------------