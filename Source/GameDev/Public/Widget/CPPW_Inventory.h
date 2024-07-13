#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/UniformGridPanel.h"
#include "CPPW_Inventory.generated.h"

//-------------------------------------------------------------------------------------------------------------
class UCPPW_Inventory_Slot;
//-------------------------------------------------------------------------------------------------------------
UCLASS()
class GAMEDEV_API UCPPW_Inventory : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget") int Gold;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget)) UUniformGridPanel *Uniform_Grid_Panel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget") TSubclassOf<UCPPW_Inventory_Slot> Inventory_Slot_Widget;
protected:
	virtual void NativeConstruct() override;
};
//-------------------------------------------------------------------------------------------------------------