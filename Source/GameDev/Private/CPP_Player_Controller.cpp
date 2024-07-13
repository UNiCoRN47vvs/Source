#include "CPP_Player_Controller.h"
#include "Blueprint/UserWidget.h"
#include "Actor/CPP_Portal_Altar.h"
#include "Widget/CPPW_HealthBar.h"
#include "Widget/CPPW_Level_Bar.h"
#include "Widget/CPPW_Main_HUD.h"
#include "Widget/CPPW_Inventory.h"
#include "Widget/CPPW_Inventory_Slot.h"
#include "Widget/CPPW_Chest.h"
#include "Widget/CPPW_Portal_Altar.h"
#include "Widget/CPPW_Rune_Menu.h"
#include "Widget/CPPW_Upgrade_Menu.h"
#include "Widget/CPPW_Inventory_Slot.h"
#include "Widget/CPPW_Pick_Up_Info.h"
#include "Widget/CPPW_Pick_Up_Menu.h"
#include "Kismet/GameplayStatics.h"
#include "GameDev/CPP_Character_Master.h"
#include "GameDev/CPP_Stats_Component.h"
#include "GameDev/CPP_Inventory_Component.h"
#include "GameDev/CPP_Chest_Component.h"
//-------------------------------------------------------------------------------------------------------------
void ACPP_Player_Controller::BeginPlay()
{
	Main_HUD = CreateWidget<UCPPW_Main_HUD>(GetWorld(), UCPPW_Main_HUD::StaticClass());
	Main_HUD->AddToViewport(0);

	Super::BeginPlay();
}
//-------------------------------------------------------------------------------------------------------------
//UPDATE
void ACPP_Player_Controller::UpdateHP(double current_hp, double max_hp)
{
	Main_HUD->WBP_Health_Bar->Update_HP_Bar(current_hp, max_hp);
}
void ACPP_Player_Controller::UpdateMP(double current_mp, double max_mp)
{
	Main_HUD->WBP_Mana_Bar->Update_MP_Bar(current_mp, max_mp);
}
void ACPP_Player_Controller::UpdateLevel(double current_exp, double need_exp, int level)
{
	Main_HUD->WBP_Level_Bar->Update_EXP_Bar(current_exp, need_exp, level);
}
void ACPP_Player_Controller::UpdateInventory()
{
	auto *character = Cast<ACPP_Character_Master>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if(!character)
	{
		GEngine->AddOnScreenDebugMessage(-1, 4.0, FColor::Blue, TEXT("CPP_Player_Controller, Character is not valid!"));
		return;
	}

	UCPP_Inventory_Component *inventory_component = character->GetInventoryComponent();
	UCPP_Chest_Component *chest_component = character->GetChestComponent();
	UCPP_Stats_Component *stats_component = character->GetStatsComponent();

	for (int i = 0; i < inventory_component->Items_Array.Num(); i++)
	{
		auto *item_icon = Cast<UCPPW_Inventory_Slot>(Main_HUD->WBP_Inventory->Uniform_Grid_Panel->GetChildAt(i));
		if (item_icon)
			item_icon->SetNewSlot(inventory_component->Items_Array[i]);
	}
	
	for (int i = 0; i < chest_component->Items_Array.Num(); i++)
	{
		auto *item_icon = Cast<UCPPW_Inventory_Slot>(Main_HUD->WBP_Chest->Uniform_Grid_Panel->GetChildAt(i));
		if (item_icon)
			item_icon->SetNewSlot(chest_component->Items_Array[i]);
	}

	auto *portal_altar = Cast<ACPP_Portal_Altar>(UGameplayStatics::GetActorOfClass(GetWorld(), ACPP_Portal_Altar::StaticClass()));
	if (IsValid(portal_altar) && Main_HUD->WBP_Portal_Altar)
		Main_HUD->WBP_Portal_Altar->Portal_Altar_Slot->SetNewSlot(portal_altar->Item_Structure);

	Main_HUD->WBP_Rune_Menu->InitParamsRuneMenu();

	for (int i = 0; i < Main_HUD->WBP_Upgrade_Menu->Upgrade_Storage.Num(); i++)
	{
		Main_HUD->WBP_Upgrade_Menu->Upgrade_Slot_Widget[i]->SetNewSlot(Main_HUD->WBP_Upgrade_Menu->Upgrade_Storage[i]);
	}

}
//-------------------------------------------------------------------------------------------------------------
//GET
FGameplayTagContainer ACPP_Player_Controller::GetControllerStatus()
{
	return Controller_Status;
}
//-------------------------------------------------------------------------------------------------------------
void ACPP_Player_Controller::PickUpItemInfo(FName name, int amount)
{
	switch (Main_HUD->WBP_Inventory->GetVisibility())
	{
		case ESlateVisibility::Collapsed:
		case ESlateVisibility::Hidden:
		auto *temp_widget = CreateWidget<UCPPW_Pick_Up_Info>(Pick_Up_Info);
		Main_HUD->WBP_Pick_Up_Menu->Vertical_Box->AddChild(temp_widget);
		break;

	}
}