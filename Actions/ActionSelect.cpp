#include "ActionSelect.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include <iostream>

ActionSelect::ActionSelect(ApplicationManager* pApp) : Action(pApp)
{
}

ActionSelect::~ActionSelect(void)
{
}

void ActionSelect::Execute()
{


	//Get a Pointer to the user Interfaces
	UI* pUi = pManager->GetUI();

	//Print Action Message
	pUi->PrintMsg("Click on the item");

	//Get Center point of the area where the Comp should be drawn
	pUi->GetPointClicked(x, y);

	Component* pComp = pManager->componentcheck(x, y);
	Connection* pCon = pManager->connectioncheck(x, y);

	if (pComp != nullptr)
	{
		pComp->setSelected(true);
		//cout << pComp->getSelected();
		pUi->ClearStatusBar();
		return;
	
		
	}
	if (pCon != nullptr)
	{
		
		pCon->setSelected(true);
		//cout << pComp->getSelected();
		pUi->ClearStatusBar();
		return;
	}
	pUi->PrintMsg("No item located here. Click anywhere to return");
	pUi->GetPointClicked(x, y);
	return;
	
	//if (pCon == nullptr)
	//{
	//	//pUi->PrintMsg("No  located here. Click anywhere to return");
	//	pUi->GetPointClicked(x, y);
	//	return;
	//}
	//else
	//{
	//	pCon->setSelected(true);
	//	
	//}
	//pUi->PrintMsg("to deselect cleck any where");
	//pUi->GetPointClicked(x, y);
	//if (y > 80)
	//{
	//	pCon->setSelected(false);
	//}

}

void ActionSelect::Undo()
{
}

void ActionSelect::Redo()
{
}
