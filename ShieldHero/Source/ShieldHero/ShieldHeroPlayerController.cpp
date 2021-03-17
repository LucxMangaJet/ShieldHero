// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShieldHeroPlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "ShieldHeroCharacter.h"
#include "Engine/World.h"

AShieldHeroPlayerController::AShieldHeroPlayerController()
{
	DefaultMouseCursor = EMouseCursor::Crosshairs;
	
}

void AShieldHeroPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	if (auto character = GetPawn<AShieldHeroCharacter>())
	{
		character->Move(_horizontal, _vertical);
		character->AimShield(_aimHorizontal, _aimVertical);
	}
}

void AShieldHeroPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAxis("Vertical", this, &AShieldHeroPlayerController::OnVertical);
	InputComponent->BindAxis("Horizontal", this, &AShieldHeroPlayerController::OnHorizontal);

	InputComponent->BindAxis("Aim_Vertical", this, &AShieldHeroPlayerController::OnAimVertical);
	InputComponent->BindAxis("Aim_Horizontal", this, &AShieldHeroPlayerController::OnAimHorizontal);
}

void AShieldHeroPlayerController::OnVertical(float vertical)
{
	_vertical = vertical;
}

void AShieldHeroPlayerController::OnHorizontal(float horizontal)
{
	_horizontal = horizontal;
}

void AShieldHeroPlayerController::OnAimVertical(float vertical)
{
	_aimVertical = vertical;
}

void AShieldHeroPlayerController::OnAimHorizontal(float horizontal)
{
	_aimHorizontal = horizontal;
}
