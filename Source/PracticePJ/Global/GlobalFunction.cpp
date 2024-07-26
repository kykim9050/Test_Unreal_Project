// Fill out your copyright notice in the Description page of Project Settings.


#include "Global/GlobalFunction.h"
#include "Kismet/GameplayStatics.h"
#include "Global/GlobalHUD.h"
#include "TestCharacter/MainGameState.h"

UKKYGameInstance* UGlobalFunction::GetKKYGameInstance(const UWorld* WorldContextObject)
{
	UKKYGameInstance* Inst = WorldContextObject->GetGameInstance<UKKYGameInstance>();

	if (false == Inst->IsValidLowLevel())
	{
		UE_LOG(LogType, Fatal, TEXT("%S(%u)> if (false == Inst->IsValidLowLevel())"), __FUNCTION__, __LINE__);
		return nullptr;
	}

	return Inst;
}

AMainGameState* UGlobalFunction::GetMainGameState(const UWorld* WorldContextObject)
{
	AMainGameState* MainGameState = WorldContextObject->GetGameState<AMainGameState>();

	if (false == MainGameState->IsValidLowLevel())
	{
		UE_LOG(LogType, Fatal, TEXT("%S(%u)> if (false == MainGameState->IsValidLowLevel())"), __FUNCTION__, __LINE__);
		return nullptr;
	}

	return MainGameState;
}

#if WITH_EDITOR
void UGlobalFunction::DebugTextPrint(UWorld* _World, FString _Text)
{
	APlayerController* Con = UGameplayStatics::GetPlayerController(_World, 0);
	AGlobalHUD* GlobalHUD = Cast<AGlobalHUD>(Con->GetHUD());
	
	if (nullptr == GlobalHUD)
	{
		return;
	}

	GlobalHUD->AddDebugString(_Text);
}
#endif