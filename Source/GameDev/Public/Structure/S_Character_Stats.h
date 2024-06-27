#pragma once

#include "CoreMinimal.h"
#include "S_Character_Stats.generated.h"

//-------------------------------------------------------------------------------------------------------------

USTRUCT(BlueprintType)

struct GAMEDEV_API FS_Character_Stats: public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character_Stats") int Skill_Points = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character_Stats") int Amount_Level_Up_Points = 5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character_Stats") int Power = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character_Stats") int Dexterity = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character_Stats") int Attack_Speed = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character_Stats") int Critical_Chance = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character_Stats") int Health = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character_Stats") int Mana = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character_Stats") int Protection = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character_Stats") int Evasion = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character_Stats") int Luck = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character_Stats") int Gold = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character_Stats") int Skill_Tree_Points = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character_Stats") int Amount_Level_Up_Skill_Tree_Points = 2;

};

//-------------------------------------------------------------------------------------------------------------