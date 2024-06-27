#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Structure/S_Parameters.h"
#include "Structure/S_Character_Stats.h"
#include "Structure/S_Drop_Chance.h"
#include "Structure/S_Items.h"
#include "CPP_Stats_Component.generated.h"


//-------------------------------------------------------------------------------------------------------------

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEDEV_API UCPP_Stats_Component : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	UCPP_Stats_Component();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrays") TArray<bool> Rune_Array_Check;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structures") FS_Parameters S_Parameters;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structures") FS_Character_Stats S_Character_Stats;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structures") FS_Drop_Chance S_Basic_Drop_Chance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Currency") TArray<FS_Items> Rune_Array;

protected:
	
	virtual void BeginPlay();

private:
	

		
};

//-------------------------------------------------------------------------------------------------------------