// Fill out your copyright notice in the Description page of Project Settings.

#include "TerrainHandler.h"

#include "ProcedualCollapseMode.h"
#include "DrawDebugHelpers.h"
#include "Async/AsyncWork.h"
#include "Async/Async.h"
#include "TerrainTileData.h"

DEFINE_LOG_CATEGORY(LogTerrainTool);

/* \/ ================ \/ *\
|  \/ ATerrainHandler  \/  |
\* \/ ================ \/ */

ATerrainHandler::ATerrainHandler()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent->SetMobility(EComponentMobility::Static);
}

void ATerrainHandler::ResetTerrain()
{
	for (AActor* EachTerrainActor : TileActors)
	{
		EachTerrainActor->Destroy();
	}
	TileActors.Empty();
}

void ATerrainHandler::DetachTerrain()
{
	for (AActor* EachTerrainActor : TileActors)
	{
		EachTerrainActor->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	}
	TileActors.Empty();
	ResetTerrain();
}

void ATerrainHandler::CollapseSuperPosition()
{
	if (FPlatformProcess::SupportsMultithreading())
	{
		//Terrain generation worker setup
		if (TerrainGenerationWorker)
		{
			if (!TerrainGenerationWorker->IsTerrainFinishedGenerating())
			{
				TerrainGenerationWorker->Shutdown();
			}

			if (!TerrainGenerationWorker->MatchData(SpawnableTiles, CollapseMode, CollapsePredictionDepth))
			{
				delete TerrainGenerationWorker;
				UE_LOG(LogTerrainTool, Warning, TEXT("Spawnable tiles do not match current tile set. Reseting terrain..."))
				TerrainGenerationWorker = new FTerrainGenerationWorker(SpawnableTiles, CollapseMode, CollapsePredictionDepth);
				ResetTerrain();
			}
		}
		else
		{
			TerrainGenerationWorker = new FTerrainGenerationWorker(SpawnableTiles, CollapseMode, CollapsePredictionDepth);
		}
		


		GetWorld()->GetTimerManager().SetTimer(TileRefreshTimerHandle, this, &ATerrainHandler::RefreshTiles, 1, true);
	}
	else
	{
		UE_LOG(LogTerrainTool, Error, TEXT("Platform does not support multi threading"));
	}
}

void ATerrainHandler::SpawnTile(int ShapeIndex, FTerrainShapeMergeResult MergeResult)
{
	if (IsValid(CurrentSpawnableTiles[ShapeIndex].SpriteData->ActorClass.Get()))
	{
		//Calculate Actor Rotation
		float A;
		float B;
		float C;
		float D;
		MergeResult.Transform.GetMatrix().GetMatrix(A, B, C, D);
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
		FTransform Transform = FTransform(FQuat(FVector(0, 0, 1), Angle), FVector(MergeResult.Transform.GetTranslation(), 0));
		AActor* NewTerrainActor = GetWorld()->SpawnActor<AActor>(CurrentSpawnableTiles[ShapeIndex].SpriteData->ActorClass.Get(), Transform);
		NewTerrainActor->SetActorTransform(Transform);
		NewTerrainActor->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
		TerrainActors.Add(NewTerrainActor);
	}
}

/* /\ ================ /\ *\
|  /\ ATerrainHandler  /\  |
\* /\ ================ /\ */



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
 * Whether or not this matches the given data. Will mutate this if possible to match the given data.
 *
 * @param UseableTiles - The tiles that will be used to generate the terrain.
 * @param Mode - The method used for deciding which superposition to collapse next.
 * @param PredictionDepth - How many iterations into the future to search for failed superpositions.
 */
bool FTerrainGenerationWorker::MatchData(TArray<FTerrainTileData> Tiles, UProcedualCollapseMode* Mode, const int PredictionDepth = 0)
{
	if (Tiles != UseableTiles)
	{
		return false;
	}

	CollapseMode = Mode;
	CollapsePredictionDepth = PredictionDepth;
	return true;
}

/**
 * Blocking function that stops the terrain generation and waits for completion.
 */
void FTerrainGenerationWorker::Shutdown()
{
	Stop();
	Thread->WaitForCompletion();
}

