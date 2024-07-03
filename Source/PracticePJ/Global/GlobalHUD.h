// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GlobalHUD.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICEPJ_API AGlobalHUD : public AHUD
{
	GENERATED_BODY()

public:
#if WITH_EDITOR
	UFUNCTION(BlueprintCallable)
	void AddDebugString(FString _Text);
#endif

protected:
	void BeginPlay() override;

private:
	
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> DebugWidgetClass;

	UPROPERTY(EditAnywhere)
	class UDebugWidget* DebugWidget = nullptr;

#endif

};
