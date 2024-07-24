// Fill out your copyright notice in the Description page of Project Settings.

#include "TestCharacter/TCPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Global/DataAssets/InputActionDatas.h"
#include "Global/KKYEnum.h"
#include "TCCharacter.h"

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

void ATCPlayerController::MoveFront()
{
	ChangeAnimation(ETCPlayerAnimation::Rifle_WalkForward);

	FVector Forward = GetPawn()->GetActorForwardVector() * 0.5f;
	GetPawn()->AddMovementInput(Forward);
}

void ATCPlayerController::MoveBack()
{
	ChangeAnimation(ETCPlayerAnimation::Rifle_WalkBackward);

	FVector Backward = GetPawn()->GetActorForwardVector() * (-0.3f);
	GetPawn()->AddMovementInput(Backward);
}

void ATCPlayerController::MoveRight()
{
	ChangeAnimation(ETCPlayerAnimation::Rifle_WalkRight);

	FVector Rightward = GetPawn()->GetActorRightVector() * (0.5f);
	GetPawn()->AddMovementInput(Rightward);
}

//void ATCPlayerController::MoveRightFront()
//{
//	ChangeAnimation(ETCPlayerAnimation::Rifle_WalkForwardRight);
//
//	FVector Forward = GetPawn()->GetActorForwardVector() * (0.5f);
//	FVector Rightward = GetPawn()->GetActorRightVector() * (0.5f);
//	FVector ResultVector = Forward + Rightward;
//
//	GetPawn()->AddMovementInput(ResultVector);
//}

void ATCPlayerController::MoveLeft()
{
	ChangeAnimation(ETCPlayerAnimation::Rifle_WalkLeft);

	FVector Leftward = GetPawn()->GetActorRightVector() * (-0.5f);
	GetPawn()->AddMovementInput(Leftward);
}

void ATCPlayerController::MoveEnd()
{
	ChangeAnimation(ETCPlayerAnimation::Rifle_Idle);
}

void ATCPlayerController::Rotating(const FInputActionValue& Value)
{
	FVector2D MouseXY = Value.Get<FVector2D>();
	AddYawInput(MouseXY.X);
}

void ATCPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//FInputModeGameOnly InputMode;
	//SetInputMode(InputMode);

	UEnhancedInputLocalPlayerSubsystem* InputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);

	InputSystem->ClearAllMappings();
	InputSystem->AddMappingContext(InputData->InputMapping, 0);

	if (nullptr != InputData->InputMapping)
	{
		EnhancedInputComponent->BindAction(InputData->Actions[0], ETriggerEvent::Triggered, this, &ATCPlayerController::MoveFront);
		EnhancedInputComponent->BindAction(InputData->Actions[0], ETriggerEvent::Completed, this, &ATCPlayerController::MoveEnd);
		EnhancedInputComponent->BindAction(InputData->Actions[2], ETriggerEvent::Triggered, this, &ATCPlayerController::MoveBack);
		EnhancedInputComponent->BindAction(InputData->Actions[2], ETriggerEvent::Completed, this, &ATCPlayerController::MoveEnd);
		EnhancedInputComponent->BindAction(InputData->Actions[1], ETriggerEvent::Triggered, this, &ATCPlayerController::Rotating);
		EnhancedInputComponent->BindAction(InputData->Actions[3], ETriggerEvent::Triggered, this, &ATCPlayerController::MoveRight);
		EnhancedInputComponent->BindAction(InputData->Actions[3], ETriggerEvent::Completed, this, &ATCPlayerController::MoveEnd);
		EnhancedInputComponent->BindAction(InputData->Actions[4], ETriggerEvent::Triggered, this, &ATCPlayerController::MoveLeft);
		EnhancedInputComponent->BindAction(InputData->Actions[4], ETriggerEvent::Completed, this, &ATCPlayerController::MoveEnd);
		//EnhancedInputComponent->BindAction(InputData->Actions[5], ETriggerEvent::Triggered, this, &ATCPlayerController::MoveRightFront);
		//EnhancedInputComponent->BindAction(InputData->Actions[5], ETriggerEvent::Completed, this, &ATCPlayerController::MoveEnd);
	}
}

void ATCPlayerController::ChangeAnimation(ETCPlayerAnimation _Animation)
{
	ATCCharacter* Ch = GetPawn<ATCCharacter>();

	if (nullptr == Ch)
	{
		return;
	}

	Ch->ChangeAnimation(_Animation);
}