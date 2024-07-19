#include "Widget/CPPW_Rune_Menu.h"
#include "Widget/CPPW_Inventory_Slot.h"
#include "Widget/CPPW_Rune_Menu_Stats_Text.h"
#include "GameDev/CPP_Character_Master.h"
#include "GameDev/CPP_Stats_Component.h"
#include "Kismet/GameplayStatics.h"
//-------------------------------------------------------------------------------------------------------------
void UCPPW_Rune_Menu::NativeConstruct()
{
	Super::NativeConstruct();
	Inventory_Slot_Array.Add(WBP_Inventory_Slot);
	Inventory_Slot_Array.Add(WBP_Inventory_Slot_1);
	Inventory_Slot_Array.Add(WBP_Inventory_Slot_2);
	Inventory_Slot_Array.Add(WBP_Inventory_Slot_3);
	Inventory_Slot_Array.Add(WBP_Inventory_Slot_4);

	Vertical_Text_Box_Array.Add(Vertical_Text_Box);
	Vertical_Text_Box_Array.Add(Vertical_Text_Box_1);
	Vertical_Text_Box_Array.Add(Vertical_Text_Box_2);
	Vertical_Text_Box_Array.Add(Vertical_Text_Box_3);
	Vertical_Text_Box_Array.Add(Vertical_Text_Box_4);

	Text_Block_Array.Add(Text_Block);
	Text_Block_Array.Add(Text_Block_1);
	Text_Block_Array.Add(Text_Block_2);
	Text_Block_Array.Add(Text_Block_3);
	Text_Block_Array.Add(Text_Block_4);
}
//-------------------------------------------------------------------------------------------------------------
void UCPPW_Rune_Menu::InitParamsRuneMenu()
{
	for (int i = 0; i < Inventory_Slot_Array.Num(); i++)
	{
		Text_Block_Array[i]->SetText(FText::FromString("Empty"));
		Vertical_Text_Box_Array[i]->ClearChildren();

		if (!Inventory_Slot_Array[i]->Map_Rune_Stats.IsEmpty())
		{
			FString temp_text = "Level " + Inventory_Slot_Array[i]->Level;
			TArray<FName> temp_keys;
			FText temp_sign;
			auto *temp_character = Cast<ACPP_Character_Master>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
			UCPP_Stats_Component *temp_character_stats = temp_character->GetStatsComponent();

			Text_Block_Array[i]->SetText(FText::FromString(temp_text));
			Inventory_Slot_Array[i]->Map_Rune_Stats.GetKeys(temp_keys);

			for (auto item : temp_keys)
			{
				auto temp_value = Inventory_Slot_Array[i]->Map_Rune_Stats.Find(item);
				if (*temp_value > 0)
				{
					temp_sign = FText::FromString("+");
				}
				else
				{
					temp_sign = FText::FromString("");
				}

				auto temp_widget = CreateWidget<UCPPW_Rune_Menu_Stats_Text>(GetWorld());
				temp_widget->InitTBSample(temp_sign, FText::AsNumber(*temp_value), FText::FromName(item));

				Vertical_Text_Box_Array[i]->AddChildToVerticalBox(temp_widget);
			}

			if (!temp_character_stats->Rune_Array_Check[Inventory_Slot_Array[i]->Index])
			{
				FS_Rune_Stats temp_rune = temp_character_stats->Rune_Array[Inventory_Slot_Array[i]->Index].Rune_Stats;
				FS_Parameters temp_param;

				temp_param.HP_Max = temp_rune.Max_HP;
				temp_param.HP_Regen = temp_rune.Regen_HP;
				temp_param.MP_Max = temp_rune.Max_MP;
				temp_param.MP_Regen = temp_rune.Regen_MP;
				temp_param.Evasion = temp_rune.Evasion;
				temp_param.Hit_Rate_Chance = temp_rune.Hit_Rate_Chance;
				temp_param.Crit_Rate_Chance = temp_rune.Crit_Rate_Chance;
				temp_param.Protection_Rate = temp_rune.Protection_Rate;
				temp_param.Power_Rate = temp_rune.Power_Rate;
				temp_param.Attack_Speed = temp_rune.Attack_Speed;

				temp_character->PlusCharacterParameters(temp_param, false);
				temp_character_stats->Rune_Array_Check[Inventory_Slot_Array[i]->Index] = true;
			}
		}
	}

}
//-------------------------------------------------------------------------------------------------------------