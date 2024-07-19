#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "CPPW_Character_Stats.generated.h"
//-------------------------------------------------------------------------------------------------------------
class ACPP_Character_Master;
//-------------------------------------------------------------------------------------------------------------
UCLASS()
class GAMEDEV_API UCPPW_Character_Stats : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable) void UpdateCharacterStatsMenu();
private:
	bool IsEnoughSkillPoints();
	void SetWidgetVisibility(ESlateVisibility visibility);
	UPROPERTY(meta = (BindWidget)) UTextBlock *Power_TextBlock;
	UPROPERTY(meta = (BindWidget)) UTextBlock *Dexterity_TextBlock;
	UPROPERTY(meta = (BindWidget)) UTextBlock *Attack_Speed_TextBlock;
	UPROPERTY(meta = (BindWidget)) UTextBlock *Critical_TextBlock;
	UPROPERTY(meta = (BindWidget)) UTextBlock *Health_TextBlock;
	UPROPERTY(meta = (BindWidget)) UTextBlock *Mana_TextBlock;
	UPROPERTY(meta = (BindWidget)) UTextBlock *Protection_TextBlock;
	UPROPERTY(meta = (BindWidget)) UTextBlock *Evasion_TextBlock;
	UPROPERTY(meta = (BindWidget)) UTextBlock *Luck_TextBlock;
	UPROPERTY(meta = (BindWidget)) UTextBlock *Gold_TextBlock;
	UPROPERTY(meta = (BindWidget)) UButton *Power_Button;
	UPROPERTY(meta = (BindWidget)) UButton *Dexterity_Button;
	UPROPERTY(meta = (BindWidget)) UButton *Attack_Speed_Button;
	UPROPERTY(meta = (BindWidget)) UButton *Critical_Button;
	UPROPERTY(meta = (BindWidget)) UButton *Health_Button;
	UPROPERTY(meta = (BindWidget)) UButton *Mana_Button;
	UPROPERTY(meta = (BindWidget)) UButton *Protection_Button;
	UPROPERTY(meta = (BindWidget)) UButton *Evasion_Button;
	UPROPERTY(meta = (BindWidget)) UButton *Luck_Button;
	UPROPERTY(meta = (BindWidget)) UButton *Gold_Button;
	ACPP_Character_Master *Player_Character;
};
//-------------------------------------------------------------------------------------------------------------