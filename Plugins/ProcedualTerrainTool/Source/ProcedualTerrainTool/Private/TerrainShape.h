#pragma once

#include "CoreMinimal.h"
#include "TerrainShape.generated.h"

/**
 * A socket's connectivity state.
 */
UENUM(BlueprintType)
enum class EConnectionResult : uint8
{
	No				= 0,
	CheckNext		= 1,
	CheckPrevious	= 2,
	CheckBoth		= 3,
	Yes				= 4,
};

/**
 * A socket storing data relevant for terrain piece connections.
 */
USTRUCT(BlueprintType)
struct PROCEDUALTERRAINTOOL_API FTerrainSocket
{
	GENERATED_BODY()

	//The index of this socket. Will only connect to sockets with the same index. Negative Indices will never connect.
	UPROPERTY(VisibleAnywhere)
	int SocketIndex = 0;

	//The length of this socket. Will only connect to sockets with the same length.
	UPROPERTY(VisibleAnywhere)
	float Length = 1;

	//The angle this socket blocks around its first vertex.
	UPROPERTY(VisibleAnywhere)
	float FirstAngle = 2 * PI;

	//The angle this socket blocks around its second vertex.
	UPROPERTY(VisibleAnywhere)
	float SecondAngle = 2 * PI;

	/**
	 * Constructs a socket given terrain geometry and an index.
	 * 
	 * @param Index - The index of this socket. Will only connect to sockets with the same index. Negative Indices will never connect.
	 * @param PreviousVertex - The vertex prior to the FirstVertex.
	 * @param FirstVertex - The first vertex defining the edge of this socket.
	 * @param SecondVertex - The second vertex defining the edge of this socket.
	 * @param NextVertex - The vertex after the SecondVertex.
	 */
	FTerrainSocket(int Index = -1, FVector2D PreviousVertex = FVector2D(), FVector2D FirstVertex = FVector2D(), FVector2D SecondVertex = FVector2D(), FVector2D NextVertex = FVector2D())
	{
		SocketIndex = Index;
		Length = FVector2D::Distance(FirstVertex, SecondVertex);

		FVector2D FP = (PreviousVertex - FirstVertex).GetSafeNormal();
		FVector2D FS = (SecondVertex - FirstVertex).GetSafeNormal();
		FVector2D SN = (NextVertex - SecondVertex).GetSafeNormal();
		FVector2D SF = (FirstVertex - SecondVertex).GetSafeNormal();
		
		FirstAngle = FMath::Acos(FP | FS);
		//if ((FP ^ FS) < 0)
		//{
		//	FirstAngle = 2 * PI - FirstAngle;
		//}

		SecondAngle = FMath::Acos(SF | SN);
		//if ((SF ^ SN) < 0)
		//{
		//	SecondAngle = 2 * PI - SecondAngle;
		//}
	}

	/**
	 * Increases the first angle.
	 * 
	 * @param Amount - The amount to increase the first angle by.
	 */
	void IncreaseFirstAngle(float Amount)
	{
		FirstAngle += Amount;
	}

	/**
	 * Increases the second angle.
	 *
	 * @param Amount - The amount to increase the second angle by.
	 */
	void IncreaseSecondAngle(float Amount)
	{
		SecondAngle += Amount;
	}

	/**
	 * Determines whether sockets can connect.
	 * 
	 * @param Other - The other socket to test.
	 * @return Whether or not this and Other can connect.
	 */
	EConnectionResult CanConnectToSocket(FTerrainSocket Other) const
	{
		if (SocketIndex < 0 || SocketIndex != Other.SocketIndex || Length != Other.Length || SecondAngle + Other.FirstAngle > 2 * PI || FirstAngle + Other.SecondAngle > 2 * PI)
		{
			return EConnectionResult::No;
		}

		bool bCheckNext = SecondAngle + Other.FirstAngle == 2 * PI;
		bool bCheckPrevious = FirstAngle + Other.SecondAngle == 2 * PI;

		if (bCheckNext || bCheckNext)
		{
			return (EConnectionResult)((int8)(bCheckNext)+(int8)(2 * bCheckPrevious));
		}

		return EConnectionResult::Yes;
	}
};

/**
 * Stores a piece of terrain's shape and its sockets.
 */
USTRUCT(BlueprintType)
struct PROCEDUALTERRAINTOOL_API FTerrainShape
{
	GENERATED_BODY()

	//Stores all of the sockets in this shape.
	UPROPERTY(VisibleAnywhere)
	TArray<FTerrainSocket> ShapeSockets = TArray<FTerrainSocket>();

