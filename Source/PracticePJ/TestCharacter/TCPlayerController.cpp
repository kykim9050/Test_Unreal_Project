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

void ATCPlayerController::MoveFront()
{
	//ChangeAnimation(ETCPlayerAnimation::Rifle_WalkForward);

	FVector Forward = GetPawn()->GetActorForwardVector();
	GetPawn()->AddMovementInput(Forward);
}

void ATCPlayerController::MoveBack()
{
	FVector Backward = GetPawn()->GetActorForwardVector() * (-1);
	GetPawn()->AddMovementInput(Backward);
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
		EnhancedInputComponent->BindAction(InputData->Actions[2], ETriggerEvent::Triggered, this, &ATCPlayerController::MoveBack);
		EnhancedInputComponent->BindAction(InputData->Actions[1], ETriggerEvent::Triggered, this, &ATCPlayerController::Rotating);
	}
}
