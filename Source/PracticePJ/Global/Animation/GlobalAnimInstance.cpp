// Fill out your copyright notice in the Description page of Project Settings.


#include "Global/Animation/GlobalAnimInstance.h"

void UGlobalAnimInstance::ChangeAnimation(const FString& _AniName)
{
	if (false == AnimMontages.Contains(_AniName))
	{
		UE_LOG(LogType, Fatal, TEXT("%S(%u)> if (false == AnimMontages.Contains(Key))"), __FUNCTION__, __LINE__);
		return;
	}

	UAnimMontage* Montage = AnimMontages[_AniName];

	if (nullptr == Montage)
	{
		UE_LOG(LogType, Fatal, TEXT("%S(%u)> if (nullptr == Montage)"), __FUNCTION__, __LINE__);
		return;
	}

	Montage_Play(Montage);
}