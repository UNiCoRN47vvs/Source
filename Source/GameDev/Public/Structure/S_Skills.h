#pragma once

#include "CoreMinimal.h"
#include "Enum/E_Spell_Type.h"
#include "Enum/E_Input_Button.h"
#include "S_Skills.generated.h"

//-------------------------------------------------------------------------------------------------------------

USTRUCT(BlueprintType)

struct GAMEDEV_API FS_Skills : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills") FName RN_ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills") FName Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills") FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills") TSoftObjectPtr<UTexture2D> Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills") E_Spell_Type Spell_Type;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills") TSoftClassPtr<bp_projectile_master> Projectile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills") TSoftObjectPtr<UAnimMontage> Anim_Montage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills") double Mana_Cost;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills") double Min_Damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills") double Max_Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills") E_Input_Button Input_Button;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills") double Cooldown;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills") double Level_Up_Min_Damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills") double Level_Up_Max_Damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills") double Level_Up_Mana_Cost;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills") double Level_Up_Cooldown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills") int LU_Min_Damage_Count;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills") int LU_Max_Damage_Count;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills") int LU_Mana_Cost_Count;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills") int LU_Cooldown_Count;


};
