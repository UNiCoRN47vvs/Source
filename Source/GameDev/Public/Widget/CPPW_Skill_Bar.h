#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/HorizontalBox.h"
#include "CPPW_Skill_Bar.generated.h"
//-------------------------------------------------------------------------------------------------------------
UCLASS()
class GAMEDEV_API UCPPW_Skill_Bar : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget), Category = "CPPW_Skill_Bar") UHorizontalBox *Horizontal_Box_64;
};
//-------------------------------------------------------------------------------------------------------------