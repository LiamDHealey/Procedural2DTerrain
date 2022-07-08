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
	CheckVertex1	= 1,
	CheckVertex2	= 2,
	CheckBoth		= 3,
	Yes				= 4,
};

/**
 * A socket storing data relevant for terrain piece connections.
 */
USTRUCT(BlueprintType)
struct PROCEDUALTERRAINTOOL_API FTerrainVertex
{
	GENERATED_BODY()

	//The type of edge after this vertex. Will only connect to vertices of the same type.
	UPROPERTY(VisibleAnywhere)
	FName Type;

	//The location of the vertex relative to the terrain.
	UPROPERTY(VisibleAnywhere)
	FVector2D Location;

	//The length of the edge after this vertex. Will only connect to vertices with the same length.
	UPROPERTY(VisibleAnywhere)
	float Length;

	//The interior angle at the vertex.
	UPROPERTY(VisibleAnywhere)
	float Angle = 2 * PI;

	/**
	 * Constructs a vertex given adjacent vertex locations and a type.
	 * 
	 * @param SocketType - The type of vertex. Will only connect to vertices of the same type.
	 * @param PreviousVertex - The location relative to the terrain of vertex prior to this.
	 * @param Vertex - The location relative to the terrain of this.
	 * @param NextVertex - The location relative to the terrain of vertex after this.
	 */
	FTerrainVertex(FName SocketType = FName(), const FVector2D PreviousVertex = FVector2D(), const FVector2D Vertex = FVector2D(), const FVector2D NextVertex = FVector2D())
		:	Length(FVector2D::Distance(Vertex, NextVertex))
	{
		Type = SocketType;

		Location = Vertex;

		FVector2D VP = (PreviousVertex - Vertex).GetSafeNormal();
		FVector2D VN = (NextVertex - Vertex).GetSafeNormal();
		
		Angle = FMath::Acos(VP | VN);
		if ((VP ^ VN) > 0)
		{
			Angle = TWO_PI - Angle;
		}
	}

	/**
	 * Increases the first angle.
	 * 
	 * @param Amount - The amount to increase the first angle by.
	 */
	void IncreaseAngle(float Amount)
	{
		Angle += Amount;
	}


	/**
	 * Determines whether vertices can connect such that Shape1Vertex1 and Shape2Vertex1 are coincident; Shape1Vertex2 and Shape2Vertex2 are coincident; and Shape1Vertex1 comes before Shape1Vertex2.
	 * 
	 * @param Shape1Vertex1 - Will be coincident to Shape2Vertex1, and comes before Shape1Vertex2.
	 * @param Shape1Vertex2 - Will be coincident to Shape2Vertex2, and comes after Shape1Vertex1.
	 * @param Shape2Vertex1 - Will be coincident to Shape1Vertex1, and comes after Shape2Vertex2.
	 * @param Shape2Vertex2 - Will be coincident to Shape1Vertex2, and comes before Shape2Vertex1.
	 * @return Whether or not these vertices can connect.
	 */
	static EConnectionResult CanVerticesConnect(const FTerrainVertex Shape1Vertex1, const FTerrainVertex Shape1Vertex2, const FTerrainVertex Shape2Vertex1, const FTerrainVertex Shape2Vertex2)
	{
		const float MergedAngle1 = Shape1Vertex1.Angle + Shape2Vertex1.Angle - TWO_PI;
		const float MergedAngle2 = Shape1Vertex2.Angle + Shape2Vertex2.Angle - TWO_PI;

		//Types, lengths, or angles are not merge-able
		if (Shape1Vertex1.Type != Shape2Vertex2.Type ||	!FMath::IsNearlyEqual(Shape1Vertex1.Length, Shape2Vertex2.Length, KINDA_SMALL_NUMBER) || MergedAngle1 > KINDA_SMALL_NUMBER || MergedAngle2 > KINDA_SMALL_NUMBER)
		{
			return EConnectionResult::No;
		}

		const bool bCheck1 = abs(MergedAngle1) < KINDA_SMALL_NUMBER;
		const bool bCheck2 = abs(MergedAngle2) < KINDA_SMALL_NUMBER;

		switch ((bCheck1)+(2 * bCheck2))
		{
		case 0:
			return EConnectionResult::Yes;

		case 1:
			return EConnectionResult::CheckVertex1;

		case 2:
			return EConnectionResult::CheckVertex2;

		case 3:
			return EConnectionResult::CheckBoth;

		default:
			return EConnectionResult::No;
		}
	}

