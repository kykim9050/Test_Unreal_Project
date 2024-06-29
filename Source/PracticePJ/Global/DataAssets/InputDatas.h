// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InputDatas.generated.h"

/**
 * 
 */
UCLASS()
class UInputDatas : public UDataAsset
{
	GENERATED_BODY()
	
public:
	class UInputMappingContext* GetInputMapping();

	TMap<FString, class UInputAction*> GetActions();

protected:

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* InputMapping = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TMap<FString, class UInputAction*> Actions = TMap<FString, class UInputAction*>();

};
