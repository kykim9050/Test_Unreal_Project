// Fill out your copyright notice in the Description page of Project Settings.


#include "Global/GlobalHUD.h"
#include "Global/Debug/DebugWidget.h"
#include "Global/KKYGameInstance.h"
#include "Global/GlobalFunction.h"

#if WITH_EDITOR
void AGlobalHUD::AddDebugString(FString _Text)
{
	if (nullptr == DebugWidget)
	{
		return;
	}

	DebugWidget->AddDebugString(_Text);
}
#endif

void AGlobalHUD::BeginPlay()
{
	Super::BeginPlay();

#if WITH_EDITOR
	UKKYGameInstance* Inst = UGlobalFunction::GetKKYGameInstance(GetWorld());
	TSubclassOf<UUserWidget> Item(Inst->GetGlobalObjectClass("Debug"));
	DebugWidgetClass = Item;

	if (nullptr != DebugWidgetClass)
	{
		DebugWidget = CreateWidget<UDebugWidget>(GetWorld(), DebugWidgetClass);
		DebugWidget->AddToViewport();
	}

#endif

}