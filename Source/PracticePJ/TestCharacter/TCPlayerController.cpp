// Fill out your copyright notice in the Description page of Project Settings.

#include "TestCharacter/TCPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
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


//void ATCPlayerController::MoveFront()
//{
//	int a = 0;
//}

void ATCPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);

	UEnhancedInputLocalPlayerSubsystem* InputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);

	int a = 0;
}
