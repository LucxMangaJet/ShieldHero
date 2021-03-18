// Fill out your copyright notice in the Description page of Project Settings.


#include "LootHelper.h"

TSubclassOf<AActor> ULootHelper::RollRandomLoot(FLootTableRow& row)
{
	float sum = 0;
	for (int x = 0; x < row.Drops.Num(); x++)
	{
		sum += row.Drops[x].Probability;
	}

	if (sum == 0)
		return nullptr;

	float rnd = FMath::RandRange(0.0f, sum);

	for (int x = 0; x < row.Drops.Num(); x++)
	{
		float probability = row.Drops[x].Probability;

		if (rnd < probability)
		{
			return row.Drops[x].Actor;
		}
		else
		{
			rnd -= probability;
		}
	}

	return nullptr;
}

TSubclassOf<AActor> ULootHelper::RollRandomLootFromHandle(FDataTableRowHandle handle)
{
	if (handle.IsNull())
		return nullptr;

	FLootTableRow* row = handle.GetRow<FLootTableRow>("");

	if (row == nullptr)
		return nullptr;

	return ULootHelper::RollRandomLoot(*row);
}
