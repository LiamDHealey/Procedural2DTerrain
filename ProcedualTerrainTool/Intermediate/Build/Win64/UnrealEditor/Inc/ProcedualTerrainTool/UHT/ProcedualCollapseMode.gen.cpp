// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProcedualTerrainTool/Private/ProcedualCollapseMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProcedualCollapseMode() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	PROCEDUALTERRAINTOOL_API UClass* Z_Construct_UClass_AManualCollapseModeLocationMarker();
	PROCEDUALTERRAINTOOL_API UClass* Z_Construct_UClass_AManualCollapseModeLocationMarker_NoRegister();
	PROCEDUALTERRAINTOOL_API UClass* Z_Construct_UClass_UCircularCollapseMode();
	PROCEDUALTERRAINTOOL_API UClass* Z_Construct_UClass_UCircularCollapseMode_NoRegister();
	PROCEDUALTERRAINTOOL_API UClass* Z_Construct_UClass_UManualCollapseMode();
	PROCEDUALTERRAINTOOL_API UClass* Z_Construct_UClass_UManualCollapseMode_NoRegister();
	PROCEDUALTERRAINTOOL_API UClass* Z_Construct_UClass_UProcedualCollapseMode();
	PROCEDUALTERRAINTOOL_API UClass* Z_Construct_UClass_UProcedualCollapseMode_NoRegister();
	PROCEDUALTERRAINTOOL_API UClass* Z_Construct_UClass_URectangularCollapseMode();
	PROCEDUALTERRAINTOOL_API UClass* Z_Construct_UClass_URectangularCollapseMode_NoRegister();
	UPackage* Z_Construct_UPackage__Script_ProcedualTerrainTool();