	//Stores all of the vertices of this shape.
	UPROPERTY(VisibleAnywhere)
	TArray<FVector2D> Vertices = TArray<FVector2D>();

	//Constructs a terrain shape from the given terrain's geometry.
	FTerrainShape(TArray<FVector2D> TerrainGeometery = TArray<FVector2D>())
	{
		if (TerrainGeometery.IsEmpty())
		{
			return;
		}
		for (int GeoIndex = 1; GeoIndex <= TerrainGeometery.Num(); GeoIndex++)
		{
			FTerrainSocket NewSocket = FTerrainSocket(0, TerrainGeometery[GeoIndex - 1], TerrainGeometery[GeoIndex % TerrainGeometery.Num()], TerrainGeometery[(GeoIndex + 1) % TerrainGeometery.Num()], TerrainGeometery[(GeoIndex + 2) % TerrainGeometery.Num()]);
			ShapeSockets.Add(NewSocket);
			Vertices.Add(TerrainGeometery[GeoIndex % TerrainGeometery.Num()]);
		}
	}

	//Constructs a terrain shape from the given sockets.
	FTerrainShape(TArray<FVector2D> TerrainGeometery, TArray<FTerrainSocket> Sockets)
	{
		Vertices = TerrainGeometery;
		ShapeSockets = Sockets;
	}

	/**
	 * Gets the number of sockets this shape has.
	 * 
	 * @return The number of sockets this shape has.
	 */
	int Num()
	{
		return ShapeSockets.Num();
	}

