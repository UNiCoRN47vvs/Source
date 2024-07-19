#include "Widget/CPPW_Item_Menu.h"
#include "TimerManager.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Animation/WidgetAnimation.h"
//-------------------------------------------------------------------------------------------------------------
void UCPPW_Item_Menu::HideItemMenu()
{
	this->PlayAnimationReverse(Show_Hide_Anim);
	UKismetSystemLibrary::K2_ClearAndInvalidateTimerHandle(GetWorld(), Timer_Handle);
	UKismetSystemLibrary::K2_ClearAndInvalidateTimerHandle(GetWorld(), Main_Timer_Handle);

	FLatentActionInfo latent_info;
	latent_info.CallbackTarget = this;
	latent_info.UUID = 1234;
	latent_info.ExecutionFunction = FName("SelfRemoveFromParent");
	latent_info.Linkage = 0;
	UKismetSystemLibrary::Delay(this, Show_Hide_Anim->GetEndTime(), latent_info);
}
//-------------------------------------------------------------------------------------------------------------
void UCPPW_Item_Menu::SelfRemoveFromParent()
{
	this->RemoveFromParent();
}