// Fill out your copyright notice in the Description page of Project Settings.

#include "NetZeroGravity.h"
#include "FloorGrid.h"


// Sets default values for this component's properties
UFloorGrid::UFloorGrid()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFloorGrid::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UFloorGrid::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