	/**
	 * Attempts to merge this shape with another.
	 * 
	 * @param MergedShape - The combined shape of this and another shape.
	 * @param MergedTransform - The transform applied to Other if the merge was successful.
	 * @param FaceIndex - The index of the face on this shape to start the merge at.
	 * @param Other - The other shape to query.
	 * @param FaceIndex - The index of the face on this the other shape to start the merge at.
	 * @return Whether or not this shape can be merged with the other shape.
	 */
	bool MergeShape(FTerrainShape& MergedShape, FTransform2D& MergedTransform, int FaceIndex, FTerrainShape Other, int OtherFaceIndex, bool bDebug = false) const
	{
		//Account for empty shapes.
		if (ShapeSockets.IsEmpty() && !Other.ShapeSockets.IsEmpty())
		{
			MergedShape = FTerrainShape(Other.Vertices, Other.ShapeSockets);
			MergedTransform = FTransform2D();
			return true;
		}

		//Fail Invalid Merges
		if (Other.ShapeSockets.IsEmpty() || !ShapeSockets.IsValidIndex(FaceIndex) || !Other.ShapeSockets.IsValidIndex(OtherFaceIndex))
		{
			return false;
		}

		// \/ Detect if merge is possible \/ //
		MergedShape = FTerrainShape(*this);
		int FirstMergeIndex = FaceIndex;
		int LastMergeIndex = FaceIndex;
		int OtherFirstMergeIndex = OtherFaceIndex;
		int OtherLastMergeIndex = OtherFaceIndex;


		bool bClockwise = false;
		do
		{
			//Reset indices
			int SearchIndex = FaceIndex + bClockwise;
			int OtherSearchIndex = OtherFaceIndex - bClockwise;

			//Search all of shapes sockets to detect if connection is possible
			do
			{
				//Test socket connectivity
				switch (ShapeSockets[SearchIndex].CanConnectToSocket(Other.ShapeSockets[OtherFaceIndex]))
				{
				case EConnectionResult::No:
					MergedShape = FTerrainShape();
					return false;

				case EConnectionResult::CheckNext:
					if (!bClockwise)
					{
						FirstMergeIndex = SearchIndex;
						OtherLastMergeIndex = OtherSearchIndex;
						goto nextLoop; //Current direction succeeded
					}
					break;

				case EConnectionResult::CheckPrevious:
					if (bClockwise)
					{
						LastMergeIndex = SearchIndex;
						OtherFirstMergeIndex = OtherSearchIndex;
						goto nextLoop; //Current direction succeeded
					}
					break;

				case EConnectionResult::CheckBoth:
					break;

				default:
					ensureMsgf(SearchIndex == FaceIndex, TEXT("Improper Shape Angle Detection"));
					goto nextLoop;
				}

				//Iterate Indices
				SearchIndex = Mod(SearchIndex + bClockwise ? 1 : -1, ShapeSockets.Num());
				OtherSearchIndex = Mod(OtherSearchIndex + !bClockwise ? 1 : -1, Other.ShapeSockets.Num());

			} while (SearchIndex != FaceIndex);
			ensureMsgf(false, TEXT("Shape indices mismatch"));

		nextLoop:
			bClockwise = !bClockwise;

		} while (!bClockwise);
		// /\ Detect if merge is possible /\ //
		
		// \/ Merge Shapes \/ //
		TArray<FTerrainSocket> OtherShapeSockets = TArray<FTerrainSocket>(Other.ShapeSockets);
		TArray<FVector2D> OtherMergedVerticies = TArray<FVector2D>(Other.Vertices);

		//Adjust socket angles
		MergedShape.ShapeSockets[Mod(LastMergeIndex + 1, MergedShape.ShapeSockets.Num())].IncreaseFirstAngle(OtherShapeSockets[OtherFirstMergeIndex].FirstAngle);
		MergedShape.ShapeSockets[Mod(FirstMergeIndex - 1, MergedShape.ShapeSockets.Num())].IncreaseSecondAngle(OtherShapeSockets[OtherLastMergeIndex].SecondAngle);

		OtherShapeSockets[Mod(OtherLastMergeIndex + 1, OtherShapeSockets.Num())].IncreaseFirstAngle(MergedShape.ShapeSockets[FirstMergeIndex].FirstAngle);
		OtherShapeSockets[Mod(OtherFirstMergeIndex - 1, OtherShapeSockets.Num())].IncreaseSecondAngle(MergedShape.ShapeSockets[LastMergeIndex].SecondAngle);

		//Prune Merged Sockets & Vertices
		MergedShape.ShapeSockets.RemoveAt(FirstMergeIndex, FMath::Min(LastMergeIndex + 1, MergedShape.ShapeSockets.Num()) - FirstMergeIndex);
		MergedShape.Vertices.RemoveAt(FirstMergeIndex, FMath::Min(LastMergeIndex + 1, MergedShape.Vertices.Num()) - FirstMergeIndex);
		if (LastMergeIndex < FirstMergeIndex)
		{
			MergedShape.ShapeSockets.RemoveAt(0, LastMergeIndex + 1);
			MergedShape.Vertices.RemoveAt(0, LastMergeIndex + 1);
		}
		OtherShapeSockets.RemoveAt(OtherFirstMergeIndex, FMath::Min(OtherLastMergeIndex + 1, OtherShapeSockets.Num()) - (OtherFirstMergeIndex));
		//OtherMergedVerticies.RemoveAt(OtherFirstMergeIndex, FMath::Min(OtherLastMergeIndex + 1, OtherShapeSockets.Num()) - (OtherFirstMergeIndex));
		if (OtherLastMergeIndex < OtherFirstMergeIndex)
		{
			OtherShapeSockets.RemoveAt(0, OtherLastMergeIndex + 2);
			//OtherMergedVerticies.RemoveAt(0, OtherLastMergeIndex + 2);
		}

		//Combine Shapes
		MergedShape.ShapeSockets.Insert(OtherShapeSockets, FirstMergeIndex);

		FQuat2D Target = FQuat2D((Vertices[Mod(FirstMergeIndex + 1, Vertices.Num())] - Vertices[FirstMergeIndex]).GetSafeNormal());
		FQuat2D Initial = FQuat2D((-Other.Vertices[Mod(OtherFirstMergeIndex + 1, Other.Vertices.Num())] + Other.Vertices[OtherFirstMergeIndex]).GetSafeNormal());
		FQuat2D Rotation = Initial.Inverse().Concatenate(Target);
		MergedTransform = FTransform2D(Rotation, Vertices[FirstMergeIndex] - Rotation.TransformPoint(Other.Vertices[Mod(OtherLastMergeIndex + 1, Other.Vertices.Num())]));
		OtherFirstMergeIndex = Mod(OtherFirstMergeIndex - 1, Other.Num());

		do
		{
			MergedShape.Vertices.Insert(MergedTransform.TransformPoint(Other.Vertices[OtherFirstMergeIndex]), FirstMergeIndex);
			OtherFirstMergeIndex = Mod(OtherFirstMergeIndex - 1, Other.Num());
		} while (OtherLastMergeIndex != OtherFirstMergeIndex);

		// /\ Merge Shapes /\ //

		return true;
	}

private:
	int Mod(int A, int B) const
	{
		int Value = A % B;
		if (Value < 0)
		{
			Value += B;
		}
		return Value;
	}
};