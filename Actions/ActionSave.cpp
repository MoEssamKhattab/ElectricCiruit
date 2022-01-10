#include "ActionSave.h"
#include "..\ApplicationManager.h"

ActionSave::ActionSave(ApplicationManager* pApp) :Action(pApp)
{
}

ActionSave::~ActionSave(void)
{
}

void ActionSave::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Enter file name, please!");

	string filename = pUI->GetSrting();
	ofstream savefile;
	savefile.open(filename);

	pManager->Save(savefile);

	pUI->PrintMsg("Saved successfully :)");

	pUI->ClearStatusBar();
}

void ActionSave::Undo()
{}

void ActionSave::Redo()
{}

