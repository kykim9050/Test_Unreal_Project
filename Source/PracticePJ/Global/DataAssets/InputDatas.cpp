// Fill out your copyright notice in the Description page of Project Settings.


#include "Global/DataAssets/InputDatas.h"



UInputMappingContext* UInputDatas::GetInputMapping()
{
	if (nullptr == InputMapping)
	{
		UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (nullptr == InputMapping)"), __FUNCTION__, __LINE__);
		return nullptr;
	}

	return InputMapping;
}

TMap<FString, class UInputAction*> UInputDatas::GetActions()
{
	if (true == Actions.IsEmpty())
	{
		UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (true == Actions.IsEmpty())"), __FUNCTION__, __LINE__);
	}

	return Actions;
}
