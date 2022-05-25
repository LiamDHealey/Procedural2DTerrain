// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "VectorArc.h"

#include "GameFramework/Actor.h"
#include "TerrainHandler.generated.h"

class UTerrainSpriteData;

/**
 * 
 */
UCLASS()
class PROCEDUALTERRAINTOOL_API ATerrainHandler : public AActor
{
	GENERATED_BODY()

	UFUNCTION(CallInEditor, Meta = (Category = "TerrainHandler"))
	void LogTest();

	UPROPERTY(EditAnywhere)
	UTerrainSpriteData* SpriteData;
};

/**/
USTRUCT()
struct PROCEDUALTERRAINTOOL_API FTerrainSocket
{
	GENERATED_BODY()

	UPROPERTY()
	float Length = 1;

	UPROPERTY()
	FVectorArc FirstAngle = FVectorArc();

	UPROPERTY()
	FVectorArc SecondAngle = FVectorArc();
};
