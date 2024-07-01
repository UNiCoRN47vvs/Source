#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CPPW_Items_Nameplate.generated.h"

//-------------------------------------------------------------------------------------------------------------

UCLASS()
class GAMEDEV_API UCPPW_Items_Nameplate : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget)) class UTextBlock* TB_Text;
};

//-------------------------------------------------------------------------------------------------------------