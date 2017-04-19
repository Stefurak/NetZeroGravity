// Fill out your copyright notice in the Description page of Project Settings.

#include "NetZeroGravity.h"
#include "MoveLevelForward.h"


// Sets default values
AMoveLevelForward::AMoveLevelForward()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	LevelSpeed = 5.0f;
}

// Called when the game starts or when spawned
void AMoveLevelForward::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMoveLevelForward::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	MoveForward();
}

void AMoveLevelForward::MoveForward() {
	FVector NewLocation = GetActorLocation();
	NewLocation.X -= LevelSpeed;

	SetActorLocation(NewLocation);
}