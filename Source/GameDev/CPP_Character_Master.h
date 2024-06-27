#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayTagContainer.h"
#include "Structure/S_Parameters.h"
#include "CPP_Character_Master.generated.h"

//-------------------------------------------------------------------------------------------------------------

class UCPP_Stats_Component;
class UCPP_Inventory_Component;
class UCPP_Chest_Component;

//-------------------------------------------------------------------------------------------------------------

UCLASS()
class GAMEDEV_API ACPP_Character_Master : public ACharacter
{
	GENERATED_BODY()

public:

	ACPP_Character_Master();
	virtual void Tick(float DeltaTime);
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent);

	UFUNCTION(BlueprintCallable) void PlusCharacterParameters(FS_Parameters s_parameters, bool basic_change);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status") FGameplayTagContainer Character_Status;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structures") FS_Parameters Basic_Character_Parameters; //Базовые статы


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vectors") FVector Mouse_Cursor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vectors") FVector Normilize_2D_Vector;

	FGameplayTagContainer GetCharacterStatus();

	class UCPP_Stats_Component* GetStatsComponent();
	class UCPP_Inventory_Component* GetInventoryComponent();
	class UCPP_Chest_Component* GetChestComponent();

protected:

	virtual void BeginPlay();


private:
	
	UFUNCTION(BlueprintCallable) void Character_Movement(double action_value_x, double action_value_y);

};

//-------------------------------------------------------------------------------------------------------------