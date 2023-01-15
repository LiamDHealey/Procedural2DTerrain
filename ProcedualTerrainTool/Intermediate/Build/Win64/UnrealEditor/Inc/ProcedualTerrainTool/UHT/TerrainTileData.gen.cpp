// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProcedualTerrainTool/Public/TerrainTileData.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTerrainTileData() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
	PROCEDUALTERRAINTOOL_API UClass* Z_Construct_UClass_UTerrainTileData();
	PROCEDUALTERRAINTOOL_API UClass* Z_Construct_UClass_UTerrainTileData_NoRegister();
	UPackage* Z_Construct_UPackage__Script_ProcedualTerrainTool();
// End Cross Module References
	void UTerrainTileData::StaticRegisterNativesUTerrainTileData()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UTerrainTileData);
	UClass* Z_Construct_UClass_UTerrainTileData_NoRegister()
	{
		return UTerrainTileData::StaticClass();
	}
	struct Z_Construct_UClass_UTerrainTileData_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ActorClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_ActorClass;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Verticies_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Verticies_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Verticies;
		static const UECodeGen_Private::FNamePropertyParams NewProp_FaceTypes_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FaceTypes_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_FaceTypes;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UTerrainTileData_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDataAsset,
		(UObject* (*)())Z_Construct_UPackage__Script_ProcedualTerrainTool,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTerrainTileData_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * The data needed for an actor to be used by the terrain generator.\n */" },
		{ "IncludePath", "TerrainTileData.h" },
		{ "ModuleRelativePath", "Public/TerrainTileData.h" },
		{ "ToolTip", "The data needed for an actor to be used by the terrain generator." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTerrainTileData_Statics::NewProp_ActorClass_MetaData[] = {
		{ "Category", "Tile Data" },
		{ "Comment", "//The class of the actor that will be spawned by the terrain generator.\n" },
		{ "ModuleRelativePath", "Public/TerrainTileData.h" },
		{ "ToolTip", "The class of the actor that will be spawned by the terrain generator." },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UTerrainTileData_Statics::NewProp_ActorClass = { "ActorClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UTerrainTileData, ActorClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UTerrainTileData_Statics::NewProp_ActorClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UTerrainTileData_Statics::NewProp_ActorClass_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UTerrainTileData_Statics::NewProp_Verticies_Inner = { "Verticies", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTerrainTileData_Statics::NewProp_Verticies_MetaData[] = {
		{ "Category", "Tile Data" },
		{ "Comment", "//The vertices of the 2D bounds of this actor.\n" },
		{ "ModuleRelativePath", "Public/TerrainTileData.h" },
		{ "ToolTip", "The vertices of the 2D bounds of this actor." },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UTerrainTileData_Statics::NewProp_Verticies = { "Verticies", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UTerrainTileData, Verticies), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UTerrainTileData_Statics::NewProp_Verticies_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UTerrainTileData_Statics::NewProp_Verticies_MetaData)) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UTerrainTileData_Statics::NewProp_FaceTypes_Inner = { "FaceTypes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTerrainTileData_Statics::NewProp_FaceTypes_MetaData[] = {
		{ "Category", "Tile Data" },
		{ "Comment", "//The indexes of each face of the bounds of this actor. Used for determining if tiles can connect.\n" },
		{ "ModuleRelativePath", "Public/TerrainTileData.h" },
		{ "ToolTip", "The indexes of each face of the bounds of this actor. Used for determining if tiles can connect." },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UTerrainTileData_Statics::NewProp_FaceTypes = { "FaceTypes", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UTerrainTileData, FaceTypes), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UTerrainTileData_Statics::NewProp_FaceTypes_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UTerrainTileData_Statics::NewProp_FaceTypes_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UTerrainTileData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTerrainTileData_Statics::NewProp_ActorClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTerrainTileData_Statics::NewProp_Verticies_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTerrainTileData_Statics::NewProp_Verticies,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTerrainTileData_Statics::NewProp_FaceTypes_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTerrainTileData_Statics::NewProp_FaceTypes,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UTerrainTileData_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTerrainTileData>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UTerrainTileData_Statics::ClassParams = {
		&UTerrainTileData::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UTerrainTileData_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UTerrainTileData_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UTerrainTileData_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UTerrainTileData_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UTerrainTileData()
	{
		if (!Z_Registration_Info_UClass_UTerrainTileData.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTerrainTileData.OuterSingleton, Z_Construct_UClass_UTerrainTileData_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UTerrainTileData.OuterSingleton;
	}
	template<> PROCEDUALTERRAINTOOL_API UClass* StaticClass<UTerrainTileData>()
	{
		return UTerrainTileData::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTerrainTileData);
	UTerrainTileData::~UTerrainTileData() {}
	struct Z_CompiledInDeferFile_FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainTileData_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainTileData_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UTerrainTileData, UTerrainTileData::StaticClass, TEXT("UTerrainTileData"), &Z_Registration_Info_UClass_UTerrainTileData, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTerrainTileData), 1970875459U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainTileData_h_302951275(TEXT("/Script/ProcedualTerrainTool"),
		Z_CompiledInDeferFile_FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainTileData_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Public_TerrainTileData_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
