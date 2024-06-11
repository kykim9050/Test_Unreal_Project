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

	UFUNCTION(BlueprintCallable)
	void FrontMove(float _DeltaTime);

	UFUNCTION(BlueprintCallable)
	void ViewCharacterJump();

	UFUNCTION(BlueprintCallable)
	void PlayerOverlapBegin(UCapsuleComponent* Capsule, AActor* _CollisionActor);

	UFUNCTION(BlueprintCallable)
	void PlayerOverlapEnd(AActor* _CollisionActor);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void ViewJump(float _DeltaTime);
	void ViewGravity(float _DeltaTime);

	void SetViewChracterPos(FVector _Pos);
	void AddViewChracterPos(FVector _Dir);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(Category = "Contents", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArm = nullptr;

	UPROPERTY(Category = "Contents", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* Camera = nullptr;

	UPROPERTY(Category = "Contents", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UCapsuleComponent* GainCollisionPtr = nullptr;

	FSideScrollPlayerData PlayerData;

	float PlayerSpeed = 0.0f;

	void PlayerJump();

	float GravityPower;

	float JumpPower;
	float CurJumpPower;

	bool IsGroundValue = true;
	bool IsJumpValue = false;


};
