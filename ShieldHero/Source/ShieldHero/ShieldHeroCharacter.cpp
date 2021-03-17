// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShieldHeroCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "HealthComponent.h"
#include "Components/ChildActorComponent.h"
#include "Materials/Material.h"
#include "Engine/World.h"
#include "Kismet/KismetMathLibrary.h"

AShieldHeroCharacter::AShieldHeroCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	_cameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	_cameraBoom->SetupAttachment(RootComponent);
	_cameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	_cameraBoom->TargetArmLength = 800.f;
	_cameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	_cameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	_topDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	_topDownCameraComponent->SetupAttachment(_cameraBoom, USpringArmComponent::SocketName);
	_topDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm


	//Create the shield...
	_shield = CreateDefaultSubobject<UChildActorComponent>(TEXT("Shield"));
	_shield->SetupAttachment(RootComponent);
	_shield->bEditableWhenInherited = true;
	_shield->SetUsingAbsoluteRotation(true);

	//Create the health component...
	_healthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health"));

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void AShieldHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AShieldHeroCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);


}

void AShieldHeroCharacter::Move(float horizontal, float vertical)
{
	FVector direction = FVector(vertical, horizontal, 0);

	if (direction.Size() > 0.0f)
	{
		FRotator rotation = UKismetMathLibrary::MakeRotFromXZ(direction, FVector::UpVector);

		SetActorRotation(rotation);

		if (direction.Size() > 0.3f)
		{
			AddMovementInput(direction, 1);
		}
	}
}

void AShieldHeroCharacter::AimShield(float horizontal, float vertical)
{
	FVector direction = FVector(vertical, horizontal, 0);
	if (direction.Size() > 0.0f)
	{
		_shieldOrientation = direction;

	}
		FRotator rotation = UKismetMathLibrary::MakeRotFromXZ(_shieldOrientation, FVector::UpVector);

		_shield->SetWorldRotation(rotation);

		 FVector offset = rotation.RotateVector(_shieldOffset);

		_shield->SetWorldLocation(GetActorLocation() + offset);
}
