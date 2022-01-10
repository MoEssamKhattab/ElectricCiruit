#include "ActionExit.h"
#include "ActionSave.h"
#include "..\ApplicationManager.h"

ActionExit::ActionExit(ApplicationManager* pApp) :Action(pApp)
{
}

ActionExit::~ActionExit(void)
{
}

void ActionExit::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("This file isn't saved? \t a.Save. (a) \t b.Don't save. (b) \t c.Cancel. (c)");
	
	pManager->Exit(pUI->GetSrting());
	
}

void ActionExit::Undo()
{}

void ActionExit::Redo()
{}

