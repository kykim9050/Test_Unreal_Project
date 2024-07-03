// Fill out your copyright notice in the Description page of Project Settings.


#include "Global/Debug/DebugWidget.h"
#include "Components/TextBlock.h"


void UDebugWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	DebugText = Cast<UTextBlock>(GetWidgetFromName(TEXT("DebugText")));
	
	if (nullptr == DebugText)
	{
		UE_LOG(LogType, Fatal, TEXT("%S(%u)> 	if (nullptr == DebugText)"), __FUNCTION__, __LINE__);
		return;
	}
}

void UDebugWidget::NativeTick(const FGeometry& _MyGeometry, float _InDeltaTime)
{
	Super::NativeTick(_MyGeometry, _InDeltaTime);

	DebugText->SetText(FText::FromString(AllDebugText));
	AllDebugText = TEXT("");
}

void UDebugWidget::AddDebugString(FString _Text)
{
	AllDebugText += _Text + TEXT("\n");
}