// Fill out your copyright notice in the Description page of Project Settings.

#include "TerrainGenerator.h"

#include "ProcedualCollapseMode.h"
#include "DrawDebugHelpers.h"
#include "Async/AsyncWork.h"
#include "Async/Async.h"
#include "TerrainTileData.h"

DEFINE_LOG_CATEGORY(LogTerrainTool);

/* \/ ================== \/ *\
|  \/ ATerrainGenerator  \/  |
\* \/ ================== \/ */

/**
 * Sets up the root component.
 */
ATerrainGenerator::ATerrainGenerator()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent->SetMobility(EComponentMobility::Static);
}

/**
 * Temporary function that can be used to debug the terrain generator.
 */
void ATerrainGenerator::Test()
{
	FlushPersistentDebugLines(GetWorld());
	for (int i =0; i < TerrainShape.Num(); i++)
	{
		DrawDebugDirectionalArrow(GetWorld(), FVector(TerrainShape.Vertices[i].Location, FMath::Lerp(-75, 100, i / (float)(TerrainShape.Num() -1))), FVector(TerrainShape.Vertices[(i + 1) % TerrainShape.Num()].Location, FMath::Lerp(-75,100, ((i + 1) % TerrainShape.Num())/(float)(TerrainShape.Num()-1))), 200, FColor::MakeRandomColor(), true, 0, 0U, 5);
	}
}

/**
 * Begins the terrain generation process.
 */
void ATerrainGenerator::BeginGeneration()
{
	if (IsValid(GenerationMode))
	{
		for (FTerrainTileSpawnData EachSpawnableTile : SpawnableTiles)
		{
			if (!IsValid(EachSpawnableTile.TileData))
			{
				UE_LOG(LogTerrainTool, Error, TEXT("Not all spawnable tiles are valid"));
				return;
			}
		}

		if (FPlatformProcess::SupportsMultithreading())
		{
			if ((bGenerateUntilSuccessful || !bUseManualSeed) && Seed.GetCurrentSeed() == Seed.GetInitialSeed())
			{
				Seed.GenerateNewSeed();
			}

			EndGeneration();
			TerrainGenerationWorker = new FTerrainGenerationWorker(SpawnableTiles, GenerationMode, Seed, PredictionDepth, TerrainShape);

			GetWorld()->GetTimerManager().SetTimer(TileRefreshTimerHandle, this, &ATerrainGenerator::RefreshTiles, .1, true);

			GenerationMode->DrawGenerationBounds();
		}
		else
		{
			UE_LOG(LogTerrainTool, Error, TEXT("Platform does not support multi threading"));
		}
	}
	else
	{
		UE_LOG(LogTerrainTool, Error, TEXT("Select a generation mode"));
	}
}

/**
 * Stops the generation before the terrain is finished generating.
 */
void ATerrainGenerator::EndGeneration()
{
	FlushPersistentDebugLines(GetWorld());

	//Terrain generation worker cleanup
	if (TerrainGenerationWorker)
	{
		if (!TerrainGenerationWorker->IsTerrainFinishedGenerating())
		{
			TerrainGenerationWorker->Stop();
		}

		delete TerrainGenerationWorker;
		TerrainGenerationWorker = NULL;
	}

	NumberOfTilesSpawned = 0;
}

/**
 * Resets the generation process and deletes all actors already spawned.
 */
void ATerrainGenerator::Reset()
{
	EndGeneration();

	for (AActor* EachTerrainActor : TileActors)
	{
		EachTerrainActor->Destroy();
	}
	TileActors.Empty();

	TerrainShape = FTerrainShape();

	Seed.Reset();

	GenerationMode->ErrorLocation = FVector::ZeroVector;
}

/**
 * Spawns any new tiles created by the worker and shuts down worker if complete.
 */
