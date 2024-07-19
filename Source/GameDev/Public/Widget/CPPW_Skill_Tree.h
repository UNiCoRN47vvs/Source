#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "CPPW_Skill_Tree.generated.h"
//-------------------------------------------------------------------------------------------------------------
UCLASS()
class GAMEDEV_API UCPPW_Skill_Tree : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable) void SetSkillPointsCount(int count);
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill_Tree", meta = (BindWidget)) UTextBlock *Skill_Points_Count;
};
//-------------------------------------------------------------------------------------------------------------