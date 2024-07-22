#include "Widget/CPPW_Inventory_Slot.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "GameDev/CPP_Character_Master.h"
#include "GameDev/CPP_Stats_Component.h"
#include "Components/CanvasPanelSlot.h"
#include "CPP_Player_Controller.h"
#include "BFL/CPP_BFL.h"
#include "Widget/CPPW_Item_Info_Panel.h"
#include "Widget/CPPW_Item_Menu.h"
//-------------------------------------------------------------------------------------------------------------
void UCPPW_Inventory_Slot::GetRuneStats()
{
	if (Storage_Type != E_Storage_Type::E_Rune_Menu)
		return;

	auto *character = Cast<ACPP_Character_Master>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if(!character)
	{
		GEngine->AddOnScreenDebugMessage(-1, 4.0, FColor::Blue, TEXT("CPPW_Inventory_Slot, player_character is not valid!"));
		return;
	}

	UCPP_Stats_Component *stats_component = character->GetStatsComponent();

	Level = stats_component->Rune_Array[Index].Item_Level;

	double temp_double;
	FS_Items temp_fitems;
	FS_Rune_Stats rune_stats;
	UCPP_BFL::GetUseValueDTR(stats_component->Rune_Array[Index].RN_ID, Level ,temp_double, temp_fitems,  rune_stats);

	Map_Rune_Stats.Empty();

	if (rune_stats.Max_HP != 0)
		Map_Rune_Stats.Add(FName("MaxHP"), rune_stats.Max_HP);

	if (rune_stats.Regen_HP != 0)
		Map_Rune_Stats.Add(FName("RegenHP"), rune_stats.Regen_HP);

	if (rune_stats.Max_MP != 0)
		Map_Rune_Stats.Add(FName("MaxMP"), rune_stats.Max_MP);

	if (rune_stats.Regen_MP != 0)
		Map_Rune_Stats.Add(FName("RegenMP"), rune_stats.Regen_MP);

	if (rune_stats.Evasion != 0)
		Map_Rune_Stats.Add(FName("Evasion"), rune_stats.Evasion);

	if (rune_stats.Hit_Rate_Chance != 0)
		Map_Rune_Stats.Add(FName("Hit Rate Chance"), rune_stats.Hit_Rate_Chance);

	if (rune_stats.Crit_Rate_Chance != 0)
		Map_Rune_Stats.Add(FName("Crit Rate Chance"), rune_stats.Crit_Rate_Chance);

	if (rune_stats.Protection_Rate != 0)
		Map_Rune_Stats.Add(FName("Protection Rate"), rune_stats.Protection_Rate);

	if (rune_stats.Power_Rate != 0)
		Map_Rune_Stats.Add(FName("Power Rate"), rune_stats.Power_Rate);

	if (rune_stats.Attack_Speed != 0)
		Map_Rune_Stats.Add(FName("Attack Speed"), rune_stats.Attack_Speed);

}
//-------------------------------------------------------------------------------------------------------------
void UCPPW_Inventory_Slot::SetNewSlot(FName name, int amount, TSoftObjectPtr<UTexture2D> icon)
{
	Name = name;
	Amount = amount;
	Item_Icon = icon;

	GetRuneStats();

	UTexture2D* loaded_item_icon = Item_Icon.LoadSynchronous();
	if (!loaded_item_icon)
	{
		UTexture2D* loaded_slot_icon = Slot_Icon.LoadSynchronous();
		if(loaded_slot_icon)
			Border_Icon->SetBrushFromTexture(loaded_slot_icon);
	} 
	else 
		Border_Icon->SetBrushFromTexture(loaded_item_icon);

	if (Name == "")
	{
		Tool_Tip = nullptr;
	}
	else
	{
		Tool_Tip = CreateWidget<UCPPW_Item_Info_Panel>(GetWorld(), Widget_Class);
	}
}
//-------------------------------------------------------------------------------------------------------------
void UCPPW_Inventory_Slot::ShowItemMenuWidget(int item_index, E_Items_Type item_type, E_Storage_Type temp_storage_type)
{
	if (!Player_Controller)
		Player_Controller = Cast<ACPP_Player_Controller>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	if (Player_Controller->Main_HUD->Current_Item_Menu_Widget)
		Player_Controller->Main_HUD->Current_Item_Menu_Widget->HideItemMenu();

	auto* local_widget = CreateWidget<UCPPW_Item_Menu>(GetWorld(), Item_Menu_Widget);
	Player_Controller->Main_HUD->Current_Item_Menu_Widget = local_widget;

	auto canvas_panel_slot = Player_Controller->Main_HUD->Canvas->AddChildToCanvas(Player_Controller->Main_HUD->Current_Item_Menu_Widget);
	FVector2D local_mouse_position = UWidgetLayoutLibrary::GetMousePositionOnViewport(GetWorld());

	canvas_panel_slot->SetAutoSize(false);
	local_mouse_position.X -= 50;
	local_mouse_position.Y -= 10;
	canvas_panel_slot->SetPosition(local_mouse_position);


}
