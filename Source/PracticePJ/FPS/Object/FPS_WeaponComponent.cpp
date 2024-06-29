// Fill out your copyright notice in the Description page of Project Settings.


#include "FPS/Object/FPS_WeaponComponent.h"
// Copyright Epic Games, Inc. All Rights Reserved.
#include "FPSTest/FPSCharacter.h"
#include "GameFramework/PlayerController.h"
#include "Camera/PlayerCameraManager.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Animation/AnimInstance.h"
#include "Engine/LocalPlayer.h"
#include "Engine/World.h"
#include "Global/KKYGameInstance.h"
#include "Global/DataAssets/InputDatas.h"

// Sets default values for this component's properties
UFPS_WeaponComponent::UFPS_WeaponComponent()
{
	// Default offset from the character location for projectiles to spawn
	MuzzleOffset = FVector(100.0f, 0.0f, 10.0f);
}


void UFPS_WeaponComponent::Fire()
{
	if (Character == nullptr || Character->GetController() == nullptr)
	{
		return;
	}

	IsFire = true;

	//// Try and fire a projectile
	//if (ProjectileClass != nullptr)
	//{
	//	UWorld* const World = GetWorld();
	//	if (World != nullptr)
	//	{
	//		APlayerController* PlayerController = Cast<APlayerController>(Character->GetController());
	//		const FRotator SpawnRotation = PlayerController->PlayerCameraManager->GetCameraRotation();
	//		// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
	//		const FVector SpawnLocation = GetOwner()->GetActorLocation() + SpawnRotation.RotateVector(MuzzleOffset);

	//		//Set Spawn Collision Handling Override
	//		FActorSpawnParameters ActorSpawnParams;
	//		ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

	//		// Spawn the projectile at the muzzle
	//		World->SpawnActor<AFPSTestProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
	//	}
	//}

	//// Try and play the sound if specified
	//if (FireSound != nullptr)
	//{
	//	UGameplayStatics::PlaySoundAtLocation(this, FireSound, Character->GetActorLocation());
	//}

	//// Try and play a firing animation if specified
	//if (FireAnimation != nullptr)
	//{
	//	// Get the animation object for the arms mesh
	//	UAnimInstance* AnimInstance = Character->GetMesh1P()->GetAnimInstance();
	//	if (AnimInstance != nullptr)
	//	{
	//		AnimInstance->Montage_Play(FireAnimation, 1.f);
	//	}
	//}
}

void UFPS_WeaponComponent::FireEnd()
{
	IsFire = false;
}

void UFPS_WeaponComponent::DetachWeapon()
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


bool UFPS_WeaponComponent::AttachWeapon(AFPSCharacter* TargetCharacter)
{
	Character = TargetCharacter;

	// Check that the character is valid, and has no weapon component yet
	if (Character == nullptr || Character->GetInstanceComponents().FindItemByClass<UFPS_WeaponComponent>())
	{
		return false;
	}

	{
		UKKYGameInstance* Inst = GetWorld()->GetGameInstanceChecked<UKKYGameInstance>();

		if (nullptr == Inst)
		{
			UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (nullptr == Inst)"), __FUNCTION__, __LINE__);
		}

		UInputDatas* Asset = Inst->GetInputDataAsset();
		FireMappingContext = Asset->GetInputMapping();

		FireAction = *(Asset->GetActions().Find(TEXT("Shoot")));
		DetachAction = *(Asset->GetActions().Find(TEXT("Detach")));
	}


	// Attach the weapon to the First Person Character
	FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);
	FName GunAttachSpot = Character->GetMesh()->GetSocketBoneName(FName(TEXT("GunSock")));
	AttachToComponent(Character->GetMesh(), AttachmentRules, GunAttachSpot);


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
			EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Triggered, this, &UFPS_WeaponComponent::Fire);

			// Fire End
			EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Completed, this, &UFPS_WeaponComponent::FireEnd);

			EnhancedInputComponent->BindAction(DetachAction, ETriggerEvent::Started, this, &UFPS_WeaponComponent::DetachWeapon);
		}
	}

	return true;
}

void UFPS_WeaponComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
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
