// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShieldHeroGameMode.h"
#include "KillAllGameMode.generated.h"



UCLASS()
class SHIELDHERO_API AKillAllGameMode : public AShieldHeroGameMode
{
	GENERATED_BODY()

protected:
		void OnEnemyDeath(AActor* actor) override;
};
