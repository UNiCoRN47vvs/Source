#include "Widget/CPPW_Skill_Tree.h"
//-------------------------------------------------------------------------------------------------------------
void UCPPW_Skill_Tree::SetSkillPointsCount(int count)
{
	FString local_string = FString(TEXT("Skill Points: ")) + FString::FromInt(count);
	FText local_text = FText::FromString(local_string);
	Skill_Points_Count->SetText(local_text);
}
//-------------------------------------------------------------------------------------------------------------
