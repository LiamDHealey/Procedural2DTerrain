// Fill out your copyright notice in the Description page of Project Settings.


#include "ProcedualCollapseMode.h"

/**
 * Gets the next super position to collapse on the given shape.
 *
 * @param SuperPositionIndex - Set to the indices of the super position to collapse next.
 * @param CurrentShape - The current shape of the terrain.
 * @param SuperPositions - The current superposition states of the terrain.
 * @return Whether or not another collapse is needed.
 */
bool UProcedualCollapseMode::GetSuperPositionsToCollapse(FIntVector& SuperPositionIndex, FTerrainShape CurrentShape, TArray<TArray<TArray<bool>>> SuperPositions, TArray<FTerrainTileData> SpawnableTiles) const
{
	SuperPositionIndex = FIntVector();
	return false;
}

/**
 * Gets the next super position to collapse on the given shape. Will collapse at Collapse Coords.
 *
 * @param SuperPositionIndex - Set to the indices of the super position to collapse next.
 * @param CurrentShape - The current shape of the terrain.
 * @param SuperPositions - The current superposition states of the terrain.
 * @return Whether or not another collapse is needed.
 */
bool UManualCollapseMode::GetSuperPositionsToCollapse(FIntVector& SuperPositionIndex, FTerrainShape CurrentShape, TArray<TArray<TArray<bool>>> SuperPositions, TArray<FTerrainTileData> SpawnableTiles) const
{
	SuperPositionIndex = CollapseCoords;
	return false;
}

/**
 * Gets the next super position to collapse on the given shape. Will all superpositions within Radius.
 *
 * @param SuperPositionIndex - Set to the indices of the super position to collapse next.
 * @param CurrentShape - The current shape of the terrain.
 * @param SuperPositions - The current superposition states of the terrain.
 * @return Whether or not another collapse is needed.
 */
