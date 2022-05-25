// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProcedualTerrainToolEditorMode.h"
#include "ProcedualTerrainToolEditorModeToolkit.h"
#include "EdModeInteractiveToolsContext.h"
#include "InteractiveToolManager.h"
#include "ProcedualTerrainToolEditorModeCommands.h"


//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////// 
// AddYourTool Step 1 - include the header file for your Tools here
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////// 
#include "Tools/ProcedualTerrainToolSimpleTool.h"
#include "Tools/ProcedualTerrainToolInteractiveTool.h"

// step 2: register a ToolBuilder in FProcedualTerrainToolEditorMode::Enter() below


#define LOCTEXT_NAMESPACE "ProcedualTerrainToolEditorMode"

const FEditorModeID UProcedualTerrainToolEditorMode::EM_ProcedualTerrainToolEditorModeId = TEXT("EM_ProcedualTerrainToolEditorMode");

FString UProcedualTerrainToolEditorMode::SimpleToolName = TEXT("ProcedualTerrainTool_ActorInfoTool");
FString UProcedualTerrainToolEditorMode::InteractiveToolName = TEXT("ProcedualTerrainTool_MeasureDistanceTool");


UProcedualTerrainToolEditorMode::UProcedualTerrainToolEditorMode()
{
	FModuleManager::Get().LoadModule("EditorStyle");

	// appearance and icon in the editing mode ribbon can be customized here
	Info = FEditorModeInfo(UProcedualTerrainToolEditorMode::EM_ProcedualTerrainToolEditorModeId,
		LOCTEXT("ModeName", "ProcedualTerrainTool"),
		FSlateIcon(),
		true);
}


UProcedualTerrainToolEditorMode::~UProcedualTerrainToolEditorMode()
{
}


void UProcedualTerrainToolEditorMode::ActorSelectionChangeNotify()
{
}

void UProcedualTerrainToolEditorMode::Enter()
{
	UEdMode::Enter();

	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	// AddYourTool Step 2 - register the ToolBuilders for your Tools here.
	// The string name you pass to the ToolManager is used to select/activate your ToolBuilder later.
	//////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////// 
	const FProcedualTerrainToolEditorModeCommands& SampleToolCommands = FProcedualTerrainToolEditorModeCommands::Get();

	RegisterTool(SampleToolCommands.SimpleTool, SimpleToolName, NewObject<UProcedualTerrainToolSimpleToolBuilder>(this));
	RegisterTool(SampleToolCommands.InteractiveTool, InteractiveToolName, NewObject<UProcedualTerrainToolInteractiveToolBuilder>(this));

	// active tool type is not relevant here, we just set to default
	GetToolManager()->SelectActiveToolType(EToolSide::Left, SimpleToolName);
}

void UProcedualTerrainToolEditorMode::CreateToolkit()
{
	Toolkit = MakeShareable(new FProcedualTerrainToolEditorModeToolkit);
}

TMap<FName, TArray<TSharedPtr<FUICommandInfo>>> UProcedualTerrainToolEditorMode::GetModeCommands() const
{
	return FProcedualTerrainToolEditorModeCommands::Get().GetCommands();
}

#undef LOCTEXT_NAMESPACE
