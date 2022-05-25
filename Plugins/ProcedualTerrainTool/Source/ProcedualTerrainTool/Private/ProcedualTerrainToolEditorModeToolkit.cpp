// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProcedualTerrainToolEditorModeToolkit.h"
#include "ProcedualTerrainToolEditorMode.h"
#include "Engine/Selection.h"

#include "Modules/ModuleManager.h"
#include "PropertyEditorModule.h"
#include "IDetailsView.h"
#include "EditorModeManager.h"

#define LOCTEXT_NAMESPACE "ProcedualTerrainToolEditorModeToolkit"

FProcedualTerrainToolEditorModeToolkit::FProcedualTerrainToolEditorModeToolkit()
{
}

void FProcedualTerrainToolEditorModeToolkit::Init(const TSharedPtr<IToolkitHost>& InitToolkitHost, TWeakObjectPtr<UEdMode> InOwningMode)
{
	FModeToolkit::Init(InitToolkitHost, InOwningMode);
}

void FProcedualTerrainToolEditorModeToolkit::GetToolPaletteNames(TArray<FName>& PaletteNames) const
{
	PaletteNames.Add(NAME_Default);
}


FName FProcedualTerrainToolEditorModeToolkit::GetToolkitFName() const
{
	return FName("ProcedualTerrainToolEditorMode");
}

FText FProcedualTerrainToolEditorModeToolkit::GetBaseToolkitName() const
{
	return LOCTEXT("DisplayName", "ProcedualTerrainToolEditorMode Toolkit");
}

#undef LOCTEXT_NAMESPACE
