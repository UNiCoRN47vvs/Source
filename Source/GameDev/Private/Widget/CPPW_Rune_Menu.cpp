#include "Widget/CPPW_Rune_Menu.h"
#include "Widget/CPPW_Inventory_Slot.h"

//-------------------------------------------------------------------------------------------------------------

void UCPPW_Rune_Menu::NativeConstruct()
{

	Inventory_Slot_Array.Add(WBP_Inventory_Slot);
	Inventory_Slot_Array.Add(WBP_Inventory_Slot_1);
	Inventory_Slot_Array.Add(WBP_Inventory_Slot_2);
	Inventory_Slot_Array.Add(WBP_Inventory_Slot_3);
	Inventory_Slot_Array.Add(WBP_Inventory_Slot_4);
}
