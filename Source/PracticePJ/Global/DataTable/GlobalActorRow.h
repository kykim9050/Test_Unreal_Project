// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "GlobalActorRow.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FGlobalActorRow : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(Category = "Resources", EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> Actor = nullptr;

	UPROPERTY(Category = "Resources", EditAnywhere, BlueprintReadWrite)
	int HP;

	UPROPERTY(Category = "Resources", EditAnywhere, BlueprintReadWrite)
	float Speed;
};
