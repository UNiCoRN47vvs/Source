#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameplayTagContainer.h"
#include "Widget/CPPW_Main_HUD.h"
#include "Enum/E_Current_Actions.h"
#include "CPP_Player_Controller.generated.h"

//-------------------------------------------------------------------------------------------------------------

UCLASS()
class GAMEDEV_API ACPP_Player_Controller : public APlayerController
{
	GENERATED_BODY()

public:

	virtual void BeginPlay();

	void UpdateHP(double current_hp, double max_hp);
	void UpdateMP(double current_mp, double max_mp);
	void UpdateLevel(double current_exp, double need_exp, int level);
	FGameplayTagContainer GetControllerStatus();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player_Controller") E_Current_Actions Current_Actions;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main HUD") UCPPW_Main_HUD *Main_HUD;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status") FGameplayTagContainer Controller_Status;
 
protected:

private:

};

//-------------------------------------------------------------------------------------------------------------