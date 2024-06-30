// Fill out your copyright notice in the Description page of Project Settings.


#include "FPS/Object/FPS_ItemBase.h"
#include "FPS_ItemComponent.h"
#include "FPS_PickUpComponent.h"

// Sets default values
AFPS_ItemBase::AFPS_ItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemComponent = CreateDefaultSubobject<UFPS_ItemComponent>(TEXT("FPS_Weapon"));
	PickUpComponent = CreateDefaultSubobject<UFPS_PickUpComponent>(TEXT("FPS_PickUp"));

	ItemComponent->SetupAttachment(RootComponent);
	PickUpComponent->SetupAttachment(ItemComponent);
}

// Called when the game starts or when spawned
void AFPS_ItemBase::BeginPlay()
{
	Super::BeginPlay();

	ItemComponent->SetCollisionProfileName(FName(TEXT("NoCollision")));
}

// Called every frame
void AFPS_ItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

