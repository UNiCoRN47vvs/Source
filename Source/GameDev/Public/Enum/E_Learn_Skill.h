// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "E_Learn_Skill.generated.h"

//-------------------------------------------------------------------------------------------------------------

UENUM(BlueprintType)

enum class E_Learn_Skill :uint8
{
	E_Min_Value UMETA(DisplayName = "Min_Value"),
	E_Max_Value UMETA(DisplayName = "Max_Value"),
	E_Mana_Cost UMETA(DisplayName = "Mana_Cost"),
	E_Cooldown UMETA(DisplayName = "Cooldown")
};
