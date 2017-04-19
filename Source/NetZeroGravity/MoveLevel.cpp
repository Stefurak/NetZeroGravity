// Fill out your copyright notice in the Description page of Project Settings.

#include "NetZeroGravity.h"
#include "MoveLevel.h"


// Sets default values
AMoveLevel::AMoveLevel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMoveLevel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMoveLevel::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

