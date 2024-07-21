// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InputActionDatas.generated.h"

/**
 * 
 */
class UInputMappingContext;
class UInputAction;
UCLASS()
class UInputActionDatas : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInputMappingContext* InputMapping = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UInputAction*> Actions = TArray<UInputAction*>();

protected:

private:

};
