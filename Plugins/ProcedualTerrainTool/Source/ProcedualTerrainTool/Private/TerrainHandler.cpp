// Fill out your copyright notice in the Description page of Project Settings.

#include "TerrainHandler.h"

#include "DrawDebugHelpers.h"
#include "PaperSpriteComponent.h"
#include "TerrainSpriteData.h"

ATerrainHandler::ATerrainHandler()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
}

void ATerrainHandler::LogTest()
{
	FlushPersistentDebugLines(GetWorld());
	for (int i = 0; i < CurrentShape.Num(); i++)
	{
		FVector Offset = FMath::RandPointInBox(FBox(FVector(-5, -5, -5), FVector(5, 5, 5)));
		FVector LineStart = GetActorTransform().TransformPosition(FVector(CurrentShape.Vertices[i].X, 0, CurrentShape.Vertices[i].Y));
		FVector LineEnd = GetActorTransform().TransformPosition(FVector(CurrentShape.Vertices[(i + 1) % CurrentShape.Num()].X, 0, CurrentShape.Vertices[(i + 1) % CurrentShape.Num()].Y));
		FColor Color = FColor::MakeRandomColor();

		DrawDebugLine(GetWorld(), LineStart, LineEnd, Color, true, 100, 0U, 5);

		Color = (Color.ReinterpretAsLinear() / 2).ToFColor(false);
		for (int j = 1; j <= CurrentShape.ShapeSockets[i].SocketIndex; j++)
		{
			if (j % 5 != 0)
			{
				DrawDebugLine(GetWorld(), (LineStart + LineEnd) / 2 + FVector(j * 5, 10, 0) + Offset, (LineStart + LineEnd) / 2 + FVector(j * 5, 10, 10) + Offset, Color, true, 100, 0U, 3);
			}
			else
			{
				DrawDebugLine(GetWorld(), (LineStart + LineEnd) / 2 + FVector((j-4) * 5, 10, 0) + Offset, (LineStart + LineEnd) / 2 + FVector((j-1) * 5, 10, 10) + Offset, Color, true, 100, 0U, 1.5);
			}
		}
	}
}


void ATerrainHandler::RefreshUseableSpriteData()
{
	SpriteShapes.Empty();

	for (UTerrainSpriteData* EachUseableSprite : UseableSprites)
	{
		SpriteShapes.Emplace(FTerrainShape(EachUseableSprite->Verticies, EachUseableSprite->FaceIndices));

		TArray<bool> Faces = TArray<bool>();
		Faces.Init(true, EachUseableSprite->Verticies.Num());
		BaseSuperPositions.Emplace(Faces);
	}

	ResetTerrain();
}

void ATerrainHandler::ResetTerrain()
{
	CurrentShape = FTerrainShape();

	SuperPositions.SetNum(1);
	SuperPositions[0] = BaseSuperPositions;	

	TSet<UActorComponent*> Components = GetComponents();
	for (UActorComponent* EachComponent : Components)
	{
		if (EachComponent != RootComponent)
		{
			EachComponent->DestroyComponent();
		}
	}
}

void ATerrainHandler::CollapseSuperPosition()
{
	if (bRandomColapse)
	{
		if (!SuperPositions.IsEmpty())
		{
			int SocketIndex = FMath::RandHelper(SuperPositions.Num());
			if (!SuperPositions[SocketIndex].IsEmpty())
			{
				int ShapeIndex = FMath::RandHelper(SuperPositions[SocketIndex].Num());
				if (!SuperPositions[SocketIndex][ShapeIndex].IsEmpty())
				{
					int FaceIndex = FMath::RandHelper(SuperPositions[SocketIndex][ShapeIndex].Num());
					CollapseSuperPosition(SocketIndex, ShapeIndex, FaceIndex);
				}
			}
		}
	}
	else
	{
		CollapseSuperPosition(CollapseCoords.X, CollapseCoords.Y, CollapseCoords.Z);
	}
}

void ATerrainHandler::CollapseSuperPosition(int SocketIndex, int ShapeIndex, int FaceIndex)
{
	if (SuperPositions.IsValidIndex(SocketIndex) && SuperPositions[SocketIndex].IsValidIndex(ShapeIndex) && SuperPositions[SocketIndex][ShapeIndex].IsValidIndex(FaceIndex) && SuperPositions[SocketIndex][ShapeIndex][FaceIndex])
	{
		FTerrainShape NewShape;
		FTransform2D MergeTransform;

		UE_LOG(LogTemp, Warning, TEXT("\\/------------------------ %i, %i, %i ------------------------\\/"), SocketIndex, ShapeIndex, FaceIndex);
		if (ensureAlwaysMsgf(CurrentShape.MergeShape(NewShape, MergeTransform, SocketIndex, SpriteShapes[ShapeIndex], FaceIndex, true), TEXT("Super Position Array False")))
		{
			UE_LOG(LogTemp, Warning, TEXT("/\\------------------------ %i, %i, %i ------------------------/\\"), SocketIndex, ShapeIndex, FaceIndex);
			CollapseSuperPosition(SocketIndex, ShapeIndex, FaceIndex, NewShape, MergeTransform);
		}
	}
}

void ATerrainHandler::CollapseSuperPosition(int SocketIndex, int ShapeIndex, int FaceIndex, FTerrainShape MergeResult, FTransform2D MergeTransform)
{
	//Calculate Sprite Rotation
	float A;
	float B;
	float C;
	float D;
	MergeTransform.GetMatrix().GetMatrix(A, B, C, D);
	if (FMath::IsNearlyZero(A))
	{
		A = SMALL_NUMBER;
	}

	float Angle = FMath::Atan(B / A);
	if (A < 0)
	{
		Angle = PI + Angle;
	}

	//Spawn Sprite
	FTransform Transform = FTransform(FQuat(FVector(0, -1, 0), Angle), FVector(MergeTransform.GetTranslation().X, 0, MergeTransform.GetTranslation().Y));
	UPaperSpriteComponent* NewSprite = NewObject<UPaperSpriteComponent>(this);
	NewSprite->SetSprite(UseableSprites[ShapeIndex]->Sprite);
	NewSprite->RegisterComponent();
	NewSprite->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
	NewSprite->SetRelativeTransform(Transform);

	//Refresh Superpositions
	CurrentShape = MergeResult;
	RefreshSuperPositions();
}

void ATerrainHandler::RefreshSuperPositions()
{
	SuperPositions.Reserve(CurrentShape.Num());
	for (int SocketIndex = 0; SocketIndex < CurrentShape.Num(); SocketIndex++)
	{
		if (!SuperPositions.IsValidIndex(SocketIndex))
		{
			SuperPositions.Emplace(BaseSuperPositions);
		}

		for (int ShapeIndex = 0; ShapeIndex < SpriteShapes.Num(); ShapeIndex++)
		{
			int SuccessCount = 0;
			int SucceededFaceIndex = 0;
			FTransform2D SucceededTransform;
			FTerrainShape NewShape;

			for (int FaceIndex = 0; FaceIndex < SpriteShapes[ShapeIndex].Num(); FaceIndex++)
			{
				SuperPositions[SocketIndex][ShapeIndex][FaceIndex] = CurrentShape.MergeShape(NewShape, SucceededTransform, SocketIndex, SpriteShapes[ShapeIndex], FaceIndex);
				SuccessCount++;
				SucceededFaceIndex = FaceIndex;
			}

			if (SuccessCount == 1)
			{
				CollapseSuperPosition(SocketIndex, ShapeIndex, SucceededFaceIndex, NewShape, SucceededTransform);
			}
		}
	}
}