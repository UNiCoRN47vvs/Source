#include "Widget/CPPW_Upgrade_Menu.h"
#include "Widget/CPPW_Inventory_Slot.h"

//-------------------------------------------------------------------------------------------------------------

void UCPPW_Upgrade_Menu::NativeConstruct()
{
	Upgrade_Slot_Widget.Add(WBP_Inventory_Slot);
	Upgrade_Slot_Widget.Add(WBP_Inventory_Slot_1);
}
