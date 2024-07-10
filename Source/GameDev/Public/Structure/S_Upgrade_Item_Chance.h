// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "S_Upgrade_Item_Chance.generated.h"

//-------------------------------------------------------------------------------------------------------------

USTRUCT(BlueprintType)

struct GAMEDEV_API FS_Upgrade_Item_Chance : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Upgrade_Item_Chance") int Level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Upgrade_Item_Chance") double Chance;

};
