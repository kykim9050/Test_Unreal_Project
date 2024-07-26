// Fill out your copyright notice in the Description page of Project Settings.


#include "TestCharacter/TCGameMode.h"
#include "Global/GlobalFunction.h"
#include "TestCharacter/MainGameState.h"
#include "Global/KKYGameInstance.h"

void ATCGameMode::StartPlay()
{
	Super::StartPlay();

	MainGameState = UGlobalFunction::GetMainGameState(GetWorld());
	Inst = UGlobalFunction::GetKKYGameInstance(GetWorld());
}

void ATCGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	EGameStage StageValue = MainGameState->GetCurStage();

	if (CurStage != StageValue)
	{
		CurStage = StageValue;
		
		// 메인 게임 인스턴스에 EGameStage 값 변경 (해당 값은 리플리케이트 되어있어야 함)
		Inst->SetMainGameStage(CurStage);
		Inst->TestValue = 100;
	}
}