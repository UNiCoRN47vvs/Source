#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CPPW_Item_Info_Panel.generated.h"

//-------------------------------------------------------------------------------------------------------------

UCLASS()
class GAMEDEV_API UCPPW_Item_Info_Panel : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Var", meta = (ExposeOnSpawn = "VALUE")) int Item_Level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Var", meta = (ExposeOnSpawn = "VALUE")) double Value;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Var", meta = (ExposeOnSpawn = "VALUE")) FName Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Var", meta = (ExposeOnSpawn = "VALUE")) FText Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Var", meta = (ExposeOnSpawn = "VALUE")) TSoftObjectPtr<UTexture2D> Image_Icon;
};

//-------------------------------------------------------------------------------------------------------------