void ATerrainGenerator::RefreshTiles()
{
	if (TerrainGenerationWorker)
	{
		for (NumberOfTilesSpawned; NumberOfTilesSpawned < TerrainGenerationWorker->GetTerrainTiles().Num(); NumberOfTilesSpawned++)
		{
			SpawnTile(TerrainGenerationWorker->GetTerrainTiles()[NumberOfTilesSpawned]);
		}

		TerrainShape = TerrainGenerationWorker->GetTerrainShape();
		
		if (TerrainGenerationWorker->IsTerrainFinishedGenerating())
		{
			TerrainGenerationWorker->Stop();
			delete TerrainGenerationWorker;
			TerrainGenerationWorker = NULL;
			GetWorldTimerManager().ClearTimer(TileRefreshTimerHandle);
			FlushPersistentDebugLines(GetWorld());

			if (!GenerationMode->ErrorLocation.IsZero())
			{
				if (bGenerateUntilSuccessful)
				{
					Reset();
					BeginGeneration();
				}
				else
				{
					DrawDebugPoint(GetWorld(), GenerationMode->ErrorLocation, 50, FColor::Red, true);
				}
			}
		}
	}
	else
	{
		FlushPersistentDebugLines(GetWorld());
		GetWorldTimerManager().ClearTimer(TileRefreshTimerHandle);
	}
}

/**
 * Spawns a single tile.
 *
 * @param TileData - The data needed to know where and what to spawn.
 */
void ATerrainGenerator::SpawnTile(FTerrainTileInstanceData TileData)
{
	if (IsValid(SpawnableTiles[TileData.ShapeIndex].TileData->ActorClass.Get()))
	{
		//Calculate Actor Rotation
		float A;
		float B;
		float C;
		float D;
		TileData.MergeResult.Transform.GetMatrix().GetMatrix(A, B, C, D);
		if (FMath::IsNearlyZero(A))
		{
			A = SMALL_NUMBER;
		}

		float Angle = FMath::Atan(B / A);
		if (A < 0)
		{
			Angle = PI + Angle;
		}

		//Spawn Actor
		FTransform Transform = FTransform(FQuat(FVector(0, 0, 1), Angle), FVector(TileData.MergeResult.Transform.GetTranslation(), 0));
		AActor* NewTerrainActor = GetWorld()->SpawnActor<AActor>(SpawnableTiles[TileData.ShapeIndex].TileData->ActorClass.Get(), Transform);
		NewTerrainActor->SetActorTransform(Transform);
		NewTerrainActor->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
		TileActors.Add(NewTerrainActor);
	}
}

/* /\ ================== /\ *\
|  /\ ATerrainGenerator  /\  |
\* /\ ================== /\ */



/* \/ ========================= \/ *\
|  \/ FTerrainGenerationWorker  \/  |
\* \/ ========================= \/ */

/**
 * Determines whether the terrain is finished generating.
 *
 * @return Whether or not the terrain is finished generating.
 */
bool FTerrainGenerationWorker::IsTerrainFinishedGenerating()
{
	return bCompleated;
}

/**
 * Creates a FTerrainGenerationWorker able to compute superposition collapses of the given tiles.
 *
 * @param OutTiles - Will be written to as superpositions are collapsed.
 * @param UseableTiles - The tiles that will be used to generate the terrain.
 * @param Mode - The method used for deciding which superposition to collapse next.
 * @param PredictionDepth - How many iterations into the future to search for failed superpositions.
 */
FTerrainGenerationWorker::FTerrainGenerationWorker(TArray<FTerrainTileSpawnData> Tiles, UProcedualCollapseMode* Mode, FRandomStream& GenerationStream, const int PredictionDepth, FTerrainShape CurrentTerrainShape) :
	bStopped(false),
	CollapseMode(Mode),
	CollapsePredictionDepth(PredictionDepth),
	UseableTiles(Tiles),
	RandomStream(GenerationStream),
	Shape(CurrentTerrainShape),
	bCompleated(false)
{ 
	//Create thread.
	Thread = FRunnableThread::Create(this, TEXT("FTerrainGenerationWorker"), 0, TPri_BelowNormal);

	//Initialize output
	TerrainTiles = TArray<FTerrainTileInstanceData>();

	//Set up generation constants.
	TileShapes = TArray<FTerrainShape>();
	BaseSuperPositions = TArray<TArray<bool>>();
	MaxTileVertices = 0;

	for (FTerrainTileSpawnData EachUseableTile : UseableTiles)
	{
		TileShapes.Emplace(FTerrainShape(EachUseableTile.TileData->Verticies, EachUseableTile.TileData->FaceTypes));
		MaxTileVertices = FMath::Max(EachUseableTile.TileData->Verticies.Num(), MaxTileVertices);

		TArray<bool> Faces = TArray<bool>();
		Faces.Init(true, EachUseableTile.TileData->Verticies.Num());
		BaseSuperPositions.Emplace(Faces);
	}

	SuperPositions = TArray<TArray<TArray<bool>>>();
	if (Shape.Num() == 0)
	{
		SuperPositions.Emplace(BaseSuperPositions);
	}
	else
	{
		RefreshSuperPositions(Shape.Num());
	}
	return;
}

