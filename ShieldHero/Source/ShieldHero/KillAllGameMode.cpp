// Fill out your copyright notice in the Description page of Project Settings.

#include "KillAllGameMode.h"
#include "HealthComponent.h"
#include "ShieldHeroPlayerController.h"


AKillAllGameMode::AKillAllGameMode()
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

void AKillAllGameMode::RegisterEnemy(AActor* actor)
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
	healthComponent->OnDeath.AddDynamic(this, &AKillAllGameMode::OnEnemyDeath);
	UE_LOG(LogTemp, Log, TEXT("Registered enemy"));
}

void AKillAllGameMode::OnEnemyDeath()
{
	UE_LOG(LogTemp, Log, TEXT("Registered enemy death"));
	_enemyCount--;
	if (_enemyCount == 0)
	{
		OnGameWon.Broadcast();
	}
}
