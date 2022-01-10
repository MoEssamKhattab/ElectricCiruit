#include "ActionAddModule.h"
#include "..\ApplicationManager.h"

ActionAddModule::ActionAddModule(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddModule::~ActionAddModule(void)
{
}

void ActionAddModule::Execute()
{
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding a new Module: Click anywhere to add");

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

	Module* pM = new Module(pGInfo);
	pManager->AddComponent(pM);

	pUI->PrintMsg("R1 = ");
	pM->setR1(stoi(pUI->GetSrting()));
	pUI->PrintMsg("R2 = ");
	pM->setR2(stoi(pUI->GetSrting()));
	pUI->PrintMsg("R3 = ");
	pM->setR3(stoi(pUI->GetSrting()));
	pUI->PrintMsg("R4 = ");
	pM->setR4(stoi(pUI->GetSrting()));

	pM->SetValue(pM->getR_eq());
	pUI->ClearStatusBar();

}


void ActionAddModule::Undo()
{}

void ActionAddModule::Redo()
{}

