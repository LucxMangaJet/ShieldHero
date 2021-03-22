// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShieldHeroCharacter.generated.h"


UENUM(BlueprintType)
enum class ShieldMode : uint8
{
	ShieldIsOwnInput,
	DirectionalShieldOnIdle,
	AutoaimShieldOnIdle
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMovementDelegate);

UCLASS(Blueprintable)
class AShieldHeroCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AShieldHeroCharacter();

	virtual void BeginPlay() override;

	UFUNCTION()
	void Move(float horizontal, float vertical);

	UFUNCTION()
	void AimShield(float horitontal, float vertical);

	UFUNCTION()
	AActor* GetClosestProjectile();

	void UpdateShieldOrientation();

	UPROPERTY(BlueprintAssignable, Category = "Gameplay")
	FMovementDelegate OnBeginMoving;

	UPROPERTY(BlueprintAssignable, Category = "Gameplay")
	FMovementDelegate OnStopMoving;

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* _topDownCameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
		class UChildActorComponent* _shield;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
	class UHealthComponent* _healthComponent;

	FVector _shieldOrientation = FVector::ForwardVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
	FVector _shieldOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
	ShieldMode _shieldMode = ShieldMode::ShieldIsOwnInput;
};