/**
 * Creates a FTerrainGenerationWorker able to compute superposition collapses of the given tiles.
 *
 * @param OutTiles - Will be written to as superpositions are collapsed.
 * @param UseableTiles - The tiles that will be used to generate the terrain.
 * @param Mode - The method used for deciding which superposition to collapse next.
 * @param PredictionDepth - How many iterations into the future to search for failed superpositions.
 */
FTerrainGenerationWorker::FTerrainGenerationWorker(TArray<FTerrainTileData> Tiles, UProcedualCollapseMode* Mode, const int PredictionDepth = 0) : 
	UseableTiles(Tiles), 
	CollapseMode(Mode), 
	CollapsePredictionDepth(PredictionDepth), 
	bCompleated(false)
{ 
	//Create thread.
	Thread = FRunnableThread::Create(this, TEXT("FTerrainGenerationWorker"), 0, TPri_BelowNormal);

	//Set up generation constants.
	TileShapes.Empty();
	BaseSuperPositions.Empty();

	for (FTerrainTileData EachUseableTile : UseableTiles)
	{
		TileShapes.Emplace(FTerrainShape(EachUseableTile.TileData->Verticies, EachUseableTile.TileData->FaceIndices));

		TArray<bool> Faces = TArray<bool>();
		Faces.Init(true, EachUseableTile.TileData->Verticies.Num());
		BaseSuperPositions.Emplace(Faces);
	}
}

/**
 * Destructs this and handles thread deletion.
 */
FTerrainGenerationWorker::~FTerrainGenerationWorker()
{ 
	delete Thread;
	Thread = NULL; 
}

bool FTerrainGenerationWorker::Init()
{
	bCompleated = false;

	UE_LOG(LogTerrainTool, Log, TEXT("*******************************"));
	UE_LOG(LogTerrainTool, Log, TEXT("Super Position Collapse Started"));
	UE_LOG(LogTerrainTool, Log, TEXT("*******************************"));

	return true;
}

uint32 FTerrainGenerationWorker::Run()
{ 
	//Initial wait before starting 
	FPlatformProcess::Sleep(0.03);	


	while (!bCompleated)
	{
		FIntVector CollapseResult;
		if (!CollapseMode->GetSuperPositionsToCollapse(CollapseResult, Shape, SuperPositions, UseableTiles))
		{
			Stop();
		}
		UE_LOG(LogTerrainTool, Log, TEXT("Collapse %s"), *CollapseResult.ToString());
		CollapseSuperPosition(CollapseResult);

		//Prevent thread from using too many resources.
		FPlatformProcess::Sleep(0.01);
	}
	return 0;
}