	bool operator==(const FTerrainVertex& OtherVertex) const
	{
		return Type == OtherVertex.Type && Length == OtherVertex.Length && Angle == OtherVertex.Angle && Location == OtherVertex.Location;
	}

	//void operator=(const FTerrainVertex& OtherVertex) const
	//{
	//	Type = OtherVertex.Type;
	//	Length = OtherVertex.Length;
	//	Angle = OtherVertex.Angle;
	//	Location = OtherVertex.Location;
	//}
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

	//The change of the indices of the original shape.
	UPROPERTY()
	int Offset = 0;
		
	//The number of new vertices gained during the merge.
	UPROPERTY()
	int Growth = 0;

	//The number of old vertices lost during the merge.
	UPROPERTY()
	int Shrinkage = 0;
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
	TArray<FTerrainVertex> Vertices = TArray<FTerrainVertex>();

	//Constructs a terrain shape from the given terrain's geometry.
	FTerrainShape(TArray<FVector2D> TerrainGeometery = TArray<FVector2D>())
	{
		TArray<FName> FaceTypes = TArray<FName>();
		FaceTypes.SetNumZeroed(TerrainGeometery.Num());
		FTerrainShape(TerrainGeometery, FaceTypes);
	}

	//Constructs a terrain shape from the given terrain's geometry and face indices.
	FTerrainShape(TArray<FVector2D> TerrainGeometery, TArray<FName> FaceTypes)
	{
		if (TerrainGeometery.IsEmpty())
		{
			return;
		}

		FaceTypes.SetNumZeroed(TerrainGeometery.Num());
		for (int GeoIndex = 1; GeoIndex <= TerrainGeometery.Num(); GeoIndex++)
		{
			FTerrainVertex NewVertex = FTerrainVertex(FaceTypes[GeoIndex % FaceTypes.Num()], TerrainGeometery[GeoIndex - 1], TerrainGeometery[GeoIndex % TerrainGeometery.Num()], TerrainGeometery[(GeoIndex + 1) % TerrainGeometery.Num()]);
			Vertices.Emplace(NewVertex);
		}
	}

	//Constructs a terrain shape from the given sockets.
	FTerrainShape(TArray<FTerrainVertex> TerrainVertices)
	{
		Vertices = TerrainVertices;
	}

	/**
	 * Gets the number of sockets this shape has.
	 * 
	 * @return The number of sockets this shape has.
	 */
	int Num() const
	{
		return Vertices.Num();
	}

