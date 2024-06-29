// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "KKYGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICEPJ_API UKKYGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:

	const struct FSideScrollGameSettingRow* GetSideScrollData();
	class UInputDatas* GetInputDataAsset();

protected:


private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowprivateAccess = "true"))
	UDataTable* ActorDataTable = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowprivateAccess = "true"))
	UDataTable* SideScrollData = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowprivateAccess = "true"))
	UDataAsset* InputDataAsset = nullptr;

	UKKYGameInstance();
};
