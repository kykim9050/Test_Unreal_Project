// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Global/Animation/GlobalAnimInstance.h"
#include "GlobalCharacter.generated.h"

UCLASS()
class PRACTICEPJ_API AGlobalCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGlobalCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	inline UGlobalAnimInstance* GetAnimationContext() const
	{
		return AnimationContext;
	}

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	//UPROPERTY(Category = "Contents", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UGlobalAnimInstance* AnimationContext = nullptr;
};
