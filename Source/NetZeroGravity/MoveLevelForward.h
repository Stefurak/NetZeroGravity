// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MoveLevelForward.generated.h"

UCLASS()
class NETZEROGRAVITY_API AMoveLevelForward : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMoveLevelForward();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	
	//Variables
	FVector2D LevelLayout;

	float LevelSpeed;

	//Functions
	void MoveForward();
};
