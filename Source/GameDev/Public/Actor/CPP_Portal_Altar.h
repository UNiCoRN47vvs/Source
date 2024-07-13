#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Structure/S_Items.h"
#include "CPP_Portal_Altar.generated.h"
//-------------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------------
UCLASS()
class GAMEDEV_API ACPP_Portal_Altar : public AActor
{
	GENERATED_BODY()
	
public:	

	ACPP_Portal_Altar();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Portal") FName RN_ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Portal") FS_Items Item_Structure;

protected:

	virtual void BeginPlay() override;
};
//-------------------------------------------------------------------------------------------------------------
