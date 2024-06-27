#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Structure/S_Currency.h"
#include "CPP_Save_Game.generated.h"


UCLASS()
class GAMEDEV_API UCPP_Save_Game : public USaveGame
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Currency") FS_Currency Chest_Currency;
	
};
