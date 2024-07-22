// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Global/KKYEnum.h"
#include "TCCharacterDataRow.generated.h"

/**
 * 
 */
USTRUCT()
struct FTCCharacterDataRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	FORCEINLINE float GetFrontWalkSpeed() const
	{
		return FrontWalkSpeed;
	}

	FORCEINLINE float GetBackWalkSpeed() const
	{
		return BackWalkSpeed;
	}

	FORCEINLINE float GetJumpValue() const
	{
		return JumpValue;
	}

	FORCEINLINE TMap<ETCPlayerAnimation, UAnimMontage*> GetAnimMontages() const
	{
		return AnimMontages;
	}

protected:

private:
	UPROPERTY(EditAnywhere, meta = (AllowprivateAccess = "true"))
	float FrontWalkSpeed = 0.0f;

	UPROPERTY(EditAnywhere, meta = (AllowprivateAccess = "true"))
	float BackWalkSpeed = 0.0f;

	UPROPERTY(EditAnywhere, meta = (AllowprivateAccess = "true"))
	float JumpValue = 0.0f;

	UPROPERTY(EditAnywhere, meta = (AllowprivateAccess = "true"))
	TMap<ETCPlayerAnimation, UAnimMontage*> AnimMontages = TMap<ETCPlayerAnimation, UAnimMontage*>();
};
