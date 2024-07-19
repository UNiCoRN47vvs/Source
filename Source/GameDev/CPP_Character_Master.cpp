#include "CPP_Character_Master.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "GameplayTagsManager.h"
#include "GameDev/CPP_Stats_Component.h"
#include "CPP_Player_Controller.h"
#include "CPP_Inventory_Component.h"
#include "CPP_Chest_Component.h"
#include "Actor/CPP_Master_Item.h"
#include "Actor/CPP_Player_Buff.h"
#include "Structure/S_Character_Stats_Multiplier.h"
#include "Structure/S_Rune_Stats.h"
//-------------------------------------------------------------------------------------------------------------
ACPP_Character_Master::ACPP_Character_Master()
{

	PrimaryActorTick.bCanEverTick = true;

}
//-------------------------------------------------------------------------------------------------------------
//Getters
FGameplayTagContainer ACPP_Character_Master::GetCharacterStatus()
{
	return Character_Status;
}
UCPP_Stats_Component* ACPP_Character_Master::GetStatsComponent()
{
	UCPP_Stats_Component *temp = Cast<UCPP_Stats_Component>(FindComponentByClass<UCPP_Stats_Component>());
	return temp;
}
UCPP_Inventory_Component* ACPP_Character_Master::GetInventoryComponent()
{
	UCPP_Inventory_Component *temp = Cast<UCPP_Inventory_Component>(FindComponentByClass<UCPP_Inventory_Component>());
	return temp;
}
UCPP_Chest_Component* ACPP_Character_Master::GetChestComponent()
{
	UCPP_Chest_Component *temp = Cast<UCPP_Chest_Component>(FindComponentByClass<UCPP_Chest_Component>());
	return temp;
}
//-------------------------------------------------------------------------------------------------------------
void ACPP_Character_Master::BeginPlay()
{
	Super::BeginPlay();
}
//-------------------------------------------------------------------------------------------------------------
void ACPP_Character_Master::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
//-------------------------------------------------------------------------------------------------------------
void ACPP_Character_Master::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
//-------------------------------------------------------------------------------------------------------------
//Parameters
void ACPP_Character_Master::PlusCharacterParameters(FS_Parameters s_parameters, bool basic_change)
{
	if (basic_change)
	{
		GetStatsComponent()->S_Parameters = Basic_Character_Parameters + s_parameters;		
	}
	else
	{
		GetStatsComponent()->S_Parameters = GetStatsComponent()->S_Parameters + s_parameters;
	}

	ACPP_Player_Controller* player_controller = Cast<ACPP_Player_Controller>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	
	player_controller->UpdateHP(GetStatsComponent()->S_Parameters.HP_Current, GetStatsComponent()->S_Parameters.HP_Max);
	player_controller->UpdateMP(GetStatsComponent()->S_Parameters.MP_Current, GetStatsComponent()->S_Parameters.MP_Max);

}
void ACPP_Character_Master::MinusCharacterParameters(FS_Parameters s_parameters, bool basic_change)
{
	if (basic_change)
	{
		GetStatsComponent()->S_Parameters = Basic_Character_Parameters - s_parameters;		
	}
	else
	{
		GetStatsComponent()->S_Parameters = GetStatsComponent()->S_Parameters - s_parameters;
	}

	ACPP_Player_Controller* player_controller = Cast<ACPP_Player_Controller>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	player_controller->UpdateHP(GetStatsComponent()->S_Parameters.HP_Current, GetStatsComponent()->S_Parameters.HP_Max);
	player_controller->UpdateMP(GetStatsComponent()->S_Parameters.MP_Current, GetStatsComponent()->S_Parameters.MP_Max);
}
void ACPP_Character_Master::SetCharacterParameters()
{
	FS_Parameters result_parameters;
	FS_Character_Stats_Multiplier stats_multiplier;
	UCPP_Stats_Component *stats_component = GetStatsComponent();

	result_parameters.HP_Max = stats_multiplier.Health_Multiplier * (double)stats_component->S_Character_Stats.Health;
	result_parameters.MP_Max = stats_multiplier.Mana_Multiplier * (double)stats_component->S_Character_Stats.Mana;
	result_parameters.Evasion = stats_multiplier.Evasion_Multiplier * (double)stats_component->S_Character_Stats.Evasion;
	result_parameters.Hit_Rate_Chance = stats_multiplier.Dexterity_Multiplier * (double)stats_component->S_Character_Stats.Dexterity;
	result_parameters.Crit_Rate_Chance = stats_multiplier.Critical_Chance_Multiplier * (double)stats_component->S_Character_Stats.Critical_Chance;
	result_parameters.Protection_Rate = stats_multiplier.Protection_Multiplier * (double)stats_component->S_Character_Stats.Protection;
	result_parameters.Power_Rate = stats_multiplier.Power_Multiplier * (double)stats_component->S_Character_Stats.Power;
	result_parameters.Attack_Speed = stats_multiplier.Attack_Speed_Multiplier * (double)stats_component->S_Character_Stats.Attack_Speed;

	PlusCharacterParameters(result_parameters, true);

	stats_component->S_Basic_Drop_Chance.Drop_Fail -= stats_multiplier.Luck_Multiplier * (double)stats_component->S_Character_Stats.Luck;
	stats_component->S_Basic_Drop_Chance.Drop_Max_Amount_Gold -= stats_multiplier.Gold_Multiplier * (double)stats_component->S_Character_Stats.Gold;
	
	TArray<AActor*, FDefaultAllocator> local_actors;
	GetAttachedActors(local_actors, true, false);
	for (auto item : local_actors)
	{
		auto *player_buff = Cast<ACPP_Player_Buff>(item);

		if (player_buff)
		{
			player_buff->ActivateBuff();
		}
	}
}
//-------------------------------------------------------------------------------------------------------------
void ACPP_Character_Master::Character_Movement(double action_value_x, double action_value_y)
{
	FGameplayTag tag_iscasting = UGameplayTagsManager::Get().RequestGameplayTag(FName("Character.bIsCasting"));
	FGameplayTag tag_isdead = UGameplayTagsManager::Get().RequestGameplayTag(FName("Character.bIsDead"));

	if (Character_Status.HasTag(tag_iscasting) || Character_Status.HasTag(tag_isdead))
		return;


		FVector local_movement(action_value_x,action_value_y, 0.0);
	
		this->AddMovementInput(local_movement);

		if(action_value_x == 1 && action_value_y == 1)
			this->GetMesh()->SetWorldRotation(FRotator(0.0, -45.0, 0.0));
		else if(action_value_x == -1 && action_value_y == 1)
			this->GetMesh()->SetWorldRotation(FRotator(0.0, 45.0, 0.0));
		else if(action_value_x == -1 && action_value_y == -1)
			this->GetMesh()->SetWorldRotation(FRotator(0.0, 135.0, 0.0));
		else if(action_value_x == 1 && action_value_y == -1)
			this->GetMesh()->SetWorldRotation(FRotator(0.0, 225.0, 0.0));
		else if (action_value_x == 1)
			this->GetMesh()->SetWorldRotation(FRotator(0.0, -90.0, 0.0));
		else if(action_value_x == -1)
			this->GetMesh()->SetWorldRotation(FRotator(0.0, 90.0, 0.0));
		else if(action_value_y == 1)
			this->GetMesh()->SetWorldRotation(FRotator(0.0, 0.0, 0.0));
		else if(action_value_y == -1)
			this->GetMesh()->SetWorldRotation(FRotator(0.0, 180.0, 0.0));
	

}
//-------------------------------------------------------------------------------------------------------------
bool ACPP_Character_Master::IsInventoryFull()
{
	int count = 0;

	for (FS_Items item : GetInventoryComponent()->Items_Array)
	{
		if (item.Is_Not_Empty)
			++count;
	}

	return GetInventoryComponent()->Items_Array.Num() == count;
}
//-------------------------------------------------------------------------------------------------------------
void ACPP_Character_Master::AddItemToSlot(int amount, FS_Items s_items, int item_level)
{
	for (auto &item : GetInventoryComponent()->Items_Array)
	{
		if (!item.Is_Not_Empty)
		{
			auto *player_controller = Cast<ACPP_Player_Controller>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

			item = s_items;
			item.Amount = amount;
			item.Is_Not_Empty = true;
			item.Item_Level = item_level;
			if (player_controller)
				player_controller->UpdateInventory();

			break;
		}
	}
}
//-------------------------------------------------------------------------------------------------------------
bool ACPP_Character_Master::PickUpFunc(FName item_row_name, int amount, int item_level)
{
	const auto dt_row = DT_All_Items.DataTable->FindRow<FS_Items>(item_row_name, "");
	auto *player_controller = Cast<ACPP_Player_Controller>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (!dt_row || !player_controller)
		return false;

	if (dt_row->Item_Type == E_Items_Type::E_Currency)
	{
		if (GetInventoryComponent()->Currency.Gold > dt_row->Max_Count)
			return false;

		GetInventoryComponent()->Currency.Gold += amount;
		player_controller->UpdateInventory();
		player_controller->PickUpItemInfo(item_row_name, amount);
		return true;
	}
	else
	{
		TArray<FS_Items> &temp_inventory_items = GetInventoryComponent()->Items_Array;

		player_controller->UpdateInventory();
		player_controller->PickUpItemInfo(item_row_name, amount);

		if (!IsInventoryFull())
		{
			int temp_max_count = dt_row->Max_Count;
			int array_count = 0;

			for (int i = 0; i < temp_inventory_items.Num(); i++)
			{
				const bool is_not_empty = temp_inventory_items[i].Is_Not_Empty;
				const bool is_rn_id_same = dt_row->RN_ID == temp_inventory_items[i].RN_ID;
				const bool is_item_level_same = temp_inventory_items[i].Item_Level == item_level;
				const bool is_max_amount_same = temp_inventory_items[i].Amount == dt_row->Max_Count;

				if(is_not_empty)
				{
					if (!is_rn_id_same || !is_item_level_same || is_max_amount_same)
					{
						++array_count;
						continue;
					}

					if ((temp_inventory_items[i].Amount + amount) <= dt_row->Max_Count)
					{
						temp_inventory_items[i].Amount += amount;
						break;
					}
				
					amount -= temp_inventory_items[i].Max_Count - temp_inventory_items[i].Amount;
					temp_inventory_items[i].Amount = temp_inventory_items[i].Max_Count;

					bool temp_pick_up = PickUpFunc(item_row_name, amount, item_level);
					return temp_pick_up;
				}
			}
			if (amount > dt_row->Max_Count)
			{
				double temp_result = amount / dt_row->Max_Count;

				for (int i = 0; i < amount % dt_row->Max_Count; i++)
				{
					if (!IsInventoryFull())
					{
						AddItemToSlot(amount, *dt_row, item_level);
						return true;
					}
					else
					{
						FActorSpawnParameters spawn_params;
						spawn_params.Owner = this;
						spawn_params.Instigator = GetInstigator();

						FVector spawn_localtion = this->GetActorLocation();
						FRotator spawn_rotation = this->GetActorRotation();
						
						auto *master_item = GetWorld()->SpawnActor<ACPP_Master_Item>(Master_Item, spawn_localtion, spawn_rotation, spawn_params);
						master_item->Amount = amount;
						master_item->Item_Row_Name = dt_row->RN_ID;
						master_item->Item_Level = item_level;
						return true;
					}					
				}
				if (FMath::TruncToInt(temp_result) == 0)
					return false;

				if (!IsInventoryFull())
				{
					AddItemToSlot(temp_result, *dt_row, item_level);
					return true;
				}
				else
				{
					FActorSpawnParameters spawn_params;
					spawn_params.Owner = this;
					spawn_params.Instigator = GetInstigator();

					FVector spawn_localtion = this->GetActorLocation();
					FRotator spawn_rotation = this->GetActorRotation();

					auto *master_item = GetWorld()->SpawnActor<ACPP_Master_Item>(Master_Item, spawn_localtion, spawn_rotation, spawn_params);
					master_item->Amount = temp_result;
					master_item->Item_Row_Name = dt_row->RN_ID;
					master_item->Item_Level = item_level;
					return true;
				}
			}
			else
			{
				AddItemToSlot(amount, *dt_row, item_level);
				return true;
			}
		}
		else
		{
			for (auto &item : temp_inventory_items)
			{
				if (!(item.RN_ID == dt_row->RN_ID && item.Item_Level == dt_row->Item_Level && item.Amount != item.Max_Count))
					return false;

				int temp_item_result = item.Max_Count - item.Amount;

				player_controller->PickUpItemInfo(item_row_name, temp_item_result);

				FActorSpawnParameters spawn_params;
				spawn_params.Owner = this;
				spawn_params.Instigator = GetInstigator();

				FVector spawn_localtion = this->GetActorLocation();
				FRotator spawn_rotation = this->GetActorRotation();

				auto *master_item = GetWorld()->SpawnActor<ACPP_Master_Item>(Master_Item, spawn_localtion, spawn_rotation, spawn_params);
				master_item->Amount = amount - temp_item_result;
				master_item->Item_Row_Name = dt_row->RN_ID;
				master_item->Item_Level = item_level;

				item.Amount = item.Max_Count;
				return true;
			}
		}
		return false;
	}
}
//-------------------------------------------------------------------------------------------------------------
void ACPP_Character_Master::ChangeRuneStats(const double parameter,const int item_level, double& rune_stats_result,const double value)
{
	if (parameter != 0)
	{
		for (int i = 0; i < item_level; i++)
		{
			rune_stats_result += value;
		}
	}
	return;
}
void ACPP_Character_Master::GetUseValue(FName item_row_name, int item_level, double& use_value, FS_Items& item_row, FS_Rune_Stats& rune_stats)
{
	auto dt_row = DT_All_Items.DataTable->FindRow<FS_Items>(item_row_name, "");

	switch (dt_row->Item_Type)
	{
		case E_Items_Type::E_None :
		case E_Items_Type::E_Quest_Item :
		case E_Items_Type::E_Currency :
		case E_Items_Type::E_Portal :
			break;

		case E_Items_Type::E_Health_Bottle :
		case E_Items_Type::E_Mana_Bottle :
			use_value = dt_row->Use_Value + (item_level - 1) * 5;
			item_row = *dt_row;
			break;

		case E_Items_Type::E_Supplies :
			switch (dt_row->Supplies_Info)
			{
				case E_Supplies_Info::E_None :
					break;

				case E_Supplies_Info::E_Inc_Health :
				case E_Supplies_Info::E_Inc_Mana :
					use_value = dt_row->Use_Value / 5 * (item_level - 1) + dt_row->Use_Value;
					item_row = *dt_row;
					break;

				case E_Supplies_Info::E_Inc_Regen_HP :
				case E_Supplies_Info::E_Inc_Regen_MP :
					use_value = dt_row->Use_Value / 10 * (item_level - 1) + dt_row->Use_Value;
					item_row = *dt_row;
					break;

				default:
					break;
			}
			break;

		case E_Items_Type::E_Rune:
			
			ChangeRuneStats(dt_row->Rune_Stats.Max_HP, item_level, rune_stats.Max_HP, 1.0);
			ChangeRuneStats(dt_row->Rune_Stats.Regen_HP, item_level, rune_stats.Regen_HP, 0.25);
			ChangeRuneStats(dt_row->Rune_Stats.Max_MP, item_level, rune_stats.Max_MP, 1.0);
			ChangeRuneStats(dt_row->Rune_Stats.Regen_MP, item_level, rune_stats.Regen_MP, 0.25);
			ChangeRuneStats(dt_row->Rune_Stats.Evasion, item_level, rune_stats.Evasion, 0.1);
			ChangeRuneStats(dt_row->Rune_Stats.Hit_Rate_Chance, item_level, rune_stats.Hit_Rate_Chance, 0.1);
			ChangeRuneStats(dt_row->Rune_Stats.Crit_Rate_Chance, item_level, rune_stats.Crit_Rate_Chance, 0.1);
			ChangeRuneStats(dt_row->Rune_Stats.Protection_Rate, item_level, rune_stats.Protection_Rate, 0.1);
			ChangeRuneStats(dt_row->Rune_Stats.Power_Rate, item_level, rune_stats.Power_Rate, 0.2);
			ChangeRuneStats(dt_row->Rune_Stats.Attack_Speed, item_level, rune_stats.Attack_Speed, 0.01);
			break;

		default:
			break;
	}
	return;
}
//-------------------------------------------------------------------------------------------------------------