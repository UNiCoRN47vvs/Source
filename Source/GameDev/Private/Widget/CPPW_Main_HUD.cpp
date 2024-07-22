#include "Widget/CPPW_Main_HUD.h"
#include "Widget/CPPW_Upgrade_Menu.h"
#include "GameDev/CPP_Inventory_Component.h"
#include "GameDev/CPP_Stats_Component.h"
#include "GameDev/CPP_Chest_Component.h"
#include "GameDev/CPP_Character_Master.h"
#include "CPP_Player_Controller.h"
#include "Widget/CPPW_HealthBar.h"
#include "Widget/CPPW_Level_Bar.h"
#include "Kismet/GameplayStatics.h"
#include "Structure/S_Items.h"
#include "Actor/CPP_Portal_Altar.h"
//-------------------------------------------------------------------------------------------------------------
void UCPPW_Main_HUD::DragDropLogic()
{
	ACPP_Character_Master *player_character = Cast<ACPP_Character_Master>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	ACPP_Player_Controller *player_controller = Cast<ACPP_Player_Controller>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	UCPP_Inventory_Component *character_inventory = player_character->GetInventoryComponent();
	UCPP_Chest_Component *character_chest = player_character->GetChestComponent();
	ACPP_Portal_Altar* temp_portal_altar = Cast<ACPP_Portal_Altar>(UGameplayStatics::GetActorOfClass(GetWorld(), Portal_Altar));
	UCPP_Stats_Component *character_stats = player_character->GetStatsComponent();

	if (!IsValid(player_character) || !IsValid(player_controller))
	{
		GEngine->AddOnScreenDebugMessage(-1, 4.0, FColor::Blue, TEXT("CPPW_Main_HUD, player_character or player_controller is not valid!"));
		return;
	}
	//Inventory to Inventory
	if (Drag_Storage_Type == E_Storage_Type::E_Inventory && Drop_Storage_Type == E_Storage_Type::E_Inventory)
	{
		if (Drop_Index == Drag_Index || !character_inventory->Items_Array[Drag_Index].Is_Not_Empty)
			return;

		FS_Items local_drag = character_inventory->Items_Array[Drag_Index];
		FS_Items local_drop = character_inventory->Items_Array[Drop_Index];

		if (local_drag.RN_ID == local_drop.RN_ID && !(local_drop.Amount == local_drop.Max_Count))
			AddItemSwitchItem(character_inventory->Items_Array, character_inventory->Items_Array);
		else
			character_inventory->Items_Array.Swap(Drag_Index, Drop_Index);

		return;
	}
	//Chest to Chest
	if (Drag_Storage_Type == E_Storage_Type::E_Chest && Drop_Storage_Type == E_Storage_Type::E_Chest)
	{
		if (Drop_Index == Drag_Index || !character_chest->Items_Array[Drag_Index].Is_Not_Empty)
			return;

		FS_Items local_drag = character_chest->Items_Array[Drag_Index];
		FS_Items local_drop = character_chest->Items_Array[Drop_Index];

		if (local_drag.RN_ID == local_drop.RN_ID && !(local_drop.Amount == local_drop.Max_Count))
		{
			AddItemSwitchItem(character_chest->Items_Array, character_chest->Items_Array);
		}
		else
		{
			character_chest->Items_Array.Swap(Drag_Index, Drop_Index);
		}
	}
	//Inventory to Chest
	if (Drag_Storage_Type == E_Storage_Type::E_Inventory && Drop_Storage_Type == E_Storage_Type::E_Chest)
	{
		if (Drop_Index == Drag_Index || !character_inventory->Items_Array[Drag_Index].Is_Not_Empty)
			return;

		FS_Items local_drag = character_inventory->Items_Array[Drag_Index];
		FS_Items local_drop = character_chest->Items_Array[Drop_Index];

		if (local_drag.RN_ID == local_drop.RN_ID && !(local_drop.Amount == local_drop.Max_Count))
		{
			AddItemSwitchItem(character_inventory->Items_Array, character_chest->Items_Array);
		}
		else
		{
			character_inventory->Items_Array[Drag_Index] = local_drop;
			character_chest->Items_Array[Drop_Index] = local_drag;
		}

	}
	//Chest to Inventory
	if (Drag_Storage_Type == E_Storage_Type::E_Chest && Drop_Storage_Type == E_Storage_Type::E_Inventory)
	{
		if (Drop_Index == Drag_Index || !character_chest->Items_Array[Drag_Index].Is_Not_Empty)
			return;

		FS_Items local_drag = character_chest->Items_Array[Drag_Index];
		FS_Items local_drop = character_inventory->Items_Array[Drop_Index];

		if (local_drag.RN_ID == local_drop.RN_ID && !(local_drop.Amount == local_drop.Max_Count))
		{
			AddItemSwitchItem(character_chest->Items_Array, character_inventory->Items_Array);
		}
		else
		{
			character_chest->Items_Array[Drag_Index] = local_drop;
			character_inventory->Items_Array[Drop_Index] = local_drag;
		}

	}
	//Inventory to DropZone
	if (Drag_Storage_Type == E_Storage_Type::E_Inventory && Drop_Storage_Type == E_Storage_Type::E_Drop_Zone)
	{
		FName temp_name;
		if (character_inventory->Items_Array[Drag_Index].RN_ID == temp_name)
			return;

		//SPAWN ITEM!!!!!!!!!
		GEngine->AddOnScreenDebugMessage(-1, 4.0, FColor::Blue, TEXT("Spawn Item!"));

		FS_Items temp_item;
		character_inventory->Items_Array[Drag_Index] = temp_item;
	}
	//Chest to DropZone
	if (Drag_Storage_Type == E_Storage_Type::E_Chest && Drop_Storage_Type == E_Storage_Type::E_Drop_Zone)
	{
		FName temp_name;
		if (character_chest->Items_Array[Drag_Index].RN_ID == temp_name)
			return;

		//SPAWN ITEM!!!!!!!!!
		GEngine->AddOnScreenDebugMessage(-1, 4.0, FColor::Blue, TEXT("Spawn Item!"));

		FS_Items temp_item;
		character_chest->Items_Array[Drag_Index] = temp_item;
	}
	//Inventory to PortalAltar
	if (Drag_Storage_Type == E_Storage_Type::E_Inventory && Drop_Storage_Type == E_Storage_Type::E_Portal_Altar)
	{
		if (character_inventory->Items_Array[Drag_Index].Item_Type != E_Items_Type::E_Portal)
			return;

		int temp_amount = character_inventory->Items_Array[Drag_Index].Amount - 1;
		FS_Items temp_item = character_inventory->Items_Array[Drag_Index];

		if (temp_amount > 0)
		{
			character_inventory->Items_Array[Drag_Index].Amount = temp_amount;
			temp_portal_altar->Item_Structure = temp_item;
		}
		else
		{
			character_inventory->Items_Array[Drag_Index] = temp_portal_altar->Item_Structure;
			temp_portal_altar->Item_Structure = temp_item;
		}
	}
	//PortalAltar to Inventory
	if (Drag_Storage_Type == E_Storage_Type::E_Portal_Altar && Drop_Storage_Type == E_Storage_Type::E_Inventory)
	{
		if (!character_inventory->Items_Array[Drop_Index].Is_Not_Empty)
		{
			FS_Items temp_item;

			character_inventory->Items_Array[Drop_Index] = temp_portal_altar->Item_Structure;
			temp_portal_altar->Item_Structure = temp_item;
		}
		else
		{
			if (character_inventory->Items_Array[Drop_Index].Item_Type != E_Items_Type::E_Portal)
				return;

			FS_Items temp_item = character_inventory->Items_Array[Drop_Index];

			character_inventory->Items_Array[Drop_Index] = temp_portal_altar->Item_Structure;
			temp_portal_altar->Item_Structure = temp_item;
		}
	}
	//Inventory to RuneMenu
	if (Drag_Storage_Type == E_Storage_Type::E_Inventory && Drop_Storage_Type == E_Storage_Type::E_Rune_Menu)
	{
		if (character_inventory->Items_Array[Drag_Index].Item_Type != E_Items_Type::E_Rune)
			return;

		FS_Items temp_item = character_inventory->Items_Array[Drag_Index];

		character_inventory->Items_Array[Drag_Index] = character_stats->Rune_Array[Drop_Index];
		character_stats->Rune_Array[Drop_Index] = temp_item;

	}
	//RuneMenu to Inventory
	if (Drag_Storage_Type == E_Storage_Type::E_Rune_Menu && Drop_Storage_Type == E_Storage_Type::E_Inventory)
	{
		if (character_inventory->Items_Array[Drop_Index].Is_Not_Empty)
			return;

		FS_Items temp_drag;
		FS_Rune_Stats temp_rune = character_stats->Rune_Array[Drag_Index].Rune_Stats;
		FS_Parameters temp_parameters;

		temp_parameters.HP_Max = -temp_rune.Max_HP;
		temp_parameters.HP_Regen = -temp_rune.Regen_HP;
		temp_parameters.MP_Max = -temp_rune.Max_MP;
		temp_parameters.MP_Regen = -temp_rune.Regen_MP;
		temp_parameters.Evasion = -temp_rune.Evasion;
		temp_parameters.Hit_Rate_Chance = -temp_rune.Hit_Rate_Chance;
		temp_parameters.Crit_Rate_Chance = -temp_rune.Crit_Rate_Chance;
		temp_parameters.Protection_Rate = -temp_rune.Protection_Rate;
		temp_parameters.Power_Rate = -temp_rune.Power_Rate;
		temp_parameters.Attack_Speed = -temp_rune.Attack_Speed;

		player_character->PlusCharacterParameters(temp_parameters, false);

		character_inventory->Items_Array[Drop_Index] = character_stats->Rune_Array[Drag_Index];
		character_stats->Rune_Array[Drag_Index] = temp_drag;
		character_stats->Rune_Array_Check[Drag_Index] = false;
	}
	//Inventory to Upgrade
	if (Drag_Storage_Type == E_Storage_Type::E_Inventory && Drop_Storage_Type == E_Storage_Type::E_Upgrate)
	{
		FS_Items temp_item = character_inventory->Items_Array[Drag_Index];
		if (Drop_Index != 1)
		{
			for (auto& item : WBP_Upgrade_Menu->Upgrade_Storage)
			{
				if (!item.Is_Not_Empty)
					continue;

				player_character->PickUpFunc(item.RN_ID, item.Amount, item.Item_Level);
				item = FS_Items{};
			}

			temp_item.Amount = --temp_item.Amount;
			WBP_Upgrade_Menu->Upgrade_Storage[Drop_Index] = temp_item;
			WBP_Upgrade_Menu->Upgrade_Storage[Drop_Index].Amount = 1;

			if (temp_item.Amount <= 0)
				temp_item = FS_Items{};

			WBP_Upgrade_Menu->UpdateText();
		}
		else
		{
			auto temp_item_type = WBP_Upgrade_Menu->Upgrade_Storage[0].Item_Type == temp_item.Item_Type;
			int temp_item_level = WBP_Upgrade_Menu->Upgrade_Storage[0].Item_Level == temp_item.Item_Level;

			if (!(temp_item_type && temp_item_level))
				return;

			temp_item.Amount = --temp_item.Amount;
			WBP_Upgrade_Menu->Upgrade_Storage[Drop_Index] = temp_item;
			WBP_Upgrade_Menu->Upgrade_Storage[Drop_Index].Amount = 1;

			if (temp_item.Amount <= 0)
				temp_item = FS_Items{};

		}


	}
	//Upgrade to Inventory
	if (Drag_Storage_Type == E_Storage_Type::E_Upgrate && Drop_Storage_Type == E_Storage_Type::E_Inventory)
	{
		FS_Items temp_item = character_inventory->Items_Array[Drop_Index];
		FS_Items temp_upgrade_storage = WBP_Upgrade_Menu->Upgrade_Storage[Drag_Index];
		FS_Items temp_empty;
		int temp_sum_amount = temp_item.Amount + temp_upgrade_storage.Amount;

		if (temp_item.Is_Not_Empty)
		{
			if (temp_upgrade_storage.Item_Type != temp_item.Item_Type || temp_upgrade_storage.Item_Level != temp_item.Item_Level)
			{
				if (temp_item.Amount > 1)
				{
					--character_inventory->Items_Array[Drop_Index].Amount;
					WBP_Upgrade_Menu->Upgrade_Storage[Drag_Index] = character_inventory->Items_Array[Drop_Index];
					for (auto& item : character_inventory->Items_Array)
					{
						if (!item.Is_Not_Empty)
						{
							item = temp_upgrade_storage;
							break;
						}
					}
				}
				else
				{
					WBP_Upgrade_Menu->Upgrade_Storage[Drag_Index] = temp_item;
					character_inventory->Items_Array[Drop_Index] = temp_upgrade_storage;
				}
			}
			else if(temp_sum_amount <= temp_item.Max_Count)
			{
				character_inventory->Items_Array[Drop_Index].Amount = temp_sum_amount;
				WBP_Upgrade_Menu->Upgrade_Storage[Drag_Index] = temp_empty;
			}
		}
		else
		{
			character_inventory->Items_Array[Drop_Index] = temp_upgrade_storage;
			WBP_Upgrade_Menu->Upgrade_Storage[Drag_Index] = temp_empty;
			player_character->PickUpFunc(temp_upgrade_storage.RN_ID, temp_upgrade_storage.Amount, temp_upgrade_storage.Item_Level);
		}

		WBP_Upgrade_Menu->UpdateText();
	}
}
//-------------------------------------------------------------------------------------------------------------
bool UCPPW_Main_HUD::NativeOnDrop(const FGeometry &InGeometry, const FDragDropEvent &InDragDropEvent, UDragDropOperation *InOperation)
{
	ACPP_Player_Controller *player_controller = Cast<ACPP_Player_Controller>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (!IsValid(player_controller))
	{
		GEngine->AddOnScreenDebugMessage(-1, 4.0, FColor::Blue, TEXT("CPPW_Main_HUD, player_controller is not valid!"));
		return false;
	}

	DragDropLogic();
	Drop_Storage_Type = E_Storage_Type::E_None;
	Drag_Storage_Type = E_Storage_Type::E_None;
	player_controller->UpdateInventory();
	return true;

}
//-------------------------------------------------------------------------------------------------------------
void UCPPW_Main_HUD::AddItemSwitchItem(TArray<FS_Items>& drag_array, TArray<FS_Items>& drop_array)
{
	int local_amount = drop_array[Drop_Index].Max_Count - drop_array[Drop_Index].Max_Count;

	if ((drag_array[Drag_Index].Amount + drop_array[Drop_Index].Amount) > drop_array[Drop_Index].Max_Count)
	{
		drop_array[Drop_Index].Amount = drop_array[Drop_Index].Max_Count;
		drag_array[Drag_Index].Amount -= local_amount;
	}
	else
	{
		drop_array[Drop_Index].Amount += drag_array[Drag_Index].Amount;
		FS_Items temp;
		drag_array[Drag_Index] = temp;
	}
}
//-------------------------------------------------------------------------------------------------------------