// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "KKYEnum.h"
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
	class UStaticMesh* GetStaticMeshData(FName _Name);
	TSubclassOf<UObject> GetGlobalObjectClass(FName _Name);
	struct FTCCharacterDataRow* GetTCCharacterData(FName _Name);

	EGameStage GetMainGameStage() const;

	UFUNCTION(Reliable, Server)
	void SetMainGameStage(EGameStage _StageValue);
	void SetMainGameStage_Implementation(EGameStage _StageValue);


protected:
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowprivateAccess = "true"))
	UDataTable* ActorDataTable = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowprivateAccess = "true"))
	UDataTable* SideScrollData = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowprivateAccess = "true"))
	UDataAsset* InputDataAsset = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowprivateAccess = "true"))
	UDataTable* StaticMeshData = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UDataTable* GlobalObjectTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UDataTable* TCCharacterData = nullptr;

	UPROPERTY(Replicated)
	EGameStage MainGameStage = EGameStage::Start;


	UKKYGameInstance();
};
