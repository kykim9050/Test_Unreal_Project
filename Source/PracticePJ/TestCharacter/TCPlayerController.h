// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Global/KKYEnum.h"
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
	void ChangeAnimation(ETCPlayerAnimation _Animation);

	UFUNCTION(BlueprintCallable)
	void MoveFront();

	UFUNCTION(BlueprintCallable)
	void MoveBack();

	UFUNCTION(BlueprintCallable)
	void MoveEnd();

	UFUNCTION(BlueprintCallable)
	void MoveRight();

	UFUNCTION(BlueprintCallable)
	void MoveLeft();

	UFUNCTION(BlueprintCallable)
	void Rotating(const FInputActionValue& Value);

	UFUNCTION(BlueprintCallable)
	void SetupInputComponent() override;

	UPROPERTY()
	UInputActionDatas* InputData = nullptr;

protected:


private:


};
