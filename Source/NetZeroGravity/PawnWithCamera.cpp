// Fill out your copyright notice in the Description page of Project Settings.

#include "NetZeroGravity.h"
#include "PawnWithCamera.h"


// Sets default values
APawnWithCamera::APawnWithCamera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create our components
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	//OurCameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	//OurCameraSpringArm->SetupAttachment(RootComponent);
	//OurCameraSpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 80.0f), FRotator(-90.0f, 0.0f, 0.0f));
	//OurCameraSpringArm->TargetArmLength = 600.f;
	//OurCameraSpringArm->bEnableCameraLag = true;
	//OurCameraSpringArm->CameraLagSpeed = 300.0f;
	//OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("GameCamera"));
	//OurCamera->SetupAttachment(OurCameraSpringArm, USpringArmComponent::SocketName);

	//Take control of the default Player
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void APawnWithCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APawnWithCamera::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	//Zoom in if ZoomIn button is down, zoom back out if it's not
	{
		if (bZoomingOut)
		{
			ZoomFactor += DeltaTime / 0.5f;         //Zoom in over half a second
		}
		else
		{
			ZoomFactor -= DeltaTime / 0.25f;        //Zoom out over a quarter of a second
		}
		ZoomFactor = FMath::Clamp<float>(ZoomFactor, 0.0f, 1.0f);
		//Blend our camera's FOV and our SpringArm's length based on ZoomFactor
		//OurCamera->FieldOfView = FMath::Lerp<float>(90.0f, 120.0f, ZoomFactor);
		//OurCameraSpringArm->TargetArmLength = FMath::Lerp<float>(400.0f, 500.0f, ZoomFactor);
	}	

	//Handle movement based on our "MoveX" and "MoveY" axes
	{
		if (!MovementInput.IsZero())
		{
			//Scale our movement input axis values by 100 units per second
			MovementInput = MovementInput.SafeNormal() * 1600.0f;
			FVector NewLocation = GetActorLocation();
			NewLocation += GetActorUpVector() * MovementInput.X * DeltaTime;
			NewLocation += GetActorRightVector() * MovementInput.Y * DeltaTime;
			
			SetActorLocation(NewLocation);
		}
	}
}

// Called to bind functionality to input
void APawnWithCamera::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	//Hook up events for "ZoomIn"
	InputComponent->BindAction("ZoomOut", IE_Pressed, this, &APawnWithCamera::ZoomOut);
	InputComponent->BindAction("ZoomOut", IE_Released, this, &APawnWithCamera::ZoomIn);

	//Hook up every-frame handling for our four axes
	InputComponent->BindAxis("MoveUp", this, &APawnWithCamera::MoveUp);
	InputComponent->BindAxis("MoveRight", this, &APawnWithCamera::MoveRight);

}

//Input functions
void APawnWithCamera::MoveUp(float AxisValue)
{
	
	MovementInput.X = FMath::Clamp<float>(AxisValue, -1.0f, 1.0f) * 0.1f;
}

void APawnWithCamera::MoveRight(float AxisValue)
{
	
	MovementInput.Y = FMath::Clamp<float>(AxisValue, -1.0f, 1.0f) * 0.1f;
}

void APawnWithCamera::ZoomIn()
{
	bZoomingOut = false;
}

void APawnWithCamera::ZoomOut()
{
	bZoomingOut = true;
}