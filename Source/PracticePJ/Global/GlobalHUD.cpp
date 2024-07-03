// Fill out your copyright notice in the Description page of Project Settings.


#include "Global/GlobalHUD.h"
#include "Global/Debug/DebugWidget.h"
#include "Global/KKYGameInstance.h"

void AGlobalHUD::AddDebugString(FString _Text)
{
	if (nullptr == DebugWidget)
	{
		return;
	}

	DebugWidget->AddDebugString(_Text);
}

void AGlobalHUD::BeginPlay()
{
	Super::BeginPlay();

#if WITH_EDITOR

	

#endif

}