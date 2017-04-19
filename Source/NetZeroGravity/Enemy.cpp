// Fill out your copyright notice in the Description page of Project Settings.

#include "NetZeroGravity.h"
#include "Enemy.h"


// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
		resetEnemyLocation = FVector(3000.0f, .0f, .0f);
	SetActorLocation(resetEnemyLocation);
	maxEnemyLocation = FVector(8000.0f, .0f, .0f);

	LevelSpeed = 12.0f;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	currentLocation = GetActorLocation();

	MoveForward(currentLocation);

	if (currentLocation.X <= -maxEnemyLocation.X) {
		MoveBackwards();
	}
}

void AEnemy::MoveForward(FVector NewLocation) {
	NewLocation.X -= LevelSpeed;
	SetActorLocation(NewLocation);
}

void AEnemy::MoveBackwards() {
	currentLocation = resetEnemyLocation;

	SetActorLocation(currentLocation);
}