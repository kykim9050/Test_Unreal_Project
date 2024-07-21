// Fill out your copyright notice in the Description page of Project Settings.

#include "TestCharacter/TCPlayerController.h"
#include "EnhancedInputComponent.h"
#include "Global/DataAssets/InputActionDatas.h"

ATCPlayerController::ATCPlayerController()
{
	FString RefPathString = TEXT("InputActionDatas'/Game/ContentsRes/TestCharacter/Datas/DA_InputActionDatas.DA_InputActionDatas'");

	ConstructorHelpers::FObjectFinder<UInputActionDatas> ResPath(*RefPathString);

	if (false == ResPath.Succeeded())
	{
		return;
	}

	InputData = ResPath.Object;
}


void ATCPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);

}