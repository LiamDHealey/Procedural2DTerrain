#pragma once

#include "CoreMinimal.h"

#include "ProcedualTerrainToolFunctionLibraries.h"

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
class FTerrainVertex
{
public:
	//The location of this vertex relative to the terrain.
	FVector2D Location = FVector2D::ZeroVector;

	//The type of socket. Will only connect to sockets with the same type.
	FName Type = FName();

	//The length of this between this and the next vertex. Will only connect to vertices with the same length.
	float Length = 1;

	//The angle this socket blocks around its first vertex.
	float Angle = 2 * PI;

	//The vertex before this one in the shape.
	FTerrainVertex* LastVertex = nullptr;

	//The vertex after this one in the shape.
	FTerrainVertex* NextVertex = nullptr;

	FTerrainVertex(TArray<FVector2D> VertexLocations, TArray<FName> FaceTypes)
	{
		if (VertexLocations.Num() < 3)
		{
			return;
		}
		FaceTypes.SetNum(VertexLocations.Num());

		FTerrainVertex(FaceTypes[0], VertexLocations[VertexLocations.Num() - 1], VertexLocations[0], VertexLocations[1]);
		FTerrainVertex* LastInitVertex = this;
		for (int Index = 1; Index < VertexLocations.Num(); Index++)
		{
			LastInitVertex->NextVertex = new FTerrainVertex(FaceTypes[Index], VertexLocations[Index - 1], VertexLocations[Index % VertexLocations.Num()], VertexLocations[(Index + 1) % VertexLocations.Num()], LastVertex);
			LastInitVertex = LastInitVertex->NextVertex;
		}

		LastVertex = LastInitVertex;
	}

	/**
	 * Constructs a socket given terrain geometry and an index.
	 * 
	 * @param Index - The type of socket. Will only connect to sockets with the same type.
	 * @param PreviousVertex - The vertex prior to this vertex.
	 * @param Vertex - Location of this vertex.
	 * @param NextVertex - The vertex after this vertex.
	 */
	FTerrainVertex(FName SocketType = FName(), FVector2D PreviousVertexLocation = FVector2D(), FVector2D VertexLocation = FVector2D(), FVector2D NextVertexLocation = FVector2D(), FTerrainVertex* PreviousVertex = nullptr)
	{
		Location = VertexLocation;
		Type = SocketType;
		Length = FVector2D::Distance(VertexLocation, NextVertexLocation);

		FVector2D VP = (PreviousVertexLocation - VertexLocation).GetSafeNormal();
		FVector2D VN = (NextVertexLocation - VertexLocation).GetSafeNormal();
		
		Angle = FMath::Acos(VP | VN);
		if ((VP ^ VN) > 0)
		{
			Angle = TWO_PI - Angle;
		}
	}

	FTerrainVertex(const FTerrainVertex& Other)
	{
		Location = Other.Location;
		Type = Other.Type;
		Length = Other.Length;
		Angle = Other.Angle;

		FTerrainVertex* LastInitVertex = this;
		for (FTerrainVertex* VertexToCopy = Other.NextVertex; VertexToCopy != Other.NextVertex; VertexToCopy = VertexToCopy->NextVertex)
		{
			LastInitVertex->NextVertex = new FTerrainVertex(VertexToCopy->Location, VertexToCopy->Type, VertexToCopy->Length, VertexToCopy->Angle);
			LastInitVertex = LastInitVertex->NextVertex;
		}

		LastVertex = LastInitVertex;
	}

	FTerrainVertex(FVector2D VertexLocation, FName VertexType, float VertexLength, float VertexAngle)
	{
		Location = VertexLocation;
		Type = VertexType;
		Length = VertexLength;
		Angle = VertexAngle;
	}

	~FTerrainVertex()
	{
		LastVertex->NextVertex = NextVertex;
		NextVertex->LastVertex = LastVertex;
	}

	/**
	 * Increases the angle.
	 * 
	 * @param Amount - The amount to increase the first angle by.
	 */
	void IncreaseAngle(float Amount)
	{
		Angle += Amount;
	}

