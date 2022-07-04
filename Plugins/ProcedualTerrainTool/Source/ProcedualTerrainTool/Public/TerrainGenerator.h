// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "TerrainShape.h"
#include "HAL/Runnable.h"

#include "GameFramework/Actor.h"
#include "TerrainGenerator.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTerrainTool, Log, All);

class UTerrainTileData;
class UProcedualCollapseMode;
class UManualCollapseMode;


/* \/ ========================= \/ *\
|  \/ FTerrainTileInstanceData  \/  |
\* \/ ========================= \/ */

/**
 * Information about a terrain tile and location.
 */
USTRUCT()
struct PROCEDUALTERRAINTOOL_API FTerrainTileInstanceData
{
	GENERATED_BODY()

	//The index of this tile.
	UPROPERTY()
	int ShapeIndex;

	//The merge result that created this tile.
	UPROPERTY()
	FTerrainShapeMergeResult MergeResult;

	/**
	 * Initializes a FTerrainTileInstanceData.
	 */
	FTerrainTileInstanceData(int Index = 0, FTerrainShapeMergeResult MergeData = FTerrainShapeMergeResult()) : ShapeIndex(Index), MergeResult(MergeData)
	{}
};

/* /\ ========================= /\ *\
|  /\ FTerrainTileInstanceData  /\  |
\* /\ ========================= /\ */


/* \/ ====================== \/ *\
|  \/ FTerrainTileSpawnData  \/  |
\* \/ ====================== \/ */

/**
 * Information needed to spawn a terrain tile.
 */
USTRUCT(BlueprintType)
struct PROCEDUALTERRAINTOOL_API FTerrainTileSpawnData
{
	GENERATED_BODY()

	//The data of this tile.
	UPROPERTY(EditAnywhere, Meta = (Category = "Tile Data"))
	UTerrainTileData* TileData = nullptr;

	//How likely this tile is to spawn.
	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0", Category = "Tile Data"))
	float SpawnWeight = 1;

	/**
	 * Initializes a FTerrainTileSpawnData.
	 */
	FTerrainTileSpawnData()
	{

	}

	bool operator==(const FTerrainTileSpawnData& OtherData) const
	{
		return TileData == OtherData.TileData && SpawnWeight == OtherData.SpawnWeight;
	}
};

/* /\ ====================== /\ *\
|  /\ FTerrainTileSpawnData  /\  |
\* /\ ====================== /\ */



/* \/ ================== \/ *\
|  \/ ATerrainGenerator  \/  |
\* \/ ================== \/ */

/**
 * A tool for generating terrain. Takes in a set of tiles and can connect them together to form terrain.
 */
UCLASS()
class PROCEDUALTERRAINTOOL_API ATerrainGenerator : public AActor
{
	GENERATED_BODY()

public:
	/**
	 * Sets up the root component.
	 */
	ATerrainGenerator();

	///**
	// * Delete me.
	// */
	//UFUNCTION(CallInEditor, BlueprintCallable, Meta = (Category = "Terrain Generator"))
	//void Test();

	/**
	 * Begins the terrain generation process.
	 */
	UFUNCTION(CallInEditor, BlueprintCallable, Meta = (Category = "Terrain Generator"))
	void BeginGeneration();

	/**
	 * Stops the generation before the terrain is finished generating.
	 */
	UFUNCTION(CallInEditor, BlueprintCallable, Meta = (Category = "Terrain Generator"))
	void EndGeneration();

	/**
	 * Resets the generation process and deletes all actors already spawned.
	 */
	UFUNCTION(CallInEditor, BlueprintCallable, Meta = (Category = "Terrain Generator"))
	void Reset();


	//The set of tiles that this will use when generating terrain.
	UPROPERTY(EditAnywhere, Meta = (Category = "Terrain Generator"))
	TArray<FTerrainTileSpawnData> SpawnableTiles;

	//The method and shape in which the terrain will be generated.
	UPROPERTY(EditAnywhere, Instanced, Meta = (Category = "Terrain Generator"))
	UProcedualCollapseMode* GenerationMode = nullptr;

	//The method and shape in which the terrain will be generated.
	UPROPERTY(EditAnywhere, Meta = (Category = "Terrain Generator"))
	bool bGenerateUntilSuccessful = false;

	//How many steps into the future to look when generating terrain. Higher numbers slow generation but reduce risk of generation failure.
	UPROPERTY(EditAnywhere, AdvancedDisplay, Meta = (ClampMin = "0", ClampMax = "4", Category = "Terrain Generator"))
	int PredictionDepth = 0;

	//Whether or not to use the manually entered seed when generating terrain.
	UPROPERTY(EditAnywhere, AdvancedDisplay, Meta = (Category = "Terrain Generator", EditCondition = "!bGenerateUntilSuccessful"))
	bool bUseManualSeed = false;

	//Whether or not to use the manually entered seed when generating terrain.
	UPROPERTY(EditAnywhere, AdvancedDisplay, Meta = (Category = "Terrain Generator", EditCondition = "!bGenerateUntilSuccessful && bUseManualSeed"))
	FRandomStream Seed = FRandomStream(0);

private:

	/**
	 * Spawns any new tiles created by the worker and shuts down worker if complete.
	 */
	UFUNCTION(Meta = (Category = "TerrainGenerator"))
	void RefreshTiles();

