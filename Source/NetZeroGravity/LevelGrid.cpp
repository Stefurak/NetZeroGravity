// Fill out your copyright notice in the Description page of Project Settings.

#include "NetZeroGravity.h"
#include "LevelGrid.h"


// Sets default values
ALevelGrid::ALevelGrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	LevelSpeed = 15.0f;

}

// Called when the game starts or when spawned
void ALevelGrid::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALevelGrid::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	MoveGrid();
}

//Moves the level forward
void ALevelGrid::MoveGrid() {
	FVector NewLocation = GetActorLocation();
	NewLocation.X -= LevelSpeed;

	SetActorLocation(NewLocation);
}

