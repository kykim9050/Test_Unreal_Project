// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedActionKeyMapping.h"
#include "SideScrollPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICEPJ_API ASideScrollPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	void SetupInputComponent() override;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* InputMapping;
	
};
