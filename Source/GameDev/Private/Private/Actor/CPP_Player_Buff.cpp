#include "Actor/CPP_Player_Buff.h"
#include "Kismet/GameplayStatics.h"
#include "GameDev/CPP_Character_Master.h"
#include "TimerManager.h"
#include "Templates/Function.h"
#include "CPP_Player_Controller.h"
#include "Blueprint/UserWidget.h"
#include "Structure/S_Rune_Stats.h"
#include "Structure/S_Items.h"
#include "Widget/CPPW_Buff_Icon.h"
//-------------------------------------------------------------------------------------------------------------
ACPP_Player_Buff::ACPP_Player_Buff()
{
	PrimaryActorTick.bCanEverTick = true;
}
//-------------------------------------------------------------------------------------------------------------
void ACPP_Player_Buff::AddWidget()
{
	if (!Player_Controller)
		Player_Controller = Cast<ACPP_Player_Controller>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	Widget_Buff = CreateWidget<UCPPW_Buff_Icon>(GetWorld(), Widget_Buff_Icon);
	Widget_Buff->Name = Name;
	Widget_Buff->Time = Time_Buff;
	Player_Controller->Main_HUD->Buff_Info_Menu->AddChild(Widget_Buff);
}
void ACPP_Player_Buff::RemoveWidget()
{
	if (!Player_Controller)
		Player_Controller = Cast<ACPP_Player_Controller>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	Player_Controller->Main_HUD->Buff_Info_Menu->RemoveChild(Widget_Buff);
}
//-------------------------------------------------------------------------------------------------------------
void ACPP_Player_Buff::BeginPlay()
{
	Player_Character = Cast<ACPP_Character_Master>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (!Player_Character)
	{
		GEngine->AddOnScreenDebugMessage(0, 5, FColor::Blue, FString(TEXT("CPP_Player_Buff, player_character cast failed")));
		return;
	}

	this->AttachToActor(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, true), FName{});

	FS_Rune_Stats local_rune_stats;
	FS_Items local_item_row;
	Player_Character->GetUseValue(Name, Item_Level, Use_Value, local_item_row, local_rune_stats);
	Supplies_Info = local_item_row.Supplies_Info;

	if (Is_Load)
	{
		switch (Supplies_Info)
		{
		case E_Supplies_Info::E_None:
			break;

		case E_Supplies_Info::E_Inc_Health:
		{
			FS_Parameters local_parameters;
			local_parameters.HP_Max = Use_Value;
			// Функция для установки таймера с заданной функцией обратного вызова и параметрами.
			SetBuffTimer([this](FS_Parameters local_parameters) {DeactivateIncrease(local_parameters); }, local_parameters);
		}
			break;

		case E_Supplies_Info::E_Inc_Mana:
		{
			FS_Parameters local_parameters;
			local_parameters.MP_Max = Use_Value;
			// Функция для установки таймера с заданной функцией обратного вызова и параметрами.
			SetBuffTimer([this](FS_Parameters local_parameters) {DeactivateIncrease(local_parameters); }, local_parameters);
		}
			break;

		case E_Supplies_Info::E_Inc_Regen_HP:
		{
			FS_Parameters local_parameters;
			local_parameters.HP_Regen = Use_Value;
			// Функция для установки таймера с заданной функцией обратного вызова и параметрами.
			SetBuffTimer([this](FS_Parameters local_parameters) {DeactivateIncrease(local_parameters); }, local_parameters);
		}
			break;

		case E_Supplies_Info::E_Inc_Regen_MP:
		{
			FS_Parameters local_parameters;
			local_parameters.MP_Regen = Use_Value;
			// Функция для установки таймера с заданной функцией обратного вызова и параметрами.
			SetBuffTimer([this](FS_Parameters local_parameters) {DeactivateIncrease(local_parameters); }, local_parameters);
		}
			break;


		default:
			break;
		}
	}
	else 
	{
		Time_Buff = local_item_row.Time_Buff;

		switch (Supplies_Info)
		{
		case E_Supplies_Info::E_None:
			break;


		case E_Supplies_Info::E_Inc_Health:
		{
			FS_Parameters local_parameters;
			local_parameters.HP_Max = Use_Value;
			Player_Character->PlusCharacterParameters(local_parameters, false);
			// Функция для установки таймера с заданной функцией обратного вызова и параметрами.
			SetBuffTimer([this](FS_Parameters local_parameters) {DeactivateIncrease(local_parameters); }, local_parameters);
		}
		break;


		case E_Supplies_Info::E_Inc_Mana:
		{
			FS_Parameters local_parameters;
			local_parameters.MP_Max = Use_Value;
			Player_Character->PlusCharacterParameters(local_parameters, false);
			// Функция для установки таймера с заданной функцией обратного вызова и параметрами.
			SetBuffTimer([this](FS_Parameters local_parameters) {DeactivateIncrease(local_parameters); }, local_parameters);
		}
			break;


		case E_Supplies_Info::E_Inc_Regen_HP:
			{
			FS_Parameters local_parameters;
			local_parameters.HP_Regen = Use_Value;
			Player_Character->PlusCharacterParameters(local_parameters, false);
			// Функция для установки таймера с заданной функцией обратного вызова и параметрами.
			SetBuffTimer([this](FS_Parameters local_parameters) {DeactivateIncrease(local_parameters); }, local_parameters);
			}
			break;


		case E_Supplies_Info::E_Inc_Regen_MP:
			{
			FS_Parameters local_parameters;
			local_parameters.MP_Regen = Use_Value;
			Player_Character->PlusCharacterParameters(local_parameters, false);
			// Функция для установки таймера с заданной функцией обратного вызова и параметрами.
			SetBuffTimer([this](FS_Parameters local_parameters) {DeactivateIncrease(local_parameters); }, local_parameters);
			}
			break;


		default:
			break;
		}
	}
	Super::BeginPlay();
}
//-------------------------------------------------------------------------------------------------------------
void ACPP_Player_Buff::SetBuffTimer(TFunction<void(FS_Parameters)> Func, FS_Parameters parameters)
{
	AddWidget();

	FTimerDelegate timer_del;
	timer_del.BindLambda([this, Func, parameters]() { Func(parameters); });
	GetWorld()->GetTimerManager().SetTimer(Timer_Handle, timer_del, 0.25, true);
}
void ACPP_Player_Buff::DeactivateIncrease(FS_Parameters parameters)
{
	if (Time_Buff <= 0)
	{
		if (!Player_Character)
			Player_Character = Cast<ACPP_Character_Master>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

		Player_Character->MinusCharacterParameters(parameters, false);
		RemoveWidget();
		Destroy();
	}
	else
	{
		Time_Buff -= 0.25;
		Widget_Buff->Time = Time_Buff;
	}
}
//-------------------------------------------------------------------------------------------------------------
void ACPP_Player_Buff::ActivateBuff()
{
	switch (Supplies_Info)
	{
	case E_Supplies_Info::E_None:
	case E_Supplies_Info::E_Inc_Regen_HP:
	case E_Supplies_Info::E_Inc_Regen_MP:
		break;


	case E_Supplies_Info::E_Inc_Health:
	{
		if (!Player_Character)
			Player_Character = Cast<ACPP_Character_Master>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

		FS_Parameters local_parameters;
		local_parameters.HP_Max = Use_Value;
		Player_Character->PlusCharacterParameters(local_parameters, false);

	}
		break;


	case E_Supplies_Info::E_Inc_Mana:
	{
		if (!Player_Character)
			Player_Character = Cast<ACPP_Character_Master>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

		FS_Parameters local_parameters;
		local_parameters.MP_Max = Use_Value;
		Player_Character->PlusCharacterParameters(local_parameters, false);
	}
		break;


	default:
		break;
	}
}
void ACPP_Player_Buff::DeactivateBuff()
{
	Time_Buff = 0.0;

	switch (Supplies_Info)
	{
	case E_Supplies_Info::E_None:
		break;

	case E_Supplies_Info::E_Inc_Health:
	{
		FS_Parameters local_parameters;
		local_parameters.HP_Max = Use_Value;
		DeactivateIncrease(local_parameters);
	}
		break;


	case E_Supplies_Info::E_Inc_Mana:
	{
			FS_Parameters local_parameters;
			local_parameters.MP_Max = Use_Value;
			DeactivateIncrease(local_parameters);
	}
		break;


	case E_Supplies_Info::E_Inc_Regen_HP:
	{
			FS_Parameters local_parameters;
			local_parameters.HP_Regen = Use_Value;
			DeactivateIncrease(local_parameters);
	}
		break;


	case E_Supplies_Info::E_Inc_Regen_MP:
	{
			FS_Parameters local_parameters;
			local_parameters.MP_Regen = Use_Value;
			DeactivateIncrease(local_parameters);
	}
		break;


	default:
		break;
	}
}
//-------------------------------------------------------------------------------------------------------------