// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "VectorArc.h"

#include "GameFramework/Actor.h"
#include "TerrainHandler.generated.h"

class UTerrainSpriteData;

/**
 * 
 */
UCLASS()
class PROCEDUALTERRAINTOOL_API ATerrainHandler : public AActor
{
	GENERATED_BODY()

	UFUNCTION(CallInEditor, Meta = (Category = "TerrainHandler"))
	void LogTest();

	UPROPERTY(EditAnywhere)
	UTerrainSpriteData* SpriteData;
};

/**
 * A socket storing data relevant for terrain piece connections.
 */
USTRUCT()
struct PROCEDUALTERRAINTOOL_API FTerrainSocket
{
	GENERATED_BODY()

	//The index of this socket. Will only connect to sockets with the same index.
	UPROPERTY()
	int32 SocketIndex = 0;

	//The length of this socket. Will only connect to sockets with the same length.
	UPROPERTY()
	float Length = 1;

	//The angle this socket blocks around its first vertex.
	UPROPERTY()
	FVectorArc FirstAngle = FVectorArc();

	//The angle this socket blocks around its second vertex.
	UPROPERTY()
	FVectorArc SecondAngle = FVectorArc();

	/**
	 * Constructs a socket given terrain geometry and an index.
	 * 
	 * @param Index - The index of this socket. Will only connect to sockets with the same index.
	 * @param PreviousVertex - The vertex prior to the FirstVertex.
	 * @param FirstVertex - The first vertex defining the edge of this socket.
	 * @param SecondVertex - The second vertex defining the edge of this socket.
	 * @param NextVertex - The vertex after the SecondVertex.
	 */
	FTerrainSocket(int32 Index, FVector2D PreviousVertex, FVector2D FirstVertex, FVector2D SecondVertex, FVector2D NextVertex)
	{
		SocketIndex = Index;
		Length = FVector2D::Distance(FirstVertex, SecondVertex);
		FirstAngle = FVectorArc(SecondVertex - FirstVertex, PreviousVertex - FirstVertex);
		SecondAngle = FVectorArc(NextVertex - SecondVertex, FirstVertex - SecondVertex);
	}
};
