// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"



#include "Engine/DataAsset.h"
#include "TerrainSpriteData.generated.h"
/**
 * 
 */
UCLASS()
class PROCEDUALTERRAINTOOL_API UTerrainSpriteData : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ActorClass;

	UPROPERTY(EditAnywhere)
	TArray<FVector2D> Verticies;

	UPROPERTY(EditAnywhere)
	TArray<int> FaceIndices;
};
