// Fill out your copyright notice in the Description page of Project Settings.


#include "SideScroll/SideScrollCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/PlayerInput.h"
#include "Global/KKYGameInstance.h"
#include "Components/InputComponent.h"
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
	
	//SpringArm->bDoCollisionTest = false;

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

	SideScrollData = Inst->GetSideScrollData();
	FSideScrollPlayerData PlayerData = SideScrollData->PlayerData;
	PlayerSpeed = PlayerData.PlayerSpeed;

	GetCharacterMovement()->GravityScale = PlayerData.GravityScale;
	GetCharacterMovement()->JumpZVelocity = PlayerData.JumpZVelocity;
	
}

// Called every frame
void ASideScrollCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalOffset(FVector(1.0f, 0.0f, 0.0f) * PlayerSpeed * DeltaTime);

}

void ASideScrollCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);

	//UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_Speed", EKeys::A, -1.f));
	//UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_Speed", EKeys::D, 1.f));

	//UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("DefaultPawn_Jump", EKeys::SpaceBar));

	//PlayerInputComponent->BindAxis("DefaultPawn_Speed", this, &ASideScrollCharacter::SpeedChange);
	//PlayerInputComponent->BindAction("DefaultPawn_Jump", EInputEvent::IE_Pressed, this, &ASideScrollCharacter::PlayerJump);
}

void ASideScrollCharacter::SpeedChange(float _Value)
{
	if (_Value != 0)
	{
		AddMovementInput(FVector(1.0f, 0.0f, 0.0f), _Value);
	}
}

void ASideScrollCharacter::PlayerJump()
{
	Jump();
}