// Fill out your copyright notice in the Description page of Project Settings.


#include "Global/KKYGameInstance.h"
#include "Global/DataTable/SideScrollGameSettingRow.h"
#include "Global/DataAssets/InputDatas.h"
#include "Global/DataTable/MeshDataRow.h"
#include "Global/DataTable/GlobalObjectRow.h"
#include "Global/DataTable/TCCharacterDataRow.h"


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

UStaticMesh* UKKYGameInstance::GetStaticMeshData(FName _Name)
{
	if (nullptr == StaticMeshData)
	{
		UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (nullptr == StaticMeshData)"), __FUNCTION__, __LINE__);
	}

	FMeshDataRow* Data = StaticMeshData->FindRow<FMeshDataRow>(_Name, nullptr);

	if (nullptr == Data)
	{
		UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (nullptr == Data)"), __FUNCTION__, __LINE__, *_Name.ToString());
	}

	UStaticMesh* StaticMesh = Data->Mesh;

	if (nullptr == StaticMesh)
	{
		UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (nullptr == StaticMesh)"), __FUNCTION__, __LINE__);
	}

	return StaticMesh;
}

TSubclassOf<UObject> UKKYGameInstance::GetGlobalObjectClass(FName _Name)
{
	if (nullptr == GlobalObjectTable)
	{
		UE_LOG(LogType, Fatal, TEXT("%S(%u)> if (nullptr == MonsterDataTable)"), __FUNCTION__, __LINE__);
	}

	FGlobalObjectRow* Data = GlobalObjectTable->FindRow<FGlobalObjectRow>(_Name, nullptr);

	if (nullptr == Data)
	{
		UE_LOG(LogType, Error, TEXT("%S(%u)> %s Name Data Is Nullptr"), __FUNCTION__, __LINE__, *_Name.ToString());
		return nullptr;
	}

	return Data->Object;
}

const FTCCharacterDataRow* UKKYGameInstance::GetTCCharacterData(FName _Name)
{
	if (nullptr == TCCharacterData)
	{
		UE_LOG(LogType, Fatal, TEXT("%S(%u)> if (nullptr == TCCharacterData)"), __FUNCTION__, __LINE__);
	}

	FTCCharacterDataRow* Data = TCCharacterData->FindRow<FTCCharacterDataRow>(_Name, nullptr);

	if (nullptr == Data)
	{
		UE_LOG(LogType, Error, TEXT("%S(%u)> %s Name Data Is Nullptr"), __FUNCTION__, __LINE__, *_Name.ToString());
		return nullptr;
	}

	return Data;
}