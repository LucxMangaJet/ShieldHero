// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ReflectionComponent.generated.h"

class UProjectileMovementComponent;

UENUM(BlueprintType)
enum class ReflectionType : uint8
{
	Reflect,
	StopAndDamage,
	ReflectAndDamage,
	Custom
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FCustomReflectionDelegate, AActor*, actor, UProjectileMovementComponent*, projectileMovement, FVector, hitNormal);


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SHIELDHERO_API UReflectionComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UReflectionComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	ReflectionType _reflectionType;

	UFUNCTION(BlueprintCallable)
	void NotifyCustomReflection(AActor* actor, UProjectileMovementComponent* projectileMovement, FVector hitNormal);

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	AActor* FindBestEnemyInDirectionAfterReflection(FVector origin, FVector normal, FVector inVelocity, float maxDistance);

	UPROPERTY(BlueprintAssignable, Category = "Gameplay")
	FCustomReflectionDelegate OnCustomReflection;

};
