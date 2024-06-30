// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "FPS_ItemComponent.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PRACTICEPJ_API UFPS_ItemComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	/** Attaches the actor to a FirstPersonCharacter */
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	bool AttachWeapon(class AFPSCharacter* TargetCharacter);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void DetachWeapon();

	/** Make the weapon Fire a Projectile */
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void Fire();

protected:
	UFPS_ItemComponent();

	/** Ends gameplay for this component. */
	UFUNCTION()
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	void BeginPlay() override;

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
