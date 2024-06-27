#pragma once

#include "CoreMinimal.h"
#include "S_Parameters.generated.h"

//-------------------------------------------------------------------------------------------------------------

USTRUCT(BlueprintType)


struct GAMEDEV_API FS_Parameters: public FTableRowBase
{
	GENERATED_BODY()

	FS_Parameters operator+(const FS_Parameters& other) const
	{
		FS_Parameters Result;

		Result.HP_Max = this->HP_Max + other.HP_Max;
		Result.HP_Regen = this->HP_Regen + other.HP_Regen;
		Result.MP_Max = this->MP_Max + other.MP_Max;
		Result.MP_Regen = this->MP_Regen + other.MP_Regen;
		Result.Evasion = this->Evasion + other.Evasion;
		Result.Hit_Rate_Chance = this->Hit_Rate_Chance + other.Hit_Rate_Chance;
		Result.Crit_Rate_Chance = this->Crit_Rate_Chance + other.Crit_Rate_Chance;
		Result.Protection_Rate = this->Protection_Rate + other.Protection_Rate;
		Result.Power_Rate = this->Power_Rate + other.Power_Rate;
		Result.Attack_Speed = this->Attack_Speed + other.Attack_Speed;


		return Result;
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameters") double HP_Current = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameters") double HP_Max = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameters") double HP_Regen = 0.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameters") double MP_Current = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameters") double MP_Max = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameters") double MP_Regen = 0.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameters") int Level = 1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameters") double EXP_Current = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameters") double EXP_Need = 100.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameters") double EXP_Multiply = 0.15;

	//Other Parameters
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameters") double Evasion = 5.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameters") double Hit_Rate_Chance = 90.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameters") double Crit_Rate_Chance = 5.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameters") double Protection_Rate = 5.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameters") double Power_Rate = 5.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameters") double Attack_Speed = 1.0;

};

//-------------------------------------------------------------------------------------------------------------