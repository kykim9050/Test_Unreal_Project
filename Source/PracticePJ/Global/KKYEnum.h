// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "KKYEnum.generated.h"


UENUM(BlueprintType)
enum class ETCPlayerAnimation : uint8
{
	Rifle_Idle			UMETA(DisplayName = "������ Idle"),
	Rifle_WalkForward	UMETA(DisplayName = "������ ��� �� �ȱ�"),
	Rifle_WalkBackward	UMETA(DisplayName = "������ ��� �ڷ� �ȱ�")
};

UENUM(BlueprintType)
enum class ESideScrollAni : uint8
{
	Run,
	Attack,
};


/**
 * 
 */
UCLASS()
class PRACTICEPJ_API UKKYEnum : public UObject
{
	GENERATED_BODY()
	
};
