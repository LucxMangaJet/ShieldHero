// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "LootHelper.generated.h"

USTRUCT(BlueprintType)
struct FDropChancePair
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TSubclassOf<AActor> Actor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float Probability;
};

USTRUCT(BlueprintType)
struct FLootTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<FDropChancePair> Drops;

};

UCLASS()
class SHIELDHERO_API ULootHelper : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	static TSubclassOf<AActor> RollRandomLoot(FLootTableRow& row);

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
		static TSubclassOf<AActor> RollRandomLootFromHandle(FDataTableRowHandle handle);
};
