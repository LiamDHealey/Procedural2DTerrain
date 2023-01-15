// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProcedualTerrainTool/Public/TerrainGenerator.h"
#include "Engine/Classes/Engine/EngineTypes.h"
#include "ProcedualTerrainTool/Private/TerrainShape.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTerrainGenerator() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRandomStream();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTimerHandle();
	PROCEDUALTERRAINTOOL_API UClass* Z_Construct_UClass_ATerrainGenerator();
	PROCEDUALTERRAINTOOL_API UClass* Z_Construct_UClass_ATerrainGenerator_NoRegister();
	PROCEDUALTERRAINTOOL_API UClass* Z_Construct_UClass_UProcedualCollapseMode_NoRegister();
	PROCEDUALTERRAINTOOL_API UClass* Z_Construct_UClass_UTerrainTileData_NoRegister();
	PROCEDUALTERRAINTOOL_API UScriptStruct* Z_Construct_UScriptStruct_FTerrainShape();
	PROCEDUALTERRAINTOOL_API UScriptStruct* Z_Construct_UScriptStruct_FTerrainShapeMergeResult();
	PROCEDUALTERRAINTOOL_API UScriptStruct* Z_Construct_UScriptStruct_FTerrainTileInstanceData();
	PROCEDUALTERRAINTOOL_API UScriptStruct* Z_Construct_UScriptStruct_FTerrainTileSpawnData();
	UPackage* Z_Construct_UPackage__Script_ProcedualTerrainTool();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_TerrainTileInstanceData;