	/**
	 * Determines whether sockets can connect.
	 * 
	 * @param Other - The other socket to test.
	 * @return Whether or not this and Other can connect.
	 */
	static EConnectionResult CanVerticesConnect(FTerrainVertex* FirstShapeVertex, FTerrainVertex* SecondShapeVertex)
	{
		FTerrainVertex* FirstShapeNextVertex = FirstShapeVertex->NextVertex;
		FTerrainVertex* SecondShapePreviousVertex = SecondShapeVertex->LastVertex;
		if (
			//Types aren't the same.
			FirstShapeVertex->Type != FirstShapeNextVertex->Type || FirstShapeVertex->Type != SecondShapeVertex->Type  || FirstShapeVertex->Type != SecondShapePreviousVertex->Type ||
			//Lengths aren't the same.
			!FMath::IsNearlyEqual(FirstShapeVertex->Length, SecondShapeVertex->Length, KINDA_SMALL_NUMBER) ||
			//Angles can't merge.
			FirstShapeVertex->Angle + SecondShapeVertex->Angle > TWO_PI + KINDA_SMALL_NUMBER || FirstShapeNextVertex->Angle + SecondShapePreviousVertex->Angle > TWO_PI + KINDA_SMALL_NUMBER
			)
		{
			return EConnectionResult::No;
		}

		bool bCheckNext = FMath::IsNearlyEqual(FirstShapeVertex->Angle + SecondShapeVertex->Angle, TWO_PI, KINDA_SMALL_NUMBER);
		bool bCheckPrevious = FMath::IsNearlyEqual(FirstShapeNextVertex->Angle + SecondShapePreviousVertex->Angle, TWO_PI, KINDA_SMALL_NUMBER);

		switch ((bCheckNext)+(2 * bCheckPrevious))
		{
		case 0:
			return EConnectionResult::Yes;

		case 1:
			return EConnectionResult::CheckNext;

		case 2:
			return EConnectionResult::CheckPrevious;

		case 3:
			return EConnectionResult::CheckBoth;

		default:
			return EConnectionResult::No;
		}
	}

	bool operator==(const FTerrainVertex& OtherVertex) const
	{
		return Location == OtherVertex.Location && Type == OtherVertex.Type && Length == OtherVertex.Length && Angle == OtherVertex.Angle;
	}
};

/**
 * Stores the results of a terrain shape merge.
 */
USTRUCT(BlueprintType)
struct PROCEDUALTERRAINTOOL_API FTerrainShapeMergeResult
{
	GENERATED_BODY()

	//The transform applied to the other shape.
	FTransform2D Transform = FTransform2D();
};

/**
 * Stores a piece of terrain's shape and its sockets.
 */
USTRUCT(BlueprintType)
struct PROCEDUALTERRAINTOOL_API FTerrainShape
{
	GENERATED_BODY()

	//Stores all of the vertices of this shape.
	FTerrainVertex* InitialVertex = nullptr;

	//Constructs a terrain shape from the given terrain's geometry.
	FTerrainShape(TArray<FVector2D> TerrainGeometery = TArray<FVector2D>())
	{
		TArray<FName> FaceTypes = TArray<FName>();
		FaceTypes.Init(TEXT("Default"), TerrainGeometery.Num());
		FTerrainShape(TerrainGeometery, FaceTypes);
	}

	//Constructs a terrain shape from the given terrain's geometry and face indices.
	FTerrainShape(TArray<FVector2D> TerrainGeometery, TArray<FName> FaceTypes)
	{
		if (TerrainGeometery.IsEmpty())
		{
			return;
		}

		InitialVertex = new FTerrainVertex(TerrainGeometery, FaceTypes);
	}
	
