// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "PawnWithCamera.generated.h"

UCLASS()
class NETZEROGRAVITY_API APawnWithCamera : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnWithCamera();

	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

protected:	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
	USpringArmComponent* OurCameraSpringArm;
	UCameraComponent* OurCamera;
	
	//Input variables
	FVector2D MovementInput;
	FVector2D CameraInput;
	float ZoomFactor;
	bool bZoomingOut;

	//Input functions
	void MoveUp(float AxisValue);
	void MoveRight(float AxisValue);
	void ZoomIn();
	void ZoomOut();
};
