#include "ApplicationManager.h"
#include "Actions\ActionAddRes.h"
#include "Actions\ActionAddBulb.h"
#include "Actions\ActionExit.h"
#include "Actions\ActionSave.h"
#include "Actions\ActionLoad.h"
#include "Actions\ActionAddModule.h"
#include "Actions\ActionAddBuz.h"
#include "Actions\ActionAddFus.h"
#include "Actions\ActionAddGro.h"
#include "Actions\ActionConct.h"
#include "Actions\ActionSelect.h"
#include "Actions\ActionUnselect.h"
#include "Actions\ActionRedo.h"
#include "Actions\ActionUndo.h"
#include "Actions\ActionLabel.h"
#include "Actions\ActionCopy.h"
#include "Actions\ActionCut.h"
#include "Actions\ActionDelete.h"
#include <iostream>
#include "UI\UI.h"


ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	ConCount = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = nullptr;

	for (int i = 0; i < MaxConCount; i++)
		ConList[i] = nullptr;

	for (int i = 0; i < MaxActCount; i++)
	{
		UndoList[i] = nullptr;
		RedoList[i] = nullptr;
	}
			

	//Creates the UI Object & Initialize the UI
	pUI = new UI;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;	
	UpdateCompID();
}

void ApplicationManager::AddConnection(Connection* pCon)
{
	ConList[ConCount++] = pCon;
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateUndoAction(Action* pAction, int x) //Update UndoList
{
	if (x == 1)
	{
		UndoList[UndoCount] = pAction;
		UndoCount++;
	}
	else
	{
		Action* Temp = nullptr;
		Temp = UndoList[UndoCount - 1];
		UndoList[UndoCount - 1] = nullptr;
		UpdateRedoAction(Temp, 1);
		delete UndoList[UndoCount-1];
		//UndoList[UndoCount-1] = nullptr;
		UndoCount--;
	}
}

void ApplicationManager::UpdateRedoAction(Action* pAction, int x)
{
	if (x == 1)
	{
		RedoList[RedoCount] = pAction;
		RedoCount++;
	}
	else
	{
		delete RedoList[RedoCount - 1];
		RedoList[RedoCount - 1] = nullptr;
		RedoCount--;
	}
}
void ApplicationManager::Undo()
{
	UndoList[UndoCount-1]->Undo();
	UpdateUndoAction(UndoList[UndoCount-1], -1);

}



void ApplicationManager::Redo()
{
	RedoList[RedoCount - 1]->Redo();
	UpdateRedoAction(RedoList[RedoCount - 1], -1);
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::Delete()  // Delete Components
{

	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->getSelected())
		{
			pUI->ClearDrawingArea();
			delete CompList[i];
			CompList[i] = nullptr;
			for (int j = i;j < CompCount - 1; j++)
			{
				CompList[j] = CompList[j + 1];
			}
			i--;
			CompCount--;
		}
	}

	for (int i = 0; i < ConCount; i++)
	{
		if (ConList[i]->getComp1()->getSelected() || ConList[i]->getComp2()->getSelected())
		{
			pUI->ClearDrawingArea();
			delete ConList[i];
			ConList[i] = nullptr;
			for (int j = i;j < ConCount - 1; j++)
			{
				ConList[j] = ConList[j + 1];
			}
			i--;
			ConCount--;
		}
	}
}


void ApplicationManager::Delete1(Component* pC)
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i] == pC)
		{
			pUI->ClearDrawingimage(CompList[i]->getGraphicsInfo());
			delete CompList[i];
			CompList[i] = nullptr;
			for (int j = i;j < CompCount - 1; j++)
			{
				CompList[j] = CompList[j + 1];
			}
			i--;
			CompCount--;
		}
	}
}



