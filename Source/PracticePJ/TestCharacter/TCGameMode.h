// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Global/KKYEnum.h"
#include "TCGameMode.generated.h"

/**
 * 
 */
class AMainGameState;
class UKKYGameInstance;
UCLASS()
class PRACTICEPJ_API ATCGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:

protected:
	void StartPlay() override;

	void Tick(float DeltaSeconds) override;

private:
	UPROPERTY()
	AMainGameState* MainGameState = nullptr;

	UPROPERTY()
	UKKYGameInstance* Inst = nullptr;

	UPROPERTY()
	EGameStage CurStage = EGameStage::Start;
};
