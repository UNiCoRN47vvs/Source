#include "Widget/CPPW_Character_Stats.h"
#include "Kismet/GameplayStatics.h"
#include "GameDev/CPP_Character_Master.h"
#include "GameDev/CPP_Stats_Component.h"
//-------------------------------------------------------------------------------------------------------------
void UCPPW_Character_Stats::UpdateCharacterStatsMenu()
{
	if (!Player_Character)
		Player_Character = Cast<ACPP_Character_Master>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	Player_Character->SetCharacterParameters();

	if (IsEnoughSkillPoints())
		SetWidgetVisibility(ESlateVisibility::Visible);
	else
		SetWidgetVisibility(ESlateVisibility::Hidden);
}
//-------------------------------------------------------------------------------------------------------------
bool UCPPW_Character_Stats::IsEnoughSkillPoints()
{
	if (!Player_Character)
		Player_Character = Cast<ACPP_Character_Master>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	int local_skill_points = Player_Character->GetStatsComponent()->S_Character_Stats.Skill_Points;

	if (local_skill_points > 0)
		return true;

	return false;
}
void UCPPW_Character_Stats::SetWidgetVisibility(ESlateVisibility visibility)
{
	Power_Button->SetVisibility(visibility);
	Dexterity_Button->SetVisibility(visibility);
	Attack_Speed_Button->SetVisibility(visibility);
	Critical_Button->SetVisibility(visibility);
	Health_Button->SetVisibility(visibility);
	Mana_Button->SetVisibility(visibility);
	Protection_Button->SetVisibility(visibility);
	Evasion_Button->SetVisibility(visibility);
	Luck_Button->SetVisibility(visibility);
	Gold_Button->SetVisibility(visibility);
}
//-------------------------------------------------------------------------------------------------------------