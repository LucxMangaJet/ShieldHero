// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShieldHeroGameMode.h"
#include "ShieldHeroPlayerController.h"
#include "ShieldHeroCharacter.h"
#include "UObject/ConstructorHelpers.h"

AShieldHeroGameMode::AShieldHeroGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AShieldHeroPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}