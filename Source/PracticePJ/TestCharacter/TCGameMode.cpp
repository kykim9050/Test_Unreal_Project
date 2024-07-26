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

	EGameStage StageValue = MainGameState->GetCurStage();

	if (CurStage != StageValue)
	{
		CurStage = StageValue;
		// ���� ���� �ν��Ͻ��� EGameStage �� ���� (�ش� ���� ���ø�����Ʈ �Ǿ��־�� ��)
	}
}