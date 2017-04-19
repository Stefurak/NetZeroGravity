// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "EnemyForwardMovement.generated.h"

UCLASS()
class NETZEROGRAVITY_API AEnemyForwardMovement : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyForwardMovement();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//Variables
	FVector currentLocation;
	float LevelSpeed;

	//Functions
	void MoveForward();
	
};
