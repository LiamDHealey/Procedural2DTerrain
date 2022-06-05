// Fill out your copyright notice in the Description page of Project Settings.

#include "TerrainHandler.h"

#include "ProcedualCollapseMode.h"
#include "DrawDebugHelpers.h"
#include "Async/AsyncWork.h"
#include "Async/Async.h"

#include "TerrainSpriteData.h"

DEFINE_LOG_CATEGORY(LogTerrainTool);

ATerrainHandler::ATerrainHandler()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent->SetMobility(EComponentMobility::Static);
}

void ATerrainHandler::LogTest()
{
	UE_LOG(LogTemp, Warning, TEXT("LogTest thing"));
	//FlushPersistentDebugLines(GetWorld());
	//for (int i = 0; i < CurrentShape.Num(); i++)
	//{
	//	FVector Offset = FMath::RandPointInBox(FBox(FVector(-5, -5, -5), FVector(5, 5, 5)));
	//	FVector LineStart = GetActorTransform().TransformPosition(FVector(CurrentShape.Vertices[i], 0));
	//	FVector LineEnd = GetActorTransform().TransformPosition(FVector(CurrentShape.Vertices[(i + 1) % CurrentShape.Num()], 0));
	//	FColor Color = FColor::MakeRandomColor();

	//	DrawDebugLine(GetWorld(), LineStart, LineEnd, Color, true, 100, 0U, 5);

	//	Color = (Color.ReinterpretAsLinear() / 2).ToFColor(false);
	//	for (int j = 1; j <= i; j++)
	//	{
	//		if (j % 5 != 0)
	//		{
	//			DrawDebugLine(GetWorld(), (LineStart + LineEnd) / 2 + FVector(j * 5, 10, 0) + Offset, (LineStart + LineEnd) / 2 + FVector(j * 5, 10, 10) + Offset, Color, true, 100, 0U, 3);
	//		}
	//		else
	//		{
	//			DrawDebugLine(GetWorld(), (LineStart + LineEnd) / 2 + FVector((j-4) * 5, 10, 0) + Offset, (LineStart + LineEnd) / 2 + FVector((j-1) * 5, 10, 10) + Offset, Color, true, 100, 0U, 1.5);
	//		}
	//	}
	//}
}


void ATerrainHandler::RefreshTileSet()
{
	SpriteShapes.Empty();
	BaseSuperPositions.Empty();
	CurrentSpawnableTiles = SpawnableTiles;

	for (FTerrainTileData EachSpawnableTiles : SpawnableTiles)
	{
		SpriteShapes.Emplace(FTerrainShape(EachSpawnableTiles.SpriteData->Verticies, EachSpawnableTiles.SpriteData->FaceIndices));

		TArray<bool> Faces = TArray<bool>();
		Faces.Init(true, EachSpawnableTiles.SpriteData->Verticies.Num());
		BaseSuperPositions.Emplace(Faces);
	}

	ResetTerrain();
}

void ATerrainHandler::ResetTerrain()
{
	FlushPersistentDebugLines(GetWorld());
	CurrentShape = FTerrainShape();

	SuperPositions.SetNum(1);
	SuperPositions[0] = BaseSuperPositions;	

	for (AActor* EachTerrainActor : TerrainActors)
	{
		EachTerrainActor->Destroy();
	}
	TerrainActors.Empty();
}

void ATerrainHandler::DetachTerrain()
{
	for (AActor* EachTerrainActor : TerrainActors)
	{
		EachTerrainActor->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	}
	TerrainActors.Empty();
	ResetTerrain();
}

void ATerrainHandler::CollapseAllSuperPositions()
{
	FPlatformProcess::SupportsMultithreading()
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ATerrainHandler::LogTest, 1, true);
	//if (IsValid(CollapseMode))
	//{
	//	//bool bAnotherCollapseNesseary = true;
	//	//while (bAnotherCollapseNesseary)
	//	//{
	//	//	FIntVector CollapseIndex;
	//	//	bAnotherCollapseNesseary = CollapseMode->GetSuperPositionsToCollapse(CollapseIndex, CurrentShape, SuperPositions, CurrentSpawnableTiles, GetActorTransform());
	//	//	CollapseSuperPosition(CollapseIndex);
	//	//}
	//	if (FTerrainGenerationWorker::IsThreadFinished())
	//	{
	//		FTerrainGenerationWorker::InitilizeCollapseThread(CollapseMode, CurrentShape, SuperPositions, CurrentSpawnableTiles, GetActorTransform())->CollapseDelegate.BindUFunction(this, FName("CollapseSuperPosition"));
	//	}
	//	else
	//	{
	//		UE_LOG(LogTerrainTool, Error, TEXT("Generation still in progress"));
	//	}
	//}
	//else
	//{
	//	UE_LOG(LogTerrainTool, Error, TEXT("Select a Collapse Mode"));
	//}
}

