// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Engine/DataAsset.h"
#include "TerrainTileData.generated.h"

/**
 * The data needed for an actor to be used by the terrain generator.
 */
UCLASS(BlueprintType)
class PROCEDUALTERRAINTOOL_API UTerrainTileData : public UDataAsset
{
	GENERATED_BODY()
	
public:
	//The class of the actor that will be spawned by the terrain generator.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ActorClass;

	//The vertices of the 2D bounds of this actor.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector2D> Verticies;

	//The indexes of each face of the bounds of this actor. Used for determining if tiles can connect.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> FaceIndices;
};
