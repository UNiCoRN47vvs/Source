#include "BFL/CPP_BFL.h"
#include "UObject/ConstructorHelpers.h"

UDataTable* UCPP_BFL::Data_Table = nullptr;

//-------------------------------------------------------------------------------------------------------------

UCPP_BFL::UCPP_BFL()
{
	//Записываем в переменную таблицу
	static ConstructorHelpers::FObjectFinder<UDataTable> DataTableObj(TEXT("/Script/Engine.DataTable'/Game/DT_All_Items.DT_All_Items'"));
	if (DataTableObj.Succeeded())
	{
		Data_Table = DataTableObj.Object;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 4.0, FColor::Blue, TEXT("DT Not Found DT_All_Items (CPP_BFL.cpp)"));
	}
}

[[__UNREAL_ENGINE_UFUNCTION__]] void UCPP_BFL::GetUseValueDTR(FName dtr_name, int item_level, double &return_use_value, FS_Items &return_item_row, FS_Rune_Stats &return_rune_stats)
{
	const FS_Items *temp_table_row = Data_Table->FindRow<FS_Items>(dtr_name, "GENERAL", true);

	if (temp_table_row)
		switch (temp_table_row->Item_Type)
	{

	case E_Items_Type::E_None:
	case E_Items_Type::E_Quest_Item:
	case E_Items_Type::E_Currency:
	case E_Items_Type::E_Portal:
		break;

	case E_Items_Type::E_Health_Bottle: 
	case E_Items_Type::E_Mana_Bottle:

		return_use_value = temp_table_row->Use_Value + (item_level - 1) * 5;
		return_item_row = *temp_table_row;
		break;

	case E_Items_Type::E_Supplies:
		switch (temp_table_row->Supplies_Info)
		{
		case E_Supplies_Info::E_None:
			break;

		case E_Supplies_Info::E_Inc_Health:
		case E_Supplies_Info::E_Inc_Mana:
			return_use_value = temp_table_row->Use_Value + (item_level - 1) * (temp_table_row->Use_Value / 5);
			return_item_row = *temp_table_row;
			break;

		case E_Supplies_Info::E_Inc_Regen_HP:
		case E_Supplies_Info::E_Inc_Regen_MP:
			return_use_value = temp_table_row->Use_Value + (item_level - 1) * (temp_table_row->Use_Value / 10);
			return_item_row = *temp_table_row;
			break;
		}
		break;
	
	
	case E_Items_Type::E_Rune:

		if (temp_table_row->Rune_Stats.Max_HP != 0)
		{
			for (int i = 0; i < item_level; i++)
			{
				return_rune_stats.Max_HP = temp_table_row->Rune_Stats.Max_HP + 1;
			}
		}

		if (temp_table_row->Rune_Stats.Regen_HP != 0)
		{
			for (int i = 0; i < item_level; i++)
			{
				return_rune_stats.Regen_HP = temp_table_row->Rune_Stats.Regen_HP + 0.25;
			}
		}

		if (temp_table_row->Rune_Stats.Max_MP != 0)
		{
			for (int i = 0; i < item_level; i++)
			{
				return_rune_stats.Max_MP = temp_table_row->Rune_Stats.Max_MP + 1;
			}
		}

		if (temp_table_row->Rune_Stats.Regen_MP != 0)
		{
			for (int i = 0; i < item_level; i++)
			{
				return_rune_stats.Regen_MP = temp_table_row->Rune_Stats.Regen_MP + 0.25;
			}
		}

		if (temp_table_row->Rune_Stats.Evasion != 0)
		{
			for (int i = 0; i < item_level; i++)
			{
				return_rune_stats.Evasion = temp_table_row->Rune_Stats.Evasion + 0.1;
			}
		}

		if (temp_table_row->Rune_Stats.Hit_Rate_Chance != 0)
		{
			for (int i = 0; i < item_level; i++)
			{
				return_rune_stats.Hit_Rate_Chance = temp_table_row->Rune_Stats.Hit_Rate_Chance + 0.1;
			}
		}

		if (temp_table_row->Rune_Stats.Crit_Rate_Chance != 0)
		{
			for (int i = 0; i < item_level; i++)
			{
				return_rune_stats.Crit_Rate_Chance = temp_table_row->Rune_Stats.Crit_Rate_Chance + 0.1;
			}
		}

		if (temp_table_row->Rune_Stats.Protection_Rate != 0)
		{
			for (int i = 0; i < item_level; i++)
			{
				return_rune_stats.Protection_Rate = temp_table_row->Rune_Stats.Protection_Rate + 0.1;
			}
		}

		if (temp_table_row->Rune_Stats.Power_Rate != 0)
		{
			for (int i = 0; i < item_level; i++)
			{
				return_rune_stats.Power_Rate = temp_table_row->Rune_Stats.Power_Rate + 0.2;
			}
		}

		if (temp_table_row->Rune_Stats.Attack_Speed != 0)
		{
			for (int i = 0; i < item_level; i++)
			{
				return_rune_stats.Attack_Speed = temp_table_row->Rune_Stats.Attack_Speed + 0.01;
			}
		}

		break;
	}

	return;
}
