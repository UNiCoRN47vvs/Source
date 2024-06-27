#pragma once

#include "CoreMinimal.h"
#include "S_Character_Stats_Multiplier.generated.h"

//-------------------------------------------------------------------------------------------------------------

USTRUCT(BlueprintType)

struct GAMEDEV_API FS_Character_Stats_Multiplier
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multiplier") double Power_Multiplier = 0.25;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multiplier") double Dexterity_Multiplier = 0.2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multiplier") double Attack_Speed_Multiplier = 0.002;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multiplier") double Critical_Chance_Multiplier = 0.2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multiplier") double Health_Multiplier = 2.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multiplier") double Mana_Multiplier = 2.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multiplier") double Protection_Multiplier = 0.1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multiplier") double Evasion_Multiplier = 0.1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multiplier") double Luck_Multiplier = 0.1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multiplier") double Gold_Multiplier = 0.25;

};
