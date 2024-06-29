// Fill out your copyright notice in the Description page of Project Settings.


#include "Global/KKYGameInstance.h"
#include "Global/DataTable/SideScrollGameSettingRow.h"
#include "Global/DataAssets/InputDatas.h"

UKKYGameInstance::UKKYGameInstance()
{

}

const struct FSideScrollGameSettingRow* UKKYGameInstance::GetSideScrollData()
{
	if (nullptr == SideScrollData)
	{
		UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (nullptr == SideScrollData)"), __FUNCTION__, __LINE__);
	}

	FSideScrollGameSettingRow* Data = SideScrollData->FindRow<FSideScrollGameSettingRow>(TEXT("PlayerData"), nullptr);

	if (nullptr == Data)
	{
		UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (nullptr == Data)"), __FUNCTION__, __LINE__);
	}

	return Data;
}

UInputDatas* UKKYGameInstance::GetInputDataAsset()
{
	if (nullptr == InputDataAsset)
	{
		UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (nullptr == InputDatas)"), __FUNCTION__, __LINE__);
	}

	UInputDatas* Data = Cast<UInputDatas, UDataAsset>(InputDataAsset);

	if (nullptr == Data)
	{
		UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (nullptr == Data)"), __FUNCTION__, __LINE__);
	}

	return Data;
}