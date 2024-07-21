// Fill out your copyright notice in the Description page of Project Settings.


#include "TestCharacter/TCPlayCharacter.h"

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
	
}

// Called every frame
void ATCPlayCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATCPlayCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATCPlayCharacter::ChangeAnimation_Implementation(uint8 _Type)
{
	int a = 0;
}