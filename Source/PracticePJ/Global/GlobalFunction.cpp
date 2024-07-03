// Fill out your copyright notice in the Description page of Project Settings.


#include "Global/GlobalFunction.h"
#include "Kismet/GameplayStatics.h"
#include "Global/GlobalHUD.h"

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