/*
void ApplicationManager::SDeleteCon(Connection* pC)
{
}

 
Component* ApplicationManager::SDelete(Component* pC)
{
	Component* Temp = nullptr;
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i] == pC)
		{

			pC = CompList[i];
			CompList[i] = Temp;
			return pC;
			pUI->ClearDrawingimage(CompList[i]->getGraphicsInfo());
			delete CompList[i];
			CompList[i] = nullptr;
			for (int j = i;j < CompCount - 1; j++)
			{
				CompList[j] = CompList[j + 1];
			}
			i--;
			CompCount--;
		}
	}
}
*/


void ApplicationManager::DeleteCon(Connection* pC)  // Delete Connections
{
	for (int i = 0; i < ConCount; i++)
	{
		if (ConList[i] == pC)
		{
			pUI->ClearDrawingArea();
			delete ConList[i];
			ConList[i] = nullptr;
			for (int j = i;j < ConCount - 1; j++)
			{
				ConList[j] = ConList[j + 1];
			}
			i--;
			ConCount--;
		}
	}
}

void ApplicationManager::DeleteMultCon()  // Delete Connections
{
	for (int i = 0; i < ConCount; i++)
	{
		if (ConList[i]->getSelected())
		{
			pUI->ClearDrawingArea();
			delete ConList[i];
			ConList[i] = nullptr;
			for (int j = i;j < ConCount - 1; j++)
			{
				ConList[j] = ConList[j + 1];
			}
			i--;
			ConCount--;
		}
	}
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::Exit(string x)
{
	if (x == "a")
	{
		this->ExecuteAction(SAVE);
	}
	else
	{
		if (pUI->GetSrting() == "b")
		{
		}
		else
		{
			pUI->PrintMsg("Invalid Choise!!");
			return;
		}
	}
	//Clear Status Bar
	pUI->ClearStatusBar();
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return pUI->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = nullptr;
	switch (ActType)
	{
		case ADD_RESISTOR:
			pAct= new ActionAddRes(this);
			UpdateUndoAction(pAct, 1);
			break;
		case ADD_BULB:
			pAct = new ActionAddBulb(this);
			UpdateUndoAction(pAct, 1);
			break;
		case ADD_GROUND:
			pAct = new ActionAddGro(this);
			UpdateUndoAction(pAct, 1);
			break;
		case ADD_FUSE:
			pAct = new ActionAddFus(this);
			UpdateUndoAction(pAct, 1);
			break;
		case ADD_BUZZER:
			pAct = new ActionAddBuz(this);
			UpdateUndoAction(pAct, 1);
			break;
		case SELECT:
			pAct = new ActionSelect(this);
			UpdateUndoAction(pAct, 1);
			break;
		case UNSELECT:
			pAct = new ActionUnselect(this);
			UpdateUndoAction(pAct, 1);
			break;
		case ADD_CONNECTION:
			pAct = new ActionConct(this);
			UpdateUndoAction(pAct, 1);
			break;
		case COPY:
			pAct = new ActionCopy(this);
			UpdateUndoAction(pAct, 1);
			break;
		case CUT:
			pAct = new ActionCut(this);
			UpdateUndoAction(pAct, 1);
			break;
		case DEL:
			pAct = new ActionDelete(this);
			UpdateUndoAction(pAct, 1);
			break;
		case LABEL:
			pAct = new ActionLabel(this);
			UpdateUndoAction(pAct, 1);
			break;

		case ADD_MODULE:
			pAct = new ActionAddModule(this);
			UpdateUndoAction(pAct, 1);
			break;
	
		case SAVE:
			pAct = new ActionSave(this);
			break;

		case LOAD:
			pAct = new ActionLoad(this);
			break;
		case UNDO:
			pAct = new ActionUndo(this);
			break;
		case REDO:
			pAct = new ActionRedo(this);
			break;
		case EXIT:
			pAct = new ActionExit(this);
			break;
	}
	if(pAct)
	{
		Action* Temp = nullptr;

		pAct->Execute();

		pAct = Temp;
		delete pAct;
		pAct = nullptr;
	}
}

////////////////////////////////////////////////////////////////////
void ApplicationManager::UpdateInterface()
{
		for(int i=0; i<CompCount; i++)
			CompList[i]->Draw(pUI);

		for (int i = 0; i < ConCount; i++)
			ConList[i]->Draw(pUI);
}

////////////////////////////////////////////////////////////////////
UI* ApplicationManager::GetUI()
{
	return pUI;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::UpdateCompID()
{
	for (int i = 0; i < CompCount; i++)
	{
		CompList[i]->SetID(i + 1);
	}
}

////////////////////////////////////////////////////////////////////

Component* ApplicationManager::GetCompList()
{
	return CompList[0];
}

Connection* ApplicationManager::GetConList()
{
	return ConList[0];
}

////////////////////////////////////////////////////////////////////

void ApplicationManager::Save(ofstream& savefile)
{
	savefile << CompCount << endl;
	for (int i = 0; i < CompCount; i++)
	{
		CompList[i]->save(savefile);
	}
	
	savefile << "Connections" << endl << ConCount <<endl;
	for (int i = 0; i < ConCount; i++)
	{
		savefile << ConList[i]->getComp1()->GetID() << "\t" << ConList[i]->getComp2()->GetID() << endl;
	}

	savefile.close();
}

////////////////////////////////////////////////////////////////////
void ApplicationManager::Load(ifstream& loadfile)
{
	int Compcount, value, Comp_ID, x, y;
	string comptype, label;
	
	Component* pCom = nullptr;
	Connection* pCon = nullptr;

	string con;
	int Concount, comp1id, comp2id;

	while (!(loadfile.eof()))
	{
		loadfile >> Compcount;
		for (int i = 0; i < Compcount; i++)
		{
			while (loadfile >> comptype >> Comp_ID >> label >> value >> x >> y)
			{
				GraphicsInfo* pGInfo = new GraphicsInfo(2);
				pGInfo->PointsList[0].x = x;
				pGInfo->PointsList[0].y = y;
				pGInfo->PointsList[1].x = x + pUI->getCompWidth();
				pGInfo->PointsList[1].y = y + pUI->getCompHeight();

				if (comptype == "RES")
				{
					pCom = new Resistor(pGInfo);
					pCom->load(label, value);
				}
				else
				{
					if (comptype == "BLB")
					{
						pCom = new Bulb(pGInfo);
						pCom->load(label, value);
					}
					else
					{
						if (comptype == "BAT")
						{
							//pCom = new Battery(pGInfo);      //Ahmed's non-copmlete Work
							//pCom->load(label, value);
						}
						else
						{
							if ((comptype == "SWT"))
							{
								//pCom = new Switch(pGInfo);      //Ahmed's non-copmlete Work
								//pCom->load(label, value);
							}
							else
							{
								if (comptype == "GRD")
								{
									pCom = new Ground(pGInfo);
									pCom->load(label, value);
								}
								else
								{
									if (comptype == "BUZ")
									{
										pCom = new Buzzer(pGInfo);
										pCom->load(label, value);
									}
									else 
									{
										if (comptype == "FUS")
										{
											pCom = new Fuse(pGInfo);
											pCom->load(label, value);
										}
										else
										{
											if (comptype == "MOD")
											{
												pCom = new Module(pGInfo);
												pCom->load(label, value);
											}
										}
									}
								}
							}
						}
					}

				}
			
				if (pCom)
				{
					AddComponent(pCom);
					delete pCom;
					pCom = nullptr;
				}
			}
		}

		loadfile >> con >> Concount;

		for (int i = 0; i < Concount; i++)
		{
			while (loadfile >> comp1id >> comp2id)
			{
				GraphicsInfo* pGInfo = new GraphicsInfo(2);

				pGInfo->PointsList[0].x = GetCompByID(comp1id)->getGraphicsInfo()->PointsList[1].x;
				pGInfo->PointsList[0].y = GetCompByID(comp1id)->getGraphicsInfo()->PointsList[1].y - 15;
				pGInfo->PointsList[1].x = GetCompByID(comp2id)->getGraphicsInfo()->PointsList[0].x;
				pGInfo->PointsList[1].y = GetCompByID(comp2id)->getGraphicsInfo()->PointsList[0].y + 15;

				pCon = new Connection(pGInfo, GetCompByID(comp1id), GetCompByID(comp2id));
				this->AddConnection(pCon);
			}
		}
		if (pCon)
		{
			delete pCom;
			pCom = nullptr;
		}
	}
}
/////////
void ApplicationManager::deleteconnection(Component* comp)
{
	for (int i = 0; i < ConCount; i++) {
		int xcon0 = ConList[i]->getConctsInfo()->PointsList[0].x;
		int ycon0 = ConList[i]->getConctsInfo()->PointsList[0].y;
		int xcomp1 = comp->getGraphicsInfo()->PointsList[1].x;
		int ycomp1 = comp->getGraphicsInfo()->PointsList[1].y - 15;

		int xcon1 = ConList[i]->getConctsInfo()->PointsList[1].x;
		int ycon1 = ConList[i]->getConctsInfo()->PointsList[1].y;
		int xcomp0 = comp->getGraphicsInfo()->PointsList[0].x;
		int ycomp0 = comp->getGraphicsInfo()->PointsList[0].y + 15;
		cout << xcon0 << "===" << xcomp1 << endl;
		cout << ycon0 << "===" << ycomp1 << endl;
		cout << xcon1 << "*===*" << xcomp0 << endl;
		cout << ycon1 << "*===*" << ycomp0 << endl;
		if (xcon0 == xcomp1 && ycon0 == ycomp1 || xcon1 == xcomp0 && ycon1 == ycomp0)
		{
			delete ConList[i];
			//cout << ConCount;
			ConList[i] = nullptr;
			for (int j = i; j < ConCount - 1; j++)
			{
				ConList[j] = ConList[j + 1];
			}
			i--;
			ConCount--;
		}

	}
}

bool ApplicationManager::groundcheck()
{
	if (groundcount >= 1)
	{
		pUI->PrintMsg("there is more than one Ground");
		return true;
	}
	return false;
}


void ApplicationManager::Addground()
{
	groundcount++;
}

Component* ApplicationManager::Copycomponent(Component* comp, int xp, int yp)
{
	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();
	pGInfo->PointsList[0].x = xp - compWidth / 2;
	pGInfo->PointsList[0].y = yp - compHeight / 2;
	pGInfo->PointsList[1].x = xp + compWidth / 2;
	pGInfo->PointsList[1].y = yp + compHeight / 2;
	Component* copy = comp->createcopy(pGInfo);
	AddComponent(copy);

	return copy;
}



void ApplicationManager::fullyconnectedcheck()
{
	if (CompCount != ConCount)
	{
		pUI->PrintMsg("Check that circuit is fully connected");
		return;
	}
	cout << "fully";
	return;
}

/// //
// 
bool ApplicationManager::componentconic(Component* comp)
{
	int brashcount1 = 0;
	int brashcount2 = 0;
	for (int i = 0; i < ConCount; i++)
	{
		int xcon0 = ConList[i]->getConctsInfo()->PointsList[0].x;
		int ycon0 = ConList[i]->getConctsInfo()->PointsList[0].y;
		int xcomp1 = comp->getGraphicsInfo()->PointsList[1].x;
		int ycomp1 = comp->getGraphicsInfo()->PointsList[1].y - 15;

		int xcon1 = ConList[i]->getConctsInfo()->PointsList[1].x;
		int ycon1 = ConList[i]->getConctsInfo()->PointsList[1].y;
		int xcomp0 = comp->getGraphicsInfo()->PointsList[0].x;
		int ycomp0 = comp->getGraphicsInfo()->PointsList[0].y + 15;

		if (xcon0 == xcomp1 && ycon0 == ycomp1)
		{
			brashcount1++;
		}
		if (xcon1 == xcomp0 && ycon1 == ycomp0)
		{
			brashcount2++;
		}
	}
	if (brashcount1 + brashcount2 >= 2)
	{
		return true;
	}
	return false;
}
/////////////////////////////////////////////////////////////////////
Component* ApplicationManager::GetCompByID(int x)
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->GetID() == x)
		{
			return CompList[i];
		}
	}
}

