#include "ActionConct.h"
#include "..\ApplicationManager.h"
#include "..\Components\Connection.h"

ActionConct::ActionConct(ApplicationManager* pApp) :Action(pApp)
{
}

ActionConct::~ActionConct(void)
{
}

void ActionConct::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	
	//Print Action Message
	pUI->PrintMsg("Click on the first component");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(x1, y1);
	
	Component* comp1 = pManager->componentcheck(x1, y1);
	if (comp1 == nullptr)
	{
		pUI->PrintMsg("Invalid component location");
		pUI->GetPointClicked(x1, y1);
		return;
	}
	//Clear Status Bar
	pUI->ClearStatusBar();

	pUI->PrintMsg("Click on the second component");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(x2, y2);
	Component* comp2 = pManager->componentcheck(x2, y2);
	if (comp2 == nullptr)
	{
		pUI->PrintMsg("Invalid component location");
		pUI->GetPointClicked(x2, y2);
		return;
	}
	//Clear Status Bar
	pUI->ClearStatusBar();

	

	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	pGInfo->PointsList[0].x = comp1->getGraphicsInfo()->PointsList[1].x;
	pGInfo->PointsList[0].y = comp1->getGraphicsInfo()->PointsList[1].y -15;
	pGInfo->PointsList[1].x = comp2->getGraphicsInfo()->PointsList[0].x;
	pGInfo->PointsList[1].y = comp2->getGraphicsInfo()->PointsList[0].y+15 ;

	Connection* con = new Connection(pGInfo, comp1, comp2);
	pManager->AddConnection(con);

}

void ActionConct::Undo()
{}

void ActionConct::Redo()
{}
