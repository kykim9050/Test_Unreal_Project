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

public:
	UFUNCTION(BlueprintCallable)
	void MoveFront();

	UFUNCTION(BlueprintCallable)
	void MoveBack();

	UFUNCTION(BlueprintCallable)
	void Rotating(const FInputActionValue& Value);

	UFUNCTION(BlueprintCallable)
	void SetupInputComponent() override;

	UPROPERTY()
	UInputActionDatas* InputData = nullptr;

protected:


private:


};