bool UCircularCollapseMode::GetSuperPositionsToCollapse(FIntVector& SuperPositionIndex, FTerrainShape CurrentShape, TArray<TArray<TArray<bool>>> SuperPositions, TArray<FTerrainTileData> SpawnableTiles) const
{
	//Draw boundary
	//FlushPersistentDebugLines(GetWorld());
	//DrawDebugCircle(GetWorld(), TerrainTransform.GetTranslation(), Radius, 32, FColor::Magenta, false, 10, 0U, 50, TerrainTransform.GetRotation().GetForwardVector(), TerrainTransform.GetRotation().GetRightVector(), false);

	if (!SuperPositions.IsEmpty() && !CurrentShape.ShapeSockets.IsEmpty())
	{
		//Get socket closest to center
		TMap<int, TArray<int>> PossibleCollapses = TMap<int, TArray<int>>();
		int SocketIndex = 0;

		float ClosestDistanceSquared = ((CurrentShape.Vertices[SocketIndex] + CurrentShape.Vertices[(SocketIndex + 1) % CurrentShape.Num()]) / 2).SquaredLength();
		for (int SearchIndex = 1; SearchIndex < CurrentShape.Num(); SearchIndex++)
		{
			float SeachDistanceSquared = ((CurrentShape.Vertices[SearchIndex] + CurrentShape.Vertices[(SearchIndex + 1) % CurrentShape.Num()]) / 2).SquaredLength();
			if (SeachDistanceSquared < ClosestDistanceSquared)
			{
				ClosestDistanceSquared = SeachDistanceSquared;
				SocketIndex = SearchIndex;
			}
		}

		//Get possible collapses around selected socket
		for (int ShapeIndex = 0; ShapeIndex < SuperPositions[SocketIndex].Num(); ShapeIndex++)
		{
			for (int FaceIndex = 0; FaceIndex < SuperPositions[SocketIndex][ShapeIndex].Num(); FaceIndex++)
			{
				if (SuperPositions[SocketIndex][ShapeIndex][FaceIndex])
				{
					if (!PossibleCollapses.Contains(ShapeIndex))
					{
						PossibleCollapses.Emplace(ShapeIndex, TArray<int>());
					}

					PossibleCollapses.Find(ShapeIndex)->Emplace(FaceIndex);
				}
			}
		}

		//End if no valid collapses
		if (PossibleCollapses.IsEmpty())
		{
			FVector2D ErrorLocation = ((CurrentShape.Vertices[SocketIndex] + CurrentShape.Vertices[(SocketIndex + 1) % CurrentShape.Num()]) / 2);
			//DrawDebugPoint(GetWorld(), TerrainTransform.TransformPosition(FVector(ErrorLocation, 0)), 50, FColor::Red, true);
			SuperPositionIndex = FIntVector(0, 0, 0);
			return false;
		}

		//Get shape index weighted
		TArray<int> Keys;
		PossibleCollapses.GenerateKeyArray(Keys);
		TArray<float> Weights = TArray<float>();
		float WeightSum = 0;
		for (int EachKey : Keys)
		{
			float LastWeight = 0;
			if (Weights.IsValidIndex(Weights.Num() - 1))
			{
				LastWeight = Weights[Weights.Num() - 1];
			}
			WeightSum += SpawnableTiles[EachKey].SpawnWeight;
			Weights.Emplace(SpawnableTiles[EachKey].SpawnWeight + LastWeight);
		}

		int ShapeIndex = 0;
		float RandomSelector = FMath::RandRange(0.f, WeightSum);
		for (int KeyIndex = 0; KeyIndex < Keys.Num(); KeyIndex++)
		{
			if (Weights[KeyIndex] >= RandomSelector)
			{
				ShapeIndex = Keys[KeyIndex];
				break;
			}
		}

		//Collapse superposition
		if (ensure(!PossibleCollapses.IsEmpty() && !PossibleCollapses.FindRef(ShapeIndex).IsEmpty()))
		{
			SuperPositionIndex = FIntVector(SocketIndex, ShapeIndex, PossibleCollapses.FindRef(ShapeIndex)[FMath::RandHelper(PossibleCollapses.FindRef(ShapeIndex).Num())]);
			return ClosestDistanceSquared < Radius* Radius;
		}

		//Fail for memory loss
		SuperPositionIndex = FIntVector(0, 0, 0);
		return false;
	}
	//Fail for invalid shapes
	UE_LOG(LogTerrainTool, Error, TEXT("Invalid shape consider refreshing tile data"));
	SuperPositionIndex = FIntVector(0,0,0);
	return CurrentShape.ShapeSockets.IsEmpty() && !SpawnableTiles.IsEmpty() && !SuperPositions.IsEmpty() && !SuperPositions[0].IsEmpty() && !SuperPositions[0][0].IsEmpty();
}

/**
 * Gets the next super position to collapse on the given shape. Will all superpositions within a box with the given extent.
 *
 * @param SuperPositionIndex - Set to the indices of the super position to collapse next.
 * @param CurrentShape - The current shape of the terrain.
 * @param SuperPositions - The current superposition states of the terrain.
 * @param SpawnableTiles - The tiles that can be spawned.
 * @return Whether or not another collapse is needed.
 */
