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
#include "Actions\ActionLabel.h"
#include "Actions\ActionCopy.h"
#include "Actions\ActionCut.h"
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

	//Creates the UI Object & Initialize the UI
	pUI = new UI;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}

void ApplicationManager::AddConnection(Connection* pCon)
{
	ConList[ConCount++] = pCon;
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::Delete()
{
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
			if (pUI->GetSrting() == "c")
			{
				ActType = DSN_TOOL;
				this -> ExecuteAction(ActType);
				this ->UpdateInterface();
			}
				
			//else
				//ActType = 
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
			break;

		case ADD_BULB:
			pAct = new ActionAddBulb(this);
			break;
		case ADD_GROUND:
			pAct = new ActionAddGro(this);
			break;
		case ADD_FUSE:
			pAct = new ActionAddFus(this);
			break;
		case ADD_BUZZER:
			pAct = new ActionAddBuz(this);
			break;
		case SELECT:
			pAct = new ActionSelect(this);
			break;
		case UNSELECT:
			pAct = new ActionUnselect(this);
			break;
		case ADD_CONNECTION:
			pAct = new ActionConct(this);
			break;
		case COPY:
			pAct = new ActionCopy(this);
			break;
		case CUT:
			pAct = new ActionCut(this);
			break;

		case LABEL:
			pAct = new ActionLabel(this);
			break;

		case ADD_MODULE:
			pAct = new ActionAddModule(this);
			break;
	
		case SAVE:
			pAct = new ActionSave(this);
			break;

		case LOAD:
			pAct = new ActionLoad(this);
			break;

		case EXIT:
			pAct = new ActionExit(this);
			break;
	}
	if(pAct)
	{
		pAct->Execute();
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
Component* ApplicationManager::GetCompList()
{
	Component* comp_list = *CompList;
	return comp_list;
}

////////////////////////////////////////////////////////////////////

void ApplicationManager::Save(ofstream& savefile)
{
	savefile << CompList[0]->Ccount << endl;
	for (int i = 0; i < CompCount; i++)
	{
		CompList[i]->save(savefile);
	}
	savefile.close();
}

////////////////////////////////////////////////////////////////////
void ApplicationManager::Load(ifstream& loadfile)
{
	int Ccount;
	string comptype;

	//Component* pC = nullptr;

	while (!(loadfile.eof()))
	{
		loadfile >> Ccount;
		loadfile >> comptype;
		
		/*
		if (pC) {
			AddComponent(pC);
			UpdateInterface();
			pC = nullptr;
		*/
		
		}
	}
	//delete pC;


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
}


Connection* ApplicationManager::connectioncheck(int x, int y)
{
	for (int i = 0; i < ConCount; i++)
	{
		int x1 = ConList[i]->getConctsInfo()->PointsList[0].x;
		int y1 = ConList[i]->getConctsInfo()->PointsList[0].y;
		int x2 = ConList[i]->getConctsInfo()->PointsList[1].x;
		int y2 = ConList[i]->getConctsInfo()->PointsList[1].y;
		if (x >= x1 && y >= y1 &&
			x <= x2 && y <= y2)
		{
			return ConList[i];
		}
	}
	return nullptr;
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