	/**
	 * Determines whether this shape can merge with another.
	 *
	 * @param FaceIndex - The index of the face on this shape to start the merge at.
	 * @param Other - The other shape to query.
	 * @param FaceIndex - The index of the face on this the other shape to start the merge at.
	 * @return Whether or not this shape can be merged with the other shape.
	 */
	bool MergeShape(FTerrainVertex* Vertex, FTerrainShape Other, FTerrainVertex* OtherVertex) const
	{
		//Account for empty shapes.
		if (!(InitialVertex->LastVertex && InitialVertex->NextVertex) && (Other.InitialVertex->LastVertex && Other.InitialVertex->NextVertex))
		{
			return true;
		}

		//Fail Invalid Merges
		if (!(Other.InitialVertex->LastVertex && Other.InitialVertex->NextVertex) || !Vertex || !OtherVertex)
		{
			return false;
		}

		// \/ Detect if merge is possible \/ //

		bool bClockwise = false;
		bool bSearchClockwise = true;
		do
		{
			//Reset search
			FTerrainVertex* SearchVertex = bClockwise ? Vertex->NextVertex : Vertex;
			FTerrainVertex* SearchOtherVertex = bClockwise ? OtherVertex->LastVertex : OtherVertex;

			//Search all of shapes sockets to detect if connection is possible
			do
			{
				//Test socket connectivity
				switch (FTerrainVertex::CanVerticesConnect(SearchVertex, SearchOtherVertex))
				{
				case EConnectionResult::No:
					return false;

				case EConnectionResult::CheckNext:
					if (!bClockwise)
					{
						if (bSearchClockwise)
						{
							goto nextLoop;
						}
						goto skipLoop;
					}
					break;

				case EConnectionResult::CheckPrevious:
					if (bClockwise)
					{
						goto nextLoop;
					}
					bSearchClockwise = false;
					break;

				case EConnectionResult::CheckBoth:
					break;

				case EConnectionResult::Yes:
					if (ensureMsgf(SearchIndex == FaceIndex, TEXT("Improper Shape Angle Detection")))
					{
						goto skipLoop;
					}

					goto nextLoop;

				default:
					ensureMsgf(false, TEXT("Invalid Socket Test Result"));
					break;
				}

				//Iterate Search
				FTerrainVertex* SearchVertex = bClockwise ? Vertex->NextVertex : Vertex->LastVertex;
				FTerrainVertex* SearchOtherVertex = bClockwise ? OtherVertex->LastVertex : OtherVertex->NextVertex;

			} while (SearchVertex != Vertex);
			ensureMsgf(false, TEXT("Shape indices mismatch"));

		nextLoop:
			bClockwise = !bClockwise;

		} while ((bClockwise));

	skipLoop:
		return true;
	}

