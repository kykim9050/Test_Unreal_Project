// Fill out your copyright notice in the Description page of Project Settings.


#include "FPS/Object/FPS_PickUpableItem.h"
#include "FPS_WeaponComponent.h"
#include "FPS_PickUpComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AFPS_PickUpableItem::AFPS_PickUpableItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WeaponComponent = CreateDefaultSubobject<UFPS_WeaponComponent>(TEXT("FPS_Weapon"));
	PickUpComponent = CreateDefaultSubobject<UFPS_PickUpComponent>(TEXT("FPS_PickUp"));
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FPS_Mesh"));
	
	WeaponComponent->SetupAttachment(RootComponent);
	PickUpComponent->SetupAttachment(WeaponComponent);
	MeshComponent->SetupAttachment(WeaponComponent);
}

// Called when the game starts or when spawned
void AFPS_PickUpableItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPS_PickUpableItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

