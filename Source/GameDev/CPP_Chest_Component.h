#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Structure/S_Currency.h"
#include "Structure/S_Items.h"
#include "CPP_Chest_Component.generated.h"

//-------------------------------------------------------------------------------------------------------------

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEDEV_API UCPP_Chest_Component : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	UCPP_Chest_Component();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Slots") int Max_Chest_Slots;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Slots") int MIS_Per_Row;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Currency") FS_Currency Currency;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Currency") TArray<FS_Items> Items_Array;

protected:
	
	virtual void BeginPlay();

private:
	

		
};

//-------------------------------------------------------------------------------------------------------------