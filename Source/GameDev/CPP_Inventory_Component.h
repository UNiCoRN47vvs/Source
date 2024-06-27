#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Structure/S_Currency.h"
#include "Structure/S_Items.h"
#include "CPP_Inventory_Component.generated.h"

//-------------------------------------------------------------------------------------------------------------

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEDEV_API UCPP_Inventory_Component : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	UCPP_Inventory_Component();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Slots") int Max_Inventory_Slots;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Slots") int MIS_Per_Row;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Currency") FS_Currency Currency;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Currency") TArray<FS_Items> Items_Array;

protected:
	
	virtual void BeginPlay() override;

private:
	

		
};

//-------------------------------------------------------------------------------------------------------------