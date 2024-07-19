#include "Actor/CPP_Master_Item.h"
#include "Kismet/GameplayStatics.h"
#include "CPP_Player_Controller.h"
#include "GameplayTagsManager.h"
#include "Structure/S_Items.h"
#include "Widget/CPPW_Items_Nameplate.h"
#include "Widget/CPPW_Mini_Map_Icon.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
//-------------------------------------------------------------------------------------------------------------
ACPP_Master_Item::ACPP_Master_Item()
{
	PrimaryActorTick.bCanEverTick = true;

	Static_Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Static Mesh");
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Widget = CreateDefaultSubobject<UWidgetComponent>("Widget");
	Mini_Map_Widget = CreateDefaultSubobject<UWidgetComponent>("Mini Map Widget");

	
	Static_Mesh->SetupAttachment(RootComponent);
	Sphere->SetupAttachment(Static_Mesh);
	Widget->SetupAttachment(Static_Mesh);
	Mini_Map_Widget->SetupAttachment(Static_Mesh);
}
//-------------------------------------------------------------------------------------------------------------
void ACPP_Master_Item::InitParams()
{
	ACPP_Player_Controller* player_controller = Cast<ACPP_Player_Controller>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	if (!IsValid(player_controller))
		return;

	FGameplayTag temp_tag = UGameplayTagsManager::Get().RequestGameplayTag(FName("ControllerStatus.L_Alt"));
	if (player_controller->Controller_Status.HasTag(temp_tag))
	{
		Widget->SetVisibility(true);
	}
	
	const auto temp_dt_row = DT_All_Items.DataTable->FindRow<FS_Items>(Item_Row_Name, "");

	if (!temp_dt_row)
	{
		Destroy();
		return;
	}

	UCPPW_Items_Nameplate *temp_widget_nameplate = Cast<UCPPW_Items_Nameplate>(Widget->GetWidget());
	UCPPW_Mini_Map_Icon* temp_widget_mini_map = Cast<UCPPW_Mini_Map_Icon>(Mini_Map_Widget->GetWidget());

	temp_widget_nameplate->TB_Text->SetText(FText::FromName(temp_dt_row->Name));

	UTexture2D* loaded_icon = temp_dt_row->Item_Icon.LoadSynchronous();
	if (loaded_icon)
	{
		temp_widget_mini_map->Image->SetBrushFromTexture(loaded_icon);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 4.0, FColor::Blue, TEXT("Failed to load icon from soft reference"));
	}
	
	UStaticMesh *loaded_mesh = temp_dt_row->Item_Static_Mesh.LoadSynchronous();
	if (loaded_mesh)
	{
		Static_Mesh->SetStaticMesh(loaded_mesh);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 4.0, FColor::Blue, TEXT("Failed to load mesh from soft reference"));
	}
}
//-------------------------------------------------------------------------------------------------------------
void ACPP_Master_Item::BeginPlay()
{
	Super::BeginPlay();
}
//-------------------------------------------------------------------------------------------------------------

