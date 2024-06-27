#pragma once

#include "CoreMinimal.h"
#include "S_Rune_Stats.generated.h"

//-------------------------------------------------------------------------------------------------------------

USTRUCT(BlueprintType)

struct GAMEDEV_API FS_Rune_Stats: public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rune Stats") double Max_HP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rune Stats") double Regen_HP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rune Stats") double Max_MP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rune Stats") double Regen_MP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rune Stats") double Evasion;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rune Stats") double Hit_Rate_Chance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rune Stats") double Crit_Rate_Chance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rune Stats") double Protection_Rate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rune Stats") double Power_Rate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rune Stats") double Attack_Speed;

};

//-------------------------------------------------------------------------------------------------------------