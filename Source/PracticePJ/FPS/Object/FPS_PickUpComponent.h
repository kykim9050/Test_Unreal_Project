// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "FPSTest/FPSCharacter.h"
#include "FPS_PickUpComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPickUp, AFPSCharacter*, PickUpCharacter);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPutDown, AFPSCharacter*, PutDownCharacter);

UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PRACTICEPJ_API UFPS_PickUpComponent : public USphereComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "Interaction")
	FOnPickUp OnPickUp; 

	UPROPERTY(BlueprintAssignable, Category = "Interaction")
	FOnPutDown OnPutDown;

	UFPS_PickUpComponent();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	

};
