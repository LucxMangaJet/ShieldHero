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

UENUM(BlueprintType)
enum class ShieldReflectionModifier : uint8
{
	None,
	Double,
	VShape,
	TShape
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FCustomReflectionDelegate, AActor*, actor, UProjectileMovementComponent*, projectileMovement, FVector, hitNormal);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPostCustomReflectionDelegate, AActor*, actor, UProjectileMovementComponent*, projectileMovement);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SHIELDHERO_API UReflectionComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UReflectionComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	ReflectionType _reflectionType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	ShieldReflectionModifier _reflectionModifier;

	UFUNCTION(BlueprintCallable)
	void NotifyCustomReflection(AActor* actor, UProjectileMovementComponent* projectileMovement, FVector hitNormal);

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	AActor* FindBestEnemyInDirectionAfterReflection(FVector origin, FVector normal, FVector inVelocity, float maxDistance);

	UPROPERTY(BlueprintAssignable, Category = "Gameplay")
	FCustomReflectionDelegate OnCustomReflection;

	UPROPERTY(BlueprintAssignable, Category = "Gameplay")
	FPostCustomReflectionDelegate OnPostCustomReflection;
};
