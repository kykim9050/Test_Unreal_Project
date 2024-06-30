// Fill out your copyright notice in the Description page of Project Settings.


#include "FPS/Object/FPS_ItemComponent.h"
#include "Global/KKYGameInstance.h"
#include "Global/DataAssets/InputDatas.h"
#include "FPSTest/FPSCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
//#include "Global/DataTable/MeshDataRow.h"


UFPS_ItemComponent::UFPS_ItemComponent()
{

}

void UFPS_ItemComponent::BeginPlay()
{
	Super::BeginPlay();

	UKKYGameInstance* Inst = GetWorld()->GetGameInstanceChecked<UKKYGameInstance>();

	if (nullptr == Inst)
	{
		UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (nullptr == Inst)"), __FUNCTION__, __LINE__);
	}

	UInputDatas* Asset = Inst->GetInputDataAsset();
	FireMappingContext = Asset->GetInputMapping();

	FireAction = *(Asset->GetActions().Find(TEXT("Shoot")));
	DetachAction = *(Asset->GetActions().Find(TEXT("Detach")));

	UStaticMesh* Mesh = Inst->GetStaticMeshData(TEXT("Rifle_Mesh"));
	SetStaticMesh(Mesh);
}

void UFPS_ItemComponent::Fire()
{
	if (Character == nullptr || Character->GetController() == nullptr)
	{
		return;
	}

	IsFire = true;
}

void UFPS_ItemComponent::FireEnd()
{
	IsFire = false;
}

void UFPS_ItemComponent::DetachWeapon()
{
	FDetachmentTransformRules DetachmentRules(EDetachmentRule::KeepWorld, true);

	DetachFromComponent(DetachmentRules);

	if (APlayerController* PlayerController = Cast<APlayerController>(Character->GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			FireMappingContext = nullptr;
		}

		if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerController->InputComponent))
		{
			EnhancedInputComponent->ClearBindingsForObject(this);

			FireAction = nullptr;
			DetachAction = nullptr;
		}
	}

	Character->RemoveInstanceComponent(this);
}

bool UFPS_ItemComponent::AttachWeapon(AFPSCharacter* TargetCharacter)
{
	Character = TargetCharacter;

	// Check that the character is valid, and has no weapon component yet
	if (Character == nullptr || Character->GetInstanceComponents().FindItemByClass<UFPS_ItemComponent>())
	{
		return false;
	}

	// Attach the weapon to the First Person Character
	FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);
	FName AttachSocket = Character->GetMesh()->GetSocketBoneName(FName(TEXT("GunSock")));
	AttachToComponent(Character->GetMesh(), AttachmentRules, AttachSocket);


	// add the weapon as an instance component to the character
	Character->AddInstanceComponent(this);

	// Set up action bindings
	if (APlayerController* PlayerController = Cast<APlayerController>(Character->GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{

			// Set the priority of the mapping to 1, so that it overrides the Jump action with the Fire action when using touch input
			Subsystem->AddMappingContext(FireMappingContext, 1);
		}

		if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerController->InputComponent))
		{
			// Fire
			EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Triggered, this, &UFPS_ItemComponent::Fire);

			// Fire End
			EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Completed, this, &UFPS_ItemComponent::FireEnd);

			EnhancedInputComponent->BindAction(DetachAction, ETriggerEvent::Started, this, &UFPS_ItemComponent::DetachWeapon);
		}
	}

	return true;
}

void UFPS_ItemComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (Character == nullptr)
	{
		return;
	}

	if (APlayerController* PlayerController = Cast<APlayerController>(Character->GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->RemoveMappingContext(FireMappingContext);
		}
	}
}
