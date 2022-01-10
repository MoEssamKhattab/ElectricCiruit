#include "ActionUndo.h"
#include "..\ApplicationManager.h"

ActionUndo::ActionUndo(ApplicationManager* pApp) :Action(pApp)
{
}

ActionUndo::~ActionUndo(void)
{
}

void ActionUndo::Execute()
{
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
}

void ActionUndo::Undo()
{}

void ActionUndo::Redo()
{}

