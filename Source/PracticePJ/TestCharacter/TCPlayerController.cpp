// Fill out your copyright notice in the Description page of Project Settings.

#include "TestCharacter/TCPlayerController.h"
#include "EnhancedInputComponent.h"

ATCPlayerController::ATCPlayerController()
{
	//FString RefPathString = "";
}


void ATCPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);

}