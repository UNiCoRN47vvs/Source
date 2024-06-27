#include "Widget/CPPW_Level_Bar.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Math/UnrealMathUtility.h"

//-------------------------------------------------------------------------------------------------------------


void UCPPW_Level_Bar::Update_EXP_Bar(double current_exp, double need_exp, int level)
{
	Progress_Bar->SetPercent(current_exp / need_exp);

	FString local_exp_str = FString::FromInt(FMath::FloorToInt(current_exp)) + " / " + FString::FromInt(FMath::FloorToInt(need_exp));

	Info_Text->SetText(FText::FromString(local_exp_str));
	Level_TB->SetText(FText::FromString(FString::FromInt(level)));
}

//-------------------------------------------------------------------------------------------------------------

void UCPPW_Level_Bar::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseIvent)
{
	Info_Text->SetVisibility(ESlateVisibility::Visible);
}

//-------------------------------------------------------------------------------------------------------------

void UCPPW_Level_Bar::NativeOnMouseLeave(const FPointerEvent& InMouseIvent)
{
	Info_Text->SetVisibility(ESlateVisibility::Collapsed);
}

//-------------------------------------------------------------------------------------------------------------