// End Cross Module References
	void UProcedualCollapseMode::StaticRegisterNativesUProcedualCollapseMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UProcedualCollapseMode);
	UClass* Z_Construct_UClass_UProcedualCollapseMode_NoRegister()
	{
		return UProcedualCollapseMode::StaticClass();
	}
	struct Z_Construct_UClass_UProcedualCollapseMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TerrainTransform_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_TerrainTransform;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ErrorLocation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UProcedualCollapseMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_ProcedualTerrainTool,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UProcedualCollapseMode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * A mode determining how superpositions are collapsed.\n */" },
		{ "IncludePath", "ProcedualCollapseMode.h" },
		{ "ModuleRelativePath", "Private/ProcedualCollapseMode.h" },
		{ "ToolTip", "A mode determining how superpositions are collapsed." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UProcedualCollapseMode_Statics::NewProp_TerrainTransform_MetaData[] = {
		{ "Comment", "//The transform of the terrain this is collapsing.\n" },
		{ "ModuleRelativePath", "Private/ProcedualCollapseMode.h" },
		{ "ToolTip", "The transform of the terrain this is collapsing." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UProcedualCollapseMode_Statics::NewProp_TerrainTransform = { "TerrainTransform", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UProcedualCollapseMode, TerrainTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(Z_Construct_UClass_UProcedualCollapseMode_Statics::NewProp_TerrainTransform_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UProcedualCollapseMode_Statics::NewProp_TerrainTransform_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UProcedualCollapseMode_Statics::NewProp_ErrorLocation_MetaData[] = {
		{ "Comment", "//The location of any errors. Will be 0,0,0 if there are no errors.\n" },
		{ "ModuleRelativePath", "Private/ProcedualCollapseMode.h" },
		{ "ToolTip", "The location of any errors. Will be 0,0,0 if there are no errors." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UProcedualCollapseMode_Statics::NewProp_ErrorLocation = { "ErrorLocation", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UProcedualCollapseMode, ErrorLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_UProcedualCollapseMode_Statics::NewProp_ErrorLocation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UProcedualCollapseMode_Statics::NewProp_ErrorLocation_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UProcedualCollapseMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UProcedualCollapseMode_Statics::NewProp_TerrainTransform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UProcedualCollapseMode_Statics::NewProp_ErrorLocation,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UProcedualCollapseMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UProcedualCollapseMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UProcedualCollapseMode_Statics::ClassParams = {
		&UProcedualCollapseMode::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UProcedualCollapseMode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UProcedualCollapseMode_Statics::PropPointers),
		0,
		0x001030A1u,
		METADATA_PARAMS(Z_Construct_UClass_UProcedualCollapseMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UProcedualCollapseMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UProcedualCollapseMode()
	{
		if (!Z_Registration_Info_UClass_UProcedualCollapseMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UProcedualCollapseMode.OuterSingleton, Z_Construct_UClass_UProcedualCollapseMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UProcedualCollapseMode.OuterSingleton;
	}
	template<> PROCEDUALTERRAINTOOL_API UClass* StaticClass<UProcedualCollapseMode>()
	{
		return UProcedualCollapseMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UProcedualCollapseMode);
	UProcedualCollapseMode::~UProcedualCollapseMode() {}
	DEFINE_FUNCTION(AManualCollapseModeLocationMarker::execCheakForInvalidMode)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CheakForInvalidMode();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AManualCollapseModeLocationMarker::execPlaceTile)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PlaceTile();
		P_NATIVE_END;
	}
	void AManualCollapseModeLocationMarker::StaticRegisterNativesAManualCollapseModeLocationMarker()
	{
		UClass* Class = AManualCollapseModeLocationMarker::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CheakForInvalidMode", &AManualCollapseModeLocationMarker::execCheakForInvalidMode },
			{ "PlaceTile", &AManualCollapseModeLocationMarker::execPlaceTile },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AManualCollapseModeLocationMarker_CheakForInvalidMode_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AManualCollapseModeLocationMarker_CheakForInvalidMode_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/**\n\x09 * Checks to see if this should still exist and updates the child actor.\n\x09 */" },
		{ "ModuleRelativePath", "Private/ProcedualCollapseMode.h" },
		{ "ToolTip", "Checks to see if this should still exist and updates the child actor." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AManualCollapseModeLocationMarker_CheakForInvalidMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AManualCollapseModeLocationMarker, nullptr, "CheakForInvalidMode", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AManualCollapseModeLocationMarker_CheakForInvalidMode_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AManualCollapseModeLocationMarker_CheakForInvalidMode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AManualCollapseModeLocationMarker_CheakForInvalidMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AManualCollapseModeLocationMarker_CheakForInvalidMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AManualCollapseModeLocationMarker_PlaceTile_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AManualCollapseModeLocationMarker_PlaceTile_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Comment", "/**\n\x09 * Places a tile at the location of this.\n\x09 */" },
		{ "ModuleRelativePath", "Private/ProcedualCollapseMode.h" },
		{ "ToolTip", "Places a tile at the location of this." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AManualCollapseModeLocationMarker_PlaceTile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AManualCollapseModeLocationMarker, nullptr, "PlaceTile", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AManualCollapseModeLocationMarker_PlaceTile_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AManualCollapseModeLocationMarker_PlaceTile_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AManualCollapseModeLocationMarker_PlaceTile()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AManualCollapseModeLocationMarker_PlaceTile_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AManualCollapseModeLocationMarker);
	UClass* Z_Construct_UClass_AManualCollapseModeLocationMarker_NoRegister()
	{
		return AManualCollapseModeLocationMarker::StaticClass();
	}
	struct Z_Construct_UClass_AManualCollapseModeLocationMarker_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AManualCollapseModeLocationMarker_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ProcedualTerrainTool,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AManualCollapseModeLocationMarker_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AManualCollapseModeLocationMarker_CheakForInvalidMode, "CheakForInvalidMode" }, // 3282769511
		{ &Z_Construct_UFunction_AManualCollapseModeLocationMarker_PlaceTile, "PlaceTile" }, // 424049512
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AManualCollapseModeLocationMarker_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Used to select the location to collapse for the manual collapse mode.\n */" },
		{ "IncludePath", "ProcedualCollapseMode.h" },
		{ "ModuleRelativePath", "Private/ProcedualCollapseMode.h" },
		{ "ToolTip", "Used to select the location to collapse for the manual collapse mode." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AManualCollapseModeLocationMarker_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AManualCollapseModeLocationMarker>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AManualCollapseModeLocationMarker_Statics::ClassParams = {
		&AManualCollapseModeLocationMarker::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x009000ACu,
		METADATA_PARAMS(Z_Construct_UClass_AManualCollapseModeLocationMarker_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AManualCollapseModeLocationMarker_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AManualCollapseModeLocationMarker()
	{
		if (!Z_Registration_Info_UClass_AManualCollapseModeLocationMarker.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AManualCollapseModeLocationMarker.OuterSingleton, Z_Construct_UClass_AManualCollapseModeLocationMarker_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AManualCollapseModeLocationMarker.OuterSingleton;
	}
	template<> PROCEDUALTERRAINTOOL_API UClass* StaticClass<AManualCollapseModeLocationMarker>()
	{
		return AManualCollapseModeLocationMarker::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AManualCollapseModeLocationMarker);
	AManualCollapseModeLocationMarker::~AManualCollapseModeLocationMarker() {}
	void UManualCollapseMode::StaticRegisterNativesUManualCollapseMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UManualCollapseMode);
	UClass* Z_Construct_UClass_UManualCollapseMode_NoRegister()
	{
		return UManualCollapseMode::StaticClass();
	}
	struct Z_Construct_UClass_UManualCollapseMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CollapseLocationMarker_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CollapseLocationMarker;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TileIndex_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_TileIndex;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UManualCollapseMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UProcedualCollapseMode,
		(UObject* (*)())Z_Construct_UPackage__Script_ProcedualTerrainTool,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UManualCollapseMode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Collapses 1 superposition at a time at a given location.\n */" },
		{ "DisplayName", "Manual" },
		{ "IncludePath", "ProcedualCollapseMode.h" },
		{ "ModuleRelativePath", "Private/ProcedualCollapseMode.h" },
		{ "ToolTip", "Collapses 1 superposition at a time at a given location." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UManualCollapseMode_Statics::NewProp_CollapseLocationMarker_MetaData[] = {
		{ "Category", "Generation Mode Settings" },
		{ "Comment", "//The location to collapse the superposition at.\n" },
		{ "MakeEditWidget", "true" },
		{ "ModuleRelativePath", "Private/ProcedualCollapseMode.h" },
		{ "ToolTip", "The location to collapse the superposition at." },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UManualCollapseMode_Statics::NewProp_CollapseLocationMarker = { "CollapseLocationMarker", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UManualCollapseMode, CollapseLocationMarker), Z_Construct_UClass_AManualCollapseModeLocationMarker_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UManualCollapseMode_Statics::NewProp_CollapseLocationMarker_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UManualCollapseMode_Statics::NewProp_CollapseLocationMarker_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UManualCollapseMode_Statics::NewProp_TileIndex_MetaData[] = {
		{ "Category", "Generation Mode Settings" },
		{ "Comment", "//The index of the tile to add.\n" },
		{ "ModuleRelativePath", "Private/ProcedualCollapseMode.h" },
		{ "ToolTip", "The index of the tile to add." },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UManualCollapseMode_Statics::NewProp_TileIndex = { "TileIndex", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UManualCollapseMode, TileIndex), METADATA_PARAMS(Z_Construct_UClass_UManualCollapseMode_Statics::NewProp_TileIndex_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UManualCollapseMode_Statics::NewProp_TileIndex_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UManualCollapseMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UManualCollapseMode_Statics::NewProp_CollapseLocationMarker,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UManualCollapseMode_Statics::NewProp_TileIndex,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UManualCollapseMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UManualCollapseMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UManualCollapseMode_Statics::ClassParams = {
		&UManualCollapseMode::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UManualCollapseMode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UManualCollapseMode_Statics::PropPointers),
		0,
		0x001030A0u,
		METADATA_PARAMS(Z_Construct_UClass_UManualCollapseMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UManualCollapseMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UManualCollapseMode()
	{
		if (!Z_Registration_Info_UClass_UManualCollapseMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UManualCollapseMode.OuterSingleton, Z_Construct_UClass_UManualCollapseMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UManualCollapseMode.OuterSingleton;
	}
	template<> PROCEDUALTERRAINTOOL_API UClass* StaticClass<UManualCollapseMode>()
	{
		return UManualCollapseMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UManualCollapseMode);
	UManualCollapseMode::~UManualCollapseMode() {}
	void UCircularCollapseMode::StaticRegisterNativesUCircularCollapseMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCircularCollapseMode);
	UClass* Z_Construct_UClass_UCircularCollapseMode_NoRegister()
	{
		return UCircularCollapseMode::StaticClass();
	}
	struct Z_Construct_UClass_UCircularCollapseMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Radius_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Radius;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCircularCollapseMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UProcedualCollapseMode,
		(UObject* (*)())Z_Construct_UPackage__Script_ProcedualTerrainTool,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCircularCollapseMode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Collapses superpositions until a circle of a given radius is filled.\n */" },
		{ "DisplayName", "Circular" },
		{ "IncludePath", "ProcedualCollapseMode.h" },
		{ "ModuleRelativePath", "Private/ProcedualCollapseMode.h" },
		{ "ToolTip", "Collapses superpositions until a circle of a given radius is filled." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCircularCollapseMode_Statics::NewProp_Radius_MetaData[] = {
		{ "Category", "Generation Mode Settings" },
		{ "Comment", "//The radius of the circle to fill.\n" },
		{ "ModuleRelativePath", "Private/ProcedualCollapseMode.h" },
		{ "ToolTip", "The radius of the circle to fill." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCircularCollapseMode_Statics::NewProp_Radius = { "Radius", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UCircularCollapseMode, Radius), METADATA_PARAMS(Z_Construct_UClass_UCircularCollapseMode_Statics::NewProp_Radius_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCircularCollapseMode_Statics::NewProp_Radius_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCircularCollapseMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCircularCollapseMode_Statics::NewProp_Radius,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCircularCollapseMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCircularCollapseMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UCircularCollapseMode_Statics::ClassParams = {
		&UCircularCollapseMode::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UCircularCollapseMode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UCircularCollapseMode_Statics::PropPointers),
		0,
		0x001030A0u,
		METADATA_PARAMS(Z_Construct_UClass_UCircularCollapseMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCircularCollapseMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCircularCollapseMode()
	{
		if (!Z_Registration_Info_UClass_UCircularCollapseMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCircularCollapseMode.OuterSingleton, Z_Construct_UClass_UCircularCollapseMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UCircularCollapseMode.OuterSingleton;
	}
	template<> PROCEDUALTERRAINTOOL_API UClass* StaticClass<UCircularCollapseMode>()
	{
		return UCircularCollapseMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCircularCollapseMode);
	UCircularCollapseMode::~UCircularCollapseMode() {}
	void URectangularCollapseMode::StaticRegisterNativesURectangularCollapseMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(URectangularCollapseMode);
	UClass* Z_Construct_UClass_URectangularCollapseMode_NoRegister()
	{
		return URectangularCollapseMode::StaticClass();
	}
	struct Z_Construct_UClass_URectangularCollapseMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Extent_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Extent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_URectangularCollapseMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UProcedualCollapseMode,
		(UObject* (*)())Z_Construct_UPackage__Script_ProcedualTerrainTool,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URectangularCollapseMode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Collapses superpositions until a rectangle of a given bounds is filled.\n */" },
		{ "DisplayName", "Rectangular" },
		{ "IncludePath", "ProcedualCollapseMode.h" },
		{ "ModuleRelativePath", "Private/ProcedualCollapseMode.h" },
		{ "ToolTip", "Collapses superpositions until a rectangle of a given bounds is filled." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URectangularCollapseMode_Statics::NewProp_Extent_MetaData[] = {
		{ "Category", "Generation Mode Settings" },
		{ "Comment", "//The extent of the box to fill.\n" },
		{ "ModuleRelativePath", "Private/ProcedualCollapseMode.h" },
		{ "ToolTip", "The extent of the box to fill." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_URectangularCollapseMode_Statics::NewProp_Extent = { "Extent", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(URectangularCollapseMode, Extent), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UClass_URectangularCollapseMode_Statics::NewProp_Extent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URectangularCollapseMode_Statics::NewProp_Extent_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_URectangularCollapseMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URectangularCollapseMode_Statics::NewProp_Extent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_URectangularCollapseMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URectangularCollapseMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_URectangularCollapseMode_Statics::ClassParams = {
		&URectangularCollapseMode::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_URectangularCollapseMode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_URectangularCollapseMode_Statics::PropPointers),
		0,
		0x001030A0u,
		METADATA_PARAMS(Z_Construct_UClass_URectangularCollapseMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_URectangularCollapseMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_URectangularCollapseMode()
	{
		if (!Z_Registration_Info_UClass_URectangularCollapseMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_URectangularCollapseMode.OuterSingleton, Z_Construct_UClass_URectangularCollapseMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_URectangularCollapseMode.OuterSingleton;
	}
	template<> PROCEDUALTERRAINTOOL_API UClass* StaticClass<URectangularCollapseMode>()
	{
		return URectangularCollapseMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(URectangularCollapseMode);
	URectangularCollapseMode::~URectangularCollapseMode() {}
	struct Z_CompiledInDeferFile_FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Private_ProcedualCollapseMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Private_ProcedualCollapseMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UProcedualCollapseMode, UProcedualCollapseMode::StaticClass, TEXT("UProcedualCollapseMode"), &Z_Registration_Info_UClass_UProcedualCollapseMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UProcedualCollapseMode), 3185194344U) },
		{ Z_Construct_UClass_AManualCollapseModeLocationMarker, AManualCollapseModeLocationMarker::StaticClass, TEXT("AManualCollapseModeLocationMarker"), &Z_Registration_Info_UClass_AManualCollapseModeLocationMarker, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AManualCollapseModeLocationMarker), 1127801398U) },
		{ Z_Construct_UClass_UManualCollapseMode, UManualCollapseMode::StaticClass, TEXT("UManualCollapseMode"), &Z_Registration_Info_UClass_UManualCollapseMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UManualCollapseMode), 2719805626U) },
		{ Z_Construct_UClass_UCircularCollapseMode, UCircularCollapseMode::StaticClass, TEXT("UCircularCollapseMode"), &Z_Registration_Info_UClass_UCircularCollapseMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCircularCollapseMode), 3681525548U) },
		{ Z_Construct_UClass_URectangularCollapseMode, URectangularCollapseMode::StaticClass, TEXT("URectangularCollapseMode"), &Z_Registration_Info_UClass_URectangularCollapseMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(URectangularCollapseMode), 3669066443U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Private_ProcedualCollapseMode_h_3169830215(TEXT("/Script/ProcedualTerrainTool"),
		Z_CompiledInDeferFile_FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Private_ProcedualCollapseMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Private_ProcedualCollapseMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
