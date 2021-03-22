// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShieldHeroGameMode.h"
#include "ShieldHeroPlayerController.h"
#include "ShieldHeroCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "HealthComponent.h"

AShieldHeroGameMode::AShieldHeroGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AShieldHeroPlayerController::StaticClass();

}


void AShieldHeroGameMode::RegisterEnemy(AActor* actor)
{
	if (!actor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Register Enemy null pointer"));
		return;
	}

	UHealthComponent* healthComponent = Cast<UHealthComponent>(actor->GetComponentByClass(UHealthComponent::StaticClass()));

	if (!healthComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("Trying to register an enemy with no health component"));
		return;
	}

	_enemyCount++;
	_enemies.Add(actor);
	healthComponent->OnDeath.AddDynamic(this, &AShieldHeroGameMode::OnEnemyDeath);
	UE_LOG(LogTemp, Log, TEXT("Registered enemy %s"), *actor->GetName());
}

TArray<AActor*>* AShieldHeroGameMode::GetEnemies()
{
	return &_enemies;
}

void AShieldHeroGameMode::OnEnemyDeath(AActor* actor)
{
	UE_LOG(LogTemp, Log, TEXT("Registered enemy death: %s"), *actor->GetName());
	_enemyCount--;
	_enemies.Remove(actor);
}
