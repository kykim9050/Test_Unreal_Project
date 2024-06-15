// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimNotifies/AnimNotify_PlayMontageNotify.h"
#include "AnimNotify_End.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICEPJ_API UAnimNotify_End : public UAnimNotify_PlayMontageNotify
{
	GENERATED_BODY()
	
public:
	UAnimNotify_End();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	FString NextAnimationName = "None";

protected:

private:
	void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

};
