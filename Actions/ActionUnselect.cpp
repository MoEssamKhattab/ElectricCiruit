#include "ActionUnselect.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include <iostream>

ActionUnselect::ActionUnselect(ApplicationManager* pApp) : Action(pApp)
{
}

ActionUnselect::~ActionUnselect(void)
{
}

void ActionUnselect::Execute()
{

	
		pManager->unselect();
	



	//if (pCon == nullptr)
	//{
	//	//pUi->PrintMsg("No component located here. Click anywhere to return");
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

void ActionUnselect::Undo()
{
}

void ActionUnselect::Redo()
{
}
