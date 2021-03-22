// Fill out your copyright notice in the Description page of Project Settings.

#include "KillAllGameMode.h"
#include "HealthComponent.h"
#include "ShieldHeroPlayerController.h"

void AKillAllGameMode::OnEnemyDeath(AActor* actor)
{
	Super::OnEnemyDeath(actor);

	if (_enemyCount <= 0)
	{
		OnGameWon.Broadcast();
	}
}
