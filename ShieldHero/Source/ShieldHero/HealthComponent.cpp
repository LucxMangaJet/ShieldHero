// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthComponent.h"
#include "Kismet/KismetMathLibrary.h"

UHealthComponent::UHealthComponent()
{
	_maxHealth = 100;
}


void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	_health = _maxHealth;
	OnHealthChanged.Broadcast(_health, 0.0f);
}

float UHealthComponent::GetHealthPercent() const
{
	if (_maxHealth == 0)
		return 0;

	return _health / _maxHealth;
}

void UHealthComponent::TakeDamage_Implementation(float amount)
{
	if (_isDead) return;

	amount = FMath::Max(0.0f, amount);
	_health -= amount;

	OnHealthChanged.Broadcast(_health, amount);

	if (_health <= 0)
	{
		_isDead = true;
		OnDeath.Broadcast();
	}
}

