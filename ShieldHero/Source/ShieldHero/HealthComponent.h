// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DamagableInterface.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FHealthChangedDelegate, float, newHealth, float, change);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDeathDelegate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHIELDHERO_API UHealthComponent : public UActorComponent , public IDamagableInterface
{
	GENERATED_BODY()

public:	
	UHealthComponent();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float _maxHealth;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Gameplay)
	float _health;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Gameplay)
	bool _isDead;

public:	
	
	void TakeDamage_Implementation(float amount) override;
	
	UFUNCTION(BlueprintCallable)
	float GetHealthPercent() const;

	UPROPERTY(BlueprintAssignable, Category = "Gameplay")
	FHealthChangedDelegate OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "Gameplay")
	FDeathDelegate OnDeath;
};
