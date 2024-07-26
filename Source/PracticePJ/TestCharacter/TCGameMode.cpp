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
		
		// ���� ���� �ν��Ͻ��� EGameStage �� ���� (�ش� ���� ���ø�����Ʈ �Ǿ��־�� ��)
		Inst->SetMainGameStage(CurStage);
		Inst->TestValue = 100;
	}
}