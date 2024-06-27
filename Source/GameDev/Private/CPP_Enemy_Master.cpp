#include "CPP_Enemy_Master.h"

//-------------------------------------------------------------------------------------------------------------

ACPP_Enemy_Master::ACPP_Enemy_Master()
{
	PrimaryActorTick.bCanEverTick = true;
}

//-------------------------------------------------------------------------------------------------------------

void ACPP_Enemy_Master::BeginPlay()
{
	Super::BeginPlay();
	
}

//-------------------------------------------------------------------------------------------------------------

void ACPP_Enemy_Master::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//-------------------------------------------------------------------------------------------------------------