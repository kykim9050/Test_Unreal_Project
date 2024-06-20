// Fill out your copyright notice in the Description page of Project Settings.


#include "FPS/Object/FPS_PickUpableItem.h"

// Sets default values
AFPS_PickUpableItem::AFPS_PickUpableItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

