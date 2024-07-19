#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CPPW_Buff_Icon.generated.h"
//-------------------------------------------------------------------------------------------------------------
UCLASS()
class GAMEDEV_API UCPPW_Buff_Icon : public UUserWidget
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CPPW_Buff_Icon") double Time;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CPPW_Buff_Icon", meta = (ExposeOnSpawn = "true")) FName Name;
};
//-------------------------------------------------------------------------------------------------------------