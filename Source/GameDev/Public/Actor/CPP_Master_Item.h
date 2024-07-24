#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "CPP_Master_Item.generated.h"

//-------------------------------------------------------------------------------------------------------------

UCLASS()
class GAMEDEV_API ACPP_Master_Item : public AActor
{
	GENERATED_BODY()
	
public:	

	ACPP_Master_Item();

	UFUNCTION(BlueprintCallable) void InitParams();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components") TObjectPtr<UStaticMeshComponent> Static_Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components") TObjectPtr<USphereComponent> Sphere;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components") TObjectPtr<UWidgetComponent> Widget;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components") TObjectPtr<UWidgetComponent> Mini_Map_Widget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item info", meta = (ExposeOnSpawn = "true") ) FName Item_Row_Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item info", meta = (ExposeOnSpawn = "true") ) int Amount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item info", meta = (ExposeOnSpawn = "true") ) int Item_Level;



protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info") FDataTableRowHandle DT_All_Items;
};

//-------------------------------------------------------------------------------------------------------------