bool URectangularCollapseMode::GetSuperPositionsToCollapse(FIntVector& SuperPositionIndex, FTerrainShape CurrentShape, TArray<TArray<TArray<bool>>> SuperPositions, TArray<FTerrainTileData> SpawnableTiles) const
{
	//Draw bounds
	FlushPersistentDebugLines(GetWorld());
	//DrawDebugBox(GetWorld(), TerrainTransform.GetTranslation(), FVector(Extent, 0), TerrainTransform.GetRotation(), FColor::Magenta, false, 10, 0U, 50);

	if (!SuperPositions.IsEmpty() && !CurrentShape.ShapeSockets.IsEmpty())
	{
		//Find left most point in extent.
		TMap<int, TArray<int>> PossibleCollapses = TMap<int, TArray<int>>();
		int SocketIndex = 0;
		float LeastXValue = MAX_FLT;
		bool bValidSocketFound = false;

		for (int SearchIndex = 0; SearchIndex < CurrentShape.Num(); SearchIndex++)
		{
			FVector2D SocketLocation = ((CurrentShape.Vertices[SearchIndex] + CurrentShape.Vertices[(SearchIndex + 1) % CurrentShape.Num()]) / 2).GetAbs();
			if (SocketLocation.X < LeastXValue && ((SocketLocation.X < abs(Extent.X)) && (SocketLocation.Y < abs(Extent.Y))))
			{
				bValidSocketFound = true;
				LeastXValue = SocketLocation.X;
				SocketIndex = SearchIndex;
			}
		}

		//Get Possible collapses
		for (int ShapeIndex = 0; ShapeIndex < SuperPositions[SocketIndex].Num(); ShapeIndex++)
		{
			for (int FaceIndex = 0; FaceIndex < SuperPositions[SocketIndex][ShapeIndex].Num(); FaceIndex++)
			{
				if (SuperPositions[SocketIndex][ShapeIndex][FaceIndex])
				{
					if (!PossibleCollapses.Contains(ShapeIndex))
					{
						PossibleCollapses.Emplace(ShapeIndex, TArray<int>());
					}

					PossibleCollapses.Find(ShapeIndex)->Emplace(FaceIndex);
				}
			}
		}

		//End if no valid collapses
		if (PossibleCollapses.IsEmpty())
		{
			UE_LOG(LogTerrainTool, Error, TEXT("Shapes do not tile, Consider adding another shape to fill the gap at the marked point or regenerating the terrain"), SocketIndex);
			FVector2D ErrorLocation = ((CurrentShape.Vertices[SocketIndex] + CurrentShape.Vertices[(SocketIndex + 1) % CurrentShape.Num()]) / 2);
			//DrawDebugPoint(GetWorld(), TerrainTransform.TransformPosition(FVector(ErrorLocation, 0)), 50, FColor::Red, true);
			SuperPositionIndex = FIntVector(0, 0, 0);
			return false;
		}

		//Get shape index weighted
		TArray<int> Keys;
		PossibleCollapses.GenerateKeyArray(Keys);
		TArray<float> Weights = TArray<float>();
		float WeightSum = 0;
		for (int EachKey : Keys)
		{
			float LastWeight = 0;
			if (Weights.IsValidIndex(Weights.Num() - 1))
			{
				LastWeight = Weights[Weights.Num() - 1];
			}
			WeightSum += SpawnableTiles[EachKey].SpawnWeight;
			Weights.Emplace(SpawnableTiles[EachKey].SpawnWeight + LastWeight);
		}

		int ShapeIndex = 0;
		float RandomSelector = FMath::RandRange(0.f, WeightSum);
		for (int KeyIndex = 0; KeyIndex < Keys.Num(); KeyIndex++)
		{
			if (Weights[KeyIndex] >= RandomSelector)
			{
				ShapeIndex = Keys[KeyIndex];
				break;
			}
		}

		//Collapse superposition
		if (ensure(!PossibleCollapses.IsEmpty() && !PossibleCollapses.FindRef(ShapeIndex).IsEmpty()))
		{
			SuperPositionIndex = FIntVector(SocketIndex, ShapeIndex, PossibleCollapses.FindRef(ShapeIndex)[FMath::RandHelper(PossibleCollapses.FindRef(ShapeIndex).Num())]);
			return bValidSocketFound;
		}
		SuperPositionIndex = FIntVector(0, 0, 0);
		return false;
	}
	UE_LOG(LogTerrainTool, Error, TEXT("Invalid shape consider refreshing tile data"));
	SuperPositionIndex = FIntVector(0, 0, 0);
	return CurrentShape.ShapeSockets.IsEmpty() && !SpawnableTiles.IsEmpty() && !SuperPositions.IsEmpty() && !SuperPositions[0].IsEmpty() && !SuperPositions[0][0].IsEmpty();
}