// Fill out your copyright notice in the Description page of Project Settings.


#include "SideScroll/SideScrollCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/PlayerInput.h"
#include "Global/KKYGameInstance.h"
#include "Components/InputComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
ASideScrollCharacter::ASideScrollCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SSSpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("SSCamera"));
	Camera->SetupAttachment(SpringArm);

	Camera->ProjectionMode = ECameraProjectionMode::Orthographic;
	Camera->SetOrthoWidth(1280.0f * 2);

	FQuat Quat = FQuat();
	UKismetMathLibrary::Quat_SetFromEuler(Quat, FVector(0.0f, 0.0f, -90.0f));
	SpringArm->SetRelativeRotation(Quat);

}

// Called when the game starts or when spawned
void ASideScrollCharacter::BeginPlay()
{
	Super::BeginPlay();

	// GameInstance & DataTable
	UKKYGameInstance* Inst = GetWorld()->GetGameInstanceChecked<UKKYGameInstance>();

	if (nullptr == Inst)
	{
		UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (nullptr == Inst)"), __FUNCTION__, __LINE__);
	}

	GainCollisionPtr = FindComponentByTag<UCapsuleComponent>(TEXT("Gain"));

	if (nullptr == GainCollisionPtr)
	{
		UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (nullptr == GainCollisionPtr)"), __FUNCTION__, __LINE__);
	}

	PlayerData = Inst->GetSideScrollData()->PlayerData;
	PlayerSpeed = PlayerData.PlayerSpeed;
}

// Called every frame
void ASideScrollCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalOffset(FVector(1.0f, 0.0f, 0.0f) * PlayerSpeed * DeltaTime);

}

void ASideScrollCharacter::PlayerJump()
{
	Jump();
}

void ASideScrollCharacter::BackMove(float _DeltaTime)
{
	GetMesh()->AddRelativeLocation(FVector(-1.0f, 0.0f, 0.0f) * _DeltaTime * PlayerSpeed);

	FVector MeshPos = GetMesh()->GetRelativeLocation();

	//if (PlayerData.BackMax >= MeshPos.X)
	//{
	//	MeshPos.X = PlayerData.BackMax;
	//}

	MeshPos.Z += GainCollisionPtr->GetScaledCapsuleHalfHeight();
	GainCollisionPtr->SetRelativeLocation(MeshPos);
}

void ASideScrollCharacter::FrontMove(float _DeltaTime)
{
	GetMesh()->AddRelativeLocation(FVector(1.0f, 0.0f, 0.0f) * _DeltaTime * PlayerSpeed);

	FVector MeshPos = GetMesh()->GetRelativeLocation();
	
	//if (PlayerData.FrontMax <= MeshPos.X)
	//{
	//	MeshPos.X = PlayerData.BackMax;
	//}

	MeshPos.Z += GainCollisionPtr->GetScaledCapsuleHalfHeight();
	GainCollisionPtr->SetRelativeLocation(MeshPos);
}