/**
 * Destructs this and handles thread deletion.
 */
FTerrainGenerationWorker::~FTerrainGenerationWorker()
{ 
	delete Thread;
	Thread = NULL; 
}

/**
 * Begins the process of terrain generation.
 *
 * @return true
 */
bool FTerrainGenerationWorker::Init()
{
	bCompleated = false;

	UE_LOG(LogTerrainTool, Log, TEXT("--- Super Position Collapse Started ---"));

	return true;
}

/**
 * Repeatedly collapses superpositions in order to generate the terrain.
 *
 * @return 0
 */
uint32 FTerrainGenerationWorker::Run()
{ 
	//Initial wait before starting 
	FPlatformProcess::Sleep(0.03);	

	while (!(bCompleated || bStopped))
	{
		if (!SuperPositions.IsEmpty())
		{
			FIntVector CollapseResult;
			bCompleated = !CollapseMode->GetSuperPositionsToCollapse(CollapseResult, Shape, SuperPositions, UseableTiles, RandomStream);
			bCompleated = !CollapseSuperPosition(CollapseResult) || bCompleated;
		}
		else
		{
			FPlatformProcess::Sleep(0.1);
		}
	}


	UE_LOG(LogTerrainTool, Log, TEXT("---- Super Position Collapse Ended ----"));

	return 0;
}

/**
 * Stops the generation process regardless of completion.
 */
void FTerrainGenerationWorker::Stop()
{ 
	bStopped = true;
}

/**
 * Attempts to collapse a super position at a given index.
 *
 * @param Index - X = Socket to connect to, Y = Tile to add, Z = Socket on tile to connect to.
 * @return Whether or not the collapse was successful.
 */
bool FTerrainGenerationWorker::CollapseSuperPosition(FIntVector Index)
{
	int SocketIndex = Index.X;
	int ShapeIndex = Index.Y;
	int FaceIndex = Index.Z;

	if (SuperPositions.IsValidIndex(SocketIndex) && SuperPositions[SocketIndex].IsValidIndex(ShapeIndex) && SuperPositions[SocketIndex][ShapeIndex].IsValidIndex(FaceIndex) && SuperPositions[SocketIndex][ShapeIndex][FaceIndex])
	{
		FTerrainShape NewShape;
		FTerrainShapeMergeResult MergeResult;

		if (ensureAlwaysMsgf(Shape.MergeShape(NewShape, MergeResult, SocketIndex, TileShapes[ShapeIndex], FaceIndex), TEXT("Super Position Array False at %i, %i, %i"), SocketIndex, ShapeIndex, FaceIndex))
		{
			TerrainTiles.Emplace(FTerrainTileInstanceData(ShapeIndex, MergeResult));
			Shape = NewShape;
			RefreshSuperPositions(MergeResult.Growth, MergeResult.Shrinkage, MergeResult.Offset);

			return true;
		}
		CollapseMode->ErrorLocation = CollapseMode->TerrainTransform.TransformPosition(FVector(((Shape.Vertices[SocketIndex].Location + Shape.Vertices[(SocketIndex + 1) % Shape.Num()].Location) / 2), 0));
	}
	UE_LOG(LogTerrainTool, Error, TEXT("Collapse Failed"));
	return false;
}

/**
 * Whether or not there is an available super position to collapse after the given merge.
 *
 * @param NewShape - The shape to query.
 * @param MergeResult - The result of the merge that most recently happened.
 * @param SeachDeapth - How many iterations into the future to search.
 */
