// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ReflectionComponent.generated.h"

UENUM(BlueprintType)
enum class ReflectionType : uint8
{
	NoReflection,
	SimpleReflection
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHIELDHERO_API UReflectionComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UReflectionComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		ReflectionType _reflectionType;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;



public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
