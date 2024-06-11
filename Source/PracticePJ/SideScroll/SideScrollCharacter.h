// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Global/DataTable/SideScrollGameSettingRow.h"
#include "SideScrollCharacter.generated.h"

UCLASS()
class PRACTICEPJ_API ASideScrollCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASideScrollCharacter();

	UFUNCTION(BlueprintCallable)
	void BackMove(float _DeltaTime);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(Category = "Contents", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArm = nullptr;

	UPROPERTY(Category = "Contents", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* Camera = nullptr;

	const FSideScrollGameSettingRow* SideScrollData = nullptr;

	float PlayerSpeed = 0.0f;

	void PlayerJump();


};
