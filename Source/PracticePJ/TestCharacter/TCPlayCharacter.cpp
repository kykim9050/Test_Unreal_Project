// Fill out your copyright notice in the Description page of Project Settings.


#include "TestCharacter/TCPlayCharacter.h"
#include "Global/Animation/GlobalAnimInstance.h"

// Sets default values
ATCPlayCharacter::ATCPlayCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATCPlayCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	AnimInst = Cast<UGlobalAnimInstance>(GetMesh()->GetAnimInstance());
}

// Called every frame
void ATCPlayCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//if (nullptr != AnimInst)
	//{
	//	AnimInst->ChangeAnimation(AniValue);
	//}
}

// Called to bind functionality to input
void ATCPlayCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATCPlayCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ATCPlayCharacter, AniValue);
}

void ATCPlayCharacter::ChangeAnimation_Implementation(uint8 _Type)
{
	AniValue = _Type;
}