	/**
	 * Determines whether this shape can merge with another.
	 *
	 * @param FaceIndex - The index of the face on this shape to start the merge at.
	 * @param Other - The other shape to query.
	 * @param FaceIndex - The index of the face on this the other shape to start the merge at.
	 * @return Whether or not this shape can be merged with the other shape.
	 */
	bool MergeShape(const int FaceIndex, const FTerrainShape Other, const int OtherFaceIndex) const
	{
		//Account for empty shapes.
		if (Vertices.IsEmpty() && !Other.Vertices.IsEmpty())
		{
			return true;
		}

		//Fail Invalid Merges
		if (Other.Vertices.IsEmpty() || !Vertices.IsValidIndex(FaceIndex) || !Other.Vertices.IsValidIndex(OtherFaceIndex))
		{
			return false;
		}

		// \/ Detect if merge is possible \/ //


		bool bSearchingForVertex1 = false;
		bool bNeedsToSearchForVertex1 = true;
		do
		{
			//Reset indices

			int SearchIndex = UPTTMath::Mod(FaceIndex + bSearchingForVertex1, Num());
			int OtherSearchIndex = UPTTMath::Mod(OtherFaceIndex - bSearchingForVertex1, Other.Num());

			//Search all of shapes sockets to detect if connection is possible
			do
			{
				//Test socket connectivity
				switch (FTerrainVertex::CanVerticesConnect(Vertices[SearchIndex], Vertices[UPTTMath::Mod(SearchIndex + 1, Num())], Other.Vertices[OtherSearchIndex], Other.Vertices[UPTTMath::Mod(OtherSearchIndex - 1, Num())]))
				{
				case EConnectionResult::No:
					return false;

				case EConnectionResult::CheckVertex1:
					if (!bSearchingForVertex1)
					{
						if (bNeedsToSearchForVertex1)
						{
							goto nextLoop;
						}
						goto skipLoop;
					}
					break;

				case EConnectionResult::CheckVertex2:
					if (bSearchingForVertex1)
					{
						goto nextLoop;
					}
					bNeedsToSearchForVertex1 = false;
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

				//Iterate Indices
				SearchIndex = UPTTMath::Mod(SearchIndex + (bSearchingForVertex1 ? 1 : -1), Num());
				OtherSearchIndex = UPTTMath::Mod(OtherSearchIndex + (!bSearchingForVertex1 ? 1 : -1), Other.Num());

			} while (SearchIndex != FaceIndex);
			ensureMsgf(false, TEXT("Shape indices mismatch"));

		nextLoop:
			bSearchingForVertex1 = !bSearchingForVertex1;

		} while ((bSearchingForVertex1));

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
	bool MergeShape(FTerrainShape& MergedShape, FTerrainShapeMergeResult& MergeResult, int FaceIndex, FTerrainShape Other, int OtherFaceIndex) const
	{
		MergeResult = FTerrainShapeMergeResult();

		//Account for empty shapes.
		if (Vertices.IsEmpty() && !Other.Vertices.IsEmpty())
		{
			MergedShape = FTerrainShape(Other.Vertices);
			MergeResult.Transform = FTransform2D();
			MergeResult.Growth = Other.Num();
			return true;
		}

		//Fail Invalid Merges
		if (Other.Vertices.IsEmpty() || !Vertices.IsValidIndex(FaceIndex) || !Other.Vertices.IsValidIndex(OtherFaceIndex))
		{
			MergedShape = FTerrainShape();
			return false;
		}

		// \/ Detect if merge is possible \/ //
		int MergeIndex1 = FaceIndex;
		int MergeIndex2 = UPTTMath::Mod(FaceIndex + 1, Num());
		int OtherMergeIndex1 = UPTTMath::Mod(OtherFaceIndex + 1, Other.Num());
		int OtherMergeIndex2 = OtherFaceIndex;


		bool bSearchingForVertex1 = false;
		bool bNeedsToSearchForVertex1 = true;
		do
		{
			//Reset indices
			int SearchIndex = UPTTMath::Mod(FaceIndex + bSearchingForVertex1, Num());
			int OtherSearchIndex = UPTTMath::Mod(OtherFaceIndex - bSearchingForVertex1, Other.Num());

			//Search all of shapes sockets to detect if connection is possible
			do
			{
				//Test socket connectivity
				switch (FTerrainVertex::CanVerticesConnect(Vertices[SearchIndex], Vertices[UPTTMath::Mod(SearchIndex + 1, Num())], Other.Vertices[UPTTMath::Mod(OtherSearchIndex + 1, Other.Num())], Other.Vertices[OtherSearchIndex]))
				{
				case EConnectionResult::No:
					MergedShape = FTerrainShape();
					return false;

				case EConnectionResult::CheckVertex1:
					if (!bSearchingForVertex1)
					{
						MergeIndex2 = SearchIndex;
						OtherMergeIndex2 = OtherSearchIndex;

						if (bNeedsToSearchForVertex1)
						{
							goto nextLoop;
						}
						goto skipLoop;
					}
					break;

				case EConnectionResult::CheckVertex2:
					if (bSearchingForVertex1)
					{
						MergeIndex1 = SearchIndex;
						OtherMergeIndex1 = OtherSearchIndex;
						goto nextLoop; 
					}
					bNeedsToSearchForVertex1 = false;
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

				//Iterate Indices
				SearchIndex = UPTTMath::Mod(SearchIndex + (bSearchingForVertex1 ? 1 : -1), Num());
				OtherSearchIndex = UPTTMath::Mod(OtherSearchIndex + (!bSearchingForVertex1 ? 1 : -1), Other.Num());

			} while (SearchIndex != FaceIndex);
			ensureMsgf(false, TEXT("Shape indices mismatch"));

		nextLoop:
			bSearchingForVertex1 = !bSearchingForVertex1;

		} while ((bSearchingForVertex1));
	skipLoop:
		// /\ Detect if merge is possible /\ //
		
		// \/ Merge Shapes \/ //
		
		//Prune Merged Sockets & Vertices
		MergeResult.Shrinkage = (MergeIndex1 <= MergeIndex2 ? MergeIndex2 - MergeIndex1 : MergeIndex2 + Num() - MergeIndex1);
		MergedShape = FTerrainShape();
		MergedShape.Vertices.SetNum(Num() - MergeResult.Shrinkage);

		MergeResult.Offset = -1 * MergeIndex2;

		for (int MergeOffset = 0; MergeOffset < MergedShape.Num(); MergeOffset++)
		{
			MergedShape.Vertices[MergeOffset] = Vertices[UPTTMath::Mod(MergeIndex2 + MergeOffset, Num())];
		}


		//Adjust socket angles
		TArray<FTerrainVertex> OtherShapeVertices = TArray<FTerrainVertex>(Other.Vertices);
		OtherShapeVertices[UPTTMath::Mod(OtherMergeIndex1, OtherShapeVertices.Num())].IncreaseAngle(Vertices[MergeIndex1].Angle);

		MergedShape.Vertices[0].IncreaseAngle(Other.Vertices[OtherMergeIndex2].Angle);


		//Get Other Transform
		FQuat2D Target = FQuat2D((Vertices[MergeIndex2].Location - Vertices[UPTTMath::Mod(MergeIndex2 - 1, Vertices.Num())].Location).GetSafeNormal());
		FQuat2D Initial = FQuat2D((Other.Vertices[OtherMergeIndex2].Location - Other.Vertices[UPTTMath::Mod(OtherMergeIndex2 + 1, Other.Vertices.Num())].Location).GetSafeNormal());
		FQuat2D Rotation = Initial.Inverse().Concatenate(Target);
		MergeResult.Transform = FTransform2D(Rotation, Vertices[MergeIndex2].Location - Rotation.TransformPoint(Other.Vertices[OtherMergeIndex2].Location));


		//Add other vertices
		MergeResult.Growth = (OtherMergeIndex1 <= OtherMergeIndex2 ? OtherMergeIndex1 - OtherMergeIndex2 : OtherMergeIndex2 + Other.Num() - OtherMergeIndex1);

		for (int MergeOffset = 0; MergeOffset < MergeResult.Growth; MergeOffset++)
		{
			int MergeIndex = UPTTMath::Mod(MergeIndex - OtherMergeIndex1, Other.Num());

			FTerrainVertex VertexToEmplace = Other.Vertices[MergeIndex];
			VertexToEmplace.Location = MergeResult.Transform.TransformPoint(Other.Vertices[MergeIndex].Location);

			MergedShape.Vertices.Emplace(VertexToEmplace);
		}

		// /\ Merge Shapes /\ //
		

		return true;
	}

	bool operator==(const FTerrainShape& OtherShape) const
	{
		return Vertices == OtherShape.Vertices;
	}
};