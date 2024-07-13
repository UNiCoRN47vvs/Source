#include "Widget/CPPW_Upgrade_Menu.h"
#include "Widget/CPPW_Inventory_Slot.h"
#include "Kismet/DataTableFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameDev/CPP_Character_Master.h"
#include "CPP_Player_Controller.h"
#include "Structure/S_Upgrade_Item_Chance.h"

//-------------------------------------------------------------------------------------------------------------
void UCPPW_Upgrade_Menu::NativeConstruct()
{
	Upgrade_Slot_Widget.Add(WBP_Inventory_Slot);
	Upgrade_Slot_Widget.Add(WBP_Inventory_Slot_1);
}
//-------------------------------------------------------------------------------------------------------------
void UCPPW_Upgrade_Menu::UpdateText()
{
	int temp_item_level = Upgrade_Storage[0].Item_Level;
	FString temp_string = FString::Printf(TEXT("%i"),temp_item_level);
	FName temp_row_name(*temp_string);

	if (Upgrade_Storage[0].Amount <= 0)
		Upgrade_Chance->SetText(FText{});

	if (Upgrade_Fails_Count > 0)
		Upgrade_Fails->SetText(FText::AsNumber(Upgrade_Fails_Count));
	else
		Upgrade_Fails->SetText(FText{});

	auto dt_row = Data_Table.DataTable->FindRow<FS_Upgrade_Item_Chance>(temp_row_name, "");
	if (!dt_row)
		GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Blue, "Upgrade_Menu, Data Table Row Not Found");

	Chance = FMath::Clamp(Chance + Upgrade_Fails_Count * Fails_Chance, 0.0, 100.0);
	Upgrade_Chance->SetText(FText::AsNumber(Chance));

}
//-------------------------------------------------------------------------------------------------------------
void UCPPW_Upgrade_Menu::CloseMenu()
{
	FS_Items temp_empty;
	auto* player_character = Cast<ACPP_Character_Master>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	auto* player_controller = Cast<ACPP_Player_Controller>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (!IsValid(player_character) || !IsValid(player_controller))
	{
		GEngine->AddOnScreenDebugMessage(-1, 4.0, FColor::Blue, TEXT("CPPW_Upgrade_Menu, player_character or player_controller is not valid!"));
		return;
	}

	this->SetVisibility(ESlateVisibility::Collapsed);
	UpdateText();
	for (auto& item : Upgrade_Storage)
	{
		if (item.Is_Not_Empty)
		{
			player_character->PickUpFunc(item.RN_ID, item.Amount, item.Item_Level);
			item = temp_empty;
		}
	}
	player_controller->UpdateInventory();
}
