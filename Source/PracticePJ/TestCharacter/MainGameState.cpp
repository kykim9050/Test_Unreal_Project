// Fill out your copyright notice in the Description page of Project Settings.


#include "TestCharacter/MainGameState.h"


void AMainGameState::AddItemNum()
{
	if (MaxItemNum < ItemNum)
	{
		return;
	}

	if (MaxItemNum == ItemNum)
	{
		CurStage = EGameStage::NextStage;
		return;
	}

	++ItemNum;
}