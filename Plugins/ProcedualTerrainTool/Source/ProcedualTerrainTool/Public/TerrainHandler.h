// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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

public:
	UFUNCTION(CallInEditor, Meta = (Category = "TerrainHandler"))
	void LogTest();

	UPROPERTY(EditAnywhere)
	TSet<UTerrainSpriteData*> UseableSprites;

	UFUNCTION(CallInEditor, Meta = (Category = "TerrainHandler"))
	void RefreshUseableSpriteData();

private:

};

/**
 * A socket's connectivity state.
 */
UENUM()
enum class EConnectionResult : int8
{
	No = 0,
	CheckNext = 1,
	CheckPrevious = 2,
	CheckBoth = 3,
	Yes = 4,
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
	float FirstAngle = 2 * PI;

	//The angle this socket blocks around its second vertex.
	UPROPERTY()
	float SecondAngle = 2 * PI;

	/**
	 * Constructs a socket given terrain geometry and an index.
	 * 
	 * @param Index - The index of this socket. Will only connect to sockets with the same index.
	 * @param PreviousVertex - The vertex prior to the FirstVertex.
	 * @param FirstVertex - The first vertex defining the edge of this socket.
	 * @param SecondVertex - The second vertex defining the edge of this socket.
	 * @param NextVertex - The vertex after the SecondVertex.
	 */
	FTerrainSocket(int32 Index = -1, FVector2D PreviousVertex = FVector2D(), FVector2D FirstVertex = FVector2D(), FVector2D SecondVertex = FVector2D(), FVector2D NextVertex = FVector2D())
	{
		SocketIndex = Index;
		Length = FVector2D::Distance(FirstVertex, SecondVertex);

		FVector2D FP = (PreviousVertex - FirstVertex).GetSafeNormal();
		FVector2D FS = (SecondVertex - FirstVertex).GetSafeNormal();
		FVector2D SN = (NextVertex - SecondVertex).GetSafeNormal();
		FVector2D SF = (FirstVertex - SecondVertex).GetSafeNormal();
		
		FirstAngle = FMath::Acos(FP | FS);
		if ((FP ^ FS) < 0)
		{
			FirstAngle = 2 * PI - FirstAngle;
		}

		SecondAngle = FMath::Acos(SF | SN);
		if ((SF ^ SN) < 0)
		{
			SecondAngle = 2 * PI - SecondAngle;
		}
	}

	/**
	 * Determines whether sockets can connect.
	 * 
	 * @param Other - The other socket to test.
	 * @return Whether or not this and Other can connect.
	 */
	EConnectionResult CanConnectToSocket(FTerrainSocket Other) const
	{
		if (SocketIndex != Other.SocketIndex || Length != Other.Length || SecondAngle + Other.FirstAngle > 2 * PI || FirstAngle + Other.SecondAngle > 2 * PI)
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
