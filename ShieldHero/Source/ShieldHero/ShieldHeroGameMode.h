// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShieldHeroGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGameWonDelegate);

UCLASS(minimalapi)
class AShieldHeroGameMode : public AGameModeBase
{
	GENERATED_BODY()


protected:

	UPROPERTY()
		int _enemyCount;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<AActor*> _enemies;

	UFUNCTION()
		virtual void OnEnemyDeath(AActor* actor);

public:
	AShieldHeroGameMode();

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
		void RegisterEnemy(AActor* actor);

	UPROPERTY(BlueprintAssignable, Category = "Gameplay")
		FGameWonDelegate OnGameWon;

	TArray<AActor*>* GetEnemies();
};
