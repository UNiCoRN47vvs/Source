#pragma once

#include "CoreMinimal.h"
#include "Enum/E_Items_Type.h"
#include "Enum/E_Supplies_Info.h"
#include "S_Rune_Stats.h"
#include "S_Items.generated.h"

//-------------------------------------------------------------------------------------------------------------

USTRUCT(BlueprintType)

struct GAMEDEV_API FS_Items : public FTableRowBase
{
		GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item") FName RN_ID;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item") FName Name;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item") FText Description;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item") E_Items_Type Item_Type;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item") double Use_Value;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item") int Amount;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item") int Max_Count;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item") bool Is_Not_Empty;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item") TSoftObjectPtr<UTexture2D> Item_Icon;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item") TSoftObjectPtr<UStaticMesh> Item_Static_Mesh;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item") E_Supplies_Info Supplies_Info;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item") double Time_Buff;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item") TSoftObjectPtr<UWorld> Level_Map_Name;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item") int Item_Level;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item") FS_Rune_Stats Rune_Stats;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item") int Cost;

};

//-------------------------------------------------------------------------------------------------------------