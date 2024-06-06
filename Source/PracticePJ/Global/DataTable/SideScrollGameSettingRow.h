// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SideScrollGameSettingRow.generated.h"


/**
 * 
 */

USTRUCT(BlueprintType)
struct FSideScrollPlayerData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Parameter")
	float PlayerSpeed = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameter")
	float PlayerJump = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameter")
	float PlayerGravityRatio = 1.0f;
};


USTRUCT(BlueprintType)
struct FSideScrollGameSettingRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameter")
	FSideScrollPlayerData PlayerData = FSideScrollPlayerData();
};
