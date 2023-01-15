// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProcedualTerrainTool/Private/ProcedualTerrainToolFunctionLibraries.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProcedualTerrainToolFunctionLibraries() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	PROCEDUALTERRAINTOOL_API UClass* Z_Construct_UClass_UPTTFactories();
	PROCEDUALTERRAINTOOL_API UClass* Z_Construct_UClass_UPTTFactories_NoRegister();
	PROCEDUALTERRAINTOOL_API UClass* Z_Construct_UClass_UPTTMath();
	PROCEDUALTERRAINTOOL_API UClass* Z_Construct_UClass_UPTTMath_NoRegister();
	UNREALED_API UClass* Z_Construct_UClass_UDataAssetFactory_NoRegister();
	UPackage* Z_Construct_UPackage__Script_ProcedualTerrainTool();
// End Cross Module References
	void UPTTMath::StaticRegisterNativesUPTTMath()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPTTMath);
	UClass* Z_Construct_UClass_UPTTMath_NoRegister()
	{
		return UPTTMath::StaticClass();
	}
	struct Z_Construct_UClass_UPTTMath_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPTTMath_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_ProcedualTerrainTool,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPTTMath_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * A library of useful math functions.\n */" },
		{ "IncludePath", "ProcedualTerrainToolFunctionLibraries.h" },
		{ "ModuleRelativePath", "Private/ProcedualTerrainToolFunctionLibraries.h" },
		{ "ToolTip", "A library of useful math functions." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPTTMath_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPTTMath>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPTTMath_Statics::ClassParams = {
		&UPTTMath::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UPTTMath_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPTTMath_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPTTMath()
	{
		if (!Z_Registration_Info_UClass_UPTTMath.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPTTMath.OuterSingleton, Z_Construct_UClass_UPTTMath_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPTTMath.OuterSingleton;
	}
	template<> PROCEDUALTERRAINTOOL_API UClass* StaticClass<UPTTMath>()
	{
		return UPTTMath::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPTTMath);
	UPTTMath::~UPTTMath() {}
	DEFINE_FUNCTION(UPTTFactories::execCreateDataAssetFactory)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UDataAssetFactory**)Z_Param__Result=UPTTFactories::CreateDataAssetFactory();
		P_NATIVE_END;
	}
	void UPTTFactories::StaticRegisterNativesUPTTFactories()
	{
		UClass* Class = UPTTFactories::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CreateDataAssetFactory", &UPTTFactories::execCreateDataAssetFactory },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPTTFactories_CreateDataAssetFactory_Statics
	{
		struct PTTFactories_eventCreateDataAssetFactory_Parms
		{
			UDataAssetFactory* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPTTFactories_CreateDataAssetFactory_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(PTTFactories_eventCreateDataAssetFactory_Parms, ReturnValue), Z_Construct_UClass_UDataAssetFactory_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPTTFactories_CreateDataAssetFactory_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPTTFactories_CreateDataAssetFactory_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPTTFactories_CreateDataAssetFactory_Statics::Function_MetaDataParams[] = {
		{ "Category", "Factories" },
		{ "ModuleRelativePath", "Private/ProcedualTerrainToolFunctionLibraries.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPTTFactories_CreateDataAssetFactory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPTTFactories, nullptr, "CreateDataAssetFactory", nullptr, nullptr, sizeof(Z_Construct_UFunction_UPTTFactories_CreateDataAssetFactory_Statics::PTTFactories_eventCreateDataAssetFactory_Parms), Z_Construct_UFunction_UPTTFactories_CreateDataAssetFactory_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPTTFactories_CreateDataAssetFactory_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPTTFactories_CreateDataAssetFactory_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPTTFactories_CreateDataAssetFactory_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPTTFactories_CreateDataAssetFactory()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPTTFactories_CreateDataAssetFactory_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPTTFactories);
	UClass* Z_Construct_UClass_UPTTFactories_NoRegister()
	{
		return UPTTFactories::StaticClass();
	}
	struct Z_Construct_UClass_UPTTFactories_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPTTFactories_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_ProcedualTerrainTool,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UPTTFactories_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPTTFactories_CreateDataAssetFactory, "CreateDataAssetFactory" }, // 3905011692
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPTTFactories_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * A library for creating various factories.\n */" },
		{ "IncludePath", "ProcedualTerrainToolFunctionLibraries.h" },
		{ "ModuleRelativePath", "Private/ProcedualTerrainToolFunctionLibraries.h" },
		{ "ToolTip", "A library for creating various factories." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPTTFactories_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPTTFactories>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPTTFactories_Statics::ClassParams = {
		&UPTTFactories::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UPTTFactories_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPTTFactories_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPTTFactories()
	{
		if (!Z_Registration_Info_UClass_UPTTFactories.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPTTFactories.OuterSingleton, Z_Construct_UClass_UPTTFactories_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPTTFactories.OuterSingleton;
	}
	template<> PROCEDUALTERRAINTOOL_API UClass* StaticClass<UPTTFactories>()
	{
		return UPTTFactories::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPTTFactories);
	UPTTFactories::~UPTTFactories() {}
	struct Z_CompiledInDeferFile_FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Private_ProcedualTerrainToolFunctionLibraries_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Private_ProcedualTerrainToolFunctionLibraries_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPTTMath, UPTTMath::StaticClass, TEXT("UPTTMath"), &Z_Registration_Info_UClass_UPTTMath, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPTTMath), 3923697062U) },
		{ Z_Construct_UClass_UPTTFactories, UPTTFactories::StaticClass, TEXT("UPTTFactories"), &Z_Registration_Info_UClass_UPTTFactories, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPTTFactories), 2125811806U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Private_ProcedualTerrainToolFunctionLibraries_h_2133568122(TEXT("/Script/ProcedualTerrainTool"),
		Z_CompiledInDeferFile_FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Private_ProcedualTerrainToolFunctionLibraries_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_snick_OneDrive_Documents_Unreal_Projects_Procedual2DTerrain_ProcedualTerrainTool_HostProject_Plugins_ProcedualTerrainTool_Source_ProcedualTerrainTool_Private_ProcedualTerrainToolFunctionLibraries_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
