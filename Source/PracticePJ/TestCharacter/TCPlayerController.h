// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TCPlayerController.generated.h"

/**
 * 
 */
class UInputActionDatas;
UCLASS()
class PRACTICEPJ_API ATCPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATCPlayerController();

	void SetupInputComponent() override;

	UPROPERTY()
	UInputActionDatas* InputData = nullptr;

protected:


private:


};