	/**
	 * Spawns a single tile.
	 * 
	 * @param TileData - The data needed to know where and what to spawn.
	 */
	UFUNCTION()
	void SpawnTile(FTerrainTileInstanceData TileData);

	//An asynchronous worker used to collapse superpositions and generate terrain without freezing the editor.
	class FTerrainGenerationWorker* TerrainGenerationWorker;

	//The current shape of the terrain.
	UPROPERTY()
	FTerrainShape TerrainShape = FTerrainShape();

	//The timer that periodically updates the tiles to match the worker.
	UPROPERTY()
	FTimerHandle TileRefreshTimerHandle;

	//The number of tiles currently spawned.
	UPROPERTY()
	int NumberOfTilesSpawned = 0;

	//All of the actors spawned by this.
	UPROPERTY()
	TSet<AActor*> TileActors = TSet<AActor*>();
};

/* /\ ================== /\ *\
|  /\ ATerrainGenerator  /\  |
\* /\ ================== /\ */


/* \/ ========================= \/ *\
|  \/ FTerrainGenerationWorker  \/  |
\* \/ ========================= \/ */

/**
 * Asynchronously generates terrain out of a given set of tiles.
 */
class FTerrainGenerationWorker : public FRunnable
{
public:
	/**
	 * Gets the results of the superposition collapses.
	 * 
	 * @return The results of the superposition collapses.
	 */
	TArray<FTerrainTileInstanceData> GetTerrainTiles()
	{
		return TerrainTiles;
	}

	/**
	 * Gets the current shape of the terrain.
	 * 
	 * @return The current shape of the terrain.
	 */
	FTerrainShape GetTerrainShape()
	{
		return Shape;
	}

	/**
	 * Determines whether the terrain is finished generating.
	 *
	 * @return Whether or not the terrain is finished generating.
	 */
	bool IsTerrainFinishedGenerating();

	/**
	 * Creates a FTerrainGenerationWorker able to compute superposition collapses of the given tiles.
	 *
	 * @param UseableTiles - The tiles that will be used to generate the terrain.
	 * @param Mode - The method used for deciding which superposition to collapse next.
	 * @param PredictionDepth - How many iterations into the future to search for failed superpositions.
	 */
	FTerrainGenerationWorker(TArray<FTerrainTileSpawnData> Tiles, UProcedualCollapseMode* Mode, FRandomStream& RandomStream, const int PredictionDepth = 0, FTerrainShape CurrentTerrainShape = FTerrainShape());

	/**
	 * Destructs this and handles thread deletion.
	 */
	virtual ~FTerrainGenerationWorker();


	// \/ Begin FRunnable interface. \/ //

	/**
	 * Begins the process of terrain generation.
	 * 
	 * @return true
	 */
	virtual bool Init();

	/**
	 * Repeatedly collapses superpositions in order to generate the terrain.
	 * 
	 * @return 0
	 */
	virtual uint32 Run();

	/**
	 * Stops the generation process regardless of completion.
	 */
	virtual void Stop();

	// /\  End FRunnable interface.  /\ //

private:
	//Thread to run the worker FRunnable on 
	FRunnableThread* Thread;
	//Whether or not the task has been stopped prematurely.
	std::atomic_bool bStopped;


	//The method used for deciding which superposition to collapse next.
	UProcedualCollapseMode* CollapseMode;
	//The random stream used to generate the terrain.
	FRandomStream& RandomStream;
	//How many iterations into the future to search for failed superpositions.
	int CollapsePredictionDepth;
	//The tiles that will be used to generate the terrain.
	TArray<FTerrainTileSpawnData> UseableTiles;
	//The shapes of the tiles.
	TArray<FTerrainShape> TileShapes;
	//The shapes of the tiles.
	int MaxTileVertices;
	//The superposition of an empty socket.
	TArray<TArray<bool>> BaseSuperPositions;


	//Will be written to as superpositions are collapsed.
	TArray<FTerrainTileInstanceData> TerrainTiles;
	//The current shape of the terrain.
	FTerrainShape Shape;
	//Whether or not a given tile can connect to a given socket. SuperPositions[Socket to connect to][Tile to add][Socket on tile to connect to].
	TArray<TArray<TArray<bool>>> SuperPositions = TArray<TArray<TArray<bool>>>();
	//Whether or not the task is complete.
	bool bCompleated;

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
	 * @param NewShape - The shape to query.
	 * @param MergeResult - The result of the merge that most recently happened.
	 * @param SeachDeapth - How many iterations into the future to search.
	 */
	bool HasNewCollapseableSuperPositions(FTerrainShape NewShape, FTerrainShapeMergeResult MergeResult, int SearchDepth = 0) const;

	/**
	 * Refreshes superpositions after a given change in vertices.
	 *
	 * @param ShapeVertexGrowth = The number of new vertices in the shape.
	 * @param ShapeVertexShrinkage = The number of old vertices removed from the shape.
	 * @param ShapeVertexOffset = The shift in vertex index.
	 */
	void RefreshSuperPositions(int ShapeVertexGrowth, int ShapeVertexShrinkage = 0, int ShapeVertexOffset = 0);
};

/* /\ ========================= /\ *\
|  /\ FTerrainGenerationWorker  /\  |
\* /\ ========================= /\ */