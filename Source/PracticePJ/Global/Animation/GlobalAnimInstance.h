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

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	uint8 AniKey;
};
