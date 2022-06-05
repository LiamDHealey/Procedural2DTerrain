// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "TerrainShape.h"
#include "HAL/Runnable.h"

#include "GameFramework/Actor.h"
#include "TerrainHandler.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTerrainTool, Log, All);

class UTerrainSpriteData;
class UProcedualCollapseMode;

/**
 * Information about a terrain tile and its spawning.
 */
USTRUCT(BlueprintType)
struct PROCEDUALTERRAINTOOL_API FTerrainTileData
{
	GENERATED_BODY()

	//The sprite data of this tile.
	UPROPERTY(EditAnywhere)
	int ShapeIndex;

	//How likely this tile is to spawn.
	UPROPERTY(EditAnywhere)
	FTerrainShapeMergeResult MergeResult;

	FTerrainTileData(int Index, MergeData) : ShapeIndex(Index), MergeResult(MergeData)
	{}
};

/**
 * Information needed to spawn a terrain tile tile.
 */
USTRUCT(BlueprintType)
struct PROCEDUALTERRAINTOOL_API FTerrainTileSpawnData
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

	UPROPERTY(EditAnywhere, Instanced)
	UProcedualCollapseMode* CollapseMode = nullptr;

	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0", ClampMax = "3"))
	int CollapsePredictionDepth = 0;

	UFUNCTION(CallInEditor, Meta = (Category = "TerrainHandler"))
	void ResetTerrain();

	UFUNCTION(CallInEditor, Meta = (Category = "TerrainHandler"))
	void DetachTerrain();

	UFUNCTION(CallInEditor, Meta = (Category = "TerrainHandler"))
	void CollapseSuperPosition();

private:

	UFUNCTION(Meta = (Category = "TerrainHandler"))
	void RefreshTileSet();

	UFUNCTION()
	void SpawnTile(int ShapeIndex, FTerrainShapeMergeResult MergeResult);

	UPROPERTY()
	TArray<FTerrainTileSpawnData> Tiles = TArray<FTerrainTileSpawnData>();

	UPROPERTY()
	int NumberOfTilesSpawned = 0;

	UPROPERTY()
	TSet<AActor*> TileActors = TSet<AActor*>();
};

class FTerrainGenerationWorker : public FRunnable
{
	//Thread to run the worker FRunnable on 
	FRunnableThread* Thread;
	//Whether or not the task is complete.
	std::atomic_bool bCompleated;
	//Will be written to as superpositions are collapsed.
	TArray<FTerrainTileSpawnData>* Tiles;


	//The method used for deciding which superposition to collapse next.
	UProcedualCollapseMode* CollapseMode;
	//How many iterations into the future to search for failed superpositions.
	int CollapsePredictionDepth;
	//The tiles that will be used to generate the terrain.
	TArray<FTerrainTileData> UseableTiles;
	//The shapes of the tiles.
	TArray<FTerrainShape> TileShapes;
	//The superposition of an empty socket.
	TArray<TArray<bool>> BaseSuperPositions;


	//The current shape of the terrain.
	FTerrainShape* Shape;
	//Whether or not a given tile can connect to a given socket. SuperPositions[Socket to connect to][Tile to add][Socket on tile to connect to].
	TArray<TArray<TArray<bool>>> SuperPositions = TArray<TArray<TArray<bool>>>();

	/**
	 * Attempts to collapse a super position at a given index. 
	 * 
	 * @param Index - X = Socket to connect to, Y = Tile to add, Z = Socket on tile to connect to.
	 * @return Whether or not the collapse was successful.
	 */
	bool CollapseSuperPosition(FIntVector Index);

	/**
	 * Whether or not there is an available super position to collapse after the given merge.
	 * 
	 * @param Shape - The shape to query.
	 * @param MergeResult - The result of the merge that most recently happened.
	 * @param SeachDeapth - How many iterations into the future to search.
	 */
	bool HasNewCollapseableSuperPositions(FTerrainShape Shape, FTerrainShapeMergeResult MergeResult, int SearchDepth = 0);

public:
	/**
	 * Creates a FTerrainGenerationWorker able to compute superposition collapses of the given tiles.
	 * 
	 * @param OutTiles - Will be written to as superpositions are collapsed.
	 * @param UseableTiles - The tiles that will be used to generate the terrain.
	 * @param Mode - The method used for deciding which superposition to collapse next.
	 * @param PredictionDepth - How many iterations into the future to search for failed superpositions.
	 */
	FTerrainGenerationWorker(TArray<FTerrainTileSpawnData>& OutTiles, TArray<FTerrainTileData> Tiles, UProcedualCollapseMode* Mode, const int PredictionDepth = 0);
	/**
	 * Destructs this and handles thread deletion.
	 */
	virtual ~FTerrainGenerationWorker();


	// \/ Begin FRunnable interface. \/ //
	virtual bool Init();
	virtual uint32 Run();
	virtual void Stop();
	// /\  End FRunnable interface.  /\ //

	/**
	 * Blocking function that stops the task and waits for completion.
	 */
	void Shutdown();

	/**
	 * Determines whether the terrain is finished generating.
	 * 
	 * @return Whether or not the terrain is finished generating.
	 */
	bool IsThreadFinished();
};