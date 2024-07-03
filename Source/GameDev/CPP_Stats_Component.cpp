#include "CPP_Stats_Component.h"

//-------------------------------------------------------------------------------------------------------------

UCPP_Stats_Component::UCPP_Stats_Component()
{
	PrimaryComponentTick.bCanEverTick = true;

	
}

//-------------------------------------------------------------------------------------------------------------

void UCPP_Stats_Component::BeginPlay()
{

	FS_Items temp_item;
	for (int i = 0; i < 5; i++)
	{
		
		Rune_Array.Add(temp_item);
	}
	Super::BeginPlay();	
}

//-------------------------------------------------------------------------------------------------------------

