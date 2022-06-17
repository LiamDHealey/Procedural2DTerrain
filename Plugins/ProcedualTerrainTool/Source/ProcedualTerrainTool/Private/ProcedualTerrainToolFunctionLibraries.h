// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Factories/DataAssetFactory.h"

#include "ProcedualTerrainToolFunctionLibraries.generated.h"

/**
 * A library of useful math functions.
 */
UCLASS()
class PROCEDUALTERRAINTOOL_API UPTTMath : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	FORCEINLINE static int Mod(int A, int B)
	{
		int Value = A % B;
		if (Value < 0)
		{
			Value += B;
		}
		return Value;
	};
};

/**
 * A library for creating various factories.
 */
UCLASS()
class PROCEDUALTERRAINTOOL_API UPTTFactories : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static FORCEINLINE UDataAssetFactory* CreateDataAssetFactory()
	{
		return NewObject<UDataAssetFactory>();
	};
};