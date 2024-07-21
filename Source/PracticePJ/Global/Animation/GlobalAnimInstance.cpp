// Fill out your copyright notice in the Description page of Project Settings.


#include "Global/Animation/GlobalAnimInstance.h"

void UGlobalAnimInstance::ChangeAnimation(uint8 _Key)
{
	if (false == AnimMontages.Contains(_Key))
	{
		UE_LOG(LogType, Fatal, TEXT("%S(%u)> if (false == AnimMontages.Contains(Key))"), __FUNCTION__, __LINE__);
		return;
	}

	UAnimMontage* Mon = AnimMontages[_Key];

	if (nullptr == Mon)
	{
		UE_LOG(LogType, Fatal, TEXT("%S(%u)> if (nullptr == Mon)"), __FUNCTION__, __LINE__);
		return;
	}

	UAnimMontage* PrevMon = GetCurrentActiveMontage();

	if (nullptr == PrevMon && nullptr != Mon)
	{

	}

	if (PrevMon != Mon)
	{
		Montage_Play(Mon);
	}
}

void UGlobalAnimInstance::PushAnimation(uint8 _Key, UAnimMontage* _Montage)
{
	if (true == AnimMontages.Contains(_Key))
	{
		return;
	}

	AnimMontages.Add(_Key, _Montage);
}