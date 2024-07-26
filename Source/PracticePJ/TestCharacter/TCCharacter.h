// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TestCharacter/TCPlayCharacter.h"
#include "Global/KKYEnum.h"
#include "TCCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UAnimMontage;
class UKKYGameInstance;
UCLASS()
class PRACTICEPJ_API ATCCharacter : public ATCPlayCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATCCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	void ChangeAnimation(ETCPlayerAnimation _Animation);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TMap<ETCPlayerAnimation, UAnimMontage*> AnimMontages = TMap<ETCPlayerAnimation, UAnimMontage*>();

	UPROPERTY()
	UKKYGameInstance* Inst = nullptr;
};
