// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "FloorGrid.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NETZEROGRAVITY_API UFloorGrid : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFloorGrid();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

		
	//Variables
	FVector2D LevelLayout;
	FVector currentLocation;

	float LevelSpeed;
	float NodeSize;

	int GridWidth;
	int GridLength;

	//Functions
	void MoveGrid();
};
