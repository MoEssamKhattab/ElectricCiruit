#include "ActionAddFus.h"
#include "..\ApplicationManager.h"

ActionAddFus::ActionAddFus(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddFus::~ActionAddFus(void)
{
}

void ActionAddFus::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding a new Fuse: Click anywhere to add");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);
	//Clear Status Bar
	pUI->ClearStatusBar();


	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();

	pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;

	Fuse* pF = new Fuse(pGInfo);
	pManager->AddComponent(pF);
}

void ActionAddFus::Undo()
{}

void ActionAddFus::Redo()
{}
