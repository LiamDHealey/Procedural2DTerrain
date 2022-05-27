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
		DrawDebugLine(GetWorld(), GetActorTransform().TransformPosition(FVector(CurrentShape.Vertices[i].X, 0, CurrentShape.Vertices[i].Y)), GetActorTransform().TransformPosition(FVector(CurrentShape.Vertices[(i + 1) % CurrentShape.Num()].X, 0, CurrentShape.Vertices[(i + 1) % CurrentShape.Num()].Y)), FColor::MakeRandomColor(), true, 100, 0U, 10);
	}
}


void ATerrainHandler::RefreshUseableSpriteData()
{
	BaseSuperPositions.Empty();

	for (UTerrainSpriteData* EachUseableSprite : UseableSprites)
	{
		BaseSuperPositions.Add(FTerrainShape(EachUseableSprite->Verticies));
	}

	ResetTerrain();
}

void ATerrainHandler::ResetTerrain()
{
	CurrentShape = FTerrainShape();

	SuperPositions.Empty();
	TArray<TArray<bool>> FirstSocetSuperPosition = TArray<TArray<bool>>();
	for (FTerrainShape EachBaseSuperPosition : BaseSuperPositions)
	{
		FirstSocetSuperPosition.Add(TArray<bool>());
		for (int i = 0; i < EachBaseSuperPosition.Num(); i++)
		{
			FirstSocetSuperPosition[0].Add(true);
		}
	}
	SuperPositions.Add(FirstSocetSuperPosition);

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
	//if (!SuperPositions.IsEmpty())
	//{
	//	int SocketIndex = FMath::RandHelper(SuperPositions.Num() - 1);
	//	int ShapeIndex = FMath::RandHelper(SuperPositions[SocketIndex].Num() - 1);
	//	int FaceIndex = FMath::RandHelper(SuperPositions[SocketIndex][ShapeIndex].Num() - 1);
	//	CollapseSuperPosition(SocketIndex, ShapeIndex, FaceIndex);
	//}
	CollapseSuperPosition(CollapseCoords.X, CollapseCoords.Y, CollapseCoords.Z);
}

void ATerrainHandler::CollapseSuperPosition(int SocketIndex, int ShapeIndex, int FaceIndex)
{
	if (SuperPositions.IsValidIndex(SocketIndex) && SuperPositions[SocketIndex].IsValidIndex(ShapeIndex) && SuperPositions[SocketIndex][ShapeIndex].IsValidIndex(FaceIndex) && SuperPositions[SocketIndex][ShapeIndex][FaceIndex])
	{
		FTerrainShape NewShape;
		FTransform2D MergeTransform;
		if (ensureMsgf(CurrentShape.MergeShape(NewShape, MergeTransform, SocketIndex, BaseSuperPositions[ShapeIndex], FaceIndex, true), TEXT("Super Position Array False")))
		{
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
	float Angle = FMath::Atan(B / A);
	if (A < 0)
	{
		Angle = PI - Angle;
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
	SuperPositions.Empty();
	for (int SocketIndex = 0; SocketIndex < CurrentShape.Num(); SocketIndex++)
	{
		SuperPositions.Add(TArray<TArray<bool>>());
		for (int ShapeIndex = 0; ShapeIndex < BaseSuperPositions.Num(); ShapeIndex++)
		{
			SuperPositions[SocketIndex].Add(TArray<bool>());

			int SuccessCount = 0;
			int SucceededFaceIndex = 0;
			FTransform2D SucceededTransform;
			FTerrainShape NewShape;

			for (int FaceIndex = 0; FaceIndex < BaseSuperPositions[ShapeIndex].Num(); FaceIndex++)
			{
				SuperPositions[SocketIndex][ShapeIndex].Add(CurrentShape.MergeShape(NewShape, SucceededTransform, SocketIndex, BaseSuperPositions[ShapeIndex], FaceIndex));
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