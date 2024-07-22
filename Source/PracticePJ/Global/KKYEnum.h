// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "KKYEnum.generated.h"


UENUM(BlueprintType)
enum class ETCPlayerAnimation : uint8
{
	Rifle_Idle				UMETA(DisplayName = "라이플 들고 Idle"),
	Rifle_WalkForward		UMETA(DisplayName = "라이플 들고 전방 걷기"),
	Rifle_WalkForwardLeft	UMETA(DisplayName = "라이플 들고 전방 좌측 걷기"),
	Rifle_WalkForwardRight	UMETA(DisplayName = "라이플 들고 전방 우측 걷기"),
	Rifle_WalkBackward		UMETA(DisplayName = "라이플 들고 후방 걷기"),
	Rifle_WalkBackwardLeft	UMETA(DisplayName = "라이플 들고 후방 좌측 걷기"),
	Rifle_WalkBackwardRight	UMETA(DisplayName = "라이플 들고 후방 우측 걷기"),
	Rifle_WalkLeft			UMETA(DisplayName = "라이플 들고 좌측 걷기"),
	Rifle_WalkRight			UMETA(DisplayName = "라이플 들고 우측 걷기")
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
