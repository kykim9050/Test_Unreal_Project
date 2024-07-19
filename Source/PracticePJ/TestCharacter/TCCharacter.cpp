// Fill out your copyright notice in the Description page of Project Settings.


#include "TestCharacter/TCCharacter.h"

// Sets default values
ATCCharacter::ATCCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATCCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATCCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATCCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

