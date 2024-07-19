#include "CPP_Inventory_Component.h"
//-------------------------------------------------------------------------------------------------------------
UCPP_Inventory_Component::UCPP_Inventory_Component()
{
	PrimaryComponentTick.bCanEverTick = true;
}
//-------------------------------------------------------------------------------------------------------------
void UCPP_Inventory_Component::BeginPlay()
{
	if (Items_Array.Num() <= Max_Inventory_Slots)
	{
		for (int i = 0; i < Max_Inventory_Slots; ++i)
		{
			FS_Items temp;
			temp.Is_Not_Empty = false;
			Items_Array.Add(temp);
		}
	}
	Super::BeginPlay();
}
//-------------------------------------------------------------------------------------------------------------

