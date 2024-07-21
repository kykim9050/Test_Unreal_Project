// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GlobalAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICEPJ_API UGlobalAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	template<typename EnumType>
	void ChangeAnimation(EnumType _Key)
	{
		ChangeAnimation(static_cast<uint8>(_Key));
	}

	void ChangeAnimation(uint8 _Key);

protected:

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TMap<uint8, class UAnimMontage*> AnimMontages = TMap<uint8, class UAnimMontage*>();
};
