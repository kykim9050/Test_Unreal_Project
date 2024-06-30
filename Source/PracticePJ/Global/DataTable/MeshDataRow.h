// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MeshDataRow.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FMeshDataRow : public FTableRowBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources")
	class UStaticMesh* Mesh = nullptr;

};
