#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enum/E_Supplies_Info.h"
#include "CPP_Player_Buff.generated.h"
//-------------------------------------------------------------------------------------------------------------
class UCPPW_Buff_Icon;
class ACPP_Character_Master;
class ACPP_Player_Controller;
struct FS_Parameters;
//-------------------------------------------------------------------------------------------------------------
UCLASS()
class GAMEDEV_API ACPP_Player_Buff : public AActor
{
	GENERATED_BODY()
	
public:	
	ACPP_Player_Buff();

	void ActivateBuff();
	void DeactivateBuff();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CPP_Player_Buff", meta = (ExposeOnSpawn = "true")) bool Is_Load;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CPP_Player_Buff", meta = (ExposeOnSpawn = "true")) int Item_Level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CPP_Player_Buff") double Use_Value;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CPP_Player_Buff") double Time_Buff;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CPP_Player_Buff") E_Supplies_Info Supplies_Info;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CPP_Player_Buff", meta = (ExposeOnSpawn = "true")) FName Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CPP_Player_Buff") FTimerHandle Timer_Handle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CPP_Player_Buff") TSubclassOf<UCPPW_Buff_Icon> Widget_Buff_Icon;


protected:
	
	virtual void BeginPlay() override;

private:

	void SetBuffTimer(TFunction<void(FS_Parameters)> Func, FS_Parameters parameters);
	void DeactivateIncrease(FS_Parameters parameters);
	UFUNCTION(BlueprintCallable) void AddWidget();
	UFUNCTION(BlueprintCallable) void RemoveWidget();

	UPROPERTY() ACPP_Character_Master *Player_Character;
	UPROPERTY() ACPP_Player_Controller *Player_Controller;
	UPROPERTY() UCPPW_Buff_Icon* Widget_Buff;
	
};
//-------------------------------------------------------------------------------------------------------------