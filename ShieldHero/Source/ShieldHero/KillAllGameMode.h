// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "KillAllGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGameWonDelegate);

UCLASS()
class SHIELDHERO_API AKillAllGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:

	UPROPERTY()
	int _enemyCount;

	UFUNCTION()
	void OnEnemyDeath();

public:
	AKillAllGameMode();


	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void RegisterEnemy(AActor* actor);

	UPROPERTY(BlueprintAssignable, Category = "Gameplay")
	FGameWonDelegate OnGameWon;
};