void FTerrainGenerationWorker::Stop()
{ 
	bCompleated = true;

	UE_LOG(LogTerrainTool, Log, TEXT("*******************************"));
	UE_LOG(LogTerrainTool, Log, TEXT(" Super Position Collapse Ended "));
	UE_LOG(LogTerrainTool, Log, TEXT("*******************************"));
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

		if (ensureAlwaysMsgf(Shape.MergeShape(NewShape, MergeResult, SocketIndex, TileShapes[ShapeIndex], FaceIndex), TEXT("Super Position Array False")))
		{


			// \/ Refresh Super Positions \/ //

			//Propagate New Super Positions
			TArray<TArray<TArray<bool>>> NewSuperPositions = TArray<TArray<TArray<bool>>>();
			NewSuperPositions.SetNum(NewShape.Num());
			//FString Debug1 = FString();

			for (int SuperPositionIndex = 0; SuperPositionIndex < NewSuperPositions.Num(); SuperPositionIndex++)
			{
				//Debug1 += FString::FromInt(Index) + "<-";
				if (SuperPositionIndex < SuperPositions.Num() - MergeResult.Shrinkage)
				{
					//Debug1 += FString::FromInt(UPTTMath::Mod(Index - MergeResult.Offset, SuperPositions.Num())) + ", ";
					NewSuperPositions[SuperPositionIndex] = SuperPositions[UPTTMath::Mod(SuperPositionIndex - MergeResult.Offset, SuperPositions.Num())];
				}
				else
				{
					//Debug1 += "B, ";
					NewSuperPositions[SuperPositionIndex] = BaseSuperPositions;
				}
			}
			SuperPositions = NewSuperPositions;
			Shape = NewShape;

			//UE_LOG(LogTerrainTool, Log, TEXT("%s"), *Debug1);

			//UE_LOG(LogTerrainTool, Log, TEXT("-------------"));
			int NumberOfPossibleCollapses = 0;
			FIntVector CollapseIndex = FIntVector();
			for (int Offset = 0; Offset < MergeResult.Growth + 2; Offset++)
			{
				//FString Debug = FString();
				//Debug += FString::FromInt(UPTTMath::Mod(CurrentShape.Num() - 1 - MergeResult.Growth + Offset, CurrentShape.Num())) + "\t|  ";
				int CollapseSocketIndex = UPTTMath::Mod(Shape.Num() - 1 - MergeResult.Growth + Offset, Shape.Num());
				for (int CollapseShapeIndex = 0; CollapseShapeIndex < BaseSuperPositions.Num(); CollapseShapeIndex++)
				{
					for (int CollapseFaceIndex = 0; CollapseFaceIndex < BaseSuperPositions[CollapseShapeIndex].Num(); CollapseFaceIndex++)
					{
						if (/*SuperPositions[CollapseSocketIndex][CollapseShapeIndex][CollapseFaceIndex]*/true)
						{
							FTerrainShape CollapsedShape;
							FTerrainShapeMergeResult CollapsedShapeMergeResult;
							if (Shape.MergeShape(CollapsedShape, CollapsedShapeMergeResult, CollapseSocketIndex, TileShapes[CollapseShapeIndex], CollapseFaceIndex))
							{
								//Debug += "C";
								bool bCanCollapse = HasNewCollapseableSuperPositions(CollapsedShape, CollapsedShapeMergeResult, CollapsePredictionDepth);
								SuperPositions[CollapseSocketIndex][CollapseShapeIndex][CollapseFaceIndex] = bCanCollapse;
								if (bCanCollapse)
								{
									//Debug += "T";
									NumberOfPossibleCollapses++;
									CollapseIndex = FIntVector(CollapseSocketIndex, CollapseShapeIndex, CollapseFaceIndex);
								}
								else
								{
									//Debug += "F";
								}
							}
							else
							{
								//Debug += " F";
								SuperPositions[CollapseSocketIndex][CollapseShapeIndex][CollapseFaceIndex] = false;
							}
						}
						else
						{
							//Debug += "  ";
						}
						//Debug += ", ";
					}
					//Debug += "  |  ";
				}
				//UE_LOG(LogTerrainTool, Log, TEXT("%s"), *Debug);
			}

			if (NumberOfPossibleCollapses == 1)
			{
				CollapseSuperPosition(CollapseIndex);
			}

			// /\ Refresh Super Positions /\ //
			return true;
		}
	}
	UE_LOG(LogTerrainTool, Error, TEXT("Collapse Failed"));
	return false;
}

/**
 * Whether or not there is an available super position to collapse after the given merge.
 *
 * @param Shape - The shape to query.
 * @param MergeResult - The result of the merge that most recently happened.
 * @param SeachDeapth - How many iterations into the future to search.
 */
bool FTerrainGenerationWorker::HasNewCollapseableSuperPositions(FTerrainShape Shape, FTerrainShapeMergeResult MergeResult, int SearchDepth) const
{
	for (int Offset = 0; Offset < MergeResult.Growth + 2; Offset++)
	{
		int CollapseSocketIndex = UPTTMath::Mod(Shape.Num() - 1 - MergeResult.Growth + Offset, Shape.Num());
		for (int CollapseShapeIndex = 0; CollapseShapeIndex < BaseSuperPositions.Num(); CollapseShapeIndex++)
		{
			for (int CollapseFaceIndex = 0; CollapseFaceIndex < BaseSuperPositions[CollapseShapeIndex].Num(); CollapseFaceIndex++)
			{
				FTerrainShape CollapsedShape;
				FTerrainShapeMergeResult CollapsedShapeMergeResult;
				if (Shape.MergeShape(CollapsedShape, CollapsedShapeMergeResult, CollapseSocketIndex, SpriteShapes[CollapseShapeIndex], CollapseFaceIndex))
				{
					if (SearchDepth == 0 || HasNewCollapseableSuperPositions(CollapsedShape, CollapsedShapeMergeResult, SearchDepth - 1))
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

/* /\ ========================= /\ *\
|  /\ FTerrainGenerationWorker  /\  |
\* /\ ========================= /\ */