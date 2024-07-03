// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DebugWidget.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICEPJ_API UDebugWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void AddDebugString(FString _Text);

	void NativeConstruct() override;

	void NativeTick(const FGeometry& _MyGeometry, float _InDeltaTime) override;

protected:

private:
	FString AllDebugText = TEXT("");
	class UTextBlock* DebugText = nullptr;
};
