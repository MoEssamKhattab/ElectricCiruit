#include "ActionLabel.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include <iostream>

ActionLabel::ActionLabel(ApplicationManager* pApp) : Action(pApp)
{
}

ActionLabel::~ActionLabel(void)
{
}

void ActionLabel::Execute()
{
	
	cout << "done";
	UI* pUi = pManager->GetUI();
	pUi->PrintMsg(" Click on the component ");
	pUi->GetPointClicked(x, y);
	

	//pUi->PrintMsg("Please click on the component you want to select/deselect");
	Component* pComp = pManager->componentcheck(x, y);
	Connection* pCon = pManager->connectioncheck(x, y);
	if (pComp == nullptr)
	{
		pUi->PrintMsg("No component located here. Click anywhere to return");
		pUi->GetPointClicked(x, y);
		return;
	}
	else
	{
		pUi->ClearStatusBar();
		pUi->PrintMsg("label your component");
		string newlabel = pUi->GetSrting();
		pUi->label(x, y, newlabel);
	}
	if (pCon == nullptr)
	{
		pUi->PrintMsg("No connection located here. Click anywhere to return");
		pUi->GetPointClicked(x, y);
		return;
	}
	else
	{
		pUi->ClearStatusBar();

		pUi->PrintMsg("label your connection");
		string newlabel = pUi->GetSrting();
		pUi->label(x, y, newlabel);
	}

}

void ActionLabel::Undo()
{
}

void ActionLabel::Redo()
{
}
