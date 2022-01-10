#include "ActionCopy.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include <iostream>

ActionCopy::ActionCopy(ApplicationManager* pApp) : Action(pApp)
{
}

ActionCopy::~ActionCopy(void)
{
}

void ActionCopy::Execute()
{

	
	UI* pUi = pManager->GetUI();
	
	pUi->PrintMsg("clickon the component");
	pUi->GetPointClicked(x, y);
	Component* pComp = pManager->componentcheck(x, y);
	cout << pComp->getGraphicsInfo()->PointsList[0].x << "   " << pComp->getGraphicsInfo()->PointsList[0].y << "   " << pComp->getGraphicsInfo()->PointsList[1].x << "  " << pComp->getGraphicsInfo()->PointsList[1].y<<endl;
	if (pComp == nullptr)
	{
		pUi->PrintMsg("No component located here. Click anywhere to return");
		pUi->GetPointClicked(x, y);
		pUi->ClearStatusBar();
		//cout << pManager->CompCountget();
		return;
		
	}
	else
	{
		pUi->PrintMsg("click to paste");
		pUi->GetPointClicked(xp, yp);
		cout << pComp->getGraphicsInfo()->PointsList[0].x << "   " << pComp->getGraphicsInfo()->PointsList[0].y << "   " << pComp->getGraphicsInfo()->PointsList[1].x << "  " << pComp->getGraphicsInfo()->PointsList[1].y << endl;
		//pManager->Copycomponent(pComp,xp, yp);
		Component* copy = pComp->createcopy();
		GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp
		pGInfo->PointsList[0].x =pComp->getGraphicsInfo()->PointsList[0].x ;
		pGInfo->PointsList[0].y =pComp->getGraphicsInfo()->PointsList[0].y ;
		pGInfo->PointsList[1].x =pComp->getGraphicsInfo()->PointsList[1].x ;
		pGInfo->PointsList[1].y =pComp->getGraphicsInfo()->PointsList[1].y ;
	
		copy->getGraphicsInfo()->PointsList[0].x = xp - pUi->getCompWidth() / 2;
		copy->getGraphicsInfo()->PointsList[0].y = yp - pUi->getCompHeight() / 2;
		copy->getGraphicsInfo()->PointsList[1].x = xp + pUi->getCompWidth() / 2;
		copy->getGraphicsInfo()->PointsList[1].y = yp + pUi->getCompHeight() / 2;
		pUi->ClearDrawingimage(pGInfo);
		pUi->ClearStatusBar();
	}

	
}

void ActionCopy::Undo()
{
}

void ActionCopy::Redo()
{
}
