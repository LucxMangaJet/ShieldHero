// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShieldHeroPlayerController.generated.h"

UCLASS()
class AShieldHeroPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AShieldHeroPlayerController();

protected:
	float _vertical;
	float _horizontal;


	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	void OnVertical(float vertical);
	void OnHorizontal(float horizontal);
};


