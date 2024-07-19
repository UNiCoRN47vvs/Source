#include "Widget/CPPW_HealthBar.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Math/UnrealMathUtility.h"

//-------------------------------------------------------------------------------------------------------------

void UCPPW_HealthBar::Update_HP_Bar(double current_hp, double max_hp)
{
	Progress_Bar->SetPercent(current_hp / max_hp);

	FString local_hp_str = FString::FromInt(FMath::FloorToInt(current_hp)) + " / " + FString::FromInt(FMath::FloorToInt(max_hp));

	Info_Text->SetText(FText::FromString(local_hp_str));
}

//-------------------------------------------------------------------------------------------------------------

void UCPPW_HealthBar::Update_MP_Bar(double current_mp, double max_mp)
{
	Progress_Bar->SetPercent(current_mp / max_mp);

	FString local_mp_str = FString::FromInt(FMath::FloorToInt(current_mp)) + " / " + FString::FromInt(FMath::FloorToInt(max_mp));

	Info_Text->SetText(FText::FromString(local_mp_str));
}

//-------------------------------------------------------------------------------------------------------------

void UCPPW_HealthBar::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseIvent)
{
	Info_Text->SetVisibility(ESlateVisibility::Visible);
}

//-------------------------------------------------------------------------------------------------------------

void UCPPW_HealthBar::NativeOnMouseLeave(const FPointerEvent& InMouseIvent)
{
	Info_Text->SetVisibility(ESlateVisibility::Collapsed);
}

//-------------------------------------------------------------------------------------------------------------