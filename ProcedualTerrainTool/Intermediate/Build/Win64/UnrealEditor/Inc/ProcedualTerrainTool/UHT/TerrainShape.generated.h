// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "TerrainShape.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROCEDUALTERRAINTOOL_TerrainShape_generated_h
#error "TerrainShape.generated.h already included, missing '#pragma once' in TerrainShape.h"
#endif
#define PROCEDUALTERRAINTOOL_TerrainShape_generated_h

#define FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Private_TerrainShape_h_28_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FTerrainVertex_Statics; \
	static class UScriptStruct* StaticStruct();


template<> PROCEDUALTERRAINTOOL_API UScriptStruct* StaticStruct<struct FTerrainVertex>();

#define FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Private_TerrainShape_h_144_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FTerrainShapeMergeResult_Statics; \
	static class UScriptStruct* StaticStruct();


template<> PROCEDUALTERRAINTOOL_API UScriptStruct* StaticStruct<struct FTerrainShapeMergeResult>();

#define FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Private_TerrainShape_h_168_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FTerrainShape_Statics; \
	static class UScriptStruct* StaticStruct();


template<> PROCEDUALTERRAINTOOL_API UScriptStruct* StaticStruct<struct FTerrainShape>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Private_TerrainShape_h


#define FOREACH_ENUM_ECONNECTIONRESULT(op) \
	op(EConnectionResult::No) \
	op(EConnectionResult::CheckVertex1) \
	op(EConnectionResult::CheckVertex2) \
	op(EConnectionResult::CheckBoth) \
	op(EConnectionResult::Yes) 

enum class EConnectionResult : uint8;
template<> struct TIsUEnumClass<EConnectionResult> { enum { Value = true }; };
template<> PROCEDUALTERRAINTOOL_API UEnum* StaticEnum<EConnectionResult>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
