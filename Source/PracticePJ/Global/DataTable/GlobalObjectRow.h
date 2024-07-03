// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "GlobalObjectRow.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FGlobalObjectRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	FGlobalObjectRow();
	~FGlobalObjectRow();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources")
	TSubclassOf<UObject> Object;
};