void ATerrainHandler::CollapseSuperPosition(FIntVector Index)
{
	int SocketIndex = Index.X;
	int ShapeIndex = Index.Y;
	int FaceIndex = Index.Z;

	UE_LOG(LogTerrainTool, Log, TEXT("\\/------------------------ %i, %i, %i ------------------------\\/"), SocketIndex, ShapeIndex, FaceIndex);
	if (SuperPositions.IsValidIndex(SocketIndex) && SuperPositions[SocketIndex].IsValidIndex(ShapeIndex) && SuperPositions[SocketIndex][ShapeIndex].IsValidIndex(FaceIndex) && SuperPositions[SocketIndex][ShapeIndex][FaceIndex])
	{
		FTerrainShape NewShape;
		FTerrainShapeMergeResult MergeResult;

		if (ensureAlwaysMsgf(CurrentShape.MergeShape(NewShape, MergeResult, SocketIndex, SpriteShapes[ShapeIndex], FaceIndex), TEXT("Super Position Array False")))
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
			CurrentShape = NewShape;

			//UE_LOG(LogTerrainTool, Log, TEXT("%s"), *Debug1);

			//UE_LOG(LogTerrainTool, Log, TEXT("-------------"));
			int NumberOfPossibleCollapses = 0;
			FIntVector CollapseIndex = FIntVector();
			for (int Offset = 0; Offset < MergeResult.Growth + 2; Offset++)
			{
				//FString Debug = FString();
				//Debug += FString::FromInt(UPTTMath::Mod(CurrentShape.Num() - 1 - MergeResult.Growth + Offset, CurrentShape.Num())) + "\t|  ";
				int CollapseSocketIndex = UPTTMath::Mod(CurrentShape.Num() - 1 - MergeResult.Growth + Offset, CurrentShape.Num());
				for (int CollapseShapeIndex = 0; CollapseShapeIndex < BaseSuperPositions.Num(); CollapseShapeIndex++)
				{
					for (int CollapseFaceIndex = 0; CollapseFaceIndex < BaseSuperPositions[CollapseShapeIndex].Num(); CollapseFaceIndex++)
					{
						if (/*SuperPositions[CollapseSocketIndex][CollapseShapeIndex][CollapseFaceIndex]*/true)
						{
							FTerrainShape CollapsedShape;
							FTerrainShapeMergeResult CollapsedShapeMergeResult;
							if (CurrentShape.MergeShape(CollapsedShape, CollapsedShapeMergeResult, CollapseSocketIndex, SpriteShapes[CollapseShapeIndex], CollapseFaceIndex))
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
			return;
		}
	}
	UE_LOG(LogTerrainTool, Error, TEXT("Collapse Failed"));
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

bool ATerrainHandler::HasNewCollapseableSuperPositions(FTerrainShape Shape, FTerrainShapeMergeResult MergeResult, int SearchDepth)
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

FTerrainGenerationWorker::FTerrainGenerationWorker(TArray<FTerrainTileSpawnData>& OutTiles, TArray<FTerrainTileData> Tiles, UProcedualCollapseMode* Mode, const int PredictionDepth = 0) : UseableTiles(Tiles), CollapseMode(Mode), CollapsePredictionDepth(PredictionDepth), bCompleated(false)
{ 
	//Link to where data should be stored .
	Tiles = &OutTiles;
	//Create thread.
	Thread = FRunnableThread::Create(this, TEXT("FTerrainGenerationWorker"), 0, TPri_BelowNormal);
}

FTerrainGenerationWorker::~FTerrainGenerationWorker()
{ 
	delete Thread;
	Thread = NULL; 
}

//Init 
bool FTerrainGenerationWorker::Init()
{
	bCompleated = false;

	UE_LOG(LogTerrainTool, Log, TEXT("*******************************"));
	UE_LOG(LogTerrainTool, Log, TEXT("Super Position Collapse Started"));
	UE_LOG(LogTerrainTool, Log, TEXT("*******************************"));

	return true;
}

//Run 
uint32 FTerrainGenerationWorker::Run()
{ 
	//Initial wait before starting 
	FPlatformProcess::Sleep(0.03);	


	while (!bCompleated)
	{
		FIntVector CollapseResult;
		if (!CollapseMode->GetSuperPositionsToCollapse(CollapseResult, Shape, SuperPositions, SpawnableTiles))
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

//stop 
void FTerrainGenerationWorker::Stop()
{ 
	bCompleated = true;

	UE_LOG(LogTerrainTool, Log, TEXT("*******************************"));
	UE_LOG(LogTerrainTool, Log, TEXT(" Super Position Collapse Ended "));
	UE_LOG(LogTerrainTool, Log, TEXT("*******************************"));
}

void FTerrainGenerationWorker::Shutdown()
{ 
	Stop();
	Thread->WaitForCompletion();
}

bool FTerrainGenerationWorker::IsThreadFinished()
{
	return bCompleated;
}