
#include "CPP_Character_Master.h"
#include "Kismet/GameplayStatics.h"
#include "GameplayTagsManager.h"
#include "GameDev/CPP_Stats_Component.h"
#include "CPP_Player_Controller.h"
#include "CPP_Inventory_Component.h"
#include "CPP_Chest_Component.h"


//-------------------------------------------------------------------------------------------------------------

ACPP_Character_Master::ACPP_Character_Master()
{

	PrimaryActorTick.bCanEverTick = true;

}

//-------------------------------------------------------------------------------------------------------------

FGameplayTagContainer ACPP_Character_Master::GetCharacterStatus()
{
	return Character_Status;
}

UCPP_Stats_Component* ACPP_Character_Master::GetStatsComponent()
{
	UCPP_Stats_Component *temp = Cast<UCPP_Stats_Component>(FindComponentByClass<UCPP_Stats_Component>());
	return temp;
}

UCPP_Inventory_Component* ACPP_Character_Master::GetInventoryComponent()
{
	UCPP_Inventory_Component *temp = Cast<UCPP_Inventory_Component>(FindComponentByClass<UCPP_Inventory_Component>());
	return temp;
}

UCPP_Chest_Component* ACPP_Character_Master::GetChestComponent()
{
	UCPP_Chest_Component *temp = Cast<UCPP_Chest_Component>(FindComponentByClass<UCPP_Chest_Component>());
	return temp;
}

//-------------------------------------------------------------------------------------------------------------

void ACPP_Character_Master::BeginPlay()
{
	Super::BeginPlay();
	
}

//-------------------------------------------------------------------------------------------------------------

void ACPP_Character_Master::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//-------------------------------------------------------------------------------------------------------------

void ACPP_Character_Master::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//-------------------------------------------------------------------------------------------------------------

void ACPP_Character_Master::PlusCharacterParameters(FS_Parameters s_parameters, bool basic_change)
{
	if (basic_change)
	{
		GetStatsComponent()->S_Parameters = Basic_Character_Parameters + s_parameters;		
	}
	else
	{
		GetStatsComponent()->S_Parameters = GetStatsComponent()->S_Parameters + s_parameters;
	}

	ACPP_Player_Controller* player_controller = Cast<ACPP_Player_Controller>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	
	player_controller->UpdateHP(GetStatsComponent()->S_Parameters.HP_Current, GetStatsComponent()->S_Parameters.HP_Max);
	player_controller->UpdateMP(GetStatsComponent()->S_Parameters.MP_Current, GetStatsComponent()->S_Parameters.MP_Max);

}

//-------------------------------------------------------------------------------------------------------------

void ACPP_Character_Master::Character_Movement(double action_value_x, double action_value_y)
{
	FGameplayTag tag_iscasting = UGameplayTagsManager::Get().RequestGameplayTag(FName("Character.bIsCasting"));
	FGameplayTag tag_isdead = UGameplayTagsManager::Get().RequestGameplayTag(FName("Character.bIsDead"));

	if (Character_Status.HasTag(tag_iscasting) || Character_Status.HasTag(tag_isdead))
		return;


		FVector local_movement(action_value_x,action_value_y, 0.0);
	
		this->AddMovementInput(local_movement);

		if(action_value_x == 1 && action_value_y == 1)
			this->GetMesh()->SetWorldRotation(FRotator(0.0, -45.0, 0.0));
		else if(action_value_x == -1 && action_value_y == 1)
			this->GetMesh()->SetWorldRotation(FRotator(0.0, 45.0, 0.0));
		else if(action_value_x == -1 && action_value_y == -1)
			this->GetMesh()->SetWorldRotation(FRotator(0.0, 135.0, 0.0));
		else if(action_value_x == 1 && action_value_y == -1)
			this->GetMesh()->SetWorldRotation(FRotator(0.0, 225.0, 0.0));
		else if (action_value_x == 1)
			this->GetMesh()->SetWorldRotation(FRotator(0.0, -90.0, 0.0));
		else if(action_value_x == -1)
			this->GetMesh()->SetWorldRotation(FRotator(0.0, 90.0, 0.0));
		else if(action_value_y == 1)
			this->GetMesh()->SetWorldRotation(FRotator(0.0, 0.0, 0.0));
		else if(action_value_y == -1)
			this->GetMesh()->SetWorldRotation(FRotator(0.0, 180.0, 0.0));
	

}

//-------------------------------------------------------------------------------------------------------------