/////////////////////////////////////////////////////////////////////

int ApplicationManager::GetCompCount()
{
	return CompCount;
}
int ApplicationManager::GetSelectedCompNum()
{
	int c = 0;
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->getSelected())
			c++;
	}
	return c;
}

/////////////////////////////////////////////////////////////////////
int ApplicationManager::GetConCount()
{
	return ConCount;
}
int ApplicationManager::GetSelectedConNum()
{
	int c = 0;
	for (int i = 0; i < ConCount; i++)
	{
		if (ConList[i]->getSelected())
			c++;
	}
	return c;
}

bool ApplicationManager::CheckDrawingArea(int x, int y)
{
	if ((((y - (pUI->getCompHeight() / 2)) >= pUI->GetToolbarHeight()) && ((y + (pUI->getCompHeight() / 2)) < (pUI->GetHeight() - pUI->GetStatusBarHeight())))
	&& (((x - (pUI->getCompWidth() / 2)) >= 0) && ((x + (pUI->getCompWidth() / 2)) < pUI->GetWidth()))
	&& !(componentcheck(x, y)) && !(connectioncheck(x, y)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

/////////////////////////////////////////////////////////////////////

Component* ApplicationManager::componentcheck(int x, int y)
{
	for (int i = 0; i < CompCount; i++)
	{
		int x1 = CompList[i]->getGraphicsInfo()->PointsList[0].x;
		int y1 = CompList[i]->getGraphicsInfo()->PointsList[0].y;
		int x2 = CompList[i]->getGraphicsInfo()->PointsList[1].x;
		int y2 = CompList[i]->getGraphicsInfo()->PointsList[1].y;
		if (x >= x1 && y >= y1 &&
			x <= x2 && y <= y2)
		{
			return CompList[i];
		}
	}
	return nullptr;
}
//Component* ApplicationManager::checkselect()
//{
//	for (int i = 0; i < CompCount; i++)
//	{
//		if (CompList[i]->getSelected)
//
//			return CompList[i];
//		
//	}
//	return nullptr;
//}
void ApplicationManager::unselect()
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->getSelected())
		{
			CompList[i]->setSelected(false);
		}
	}
	for (int i = 0; i < ConCount; i++)
	{
		if (ConList[i]->getSelected())
		{
			ConList[i]->setSelected(false);
		}
	}
	pUI->ClearDrawingArea();
}

Connection* ApplicationManager::connectioncheck(int x, int y)
{
	for (int i = 0; i < ConCount; i++)
	{
		int x1 = ConList[i]->getConctsInfo()->PointsList[0].x;
		int y1 = ConList[i]->getConctsInfo()->PointsList[0].y;
		int x2 = ConList[i]->getConctsInfo()->PointsList[1].x;
		int y2 = ConList[i]->getConctsInfo()->PointsList[1].y;
		
		if (((x >= x1 && y >= y1 && x <= x2 && y <= y2) || (x >= x1 && y <= y1 &&x <= x2 && y >= y2)) || 
			((x <= x1 && y <= y1 && x >= x2 && y >= y2) || (x <= x1 && y >= y1 && x >= x2 && y <= y2)))
		{
			return ConList[i];
		}
	}
	return nullptr;
}
int ApplicationManager::GetUndoCount() const
{
	return UndoCount;
}
int ApplicationManager::GetRedoCount() const
{
	return RedoCount;
}
////////////////////////////////////////////////////////////////////
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];

	for (int i = 0; i < ConCount; i++)
		delete ConList[i];
	delete pUI;
	
}