	/**
	 * Attempts to merge this shape with another.
	 * 
	 * @param MergedShape - The shape of the this and other combined.
	 * @param MergedResult - Data about how the shapes were merged.
	 * @param FaceIndex - The index of the face on this shape to start the merge at.
	 * @param Other - The other shape to query.
	 * @param FaceIndex - The index of the face on this the other shape to start the merge at.
	 * @return Whether or not this shape can be merged with the other shape.
	 */
	bool MergeShape(FTerrainShape& MergedShape, FTerrainShapeMergeResult& MergeResult, FTerrainVertex* Vertex, FTerrainShape Other, FTerrainVertex* OtherVertex) const
	{
		MergeResult = FTerrainShapeMergeResult();

		//Account for empty shapes.
		if (!(InitialVertex->LastVertex && InitialVertex->NextVertex) && (Other.InitialVertex->LastVertex && Other.InitialVertex->NextVertex))
		{
			MergedShape = FTerrainShape(Other);
			MergeResult.Transform = FTransform2D();
			return true;
		}

		//Fail Invalid Merges
		if (!(Other.InitialVertex->LastVertex && Other.InitialVertex->NextVertex) || !Vertex || !OtherVertex)
		{
			MergedShape = FTerrainShape();
			return false;
		}


		// \/ Detect if merge is possible \/ //

		FTerrainVertex* FirstMergeVertex = new FTerrainVertex(*Vertex);
		FTerrainVertex* LastMergeVertex = new FTerrainVertex(*Vertex->NextVertex);
		FTerrainVertex* OtherFirstMergeVertex = new FTerrainVertex(*OtherVertex);
		FTerrainVertex* OtherLastMergeVertex = new FTerrainVertex(*OtherVertex->NextVertex);

		bool bClockwise = false;
		bool bSearchClockwise = true;
		do
		{
			//Reset search
			FTerrainVertex* SearchVertex = bClockwise ? Vertex->NextVertex : Vertex;
			FTerrainVertex* SearchOtherVertex = bClockwise ? OtherVertex->LastVertex : OtherVertex;

			//Search all of shapes sockets to detect if connection is possible
			do
			{
				//Test socket connectivity
				switch (FTerrainVertex::CanVerticesConnect(SearchVertex, SearchOtherVertex))
				{
				case EConnectionResult::No:
					return false;

				case EConnectionResult::CheckNext:
					if (!bClockwise)
					{
						FirstMergeVertex = new FTerrainVertex(*SearchVertex);
						OtherLastMergeVertex = new FTerrainVertex(*SearchOtherVertex->NextVertex);
						if (bSearchClockwise)
						{
							goto nextLoop;
						}
						goto skipLoop;
					}
					break;

				case EConnectionResult::CheckPrevious:
					if (bClockwise)
					{
						LastMergeVertex = new FTerrainVertex(*SearchVertex->NextVertex);
						OtherFirstMergeVertex = new FTerrainVertex(*SearchOtherVertex);
						goto nextLoop;
					}
					bSearchClockwise = false;
					break;

				case EConnectionResult::CheckBoth:
					break;

				case EConnectionResult::Yes:
					if (ensureMsgf(SearchVertex == Vertex, TEXT("Improper Shape Angle Detection")))
					{
						goto skipLoop;
					}

					goto nextLoop;

				default:
					ensureMsgf(false, TEXT("Invalid Socket Test Result"));
					break;
				}

				//Iterate Search
				FTerrainVertex* SearchVertex = bClockwise ? Vertex->NextVertex : Vertex->LastVertex;
				FTerrainVertex* SearchOtherVertex = bClockwise ? OtherVertex->LastVertex : OtherVertex->NextVertex;

			} while (SearchVertex != Vertex);
			ensureMsgf(false, TEXT("Shape indices mismatch"));

		nextLoop:
			bClockwise = !bClockwise;

		} while ((bClockwise));

	skipLoop:

		// /\ Detect if merge is possible /\ //
		
		// \/ Merge Shapes \/ //
		
		//Prune Merged Sockets & Vertices
		MergedShape = FTerrainShape(*this);
		for (FTerrainVertex* SeachVertex = FirstMergeVertex->NextVertex; SeachVertex != LastMergeVertex; SeachVertex = SeachVertex->NextVertex)
		{
			delete SeachVertex->LastVertex;
		}

		//Adjust socket angles
		FTerrainVertex OtherShapeSockets = TArray<FTerrainSocket>(Other.ShapeSockets);
		OtherShapeSockets[UPTTMath::Mod(OtherLastMergeIndex + 1, OtherShapeSockets.Num())].IncreaseFirstAngle(ShapeSockets[FirstMergeIndex].FirstAngle);
		OtherShapeSockets[UPTTMath::Mod(OtherFirstMergeIndex - 1, OtherShapeSockets.Num())].IncreaseSecondAngle(ShapeSockets[LastMergeIndex].SecondAngle);

		MergedShape.ShapeSockets[0].IncreaseFirstAngle(Other.ShapeSockets[OtherFirstMergeIndex].FirstAngle);
		MergedShape.ShapeSockets[MergedShape.Num() - 1].IncreaseSecondAngle(Other.ShapeSockets[OtherLastMergeIndex].SecondAngle);


		//Get Other Transform
		FQuat2D Target = FQuat2D((MergedShape.Vertices[0] - Vertices[LastMergeIndex]).GetSafeNormal());
		FQuat2D Initial = FQuat2D((Other.Vertices[OtherFirstMergeIndex] - Other.Vertices[UPTTMath::Mod(OtherFirstMergeIndex + 1, Other.Vertices.Num())]).GetSafeNormal());
		FQuat2D Rotation = Initial.Inverse().Concatenate(Target);
		MergeResult.Transform = FTransform2D(Rotation, Vertices[FirstMergeIndex] - Rotation.TransformPoint(Other.Vertices[UPTTMath::Mod(OtherLastMergeIndex + 1, Other.Vertices.Num())]));


		//Add other vertices
		OtherLastMergeIndex = UPTTMath::Mod(OtherLastMergeIndex + 1, Other.Num());
		do
		{
			MergedShape.Vertices.Emplace(MergeResult.Transform.TransformPoint(Other.Vertices[OtherLastMergeIndex]));
			MergedShape.ShapeSockets.Emplace(OtherShapeSockets[OtherLastMergeIndex]);
			MergeResult.Growth++;

			OtherLastMergeIndex = UPTTMath::Mod(OtherLastMergeIndex + 1, Other.Num());
		} while (OtherLastMergeIndex != OtherFirstMergeIndex);

		// /\ Merge Shapes /\ //
		

		return true;
	}

	bool operator==(const FTerrainShape& OtherShape) const
	{
		return ShapeSockets == OtherShape.ShapeSockets && Vertices == OtherShape.Vertices;
	}
};