#include "Widget/CPPW_Rune_Menu_Stats_Text.h"

//-------------------------------------------------------------------------------------------------------------

void UCPPW_Rune_Menu_Stats_Text::InitTBSample(FText sign, FText value, FText stat_name)
{
	Text_Block_Sample->SetText(FText::Format(sign, value, stat_name));
}
