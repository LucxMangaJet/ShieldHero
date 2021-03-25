// Fill out your copyright notice in the Description page of Project Settings.

#include "ReflectionComponent.h"
#include "ShieldHeroGameMode.h"
#include "GenericPlatform/GenericPlatformMath.h"

// Sets default values for this component's properties
UReflectionComponent::UReflectionComponent()
{


}

void UReflectionComponent::NotifyCustomReflection(AActor* actor, UProjectileMovementComponent* projectileMovement, FVector hitNormal)
{
	OnCustomReflection.Broadcast(actor, projectileMovement, hitNormal);
	OnPostCustomReflection.Broadcast(actor, projectileMovement);
}

AActor* UReflectionComponent::FindBestEnemyInDirectionAfterReflection(FVector origin, FVector normal, FVector inVelocity, float maxDistance)
{
	AShieldHeroGameMode* gameMode = GetWorld()->GetAuthGameMode<AShieldHeroGameMode>();

	TArray<AActor*>* enemies = gameMode->GetEnemies();

	float maxDot = TNumericLimits<float>::Min();
	AActor* bestEnemy = nullptr;

	for (size_t i = 0; i < enemies->Num(); i++)
	{
		AActor* enemy = (*enemies)[i];


		FVector toEnemy = enemy->GetActorLocation() - origin;

		//InRange
		if (toEnemy.Size() < maxDistance)
		{
			FVector normalizedToEnemy = toEnemy.GetSafeNormal();

			//InDirection
			if (FVector::DotProduct(normalizedToEnemy, normal) > 0)
			{

				FVector reflectedVelocity = FMath::GetReflectionVector(inVelocity, normal);

				float reflectedDot = FVector::DotProduct(reflectedVelocity, normalizedToEnemy);
				if (reflectedDot > maxDot)
				{
					maxDot = reflectedDot;
					bestEnemy = enemy;
				}
			}
		}
	}

	return bestEnemy;
}
