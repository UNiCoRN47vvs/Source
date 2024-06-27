#include "CPP_Chest_Component.h"

//-------------------------------------------------------------------------------------------------------------

UCPP_Chest_Component::UCPP_Chest_Component()
{
	PrimaryComponentTick.bCanEverTick = true;

}

//-------------------------------------------------------------------------------------------------------------

void UCPP_Chest_Component::BeginPlay()
{
	if (Items_Array.Num() <= Max_Chest_Slots)
	{
		for (int i = 0; i < Max_Chest_Slots; ++i)
		{
			FS_Items temp;
			Items_Array.Add(temp);
		}
	}

	Super::BeginPlay();	
}

//-------------------------------------------------------------------------------------------------------------
