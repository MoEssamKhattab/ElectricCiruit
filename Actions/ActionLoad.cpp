#include "ActionLoad.h"
#include "..\ApplicationManager.h"

ActionLoad::ActionLoad(ApplicationManager* pApp) :Action(pApp)
{
}

ActionLoad::~ActionLoad(void)
{
}

void ActionLoad::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Enter file name, please!");

	string filename = pUI->GetSrting();
	ifstream loadfile;
	loadfile.open(filename);
	if (!loadfile)
	{
		pUI->PrintMsg("File Not Found!!!\n");
	}
	else
	{
		pManager->Load(loadfile);
	}

	loadfile.close();
	pUI->PrintMsg("Loaded successfully :)");

	pUI->ClearStatusBar();
}

void ActionLoad::Undo()
{}

void ActionLoad::Redo()
{}