class UScriptStruct* FTerrainTileInstanceData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_TerrainTileInstanceData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_TerrainTileInstanceData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FTerrainTileInstanceData, Z_Construct_UPackage__Script_ProcedualTerrainTool(), TEXT("TerrainTileInstanceData"));
	}
	return Z_Registration_Info_UScriptStruct_TerrainTileInstanceData.OuterSingleton;
}
template<> PROCEDUALTERRAINTOOL_API UScriptStruct* StaticStruct<FTerrainTileInstanceData>()
{
	return FTerrainTileInstanceData::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FTerrainTileInstanceData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ShapeIndex_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_ShapeIndex;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MergeResult_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_MergeResult;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTerrainTileInstanceData_Statics::Struct_MetaDataParams[] = {
		{ "Comment", "/**\n * Information about a terrain tile and location.\n */" },
		{ "ModuleRelativePath", "Public/TerrainGenerator.h" },
		{ "ToolTip", "Information about a terrain tile and location." },
	};
#endif
	void* Z_Construct_UScriptStruct_FTerrainTileInstanceData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FTerrainTileInstanceData>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTerrainTileInstanceData_Statics::NewProp_ShapeIndex_MetaData[] = {
		{ "Comment", "//The index of this tile.\n" },
		{ "ModuleRelativePath", "Public/TerrainGenerator.h" },
		{ "ToolTip", "The index of this tile." },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FTerrainTileInstanceData_Statics::NewProp_ShapeIndex = { "ShapeIndex", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FTerrainTileInstanceData, ShapeIndex), METADATA_PARAMS(Z_Construct_UScriptStruct_FTerrainTileInstanceData_Statics::NewProp_ShapeIndex_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTerrainTileInstanceData_Statics::NewProp_ShapeIndex_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTerrainTileInstanceData_Statics::NewProp_MergeResult_MetaData[] = {
		{ "Comment", "//The merge result that created this tile.\n" },
		{ "ModuleRelativePath", "Public/TerrainGenerator.h" },
		{ "ToolTip", "The merge result that created this tile." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FTerrainTileInstanceData_Statics::NewProp_MergeResult = { "MergeResult", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FTerrainTileInstanceData, MergeResult), Z_Construct_UScriptStruct_FTerrainShapeMergeResult, METADATA_PARAMS(Z_Construct_UScriptStruct_FTerrainTileInstanceData_Statics::NewProp_MergeResult_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTerrainTileInstanceData_Statics::NewProp_MergeResult_MetaData)) }; // 2116728006
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FTerrainTileInstanceData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTerrainTileInstanceData_Statics::NewProp_ShapeIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTerrainTileInstanceData_Statics::NewProp_MergeResult,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FTerrainTileInstanceData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_ProcedualTerrainTool,
		nullptr,
		&NewStructOps,
		"TerrainTileInstanceData",
		sizeof(FTerrainTileInstanceData),
		alignof(FTerrainTileInstanceData),
		Z_Construct_UScriptStruct_FTerrainTileInstanceData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTerrainTileInstanceData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FTerrainTileInstanceData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTerrainTileInstanceData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FTerrainTileInstanceData()
	{
		if (!Z_Registration_Info_UScriptStruct_TerrainTileInstanceData.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_TerrainTileInstanceData.InnerSingleton, Z_Construct_UScriptStruct_FTerrainTileInstanceData_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_TerrainTileInstanceData.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_TerrainTileSpawnData;
class UScriptStruct* FTerrainTileSpawnData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_TerrainTileSpawnData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_TerrainTileSpawnData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FTerrainTileSpawnData, Z_Construct_UPackage__Script_ProcedualTerrainTool(), TEXT("TerrainTileSpawnData"));
	}
	return Z_Registration_Info_UScriptStruct_TerrainTileSpawnData.OuterSingleton;
}
template<> PROCEDUALTERRAINTOOL_API UScriptStruct* StaticStruct<FTerrainTileSpawnData>()
{
	return FTerrainTileSpawnData::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FTerrainTileSpawnData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TileData_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TileData;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpawnWeight_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_SpawnWeight;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTerrainTileSpawnData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Information needed to spawn a terrain tile.\n */" },
		{ "ModuleRelativePath", "Public/TerrainGenerator.h" },
		{ "ToolTip", "Information needed to spawn a terrain tile." },
	};
#endif
	void* Z_Construct_UScriptStruct_FTerrainTileSpawnData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FTerrainTileSpawnData>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTerrainTileSpawnData_Statics::NewProp_TileData_MetaData[] = {
		{ "Category", "Tile Data" },
		{ "Comment", "//The data of this tile.\n" },
		{ "ModuleRelativePath", "Public/TerrainGenerator.h" },
		{ "ToolTip", "The data of this tile." },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FTerrainTileSpawnData_Statics::NewProp_TileData = { "TileData", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FTerrainTileSpawnData, TileData), Z_Construct_UClass_UTerrainTileData_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FTerrainTileSpawnData_Statics::NewProp_TileData_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTerrainTileSpawnData_Statics::NewProp_TileData_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTerrainTileSpawnData_Statics::NewProp_SpawnWeight_MetaData[] = {
		{ "Category", "Tile Data" },
		{ "ClampMin", "0" },
		{ "Comment", "//How likely this tile is to spawn.\n" },
		{ "ModuleRelativePath", "Public/TerrainGenerator.h" },
		{ "ToolTip", "How likely this tile is to spawn." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FTerrainTileSpawnData_Statics::NewProp_SpawnWeight = { "SpawnWeight", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FTerrainTileSpawnData, SpawnWeight), METADATA_PARAMS(Z_Construct_UScriptStruct_FTerrainTileSpawnData_Statics::NewProp_SpawnWeight_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTerrainTileSpawnData_Statics::NewProp_SpawnWeight_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FTerrainTileSpawnData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTerrainTileSpawnData_Statics::NewProp_TileData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTerrainTileSpawnData_Statics::NewProp_SpawnWeight,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FTerrainTileSpawnData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_ProcedualTerrainTool,
		nullptr,
		&NewStructOps,
		"TerrainTileSpawnData",
		sizeof(FTerrainTileSpawnData),
		alignof(FTerrainTileSpawnData),
		Z_Construct_UScriptStruct_FTerrainTileSpawnData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTerrainTileSpawnData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FTerrainTileSpawnData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTerrainTileSpawnData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FTerrainTileSpawnData()
	{
		if (!Z_Registration_Info_UScriptStruct_TerrainTileSpawnData.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_TerrainTileSpawnData.InnerSingleton, Z_Construct_UScriptStruct_FTerrainTileSpawnData_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_TerrainTileSpawnData.InnerSingleton;
	}
	DEFINE_FUNCTION(ATerrainGenerator::execSpawnTile)
	{
		P_GET_STRUCT(FTerrainTileInstanceData,Z_Param_TileData);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SpawnTile(Z_Param_TileData);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATerrainGenerator::execRefreshTiles)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RefreshTiles();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATerrainGenerator::execReset)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Reset();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATerrainGenerator::execEndGeneration)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EndGeneration();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATerrainGenerator::execBeginGeneration)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BeginGeneration();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATerrainGenerator::execTest)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Test();
		P_NATIVE_END;
	}
	void ATerrainGenerator::StaticRegisterNativesATerrainGenerator()
	{
		UClass* Class = ATerrainGenerator::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BeginGeneration", &ATerrainGenerator::execBeginGeneration },
			{ "EndGeneration", &ATerrainGenerator::execEndGeneration },
			{ "RefreshTiles", &ATerrainGenerator::execRefreshTiles },
			{ "Reset", &ATerrainGenerator::execReset },
			{ "SpawnTile", &ATerrainGenerator::execSpawnTile },
			{ "Test", &ATerrainGenerator::execTest },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ATerrainGenerator_BeginGeneration_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATerrainGenerator_BeginGeneration_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Terrain Generator" },
		{ "Comment", "/**\n\x09 * Begins the terrain generation process.\n\x09 */" },
		{ "ModuleRelativePath", "Public/TerrainGenerator.h" },
		{ "ToolTip", "Begins the terrain generation process." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATerrainGenerator_BeginGeneration_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATerrainGenerator, nullptr, "BeginGeneration", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATerrainGenerator_BeginGeneration_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATerrainGenerator_BeginGeneration_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATerrainGenerator_BeginGeneration()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATerrainGenerator_BeginGeneration_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATerrainGenerator_EndGeneration_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATerrainGenerator_EndGeneration_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Terrain Generator" },
		{ "Comment", "/**\n\x09 * Stops the generation before the terrain is finished generating.\n\x09 */" },
		{ "ModuleRelativePath", "Public/TerrainGenerator.h" },
		{ "ToolTip", "Stops the generation before the terrain is finished generating." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATerrainGenerator_EndGeneration_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATerrainGenerator, nullptr, "EndGeneration", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATerrainGenerator_EndGeneration_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATerrainGenerator_EndGeneration_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATerrainGenerator_EndGeneration()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATerrainGenerator_EndGeneration_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATerrainGenerator_RefreshTiles_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATerrainGenerator_RefreshTiles_Statics::Function_MetaDataParams[] = {
		{ "Category", "Terrain Generator" },
		{ "Comment", "/**\n\x09 * Spawns any new tiles created by the worker and shuts down worker if complete.\n\x09 */" },
		{ "ModuleRelativePath", "Public/TerrainGenerator.h" },
		{ "ToolTip", "Spawns any new tiles created by the worker and shuts down worker if complete." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATerrainGenerator_RefreshTiles_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATerrainGenerator, nullptr, "RefreshTiles", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATerrainGenerator_RefreshTiles_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATerrainGenerator_RefreshTiles_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATerrainGenerator_RefreshTiles()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATerrainGenerator_RefreshTiles_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATerrainGenerator_Reset_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATerrainGenerator_Reset_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Terrain Generator" },
		{ "Comment", "/**\n\x09 * Resets the generation process and deletes all actors already spawned.\n\x09 */" },
		{ "ModuleRelativePath", "Public/TerrainGenerator.h" },
		{ "ToolTip", "Resets the generation process and deletes all actors already spawned." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATerrainGenerator_Reset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATerrainGenerator, nullptr, "Reset", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATerrainGenerator_Reset_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATerrainGenerator_Reset_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATerrainGenerator_Reset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATerrainGenerator_Reset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATerrainGenerator_SpawnTile_Statics
	{
		struct TerrainGenerator_eventSpawnTile_Parms
		{
			FTerrainTileInstanceData TileData;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_TileData;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATerrainGenerator_SpawnTile_Statics::NewProp_TileData = { "TileData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TerrainGenerator_eventSpawnTile_Parms, TileData), Z_Construct_UScriptStruct_FTerrainTileInstanceData, METADATA_PARAMS(nullptr, 0) }; // 1979086913
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATerrainGenerator_SpawnTile_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATerrainGenerator_SpawnTile_Statics::NewProp_TileData,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATerrainGenerator_SpawnTile_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/**\n\x09 * Spawns a single tile.\n\x09 * \n\x09 * @param TileData - The data needed to know where and what to spawn.\n\x09 */" },
		{ "ModuleRelativePath", "Public/TerrainGenerator.h" },
		{ "ToolTip", "Spawns a single tile.\n\n@param TileData - The data needed to know where and what to spawn." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATerrainGenerator_SpawnTile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATerrainGenerator, nullptr, "SpawnTile", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATerrainGenerator_SpawnTile_Statics::TerrainGenerator_eventSpawnTile_Parms), Z_Construct_UFunction_ATerrainGenerator_SpawnTile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATerrainGenerator_SpawnTile_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATerrainGenerator_SpawnTile_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATerrainGenerator_SpawnTile_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATerrainGenerator_SpawnTile()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATerrainGenerator_SpawnTile_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATerrainGenerator_Test_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATerrainGenerator_Test_Statics::Function_MetaDataParams[] = {
		{ "Category", "Terrain Generator" },
		{ "Comment", "/*CallInEditor, BlueprintCallable,*/" },
		{ "ModuleRelativePath", "Public/TerrainGenerator.h" },
		{ "ToolTip", "CallInEditor, BlueprintCallable," },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATerrainGenerator_Test_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATerrainGenerator, nullptr, "Test", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATerrainGenerator_Test_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATerrainGenerator_Test_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATerrainGenerator_Test()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATerrainGenerator_Test_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATerrainGenerator);
	UClass* Z_Construct_UClass_ATerrainGenerator_NoRegister()
	{
		return ATerrainGenerator::StaticClass();
	}
	struct Z_Construct_UClass_ATerrainGenerator_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnableTiles_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpawnableTiles_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_SpawnableTiles;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GenerationMode_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_GenerationMode;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bGenerateUntilSuccessful_MetaData[];
#endif
		static void NewProp_bGenerateUntilSuccessful_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bGenerateUntilSuccessful;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PredictionDepth_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_PredictionDepth;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseManualSeed_MetaData[];
#endif
		static void NewProp_bUseManualSeed_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseManualSeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Seed_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Seed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TerrainShape_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_TerrainShape;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TileRefreshTimerHandle_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_TileRefreshTimerHandle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NumberOfTilesSpawned_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_NumberOfTilesSpawned;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TileActors_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TileActors_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_TileActors;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATerrainGenerator_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ProcedualTerrainTool,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ATerrainGenerator_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ATerrainGenerator_BeginGeneration, "BeginGeneration" }, // 506989023
		{ &Z_Construct_UFunction_ATerrainGenerator_EndGeneration, "EndGeneration" }, // 3652218625
		{ &Z_Construct_UFunction_ATerrainGenerator_RefreshTiles, "RefreshTiles" }, // 2740287707
		{ &Z_Construct_UFunction_ATerrainGenerator_Reset, "Reset" }, // 4115990962
		{ &Z_Construct_UFunction_ATerrainGenerator_SpawnTile, "SpawnTile" }, // 1955403444
		{ &Z_Construct_UFunction_ATerrainGenerator_Test, "Test" }, // 1834856770
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * A tool for generating terrain. Takes in a set of tiles and can connect them together to form terrain.\n */" },
		{ "IncludePath", "TerrainGenerator.h" },
		{ "ModuleRelativePath", "Public/TerrainGenerator.h" },
		{ "ToolTip", "A tool for generating terrain. Takes in a set of tiles and can connect them together to form terrain." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_SpawnableTiles_Inner = { "SpawnableTiles", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UScriptStruct_FTerrainTileSpawnData, METADATA_PARAMS(nullptr, 0) }; // 3951561433
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_SpawnableTiles_MetaData[] = {
		{ "Category", "Terrain Generator" },
		{ "Comment", "//The set of tiles that this will use when generating terrain.\n" },
		{ "ModuleRelativePath", "Public/TerrainGenerator.h" },
		{ "ToolTip", "The set of tiles that this will use when generating terrain." },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_SpawnableTiles = { "SpawnableTiles", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATerrainGenerator, SpawnableTiles), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_SpawnableTiles_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_SpawnableTiles_MetaData)) }; // 3951561433
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_GenerationMode_MetaData[] = {
		{ "Category", "Terrain Generator" },
		{ "Comment", "//The method and shape in which the terrain will be generated.\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/TerrainGenerator.h" },
		{ "ToolTip", "The method and shape in which the terrain will be generated." },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_GenerationMode = { "GenerationMode", nullptr, (EPropertyFlags)0x0012000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATerrainGenerator, GenerationMode), Z_Construct_UClass_UProcedualCollapseMode_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_GenerationMode_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_GenerationMode_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bGenerateUntilSuccessful_MetaData[] = {
		{ "Category", "Terrain Generator" },
		{ "Comment", "//The method and shape in which the terrain will be generated.\n" },
		{ "ModuleRelativePath", "Public/TerrainGenerator.h" },
		{ "ToolTip", "The method and shape in which the terrain will be generated." },
	};
#endif
	void Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bGenerateUntilSuccessful_SetBit(void* Obj)
	{
		((ATerrainGenerator*)Obj)->bGenerateUntilSuccessful = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bGenerateUntilSuccessful = { "bGenerateUntilSuccessful", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(ATerrainGenerator), &Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bGenerateUntilSuccessful_SetBit, METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bGenerateUntilSuccessful_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bGenerateUntilSuccessful_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_PredictionDepth_MetaData[] = {
		{ "Category", "Terrain Generator" },
		{ "ClampMax", "4" },
		{ "ClampMin", "0" },
		{ "Comment", "//How many steps into the future to look when generating terrain. Higher numbers slow generation but reduce risk of generation failure.\n" },
		{ "ModuleRelativePath", "Public/TerrainGenerator.h" },
		{ "ToolTip", "How many steps into the future to look when generating terrain. Higher numbers slow generation but reduce risk of generation failure." },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_PredictionDepth = { "PredictionDepth", nullptr, (EPropertyFlags)0x0010040000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATerrainGenerator, PredictionDepth), METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_PredictionDepth_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_PredictionDepth_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseManualSeed_MetaData[] = {
		{ "Category", "Terrain Generator" },
		{ "Comment", "//Whether or not to use the manually entered seed when generating terrain.\n" },
		{ "EditCondition", "!bGenerateUntilSuccessful" },
		{ "ModuleRelativePath", "Public/TerrainGenerator.h" },
		{ "ToolTip", "Whether or not to use the manually entered seed when generating terrain." },
	};
#endif
	void Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseManualSeed_SetBit(void* Obj)
	{
		((ATerrainGenerator*)Obj)->bUseManualSeed = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseManualSeed = { "bUseManualSeed", nullptr, (EPropertyFlags)0x0010040000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(ATerrainGenerator), &Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseManualSeed_SetBit, METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseManualSeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseManualSeed_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Seed_MetaData[] = {
		{ "Category", "Terrain Generator" },
		{ "Comment", "//Whether or not to use the manually entered seed when generating terrain.\n" },
		{ "EditCondition", "!bGenerateUntilSuccessful && bUseManualSeed" },
		{ "ModuleRelativePath", "Public/TerrainGenerator.h" },
		{ "ToolTip", "Whether or not to use the manually entered seed when generating terrain." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Seed = { "Seed", nullptr, (EPropertyFlags)0x0010040000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATerrainGenerator, Seed), Z_Construct_UScriptStruct_FRandomStream, METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Seed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Seed_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_TerrainShape_MetaData[] = {
		{ "Comment", "//The current shape of the terrain.\n" },
		{ "ModuleRelativePath", "Public/TerrainGenerator.h" },
		{ "ToolTip", "The current shape of the terrain." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_TerrainShape = { "TerrainShape", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATerrainGenerator, TerrainShape), Z_Construct_UScriptStruct_FTerrainShape, METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_TerrainShape_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_TerrainShape_MetaData)) }; // 2577067158
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_TileRefreshTimerHandle_MetaData[] = {
		{ "Comment", "//The timer that periodically updates the tiles to match the worker.\n" },
		{ "ModuleRelativePath", "Public/TerrainGenerator.h" },
		{ "ToolTip", "The timer that periodically updates the tiles to match the worker." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_TileRefreshTimerHandle = { "TileRefreshTimerHandle", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATerrainGenerator, TileRefreshTimerHandle), Z_Construct_UScriptStruct_FTimerHandle, METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_TileRefreshTimerHandle_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_TileRefreshTimerHandle_MetaData)) }; // 4017759265
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_NumberOfTilesSpawned_MetaData[] = {
		{ "Comment", "//The number of tiles currently spawned.\n" },
		{ "ModuleRelativePath", "Public/TerrainGenerator.h" },
		{ "ToolTip", "The number of tiles currently spawned." },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_NumberOfTilesSpawned = { "NumberOfTilesSpawned", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATerrainGenerator, NumberOfTilesSpawned), METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_NumberOfTilesSpawned_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_NumberOfTilesSpawned_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_TileActors_ElementProp = { "TileActors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_TileActors_MetaData[] = {
		{ "Comment", "//All of the actors spawned by this.\n" },
		{ "ModuleRelativePath", "Public/TerrainGenerator.h" },
		{ "ToolTip", "All of the actors spawned by this." },
	};
#endif
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_TileActors = { "TileActors", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATerrainGenerator, TileActors), METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_TileActors_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_TileActors_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATerrainGenerator_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_SpawnableTiles_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_SpawnableTiles,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_GenerationMode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bGenerateUntilSuccessful,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_PredictionDepth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseManualSeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Seed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_TerrainShape,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_TileRefreshTimerHandle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_NumberOfTilesSpawned,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_TileActors_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_TileActors,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATerrainGenerator_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATerrainGenerator>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ATerrainGenerator_Statics::ClassParams = {
		&ATerrainGenerator::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ATerrainGenerator_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATerrainGenerator()
	{
		if (!Z_Registration_Info_UClass_ATerrainGenerator.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATerrainGenerator.OuterSingleton, Z_Construct_UClass_ATerrainGenerator_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ATerrainGenerator.OuterSingleton;
	}
	template<> PROCEDUALTERRAINTOOL_API UClass* StaticClass<ATerrainGenerator>()
	{
		return ATerrainGenerator::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATerrainGenerator);
	ATerrainGenerator::~ATerrainGenerator() {}
	struct Z_CompiledInDeferFile_FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h_Statics::ScriptStructInfo[] = {
		{ FTerrainTileInstanceData::StaticStruct, Z_Construct_UScriptStruct_FTerrainTileInstanceData_Statics::NewStructOps, TEXT("TerrainTileInstanceData"), &Z_Registration_Info_UScriptStruct_TerrainTileInstanceData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FTerrainTileInstanceData), 1979086913U) },
		{ FTerrainTileSpawnData::StaticStruct, Z_Construct_UScriptStruct_FTerrainTileSpawnData_Statics::NewStructOps, TEXT("TerrainTileSpawnData"), &Z_Registration_Info_UScriptStruct_TerrainTileSpawnData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FTerrainTileSpawnData), 3951561433U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ATerrainGenerator, ATerrainGenerator::StaticClass, TEXT("ATerrainGenerator"), &Z_Registration_Info_UClass_ATerrainGenerator, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATerrainGenerator), 2643290754U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h_2757236025(TEXT("/Script/ProcedualTerrainTool"),
		Z_CompiledInDeferFile_FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
