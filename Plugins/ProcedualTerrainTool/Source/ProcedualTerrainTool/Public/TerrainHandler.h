// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "TerrainShape.h"

#include "GameFramework/Actor.h"
#include "TerrainHandler.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTerrainTool, Log, All);

class UTerrainSpriteData;
class UProcedualCollapseMode;

/**
 * A socket storing data relevant for terrain piece connections.
 */
USTRUCT(BlueprintType)
struct PROCEDUALTERRAINTOOL_API FTerrainTileData
{
	GENERATED_BODY()

	//The sprite data of this tile.
	UPROPERTY(EditAnywhere)
	UTerrainSpriteData* SpriteData = nullptr;

	//How likely this tile is to spawn.
	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"))
	float SpawnWeight = 1;

	FTerrainTileData()
	{

	}
};

/**
 * 
 */
UCLASS()
class PROCEDUALTERRAINTOOL_API ATerrainHandler : public AActor
{
	GENERATED_BODY()

public:
	ATerrainHandler();

	UFUNCTION(CallInEditor, Meta = (Category = "TerrainHandler"))
	void LogTest();

	UPROPERTY(EditAnywhere)
	TArray<FTerrainTileData> SpawnableTiles;

	UPROPERTY(EditAnywhere)
	int CollapsePredictionDepth = 0;

	UPROPERTY(EditAnywhere, Instanced)
	UProcedualCollapseMode* CollapseMode = nullptr;

	UFUNCTION(CallInEditor, Meta = (Category = "TerrainHandler"))
	void RefreshTileSet();

	UFUNCTION(CallInEditor, Meta = (Category = "TerrainHandler"))
	void ResetTerrain();

	UFUNCTION(CallInEditor, Meta = (Category = "TerrainHandler"))
	void DetachTerrain();

	UFUNCTION(CallInEditor, Meta = (Category = "TerrainHandler"))
	void CollapseSuperPosition();
	void CollapseSuperPosition(int SocketIndex, int ShapeIndex, int FaceIndex);

private:
	UPROPERTY()
	TArray<FTerrainTileData> CurrentSpawnableTiles = TArray<FTerrainTileData>();

	UPROPERTY()
	FTerrainShape CurrentShape = FTerrainShape();

	UPROPERTY()
	TArray<FTerrainShape> SpriteShapes = TArray<FTerrainShape>();

	UPROPERTY()
	TSet<AActor*> TerrainActors = TSet<AActor*>();

	TArray<TArray<bool>> BaseSuperPositions = TArray<TArray<bool>>();

	TArray<TArray<TArray<bool>>> SuperPositions = TArray<TArray<TArray<bool>>>();

	UFUNCTION()
	bool HasNewCollapseableSuperPositions(FTerrainShape Shape, FTerrainShapeMergeResult MergeResult, int SearchDepth = 0);
};