// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "TerrainShape.h"

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
	ATerrainHandler();

	UFUNCTION(CallInEditor, Meta = (Category = "TerrainHandler"))
	void LogTest();

	UPROPERTY(EditAnywhere)
	TArray<UTerrainSpriteData*> UseableSprites;

	UPROPERTY(EditAnywhere)
	bool bRandomColapse = false;

	UPROPERTY(EditAnywhere, Meta=(EditCondition = "!bRandomColapse"))
	FIntVector CollapseCoords = FIntVector();

	UFUNCTION(CallInEditor, Meta = (Category = "TerrainHandler"))
	void RefreshUseableSpriteData();

	UFUNCTION(CallInEditor, Meta = (Category = "TerrainHandler"))
	void ResetTerrain();

	UFUNCTION(CallInEditor, Meta = (Category = "TerrainHandler"))
	void CollapseSuperPosition();
	void CollapseSuperPosition(int SocketIndex, int ShapeIndex, int FaceIndex);
	void CollapseSuperPosition(int SocketIndex, int ShapeIndex, int FaceIndex, FTerrainShape NewShape, FTerrainShapeMergeResult MergeResult);

	//UPROPERTY(VisibleAnywhere, AdvancedDisplay)
	FTerrainShape CurrentShape = FTerrainShape();

	//UPROPERTY(VisibleAnywhere, AdvancedDisplay)
	TArray<FTerrainShape> SpriteShapes = TArray<FTerrainShape>();

private:
	TArray<TArray<bool>> BaseSuperPositions = TArray<TArray<bool>>();

	TArray<TArray<TArray<bool>>> SuperPositions = TArray<TArray<TArray<bool>>>();

	UFUNCTION()
	void RefreshSuperPositions(int SearchDepth = 0);
};