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
	}
}

void AShieldHeroPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAxis("Vertical", this, &AShieldHeroPlayerController::OnVertical);
	InputComponent->BindAxis("Horizontal", this, &AShieldHeroPlayerController::OnHorizontal);
}

void AShieldHeroPlayerController::OnVertical(float vertical)
{
	_vertical = vertical;
}

void AShieldHeroPlayerController::OnHorizontal(float horizontal)
{
	_horizontal = horizontal;
}
