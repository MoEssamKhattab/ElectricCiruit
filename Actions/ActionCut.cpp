#include "ActionCut.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include <iostream>

ActionCut::ActionCut(ApplicationManager* pApp) : Action(pApp)
{
}

ActionCut::~ActionCut(void)
{
}

void ActionCut::Execute()
{

	
	UI* pUi = pManager->GetUI();
	pUi->PrintMsg("clickon the component");
	pUi->GetPointClicked(x, y);
	Component* pComp = pManager->componentcheck(x, y);

	if (pComp == nullptr)
	{
		pUi->PrintMsg("No component located here. Click anywhere to return");
		pUi->GetPointClicked(x, y);
		
		return;
	}
	else
	{
		pUi->PrintMsg("click to paste");
		pUi->GetPointClicked(xp, yp);
		//pManager->Copycomponent(pComp, xp, yp);
		///pManager->Deletecomponent(pComp);
		pUi->ClearStatusBar();
	}


}

void ActionCut::Undo()
{
}

void ActionCut::Redo()
{
}
