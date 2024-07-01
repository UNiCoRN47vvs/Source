#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CPPW_Mini_Map_Icon.generated.h"

//-------------------------------------------------------------------------------------------------------------

UCLASS()
class GAMEDEV_API UCPPW_Mini_Map_Icon : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget)) class UImage* Image;
};

//-------------------------------------------------------------------------------------------------------------