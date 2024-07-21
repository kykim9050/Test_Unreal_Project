// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Net/UnrealNetwork.h"
#include "TCPlayCharacter.generated.h"


class UGlobalAnimInstance;
UCLASS()
class PRACTICEPJ_API ATCPlayCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATCPlayCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	template<typename EnumType>
	void ChangeAnimation(EnumType _Type)
	{
		ChangeAnimation(static_cast<uint8>(_Type));
	}

	UFUNCTION(Reliable, Server)
	void ChangeAnimation(uint8 _Type);
	void ChangeAnimation_Implementation(uint8 _Type);

	FORCEINLINE UGlobalAnimInstance* GetGlobalAnimInstance() const
	{
		return AnimInst;
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:	
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	uint8 AniValue = -1;

	// Replicated 빼면 어떻게 되려나? 해보쟈
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UGlobalAnimInstance* AnimInst = nullptr;
};
