// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "KKYGameInstance.h"
#include "GlobalFunction.generated.h"

/**
 * 
 */
class AMainGameState;
UCLASS()
class PRACTICEPJ_API UGlobalFunction : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
#if WITH_EDITOR
	UFUNCTION(BlueprintCallable)
	static void DebugTextPrint(UWorld* _World, FString _Text);
#endif

	static UKKYGameInstance* GetKKYGameInstance(const UWorld* WorldContextObject);

	static AMainGameState* GetMainGameState(const UWorld* WorldContextObject);

protected:

private:


};
