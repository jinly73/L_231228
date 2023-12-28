// Fill out your copyright notice in the Description page of Project Settings.


#include "BBC.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"

// Sets default values
ABBC::ABBC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);


	GetMesh()->SetRelativeLocation(FVector(0, 0, -GetCapsuleComponent()->GetScaledCapsuleHalfHeight()));
	GetMesh()->SetRelativeRotation(FRotator(0, -90.0f, 0));
	//GetCapsuleComponent()->GetScaledCapsuleHalfHeight(); 
}

// Called when the game starts or when spawned
void ABBC::BeginPlay()
{
	Super::BeginPlay();
	

}

// Called every frame
void ABBC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABBC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* UEIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (UEIC)
	{
		UEIC->BindAction(IA_Jump, ETriggerEvent::Triggered, this, &ABBC::Jump);
		UEIC->BindAction(IA_Jump, ETriggerEvent::Completed, this, &ABBC::StopJumping);

		UEIC->BindAction(IA_Move, ETriggerEvent::Triggered, this, &ABBC::Move);
		UEIC->BindAction(IA_Look, ETriggerEvent::Triggered, this, &ABBC::Look);
	}

}

void ABBC::Move(const FInputActionValue& Value)
{
	FVector2D Dir = Value.Get<FVector2D>();
	AddMovementInput(FVector(Dir.Y, Dir.X, 0));
}

void ABBC::Look(const FInputActionValue& Value)
{
	FVector2D Rotation = Value.Get<FVector2D>();

	AddControllerYawInput(Rotation.X); //절대 회전을 시킨다.
	AddControllerPitchInput(Rotation.Y);
}

