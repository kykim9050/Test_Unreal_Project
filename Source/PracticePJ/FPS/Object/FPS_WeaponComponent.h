// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "FPS_WeaponComponent.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PRACTICEPJ_API UFPS_WeaponComponent : public USkeletalMeshComponent
{
	GENERATED_BODY()
	
public:
	///** Projectile class to spawn */
	//UPROPERTY(EditDefaultsOnly, Category = Projectile)
	//TSubclassOf<class AFPSTestProjectile> ProjectileClass;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	USoundBase* FireSound;

	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	UAnimMontage* FireAnimation;
	
	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FVector MuzzleOffset;



	/** Sets default values for this component's properties */
	UFPS_WeaponComponent();

	/** Attaches the actor to a FirstPersonCharacter */
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	bool AttachWeapon(class AFPSCharacter* TargetCharacter);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void DetachWeapon();

	/** Make the weapon Fire a Projectile */
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void Fire();


protected:
	/** Ends gameplay for this component. */
	UFUNCTION()
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	// Fire 기능 종료
	void FireEnd();

private:
	/** The Character holding this weapon*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Owner", meta = (AllowPrivateAccess = "true"))
	AFPSCharacter* Character;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Owner", meta = (AllowPrivateAccess = "true"))
	bool IsFire = false;

	/** MappingContext */
	UPROPERTY()
	class UInputMappingContext* FireMappingContext = nullptr;

	/** Fire Input Action */
	UPROPERTY()
	class UInputAction* FireAction = nullptr;

	UPROPERTY()
	class UInputAction* DetachAction = nullptr;

};
