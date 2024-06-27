#pragma once

#include "CoreMinimal.h"
#include "S_Currency.generated.h"


USTRUCT(BlueprintType)

struct GAMEDEV_API FS_Currency
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Currency") int Gold = 0;
};
