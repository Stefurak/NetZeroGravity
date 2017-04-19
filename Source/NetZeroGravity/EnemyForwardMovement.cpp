// Fill out your copyright notice in the Description page of Project Settings.

#include "NetZeroGravity.h"
#include "EnemyForwardMovement.h"


// Sets default values
AEnemyForwardMovement::AEnemyForwardMovement()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	LevelSpeed = 15.0f;
}

// Called when the game starts or when spawned
void AEnemyForwardMovement::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyForwardMovement::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	MoveForward();
}

void AEnemyForwardMovement::MoveForward() {
	FVector NewLocation = GetActorLocation();
	NewLocation.X -= LevelSpeed;

	SetActorLocation(NewLocation);
}
