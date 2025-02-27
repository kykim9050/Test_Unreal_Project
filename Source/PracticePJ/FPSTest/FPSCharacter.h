// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPSCharacter.generated.h"

UCLASS()
class PRACTICEPJ_API AFPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacter();

	UFUNCTION(BlueprintCallable)
	void BackMove();

	UFUNCTION(BlueprintCallable)
	void FrontMove();

	UFUNCTION(BlueprintCallable)
	void RightMove();

	UFUNCTION(BlueprintCallable)
	void LeftMove();

	UFUNCTION(BlueprintCallable)
	void FPSJump();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	inline class UCameraComponent* GetCameraComponent() const
	{
		return Camera;
	}

private:
	UPROPERTY(Category = "Contents", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArm = nullptr;

	UPROPERTY(Category = "Contents", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* Camera = nullptr;

};
