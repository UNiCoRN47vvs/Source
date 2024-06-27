#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayTagContainer.h"
#include "CPP_Enemy_Master.generated.h"

//-------------------------------------------------------------------------------------------------------------

UCLASS()
class GAMEDEV_API ACPP_Enemy_Master : public ACharacter
{
	GENERATED_BODY()

public:
	ACPP_Enemy_Master();

protected:
	
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage") double Min_Damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage") double Max_Damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXP") double EXP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Portal", meta = (ExposeOnSpawn = "true") ) int Portal_Level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Name", meta = (ExposeOnSpawn = "true") ) FName Row_Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Name") FGameplayTagContainer Enemy_Status;


private:

};

//-------------------------------------------------------------------------------------------------------------