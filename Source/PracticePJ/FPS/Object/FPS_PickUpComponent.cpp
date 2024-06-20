// Fill out your copyright notice in the Description page of Project Settings.


#include "FPS/Object/FPS_PickUpComponent.h"

UFPS_PickUpComponent::UFPS_PickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UFPS_PickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UFPS_PickUpComponent::OnSphereBeginOverlap);
}

void UFPS_PickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	AFPSCharacter* Character = Cast<AFPSCharacter>(OtherActor);
	if (Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}