#include "Widget/CPPW_Pick_Up_Info.h"
#include "Structure/S_Items.h"
//-------------------------------------------------------------------------------------------------------------
void UCPPW_Pick_Up_Info::NativeConstruct()
{
	auto dt_row = Data_Table.DataTable->FindRow<FS_Items>(Name, "");
	if (!dt_row)
	{
		GEngine->AddOnScreenDebugMessage(0, 5, FColor::Cyan, FString(TEXT("CPPW_Pick_Up_Info, data table row not found!")));
		this->RemoveFromParent();
	}

	UTexture2D *load_item_icon = dt_row->Item_Icon.LoadSynchronous();
	if (!load_item_icon)
	{
		GEngine->AddOnScreenDebugMessage(0, 5, FColor::Cyan, FString(TEXT("CPPW_Pick_Up_Info, item icon not loaded!")));
		this->RemoveFromParent();
	}

	Image->SetBrushFromTexture(load_item_icon);
	SetItemText();

	Super::NativeConstruct();
}
//-------------------------------------------------------------------------------------------------------------
void UCPPW_Pick_Up_Info::SetItemText()
{
	Item_Name_TB->SetText(FText::FromName(Name));
	Amount_TB->SetText(FText::AsNumber(Amount));
}
//-------------------------------------------------------------------------------------------------------------