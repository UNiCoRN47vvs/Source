#include "CPP_Player_Controller.h"
#include "Blueprint/UserWidget.h"
#include "Widget/CPPW_HealthBar.h"
#include "Widget/CPPW_Level_Bar.h"

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

//-------------------------------------------------------------------------------------------------------------