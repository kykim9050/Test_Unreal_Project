// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSTest/FPSCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"



// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());

	SpringArm->TargetArmLength = 500.0f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	FQuat Quat = FQuat();
	UKismetMathLibrary::Quat_SetFromEuler(Quat, FVector(0.0f, -35.0f, 0.0f));
	SpringArm->SetRelativeRotation(Quat);
	SpringArm->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));
}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AFPSCharacter::BackMove()
{
	AddMovementInput(FVector(-1.0f, 0.0f, 0.0f), 1.0f);
}

void AFPSCharacter::FrontMove()
{
	AddMovementInput(FVector(1.0f, 0.0f, 0.0f), 1.0f);
}

void AFPSCharacter::RightMove()
{
	AddMovementInput(FVector(0.0f, 1.0f, 0.0f), 1.0f);
}

void AFPSCharacter::LeftMove()
{
	AddMovementInput(FVector(0.0f, -1.0f, 0.0f), 1.0f);
}

void AFPSCharacter::FPSJump()
{
	AddMovementInput(FVector(0.0f, 0.0f, 1.0f), 1.0f);
}