bool FTerrainGenerationWorker::HasNewCollapseableSuperPositions(FTerrainShape NewShape, FTerrainShapeMergeResult MergeResult, int SearchDepth) const
{
	for (int Offset = 0; Offset < FMath::Min(MergeResult.Growth + 2, NewShape.Num()); Offset++)
	{
		int CollapseSocketIndex = UPTTMath::Mod(NewShape.Num() - 1 - MergeResult.Growth + Offset, NewShape.Num());
		for (int CollapseShapeIndex = 0; CollapseShapeIndex < BaseSuperPositions.Num(); CollapseShapeIndex++)
		{
			for (int CollapseFaceIndex = 0; CollapseFaceIndex < BaseSuperPositions[CollapseShapeIndex].Num(); CollapseFaceIndex++)
			{
				if (SearchDepth == 0)
				{
					if (NewShape.MergeShape(CollapseSocketIndex, TileShapes[CollapseShapeIndex], CollapseFaceIndex))
					{
						goto NextSocket;
					}
				}
				else
				{
					FTerrainShape CollapsedShape;
					FTerrainShapeMergeResult CollapsedShapeMergeResult;

					if (NewShape.MergeShape(CollapsedShape, CollapsedShapeMergeResult, CollapseSocketIndex, TileShapes[CollapseShapeIndex], CollapseFaceIndex, false) && HasNewCollapseableSuperPositions(CollapsedShape, CollapsedShapeMergeResult, SearchDepth - 1))
					{
						goto NextSocket;
					}
					
				}
			}
		}
		return false;


	NextSocket:
		;
	}

	return true;
}

/**
 * Refreshes superpositions after a given change in vertices.
 * 
 * @param ShapeVertexGrowth = The number of new vertices in the shape.
 * @param ShapeVertexShrinkage = The number of old vertices removed from the shape.
 * @param ShapeVertexOffset = The shift in vertex index.
 */
void FTerrainGenerationWorker::RefreshSuperPositions(int ShapeVertexGrowth, int ShapeVertexShrinkage, int ShapeVertexOffset)
{
	//Propagate New Super Positions
	TArray<TArray<TArray<bool>>> NewSuperPositions = TArray<TArray<TArray<bool>>>();
	NewSuperPositions.SetNum(Shape.Num());

	for (int SuperPositionIndex = 0; SuperPositionIndex < NewSuperPositions.Num(); SuperPositionIndex++)
	{
		if (SuperPositionIndex < SuperPositions.Num() - ShapeVertexShrinkage)
		{
			NewSuperPositions[SuperPositionIndex] = SuperPositions[UPTTMath::Mod(SuperPositionIndex - ShapeVertexOffset, SuperPositions.Num())];
		}
		else
		{
			NewSuperPositions[SuperPositionIndex] = BaseSuperPositions;
		}
	}

	int NumberOfPossibleCollapses = 0;
	FIntVector CollapseIndex = FIntVector();

	for (int Offset = 0; Offset < FMath::Min(ShapeVertexGrowth + 2 * MaxTileVertices, Shape.Num()); Offset++)
	{
		int CollapseSocketIndex = UPTTMath::Mod(Shape.Num() - MaxTileVertices - ShapeVertexGrowth + Offset, Shape.Num());
		for (int CollapseShapeIndex = 0; CollapseShapeIndex < BaseSuperPositions.Num(); CollapseShapeIndex++)
		{
			for (int CollapseFaceIndex = 0; CollapseFaceIndex < BaseSuperPositions[CollapseShapeIndex].Num(); CollapseFaceIndex++)
			{
				FTerrainShape CollapsedShape;
				FTerrainShapeMergeResult CollapsedShapeMergeResult;
				if (Shape.MergeShape(CollapsedShape, CollapsedShapeMergeResult, CollapseSocketIndex, TileShapes[CollapseShapeIndex], CollapseFaceIndex))
				{
					bool bCanCollapse = HasNewCollapseableSuperPositions(CollapsedShape, CollapsedShapeMergeResult, CollapsePredictionDepth);
					NewSuperPositions[CollapseSocketIndex][CollapseShapeIndex][CollapseFaceIndex] = bCanCollapse;
					if (bCanCollapse)
					{
						NumberOfPossibleCollapses++;
						CollapseIndex = FIntVector(CollapseSocketIndex, CollapseShapeIndex, CollapseFaceIndex);
					}
				}
				else
				{
					NewSuperPositions[CollapseSocketIndex][CollapseShapeIndex][CollapseFaceIndex] = false;
				}
			}
		}
	}

	SuperPositions = NewSuperPositions;

	if (NumberOfPossibleCollapses == 1)
	{
		CollapseSuperPosition(CollapseIndex);
	}
}

/* /\ ========================= /\ *\
|  /\ FTerrainGenerationWorker  /\  |
\* /\ ========================= /\ */