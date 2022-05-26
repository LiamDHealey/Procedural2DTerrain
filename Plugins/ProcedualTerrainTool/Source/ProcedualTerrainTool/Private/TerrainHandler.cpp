// Fill out your copyright notice in the Description page of Project Settings.

#include "TerrainHandler.h"

#include "TerrainSpriteData.h"


void ATerrainHandler::LogTest()
{
	//UE_LOG(LogTemp, Warning, TEXT("\\/-------------------\\/"));
	//for (FSpriteGeometryShape EachShape : SpriteData->Shape)
	//{
	//	for (FVector2D EachVertex : EachShape.Vertices)
	//	{
	//		UE_LOG(LogTemp, Warning, TEXT("%s"), *EachVertex.ToString());
	//	}
	//}
	//UE_LOG(LogTemp, Warning, TEXT("/\\-------------------/\\"));
}


void ATerrainHandler::RefreshUseableSpriteData()
{
	BaseSuperPositions.Empty();

	for (UTerrainSpriteData* EachUseableSprite : UseableSprites)
	{
		BaseSuperPositions.Add(FTerrainShape(EachUseableSprite->Verticies));
	}
}

void ATerrainHandler::ResetTerrain()
{
	CurrentShape = FTerrainShape();

	SuperPositions.Empty();
	TArray<TArray<bool>> FirstSocetSuperPosition = TArray<TArray<bool>>();
	for (FTerrainShape EachBaseSuperPosition : BaseSuperPositions)
	{
		bool DefaultValue = true;
		FirstSocetSuperPosition.Add(TArray<bool>(&DefaultValue, EachBaseSuperPosition.Num()));
	}
	SuperPositions.Add(FirstSocetSuperPosition);
}

void ATerrainHandler::CollapseSuperPosition()
{
	int SocketIndex = FMath::RandHelper(SuperPositions.Num() - 1);
	int ShapeIndex	= FMath::RandHelper(SuperPositions[SocketIndex].Num() - 1);
	int FaceIndex	= FMath::RandHelper(SuperPositions[SocketIndex][ShapeIndex].Num() - 1);
	CollapseSuperPosition(ShapeIndex, ShapeIndex, FaceIndex);
}

void ATerrainHandler::CollapseSuperPosition(int SocketIndex, int ShapeIndex, int FaceIndex)
{
	if (SuperPositions.IsValidIndex(SocketIndex) && SuperPositions[SocketIndex].IsValidIndex(ShapeIndex) && SuperPositions[SocketIndex][ShapeIndex].IsValidIndex(FaceIndex) && SuperPositions[SocketIndex][ShapeIndex][FaceIndex])
	{
		FTerrainShape NewShape;
		SuperPositions[SocketIndex][ShapeIndex].Add(CurrentShape.MergeShape(NewShape, SocketIndex, BaseSuperPositions[ShapeIndex], FaceIndex));
		CurrentShape = NewShape;

		RefreshSuperPositions();
	}
}

void ATerrainHandler::RefreshSuperPositions()
{
	SuperPositions.Empty();
	for (int SocketIndex = 0; SocketIndex < CurrentShape.Num(); SocketIndex)
	{
		SuperPositions.Add(TArray<TArray<bool>>());
		for (int ShapeIndex = 0; ShapeIndex < BaseSuperPositions.Num(); ShapeIndex)
		{
			SuperPositions[SocketIndex].Add(TArray<bool>());

			int SuccessCount = 0;
			FTerrainShape NewShape;

			for (int FaceIndex = 0; FaceIndex < BaseSuperPositions[ShapeIndex].Num(); FaceIndex)
			{
				SuperPositions[SocketIndex][ShapeIndex].Add(CurrentShape.MergeShape(NewShape, SocketIndex, BaseSuperPositions[ShapeIndex], FaceIndex));
				SuccessCount++;
			}

			if (SuccessCount == 1)
			{
				CurrentShape = NewShape;
				RefreshSuperPositions();
			}
		}
	}
}