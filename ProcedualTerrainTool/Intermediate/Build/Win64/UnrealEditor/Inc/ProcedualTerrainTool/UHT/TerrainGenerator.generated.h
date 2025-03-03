// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "TerrainGenerator.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FTerrainTileInstanceData;
#ifdef PROCEDUALTERRAINTOOL_TerrainGenerator_generated_h
#error "TerrainGenerator.generated.h already included, missing '#pragma once' in TerrainGenerator.h"
#endif
#define PROCEDUALTERRAINTOOL_TerrainGenerator_generated_h

#define FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h_30_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FTerrainTileInstanceData_Statics; \
	static class UScriptStruct* StaticStruct();


template<> PROCEDUALTERRAINTOOL_API UScriptStruct* StaticStruct<struct FTerrainTileInstanceData>();

#define FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h_62_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FTerrainTileSpawnData_Statics; \
	static class UScriptStruct* StaticStruct();


template<> PROCEDUALTERRAINTOOL_API UScriptStruct* StaticStruct<struct FTerrainTileSpawnData>();

#define FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h_102_SPARSE_DATA
#define FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h_102_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSpawnTile); \
	DECLARE_FUNCTION(execRefreshTiles); \
	DECLARE_FUNCTION(execReset); \
	DECLARE_FUNCTION(execEndGeneration); \
	DECLARE_FUNCTION(execBeginGeneration); \
	DECLARE_FUNCTION(execTest);


#define FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h_102_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSpawnTile); \
	DECLARE_FUNCTION(execRefreshTiles); \
	DECLARE_FUNCTION(execReset); \
	DECLARE_FUNCTION(execEndGeneration); \
	DECLARE_FUNCTION(execBeginGeneration); \
	DECLARE_FUNCTION(execTest);


#define FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h_102_ACCESSORS
#define FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h_102_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATerrainGenerator(); \
	friend struct Z_Construct_UClass_ATerrainGenerator_Statics; \
public: \
	DECLARE_CLASS(ATerrainGenerator, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProcedualTerrainTool"), NO_API) \
	DECLARE_SERIALIZER(ATerrainGenerator)


#define FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h_102_INCLASS \
private: \
	static void StaticRegisterNativesATerrainGenerator(); \
	friend struct Z_Construct_UClass_ATerrainGenerator_Statics; \
public: \
	DECLARE_CLASS(ATerrainGenerator, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProcedualTerrainTool"), NO_API) \
	DECLARE_SERIALIZER(ATerrainGenerator)


#define FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h_102_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATerrainGenerator(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATerrainGenerator) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATerrainGenerator); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATerrainGenerator); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATerrainGenerator(ATerrainGenerator&&); \
	NO_API ATerrainGenerator(const ATerrainGenerator&); \
public: \
	NO_API virtual ~ATerrainGenerator();


#define FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h_102_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATerrainGenerator(ATerrainGenerator&&); \
	NO_API ATerrainGenerator(const ATerrainGenerator&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATerrainGenerator); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATerrainGenerator); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATerrainGenerator) \
	NO_API virtual ~ATerrainGenerator();


#define FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h_99_PROLOG
#define FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h_102_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h_102_SPARSE_DATA \
	FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h_102_RPC_WRAPPERS \
	FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h_102_ACCESSORS \
	FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h_102_INCLASS \
	FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h_102_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h_102_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h_102_SPARSE_DATA \
	FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h_102_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h_102_ACCESSORS \
	FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h_102_INCLASS_NO_PURE_DECLS \
	FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h_102_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROCEDUALTERRAINTOOL_API UClass* StaticClass<class ATerrainGenerator>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainGenerator_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
