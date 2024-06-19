// Fill out your copyright notice in the Description page of Project Settings.


#include "FPS/Object/FPS_PickUpComponent.h"

// Sets default values
AFPS_PickUpComponent::AFPS_PickUpComponent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFPS_PickUpComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPS_PickUpComponent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

