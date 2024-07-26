// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "Global/KKYEnum.h"
#include "MainGameState.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICEPJ_API AMainGameState : public AGameState
{
	GENERATED_BODY()
public:
	UFUNCTION()
	FORCEINLINE int GetTestValue() const
	{
		return TestValue;
	}

	UFUNCTION(BlueprintCallable)
	FORCEINLINE void AddTestValue()
	{
		++TestValue;
	}

	UFUNCTION(BlueprintCallable)
	FORCEINLINE bool GetIsStageChange() const
	{
		return IsStageChange;
	}

	UFUNCTION(BlueprintCallable)
	FORCEINLINE void SetIsStageChange(bool _Value)
	{
		IsStageChange = _Value;
	}

	UFUNCTION(BlueprintCallable)
	FORCEINLINE EGameStage GetCurStage() const
	{
		return CurStage;
	}

	UFUNCTION(BlueprintCallable)
	FORCEINLINE void SetCurStage(EGameStage _GameStage)
	{
		CurStage = _GameStage;
	}

	UFUNCTION(BlueprintCallable)
	void AddItemNum();

protected:

private:
	UPROPERTY()
	int TestValue = 0;

	UPROPERTY()
	int ItemNum = 0;

	UPROPERTY()
	int MaxItemNum = 2;

	UPROPERTY()
	EGameStage CurStage = EGameStage::Start;

	UPROPERTY()
	bool IsStageChange = false;
};
