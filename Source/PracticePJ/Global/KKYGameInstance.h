// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "KKYGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICEPJ_API UKKYGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowprivateAccess = "true"))
	UDataTable* ActorDataTable = nullptr;
};
