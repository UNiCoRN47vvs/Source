#include "Widget/CPPW_Chest.h"
#include "Kismet/GameplayStatics.h"
#include "GameDev/CPP_Character_Master.h"
#include "GameDev/CPP_Chest_Component.h"
#include "CPP_Player_Controller.h"
#include "Widget/CPPW_Inventory_Slot.h"
//-------------------------------------------------------------------------------------------------------------
void UCPPW_Chest::NativeConstruct()
{
	auto* player_character = Cast<ACPP_Character_Master>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	auto* player_controller = Cast<ACPP_Player_Controller>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	if (!IsValid(player_character) || !IsValid(player_controller) || !Inventory_Slot_Widget)
	{
		GEngine->AddOnScreenDebugMessage(-1, 4.0, FColor::Blue, TEXT("CPPW_Inventory, player_character or player_controller or Inventory_Slot_Widget is not valid!"));
		return;
	}
	int temp_chest_slots = player_character->GetChestComponent()->Max_Chest_Slots;
	int temp_mis_per_row = player_character->GetChestComponent()->MIS_Per_Row;
	for (int i = 0; i < temp_chest_slots; i++)
	{
		auto *temp_slot_widget = CreateWidget<UCPPW_Inventory_Slot>(GetWorld(), Inventory_Slot_Widget);
		temp_slot_widget->Index = i;
		temp_slot_widget->Storage_Type = E_Storage_Type::E_Inventory;
		Uniform_Grid_Panel->AddChildToUniformGrid(temp_slot_widget, i / temp_mis_per_row, i % temp_mis_per_row);
	}
	player_controller->UpdateInventory();
}
//-------------------------------------------------------------------------------------------------------------