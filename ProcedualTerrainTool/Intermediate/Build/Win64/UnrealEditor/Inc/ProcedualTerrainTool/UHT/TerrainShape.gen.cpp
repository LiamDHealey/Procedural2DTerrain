// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProcedualTerrainTool/Private/TerrainShape.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTerrainShape() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	PROCEDUALTERRAINTOOL_API UEnum* Z_Construct_UEnum_ProcedualTerrainTool_EConnectionResult();
	PROCEDUALTERRAINTOOL_API UScriptStruct* Z_Construct_UScriptStruct_FTerrainShape();
	PROCEDUALTERRAINTOOL_API UScriptStruct* Z_Construct_UScriptStruct_FTerrainShapeMergeResult();
	PROCEDUALTERRAINTOOL_API UScriptStruct* Z_Construct_UScriptStruct_FTerrainVertex();
	UPackage* Z_Construct_UPackage__Script_ProcedualTerrainTool();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EConnectionResult;
	static UEnum* EConnectionResult_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EConnectionResult.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EConnectionResult.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ProcedualTerrainTool_EConnectionResult, Z_Construct_UPackage__Script_ProcedualTerrainTool(), TEXT("EConnectionResult"));
		}
		return Z_Registration_Info_UEnum_EConnectionResult.OuterSingleton;
	}
	template<> PROCEDUALTERRAINTOOL_API UEnum* StaticEnum<EConnectionResult>()
	{
		return EConnectionResult_StaticEnum();
	}
	struct Z_Construct_UEnum_ProcedualTerrainTool_EConnectionResult_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_ProcedualTerrainTool_EConnectionResult_Statics::Enumerators[] = {
		{ "EConnectionResult::No", (int64)EConnectionResult::No },
		{ "EConnectionResult::CheckVertex1", (int64)EConnectionResult::CheckVertex1 },
		{ "EConnectionResult::CheckVertex2", (int64)EConnectionResult::CheckVertex2 },
		{ "EConnectionResult::CheckBoth", (int64)EConnectionResult::CheckBoth },
		{ "EConnectionResult::Yes", (int64)EConnectionResult::Yes },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_ProcedualTerrainTool_EConnectionResult_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "CheckBoth.Name", "EConnectionResult::CheckBoth" },
		{ "CheckVertex1.Name", "EConnectionResult::CheckVertex1" },
		{ "CheckVertex2.Name", "EConnectionResult::CheckVertex2" },
		{ "Comment", "/**\n * A socket's connectivity state.\n */" },
		{ "ModuleRelativePath", "Private/TerrainShape.h" },
		{ "No.Name", "EConnectionResult::No" },
		{ "ToolTip", "A socket's connectivity state." },
		{ "Yes.Name", "EConnectionResult::Yes" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ProcedualTerrainTool_EConnectionResult_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_ProcedualTerrainTool,
		nullptr,
		"EConnectionResult",
		"EConnectionResult",
		Z_Construct_UEnum_ProcedualTerrainTool_EConnectionResult_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_ProcedualTerrainTool_EConnectionResult_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_ProcedualTerrainTool_EConnectionResult_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_ProcedualTerrainTool_EConnectionResult_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_ProcedualTerrainTool_EConnectionResult()
	{
		if (!Z_Registration_Info_UEnum_EConnectionResult.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EConnectionResult.InnerSingleton, Z_Construct_UEnum_ProcedualTerrainTool_EConnectionResult_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EConnectionResult.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_TerrainVertex;
class UScriptStruct* FTerrainVertex::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_TerrainVertex.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_TerrainVertex.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FTerrainVertex, Z_Construct_UPackage__Script_ProcedualTerrainTool(), TEXT("TerrainVertex"));
	}
	return Z_Registration_Info_UScriptStruct_TerrainVertex.OuterSingleton;
}
template<> PROCEDUALTERRAINTOOL_API UScriptStruct* StaticStruct<FTerrainVertex>()
{
	return FTerrainVertex::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FTerrainVertex_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Type_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_Type;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Length_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Length;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Angle_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_Angle;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTerrainVertex_Statics::Struct_MetaDataParams[] = {
		{ "Comment", "/**\n * A socket storing data relevant for terrain piece connections.\n */" },
		{ "ModuleRelativePath", "Private/TerrainShape.h" },
		{ "ToolTip", "A socket storing data relevant for terrain piece connections." },
	};
#endif
	void* Z_Construct_UScriptStruct_FTerrainVertex_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FTerrainVertex>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTerrainVertex_Statics::NewProp_Type_MetaData[] = {
		{ "Comment", "//The type of edge after this vertex. Will only connect to vertices of the same type.\n" },
		{ "ModuleRelativePath", "Private/TerrainShape.h" },
		{ "ToolTip", "The type of edge after this vertex. Will only connect to vertices of the same type." },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FTerrainVertex_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FTerrainVertex, Type), METADATA_PARAMS(Z_Construct_UScriptStruct_FTerrainVertex_Statics::NewProp_Type_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTerrainVertex_Statics::NewProp_Type_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTerrainVertex_Statics::NewProp_Location_MetaData[] = {
		{ "Comment", "//The location of the vertex relative to the terrain.\n" },
		{ "ModuleRelativePath", "Private/TerrainShape.h" },
		{ "ToolTip", "The location of the vertex relative to the terrain." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FTerrainVertex_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FTerrainVertex, Location), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UScriptStruct_FTerrainVertex_Statics::NewProp_Location_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTerrainVertex_Statics::NewProp_Location_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTerrainVertex_Statics::NewProp_Length_MetaData[] = {
		{ "Comment", "//The length of the edge after this vertex. Will only connect to vertices with the same length.\n" },
		{ "ModuleRelativePath", "Private/TerrainShape.h" },
		{ "ToolTip", "The length of the edge after this vertex. Will only connect to vertices with the same length." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FTerrainVertex_Statics::NewProp_Length = { "Length", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FTerrainVertex, Length), METADATA_PARAMS(Z_Construct_UScriptStruct_FTerrainVertex_Statics::NewProp_Length_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTerrainVertex_Statics::NewProp_Length_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTerrainVertex_Statics::NewProp_Angle_MetaData[] = {
		{ "Comment", "//The interior angle at the vertex.\n" },
		{ "ModuleRelativePath", "Private/TerrainShape.h" },
		{ "ToolTip", "The interior angle at the vertex." },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FTerrainVertex_Statics::NewProp_Angle = { "Angle", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FTerrainVertex, Angle), METADATA_PARAMS(Z_Construct_UScriptStruct_FTerrainVertex_Statics::NewProp_Angle_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTerrainVertex_Statics::NewProp_Angle_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FTerrainVertex_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTerrainVertex_Statics::NewProp_Type,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTerrainVertex_Statics::NewProp_Location,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTerrainVertex_Statics::NewProp_Length,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTerrainVertex_Statics::NewProp_Angle,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FTerrainVertex_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_ProcedualTerrainTool,
		nullptr,
		&NewStructOps,
		"TerrainVertex",
		sizeof(FTerrainVertex),
		alignof(FTerrainVertex),
		Z_Construct_UScriptStruct_FTerrainVertex_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTerrainVertex_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FTerrainVertex_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTerrainVertex_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FTerrainVertex()
	{
		if (!Z_Registration_Info_UScriptStruct_TerrainVertex.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_TerrainVertex.InnerSingleton, Z_Construct_UScriptStruct_FTerrainVertex_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_TerrainVertex.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_TerrainShapeMergeResult;
class UScriptStruct* FTerrainShapeMergeResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_TerrainShapeMergeResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_TerrainShapeMergeResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FTerrainShapeMergeResult, Z_Construct_UPackage__Script_ProcedualTerrainTool(), TEXT("TerrainShapeMergeResult"));
	}
	return Z_Registration_Info_UScriptStruct_TerrainShapeMergeResult.OuterSingleton;
}
template<> PROCEDUALTERRAINTOOL_API UScriptStruct* StaticStruct<FTerrainShapeMergeResult>()
{
	return FTerrainShapeMergeResult::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FTerrainShapeMergeResult_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Offset_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_Offset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Growth_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_Growth;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Shrinkage_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_Shrinkage;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTerrainShapeMergeResult_Statics::Struct_MetaDataParams[] = {
		{ "Comment", "/**\n * Stores the results of a terrain shape merge.\n */" },
		{ "ModuleRelativePath", "Private/TerrainShape.h" },
		{ "ToolTip", "Stores the results of a terrain shape merge." },
	};
#endif
	void* Z_Construct_UScriptStruct_FTerrainShapeMergeResult_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FTerrainShapeMergeResult>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTerrainShapeMergeResult_Statics::NewProp_Offset_MetaData[] = {
		{ "Comment", "//The change of the indices of the original shape.\n" },
		{ "ModuleRelativePath", "Private/TerrainShape.h" },
		{ "ToolTip", "The change of the indices of the original shape." },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FTerrainShapeMergeResult_Statics::NewProp_Offset = { "Offset", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FTerrainShapeMergeResult, Offset), METADATA_PARAMS(Z_Construct_UScriptStruct_FTerrainShapeMergeResult_Statics::NewProp_Offset_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTerrainShapeMergeResult_Statics::NewProp_Offset_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTerrainShapeMergeResult_Statics::NewProp_Growth_MetaData[] = {
		{ "Comment", "//The number of new vertices gained during the merge.\n" },
		{ "ModuleRelativePath", "Private/TerrainShape.h" },
		{ "ToolTip", "The number of new vertices gained during the merge." },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FTerrainShapeMergeResult_Statics::NewProp_Growth = { "Growth", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FTerrainShapeMergeResult, Growth), METADATA_PARAMS(Z_Construct_UScriptStruct_FTerrainShapeMergeResult_Statics::NewProp_Growth_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTerrainShapeMergeResult_Statics::NewProp_Growth_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTerrainShapeMergeResult_Statics::NewProp_Shrinkage_MetaData[] = {
		{ "Comment", "//The number of old vertices lost during the merge.\n" },
		{ "ModuleRelativePath", "Private/TerrainShape.h" },
		{ "ToolTip", "The number of old vertices lost during the merge." },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FTerrainShapeMergeResult_Statics::NewProp_Shrinkage = { "Shrinkage", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FTerrainShapeMergeResult, Shrinkage), METADATA_PARAMS(Z_Construct_UScriptStruct_FTerrainShapeMergeResult_Statics::NewProp_Shrinkage_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTerrainShapeMergeResult_Statics::NewProp_Shrinkage_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FTerrainShapeMergeResult_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTerrainShapeMergeResult_Statics::NewProp_Offset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTerrainShapeMergeResult_Statics::NewProp_Growth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTerrainShapeMergeResult_Statics::NewProp_Shrinkage,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FTerrainShapeMergeResult_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_ProcedualTerrainTool,
		nullptr,
		&NewStructOps,
		"TerrainShapeMergeResult",
		sizeof(FTerrainShapeMergeResult),
		alignof(FTerrainShapeMergeResult),
		Z_Construct_UScriptStruct_FTerrainShapeMergeResult_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTerrainShapeMergeResult_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FTerrainShapeMergeResult_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTerrainShapeMergeResult_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FTerrainShapeMergeResult()
	{
		if (!Z_Registration_Info_UScriptStruct_TerrainShapeMergeResult.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_TerrainShapeMergeResult.InnerSingleton, Z_Construct_UScriptStruct_FTerrainShapeMergeResult_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_TerrainShapeMergeResult.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_TerrainShape;
class UScriptStruct* FTerrainShape::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_TerrainShape.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_TerrainShape.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FTerrainShape, Z_Construct_UPackage__Script_ProcedualTerrainTool(), TEXT("TerrainShape"));
	}
	return Z_Registration_Info_UScriptStruct_TerrainShape.OuterSingleton;
}
template<> PROCEDUALTERRAINTOOL_API UScriptStruct* StaticStruct<FTerrainShape>()
{
	return FTerrainShape::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FTerrainShape_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructPropertyParams NewProp_Vertices_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Vertices_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Vertices;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTerrainShape_Statics::Struct_MetaDataParams[] = {
		{ "Comment", "/**\n * Stores a piece of terrain's shape and its sockets.\n */" },
		{ "ModuleRelativePath", "Private/TerrainShape.h" },
		{ "ToolTip", "Stores a piece of terrain's shape and its sockets." },
	};
#endif
	void* Z_Construct_UScriptStruct_FTerrainShape_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FTerrainShape>();
	}
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FTerrainShape_Statics::NewProp_Vertices_Inner = { "Vertices", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UScriptStruct_FTerrainVertex, METADATA_PARAMS(nullptr, 0) }; // 2980008566
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTerrainShape_Statics::NewProp_Vertices_MetaData[] = {
		{ "Comment", "//Stores all of the sockets in this shape.\n" },
		{ "ModuleRelativePath", "Private/TerrainShape.h" },
		{ "ToolTip", "Stores all of the sockets in this shape." },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FTerrainShape_Statics::NewProp_Vertices = { "Vertices", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FTerrainShape, Vertices), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FTerrainShape_Statics::NewProp_Vertices_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTerrainShape_Statics::NewProp_Vertices_MetaData)) }; // 2980008566
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FTerrainShape_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTerrainShape_Statics::NewProp_Vertices_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTerrainShape_Statics::NewProp_Vertices,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FTerrainShape_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_ProcedualTerrainTool,
		nullptr,
		&NewStructOps,
		"TerrainShape",
		sizeof(FTerrainShape),
		alignof(FTerrainShape),
		Z_Construct_UScriptStruct_FTerrainShape_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTerrainShape_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FTerrainShape_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTerrainShape_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FTerrainShape()
	{
		if (!Z_Registration_Info_UScriptStruct_TerrainShape.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_TerrainShape.InnerSingleton, Z_Construct_UScriptStruct_FTerrainShape_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_TerrainShape.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Private_TerrainShape_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Private_TerrainShape_h_Statics::EnumInfo[] = {
		{ EConnectionResult_StaticEnum, TEXT("EConnectionResult"), &Z_Registration_Info_UEnum_EConnectionResult, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2596577342U) },
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Private_TerrainShape_h_Statics::ScriptStructInfo[] = {
		{ FTerrainVertex::StaticStruct, Z_Construct_UScriptStruct_FTerrainVertex_Statics::NewStructOps, TEXT("TerrainVertex"), &Z_Registration_Info_UScriptStruct_TerrainVertex, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FTerrainVertex), 2980008566U) },
		{ FTerrainShapeMergeResult::StaticStruct, Z_Construct_UScriptStruct_FTerrainShapeMergeResult_Statics::NewStructOps, TEXT("TerrainShapeMergeResult"), &Z_Registration_Info_UScriptStruct_TerrainShapeMergeResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FTerrainShapeMergeResult), 2116728006U) },
		{ FTerrainShape::StaticStruct, Z_Construct_UScriptStruct_FTerrainShape_Statics::NewStructOps, TEXT("TerrainShape"), &Z_Registration_Info_UScriptStruct_TerrainShape, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FTerrainShape), 2577067158U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Private_TerrainShape_h_2695941013(TEXT("/Script/ProcedualTerrainTool"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Private_TerrainShape_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Private_TerrainShape_h_Statics::ScriptStructInfo),
		Z_CompiledInDeferFile_FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Private_TerrainShape_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Private_TerrainShape_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
