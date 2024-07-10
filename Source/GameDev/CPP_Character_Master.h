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
class ACPP_Master_Item;
struct FS_Items;

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
	UFUNCTION(BlueprintCallable) void PickUpFunc(FName item_row_name, int amount, int item_level);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status") FGameplayTagContainer Character_Status;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structures") FS_Parameters Basic_Character_Parameters; //������� �����


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vectors") FVector Mouse_Cursor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vectors") FVector Normilize_2D_Vector;

	FGameplayTagContainer GetCharacterStatus();

	class UCPP_Stats_Component* GetStatsComponent();
	class UCPP_Inventory_Component* GetInventoryComponent();
	class UCPP_Chest_Component* GetChestComponent();

protected:

	virtual void BeginPlay();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info") FDataTableRowHandle DT_All_Items;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character_Master") TSubclassOf<ACPP_Master_Item> Master_Item;

private:
	
	bool IsInventoryFull();
	void AddItemToSlot(int amount, FS_Items s_items, int item_level, TArray<FS_Items> inventory_items);
	UFUNCTION(BlueprintCallable) void Character_Movement(double action_value_x, double action_value_y);



};

//-------------------------------------------------------------------------------------------------------------