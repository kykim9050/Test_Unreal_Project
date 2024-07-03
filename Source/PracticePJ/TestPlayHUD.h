// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Global/GlobalHUD.h"
#include "TestPlayHUD.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICEPJ_API ATestPlayHUD : public AGlobalHUD
{
	GENERATED_BODY()
	
protected:
	void BeginPlay() override;

private:

};
