// Fill out your copyright notice in the Description page of Project Settings.


#include "TestCharacter/TCGameMode.h"
#include "Global/GlobalFunction.h"
#include "TestCharacter/MainGameState.h"

void ATCGameMode::StartPlay()
{
	Super::StartPlay();

	MainGameState = UGlobalFunction::GetMainGameState(GetWorld());
}

void ATCGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (true == MainGameState->GetIsStageChange())
	{
		int a = 0;
		MainGameState->SetIsStageChange(false);
	}
}