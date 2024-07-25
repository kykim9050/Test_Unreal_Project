// Fill out your copyright notice in the Description page of Project Settings.


#include "TestCharacter/TCCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Global/KKYEnum.h"
#include "Global/Animation/GlobalAnimInstance.h"
#include "Global/GlobalFunction.h"
#include "Global/DataTable/TCCharacterDataRow.h"
#include "TestCharacter/MainGameState.h"

// Sets default values
ATCCharacter::ATCCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("TCCharacterSpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("TCCharacterCamera"));
	Camera->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void ATCCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	SpringArm->TargetArmLength = 500.0f;
	
	FQuat Quat = FQuat();
	UKismetMathLibrary::Quat_SetFromEuler(Quat, FVector(0.0f, -20.0f, 0.0f));
	SpringArm->SetRelativeRotation(Quat);
	SpringArm->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));


	UKKYGameInstance* Inst = UGlobalFunction::GetKKYGameInstance(GetWorld());

	if (nullptr == Inst)
	{
		UE_LOG(LogType, Fatal, TEXT("%S(%u)> if (nullptr == Inst)"), __FUNCTION__, __LINE__);
		return;
	}

	FName Name = FName(TEXT("Character1"));
	FTCCharacterDataRow* Data = Inst->GetTCCharacterData(FName(Name));
	AnimMontages = Data->GetAnimMontages();

	if (true == AnimMontages.IsEmpty())
	{
		UE_LOG(LogType, Fatal, TEXT("%S(%u)> if (true == AnimMontages.IsEmpty())"), __FUNCTION__, __LINE__);
		return;
	}

	for (TPair< ETCPlayerAnimation, class UAnimMontage*> Montage : AnimMontages)
	{
		GetGlobalAnimInstance()->PushAnimation(Montage.Key, Montage.Value);
	}
	
	GetGlobalAnimInstance()->ChangeAnimation(ETCPlayerAnimation::Rifle_Idle);

}

// Called every frame
void ATCCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AMainGameState* TCGameState = Cast<AMainGameState>(GetWorld()->GetGameState());
	
	int Value = TCGameState->GetTestValue();
	FString Info = FString::FromInt(Value);
	UGlobalFunction::DebugTextPrint(GetWorld(), FString(TEXT("Test Value : ") + Info));
}

// Called to bind functionality to input
void ATCCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATCCharacter::ChangeAnimation(ETCPlayerAnimation _Animation)
{
	ATCPlayCharacter::ChangeAnimation(_Animation);
}