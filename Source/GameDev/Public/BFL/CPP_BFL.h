#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/DataTable.h"
#include "Structure/S_Items.h"
#include "Structure/S_Rune_Stats.h"
#include "CPP_BFL.generated.h"

//-------------------------------------------------------------------------------------------------------------

UCLASS(Blueprintable)
class GAMEDEV_API UCPP_BFL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	UCPP_BFL();

	UFUNCTION(BlueprintCallable) static void GetUseValueDTR(FName dtr_name, int item_level, double &return_use_value, FS_Items &return_item_row, FS_Rune_Stats &return_rune_stats);

	static UDataTable* Data_Table;
};

//-------------------------------------------------------------------------------------------------------------