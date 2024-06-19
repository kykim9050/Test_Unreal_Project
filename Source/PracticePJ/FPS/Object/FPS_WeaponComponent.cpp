// Fill out your copyright notice in the Description page of Project Settings.


#include "FPS/Object/FPS_WeaponComponent.h"

// Sets default values
AFPS_WeaponComponent::AFPS_WeaponComponent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFPS_WeaponComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPS_WeaponComponent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

