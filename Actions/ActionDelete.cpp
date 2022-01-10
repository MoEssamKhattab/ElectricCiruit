#include "ActionDelete.h"
#include "..\ApplicationManager.h"

ActionDelete::ActionDelete(ApplicationManager* pApp) :Action(pApp)
{
}

ActionDelete::~ActionDelete(void)
{
}

void ActionDelete::Execute()
{
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	
	
	

}

void ActionDelete::Undo()
{}

void ActionDelete::Redo()
{}

