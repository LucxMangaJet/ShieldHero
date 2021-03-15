// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "DamagableInterface.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UDamagableInterface : public UInterface
{
	GENERATED_BODY()
};

class IDamagableInterface
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = Gameplay)
	void TakeDamage(float amount);

};