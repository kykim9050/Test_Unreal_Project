// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EditFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICEPJEDITOR_API UEditFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Game")
	static void DataTableTest(UDataTable* _DataTable);

protected:
	UEditFunctionLibrary();

private:

};
