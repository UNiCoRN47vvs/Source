#pragma once

#include "CoreMinimal.h"
#include "S_Drop_Chance.generated.h"

//-------------------------------------------------------------------------------------------------------------

USTRUCT(BlueprintType)

struct GAMEDEV_API FS_Drop_Chance: public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drop_Chance") double Drop_Fail = 40.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drop_Chance") double Drop_Currency = 30.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drop_Chance") double Drop_Health_Bottle = 26.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drop_Chance") double Drop_Mana_Bottle = 26.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drop_Chance") double Drop_Supplies = 12.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drop_Chance") double Drop_Rune = 7.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drop_Chance") double Drop_Portal = 7.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drop_Chance") double Drop_Max_Amount_Gold = 5.0;

};

//-------------------------------------------------------------------------------------------------------------