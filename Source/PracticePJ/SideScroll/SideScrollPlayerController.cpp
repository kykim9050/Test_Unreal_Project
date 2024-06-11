// Fill out your copyright notice in the Description page of Project Settings.


#include "SideScroll/SideScrollPlayerController.h"

void ASideScrollPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();


	UEnhancedInputLocalPlayerSubsystem* InputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);

	InputSystem->ClearAllMappings();
	InputSystem->AddMappingContext(InputMapping, 0);
}