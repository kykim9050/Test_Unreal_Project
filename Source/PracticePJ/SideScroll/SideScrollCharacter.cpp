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
#include "Global/Animation/GlobalAnimInstance.h"


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

	
	AnimInst = Cast<UGlobalAnimInstance>(GetMesh()->GetAnimInstance());
	AnimInst->ChangeAnimation(TEXT("Run"));
}

// Called every frame
void ASideScrollCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalOffset(FVector(1.0f, 0.0f, 0.0f) * PlayerSpeed * DeltaTime);

	if (true == IsJumpValue)
	{
		ViewJump(DeltaTime);
	}

	if (false == IsGroundValue && false == IsJumpValue)
	{
		ViewGravity(DeltaTime);
	}
}

void ASideScrollCharacter::PlayerJump()
{
	AnimInst->ChangeAnimation(TEXT("Jump"));

	Jump();
}

void ASideScrollCharacter::BackMove(float _DeltaTime)
{
	GetMesh()->AddRelativeLocation(FVector(-1.0f, 0.0f, 0.0f) * _DeltaTime * PlayerSpeed);

	FVector MeshPos = GetMesh()->GetRelativeLocation();

	if (PlayerData.BackMax >= MeshPos.X)
	{
		MeshPos.X = PlayerData.BackMax;
	}


	GetMesh()->SetRelativeLocation(MeshPos);
	MeshPos.Z += GainCollisionPtr->GetScaledCapsuleHalfHeight();
	GainCollisionPtr->SetRelativeLocation(MeshPos);
}

void ASideScrollCharacter::FrontMove(float _DeltaTime)
{
	GetMesh()->AddRelativeLocation(FVector(1.0f, 0.0f, 0.0f) * _DeltaTime * PlayerSpeed);

	FVector MeshPos = GetMesh()->GetRelativeLocation();
	
	if (PlayerData.FrontMax <= MeshPos.X)
	{
		MeshPos.X = PlayerData.FrontMax;
	}

	GetMesh()->SetRelativeLocation(MeshPos);
	MeshPos.Z += GainCollisionPtr->GetScaledCapsuleHalfHeight();
	GainCollisionPtr->SetRelativeLocation(MeshPos);
}



void ASideScrollCharacter::PlayerOverlapBegin(UCapsuleComponent* Capsule, AActor* _CollisionActor)
{
	if (true == _CollisionActor->ActorHasTag(TEXT("Coin")))
	{
		_CollisionActor->Destroy();
	}

	if (true == _CollisionActor->ActorHasTag(TEXT("Ground")))
	{
		// 매쉬 컴포넌트를 찾는방법
		UStaticMeshComponent* Ptr = _CollisionActor->GetComponentByClass<UStaticMeshComponent>();

		if (nullptr == Ptr)
		{
			UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (nullptr == Cap)"), __FUNCTION__, __LINE__);
		}

		FBoxSphereBounds Bound = Ptr->Bounds;
		FVector Pos = _CollisionActor->GetActorLocation();

		JumpPower = 0.0f;
		GravityPower = 0.0f;
		FVector MeshPos = GetMesh()->GetRelativeLocation();
		MeshPos.Z = Pos.Z + Bound.BoxExtent.Z;
		SetViewChracterPos(MeshPos);
		IsGroundValue = true;
		IsJumpValue = false;
	}
}

void ASideScrollCharacter::PlayerOverlapEnd(AActor* _CollisionActor)
{
	if (true == _CollisionActor->ActorHasTag(TEXT("Ground")))
	{
		IsGroundValue = false;
	}
}

void ASideScrollCharacter::ViewCharacterJump()
{
	if (true == IsGroundValue)
	{
		IsJumpValue = true;
		GravityPower = 0.0f;
		JumpPower = PlayerData.JumpZVelocity;
		SetViewChracterPos(GetMesh()->GetRelativeLocation() + FVector(0.0f, 0.0f, 1.0f));
	}
}

void ASideScrollCharacter::ViewJump(float _DeltaTime)
{
	GravityPower += PlayerData.GravityAccSpeed * _DeltaTime;
	CurJumpPower = JumpPower + GravityPower;

	AddViewChracterPos(FVector(0.0f, 0.0f, CurJumpPower) * _DeltaTime);
}

void ASideScrollCharacter::ViewGravity(float _DeltaTime)
{
	GravityPower += PlayerData.GravityAccSpeed * _DeltaTime;
	AddViewChracterPos(FVector(0.0f, 0.0f, GravityPower));
}

void ASideScrollCharacter::SetViewChracterPos(FVector _Pos)
{
	GetMesh()->SetRelativeLocation(_Pos);
	_Pos.Z += GainCollisionPtr->GetScaledCapsuleHalfHeight();
	GainCollisionPtr->SetRelativeLocation(_Pos);
}

void ASideScrollCharacter::AddViewChracterPos(FVector _Dir)
{
	GetMesh()->AddRelativeLocation(_Dir);
	GainCollisionPtr->AddRelativeLocation(_Dir);
}