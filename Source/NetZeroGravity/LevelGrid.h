// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "LevelGrid.generated.h"

UCLASS()
class NETZEROGRAVITY_API ALevelGrid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelGrid();

	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	//Variables
	FVector2D LevelLayout;
	float LevelSpeed;
	float NodeSize;
	int GridWidth;
	int GridLength;

	//Functions
	void MoveGrid(float AxisValue);
};
